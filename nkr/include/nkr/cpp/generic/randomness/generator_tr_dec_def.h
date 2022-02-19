/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/cpp/generic/randomness/generator_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::cpp::generic::randomness::generator_tg>::Is_Any()
        noexcept
    {
        return nkr::cpp::generic::randomness::generator_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::cpp::generic::randomness::generator_ttg>::Is_Any()
        noexcept
    {
        return nkr::cpp::generic::randomness::generator_ttr<other_p>;
    }

}}
