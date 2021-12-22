/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/type_i_dec.h"

#include "nkr/positive/integer_t_dec.h"

#include "nkr/trait/positive_tr_dec.h"
#include "nkr/trait/positive/any_tr_dec.h"
#include "nkr/trait/positive/integer_tr_dec.h"

namespace nkr { namespace positive {

    struct  size_tg {};

    template <typename type_p>
    concept size_tr =
        cpp::is_any_tr<type_p, size_t> ||
        (cpp::positive_integer_tr<type_p> && sizeof(type_p) == sizeof(size_t));

}}

namespace nkr { namespace interface {

    template <>
    class type_i<positive::size_tg> :
        public type_i<positive::size_t>
    {
    public:
    };

}}
