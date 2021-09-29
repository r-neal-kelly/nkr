/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/macros.h"
#include "nkr/traits.h"
#include "nkr/utils.h"

namespace nkr { namespace $pointer_t {

    template <any_type_tr unit_p>
    class any_type_sp
    {
    public:
        /// @name aliases
        /// @copydoc 
        /// @{
        using unit_t    = unit_p;
        using units_t   = unit_p*;
        /// @}

    private:
        static bool_t   Is_Equal_To(is_any_tr<any_type_sp> auto a, is_any_tr<any_type_sp> auto b);

    public:
        friend bool_t operator ==(is_any_tr<any_type_sp> auto a, is_any_tr<any_type_sp> auto b)
        {
            return Is_Equal_To(a, b);
        }

        friend bool_t operator !=(is_any_tr<any_type_sp> auto a, is_any_tr<any_type_sp> auto b)
        {
            return !Is_Equal_To(a, b);
        }

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
        any_type_sp();

        any_type_sp(convertible_tr<unit_t*> auto unit);
        any_type_sp(convertible_tr<units_t> auto units, count_t unit_count);

        any_type_sp(const any_type_sp& other);
        any_type_sp(const volatile any_type_sp& other);
        any_type_sp(any_type_sp&& other) noexcept;
        any_type_sp(volatile any_type_sp&& other) noexcept;

        any_type_sp&            operator =(const any_type_sp& other);
        volatile any_type_sp&   operator =(const any_type_sp& other) volatile;
        any_type_sp&            operator =(const volatile any_type_sp& other);
        volatile any_type_sp&   operator =(const volatile any_type_sp& other) volatile;
        any_type_sp&            operator =(any_type_sp&& other) noexcept;
        volatile any_type_sp&   operator =(any_type_sp&& other) volatile noexcept;
        any_type_sp&            operator =(is_just_volatile_tr<any_type_sp> auto&& other) noexcept;
        volatile any_type_sp&   operator =(is_just_volatile_tr<any_type_sp> auto&& other) volatile noexcept;

        ~any_type_sp();
        /// @}

    public:
        unit_t*&                Unit();
        unit_t* const&          Unit() const;
        unit_t* volatile&       Unit() volatile;
        unit_t* const volatile& Unit() const volatile;

        units_t&                Units();
        const units_t&          Units() const;
        volatile units_t&       Units() volatile;
        const volatile units_t& Units() const volatile;

        count_t&                Unit_Count();
        const count_t&          Unit_Count() const;
        volatile count_t&       Unit_Count() volatile;
        const volatile count_t& Unit_Count() const volatile;

    public:
        /// @name casts
        /// @copydoc 
        /// @{
        operator    units_t&();
        operator    const units_t&() const;
        operator    volatile units_t&() volatile;
        operator    const volatile units_t&() const volatile;
        /// @}

    public:
        /// @name operators
        /// @copydoc 
        /// @{
        units_t&                operator ()();
        const units_t&          operator ()() const;
        volatile units_t&       operator ()() volatile;
        const volatile units_t& operator ()() const volatile;
        any_type_sp&            operator ()(convertible_tr<unit_t*> auto unit);
        volatile any_type_sp&   operator ()(convertible_tr<unit_t*> auto unit) volatile;
        any_type_sp&            operator ()(convertible_tr<units_t> auto units, count_t unit_count);
        volatile any_type_sp&   operator ()(convertible_tr<units_t> auto units, count_t unit_count) volatile;

        any_type_sp             operator +(integer_tr auto amount) const volatile;
        any_type_sp             operator -(integer_tr auto amount) const volatile;

        any_type_sp&            operator +=(integer_tr auto amount);
        volatile any_type_sp&   operator +=(integer_tr auto amount) volatile;
        any_type_sp&            operator -=(integer_tr auto amount);
        volatile any_type_sp&   operator -=(integer_tr auto amount) volatile;

        any_type_sp&            operator ++();
        volatile any_type_sp&   operator ++() volatile;
        any_type_sp             operator ++(int) volatile;
        any_type_sp&            operator --();
        volatile any_type_sp&   operator --() volatile;
        any_type_sp             operator --(int) volatile;

