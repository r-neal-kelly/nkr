/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/template_i_def.h"
#include "nkr/interface/type_i_def.h"

#include "nkr/trait/type_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<trait::type_tg>::Is_Any()
        noexcept
    {
        return trait::type_tr<other_p>;
    }

    inline constexpr boolean::cpp_t
        template_i<trait::type_ttg>::Is_Implemented()
        noexcept
    {
        return true;
    }

}}
