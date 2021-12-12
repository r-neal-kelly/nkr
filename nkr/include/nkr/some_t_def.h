/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/some_t_dec.h"

namespace nkr {

    template <typename other_p>
    inline constexpr c_bool_t
        type_traits_i<some_tg>::Is_Any()
    {
        return $some_t::any_tr<other_p>;
    }

    inline constexpr c_bool_t
        template_traits_i<some_ttg>::Is_Implemented()
    {
        return true;
    }

    template <some_i any_p>
    inline bool_t
        some_t<any_p>::Is_Equal_To(const is_any_tr<some_t> auto& self, const tr0<any_tg> auto& other)
    {
        using self_t = std::remove_reference_t<decltype(self)>;
        using other_t = std::remove_reference_t<decltype(other)>;

        if constexpr (is_any_tr<other_t, value_t>) {
            if constexpr (can_equal_to_tr<decltype(self()), decltype(other)>) {
                return self() == other;
            } else {
                static_assert(false, "these two values can not be equal to each other.");
            }
        } else if constexpr (tr1<other_t, any_tg, some_tg>) {
            if constexpr (can_equal_to_tr<decltype(self()), decltype(other())>) {
                return self() == other();
            } else {
                static_assert(false, "these two values can not be equal to each other.");
            }
        } else {
            return static_cast<same_qualification_as_t<base_t, self_t>&>(self).operator ==(other);
        }
    }

    template <some_i any_p>
    inline bool_t
        some_t<any_p>::operator ==(const tr0<any_tg> auto& other)
        const
    {
        return Is_Equal_To(*this, other);
    }

    template <some_i any_p>
    inline bool_t
        some_t<any_p>::operator ==(const tr0<any_tg> auto& other)
        const volatile
    {
        return Is_Equal_To(*this, other);
    }

    template <some_i any_p>
    inline bool_t
        some_t<any_p>::operator ==(const tr0<any_tg> auto&& other)
        const
    {
        return Is_Equal_To(*this, other);
    }

    template <some_i any_p>
    inline bool_t
        some_t<any_p>::operator ==(const tr0<any_tg> auto&& other)
        const volatile
    {
        return Is_Equal_To(*this, other);
    }

    template <some_i any_p>
    inline bool_t
        some_t<any_p>::operator !=(const tr0<any_tg> auto& other)
        const
    {
        return !Is_Equal_To(*this, other);
    }

    template <some_i any_p>
    inline bool_t
        some_t<any_p>::operator !=(const tr0<any_tg> auto& other)
        const volatile
    {
        return !Is_Equal_To(*this, other);
    }

    template <some_i any_p>
    inline bool_t
        some_t<any_p>::operator !=(const tr0<any_tg> auto&& other)
        const
    {
        return !Is_Equal_To(*this, other);
    }

    template <some_i any_p>
    inline bool_t
        some_t<any_p>::operator !=(const tr0<any_tg> auto&& other)
        const volatile
    {
        return !Is_Equal_To(*this, other);
    }

}
