/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/generic/implementing/interface/template_tr_dec.h"

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::generic::implementing::interface::template_ttg>::Is_Any()
        noexcept
    {
        return nkr::generic::implementing::interface::template_ttr<other_p>;
    }

}}