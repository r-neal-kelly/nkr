/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/utils.h"

#include "nkr/string_itr_def.h"
#include "nkr/string/static_t_dec.h"

namespace nkr { namespace string {

    template <charcoder_i charcoder_p>
    inline constexpr c_bool_t
        static_t<charcoder_p>::Has_Guaranteed_Terminus()
    {
        return false;
    }

    template <charcoder_i charcoder_p>
    inline const typename static_t<charcoder_p>::unit_t*
        static_t<charcoder_p>::Empty_C_String()
    {
        static const unit_t default_c_string[1] = { 0 };

        return default_c_string;
    }

    template <charcoder_i charcoder_p>
    inline auto&
        static_t<charcoder_p>::Copy_Assign(is_any_non_const_tr<static_t> auto& self, const is_any_tr<static_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            self.point_count = other.point_count;
            self.array = other.array;
        }

        return self;
    }

    template <charcoder_i charcoder_p>
    inline auto&
        static_t<charcoder_p>::Move_Assign(is_any_non_const_tr<static_t> auto& self, is_any_non_const_tr<static_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            self.point_count = nkr::Move(other.point_count);
            self.array = nkr::Move(other.array);
        }

        return self;
    }

    template <charcoder_i charcoder_p>
    inline bool_t
        static_t<charcoder_p>::Has_Terminus(const is_any_tr<static_t> auto& self)
    {
        count_t unit_count = Unit_Count(self);

        return unit_count > 0 && self.array[unit_count - 1] == 0;
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Unit_Count(const is_any_tr<static_t> auto& self)
    {
        return self.array.Count();
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Unit_Length(const is_any_tr<static_t> auto& self)
    {
        count_t unit_count = Unit_Count(self);
        if (unit_count > 0 && self.array[unit_count - 1] == 0) {
            return unit_count - 1;
        } else {
            return unit_count;
        }
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Point_Count(const is_any_tr<static_t> auto& self)
    {
        return self.point_count;
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Point_Length(const is_any_tr<static_t> auto& self)
    {
        count_t point_count = Point_Count(self);
        if (point_count > 0 && Has_Terminus(self)) {
            return point_count - 1;
        } else {
            return point_count;
        }
    }

    template <charcoder_i charcoder_p>
    inline auto
        static_t<charcoder_p>::C_String(const is_any_tr<static_t> auto& self)
    {
        return &self.array[0];
    }

    template <charcoder_i charcoder_p>
    inline auto&
        static_t<charcoder_p>::Unit(is_any_tr<static_t> auto& self, index_t unit_index)
    {
        nkr_ASSERT_THAT(self.array.Count() > unit_index);

        return self.array[unit_index];
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(tr1<any_tg, unit_t*> auto c_string) :
        static_t(some_t<unit_t*>(c_string))
    {
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(tr1<any_tg, unit_t*> auto c_string,
                                           count_t unit_count,
                                           count_t point_count) :
        static_t(some_t<unit_t*>(c_string), unit_count, point_count)
    {
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(tr2<any_tg, some_t, of_any_tg, unit_t*> auto some_c_string) :
        point_count(0),
        array()
    {
        nkr_ASSERT_THAT(some_c_string);

        charcoder_t charcoder;
        count_t unit_count = 0;
        do {
            unit_count += charcoder.Read_Forward(some_c_string + unit_count);
            this->point_count += 1;
        } while (charcoder);

        this->array = pointer_t<unit_t>(some_c_string, unit_count);
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(tr2<any_tg, some_t, of_any_tg, unit_t*> auto some_c_string,
                                           count_t unit_count,
                                           count_t point_count) :
        point_count(point_count),
        array((nkr_ASSERT_THAT(some_c_string), pointer_t<unit_t>(some_c_string, unit_count)))
    {
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(const static_t& other) :
        point_count(other.point_count),
        array(other.array)
    {
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(const volatile static_t& other) :
        point_count(other.point_count),
        array(other.array)
    {
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(static_t&& other) noexcept :
        point_count(nkr::Move(other.point_count)),
        array(nkr::Move(other.array))
    {
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(volatile static_t&& other) noexcept :
        point_count(nkr::Move(other.point_count)),
        array(nkr::Move(other.array))
    {
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>&
        static_t<charcoder_p>::operator =(const static_t& other)
    {
        return Copy_Assign(*this, other);
    }

    template <charcoder_i charcoder_p>
    inline volatile static_t<charcoder_p>&
        static_t<charcoder_p>::operator =(const static_t& other)
        volatile
    {
        return Copy_Assign(*this, other);
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>&
        static_t<charcoder_p>::operator =(const volatile static_t& other)
    {
        return Copy_Assign(*this, other);
    }

    template <charcoder_i charcoder_p>
    inline volatile static_t<charcoder_p>&
        static_t<charcoder_p>::operator =(const volatile static_t& other)
        volatile
    {
        return Copy_Assign(*this, other);
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>&
        static_t<charcoder_p>::operator =(static_t&& other)
        noexcept
    {
        return Move_Assign(*this, other);
    }

    template <charcoder_i charcoder_p>
    inline volatile static_t<charcoder_p>&
        static_t<charcoder_p>::operator =(static_t&& other)
        volatile noexcept
    {
        return Move_Assign(*this, other);
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>&
        static_t<charcoder_p>::operator =(is_just_volatile_tr<static_t> auto&& other)
        noexcept
    {
        return Move_Assign(*this, other);
    }

    template <charcoder_i charcoder_p>
    inline volatile static_t<charcoder_p>&
        static_t<charcoder_p>::operator =(is_just_volatile_tr<static_t> auto&& other)
        volatile noexcept
    {
        return Move_Assign(*this, other);
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::~static_t()
    {
        this->point_count = 0;
    }

    template <charcoder_i charcoder_p>
    inline bool_t
        static_t<charcoder_p>::Has_Terminus()
        const
    {
        return Has_Terminus(*this);
    }

    template <charcoder_i charcoder_p>
    inline bool_t
        static_t<charcoder_p>::Has_Terminus()
        const volatile
    {
        return Has_Terminus(*this);
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Unit_Count()
        const
    {
        return Unit_Count(*this);
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Unit_Count()
        const volatile
    {
        return Unit_Count(*this);
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Unit_Length()
        const
    {
        return Unit_Length(*this);
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Unit_Length()
        const volatile
    {
        return Unit_Length(*this);
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Point_Count()
        const
    {
        return Point_Count(*this);
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Point_Count()
        const volatile
    {
        return Point_Count(*this);
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Point_Length()
        const
    {
        return Point_Length(*this);
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Point_Length()
        const volatile
    {
        return Point_Length(*this);
    }

    template <charcoder_i charcoder_p>
    inline some_t<const typename static_t<charcoder_p>::unit_t*>
        static_t<charcoder_p>::C_String()
        const
    {
        return C_String(*this);
    }

    template <charcoder_i charcoder_p>
    inline some_t<const volatile typename static_t<charcoder_p>::unit_t*>
        static_t<charcoder_p>::C_String()
        const volatile
    {
        return C_String(*this);
    }

    template <charcoder_i charcoder_p>
    inline typename static_t<charcoder_p>::unit_t&
        static_t<charcoder_p>::Unit(index_t unit_index)
    {
        return Unit(*this, unit_index);
    }

    template <charcoder_i charcoder_p>
    inline const typename static_t<charcoder_p>::unit_t&
        static_t<charcoder_p>::Unit(index_t unit_index)
        const
    {
        return Unit(*this, unit_index);
    }

    template <charcoder_i charcoder_p>
    inline volatile typename static_t<charcoder_p>::unit_t&
        static_t<charcoder_p>::Unit(index_t unit_index)
        volatile
    {
        return Unit(*this, unit_index);
    }

    template <charcoder_i charcoder_p>
    inline const volatile typename static_t<charcoder_p>::unit_t&
        static_t<charcoder_p>::Unit(index_t unit_index)
        const volatile
    {
        return Unit(*this, unit_index);
    }

}}
