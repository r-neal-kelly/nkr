/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/concurrency/lockee_t_dec.h"
#include "nkr/cpp/randomness/generator/hardware_t_dec.h"

namespace nkr { namespace randomness { namespace generator { namespace hardware {

    using   default_t   = nkr::cpp::randomness::generator::hardware_t;

    nkr::concurrency::lockee_t<default_t>   Default() noexcept;

}}}}

#include "nkr/randomness/generator/hardware/default_t_dec_def.h"
