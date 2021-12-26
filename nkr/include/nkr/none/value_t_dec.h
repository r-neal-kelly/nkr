/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/generic/implementing/interface/none/value_tr_dec.h"
#include "nkr/generic/none_tr_dec.h"
#include "nkr/generic/none/any_tr_dec.h"
#include "nkr/generic/type_tr_dec.h"

namespace nkr { namespace none {

    template <generic::implementing::interface::none::value_tr type_p>
    class   value_t;

    struct  value_tg    {};

    template <typename>
    struct  value_ttg   {};

    template <typename type_p>
    concept value_tr =
        cpp::is_any_tr<type_p, value_t<typename type_p::type_t>>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::none::value_tg>
    {
    public:
        using type_t    = nkr::none::value_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::none::value_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::none::value_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_t::type_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::none::value_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = nkr::none::value_t<of_p>;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <>
    class template_i<nkr::none::value_t> :
        public template_i<nkr::none::value_ttg>
    {
    public:
    };

}}

namespace nkr { namespace none {

    // type_t alias really should be value_t. We need to make that work syntactically here,
    // but we should do that to be consistent with other types that produce a value.

    template <generic::implementing::interface::none::value_tr type_p>
    class value_t
    {
    public:
        using type_t        = type_p;
        using interface_t   = interface::none::value_i<type_t>;

    public:
        constexpr value_t() noexcept;

        constexpr value_t(const value_t& other) noexcept;
        constexpr value_t(const volatile value_t& other) noexcept;
        constexpr value_t(value_t&& other) noexcept;
        constexpr value_t(volatile value_t&& other) noexcept;

        constexpr value_t&          operator =(const value_t& other) noexcept;
        constexpr volatile value_t& operator =(const value_t& other) volatile noexcept;
        constexpr value_t&          operator =(const volatile value_t& other) noexcept;
        constexpr volatile value_t& operator =(const volatile value_t& other) volatile noexcept;
        constexpr value_t&          operator =(value_t&& other) noexcept;
        constexpr volatile value_t& operator =(value_t&& other) volatile noexcept;
        constexpr value_t&          operator =(tr1<just_volatile_tg, value_t> auto&& other) noexcept;
        constexpr volatile value_t& operator =(tr1<just_volatile_tg, value_t> auto&& other) volatile noexcept;

#if defined(nkr_IS_DEBUG)
        constexpr ~value_t() noexcept;
#endif

    public:
        constexpr operator  value_t::type_t() const noexcept;
        constexpr operator  value_t::type_t() const volatile noexcept;
    };

}}

namespace nkr {

    /*constexpr boolean::cpp_t    operator ==(const tr1<any_tg, none::value_tg> auto& a, const tr0<any_tg> auto& b) noexcept;
    constexpr boolean::cpp_t    operator ==(const tr1<any_tg, none::value_tg> auto& a, const tr0<any_tg> auto&& b) noexcept;
    constexpr boolean::cpp_t    operator ==(const tr1<any_tg, none::value_tg> auto&& a, const tr0<any_tg> auto& b) noexcept;
    constexpr boolean::cpp_t    operator ==(const tr1<any_tg, none::value_tg> auto&& a, const tr0<any_tg> auto&& b) noexcept;

    constexpr boolean::cpp_t    operator !=(const tr1<any_tg, none::value_tg> auto& a, const tr0<any_tg> auto& b) noexcept;
    constexpr boolean::cpp_t    operator !=(const tr1<any_tg, none::value_tg> auto& a, const tr0<any_tg> auto&& b) noexcept;
    constexpr boolean::cpp_t    operator !=(const tr1<any_tg, none::value_tg> auto&& a, const tr0<any_tg> auto& b) noexcept;
    constexpr boolean::cpp_t    operator !=(const tr1<any_tg, none::value_tg> auto&& a, const tr0<any_tg> auto&& b) noexcept;*/

}

#include "nkr/none/value_t_dec_def.h"

namespace nkr { namespace none {

    /*static_assert(generic::none_tr<value_t<positive::integer_t>>);
    static_assert(generic::none_tr<const value_t<positive::integer_t>>);
    static_assert(generic::none_tr<volatile value_t<positive::integer_t>>);
    static_assert(generic::none_tr<const volatile value_t<positive::integer_t>>);

    static_assert(generic::none::any_tr<value_t<positive::integer_t>>);
    static_assert(generic::none::any_tr<const value_t<positive::integer_t>>);
    static_assert(generic::none::any_tr<volatile value_t<positive::integer_t>>);
    static_assert(generic::none::any_tr<const volatile value_t<positive::integer_t>>);*/

}}
