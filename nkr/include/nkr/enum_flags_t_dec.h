/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/atomic_t.h"
#include "nkr/intrinsics.h"
#include "nkr/macros.h"
#include "nkr/traits.h"

namespace nkr { namespace $enum_flags_t {

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    class any_sp
    {
    public:
        using value_t           = integer_p;
        using actual_value_t    = actual_value_p;

    public:
        static constexpr index_t    Min_Index();
        static constexpr index_t    Max_Index();

        template <index_t index_p>
        static constexpr value_t    Define();

    public:
        actual_value_t  value;

    public:
        any_sp();

        any_sp(value_t value);

        any_sp(const any_sp& other);
        any_sp(const volatile any_sp& other);
        any_sp(any_sp&& other) noexcept;
        any_sp(volatile any_sp&& other) noexcept;

        any_sp&             operator =(value_t value);
        volatile any_sp&    operator =(value_t value) volatile;

        any_sp&             operator =(const any_sp& other);
        volatile any_sp&    operator =(const any_sp& other) volatile;
        any_sp&             operator =(const volatile any_sp& other);
        volatile any_sp&    operator =(const volatile any_sp& other) volatile;
        any_sp&             operator =(any_sp&& other) noexcept;
        volatile any_sp&    operator =(any_sp&& other) volatile noexcept;
        any_sp&             operator =(volatile any_sp&& other) noexcept;
        volatile any_sp&    operator =(volatile any_sp&& other) volatile noexcept;

        ~any_sp();

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

}}

namespace nkr {

    template <typename any_p>
    class enum_flags_t
    {
    public:
    };

    template <integer_unsigned_tr integer_p>
    class enum_flags_t<integer_p> :
        public $enum_flags_t::any_sp<integer_p, integer_p>
    {
    public:
        using base_enum_t   = enum_flags_t;

    private:
        using base_t    = $enum_flags_t::any_sp<integer_p, integer_p>;

    public:
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(enum_flags_t, base_t);
    };

    template <any_non_const_atomic_of_any_non_const_unsigned_integer_tr atomic_p>
    class enum_flags_t<atomic_p> :
        public $enum_flags_t::any_sp<typename atomic_p::value_t, atomic_p>
    {
    public:
        using base_enum_t   = enum_flags_t;

    private:
        using base_t    = $enum_flags_t::any_sp<typename atomic_p::value_t, atomic_p>;

    public:
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(enum_flags_t, base_t);
    };

}
