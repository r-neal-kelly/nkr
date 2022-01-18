/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/boolean/deleted_operators_t_dec.h"

/*
    pure_t:
        - to remove the integer-like behavior of an nkr::boolean::cpp_t
*/

namespace nkr { namespace boolean {

    class   pure_t;

    struct  pure_tg {};

    template <typename type_p>
    concept pure_tr =
        cpp::is_any_tr<type_p, pure_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::boolean::pure_tg>
    {
    public:
        using type_t    = nkr::boolean::pure_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::boolean::pure_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::boolean::pure_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;
    };

}}

namespace nkr { namespace boolean {

    class pure_t :
        public deleted_operators_t
    {
    public:
        using value_t   = nkr::boolean::cpp_t;

    private:
        static constexpr auto&  Assign(tr1<any_non_const_tg, pure_t> auto& self, const tr1<any_tg, pure_t> auto& other) noexcept;
        static constexpr auto&  Assign(tr1<any_non_const_tg, pure_t> auto& self, tr1<any_non_const_tg, pure_t> auto&& other) noexcept;

    private:
        static constexpr value_t    Value(const tr1<any_tg, pure_t> auto& self) noexcept;

    protected:
        value_t value;

    public:
        constexpr pure_t() noexcept;

        constexpr pure_t(const tr1<any_to_tg, value_t> auto& to_value) noexcept;
        constexpr pure_t(tr1<any_non_const_to_tg, value_t> auto&& to_value) noexcept;

        constexpr pure_t(const pure_t& other) noexcept;
        constexpr pure_t(const volatile pure_t& other) noexcept;
        constexpr pure_t(pure_t&& other) noexcept;
        constexpr pure_t(volatile pure_t&& other) noexcept;

        constexpr pure_t&           operator =(const pure_t& other) noexcept;
        constexpr volatile pure_t&  operator =(const pure_t& other) volatile noexcept;
        constexpr pure_t&           operator =(const volatile pure_t& other) noexcept;
        constexpr volatile pure_t&  operator =(const volatile pure_t& other) volatile noexcept;
        constexpr pure_t&           operator =(pure_t&& other) noexcept;
        constexpr volatile pure_t&  operator =(pure_t&& other) volatile noexcept;
        constexpr pure_t&           operator =(tr1<just_volatile_tg, pure_t> auto&& other) noexcept;
        constexpr volatile pure_t&  operator =(tr1<just_volatile_tg, pure_t> auto&& other) volatile noexcept;

#if defined(nkr_IS_DEBUG)
        constexpr ~pure_t() noexcept;
#endif

    public:
        explicit constexpr operator pure_t::value_t() const noexcept;
        explicit constexpr operator pure_t::value_t() const volatile noexcept;

    public:
        constexpr value_t   operator ()() const noexcept;
        constexpr value_t   operator ()() const volatile noexcept;
    };

}}

constexpr nkr::boolean::cpp_t   operator ==(const nkr::tr1<nkr::any_tg, nkr::boolean::pure_t> auto& a, const auto& b) noexcept;
constexpr nkr::boolean::cpp_t   operator ==(const nkr::tr1<nkr::any_tg, nkr::boolean::pure_t> auto& a, const auto&& b) noexcept;
constexpr nkr::boolean::cpp_t   operator ==(const nkr::tr1<nkr::any_tg, nkr::boolean::pure_t> auto&& a, const auto& b) noexcept;
constexpr nkr::boolean::cpp_t   operator ==(const nkr::tr1<nkr::any_tg, nkr::boolean::pure_t> auto&& a, const auto&& b) noexcept;

constexpr nkr::boolean::cpp_t   operator !=(const nkr::tr1<nkr::any_tg, nkr::boolean::pure_t> auto& a, const auto& b) noexcept;
constexpr nkr::boolean::cpp_t   operator !=(const nkr::tr1<nkr::any_tg, nkr::boolean::pure_t> auto& a, const auto&& b) noexcept;
constexpr nkr::boolean::cpp_t   operator !=(const nkr::tr1<nkr::any_tg, nkr::boolean::pure_t> auto&& a, const auto& b) noexcept;
constexpr nkr::boolean::cpp_t   operator !=(const nkr::tr1<nkr::any_tg, nkr::boolean::pure_t> auto&& a, const auto&& b) noexcept;

#include "nkr/boolean/pure_t_dec_def.h"
