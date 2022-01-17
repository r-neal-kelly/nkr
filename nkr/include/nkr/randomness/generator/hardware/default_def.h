/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_def.h"

#include "nkr/concurrency/lockee_t_def.h"
#include "nkr/cpp/randomness/generator/hardware_t_def.h"

#include "nkr/randomness/generator/hardware/default_dec.h"

namespace nkr { namespace randomness { namespace generator { namespace hardware {

    nkr::concurrency::lockee_t<nkr::cpp::randomness::generator::hardware_t>
        Default()
        noexcept
    {
        static nkr::cpp::randomness::generator::hardware_t generator;
        static nkr::cpp::concurrency::lock::perpetual::deep_t lock;

        return nkr::concurrency::lockee_t<nkr::cpp::randomness::generator::hardware_t>(generator, lock);
    }

}}}}
