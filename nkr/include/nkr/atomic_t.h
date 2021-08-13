/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsic.h"
#include "nkr/traits.h"

namespace nkr {

    template <atomicable_tr value_p = word_t>
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
        value_t Exchange(integral_p with);

    public:
        explicit operator   bool_t() const;
        operator            value_t() const;

    public:
        bool_t  operator !() const;

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
        value_t Exchange(value_t with);

    public:
        operator    value_t() const;

    public:
        value_t operator !() const;

        value_t operator ()() const;

        value_t operator =(value_t other);
    };

    template <atomicable_tr value_p>
    class atomic_t<value_p*>
    {
    public:
        using value_t   = value_p;
        using values_t  = value_p*;

    private:
        volatile values_t   values;

    public:
        atomic_t();
        atomic_t(values_t values);
        atomic_t(const atomic_t& other);
        atomic_t(atomic_t&& other) noexcept;
        atomic_t& operator =(const atomic_t& other);
        atomic_t& operator =(atomic_t&& other) noexcept;
        ~atomic_t();

    public:
        values_t    Access() const;
        template <pointer_tr pointer_p>
        values_t    Exchange(pointer_p with);

    public:
        explicit operator   bool_t() const;
        operator            values_t() const;

    public:
        bool_t      operator !() const;

        values_t    operator ()() const;

        template <pointer_tr pointer_p>
        values_t    operator =(pointer_p other);

        template <integral_tr integral_p>
        values_t    operator +(integral_p other) const;
        template <integral_tr integral_p>
        values_t    operator -(integral_p other) const;
        template <integral_tr integral_p>
        values_t    operator +=(integral_p other);
        template <integral_tr integral_p>
        values_t    operator -=(integral_p other);
        values_t    operator ++();
        values_t    operator ++(int);
        values_t    operator --();
        values_t    operator --(int);

        values_t    operator ->() const;
        value_t&    operator *() const;
        value_t&    operator [](index_t index) const;
    };

}

#include "nkr/atomic_t.inl"
