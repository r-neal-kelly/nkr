/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/fors.h"
#include "nkr/safe_numbers.h"

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
    inline signed_positive_t<integer_p>::signed_positive_t(integer_tr auto other) :
        value(To_Value(other))
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>::signed_positive_t(const signed_positive_t& other) :
        value(other.value)
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>::signed_positive_t(volatile const signed_positive_t& other) :
        value(other.value)
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>::signed_positive_t(signed_positive_t&& other) noexcept :
        value(std::exchange(other.value, MIN))
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>::signed_positive_t(volatile signed_positive_t&& other) noexcept :
        value(std::exchange(other.value, MIN))
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator =(integer_tr auto other)
    {
        this->value = To_Value(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator =(integer_tr auto other) volatile
    {
        this->value = To_Value(other);
        return *this;
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
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator =(volatile const signed_positive_t& other) volatile
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
            this->value = std::exchange(other.value, MIN);
        }
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator =(volatile signed_positive_t&& other) volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->value = std::exchange(other.value, MIN);
        }
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>::~signed_positive_t<integer_p>()
    {
        this->value = MIN;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>::operator value_t() volatile const
    {
        return this->value;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator +(integer_tr auto other) volatile const
    {
        return this->value + other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator -(integer_tr auto other) volatile const
    {
        return this->value - other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator *(integer_tr auto other) volatile const
    {
        return this->value * other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator /(integer_tr auto other) volatile const
    {
        return this->value / other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator %(integer_tr auto other) volatile const
    {
        return this->value % other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator ~() volatile const
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
        return ~this->value;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator |(integer_tr auto other) volatile const
    {
        return this->value | other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator &(integer_tr auto other) volatile const
    {
        return this->value & other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator ^(integer_tr auto other) volatile const
    {
        return this->value ^ other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator <<(integer_tr auto other) volatile const
    {
        return this->value << other;
    }

    template <integer_signed_tr integer_p>
    inline auto signed_positive_t<integer_p>::operator >>(integer_tr auto other) volatile const
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
    inline signed_negative_t<integer_p>::signed_negative_t(integer_tr auto other) :
        value(To_Value(other))
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>::signed_negative_t(const signed_negative_t& other) :
        value(other.value)
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>::signed_negative_t(volatile const signed_negative_t& other) :
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
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator =(integer_tr auto other)
    {
        this->value = To_Value(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator =(integer_tr auto other) volatile
    {
        this->value = To_Value(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator =(const signed_negative_t& other)
    {
        if (this != std::addressof(other)) {
            new (this) signed_negative_t(other);
        }
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator =(signed_negative_t&& other) noexcept
    {
        if (this != std::addressof(other)) {
            new (this) signed_negative_t(std::move(other));
        }
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>::~signed_negative_t<integer_p>()
    {
        this->value = MAX;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>::operator value_t() volatile const
    {
        return this->value;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator +(integer_tr auto other) volatile const
    {
        return this->value + other;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator -(integer_tr auto other) volatile const
    {
        return this->value - other;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator *(integer_tr auto other) volatile const
    {
        return this->value * other;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator /(integer_tr auto other) volatile const
    {
        return this->value / other;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator %(integer_tr auto other) volatile const
    {
        return this->value % other;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator ~() volatile const
    {
        return ~this->value;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator |(integer_tr auto other) volatile const
    {
        return this->value | other;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator &(integer_tr auto other) volatile const
    {
        return this->value & other;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator ^(integer_tr auto other) volatile const
    {
        return this->value ^ other;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator <<(integer_tr auto other) volatile const
    {
        return this->value << other;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator >>(integer_tr auto other) volatile const
    {
        return this->value >> other;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator +=(integer_tr auto other)
    {
        this->value = operator +(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator +=(integer_tr auto other) volatile
    {
        this->value = operator +(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator -=(integer_tr auto other)
    {
        this->value = operator -(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator -=(integer_tr auto other) volatile
    {
        this->value = operator -(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator *=(integer_tr auto other)
    {
        this->value = operator *(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator *=(integer_tr auto other) volatile
    {
        this->value = operator *(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator /=(integer_tr auto other)
    {
        this->value = operator /(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator /=(integer_tr auto other) volatile
    {
        this->value = operator /(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator %=(integer_tr auto other)
    {
        this->value = operator %(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator %=(integer_tr auto other) volatile
    {
        this->value = operator %(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator |=(integer_tr auto other)
    {
        this->value = operator |(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator |=(integer_tr auto other) volatile
    {
        this->value = operator |(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator &=(integer_tr auto other)
    {
        this->value = operator &(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator &=(integer_tr auto other) volatile
    {
        this->value = operator &(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator ^=(integer_tr auto other)
    {
        this->value = operator ^(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator ^=(integer_tr auto other) volatile
    {
        this->value = operator ^(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator <<=(integer_tr auto other)
    {
        this->value = operator <<(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator <<=(integer_tr auto other) volatile
    {
        this->value = operator <<(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator >>=(integer_tr auto other)
    {
        this->value = operator >>(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator >>=(integer_tr auto other) volatile
    {
        this->value = operator >>(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator ++()
    {
        this->value = operator +(1);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator ++() volatile
    {
        this->value = operator +(1);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator ++(int) volatile
    {
        value_t value = this->value;
        this->value = operator +(1);
        return value;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator --()
    {
        this->value = operator -(1);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator --() volatile
    {
        this->value = operator -(1);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator --(int) volatile
    {
        value_t value = this->value;
        this->value = operator -(1);
        return value;
    }

}
