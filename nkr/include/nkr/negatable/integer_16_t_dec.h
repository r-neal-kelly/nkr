/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/cpp/generic/randomness/generator_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/tr_dec.h"

namespace nkr { namespace negatable {

    struct  integer_16_tg   {};

    template <typename type_p>
    concept integer_16_tr =
        nkr::cpp::is_any_tr<type_p, integer_16_t> ||
        (nkr::cpp::negatable_integer_tr<type_p> && sizeof(type_p) * 8 == 16);

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::negatable::integer_16_tg>
    {
    public:
        using type_t    = nkr::negatable::integer_16_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::negatable::integer_16_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::negatable::integer_16_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;
    };

}}

namespace nkr { namespace negatable { namespace $integer_16_t {

    template <nkr::negatable::integer_16_tr type_p>
    class none_value_i_sp
    {
    public:
        using type_t    = type_p;
        using value_t   = nkr::cpp::just_non_qualified_t<type_t>;

    public:
        static constexpr value_t    Value() noexcept;

    public:
        template <typename ...>
        constexpr none_value_i_sp(...) noexcept = delete;
    };

}}}

namespace nkr { namespace interface { namespace none {

    template <nkr::negatable::integer_16_tr type_p>
    class value_i_sp<type_p>
    {
    public:
        using type_t    = nkr::negatable::$integer_16_t::none_value_i_sp<type_p>;
    };

}}}

namespace nkr { namespace negatable { namespace $integer_16_t {

    template <nkr::negatable::integer_16_tr type_p>
    class randomness_value_i_sp
    {
    public:
        using type_t    = type_p;
        using value_t   = nkr::cpp::just_non_qualified_t<type_t>;

    public:
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(value_t min = nkr::cpp::Default_Min<value_t>(), value_t max = nkr::cpp::Default_Max<value_t>()) noexcept;
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                              value_t min = nkr::cpp::Default_Min<value_t>(), value_t max = nkr::cpp::Default_Max<value_t>()) noexcept;

    public:
        template <typename ...>
        constexpr randomness_value_i_sp(...) noexcept   = delete;
    };

}}}

namespace nkr { namespace interface { namespace randomness {

    template <nkr::negatable::integer_16_tr type_p>
    class value_i_sp<type_p>
    {
    public:
        using type_t    = nkr::negatable::$integer_16_t::randomness_value_i_sp<type_p>;
    };

}}}

#include "nkr/negatable/integer_16_t_dec_def.h"
