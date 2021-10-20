/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/traits.h"

namespace nkr {

    template <any_type_tr value_p>
    class optional_t
    {
    public:
        using value_t   = value_p;

    protected:
        bool_t  has_value;
        value_t value;

    public:
        optional_t();

        optional_t(const value_t& value);
        optional_t(value_t&& value) noexcept;
        optional_t(const value_t& value, bool_t has_value);
        optional_t(value_t&& value, bool_t has_value) noexcept;

        optional_t(const optional_t& other);
        optional_t(const volatile optional_t& other);
        optional_t(optional_t&& other) noexcept;
        optional_t(volatile optional_t&& other) noexcept;

        optional_t&             operator =(const optional_t& other);
        volatile optional_t&    operator =(const optional_t& other) volatile;
        optional_t&             operator =(const volatile optional_t& other);
        volatile optional_t&    operator =(const volatile optional_t& other) volatile;
        optional_t&             operator =(optional_t&& other) noexcept;
        volatile optional_t&    operator =(optional_t&& other) volatile noexcept;
        optional_t&             operator =(is_just_volatile_tr<optional_t> auto&& other) noexcept;
        volatile optional_t&    operator =(is_just_volatile_tr<optional_t> auto&& other) volatile noexcept;

        ~optional_t();

    public:
        bool_t                  Has_Value() const;
        bool_t                  Has_Value() const volatile;

        value_t&                Value();
        const value_t&          Value() const;
        volatile value_t&       Value() volatile;
        const volatile value_t& Value() const volatile;

    public:
        explicit operator   std_bool_t() const;
        explicit operator   std_bool_t() const volatile;
    };

}
