/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/z_none_t_dec.h"

namespace nkr {

    template <typename other_p>
    inline constexpr c_bool_t
        type_traits_i<none_tg>::Is_Any()
    {
        return none_tr<other_p>;
    }

}

namespace nkr {

    inline none_t::none_t()
    {
    }

    inline none_t::none_t(const none_t& other)
    {
    }

    inline none_t::none_t(const volatile none_t& other)
    {
    }

    inline none_t::none_t(none_t&& other) noexcept
    {
    }

    inline none_t::none_t(volatile none_t&& other) noexcept
    {
    }

    inline none_t&
        none_t::operator =(const none_t& other)
    {
        return *this;
    }

    inline volatile none_t&
        none_t::operator =(const none_t& other)
        volatile
    {
        return *this;
    }

    inline none_t&
        none_t::operator =(const volatile none_t& other)
    {
        return *this;
    }

    inline volatile none_t&
        none_t::operator =(const volatile none_t& other)
        volatile
    {
        return *this;
    }

    inline none_t&
        none_t::operator =(none_t&& other)
        noexcept
    {
        return *this;
    }

    inline volatile none_t&
        none_t::operator =(none_t&& other)
        volatile noexcept
    {
        return *this;
    }

    inline none_t&
        none_t::operator =(is_just_volatile_tr<none_t> auto&& other)
        noexcept
    {
        return *this;
    }

    inline volatile none_t&
        none_t::operator =(is_just_volatile_tr<none_t> auto&& other)
        volatile noexcept
    {
        return *this;
    }

    inline none_t::~none_t()
    {
    }

    inline bool_t
        operator ==(built_in_tr auto built_in, is_any_tr<none_t> auto none)
    {
        return built_in == std::remove_cvref_t<decltype(built_in)>(0);
    }

    inline bool_t
        operator !=(built_in_tr auto built_in, is_any_tr<none_t> auto none)
    {
        return !operator ==(built_in, none_t());
    }

    template <typename type_p>
    inline auto
        None()
    {
        if constexpr (built_in_tr<type_p>) {
            return std::remove_cvref_t<type_p>(0);
        } else {
            return std::remove_cvref_t<type_p>(none_t());
        }
    }

}