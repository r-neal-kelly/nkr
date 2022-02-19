/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

namespace nkr { namespace boolean {

    class deleted_operators_t
    {
    public:
        constexpr auto  operator +() const volatile noexcept        = delete;
        constexpr auto  operator -() const volatile noexcept        = delete;

        constexpr auto  operator +(auto) const volatile noexcept    = delete;
        constexpr auto  operator -(auto) const volatile noexcept    = delete;
        constexpr auto  operator *(auto) const volatile noexcept    = delete;
        constexpr auto  operator /(auto) const volatile noexcept    = delete;
        constexpr auto  operator %(auto) const volatile noexcept    = delete;

        constexpr auto  operator ~() const volatile noexcept        = delete;
        constexpr auto  operator |(auto) const volatile noexcept    = delete;
        constexpr auto  operator &(auto) const volatile noexcept    = delete;
        constexpr auto  operator ^(auto) const volatile noexcept    = delete;
        constexpr auto  operator <<(auto) const volatile noexcept   = delete;
        constexpr auto  operator >>(auto) const volatile noexcept   = delete;

        constexpr auto  operator +=(auto) const volatile noexcept   = delete;
        constexpr auto  operator -=(auto) const volatile noexcept   = delete;
        constexpr auto  operator *=(auto) const volatile noexcept   = delete;
        constexpr auto  operator /=(auto) const volatile noexcept   = delete;
        constexpr auto  operator %=(auto) const volatile noexcept   = delete;

        constexpr auto  operator |=(auto) const volatile noexcept   = delete;
        constexpr auto  operator &=(auto) const volatile noexcept   = delete;
        constexpr auto  operator ^=(auto) const volatile noexcept   = delete;
        constexpr auto  operator <<=(auto) const volatile noexcept  = delete;
        constexpr auto  operator >>=(auto) const volatile noexcept  = delete;

        constexpr auto  operator ++() const volatile noexcept       = delete;
        constexpr auto  operator ++(int) const volatile noexcept    = delete;
        constexpr auto  operator --() const volatile noexcept       = delete;
        constexpr auto  operator --(int) const volatile noexcept    = delete;

        constexpr auto  operator <(auto) const volatile noexcept    = delete;
        constexpr auto  operator >(auto) const volatile noexcept    = delete;
        constexpr auto  operator <=(auto) const volatile noexcept   = delete;
        constexpr auto  operator >=(auto) const volatile noexcept   = delete;
        constexpr auto  operator <=>(auto) const volatile noexcept  = delete;
    };

}}

#include "nkr/boolean/deleted_operators_t_dec_def.h"
