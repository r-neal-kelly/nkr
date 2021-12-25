/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/negatable/integer_t_dec.h"

#include "nkr/general/negatable_tr_dec.h"
#include "nkr/general/negatable/any_tr_dec.h"
#include "nkr/general/negatable/integer_tr_dec.h"

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

#include "nkr/negatable/word_t_dec_def.h"

namespace nkr { namespace negatable {

    static_assert(general::negatable_tr<word_t>);
    static_assert(general::negatable_tr<const word_t>);
    static_assert(general::negatable_tr<volatile word_t>);
    static_assert(general::negatable_tr<const volatile word_t>);

    static_assert(general::negatable::any_tr<word_t>);
    static_assert(general::negatable::any_tr<const word_t>);
    static_assert(general::negatable::any_tr<volatile word_t>);
    static_assert(general::negatable::any_tr<const volatile word_t>);

    static_assert(general::negatable::integer_tr<word_t>);
    static_assert(general::negatable::integer_tr<const word_t>);
    static_assert(general::negatable::integer_tr<volatile word_t>);
    static_assert(general::negatable::integer_tr<const volatile word_t>);

}}