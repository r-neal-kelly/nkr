/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_def.h"
#include "nkr/intrinsics_def.h"

#include "nkr/interface/template_traits_i_def.h"
#include "nkr/interface/type_traits_i_def.h"

#include "nkr/interface/boolean_i_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr cpp::bool_t
        type_traits_i<boolean_tg>::Is_Any()
    {
        return boolean_i<other_p>;
    }

    inline constexpr cpp::bool_t
        template_traits_i<boolean_ttg>::Is_Implemented()
    {
        return true;
    }

}}
