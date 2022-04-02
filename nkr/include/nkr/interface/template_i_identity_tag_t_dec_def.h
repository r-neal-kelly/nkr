/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_a6d902b3_8828_4eb6_808b_a328881fcfb4
#define nkr_INCLUDE_GUARD_a6d902b3_8828_4eb6_808b_a328881fcfb4

#include "nkr/interface/template_i_identity_tag_t_dec.h"

namespace nkr { namespace interface {

    template <typename template_specialization_p>
    inline constexpr nkr::positive::count_t
        template_i_identity_tag_t<template_specialization_p>::Actual_Min_Argument_Count()
        noexcept
    {
        return nkr::positive::count_t(0);
    }

    template <typename template_specialization_p>
    inline constexpr nkr::positive::count_t
        template_i_identity_tag_t<template_specialization_p>::Actual_Max_Argument_Count()
        noexcept
    {
        return nkr::positive::count_t(~0);
    }

    template <typename template_specialization_p>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_identity_tag_t<template_specialization_p>::Is_Any_Actual()
        noexcept
    {
        return nkr::cpp::is_any_ttr<other_p, actual_template_t>;
    }

}}

#endif
