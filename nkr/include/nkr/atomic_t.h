/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"

namespace nkr {

    template <typename integer_p = word_t>
    class atomic_t
    {
    public:
        static_assert(integer_tr<integer_p>, "invalid atomic value_t.");

    public:
        using value_t   = integer_p;

    private:
        volatile value_t    value;

    public:
        atomic_t();
        atomic_t(value_t value);
        atomic_t(const atomic_t& other);
        atomic_t(atomic_t&& other) noexcept;
        atomic_t& operator =(const atomic_t& other);
        atomic_t& operator =(atomic_t&& other) noexcept;
        ~atomic_t();

    public:
        value_t Access() const;
        value_t Access_Add(integer_tr auto value) const;
        value_t Access_Subtract(integer_tr auto value) const;
        value_t Access_Or(integer_tr auto value) const;
        value_t Access_And(integer_tr auto value) const;
        value_t Access_Xor(integer_tr auto value) const;

        value_t Assign(integer_tr auto value);
        value_t Assign_Add(integer_tr auto value);
        value_t Assign_Subtract(integer_tr auto value);
        value_t Assign_Or(integer_tr auto value);
        value_t Assign_And(integer_tr auto value);
        value_t Assign_Xor(integer_tr auto value);

        value_t Exchange(integer_tr auto value);
        value_t Exchange_If_Equals(integer_tr auto value, integer_tr auto target);
        value_t Exchange_Add(integer_tr auto value);
        value_t Exchange_Subtract(integer_tr auto value);
        value_t Exchange_Or(integer_tr auto value);
        value_t Exchange_And(integer_tr auto value);
        value_t Exchange_Xor(integer_tr auto value);

    public:
        operator    value_t() const;

    public:
        value_t operator ()() const;

        value_t operator =(integer_tr auto value);

        value_t operator +(integer_tr auto value) const;
        value_t operator -(integer_tr auto value) const;
        value_t operator +=(integer_tr auto value);
        value_t operator -=(integer_tr auto value);
        value_t operator ++();
        value_t operator ++(int);
        value_t operator --();
        value_t operator --(int);

        value_t operator ~() const;
        value_t operator |(integer_tr auto value) const;
        value_t operator &(integer_tr auto value) const;
        value_t operator ^(integer_tr auto value) const;
        value_t operator |=(integer_tr auto value);
        value_t operator &=(integer_tr auto value);
        value_t operator ^=(integer_tr auto value);
    };

    template <>
    class atomic_t<bool_t>
    {
    public:
        using value_t   = bool_t;

    private:
        volatile value_t    value;

    public:
        atomic_t();
        atomic_t(value_t value);
        atomic_t(const atomic_t& other);
        atomic_t(atomic_t&& other) noexcept;
        atomic_t& operator =(const atomic_t& other);
        atomic_t& operator =(atomic_t&& other) noexcept;
        ~atomic_t();

    public:
        value_t Access() const;

        value_t Assign(value_t value);

        value_t Exchange(value_t value);
        value_t Exchange_If_Equals(value_t value, value_t target);

    public:
        operator    value_t() const;

    public:
        value_t operator ()() const;

        value_t operator =(value_t value);
    };

    template <typename value_p>
    class atomic_t<value_p*>
    {
    public:
        using value_t   = value_p;

    private:
        value_t* volatile   value;

    public:
        atomic_t();
        atomic_t(value_t* value);
        atomic_t(const atomic_t& other);
        atomic_t(atomic_t&& other) noexcept;
        atomic_t& operator =(const atomic_t& other);
        atomic_t& operator =(atomic_t&& other) noexcept;
        ~atomic_t();

    public:
        value_t*    Access() const;
        value_t*    Access_Add(integer_tr auto value) const;
        value_t*    Access_Subtract(integer_tr auto value) const;

        value_t*    Assign(pointer_tr auto value);
        value_t*    Assign_Add(integer_tr auto value);
        value_t*    Assign_Subtract(integer_tr auto value);

        value_t*    Exchange(pointer_tr auto value);
        value_t*    Exchange_If_Equals(pointer_tr auto value, pointer_tr auto target);
        value_t*    Exchange_Add(integer_tr auto value);
        value_t*    Exchange_Subtract(integer_tr auto value);

    public:
        operator    value_t*() const;

    public:
        value_t*    operator ()() const;

        value_t*    operator =(pointer_tr auto value);

        value_t*    operator +(integer_tr auto value) const;
        value_t*    operator -(integer_tr auto value) const;
        value_t*    operator +=(integer_tr auto value);
        value_t*    operator -=(integer_tr auto value);
        value_t*    operator ++();
        value_t*    operator ++(int);
        value_t*    operator --();
        value_t*    operator --(int);

        value_t*    operator ->() const;
        value_t&    operator *() const;
        value_t&    operator [](integer_tr auto index) const;
    };

    template <>
    class atomic_t<void_t*>
    {
    public:
        using value_t   = void_t;

    private:
        value_t* volatile   value;

    public:
        atomic_t();
        atomic_t(value_t* value);
        atomic_t(const atomic_t& other);
        atomic_t(atomic_t&& other) noexcept;
        atomic_t& operator =(const atomic_t& other);
        atomic_t& operator =(atomic_t&& other) noexcept;
        ~atomic_t();

    public:
        value_t*    Access() const;

        value_t*    Assign(pointer_tr auto value);

        value_t*    Exchange(pointer_tr auto value);
        value_t*    Exchange_If_Equals(pointer_tr auto value, pointer_tr auto target);

    public:
        operator    value_t*() const;

    public:
        value_t*    operator ()() const;

        value_t*    operator =(pointer_tr auto value);
    };

}

#include "nkr/atomic_t.inl"
