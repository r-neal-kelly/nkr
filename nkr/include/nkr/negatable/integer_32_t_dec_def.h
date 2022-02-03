/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/negatable/integer_32_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::negatable::integer_32_tg>::Is_Any()
        noexcept
    {
        return nkr::negatable::integer_32_tr<other_p>;
    }

}}

namespace nkr { namespace negatable { namespace $integer_32_t {

    inline constexpr none_value_i_sp::type_t
        none_value_i_sp::Value()
        noexcept
    {
        return type_t();
    }

}}}
