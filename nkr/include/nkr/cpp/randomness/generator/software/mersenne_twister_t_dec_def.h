/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/cpp/randomness/generator/software/mersenne_twister_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::cpp::randomness::generator::software::mersenne_twister_tg>::Is_Any()
        noexcept
    {
        return nkr::cpp::randomness::generator::software::mersenne_twister_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::cpp::randomness::generator::software::mersenne_twister_ttg>::Is_Any()
        noexcept
    {
        return nkr::cpp::randomness::generator::software::mersenne_twister_ttr<other_p>;
    }

}}
