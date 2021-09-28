/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/charcoder_i.h"
#include "nkr/intrinsics.h"
#include "nkr/macros.h"
#include "nkr/utils.h"

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
        utf_16_t(const volatile utf_16_t& other);
        utf_16_t(utf_16_t&& other) noexcept;
        utf_16_t(volatile utf_16_t&& other) noexcept;

        utf_16_t&           operator =(const utf_16_t& other);
        volatile utf_16_t&  operator =(const utf_16_t& other) volatile;
        utf_16_t&           operator =(const volatile utf_16_t& other);
        volatile utf_16_t&  operator =(const volatile utf_16_t& other) volatile;
        utf_16_t&           operator =(utf_16_t&& other) noexcept;
        volatile utf_16_t&  operator =(utf_16_t&& other) volatile noexcept;
        utf_16_t&           operator =(is_just_volatile_tr<utf_16_t> auto&& other) noexcept;
        volatile utf_16_t&  operator =(is_just_volatile_tr<utf_16_t> auto&& other) volatile noexcept;

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
        using base_t    = utf_16_t;

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(utf_16_be_t, base_t);
        /// @}

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
        using base_t    = utf_16_t;

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(utf_16_le_t, base_t);
        /// @}

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
