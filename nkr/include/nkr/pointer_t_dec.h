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
        /// @}

    protected:
        /// @name object data
        /// @copydoc 
        /// @{
        unit_t* units;
        count_t unit_count;
        /// @}

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        type_sp();
        type_sp(convertible_tr<unit_t*> auto unit);
        type_sp(convertible_tr<unit_t*> auto units, count_t unit_count);
        type_sp(const type_sp& other);
        type_sp(type_sp&& other) noexcept;
        type_sp& operator =(const type_sp& other);
        type_sp& operator =(type_sp&& other) noexcept;
        ~type_sp();
        /// @}

    public:
        /// @name methods
        /// @copydoc 
        /// @{
        unit_t* Units() volatile const;
        count_t Unit_Count() volatile const;
        /// @}

    public:
        /// @name casts
        /// @copydoc 
        /// @{
        operator            unit_t*() volatile const;
        explicit operator   count_t() volatile const;
        /// @}

    public:
        /// @name operators
        /// @copydoc 
        /// @{
        unit_t*     operator ()() volatile const;
        type_sp&    operator ()(convertible_tr<unit_t*> auto unit);
        type_sp&    operator ()(convertible_tr<unit_t*> auto units, count_t unit_count);

        type_sp     operator +(integer_tr auto amount) volatile const;
        type_sp     operator -(integer_tr auto amount) volatile const;

        type_sp&    operator +=(integer_tr auto amount);
        type_sp&    operator -=(integer_tr auto amount);

        type_sp&    operator ++();
        type_sp     operator ++(int);
        type_sp&    operator --();
        type_sp     operator --(int);

        unit_t*     operator ->() const;
        unit_t&     operator *() const;
        unit_t&     operator [](index_t index) const;
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
        /// @}

    protected:
        /// @name object data
        /// @copydoc 
        /// @{
        unit_t* units;
        count_t unit_count;
        /// @}

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        non_type_sp();
        non_type_sp(convertible_tr<unit_t*> auto unit);
        non_type_sp(convertible_tr<unit_t*> auto units, count_t unit_count);
        non_type_sp(const non_type_sp& other);
        non_type_sp(non_type_sp&& other) noexcept;
        non_type_sp& operator =(const non_type_sp& other);
        non_type_sp& operator =(non_type_sp&& other) noexcept;
        ~non_type_sp();
        /// @}

    public:
        /// @name methods
        /// @copydoc 
        /// @{
        unit_t* Units() volatile const;
        count_t Unit_Count() volatile const;
        /// @}

    public:
        /// @name casts
        /// @copydoc 
        /// @{
        operator            unit_t*() volatile const;
        explicit operator   count_t() volatile const;
        /// @}

    public:
        /// @name operators
        /// @copydoc 
        /// @{
        unit_t*         operator ()() volatile const;
        non_type_sp&    operator ()(convertible_tr<unit_t*> auto unit);
        non_type_sp&    operator ()(convertible_tr<unit_t*> auto units, count_t unit_count);
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
        pointer_t()                                     = delete;
        pointer_t(const pointer_t& other)               = delete;
        pointer_t(pointer_t&& other) noexcept           = delete;
        pointer_t& operator =(const pointer_t& other)   = delete;
        pointer_t& operator =(pointer_t&& other)        = delete;
        ~pointer_t()                                    = delete;
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc 
    template <type_tr unit_p>
    class pointer_t<unit_p> :
        public $pointer_t::type_sp<unit_p>
    {
    public:
        /// @name inherited objects
        /// @{
        using $pointer_t::type_sp<unit_p>::type_sp;
        /// @}

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        pointer_t()                                     = default;
        pointer_t(const pointer_t& other)               = default;
        pointer_t(pointer_t&& other) noexcept           = default;
        pointer_t& operator =(const pointer_t& other)   = default;
        pointer_t& operator =(pointer_t&& other)        = default;
        ~pointer_t()                                    = default;
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc 
    template <non_type_tr unit_p>
    class pointer_t<unit_p> :
        public $pointer_t::non_type_sp<unit_p>
    {
    public:
        /// @name inherited objects
        /// @{
        using $pointer_t::non_type_sp<unit_p>::non_type_sp;
        /// @}

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        pointer_t()                                     = default;
        pointer_t(const pointer_t& other)               = default;
        pointer_t(pointer_t&& other) noexcept           = default;
        pointer_t& operator =(const pointer_t& other)   = default;
        pointer_t& operator =(pointer_t&& other)        = default;
        ~pointer_t()                                    = default;
        /// @}
    };

}
