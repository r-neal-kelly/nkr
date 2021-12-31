/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/none/value_i_dec.h"

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

namespace nkr { namespace interface { namespace none {

    template <tr1<just_non_qualified_tg, nkr::generic::implementing::constructor::default_tg> type_p>
    inline constexpr value_i<type_p>::type_t
        value_i<type_p>::Value()
        noexcept
    {
        return type_t();
    }

}}}
