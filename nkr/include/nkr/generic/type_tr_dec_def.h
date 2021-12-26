/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/generic/type_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<generic::type_tg>::Is_Any()
        noexcept
    {
        return generic::type_tr<other_p>;
    }

    inline constexpr boolean::cpp_t
        template_i<generic::type_ttg>::Is_Implemented()
        noexcept
    {
        return true;
    }

}}
