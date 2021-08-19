/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/atomic_t.h"
#include "nkr/os.h"

namespace nkr {

    template <typename integer_p>
    inline atomic_t<integer_p>::atomic_t() :
        value(0)
    {
    }

    template <typename integer_p>
    inline atomic_t<integer_p>::atomic_t(value_t value) :
        value(value)
    {
    }

    template <typename integer_p>
    inline atomic_t<integer_p>::atomic_t(const atomic_t& other) :
        value(other.Access())
    {
    }

    template <typename integer_p>
    inline atomic_t<integer_p>::atomic_t(atomic_t&& other) noexcept :
        value(other.Exchange(0))
    {
    }

    template <typename integer_p>
    inline atomic_t<integer_p>& atomic_t<integer_p>::operator =(const atomic_t& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.Access();
        }
        return *this;
    }

    template <typename integer_p>
    inline atomic_t<integer_p>& atomic_t<integer_p>::operator =(atomic_t&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->value = other.Exchange(0);
        }
        return *this;
    }

    template <typename integer_p>
    inline atomic_t<integer_p>::~atomic_t()
    {
        Assign(0);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::Access() const
    {
        return os::atomic::Access(this->value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::Access_Add(integer_tr auto value) const
    {
        return os::atomic::Access_Add(this->value, value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::Access_Subtract(integer_tr auto value) const
    {
        return os::atomic::Access_Subtract(this->value, value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::Access_Or(integer_tr auto value) const
    {
        return os::atomic::Access_Or(this->value, value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::Access_And(integer_tr auto value) const
    {
        return os::atomic::Access_And(this->value, value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::Access_Xor(integer_tr auto value) const
    {
        return os::atomic::Access_Xor(this->value, value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::Assign(integer_tr auto value)
    {
        return os::atomic::Assign(this->value, value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::Assign_Add(integer_tr auto value)
    {
        return os::atomic::Assign_Add(this->value, value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::Assign_Subtract(integer_tr auto value)
    {
        return os::atomic::Assign_Subtract(this->value, value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::Assign_Or(integer_tr auto value)
    {
        return os::atomic::Assign_Or(this->value, value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::Assign_And(integer_tr auto value)
    {
        return os::atomic::Assign_And(this->value, value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::Assign_Xor(integer_tr auto value)
    {
        return os::atomic::Assign_Xor(this->value, value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::Exchange(integer_tr auto value)
    {
        return os::atomic::Exchange(this->value, value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::Exchange_If_Equals(integer_tr auto value,
                                                                                         integer_tr auto target)
    {
        return os::atomic::Exchange_If_Equals(this->value, value, target);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::Exchange_Add(integer_tr auto value)
    {
        return os::atomic::Exchange_Add(this->value, value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::Exchange_Subtract(integer_tr auto value)
    {
        return os::atomic::Exchange_Subtract(this->value, value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::Exchange_Or(integer_tr auto value)
    {
        return os::atomic::Exchange_Or(this->value, value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::Exchange_And(integer_tr auto value)
    {
        return os::atomic::Exchange_And(this->value, value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::Exchange_Xor(integer_tr auto value)
    {
        return os::atomic::Exchange_Xor(this->value, value);
    }

    template <typename integer_p>
    inline atomic_t<integer_p>::operator value_t() const
    {
        return Access();
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::operator ()() const
    {
        return Access();
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::operator =(integer_tr auto value)
    {
        return Assign(value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::operator +(integer_tr auto value) const
    {
        return Access_Add(value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::operator -(integer_tr auto value) const
    {
        return Access_Subtract(value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::operator +=(integer_tr auto value)
    {
        return Assign_Add(value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::operator -=(integer_tr auto value)
    {
        return Assign_Subtract(value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::operator ++()
    {
        return Assign_Add(1);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::operator ++(int)
    {
        return Exchange_Add(1);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::operator --()
    {
        return Assign_Subtract(1);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::operator --(int)
    {
        return Exchange_Subtract(1);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::operator ~() const
    {
        return ~Access();
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::operator |(integer_tr auto value) const
    {
        return Access_Or(value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::operator &(integer_tr auto value) const
    {
        return Access_And(value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::operator ^(integer_tr auto value) const
    {
        return Access_Xor(value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::operator |=(integer_tr auto value)
    {
        return Assign_Or(value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::operator &=(integer_tr auto value)
    {
        return Assign_And(value);
    }

    template <typename integer_p>
    inline typename atomic_t<integer_p>::value_t atomic_t<integer_p>::operator ^=(integer_tr auto value)
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

    inline typename atomic_t<bool_t>::value_t atomic_t<bool_t>::Exchange(value_t value)
    {
        return os::atomic::Exchange(this->value, value);
    }

    inline typename atomic_t<bool_t>::value_t atomic_t<bool_t>::Exchange_If_Equals(value_t value, value_t target)
    {
        return os::atomic::Exchange_If_Equals(this->value, value, target);
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
        value(other.Exchange(nullptr))
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
            this->value = other.Exchange(nullptr);
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
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Access_Add(integer_tr auto value) const
    {
        return os::atomic::Access_Add(this->value, value);
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Access_Subtract(integer_tr auto value) const
    {
        return os::atomic::Access_Subtract(this->value, value);
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Assign(pointer_tr auto value)
    {
        return os::atomic::Assign(this->value, value);
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Assign_Add(integer_tr auto value)
    {
        return os::atomic::Assign_Add(this->value, value);
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Assign_Subtract(integer_tr auto value)
    {
        return os::atomic::Assign_Subtract(this->value, value);
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Exchange(pointer_tr auto value)
    {
        return os::atomic::Exchange(this->value, value);
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Exchange_If_Equals(pointer_tr auto value,
                                                                                        pointer_tr auto target)
    {
        return os::atomic::Exchange_If_Equals(this->value, value, target);
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Exchange_Add(integer_tr auto value)
    {
        return os::atomic::Exchange_Add(this->value, value);
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Exchange_Subtract(integer_tr auto value)
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
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator =(pointer_tr auto value)
    {
        return Assign(value);
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator +(integer_tr auto value) const
    {
        return Access_Add(value);
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator -(integer_tr auto value) const
    {
        return Access_Subtract(value);
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator +=(integer_tr auto value)
    {
        return Assign_Add(value);
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator -=(integer_tr auto value)
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
    inline typename atomic_t<value_p*>::value_t& atomic_t<value_p*>::operator [](integer_tr auto index) const
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
        value(other.Exchange(nullptr))
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
            this->value = other.Exchange(nullptr);
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

    inline typename atomic_t<void_t*>::value_t* atomic_t<void_t*>::Assign(pointer_tr auto value)
    {
        return os::atomic::Assign(this->value, value);
    }

    inline typename atomic_t<void_t*>::value_t* atomic_t<void_t*>::Exchange(pointer_tr auto value)
    {
        return os::atomic::Exchange(this->value, value);
    }

    inline typename atomic_t<void_t*>::value_t* atomic_t<void_t*>::Exchange_If_Equals(pointer_tr auto value,
                                                                                      pointer_tr auto target)
    {
        return os::atomic::Exchange_If_Equals(this->value, value, target);
    }

    inline atomic_t<void_t*>::operator value_t*() const
    {
        return Access();
    }

    inline typename atomic_t<void_t*>::value_t* atomic_t<void_t*>::operator ()() const
    {
        return Access();
    }

    inline typename atomic_t<void_t*>::value_t* atomic_t<void_t*>::operator =(pointer_tr auto value)
    {
        return Assign(value);
    }

}
