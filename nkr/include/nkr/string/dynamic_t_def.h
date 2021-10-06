/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/string/dynamic_t_dec.h"

namespace nkr { namespace string {

    inline count_t C_String_Unit_Count(const any_character_tr auto* c_string)
    {
        nkr_ASSERT_THAT(c_string != nullptr);

        count_t count = 0;
        while (*c_string != 0) {
            count += 1;
            c_string += 1;
        }

        return count + 1;
    }

    inline count_t C_String_Unit_Length(const any_character_tr auto* c_string)
    {
        nkr_ASSERT_THAT(c_string != nullptr);

        count_t count = 0;
        while (*c_string != 0) {
            count += 1;
            c_string += 1;
        }

        return count;
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Copy_Construct(is_any_non_const_tr<dynamic_t> auto& self,
                                                                         const is_any_tr<dynamic_t> auto& other)
    {
        nkr_ASSERT_THAT(!self.array.Has_Memory());
        nkr_ASSERt_THAT(self.point_count == 0);

        self.array = other.array;
        if (self.array.Has_Memory()) {
            self.point_count = other.point_count;
        }
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Move_Construct(is_any_non_const_tr<dynamic_t> auto& self,
                                                                         is_any_non_const_tr<dynamic_t> auto&& other)
    {
        nkr_ASSERT_THAT(std::addressof(self) != std::addressof(other));

        self.array = nkr::Move(other.array);
        self.point_count = nkr::Move(other.point_count);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Destruct(is_any_tr<dynamic_t> auto& self)
    {
        self.array.~array_t();
        self.point_count = 0;
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Has_Memory(const is_any_tr<dynamic_t> auto& self)
    {
        return self.array.Has_Memory();
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
    inline count_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit_Capacity(const is_any_tr<dynamic_t> auto& self)
    {
        return self.array.Capacity();
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit_Capacity(is_any_tr<dynamic_t> auto& self, count_t unit_capacity_including_null)
    {
        return nkr::Move(self.array.Capacity(unit_capacity_including_null));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline some_t<const typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::unit_t*>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::C_String(const is_any_tr<dynamic_t> auto& self)
    {
        if (Has_Memory(self)) {
            return self.array.Pointer().Units();
        } else {
            return "";
        }
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push_Null(is_any_tr<dynamic_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Memory(self));
        nkr_ASSERT_THAT(Unit_Count(self) < Unit_Capacity(self));

        self.array.Push(0).Ignore_Error();
        self.point_count += 1;
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Pop_Null(is_any_tr<dynamic_t> auto& self)
    {
        count_t unit_count = Unit_Count(self);
        if (unit_count > 0 && self.array[unit_count - 1] == 0) {
            self.array.Pop();
            self.point_count -= 1;
        }
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(is_any_tr<dynamic_t> auto& self, point_t point)
    {
        charcoder_t charcoder;
        charcoder.Encode(point);
        Push(self, charcoder);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(is_any_tr<dynamic_t> auto& self, const charcoder_t& charcoder)
    {
        count_t unit_count = Unit_Count(self);
        count_t charcoder_length = charcoder.Unit_Count();

        if (math::Will_Overflow_Add(unit_count, charcoder_length)) {
            return allocator_err::OUT_OF_MEMORY;
        } else {
            maybe_t<allocator_err> err = Unic_Capacity(self, unit_count + charcoder_length);
            if (err) {
                return err;
            } else {
                Pop_Null(self);

                for (index_t idx = 0, end = charcoder_length; idx < end; idx += 1) {
                    self.array.Push(charcoder[idx]).Ignore_Error();
                }
                self.point_count += 1;

                Push_Null(self);

                return allocator_err::NONE;
            }
        }
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(is_any_tr<dynamic_t> auto& self, const is_any_tr<unit_t> auto* c_string)
    {
        count_t unit_length = Unit_Length(self);
        count_t c_string_unit_count = C_String_Unit_Count(c_string);

        if (math::Will_Overflow_Add(unit_length, c_string_unit_count)) {
            return allocator_err::OUT_OF_MEMORY;
        } else {
            maybe_t<allocator_err> err = Unit_Capacity(self, unit_length + c_string_unit_count);
            if (err) {
                return err;
            } else {
                Pop_Null(self);

                // we need point_count, so we interpret the string with charcoder which guarantees a point even from erroneous units.
                // we copy the actual units of c_string as they are though, errors included. this simplifies out of memory recovery,
                // and can only punish performance on the rare case that there is actually an error in the string.
                charcoder_t charcoder;
                for (index_t idx = 0, next_point_idx = 0, end = c_string_unit_count; idx < end;) {
                    next_point_idx = idx + charcoder.Read_Forward(c_string + idx);
                    for (; idx < next_point_idx; idx += 1) {
                        self.array.Push(c_string[idx]).Ignore_Error();
                    }
                    self.point_count += 1;
                }

                return allocator_err::NONE;
            }
        }
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<charcoder_p, allocator_p, grow_rate_p>::dynamic_t() :
        array(),
        point_count(0)
    {
        // we allow a non-allocated state for the sake of memory recovery and also because it can be inefficient
        // just to allocate for null when the user actually wants more. this allows for cheap declarations.
        // we don't use a static pointer either because it doesn't seem worth it at this time to check it constantly.
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<charcoder_p, allocator_p, grow_rate_p>::dynamic_t(count_t unit_capacity_including_null) :
        array(unit_capacity_including_null),
        point_count(0)
    {
        if (Has_Memory(*this)) {
            Push_Null(*this);
        }
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<charcoder_p, allocator_p, grow_rate_p>::dynamic_t(const is_any_tr<unit_t> auto* c_string) :
        array(),
        point_count(0)
    {
        Push(*this, c_string).Ignore_Error();
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
        if (this != std::addressof(other)) {
            Destruct(*this);
            Copy_Construct(*this, other);
        }
        return *this;
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline volatile dynamic_t<charcoder_p, allocator_p, grow_rate_p>&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::operator =(const dynamic_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            Destruct(*this);
            Copy_Construct(*this, other);
        }
        return *this;
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<charcoder_p, allocator_p, grow_rate_p>&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::operator =(const volatile dynamic_t& other)
    {
        if (this != std::addressof(other)) {
            Destruct(*this);
            Copy_Construct(*this, other);
        }
        return *this;
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline volatile dynamic_t<charcoder_p, allocator_p, grow_rate_p>&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::operator =(const volatile dynamic_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            Destruct(*this);
            Copy_Construct(*this, other);
        }
        return *this;
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<charcoder_p, allocator_p, grow_rate_p>&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::operator =(dynamic_t&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            Destruct(*this);
            Move_Construct(*this, nkr::Move(other));
        }
        return *this;
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline volatile dynamic_t<charcoder_p, allocator_p, grow_rate_p>&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::operator =(dynamic_t&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            Destruct(*this);
            Move_Construct(*this, nkr::Move(other));
        }
        return *this;
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<charcoder_p, allocator_p, grow_rate_p>&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::operator =(is_just_volatile_tr<dynamic_t> auto&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            Destruct(*this);
            Move_Construct(*this, nkr::Move(other));
        }
        return *this;
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline volatile dynamic_t<charcoder_p, allocator_p, grow_rate_p>&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::operator =(is_just_volatile_tr<dynamic_t> auto&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            Destruct(*this);
            Move_Construct(*this, nkr::Move(other));
        }
        return *this;
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<charcoder_p, allocator_p, grow_rate_p>::~dynamic_t()
    {
        Destruct(*this);
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
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit_Capacity(count_t unit_capacity_including_null)
    {
        return nkr::Move(Unit_Capacity(*this, unit_capacity_including_null));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit_Capacity(count_t unit_capacity_including_null)
        volatile
    {
        return nkr::Move(Unit_Capacity(*this, unit_capacity_including_null));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline some_t<const typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::unit_t*>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::C_String()
        const
    {
        return C_String(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline some_t<const typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::unit_t*>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::C_String()
        const volatile
    {
        return C_String(*this);
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

}}
