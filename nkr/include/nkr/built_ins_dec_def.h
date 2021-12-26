/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

namespace nkr { namespace interface {

    template <cpp::just_non_qualified_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<type_p>::Is_Any()
        noexcept
    {
        return cpp::is_any_tr<other_p, type_t>;
    }

}}
