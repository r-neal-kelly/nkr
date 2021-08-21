/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"

namespace nkr {

    // similar to atomic_t, this will have implementations for
    // integer_tr, pointer_tr, and for custom types that have the interface.
    // also a cheap implementation for bool_t would be good.
    // we'll have to wrap integers and pointers and other types that would work with the interface.

    class none_t
    {
    public:
        const word_t    none;

    public:
        inline  none_t();
        inline  none_t(const none_t& other)                 = delete;
        inline  none_t(none_t&& other) noexcept             = delete;
        inline  none_t& operator =(const none_t& other)     = delete;
        inline  none_t& operator =(none_t&& other) noexcept = delete;
        inline  ~none_t()                                   = default;
    };
    static_assert(sizeof(none_t) == sizeof(word_t));

    // we require the type_p(none_t()) because we can't assume the default ctor will actually equate to none.
    // same with the operator ==
    template <typename type_p>
    concept maybe_i = requires(type_p instance, const type_p const_instance)
    {
        { instance.operator =(none_t()) } -> std::same_as<type_p&>;
        { const_instance.operator ==(none_t()) } -> std::same_as<bool_t>;
        { const_instance.operator !=(none_t()) } -> std::same_as<bool_t>;
    };

    template <maybe_i any_p>
    class maybe_t :
        public any_p
    {
    public:
        using value_t   = any_p;

    public:
        using value_t::value_t;
        using value_t::operator =;

    public:
        explicit operator   bool_t() const;

    public:
        maybe_t&    operator =(none_t);
        bool_t      operator ==(none_t) const;
        bool_t      operator !=(none_t) const;
    };

    template <maybe_i any_p>
    class some_t :
        public maybe_t<any_p>
    {
    public:
        using value_t   = any_p;

    public:
        using maybe_t<value_t>::maybe_t;
        using maybe_t<value_t>::operator =;

    public:
        some_t& operator =(none_t)  = delete;
    };

}

#include "nkr/maybe_t.inl"
