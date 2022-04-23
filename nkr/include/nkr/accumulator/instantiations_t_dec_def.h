/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_e23b038c_5dbe_4391_87c9_a6191bf3a8a1
#define nkr_INCLUDE_GUARD_e23b038c_5dbe_4391_87c9_a6191bf3a8a1

#include "nkr/accumulator/instantiations_t_dec.h"

namespace nkr { namespace accumulator { namespace instantiations_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::accumulator::instantiations_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::accumulator::instantiations_tg>;
    }

    template <nkr::accumulator::instantiations_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::accumulator::instantiations_t$::Is_Any_General<other_p>();
    }

    template <nkr::accumulator::instantiations_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::accumulator::instantiations_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::accumulator::instantiations_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::accumulator::instantiations_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
