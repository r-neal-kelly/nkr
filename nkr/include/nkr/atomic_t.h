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
        value_t Assign(integral_p with);
        template <integral_tr integral_p>
        value_t Exchange_Assign(integral_p with);
        template <integral_tr integral_a_p, integral_tr integral_b_p>
        value_t Exchange_Assign_If_Equals(integral_a_p with, integral_b_p target);

        template <integral_tr integral_p>
        value_t Add(integral_p with);
        template <integral_tr integral_p>
        value_t Exchange_Add(integral_p with);
        template <integral_tr integral_p>
        value_t Subtract(integral_p with);
        template <integral_tr integral_p>
        value_t Exchange_Subtract(integral_p with);

        template <integral_tr integral_p>
        value_t Or(integral_p with);
        template <integral_tr integral_p>
        value_t Exchange_Or(integral_p with);
        template <integral_tr integral_p>
        value_t And(integral_p with);
        template <integral_tr integral_p>
        value_t Exchange_And(integral_p with);
        template <integral_tr integral_p>
        value_t Xor(integral_p with);
        template <integral_tr integral_p>
        value_t Exchange_Xor(integral_p with);

    public:
        operator    value_t() const;

    public:
        value_t operator ()() const;

        template <integral_tr integral_p>
        value_t operator =(integral_p other);

        template <integral_tr integral_p>
        value_t operator +(integral_p other) const;
        template <integral_tr integral_p>
        value_t operator -(integral_p other) const;
        template <integral_tr integral_p>
        value_t operator +=(integral_p other);
        template <integral_tr integral_p>
        value_t operator -=(integral_p other);
        value_t operator ++();
        value_t operator ++(int);
        value_t operator --();
        value_t operator --(int);

        value_t operator ~() const;
        template <integral_tr integral_p>
        value_t operator |(integral_p other) const;
        template <integral_tr integral_p>
        value_t operator &(integral_p other) const;
        template <integral_tr integral_p>
        value_t operator ^(integral_p other) const;
        template <integral_tr integral_p>
        value_t operator |=(integral_p other);
        template <integral_tr integral_p>
        value_t operator &=(integral_p other);
        template <integral_tr integral_p>
        value_t operator ^=(integral_p other);

    public:
        static_assert(std::is_integral<value_t>::value &&
                      (sizeof(value_t) <= sizeof(word_t)),
                      "invalid atomic value_t.");
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

        value_t Assign(value_t with);
        value_t Exchange_Assign(value_t with);
        value_t Exchange_Assign_If_Equals(value_t with, value_t target);

    public:
        operator    value_t() const;

    public:
        value_t operator ()() const;

        value_t operator =(value_t other);
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

        template <pointer_tr pointer_p>
        value_t*    Assign(pointer_p with);
        template <pointer_tr pointer_p>
        value_t*    Exchange_Assign(pointer_p with);
        template <pointer_tr pointer_a_p, pointer_tr pointer_b_p>
        value_t*    Exchange_Assign_If_Equals(pointer_a_p with, pointer_b_p target);

        template <integral_tr integral_p>
        value_t*    Add(integral_p with);
        template <integral_tr integral_p>
        value_t*    Exchange_Add(integral_p with);
        template <integral_tr integral_p>
        value_t*    Subtract(integral_p with);
        template <integral_tr integral_p>
        value_t*    Exchange_Subtract(integral_p with);

    public:
        operator    value_t*() const;

    public:
        value_t*    operator ()() const;

        template <pointer_tr pointer_p>
        value_t*    operator =(pointer_p other);

        template <integral_tr integral_p>
        value_t*    operator +(integral_p other) const;
        template <integral_tr integral_p>
        value_t*    operator -(integral_p other) const;
        template <integral_tr integral_p>
        value_t*    operator +=(integral_p other);
        template <integral_tr integral_p>
        value_t*    operator -=(integral_p other);
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
        value_t*    Assign(pointer_p with);
        template <pointer_tr pointer_p>
        value_t*    Exchange_Assign(pointer_p with);
        template <pointer_tr pointer_a_p, pointer_tr pointer_b_p>
        value_t*    Exchange_Assign_If_Equals(pointer_a_p with, pointer_b_p target);

    public:
        operator    value_t*() const;

    public:
        value_t*    operator ()() const;

        template <pointer_tr pointer_p>
        value_t*    operator =(pointer_p other);
    };

}

#include "nkr/atomic_t.inl"
