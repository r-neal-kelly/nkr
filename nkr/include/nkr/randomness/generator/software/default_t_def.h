/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_6d4cc9e1_a294_4ea8_924d_9e7ffa37bc97
#define nkr_INCLUDE_GUARD_6d4cc9e1_a294_4ea8_924d_9e7ffa37bc97

#include "nkr/concurrency/lockee_t_def.h"
#include "nkr/cpp/randomness/generator/software/mersenne_twister_19937_32_t_def.h"
#include "nkr/cpp/randomness/generator/software/mersenne_twister_19937_64_t_def.h"

#include "nkr/randomness/generator/software/default_t_dec.h"

#include "nkr/cpp/concurrency/lock/perpetual/deep_t_def.h"
#include "nkr/randomness/generator/hardware/default_t_def.h"

namespace nkr { namespace randomness { namespace generator { namespace software {

    inline nkr::concurrency::lockee_t<default_t>
        Default()
        noexcept
    {
        static default_t generator(nkr::randomness::generator::hardware::Default().Value()());
        static nkr::cpp::concurrency::lock::perpetual::deep_t lock;

        return nkr::concurrency::lockee_t<default_t>(generator, lock);
    }

}}}}

#endif
