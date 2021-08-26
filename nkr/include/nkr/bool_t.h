/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/none_t.h"

namespace nkr {

    class bool_t
    {
    public:
        word_t  value;

    public:
        bool_t();
        bool_t(std_bool_t value);
        bool_t(const bool_t& other);
        bool_t(bool_t&& other) noexcept;
        bool_t(volatile const bool_t& other);
        bool_t(volatile bool_t&& other) noexcept;
        bool_t& operator =(std_bool_t value);
        bool_t& operator =(const bool_t& other);
        bool_t& operator =(bool_t&& other) noexcept;
        volatile bool_t& operator =(std_bool_t value) volatile;
        volatile bool_t& operator =(volatile const bool_t& other) volatile;
        volatile bool_t& operator =(volatile bool_t&& other) volatile noexcept;
        ~bool_t();

    public:
        explicit operator   std_bool_t() const; // explicit to prevent unwanted native operators, make sure to doc that. this is here to interact with boolean expressions
        explicit operator   std_bool_t() volatile const;

        explicit operator   word_t&();
        explicit operator   const word_t&() const;
        explicit operator   volatile word_t&() volatile;
        explicit operator   volatile const word_t&() volatile const;

    public:
        friend bool_t   operator !(bool_t a);

        friend bool_t   operator ==(bool_t a, bool_t b);
        friend bool_t   operator !=(bool_t a, bool_t b);

    public:
        bool_t& operator =(none_t);
        bool_t  operator ==(none_t) const;
        bool_t  operator !=(none_t) const;
    };
    static_assert(sizeof(bool_t) == sizeof(word_t));

}

#include "nkr/bool_t.inl"
