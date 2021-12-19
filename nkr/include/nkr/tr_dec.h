/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_dec.h"
#include "nkr/intrinsics_dec.h"

#include "nkr/interface/template_i_dec.h"
#include "nkr/interface/type_i_dec.h"

namespace nkr {

    struct any_tg                               { class any_t; };
    struct any_qualified_tg                     { class any_t; };
    struct any_non_qualified_tg                 { class any_t; };
    struct any_const_tg                         { class any_t; };
    struct any_non_const_tg                     { class any_t; };
    struct any_volatile_tg                      { class any_t; };
    struct any_non_volatile_tg                  { class any_t; };

    struct just_tg                              { class just_t; };
    struct just_non_qualified_tg                { class just_t; };
    struct just_const_tg                        { class just_t; };
    struct just_volatile_tg                     { class just_t; };
    struct just_const_volatile_tg               { class just_t; };

    struct not_any_tg                           { class not_t; class any_t; using is_tg = any_tg; };
    struct not_any_qualified_tg                 { class not_t; class any_t; using is_tg = any_qualified_tg; };
    struct not_any_non_qualified_tg             { class not_t; class any_t; using is_tg = any_non_qualified_tg; };
    struct not_any_const_tg                     { class not_t; class any_t; using is_tg = any_const_tg; };
    struct not_any_non_const_tg                 { class not_t; class any_t; using is_tg = any_non_const_tg; };
    struct not_any_volatile_tg                  { class not_t; class any_t; using is_tg = any_volatile_tg; };
    struct not_any_non_volatile_tg              { class not_t; class any_t; using is_tg = any_non_volatile_tg; };

    struct just_not_tg                          { class just_t; class not_t; using is_tg = just_tg; };
    struct just_not_non_qualified_tg            { class just_t; class not_t; using is_tg = just_non_qualified_tg; };
    struct just_not_const_tg                    { class just_t; class not_t; using is_tg = just_const_tg; };
    struct just_not_volatile_tg                 { class just_t; class not_t; using is_tg = just_volatile_tg; };
    struct just_not_const_volatile_tg           { class just_t; class not_t; using is_tg = just_const_volatile_tg; };

    struct any_to_tg                            { class any_t; class to_t; using base_tg = any_tg; };
    struct any_qualified_to_tg                  { class any_t; class to_t; using base_tg = any_qualified_tg; };
    struct any_non_qualified_to_tg              { class any_t; class to_t; using base_tg = any_non_qualified_tg; };
    struct any_const_to_tg                      { class any_t; class to_t; using base_tg = any_const_tg; };
    struct any_non_const_to_tg                  { class any_t; class to_t; using base_tg = any_non_const_tg; };
    struct any_volatile_to_tg                   { class any_t; class to_t; using base_tg = any_volatile_tg; };
    struct any_non_volatile_to_tg               { class any_t; class to_t; using base_tg = any_non_volatile_tg; };

    struct just_to_tg                           { class just_t; class to_t; using base_tg = just_tg; };
    struct just_non_qualified_to_tg             { class just_t; class to_t; using base_tg = just_non_qualified_tg; };
    struct just_const_to_tg                     { class just_t; class to_t; using base_tg = just_const_tg; };
    struct just_volatile_to_tg                  { class just_t; class to_t; using base_tg = just_volatile_tg; };
    struct just_const_volatile_to_tg            { class just_t; class to_t; using base_tg = just_const_volatile_tg; };

    struct not_any_to_tg                        { class not_t; class any_t; class to_t; using base_tg = not_any_tg; };
    struct not_any_qualified_to_tg              { class not_t; class any_t; class to_t; using base_tg = not_any_qualified_tg; };
    struct not_any_non_qualified_to_tg          { class not_t; class any_t; class to_t; using base_tg = not_any_non_qualified_tg; };
    struct not_any_const_to_tg                  { class not_t; class any_t; class to_t; using base_tg = not_any_const_tg; };
    struct not_any_non_const_to_tg              { class not_t; class any_t; class to_t; using base_tg = not_any_non_const_tg; };
    struct not_any_volatile_to_tg               { class not_t; class any_t; class to_t; using base_tg = not_any_volatile_tg; };
    struct not_any_non_volatile_to_tg           { class not_t; class any_t; class to_t; using base_tg = not_any_non_volatile_tg; };

    struct just_not_to_tg                       { class just_t; class not_t; class to_t; using base_tg = just_not_tg; };
    struct just_not_non_qualified_to_tg         { class just_t; class not_t; class to_t; using base_tg = just_not_non_qualified_tg; };
    struct just_not_const_to_tg                 { class just_t; class not_t; class to_t; using base_tg = just_not_const_tg; };
    struct just_not_volatile_to_tg              { class just_t; class not_t; class to_t; using base_tg = just_not_volatile_tg; };
    struct just_not_const_volatile_to_tg        { class just_t; class not_t; class to_t; using base_tg = just_not_const_volatile_tg; };

