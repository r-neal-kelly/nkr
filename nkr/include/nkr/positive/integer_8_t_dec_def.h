/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/positive/integer_8_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::positive::integer_8_tg>::Is_Any()
        noexcept
    {
        return nkr::positive::integer_8_tr<other_p>;
    }

}}

namespace nkr { namespace positive { namespace $integer_8_t {

    inline constexpr none_value_i_sp::type_t
        none_value_i_sp::Value()
        noexcept
    {
        return type_t();
    }

}}}