        units_t                 operator ->() const volatile;
        unit_t&                 operator *() const volatile;
        unit_t&                 operator [](index_t index) const volatile;
        /// @}

    public:
        /// @name none_t interface
        /// @copydoc 
        /// @{
        any_type_sp(none_t);                                        ///< @copydoc 

        any_type_sp&            operator =(none_t);                 ///< @copydoc 
        volatile any_type_sp&   operator =(none_t) volatile;        ///< @copydoc 

        bool_t                  operator ==(none_t) const;          ///< @copydoc 
        bool_t                  operator ==(none_t) const volatile; ///< @copydoc 
        bool_t                  operator !=(none_t) const;          ///< @copydoc 
        bool_t                  operator !=(none_t) const volatile; ///< @copydoc 
        /// @}
    };

    template <any_non_type_tr unit_p>
    class any_non_type_sp
    {
    public:
        /// @name aliases
        /// @copydoc 
        /// @{
        using unit_t    = unit_p;
        using units_t   = unit_p*;
        /// @}

    private:
        static bool_t   Is_Equal_To(is_any_tr<any_non_type_sp> auto a, is_any_tr<any_non_type_sp> auto b);

    public:
        friend bool_t operator ==(is_any_tr<any_non_type_sp> auto a, is_any_tr<any_non_type_sp> auto b)
        {
            return Is_Equal_To(a, b);
        }

        friend bool_t operator !=(is_any_tr<any_non_type_sp> auto a, is_any_tr<any_non_type_sp> auto b)
        {
            return !Is_Equal_To(a, b);
        }

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
        any_non_type_sp();
        any_non_type_sp(convertible_tr<unit_t*> auto unit);
        any_non_type_sp(convertible_tr<units_t> auto units, count_t unit_count);

        any_non_type_sp(const any_non_type_sp& other);
        any_non_type_sp(const volatile any_non_type_sp& other);
        any_non_type_sp(any_non_type_sp&& other) noexcept;
        any_non_type_sp(volatile any_non_type_sp&& other) noexcept;

        any_non_type_sp&            operator =(const any_non_type_sp& other);
        volatile any_non_type_sp&   operator =(const any_non_type_sp& other) volatile;
        any_non_type_sp&            operator =(const volatile any_non_type_sp& other);
        volatile any_non_type_sp&   operator =(const volatile any_non_type_sp& other) volatile;
        any_non_type_sp&            operator =(any_non_type_sp&& other) noexcept;
        volatile any_non_type_sp&   operator =(any_non_type_sp&& other) volatile noexcept;
        any_non_type_sp&            operator =(is_just_volatile_tr<any_non_type_sp> auto&& other) noexcept;
        volatile any_non_type_sp&   operator =(is_just_volatile_tr<any_non_type_sp> auto&& other) volatile noexcept;

        ~any_non_type_sp();
        /// @}

    public:
        unit_t*&                Unit();
        unit_t* const&          Unit() const;
        unit_t* volatile&       Unit() volatile;
        unit_t* const volatile& Unit() const volatile;

        units_t&                Units();
        const units_t&          Units() const;
        volatile units_t&       Units() volatile;
        const volatile units_t& Units() const volatile;

        count_t&                Unit_Count();
        const count_t&          Unit_Count() const;
        volatile count_t&       Unit_Count() volatile;
        const volatile count_t& Unit_Count() const volatile;

    public:
        /// @name casts
        /// @copydoc 
        /// @{
        operator    units_t&();
        operator    const units_t&() const;
        operator    volatile units_t&() volatile;
        operator    const volatile units_t&() const volatile;
        /// @}

    public:
        /// @name operators
        /// @copydoc 
        /// @{
        units_t&                    operator ()();
        const units_t&              operator ()() const;
        volatile units_t&           operator ()() volatile;
        const volatile units_t&     operator ()() const volatile;
        any_non_type_sp&            operator ()(convertible_tr<unit_t*> auto unit);
        volatile any_non_type_sp&   operator ()(convertible_tr<unit_t*> auto unit) volatile;
        any_non_type_sp&            operator ()(convertible_tr<units_t> auto units, count_t unit_count);
        volatile any_non_type_sp&   operator ()(convertible_tr<units_t> auto units, count_t unit_count) volatile;
        /// @}

