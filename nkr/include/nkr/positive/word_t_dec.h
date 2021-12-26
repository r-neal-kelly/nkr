/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/positive/integer_t_dec.h"

#include "nkr/generic/positive_tr_dec.h"
#include "nkr/generic/positive/any_tr_dec.h"
#include "nkr/generic/positive/integer_tr_dec.h"

namespace nkr { namespace positive {

    struct  word_tg {};

    template <typename type_p>
    concept word_tr =
        cpp::is_any_tr<type_p, word_t> ||
        (cpp::positive_integer_tr<type_p> && sizeof(type_p) == sizeof(word_t));

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::positive::word_tg> :
        public type_i<nkr::positive::word_t>
    {
    public:
        using type_t    = nkr::positive::word_tg;
    };

}}

#include "nkr/positive/word_t_dec_def.h"

namespace nkr { namespace positive {

    static_assert(generic::positive_tr<word_t>);
    static_assert(generic::positive_tr<const word_t>);
    static_assert(generic::positive_tr<volatile word_t>);
    static_assert(generic::positive_tr<const volatile word_t>);

    static_assert(generic::positive::any_tr<word_t>);
    static_assert(generic::positive::any_tr<const word_t>);
    static_assert(generic::positive::any_tr<volatile word_t>);
    static_assert(generic::positive::any_tr<const volatile word_t>);

    static_assert(generic::positive::integer_tr<word_t>);
    static_assert(generic::positive::integer_tr<const word_t>);
    static_assert(generic::positive::integer_tr<volatile word_t>);
    static_assert(generic::positive::integer_tr<const volatile word_t>);

}}
