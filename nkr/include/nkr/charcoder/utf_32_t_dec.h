/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/charcoder_i.h"
#include "nkr/intrinsics.h"
#include "nkr/macros.h"
#include "nkr/none_t.h"
#include "nkr/utils.h"

namespace nkr { namespace charcoder {

    // I really want to move the enum and static funcs out of the charcoder an into a separate space, because it's used by all Unicode charcoders.

    class utf_32_t
    {
    private:
        static_assert(sizeof(point_t) >= sizeof(u32_t));

    public:
        /// @name aliases
        /// @copydoc 
        /// @{
        using unit_t    = c32_t;
        /// @}

    public:
        /// @name enums
        /// @copydoc 
        /// @{
        enum : unit_t
        {
            POINT_FIRST                         = 0x00000000,
            POINT_LAST                          = 0x0010FFFF,

            BMP_FIRST                           = 0x00000000,
            BMP_LAST                            = 0x0000FFFF,

            SURROGATE_HIGH_FIRST                = 0x0000D800,
            SURROGATE_HIGH_LAST                 = 0x0000DBFF,
            SURROGATE_LOW_FIRST                 = 0x0000DC00,
            SURROGATE_LOW_LAST                  = 0x0000DFFF,

            UTF_8_BRACKET_1_FIRST               = 0x00000000,
            UTF_8_BRACKET_1_LAST                = 0x0000007F,
            UTF_8_BRACKET_2_FIRST               = 0x00000080,
            UTF_8_BRACKET_2_LAST                = 0x000007FF,
            UTF_8_BRACKET_3_FIRST               = 0x00000800,
            UTF_8_BRACKET_3_LAST                = 0x0000FFFF,
            UTF_8_BRACKET_4_FIRST               = 0x00010000,
            UTF_8_BRACKET_4_LAST                = 0x0010FFFF,

            BYTE_ORDER_MARKER                   = 0x0000FEFF,

            REPLACEMENT_CHARACTER               = 0x0000FFFD,
            REPLACEMENT_CHARACTER_16_SWAPPED    = 0xFDFF,
            REPLACEMENT_CHARACTER_32_SWAPPED    = 0xFDFF0000,
        };
        /// @}

    public:
        /// @name static constexpr functions
        /// @copydoc 
        /// @{
        static constexpr point_t    Last_Point();
        static constexpr point_t    Replacement_Point();

        static constexpr count_t    Max_Unit_Count();

        static constexpr std_bool_t Is_Point(point_t point);
        static constexpr std_bool_t Is_Scalar(point_t point);
        static constexpr std_bool_t Is_Surrogate(point_t point);
        static constexpr std_bool_t Is_Surrogate_High(point_t point);
        static constexpr std_bool_t Is_Surrogate_Low(point_t point);

        static constexpr std_bool_t Is_UTF_8_Bracket_1_Point(point_t point);
        static constexpr std_bool_t Is_UTF_8_Bracket_2_Point(point_t point);
        static constexpr std_bool_t Is_UTF_8_Bracket_3_Point(point_t point);
        static constexpr std_bool_t Is_UTF_8_Bracket_4_Point(point_t point);
        static constexpr std_bool_t Is_UTF_8_Lead_Byte(byte_t byte);
        static constexpr std_bool_t Is_UTF_8_Trailing_Byte(byte_t byte);
        /// @}

    private:
        static auto&    Assign_Copy(is_any_non_const_tr<utf_32_t> auto& self, const is_any_tr<utf_32_t> auto& other);
        static auto&    Assign_Move(is_any_non_const_tr<utf_32_t> auto& self, is_any_non_const_tr<utf_32_t> auto& other);

        static bool_t   Is_Well_Formed_Normal(const is_any_tr<utf_32_t> auto& self);
        static bool_t   Is_Well_Formed_Swapped(const is_any_tr<utf_32_t> auto& self);

        static void_t   Encode_Normal(is_any_non_const_tr<utf_32_t> auto& self, point_t point);
        static void_t   Encode_Swapped(is_any_non_const_tr<utf_32_t> auto& self, point_t point);
        static point_t  Decode_Normal(const is_any_tr<utf_32_t> auto& self);
        static point_t  Decode_Swapped(const is_any_tr<utf_32_t> auto& self);

        static count_t  Read_Forward_Normal(is_any_non_const_tr<utf_32_t> auto& self, const unit_t* from);
        static count_t  Read_Forward_Swapped(is_any_non_const_tr<utf_32_t> auto& self, const unit_t* from);
        static count_t  Read_Reverse_Normal(is_any_non_const_tr<utf_32_t> auto& self, const unit_t* from, const unit_t* first);
        static count_t  Read_Reverse_Swapped(is_any_non_const_tr<utf_32_t> auto& self, const unit_t* from, const unit_t* first);

        static count_t  Unit_Count(const is_any_tr<utf_32_t> auto& self);

        static unit_t   Operator_Access(const is_any_tr<utf_32_t> auto& self, index_t index);

        static auto&    Assign_None(is_any_non_const_tr<utf_32_t> auto& self);
        static bool_t   Is_Equal_To_None(const is_any_tr<utf_32_t> auto& self);

    protected:
        /// @name protected object data
        /// @copydoc 
        /// @{
        unit_t  unit;
        /// @}

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        utf_32_t();

        utf_32_t(const utf_32_t& other);
        utf_32_t(const volatile utf_32_t& other);
        utf_32_t(utf_32_t&& other) noexcept;
        utf_32_t(volatile utf_32_t&& other) noexcept;

