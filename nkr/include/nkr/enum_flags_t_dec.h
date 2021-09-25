/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"

namespace nkr {

    // we need to make a specialization for atomic unsigned integers

    template <integer_unsigned_tr value_p>
    class enum_flags_t
    {
    public:
        using value_t           = value_p;
        using writable_value_t  = std::remove_const_t<value_t>;

    protected:
        using base_t    = enum_flags_t;

    public:
        static constexpr index_t    Min_Index();
        static constexpr index_t    Max_Index();

        template <index_t index_p>
        static constexpr value_t    Define();

    public:
        value_t value;

    public:
        enum_flags_t();

        enum_flags_t(value_t value);

        enum_flags_t(const enum_flags_t& other);
        enum_flags_t(const volatile enum_flags_t& other);
        enum_flags_t(enum_flags_t&& other) noexcept;
        enum_flags_t(volatile enum_flags_t&& other) noexcept;

        enum_flags_t&           operator =(value_t value);
        volatile enum_flags_t&  operator =(value_t value) volatile;

        enum_flags_t&           operator =(const enum_flags_t& other);
        volatile enum_flags_t&  operator =(const enum_flags_t& other) volatile;
        enum_flags_t&           operator =(const volatile enum_flags_t& other);
        volatile enum_flags_t&  operator =(const volatile enum_flags_t& other) volatile;
        enum_flags_t&           operator =(enum_flags_t&& other) noexcept;
        volatile enum_flags_t&  operator =(enum_flags_t&& other) volatile noexcept;
        enum_flags_t&           operator =(volatile enum_flags_t&& other) noexcept;
        volatile enum_flags_t&  operator =(volatile enum_flags_t&& other) volatile noexcept;

        ~enum_flags_t();

    public:
        value_t Flags() const;
        value_t Flags() const volatile;

        bool_t  Is_Flagged(value_t flag) const;
        bool_t  Is_Flagged(value_t flag) const volatile;

        void_t  Flag(value_t flag);
        void_t  Flag(value_t flag) volatile;
        void_t  Unflag(value_t flag);
        void_t  Unflag(value_t flag) volatile;
    };

}
