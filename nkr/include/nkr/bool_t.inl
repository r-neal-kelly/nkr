/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"

namespace nkr {

    inline bool_t::bool_t() :
        value(value_t())
    {
    }

    inline bool_t::bool_t(value_t value) :
        value(value)
    {
    }

    inline bool_t::bool_t(const bool_t& other) :
        value(other.value)
    {
    }

    inline bool_t::bool_t(bool_t&& other) noexcept :
        value(std::exchange(other.value, value_t()))
    {
    }

    inline bool_t::bool_t(const volatile bool_t& other) :
        value(other.value)
    {
    }

    inline bool_t::bool_t(volatile bool_t&& other) noexcept :
        value(std::exchange(other.value, value_t()))
    {
    }

    inline bool_t& bool_t::operator =(value_t value)
    {
        this->value = value;
        return *this;
    }

    inline bool_t& bool_t::operator =(const bool_t& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    inline bool_t& bool_t::operator =(bool_t&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    inline volatile bool_t& bool_t::operator =(value_t value) volatile
    {
        this->value = value;
        return *this;
    }

    inline volatile bool_t& bool_t::operator =(const bool_t& other) volatile
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    inline volatile bool_t& bool_t::operator =(bool_t&& other) volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    inline bool_t::~bool_t()
    {
        this->value = value_t();
    }

    inline bool_t::operator value_t() const
    {
        return this->value;
    }

    inline bool_t::operator value_t() const volatile
    {
        return this->value;
    }

    inline typename bool_t::value_t& bool_t::operator()()
    {
        return this->value;
    }

    inline typename const bool_t::value_t& bool_t::operator()() const
    {
        return this->value;
    }

    inline bool_t operator !(bool_t a)
    {
        return !static_cast<bool_t::value_t>(a);
    }

    inline bool_t operator ==(bool_t a, bool_t b)
    {
        return static_cast<bool_t::value_t>(a) == static_cast<bool_t::value_t>(b);
    }

    inline bool_t operator !=(bool_t a, bool_t b)
    {
        return !operator ==(a, b);
    }

    inline bool_t& bool_t::operator =(none_t)
    {
        this->value = value_t();
        return *this;
    }

    inline bool_t bool_t::operator ==(none_t) const
    {
        return this->value == value_t();
    }

    inline bool_t bool_t::operator !=(none_t) const
    {
        return !operator ==(none_t());
    }

}