    public:
        /// @name none_t interface
        /// @copydoc 
        /// @{
        any_non_type_sp(none_t);                                        ///< @copydoc 

        any_non_type_sp&            operator =(none_t);                 ///< @copydoc 
        volatile any_non_type_sp&   operator =(none_t) volatile;        ///< @copydoc 

        bool_t                      operator ==(none_t) const;          ///< @copydoc 
        bool_t                      operator ==(none_t) const volatile; ///< @copydoc 
        bool_t                      operator !=(none_t) const;          ///< @copydoc 
        bool_t                      operator !=(none_t) const volatile; ///< @copydoc 
        /// @}
    };

}}

namespace nkr {

    /// @nosubgrouping
    /// @copydoc 
    template <typename unit_p>
    class pointer_t
    {
    public:
        friend bool_t   operator ==(is_any_tr<pointer_t> auto a, is_any_tr<pointer_t> auto b)   = delete;
        friend bool_t   operator !=(is_any_tr<pointer_t> auto a, is_any_tr<pointer_t> auto b)   = delete;

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        pointer_t()                                                                                     = delete;

        pointer_t(const pointer_t& other)                                                               = delete;
        pointer_t(const volatile pointer_t& other)                                                      = delete;
        pointer_t(pointer_t&& other) noexcept                                                           = delete;
        pointer_t(volatile pointer_t&& other) noexcept                                                  = delete;

        pointer_t&          operator =(const pointer_t& other)                                          = delete;
        volatile pointer_t& operator =(const pointer_t& other) volatile                                 = delete;
        pointer_t&          operator =(const volatile pointer_t& other)                                 = delete;
        volatile pointer_t& operator =(const volatile pointer_t& other) volatile                        = delete;
        pointer_t&          operator =(pointer_t&& other) noexcept                                      = delete;
        volatile pointer_t& operator =(pointer_t&& other) volatile noexcept                             = delete;
        pointer_t&          operator =(is_just_volatile_tr<pointer_t> auto&& other) noexcept            = delete;
        volatile pointer_t& operator =(is_just_volatile_tr<pointer_t> auto&& other) volatile noexcept   = delete;

        ~pointer_t()                                                                                    = delete;
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc 
    template <any_type_tr unit_p>
    class pointer_t<unit_p> :
        public $pointer_t::any_type_sp<unit_p>
    {
    public:
        using base_t    = $pointer_t::any_type_sp<unit_p>;

    public:
        friend bool_t operator ==(is_any_tr<pointer_t> auto a, is_any_tr<pointer_t> auto b)
        {
            return operator ==(a.Base(), b.Base());
        }

        friend bool_t operator !=(is_any_tr<pointer_t> auto a, is_any_tr<pointer_t> auto b)
        {
            return operator !=(a.Base(), b.Base());
        }

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(pointer_t, base_t);
        /// @}

    private:
        nkr_DEFINE_INHERITANCE_WRAPPER_BASE_ACCESSORS(Base, base_t);
    };

    /// @nosubgrouping
    /// @copydoc 
    template <any_non_type_tr unit_p>
    class pointer_t<unit_p> :
        public $pointer_t::any_non_type_sp<unit_p>
    {
    public:
        using base_t    = $pointer_t::any_non_type_sp<unit_p>;

    public:
        friend bool_t operator ==(is_any_tr<pointer_t> auto a, is_any_tr<pointer_t> auto b)
        {
            return operator ==(a.Base(), b.Base());
        }

        friend bool_t operator !=(is_any_tr<pointer_t> auto a, is_any_tr<pointer_t> auto b)
        {
            return operator !=(a.Base(), b.Base());
        }

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(pointer_t, base_t);
        /// @}

    private:
        nkr_DEFINE_INHERITANCE_WRAPPER_BASE_ACCESSORS(Base, base_t);
    };

}
