/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_30599994_32e2_46bd_9381_75703a71d2dc
#define nkr_INCLUDE_GUARD_30599994_32e2_46bd_9381_75703a71d2dc

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

#endif
