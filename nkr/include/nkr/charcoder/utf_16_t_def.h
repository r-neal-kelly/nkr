/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/macros_def.h"
#include "nkr/os.h"
#include "nkr/utils.h"

#include "nkr/charcoder/utf_16_t_dec.h"
#include "nkr/charcoder/utf_32_t.h"

namespace nkr { namespace charcoder {

    inline constexpr point_t
        utf_16_t::Last_Point()
    {
        return utf_32_t::POINT_LAST;
    }

    inline constexpr point_t
        utf_16_t::Replacement_Point()
    {
        return utf_32_t::REPLACEMENT_CHARACTER;
    }

    inline constexpr count_t
        utf_16_t::Max_Unit_Count()
    {
        return 2;
    }

    inline auto&
        utf_16_t::Assign_Copy(is_any_non_const_tr<utf_16_t> auto& self, const is_any_tr<utf_16_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            self.units = other.units;
        }
        return self;
    }

    inline auto&
        utf_16_t::Assign_Move(is_any_non_const_tr<utf_16_t> auto& self, is_any_non_const_tr<utf_16_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            self.units = nkr::Exchange(other.units, units_t{ unit_t(0) });
        }
        return self;
    }

    inline bool_t
        utf_16_t::Is_Well_Formed_Normal(const is_any_tr<utf_16_t> auto& self)
    {
        if (self.units.Count() == 1) {
            return
                utf_32_t::Is_Scalar(self.units[0]);
        } else if (self.units.Count() == 2) {
            return
                utf_32_t::Is_Surrogate_High(self.units[0]) &&
                utf_32_t::Is_Surrogate_Low(self.units[1]);
        } else {
            return false;
        }
    }

    inline bool_t
        utf_16_t::Is_Well_Formed_Swapped(const is_any_tr<utf_16_t> auto& self)
    {
        if (self.units.Count() == 1) {
            return
                utf_32_t::Is_Scalar(os::endian::Swap(self.units[0]));
        } else if (self.units.Count() == 2) {
            return
                utf_32_t::Is_Surrogate_High(os::endian::Swap(self.units[0])) &&
                utf_32_t::Is_Surrogate_Low(os::endian::Swap(self.units[1]));
        } else {
            return false;
        }
    }

    inline void_t
        utf_16_t::Encode_Normal(is_any_non_const_tr<utf_16_t> auto& self, point_t point)
    {
        self.units.Count(0);

        if (utf_32_t::Is_Scalar(point)) {
            if (point <= 0xFFFF) {
                self.units = {
                    unit_t(point),
                };
            } else {
                self.units = {
                    unit_t(((point - 0x10000) >> 10) + utf_32_t::SURROGATE_HIGH_FIRST),
                    unit_t(((point - 0x10000) & 0x3FF) + utf_32_t::SURROGATE_LOW_FIRST),
                };
            }
        } else {
            self.units = {
                unit_t(utf_32_t::REPLACEMENT_CHARACTER),
            };
        }

        nkr_ASSERT_THAT(Is_Well_Formed_Normal(self));
    }

    inline void_t
        utf_16_t::Encode_Swapped(is_any_non_const_tr<utf_16_t> auto& self, point_t point)
    {
        self.units.Count(0);

        if (utf_32_t::Is_Scalar(point)) {
            if (point <= 0xFFFF) {
                self.units = {
                    os::endian::Swap(unit_t(point)),
                };
            } else {
                self.units = {
                    os::endian::Swap(unit_t(((point - 0x10000) >> 10) + utf_32_t::SURROGATE_HIGH_FIRST)),
                    os::endian::Swap(unit_t(((point - 0x10000) & 0x3FF) + utf_32_t::SURROGATE_LOW_FIRST)),
                };
            }
        } else {
            self.units = {
                unit_t(utf_32_t::REPLACEMENT_CHARACTER_16_SWAPPED),
            };
        }

        nkr_ASSERT_THAT(Is_Well_Formed_Swapped(self));
    }

    inline point_t
        utf_16_t::Decode_Normal(const is_any_tr<utf_16_t> auto& self)
    {
        nkr_ASSERT_THAT(Is_Well_Formed_Normal(self));

        if (self.units.Count() == 1) {
            return
                u32_t(self.units[0]);
        } else {
            return
                ((u32_t(self.units[0]) - utf_32_t::SURROGATE_HIGH_FIRST) << 10) +
                (u32_t(self.units[1]) - utf_32_t::SURROGATE_LOW_FIRST) + 0x10000;
        }
    }

    inline point_t
        utf_16_t::Decode_Swapped(const is_any_tr<utf_16_t> auto& self)
    {
        nkr_ASSERT_THAT(Is_Well_Formed_Swapped(self));

        if (self.units.Count() == 1) {
            return
                u32_t(os::endian::Swap(self.units[0]));
        } else {
            return
                ((u32_t(os::endian::Swap(self.units[0])) - utf_32_t::SURROGATE_HIGH_FIRST) << 10) +
                (u32_t(os::endian::Swap(self.units[1])) - utf_32_t::SURROGATE_LOW_FIRST) + 0x10000;
        }
    }

    inline count_t
        utf_16_t::Read_Forward_Normal(is_any_non_const_tr<utf_16_t> auto& self, const unit_t* from)
    {
        nkr_ASSERT_THAT(from);

        auto& raw_units = self.units.Array();

        raw_units[0] = *from;
        if (utf_32_t::Is_Surrogate_High(raw_units[0])) {
            raw_units[1] = *(from + 1);
            if (utf_32_t::Is_Surrogate_Low(raw_units[1])) {
                self.units.Count(2);
            } else {
                raw_units[0] = utf_32_t::REPLACEMENT_CHARACTER;
                self.units.Count(1);
            }
        } else if (utf_32_t::Is_Surrogate_Low(raw_units[0])) {
            raw_units[0] = utf_32_t::REPLACEMENT_CHARACTER;
            self.units.Count(1);
        } else {
            self.units.Count(1);
        }

        return self.units.Count();
    }

    inline count_t
        utf_16_t::Read_Forward_Swapped(is_any_non_const_tr<utf_16_t> auto& self, const unit_t* from)
    {
        nkr_ASSERT_THAT(from);

        auto& raw_units = self.units.Array();

        raw_units[0] = *from;
        if (utf_32_t::Is_Surrogate_High(os::endian::Swap(raw_units[0]))) {
            raw_units[1] = *(from + 1);
            if (utf_32_t::Is_Surrogate_Low(os::endian::Swap(raw_units[1]))) {
                self.units.Count(2);
            } else {
                raw_units[0] = utf_32_t::REPLACEMENT_CHARACTER_16_SWAPPED;
                self.units.Count(1);
            }
        } else if (utf_32_t::Is_Surrogate_Low(os::endian::Swap(raw_units[0]))) {
            raw_units[0] = utf_32_t::REPLACEMENT_CHARACTER_16_SWAPPED;
            self.units.Count(1);
        } else {
            self.units.Count(1);
        }

        return self.units.Count();
    }

    inline count_t
        utf_16_t::Read_Reverse_Normal(is_any_non_const_tr<utf_16_t> auto& self, const unit_t* from, const unit_t* first)
    {
        nkr_ASSERT_THAT(from);
        nkr_ASSERT_THAT(first);
        nkr_ASSERT_THAT(from > first);

        auto& raw_units = self.units.Array();

        unit_t unit_a = *(from - 1);
        if (utf_32_t::Is_Surrogate_Low(unit_a)) {
            if (from - 2 >= first) {
                unit_t unit_b = *(from - 2);
                if (utf_32_t::Is_Surrogate_High(unit_b)) {
                    raw_units[0] = unit_b;
                    raw_units[1] = unit_a;
                    self.units.Count(2);
                } else {
                    raw_units[0] = utf_32_t::REPLACEMENT_CHARACTER;
                    self.units.Count(1);
                }
            } else {
                raw_units[0] = utf_32_t::REPLACEMENT_CHARACTER;
                self.units.Count(1);
            }
        } else if (utf_32_t::Is_Surrogate_High(unit_a)) {
            raw_units[0] = utf_32_t::REPLACEMENT_CHARACTER;
            self.units.Count(1);
        } else {
            raw_units[0] = unit_a;
            self.units.Count(1);
        }

        return self.units.Count();
    }

    inline count_t
        utf_16_t::Read_Reverse_Swapped(is_any_non_const_tr<utf_16_t> auto& self, const unit_t* from, const unit_t* first)
    {
        nkr_ASSERT_THAT(from);
        nkr_ASSERT_THAT(first);
        nkr_ASSERT_THAT(from > first);

        auto& raw_units = self.units.Array();

        unit_t unit_a = *(from - 1);
        if (utf_32_t::Is_Surrogate_Low(os::endian::Swap(unit_a))) {
            if (from - 2 >= first) {
                unit_t unit_b = *(from - 2);
                if (utf_32_t::Is_Surrogate_High(os::endian::Swap(unit_b))) {
                    raw_units[0] = unit_b;
                    raw_units[1] = unit_a;
                    self.units.Count(2);
                } else {
                    raw_units[0] = utf_32_t::REPLACEMENT_CHARACTER_16_SWAPPED;
                    self.units.Count(1);
                }
            } else {
                raw_units[0] = utf_32_t::REPLACEMENT_CHARACTER_16_SWAPPED;
                self.units.Count(1);
            }
        } else if (utf_32_t::Is_Surrogate_High(os::endian::Swap(unit_a))) {
            raw_units[0] = utf_32_t::REPLACEMENT_CHARACTER_16_SWAPPED;
            self.units.Count(1);
        } else {
            raw_units[0] = unit_a;
            self.units.Count(1);
        }

        return self.units.Count();
    }

    inline count_t
        utf_16_t::Unit_Count(const is_any_tr<utf_16_t> auto& self)
    {
        return self.units.Count();
    }

    inline typename utf_16_t::unit_t
        utf_16_t::Operator_Access(const is_any_tr<utf_16_t> auto& self, index_t index)
    {
        nkr_ASSERT_THAT(index < self.units.Count());

        return self.units[index];
    }

    inline auto&
        utf_16_t::Assign_None(is_any_non_const_tr<utf_16_t> auto& self)
    {
        self.units = {
            unit_t(0),
        };

        return self;
    }

    inline bool_t
        utf_16_t::Is_Equal_To_None(const is_any_tr<utf_16_t> auto& self)
    {
        return self.units.Count() == 1 && self.units[0] == 0;
    }

    inline utf_16_t::utf_16_t() :
        units{ unit_t(0) }
    {
    }

    inline utf_16_t::utf_16_t(const utf_16_t& other) :
        units(other.units)
    {
    }

    inline utf_16_t::utf_16_t(const volatile utf_16_t& other) :
        units(other.units)
    {
    }

    inline utf_16_t::utf_16_t(utf_16_t&& other) noexcept :
        units(nkr::Exchange(other.units, units_t{ unit_t(0) }))
    {
    }

    inline utf_16_t::utf_16_t(volatile utf_16_t&& other) noexcept :
        units(nkr::Exchange(other.units, units_t{ unit_t(0) }))
    {
    }

    inline utf_16_t&
        utf_16_t::operator =(const utf_16_t& other)
    {
        return Assign_Copy(*this, other);
    }

    inline volatile utf_16_t&
        utf_16_t::operator =(const utf_16_t& other)
        volatile
    {
        return Assign_Copy(*this, other);
    }

    inline utf_16_t&
        utf_16_t::operator =(const volatile utf_16_t& other)
    {
        return Assign_Copy(*this, other);
    }

    inline volatile utf_16_t&
        utf_16_t::operator =(const volatile utf_16_t& other)
        volatile
    {
        return Assign_Copy(*this, other);
    }

    inline utf_16_t&
        utf_16_t::operator =(utf_16_t&& other)
        noexcept
    {
        return Assign_Move(*this, other);
    }

    inline volatile utf_16_t&
        utf_16_t::operator =(utf_16_t&& other)
        volatile noexcept
    {
        return Assign_Move(*this, other);
    }

    inline utf_16_t&
        utf_16_t::operator =(is_just_volatile_tr<utf_16_t> auto&& other)
        noexcept
    {
        return Assign_Move(*this, other);
    }

    inline volatile utf_16_t&
        utf_16_t::operator =(is_just_volatile_tr<utf_16_t> auto&& other)
        volatile noexcept
    {
        return Assign_Move(*this, other);
    }

    inline bool_t
        utf_16_t::Is_Well_Formed_Normal()
        const
    {
        return Is_Well_Formed_Normal(*this);
    }

    inline bool_t
        utf_16_t::Is_Well_Formed_Normal()
        const volatile
    {
        return Is_Well_Formed_Normal(*this);
    }

    inline bool_t
        utf_16_t::Is_Well_Formed_Swapped()
        const
    {
        return Is_Well_Formed_Swapped(*this);
    }

    inline bool_t
        utf_16_t::Is_Well_Formed_Swapped()
        const volatile
    {
        return Is_Well_Formed_Swapped(*this);
    }

    inline void_t
        utf_16_t::Encode_Normal(point_t point)
    {
        return Encode_Normal(*this, point);
    }

    inline void_t
        utf_16_t::Encode_Normal(point_t point)
        volatile
    {
        return Encode_Normal(*this, point);
    }

    inline void_t
        utf_16_t::Encode_Swapped(point_t point)
    {
        return Encode_Swapped(*this, point);
    }

    inline void_t
        utf_16_t::Encode_Swapped(point_t point)
        volatile
    {
        return Encode_Swapped(*this, point);
    }

    inline point_t
        utf_16_t::Decode_Normal()
        const
    {
        return Decode_Normal(*this);
    }

    inline point_t
        utf_16_t::Decode_Normal()
        const volatile
    {
        return Decode_Normal(*this);
    }

    inline point_t
        utf_16_t::Decode_Swapped()
        const
    {
        return Decode_Swapped(*this);
    }

    inline point_t
        utf_16_t::Decode_Swapped()
        const volatile
    {
        return Decode_Swapped(*this);
    }

    inline count_t
        utf_16_t::Read_Forward_Normal(const unit_t* from)
    {
        return Read_Forward_Normal(*this, from);
    }

    inline count_t
        utf_16_t::Read_Forward_Normal(const unit_t* from)
        volatile
    {
        return Read_Forward_Normal(*this, from);
    }

    inline count_t
        utf_16_t::Read_Forward_Swapped(const unit_t* from)
    {
        return Read_Forward_Swapped(*this, from);
    }

    inline count_t
        utf_16_t::Read_Forward_Swapped(const unit_t* from)
        volatile
    {
        return Read_Forward_Swapped(*this, from);
    }

    inline count_t
        utf_16_t::Read_Reverse_Normal(const unit_t* from, const unit_t* first)
    {
        return Read_Reverse_Normal(*this, from, first);
    }

    inline count_t
        utf_16_t::Read_Reverse_Normal(const unit_t* from, const unit_t* first)
        volatile
    {
        return Read_Reverse_Normal(*this, from, first);
    }

    inline count_t
        utf_16_t::Read_Reverse_Swapped(const unit_t* from, const unit_t* first)
    {
        return Read_Reverse_Swapped(*this, from, first);
    }

    inline count_t
        utf_16_t::Read_Reverse_Swapped(const unit_t* from, const unit_t* first)
        volatile
    {
        return Read_Reverse_Swapped(*this, from, first);
    }

    inline count_t
        utf_16_t::Unit_Count()
        const
    {
        return Unit_Count(*this);
    }

    inline count_t
        utf_16_t::Unit_Count()
        const volatile
    {
        return Unit_Count(*this);
    }

    inline typename utf_16_t::unit_t
        utf_16_t::operator [](index_t index)
        const
    {
        return Operator_Access(*this, index);
    }

    inline typename utf_16_t::unit_t
        utf_16_t::operator [](index_t index)
        const volatile
    {
        return Operator_Access(*this, index);
    }

    inline utf_16_t::utf_16_t(none_t) :
        utf_16_t()
    {
    }

    inline utf_16_t&
        utf_16_t::operator =(none_t)
    {
        return Assign_None(*this);
    }

    inline volatile utf_16_t&
        utf_16_t::operator =(none_t)
        volatile
    {
        return Assign_None(*this);
    }

    inline bool_t
        utf_16_t::operator ==(none_t)
        const
    {
        return Is_Equal_To_None(*this);
    }

    inline bool_t
        utf_16_t::operator ==(none_t)
        const volatile
    {
        return Is_Equal_To_None(*this);
    }

    inline bool_t
        utf_16_t::operator !=(none_t)
        const
    {
        return !Is_Equal_To_None(*this);
    }

    inline bool_t
        utf_16_t::operator !=(none_t)
        const volatile
    {
        return !Is_Equal_To_None(*this);
    }

    inline bool_t
        utf_16_be_t::Is_Well_Formed(const is_any_tr<utf_16_be_t> auto& self)
    {
        if constexpr (os::endian::Is_Big()) {
            return self.Is_Well_Formed_Normal();
        } else if constexpr (os::endian::Is_Little()) {
            return self.Is_Well_Formed_Swapped();
        } else {
            static_assert(false);
        }
    }

    inline void_t
        utf_16_be_t::Encode(is_any_non_const_tr<utf_16_be_t> auto& self, point_t point)
    {
        if constexpr (os::endian::Is_Big()) {
            return self.Encode_Normal(point);
        } else if constexpr (os::endian::Is_Little()) {
            return self.Encode_Swapped(point);
        } else {
            static_assert(false);
        }
    }

    inline point_t
        utf_16_be_t::Decode(const is_any_tr<utf_16_be_t> auto& self)
    {
        if constexpr (os::endian::Is_Big()) {
            return self.Decode_Normal();
        } else if constexpr (os::endian::Is_Little()) {
            return self.Decode_Swapped();
        } else {
            static_assert(false);
        }
    }

    inline count_t
        utf_16_be_t::Read_Forward(is_any_non_const_tr<utf_16_be_t> auto& self, const unit_t* from)
    {
        if constexpr (os::endian::Is_Big()) {
            return self.Read_Forward_Normal(from);
        } else if constexpr (os::endian::Is_Little()) {
            return self.Read_Forward_Swapped(from);
        } else {
            static_assert(false);
        }
    }

    inline count_t
        utf_16_be_t::Read_Reverse(is_any_non_const_tr<utf_16_be_t> auto& self, const unit_t* from, const unit_t* first)
    {
        if constexpr (os::endian::Is_Big()) {
            return self.Read_Reverse_Normal(from, first);
        } else if constexpr (os::endian::Is_Little()) {
            return self.Read_Reverse_Swapped(from, first);
        } else {
            static_assert(false);
        }
    }

    inline utf_16_be_t::utf_16_be_t(point_t point) :
        utf_16_be_t()
    {
        Encode(*this, point);
    }

    inline bool_t
        utf_16_be_t::Is_Well_Formed()
        const
    {
        return Is_Well_Formed(*this);
    }

    inline bool_t
        utf_16_be_t::Is_Well_Formed()
        const volatile
    {
        return Is_Well_Formed(*this);
    }

    inline void_t
        utf_16_be_t::Encode(point_t point)
    {
        return Encode(*this, point);
    }

    inline void_t
        utf_16_be_t::Encode(point_t point)
        volatile
    {
        return Encode(*this, point);
    }

    inline point_t
        utf_16_be_t::Decode()
        const
    {
        return Decode(*this);
    }

    inline point_t
        utf_16_be_t::Decode()
        const volatile
    {
        return Decode(*this);
    }

    inline count_t
        utf_16_be_t::Read_Forward(const unit_t* from)
    {
        return Read_Forward(*this, from);
    }

    inline count_t
        utf_16_be_t::Read_Forward(const unit_t* from)
        volatile
    {
        return Read_Forward(*this, from);
    }

    inline count_t
        utf_16_be_t::Read_Reverse(const unit_t* from, const unit_t* first)
    {
        return Read_Reverse(*this, from, first);
    }

    inline count_t
        utf_16_be_t::Read_Reverse(const unit_t* from, const unit_t* first)
        volatile
    {
        return Read_Reverse(*this, from, first);
    }

    inline bool_t
        utf_16_le_t::Is_Well_Formed(const is_any_tr<utf_16_le_t> auto& self)
    {
        if constexpr (os::endian::Is_Big()) {
            return self.Is_Well_Formed_Swapped();
        } else if constexpr (os::endian::Is_Little()) {
            return self.Is_Well_Formed_Normal();
        } else {
            static_assert(false);
        }
    }

    inline void_t
        utf_16_le_t::Encode(is_any_non_const_tr<utf_16_le_t> auto& self, point_t point)
    {
        if constexpr (os::endian::Is_Big()) {
            return self.Encode_Swapped(point);
        } else if constexpr (os::endian::Is_Little()) {
            return self.Encode_Normal(point);
        } else {
            static_assert(false);
        }
    }

    inline point_t
        utf_16_le_t::Decode(const is_any_tr<utf_16_le_t> auto& self)
    {
        if constexpr (os::endian::Is_Big()) {
            return self.Decode_Swapped();
        } else if constexpr (os::endian::Is_Little()) {
            return self.Decode_Normal();
        } else {
            static_assert(false);
        }
    }

    inline count_t
        utf_16_le_t::Read_Forward(is_any_non_const_tr<utf_16_le_t> auto& self, const unit_t* from)
    {
        if constexpr (os::endian::Is_Big()) {
            return self.Read_Forward_Swapped(from);
        } else if constexpr (os::endian::Is_Little()) {
            return self.Read_Forward_Normal(from);
        } else {
            static_assert(false);
        }
    }

    inline count_t
        utf_16_le_t::Read_Reverse(is_any_non_const_tr<utf_16_le_t> auto& self, const unit_t* from, const unit_t* first)
    {
        if constexpr (os::endian::Is_Big()) {
            return self.Read_Reverse_Swapped(from, first);
        } else if constexpr (os::endian::Is_Little()) {
            return self.Read_Reverse_Normal(from, first);
        } else {
            static_assert(false);
        }
    }

    inline utf_16_le_t::utf_16_le_t(point_t point) :
        utf_16_le_t()
    {
        Encode(*this, point);
    }

    inline bool_t
        utf_16_le_t::Is_Well_Formed()
        const
    {
        return Is_Well_Formed(*this);
    }

    inline bool_t
        utf_16_le_t::Is_Well_Formed()
        const volatile
    {
        return Is_Well_Formed(*this);
    }

    inline void_t
        utf_16_le_t::Encode(point_t point)
    {
        return Encode(*this, point);
    }

    inline void_t
        utf_16_le_t::Encode(point_t point)
        volatile
    {
        return Encode(*this, point);
    }

    inline point_t
        utf_16_le_t::Decode()
        const
    {
        return Decode(*this);
    }

    inline point_t
        utf_16_le_t::Decode()
        const volatile
    {
        return Decode(*this);
    }

    inline count_t
        utf_16_le_t::Read_Forward(const unit_t* from)
    {
        return Read_Forward(*this, from);
    }

    inline count_t
        utf_16_le_t::Read_Forward(const unit_t* from)
        volatile
    {
        return Read_Forward(*this, from);
    }

    inline count_t
        utf_16_le_t::Read_Reverse(const unit_t* from, const unit_t* first)
    {
        return Read_Reverse(*this, from, first);
    }

    inline count_t
        utf_16_le_t::Read_Reverse(const unit_t* from, const unit_t* first)
        volatile
    {
        return Read_Reverse(*this, from, first);
    }

}}
