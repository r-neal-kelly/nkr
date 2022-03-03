/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/generic/type/self/non_copyable_moveable_tr_dec.h"

namespace nkr { namespace generic { namespace type { namespace self { namespace $non_copyable_moveable_tr {

    template <nkr::cpp::is_any_tr<nkr::generic::type::self::non_copyable_moveable_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::generic::type::self::non_copyable_moveable_tr<other_p>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::type::self::non_copyable_moveable_tg> type_p>
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
        template_i<nkr::generic::type::self::non_copyable_moveable_ttg>::Is_Any()
        noexcept
    {
        return nkr::generic::type::self::non_copyable_moveable_ttr<other_p>;
    }

}}
