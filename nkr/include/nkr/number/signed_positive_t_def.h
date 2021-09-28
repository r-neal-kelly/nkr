/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/fors.h"
#include "nkr/utils.h"

#include "nkr/number/signed_positive_t_dec.h"

namespace nkr {

    template <integer_signed_tr integer_p>
    inline typename signed_positive_t<integer_p>::value_t signed_positive_t<integer_p>::To_Value(integer_tr auto from)
    {
        return from % TOTAL;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>::signed_positive_t() :
        value(MIN)
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>::signed_positive_t(integer_tr auto value) :
        value(To_Value(value))
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>::signed_positive_t(const signed_positive_t& other) :
        value(other.value)
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>::signed_positive_t(const volatile signed_positive_t& other) :
        value(other.value)
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>::signed_positive_t(signed_positive_t&& other) noexcept :
        value(nkr::Move(other.value))
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>::signed_positive_t(volatile signed_positive_t&& other) noexcept :
        value(nkr::Move(other.value))
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator =(const signed_positive_t& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator =(const signed_positive_t& other) volatile
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator =(const volatile signed_positive_t& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator =(const volatile signed_positive_t& other) volatile
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator =(signed_positive_t&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator =(signed_positive_t&& other) volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator =(is_just_volatile_tr<signed_positive_t> auto&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator =(is_just_volatile_tr<signed_positive_t> auto&& other) volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>::~signed_positive_t<integer_p>()
    {
        this->value = MIN;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>::operator value_t() const volatile
    {
        return this->value;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator +(integer_tr auto other) const volatile
    {
        return this->value + other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator -(integer_tr auto other) const volatile
    {
        return this->value - other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator *(integer_tr auto other) const volatile
    {
        return this->value * other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator /(integer_tr auto other) const volatile
    {
        return this->value / other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator %(integer_tr auto other) const volatile
    {
        return this->value % other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator ~() const volatile
    {
        if constexpr (sizeof(value_t) == sizeof(s8_t)) {
            return ~this->value & 0x7F;
        } else if constexpr (sizeof(value_t) == sizeof(s16_t)) {
            return ~this->value & 0x7FFF;
        } else if constexpr (sizeof(value_t) == sizeof(s32_t)) {
            return ~this->value & 0x7FFFFFFF;
        } else if constexpr (sizeof(value_t) == sizeof(s64_t)) {
            return ~this->value & 0x7FFFFFFFFFFFFFFF;
        }
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator |(integer_tr auto other) const volatile
    {
        return this->value | other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator &(integer_tr auto other) const volatile
    {
        return this->value & other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator ^(integer_tr auto other) const volatile
    {
        return this->value ^ other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator <<(integer_tr auto other) const volatile
    {
        return this->value << other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator >>(integer_tr auto other) const volatile
    {
        return this->value >> other;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator +=(integer_tr auto other)
    {
        return operator =(this->value + other);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator +=(integer_tr auto other) volatile
    {
        return operator =(this->value + other);
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator -=(integer_tr auto other)
    {
        return operator =(this->value - other);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator -=(integer_tr auto other) volatile
    {
        return operator =(this->value - other);
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator *=(integer_tr auto other)
    {
        return operator =(this->value * other);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator *=(integer_tr auto other) volatile
    {
        return operator =(this->value * other);
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator /=(integer_tr auto other)
    {
        return operator =(this->value / other);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator /=(integer_tr auto other) volatile
    {
        return operator =(this->value / other);
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator %=(integer_tr auto other)
    {
        return operator =(this->value % other);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator %=(integer_tr auto other) volatile
    {
        return operator =(this->value % other);
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator |=(integer_tr auto other)
    {
        return operator =(this->value | other);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator |=(integer_tr auto other) volatile
    {
        return operator =(this->value | other);
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator &=(integer_tr auto other)
    {
        return operator =(this->value & other);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator &=(integer_tr auto other) volatile
    {
        return operator =(this->value & other);
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator ^=(integer_tr auto other)
    {
        return operator =(this->value ^ other);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator ^=(integer_tr auto other) volatile
    {
        return operator =(this->value ^ other);
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator <<=(integer_tr auto other)
    {
        return operator =(this->value << other);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator <<=(integer_tr auto other) volatile
    {
        return operator =(this->value << other);
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator >>=(integer_tr auto other)
    {
        return operator =(this->value >> other);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator >>=(integer_tr auto other) volatile
    {
        return operator =(this->value >> other);
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator ++()
    {
        return operator =(this->value + 1);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator ++() volatile
    {
        return operator =(this->value + 1);
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p> signed_positive_t<integer_p>::operator ++(int) volatile
    {
        value_t value = this->value;
        operator =(this->value + 1);
        return value;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator --()
    {
        return operator =(this->value - 1);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator --() volatile
    {
        return operator =(this->value - 1);
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p> signed_positive_t<integer_p>::operator --(int) volatile
    {
        value_t value = this->value;
        operator =(this->value - 1);
        return value;
    }

}
