/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/random/generator/software/cpp/mersenne_twister_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::random::generator::software::cpp::mersenne_twister_tg>::Is_Any()
        noexcept
    {
        return nkr::random::generator::software::cpp::mersenne_twister_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::random::generator::software::cpp::mersenne_twister_ttg>::Is_Any()
        noexcept
    {
        return nkr::random::generator::software::cpp::mersenne_twister_ttr<other_p>;
    }

}}
