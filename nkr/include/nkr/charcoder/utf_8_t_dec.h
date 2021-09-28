/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/charcoder_i.h"
#include "nkr/intrinsics.h"

namespace nkr { namespace charcoder {

    // eventually we can use the array::stack_t as units

    class utf_8_t
    {
    public:
        using unit_t    = u8_t;

    protected:
        unit_t  units[4];
        count_t unit_count;

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
    };
    static_assert(charcoder_i<utf_8_t>);

}}
