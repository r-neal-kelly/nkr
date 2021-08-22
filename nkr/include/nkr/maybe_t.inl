/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/maybe_t.h"

namespace nkr {

    inline none_t::none_t() :
        none(0)
    {
    }

    template <built_in_tr built_in_p>
    inline maybe_built_in_t<built_in_p>::maybe_built_in_t() :
        value(value_t())
    {
    }

    template <built_in_tr built_in_p>
    inline maybe_built_in_t<built_in_p>::maybe_built_in_t(value_t value) :
        value(value)
    {
    }

    template <built_in_tr built_in_p>
    inline maybe_built_in_t<built_in_p>::maybe_built_in_t(const maybe_built_in_t& other) :
        value(other.value)
    {
    }

    template <built_in_tr built_in_p>
    inline maybe_built_in_t<built_in_p>::maybe_built_in_t(maybe_built_in_t&& other) noexcept :
        value(std::exchange(other.value, value_t()))
    {
    }

    template <built_in_tr built_in_p>
    inline maybe_built_in_t<built_in_p>& maybe_built_in_t<built_in_p>::operator =(const maybe_built_in_t& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <built_in_tr built_in_p>
    inline maybe_built_in_t<built_in_p>& maybe_built_in_t<built_in_p>::operator =(maybe_built_in_t&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->value = std::exchange(other.value, value_t());
        }
        return *this;
    }

    template <built_in_tr built_in_p>
    inline maybe_built_in_t<built_in_p>::~maybe_built_in_t()
    {
        this->value = value_t();
    }

    template <built_in_tr built_in_p>
    inline maybe_built_in_t<built_in_p>::operator value_t&()
    {
        return this->value;
    }

    template <built_in_tr built_in_p>
    inline maybe_built_in_t<built_in_p>::operator const value_t&() const
    {
        return this->value;
    }

    template <built_in_tr built_in_p>
    inline maybe_built_in_t<built_in_p>::operator bool_t() const
    {
        return operator !=(none_t());
    }

    template <built_in_tr built_in_p>
    inline maybe_built_in_t<built_in_p>& maybe_built_in_t<built_in_p>::operator =(none_t)
    {
        this->value = value_t();
        return *this;
    }

    template <built_in_tr built_in_p>
    inline bool_t maybe_built_in_t<built_in_p>::operator ==(none_t) const
    {
        return operator !=(none_t());
    }

    template <built_in_tr built_in_p>
    inline bool_t maybe_built_in_t<built_in_p>::operator !=(none_t) const
    {
        return static_cast<bool_t>(this->value);
    }

    template <none_i custom_p>
    inline maybe_custom_t<custom_p>::operator bool_t() const
    {
        return value_t::operator !=(none_t());
    }

    template <none_i custom_p>
    inline maybe_custom_t<custom_p>& maybe_custom_t<custom_p>::operator =(none_t)
    {
        return value_t::operator =(none_t());
    }

    template <none_i custom_p>
    inline bool_t maybe_custom_t<custom_p>::operator ==(none_t) const
    {
        return value_t::operator ==(none_t());
    }

    template <none_i custom_p>
    inline bool_t maybe_custom_t<custom_p>::operator !=(none_t) const
    {
        return value_t::operator !=(none_t());
    }

}
