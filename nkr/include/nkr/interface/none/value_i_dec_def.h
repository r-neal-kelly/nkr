/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/none/value_i_dec.h"

namespace nkr { namespace interface { namespace none {

    template <tr0<just_non_qualified_tg> type_p>
    inline constexpr value_i<type_p>::type_t
        value_i<type_p>::Value()
        noexcept
    {
        return type_t();
    }

}}}
