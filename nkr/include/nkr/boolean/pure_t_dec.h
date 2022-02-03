/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/boolean/deleted_operators_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/randomness/value_i_dec.h"
#include "nkr/negatable/real_t_dec.h"
#include "nkr/none/type_t_dec.h"
#include "nkr/tr_dec.h"

/*
    pure_t:
        - to remove the integer-like behavior of an nkr::boolean::cpp_t
*/

namespace nkr { namespace boolean {

    class   pure_t;

    struct  pure_tg {};

    template <typename type_p>
    concept pure_tr =
        nkr::cpp::is_any_tr<type_p, pure_t>;

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
        static constexpr auto&  Assign(tr<any_non_const_tg, t<pure_t>> auto& self, const tr<any_tg, t<pure_t>> auto& other) noexcept;
        static constexpr auto&  Assign(tr<any_non_const_tg, t<pure_t>> auto& self, tr<any_non_const_tg, t<pure_t>> auto&& other) noexcept;

    private:
        static constexpr value_t    Value(const tr<any_tg, t<pure_t>> auto& self) noexcept;

    protected:
        value_t value;

    public:
        constexpr pure_t() noexcept;

        constexpr pure_t(const tr<any_to_tg, t<value_t>> auto& from) noexcept;
        constexpr pure_t(tr<any_non_const_to_tg, t<value_t>> auto&& from) noexcept;

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
        constexpr pure_t&           operator =(tr<just_volatile_tg, t<pure_t>> auto&& other) noexcept;
        constexpr volatile pure_t&  operator =(tr<just_volatile_tg, t<pure_t>> auto&& other) volatile noexcept;

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

namespace nkr { namespace boolean { namespace $pure_t {

    class none_value_i_sp
    {
    public:
        using type_t    = nkr::boolean::pure_t;

    public:
        static constexpr type_t Value() noexcept;

    public:
        template <typename ...>
        constexpr none_value_i_sp(...) noexcept = delete;
    };

}}}

namespace nkr { namespace interface { namespace none {

    template <nkr::boolean::pure_tr type_p>
    class value_i_sp<type_p>
    {
    public:
        using type_t    = nkr::boolean::$pure_t::none_value_i_sp;
    };

}}}

namespace nkr { namespace boolean { namespace $pure_t {

    template <nkr::boolean::pure_tr value_p>
    class randomness_value_i_sp
    {
    public:
        using value_t   = value_p;

    public:
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(nkr::negatable::real_t probability_for_true = 0.5) noexcept;
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                              nkr::negatable::real_t probability_for_true = 0.5) noexcept;

        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(value_t min, value_t max) noexcept;
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                              value_t min, value_t max) noexcept;

    public:
        template <typename ...>
        constexpr randomness_value_i_sp(...) noexcept   = delete;
    };

}}}

namespace nkr { namespace interface { namespace randomness {

    template <nkr::boolean::pure_tr value_p>
    class value_i_sp<value_p>
    {
    public:
        using type_t    = nkr::boolean::$pure_t::randomness_value_i_sp<nkr::cpp::just_non_qualified_t<value_p>>;
    };

}}}

constexpr nkr::boolean::cpp_t   operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto& a, const auto& b) noexcept;
constexpr nkr::boolean::cpp_t   operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto& a, const auto&& b) noexcept;
constexpr nkr::boolean::cpp_t   operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto&& a, const auto& b) noexcept;
constexpr nkr::boolean::cpp_t   operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto&& a, const auto&& b) noexcept;

constexpr nkr::boolean::cpp_t   operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto& a, const auto& b) noexcept;
constexpr nkr::boolean::cpp_t   operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto& a, const auto&& b) noexcept;
constexpr nkr::boolean::cpp_t   operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto&& a, const auto& b) noexcept;
constexpr nkr::boolean::cpp_t   operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto&& a, const auto&& b) noexcept;

#include "nkr/boolean/pure_t_dec_def.h"
