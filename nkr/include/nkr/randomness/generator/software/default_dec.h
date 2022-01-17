/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/concurrency/lockee_t_dec.h"
#include "nkr/cpp/randomness/generator/software/mersenne_twister_19937_32_t_dec.h"
#include "nkr/cpp/randomness/generator/software/mersenne_twister_19937_64_t_dec.h"
#include "nkr/randomness/generator/hardware/default_dec.h"

namespace nkr { namespace randomness { namespace generator { namespace software {

#if defined(nkr_IS_64_BIT)

    nkr::concurrency::lockee_t<nkr::cpp::randomness::generator::software::mersenne_twister_19937_64_t>  Default() noexcept;

#elif defined(nkr_IS_32_BIT)

    nkr::concurrency::lockee_t<nkr::cpp::randomness::generator::software::mersenne_twister_19937_32_t>  Default() noexcept;

#endif

}}}}

#include "nkr/randomness/generator/software/default_dec_def.h"
