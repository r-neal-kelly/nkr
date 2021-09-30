/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/atomic_t_dec.h"
#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/macros.h"
#include "nkr/none_t.h"
#include "nkr/traits.h"

namespace nkr { namespace enumeration {

    template <typename value_p, value_p none_p>
    class types_t;

    template <typename types_p>
    concept any_types_tr =
        is_any_tr<types_p, types_t<typename types_p::actual_value_t, types_p::NONE>>;

    nkr_DEFINE_CONTAINER_TRAITS(types, actual_value_t);

}}

namespace nkr { namespace enumeration { namespace $types_t {

    template <integer_tr value_p, any_tr actual_value_p, value_p none_p>
    class any_sp
    {
    public:
        using value_t           = value_p;
        using actual_value_t    = actual_value_p;

    public:
        static constexpr value_t    NONE    = none_p;

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
        operator            actual_value_t&();
        operator            const actual_value_t&() const;
        operator            volatile actual_value_t&() volatile;
        operator            const volatile actual_value_t&() const volatile;

        explicit operator   std_bool_t() const;
        explicit operator   std_bool_t() const volatile;

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

    template <typename value_p, value_p none_p = -1>
    class types_t
    {
    public:
        types_t()                                                                                   = delete;

        types_t(const types_t& other)                                                               = delete;
        types_t(const volatile types_t& other)                                                      = delete;
        types_t(types_t&& other) noexcept                                                           = delete;
        types_t(volatile types_t&& other) noexcept                                                  = delete;

        types_t&            operator =(const types_t& other)                                        = delete;
        volatile types_t&   operator =(const types_t& other) volatile                               = delete;
        types_t&            operator =(const volatile types_t& other)                               = delete;
        volatile types_t&   operator =(const volatile types_t& other) volatile                      = delete;
        types_t&            operator =(types_t&& other) noexcept                                    = delete;
        volatile types_t&   operator =(types_t&& other) volatile noexcept                           = delete;
        types_t&            operator =(is_just_volatile_tr<types_t> auto&& other) noexcept          = delete;
        volatile types_t&   operator =(is_just_volatile_tr<types_t> auto&& other) volatile noexcept = delete;

        ~types_t()                                                                                  = delete;
    };

    template <integer_signed_tr integer_p, integer_p none_p>
    class types_t<integer_p, none_p> :
        public $types_t::any_sp<integer_p, integer_p, none_p>
    {
    private:
        using base_t    = $types_t::any_sp<integer_p, integer_p, none_p>;

    public:
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(types_t, base_t);
    };

    template <any_non_const_atomic_of_any_non_const_signed_integer_tr atomic_p, typename atomic_p::value_t none_p>
    class types_t<atomic_p, none_p> :
        public $types_t::any_sp<typename atomic_p::value_t, atomic_p, none_p>
    {
    private:
        using base_t    = $types_t::any_sp<typename atomic_p::value_t, atomic_p, none_p>;

    public:
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(types_t, base_t);
    };

}}
