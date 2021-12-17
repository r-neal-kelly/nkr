/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_def.h"
#include "nkr/intrinsics_def.h"

#include "nkr/interface/type_traits_i_dec.h"

namespace nkr { namespace interface {

    template <typename type_p>
    template <typename other_p>
    inline constexpr cpp::bool_t
        type_traits_i<type_p>::Is_Any()
    {
        static_assert(false, "you need to implement a type_traits_i for this type");
    }

}}