    struct of_any_tg                            { class of_t; class any_t; using base_tg = any_tg; };
    struct of_any_qualified_tg                  { class of_t; class any_t; using base_tg = any_qualified_tg; };
    struct of_any_non_qualified_tg              { class of_t; class any_t; using base_tg = any_non_qualified_tg; };
    struct of_any_const_tg                      { class of_t; class any_t; using base_tg = any_const_tg; };
    struct of_any_non_const_tg                  { class of_t; class any_t; using base_tg = any_non_const_tg; };
    struct of_any_volatile_tg                   { class of_t; class any_t; using base_tg = any_volatile_tg; };
    struct of_any_non_volatile_tg               { class of_t; class any_t; using base_tg = any_non_volatile_tg; };

    struct of_just_tg                           { class of_t; class just_t; using base_tg = just_tg; };
    struct of_just_non_qualified_tg             { class of_t; class just_t; using base_tg = just_non_qualified_tg; };
    struct of_just_const_tg                     { class of_t; class just_t; using base_tg = just_const_tg; };
    struct of_just_volatile_tg                  { class of_t; class just_t; using base_tg = just_volatile_tg; };
    struct of_just_const_volatile_tg            { class of_t; class just_t; using base_tg = just_const_volatile_tg; };

    struct of_not_any_tg                        { class of_t; class not_t; class any_t; using base_tg = not_any_tg; };
    struct of_not_any_qualified_tg              { class of_t; class not_t; class any_t; using base_tg = not_any_qualified_tg; };
    struct of_not_any_non_qualified_tg          { class of_t; class not_t; class any_t; using base_tg = not_any_non_qualified_tg; };
    struct of_not_any_const_tg                  { class of_t; class not_t; class any_t; using base_tg = not_any_const_tg; };
    struct of_not_any_non_const_tg              { class of_t; class not_t; class any_t; using base_tg = not_any_non_const_tg; };
    struct of_not_any_volatile_tg               { class of_t; class not_t; class any_t; using base_tg = not_any_volatile_tg; };
    struct of_not_any_non_volatile_tg           { class of_t; class not_t; class any_t; using base_tg = not_any_non_volatile_tg; };

    struct of_just_not_tg                       { class of_t; class just_t; class not_t; using base_tg = just_not_tg; };
    struct of_just_not_non_qualified_tg         { class of_t; class just_t; class not_t; using base_tg = just_not_non_qualified_tg; };
    struct of_just_not_const_tg                 { class of_t; class just_t; class not_t; using base_tg = just_not_const_tg; };
    struct of_just_not_volatile_tg              { class of_t; class just_t; class not_t; using base_tg = just_not_volatile_tg; };
    struct of_just_not_const_volatile_tg        { class of_t; class just_t; class not_t; using base_tg = just_not_const_volatile_tg; };

    struct of_any_access_tg                     { class of_t; class any_t; class access_t; using base_tg = any_tg; };
    struct of_any_access_qualified_tg           { class of_t; class any_t; class access_t; using base_tg = any_qualified_tg; };
    struct of_any_access_non_qualified_tg       { class of_t; class any_t; class access_t; using base_tg = any_non_qualified_tg; };
    struct of_any_access_const_tg               { class of_t; class any_t; class access_t; using base_tg = any_const_tg; };
    struct of_any_access_non_const_tg           { class of_t; class any_t; class access_t; using base_tg = any_non_const_tg; };
    struct of_any_access_volatile_tg            { class of_t; class any_t; class access_t; using base_tg = any_volatile_tg; };
    struct of_any_access_non_volatile_tg        { class of_t; class any_t; class access_t; using base_tg = any_non_volatile_tg; };

    struct of_just_access_tg                    { class of_t; class just_t; class access_t; using base_tg = just_tg; };
    struct of_just_access_non_qualified_tg      { class of_t; class just_t; class access_t; using base_tg = just_non_qualified_tg; };
    struct of_just_access_const_tg              { class of_t; class just_t; class access_t; using base_tg = just_const_tg; };
    struct of_just_access_volatile_tg           { class of_t; class just_t; class access_t; using base_tg = just_volatile_tg; };
    struct of_just_access_const_volatile_tg     { class of_t; class just_t; class access_t; using base_tg = just_const_volatile_tg; };

