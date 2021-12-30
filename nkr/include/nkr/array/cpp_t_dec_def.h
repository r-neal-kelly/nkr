/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/array/cpp_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::array::cpp_tg>::Is_Any()
        noexcept
    {
        return nkr::array::cpp_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::array::cpp_ttg>::Is()
        noexcept
    {
        return nkr::array::cpp_ttr<other_p>;
    }

}}
