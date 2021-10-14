/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/traits.h"

#include "nkr/enumeration/types_t.h"

namespace nkr { namespace enumeration {

    template <integer_signed_tr integer_p, integer_p none_p = 0>
    class errors_t
    {
    public:
        using value_t           = integer_p;
        using actual_value_t    = types_t<integer_p, none_p>;

    public:
        static constexpr value_t    NONE    = actual_value_t::NONE;

    private:
        mutable bool_t  has_been_checked;
        actual_value_t  value;

    public:
        errors_t();

        errors_t(value_t value);
        errors_t(std_bool_t value)                                                                      = delete;
        errors_t(bool_t value)                                                                          = delete;

        errors_t(const errors_t& other);
        errors_t(const volatile errors_t& other);
        errors_t(errors_t&& other) noexcept;
        errors_t(volatile errors_t&& other) noexcept;

        errors_t&           operator =(const errors_t& other);
        volatile errors_t&  operator =(const errors_t& other) volatile;
        errors_t&           operator =(const volatile errors_t& other);
        volatile errors_t&  operator =(const volatile errors_t& other) volatile;
        errors_t&           operator =(errors_t&& other) noexcept;
        volatile errors_t&  operator =(errors_t&& other) volatile noexcept;
        errors_t&           operator =(is_just_volatile_tr<errors_t> auto&& other) noexcept;
        volatile errors_t&  operator =(is_just_volatile_tr<errors_t> auto&& other) volatile noexcept;

        ~errors_t();

    public:
        void_t  Ignore_Error();

    public:
        operator            value_t() const;
        operator            value_t() const volatile;

        explicit operator   std_bool_t() const;
        explicit operator   std_bool_t() const volatile;

    public:
        /// @name none_t interface
        /// @copydoc 
        /// @{
        errors_t(none_t);                                       ///< @copydoc 

        errors_t&           operator =(none_t);                 ///< @copydoc 
        volatile errors_t&  operator =(none_t) volatile;        ///< @copydoc 

        bool_t              operator ==(none_t) const;          ///< @copydoc 
        bool_t              operator ==(none_t) const volatile; ///< @copydoc 
        bool_t              operator !=(none_t) const;          ///< @copydoc 
        bool_t              operator !=(none_t) const volatile; ///< @copydoc 
        /// @}
    };

}}
