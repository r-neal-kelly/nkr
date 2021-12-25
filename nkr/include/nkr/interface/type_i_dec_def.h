/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/type_i_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::interface::type_tg>::Is_Any()
        noexcept
    {
        return nkr::interface::type_tr<other_p>;
    }

}}