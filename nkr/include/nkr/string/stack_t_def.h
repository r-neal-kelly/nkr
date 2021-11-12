/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/math.h"
#include "nkr/utils.h"

#include "nkr/string_itr_def.h"
#include "nkr/string/stack_t_dec.h"

namespace nkr { namespace string {

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline constexpr count_t
        stack_t<charcoder_p, unit_capacity_p>::Unit_Capacity()
    {
        return unit_capacity_p;
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline const typename stack_t<charcoder_p, unit_capacity_p>::unit_t*
        stack_t<charcoder_p, unit_capacity_p>::Empty_C_String()
    {
        static const unit_t default_c_string[1] = { 0 };

        return default_c_string;
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline auto&
        stack_t<charcoder_p, unit_capacity_p>::Copy_Assign(is_any_non_const_tr<stack_t> auto& self, const is_any_tr<stack_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            self.point_count = other.point_count;
            self.array = other.array;
        }

        return self;
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline auto&
        stack_t<charcoder_p, unit_capacity_p>::Move_Assign(is_any_non_const_tr<stack_t> auto& self, is_any_non_const_tr<stack_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            self.point_count = nkr::Move(other.point_count);
            self.array = nkr::Move(other.array);
        }

        return self;
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline bool_t
        stack_t<charcoder_p, unit_capacity_p>::Has_Terminus(const is_any_tr<stack_t> auto& self)
    {
        count_t unit_count = Unit_Count(self);

        return unit_count > 0 && self.array[unit_count - 1] == 0;
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline count_t
        stack_t<charcoder_p, unit_capacity_p>::Unit_Capacity(const is_any_tr<stack_t> auto& self)
    {
        return Unit_Capacity();
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline maybe_t<allocator_err>
        stack_t<charcoder_p, unit_capacity_p>::Unit_Capacity(is_any_non_const_tr<stack_t> auto& self, count_t unit_capacity_including_terminus)
    {
        // I think it would be an anit-pattern to allow otherwise, because it breaks the point count and possibly the last point before terminus
        nkr_ASSERT_THAT(Unit_Count(self) <= unit_capacity_including_terminus);

        return nkr::Move(self.array.Capacity(unit_capacity_including_terminus));
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline count_t
        stack_t<charcoder_p, unit_capacity_p>::Unit_Count(const is_any_tr<stack_t> auto& self)
    {
        return self.array.Count();
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline count_t
        stack_t<charcoder_p, unit_capacity_p>::Unit_Length(const is_any_tr<stack_t> auto& self)
    {
        if (Has_Terminus(self)) {
            return Unit_Count(self) - 1;
        } else {
            return Unit_Count(self);
        }
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline count_t
        stack_t<charcoder_p, unit_capacity_p>::Point_Count(const is_any_tr<stack_t> auto& self)
    {
        return self.point_count;
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline count_t
        stack_t<charcoder_p, unit_capacity_p>::Point_Length(const is_any_tr<stack_t> auto& self)
    {
        if (Has_Terminus(self)) {
            return Point_Count(self) - 1;
        } else {
            return Point_Count(self);
        }
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline auto
        stack_t<charcoder_p, unit_capacity_p>::C_String(const is_any_tr<stack_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));

        return &self.array[0];
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline auto
        stack_t<charcoder_p, unit_capacity_p>::At(const is_any_tr<stack_t> auto& self, index_t point_index)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));
        nkr_ASSERT_THAT(point_index < Point_Count(self));

        return string_itr<std::remove_reference_t<decltype(self)>>(self, point_index);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline auto
        stack_t<charcoder_p, unit_capacity_p>::At_Prefix(const is_any_tr<stack_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));

        return string_itr<std::remove_reference_t<decltype(self)>>(self, position_e::prefix_tg());
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline auto
        stack_t<charcoder_p, unit_capacity_p>::At_First(const is_any_tr<stack_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));

        return string_itr<std::remove_reference_t<decltype(self)>>(self, position_e::first_tg());
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline auto
        stack_t<charcoder_p, unit_capacity_p>::At_Last(const is_any_tr<stack_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));

        return string_itr<std::remove_reference_t<decltype(self)>>(self, position_e::last_tg());
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline auto
        stack_t<charcoder_p, unit_capacity_p>::At_Terminus(const is_any_tr<stack_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));

        return string_itr<std::remove_reference_t<decltype(self)>>(self, position_e::terminus_tg());
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline auto
        stack_t<charcoder_p, unit_capacity_p>::At_Postfix(const is_any_tr<stack_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));

        return string_itr<std::remove_reference_t<decltype(self)>>(self, position_e::postfix_tg());
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline void_t
        stack_t<charcoder_p, unit_capacity_p>::Push_Terminus(is_any_non_const_tr<stack_t> auto& self)
    {
        nkr_ASSERT_THAT(!Has_Terminus(self));
        nkr_ASSERT_THAT(Unit_Count(self) < Unit_Capacity(self));

        self.array.Push(unit_t(0)).Ignore_Error();
        self.point_count += 1;
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline void_t
        stack_t<charcoder_p, unit_capacity_p>::Pop_Terminus(is_any_non_const_tr<stack_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));

        self.array.Pop();
        self.point_count -= 1;
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline maybe_t<allocator_err>
        stack_t<charcoder_p, unit_capacity_p>::Push(is_any_non_const_tr<stack_t> auto& self, point_t point)
    {
        nkr_ASSERT_THAT(point > 0);
        nkr_ASSERT_THAT(Has_Terminus(self));

        charcoder_t charcoder;
        charcoder.Encode(point);

        return nkr::Move(Push(self, charcoder));
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline maybe_t<allocator_err>
        stack_t<charcoder_p, unit_capacity_p>::Push(is_any_non_const_tr<stack_t> auto& self, const charcoder_t& charcoder)
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

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline maybe_t<allocator_err>
        stack_t<charcoder_p, unit_capacity_p>::Push(is_any_non_const_tr<stack_t> auto& self, any_c_pointer_of_any_tr<unit_t> auto c_string)
    {
        nkr_ASSERT_THAT(c_string);
        nkr_ASSERT_THAT(Has_Terminus(self));

        return nkr::Move(Push(self, c_string, C_String_Unit_Length(c_string)));
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline maybe_t<allocator_err>
        stack_t<charcoder_p, unit_capacity_p>::Push(is_any_non_const_tr<stack_t> auto& self,
                                                    any_c_pointer_of_any_tr<unit_t> auto c_string,
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
                Pop_Terminus(self);

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

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline maybe_t<allocator_err>
        stack_t<charcoder_p, unit_capacity_p>::Push(is_any_non_const_tr<stack_t> auto& self, const any_string_tr auto& other)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));
        nkr_ASSERT_THAT(other.Has_Terminus());

        if constexpr (is_tr<charcoder_t, typename std::remove_reference_t<decltype(other)>::charcoder_t>) {
            Pop_Terminus(self);

            maybe_t<allocator_err> err = self.array.Copy_From(other.array);
            if (err) {
                Push_Terminus(self);

                return err;
            } else {
                self.point_count += other.point_count;

                return allocator_err::NONE;
            }
        } else {
            const count_t original_point_length = Point_Length(self);
            const count_t other_point_count = other.Point_Count();
            if (math::Will_Overflow_Add(original_point_length, other_point_count)) {
                return allocator_err::OUT_OF_MEMORY;
            } else {
                const count_t original_capacity = Unit_Capacity(self);
                const count_t original_unit_length = Unit_Length(self);

                Pop_Terminus(self);

                charcoder_t charcoder;
                maybe_t<allocator_err> err = allocator_err::NONE;
                for (auto other_itr = other.At_First(); !other_itr.Is_At_Postfix(); other_itr += 1) {
                    charcoder.Encode(other_itr.Point());
                    for (index_t idx = 0, end = charcoder.Unit_Count(); idx < end; idx += 1) {
                        err = self.array.Push(charcoder[idx]);
                        if (err) {
                            self.array.Capacity(original_capacity);
                            while (self.unit_count > original_unit_length) {
                                self.array.Pop();
                            }
                            self.point_count = original_point_length;

                            Push_Terminus(self);

                            return err;
                        }
                    }
                    self.point_count += 1;
                }
            }
        }
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline maybe_t<allocator_err>
        stack_t<charcoder_p, unit_capacity_p>::Push(is_any_non_const_tr<stack_t> auto& self, any_non_const_string_tr auto&& other)
    {
        nkr_ASSERT_THAT(Has_Terminus(self));
        nkr_ASSERT_THAT(other.Has_Terminus());

        if constexpr (is_tr<charcoder_t, typename std::remove_reference_t<decltype(other)>::charcoder_t>) {
            Pop_Terminus(self);

            maybe_t<allocator_err> err = self.array.Move_From(other.array);
            if (err) {
                Push_Terminus(self);

                return err;
            } else {
                self.point_count += nkr::Move(other.point_count);

                return allocator_err::NONE;
            }
        } else {
            return nkr::Move(Push(self, other));
        }
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline auto&
        stack_t<charcoder_p, unit_capacity_p>::Unit(is_any_tr<stack_t> auto& self, index_t unit_index)
    {
        nkr_ASSERT_THAT(unit_index < Unit_Count(self));

        return self.array[unit_index];
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline stack_t<charcoder_p, unit_capacity_p>::stack_t() :
        point_count(1),
        array{ unit_t(0) }
    {
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline stack_t<charcoder_p, unit_capacity_p>::stack_t(const charcoder_t& charcoder) :
        stack_t()
    {
        if (charcoder.Decode() > 0) {
            Push(*this, charcoder).Ignore_Error();
        }
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline stack_t<charcoder_p, unit_capacity_p>::stack_t(any_c_pointer_of_any_tr<unit_t> auto c_string) :
        stack_t()
    {
        nkr_ASSERT_THAT(c_string);

        Push(*this, c_string).Ignore_Error();
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline stack_t<charcoder_p, unit_capacity_p>::stack_t(any_maybe_of_any_c_pointer_of_any_tr<unit_t> auto maybe_c_string) :
        stack_t()
    {
        if (maybe_c_string) {
            Push(*this, maybe_c_string()).Ignore_Error();
        }
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline stack_t<charcoder_p, unit_capacity_p>::stack_t(any_some_of_any_c_pointer_of_any_tr<unit_t> auto some_c_string) :
        stack_t()
    {
        nkr_ASSERT_THAT(some_c_string);

        Push(*this, some_c_string()).Ignore_Error();
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline stack_t<charcoder_p, unit_capacity_p>::stack_t(const any_string_tr auto& string) :
        stack_t()
    {
        Push(*this, string).Ignore_Error();
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline stack_t<charcoder_p, unit_capacity_p>::stack_t(any_non_const_string_tr auto&& string) :
        stack_t()
    {
        Push(*this, nkr::Move(string)).Ignore_Error();
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline stack_t<charcoder_p, unit_capacity_p>::stack_t(const stack_t& other) :
        point_count(other.point_count),
        array(other.array)
    {
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline stack_t<charcoder_p, unit_capacity_p>::stack_t(const volatile stack_t& other) :
        point_count(other.point_count),
        array(other.array)
    {
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline stack_t<charcoder_p, unit_capacity_p>::stack_t(stack_t&& other) noexcept :
        point_count(nkr::Move(other.point_count)),
        array(nkr::Move(other.array))
    {
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline stack_t<charcoder_p, unit_capacity_p>::stack_t(volatile stack_t&& other) noexcept :
        point_count(nkr::Move(other.point_count)),
        array(nkr::Move(other.array))
    {
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline stack_t<charcoder_p, unit_capacity_p>&
        stack_t<charcoder_p, unit_capacity_p>::operator =(const stack_t& other)
    {
        return Copy_Assign(*this, other);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline volatile stack_t<charcoder_p, unit_capacity_p>&
        stack_t<charcoder_p, unit_capacity_p>::operator =(const stack_t& other)
        volatile
    {
        return Copy_Assign(*this, other);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline stack_t<charcoder_p, unit_capacity_p>&
        stack_t<charcoder_p, unit_capacity_p>::operator =(const volatile stack_t& other)
    {
        return Copy_Assign(*this, other);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline volatile stack_t<charcoder_p, unit_capacity_p>&
        stack_t<charcoder_p, unit_capacity_p>::operator =(const volatile stack_t& other)
        volatile
    {
        return Copy_Assign(*this, other);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline stack_t<charcoder_p, unit_capacity_p>&
        stack_t<charcoder_p, unit_capacity_p>::operator =(stack_t&& other)
        noexcept
    {
        return Move_Assign(*this, other);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline volatile stack_t<charcoder_p, unit_capacity_p>&
        stack_t<charcoder_p, unit_capacity_p>::operator =(stack_t&& other)
        volatile noexcept
    {
        return Move_Assign(*this, other);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline stack_t<charcoder_p, unit_capacity_p>&
        stack_t<charcoder_p, unit_capacity_p>::operator =(is_just_volatile_tr<stack_t> auto&& other)
        noexcept
    {
        return Move_Assign(*this, other);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline volatile stack_t<charcoder_p, unit_capacity_p>&
        stack_t<charcoder_p, unit_capacity_p>::operator =(is_just_volatile_tr<stack_t> auto&& other)
        volatile noexcept
    {
        return Move_Assign(*this, other);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline stack_t<charcoder_p, unit_capacity_p>::~stack_t()
    {
        this->point_count = 0;
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline bool_t
        stack_t<charcoder_p, unit_capacity_p>::Has_Terminus()
        const
    {
        return Has_Terminus(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline bool_t
        stack_t<charcoder_p, unit_capacity_p>::Has_Terminus()
        const volatile
    {
        return Has_Terminus(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline maybe_t<allocator_err>
        stack_t<charcoder_p, unit_capacity_p>::Unit_Capacity(count_t unit_capacity_including_terminus)
    {
        return nkr::Move(Unit_Capacity(*this, unit_capacity_including_terminus));
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline maybe_t<allocator_err>
        stack_t<charcoder_p, unit_capacity_p>::Unit_Capacity(count_t unit_capacity_including_terminus)
        volatile
    {
        return nkr::Move(Unit_Capacity(*this, unit_capacity_including_terminus));
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline count_t
        stack_t<charcoder_p, unit_capacity_p>::Unit_Count()
        const
    {
        return Unit_Count(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline count_t
        stack_t<charcoder_p, unit_capacity_p>::Unit_Count()
        const volatile
    {
        return Unit_Count(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline count_t
        stack_t<charcoder_p, unit_capacity_p>::Unit_Length()
        const
    {
        return Unit_Length(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline count_t
        stack_t<charcoder_p, unit_capacity_p>::Unit_Length()
        const volatile
    {
        return Unit_Length(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline count_t
        stack_t<charcoder_p, unit_capacity_p>::Point_Count()
        const
    {
        return Point_Count(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline count_t
        stack_t<charcoder_p, unit_capacity_p>::Point_Count()
        const volatile
    {
        return Point_Count(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline count_t
        stack_t<charcoder_p, unit_capacity_p>::Point_Length()
        const
    {
        return Point_Length(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline count_t
        stack_t<charcoder_p, unit_capacity_p>::Point_Length()
        const volatile
    {
        return Point_Length(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline some_t<const typename stack_t<charcoder_p, unit_capacity_p>::unit_t*>
        stack_t<charcoder_p, unit_capacity_p>::C_String()
        const
    {
        return C_String(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline some_t<const volatile typename stack_t<charcoder_p, unit_capacity_p>::unit_t*>
        stack_t<charcoder_p, unit_capacity_p>::C_String()
        const volatile
    {
        return C_String(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline string_itr<const stack_t<charcoder_p, unit_capacity_p>>
        stack_t<charcoder_p, unit_capacity_p>::At(index_t point_index)
        const
    {
        return At(*this, point_index);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline string_itr<const volatile stack_t<charcoder_p, unit_capacity_p>>
        stack_t<charcoder_p, unit_capacity_p>::At(index_t point_index)
        const volatile
    {
        return At(*this, point_index);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline string_itr<const stack_t<charcoder_p, unit_capacity_p>>
        stack_t<charcoder_p, unit_capacity_p>::At_Prefix()
        const
    {
        return At_Prefix(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline string_itr<const volatile stack_t<charcoder_p, unit_capacity_p>>
        stack_t<charcoder_p, unit_capacity_p>::At_Prefix()
        const volatile
    {
        return At_Prefix(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline string_itr<const stack_t<charcoder_p, unit_capacity_p>>
        stack_t<charcoder_p, unit_capacity_p>::At_First()
        const
    {
        return At_First(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline string_itr<const volatile stack_t<charcoder_p, unit_capacity_p>>
        stack_t<charcoder_p, unit_capacity_p>::At_First()
        const volatile
    {
        return At_First(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline string_itr<const stack_t<charcoder_p, unit_capacity_p>>
        stack_t<charcoder_p, unit_capacity_p>::At_Last()
        const
    {
        return At_Last(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline string_itr<const volatile stack_t<charcoder_p, unit_capacity_p>>
        stack_t<charcoder_p, unit_capacity_p>::At_Last()
        const volatile
    {
        return At_Last(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline string_itr<const stack_t<charcoder_p, unit_capacity_p>>
        stack_t<charcoder_p, unit_capacity_p>::At_Terminus()
        const
    {
        return At_Terminus(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline string_itr<const volatile stack_t<charcoder_p, unit_capacity_p>>
        stack_t<charcoder_p, unit_capacity_p>::At_Terminus()
        const volatile
    {
        return At_Terminus(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline string_itr<const stack_t<charcoder_p, unit_capacity_p>>
        stack_t<charcoder_p, unit_capacity_p>::At_Postfix()
        const
    {
        return At_Postfix(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline string_itr<const volatile stack_t<charcoder_p, unit_capacity_p>>
        stack_t<charcoder_p, unit_capacity_p>::At_Postfix()
        const volatile
    {
        return At_Postfix(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline maybe_t<allocator_err>
        stack_t<charcoder_p, unit_capacity_p>::Push(point_t point)
    {
        return nkr::Move(Push(*this, point));
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline maybe_t<allocator_err>
        stack_t<charcoder_p, unit_capacity_p>::Push(point_t point)
        volatile
    {
        return nkr::Move(Push(*this, point));
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline maybe_t<allocator_err>
        stack_t<charcoder_p, unit_capacity_p>::Push(const charcoder_t& charcoder)
    {
        return nkr::Move(Push(*this, charcoder));
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline maybe_t<allocator_err>
        stack_t<charcoder_p, unit_capacity_p>::Push(const charcoder_t& charcoder)
        volatile
    {
        return nkr::Move(Push(*this, charcoder));
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline maybe_t<allocator_err>
        stack_t<charcoder_p, unit_capacity_p>::Push(const is_any_tr<unit_t> auto* c_string)
    {
        return nkr::Move(Push(*this, c_string));
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline maybe_t<allocator_err>
        stack_t<charcoder_p, unit_capacity_p>::Push(const is_any_tr<unit_t> auto* c_string)
        volatile
    {
        return nkr::Move(Push(*this, c_string));
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline maybe_t<allocator_err>
        stack_t<charcoder_p, unit_capacity_p>::Push(const is_any_tr<unit_t> auto* c_string, count_t unit_length)
    {
        return nkr::Move(Push(*this, c_string, unit_length));
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline maybe_t<allocator_err>
        stack_t<charcoder_p, unit_capacity_p>::Push(const is_any_tr<unit_t> auto* c_string, count_t unit_length)
        volatile
    {
        return nkr::Move(Push(*this, c_string, unit_length));
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline maybe_t<allocator_err>
        stack_t<charcoder_p, unit_capacity_p>::Push(const any_string_tr auto& string)
    {
        return nkr::Move(Push(*this, string));
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline maybe_t<allocator_err>
        stack_t<charcoder_p, unit_capacity_p>::Push(const any_string_tr auto& string)
        volatile
    {
        return nkr::Move(Push(*this, string));
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline maybe_t<allocator_err>
        stack_t<charcoder_p, unit_capacity_p>::Push(any_non_const_string_tr auto&& string)
    {
        return nkr::Move(Push(*this, nkr::Move(string)));
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline maybe_t<allocator_err>
        stack_t<charcoder_p, unit_capacity_p>::Push(any_non_const_string_tr auto&& string)
        volatile
    {
        return nkr::Move(Push(*this, nkr::Move(string)));
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline typename stack_t<charcoder_p, unit_capacity_p>::unit_t&
        stack_t<charcoder_p, unit_capacity_p>::Unit(index_t unit_index)
    {
        return Unit(*this, unit_index);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline const typename stack_t<charcoder_p, unit_capacity_p>::unit_t&
        stack_t<charcoder_p, unit_capacity_p>::Unit(index_t unit_index) const
    {
        return Unit(*this, unit_index);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline volatile typename stack_t<charcoder_p, unit_capacity_p>::unit_t&
        stack_t<charcoder_p, unit_capacity_p>::Unit(index_t unit_index) volatile
    {
        return Unit(*this, unit_index);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline const volatile typename stack_t<charcoder_p, unit_capacity_p>::unit_t&
        stack_t<charcoder_p, unit_capacity_p>::Unit(index_t unit_index) const volatile
    {
        return Unit(*this, unit_index);
    }

}}

namespace nkr {

    template <tr1<any_tg, string::stack_tg> string_p, count_t min_point_count_p, count_t max_point_count_p>
    inline auto Random(bool_t use_errorneous_units)
    {
        using string_t = string_p;
        using charcoder_t = string_t::charcoder_t;
        using unit_t = string_t::unit_t;

        nkr_ASSERT_THAT(min_point_count_p >= 1);
        nkr_ASSERT_THAT(max_point_count_p >= 1);
        nkr_ASSERT_THAT(min_point_count_p <= max_point_count_p);

        const count_t point_count = nkr::Random<count_t>(min_point_count_p, max_point_count_p);
        string::stack_t<charcoder_t, max_point_count_p * charcoder_t::Max_Unit_Count()> string;
        if (use_errorneous_units) {
            array::stack_t<unit_t, charcoder_t::Max_Unit_Count()> units;
            for (index_t idx = 0, end = point_count - 1; idx < end; idx += 1) {
                for (index_t idx = 0, end = Random<count_t>(1, units.Capacity()); idx < end; idx += 1) {
                    units.Push(Random<unit_t>(1)).Ignore_Error();
                }
                string.Push(units.Array(), units.Count()).Ignore_Error();
                units.Clear();
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
