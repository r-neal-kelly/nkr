/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/cpp/generic/randomness/distributor_tr_dec.h"

namespace nkr { namespace cpp { namespace generic { namespace randomness { namespace $distributor_tr {

    template <nkr::cpp::is_any_tr<nkr::cpp::generic::randomness::distributor_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::generic::randomness::distributor_tr<other_p>;
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::generic::randomness::distributor_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::cpp::generic::randomness::distributor_ttg>::Is_Any()
        noexcept
    {
        return nkr::cpp::generic::randomness::distributor_ttr<other_p>;
    }

}}
