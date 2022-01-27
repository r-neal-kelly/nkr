/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/positive/integer_t_dec.h"

namespace nkr { namespace positive {

    using   index_t =
        nkr::cpp::positive::index_t;

    struct  index_tg    {};

    template <typename type_p>
    concept index_tr =
        nkr::cpp::is_any_tr<type_p, index_t> ||
        (nkr::cpp::positive_integer_tr<type_p> && sizeof(type_p) == sizeof(index_t));

    template <index_t value_p>
    using   index_c =
        nkr::cpp::constant_t<index_t, value_p>;

    template <typename type_p>
    concept index_ctr =
        nkr::cpp::constant_of_tr<type_p, index_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::positive::index_tg> :
        public type_i<nkr::positive::index_t>
    {
    public:
        using type_t    = nkr::positive::index_tg;
        using of_t      = nkr::none::type_t;
    };

}}

#include "nkr/positive/index_t_dec_def.h"
