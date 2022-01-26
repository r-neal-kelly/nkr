/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/negatable/real_32_t_dec.h"
#include "nkr/negatable/real_64_t_dec.h"

#include "nkr/generic/negatable_tr_dec.h"
#include "nkr/generic/negatable/any_tr_dec.h"
#include "nkr/generic/negatable/real_tr_dec.h"

namespace nkr { namespace negatable {

    using   real_t =
        nkr::cpp::negatable::real_t;

    struct  real_tg {};

    template <typename type_p>
    concept real_tr =
        nkr::cpp::is_any_tr<type_p, real_t> ||
        (nkr::cpp::negatable_real_tr<type_p> && sizeof(type_p) == sizeof(real_t));

    template <real_t value_p>
    using   real_c =
        nkr::cpp::constant_t<real_t, value_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::negatable::real_tg> :
        public type_i<nkr::negatable::real_t>
    {
    public:
        using type_t    = nkr::negatable::real_tg;
    };

}}

#include "nkr/negatable/real_t_dec_def.h"

namespace nkr { namespace negatable {

    static_assert(generic::negatable_tr<real_t>);
    static_assert(generic::negatable_tr<const real_t>);
    static_assert(generic::negatable_tr<volatile real_t>);
    static_assert(generic::negatable_tr<const volatile real_t>);

    static_assert(generic::negatable::any_tr<real_t>);
    static_assert(generic::negatable::any_tr<const real_t>);
    static_assert(generic::negatable::any_tr<volatile real_t>);
    static_assert(generic::negatable::any_tr<const volatile real_t>);

    static_assert(generic::negatable::real_tr<real_t>);
    static_assert(generic::negatable::real_tr<const real_t>);
    static_assert(generic::negatable::real_tr<volatile real_t>);
    static_assert(generic::negatable::real_tr<const volatile real_t>);

}}
