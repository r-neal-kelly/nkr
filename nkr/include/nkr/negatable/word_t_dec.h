/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/type_i_dec.h"

#include "nkr/negatable/integer_t_dec.h"

namespace nkr { namespace negatable {

    struct  word_tg {};

    template <typename type_p>
    concept word_tr =
        cpp::is_any_tr<type_p, word_t> ||
        (cpp::negatable_integer_tr<type_p> && sizeof(type_p) == sizeof(word_t));

}}

namespace nkr { namespace interface {

    template <>
    class type_i<negatable::word_tg> :
        public type_i<negatable::word_t>
    {
    public:
    };

}}
