/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/maybe_t.h"

namespace nkr { namespace $maybe_t {

    template <built_in_tr built_in_p>
    inline built_in_sp<built_in_p>::built_in_sp() :
        value(value_t())
    {
    }

    template <built_in_tr built_in_p>
    inline built_in_sp<built_in_p>::built_in_sp(value_t value) :
        value(value)
    {
    }

    template <built_in_tr built_in_p>
    inline built_in_sp<built_in_p>::built_in_sp(const built_in_sp& other) :
        value(other.value)
    {
    }

    template <built_in_tr built_in_p>
    inline built_in_sp<built_in_p>::built_in_sp(built_in_sp&& other) noexcept :
        value(std::exchange(other.value, value_t()))
    {
    }

    template <built_in_tr built_in_p>
    inline built_in_sp<built_in_p>& built_in_sp<built_in_p>::operator =(value_t other)
    {
        this->value = other;
        return *this;
    }

    template <built_in_tr built_in_p>
    inline built_in_sp<built_in_p>& built_in_sp<built_in_p>::operator =(const built_in_sp& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <built_in_tr built_in_p>
    inline built_in_sp<built_in_p>& built_in_sp<built_in_p>::operator =(built_in_sp&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->value = std::exchange(other.value, value_t());
        }
        return *this;
    }

    template <built_in_tr built_in_p>
    inline built_in_sp<built_in_p>::~built_in_sp()
    {
        this->value = value_t();
    }

    template <built_in_tr built_in_p>
    inline built_in_sp<built_in_p>::operator value_t&()
    {
        return this->value;
    }

    template <built_in_tr built_in_p>
    inline built_in_sp<built_in_p>::operator const value_t&() const
    {
        return this->value;
    }

    template <built_in_tr built_in_p>
    inline built_in_sp<built_in_p>::operator bool_t() const
    {
        return static_cast<bool_t>(this->value);
    }

    template <built_in_tr built_in_p>
    inline typename built_in_sp<built_in_p>::value_t& built_in_sp<built_in_p>::operator ()()
    {
        return this->value;
    }

    template <built_in_tr built_in_p>
    inline typename const built_in_sp<built_in_p>::value_t& built_in_sp<built_in_p>::operator ()() const
    {
        return this->value;
    }

    template <built_in_tr built_in_p>
    inline bool_t built_in_sp<built_in_p>::operator !() const
    {
        return !operator bool_t();
    }

    template <built_in_tr built_in_p>
    inline built_in_sp<built_in_p>& built_in_sp<built_in_p>::operator =(none_t)
    {
        this->value = value_t();
        return *this;
    }

    template <built_in_tr built_in_p>
    inline bool_t built_in_sp<built_in_p>::operator ==(none_t) const
    {
        return !operator bool_t();
    }

    template <built_in_tr built_in_p>
    inline bool_t built_in_sp<built_in_p>::operator !=(none_t) const
    {
        return !operator ==(none_t());
    }

    template <none_i user_defined_p>
    inline user_defined_sp<user_defined_p>::operator bool_t() const
    {
        return value_t::operator !=(none_t());
    }

    template <none_i user_defined_p>
    inline typename user_defined_sp<user_defined_p>::value_t& user_defined_sp<user_defined_p>::operator ()()
    {
        return static_cast<value_t&>(*this);
    }

    template <none_i user_defined_p>
    inline typename const user_defined_sp<user_defined_p>::value_t& user_defined_sp<user_defined_p>::operator ()() const
    {
        return static_cast<const value_t&>(*this);
    }

    template <none_i user_defined_p>
    inline bool_t user_defined_sp<user_defined_p>::operator !() const
    {
        return !operator bool_t();
    }

    template <none_i user_defined_p>
    inline user_defined_sp<user_defined_p>& user_defined_sp<user_defined_p>::operator =(none_t)
    {
        return value_t::operator =(none_t());
    }

    template <none_i user_defined_p>
    inline bool_t user_defined_sp<user_defined_p>::operator ==(none_t) const
    {
        return value_t::operator ==(none_t());
    }

    template <none_i user_defined_p>
    inline bool_t user_defined_sp<user_defined_p>::operator !=(none_t) const
    {
        return value_t::operator !=(none_t());
    }

}}
