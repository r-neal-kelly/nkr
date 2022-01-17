/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/concurrency/lockee_t_dec.h"
#include "nkr/cpp/randomness/generator/hardware_t_dec.h"

namespace nkr { namespace randomness { namespace generator { namespace hardware {

    nkr::concurrency::lockee_t<nkr::cpp::randomness::generator::hardware_t> Default() noexcept;

}}}}

#include "nkr/randomness/generator/hardware/default_dec_def.h"
