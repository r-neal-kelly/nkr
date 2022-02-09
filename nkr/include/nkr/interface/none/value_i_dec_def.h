/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/none/value_i_dec.h"

namespace nkr { namespace interface { namespace none { namespace $value_i {

    template <nkr::cpp::is_any_tr<example_t> type_p>
    inline constexpr example_value_i_sp<type_p>::value_t
        example_value_i_sp<type_p>::Value()
        noexcept
    {
        return value_t();
    }

}}}}

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::interface::none::value_tg>::Is_Any()
        noexcept
    {
        return nkr::interface::none::value_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::interface::none::value_ttg>::Is_Any()
        noexcept
    {
        return nkr::interface::none::value_ttr<other_p>;
    }

}}
