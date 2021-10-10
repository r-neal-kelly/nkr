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

#include "nkr/array/stack_t.h"

namespace nkr { namespace charcoder {

    class utf_16_t
    {
    private:
        static_assert(sizeof(point_t) >= sizeof(u32_t));

    public:
        /// @name aliases
        /// @copydoc 
        /// @{
        using unit_t    = c16_t;
        using units_t   = array::stack_t<unit_t, 2>;
        /// @}

    public:
        /// @name static constexpr functions
        /// @copydoc 
        /// @{
        static constexpr point_t    Replacement_Point();
        static constexpr std_bool_t Has_1_To_1_Unit_To_Point_Ratio();
        /// @}

    private:
        static auto&    Assign_Copy(is_any_non_const_tr<utf_16_t> auto& self, const is_any_tr<utf_16_t> auto& other);
        static auto&    Assign_Move(is_any_non_const_tr<utf_16_t> auto& self, is_any_non_const_tr<utf_16_t> auto& other);

        static void_t   Encode_Normal(is_any_non_const_tr<utf_16_t> auto& self, point_t point);
        static void_t   Encode_Swapped(is_any_non_const_tr<utf_16_t> auto& self, point_t point);
        static point_t  Decode_Normal(const is_any_tr<utf_16_t> auto& self);
        static point_t  Decode_Swapped(const is_any_tr<utf_16_t> auto& self);

        static count_t  Read_Forward_Normal(is_any_non_const_tr<utf_16_t> auto& self, const unit_t* from);
        static count_t  Read_Forward_Swapped(is_any_non_const_tr<utf_16_t> auto& self, const unit_t* from);
        static count_t  Read_Reverse_Normal(is_any_non_const_tr<utf_16_t> auto& self, const unit_t* from, const unit_t* first);
        static count_t  Read_Reverse_Swapped(is_any_non_const_tr<utf_16_t> auto& self, const unit_t* from, const unit_t* first);

        static count_t  Unit_Count(const is_any_tr<utf_16_t> auto& self);

        static bool_t   Is_Well_Formed_Normal(const is_any_tr<utf_16_t> auto& self);
        static bool_t   Is_Well_Formed_Swapped(const is_any_tr<utf_16_t> auto& self);

        static unit_t   Operator_Access(const is_any_tr<utf_16_t> auto& self, index_t index);

        static auto&    Assign_None(is_any_non_const_tr<utf_16_t> auto& self);
        static bool_t   Is_Equal_To_None(const is_any_tr<utf_16_t> auto& self);

    protected:
        /// @name protected object data
        /// @copydoc 
        /// @{
        units_t units;
        /// @}

    public:
        /// @name objects
        /// @copydoc 
        /// @{
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
        /// @}

    public:
        /// @name methods
        /// @copydoc 
        /// @{
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

    protected:
        /// @name protected methods
        /// @copydoc 
        /// @{
        bool_t  Is_Well_Formed_Normal() const;
        bool_t  Is_Well_Formed_Normal() const volatile;
        bool_t  Is_Well_Formed_Swapped() const;
        bool_t  Is_Well_Formed_Swapped() const volatile;
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
        utf_16_t(none_t);                                       ///< @copydoc 

        utf_16_t&           operator =(none_t);                 ///< @copydoc 
        volatile utf_16_t&  operator =(none_t) volatile;        ///< @copydoc 

        bool_t              operator ==(none_t) const;          ///< @copydoc 
        bool_t              operator ==(none_t) const volatile; ///< @copydoc 
        bool_t              operator !=(none_t) const;          ///< @copydoc 
        bool_t              operator !=(none_t) const volatile; ///< @copydoc 
        /// @}
    };

    class utf_16_be_t :
        public utf_16_t
    {
    private:
        using base_t    = utf_16_t;

    private:
        template <typename = void_t>
        static void_t   Encode(is_any_non_const_tr<utf_16_be_t> auto& self, point_t point);
        template <typename = void_t>
        static point_t  Decode(const is_any_tr<utf_16_be_t> auto& self);

        template <typename = void_t>
        static count_t  Read_Forward(is_any_non_const_tr<utf_16_be_t> auto& self, const unit_t* from);
        template <typename = void_t>
        static count_t  Read_Reverse(is_any_non_const_tr<utf_16_be_t> auto& self, const unit_t* from, const unit_t* first);

        template <typename = void_t>
        static bool_t   Is_Well_Formed(const is_any_tr<utf_16_be_t> auto& self);

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(utf_16_be_t, base_t);

        utf_16_be_t(point_t point);
        /// @}

    public:
        /// @name methods
        /// @copydoc 
        /// @{
        void_t  Encode(point_t point);
        void_t  Encode(point_t point) volatile;
        point_t Decode() const;
        point_t Decode() const volatile;

        count_t Read_Forward(const unit_t* from);
        count_t Read_Forward(const unit_t* from) volatile;
        count_t Read_Reverse(const unit_t* from, const unit_t* first);
        count_t Read_Reverse(const unit_t* from, const unit_t* first) volatile;
        /// @}

    protected:
        /// @name protected methods
        /// @copydoc 
        /// @{
        bool_t  Is_Well_Formed() const;
        bool_t  Is_Well_Formed() const volatile;
        /// @}
    };
    static_assert(charcoder_i<utf_16_be_t>);

    class utf_16_le_t :
        public utf_16_t
    {
    private:
        using base_t    = utf_16_t;

    private:
        template <typename = void_t>
        static void_t   Encode(is_any_non_const_tr<utf_16_le_t> auto& self, point_t point);
        template <typename = void_t>
        static point_t  Decode(const is_any_tr<utf_16_le_t> auto& self);

        template <typename = void_t>
        static count_t  Read_Forward(is_any_non_const_tr<utf_16_le_t> auto& self, const unit_t* from);
        template <typename = void_t>
        static count_t  Read_Reverse(is_any_non_const_tr<utf_16_le_t> auto& self, const unit_t* from, const unit_t* first);

        template <typename = void_t>
        static bool_t   Is_Well_Formed(const is_any_tr<utf_16_le_t> auto& self);

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(utf_16_le_t, base_t);

        utf_16_le_t(point_t point);
        /// @}

    public:
        /// @name methods
        /// @copydoc 
        /// @{
        void_t  Encode(point_t point);
        void_t  Encode(point_t point) volatile;
        point_t Decode() const;
        point_t Decode() const volatile;

        count_t Read_Forward(const unit_t* from);
        count_t Read_Forward(const unit_t* from) volatile;
        count_t Read_Reverse(const unit_t* from, const unit_t* first);
        count_t Read_Reverse(const unit_t* from, const unit_t* first) volatile;
        /// @}

    protected:
        /// @name protected methods
        /// @copydoc 
        /// @{
        bool_t  Is_Well_Formed() const;
        bool_t  Is_Well_Formed() const volatile;
        /// @}
    };
    static_assert(charcoder_i<utf_16_le_t>);

}}
