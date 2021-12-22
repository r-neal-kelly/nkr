/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/type_i_dec.h"

#include "nkr/negatable/real_32_t_dec.h"
#include "nkr/negatable/real_64_t_dec.h"

#include "nkr/trait/negatable_tr_dec.h"
#include "nkr/trait/negatable/any_tr_dec.h"
#include "nkr/trait/negatable/real_tr_dec.h"

namespace nkr { namespace negatable {

    struct  real_tg {};

    template <typename type_p>
    concept real_tr =
        cpp::is_any_tr<type_p, real_t> ||
        (cpp::negatable_real_tr<type_p> && sizeof(type_p) == sizeof(real_t));

}}

namespace nkr { namespace interface {

    template <>
    class type_i<negatable::real_tg> :
        public type_i<negatable::real_t>
    {
    public:
    };

}}
