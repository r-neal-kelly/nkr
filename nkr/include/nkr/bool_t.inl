/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"

namespace nkr {

    inline bool_t::bool_t() :
        value(static_cast<word_t>(false))
    {
    }

    inline bool_t::bool_t(std_bool_t value) :
        value(static_cast<word_t>(value))
    {
    }

    inline bool_t::bool_t(const bool_t& other) :
        value(other.value)
    {
    }

    inline bool_t::bool_t(bool_t&& other) noexcept :
        value(std::exchange(other.value, static_cast<word_t>(false)))
    {
    }

    inline bool_t::bool_t(volatile const bool_t& other) :
        value(other.value)
    {
    }

    inline bool_t::bool_t(volatile bool_t&& other) noexcept :
        value(std::exchange(other.value, static_cast<word_t>(false)))
    {
    }

    inline bool_t& bool_t::operator =(std_bool_t value)
    {
        this->value = static_cast<word_t>(value);
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
            this->value = std::exchange(other.value, static_cast<word_t>(false));
        }
        return *this;
    }

    inline volatile bool_t& bool_t::operator =(std_bool_t value) volatile
    {
        this->value = static_cast<word_t>(value);
        return *this;
    }

    inline volatile bool_t& bool_t::operator =(volatile const bool_t& other) volatile
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    inline volatile bool_t& bool_t::operator =(volatile bool_t&& other) volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->value = std::exchange(other.value, static_cast<word_t>(false));
        }
        return *this;
    }

    inline bool_t::~bool_t()
    {
        this->value = static_cast<word_t>(false);
    }

    inline bool_t::operator std_bool_t() const
    {
        return static_cast<std_bool_t>(this->value);
    }

    inline bool_t::operator std_bool_t() volatile const
    {
        return static_cast<std_bool_t>(this->value);
    }

    inline bool_t::operator word_t&()
    {
        return this->value;
    }

    inline bool_t::operator const word_t&() const
    {
        return this->value;
    }

    inline bool_t::operator volatile word_t&() volatile
    {
        return this->value;
    }

    inline bool_t::operator volatile const word_t&() volatile const
    {
        return this->value;
    }

    inline bool_t operator !(bool_t a)
    {
        return !static_cast<std_bool_t>(a);
    }

    inline bool_t operator ==(bool_t a, bool_t b)
    {
        return static_cast<std_bool_t>(a) == static_cast<std_bool_t>(b);
    }

    inline bool_t operator !=(bool_t a, bool_t b)
    {
        return !operator ==(a, b);
    }

    inline bool_t& bool_t::operator =(none_t)
    {
        this->value = static_cast<word_t>(false);
        return *this;
    }

    inline bool_t bool_t::operator ==(none_t) const
    {
        return !static_cast<std_bool_t>(this->value);
    }

    inline bool_t bool_t::operator !=(none_t) const
    {
        return !operator ==(none_t());
    }

}
