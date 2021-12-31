/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/macros_def.h"
#include "nkr/utils.h"

#include "nkr/z_enumeration/errors_t_dec.h"

namespace nkr { namespace enumeration {

    template <integer_signed_tr integer_p, integer_p none_p>
    inline errors_t<integer_p, none_p>::errors_t() :
        has_been_checked(false),
        value(NONE)
    {
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline errors_t<integer_p, none_p>::errors_t(value_t value) :
        has_been_checked(false),
        value(value)
    {
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline errors_t<integer_p, none_p>::errors_t(const errors_t& other) :
        has_been_checked(false),
        value(other.value)
    {
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline errors_t<integer_p, none_p>::errors_t(const volatile errors_t& other) :
        has_been_checked(false),
        value(other.value)
    {
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline errors_t<integer_p, none_p>::errors_t(errors_t&& other) noexcept :
        has_been_checked(nkr::Exchange(other.has_been_checked, true)),
        value(nkr::Move(other.value))
    {
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline errors_t<integer_p, none_p>::errors_t(volatile errors_t&& other) noexcept :
        has_been_checked(nkr::Exchange(other.has_been_checked, true)),
        value(nkr::Move(other.value))
    {
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline errors_t<integer_p, none_p>&
        errors_t<integer_p, none_p>::operator =(const errors_t& other)
    {
        if (this != std::addressof(other)) {
            this->has_been_checked = false;
            this->value = other.value;
        }

        return *this;
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline volatile errors_t<integer_p, none_p>&
        errors_t<integer_p, none_p>::operator =(const errors_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->has_been_checked = false;
            this->value = other.value;
        }

        return *this;
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline errors_t<integer_p, none_p>&
        errors_t<integer_p, none_p>::operator =(const volatile errors_t& other)
    {
        if (this != std::addressof(other)) {
            this->has_been_checked = false;
            this->value = other.value;
        }

        return *this;
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline volatile errors_t<integer_p, none_p>&
        errors_t<integer_p, none_p>::operator =(const volatile errors_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->has_been_checked = false;
            this->value = other.value;
        }

        return *this;
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline errors_t<integer_p, none_p>&
        errors_t<integer_p, none_p>::operator =(errors_t&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->has_been_checked = nkr::Exchange(other.has_been_checked, true);
            this->value = nkr::Move(other.value);
        }

        return *this;
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline volatile errors_t<integer_p, none_p>&
        errors_t<integer_p, none_p>::operator =(errors_t&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->has_been_checked = nkr::Exchange(other.has_been_checked, true);
            this->value = nkr::Move(other.value);
        }

        return *this;
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline errors_t<integer_p, none_p>&
        errors_t<integer_p, none_p>::operator =(is_just_volatile_tr<errors_t> auto&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->has_been_checked = nkr::Exchange(other.has_been_checked, true);
            this->value = nkr::Move(other.value);
        }

        return *this;
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline volatile errors_t<integer_p, none_p>&
        errors_t<integer_p, none_p>::operator =(is_just_volatile_tr<errors_t> auto&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->has_been_checked = nkr::Exchange(other.has_been_checked, true);
            this->value = nkr::Move(other.value);
        }

        return *this;
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline errors_t<integer_p, none_p>::~errors_t()
    {
        nkr_ASSERT_THAT(this->has_been_checked);

        this->has_been_checked = true;
        this->value = NONE;
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline void_t errors_t<integer_p, none_p>::Ignore_Error()
    {
        this->has_been_checked = true;
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline errors_t<integer_p, none_p>::operator value_t()
        const
    {
        this->has_been_checked = true;

        return this->value;
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline errors_t<integer_p, none_p>::operator value_t()
        const volatile
    {
        this->has_been_checked = true;

        return this->value;
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline errors_t<integer_p, none_p>::operator c_bool_t()
        const
    {
        this->has_been_checked = true;

        return static_cast<c_bool_t>(this->value);
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline errors_t<integer_p, none_p>::operator c_bool_t()
        const volatile
    {
        this->has_been_checked = true;

        return static_cast<c_bool_t>(this->value);
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline errors_t<integer_p, none_p>::errors_t(none_t) :
        has_been_checked(false),
        value(NONE)
    {
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline errors_t<integer_p, none_p>&
        errors_t<integer_p, none_p>::operator =(none_t)
    {
        this->has_been_checked = false;
        this->value = NONE;

        return *this;
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline volatile errors_t<integer_p, none_p>&
        errors_t<integer_p, none_p>::operator =(none_t)
        volatile
    {
        this->has_been_checked = false;
        this->value = NONE;

        return *this;
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline bool_t
        errors_t<integer_p, none_p>::operator ==(none_t)
        const
    {
        this->has_been_checked = true;

        return this->value == NONE;
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline bool_t
        errors_t<integer_p, none_p>::operator ==(none_t)
        const volatile
    {
        this->has_been_checked = true;

        return this->value == NONE;
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline bool_t
        errors_t<integer_p, none_p>::operator !=(none_t)
        const
    {
        return !operator ==(none_t());
    }

    template <integer_signed_tr integer_p, integer_p none_p>
    inline bool_t
        errors_t<integer_p, none_p>::operator !=(none_t)
        const volatile
    {
        return !operator ==(none_t());
    }

}}
