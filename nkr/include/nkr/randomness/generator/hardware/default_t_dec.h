/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_d86e6595_5b21_48f9_9cc4_b1b80e5f1f5f
#define nkr_INCLUDE_GUARD_d86e6595_5b21_48f9_9cc4_b1b80e5f1f5f

#include "nkr/concurrency/lockee_t_dec.h"
#include "nkr/cpp/randomness/generator/hardware_t_dec.h"

namespace nkr { namespace randomness { namespace generator { namespace hardware {

    using   default_t   = nkr::cpp::randomness::generator::hardware_t;

    nkr::concurrency::lockee_t<default_t>   Default() noexcept;

}}}}

#include "nkr/randomness/generator/hardware/default_t_dec_def.h"

#endif
