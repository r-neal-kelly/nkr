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
    inline const typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::unit_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::DEFAULT_C_STRING[1] = { 0 };

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline auto&
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Copy_Assign(is_any_non_const_tr<dynamic_t> auto& self,
                                                                      const is_any_tr<dynamic_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            self.array = other.array;
            if (self.array.Has_Memory()) {
                self.point_count = other.point_count;
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
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Unit_Capacity(is_any_tr<dynamic_t> auto& self, count_t unit_capacity_including_terminus)
    {
        return nkr::Move(self.array.Capacity(unit_capacity_including_terminus));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline some_t<const typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::unit_t*>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::C_String(const is_any_tr<dynamic_t> auto& self)
    {
        if (Has_Memory(self)) {
            return self.array.Pointer().Units();
        } else {
            return DEFAULT_C_STRING;
        }
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::iterator_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Prefix(const is_any_tr<dynamic_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));

        return iterator_t(&self, position_e::prefix_tg());
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::iterator_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::First(const is_any_tr<dynamic_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));

        return iterator_t(&self, position_e::first_tg());
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::iterator_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Last(const is_any_tr<dynamic_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));

        return iterator_t(&self, position_e::last_tg());
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::iterator_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Terminus(const is_any_tr<dynamic_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));

        return iterator_t(&self, position_e::terminus_tg());
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::iterator_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Postfix(const is_any_tr<dynamic_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));

        return iterator_t(&self, position_e::postfix_tg());
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::iterator_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::At(const is_any_tr<dynamic_t> auto& self, index_t point_index)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));
        nkr_ASSERT_THAT(point_index < self.point_count);

        return iterator_t(&self, point_index);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push_Terminus(is_any_tr<dynamic_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Memory(self));
        nkr_ASSERT_THAT(!Has_Terminus(self));
        nkr_ASSERT_THAT(Unit_Count(self) < Unit_Capacity(self));

        self.array.Push(0).Ignore_Error();
        self.point_count += 1;
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Pop_Terminus(is_any_tr<dynamic_t> auto& self)
    {
        if (Has_Terminus(self)) {
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
            maybe_t<allocator_err> err = Unit_Capacity(self, unit_count + charcoder_length);
            if (err) {
                return err;
            } else {
                Pop_Terminus(self);

                for (index_t idx = 0, end = charcoder_length; idx < end; idx += 1) {
                    self.array.Push(charcoder[idx]).Ignore_Error();
                }
                self.point_count += 1;

                Push_Terminus(self);

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
                Pop_Terminus(self);

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
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(is_any_tr<dynamic_t> auto& self, any_string_tr auto& other)
    {
        using other_charcoder_t = std::remove_reference_t<decltype(other)>::charcoder_t;

        if constexpr (is_tr<charcoder_t, other_charcoder_t>) {
            // can probably just call Copy_From

            count_t unit_length = Unit_Length(self);
            count_t other_unit_count = other.Unit_Count();

            if (math::Will_Overflow_Add(unit_length, other_unit_count)) {
                return allocator_err::OUT_OF_MEMORY;
            } else {
                maybe_t<allocator_err> err = Unit_Capacity(self, unit_length + other_unit_count);
                if (err) {
                    return err;
                } else {
                    Pop_Terminus(self);

                    for (index_t idx = 0, end = other_unit_count; idx < end; idx += 1) {
                        self.array.Push(other[idx]).Ignore_Error();
                    }

                    return allocator_err::NONE;
                }
            }
        } else {
            const count_t unit_length = Unit_Length(self);
            const count_t unit_count = Unit_Count(self);
            const count_t point_length = Point_Length(self);

            // for these we have to deallocate on failure and try to call fit, ignoring failure. don't forget to add back terminus on failure

            Pop_Terminus(*this);

            // would be nice to use iterator here
            charcoder_t charcoder;
            other_charcoder_t other_charcoder;

        }
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
        array(),
        point_count(0)
    {
        // we allow a non-allocated state for the sake of memory recovery and also because it can be inefficient
        // just to allocate for terminus when the user actually wants more. this allows for cheap declarations.
        // we don't use a static pointer either because it doesn't seem worth it at this time to check it constantly.
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
    inline typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::iterator_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Prefix()
        const
    {
        return Prefix(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::iterator_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Prefix()
        const volatile
    {
        return Prefix(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::iterator_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::First()
        const
    {
        return First(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::iterator_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::First()
        const volatile
    {
        return First(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::iterator_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Last()
        const
    {
        return Last(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::iterator_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Last()
        const volatile
    {
        return Last(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::iterator_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Terminus()
        const
    {
        return Terminus(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::iterator_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Terminus()
        const volatile
    {
        return Terminus(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::iterator_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Postfix()
        const
    {
        return Postfix(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::iterator_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Postfix()
        const volatile
    {
        return Postfix(*this);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::iterator_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::At(index_t point_index)
        const
    {
        return At(*this, point_index);
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<charcoder_p, allocator_p, grow_rate_p>::iterator_t
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::At(index_t point_index)
        const volatile
    {
        return At(*this, point_index);
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
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(any_string_tr auto& string)
    {
        return nkr::Move(Push(*this, string));
    }

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<charcoder_p, allocator_p, grow_rate_p>::Push(any_string_tr auto& string)
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
