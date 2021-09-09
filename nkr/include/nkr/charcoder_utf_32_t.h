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

    public:
        enum : unit_t
        {
            POINT_FIRST                         = 0x00000000,
            POINT_LAST                          = 0x0010FFFF,

            SURROGATE_HIGH_FIRST                = 0x0000D800,
            SURROGATE_HIGH_LAST                 = 0x0000DBFF,
            SURROGATE_LOW_FIRST                 = 0x0000DC00,
            SURROGATE_LOW_LAST                  = 0x0000DFFF,

            BYTE_ORDER_MARKER                   = 0x0000FEFF,

            REPLACEMENT_CHARACTER               = 0x0000FFFD,
            REPLACEMENT_CHARACTER_16_SWAPPED    = 0xFDFF,
            REPLACEMENT_CHARACTER_32_SWAPPED    = 0xFDFF0000,
        };

    public:
        static bool_t   Is_Point(point_t point);
        static bool_t   Is_Scalar(point_t point);
        static bool_t   Is_Surrogate(point_t point);
        static bool_t   Is_Surrogate_High(point_t point);
        static bool_t   Is_Surrogate_Low(point_t point);

    protected:
        unit_t  unit;

    public:
        utf_32_t();
        utf_32_t(const utf_32_t& other);
        utf_32_t(utf_32_t&& other) noexcept;
        utf_32_t& operator =(const utf_32_t& other);
        utf_32_t& operator =(utf_32_t&& other) noexcept;
        ~utf_32_t();

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
    static_assert(charcoder_i<utf_32_le_t>);

}}

#include "nkr/charcoder_utf_32_t.inl"
