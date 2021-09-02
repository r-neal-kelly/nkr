/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/atomic_t.h"
#include "nkr/os.h"

namespace nkr { namespace $atomic_t {

    template <boolean_tr boolean_p>
    inline typename const boolean_sp<boolean_p>::value_t    boolean_sp<boolean_p>::DEFAULT_VALUE    = value_t();

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>::boolean_sp() :
        value(DEFAULT_VALUE)
    {
    }

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>::boolean_sp(convertible_tr<value_t> auto value) :
        value(static_cast<value_t>(value))
    {
    }

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>::boolean_sp(const boolean_sp& other) :
        value(other.Access())
    {
    }

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>::boolean_sp(boolean_sp&& other) noexcept :
        value(other.Exchange(DEFAULT_VALUE))
    {
    }

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>& boolean_sp<boolean_p>::operator =(convertible_tr<value_t> auto value)
    {
        return Assign(value);
    }

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>& boolean_sp<boolean_p>::operator =(const boolean_sp& other)
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>& boolean_sp<boolean_p>::operator =(boolean_sp&& other) noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>::~boolean_sp()
    {
        Assign(DEFAULT_VALUE);
    }

    template <boolean_tr boolean_p>
    inline typename boolean_sp<boolean_p>::value_t boolean_sp<boolean_p>::Access() const
    {
        return os::atomic::Access(this->value);
    }

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>& boolean_sp<boolean_p>::Assign(convertible_tr<value_t> auto value)
    {
        os::atomic::Assign(this->value, value);
        return *this;
    }

    template <boolean_tr boolean_p>
    inline typename boolean_sp<boolean_p>::value_t boolean_sp<boolean_p>::Exchange(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange(this->value, value);
    }

    template <boolean_tr boolean_p>
    inline bool_t boolean_sp<boolean_p>::Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_If_Equals(this->value, snapshot, value);
    }

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>::operator std_bool_t() const
    {
        return Access();
    }

    template <boolean_tr boolean_p>
    inline typename boolean_sp<boolean_p>::value_t boolean_sp<boolean_p>::operator ()() const
    {
        return Access();
    }

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>::boolean_sp(none_t) :
        value(DEFAULT_VALUE)
    {
    }

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>& boolean_sp<boolean_p>::operator =(none_t)
    {
        return Assign(DEFAULT_VALUE);
    }

    template <boolean_tr boolean_p>
    inline bool_t boolean_sp<boolean_p>::operator ==(none_t) const
    {
        return static_cast<bool_t>(Access()) == false;
    }

    template <boolean_tr boolean_p>
    inline bool_t boolean_sp<boolean_p>::operator !=(none_t) const
    {
        return !operator ==(none_t());
    }

    template <integer_tr integer_p>
    inline typename const integer_sp<integer_p>::value_t    integer_sp<integer_p>::DEFAULT_VALUE    = value_t();

