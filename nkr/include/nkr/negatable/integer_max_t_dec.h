/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/negatable/integer_8_t_dec.h"
#include "nkr/negatable/integer_16_t_dec.h"
#include "nkr/negatable/integer_32_t_dec.h"
#include "nkr/negatable/integer_64_t_dec.h"

namespace nkr { namespace negatable {

    struct  integer_max_tg  {};

    template <typename type_p>
    concept integer_max_tr =
        nkr::cpp::is_any_tr<type_p, integer_max_t> ||
        (nkr::cpp::negatable_integer_tr<type_p> && sizeof(type_p) == sizeof(integer_max_t));

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::negatable::integer_max_tg> :
        public type_i<nkr::negatable::integer_max_t>
    {
    public:
        using type_t    = nkr::negatable::integer_max_tg;
        using of_t      = nkr::none::type_t;
    };

}}

#include "nkr/negatable/integer_max_t_dec_def.h"
