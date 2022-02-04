/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace negatable {

    using   real_32_t =
        nkr::cpp::negatable::real_32_t;

    struct  real_32_tg  {};

    template <typename type_p>
    concept real_32_tr =
        nkr::cpp::is_any_tr<type_p, real_32_t> ||
        (nkr::cpp::negatable_real_tr<type_p> && sizeof(type_p) * 8 == 32);

    template <real_32_t value_p>
    using   real_32_c =
        nkr::cpp::constant_t<real_32_t, value_p>;

    template <typename type_p>
    concept real_32_ctr =
        nkr::cpp::constant_of_tr<type_p, real_32_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::negatable::real_32_tg>
    {
    public:
        using type_t    = nkr::negatable::real_32_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::negatable::real_32_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::negatable::real_32_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;
    };

}}

namespace nkr { namespace negatable { namespace $real_32_t {

    template <nkr::negatable::real_32_tr type_p>
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

    template <nkr::negatable::real_32_tr type_p>
    class value_i_sp<type_p>
    {
    public:
        using type_t    = nkr::negatable::$real_32_t::none_value_i_sp<type_p>;
    };

}}}

#include "nkr/negatable/real_32_t_dec_def.h"
