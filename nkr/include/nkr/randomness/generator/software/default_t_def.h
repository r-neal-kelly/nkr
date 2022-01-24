/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_def.h"

#include "nkr/concurrency/lockee_t_def.h"
#include "nkr/cpp/randomness/generator/software/mersenne_twister_19937_32_t_def.h"
#include "nkr/cpp/randomness/generator/software/mersenne_twister_19937_64_t_def.h"
#include "nkr/randomness/generator/hardware/default_t_def.h"

#include "nkr/randomness/generator/software/default_t_dec.h"

namespace nkr { namespace randomness { namespace generator { namespace software {

#if defined(nkr_IS_64_BIT)

    inline nkr::concurrency::lockee_t<default_t>
        Default()
        noexcept
    {
        static default_t generator(nkr::randomness::generator::hardware::Default().Value()());
        static nkr::cpp::concurrency::lock::perpetual::deep_t lock;

        return nkr::concurrency::lockee_t<default_t>(generator, lock);
    }

#elif defined(nkr_IS_32_BIT)

    inline nkr::concurrency::lockee_t<default_t>
        Default()
        noexcept
    {
        static default_t generator(nkr::randomness::generator::hardware::Default().Value()());
        static nkr::cpp::concurrency::lock::perpetual::deep_t lock;

        return nkr::concurrency::lockee_t<default_t>(generator, lock);
    }

#endif

}}}}
