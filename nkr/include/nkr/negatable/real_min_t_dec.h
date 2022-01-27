/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/negatable/real_32_t_dec.h"
#include "nkr/negatable/real_64_t_dec.h"

namespace nkr { namespace negatable {

    using   real_min_t =
        nkr::cpp::negatable::real_min_t;

    struct  real_min_tg {};

    template <typename type_p>
    concept real_min_tr =
        nkr::cpp::is_any_tr<type_p, real_min_t> ||
        (nkr::cpp::negatable_real_tr<type_p> && sizeof(type_p) == sizeof(real_min_t));

    template <real_min_t value_p>
    using   real_min_c =
        nkr::cpp::constant_t<real_min_t, value_p>;

    template <typename type_p>
    concept real_min_ctr =
        nkr::cpp::constant_of_tr<type_p, real_min_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::negatable::real_min_tg> :
        public type_i<nkr::negatable::real_min_t>
    {
    public:
        using type_t    = nkr::negatable::real_min_tg;
        using of_t      = nkr::none::type_t;
    };

}}

#include "nkr/negatable/real_min_t_dec_def.h"
