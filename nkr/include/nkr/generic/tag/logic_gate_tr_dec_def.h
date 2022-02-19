/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/generic/tag/logic_gate_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::generic::tag::logic_gate_tg>::Is_Any()
        noexcept
    {
        return nkr::generic::tag::logic_gate_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::generic::tag::logic_gate_ttg>::Is_Any()
        noexcept
    {
        return nkr::generic::tag::logic_gate_ttr<other_p>;
    }

}}
