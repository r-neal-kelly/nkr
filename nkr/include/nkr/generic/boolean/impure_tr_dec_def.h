/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/generic/boolean/impure_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::generic::boolean::impure_tg>::Is_Any()
        noexcept
    {
        return nkr::generic::boolean::impure_tr<other_p>;
    }

}}
