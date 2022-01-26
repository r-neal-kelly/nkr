/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/type_i_dec.h"

namespace nkr { namespace interface {

    template <typename type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<type_p>::Is_Any()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::interface::type_tg>::Is_Any()
        noexcept
    {
        return nkr::interface::type_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::interface::type_ttg>::Is_Any()
        noexcept
    {
        return nkr::interface::type_ttr<other_p>;
    }

}}
