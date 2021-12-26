/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/generic/implementing/interface/none/value_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::generic::implementing::interface::none::value_tg>::Is_Any()
        noexcept
    {
        return nkr::generic::implementing::interface::none::value_tr<other_p>;
    }

}}
