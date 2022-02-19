/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/generic/implementing/self/constructor_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::generic::implementing::self::constructor_tg>::Is_Any()
        noexcept
    {
        return nkr::generic::implementing::self::constructor_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::generic::implementing::self::constructor_ttg>::Is_Any()
        noexcept
    {
        return nkr::generic::implementing::self::constructor_ttr<other_p>;
    }

}}
