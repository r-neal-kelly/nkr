/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace negatable {

    using   integer_8_t =
        nkr::cpp::negatable::integer_8_t;

    struct  integer_8_tg    {};

    template <typename type_p>
    concept integer_8_tr =
        nkr::cpp::is_any_tr<type_p, integer_8_t> ||
        (nkr::cpp::negatable_integer_tr<type_p> && sizeof(type_p) * 8 == 8);

    template <integer_8_t value_p>
    using   integer_8_c =
        nkr::cpp::constant_t<integer_8_t, value_p>;

    template <typename type_p>
    concept integer_8_ctr =
        nkr::cpp::constant_of_tr<type_p, integer_8_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::negatable::integer_8_tg>
    {
    public:
        using type_t    = nkr::negatable::integer_8_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::negatable::integer_8_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::negatable::integer_8_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;
    };

}}

namespace nkr { namespace negatable { namespace $integer_8_t {

    class none_value_i_sp
    {
    public:
        using type_t    = nkr::negatable::integer_8_t;

    public:
        static constexpr type_t Value() noexcept;

    public:
        template <typename ...>
        constexpr none_value_i_sp(...) noexcept = delete;
    };

}}}

namespace nkr { namespace interface { namespace none {

    template <nkr::negatable::integer_8_tr type_p>
    class value_i_sp<type_p>
    {
    public:
        using type_t    = nkr::negatable::$integer_8_t::none_value_i_sp;
    };

}}}

#include "nkr/negatable/integer_8_t_dec_def.h"
