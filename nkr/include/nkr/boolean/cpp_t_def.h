/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_def.h"
#include "nkr/intrinsics_def.h"

#include "nkr/interface/type_i_def.h"

#include "nkr/boolean/cpp_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr cpp::bool_t
        type_i<boolean::cpp_tg>::Is_Any()
    {
        return boolean::cpp_tr<other_p>;
    }

}}
