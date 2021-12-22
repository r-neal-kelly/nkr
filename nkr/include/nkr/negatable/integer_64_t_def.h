/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/type_i_def.h"

#include "nkr/negatable/integer_64_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<negatable::integer_64_tg>::Is_Any()
        noexcept
    {
        return negatable::integer_64_tr<other_p>;
    }

}}

namespace nkr { namespace negatable {



}}
