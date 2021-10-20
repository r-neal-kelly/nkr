/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/optional_t_dec.h"
#include "nkr/utils.h"

namespace nkr {

    template <any_type_tr value_p>
    inline optional_t<value_p>::optional_t() :
        has_value(false),
        value()
    {
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::optional_t(const value_t& value) :
        has_value(static_cast<bool_t>(value)),
        value(value)
    {
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::optional_t(value_t&& value) noexcept :
        has_value(static_cast<bool_t>(value)),
        value(nkr::Move(value))
    {
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::optional_t(const value_t& value, bool_t has_value) :
        has_value(has_value),
        value(value)
    {
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::optional_t(value_t&& value, bool_t has_value) noexcept :
        has_value(has_value),
        value(nkr::Move(value))
    {
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::optional_t(const optional_t& other) :
        has_value(other.has_value),
        value(other.value)
    {
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::optional_t(const volatile optional_t& other) :
        has_value(other.has_value),
        value(other.value)
    {
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::optional_t(optional_t&& other) noexcept :
        has_value(nkr::Move(other.has_value)),
        value(nkr::Move(other.value))
    {
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::optional_t(volatile optional_t&& other) noexcept :
        has_value(nkr::Move(other.has_value)),
        value(nkr::Move(other.value))
    {
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>&
        optional_t<value_p>::operator =(const optional_t& other)
    {
        if (this != std::addressof(other)) {
            this->has_value = other.has_value;
            this->value = other.value;
        }

        return *this;
    }

    template <any_type_tr value_p>
    inline volatile optional_t<value_p>&
        optional_t<value_p>::operator =(const optional_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->has_value = other.has_value;
            this->value = other.value;
        }

        return *this;
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>&
        optional_t<value_p>::operator =(const volatile optional_t& other)
    {
        if (this != std::addressof(other)) {
            this->has_value = other.has_value;
            this->value = other.value;
        }

        return *this;
    }

    template <any_type_tr value_p>
    inline volatile optional_t<value_p>&
        optional_t<value_p>::operator =(const volatile optional_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->has_value = other.has_value;
            this->value = other.value;
        }

        return *this;
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>&
        optional_t<value_p>::operator =(optional_t&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->has_value = nkr::Move(other.has_value);
            this->value = nkr::Move(other.value);
        }

        return *this;
    }

    template <any_type_tr value_p>
    inline volatile optional_t<value_p>&
        optional_t<value_p>::operator =(optional_t&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->has_value = nkr::Move(other.has_value);
            this->value = nkr::Move(other.value);
        }

        return *this;
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>&
        optional_t<value_p>::operator =(is_just_volatile_tr<optional_t> auto&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->has_value = nkr::Move(other.has_value);
            this->value = nkr::Move(other.value);
        }

        return *this;
    }

    template <any_type_tr value_p>
    inline volatile optional_t<value_p>&
        optional_t<value_p>::operator =(is_just_volatile_tr<optional_t> auto&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->has_value = nkr::Move(other.has_value);
            this->value = nkr::Move(other.value);
        }

        return *this;
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::~optional_t()
    {
        this->has_value = false;

        if constexpr (built_in_tr<value_t>) {
            this->value = static_cast<value_t>(0);
        }
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::Has_Value()
        const
    {
        return this->has_value;
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::Has_Value()
        const volatile
    {
        return this->has_value;
    }

    template <any_type_tr value_p>
    inline typename optional_t<value_p>::value_t&
        optional_t<value_p>::Value()
    {
        return this->value;
    }

    template <any_type_tr value_p>
    inline const typename optional_t<value_p>::value_t&
        optional_t<value_p>::Value()
        const
    {
        return this->value;
    }

    template <any_type_tr value_p>
    inline volatile typename optional_t<value_p>::value_t&
        optional_t<value_p>::Value()
        volatile
    {
        return this->value;
    }

    template <any_type_tr value_p>
    inline const volatile typename optional_t<value_p>::value_t&
        optional_t<value_p>::Value()
        const volatile
    {
        return this->value;
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::operator std_bool_t()
        const
    {
        return this->has_value;
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::operator std_bool_t()
        const volatile
    {
        return this->has_value;
    }

}
