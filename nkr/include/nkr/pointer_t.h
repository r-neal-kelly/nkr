/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"

namespace nkr {

    /// @nosubgrouping
    /// @copydoc 
    template <type_tr unit_p>
    class pointer_t
    {
    public:
        /// @name aliases
        /// @copydoc 
        /// @{
        using unit_t    = unit_p;
        using units_t   = unit_p*;
        /// @}

    protected:
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
        pointer_t();
        pointer_t(unit_t* unit);
        pointer_t(units_t units, count_t unit_count);
        pointer_t(const pointer_t& other);
        pointer_t(pointer_t&& other) noexcept;
        pointer_t& operator =(unit_t* unit);
        pointer_t& operator =(const pointer_t& other);
        pointer_t& operator =(pointer_t&& other) noexcept;
        ~pointer_t();
        /// @}

    public:
        /// @name methods
        /// @copydoc 
        /// @{
        units_t Units() volatile const;
        count_t Unit_Count() volatile const;
        /// @}

    public:
        /// @name casts
        /// @copydoc 
        /// @{
        operator    units_t() volatile const;
        /// @}

    public:
        /// @name operators
        /// @copydoc 
        /// @{
        units_t     operator ()() volatile const;
        pointer_t&  operator ()(unit_t* unit);
        pointer_t&  operator ()(units_t units, count_t unit_count);

        pointer_t   operator +(integer_tr auto amount);
        pointer_t   operator -(integer_tr auto amount);

        pointer_t&  operator +=(integer_tr auto amount);
        pointer_t&  operator -=(integer_tr auto amount);

        pointer_t&  operator ++();
        pointer_t   operator ++(int);
        pointer_t&  operator --();
        pointer_t   operator --(int);

        units_t     operator ->() const;
        unit_t&     operator *() const;
        unit_t&     operator [](index_t index) const;
        /// @}
    };

}

#include "nkr/pointer_t.inl"