        utf_32_t&           operator =(const utf_32_t& other);
        volatile utf_32_t&  operator =(const utf_32_t& other) volatile;
        utf_32_t&           operator =(const volatile utf_32_t& other);
        volatile utf_32_t&  operator =(const volatile utf_32_t& other) volatile;
        utf_32_t&           operator =(utf_32_t&& other) noexcept;
        volatile utf_32_t&  operator =(utf_32_t&& other) volatile noexcept;
        utf_32_t&           operator =(is_just_volatile_tr<utf_32_t> auto&& other) noexcept;
        volatile utf_32_t&  operator =(is_just_volatile_tr<utf_32_t> auto&& other) volatile noexcept;

        ~utf_32_t();
        /// @}

    public:
        /// @name methods
        /// @copydoc 
        /// @{
        bool_t  Is_Well_Formed_Normal() const;
        bool_t  Is_Well_Formed_Normal() const volatile;
        bool_t  Is_Well_Formed_Swapped() const;
        bool_t  Is_Well_Formed_Swapped() const volatile;
        
        void_t  Encode_Normal(point_t point);
        void_t  Encode_Normal(point_t point) volatile;
        void_t  Encode_Swapped(point_t point);
        void_t  Encode_Swapped(point_t point) volatile;
        point_t Decode_Normal() const;
        point_t Decode_Normal() const volatile;
        point_t Decode_Swapped() const;
        point_t Decode_Swapped() const volatile;

        count_t Read_Forward_Normal(const unit_t* from);
        count_t Read_Forward_Normal(const unit_t* from) volatile;
        count_t Read_Forward_Swapped(const unit_t* from);
        count_t Read_Forward_Swapped(const unit_t* from) volatile;
        count_t Read_Reverse_Normal(const unit_t* from, const unit_t* first);
        count_t Read_Reverse_Normal(const unit_t* from, const unit_t* first) volatile;
        count_t Read_Reverse_Swapped(const unit_t* from, const unit_t* first);
        count_t Read_Reverse_Swapped(const unit_t* from, const unit_t* first) volatile;

        count_t Unit_Count() const;
        count_t Unit_Count() const volatile;
        /// @}

    public:
        /// @name operators
        /// @copydoc 
        /// @{
        unit_t  operator [](index_t index) const;
        unit_t  operator [](index_t index) const volatile;
        /// @}

    public:
        /// @name none_t interface
        /// @copydoc 
        /// @{
        utf_32_t(none_t);                                       ///< @copydoc 

        utf_32_t&           operator =(none_t);                 ///< @copydoc 
        volatile utf_32_t&  operator =(none_t) volatile;        ///< @copydoc 

        bool_t              operator ==(none_t) const;          ///< @copydoc 
        bool_t              operator ==(none_t) const volatile; ///< @copydoc 
        bool_t              operator !=(none_t) const;          ///< @copydoc 
        bool_t              operator !=(none_t) const volatile; ///< @copydoc 
        /// @}
    };

    class utf_32_be_t :
        public utf_32_t
    {
    private:
        using base_t    = utf_32_t;

    private:
        static bool_t   Is_Well_Formed(const is_any_tr<utf_32_be_t> auto& self);

        static void_t   Encode(is_any_non_const_tr<utf_32_be_t> auto& self, point_t point);
        static point_t  Decode(const is_any_tr<utf_32_be_t> auto& self);

        static count_t  Read_Forward(is_any_non_const_tr<utf_32_be_t> auto& self, const unit_t* from);
        static count_t  Read_Reverse(is_any_non_const_tr<utf_32_be_t> auto& self, const unit_t* from, const unit_t* first);

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(utf_32_be_t, base_t);

        utf_32_be_t(point_t point);
        /// @}

    public:
        /// @name methods
        /// @copydoc 
        /// @{
        bool_t  Is_Well_Formed() const;
        bool_t  Is_Well_Formed() const volatile;
        
        void_t  Encode(point_t point);
        void_t  Encode(point_t point) volatile;
        point_t Decode() const;
        point_t Decode() const volatile;

        count_t Read_Forward(const unit_t* from);
        count_t Read_Forward(const unit_t* from) volatile;
        count_t Read_Reverse(const unit_t* from, const unit_t* first);
        count_t Read_Reverse(const unit_t* from, const unit_t* first) volatile;
        /// @}
    };
    static_assert(charcoder_i<utf_32_be_t>);

    class utf_32_le_t :
        public utf_32_t
    {
    private:
        using base_t    = utf_32_t;

    private:
        static bool_t   Is_Well_Formed(const is_any_tr<utf_32_le_t> auto& self);

        static void_t   Encode(is_any_non_const_tr<utf_32_le_t> auto& self, point_t point);
        static point_t  Decode(const is_any_tr<utf_32_le_t> auto& self);

        static count_t  Read_Forward(is_any_non_const_tr<utf_32_le_t> auto& self, const unit_t* from);
        static count_t  Read_Reverse(is_any_non_const_tr<utf_32_le_t> auto& self, const unit_t* from, const unit_t* first);

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(utf_32_le_t, base_t);

        utf_32_le_t(point_t point);
        /// @}

    public:
        /// @name methods
        /// @copydoc 
        /// @{
        bool_t  Is_Well_Formed() const;
        bool_t  Is_Well_Formed() const volatile;
        
        void_t  Encode(point_t point);
        void_t  Encode(point_t point) volatile;
        point_t Decode() const;
        point_t Decode() const volatile;

        count_t Read_Forward(const unit_t* from);
        count_t Read_Forward(const unit_t* from) volatile;
        count_t Read_Reverse(const unit_t* from, const unit_t* first);
        count_t Read_Reverse(const unit_t* from, const unit_t* first) volatile;
        /// @}
    };
    static_assert(charcoder_i<utf_32_le_t>);

}}
