/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_90c912c5_53ec_47cb_8f7f_9dd5f407546d
#define nkr_INCLUDE_GUARD_90c912c5_53ec_47cb_8f7f_9dd5f407546d

#include "nkr/accumulator/templates_t_dec.h"

namespace nkr { namespace accumulator { namespace templates_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::accumulator::templates_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::accumulator::templates_tg>;
    }

    template <nkr::accumulator::templates_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::accumulator::templates_t$::Is_Any_General<other_p>();
    }

    template <nkr::accumulator::templates_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::accumulator::templates_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::accumulator::templates_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::accumulator::templates_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
