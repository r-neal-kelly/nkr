/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_89019349_0654_4974_b87c_387b2d1c30b0
#define nkr_INCLUDE_GUARD_89019349_0654_4974_b87c_387b2d1c30b0

#include "nkr/cpp/generic/randomness/distributor_tr_dec.h"

namespace nkr { namespace cpp { namespace generic { namespace randomness { namespace distributor_tr$ {

    template <nkr::cpp::is_any_tr<nkr::cpp::generic::randomness::distributor_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::cpp::generic::randomness::distributor_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::cpp::generic::randomness::distributor_tg>;
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

namespace nkr { namespace cpp { namespace generic { namespace randomness { namespace distributor_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::generic::randomness::distributor_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::cpp::generic::randomness::distributor_ttr<other_p>;
    }

}}}}}

#endif
