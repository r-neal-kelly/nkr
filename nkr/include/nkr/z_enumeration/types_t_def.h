/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_utils.h"

#include "nkr/z_enumeration/types_t_dec.h"

namespace nkr { namespace enumeration { namespace types_t$ {

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline any_sp<value_p, actual_value_p, none_p>::any_sp() :
        value(NONE)
    {
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline any_sp<value_p, actual_value_p, none_p>::any_sp(value_t value) :
        value(value)
    {
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline any_sp<value_p, actual_value_p, none_p>::any_sp(const any_sp& other) :
        value(other.value)
    {
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline any_sp<value_p, actual_value_p, none_p>::any_sp(const volatile any_sp& other) :
        value(other.value)
    {
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline any_sp<value_p, actual_value_p, none_p>::any_sp(any_sp&& other) noexcept :
        value(nkr::Move(other.value))
    {
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline any_sp<value_p, actual_value_p, none_p>::any_sp(volatile any_sp&& other) noexcept :
        value(nkr::Move(other.value))
    {
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline any_sp<value_p, actual_value_p, none_p>&
        any_sp<value_p, actual_value_p, none_p>::operator =(const any_sp& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline volatile any_sp<value_p, actual_value_p, none_p>&
        any_sp<value_p, actual_value_p, none_p>::operator =(const any_sp& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline any_sp<value_p, actual_value_p, none_p>&
        any_sp<value_p, actual_value_p, none_p>::operator =(const volatile any_sp& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline volatile any_sp<value_p, actual_value_p, none_p>&
        any_sp<value_p, actual_value_p, none_p>::operator =(const volatile any_sp& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline any_sp<value_p, actual_value_p, none_p>&
        any_sp<value_p, actual_value_p, none_p>::operator =(any_sp&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline volatile any_sp<value_p, actual_value_p, none_p>&
        any_sp<value_p, actual_value_p, none_p>::operator =(any_sp&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline any_sp<value_p, actual_value_p, none_p>&
        any_sp<value_p, actual_value_p, none_p>::operator =(is_just_volatile_tr<any_sp> auto&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline volatile any_sp<value_p, actual_value_p, none_p>&
        any_sp<value_p, actual_value_p, none_p>::operator =(is_just_volatile_tr<any_sp> auto&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline any_sp<value_p, actual_value_p, none_p>::~any_sp()
    {
        this->value = NONE;
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline any_sp<value_p, actual_value_p, none_p>::operator actual_value_t&()
    {
        return this->value;
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline any_sp<value_p, actual_value_p, none_p>::operator const actual_value_t&()
        const
    {
        return this->value;
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline any_sp<value_p, actual_value_p, none_p>::operator volatile actual_value_t&()
        volatile
    {
        return this->value;
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline any_sp<value_p, actual_value_p, none_p>::operator const volatile actual_value_t&()
        const volatile
    {
        return this->value;
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline any_sp<value_p, actual_value_p, none_p>::operator c_bool_t()
        const
    {
        return this->value != NONE;
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline any_sp<value_p, actual_value_p, none_p>::operator c_bool_t()
        const volatile
    {
        return this->value != NONE;
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline any_sp<value_p, actual_value_p, none_p>::any_sp(none_t) :
        value(NONE)
    {
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline any_sp<value_p, actual_value_p, none_p>&
        any_sp<value_p, actual_value_p, none_p>::operator =(none_t)
    {
        this->value = NONE;
        return *this;
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline volatile any_sp<value_p, actual_value_p, none_p>&
        any_sp<value_p, actual_value_p, none_p>::operator =(none_t)
        volatile
    {
        this->value = NONE;
        return *this;
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline bool_t
        any_sp<value_p, actual_value_p, none_p>::operator ==(none_t)
        const
    {
        return this->value == NONE;
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline bool_t
        any_sp<value_p, actual_value_p, none_p>::operator ==(none_t)
        const volatile
    {
        return this->value == NONE;
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline bool_t
        any_sp<value_p, actual_value_p, none_p>::operator !=(none_t)
        const
    {
        return !operator =(none_t());
    }

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    inline bool_t
        any_sp<value_p, actual_value_p, none_p>::operator !=(none_t)
        const volatile
    {
        return !operator =(none_t());
    }

}}}
