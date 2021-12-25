/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/none/value_i_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<interface::none::value_tg>::Is_Any()
        noexcept
    {
        return interface::none::value_tr<other_p>;
    }

    inline constexpr boolean::cpp_t
        template_i<interface::none::value_ttg>::Is_Implemented()
        noexcept
    {
        return true;
    }

}}

namespace nkr { namespace interface { namespace none {

    template <tr1<just_non_qualified_tg, trait::implementing::constructor::default_tg> type_p>
    inline constexpr value_i<type_p>::type_t
        value_i<type_p>::Value()
        noexcept
    {
        return type_t();
    }

}}}
