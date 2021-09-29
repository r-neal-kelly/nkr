/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/atomic_t.h"
#include "nkr/intrinsics.h"
#include "nkr/macros.h"
#include "nkr/traits.h"

namespace nkr { namespace enumeration { namespace $types_t {

    template <integer_tr value_p, any_tr actual_value_p>
    class any_sp
    {
    public:
        using value_t           = value_p;
        using actual_value_t    = actual_value_p;

    public:
        actual_value_t  value;

    public:
        any_sp();

        any_sp(value_t value);

        any_sp(const any_sp& other);
        any_sp(const volatile any_sp& other);
        any_sp(any_sp&& other) noexcept;
        any_sp(volatile any_sp&& other) noexcept;

        any_sp&             operator =(const any_sp& other);
        volatile any_sp&    operator =(const any_sp& other) volatile;
        any_sp&             operator =(const volatile any_sp& other);
        volatile any_sp&    operator =(const volatile any_sp& other) volatile;
        any_sp&             operator =(any_sp&& other) noexcept;
        volatile any_sp&    operator =(any_sp&& other) volatile noexcept;
        any_sp&             operator =(is_just_volatile_tr<any_sp>&& other) noexcept;
        volatile any_sp&    operator =(is_just_volatile_tr<any_sp>&& other) volatile noexcept;

        ~any_sp();

    public:

    };

}}}

namespace nkr { namespace enumeration {

    template <typename value_p>
    class types_t
    {
    public:
        types_t()                                                                               = delete;

        types_t(const types_t& other)                                                           = delete;
        types_t(const volatile types_t& other)                                                  = delete;
        types_t(types_t&& other) noexcep                                                        = delete;
        types_t(volatile types_t&& other) noexcept                                              = delete;

        types_t&            operator =(const types_t& other)                                    = delete;
        volatile types_t&   operator =(const types_t& other) volatile                           = delete;
        types_t&            operator =(const volatile types_t& other)                           = delete;
        volatile types_t&   operator =(const volatile types_t& other) volatile                  = delete;
        types_t&            operator =(types_t&& other) noexcept                                = delete;
        volatile types_t&   operator =(types_t&& other) volatile noexcept                       = delete;
        types_t&            operator =(is_just_volatile_tr<types_t>&& other) noexcept           = delete;
        volatile types_t&   operator =(is_just_volatile_tr<types_t>&& other) volatile noexcept  = delete;

        ~types_t()                                                                              = delete;
    };

    template <integer_unsigned_tr integer_p>
    class types_t<integer_p> :
        public $types_t::any_sp<integer_p, integer_p>
    {
    private:
        using base_t    = $types_t::any_sp<integer_p, integer_p>;

    public:
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(types_t, base_t);
    };

    template <any_non_const_atomic_of_any_non_const_unsigned_integer_tr atomic_p>
    class types_t<atomic_p> :
        public $types_t::any_sp<typename atomic_p::value_t, atomic_p>
    {
    private:
        using base_t    = $types_t::any_sp<typename atomic_p::value_t, atomic_p>;

    public:
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(types_t, base_t);
    };

}}
