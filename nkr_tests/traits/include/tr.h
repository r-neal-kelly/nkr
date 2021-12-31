/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/z_bool_t.h"
#include "nkr/z_intrinsics.h"
#include "nkr/z_traits.h"

#include "doctest.h"

namespace nkr {

    class non_match_t;

    template <>
    class type_traits_i<non_match_t>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t Is_Any()
        {
            return is_any_tr<other_p, non_match_t>;
        }
    };

    class non_match_t
    {
    public:
    };

    class user_defined_t;

    template <>
    class type_traits_i<user_defined_t>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t Is_Any()
        {
            return is_any_tr<other_p, user_defined_t>;
        }
    };

    class user_defined_t
    {
    public:
    };

    template <typename value_p>
    class value_template_t;

    namespace $value_template_t {

        template <typename type_p>
        concept any_tr =
            is_any_tr<type_p, value_template_t<typename type_p::value_t>>;

    }

    template <$value_template_t::any_tr type_p>
    class type_traits_i<type_p>
    {
    public:
        using of_t  = type_p::value_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t Is_Any()
        {
            return $value_template_t::any_tr<other_p>;
        }
    };

    template <>
    class template_traits_i<value_template_t>
    {
    public:
        template <typename of_p>
        using type_t    = value_template_t<of_p>;

    public:
        static constexpr c_bool_t Is_Implemented()
        {
            return true;
        }
    };

    template <typename value_p>
    class value_template_t
    {
    public:
        using value_t   = value_p;
    };

    template <typename unit_p>
    class unit_template_t;

    namespace $unit_template_t {

        template <typename type_p>
        concept any_tr =
            is_any_tr<type_p, unit_template_t<typename type_p::unit_t>>;

    }

    template <$unit_template_t::any_tr type_p>
    class type_traits_i<type_p>
    {
    public:
        using of_t  = type_p::unit_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t Is_Any()
        {
            return $unit_template_t::any_tr<other_p>;
        }
    };

    template <>
    class template_traits_i<unit_template_t>
    {
    public:
        template <typename of_p>
        using type_t    = unit_template_t<of_p>;

    public:
        static constexpr c_bool_t Is_Implemented()
        {
            return true;
        }
    };

    template <typename unit_p>
    class unit_template_t
    {
    public:
        using unit_t    = unit_p;
    };

}

namespace nkr { namespace traits {

    #define nkr_ANY(TYPE_p)     \
        TYPE_p,                 \
        const TYPE_p,           \
        volatile TYPE_p,        \
        const volatile TYPE_p

    #define nkr_ANY_QUALIFIED(TYPE_p)   \
        const TYPE_p,                   \
        volatile TYPE_p,                \
        const volatile TYPE_p

    #define nkr_ANY_NON_QUALIFIED(TYPE_p)   \
        TYPE_p

    #define nkr_ANY_CONST(TYPE_p)   \
        const TYPE_p,               \
        const volatile TYPE_p

    #define nkr_ANY_NON_CONST(TYPE_p)   \
        TYPE_p,                         \
        volatile TYPE_p

    #define nkr_ANY_VOLATILE(TYPE_p)    \
        volatile TYPE_p,                \
        const volatile TYPE_p

    #define nkr_ANY_NON_VOLATILE(TYPE_p)    \
        TYPE_p,                             \
        const TYPE_p

    #define nkr_JUST(TYPE_p)    \
        TYPE_p,                 \
        const TYPE_p,           \
        volatile TYPE_p,        \
        const volatile TYPE_p

    #define nkr_JUST_NON_QUALIFIED(TYPE_p)  \
        TYPE_p

    #define nkr_NOT_JUST_NON_QUALIFIED(TYPE_p)  \
        const TYPE_p,                           \
        volatile TYPE_p,                        \
        const volatile TYPE_p

    #define nkr_JUST_CONST(TYPE_p)  \
        const TYPE_p

    #define nkr_NOT_JUST_CONST(TYPE_p)  \
        TYPE_p,                         \
        volatile TYPE_p,                \
        const volatile TYPE_p

    #define nkr_JUST_VOLATILE(TYPE_p)   \
        volatile TYPE_p

    #define nkr_NOT_JUST_VOLATILE(TYPE_p)   \
        TYPE_p,                             \
        const TYPE_p,                       \
        const volatile TYPE_p

    #define nkr_JUST_CONST_VOLATILE(TYPE_p) \
        const volatile TYPE_p

    #define nkr_NOT_JUST_CONST_VOLATILE(TYPE_p) \
        TYPE_p,                                 \
        const TYPE_p,                           \
        volatile TYPE_p

    #define nkr_TYPES(MODIFIER_p)               \
        MODIFIER_p(void_t),                     \
        MODIFIER_p(c_bool_t),                   \
        MODIFIER_p(bool_t),                     \
        MODIFIER_p(unsigned_word_t),            \
        MODIFIER_p(signed_word_t),              \
        MODIFIER_p(real_t),                     \
        MODIFIER_p(std::add_pointer_t<void_t>), \
        MODIFIER_p(std::add_pointer_t<word_t>), \
        MODIFIER_p(word_t[1]),                  \
        MODIFIER_p(user_defined_t),             \
        MODIFIER_p(value_template_t<word_t>),   \
        MODIFIER_p(unit_template_t<word_t>)

    #define nkr_ANY_TYPES   \
        nkr_TYPES(nkr_ANY)

    #define nkr_ANY_QUALIFIED_TYPES     \
        nkr_TYPES(nkr_ANY_QUALIFIED)

    #define nkr_ANY_NON_QUALIFIED_TYPES     \
        nkr_TYPES(nkr_ANY_NON_QUALIFIED)

    #define nkr_ANY_CONST_TYPES     \
        nkr_TYPES(nkr_ANY_CONST)

    #define nkr_ANY_NON_CONST_TYPES     \
        nkr_TYPES(nkr_ANY_NON_CONST)

    #define nkr_ANY_VOLATILE_TYPES  \
        nkr_TYPES(nkr_ANY_VOLATILE)

    #define nkr_ANY_NON_VOLATILE_TYPES  \
        nkr_TYPES(nkr_ANY_NON_VOLATILE)

    #define nkr_JUST_TYPES  \
        nkr_TYPES(nkr_JUST)

    #define nkr_JUST_NON_QUALIFIED_TYPES    \
        nkr_TYPES(nkr_JUST_NON_QUALIFIED)

    #define nkr_NOT_JUST_NON_QUALIFIED_TYPES    \
        nkr_TYPES(nkr_NOT_JUST_NON_QUALIFIED)

    #define nkr_JUST_CONST_TYPES    \
        nkr_TYPES(nkr_JUST_CONST)

    #define nkr_NOT_JUST_CONST_TYPES    \
        nkr_TYPES(nkr_NOT_JUST_CONST)

    #define nkr_JUST_VOLATILE_TYPES     \
        nkr_TYPES(nkr_JUST_VOLATILE)

    #define nkr_NOT_JUST_VOLATILE_TYPES     \
        nkr_TYPES(nkr_NOT_JUST_VOLATILE)

    #define nkr_JUST_CONST_VOLATILE_TYPES   \
        nkr_TYPES(nkr_JUST_CONST_VOLATILE)

    #define nkr_NOT_JUST_CONST_VOLATILE_TYPES   \
        nkr_TYPES(nkr_NOT_JUST_CONST_VOLATILE)

}}
