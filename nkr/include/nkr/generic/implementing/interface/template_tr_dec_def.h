/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_86ee8841_3cd7_424a_b4b3_4dd081319ddc
#define nkr_INCLUDE_GUARD_86ee8841_3cd7_424a_b4b3_4dd081319ddc

#include "nkr/generic/implementing/interface/template_tr_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace interface { namespace template_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::implementing::interface::template_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::implementing::interface::template_ttr<other_p>;
    }

}}}}}

#endif
