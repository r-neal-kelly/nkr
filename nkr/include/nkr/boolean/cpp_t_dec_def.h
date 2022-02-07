/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::boolean::cpp_tg>::Is_Any()
        noexcept
    {
        return nkr::boolean::cpp_tr<other_p>;
    }

}}

namespace nkr { namespace boolean { namespace $cpp_t {

    template <nkr::boolean::cpp_tr type_p>
    inline constexpr none_value_i_sp<type_p>::value_t
        none_value_i_sp<type_p>::Value()
        noexcept
    {
        return false;
    }

}}}
