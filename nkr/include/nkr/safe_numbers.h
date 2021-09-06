/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"

namespace nkr {

    template <integer_signed_tr integer_p>
    class signed_positive_t
    {
    public:
        /// @name aliases
        /// @copydoc 
        /// @{
        using value_t   = integer_p;
        /// @}

    public:
        /// @name static data
        /// @copydoc 
        /// @{
        static const value_t    MIN = 0;
        static const value_t    MAX = std::numeric_limits<value_t>::max();
        static const u64_t      TOTAL = static_cast<u64_t>(std::numeric_limits<value_t>::max()) + 1;
        /// @}

    public:
        /// @name static functions
        /// @copydoc 
        /// @{
        static value_t  To_Value(integer_tr auto from);
        /// @}

    protected:
        /// @name object data
        /// @copydoc 
        /// @{
        value_t value;
        /// @}

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        signed_positive_t();
        signed_positive_t(integer_tr auto other);
        signed_positive_t(const signed_positive_t& other);
        signed_positive_t(volatile const signed_positive_t& other);
        signed_positive_t(signed_positive_t&& other) noexcept;
        signed_positive_t(volatile signed_positive_t&& other) noexcept;
        signed_positive_t& operator =(integer_tr auto other);
        volatile signed_positive_t& operator =(integer_tr auto other) volatile;
        signed_positive_t& operator =(const signed_positive_t& other);
        volatile signed_positive_t& operator =(volatile const signed_positive_t& other) volatile;
        signed_positive_t& operator =(signed_positive_t&& other) noexcept;
        volatile signed_positive_t& operator =(volatile signed_positive_t&& other) volatile noexcept;
        ~signed_positive_t();
        /// @}

    public:
        /// @name casts
        /// @copydoc 
        /// @{
        operator    value_t() volatile const;
        /// @}

    public:
        /// @name operators
        /// @copydoc 
        /// @{
        signed_positive_t           operator +() volatile const                         = delete;
        signed_positive_t           operator -() volatile const                         = delete;
        signed_positive_t           operator +(integer_tr auto other) volatile const;
        signed_positive_t           operator -(integer_tr auto other) volatile const;
        signed_positive_t           operator *(integer_tr auto other) volatile const;
        signed_positive_t           operator /(integer_tr auto other) volatile const;
        signed_positive_t           operator %(integer_tr auto other) volatile const;

        signed_positive_t           operator ~() volatile const;
        signed_positive_t           operator |(integer_tr auto other) volatile const;
        signed_positive_t           operator &(integer_tr auto other) volatile const;
        signed_positive_t           operator ^(integer_tr auto other) volatile const;
        signed_positive_t           operator <<(integer_tr auto other) volatile const;
        signed_positive_t           operator >>(integer_tr auto other) volatile const;

        signed_positive_t&          operator +=(integer_tr auto other);
        volatile signed_positive_t& operator +=(integer_tr auto other) volatile;
        signed_positive_t&          operator -=(integer_tr auto other);
        volatile signed_positive_t& operator -=(integer_tr auto other) volatile;
        signed_positive_t&          operator *=(integer_tr auto other);
        volatile signed_positive_t& operator *=(integer_tr auto other) volatile;
        signed_positive_t&          operator /=(integer_tr auto other);
        volatile signed_positive_t& operator /=(integer_tr auto other) volatile;
        signed_positive_t&          operator %=(integer_tr auto other);
        volatile signed_positive_t& operator %=(integer_tr auto other) volatile;

        signed_positive_t&          operator |=(integer_tr auto other);
        volatile signed_positive_t& operator |=(integer_tr auto other) volatile;
        signed_positive_t&          operator &=(integer_tr auto other);
        volatile signed_positive_t& operator &=(integer_tr auto other) volatile;
        signed_positive_t&          operator ^=(integer_tr auto other);
        volatile signed_positive_t& operator ^=(integer_tr auto other) volatile;
        signed_positive_t&          operator <<=(integer_tr auto other);
        volatile signed_positive_t& operator <<=(integer_tr auto other) volatile;
        signed_positive_t&          operator >>=(integer_tr auto other);
        volatile signed_positive_t& operator >>=(integer_tr auto other) volatile;

        signed_positive_t&          operator ++();
        volatile signed_positive_t& operator ++() volatile;
        signed_positive_t           operator ++(int) volatile;
        signed_positive_t&          operator --();
        volatile signed_positive_t& operator --() volatile;
        signed_positive_t           operator --(int) volatile;
        /// @}
    };

    template <integer_signed_tr integer_p>
    class signed_negative_t
    {
    public:
        /// @name aliases
        /// @copydoc 
        /// @{
        using value_t   = integer_p;
        /// @}

