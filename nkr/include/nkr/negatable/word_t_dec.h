/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/negatable/integer_t_dec.h"

#include "nkr/generic/negatable_tr_dec.h"
#include "nkr/generic/negatable/any_tr_dec.h"
#include "nkr/generic/negatable/integer_tr_dec.h"

namespace nkr { namespace negatable {

    using   word_t =
        nkr::cpp::negatable::word_t;

    struct  word_tg {};

    template <typename type_p>
    concept word_tr =
        nkr::cpp::is_any_tr<type_p, word_t> ||
        (nkr::cpp::negatable_integer_tr<type_p> && sizeof(type_p) == sizeof(word_t));

    template <word_t value_p>
    using   word_c =
        nkr::cpp::constant_t<word_t, value_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::negatable::word_tg> :
        public type_i<nkr::negatable::word_t>
    {
    public:
        using type_t    = nkr::negatable::word_tg;
    };

}}

#include "nkr/negatable/word_t_dec_def.h"

namespace nkr { namespace negatable {

    static_assert(generic::negatable_tr<word_t>);
    static_assert(generic::negatable_tr<const word_t>);
    static_assert(generic::negatable_tr<volatile word_t>);
    static_assert(generic::negatable_tr<const volatile word_t>);

    static_assert(generic::negatable::any_tr<word_t>);
    static_assert(generic::negatable::any_tr<const word_t>);
    static_assert(generic::negatable::any_tr<volatile word_t>);
    static_assert(generic::negatable::any_tr<const volatile word_t>);

    static_assert(generic::negatable::integer_tr<word_t>);
    static_assert(generic::negatable::integer_tr<const word_t>);
    static_assert(generic::negatable::integer_tr<volatile word_t>);
    static_assert(generic::negatable::integer_tr<const volatile word_t>);

}}
