/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::tuple::types_tg>::Is_Any()
        noexcept
    {
        return nkr::tuple::types_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::tuple::types_ttg>::Is_Any()
        noexcept
    {
        return nkr::tuple::types_ttr<other_p>;
    }

}}

namespace nkr { namespace tuple {

    template <typename head_p, typename ...tail_p>
    inline constexpr nkr::positive::count_t
        types_t<head_p, tail_p...>::Count()
        noexcept
    {
        return 1 + sizeof...(tail_p);
    }

}}
