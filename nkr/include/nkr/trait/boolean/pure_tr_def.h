/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_def.h"
#include "nkr/intrinsics_def.h"

#include "nkr/interface/template_i_def.h"
#include "nkr/interface/type_i_def.h"

#include "nkr/trait/boolean/impure_tr_def.h"

#include "nkr/trait/boolean/pure_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr cpp::bool_t
        type_i<trait::boolean::pure_tg>::Is_Any()
        noexcept
    {
        return trait::boolean::pure_tr<other_p>;
    }

    inline constexpr cpp::bool_t
        template_i<trait::boolean::pure_ttg>::Is_Implemented()
        noexcept
    {
        return true;
    }

}}
