/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/type_i_def.h"

#include "nkr/negatable/integer_t_def.h"

#include "nkr/trait/negatable_tr_def.h"
#include "nkr/trait/negatable/any_tr_def.h"
#include "nkr/trait/negatable/integer_tr_def.h"

#include "nkr/negatable/count_t_dec.h"

namespace nkr { namespace negatable {

    static_assert(trait::negatable_tr<count_t>);
    static_assert(trait::negatable_tr<const count_t>);
    static_assert(trait::negatable_tr<volatile count_t>);
    static_assert(trait::negatable_tr<const volatile count_t>);

    static_assert(trait::negatable::any_tr<count_t>);
    static_assert(trait::negatable::any_tr<const count_t>);
    static_assert(trait::negatable::any_tr<volatile count_t>);
    static_assert(trait::negatable::any_tr<const volatile count_t>);

    static_assert(trait::negatable::integer_tr<count_t>);
    static_assert(trait::negatable::integer_tr<const count_t>);
    static_assert(trait::negatable::integer_tr<volatile count_t>);
    static_assert(trait::negatable::integer_tr<const volatile count_t>);

}}
