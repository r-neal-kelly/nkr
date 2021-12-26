/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

// will get mixed with the old traits until we remove them
//#include "nkr/tr_dec.h"

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
