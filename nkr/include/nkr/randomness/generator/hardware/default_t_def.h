/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_2aea53a8_78b4_4804_be07_7dfb6227338c
#define nkr_INCLUDE_GUARD_2aea53a8_78b4_4804_be07_7dfb6227338c

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

#endif
