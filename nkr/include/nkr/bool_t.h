/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/none_t.h"
#include "nkr/traits.h"

namespace nkr {

    class bool_t
    {
    public:
        using value_t   = bool;

    public:
        value_t value;

    public:
        bool_t();
        bool_t(value_t value);
        bool_t(const bool_t& other);
        bool_t(bool_t&& other) noexcept;
        bool_t(const volatile bool_t& other);
        bool_t(volatile bool_t&& other) noexcept;
        bool_t& operator =(value_t value);
        bool_t& operator =(const bool_t& other);
        bool_t& operator =(bool_t&& other) noexcept;
        volatile bool_t& operator =(value_t value) volatile;
        volatile bool_t& operator =(const bool_t& other) volatile;
        volatile bool_t& operator =(bool_t&& other) volatile noexcept;
        ~bool_t();

    public:
        explicit operator   value_t() const; // explicit to prevent unwanted native operators
        explicit operator   value_t() const volatile;
        explicit operator   u8_t() const { return this->value; } // temp rewrite this

    public:
        value_t&        operator()();
        const value_t&  operator()() const;

        friend bool_t   operator !(bool_t a);

        friend bool_t   operator ==(bool_t a, bool_t b);
        friend bool_t   operator !=(bool_t a, bool_t b);

    public:
        bool_t& operator =(none_t);
        bool_t  operator ==(none_t) const;
        bool_t  operator !=(none_t) const;
    };

}

#include "nkr/bool_t.inl"
