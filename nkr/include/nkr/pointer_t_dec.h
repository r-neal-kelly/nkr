/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"

namespace nkr { namespace $pointer_t {

    template <type_tr unit_p>
    class type_sp
    {
    public:
        /// @name aliases
        /// @copydoc 
        /// @{
        using unit_t    = unit_p;
        using units_t   = unit_p*;
        /// @}

    public:
        /// @name object data
        /// @copydoc 
        /// @{
        units_t units;
        count_t unit_count;
        /// @}

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        type_sp();
        type_sp(convertible_tr<unit_t*> auto unit);
        type_sp(convertible_tr<units_t> auto units, count_t unit_count);

        type_sp(const type_sp& other);
        type_sp(volatile const type_sp& other);
        type_sp(type_sp&& other) noexcept;
        type_sp(volatile type_sp&& other) noexcept;

        type_sp&            operator =(const type_sp& other);
        volatile type_sp&   operator =(volatile const type_sp& other) volatile;
        type_sp&            operator =(type_sp&& other) noexcept;
        volatile type_sp&   operator =(volatile type_sp&& other) volatile noexcept;

        ~type_sp();
        /// @}

    public:
        /// @name casts
        /// @copydoc 
        /// @{
        operator            units_t&();
        operator            const units_t&() const;
        operator            volatile units_t&() volatile;
        operator            volatile const units_t&() volatile const;

        explicit operator   count_t&();
        explicit operator   const count_t&() const;
        explicit operator   volatile count_t&() volatile;
        explicit operator   volatile const count_t&() volatile const;
        /// @}

    public:
        /// @name operators
        /// @copydoc 
        /// @{
        units_t&                operator ()();
        const units_t&          operator ()() const;
        volatile units_t&       operator ()() volatile;
        volatile const units_t& operator ()() volatile const;
        type_sp&                operator ()(convertible_tr<unit_t*> auto unit);
        volatile type_sp&       operator ()(convertible_tr<unit_t*> auto unit) volatile;
        type_sp&                operator ()(convertible_tr<units_t> auto units, count_t unit_count);
        volatile type_sp&       operator ()(convertible_tr<units_t> auto units, count_t unit_count) volatile;

        type_sp                 operator +(integer_tr auto amount) volatile const;
        type_sp                 operator -(integer_tr auto amount) volatile const;

        type_sp&                operator +=(integer_tr auto amount);
        volatile type_sp&       operator +=(integer_tr auto amount) volatile;
        type_sp&                operator -=(integer_tr auto amount);
        volatile type_sp&       operator -=(integer_tr auto amount) volatile;

        type_sp&                operator ++();
        volatile type_sp&       operator ++() volatile;
        type_sp                 operator ++(int) volatile;
        type_sp&                operator --();
        volatile type_sp&       operator --() volatile;
        type_sp                 operator --(int) volatile;

        units_t                 operator ->() volatile const;
        unit_t&                 operator *() volatile const;
        unit_t&                 operator [](index_t index) volatile const;
        /// @}
    };

    template <non_type_tr unit_p>
    class non_type_sp
    {
    public:
        /// @name aliases
        /// @copydoc 
        /// @{
        using unit_t    = unit_p;
        using units_t   = unit_p*;
        /// @}

    public:
        /// @name object data
        /// @copydoc 
        /// @{
        units_t units;
        count_t unit_count;
        /// @}

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        non_type_sp();
        non_type_sp(convertible_tr<unit_t*> auto unit);
        non_type_sp(convertible_tr<units_t> auto units, count_t unit_count);

        non_type_sp(const non_type_sp& other);
        non_type_sp(volatile const non_type_sp& other);
        non_type_sp(non_type_sp&& other) noexcept;
        non_type_sp(volatile non_type_sp&& other) noexcept;

        non_type_sp&            operator =(const non_type_sp& other);
        volatile non_type_sp&   operator =(volatile const non_type_sp& other) volatile;
        non_type_sp&            operator =(non_type_sp&& other) noexcept;
        volatile non_type_sp&   operator =(volatile non_type_sp&& other) volatile noexcept;

        ~non_type_sp();
        /// @}

    public:
        /// @name casts
        /// @copydoc 
        /// @{
        operator            units_t&();
        operator            const units_t&() const;
        operator            volatile units_t&() volatile;
        operator            volatile const units_t&() volatile const;

