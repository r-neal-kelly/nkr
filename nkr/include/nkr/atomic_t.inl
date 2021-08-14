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
        this->value = 0;
    }

    template <typename value_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Access() const
    {
        return os::atomic::Access(this->value);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Assign(integral_p with)
    {
        return os::atomic::Assign(this->value, with);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Exchange_Assign(integral_p with)
    {
        return os::atomic::Exchange_Assign(this->value, with);
    }

    template <typename value_p>
    template <integral_tr integral_a_p, integral_tr integral_b_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Exchange_Assign_If_Equals(integral_a_p with, integral_b_p target)
    {
        return os::atomic::Exchange_Assign_If_Equals(this->value, with, target);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Add(integral_p with)
    {
        return os::atomic::Add(this->value, with);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Exchange_Add(integral_p with)
    {
        return os::atomic::Exchange_Add(this->value, with);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Subtract(integral_p with)
    {
        return os::atomic::Subtract(this->value, with);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Exchange_Subtract(integral_p with)
    {
        return os::atomic::Exchange_Subtract(this->value, with);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Or(integral_p with)
    {
        return os::atomic::Or(this->value, with);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Exchange_Or(integral_p with)
    {
        return os::atomic::Exchange_Or(this->value, with);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::And(integral_p with)
    {
        return os::atomic::And(this->value, with);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Exchange_And(integral_p with)
    {
        return os::atomic::Exchange_And(this->value, with);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Xor(integral_p with)
    {
        return os::atomic::Xor(this->value, with);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::Exchange_Xor(integral_p with)
    {
        return os::atomic::Exchange_Xor(this->value, with);
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
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator =(integral_p other)
    {
        return Assign(other);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator +(integral_p other) const
    {
        return Access() + other;
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator -(integral_p other) const
    {
        return Access() - other;
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator +=(integral_p other)
    {
        return Add(other);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator -=(integral_p other)
    {
        return Subtract(other);
    }

    template <typename value_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator ++()
    {
        return Add(1);
    }

    template <typename value_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator ++(int)
    {
        return Exchange_Add(1);
    }

    template <typename value_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator --()
    {
        return Subtract(1);
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
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator |(integral_p other) const
    {
        return Access() | other;
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator &(integral_p other) const
    {
        return Access() & other;
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator ^(integral_p other) const
    {
        return Access() ^ other;
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator |=(integral_p other)
    {
        return Or(other);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator &=(integral_p other)
    {
        return And(other);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p>::value_t atomic_t<value_p>::operator ^=(integral_p other)
    {
        return Xor(other);
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
        this->value = false;
    }

    inline typename atomic_t<bool_t>::value_t atomic_t<bool_t>::Access() const
    {
        return os::atomic::Access(this->value);
    }

    inline typename atomic_t<bool_t>::value_t atomic_t<bool_t>::Assign(value_t with)
    {
        return os::atomic::Assign(this->value, with);
    }

    inline typename atomic_t<bool_t>::value_t atomic_t<bool_t>::Exchange_Assign(value_t with)
    {
        return os::atomic::Exchange_Assign(this->value, with);
    }

    inline typename atomic_t<bool_t>::value_t atomic_t<bool_t>::Exchange_Assign_If_Equals(value_t with, value_t target)
    {
        return os::atomic::Exchange_Assign_If_Equals(this->value, with, target);
    }

    inline atomic_t<bool_t>::operator value_t() const
    {
        return Access();
    }

    inline typename atomic_t<bool_t>::value_t atomic_t<bool_t>::operator ()() const
    {
        return Access();
    }

    inline typename atomic_t<bool_t>::value_t atomic_t<bool_t>::operator =(value_t other)
    {
        return Assign(other);
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
        this->value = nullptr;
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Access() const
    {
        return os::atomic::Access(this->value);
    }

    template <typename value_p>
    template <pointer_tr pointer_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Assign(pointer_p with)
    {
        return os::atomic::Assign(this->value, with);
    }

    template <typename value_p>
    template <pointer_tr pointer_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Exchange_Assign(pointer_p with)
    {
        return os::atomic::Exchange_Assign(this->value, with);
    }

    template <typename value_p>
    template <pointer_tr pointer_a_p, pointer_tr pointer_b_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Exchange_Assign_If_Equals(pointer_a_p with, pointer_b_p target)
    {
        return os::atomic::Exchange_Assign_If_Equals(this->value, with, target);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Add(integral_p with)
    {
        return os::atomic::Add(this->value, with);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Exchange_Add(integral_p with)
    {
        return os::atomic::Exchange_Add(this->value, with);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Subtract(integral_p with)
    {
        return os::atomic::Subtract(this->value, with);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::Exchange_Subtract(integral_p with)
    {
        return os::atomic::Exchange_Subtract(this->value, with);
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
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator =(pointer_p other)
    {
        return Assign(other);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator +(integral_p other) const
    {
        return Access() + other;
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator -(integral_p other) const
    {
        return Access() - other;
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator +=(integral_p other)
    {
        return Add(other);
    }

    template <typename value_p>
    template <integral_tr integral_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator -=(integral_p other)
    {
        return Subtract(other);
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator ++()
    {
        return Add(1);
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator ++(int)
    {
        return Exchange_Add(1);
    }

    template <typename value_p>
    inline typename atomic_t<value_p*>::value_t* atomic_t<value_p*>::operator --()
    {
        return Subtract(1);
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
        this->value = nullptr;
    }

    inline typename atomic_t<void_t*>::value_t* atomic_t<void_t*>::Access() const
    {
        return os::atomic::Access(this->value);
    }

    template <pointer_tr pointer_p>
    inline typename atomic_t<void_t*>::value_t* atomic_t<void_t*>::Assign(pointer_p with)
    {
        return os::atomic::Assign(this->value, with);
    }

    template <pointer_tr pointer_p>
    inline typename atomic_t<void_t*>::value_t* atomic_t<void_t*>::Exchange_Assign(pointer_p with)
    {
        return os::atomic::Exchange_Assign(this->value, with);
    }

    template <pointer_tr pointer_a_p, pointer_tr pointer_b_p>
    inline typename atomic_t<void_t*>::value_t* atomic_t<void_t*>::Exchange_Assign_If_Equals(pointer_a_p with, pointer_b_p target)
    {
        return os::atomic::Exchange_Assign_If_Equals(this->value, with, target);
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
    inline typename atomic_t<void_t*>::value_t* atomic_t<void_t*>::operator =(pointer_p other)
    {
        return Assign(other);
    }

}
