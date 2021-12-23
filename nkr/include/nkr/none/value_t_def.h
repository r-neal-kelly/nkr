/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_def.h"

#include "nkr/boolean/cpp_t_def.h"

#include "nkr/interface/template_i_def.h"
#include "nkr/interface/type_i_def.h"

#include "nkr/trait/defaultable_tr_def.h"
#include "nkr/trait/none_tr_def.h"
#include "nkr/trait/none/any_tr_def.h"

#include "nkr/none/value_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<none::value_tg>::Is_Any()
        noexcept
    {
        return none::value_tr<other_p>;
    }

    inline constexpr boolean::cpp_t
        template_i<none::value_ttg>::Is_Implemented()
        noexcept
    {
        return true;
    }

}}

namespace nkr { namespace none {

    template <trait::defaultable_tr type_p>
    inline constexpr value_t<type_p>::value_t() noexcept
    {
    }

    template <trait::defaultable_tr type_p>
    inline constexpr value_t<type_p>::value_t(const value_t& other) noexcept
    {
    }

    template <trait::defaultable_tr type_p>
    inline constexpr value_t<type_p>::value_t(const volatile value_t& other) noexcept
    {
    }

    template <trait::defaultable_tr type_p>
    inline constexpr value_t<type_p>::value_t(value_t&& other) noexcept
    {
    }

    template <trait::defaultable_tr type_p>
    inline constexpr value_t<type_p>::value_t(volatile value_t&& other) noexcept
    {
    }

    template <trait::defaultable_tr type_p>
    inline constexpr value_t<type_p>&
        value_t<type_p>::operator =(const value_t& other)
        noexcept
    {
        return *this;
    }

    template <trait::defaultable_tr type_p>
    inline constexpr volatile value_t<type_p>&
        value_t<type_p>::operator =(const value_t& other)
        volatile noexcept
    {
        return *this;
    }

    template <trait::defaultable_tr type_p>
    inline constexpr value_t<type_p>&
        value_t<type_p>::operator =(const volatile value_t& other)
        noexcept
    {
        return *this;
    }

    template <trait::defaultable_tr type_p>
    inline constexpr volatile value_t<type_p>&
        value_t<type_p>::operator =(const volatile value_t& other)
        volatile noexcept
    {
        return *this;
    }

    template <trait::defaultable_tr type_p>
    inline constexpr value_t<type_p>&
        value_t<type_p>::operator =(value_t&& other)
        noexcept
    {
        return *this;
    }

    template <trait::defaultable_tr type_p>
    inline constexpr volatile value_t<type_p>&
        value_t<type_p>::operator =(value_t&& other)
        volatile noexcept
    {
        return *this;
    }

    template <trait::defaultable_tr type_p>
    inline constexpr value_t<type_p>&
        value_t<type_p>::operator =(tr1<just_volatile_tg, value_t> auto&& other)
        noexcept
    {
        return *this;
    }

    template <trait::defaultable_tr type_p>
    inline constexpr volatile value_t<type_p>&
        value_t<type_p>::operator =(tr1<just_volatile_tg, value_t> auto&& other)
        volatile noexcept
    {
        return *this;
    }

#if defined(nkr_IS_DEBUG)
    template <trait::defaultable_tr type_p>
    inline constexpr value_t<type_p>::~value_t() noexcept
    {
    }
#endif

    template <trait::defaultable_tr type_p>
    inline constexpr value_t<type_p>::operator type_t()
        const noexcept
    {
        return cpp::just_non_qualified_t<type_t>();
    }

    template <trait::defaultable_tr type_p>
    inline constexpr value_t<type_p>::operator type_t()
        const volatile noexcept
    {
        return cpp::just_non_qualified_t<type_t>();
    }

}}

namespace nkr { namespace none {

    static_assert(trait::none_tr<value_t<positive::integer_t>>);
    static_assert(trait::none_tr<const value_t<positive::integer_t>>);
    static_assert(trait::none_tr<volatile value_t<positive::integer_t>>);
    static_assert(trait::none_tr<const volatile value_t<positive::integer_t>>);

    static_assert(trait::none::any_tr<value_t<positive::integer_t>>);
    static_assert(trait::none::any_tr<const value_t<positive::integer_t>>);
    static_assert(trait::none::any_tr<volatile value_t<positive::integer_t>>);
    static_assert(trait::none::any_tr<const volatile value_t<positive::integer_t>>);

}}
