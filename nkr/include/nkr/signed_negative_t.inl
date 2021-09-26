/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/fors.h"
#include "nkr/signed_negative_t.h"

namespace nkr {

    template <integer_signed_tr integer_p>
    inline typename signed_negative_t<integer_p>::value_t signed_negative_t<integer_p>::To_Value(integer_tr auto from)
    {
        value_t value = from % TOTAL;
        if (value != 0) {
            value -= TOTAL;
        }
        return value;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>::signed_negative_t() :
        value(MAX)
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>::signed_negative_t(integer_tr auto value) :
        value(To_Value(value))
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>::signed_negative_t(const signed_negative_t& other) :
        value(other.value)
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>::signed_negative_t(const volatile signed_negative_t& other) :
        value(other.value)
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>::signed_negative_t(signed_negative_t&& other) noexcept :
        value(std::exchange(other.value, MAX))
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>::signed_negative_t(volatile signed_negative_t&& other) noexcept :
        value(std::exchange(other.value, MAX))
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator =(const signed_negative_t& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator =(const signed_negative_t& other) volatile
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator =(const volatile signed_negative_t& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator =(const volatile signed_negative_t& other) volatile
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator =(signed_negative_t&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->value = std::exchange(other.value, MAX);
        }
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator =(signed_negative_t&& other) volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->value = std::exchange(other.value, MAX);
        }
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator =(is_just_volatile_tr<signed_negative_t> auto&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->value = std::exchange(other.value, MAX);
        }
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator =(is_just_volatile_tr<signed_negative_t> auto&& other) volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->value = std::exchange(other.value, MAX);
        }
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>::~signed_negative_t<integer_p>()
    {
        this->value = MAX;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>::operator value_t() const volatile
    {
        return this->value;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_negative_t<integer_p>::operator +(integer_tr auto other) const volatile
    {
        return this->value + other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_negative_t<integer_p>::operator -(integer_tr auto other) const volatile
    {
        return this->value - other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_negative_t<integer_p>::operator *(integer_tr auto other) const volatile
    {
        return this->value * other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_negative_t<integer_p>::operator /(integer_tr auto other) const volatile
    {
        return this->value / other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_negative_t<integer_p>::operator %(integer_tr auto other) const volatile
    {
        return this->value % other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_negative_t<integer_p>::operator ~() const volatile
    {
        if constexpr (sizeof(value_t) == sizeof(s8_t)) {
            return ~this->value | 0x80;
        } else if constexpr (sizeof(value_t) == sizeof(s16_t)) {
            return ~this->value | 0x8000;
        } else if constexpr (sizeof(value_t) == sizeof(s32_t)) {
            return ~this->value | 0x80000000;
        } else if constexpr (sizeof(value_t) == sizeof(s64_t)) {
            return ~this->value | 0x8000000000000000;
        }
    }

    template <integer_signed_tr integer_p>
    inline auto signed_negative_t<integer_p>::operator |(integer_tr auto other) const volatile
    {
        return this->value | other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_negative_t<integer_p>::operator &(integer_tr auto other) const volatile
    {
        return this->value & other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_negative_t<integer_p>::operator ^(integer_tr auto other) const volatile
    {
        return this->value ^ other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_negative_t<integer_p>::operator >>(integer_tr auto other) const volatile
    {
        return this->value >> other;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator +=(integer_tr auto other)
    {
        return operator =(this->value + other);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator +=(integer_tr auto other) volatile
    {
        return operator =(this->value + other);
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator -=(integer_tr auto other)
    {
        return operator =(this->value - other);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator -=(integer_tr auto other) volatile
    {
        return operator =(this->value - other);
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator *=(integer_tr auto other)
    {
        return operator =(this->value * other);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator *=(integer_tr auto other) volatile
    {
        return operator =(this->value * other);
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator /=(integer_tr auto other)
    {
        return operator =(this->value / other);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator /=(integer_tr auto other) volatile
    {
        return operator =(this->value / other);
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator %=(integer_tr auto other)
    {
        return operator =(this->value % other);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator %=(integer_tr auto other) volatile
    {
        return operator =(this->value % other);
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator |=(integer_tr auto other)
    {
        return operator =(this->value | other);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator |=(integer_tr auto other) volatile
    {
        return operator =(this->value | other);
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator &=(integer_tr auto other)
    {
        return operator =(this->value & other);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator &=(integer_tr auto other) volatile
    {
        return operator =(this->value & other);
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator ^=(integer_tr auto other)
    {
        return operator =(this->value ^ other);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator ^=(integer_tr auto other) volatile
    {
        return operator =(this->value ^ other);
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator >>=(integer_tr auto other)
    {
        return operator =(this->value >> other);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator >>=(integer_tr auto other) volatile
    {
        return operator =(this->value >> other);
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator ++()
    {
        return operator =(this->value + 1);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator ++() volatile
    {
        return operator =(this->value + 1);
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator ++(int) volatile
    {
        value_t value = this->value;
        operator =(this->value + 1);
        return value;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator --()
    {
        return operator =(this->value - 1);
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator --() volatile
    {
        return operator =(this->value - 1);
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator --(int) volatile
    {
        value_t value = this->value;
        operator =(this->value - 1);
        return value;
    }

}
