/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_dec.h"

namespace nkr { namespace cpp {

    template <typename type_p, positive::count_t capacity_p>
    inline constexpr positive::count_t
        array_tmpl<type_p[capacity_p]>::Capacity()
        noexcept
    {
        return capacity_p;
    }

}}

namespace nkr { namespace cpp {

    inline constexpr boolean_t
        Is_Big_Endian()
        noexcept
    {
        return std::endian::native == std::endian::big;
    }

    inline constexpr boolean_t
        Is_Little_Endian()
        noexcept
    {
        return std::endian::native == std::endian::little;
    }

    inline constexpr positive::count_t
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

    template <typename parameter_p>
    inline constexpr parameter_p&&
        Forward(std::remove_reference_t<parameter_p>& argument)
        noexcept
    {
        return static_cast<parameter_p&&>(argument);
    }

    template <typename parameter_p>
        requires (!lvalue_reference_tr<parameter_p>)
    inline constexpr parameter_p&&
        Forward(std::remove_reference_t<parameter_p>&& argument)
        noexcept
    {
        return static_cast<parameter_p&&>(argument);
    }

    template <typename value_p>
        requires boolean_tr<value_p> || integer_tr<value_p> || real_tr<value_p> || pointer_tr<value_p>
    inline constexpr value_p
        Default_Min()
        noexcept
    {
        if constexpr (boolean_tr<value_p>) {
            return false;
        } else if constexpr (integer_tr<value_p>) {
            return std::numeric_limits<value_p>::min();
        } else if constexpr (real_tr<value_p>) {
            return std::numeric_limits<value_p>::lowest();
        } else if constexpr (pointer_tr<value_p>) {
            return nullptr;
        }
    }

    template <typename value_p>
        requires boolean_tr<value_p> || integer_tr<value_p> || real_tr<value_p> || pointer_tr<value_p>
    inline constexpr value_p
        Default_Max()
        noexcept
    {
        if constexpr (boolean_tr<value_p>) {
            return true;
        } else if constexpr (integer_tr<value_p>) {
            return std::numeric_limits<value_p>::max();
        } else if constexpr (real_tr<value_p>) {
            return std::numeric_limits<value_p>::max();
        } else if constexpr (pointer_tr<value_p>) {
            return reinterpret_cast<value_p>(std::numeric_limits<positive::word_t>::max());
        }
    }

    template <array_tr array_p>
    inline constexpr positive::count_t
        Array_Capacity()
        noexcept
    {
        return array_tmpl<array_p>::Capacity();
    }

}}

namespace nkr { namespace cpp {

    template <type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::value_t
        constant_t<type_p, value_p>::Value()
        noexcept
    {
        return value_p;
    }

    template <type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::constant_t() noexcept
    {
    }

    template <type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::constant_t(const constant_t& other) noexcept
    {
    }

    template <type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::constant_t(const volatile constant_t& other) noexcept
    {
    }

    template <type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::constant_t(constant_t&& other) noexcept
    {
    }

    template <type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::constant_t(volatile constant_t&& other) noexcept
    {
    }

#if defined(nkr_IS_DEBUG)
    template <type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::~constant_t() noexcept
    {
    }
#endif

    template <type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::operator constant_t<type_p, value_p>::value_t()
        const noexcept
    {
        return Value();
    }

    template <type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::operator constant_t<type_p, value_p>::value_t()
        const volatile noexcept
    {
        return Value();
    }

    template <type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::value_t
        constant_t<type_p, value_p>::operator ()()
        const noexcept
    {
        return Value();
    }

    template <type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::value_t
        constant_t<type_p, value_p>::operator ()()
        const volatile noexcept
    {
        return Value();
    }

}}
