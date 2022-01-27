/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/forward_dec.h"
#include "nkr/negatable/integer_t_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace negatable {

    using   size_t =
        nkr::cpp::negatable::size_t;

    struct  size_tg {};

    template <typename type_p>
    concept size_tr =
        nkr::cpp::is_any_tr<type_p, size_t> ||
        (nkr::cpp::negatable_integer_tr<type_p> && sizeof(type_p) == sizeof(size_t));

    template <size_t value_p>
    using   size_c =
        nkr::cpp::constant_t<size_t, value_p>;

    template <typename type_p>
    concept size_ctr =
        nkr::cpp::constant_of_tr<type_p, size_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::negatable::size_tg> :
        public type_i<nkr::negatable::size_t>
    {
    public:
        using type_t    = nkr::negatable::size_tg;
        using of_t      = nkr::none::type_t;
    };

}}

#include "nkr/negatable/size_t_dec_def.h"
