/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/type_i_def.h"

#include "nkr/negatable/real_32_t_def.h"
#include "nkr/negatable/real_64_t_def.h"

#include "nkr/trait/negatable_tr_def.h"
#include "nkr/trait/negatable/any_tr_def.h"
#include "nkr/trait/negatable/real_tr_def.h"

#include "nkr/negatable/real_t_dec.h"

namespace nkr { namespace negatable {

    static_assert(trait::negatable_tr<real_t>);
    static_assert(trait::negatable_tr<const real_t>);
    static_assert(trait::negatable_tr<volatile real_t>);
    static_assert(trait::negatable_tr<const volatile real_t>);

    static_assert(trait::negatable::any_tr<real_t>);
    static_assert(trait::negatable::any_tr<const real_t>);
    static_assert(trait::negatable::any_tr<volatile real_t>);
    static_assert(trait::negatable::any_tr<const volatile real_t>);

    static_assert(trait::negatable::real_tr<real_t>);
    static_assert(trait::negatable::real_tr<const real_t>);
    static_assert(trait::negatable::real_tr<volatile real_t>);
    static_assert(trait::negatable::real_tr<const volatile real_t>);

}}
