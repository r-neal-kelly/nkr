/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_def.h"

#include "nkr/interface/template_i_def.h"
#include "nkr/interface/type_i_def.h"

#include "nkr/trait/boolean/any_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<trait::boolean::any_tg>::Is_Any()
        noexcept
    {
        return trait::boolean::any_tr<other_p>;
    }

    inline constexpr boolean::cpp_t
        template_i<trait::boolean::any_ttg>::Is_Implemented()
        noexcept
    {
        return true;
    }

}}
