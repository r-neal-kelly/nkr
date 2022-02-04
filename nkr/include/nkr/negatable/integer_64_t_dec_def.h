/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/negatable/integer_64_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::negatable::integer_64_tg>::Is_Any()
        noexcept
    {
        return nkr::negatable::integer_64_tr<other_p>;
    }

}}

namespace nkr { namespace negatable { namespace $integer_64_t {

    template <nkr::negatable::integer_64_tr type_p>
    inline constexpr none_value_i_sp<type_p>::value_t
        none_value_i_sp<type_p>::Value()
        noexcept
    {
        return value_t();
    }

}}}
