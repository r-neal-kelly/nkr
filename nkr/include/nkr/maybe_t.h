/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"

namespace nkr {

    /// @nosubgrouping
    /// @copydoc _e81dde10_53a3_4c5e_b5e3_fa01c3325510
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

    /// @nosubgrouping
    /// @ingroup _7752ee81_def2_4386_b164_bc31f29ce7b8
    /// @copydoc _9d52d2e1_c6dc_4dbb_ad58_01a219c6e510
    template <typename type_p>
    concept none_i = requires(type_p instance, const type_p const_instance)
    {
        { instance.operator =(none_t()) }           -> std::same_as<type_p&>;
        { const_instance.operator ==(none_t()) }    -> std::same_as<bool_t>;
        { const_instance.operator !=(none_t()) }    -> std::same_as<bool_t>;
    };

}

namespace nkr {

    /// @ingroup namespaces
    /// @copydoc _c8a34890_b904_42a7_a88c_ada39529db42
    namespace $maybe_t {};

}

namespace nkr { namespace $maybe_t {

    /// @nosubgrouping
    /// @copydoc _0d45c64a_558d_4bd7_baa2_6f521f6656d5
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

    /// @nosubgrouping
    /// @copydoc _870ca0b2_c146_47a9_838f_140187d046e9
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

    /// @nosubgrouping
    /// @copydoc _1f11b26a_7bf8_462e_a657_b37f6313bff3
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

    /// @nosubgrouping
    /// @copydoc _b0155c57_e98a_479c_b659_c2e869035bec
    template <built_in_tr built_in_p>
    class maybe_t<built_in_p> :
        public $maybe_t::built_in_sp<built_in_p>
    {
    public:
        using $maybe_t::built_in_sp<built_in_p>::built_in_sp;
        using $maybe_t::built_in_sp<built_in_p>::operator =;
    };

    /// @nosubgrouping
    /// @copydoc _28243913_2a03_428d_95ac_cbabc3cb3baa
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

    /// @nosubgrouping
    /// @copydoc _fe4b1321_2470_4544_b8c0_0e93c38e7275
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
