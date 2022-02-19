/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/tuple/templates_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::tuple::templates_tg>::Is_Any()
        noexcept
    {
        return nkr::tuple::templates_tr<other_p>;
    }

}}

namespace nkr { namespace tuple {

    template <template <typename ...> typename ...templates_p>
    inline constexpr nkr::positive::count_t
        templates_t<templates_p...>::Count()
        noexcept
    {
        return 0;
    }

}}

namespace nkr { namespace tuple {

    template <template <typename ...> typename head_p, template <typename ...> typename ...tail_p>
    inline constexpr nkr::positive::count_t
        templates_t<head_p, tail_p...>::Count()
        noexcept
    {
        return 1 + sizeof...(tail_p);
    }

}}