    public:
        /// @name static data
        /// @copydoc 
        /// @{
        static const value_t    MIN = std::numeric_limits<value_t>::lowest() + 1;
        static const value_t    MAX = 0;
        static const u64_t      TOTAL = static_cast<u64_t>(std::numeric_limits<value_t>::max()) + 1;
        /// @}

    public:
        /// @name static functions
        /// @copydoc 
        /// @{
        static value_t  To_Value(integer_tr auto from);
        /// @}

    protected:
        /// @name object data
        /// @copydoc 
        /// @{
        value_t value;
        /// @}

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        signed_negative_t();
        signed_negative_t(integer_tr auto other);
        signed_negative_t(const signed_negative_t& other);
        signed_negative_t(volatile const signed_negative_t& other);
        signed_negative_t(signed_negative_t&& other) noexcept;
        signed_negative_t(volatile signed_negative_t&& other) noexcept;
        signed_negative_t& operator =(integer_tr auto other);
        volatile signed_negative_t& operator =(integer_tr auto other) volatile;
        signed_negative_t& operator =(const signed_negative_t& other);
        volatile signed_negative_t& operator =(volatile const signed_negative_t& other) volatile;
        signed_negative_t& operator =(signed_negative_t&& other) noexcept;
        volatile signed_negative_t& operator =(volatile signed_negative_t&& other) volatile noexcept;
        ~signed_negative_t();
        /// @}

    public:
        /// @name casts
        /// @copydoc 
        /// @{
        operator    value_t() volatile const;
        /// @}

    public:
        /// @name operators
        /// @copydoc 
        /// @{
        signed_negative_t           operator +() volatile const                         = delete;
        signed_negative_t           operator -() volatile const                         = delete;
        signed_negative_t           operator +(integer_tr auto other) volatile const;
        signed_negative_t           operator -(integer_tr auto other) volatile const;
        signed_negative_t           operator *(integer_tr auto other) volatile const;
        signed_negative_t           operator /(integer_tr auto other) volatile const;
        signed_negative_t           operator %(integer_tr auto other) volatile const;

        signed_negative_t           operator ~() volatile const;
        signed_negative_t           operator |(integer_tr auto other) volatile const;
        signed_negative_t           operator &(integer_tr auto other) volatile const;
        signed_negative_t           operator ^(integer_tr auto other) volatile const;
        signed_negative_t           operator <<(integer_tr auto other) volatile const;
        signed_negative_t           operator >>(integer_tr auto other) volatile const;

        signed_negative_t&          operator +=(integer_tr auto other);
        volatile signed_negative_t& operator +=(integer_tr auto other) volatile;
        signed_negative_t&          operator -=(integer_tr auto other);
        volatile signed_negative_t& operator -=(integer_tr auto other) volatile;
        signed_negative_t&          operator *=(integer_tr auto other);
        volatile signed_negative_t& operator *=(integer_tr auto other) volatile;
        signed_negative_t&          operator /=(integer_tr auto other);
        volatile signed_negative_t& operator /=(integer_tr auto other) volatile;
        signed_negative_t&          operator %=(integer_tr auto other);
        volatile signed_negative_t& operator %=(integer_tr auto other) volatile;

        signed_negative_t&          operator |=(integer_tr auto other);
        volatile signed_negative_t& operator |=(integer_tr auto other) volatile;
        signed_negative_t&          operator &=(integer_tr auto other);
        volatile signed_negative_t& operator &=(integer_tr auto other) volatile;
        signed_negative_t&          operator ^=(integer_tr auto other);
        volatile signed_negative_t& operator ^=(integer_tr auto other) volatile;
        signed_negative_t&          operator <<=(integer_tr auto other);
        volatile signed_negative_t& operator <<=(integer_tr auto other) volatile;
        signed_negative_t&          operator >>=(integer_tr auto other);
        volatile signed_negative_t& operator >>=(integer_tr auto other) volatile;

        signed_negative_t&          operator ++();
        volatile signed_negative_t& operator ++() volatile;
        signed_negative_t           operator ++(int) volatile;
        signed_negative_t&          operator --();
        volatile signed_negative_t& operator --() volatile;
        signed_negative_t           operator --(int) volatile;
        /// @}
    };

    using sp8_t     = signed_positive_t<s8_t>;
    using sp16_t    = signed_positive_t<s16_t>;
    using sp32_t    = signed_positive_t<s32_t>;
    using sp64_t    = signed_positive_t<s64_t>;

    using sn8_t     = signed_negative_t<s8_t>;
    using sn16_t    = signed_negative_t<s16_t>;
    using sn32_t    = signed_negative_t<s32_t>;
    using sn64_t    = signed_negative_t<s64_t>;

}

#include "safe_numbers.inl"