/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/template_i_def.h"
#include "nkr/interface/type_i_def.h"

#include "nkr/trait/positive/any_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<trait::positive::any_tg>::Is_Any()
        noexcept
    {
        return trait::positive::any_tr<other_p>;
    }

    inline constexpr boolean::cpp_t
        template_i<trait::positive::any_ttg>::Is_Implemented()
        noexcept
    {
        return true;
    }

}}
