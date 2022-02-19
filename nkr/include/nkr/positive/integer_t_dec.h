/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/positive/integer_8_t_dec.h"
#include "nkr/positive/integer_16_t_dec.h"
#include "nkr/positive/integer_32_t_dec.h"
#include "nkr/positive/integer_64_t_dec.h"

namespace nkr { namespace positive {

    struct  integer_tg  {};

    template <typename type_p>
    concept integer_tr =
        nkr::cpp::is_any_tr<type_p, integer_t> ||
        (nkr::cpp::positive_integer_tr<type_p> && sizeof(type_p) == sizeof(integer_t));

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::positive::integer_tg> :
        public type_i<nkr::positive::integer_t>
    {
    public:
        using type_t    = nkr::positive::integer_tg;
        using of_t      = nkr::none::type_t;
    };

}}

#include "nkr/positive/integer_t_dec_def.h"
