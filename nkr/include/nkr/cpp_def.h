/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_def.h"

#include "nkr/cpp_dec.h"

namespace nkr { namespace cpp {

    inline constexpr bool_t
        Is_Big_Endian()
        noexcept
    {
        return std::endian::native == std::endian::big;
    }

    inline constexpr bool_t
        Is_Little_Endian()
        noexcept
    {
        return std::endian::native == std::endian::little;
    }

    inline constexpr count_t
        Byte_Bit_Count()
        noexcept
    {
        return CHAR_BIT;
    }

    inline constexpr auto*
        Address(const auto& of)
        noexcept
    {
        return std::addressof(of);
    }

    inline constexpr auto&&
        Move(auto& value)
        noexcept
    {
        return static_cast<std::remove_reference_t<decltype(value)>&&>(value);
    }

    inline constexpr auto&&
        Move(auto&& value)
        noexcept
    {
        return static_cast<std::remove_reference_t<decltype(value)>&&>(value);
    }

    inline constexpr auto
        Exchange(auto& value, const auto& with)
        noexcept
    {
        using value_t = std::remove_reference_t<decltype(value)>;
        using with_t = std::remove_reference_t<decltype(with)>;

        value_t old = static_cast<value_t&&>(value);
        value = with;

        return old;
    }

    inline constexpr auto
        Exchange(auto& value, auto&& with)
        noexcept
    {
        using value_t = std::remove_reference_t<decltype(value)>;
        using with_t = std::remove_reference_t<decltype(with)>;

        value_t old = static_cast<value_t&&>(value);
        value = static_cast<with_t&&>(with);

        return old;
    }

}}
