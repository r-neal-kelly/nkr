/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/type_i_def.h"

#include "nkr/negatable/integer_8_t_def.h"
#include "nkr/negatable/integer_16_t_def.h"
#include "nkr/negatable/integer_32_t_def.h"
#include "nkr/negatable/integer_64_t_def.h"

#include "nkr/trait/negatable_tr_def.h"
#include "nkr/trait/negatable/any_tr_def.h"
#include "nkr/trait/negatable/integer_tr_def.h"

#include "nkr/negatable/integer_t_dec.h"

namespace nkr { namespace negatable {

    static_assert(trait::negatable_tr<integer_t>);
    static_assert(trait::negatable_tr<const integer_t>);
    static_assert(trait::negatable_tr<volatile integer_t>);
    static_assert(trait::negatable_tr<const volatile integer_t>);

    static_assert(trait::negatable::any_tr<integer_t>);
    static_assert(trait::negatable::any_tr<const integer_t>);
    static_assert(trait::negatable::any_tr<volatile integer_t>);
    static_assert(trait::negatable::any_tr<const volatile integer_t>);

    static_assert(trait::negatable::integer_tr<integer_t>);
    static_assert(trait::negatable::integer_tr<const integer_t>);
    static_assert(trait::negatable::integer_tr<volatile integer_t>);
    static_assert(trait::negatable::integer_tr<const volatile integer_t>);

}}
