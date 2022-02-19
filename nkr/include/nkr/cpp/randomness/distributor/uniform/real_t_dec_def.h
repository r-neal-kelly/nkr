/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/cpp/randomness/distributor/uniform/real_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::cpp::randomness::distributor::uniform::real_tg>::Is_Any()
        noexcept
    {
        return nkr::cpp::randomness::distributor::uniform::real_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::cpp::randomness::distributor::uniform::real_ttg>::Is_Any()
        noexcept
    {
        return nkr::cpp::randomness::distributor::uniform::real_ttr<other_p>;
    }

}}
