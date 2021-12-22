/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/template_i_def.h"
#include "nkr/interface/type_i_def.h"

#include "nkr/trait/negatable/any_tr_def.h"

#include "nkr/trait/negatable/real_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<trait::negatable::real_tg>::Is_Any()
        noexcept
    {
        return trait::negatable::real_tr<other_p>;
    }

    inline constexpr boolean::cpp_t
        template_i<trait::negatable::real_ttg>::Is_Implemented()
        noexcept
    {
        return true;
    }

}}
