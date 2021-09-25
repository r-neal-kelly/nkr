/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/enum_flags_t_dec.h"
#include "nkr/math.h"
#include "nkr/utils.h"

namespace nkr {

    template <integer_unsigned_tr value_p>
    inline constexpr index_t
        enum_flags_t<value_p>::Min_Index()
    {
        return 0;
    }

    template <integer_unsigned_tr value_p>
    inline constexpr index_t
        enum_flags_t<value_p>::Max_Index()
    {
        return (sizeof(value_t) * 8) - 1;
    }

    template <integer_unsigned_tr value_p>
    template <index_t index_p>
    inline constexpr typename enum_flags_t<value_p>::value_t
        enum_flags_t<value_p>::Define()
    {
        static_assert(index_p >= Min_Index());
        static_assert(index_p <= Max_Index());

        return static_cast<value_t>(1) << index_p;
    }

    template <integer_unsigned_tr value_p>
    inline enum_flags_t<value_p>::enum_flags_t() :
        value(0)
    {
    }

    template <integer_unsigned_tr value_p>
    inline enum_flags_t<value_p>::enum_flags_t(value_t value) :
        value(value)
    {
    }

    template <integer_unsigned_tr value_p>
    inline enum_flags_t<value_p>::enum_flags_t(const enum_flags_t& other) :
        value(other.value)
    {
    }

    template <integer_unsigned_tr value_p>
    inline enum_flags_t<value_p>::enum_flags_t(const volatile enum_flags_t& other) :
        value(other.value)
    {
    }

    template <integer_unsigned_tr value_p>
    inline enum_flags_t<value_p>::enum_flags_t(enum_flags_t&& other) noexcept :
        value(nkr::Move(other.value))
    {
    }

    template <integer_unsigned_tr value_p>
    inline enum_flags_t<value_p>::enum_flags_t(volatile enum_flags_t&& other) noexcept :
        value(nkr::Move(other.value))
    {
    }

    template <integer_unsigned_tr value_p>
    inline enum_flags_t<value_p>&
        enum_flags_t<value_p>::operator =(value_t value)
    {
        this->value = value;
        return *this;
    }

    template <integer_unsigned_tr value_p>
    inline volatile enum_flags_t<value_p>&
        enum_flags_t<value_p>::operator =(value_t value)
        volatile
    {
        this->value = value;
        return *this;
    }

    template <integer_unsigned_tr value_p>
    inline enum_flags_t<value_p>&
        enum_flags_t<value_p>::operator =(const enum_flags_t& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <integer_unsigned_tr value_p>
    inline volatile enum_flags_t<value_p>&
        enum_flags_t<value_p>::operator =(const enum_flags_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <integer_unsigned_tr value_p>
    inline enum_flags_t<value_p>&
        enum_flags_t<value_p>::operator =(const volatile enum_flags_t& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <integer_unsigned_tr value_p>
    inline volatile enum_flags_t<value_p>&
        enum_flags_t<value_p>::operator =(const volatile enum_flags_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <integer_unsigned_tr value_p>
    inline enum_flags_t<value_p>&
        enum_flags_t<value_p>::operator =(enum_flags_t&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    template <integer_unsigned_tr value_p>
    inline volatile enum_flags_t<value_p>&
        enum_flags_t<value_p>::operator =(enum_flags_t&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    template <integer_unsigned_tr value_p>
    inline enum_flags_t<value_p>&
        enum_flags_t<value_p>::operator =(volatile enum_flags_t&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    template <integer_unsigned_tr value_p>
    inline volatile enum_flags_t<value_p>&
        enum_flags_t<value_p>::operator =(volatile enum_flags_t&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    template <integer_unsigned_tr value_p>
    inline enum_flags_t<value_p>::~enum_flags_t()
    {
        if constexpr (any_non_const_tr<value_t>) {
            this->value = 0;
        }
    }

    template <integer_unsigned_tr value_p>
    inline typename enum_flags_t<value_p>::value_t
        enum_flags_t<value_p>::Flags()
        const
    {
        return this->value;
    }

    template <integer_unsigned_tr value_p>
    inline typename enum_flags_t<value_p>::value_t
        enum_flags_t<value_p>::Flags()
        const volatile
    {
        return this->value;
    }

    template <integer_unsigned_tr value_p>
    inline bool_t
        enum_flags_t<value_p>::Is_Flagged(value_t flag)
        const
    {
        assert(math::Is_Power_Of_2(flag));

        return (this->value & flag) != 0;
    }

    template <integer_unsigned_tr value_p>
    inline bool_t
        enum_flags_t<value_p>::Is_Flagged(value_t flag)
        const volatile
    {
        assert(math::Is_Power_Of_2(flag));

        return (this->value & flag) != 0;
    }

    template <integer_unsigned_tr value_p>
    inline void_t
        enum_flags_t<value_p>::Flag(value_t flag)
    {
        assert(math::Is_Power_Of_2(flag));

        this->value |= flag;
    }

    template <integer_unsigned_tr value_p>
    inline void_t
        enum_flags_t<value_p>::Flag(value_t flag)
        volatile
    {
        assert(math::Is_Power_Of_2(flag));

        this->value |= flag;
    }

    template <integer_unsigned_tr value_p>
    inline void_t
        enum_flags_t<value_p>::Unflag(value_t flag)
    {
        assert(math::Is_Power_Of_2(flag));

        this->value &= ~flag;
    }

    template <integer_unsigned_tr value_p>
    inline void_t
        enum_flags_t<value_p>::Unflag(value_t flag)
        volatile
    {
        assert(math::Is_Power_Of_2(flag));

        this->value &= ~flag;
    }

}
