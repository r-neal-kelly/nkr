/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_atomic_t.h"
#include "nkr/z_bool_t.h"
#include "nkr/z_intrinsics.h"
#include "nkr/z_macros.h"
#include "nkr/z_none_t.h"
#include "nkr/z_traits.h"

namespace nkr { namespace enumeration {

    template <typename value_p>
    class flags_t;

    template <typename flags_p>
    concept any_flags_tr =
        is_any_tr<flags_p, flags_t<typename flags_p::actual_value_t>>;

    nkr_DEFINE_CONTAINER_TRAITS(flags, actual_value_t);

}}

namespace nkr { namespace enumeration { namespace $flags_t {

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    class any_sp
    {
    public:
        using value_t           = integer_p;
        using actual_value_t    = actual_value_p;

    public:
        static constexpr index_t    Min_Index();
        static constexpr value_t    Min_Value();

        static constexpr index_t    Max_Index();
        static constexpr value_t    Max_Value();

        static constexpr index_t    Index(value_t value);
        static constexpr value_t    Value(index_t index);

    public:
        actual_value_t  value;

    public:
        any_sp();

        any_sp(value_t value);

        any_sp(const any_sp& other);
        any_sp(const volatile any_sp& other);
        any_sp(any_sp&& other) noexcept;
        any_sp(volatile any_sp&& other) noexcept;

        any_sp&             operator =(const any_sp& other);
        volatile any_sp&    operator =(const any_sp& other) volatile;
        any_sp&             operator =(const volatile any_sp& other);
        volatile any_sp&    operator =(const volatile any_sp& other) volatile;
        any_sp&             operator =(any_sp&& other) noexcept;
        volatile any_sp&    operator =(any_sp&& other) volatile noexcept;
        any_sp&             operator =(is_just_volatile_tr<any_sp> auto&& other) noexcept;
        volatile any_sp&    operator =(is_just_volatile_tr<any_sp> auto&& other) volatile noexcept;

        ~any_sp();

    public:
        value_t Flags() const;
        value_t Flags() const volatile;

        bool_t  Is_Index_Flagged(index_t index) const;
        bool_t  Is_Index_Flagged(index_t index) const volatile;
        bool_t  Is_Value_Flagged(value_t value) const;
        bool_t  Is_Value_Flagged(value_t value) const volatile;

        void_t  Flag_Index(index_t index);
        void_t  Flag_Index(index_t index) volatile;
        void_t  Flag_Value(value_t value);
        void_t  Flag_Value(value_t value) volatile;

        void_t  Unflag_Index(index_t index);
        void_t  Unflag_Index(index_t index) volatile;
        void_t  Unflag_Value(value_t value);
        void_t  Unflag_Value(value_t value) volatile;

    public:
        /// @name none_t interface
        /// @copydoc 
        /// @{
        any_sp(none_t);                                         ///< @copydoc 

        any_sp&             operator =(none_t);                 ///< @copydoc 
        volatile any_sp&    operator =(none_t) volatile;        ///< @copydoc 

        bool_t              operator ==(none_t) const;          ///< @copydoc 
        bool_t              operator ==(none_t) const volatile; ///< @copydoc 
        bool_t              operator !=(none_t) const;          ///< @copydoc 
        bool_t              operator !=(none_t) const volatile; ///< @copydoc 
        /// @}
    };

}}}

namespace nkr { namespace enumeration {

    template <typename value_p>
    class flags_t
    {
    public:
        flags_t()                                                                                   = delete;

        flags_t(const flags_t& other)                                                               = delete;
        flags_t(const volatile flags_t& other)                                                      = delete;
        flags_t(flags_t&& other) noexcept                                                           = delete;
        flags_t(volatile flags_t&& other) noexcept                                                  = delete;

        flags_t&            operator =(const flags_t& other)                                        = delete;
        volatile flags_t&   operator =(const flags_t& other) volatile                               = delete;
        flags_t&            operator =(const volatile flags_t& other)                               = delete;
        volatile flags_t&   operator =(const volatile flags_t& other) volatile                      = delete;
        flags_t&            operator =(flags_t&& other) noexcept                                    = delete;
        volatile flags_t&   operator =(flags_t&& other) volatile noexcept                           = delete;
        flags_t&            operator =(is_just_volatile_tr<flags_t> auto&& other) noexcept          = delete;
        volatile flags_t&   operator =(is_just_volatile_tr<flags_t> auto&& other) volatile noexcept = delete;

        ~flags_t()                                                                                  = delete;
    };

    template <integer_unsigned_tr integer_p>
    class flags_t<integer_p> :
        public $flags_t::any_sp<integer_p, integer_p>
    {
    private:
        using base_t    = $flags_t::any_sp<integer_p, integer_p>;

    public:
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(flags_t, base_t);
    };

    template <any_non_const_atomic_of_any_non_const_unsigned_integer_tr atomic_p>
    class flags_t<atomic_p> :
        public $flags_t::any_sp<typename atomic_p::value_t, atomic_p>
    {
    private:
        using base_t    = $flags_t::any_sp<typename atomic_p::value_t, atomic_p>;

    public:
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(flags_t, base_t);
    };

}}