    struct of_not_any_access_tg                 { class of_t; class not_t; class any_t; class access_t; using base_tg = not_any_tg; };
    struct of_not_any_access_qualified_tg       { class of_t; class not_t; class any_t; class access_t; using base_tg = not_any_qualified_tg; };
    struct of_not_any_access_non_qualified_tg   { class of_t; class not_t; class any_t; class access_t; using base_tg = not_any_non_qualified_tg; };
    struct of_not_any_access_const_tg           { class of_t; class not_t; class any_t; class access_t; using base_tg = not_any_const_tg; };
    struct of_not_any_access_non_const_tg       { class of_t; class not_t; class any_t; class access_t; using base_tg = not_any_non_const_tg; };
    struct of_not_any_access_volatile_tg        { class of_t; class not_t; class any_t; class access_t; using base_tg = not_any_volatile_tg; };
    struct of_not_any_access_non_volatile_tg    { class of_t; class not_t; class any_t; class access_t; using base_tg = not_any_non_volatile_tg; };

    struct of_just_not_access_tg                { class of_t; class just_t; class not_t; class access_t; using base_tg = just_not_tg; };
    struct of_just_not_access_non_qualified_tg  { class of_t; class just_t; class not_t; class access_t; using base_tg = just_not_non_qualified_tg; };
    struct of_just_not_access_const_tg          { class of_t; class just_t; class not_t; class access_t; using base_tg = just_not_const_tg; };
    struct of_just_not_access_volatile_tg       { class of_t; class just_t; class not_t; class access_t; using base_tg = just_not_volatile_tg; };
    struct of_just_not_access_const_volatile_tg { class of_t; class just_t; class not_t; class access_t; using base_tg = just_not_const_volatile_tg; };

}

namespace nkr { namespace $tr {

    template <typename type_p>
    class type_i :
        public interface::type_i<cpp::just_non_qualified_t<type_p>>
    {
    public:
    };

    template <cpp::array_tr type_p>
    class type_i<type_p> :
        public interface::type_i<type_p>
    {
    public:
    };

    template <template <typename ...> typename template_p>
    class template_i :
        public interface::template_i<template_p>
    {
    public:
    };

    template <typename type_p>
    concept any_operator_tr = requires
    {
        typename type_p::any_t;
    };

    template <typename type_p>
    concept just_operator_tr = requires
    {
        typename type_p::just_t;
    };

    template <typename type_p>
    concept not_operator_tr = requires
    {
        typename type_p::not_t;
    };

    template <typename type_p>
    concept of_operator_tr = requires
    {
        typename type_p::of_t;
    };

    template <typename type_p>
    concept to_operator_tr = requires
    {
        typename type_p::to_t;
    };

    template <typename type_p>
    concept access_operator_tr = requires
    {
        typename type_p::access_t;
    };

    template <typename child_p, typename parent_p, cpp::bool_t do_access_p>
    class access_or_not_tmpl
    {
    public:
        using type_t    = child_p;
    };

    template <typename child_p, typename parent_p>
    class access_or_not_tmpl<child_p, parent_p, true>
    {
    public:
        using type_t    = cpp::access_qualification_of_t<child_p, parent_p>;
    };

    template <typename child_p, typename parent_p, cpp::bool_t do_access_p>
    using access_or_not_t   = access_or_not_tmpl<child_p, parent_p, do_access_p>::type_t;

