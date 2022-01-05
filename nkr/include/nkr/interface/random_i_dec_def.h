/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/random_i_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::interface::random_tg>::Is_Any()
        noexcept
    {
        return nkr::interface::random_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::interface::random_ttg>::Is_Any()
        noexcept
    {
        return nkr::interface::random_ttr<other_p>;
    }

}}
