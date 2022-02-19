/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/cpp/concurrency/locker/exclusive_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::cpp::concurrency::locker::exclusive_tg>::Is_Any()
        noexcept
    {
        return nkr::cpp::concurrency::locker::exclusive_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::cpp::concurrency::locker::exclusive_ttg>::Is_Any()
        noexcept
    {
        return nkr::cpp::concurrency::locker::exclusive_ttr<other_p>;
    }

}}
