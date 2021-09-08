/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/charcoder_i.h"
#include "nkr/intrinsics.h"

namespace nkr { namespace charcoder {

    class utf_32_t
    {
    public:
        using unit_t    = u32_t;

    protected:
        unit_t  units[1];

    public:
        bool_t  Is_Well_Formed() const;
        bool_t  Is_Well_Formed_Swapped() const;

        count_t Read_Forward(const unit_t* from);
        count_t Read_Forward_Swapped(const unit_t* from);
        count_t Read_Reverse(const unit_t* from, const unit_t* first);
        count_t Read_Reverse_Swapped(const unit_t* from, const unit_t* first);

        void_t  Encode(point_t point);
        void_t  Encode_Swapped(point_t point);
        point_t Decode() const;
        point_t Decode_Swapped() const;

        count_t Unit_Count() const;

    public:
        unit_t  operator [](index_t index) const;
    };

    class utf_32_be_t :
        public utf_32_t
    {
    public:
        using utf_32_t::utf_32_t;
        using utf_32_t::operator =;

    public:
        utf_32_be_t(const utf_32_t& other);
        utf_32_be_t(utf_32_t&& other) noexcept;

    public:
        bool_t  Is_Well_Formed() const;

        count_t Read_Forward(const unit_t* from);
        count_t Read_Reverse(const unit_t* from, const unit_t* first);

        void_t  Encode(point_t point);
        point_t Decode() const;
    };
    static_assert(charcoder_i<utf_32_be_t>);

    class utf_32_le_t :
        public utf_32_t
    {
    public:
        using utf_32_t::utf_32_t;
        using utf_32_t::operator =;

    public:
        utf_32_le_t(const utf_32_t& other);
        utf_32_le_t(utf_32_t&& other) noexcept;

    public:
        bool_t  Is_Well_Formed() const;

        count_t Read_Forward(const unit_t* from);
        count_t Read_Reverse(const unit_t* from, const unit_t* first);

        void_t  Encode(point_t point);
        point_t Decode() const;
    };
    static_assert(charcoder_i<utf_32_le_t>);

}}

#include "nkr/charcoder_utf_32_t.inl"
