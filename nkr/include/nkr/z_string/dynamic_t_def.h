/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_utils.h"

#include "nkr/z_array/stack_t.h"

#include "nkr/z_string_itr_def.h"
#include "nkr/z_string/dynamic_t_dec.h"

namespace nkr {

    template <typename other_p>
    inline constexpr c_bool_t
        type_traits_i<string::dynamic_tg>::Is_Any()
    {
        return string::$dynamic_t::any_tr<other_p>;
    }

    inline constexpr c_bool_t
        template_traits_i<string::dynamic_ttg>::Is_Implemented()
    {
        return true;
    }

}

namespace nkr { namespace string {

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline constexpr c_bool_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Has_Guaranteed_Terminus()
    {
        return true;
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline const typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::unit_t*
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Empty_C_String()
    {
        static const unit_t default_c_string[1] = { 0 };

        return default_c_string;
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline auto&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Copy_Assign(is_any_non_const_tr<dynamic_t> auto& self,
                                                                      const is_any_tr<dynamic_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            self.array = other.array;
            if (self.array.Has_Memory()) {
                self.point_count = other.point_count;
            } else {
                self.point_count = 0;
            }
        }
        return self;
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline auto&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Move_Assign(is_any_non_const_tr<dynamic_t> auto& self,
                                                                      is_any_non_const_tr<dynamic_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            self.array = nkr::Move(other.array);
            self.point_count = nkr::Move(other.point_count);
        }
        return self;
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Has_Memory(const is_any_tr<dynamic_t> auto& self)
    {
        return self.array.Has_Memory();
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Has_Terminus(const is_any_tr<dynamic_t> auto& self)
    {
        if (self.array.Has_Memory()) {
            count_t unit_count = Unit_Count(self);

            return unit_count > 0 && self.array[unit_count - 1] == 0;
        } else {
            return false;
        }
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit_Capacity(const is_any_tr<dynamic_t> auto& self)
    {
        return self.array.Capacity();
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit_Capacity(is_any_tr<dynamic_t> auto& self, count_t unit_capacity_including_terminus)
    {
        // I think it would be an anit-pattern to allow otherwise, because it breaks the point count and possibly the last point before terminus
        nkr_ASSERT_THAT(Unit_Count(self) <= unit_capacity_including_terminus);

        return nkr::Move(self.array.Capacity(unit_capacity_including_terminus));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit_Count(const is_any_tr<dynamic_t> auto& self)
    {
        return self.array.Count();
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit_Length(const is_any_tr<dynamic_t> auto& self)
    {
        count_t unit_count = Unit_Count(self);
        if (unit_count > 0 && self.array[unit_count - 1] == 0) {
            return unit_count - 1;
        } else {
            return unit_count;
        }
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Point_Count(const is_any_tr<dynamic_t> auto& self)
    {
        return self.point_count;
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Point_Length(const is_any_tr<dynamic_t> auto& self)
    {
        count_t point_count = Point_Count(self);
        if (point_count > 0 && self.array[Unit_Count(self) - 1] == 0) {
            return point_count - 1;
        } else {
            return point_count;
        }
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline auto
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::C_String(const is_any_tr<dynamic_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));

        return &self.array[0];
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline auto
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::At(const is_any_tr<dynamic_t> auto& self, index_t point_index)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));
        nkr_ASSERT_THAT(point_index < Point_Count(self));

        return string_itr<std::remove_reference_t<decltype(self)>>(self, point_index);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline auto
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::At_Prefix(const is_any_tr<dynamic_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));

        return string_itr<std::remove_reference_t<decltype(self)>>(self, position_e::prefix_tg());
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline auto
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::At_First(const is_any_tr<dynamic_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));

        return string_itr<std::remove_reference_t<decltype(self)>>(self, position_e::first_tg());
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline auto
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::At_Last(const is_any_tr<dynamic_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));

        return string_itr<std::remove_reference_t<decltype(self)>>(self, position_e::last_tg());
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline auto
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::At_Terminus(const is_any_tr<dynamic_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));

        return string_itr<std::remove_reference_t<decltype(self)>>(self, position_e::terminus_tg());
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline auto
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::At_Postfix(const is_any_tr<dynamic_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));

        return string_itr<std::remove_reference_t<decltype(self)>>(self, position_e::postfix_tg());
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push_Terminus(is_any_tr<dynamic_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Memory(self));
        nkr_ASSERT_THAT(!Has_Terminus(self));
        nkr_ASSERT_THAT(Unit_Count(self) < Unit_Capacity(self));

        self.array.Push(unit_t(0)).Ignore_Error();
        self.point_count += 1;
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Pop_Terminus(is_any_tr<dynamic_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));

        self.array.Pop();
        self.point_count -= 1;
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(is_any_tr<dynamic_t> auto& self, point_t point)
    {
        nkr_ASSERT_THAT(point > 0);
        nkr_ASSERT_THAT(Has_Terminus(self));

        charcoder_t charcoder;
        charcoder.Encode(point);
        return nkr::Move(Push(self, charcoder));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(is_any_tr<dynamic_t> auto& self, const charcoder_t& charcoder)
    {
        nkr_ASSERT_THAT(charcoder.Decode() > 0);
        nkr_ASSERT_THAT(Has_Terminus(self));

        count_t unit_count = Unit_Count(self);
        count_t charcoder_length = charcoder.Unit_Count();

        if (math::Will_Overflow_Add(unit_count, charcoder_length)) {
            return allocator_err::OUT_OF_MEMORY;
        } else {
            maybe_t<allocator_err> err = Unit_Capacity(self, unit_count + charcoder_length);
            if (err) {
                return err;
            } else {
                if (Has_Terminus(self)) {
                    Pop_Terminus(self);
                }

                for (index_t idx = 0, end = charcoder_length; idx < end; idx += 1) {
                    self.array.Push(charcoder[idx]).Ignore_Error();
                }
                self.point_count += 1;

                if (!Has_Terminus(self)) {
                    Push_Terminus(self);
                }

                return allocator_err::NONE;
            }
        }
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(is_any_tr<dynamic_t> auto& self, const is_any_tr<unit_t> auto* c_string)
    {
        nkr_ASSERT_THAT(c_string);
        nkr_ASSERT_THAT(Has_Terminus(self));

        return nkr::Move(Push(self, c_string, C_String_Unit_Length(c_string)));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(is_any_tr<dynamic_t> auto& self,
                                                               const is_any_tr<unit_t> auto* c_string,
                                                               count_t unit_length)
    {
        nkr_ASSERT_THAT(c_string);
        nkr_ASSERT_THAT(Has_Terminus(self));

        const count_t unit_count = Unit_Count(self);

        if (math::Will_Overflow_Add(unit_count, unit_length)) {
            return allocator_err::OUT_OF_MEMORY;
        } else {
            maybe_t<allocator_err> err = Unit_Capacity(self, unit_count + unit_length);
            if (err) {
                return err;
            } else {
                if constexpr (charcoder_t::Max_Unit_Count() > 1) {
                    const count_t offset_to_new_mid_point = Offset_To_New_Mid_Point<dynamic_t>(self, c_string, unit_length);

                    Pop_Terminus(self);

                    for (index_t idx = 0, end = offset_to_new_mid_point; idx < end; idx += 1) {
                        self.array.Push(c_string[idx]).Ignore_Error();
                    }

                    c_string += offset_to_new_mid_point;
                    unit_length -= offset_to_new_mid_point;
                } else {
                    Pop_Terminus(self);
                }

                charcoder_t charcoder;
                for (index_t idx = 0, next_point_idx = 0, end = unit_length; idx < end;) {
                    next_point_idx = idx + charcoder.Read_Forward(c_string + idx);
                    for (; idx < next_point_idx; idx += 1) {
                        nkr_ASSERT_THAT(c_string[idx] != 0);
                        self.array.Push(c_string[idx]).Ignore_Error();
                    }
                    self.point_count += 1;
                }

                Push_Terminus(self);

                return allocator_err::NONE;
            }
        }
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(is_any_tr<dynamic_t> auto& self, const any_string_tr auto& other)
    {
        // this needs to be redone and completed, look at how stack_t does it
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(is_any_tr<dynamic_t> auto& self, any_non_const_string_tr auto&& other)
    {

    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline auto&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit(is_any_tr<dynamic_t> auto& self, index_t unit_index)
    {
        nkr_ASSERT_THAT(self.array.Count() > unit_index);

        return self.array[unit_index];
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<charcoder_p, allocator_p, grow_rate_p>::dynamic_t() :
        dynamic_t(1)
    {
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<charcoder_p, allocator_p, grow_rate_p>::dynamic_t(count_t unit_capacity_including_terminus) :
        array(unit_capacity_including_terminus),
        point_count(0)
    {
        if (Has_Memory(*this)) {
            Push_Terminus(*this);
        }
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<charcoder_p, allocator_p, grow_rate_p>::dynamic_t(const charcoder_t& charcoder) :
        dynamic_t(charcoder.Unit_Count() + 1)
    {
        if (Has_Memory(*this) && charcoder.Decode() > 0) {
            Push(*this, charcoder).Ignore_Error();
        }
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<charcoder_p, allocator_p, grow_rate_p>::dynamic_t(const is_any_tr<unit_t> auto* c_string) :
        dynamic_t(C_String_Unit_Count(c_string))
    {
        if (Has_Memory(*this)) {
            Push(*this, c_string, Unit_Capacity(*this) - 1).Ignore_Error();
        }
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<charcoder_p, allocator_p, grow_rate_p>::dynamic_t(const dynamic_t& other) :
        array(other.array),
        point_count(other.point_count)
    {
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<charcoder_p, allocator_p, grow_rate_p>::dynamic_t(const volatile dynamic_t& other) :
        array(other.array),
        point_count(other.point_count)
    {
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<charcoder_p, allocator_p, grow_rate_p>::dynamic_t(dynamic_t&& other) noexcept :
        array(nkr::Move(other.array)),
        point_count(nkr::Move(other.point_count))
    {
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<charcoder_p, allocator_p, grow_rate_p>::dynamic_t(volatile dynamic_t&& other) noexcept :
        array(nkr::Move(other.array)),
        point_count(nkr::Move(other.point_count))
    {
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<charcoder_p, allocator_p, grow_rate_p>&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::operator =(const dynamic_t& other)
    {
        return Copy_Assign(*this, other);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline volatile dynamic_t<charcoder_p, allocator_p, grow_rate_p>&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::operator =(const dynamic_t& other)
        volatile
    {
        return Copy_Assign(*this, other);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<charcoder_p, allocator_p, grow_rate_p>&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::operator =(const volatile dynamic_t& other)
    {
        return Copy_Assign(*this, other);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline volatile dynamic_t<charcoder_p, allocator_p, grow_rate_p>&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::operator =(const volatile dynamic_t& other)
        volatile
    {
        return Copy_Assign(*this, other);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<charcoder_p, allocator_p, grow_rate_p>&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::operator =(dynamic_t&& other)
        noexcept
    {
        return Move_Assign(*this, other);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline volatile dynamic_t<charcoder_p, allocator_p, grow_rate_p>&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::operator =(dynamic_t&& other)
        volatile noexcept
    {
        return Move_Assign(*this, other);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<charcoder_p, allocator_p, grow_rate_p>&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::operator =(is_just_volatile_tr<dynamic_t> auto&& other)
        noexcept
    {
        return Move_Assign(*this, other);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline volatile dynamic_t<charcoder_p, allocator_p, grow_rate_p>&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::operator =(is_just_volatile_tr<dynamic_t> auto&& other)
        volatile noexcept
    {
        return Move_Assign(*this, other);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<charcoder_p, allocator_p, grow_rate_p>::~dynamic_t()
    {
        this->point_count = 0;
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Has_Memory()
        const
    {
        return Has_Memory(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Has_Memory()
        const volatile
    {
        return Has_Memory(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Has_Terminus()
        const
    {
        return Has_Terminus(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Has_Terminus()
        const volatile
    {
        return Has_Terminus(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit_Capacity()
        const
    {
        return Unit_Capacity(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit_Capacity()
        const volatile
    {
        return Unit_Capacity(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit_Capacity(count_t unit_capacity_including_terminus)
    {
        return nkr::Move(Unit_Capacity(*this, unit_capacity_including_terminus));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit_Capacity(count_t unit_capacity_including_terminus)
        volatile
    {
        return nkr::Move(Unit_Capacity(*this, unit_capacity_including_terminus));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit_Count()
        const
    {
        return Unit_Count(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit_Count()
        const volatile
    {
        return Unit_Count(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit_Length()
        const
    {
        return Unit_Length(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit_Length()
        const volatile
    {
        return Unit_Length(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Point_Count()
        const
    {
        return Point_Count(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Point_Count()
        const volatile
    {
        return Point_Count(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Point_Length()
        const
    {
        return Point_Length(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Point_Length()
        const volatile
    {
        return Point_Length(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline some_t<const typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::unit_t*>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::C_String()
        const
    {
        return C_String(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline some_t<const volatile typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::unit_t*>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::C_String()
        const volatile
    {
        return C_String(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline string_itr<const dynamic_t<charcoder_p, allocator_p, grow_rate_p>>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::At(index_t point_index)
        const
    {
        return At(*this, point_index);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline string_itr<const volatile dynamic_t<charcoder_p, allocator_p, grow_rate_p>>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::At(index_t point_index)
        const volatile
    {
        return At(*this, point_index);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline string_itr<const dynamic_t<charcoder_p, allocator_p, grow_rate_p>>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::At_Prefix()
        const
    {
        return At_Prefix(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline string_itr<const volatile dynamic_t<charcoder_p, allocator_p, grow_rate_p>>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::At_Prefix()
        const volatile
    {
        return At_Prefix(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline string_itr<const dynamic_t<charcoder_p, allocator_p, grow_rate_p>>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::At_First()
        const
    {
        return At_First(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline string_itr<const volatile dynamic_t<charcoder_p, allocator_p, grow_rate_p>>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::At_First()
        const volatile
    {
        return At_First(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline string_itr<const dynamic_t<charcoder_p, allocator_p, grow_rate_p>>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::At_Last()
        const
    {
        return At_Last(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline string_itr<const volatile dynamic_t<charcoder_p, allocator_p, grow_rate_p>>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::At_Last()
        const volatile
    {
        return At_Last(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline string_itr<const dynamic_t<charcoder_p, allocator_p, grow_rate_p>>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::At_Terminus()
        const
    {
        return At_Terminus(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline string_itr<const volatile dynamic_t<charcoder_p, allocator_p, grow_rate_p>>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::At_Terminus()
        const volatile
    {
        return At_Terminus(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline string_itr<const dynamic_t<charcoder_p, allocator_p, grow_rate_p>>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::At_Postfix()
        const
    {
        return At_Postfix(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline string_itr<const volatile dynamic_t<charcoder_p, allocator_p, grow_rate_p>>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::At_Postfix()
        const volatile
    {
        return At_Postfix(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(point_t point)
    {
        return nkr::Move(Push(*this, point));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(point_t point)
        volatile
    {
        return nkr::Move(Push(*this, point));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(const charcoder_t& charcoder)
    {
        return nkr::Move(Push(*this, charcoder));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(const charcoder_t& charcoder)
        volatile
    {
        return nkr::Move(Push(*this, charcoder));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(const is_any_tr<unit_t> auto* c_string)
    {
        return nkr::Move(Push(*this, c_string));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(const is_any_tr<unit_t> auto* c_string)
        volatile
    {
        return nkr::Move(Push(*this, c_string));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(const is_any_tr<unit_t> auto* c_string, count_t unit_length)
    {
        return nkr::Move(Push(*this, c_string, unit_length));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(const is_any_tr<unit_t> auto* c_string, count_t unit_length)
        volatile
    {
        return nkr::Move(Push(*this, c_string, unit_length));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(const any_string_tr auto& string)
    {
        return nkr::Move(Push(*this, string));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(const any_string_tr auto& string)
        volatile
    {
        return nkr::Move(Push(*this, string));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(any_non_const_string_tr auto&& string)
    {
        return nkr::Move(Push(*this, nkr::Move(string)));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(any_non_const_string_tr auto&& string)
        volatile
    {
        return nkr::Move(Push(*this, nkr::Move(string)));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::unit_t&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit(index_t unit_index)
    {
        return Unit(*this, unit_index);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline const typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::unit_t&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit(index_t unit_index)
        const
    {
        return Unit(*this, unit_index);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline volatile typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::unit_t&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit(index_t unit_index)
        volatile
    {
        return Unit(*this, unit_index);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline const volatile typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::unit_t&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit(index_t unit_index)
        const volatile
    {
        return Unit(*this, unit_index);
    }

}}

namespace nkr {

    template <string::any_dynamic_tr string_p, count_t min_point_count_p, count_t max_point_count_p>
    inline auto
        Random(bool_t use_erroneous_units)
    {
        using string_t = string_p;
        using charcoder_t = string_t::charcoder_t;
        using qualified_charcoder_t = string_t::qualified_charcoder_t;
        using unit_t = string_t::unit_t;

        nkr_ASSERT_THAT(min_point_count_p >= 1);
        nkr_ASSERT_THAT(max_point_count_p >= 1);
        nkr_ASSERT_THAT(min_point_count_p <= max_point_count_p);

        const count_t point_count = nkr::Random<count_t>(min_point_count_p, max_point_count_p);
        std::remove_const_t<string_t> string(point_count * charcoder_t::Max_Unit_Count());
        if (use_erroneous_units) {
            charcoder_t charcoder;
            array::stack_t<unit_t, charcoder_t::Max_Unit_Count()> units;
            for (index_t idx = 0, end = point_count - 1; idx < end;) {
                for (index_t idx = 0, end = units.Capacity(); idx < end; idx += 1) {
                    units.Push(Random<unit_t>(1)).Ignore_Error();
                }
                const count_t previous_point_count = string.Point_Count();
                string.Push(units.Array(), charcoder.Read_Forward(&units[0])).Ignore_Error();
                units.Clear();
                if (string.Point_Count() > previous_point_count) {
                    idx += 1;
                }
            }
        } else {
            charcoder_t charcoder;
            for (index_t idx = 0, end = point_count - 1; idx < end; idx += 1) {
                do {
                    charcoder.Encode(nkr::Random<string::point_t>(1, charcoder_t::Last_Point()));
                } while (charcoder.Decode() == charcoder_t::Replacement_Point());
                string.Push(charcoder).Ignore_Error();
            }
        }

        return string;
    }

}
