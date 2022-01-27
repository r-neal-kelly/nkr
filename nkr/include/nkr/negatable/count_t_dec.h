/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/forward_dec.h"
#include "nkr/negatable/integer_t_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace negatable {

    using   count_t =
        nkr::cpp::negatable::count_t;

    struct  count_tg    {};

    template <typename type_p>
    concept count_tr =
        nkr::cpp::is_any_tr<type_p, count_t> ||
        (nkr::cpp::negatable_integer_tr<type_p> && sizeof(type_p) == sizeof(count_t));

    template <count_t value_p>
    using   count_c =
        nkr::cpp::constant_t<count_t, value_p>;

    template <typename type_p>
    concept count_ctr =
        nkr::cpp::constant_of_tr<type_p, count_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::negatable::count_tg> :
        public type_i<nkr::negatable::count_t>
    {
    public:
        using type_t    = nkr::negatable::count_tg;
        using of_t      = nkr::none::type_t;
    };

}}

#include "nkr/negatable/count_t_dec_def.h"
