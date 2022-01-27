/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/concurrency/lockee_t_def.h"
#include "nkr/cpp/randomness/generator/hardware_t_def.h"

#include "nkr/randomness/generator/hardware/default_t_dec.h"

#include "nkr/cpp/concurrency/lock/perpetual/deep_t_def.h"

namespace nkr { namespace randomness { namespace generator { namespace hardware {

    inline nkr::concurrency::lockee_t<default_t>
        Default()
        noexcept
    {
        static default_t generator;
        static nkr::cpp::concurrency::lock::perpetual::deep_t lock;

        return nkr::concurrency::lockee_t<default_t>(generator, lock);
    }

}}}}
