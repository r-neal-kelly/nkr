/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/negatable/integer_t_dec.h"

namespace nkr { namespace negatable {

    struct  count_tg    {};

    template <typename type_p>
    concept count_tr =
        nkr::cpp::is_any_tr<type_p, count_t> ||
        (nkr::cpp::negatable_integer_tr<type_p> && sizeof(type_p) == sizeof(count_t));

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
