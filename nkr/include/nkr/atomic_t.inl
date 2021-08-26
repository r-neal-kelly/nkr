/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/atomic_t.h"
#include "nkr/os.h"

namespace nkr { namespace $atomic_t {

    inline typename const bool_sp::value_t  bool_sp::DEFAULT_VALUE  = value_t();

    inline bool_sp::bool_sp() :
        value(DEFAULT_VALUE)
    {
    }

    inline bool_sp::bool_sp(value_t value) :
        value(value)
    {
    }

    inline bool_sp::bool_sp(const bool_sp& other) :
        value(other.Access())
    {
    }

    inline bool_sp::bool_sp(bool_sp&& other) noexcept :
        value(other.Exchange(DEFAULT_VALUE))
    {
    }

    inline bool_sp& bool_sp::operator =(const bool_sp& other)
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    inline bool_sp& bool_sp::operator =(bool_sp&& other) noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    inline bool_sp::~bool_sp()
    {
        Assign(DEFAULT_VALUE);
    }

    inline typename bool_sp::value_t bool_sp::Access() const
    {
        return os::atomic::Access(this->value);
    }

    inline typename bool_sp::value_t bool_sp::Assign(value_t value)
    {
        return os::atomic::Assign(this->value, value);
    }

    inline typename bool_sp::value_t bool_sp::Exchange(value_t value)
    {
        return os::atomic::Exchange(this->value, value);
    }

    inline typename bool_sp::value_t bool_sp::Exchange_If_Equals(value_t value, value_t target)
    {
        return os::atomic::Exchange_If_Equals(this->value, value, target);
    }

    inline bool_sp::operator value_t() const
    {
        return Access();
    }

    inline typename bool_sp::value_t bool_sp::operator ()() const
    {
        return Access();
    }

    inline typename bool_sp::value_t bool_sp::operator =(value_t value)
    {
        return Assign(value);
    }

    inline bool_sp& bool_sp::operator =(none_t)
    {
        Assign(DEFAULT_VALUE);
        return *this;
    }

    inline bool_t bool_sp::operator ==(none_t) const
    {
        return static_cast<bool_t>(Access()) == false;
    }

