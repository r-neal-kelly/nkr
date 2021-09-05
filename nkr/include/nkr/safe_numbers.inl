/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/fors.h"
#include "nkr/safe_numbers.h"

namespace nkr {

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>::signed_positive_t() :
        value(MIN)
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>::signed_positive_t(convertible_tr<value_t> auto other) :
        value(other % TOTAL)
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>::signed_positive_t(const signed_positive_t& other) :
        value(other.value)
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>::signed_positive_t(signed_positive_t&& other) noexcept :
        value(std::exchange(other.value, MIN))
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator =(convertible_tr<value_t> auto other)
    {
        new (this) signed_positive_t(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator =(const signed_positive_t& other)
    {
        if (this != std::addressof(other)) {
            new (this) signed_positive_t(other);
        }
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator =(signed_positive_t&& other) noexcept
    {
        if (this != std::addressof(other)) {
            new (this) signed_positive_t(std::move(other));
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
    inline signed_positive_t<integer_p> signed_positive_t<integer_p>::operator +(convertible_tr<value_t> auto other) volatile const
    {
        return this->value + other;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p> signed_positive_t<integer_p>::operator -(convertible_tr<value_t> auto other) volatile const
    {
        return this->value - other;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p> signed_positive_t<integer_p>::operator *(convertible_tr<value_t> auto other) volatile const
    {
        return this->value * other;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p> signed_positive_t<integer_p>::operator /(convertible_tr<value_t> auto other) volatile const
    {
        return this->value / other;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p> signed_positive_t<integer_p>::operator %(convertible_tr<value_t> auto other) volatile const
    {
        return this->value % other;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p> signed_positive_t<integer_p>::operator ~() volatile const
    {
        return ~this->value;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p> signed_positive_t<integer_p>::operator |(convertible_tr<value_t> auto other) volatile const
    {
        return this->value | other;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p> signed_positive_t<integer_p>::operator &(convertible_tr<value_t> auto other) volatile const
    {
        return this->value & other;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p> signed_positive_t<integer_p>::operator ^(convertible_tr<value_t> auto other) volatile const
    {
        return this->value ^ other;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p> signed_positive_t<integer_p>::operator <<(convertible_tr<value_t> auto other) volatile const
    {
        return this->value << other;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p> signed_positive_t<integer_p>::operator >>(convertible_tr<value_t> auto other) volatile const
    {
        return this->value >> other;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator +=(convertible_tr<value_t> auto other)
    {
        this->value = operator +(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator +=(convertible_tr<value_t> auto other) volatile
    {
        this->value = operator +(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator -=(convertible_tr<value_t> auto other)
    {
        this->value = operator -(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator -=(convertible_tr<value_t> auto other) volatile
    {
        this->value = operator -(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator *=(convertible_tr<value_t> auto other)
    {
        this->value = operator *(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator *=(convertible_tr<value_t> auto other) volatile
    {
        this->value = operator *(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator /=(convertible_tr<value_t> auto other)
    {
        this->value = operator /(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator /=(convertible_tr<value_t> auto other) volatile
    {
        this->value = operator /(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator %=(convertible_tr<value_t> auto other)
    {
        this->value = operator %(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator %=(convertible_tr<value_t> auto other) volatile
    {
        this->value = operator %(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator |=(convertible_tr<value_t> auto other)
    {
        this->value = operator |(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator |=(convertible_tr<value_t> auto other) volatile
    {
        this->value = operator |(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator &=(convertible_tr<value_t> auto other)
    {
        this->value = operator &(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator &=(convertible_tr<value_t> auto other) volatile
    {
        this->value = operator &(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator ^=(convertible_tr<value_t> auto other)
    {
        this->value = operator ^(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator ^=(convertible_tr<value_t> auto other) volatile
    {
        this->value = operator ^(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator <<=(convertible_tr<value_t> auto other)
    {
        this->value = operator <<(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator <<=(convertible_tr<value_t> auto other) volatile
    {
        this->value = operator <<(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator >>=(convertible_tr<value_t> auto other)
    {
        this->value = operator >>(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator >>=(convertible_tr<value_t> auto other) volatile
    {
        this->value = operator >>(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator ++()
    {
        this->value = operator +(1);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator ++() volatile
    {
        this->value = operator +(1);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p> signed_positive_t<integer_p>::operator ++(int) volatile
    {
        value_t value = this->value;
        this->value = operator +(1);
        return value;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator --()
    {
        this->value = operator -(1);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_positive_t<integer_p>& signed_positive_t<integer_p>::operator --() volatile
    {
        this->value = operator -(1);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_positive_t<integer_p> signed_positive_t<integer_p>::operator --(int) volatile
    {
        value_t value = this->value;
        this->value = operator -(1);
        return value;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>::signed_negative_t() :
        value(MAX)
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>::signed_negative_t(convertible_tr<value_t> auto other) :
        value(other % TOTAL)
    {
        if (value != 0) {
            value -= TOTAL;
        }
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>::signed_negative_t(const signed_negative_t& other) :
        value(other.value)
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>::signed_negative_t(signed_negative_t&& other) noexcept :
        value(std::exchange(other.value, MAX))
    {
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator =(convertible_tr<value_t> auto other)
    {
        new (this) signed_negative_t(other);
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
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator +(convertible_tr<value_t> auto other) volatile const
    {
        return this->value + other;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator -(convertible_tr<value_t> auto other) volatile const
    {
        return this->value - other;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator *(convertible_tr<value_t> auto other) volatile const
    {
        return this->value * other;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator /(convertible_tr<value_t> auto other) volatile const
    {
        return this->value / other;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator %(convertible_tr<value_t> auto other) volatile const
    {
        return this->value % other;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator ~() volatile const
    {
        return ~this->value;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator |(convertible_tr<value_t> auto other) volatile const
    {
        return this->value | other;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator &(convertible_tr<value_t> auto other) volatile const
    {
        return this->value & other;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator ^(convertible_tr<value_t> auto other) volatile const
    {
        return this->value ^ other;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator <<(convertible_tr<value_t> auto other) volatile const
    {
        return this->value << other;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p> signed_negative_t<integer_p>::operator >>(convertible_tr<value_t> auto other) volatile const
    {
        return this->value >> other;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator +=(convertible_tr<value_t> auto other)
    {
        this->value = operator +(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator +=(convertible_tr<value_t> auto other) volatile
    {
        this->value = operator +(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator -=(convertible_tr<value_t> auto other)
    {
        this->value = operator -(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator -=(convertible_tr<value_t> auto other) volatile
    {
        this->value = operator -(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator *=(convertible_tr<value_t> auto other)
    {
        this->value = operator *(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator *=(convertible_tr<value_t> auto other) volatile
    {
        this->value = operator *(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator /=(convertible_tr<value_t> auto other)
    {
        this->value = operator /(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator /=(convertible_tr<value_t> auto other) volatile
    {
        this->value = operator /(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator %=(convertible_tr<value_t> auto other)
    {
        this->value = operator %(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator %=(convertible_tr<value_t> auto other) volatile
    {
        this->value = operator %(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator |=(convertible_tr<value_t> auto other)
    {
        this->value = operator |(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator |=(convertible_tr<value_t> auto other) volatile
    {
        this->value = operator |(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator &=(convertible_tr<value_t> auto other)
    {
        this->value = operator &(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator &=(convertible_tr<value_t> auto other) volatile
    {
        this->value = operator &(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator ^=(convertible_tr<value_t> auto other)
    {
        this->value = operator ^(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator ^=(convertible_tr<value_t> auto other) volatile
    {
        this->value = operator ^(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator <<=(convertible_tr<value_t> auto other)
    {
        this->value = operator <<(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator <<=(convertible_tr<value_t> auto other) volatile
    {
        this->value = operator <<(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator >>=(convertible_tr<value_t> auto other)
    {
        this->value = operator >>(other);
        return *this;
    }

    template <integer_signed_tr integer_p>
    inline volatile signed_negative_t<integer_p>& signed_negative_t<integer_p>::operator >>=(convertible_tr<value_t> auto other) volatile
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
