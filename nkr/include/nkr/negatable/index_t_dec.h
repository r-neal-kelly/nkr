/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/type_i_dec.h"

#include "nkr/negatable/integer_t_dec.h"

#include "nkr/trait/negatable_tr_dec.h"
#include "nkr/trait/negatable/any_tr_dec.h"
#include "nkr/trait/negatable/integer_tr_dec.h"

namespace nkr { namespace negatable {

    struct  index_tg    {};

    template <typename type_p>
    concept index_tr =
        cpp::is_any_tr<type_p, index_t> ||
        (cpp::negatable_integer_tr<type_p> && sizeof(type_p) == sizeof(index_t));

}}

namespace nkr { namespace interface {

    template <>
    class type_i<negatable::index_tg> :
        public type_i<negatable::index_t>
    {
    public:
    };

}}
