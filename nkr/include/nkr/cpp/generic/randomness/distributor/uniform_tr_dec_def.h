/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_3bd06cc5_d3d3_4544_9f33_0d0dd156366a
#define nkr_INCLUDE_GUARD_3bd06cc5_d3d3_4544_9f33_0d0dd156366a

#include "nkr/cpp/generic/randomness/distributor/uniform_tr_dec.h"

namespace nkr { namespace cpp { namespace generic { namespace randomness { namespace distributor { namespace uniform_tr$ {

    template <nkr::cpp::is_any_tr<nkr::cpp::generic::randomness::distributor::uniform_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::cpp::generic::randomness::distributor::uniform_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::cpp::generic::randomness::distributor::uniform_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::generic::randomness::distributor::uniform_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}}

namespace nkr { namespace cpp { namespace generic { namespace randomness { namespace distributor { namespace uniform_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::generic::randomness::distributor::uniform_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::cpp::generic::randomness::distributor::uniform_ttr<other_p>;
    }

}}}}}}

#endif
