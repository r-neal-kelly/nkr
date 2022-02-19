/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_utils_def.h"

#include "nkr/boolean/deleted_operators_t_def.h"

#include "nkr/z_bool_t_dec.h"

namespace nkr {

    inline bool_t::bool_t() :
        value(static_cast<word_t>(false))
    {
    }

    inline bool_t::bool_t(to_c_bool_tr auto value) :
        value(static_cast<word_t>(static_cast<c_bool_t>(value)))
    {
    }

    inline bool_t::bool_t(const bool_t& other) :
        value(other.value)
    {
    }

    inline bool_t::bool_t(const volatile bool_t& other) :
        value(other.value)
    {
    }

    inline bool_t::bool_t(bool_t&& other) noexcept :
        value(nkr::Move(other.value))
    {
    }

    inline bool_t::bool_t(volatile bool_t&& other) noexcept :
        value(nkr::Move(other.value))
    {
    }

    inline bool_t&
        bool_t::operator =(const bool_t& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    inline volatile bool_t&
        bool_t::operator =(const bool_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    inline bool_t&
        bool_t::operator =(const volatile bool_t& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    inline volatile bool_t&
        bool_t::operator =(const volatile bool_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    inline bool_t&
        bool_t::operator =(bool_t&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    inline volatile bool_t&
        bool_t::operator =(bool_t&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    inline bool_t&
        bool_t::operator =(is_just_volatile_tr<bool_t> auto&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    inline volatile bool_t&
        bool_t::operator =(is_just_volatile_tr<bool_t> auto&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    inline bool_t::~bool_t()
    {
        this->value = static_cast<word_t>(false);
    }

    inline bool_t::operator c_bool_t()
        const
    {
        return static_cast<c_bool_t>(this->value);
    }

    inline bool_t::operator c_bool_t()
        const volatile
    {
        return static_cast<c_bool_t>(this->value);
    }

    inline bool_t::operator word_t&()
    {
        return this->value;
    }

    inline bool_t::operator const word_t&()
        const
    {
        return this->value;
    }

    inline bool_t::operator volatile word_t&()
        volatile
    {
        return this->value;
    }

    inline bool_t::operator const volatile word_t&()
        const volatile
    {
        return this->value;
    }

    inline bool_t::bool_t(none_t) :
        value(static_cast<word_t>(false))
    {
    }

    inline bool_t&
        bool_t::operator =(none_t)
    {
        this->value = static_cast<word_t>(false);
        return *this;
    }

    inline volatile bool_t&
        bool_t::operator =(none_t)
        volatile
    {
        this->value = static_cast<word_t>(false);
        return *this;
    }

    inline bool_t
        bool_t::operator ==(none_t)
        const
    {
        return !static_cast<c_bool_t>(this->value);
    }

    inline bool_t
        bool_t::operator ==(none_t)
        const volatile
    {
        return !static_cast<c_bool_t>(this->value);
    }

    inline bool_t
        bool_t::operator !=(none_t)
        const
    {
        return !operator ==(none_t());
    }

    inline bool_t
        bool_t::operator !=(none_t)
        const volatile
    {
        return !operator ==(none_t());
    }

}
