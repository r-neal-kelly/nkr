/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/pointer/cpp_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::pointer::cpp_tg>::Is_Any()
        noexcept
    {
        return nkr::pointer::cpp_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::pointer::cpp_ttg>::Is_Any()
        noexcept
    {
        return nkr::pointer::cpp_ttr<other_p>;
    }

}}

namespace nkr { namespace pointer { namespace $cpp_t {

    template <nkr::pointer::cpp_tr type_p>
    inline constexpr none_value_i_sp<type_p>::value_t
        none_value_i_sp<type_p>::Value()
        noexcept
    {
        return value_t();
    }

}}}
