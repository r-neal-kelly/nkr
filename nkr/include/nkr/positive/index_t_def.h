/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/type_i_def.h"

#include "nkr/positive/integer_t_def.h"

#include "nkr/trait/positive_tr_def.h"
#include "nkr/trait/positive/any_tr_def.h"
#include "nkr/trait/positive/integer_tr_def.h"

#include "nkr/positive/index_t_dec.h"

namespace nkr { namespace positive {

    static_assert(trait::positive_tr<index_t>);
    static_assert(trait::positive_tr<const index_t>);
    static_assert(trait::positive_tr<volatile index_t>);
    static_assert(trait::positive_tr<const volatile index_t>);

    static_assert(trait::positive::any_tr<index_t>);
    static_assert(trait::positive::any_tr<const index_t>);
    static_assert(trait::positive::any_tr<volatile index_t>);
    static_assert(trait::positive::any_tr<const volatile index_t>);

    static_assert(trait::positive::integer_tr<index_t>);
    static_assert(trait::positive::integer_tr<const index_t>);
    static_assert(trait::positive::integer_tr<volatile index_t>);
    static_assert(trait::positive::integer_tr<const volatile index_t>);

}}
