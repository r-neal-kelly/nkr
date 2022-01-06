/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/random/distributor/cpp/bernoulli_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::random::distributor::cpp::bernoulli_tg>::Is_Any()
        noexcept
    {
        return nkr::random::distributor::cpp::bernoulli_tr<other_p>;
    }

}}
