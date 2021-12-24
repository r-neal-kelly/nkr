/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/type_i_dec.h"

namespace nkr { namespace interface {

    template <typename type_p>
    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<type_p>::Is_Any()
        noexcept
    {
        static_assert(false, "you need to implement or include a type_i for this type");
    }

}}