        explicit operator   count_t&();
        explicit operator   const count_t&() const;
        explicit operator   volatile count_t&() volatile;
        explicit operator   volatile const count_t&() volatile const;
        /// @}

    public:
        /// @name operators
        /// @copydoc 
        /// @{
        units_t&                operator ()();
        const units_t&          operator ()() const;
        volatile units_t&       operator ()() volatile;
        volatile const units_t& operator ()() volatile const;
        non_type_sp&            operator ()(convertible_tr<unit_t*> auto unit);
        volatile non_type_sp&   operator ()(convertible_tr<unit_t*> auto unit) volatile;
        non_type_sp&            operator ()(convertible_tr<units_t> auto units, count_t unit_count);
        volatile non_type_sp&   operator ()(convertible_tr<units_t> auto units, count_t unit_count) volatile;
        /// @}
    };

}}

namespace nkr {

    /// @nosubgrouping
    /// @copydoc 
    template <any_tr unit_p>
    class pointer_t
    {
    public:
        /// @name objects
        /// @copydoc 
        /// @{
        pointer_t()                                                                     = delete;

        pointer_t(const pointer_t& other)                                               = delete;
        pointer_t(volatile const pointer_t& other)                                      = delete;
        pointer_t(pointer_t&& other) noexcept                                           = delete;
        pointer_t(volatile pointer_t&& other) noexcept                                  = delete;

        pointer_t&          operator =(const pointer_t& other)                          = delete;
        volatile pointer_t& operator =(volatile const pointer_t& other) volatile        = delete;
        pointer_t&          operator =(pointer_t&& other) noexcept                      = delete;
        volatile pointer_t& operator =(volatile pointer_t&& other) volatile noexcept    = delete;

        ~pointer_t()                                                                    = delete;
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc 
    template <type_tr unit_p>
    class pointer_t<unit_p> :
        public $pointer_t::type_sp<unit_p>
    {
    private:
        using base_t    = $pointer_t::type_sp<unit_p>;

    public:
        /// @name inherited objects
        /// @{
        using base_t::base_t;
        /// @}

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        pointer_t() = default;

        pointer_t(const pointer_t& other) = default;

        pointer_t(volatile const pointer_t& other) :
            base_t(static_cast<volatile const base_t&>(other))
        {
        }

        pointer_t(pointer_t&& other) noexcept = default;

        pointer_t(volatile pointer_t&& other) noexcept :
            base_t(static_cast<volatile base_t&&>(other))
        {
        }

        pointer_t& operator =(const pointer_t& other) = default;

        volatile pointer_t& operator =(volatile const pointer_t& other) volatile
        {
            base_t::operator =(static_cast<volatile const base_t&>(other));
            return *this;
        }

        pointer_t& operator =(pointer_t&& other) noexcept = default;

        volatile pointer_t& operator =(volatile pointer_t&& other) volatile noexcept
        {
            base_t::operator =(static_cast<volatile base_t&&>(other));
            return *this;
        }

        ~pointer_t() = default;
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc 
    template <non_type_tr unit_p>
    class pointer_t<unit_p> :
        public $pointer_t::non_type_sp<unit_p>
    {
    private:
        using base_t    = $pointer_t::non_type_sp<unit_p>;

    public:
        /// @name inherited objects
        /// @{
        using base_t::base_t;
        /// @}

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        pointer_t() = default;

        pointer_t(const pointer_t& other) = default;

        pointer_t(volatile const pointer_t& other) :
            base_t(static_cast<volatile const base_t&>(other))
        {
        }

        pointer_t(pointer_t&& other) noexcept = default;

        pointer_t(volatile pointer_t&& other) noexcept :
            base_t(static_cast<volatile base_t&&>(other))
        {
        }

        pointer_t& operator =(const pointer_t& other) = default;

        volatile pointer_t& operator =(volatile const pointer_t& other) volatile
        {
            base_t::operator =(static_cast<volatile const base_t&>(other));
            return *this;
        }

        pointer_t& operator =(pointer_t&& other) noexcept = default;

        volatile pointer_t& operator =(volatile pointer_t&& other) volatile noexcept
        {
            base_t::operator =(static_cast<volatile base_t&&>(other));
            return *this;
        }

        ~pointer_t() = default;
        /// @}
    };

}
