/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/charcoder_i.h"
#include "nkr/intrinsics.h"

namespace nkr { namespace charcoder {

    class ascii_t
    {
    public:
        using unit_t    = s8_t;

    protected:
        unit_t  unit;

    public:
        ascii_t();

        ascii_t(const ascii_t& other);
        ascii_t(const volatile ascii_t& other);
        ascii_t(ascii_t&& other) noexcept;
        ascii_t(volatile ascii_t&& other) noexcept;

        ascii_t&            operator =(const ascii_t& other);
        volatile ascii_t&   operator =(const ascii_t& other) volatile;
        ascii_t&            operator =(const volatile ascii_t& other);
        volatile ascii_t&   operator =(const volatile ascii_t& other) volatile;
        ascii_t&            operator =(ascii_t&& other) noexcept;
        volatile ascii_t&   operator =(ascii_t&& other) volatile noexcept;
        ascii_t&            operator =(is_just_volatile_tr<ascii_t> auto&& other) noexcept;
        volatile ascii_t&   operator =(is_just_volatile_tr<ascii_t> auto&& other) volatile noexcept;

        ~ascii_t();

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
    static_assert(charcoder_i<ascii_t>);

}}

#include "nkr/charcoder/ascii_t.inl"
