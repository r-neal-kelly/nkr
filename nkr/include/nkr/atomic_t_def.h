/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/atomic_t_dec.h"
#include "nkr/os.h"
#include "nkr/utils.h"

namespace nkr { namespace $atomic_t {

    template <boolean_tr boolean_p>
    inline typename const boolean_sp<boolean_p>::value_t
        boolean_sp<boolean_p>::DEFAULT_VALUE    = value_t();

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
    inline boolean_sp<boolean_p>::boolean_sp(const volatile boolean_sp& other) :
        value(other.Access())
    {
    }

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>::boolean_sp(boolean_sp&& other) noexcept :
        value(other.Exchange(DEFAULT_VALUE))
    {
    }

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>::boolean_sp(volatile boolean_sp&& other) noexcept :
        value(other.Exchange(DEFAULT_VALUE))
    {
    }

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>&
        boolean_sp<boolean_p>::operator =(const boolean_sp& other)
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    template <boolean_tr boolean_p>
    inline volatile boolean_sp<boolean_p>&
        boolean_sp<boolean_p>::operator =(const boolean_sp& other)
        volatile
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>&
        boolean_sp<boolean_p>::operator =(const volatile boolean_sp& other)
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    template <boolean_tr boolean_p>
    inline volatile boolean_sp<boolean_p>&
        boolean_sp<boolean_p>::operator =(const volatile boolean_sp& other)
        volatile
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>&
        boolean_sp<boolean_p>::operator =(boolean_sp&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    template <boolean_tr boolean_p>
    inline volatile boolean_sp<boolean_p>&
        boolean_sp<boolean_p>::operator =(boolean_sp&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>&
        boolean_sp<boolean_p>::operator =(is_just_volatile_tr<boolean_sp> auto&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    template <boolean_tr boolean_p>
    inline volatile boolean_sp<boolean_p>&
        boolean_sp<boolean_p>::operator =(is_just_volatile_tr<boolean_sp> auto&& other)
        volatile noexcept
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
    inline typename boolean_sp<boolean_p>::value_t
        boolean_sp<boolean_p>::Access()
        const
    {
        return os::atomic::Access(this->value);
    }

    template <boolean_tr boolean_p>
    inline typename boolean_sp<boolean_p>::value_t
        boolean_sp<boolean_p>::Access()
        const volatile
    {
        return os::atomic::Access(this->value);
    }

    template <boolean_tr boolean_p>
    inline typename boolean_sp<boolean_p>::value_t
        boolean_sp<boolean_p>::Assign(convertible_tr<value_t> auto value)
    {
        return os::atomic::Assign(this->value, value);
    }

    template <boolean_tr boolean_p>
    inline typename boolean_sp<boolean_p>::value_t
        boolean_sp<boolean_p>::Assign(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Assign(this->value, value);
    }

    template <boolean_tr boolean_p>
    inline typename boolean_sp<boolean_p>::value_t
        boolean_sp<boolean_p>::Exchange(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange(this->value, value);
    }

    template <boolean_tr boolean_p>
    inline typename boolean_sp<boolean_p>::value_t
        boolean_sp<boolean_p>::Exchange(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Exchange(this->value, value);
    }

    template <boolean_tr boolean_p>
    inline bool_t
        boolean_sp<boolean_p>::Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_If_Equals(this->value, snapshot, value);
    }

    template <boolean_tr boolean_p>
    inline bool_t
        boolean_sp<boolean_p>::Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Exchange_If_Equals(this->value, snapshot, value);
    }

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>::operator std_bool_t()
        const
    {
        return Access();
    }

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>::operator std_bool_t()
        const volatile
    {
        return Access();
    }

    template <boolean_tr boolean_p>
    inline typename boolean_sp<boolean_p>::value_t
        boolean_sp<boolean_p>::operator ()()
        const
    {
        return Access();
    }

    template <boolean_tr boolean_p>
    inline typename boolean_sp<boolean_p>::value_t
        boolean_sp<boolean_p>::operator ()()
        const volatile
    {
        return Access();
    }

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>::boolean_sp(none_t) :
        value(DEFAULT_VALUE)
    {
    }

    template <boolean_tr boolean_p>
    inline boolean_sp<boolean_p>&
        boolean_sp<boolean_p>::operator =(none_t)
    {
        Assign(DEFAULT_VALUE);
        return *this;
    }

    template <boolean_tr boolean_p>
    inline volatile boolean_sp<boolean_p>&
        boolean_sp<boolean_p>::operator =(none_t)
        volatile
    {
        Assign(DEFAULT_VALUE);
        return *this;
    }

    template <boolean_tr boolean_p>
    inline bool_t
        boolean_sp<boolean_p>::operator ==(none_t)
        const
    {
        return static_cast<bool_t>(Access()) == false;
    }

    template <boolean_tr boolean_p>
    inline bool_t
        boolean_sp<boolean_p>::operator ==(none_t)
        const volatile
    {
        return static_cast<bool_t>(Access()) == false;
    }

    template <boolean_tr boolean_p>
    inline bool_t
        boolean_sp<boolean_p>::operator !=(none_t)
        const
    {
        return !operator ==(none_t());
    }

    template <boolean_tr boolean_p>
    inline bool_t
        boolean_sp<boolean_p>::operator !=(none_t)
        const volatile
    {
        return !operator ==(none_t());
    }

    template <integer_tr integer_p>
    inline typename const integer_sp<integer_p>::value_t
        integer_sp<integer_p>::DEFAULT_VALUE    = value_t();

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
    inline integer_sp<integer_p>::integer_sp(const volatile integer_sp& other) :
        value(other.Access())
    {
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>::integer_sp(integer_sp&& other) noexcept :
        value(other.Exchange(DEFAULT_VALUE))
    {
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>::integer_sp(volatile integer_sp&& other) noexcept :
        value(other.Exchange(DEFAULT_VALUE))
    {
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>&
        integer_sp<integer_p>::operator =(const integer_sp& other)
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    template <integer_tr integer_p>
    inline volatile integer_sp<integer_p>&
        integer_sp<integer_p>::operator =(const integer_sp& other)
        volatile
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>&
        integer_sp<integer_p>::operator =(const volatile integer_sp& other)
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    template <integer_tr integer_p>
    inline volatile integer_sp<integer_p>&
        integer_sp<integer_p>::operator =(const volatile integer_sp& other)
        volatile
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>&
        integer_sp<integer_p>::operator =(integer_sp&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    template <integer_tr integer_p>
    inline volatile integer_sp<integer_p>&
        integer_sp<integer_p>::operator =(integer_sp&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>&
        integer_sp<integer_p>::operator =(is_just_volatile_tr<integer_sp> auto&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    template <integer_tr integer_p>
    inline volatile integer_sp<integer_p>&
        integer_sp<integer_p>::operator =(is_just_volatile_tr<integer_sp> auto&& other)
        volatile noexcept
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
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Access()
        const
    {
        return os::atomic::Access(this->value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Access()
        const volatile
    {
        return os::atomic::Access(this->value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign(convertible_tr<value_t> auto value)
    {
        return os::atomic::Assign(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Assign(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign_Add(convertible_tr<value_t> auto value)
    {
        return os::atomic::Assign_Add(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign_Add(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Assign_Add(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign_Subtract(convertible_tr<value_t> auto value)
    {
        return os::atomic::Assign_Subtract(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign_Subtract(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Assign_Subtract(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign_Multiply(convertible_tr<value_t> auto value)
    {
        return os::atomic::Assign_Multiply(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign_Multiply(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Assign_Multiply(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign_Divide(convertible_tr<value_t> auto value)
    {
        return os::atomic::Assign_Divide(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign_Divide(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Assign_Divide(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign_Modulus(integer_tr auto value)
    {
        return os::atomic::Assign_Modulus(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign_Modulus(integer_tr auto value)
        volatile
    {
        return os::atomic::Assign_Modulus(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign_Or(integer_tr auto value)
    {
        return os::atomic::Assign_Or(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign_Or(integer_tr auto value)
        volatile
    {
        return os::atomic::Assign_Or(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign_And(integer_tr auto value)
    {
        return os::atomic::Assign_And(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign_And(integer_tr auto value)
        volatile
    {
        return os::atomic::Assign_And(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign_Xor(integer_tr auto value)
    {
        return os::atomic::Assign_Xor(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign_Xor(integer_tr auto value)
        volatile
    {
        return os::atomic::Assign_Xor(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign_Left_Shift(integer_tr auto value)
    {
        return os::atomic::Assign_Left_Shift(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign_Left_Shift(integer_tr auto value)
        volatile
    {
        return os::atomic::Assign_Left_Shift(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign_Right_Shift(integer_tr auto value)
    {
        return os::atomic::Assign_Right_Shift(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Assign_Right_Shift(integer_tr auto value)
        volatile
    {
        return os::atomic::Assign_Right_Shift(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Exchange(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange_Add(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_Add(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange_Add(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Exchange_Add(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange_Subtract(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_Subtract(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange_Subtract(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Exchange_Subtract(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange_Multiply(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_Multiply(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange_Multiply(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Exchange_Multiply(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange_Divide(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_Divide(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange_Divide(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Exchange_Divide(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange_Modulus(integer_tr auto value)
    {
        return os::atomic::Exchange_Modulus(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange_Modulus(integer_tr auto value)
        volatile
    {
        return os::atomic::Exchange_Modulus(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange_Or(integer_tr auto value)
    {
        return os::atomic::Exchange_Or(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange_Or(integer_tr auto value)
        volatile
    {
        return os::atomic::Exchange_Or(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange_And(integer_tr auto value)
    {
        return os::atomic::Exchange_And(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange_And(integer_tr auto value)
        volatile
    {
        return os::atomic::Exchange_And(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange_Xor(integer_tr auto value)
    {
        return os::atomic::Exchange_Xor(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange_Xor(integer_tr auto value)
        volatile
    {
        return os::atomic::Exchange_Xor(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange_Left_Shift(integer_tr auto value)
    {
        return os::atomic::Exchange_Left_Shift(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange_Left_Shift(integer_tr auto value)
        volatile
    {
        return os::atomic::Exchange_Left_Shift(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange_Right_Shift(integer_tr auto value)
    {
        return os::atomic::Exchange_Right_Shift(this->value, value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::Exchange_Right_Shift(integer_tr auto value)
        volatile
    {
        return os::atomic::Exchange_Right_Shift(this->value, value);
    }

    template <integer_tr integer_p>
    inline bool_t
        integer_sp<integer_p>::Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_If_Equals(this->value, snapshot, value);
    }

    template <integer_tr integer_p>
    inline bool_t
        integer_sp<integer_p>::Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Exchange_If_Equals(this->value, snapshot, value);
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>::operator value_t()
        const
    {
        return Access();
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>::operator value_t()
        const volatile
    {
        return Access();
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator ()()
        const
    {
        return Access();
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator ()()
        const volatile
    {
        return Access();
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator +=(convertible_tr<value_t> auto value)
    {
        return Assign_Add(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator +=(convertible_tr<value_t> auto value)
        volatile
    {
        return Assign_Add(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator -=(convertible_tr<value_t> auto value)
    {
        return Assign_Subtract(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator -=(convertible_tr<value_t> auto value)
        volatile
    {
        return Assign_Subtract(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator *=(convertible_tr<value_t> auto value)
    {
        return Assign_Multiply(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator *=(convertible_tr<value_t> auto value)
        volatile
    {
        return Assign_Multiply(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator /=(convertible_tr<value_t> auto value)
    {
        return Assign_Divide(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator /=(convertible_tr<value_t> auto value)
        volatile
    {
        return Assign_Divide(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator %=(integer_tr auto value)
    {
        return Assign_Modulus(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator %=(integer_tr auto value)
        volatile
    {
        return Assign_Modulus(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator |=(integer_tr auto value)
    {
        return Assign_Or(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator |=(integer_tr auto value)
        volatile
    {
        return Assign_Or(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator &=(integer_tr auto value)
    {
        return Assign_And(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator &=(integer_tr auto value)
        volatile
    {
        return Assign_And(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator ^=(integer_tr auto value)
    {
        return Assign_Xor(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator ^=(integer_tr auto value)
        volatile
    {
        return Assign_Xor(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator <<=(integer_tr auto value)
    {
        return Assign_Left_Shift(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator <<=(integer_tr auto value)
        volatile
    {
        return Assign_Left_Shift(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator >>=(integer_tr auto value)
    {
        return Assign_Right_Shift(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator >>=(integer_tr auto value)
        volatile
    {
        return Assign_Right_Shift(value);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator ++()
    {
        return Assign_Add(1);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator ++()
        volatile
    {
        return Assign_Add(1);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator ++(int)
    {
        return Exchange_Add(1);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator ++(int)
        volatile
    {
        return Exchange_Add(1);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator --()
    {
        return Assign_Subtract(1);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator --()
        volatile
    {
        return Assign_Subtract(1);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator --(int)
    {
        return Exchange_Subtract(1);
    }

    template <integer_tr integer_p>
    inline typename integer_sp<integer_p>::value_t
        integer_sp<integer_p>::operator --(int)
        volatile
    {
        return Exchange_Subtract(1);
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>::integer_sp(none_t) :
        value(DEFAULT_VALUE)
    {
    }

    template <integer_tr integer_p>
    inline integer_sp<integer_p>&
        integer_sp<integer_p>::operator =(none_t)
    {
        Assign(DEFAULT_VALUE);
        return *this;
    }

    template <integer_tr integer_p>
    inline volatile integer_sp<integer_p>&
        integer_sp<integer_p>::operator =(none_t)
        volatile
    {
        Assign(DEFAULT_VALUE);
        return *this;
    }

    template <integer_tr integer_p>
    inline bool_t
        integer_sp<integer_p>::operator ==(none_t)
        const
    {
        return static_cast<bool_t>(Access()) == false;
    }

    template <integer_tr integer_p>
    inline bool_t
        integer_sp<integer_p>::operator ==(none_t)
        const volatile
    {
        return static_cast<bool_t>(Access()) == false;
    }

    template <integer_tr integer_p>
    inline bool_t
        integer_sp<integer_p>::operator !=(none_t)
        const
    {
        return !operator ==(none_t());
    }

    template <integer_tr integer_p>
    inline bool_t
        integer_sp<integer_p>::operator !=(none_t)
        const volatile
    {
        return !operator ==(none_t());
    }

    template <real_tr real_p>
    inline typename const real_sp<real_p>::value_t
        real_sp<real_p>::DEFAULT_VALUE  = value_t();

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
    inline real_sp<real_p>::real_sp(const volatile real_sp& other) :
        value(other.Access())
    {
    }

    template <real_tr real_p>
    inline real_sp<real_p>::real_sp(real_sp&& other) noexcept :
        value(other.Exchange(DEFAULT_VALUE))
    {
    }

    template <real_tr real_p>
    inline real_sp<real_p>::real_sp(volatile real_sp&& other) noexcept :
        value(other.Exchange(DEFAULT_VALUE))
    {
    }

    template <real_tr real_p>
    inline real_sp<real_p>&
        real_sp<real_p>::operator =(const real_sp& other)
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    template <real_tr real_p>
    inline volatile real_sp<real_p>&
        real_sp<real_p>::operator =(const real_sp& other)
        volatile
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    template <real_tr real_p>
    inline real_sp<real_p>&
        real_sp<real_p>::operator =(const volatile real_sp& other)
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    template <real_tr real_p>
    inline volatile real_sp<real_p>&
        real_sp<real_p>::operator =(const volatile real_sp& other)
        volatile
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    template <real_tr real_p>
    inline real_sp<real_p>&
        real_sp<real_p>::operator =(real_sp&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    template <real_tr real_p>
    inline volatile real_sp<real_p>&
        real_sp<real_p>::operator =(real_sp&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    template <real_tr real_p>
    inline real_sp<real_p>&
        real_sp<real_p>::operator =(is_just_volatile_tr<real_sp> auto&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    template <real_tr real_p>
    inline volatile real_sp<real_p>&
        real_sp<real_p>::operator =(is_just_volatile_tr<real_sp> auto&& other)
        volatile noexcept
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
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Access()
        const
    {
        return os::atomic::Access(this->value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Access()
        const volatile
    {
        return os::atomic::Access(this->value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Assign(convertible_tr<value_t> auto value)
    {
        return os::atomic::Assign(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Assign(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Assign(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Assign_Add(convertible_tr<value_t> auto value)
    {
        return os::atomic::Assign_Add(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Assign_Add(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Assign_Add(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Assign_Subtract(convertible_tr<value_t> auto value)
    {
        return os::atomic::Assign_Subtract(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Assign_Subtract(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Assign_Subtract(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Assign_Multiply(convertible_tr<value_t> auto value)
    {
        return os::atomic::Assign_Multiply(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Assign_Multiply(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Assign_Multiply(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Assign_Divide(convertible_tr<value_t> auto value)
    {
        return os::atomic::Assign_Divide(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Assign_Divide(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Assign_Divide(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Exchange(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Exchange(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Exchange(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Exchange_Add(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_Add(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Exchange_Add(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Exchange_Add(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Exchange_Subtract(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_Subtract(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Exchange_Subtract(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Exchange_Subtract(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Exchange_Multiply(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_Multiply(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Exchange_Multiply(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Exchange_Multiply(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Exchange_Divide(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_Divide(this->value, value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::Exchange_Divide(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Exchange_Divide(this->value, value);
    }

    template <real_tr real_p>
    inline bool_t
        real_sp<real_p>::Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_If_Equals(this->value, snapshot, value);
    }

    template <real_tr real_p>
    inline bool_t
        real_sp<real_p>::Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Exchange_If_Equals(this->value, snapshot, value);
    }

    template <real_tr real_p>
    inline real_sp<real_p>::operator value_t()
        const
    {
        return Access();
    }

    template <real_tr real_p>
    inline real_sp<real_p>::operator value_t()
        const volatile
    {
        return Access();
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator ()()
        const
    {
        return Access();
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator ()()
        const volatile
    {
        return Access();
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator +=(convertible_tr<value_t> auto value)
    {
        return Assign_Add(value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator +=(convertible_tr<value_t> auto value)
        volatile
    {
        return Assign_Add(value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator -=(convertible_tr<value_t> auto value)
    {
        return Assign_Subtract(value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator -=(convertible_tr<value_t> auto value)
        volatile
    {
        return Assign_Subtract(value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator *=(convertible_tr<value_t> auto value)
    {
        return Assign_Multiply(value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator *=(convertible_tr<value_t> auto value)
        volatile
    {
        return Assign_Multiply(value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator /=(convertible_tr<value_t> auto value)
    {
        return Assign_Divide(value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator /=(convertible_tr<value_t> auto value)
        volatile
    {
        return Assign_Divide(value);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator ++()
    {
        return Assign_Add(1);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator ++()
        volatile
    {
        return Assign_Add(1);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator ++(int)
    {
        return Exchange_Add(1);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator ++(int)
        volatile
    {
        return Exchange_Add(1);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator --()
    {
        return Assign_Subtract(1);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator --()
        volatile
    {
        return Assign_Subtract(1);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator --(int)
    {
        return Exchange_Subtract(1);
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator --(int)
        volatile
    {
        return Exchange_Subtract(1);
    }

    template <real_tr real_p>
    inline real_sp<real_p>::real_sp(none_t) :
        value(DEFAULT_VALUE)
    {
    }

    template <real_tr real_p>
    inline real_sp<real_p>&
        real_sp<real_p>::operator =(none_t)
    {
        Assign(DEFAULT_VALUE);
        return *this;
    }

    template <real_tr real_p>
    inline volatile real_sp<real_p>&
        real_sp<real_p>::operator =(none_t)
        volatile
    {
        Assign(DEFAULT_VALUE);
        return *this;
    }

    template <real_tr real_p>
    inline bool_t
        real_sp<real_p>::operator ==(none_t)
        const
    {
        return Access() == DEFAULT_VALUE;
    }

    template <real_tr real_p>
    inline bool_t
        real_sp<real_p>::operator ==(none_t)
        const volatile
    {
        return Access() == DEFAULT_VALUE;
    }

    template <real_tr real_p>
    inline bool_t
        real_sp<real_p>::operator !=(none_t)
        const
    {
        return !operator ==(none_t());
    }

    template <real_tr real_p>
    inline bool_t
        real_sp<real_p>::operator !=(none_t)
        const volatile
    {
        return !operator ==(none_t());
    }

    template <c_pointer_tr c_pointer_p>
    inline typename const c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::DEFAULT_VALUE    = value_t();

    template <c_pointer_tr c_pointer_p>
    inline c_pointer_sp<c_pointer_p>::c_pointer_sp() :
        value(DEFAULT_VALUE)
    {
    }

    template <c_pointer_tr c_pointer_p>
    inline c_pointer_sp<c_pointer_p>::c_pointer_sp(convertible_tr<value_t> auto value) :
        value(static_cast<value_t>(value))
    {
    }

    template <c_pointer_tr c_pointer_p>
    inline c_pointer_sp<c_pointer_p>::c_pointer_sp(const c_pointer_sp& other) :
        value(other.Access())
    {
    }

    template <c_pointer_tr c_pointer_p>
    inline c_pointer_sp<c_pointer_p>::c_pointer_sp(const volatile c_pointer_sp& other) :
        value(other.Access())
    {
    }

    template <c_pointer_tr c_pointer_p>
    inline c_pointer_sp<c_pointer_p>::c_pointer_sp(c_pointer_sp&& other) noexcept :
        value(other.Exchange(DEFAULT_VALUE))
    {
    }

    template <c_pointer_tr c_pointer_p>
    inline c_pointer_sp<c_pointer_p>::c_pointer_sp(volatile c_pointer_sp&& other) noexcept :
        value(other.Exchange(DEFAULT_VALUE))
    {
    }

    template <c_pointer_tr c_pointer_p>
    inline c_pointer_sp<c_pointer_p>&
        c_pointer_sp<c_pointer_p>::operator =(const c_pointer_sp& other)
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    template <c_pointer_tr c_pointer_p>
    inline volatile c_pointer_sp<c_pointer_p>&
        c_pointer_sp<c_pointer_p>::operator =(const c_pointer_sp& other)
        volatile
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    template <c_pointer_tr c_pointer_p>
    inline c_pointer_sp<c_pointer_p>&
        c_pointer_sp<c_pointer_p>::operator =(const volatile c_pointer_sp& other)
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    template <c_pointer_tr c_pointer_p>
    inline volatile c_pointer_sp<c_pointer_p>&
        c_pointer_sp<c_pointer_p>::operator =(const volatile c_pointer_sp& other)
        volatile
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    template <c_pointer_tr c_pointer_p>
    inline c_pointer_sp<c_pointer_p>&
        c_pointer_sp<c_pointer_p>::operator =(c_pointer_sp&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    template <c_pointer_tr c_pointer_p>
    inline volatile c_pointer_sp<c_pointer_p>&
        c_pointer_sp<c_pointer_p>::operator =(c_pointer_sp&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    template <c_pointer_tr c_pointer_p>
    inline c_pointer_sp<c_pointer_p>&
        c_pointer_sp<c_pointer_p>::operator =(is_just_volatile_tr<c_pointer_sp> auto&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    template <c_pointer_tr c_pointer_p>
    inline volatile c_pointer_sp<c_pointer_p>&
        c_pointer_sp<c_pointer_p>::operator =(is_just_volatile_tr<c_pointer_sp> auto&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    template <c_pointer_tr c_pointer_p>
    inline c_pointer_sp<c_pointer_p>::~c_pointer_sp()
    {
        Assign(DEFAULT_VALUE);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::Access()
        const
    {
        return os::atomic::Access(this->value);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::Access()
        const volatile
    {
        return os::atomic::Access(this->value);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::Assign(convertible_tr<value_t> auto value)
    {
        return os::atomic::Assign(this->value, value);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::Assign(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Assign(this->value, value);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::Assign_Add(integer_tr auto value)
    {
        return os::atomic::Assign_Add(this->value, value);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::Assign_Add(integer_tr auto value)
        volatile
    {
        return os::atomic::Assign_Add(this->value, value);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::Assign_Subtract(integer_tr auto value)
    {
        return os::atomic::Assign_Subtract(this->value, value);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::Assign_Subtract(integer_tr auto value)
        volatile
    {
        return os::atomic::Assign_Subtract(this->value, value);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::Exchange(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange(this->value, value);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::Exchange(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Exchange(this->value, value);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::Exchange_Add(integer_tr auto value)
    {
        return os::atomic::Exchange_Add(this->value, value);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::Exchange_Add(integer_tr auto value)
        volatile
    {
        return os::atomic::Exchange_Add(this->value, value);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::Exchange_Subtract(integer_tr auto value)
    {
        return os::atomic::Exchange_Subtract(this->value, value);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::Exchange_Subtract(integer_tr auto value)
        volatile
    {
        return os::atomic::Exchange_Subtract(this->value, value);
    }

    template <c_pointer_tr c_pointer_p>
    inline bool_t
        c_pointer_sp<c_pointer_p>::Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_If_Equals(this->value, snapshot, value);
    }

    template <c_pointer_tr c_pointer_p>
    inline bool_t
        c_pointer_sp<c_pointer_p>::Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Exchange_If_Equals(this->value, snapshot, value);
    }

    template <c_pointer_tr c_pointer_p>
    inline c_pointer_sp<c_pointer_p>::operator value_t()
        const
    {
        return Access();
    }

    template <c_pointer_tr c_pointer_p>
    inline c_pointer_sp<c_pointer_p>::operator value_t()
        const volatile
    {
        return Access();
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::operator ()()
        const
    {
        return Access();
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::operator ()()
        const volatile
    {
        return Access();
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::operator +=(integer_tr auto value)
    {
        return Assign_Add(value);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::operator +=(integer_tr auto value)
        volatile
    {
        return Assign_Add(value);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::operator -=(integer_tr auto value)
    {
        return Assign_Subtract(value);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::operator -=(integer_tr auto value)
        volatile
    {
        return Assign_Subtract(value);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::operator ++()
    {
        return Assign_Add(1);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::operator ++()
        volatile
    {
        return Assign_Add(1);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::operator ++(int)
    {
        return Exchange_Add(1);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::operator ++(int)
        volatile
    {
        return Exchange_Add(1);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::operator --()
    {
        return Assign_Subtract(1);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::operator --()
        volatile
    {
        return Assign_Subtract(1);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::operator --(int)
    {
        return Exchange_Subtract(1);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::operator --(int)
        volatile
    {
        return Exchange_Subtract(1);
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::operator ->()
        const
    {
        return Access();
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::value_t
        c_pointer_sp<c_pointer_p>::operator ->()
        const volatile
    {
        return Access();
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::unit_t&
        c_pointer_sp<c_pointer_p>::operator *()
        const
    {
        return *Access();
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::unit_t&
        c_pointer_sp<c_pointer_p>::operator *()
        const volatile
    {
        return *Access();
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::unit_t&
        c_pointer_sp<c_pointer_p>::operator [](integer_tr auto index)
        const
    {
        return Access()[static_cast<index_t>(index)];
    }

    template <c_pointer_tr c_pointer_p>
    inline typename c_pointer_sp<c_pointer_p>::unit_t&
        c_pointer_sp<c_pointer_p>::operator [](integer_tr auto index)
        const volatile
    {
        return Access()[static_cast<index_t>(index)];
    }

    template <c_pointer_tr c_pointer_p>
    inline c_pointer_sp<c_pointer_p>::c_pointer_sp(none_t) :
        value(DEFAULT_VALUE)
    {
    }

    template <c_pointer_tr c_pointer_p>
    inline c_pointer_sp<c_pointer_p>&
        c_pointer_sp<c_pointer_p>::operator =(none_t)
    {
        Assign(DEFAULT_VALUE);
        return *this;
    }

    template <c_pointer_tr c_pointer_p>
    inline volatile c_pointer_sp<c_pointer_p>&
        c_pointer_sp<c_pointer_p>::operator =(none_t)
        volatile
    {
        Assign(DEFAULT_VALUE);
        return *this;
    }

    template <c_pointer_tr c_pointer_p>
    inline bool_t
        c_pointer_sp<c_pointer_p>::operator ==(none_t)
        const
    {
        return static_cast<bool_t>(Access()) == false;
    }

    template <c_pointer_tr c_pointer_p>
    inline bool_t
        c_pointer_sp<c_pointer_p>::operator ==(none_t)
        const volatile
    {
        return static_cast<bool_t>(Access()) == false;
    }

    template <c_pointer_tr c_pointer_p>
    inline bool_t
        c_pointer_sp<c_pointer_p>::operator !=(none_t)
        const
    {
        return !operator ==(none_t());
    }

    template <c_pointer_tr c_pointer_p>
    inline bool_t
        c_pointer_sp<c_pointer_p>::operator !=(none_t)
        const volatile
    {
        return !operator ==(none_t());
    }

    inline typename const void_pointer_sp::value_t
        void_pointer_sp::DEFAULT_VALUE  = value_t();

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

    inline void_pointer_sp::void_pointer_sp(const volatile void_pointer_sp& other) :
        value(other.Access())
    {
    }

    inline void_pointer_sp::void_pointer_sp(void_pointer_sp&& other) noexcept :
        value(other.Exchange(DEFAULT_VALUE))
    {
    }

    inline void_pointer_sp::void_pointer_sp(volatile void_pointer_sp&& other) noexcept :
        value(other.Exchange(DEFAULT_VALUE))
    {
    }

    inline void_pointer_sp&
        void_pointer_sp::operator =(const void_pointer_sp& other)
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    inline volatile void_pointer_sp&
        void_pointer_sp::operator =(const void_pointer_sp& other)
        volatile
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    inline void_pointer_sp&
        void_pointer_sp::operator =(const volatile void_pointer_sp& other)
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    inline volatile void_pointer_sp&
        void_pointer_sp::operator =(const volatile void_pointer_sp& other)
        volatile
    {
        if (this != std::addressof(other)) {
            Assign(other.Access());
        }
        return *this;
    }

    inline void_pointer_sp&
        void_pointer_sp::operator =(void_pointer_sp&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    inline volatile void_pointer_sp&
        void_pointer_sp::operator =(void_pointer_sp&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    inline void_pointer_sp&
        void_pointer_sp::operator =(is_just_volatile_tr<void_pointer_sp> auto&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            Assign(other.Exchange(DEFAULT_VALUE));
        }
        return *this;
    }

    inline volatile void_pointer_sp&
        void_pointer_sp::operator =(is_just_volatile_tr<void_pointer_sp> auto&& other)
        volatile noexcept
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

    inline typename void_pointer_sp::value_t
        void_pointer_sp::Access()
        const
    {
        return os::atomic::Access(this->value);
    }

    inline typename void_pointer_sp::value_t
        void_pointer_sp::Access()
        const volatile
    {
        return os::atomic::Access(this->value);
    }

    inline typename void_pointer_sp::value_t
        void_pointer_sp::Assign(convertible_tr<value_t> auto value)
    {
        return os::atomic::Assign(this->value, value);
    }

    inline typename void_pointer_sp::value_t
        void_pointer_sp::Assign(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Assign(this->value, value);
    }

    inline typename void_pointer_sp::value_t
        void_pointer_sp::Exchange(convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange(this->value, value);
    }

    inline typename void_pointer_sp::value_t
        void_pointer_sp::Exchange(convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Exchange(this->value, value);
    }

    inline bool_t
        void_pointer_sp::Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value)
    {
        return os::atomic::Exchange_If_Equals(this->value, snapshot, value);
    }

    inline bool_t
        void_pointer_sp::Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value)
        volatile
    {
        return os::atomic::Exchange_If_Equals(this->value, snapshot, value);
    }

    inline void_pointer_sp::operator value_t()
        const
    {
        return Access();
    }

    inline void_pointer_sp::operator value_t()
        const volatile
    {
        return Access();
    }

    inline typename void_pointer_sp::value_t
        void_pointer_sp::operator ()()
        const
    {
        return Access();
    }

    inline typename void_pointer_sp::value_t
        void_pointer_sp::operator ()()
        const volatile
    {
        return Access();
    }

    inline void_pointer_sp::void_pointer_sp(none_t) :
        value(DEFAULT_VALUE)
    {
    }

    inline void_pointer_sp&
        void_pointer_sp::operator =(none_t)
    {
        Assign(DEFAULT_VALUE);
        return *this;
    }

    inline volatile void_pointer_sp&
        void_pointer_sp::operator =(none_t)
        volatile
    {
        Assign(DEFAULT_VALUE);
        return *this;
    }

    inline bool_t
        void_pointer_sp::operator ==(none_t)
        const
    {
        return static_cast<bool_t>(Access()) == false;
    }

    inline bool_t
        void_pointer_sp::operator ==(none_t)
        const volatile
    {
        return static_cast<bool_t>(Access()) == false;
    }

    inline bool_t
        void_pointer_sp::operator !=(none_t)
        const
    {
        return !operator ==(none_t());
    }

    inline bool_t
        void_pointer_sp::operator !=(none_t)
        const volatile
    {
        return !operator ==(none_t());
    }

}}
