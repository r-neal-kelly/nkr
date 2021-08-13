/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/atomic_t.h"
#include "nkr/os.h"

namespace nkr {

    template <atomicable_tr value_p>
    inline atomic_t<value_p>::atomic_t() :
        value(0)
    {
    }

    template <atomicable_tr value_p>
    inline atomic_t<value_p>::atomic_t(value_t value) :
        value(value)
    {
    }

    template <atomicable_tr value_p>
    inline atomic_t<value_p>::atomic_t(const atomic_t& other) :
        value(other.Access())
    {
    }

    template <atomicable_tr value_p>
    inline atomic_t<value_p>::atomic_t(atomic_t&& other) noexcept :
        value(other.Exchange(0))
    {
    }

    template <atomicable_tr value_p>
    inline atomic_t<value_p>& atomic_t<value_p>::operator =(const atomic_t& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.Access();
        }
        return *this;
    }

    template <atomicable_tr value_p>
    inline atomic_t<value_p>& atomic_t<value_p>::operator =(atomic_t&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->value = other.Exchange(0);
        }
        return *this;
    }

    template <atomicable_tr value_p>
    inline atomic_t<value_p>::~atomic_t()
    {
        this->value = 0;
    }

    template <atomicable_tr value_p>
    inline atomic_t<value_p>::value_t atomic_t<value_p>::Access() const
    {
        return os::atomic::Access(this->value);
    }

    template <atomicable_tr value_p>
    template <integral_tr integral_p>
    inline atomic_t<value_p>::value_t atomic_t<value_p>::Exchange(integral_p with)
    {
        return os::atomic::Exchange_Assign(this->value, with);
    }

    template <atomicable_tr value_p>
    inline atomic_t<value_p>::operator bool_t() const
    {
        return static_cast<bool_t>(os::atomic::Access(this->value));
    }

    template <atomicable_tr value_p>
    inline atomic_t<value_p>::operator value_t() const
    {
        return os::atomic::Access(this->value);
    }

    template <atomicable_tr value_p>
    inline bool_t atomic_t<value_p>::operator !() const
    {
        return !operator bool_t();
    }

    template <atomicable_tr value_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator ()() const
    {
        return os::atomic::Access(this->value);
    }

    template <atomicable_tr value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator =(integral_p other)
    {
        return os::atomic::Assign(this->value, other);
    }

    template <atomicable_tr value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator +(integral_p other) const
    {
        return os::atomic::Access(this->value) + other;
    }

    template <atomicable_tr value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator -(integral_p other) const
    {
        return os::atomic::Access(this->value) - other;
    }

    template <atomicable_tr value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator +=(integral_p other)
    {
        return os::atomic::Add(this->value, other);
    }

    template <atomicable_tr value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator -=(integral_p other)
    {
        return os::atomic::Subtract(this->value, other);
    }

    template <atomicable_tr value_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator ++()
    {
        return os::atomic::Add(this->value, 1);
    }

    template <atomicable_tr value_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator ++(int)
    {
        return os::atomic::Exchange_Add(this->value, 1);
    }

    template <atomicable_tr value_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator --()
    {
        return os::atomic::Subtract(this->value, 1);
    }

    template <atomicable_tr value_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator --(int)
    {
        return os::atomic::Exchange_Subtract(this->value, 1);
    }

    template <atomicable_tr value_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator ~() const
    {
        return ~os::atomic::Access(this->value);
    }

    template <atomicable_tr value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator |(integral_p other) const
    {
        return os::atomic::Access(this->value) | other;
    }

    template <atomicable_tr value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator &(integral_p other) const
    {
        return os::atomic::Access(this->value) & other;
    }

    template <atomicable_tr value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator ^(integral_p other) const
    {
        return os::atomic::Access(this->value) ^ other;
    }

    template <atomicable_tr value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator |=(integral_p other)
    {
        return os::atomic::Or(this->value, other);
    }

    template <atomicable_tr value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator &=(integral_p other)
    {
        return os::atomic::And(this->value, other);
    }

    template <atomicable_tr value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator ^=(integral_p other)
    {
        return os::atomic::Xor(this->value, other);
    }

    inline atomic_t<bool_t>::atomic_t() :
        value(false)
    {
    }

    inline atomic_t<bool_t>::atomic_t(value_t value) :
        value(value)
    {
    }

    inline atomic_t<bool_t>::atomic_t(const atomic_t& other) :
        value(other.Access())
    {
    }

    inline atomic_t<bool_t>::atomic_t(atomic_t&& other) noexcept :
        value(other.Exchange(false))
    {
    }

    inline atomic_t<bool_t>& atomic_t<bool_t>::operator =(const atomic_t& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.Access();
        }
        return *this;
    }

    inline atomic_t<bool_t>& atomic_t<bool_t>::operator =(atomic_t&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->value = other.Exchange(false);
        }
        return *this;
    }

    inline atomic_t<bool_t>::~atomic_t()
    {
        this->value = false;
    }

    inline atomic_t<bool_t>::value_t atomic_t<bool_t>::Access() const
    {
        return os::atomic::Access(this->value);
    }

    inline atomic_t<bool_t>::value_t atomic_t<bool_t>::Exchange(value_t with)
    {
        return os::atomic::Exchange_Assign(this->value, with);
    }

    inline atomic_t<bool_t>::operator value_t() const
    {
        return os::atomic::Access(this->value);
    }

    inline typename atomic_t<bool_t>::value_t atomic_t<bool_t>::operator !() const
    {
        return !operator value_t();
    }

    inline typename atomic_t<bool_t>::value_t atomic_t<bool_t>::operator ()() const
    {
        return os::atomic::Access(this->value);
    }

    inline typename atomic_t<bool_t>::value_t atomic_t<bool_t>::operator =(value_t other)
    {
        return os::atomic::Assign(this->value, other);
    }

    template <atomicable_tr value_p>
    inline atomic_t<value_p*>::atomic_t() :
        values(nullptr)
    {
    }

    template <atomicable_tr value_p>
    inline atomic_t<value_p*>::atomic_t(values_t values) :
        values(values)
    {
    }

    template <atomicable_tr value_p>
    inline atomic_t<value_p*>::atomic_t(const atomic_t& other) :
        values(other.Access())
    {
    }

    template <atomicable_tr value_p>
    inline atomic_t<value_p*>::atomic_t(atomic_t&& other) noexcept :
        values(other.Exchange(nullptr))
    {
    }

    template <atomicable_tr value_p>
    inline atomic_t<value_p*>& atomic_t<value_p*>::operator =(const atomic_t& other)
    {
        if (this != std::addressof(other)) {
            this->values = other.Access();
        }
        return *this;
    }

    template <atomicable_tr value_p>
    inline atomic_t<value_p*>& atomic_t<value_p*>::operator =(atomic_t&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->values = other.Exchange(nullptr);
        }
        return *this;
    }

    template <atomicable_tr value_p>
    inline atomic_t<value_p*>::~atomic_t()
    {
        this->values = nullptr;
    }

    template <atomicable_tr value_p>
    inline atomic_t<value_p*>::values_t atomic_t<value_p*>::Access() const
    {
        return os::atomic::Access(this->values);
    }

    template <atomicable_tr value_p>
    template <pointer_tr pointer_p>
    inline atomic_t<value_p*>::values_t atomic_t<value_p*>::Exchange(pointer_p with)
    {
        return os::atomic::Exchange_Assign(this->values, with);
    }

    template <atomicable_tr value_p>
    inline atomic_t<value_p*>::operator bool_t() const
    {
        return static_cast<bool_t>(os::atomic::Access(this->values));
    }

    template <atomicable_tr value_p>
    inline atomic_t<value_p*>::operator values_t() const
    {
        return os::atomic::Access(this->values);
    }

    template <atomicable_tr value_p>
    inline bool_t atomic_t<value_p*>::operator !() const
    {
        return !operator bool_t();
    }

    template <atomicable_tr value_p>
    inline typename atomic_t<value_p*>::values_t atomic_t<value_p*>::operator ()() const
    {
        return os::atomic::Access(this->values);
    }

    template <atomicable_tr value_p>
    template <pointer_tr pointer_p>
    inline typename atomic_t<value_p*>::values_t atomic_t<value_p*>::operator =(pointer_p other)
    {
        return os::atomic::Assign(this->values, other);
    }

    template <atomicable_tr value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p*>::values_t atomic_t<value_p*>::operator +(integral_p other) const
    {
        return os::atomic::Access(this->values) + other;
    }

    template <atomicable_tr value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p*>::values_t atomic_t<value_p*>::operator -(integral_p other) const
    {
        return os::atomic::Access(this->values) - other;
    }

    template <atomicable_tr value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p*>::values_t atomic_t<value_p*>::operator +=(integral_p other)
    {
        return os::atomic::Add(this->values, other);
    }

    template <atomicable_tr value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p*>::values_t atomic_t<value_p*>::operator -=(integral_p other)
    {
        return os::atomic::Subtract(this->values, other);
    }

    template <atomicable_tr value_p>
    inline typename atomic_t<value_p*>::values_t atomic_t<value_p*>::operator ++()
    {
        return os::atomic::Add(this->values, 1);
    }

    template <atomicable_tr value_p>
    inline typename atomic_t<value_p*>::values_t atomic_t<value_p*>::operator ++(int)
    {
        return os::atomic::Exchange_Add(this->values, 1);
    }

    template <atomicable_tr value_p>
    inline typename atomic_t<value_p*>::values_t atomic_t<value_p*>::operator --()
    {
        return os::atomic::Subtract(this->values, 1);
    }

    template <atomicable_tr value_p>
    inline typename atomic_t<value_p*>::values_t atomic_t<value_p*>::operator --(int)
    {
        return os::atomic::Exchange_Subtract(this->values, 1);
    }

    template <atomicable_tr value_p>
    inline typename atomic_t<value_p*>::values_t atomic_t<value_p*>::operator ->() const
    {
        return os::atomic::Access(this->values);
    }

    template <atomicable_tr value_p>
    inline typename atomic_t<value_p*>::value_t& atomic_t<value_p*>::operator *() const
    {
        return *os::atomic::Access(this->values);
    }

    template <atomicable_tr value_p>
    inline typename atomic_t<value_p*>::value_t& atomic_t<value_p*>::operator [](index_t index) const
    {
        return os::atomic::Access(this->values)[index];
    }

}