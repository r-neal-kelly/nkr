/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/z_bool_t.h"
#include "nkr/z_charcoder_i.h"
#include "nkr/z_intrinsics.h"
#include "nkr/z_none_t.h"

#include "nkr/z_array/stack_t.h"

namespace nkr { namespace charcoder {

    class utf_8_t
    {
    private:
        static_assert(sizeof(point_t) >= sizeof(u32_t));

    public:
        /// @name aliases
        /// @copydoc 
        /// @{
        using unit_t    = u8_t;
        using units_t   = array::stack_t<unit_t, 4>;
        /// @}

    public:
        /// @name static constexpr functions
        /// @copydoc 
        /// @{
        static constexpr point_t    Last_Point();
        static constexpr point_t    Replacement_Point();

        static constexpr count_t    Max_Unit_Count();
        /// @}

    private:
        static auto&    Assign_Copy(is_any_non_const_tr<utf_8_t> auto& self, const is_any_tr<utf_8_t> auto& other);
        static auto&    Assign_Move(is_any_non_const_tr<utf_8_t> auto& self, is_any_non_const_tr<utf_8_t> auto& other);

        static bool_t   Is_Well_Formed(const is_any_tr<utf_8_t> auto& self);

        static void_t   Encode(is_any_non_const_tr<utf_8_t> auto& self, point_t point);
        static point_t  Decode(const is_any_tr<utf_8_t> auto& self);

        static count_t  Read_Forward(is_any_non_const_tr<utf_8_t> auto& self, const is_any_tr<unit_t> auto* from);
        static count_t  Read_Reverse(is_any_non_const_tr<utf_8_t> auto& self, const is_any_tr<unit_t> auto* from, const is_any_tr<unit_t> auto* first);

        static count_t  Unit_Count(const is_any_tr<utf_8_t> auto& self);
        static unit_t   Unit(const is_any_tr<utf_8_t> auto& self, index_t unit_index);

        static auto&    Assign_None(is_any_non_const_tr<utf_8_t> auto& self);
        static bool_t   Is_Equal_To_None(const is_any_tr<utf_8_t> auto& self);

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
        utf_8_t();

        utf_8_t(point_t point);

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

        ~utf_8_t()                                                                                      = default;
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

        count_t Read_Forward(const is_any_tr<unit_t> auto* from);
        count_t Read_Forward(const is_any_tr<unit_t> auto* from) volatile;
        count_t Read_Reverse(const is_any_tr<unit_t> auto* from, const is_any_tr<unit_t> auto* first);
        count_t Read_Reverse(const is_any_tr<unit_t> auto* from, const is_any_tr<unit_t> auto* first) volatile;

        count_t Unit_Count() const;
        count_t Unit_Count() const volatile;
        unit_t  Unit(index_t unit_index) const;
        unit_t  Unit(index_t unit_index) const volatile;
        /// @}

    public:
        /// @name operators
        /// @copydoc 
        /// @{
        unit_t  operator [](index_t unit_index) const;
        unit_t  operator [](index_t unit_index) const volatile;
        /// @}

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