/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/type_i_def.h"

#include "nkr/positive/integer_t_def.h"

#include "nkr/trait/positive_tr_def.h"
#include "nkr/trait/positive/any_tr_def.h"
#include "nkr/trait/positive/integer_tr_def.h"

#include "nkr/positive/size_t_dec.h"

namespace nkr { namespace positive {

    static_assert(trait::positive_tr<size_t>);
    static_assert(trait::positive_tr<const size_t>);
    static_assert(trait::positive_tr<volatile size_t>);
    static_assert(trait::positive_tr<const volatile size_t>);

    static_assert(trait::positive::any_tr<size_t>);
    static_assert(trait::positive::any_tr<const size_t>);
    static_assert(trait::positive::any_tr<volatile size_t>);
    static_assert(trait::positive::any_tr<const volatile size_t>);

    static_assert(trait::positive::integer_tr<size_t>);
    static_assert(trait::positive::integer_tr<const size_t>);
    static_assert(trait::positive::integer_tr<volatile size_t>);
    static_assert(trait::positive::integer_tr<const volatile size_t>);

}}
