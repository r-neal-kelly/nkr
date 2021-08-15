/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsic.h"
#include "nkr/traits.h"

namespace nkr {

    template <typename value_p = word_t>
    class atomic_t
    {
    public:
        using value_t   = value_p;

    public:
        static_assert(std::is_integral<value_t>::value, "invalid atomic value_t.");

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
        template <integral_tr integral_p>
        value_t Access_Add(integral_p value) const;
        template <integral_tr integral_p>
        value_t Access_Subtract(integral_p value) const;
        template <integral_tr integral_p>
        value_t Access_Or(integral_p value) const;
        template <integral_tr integral_p>
        value_t Access_And(integral_p value) const;
        template <integral_tr integral_p>
        value_t Access_Xor(integral_p value) const;

        template <integral_tr integral_p>
        value_t Assign(integral_p value);
        template <integral_tr integral_p>
        value_t Assign_Add(integral_p value);
        template <integral_tr integral_p>
        value_t Assign_Subtract(integral_p value);
        template <integral_tr integral_p>
        value_t Assign_Or(integral_p value);
        template <integral_tr integral_p>
        value_t Assign_And(integral_p value);
        template <integral_tr integral_p>
        value_t Assign_Xor(integral_p value);

        template <integral_tr integral_p>
        value_t Exchange(integral_p value);
        template <integral_tr integral_a_p, integral_tr integral_b_p>
        value_t Exchange_If_Equals(integral_a_p value, integral_b_p target);
        template <integral_tr integral_p>
        value_t Exchange_Add(integral_p value);
        template <integral_tr integral_p>
        value_t Exchange_Subtract(integral_p value);
        template <integral_tr integral_p>
        value_t Exchange_Or(integral_p value);
        template <integral_tr integral_p>
        value_t Exchange_And(integral_p value);
        template <integral_tr integral_p>
        value_t Exchange_Xor(integral_p value);

    public:
        operator    value_t() const;

    public:
        value_t operator ()() const;

        template <integral_tr integral_p>
        value_t operator =(integral_p value);

        template <integral_tr integral_p>
        value_t operator +(integral_p value) const;
        template <integral_tr integral_p>
        value_t operator -(integral_p value) const;
        template <integral_tr integral_p>
        value_t operator +=(integral_p value);
        template <integral_tr integral_p>
        value_t operator -=(integral_p value);
        value_t operator ++();
        value_t operator ++(int);
        value_t operator --();
        value_t operator --(int);

        value_t operator ~() const;
        template <integral_tr integral_p>
        value_t operator |(integral_p value) const;
        template <integral_tr integral_p>
        value_t operator &(integral_p value) const;
        template <integral_tr integral_p>
        value_t operator ^(integral_p value) const;
        template <integral_tr integral_p>
        value_t operator |=(integral_p value);
        template <integral_tr integral_p>
        value_t operator &=(integral_p value);
        template <integral_tr integral_p>
        value_t operator ^=(integral_p value);
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
        template <integral_tr integral_p>
        value_t*    Access_Add(integral_p value) const;
        template <integral_tr integral_p>
        value_t*    Access_Subtract(integral_p value) const;

        template <pointer_tr pointer_p>
        value_t*    Assign(pointer_p value);
        template <integral_tr integral_p>
        value_t*    Assign_Add(integral_p value);
        template <integral_tr integral_p>
        value_t*    Assign_Subtract(integral_p value);

        template <pointer_tr pointer_p>
        value_t*    Exchange(pointer_p value);
        template <pointer_tr pointer_a_p, pointer_tr pointer_b_p>
        value_t*    Exchange_If_Equals(pointer_a_p value, pointer_b_p target);
        template <integral_tr integral_p>
        value_t*    Exchange_Add(integral_p value);
        template <integral_tr integral_p>
        value_t*    Exchange_Subtract(integral_p value);

    public:
        operator    value_t*() const;

    public:
        value_t*    operator ()() const;

        template <pointer_tr pointer_p>
        value_t*    operator =(pointer_p value);

        template <integral_tr integral_p>
        value_t*    operator +(integral_p value) const;
        template <integral_tr integral_p>
        value_t*    operator -(integral_p value) const;
        template <integral_tr integral_p>
        value_t*    operator +=(integral_p value);
        template <integral_tr integral_p>
        value_t*    operator -=(integral_p value);
        value_t*    operator ++();
        value_t*    operator ++(int);
        value_t*    operator --();
        value_t*    operator --(int);

        value_t*    operator ->() const;
        value_t&    operator *() const;
        template <integral_tr integral_p>
        value_t&    operator [](integral_p index) const;
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

        template <pointer_tr pointer_p>
        value_t*    Assign(pointer_p value);

        template <pointer_tr pointer_p>
        value_t*    Exchange(pointer_p value);
        template <pointer_tr pointer_a_p, pointer_tr pointer_b_p>
        value_t*    Exchange_If_Equals(pointer_a_p value, pointer_b_p target);

    public:
        operator    value_t*() const;

    public:
        value_t*    operator ()() const;

        template <pointer_tr pointer_p>
        value_t*    operator =(pointer_p value);
    };

}

#include "nkr/atomic_t.inl"
