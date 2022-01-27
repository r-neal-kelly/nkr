/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/forward_dec.h"
#include "nkr/none/type_t_dec.h"
#include "nkr/positive/integer_t_dec.h"

namespace nkr { namespace positive {

    using   word_t =
        nkr::cpp::positive::word_t;

    struct  word_tg {};

    template <typename type_p>
    concept word_tr =
        nkr::cpp::is_any_tr<type_p, word_t> ||
        (nkr::cpp::positive_integer_tr<type_p> && sizeof(type_p) == sizeof(word_t));

    template <word_t value_p>
    using   word_c =
        nkr::cpp::constant_t<word_t, value_p>;

    template <typename type_p>
    concept word_ctr =
        nkr::cpp::constant_of_tr<type_p, word_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::positive::word_tg> :
        public type_i<nkr::positive::word_t>
    {
    public:
        using type_t    = nkr::positive::word_tg;
        using of_t      = nkr::none::type_t;
    };

}}

#include "nkr/positive/word_t_dec_def.h"
