/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/interface/template_i_dec.h"
#include "nkr/interface/type_i_dec.h"

#include "nkr/trait/defaultable_tr_dec.h"
#include "nkr/trait/none_tr_dec.h"
#include "nkr/trait/none/any_tr_dec.h"

namespace nkr { namespace none {

    template <trait::defaultable_tr type_p>
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
    class type_i<none::value_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <none::value_tr type_p>
    class type_i<type_p> :
        public type_i<none::value_tg>
    {
    public:
        using of_t  = type_p::type_t;
    };

    template <>
    class template_i<none::value_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = none::value_t<of_p>;

    public:
        static constexpr boolean::cpp_t Is_Implemented() noexcept;
    };

    template <>
    class template_i<none::value_t> :
        public template_i<none::value_ttg>
    {
    public:
    };

}}

namespace nkr { namespace none {

    // the idea is that most type's 'none' value is the default constructed object, or zero in the case of built-ins.
    // however, one could simply add a single constructor for the value_t in their type that does not have the default
    // equal to none and do whatever they want, because the implicit cast should be skipped when there is a non-template constructor.
    // There may be a conflict between it and the default copy constructor however, so I'll need to do some testing to see if that
    // can be made to work correctly. Most types don't need to worry about though and this should make it far easier to use this.

    template <trait::defaultable_tr type_p>
    class value_t
    {
    public:
        using type_t    = type_p;

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