    template <
        typename subject_p,
        typename operator_p
    > constexpr cpp::bool_t
        TR0()
        noexcept
    {
        using subject_t = subject_p;

        if constexpr (cpp::is_tr<operator_p, any_tg>)                           return true;
        else if constexpr (cpp::is_tr<operator_p, any_qualified_tg>)            return cpp::any_qualified_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, any_non_qualified_tg>)        return cpp::any_non_qualified_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, any_const_tg>)                return cpp::any_const_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, any_non_const_tg>)            return cpp::any_non_const_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, any_volatile_tg>)             return cpp::any_volatile_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, any_non_volatile_tg>)         return cpp::any_non_volatile_tr<subject_t>;

        else if constexpr (cpp::is_tr<operator_p, not_any_tg>)                  return false;
        else if constexpr (cpp::is_tr<operator_p, not_any_qualified_tg>)        return !cpp::any_qualified_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, not_any_non_qualified_tg>)    return !cpp::any_non_qualified_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, not_any_const_tg>)            return !cpp::any_const_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, not_any_non_const_tg>)        return !cpp::any_non_const_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, not_any_volatile_tg>)         return !cpp::any_volatile_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, not_any_non_volatile_tg>)     return !cpp::any_non_volatile_tr<subject_t>;

        else if constexpr (cpp::is_tr<operator_p, just_tg>)                     return true;
        else if constexpr (cpp::is_tr<operator_p, just_non_qualified_tg>)       return cpp::just_non_qualified_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, just_const_tg>)               return cpp::just_const_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, just_volatile_tg>)            return cpp::just_volatile_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, just_const_volatile_tg>)      return cpp::just_const_volatile_tr<subject_t>;

        else if constexpr (cpp::is_tr<operator_p, just_not_tg>)                 return false;
        else if constexpr (cpp::is_tr<operator_p, just_not_non_qualified_tg>)   return !cpp::just_non_qualified_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, just_not_const_tg>)           return !cpp::just_const_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, just_not_volatile_tg>)        return !cpp::just_volatile_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, just_not_const_volatile_tg>)  return !cpp::just_const_volatile_tr<subject_t>;

        else                                                                    static_assert(false, "undefined or invalid operator");
    }

    template <
        typename subject_p,
        typename operator_p, typename operand_p
    > constexpr cpp::bool_t
        TR1()
        noexcept
    {
        using subject_t = subject_p;
        using object_t = operand_p;

        if constexpr (to_operator_tr<operator_p>) {
            if constexpr (not_operator_tr<operator_p>) {
                return !(TR0<subject_t, typename operator_p::base_tg::is_tg>() && cpp::to_tr<subject_t, object_t>);
            } else {
                return TR0<subject_t, typename operator_p::base_tg>() && cpp::to_tr<subject_t, object_t>;
            }
        } else {
            if constexpr (type_i<object_t>::template Is_Any<cpp::just_non_qualified_t<subject_t>>()) {
                if constexpr (cpp::is_tr<operator_p, just_tg>) {
                    return cpp::is_tr<object_t, cpp::same_qualification_as_t<object_t, subject_p>>;
                } else if constexpr (cpp::is_tr<operator_p, just_not_tg>) {
                    return !cpp::is_tr<object_t, cpp::same_qualification_as_t<object_t, subject_p>>;
                } else {
                    return TR0<subject_t, operator_p>();
                }
            } else {
                return not_operator_tr<operator_p>;
            }
        }
    }

    template <
        typename subject_p,
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > constexpr cpp::bool_t
        TR2()
        noexcept
    {
        static_assert(template_i<operand_p>::Is_Implemented());

        using subject_t = subject_p;
        using of_subject_t = access_or_not_t<typename type_i<subject_t>::of_t, subject_t, access_operator_tr<of_operator_p>>;
        using object_t = template_i<operand_p>::template type_t<of_operand_p>;
        using of_object_t = of_operand_p;

        if constexpr (not_operator_tr<operator_p>) {
            return
                !(TR1<subject_t, typename operator_p::is_tg, object_t>() &&
                  TR1<of_subject_t, typename of_operator_p::base_tg, of_object_t>());
        } else {
            return
                TR1<subject_t, operator_p, object_t>() &&
                TR1<of_subject_t, typename of_operator_p::base_tg, of_object_t>();
        }
    }

    template <
        typename subject_p,
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > constexpr cpp::bool_t
        TR3()
        noexcept
    {
        static_assert(template_i<of_operand_p>::Is_Implemented());

        using subject_t = subject_p;
        using of_subject_t = access_or_not_t<typename type_i<subject_t>::of_t, subject_t, access_operator_tr<of_of_operator_p>>;
        using of_of_subject_t = access_or_not_t<typename type_i<of_subject_t>::of_t, of_subject_t, access_operator_tr<of_of_operator_p>>;
        using of_object_t = template_i<of_operand_p>::template type_t<of_of_operand_p>;
        using of_of_object_t = of_of_operand_p;

        if constexpr (not_operator_tr<operator_p>) {
            return
                !(TR2<subject_t, typename operator_p::is_tg, operand_p, of_operator_p, of_object_t>() &&
                  TR1<of_of_subject_t, typename of_of_operator_p::base_tg, of_of_object_t>());
        } else {
            return
                TR2<subject_t, operator_p, operand_p, of_operator_p, of_object_t>() &&
                TR1<of_of_subject_t, typename of_of_operator_p::base_tg, of_of_object_t>();
        }
    }

}}

namespace nkr {

    template <
        typename subject_p,
        typename operator_p
    > concept tr0 =
        $tr::TR0<subject_p, operator_p>();

    template <
        typename subject_p,
        typename operator_p, typename operand_p
    > concept tr1 =
        $tr::TR1<subject_p, operator_p, operand_p>();

    template <
        typename subject_p,
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > concept tr2 =
        $tr::TR2<subject_p, operator_p, operand_p, of_operator_p, of_operand_p>();

    template <
        typename subject_p,
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > concept tr3 =
        $tr::TR3<subject_p, operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>();

}
