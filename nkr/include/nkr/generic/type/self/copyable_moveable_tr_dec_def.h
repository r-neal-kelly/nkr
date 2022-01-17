/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/generic/type/self/copyable_moveable_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::generic::type::self::copyable_moveable_tg>::Is_Any()
        noexcept
    {
        return nkr::generic::type::self::copyable_moveable_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::generic::type::self::copyable_moveable_ttg>::Is_Any()
        noexcept
    {
        return nkr::generic::type::self::copyable_moveable_ttr<other_p>;
    }

}}