    template <integer_tr integer_p>
    inline integer_sp<integer_p>::integer_sp() :
        value(DEFAULT_VALUE)
    {
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>::integer_sp(convertible_tr<value_t> auto value) :
        value(static_cast<value_t>(value))
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
    inline integer_sp<integer_p>& integer_sp<integer_p>::operator =(convertible_tr<value_t> auto value)
    {
        return Assign(value);
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
    inline integer_sp<integer_p>& integer_sp<integer_p>::Assign(convertible_tr<value_t> auto value)
    {
        os::atomic::Assign(this->value, value);
        return *this;
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::Assign_Add(convertible_tr<value_t> auto value)
    {
        os::atomic::Assign_Add(this->value, value);
        return *this;
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::Assign_Subtract(convertible_tr<value_t> auto value)
    {
        os::atomic::Assign_Subtract(this->value, value);
        return *this;
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::Assign_Multiply(convertible_tr<value_t> auto value)
    {
        os::atomic::Assign_Multiply(this->value, value);
        return *this;
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::Assign_Divide(convertible_tr<value_t> auto value)
    {
        os::atomic::Assign_Divide(this->value, value);
        return *this;
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::Assign_Modulus(integer_tr auto value)
    {
        os::atomic::Assign_Modulus(this->value, value);
        return *this;
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::Assign_Or(integer_tr auto value)
    {
        os::atomic::Assign_Or(this->value, value);
        return *this;
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::Assign_And(integer_tr auto value)
    {
        os::atomic::Assign_And(this->value, value);
        return *this;
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::Assign_Xor(integer_tr auto value)
    {
        os::atomic::Assign_Xor(this->value, value);
        return *this;
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::Assign_Left_Shift(integer_tr auto value)
    {
        os::atomic::Assign_Left_Shift(this->value, value);
        return *this;
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::Assign_Right_Shift(integer_tr auto value)
    {
        os::atomic::Assign_Right_Shift(this->value, value);
        return *this;
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Exchange(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Exchange_Add(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_Add(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Exchange_Subtract(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_Subtract(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Exchange_Multiply(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_Multiply(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Exchange_Divide(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_Divide(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Exchange_Modulus(integer_tr auto value)
    {
        return os::atomic::Exchange_Modulus(this->value, value);
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
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Exchange_Left_Shift(integer_tr auto value)
    {
        return os::atomic::Exchange_Left_Shift(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::Exchange_Right_Shift(integer_tr auto value)
    {
        return os::atomic::Exchange_Right_Shift(this->value, value);
    }

    template <integer_tr integer_p>
    inline bool_t integer_sp<integer_p>::Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_If_Equals(this->value, snapshot, value);
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
    inline integer_sp<integer_p>& integer_sp<integer_p>::operator +=(convertible_tr<value_t> auto value)
    {
        return Assign_Add(value);
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::operator -=(convertible_tr<value_t> auto value)
    {
        return Assign_Subtract(value);
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::operator *=(convertible_tr<value_t> auto value)
    {
        return Assign_Multiply(value);
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::operator /=(convertible_tr<value_t> auto value)
    {
        return Assign_Divide(value);
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::operator %=(integer_tr auto value)
    {
        return Assign_Modulus(value);
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::operator |=(integer_tr auto value)
    {
        return Assign_Or(value);
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::operator &=(integer_tr auto value)
    {
        return Assign_And(value);
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::operator ^=(integer_tr auto value)
    {
        return Assign_Xor(value);
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::operator <<=(integer_tr auto value)
    {
        return Assign_Left_Shift(value);
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::operator >>=(integer_tr auto value)
    {
        return Assign_Right_Shift(value);
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::operator ++()
    {
        return Assign_Add(1);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::operator ++(int)
    {
        return Exchange_Add(1);
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::operator --()
    {
        return Assign_Subtract(1);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t integer_sp<integer_p>::operator --(int)
    {
        return Exchange_Subtract(1);
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>::integer_sp(none_t) :
        value(DEFAULT_VALUE)
    {
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>& integer_sp<integer_p>::operator =(none_t)
    {
        return Assign(DEFAULT_VALUE);
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

    template <real_tr real_p>
    inline typename const real_sp<real_p>::value_t  real_sp<real_p>::DEFAULT_VALUE  = value_t();

    template <real_tr real_p>
    inline real_sp<real_p>::real_sp() :
        value(DEFAULT_VALUE)
    {
    }

    template <real_tr real_p>
    inline real_sp<real_p>::real_sp(convertible_tr<value_t> auto value) :
        value(static_cast<value_t>(value))
    {
    }

    template <real_tr real_p>
    inline real_sp<real_p>::real_sp(const real_sp& other) :
        value(other.Access())
    {
    }

    template <real_tr real_p>
    inline real_sp<real_p>::real_sp(real_sp&& other) noexcept :
        value(other.Exchange(DEFAULT_VALUE))
    {
    }

    template <real_tr real_p>
    inline real_sp<real_p>& real_sp<real_p>::operator =(convertible_tr<value_t> auto value)
    {
        return Assign(value);
    }

    template <real_tr real_p>
    inline real_sp<real_p>& real_sp<real_p>::operator =(const real_sp& other)
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    template <real_tr real_p>
    inline real_sp<real_p>& real_sp<real_p>::operator =(real_sp&& other) noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    template <real_tr real_p>
    inline real_sp<real_p>::~real_sp()
    {
        Assign(DEFAULT_VALUE);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t real_sp<real_p>::Access() const
    {
        return os::atomic::Access(this->value);
    }

    template <real_tr real_p>
    inline real_sp<real_p>& real_sp<real_p>::Assign(convertible_tr<value_t> auto value)
    {
        os::atomic::Assign(this->value, value);
        return *this;
    }

    template <real_tr real_p>
    inline real_sp<real_p>& real_sp<real_p>::Assign_Add(convertible_tr<value_t> auto value)
    {
        os::atomic::Assign_Add(this->value, value);
        return *this;
    }

    template <real_tr real_p>
    inline real_sp<real_p>& real_sp<real_p>::Assign_Subtract(convertible_tr<value_t> auto value)
    {
        os::atomic::Assign_Subtract(this->value, value);
        return *this;
    }

    template <real_tr real_p>
    inline real_sp<real_p>& real_sp<real_p>::Assign_Multiply(convertible_tr<value_t> auto value)
    {
        os::atomic::Assign_Multiply(this->value, value);
        return *this;
    }

    template <real_tr real_p>
    inline real_sp<real_p>& real_sp<real_p>::Assign_Divide(convertible_tr<value_t> auto value)
    {
        os::atomic::Assign_Divide(this->value, value);
        return *this;
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t real_sp<real_p>::Exchange(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t real_sp<real_p>::Exchange_Add(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_Add(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t real_sp<real_p>::Exchange_Subtract(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_Subtract(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t real_sp<real_p>::Exchange_Multiply(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_Multiply(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t real_sp<real_p>::Exchange_Divide(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_Divide(this->value, value);
    }

    template <real_tr real_p>
    inline bool_t real_sp<real_p>::Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_If_Equals(this->value, snapshot, value);
    }

    template <real_tr real_p>
    inline real_sp<real_p>::operator value_t() const
    {
        return Access();
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t real_sp<real_p>::operator ()() const
    {
        return Access();
    }

    template <real_tr real_p>
    inline real_sp<real_p>& real_sp<real_p>::operator +=(convertible_tr<value_t> auto value)
    {
        return Assign_Add(value);
    }

    template <real_tr real_p>
    inline real_sp<real_p>& real_sp<real_p>::operator -=(convertible_tr<value_t> auto value)
    {
        return Assign_Subtract(value);
    }

    template <real_tr real_p>
    inline real_sp<real_p>& real_sp<real_p>::operator *=(convertible_tr<value_t> auto value)
    {
        return Assign_Multiply(value);
    }

    template <real_tr real_p>
    inline real_sp<real_p>& real_sp<real_p>::operator /=(convertible_tr<value_t> auto value)
    {
        return Assign_Divide(value);
    }

    template <real_tr real_p>
    inline real_sp<real_p>& real_sp<real_p>::operator ++()
    {
        return Assign_Add(1);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t real_sp<real_p>::operator ++(int)
    {
        return Exchange_Add(1);
    }

    template <real_tr real_p>
    inline real_sp<real_p>& real_sp<real_p>::operator --()
    {
        return Assign_Subtract(1);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t real_sp<real_p>::operator --(int)
    {
        return Exchange_Subtract(1);
    }

    template <real_tr real_p>
    inline real_sp<real_p>::real_sp(none_t) :
        value(DEFAULT_VALUE)
    {
    }

    template <real_tr real_p>
    inline real_sp<real_p>& real_sp<real_p>::operator =(none_t)
    {
        return Assign(DEFAULT_VALUE);
    }

    template <real_tr real_p>
    inline bool_t real_sp<real_p>::operator ==(none_t) const
    {
        return Access() == DEFAULT_VALUE;
    }

    template <real_tr real_p>
    inline bool_t real_sp<real_p>::operator !=(none_t) const
    {
        return !operator ==(none_t());
    }

    template <pointer_tr pointer_p>
    inline typename const pointer_sp<pointer_p>::value_t    pointer_sp<pointer_p>::DEFAULT_VALUE    = value_t();

    template <pointer_tr pointer_p>
    inline pointer_sp<pointer_p>::pointer_sp() :
        value(DEFAULT_VALUE)
    {
    }

    template <pointer_tr pointer_p>
    inline pointer_sp<pointer_p>::pointer_sp(convertible_tr<value_t> auto value) :
        value(static_cast<value_t>(value))
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
    inline pointer_sp<pointer_p>& pointer_sp<pointer_p>::operator =(convertible_tr<value_t> auto value)
    {
        return Assign(value);
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
    inline pointer_sp<pointer_p>& pointer_sp<pointer_p>::Assign(convertible_tr<value_t> auto value)
    {
        os::atomic::Assign(this->value, value);
        return *this;
    }

    template <pointer_tr pointer_p>
    inline pointer_sp<pointer_p>& pointer_sp<pointer_p>::Assign_Add(integer_tr auto value)
    {
        os::atomic::Assign_Add(this->value, value);
        return *this;
    }

    template <pointer_tr pointer_p>
    inline pointer_sp<pointer_p>& pointer_sp<pointer_p>::Assign_Subtract(integer_tr auto value)
    {
        os::atomic::Assign_Subtract(this->value, value);
        return *this;
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::Exchange(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange(this->value, value);
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
    inline bool_t pointer_sp<pointer_p>::Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_If_Equals(this->value, snapshot, value);
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
    inline pointer_sp<pointer_p>& pointer_sp<pointer_p>::operator +=(integer_tr auto value)
    {
        return Assign_Add(value);
    }

    template <pointer_tr pointer_p>
    inline pointer_sp<pointer_p>& pointer_sp<pointer_p>::operator -=(integer_tr auto value)
    {
        return Assign_Subtract(value);
    }

    template <pointer_tr pointer_p>
    inline pointer_sp<pointer_p>& pointer_sp<pointer_p>::operator ++()
    {
        return Assign_Add(1);
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::value_t pointer_sp<pointer_p>::operator ++(int)
    {
        return Exchange_Add(1);
    }

    template <pointer_tr pointer_p>
    inline pointer_sp<pointer_p>& pointer_sp<pointer_p>::operator --()
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
        return Access()[static_cast<index_t>(index)];
    }

    template <pointer_tr pointer_p>
    inline pointer_sp<pointer_p>::pointer_sp(none_t) :
        value(DEFAULT_VALUE)
    {
    }

    template <pointer_tr pointer_p>
    inline pointer_sp<pointer_p>& pointer_sp<pointer_p>::operator =(none_t)
    {
        return Assign(DEFAULT_VALUE);
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

    inline typename const void_pointer_sp::value_t  void_pointer_sp::DEFAULT_VALUE  = value_t();

    inline void_pointer_sp::void_pointer_sp() :
        value(DEFAULT_VALUE)
    {
    }

    inline void_pointer_sp::void_pointer_sp(convertible_tr<value_t> auto value) :
        value(static_cast<value_t>(value))
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

    inline void_pointer_sp& void_pointer_sp::operator =(convertible_tr<value_t> auto value)
    {
        return Assign(value);
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

    inline void_pointer_sp& void_pointer_sp::Assign(convertible_tr<value_t> auto value)
    {
        os::atomic::Assign(this->value, value);
        return *this;
    }

    inline typename void_pointer_sp::value_t void_pointer_sp::Exchange(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange(this->value, value);
    }

    inline bool_t void_pointer_sp::Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_If_Equals(this->value, snapshot, value);
    }

    inline void_pointer_sp::operator value_t() const
    {
        return Access();
    }

    inline typename void_pointer_sp::value_t void_pointer_sp::operator ()() const
    {
        return Access();
    }

    inline void_pointer_sp::void_pointer_sp(none_t) :
        value(DEFAULT_VALUE)
    {
    }

    inline void_pointer_sp& void_pointer_sp::operator =(none_t)
    {
        return Assign(DEFAULT_VALUE);
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
