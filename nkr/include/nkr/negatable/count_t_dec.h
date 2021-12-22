/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/type_i_dec.h"

#include "nkr/negatable/integer_t_dec.h"

namespace nkr { namespace negatable {

    struct  count_tg    {};

    template <typename type_p>
    concept count_tr =
        cpp::is_any_tr<type_p, count_t> ||
        (cpp::negatable_integer_tr<type_p> && sizeof(type_p) == sizeof(count_t));

}}

namespace nkr { namespace interface {

    template <>
    class type_i<negatable::count_tg> :
        public type_i<negatable::count_t>
    {
    public:
    };

}}
