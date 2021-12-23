/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_def.h"

#include "nkr/positive/integer_t_def.h"

#include "nkr/trait/positive_tr_def.h"
#include "nkr/trait/positive/any_tr_def.h"
#include "nkr/trait/positive/integer_tr_def.h"

#include "nkr/positive/count_t_dec.h"

namespace nkr { namespace positive {

    static_assert(trait::positive_tr<count_t>);
    static_assert(trait::positive_tr<const count_t>);
    static_assert(trait::positive_tr<volatile count_t>);
    static_assert(trait::positive_tr<const volatile count_t>);

    static_assert(trait::positive::any_tr<count_t>);
    static_assert(trait::positive::any_tr<const count_t>);
    static_assert(trait::positive::any_tr<volatile count_t>);
    static_assert(trait::positive::any_tr<const volatile count_t>);

    static_assert(trait::positive::integer_tr<count_t>);
    static_assert(trait::positive::integer_tr<const count_t>);
    static_assert(trait::positive::integer_tr<volatile count_t>);
    static_assert(trait::positive::integer_tr<const volatile count_t>);

}}
