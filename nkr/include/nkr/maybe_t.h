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
        inline  none_t()                                    = default;
        inline  none_t(const none_t& other)                 = delete;
        inline  none_t(none_t&& other) noexcept             = delete;
        inline  none_t& operator =(const none_t& other)     = delete;
        inline  none_t& operator =(none_t&& other) noexcept = delete;
        inline  ~none_t()                                   = default;
    };

    // we make no assumptions so we avoid using operator bool_t() or the default ctor()
    template <typename type_p>
    concept none_i = requires(type_p instance, const type_p const_instance)
    {
        { instance.operator =(none_t()) }           -> std::same_as<type_p&>;
        { const_instance.operator ==(none_t()) }    -> std::same_as<bool_t>;
        { const_instance.operator !=(none_t()) }    -> std::same_as<bool_t>;
    };

}

namespace nkr { namespace $maybe_t {

    // built in fundamentals need a wrapper to be extended
    template <built_in_tr built_in_p>
    class built_in_sp
    {
    public:
        using value_t   = built_in_p;

    public:
        value_t value;

    public:
        built_in_sp();
        built_in_sp(value_t value);
        built_in_sp(const built_in_sp& other);
        built_in_sp(built_in_sp&& other) noexcept;
        built_in_sp& operator =(const built_in_sp& other);
        built_in_sp& operator = (built_in_sp&& other) noexcept;
        ~built_in_sp();

    public:
        operator            value_t&();
        operator            const value_t&() const;

        explicit operator   bool_t() const;

    public:
        built_in_sp&    operator =(none_t);
        bool_t          operator ==(none_t) const;
        bool_t          operator !=(none_t) const;
    };

    template <none_i user_defined_p>
    class user_defined_sp :
        public user_defined_p
    {
    public:
        using value_t   = user_defined_p;

    public:
        using value_t::value_t;
        using value_t::operator =;

    public:
        explicit operator   bool_t() const;

    public:
        user_defined_sp&    operator =(none_t); // added on top in case the user_defined_p can't take none_t&
        bool_t              operator ==(none_t) const;
        bool_t              operator !=(none_t) const;
    };

}}

namespace nkr {

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

    // we're doing it this way to avoid a bug, link to the stack overflow page.
    template <built_in_tr built_in_p>
    class maybe_t<built_in_p> :
        public $maybe_t::built_in_sp<built_in_p>
    {
    public:
        using $maybe_t::built_in_sp<built_in_p>::built_in_sp;
        using $maybe_t::built_in_sp<built_in_p>::operator =;
    };

    template <none_i user_defined_p>
    class maybe_t<user_defined_p> :
        public $maybe_t::user_defined_sp<user_defined_p>
    {
    public:
        using $maybe_t::user_defined_sp<user_defined_p>::user_defined_sp;
        using $maybe_t::user_defined_sp<user_defined_p>::operator =;
    };

}

namespace nkr {

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
