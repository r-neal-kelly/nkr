/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/charcoder_i.h"
#include "nkr/intrinsics.h"

namespace nkr { namespace charcoder {

    class utf_16_t
    {
    public:
        using unit_t    = u16_t;

    protected:
        unit_t  units[2];
        count_t unit_count;

    public:
        utf_16_t();
        utf_16_t(const utf_16_t& other);
        utf_16_t(utf_16_t&& other) noexcept;
        utf_16_t& operator =(const utf_16_t& other);
        utf_16_t& operator =(utf_16_t&& other) noexcept;
        ~utf_16_t();

    public:
        bool_t  Is_Well_Formed_Normal() const;
        bool_t  Is_Well_Formed_Swapped() const;

        void_t  Encode_Normal(point_t point);
        void_t  Encode_Swapped(point_t point);
        point_t Decode_Normal() const;
        point_t Decode_Swapped() const;

        count_t Read_Forward_Normal(const unit_t* from);
        count_t Read_Forward_Swapped(const unit_t* from);
        count_t Read_Reverse_Normal(const unit_t* from, const unit_t* first);
        count_t Read_Reverse_Swapped(const unit_t* from, const unit_t* first);

        count_t Unit_Count() const;

    public:
        unit_t  operator [](index_t index) const;
    };

    class utf_16_be_t :
        public utf_16_t
    {
    public:
        using utf_16_t::utf_16_t;
        using utf_16_t::operator =;

    public:
        utf_16_be_t(const utf_16_t& other);
        utf_16_be_t(utf_16_t&& other) noexcept;

    public:
        template <typename = void_t>
        bool_t  Is_Well_Formed() const;

        template <typename = void_t>
        void_t  Encode(point_t point);
        template <typename = void_t>
        point_t Decode() const;

        template <typename = void_t>
        count_t Read_Forward(const unit_t* from);
        template <typename = void_t>
        count_t Read_Reverse(const unit_t* from, const unit_t* first);
    };
    static_assert(charcoder_i<utf_16_be_t>);

    class utf_16_le_t :
        public utf_16_t
    {
    public:
        using utf_16_t::utf_16_t;
        using utf_16_t::operator =;

    public:
        utf_16_le_t(const utf_16_t& other);
        utf_16_le_t(utf_16_t&& other) noexcept;

    public:
        template <typename = void_t>
        bool_t  Is_Well_Formed() const;

        template <typename = void_t>
        void_t  Encode(point_t point);
        template <typename = void_t>
        point_t Decode() const;

        template <typename = void_t>
        count_t Read_Forward(const unit_t* from);
        template <typename = void_t>
        count_t Read_Reverse(const unit_t* from, const unit_t* first);
    };
    static_assert(charcoder_i<utf_16_le_t>);

}}

#include "nkr/charcoder_utf_16_t.inl"
