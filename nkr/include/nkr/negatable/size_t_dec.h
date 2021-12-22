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

    struct  size_tg {};

    template <typename type_p>
    concept size_tr =
        cpp::is_any_tr<type_p, size_t> ||
        (cpp::negatable_integer_tr<type_p> && sizeof(type_p) == sizeof(size_t));

}}

namespace nkr { namespace interface {

    template <>
    class type_i<negatable::size_tg> :
        public type_i<negatable::size_t>
    {
    public:
    };

}}
