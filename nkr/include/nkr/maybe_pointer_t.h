/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/maybe_t.h"

namespace nkr {

    /*
    template <typename T>
    class none_t<T*>
    {
    public:
        using value_t   = T;
        using pointer_t = T*;

    public:
        none_t();
        none_t(const none_t& other);
        none_t(none_t&& other) noexcept;
        none_t& operator =(const none_t& other);
        none_t& operator =(none_t&& other) noexcept;
        ~none_t();

    public:
        explicit operator   bool_t() const;

        operator            pointer_t();
        operator            const pointer_t() const;

    public:
        bool_t          operator !() const;

        pointer_t       operator ()();
        const pointer_t operator ()() const;
    };

    template <typename T>
    class maybe_t<T*>
    {
    public:
        using value_t   = T;
        using pointer_t = T*;

    public:
        pointer_t   pointer;

    public:
        maybe_t();
        maybe_t(pointer_t pointer);
        maybe_t(const maybe_t& other);
        maybe_t(maybe_t&& other) noexcept;
        maybe_t& operator =(const maybe_t& other);
        maybe_t& operator =(maybe_t&& other) noexcept;
        maybe_t& operator =(pointer_t other);
        ~maybe_t();

    public:
        explicit operator   bool_t() const;

        operator            pointer_t&();
        operator            const pointer_t&() const;

    public:
        bool_t              operator !() const;

        pointer_t&          operator ()();
        const pointer_t&    operator ()() const;

        pointer_t           operator ->();
        const pointer_t     operator ->() const;

        pointer_t*          operator &();
        const pointer_t*    operator &() const;

        value_t&            operator *();
        const value_t&      operator *() const;

        value_t&            operator [](size_t index);
        const value_t&      operator [](size_t index) const;
    };

    template <typename T>
    class some_t<T*>
    {
    public:
        using value_t   = T;
        using pointer_t = T*;

    public:
        pointer_t   pointer;

    public:
        some_t() = delete;

        some_t(pointer_t pointer);
        some_t(const some_t& other);
        some_t(some_t&& other) noexcept;
        some_t& operator =(const some_t& other);
        some_t& operator =(some_t&& other) noexcept;
        some_t& operator =(pointer_t other);
        ~some_t();

    public:
        explicit operator   bool_t() const;

        operator            pointer_t&();
        operator            const pointer_t&() const;

    public:
        bool_t              operator !() const;

        pointer_t&          operator ()();
        const pointer_t&    operator ()() const;

        pointer_t           operator ->();
        const pointer_t     operator ->() const;

        pointer_t*          operator &();
        const pointer_t*    operator &() const;

        value_t&            operator *();
        const value_t&      operator *() const;

        value_t&            operator [](size_t index);
        const value_t&      operator [](size_t index) const;
    };
    */

}

#include "nkr/maybe_pointer_t.inl"
