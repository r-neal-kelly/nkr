/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/cpp/concurrency/thread_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::cpp::concurrency::thread_tg>::Is_Any()
        noexcept
    {
        return nkr::cpp::concurrency::thread_tr<other_p>;
    }

}}
