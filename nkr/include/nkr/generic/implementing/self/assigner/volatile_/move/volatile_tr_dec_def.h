/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_66f73601_c5b5_4709_957c_8a6105f522ce
#define nkr_INCLUDE_GUARD_66f73601_c5b5_4709_957c_8a6105f522ce

#include "nkr/generic/implementing/self/assigner/volatile_/move/volatile_tr_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace self { namespace assigner {
namespace volatile_ { namespace move { namespace volatile_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::self::assigner::volatile_::move::volatile_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::implementing::self::assigner::volatile_::move::volatile_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::implementing::self::assigner::volatile_::move::volatile_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::self::assigner::volatile_::move::volatile_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}}}}

namespace nkr { namespace generic { namespace implementing { namespace self { namespace assigner {
namespace volatile_ { namespace move { namespace volatile_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::implementing::self::assigner::volatile_::move::volatile_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::implementing::self::assigner::volatile_::move::volatile_ttr<other_p>;
    }

}}}}}}}}

#endif
