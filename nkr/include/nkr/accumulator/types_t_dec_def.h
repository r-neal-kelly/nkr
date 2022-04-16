/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_41374b1b_eae9_4680_a9a5_0f48fc8240ef
#define nkr_INCLUDE_GUARD_41374b1b_eae9_4680_a9a5_0f48fc8240ef

#include "nkr/accumulator/types_t_dec.h"

namespace nkr { namespace accumulator { namespace types_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::accumulator::types_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::accumulator::types_tg>;
    }

    template <nkr::accumulator::types_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::accumulator::types_t$::Is_Any_General<other_p>();
    }

    template <nkr::accumulator::types_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::accumulator::types_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::accumulator::types_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::accumulator::types_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
