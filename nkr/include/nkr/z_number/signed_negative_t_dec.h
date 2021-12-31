/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/z_intrinsics.h"
#include "nkr/z_traits.h"

namespace nkr {

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

        signed_negative_t(integer_tr auto value);

        signed_negative_t(const signed_negative_t& other);
        signed_negative_t(const volatile signed_negative_t& other);
        signed_negative_t(signed_negative_t&& other) noexcept;
        signed_negative_t(volatile signed_negative_t&& other) noexcept;

        signed_negative_t&          operator =(const signed_negative_t& other);
        volatile signed_negative_t& operator =(const signed_negative_t& other) volatile;
        signed_negative_t&          operator =(const volatile signed_negative_t& other);
        volatile signed_negative_t& operator =(const volatile signed_negative_t& other) volatile;
        signed_negative_t&          operator =(signed_negative_t&& other) noexcept;
        volatile signed_negative_t& operator =(signed_negative_t&& other) volatile noexcept;
        signed_negative_t&          operator =(is_just_volatile_tr<signed_negative_t> auto&& other) noexcept;
        volatile signed_negative_t& operator =(is_just_volatile_tr<signed_negative_t> auto&& other) volatile noexcept;

        ~signed_negative_t();
        /// @}

    public:
        /// @name casts
        /// @copydoc 
        /// @{
        operator    value_t() const volatile;
        /// @}

    public:
        /// @name operators
        /// @copydoc 
        /// @{
        auto                        operator +() const volatile                         = delete;
        auto                        operator -() const volatile                         = delete;
        auto                        operator +(integer_tr auto other) const volatile;
        auto                        operator -(integer_tr auto other) const volatile;
        auto                        operator *(integer_tr auto other) const volatile;
        auto                        operator /(integer_tr auto other) const volatile;
        auto                        operator %(integer_tr auto other) const volatile;

        auto                        operator ~() const volatile;
        auto                        operator |(integer_tr auto other) const volatile;
        auto                        operator &(integer_tr auto other) const volatile;
        auto                        operator ^(integer_tr auto other) const volatile;
        auto                        operator <<(integer_tr auto other) const volatile   = delete;
        auto                        operator >>(integer_tr auto other) const volatile;

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
        signed_negative_t&          operator <<=(integer_tr auto other)                 = delete;
        volatile signed_negative_t& operator <<=(integer_tr auto other) volatile        = delete;
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

    using sn8_t     = signed_negative_t<s8_t>;
    using sn16_t    = signed_negative_t<s16_t>;
    using sn32_t    = signed_negative_t<s32_t>;
    using sn64_t    = signed_negative_t<s64_t>;

}
