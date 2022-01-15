/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp/concurrency/lock/temporal/unary_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::cpp::concurrency::lock::temporal::unary_tg>::Is_Any()
        noexcept
    {
        return nkr::cpp::concurrency::lock::temporal::unary_tr<other_p>;
    }

}}
