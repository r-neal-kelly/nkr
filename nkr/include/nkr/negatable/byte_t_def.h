/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_def.h"

#include "nkr/negatable/integer_t_def.h"

#include "nkr/trait/negatable_tr_def.h"
#include "nkr/trait/negatable/any_tr_def.h"
#include "nkr/trait/negatable/integer_tr_def.h"

#include "nkr/negatable/byte_t_dec.h"

namespace nkr { namespace negatable {

    static_assert(trait::negatable_tr<byte_t>);
    static_assert(trait::negatable_tr<const byte_t>);
    static_assert(trait::negatable_tr<volatile byte_t>);
    static_assert(trait::negatable_tr<const volatile byte_t>);

    static_assert(trait::negatable::any_tr<byte_t>);
    static_assert(trait::negatable::any_tr<const byte_t>);
    static_assert(trait::negatable::any_tr<volatile byte_t>);
    static_assert(trait::negatable::any_tr<const volatile byte_t>);

    static_assert(trait::negatable::integer_tr<byte_t>);
    static_assert(trait::negatable::integer_tr<const byte_t>);
    static_assert(trait::negatable::integer_tr<volatile byte_t>);
    static_assert(trait::negatable::integer_tr<const volatile byte_t>);

}}