    inline bool_t bool_sp::operator !=(none_t) const
    {
        return !operator ==(none_t());
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>::integer_sp() :
        value(DEFAULT_VALUE)
    {
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>::integer_sp(value_t value) :
        value(value)
    {
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>::integer_sp(const integer_sp& other) :
        value(other.Access())
    {
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>::integer_sp(integer_sp&& other) noexcept :
        value(other.Exchange(DEFAULT_VALUE))
    {
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::operator =(const integer_sp& other)
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::operator =(integer_sp&& other) noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>::~integer_sp()
    {
        Assign(DEFAULT_VALUE);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Access() const
    {
        return os::atomic::Access(this->value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Access_Add(integer_tr auto value) const
    {
        return os::atomic::Access_Add(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Access_Subtract(integer_tr auto value) const
    {
        return os::atomic::Access_Subtract(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Access_Or(integer_tr auto value) const
    {
        return os::atomic::Access_Or(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Access_And(integer_tr auto value) const
    {
        return os::atomic::Access_And(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Access_Xor(integer_tr auto value) const
    {
        return os::atomic::Access_Xor(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Assign(integer_tr auto value)
    {
        return os::atomic::Assign(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Assign_Add(integer_tr auto value)
    {
        return os::atomic::Assign_Add(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Assign_Subtract(integer_tr auto value)
    {
        return os::atomic::Assign_Subtract(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Assign_Or(integer_tr auto value)
    {
        return os::atomic::Assign_Or(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Assign_And(integer_tr auto value)
    {
        return os::atomic::Assign_And(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Assign_Xor(integer_tr auto value)
    {
        return os::atomic::Assign_Xor(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Exchange(integer_tr auto value)
    {
        return os::atomic::Exchange(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Exchange_If_Equals(integer_tr auto value, integer_tr auto target)
    {
        return os::atomic::Exchange_If_Equals(this->value, value, target);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Exchange_Add(integer_tr auto value)
    {
        return os::atomic::Exchange_Add(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Exchange_Subtract(integer_tr auto value)
    {
        return os::atomic::Exchange_Subtract(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Exchange_Or(integer_tr auto value)
    {
        return os::atomic::Exchange_Or(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Exchange_And(integer_tr auto value)
    {
        return os::atomic::Exchange_And(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Exchange_Xor(integer_tr auto value)
    {
        return os::atomic::Exchange_Xor(this->value, value);
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>::operator value_t() const
    {
        return Access();
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::operator ()() const
    {
        return Access();
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::operator =(integer_tr auto value)
    {
        return Assign(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::operator +(integer_tr auto value) const
    {
        return Access_Add(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::operator -(integer_tr auto value) const
    {
        return Access_Subtract(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::operator +=(integer_tr auto value)
    {
        return Assign_Add(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::operator -=(integer_tr auto value)
    {
        return Assign_Subtract(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::operator ++()
    {
        return Assign_Add(1);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::operator ++(int)
    {
        return Exchange_Add(1);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::operator --()
    {
        return Assign_Subtract(1);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::operator --(int)
    {
        return Exchange_Subtract(1);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::operator ~() const
    {
        return ~Access();
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::operator |(integer_tr auto value) const
    {
        return Access_Or(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::operator &(integer_tr auto value) const
    {
        return Access_And(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::operator ^(integer_tr auto value) const
    {
        return Access_Xor(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::operator |=(integer_tr auto value)
    {
        return Assign_Or(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::operator &=(integer_tr auto value)
    {
        return Assign_And(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::operator ^=(integer_tr auto value)
    {
        return Assign_Xor(value);
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::operator =(none_t)
    {
        Assign(DEFAULT_VALUE);
        return *this;
    }

    template <integer_tr integer_p>
    inline bool_t integer_sp<integer_p>::operator ==(none_t) const
    {
        return static_cast<bool_t>(Access()) == false;
    }

    template <integer_tr integer_p>
    inline bool_t integer_sp<integer_p>::operator !=(none_t) const
    {
        return !operator ==(none_t());
    }

    template <pointer_tr pointer_p>
    inline pointer_sp<pointer_p>::pointer_sp() :
        value(DEFAULT_VALUE)
    {
    }

    template <pointer_tr pointer_p>
    inline pointer_sp<pointer_p>::pointer_sp(value_t value) :
        value(value)
    {
    }

    template <pointer_tr pointer_p>
    inline pointer_sp<pointer_p>::pointer_sp(const pointer_sp& other) :
        value(other.Access())
    {
    }

    template <pointer_tr pointer_p>
    inline pointer_sp<pointer_p>::pointer_sp(pointer_sp&& other) noexcept :
        value(other.Exchange(DEFAULT_VALUE))
    {
    }

    template <pointer_tr pointer_p>
    inline pointer_sp<pointer_p>& pointer_sp<pointer_p>::operator =(const pointer_sp& other)
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    template <pointer_tr pointer_p>
    inline pointer_sp<pointer_p>& pointer_sp<pointer_p>::operator =(pointer_sp&& other) noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    template <pointer_tr pointer_p>
    inline pointer_sp<pointer_p>::~pointer_sp()
    {
        Assign(DEFAULT_VALUE);
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::Access() const
    {
        return os::atomic::Access(this->value);
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::Access_Add(integer_tr auto value) const
    {
        return os::atomic::Access_Add(this->value, value);
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::Access_Subtract(integer_tr auto value) const
    {
        return os::atomic::Access_Subtract(this->value, value);
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::Assign(pointer_tr auto value)
    {
        return os::atomic::Assign(this->value, value);
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::Assign_Add(integer_tr auto value)
    {
        return os::atomic::Assign_Add(this->value, value);
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::Assign_Subtract(integer_tr auto value)
    {
        return os::atomic::Assign_Subtract(this->value, value);
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::Exchange(pointer_tr auto value)
    {
        return os::atomic::Exchange(this->value, value);
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::Exchange_If_Equals(pointer_tr auto value, pointer_tr auto target)
    {
        return os::atomic::Exchange_If_Equals(this->value, value, target);
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::Exchange_Add(integer_tr auto value)
    {
        return os::atomic::Exchange_Add(this->value, value);
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::Exchange_Subtract(integer_tr auto value)
    {
        return os::atomic::Exchange_Subtract(this->value, value);
    }

    template <pointer_tr pointer_p>
    inline pointer_sp<pointer_p>::operator value_t() const
    {
        return Access();
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::operator ()() const
    {
        return Access();
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::operator =(pointer_tr auto value)
    {
        return Assign(value);
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::operator +(integer_tr auto value) const
    {
        return Access_Add(value);
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::operator -(integer_tr auto value) const
    {
        return Access_Subtract(value);
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::operator +=(integer_tr auto value)
    {
        return Assign_Add(value);
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::operator -=(integer_tr auto value)
    {
        return Assign_Subtract(value);
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::operator ++()
    {
        return Assign_Add(1);
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::operator ++(int)
    {
        return Exchange_Add(1);
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::operator --()
    {
        return Assign_Subtract(1);
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::operator --(int)
    {
        return Exchange_Subtract(1);
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::operator ->() const
    {
        return Access();
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::unit_t& pointer_sp<pointer_p>::operator *() const
    {
        return *Access();
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::unit_t& pointer_sp<pointer_p>::operator [](integer_tr auto index) const
    {
        return Access()[index];
    }

    template <pointer_tr pointer_p>
    inline pointer_sp<pointer_p>& pointer_sp<pointer_p>::operator =(none_t)
    {
        Assign(DEFAULT_VALUE);
        return *this;
    }

    template <pointer_tr pointer_p>
    inline bool_t pointer_sp<pointer_p>::operator ==(none_t) const
    {
        return static_cast<bool_t>(Access()) == false;
    }

    template <pointer_tr pointer_p>
    inline bool_t pointer_sp<pointer_p>::operator !=(none_t) const
    {
        return !operator ==(none_t());
    }

    inline void_pointer_sp::void_pointer_sp() :
        value(DEFAULT_VALUE)
    {
    }

    inline void_pointer_sp::void_pointer_sp(value_t value) :
        value(value)
    {
    }

    inline void_pointer_sp::void_pointer_sp(const void_pointer_sp& other) :
        value(other.Access())
    {
    }

    inline void_pointer_sp::void_pointer_sp(void_pointer_sp&& other) noexcept :
        value(other.Exchange(DEFAULT_VALUE))
    {
    }

    inline void_pointer_sp& void_pointer_sp::operator =(const void_pointer_sp& other)
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    inline void_pointer_sp& void_pointer_sp::operator =(void_pointer_sp&& other) noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    inline void_pointer_sp::~void_pointer_sp()
    {
        Assign(DEFAULT_VALUE);
    }

    inline typename void_pointer_sp::value_t void_pointer_sp::Access() const
    {
        return os::atomic::Access(this->value);
    }

    inline typename void_pointer_sp::value_t void_pointer_sp::Assign(pointer_tr auto value)
    {
        return os::atomic::Assign(this->value, value);
    }

    inline typename void_pointer_sp::value_t void_pointer_sp::Exchange(pointer_tr auto value)
    {
        return os::atomic::Exchange(this->value, value);
    }

    inline typename void_pointer_sp::value_t void_pointer_sp::Exchange_If_Equals(pointer_tr auto value,
                                                                                     pointer_tr auto target)
    {
        return os::atomic::Exchange_If_Equals(this->value, value, target);
    }

    inline void_pointer_sp::operator value_t() const
    {
        return Access();
    }

    inline typename void_pointer_sp::value_t void_pointer_sp::operator ()() const
    {
        return Access();
    }

    inline typename void_pointer_sp::value_t void_pointer_sp::operator =(pointer_tr auto value)
    {
        return Assign(value);
    }

    inline void_pointer_sp& void_pointer_sp::operator =(none_t)
    {
        Assign(DEFAULT_VALUE);
        return *this;
    }

    inline bool_t void_pointer_sp::operator ==(none_t) const
    {
        return static_cast<bool_t>(Access()) == false;
    }

    inline bool_t void_pointer_sp::operator !=(none_t) const
    {
        return !operator ==(none_t());
    }

}}
