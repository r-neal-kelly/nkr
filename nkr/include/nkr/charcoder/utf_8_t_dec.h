/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/charcoder_i.h"
#include "nkr/intrinsics.h"
#include "nkr/none_t.h"

namespace nkr { namespace charcoder {

    // eventually we can use the array::stack_t as units

    class utf_8_t
    {
    public:
        using unit_t    = c8_t;

    protected:
        count_t unit_count;
        unit_t  units[4];

    public:
        utf_8_t();

        utf_8_t(const utf_8_t& other);
        utf_8_t(const volatile utf_8_t& other);
        utf_8_t(utf_8_t&& other) noexcept;
        utf_8_t(volatile utf_8_t&& other) noexcept;

        utf_8_t&            operator =(const utf_8_t& other);
        volatile utf_8_t&   operator =(const utf_8_t& other) volatile;
        utf_8_t&            operator =(const volatile utf_8_t& other);
        volatile utf_8_t&   operator =(const volatile utf_8_t& other) volatile;
        utf_8_t&            operator =(utf_8_t&& other) noexcept;
        volatile utf_8_t&   operator =(utf_8_t&& other) volatile noexcept;
        utf_8_t&            operator =(is_just_volatile_tr<utf_8_t> auto&& other) noexcept;
        volatile utf_8_t&   operator =(is_just_volatile_tr<utf_8_t> auto&& other) volatile noexcept;

        ~utf_8_t();

    public:
        bool_t  Is_Well_Formed() const;

        void_t  Encode(point_t point);
        point_t Decode() const;

        count_t Read_Forward(const unit_t* from);
        count_t Read_Reverse(const unit_t* from, const unit_t* first);

        count_t Unit_Count() const;

    public:
        unit_t  operator [](index_t index) const;

    public:
        /// @name none_t interface
        /// @copydoc 
        /// @{
        utf_8_t(none_t);                                        ///< @copydoc 

        utf_8_t&            operator =(none_t);                 ///< @copydoc 
        volatile utf_8_t&   operator =(none_t) volatile;        ///< @copydoc 

        bool_t              operator ==(none_t) const;          ///< @copydoc 
        bool_t              operator ==(none_t) const volatile; ///< @copydoc 
        bool_t              operator !=(none_t) const;          ///< @copydoc 
        bool_t              operator !=(none_t) const volatile; ///< @copydoc 
        /// @}
    };
    static_assert(charcoder_i<utf_8_t>);

}}
