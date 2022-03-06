/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_some_t_dec.h"

namespace nkr {

    template <typename other_p>
    inline constexpr c_bool_t
        type_traits_i<some_tg>::Is_Any()
    {
        return some_t$::any_tr<other_p>;
    }

    inline constexpr c_bool_t
        template_traits_i<some_ttg>::Is_Implemented()
    {
        return true;
    }

}

namespace nkr {

    inline bool_t
        operator ==(const tr1<any_tg, some_tg> auto& a, const tr0<any_tg> auto& b)
    {
        using a_t = std::remove_reference_t<decltype(a)>;
        using b_t = std::remove_reference_t<decltype(b)>;

        if constexpr (is_any_tr<b_t, none_t>) {
            return a.operator ==(b);
        } else if constexpr (is_any_tr<b_t, typename a_t::value_t>) {
            if constexpr (can_equal_to_tr<decltype(a()), decltype(b)>) {
                return a() == b;
            } else {
                [] <bool _ = false>() { static_assert(_, "these two values can not be equal to each other."); }();
            }
        } else if constexpr (tr1<b_t, any_tg, some_tg>) {
            if constexpr (can_equal_to_tr<decltype(a()), decltype(b())>) {
                return a() == b();
            } else {
                [] <bool _ = false>() { static_assert(_, "these two values can not be equal to each other."); }();
            }
        } else {
            return static_cast<same_qualification_as_t<maybe_t<typename a_t::value_t>, a_t>&>(a) == b;
        }
    }

    inline bool_t
        operator ==(const tr1<any_tg, some_tg> auto& a, const tr0<any_tg> auto&& b)
    {
        return operator ==(a, b);
    }

    inline bool_t
        operator ==(const tr1<any_tg, some_tg> auto&& a, const tr0<any_tg> auto& b)
    {
        return operator ==(a, b);
    }

    inline bool_t
        operator ==(const tr1<any_tg, some_tg> auto&& a, const tr0<any_tg> auto&& b)
    {
        return operator ==(a, b);
    }

    inline bool_t
        operator !=(const tr1<any_tg, some_tg> auto& a, const tr0<any_tg> auto& b)
    {
        return !operator ==(a, b);
    }

    inline bool_t
        operator !=(const tr1<any_tg, some_tg> auto& a, const tr0<any_tg> auto&& b)
    {
        return !operator ==(a, b);
    }

    inline bool_t
        operator !=(const tr1<any_tg, some_tg> auto&& a, const tr0<any_tg> auto& b)
    {
        return !operator ==(a, b);
    }

    inline bool_t
        operator !=(const tr1<any_tg, some_tg> auto&& a, const tr0<any_tg> auto&& b)
    {
        return !operator ==(a, b);
    }

}
