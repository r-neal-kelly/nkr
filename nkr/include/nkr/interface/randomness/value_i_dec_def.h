/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/randomness/value_i_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::interface::randomness::value_tg>::Is_Any()
        noexcept
    {
        return nkr::interface::randomness::value_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::interface::randomness::value_ttg>::Is_Any()
        noexcept
    {
        return nkr::interface::randomness::value_ttr<other_p>;
    }

}}
