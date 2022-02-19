/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/negatable/real_32_t_dec.h"
#include "nkr/negatable/real_64_t_dec.h"

namespace nkr { namespace negatable {

    struct  real_max_tg {};

    template <typename type_p>
    concept real_max_tr =
        nkr::cpp::is_any_tr<type_p, real_max_t> ||
        (nkr::cpp::negatable_real_tr<type_p> && sizeof(type_p) == sizeof(real_max_t));

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::negatable::real_max_tg> :
        public type_i<nkr::negatable::real_max_t>
    {
    public:
        using type_t    = nkr::negatable::real_max_tg;
        using of_t      = nkr::none::type_t;
    };

}}

#include "nkr/negatable/real_max_t_dec_def.h"
