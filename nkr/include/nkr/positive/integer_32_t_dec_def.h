/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/positive/integer_32_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::positive::integer_32_tg>::Is_Any()
        noexcept
    {
        return nkr::positive::integer_32_tr<other_p>;
    }

}}

namespace nkr { namespace positive { namespace $integer_32_t {

    template <nkr::positive::integer_32_tr type_p>
    inline constexpr none_value_i_sp<type_p>::value_t
        none_value_i_sp<type_p>::Value()
        noexcept
    {
        return value_t();
    }

}}}
