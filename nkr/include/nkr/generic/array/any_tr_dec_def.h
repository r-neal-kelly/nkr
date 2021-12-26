/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/generic/array/any_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<generic::array::any_tg>::Is_Any()
        noexcept
    {
        return generic::array::any_tr<other_p>;
    }

    inline constexpr boolean::cpp_t
        template_i<generic::array::any_ttg>::Is_Implemented()
        noexcept
    {
        return true;
    }

}}
