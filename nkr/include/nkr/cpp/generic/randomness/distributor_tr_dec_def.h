/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp/generic/randomness/distributor_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::cpp::generic::randomness::distributor_tg>::Is_Any()
        noexcept
    {
        return nkr::cpp::generic::randomness::distributor_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::cpp::generic::randomness::distributor_ttg>::Is_Any()
        noexcept
    {
        return nkr::cpp::generic::randomness::distributor_ttr<other_p>;
    }

}}
