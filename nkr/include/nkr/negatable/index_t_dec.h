/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/negatable/integer_t_dec.h"

namespace nkr { namespace negatable {

    struct  index_tg    {};

    template <typename type_p>
    concept index_tr =
        nkr::cpp::is_any_tr<type_p, index_t> ||
        (nkr::cpp::negatable_integer_tr<type_p> && sizeof(type_p) == sizeof(index_t));

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::negatable::index_tg> :
        public type_i<nkr::negatable::index_t>
    {
    public:
        using type_t    = nkr::negatable::index_tg;
        using of_t      = nkr::none::type_t;
    };

}}

#include "nkr/negatable/index_t_dec_def.h"
