/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_def.h"

#include "nkr/positive/integer_t_def.h"

#include "nkr/trait/positive_tr_def.h"
#include "nkr/trait/positive/any_tr_def.h"
#include "nkr/trait/positive/integer_tr_def.h"

#include "nkr/positive/word_t_dec.h"

namespace nkr { namespace positive {

    static_assert(trait::positive_tr<word_t>);
    static_assert(trait::positive_tr<const word_t>);
    static_assert(trait::positive_tr<volatile word_t>);
    static_assert(trait::positive_tr<const volatile word_t>);

    static_assert(trait::positive::any_tr<word_t>);
    static_assert(trait::positive::any_tr<const word_t>);
    static_assert(trait::positive::any_tr<volatile word_t>);
    static_assert(trait::positive::any_tr<const volatile word_t>);

    static_assert(trait::positive::integer_tr<word_t>);
    static_assert(trait::positive::integer_tr<const word_t>);
    static_assert(trait::positive::integer_tr<volatile word_t>);
    static_assert(trait::positive::integer_tr<const volatile word_t>);

}}
