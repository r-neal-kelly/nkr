/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_2ff3257d_7323_47b4_8f36_4ebe6ddf9ebd
#define nkr_INCLUDE_GUARD_2ff3257d_7323_47b4_8f36_4ebe6ddf9ebd

#include "nkr/generic/type/self/copyable_moveable_tr_dec.h"

namespace nkr { namespace generic { namespace type { namespace self { namespace copyable_moveable_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::type::self::copyable_moveable_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::type::self::copyable_moveable_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::type::self::copyable_moveable_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::type::self::copyable_moveable_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}

namespace nkr { namespace generic { namespace type { namespace self { namespace copyable_moveable_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::type::self::copyable_moveable_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::type::self::copyable_moveable_ttr<other_p>;
    }

}}}}}

#endif
