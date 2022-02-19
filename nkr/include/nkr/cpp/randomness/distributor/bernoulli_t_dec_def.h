/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/cpp/randomness/distributor/bernoulli_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::cpp::randomness::distributor::bernoulli_tg>::Is_Any()
        noexcept
    {
        return nkr::cpp::randomness::distributor::bernoulli_tr<other_p>;
    }

}}
