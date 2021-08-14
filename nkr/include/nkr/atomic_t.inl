/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/atomic_t.h"
#include "nkr/os.h"

namespace nkr {

    template <typename value_p>
    inline atomic_t<value_p>::atomic_t() :
        value(0)
    {
    }

    template <typename value_p>
    inline atomic_t<value_p>::atomic_t(value_t value) :
        value(value)
    {
    }

    template <typename value_p>
    inline atomic_t<value_p>::atomic_t(const atomic_t& other) :
        value(other.Access())
    {
    }

    template <typename value_p>
    inline atomic_t<value_p>::atomic_t(atomic_t&& other) noexcept :
        value(other.Exchange_Assign(0))
    {
    }

    template <typename value_p>
    inline atomic_t<value_p>& atomic_t<value_p>::operator =(const atomic_t& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.Access();
        }
        return *this;
    }

    template <typename value_p>
    inline atomic_t<value_p>& atomic_t<value_p>::operator =(atomic_t&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->value = other.Exchange_Assign(0);
        }
        return *this;
    }

    template <typename value_p>
    inline atomic_t<value_p>::~atomic_t()
    {
        Assign(0);
    }

    template <typename value_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Access() const
    {
        return os::atomic::Access(this->value);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Assign(integral_p value)
    {
        return os::atomic::Assign(this->value, value);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Exchange_Assign(integral_p value)
    {
        return os::atomic::Exchange_Assign(this->value, value);
    }

    template <typename value_p>
    template <integral_tr integral_a_p, integral_tr integral_b_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Exchange_Assign_If_Equals(integral_a_p value, integral_b_p target)
    {
        return os::atomic::Exchange_Assign_If_Equals(this->value, value, target);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Assign_Add(integral_p value)
    {
        return os::atomic::Assign_Add(this->value, value);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Exchange_Add(integral_p value)
    {
        return os::atomic::Exchange_Add(this->value, value);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Assign_Subtract(integral_p value)
    {
        return os::atomic::Assign_Subtract(this->value, value);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Exchange_Subtract(integral_p value)
    {
        return os::atomic::Exchange_Subtract(this->value, value);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Assign_Or(integral_p value)
    {
        return os::atomic::Assign_Or(this->value, value);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Exchange_Or(integral_p value)
    {
        return os::atomic::Exchange_Or(this->value, value);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Assign_And(integral_p value)
    {
        return os::atomic::Assign_And(this->value, value);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Exchange_And(integral_p value)
    {
        return os::atomic::Exchange_And(this->value, value);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Assign_Xor(integral_p value)
    {
        return os::atomic::Assign_Xor(this->value, value);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Exchange_Xor(integral_p value)
    {
        return os::atomic::Exchange_Xor(this->value, value);
    }

    template <typename value_p>
    inline atomic_t<value_p>::operator value_t() const
    {
        return Access();
    }

    template <typename value_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator ()() const
    {
        return Access();
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator =(integral_p value)
    {
        return Assign(value);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator +(integral_p value) const
    {
        return Access() + value;
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator -(integral_p value) const
    {
        return Access() - value;
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator +=(integral_p value)
    {
        return Assign_Add(value);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator -=(integral_p value)
    {
        return Assign_Subtract(value);
    }

    template <typename value_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator ++()
    {
        return Assign_Add(1);
    }

    template <typename value_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator ++(int)
    {
        return Exchange_Add(1);
    }

    template <typename value_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator --()
    {
        return Assign_Subtract(1);
    }

    template <typename value_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator --(int)
    {
        return Exchange_Subtract(1);
    }

    template <typename value_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator ~() const
    {
        return ~Access();
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator |(integral_p value) const
    {
        return Access() | value;
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator &(integral_p value) const
    {
        return Access() & value;
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator ^(integral_p value) const
    {
        return Access() ^ value;
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator |=(integral_p value)
    {
        return Assign_Or(value);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator &=(integral_p value)
    {
        return Assign_And(value);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator ^=(integral_p value)
    {
        return Assign_Xor(value);
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
        value(other.Exchange_Assign(false))
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
            this->value = other.Exchange_Assign(false);
        }
        return *this;
    }

    inline atomic_t<bool_t>::~atomic_t()
    {
        Assign(false);
    }

    inline typename atomic_t<bool_t>::value_t atomic_t<bool_t>::Access() const
    {
        return os::atomic::Access(this->value);
    }

    inline typename atomic_t<bool_t>::value_t atomic_t<bool_t>::Assign(value_t value)
    {
        return os::atomic::Assign(this->value, value);
    }

    inline typename atomic_t<bool_t>::value_t atomic_t<bool_t>::Exchange_Assign(value_t value)
    {
        return os::atomic::Exchange_Assign(this->value, value);
    }

    inline typename atomic_t<bool_t>::value_t atomic_t<bool_t>::Exchange_Assign_If_Equals(value_t value, value_t target)
    {
        return os::atomic::Exchange_Assign_If_Equals(this->value, value, target);
    }

    inline atomic_t<bool_t>::operator value_t() const
    {
        return Access();
    }

    inline typename atomic_t<bool_t>::value_t atomic_t<bool_t>::operator ()() const
    {
        return Access();
    }

    inline typename atomic_t<bool_t>::value_t atomic_t<bool_t>::operator =(value_t value)
    {
        return Assign(value);
    }

    template <typename value_p>
    inline atomic_t<value_p*>::atomic_t() :
        value(nullptr)
    {
    }

    template <typename value_p>
    inline atomic_t<value_p*>::atomic_t(value_t* value) :
        value(value)
    {
    }

    template <typename value_p>
    inline atomic_t<value_p*>::atomic_t(const atomic_t& other) :
        value(other.Access())
    {
    }

    template <typename value_p>
    inline atomic_t<value_p*>::atomic_t(atomic_t&& other) noexcept :
        value(other.Exchange_Assign(nullptr))
    {
    }

    template <typename value_p>
    inline atomic_t<value_p*>& atomic_t<value_p*>::operator =(const atomic_t& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.Access();
        }
        return *this;
    }

    template <typename value_p>
    inline atomic_t<value_p*>& atomic_t<value_p*>::operator =(atomic_t&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->value = other.Exchange_Assign(nullptr);
        }
        return *this;
    }

    template <typename value_p>
    inline atomic_t<value_p*>::~atomic_t()
    {
        Assign(nullptr);
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Access() const
    {
        return os::atomic::Access(this->value);
    }

    template <typename value_p>
    template <pointer_tr pointer_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Assign(pointer_p value)
    {
        return os::atomic::Assign(this->value, value);
    }

    template <typename value_p>
    template <pointer_tr pointer_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Exchange_Assign(pointer_p value)
    {
        return os::atomic::Exchange_Assign(this->value, value);
    }

    template <typename value_p>
    template <pointer_tr pointer_a_p, pointer_tr pointer_b_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Exchange_Assign_If_Equals(pointer_a_p value, pointer_b_p target)
    {
        return os::atomic::Exchange_Assign_If_Equals(this->value, value, target);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Assign_Add(integral_p value)
    {
        return os::atomic::Assign_Add(this->value, value);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Exchange_Add(integral_p value)
    {
        return os::atomic::Exchange_Add(this->value, value);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Assign_Subtract(integral_p value)
    {
        return os::atomic::Assign_Subtract(this->value, value);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Exchange_Subtract(integral_p value)
    {
        return os::atomic::Exchange_Subtract(this->value, value);
    }

    template <typename value_p>
    inline atomic_t<value_p*>::operator value_t*() const
    {
        return Access();
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator ()() const
    {
        return Access();
    }

    template <typename value_p>
    template <pointer_tr pointer_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator =(pointer_p value)
    {
        return Assign(value);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator +(integral_p value) const
    {
        return Access() + value;
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator -(integral_p value) const
    {
        return Access() - value;
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator +=(integral_p value)
    {
        return Assign_Add(value);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator -=(integral_p value)
    {
        return Assign_Subtract(value);
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator ++()
    {
        return Assign_Add(1);
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator ++(int)
    {
        return Exchange_Add(1);
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator --()
    {
        return Assign_Subtract(1);
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator --(int)
    {
        return Exchange_Subtract(1);
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator ->() const
    {
        return Access();
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t& atomic_t<value_p*>::operator *() const
    {
        return *Access();
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p*>::value_t& atomic_t<value_p*>::operator [](integral_p index) const
    {
        return Access()[index];
    }

    inline atomic_t<void_t*>::atomic_t() :
        value(nullptr)
    {
    }

    inline atomic_t<void_t*>::atomic_t(value_t* value) :
        value(value)
    {
    }

    inline atomic_t<void_t*>::atomic_t(const atomic_t& other) :
        value(other.Access())
    {
    }

    inline atomic_t<void_t*>::atomic_t(atomic_t&& other) noexcept :
        value(other.Exchange_Assign(nullptr))
    {
    }

    inline atomic_t<void_t*>& atomic_t<void_t*>::operator =(const atomic_t& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.Access();
        }
        return *this;
    }

    inline atomic_t<void_t*>& atomic_t<void_t*>::operator =(atomic_t&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->value = other.Exchange_Assign(nullptr);
        }
        return *this;
    }

    inline atomic_t<void_t*>::~atomic_t()
    {
        Assign(nullptr);
    }

    inline typename atomic_t<void_t*>::value_t* atomic_t<void_t*>::Access() const
    {
        return os::atomic::Access(this->value);
    }

    template <pointer_tr pointer_p>
    inline typename atomic_t<void_t*>::value_t* atomic_t<void_t*>::Assign(pointer_p value)
    {
        return os::atomic::Assign(this->value, value);
    }

    template <pointer_tr pointer_p>
    inline typename atomic_t<void_t*>::value_t* atomic_t<void_t*>::Exchange_Assign(pointer_p value)
    {
        return os::atomic::Exchange_Assign(this->value, value);
    }

    template <pointer_tr pointer_a_p, pointer_tr pointer_b_p>
    inline typename atomic_t<void_t*>::value_t* atomic_t<void_t*>::Exchange_Assign_If_Equals(pointer_a_p value, pointer_b_p target)
    {
        return os::atomic::Exchange_Assign_If_Equals(this->value, value, target);
    }

    inline atomic_t<void_t*>::operator value_t*() const
    {
        return Access();
    }

    inline typename atomic_t<void_t*>::value_t* atomic_t<void_t*>::operator ()() const
    {
        return Access();
    }

    template <pointer_tr pointer_p>
    inline typename atomic_t<void_t*>::value_t* atomic_t<void_t*>::operator =(pointer_p value)
    {
        return Assign(value);
    }

}
