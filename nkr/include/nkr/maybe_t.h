/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"

namespace nkr {

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

    // we can't assume the default ctor will actually equate to none, or that bool_t() relates to none_t
    template <typename type_p>
    concept none_i = requires(type_p instance, const type_p const_instance)
    {
        { instance.operator =(none_t()) } -> std::same_as<type_p&>;
        { const_instance.operator ==(none_t()) } -> std::same_as<bool_t>;
        { const_instance.operator !=(none_t()) } -> std::same_as<bool_t>;
    };

    template <typename invalid_p>
    class maybe_t
    {
    public:
        maybe_t()                                       = delete;
        maybe_t(const maybe_t& other)                   = delete;
        maybe_t(maybe_t&& other) noexcept               = delete;
        maybe_t& operator =(const maybe_t& other)       = delete;
        maybe_t& operator =(maybe_t&& other) noexcept   = delete;
        ~maybe_t()                                      = delete;
    };

    // built in fundamentals need a wrapper to be extended
    template <built_in_tr built_in_p>
    class maybe_built_in_t
    {
    public:
        using value_t   = built_in_p;

    public:
        value_t value;

    public:
        maybe_built_in_t();
        maybe_built_in_t(value_t value);
        maybe_built_in_t(const maybe_built_in_t& other);
        maybe_built_in_t(maybe_built_in_t&& other) noexcept;
        maybe_built_in_t& operator =(const maybe_built_in_t& other);
        maybe_built_in_t& operator = (maybe_built_in_t&& other) noexcept;
        ~maybe_built_in_t();

    public:
        operator            value_t&();
        operator            const value_t&() const;

        explicit operator   bool_t() const;

    public:
        maybe_built_in_t&   operator =(none_t);
        bool_t              operator ==(none_t) const;
        bool_t              operator !=(none_t) const;
    };
    static_assert(none_i<maybe_built_in_t<word_t>>, "maybe_built_in_t must satisfy none_i");

    template <none_i custom_p>
    class maybe_custom_t :
        public custom_p
    {
    public:
        using value_t   = custom_p;

    public:
        using value_t::value_t;
        using value_t::operator =;

    public:
        explicit operator   bool_t() const;

    public:
        maybe_custom_t& operator =(none_t); // these are added on top in case the custom_p can't take none_t&
        bool_t          operator ==(none_t) const;
        bool_t          operator !=(none_t) const;
    };
    static_assert(none_i<maybe_custom_t<maybe_built_in_t<word_t>>>, "maybe_custom_t must satisfy none_i");

    // we're doing it this way to avoid a bug, link to the stack overflow page.
    template <built_in_tr built_in_p>
    class maybe_t<built_in_p> :
        public maybe_built_in_t<built_in_p>
    {
    public:
        using maybe_built_in_t<built_in_p>::maybe_built_in_t;
        using maybe_built_in_t<built_in_p>::operator =;
    };

    template <none_i custom_p>
    class maybe_t<custom_p> :
        public maybe_custom_t<custom_p>
    {
    public:
        using maybe_custom_t<custom_p>::maybe_custom_t;
        using maybe_custom_t<custom_p>::operator =;
    };

    template <typename any_p>
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
