/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_643a75b4_f407_4c7e_8aaa_f29e4181f4d5
#define nkr_INCLUDE_GUARD_643a75b4_f407_4c7e_8aaa_f29e4181f4d5

#include "nkr/concurrency/lockee_t_dec.h"
#include "nkr/cpp/randomness/generator/software/mersenne_twister_19937_32_t_dec.h"
#include "nkr/cpp/randomness/generator/software/mersenne_twister_19937_64_t_dec.h"

namespace nkr { namespace randomness { namespace generator { namespace software {

#if defined(nkr_IS_64_BIT)
    using   default_t   = nkr::cpp::randomness::generator::software::mersenne_twister_19937_64_t;
#elif defined(nkr_IS_32_BIT)
    using   default_t   = nkr::cpp::randomness::generator::software::mersenne_twister_19937_32_t;
#endif

    nkr::concurrency::lockee_t<default_t>   Default() noexcept;

}}}}

#include "nkr/randomness/generator/software/default_t_dec_def.h"

#endif
