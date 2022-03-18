/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/tuple/templates_t_dec.h"

namespace nkr { namespace tuple { namespace templates_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::tuple::templates_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::tuple::templates_tg>;
    }

    template <nkr::tuple::templates_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::tuple::templates_t$::Is_Any_General<other_p>();
    }

    template <nkr::tuple::templates_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::tuple::templates_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::tuple::templates_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::tuple::templates_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

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
