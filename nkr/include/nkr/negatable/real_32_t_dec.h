/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/generic/negatable_tr_dec.h"
#include "nkr/generic/negatable/any_tr_dec.h"
#include "nkr/generic/negatable/real_tr_dec.h"

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
    };

}}

#include "nkr/negatable/real_32_t_dec_def.h"

namespace nkr { namespace negatable {

    static_assert(generic::negatable_tr<real_32_t>);
    static_assert(generic::negatable_tr<const real_32_t>);
    static_assert(generic::negatable_tr<volatile real_32_t>);
    static_assert(generic::negatable_tr<const volatile real_32_t>);

    static_assert(generic::negatable::any_tr<real_32_t>);
    static_assert(generic::negatable::any_tr<const real_32_t>);
    static_assert(generic::negatable::any_tr<volatile real_32_t>);
    static_assert(generic::negatable::any_tr<const volatile real_32_t>);

    static_assert(generic::negatable::real_tr<real_32_t>);
    static_assert(generic::negatable::real_tr<const real_32_t>);
    static_assert(generic::negatable::real_tr<volatile real_32_t>);
    static_assert(generic::negatable::real_tr<const volatile real_32_t>);

}}
