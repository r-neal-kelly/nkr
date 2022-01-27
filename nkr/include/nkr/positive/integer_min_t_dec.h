/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/positive/integer_8_t_dec.h"
#include "nkr/positive/integer_16_t_dec.h"
#include "nkr/positive/integer_32_t_dec.h"
#include "nkr/positive/integer_64_t_dec.h"

namespace nkr { namespace positive {

    using   integer_min_t =
        nkr::cpp::positive::integer_min_t;

    struct  integer_min_tg  {};

    template <typename type_p>
    concept integer_min_tr =
        nkr::cpp::is_any_tr<type_p, integer_min_t> ||
        (nkr::cpp::positive_integer_tr<type_p> && sizeof(type_p) == sizeof(integer_min_t));

    template <integer_min_t value_p>
    using   integer_min_c =
        nkr::cpp::constant_t<integer_min_t, value_p>;

    template <typename type_p>
    concept integer_min_ctr =
        nkr::cpp::constant_of_tr<type_p, integer_min_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::positive::integer_min_tg> :
        public type_i<nkr::positive::integer_min_t>
    {
    public:
        using type_t    = nkr::positive::integer_min_tg;
        using of_t      = nkr::none::type_t;
    };

}}

#include "nkr/positive/integer_min_t_dec_def.h"