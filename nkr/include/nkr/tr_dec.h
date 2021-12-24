/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/template_i_dec.h"
#include "nkr/interface/type_i_dec.h"

namespace nkr {

    struct  any_tg                                  { class any_t; };
    struct  any_qualified_tg                        { class any_t; };
    struct  any_non_qualified_tg                    { class any_t; };
    struct  any_const_tg                            { class any_t; };
    struct  any_non_const_tg                        { class any_t; };
    struct  any_volatile_tg                         { class any_t; };
    struct  any_non_volatile_tg                     { class any_t; };

    struct  just_tg                                 { class just_t; };
    struct  just_non_qualified_tg                   { class just_t; };
    struct  just_const_tg                           { class just_t; };
    struct  just_volatile_tg                        { class just_t; };
    struct  just_const_volatile_tg                  { class just_t; };

    struct  not_any_tg                              { class not_t; class any_t; using is_tg = any_tg; };
    struct  not_any_qualified_tg                    { class not_t; class any_t; using is_tg = any_qualified_tg; };
    struct  not_any_non_qualified_tg                { class not_t; class any_t; using is_tg = any_non_qualified_tg; };
    struct  not_any_const_tg                        { class not_t; class any_t; using is_tg = any_const_tg; };
    struct  not_any_non_const_tg                    { class not_t; class any_t; using is_tg = any_non_const_tg; };
    struct  not_any_volatile_tg                     { class not_t; class any_t; using is_tg = any_volatile_tg; };
    struct  not_any_non_volatile_tg                 { class not_t; class any_t; using is_tg = any_non_volatile_tg; };

    struct  just_not_tg                             { class just_t; class not_t; using is_tg = just_tg; };
    struct  just_not_non_qualified_tg               { class just_t; class not_t; using is_tg = just_non_qualified_tg; };
    struct  just_not_const_tg                       { class just_t; class not_t; using is_tg = just_const_tg; };
    struct  just_not_volatile_tg                    { class just_t; class not_t; using is_tg = just_volatile_tg; };
    struct  just_not_const_volatile_tg              { class just_t; class not_t; using is_tg = just_const_volatile_tg; };

    struct  any_to_tg                               { class any_t; class to_t; using base_tg = any_tg; };
    struct  any_qualified_to_tg                     { class any_t; class to_t; using base_tg = any_qualified_tg; };
    struct  any_non_qualified_to_tg                 { class any_t; class to_t; using base_tg = any_non_qualified_tg; };
    struct  any_const_to_tg                         { class any_t; class to_t; using base_tg = any_const_tg; };
    struct  any_non_const_to_tg                     { class any_t; class to_t; using base_tg = any_non_const_tg; };
    struct  any_volatile_to_tg                      { class any_t; class to_t; using base_tg = any_volatile_tg; };
    struct  any_non_volatile_to_tg                  { class any_t; class to_t; using base_tg = any_non_volatile_tg; };

    struct  just_to_tg                              { class just_t; class to_t; using base_tg = just_tg; };
    struct  just_non_qualified_to_tg                { class just_t; class to_t; using base_tg = just_non_qualified_tg; };
    struct  just_const_to_tg                        { class just_t; class to_t; using base_tg = just_const_tg; };
    struct  just_volatile_to_tg                     { class just_t; class to_t; using base_tg = just_volatile_tg; };
    struct  just_const_volatile_to_tg               { class just_t; class to_t; using base_tg = just_const_volatile_tg; };

    struct  not_any_to_tg                           { class not_t; class any_t; class to_t; using base_tg = not_any_tg; };
    struct  not_any_qualified_to_tg                 { class not_t; class any_t; class to_t; using base_tg = not_any_qualified_tg; };
    struct  not_any_non_qualified_to_tg             { class not_t; class any_t; class to_t; using base_tg = not_any_non_qualified_tg; };
    struct  not_any_const_to_tg                     { class not_t; class any_t; class to_t; using base_tg = not_any_const_tg; };
    struct  not_any_non_const_to_tg                 { class not_t; class any_t; class to_t; using base_tg = not_any_non_const_tg; };
    struct  not_any_volatile_to_tg                  { class not_t; class any_t; class to_t; using base_tg = not_any_volatile_tg; };
    struct  not_any_non_volatile_to_tg              { class not_t; class any_t; class to_t; using base_tg = not_any_non_volatile_tg; };

    struct  just_not_to_tg                          { class just_t; class not_t; class to_t; using base_tg = just_not_tg; };
    struct  just_not_non_qualified_to_tg            { class just_t; class not_t; class to_t; using base_tg = just_not_non_qualified_tg; };
    struct  just_not_const_to_tg                    { class just_t; class not_t; class to_t; using base_tg = just_not_const_tg; };
    struct  just_not_volatile_to_tg                 { class just_t; class not_t; class to_t; using base_tg = just_not_volatile_tg; };
    struct  just_not_const_volatile_to_tg           { class just_t; class not_t; class to_t; using base_tg = just_not_const_volatile_tg; };

    struct  of_any_tg                               { class of_t; class any_t; using base_tg = any_tg; };
    struct  of_any_qualified_tg                     { class of_t; class any_t; using base_tg = any_qualified_tg; };
    struct  of_any_non_qualified_tg                 { class of_t; class any_t; using base_tg = any_non_qualified_tg; };
    struct  of_any_const_tg                         { class of_t; class any_t; using base_tg = any_const_tg; };
    struct  of_any_non_const_tg                     { class of_t; class any_t; using base_tg = any_non_const_tg; };
    struct  of_any_volatile_tg                      { class of_t; class any_t; using base_tg = any_volatile_tg; };
    struct  of_any_non_volatile_tg                  { class of_t; class any_t; using base_tg = any_non_volatile_tg; };

    struct  of_just_tg                              { class of_t; class just_t; using base_tg = just_tg; };
    struct  of_just_non_qualified_tg                { class of_t; class just_t; using base_tg = just_non_qualified_tg; };
    struct  of_just_const_tg                        { class of_t; class just_t; using base_tg = just_const_tg; };
    struct  of_just_volatile_tg                     { class of_t; class just_t; using base_tg = just_volatile_tg; };
    struct  of_just_const_volatile_tg               { class of_t; class just_t; using base_tg = just_const_volatile_tg; };

    struct  of_not_any_tg                           { class of_t; class not_t; class any_t; using base_tg = not_any_tg; };
    struct  of_not_any_qualified_tg                 { class of_t; class not_t; class any_t; using base_tg = not_any_qualified_tg; };
    struct  of_not_any_non_qualified_tg             { class of_t; class not_t; class any_t; using base_tg = not_any_non_qualified_tg; };
    struct  of_not_any_const_tg                     { class of_t; class not_t; class any_t; using base_tg = not_any_const_tg; };
    struct  of_not_any_non_const_tg                 { class of_t; class not_t; class any_t; using base_tg = not_any_non_const_tg; };
    struct  of_not_any_volatile_tg                  { class of_t; class not_t; class any_t; using base_tg = not_any_volatile_tg; };
    struct  of_not_any_non_volatile_tg              { class of_t; class not_t; class any_t; using base_tg = not_any_non_volatile_tg; };

    struct  of_just_not_tg                          { class of_t; class just_t; class not_t; using base_tg = just_not_tg; };
    struct  of_just_not_non_qualified_tg            { class of_t; class just_t; class not_t; using base_tg = just_not_non_qualified_tg; };
    struct  of_just_not_const_tg                    { class of_t; class just_t; class not_t; using base_tg = just_not_const_tg; };
    struct  of_just_not_volatile_tg                 { class of_t; class just_t; class not_t; using base_tg = just_not_volatile_tg; };
    struct  of_just_not_const_volatile_tg           { class of_t; class just_t; class not_t; using base_tg = just_not_const_volatile_tg; };

    struct  of_any_access_tg                        { class of_t; class any_t; class access_t; using base_tg = any_tg; };
    struct  of_any_access_qualified_tg              { class of_t; class any_t; class access_t; using base_tg = any_qualified_tg; };
    struct  of_any_access_non_qualified_tg          { class of_t; class any_t; class access_t; using base_tg = any_non_qualified_tg; };
    struct  of_any_access_const_tg                  { class of_t; class any_t; class access_t; using base_tg = any_const_tg; };
    struct  of_any_access_non_const_tg              { class of_t; class any_t; class access_t; using base_tg = any_non_const_tg; };
    struct  of_any_access_volatile_tg               { class of_t; class any_t; class access_t; using base_tg = any_volatile_tg; };
    struct  of_any_access_non_volatile_tg           { class of_t; class any_t; class access_t; using base_tg = any_non_volatile_tg; };

    struct  of_just_access_tg                       { class of_t; class just_t; class access_t; using base_tg = just_tg; };
    struct  of_just_access_non_qualified_tg         { class of_t; class just_t; class access_t; using base_tg = just_non_qualified_tg; };
    struct  of_just_access_const_tg                 { class of_t; class just_t; class access_t; using base_tg = just_const_tg; };
    struct  of_just_access_volatile_tg              { class of_t; class just_t; class access_t; using base_tg = just_volatile_tg; };
    struct  of_just_access_const_volatile_tg        { class of_t; class just_t; class access_t; using base_tg = just_const_volatile_tg; };

    struct  of_not_any_access_tg                    { class of_t; class not_t; class any_t; class access_t; using base_tg = not_any_tg; };
    struct  of_not_any_access_qualified_tg          { class of_t; class not_t; class any_t; class access_t; using base_tg = not_any_qualified_tg; };
    struct  of_not_any_access_non_qualified_tg      { class of_t; class not_t; class any_t; class access_t; using base_tg = not_any_non_qualified_tg; };
    struct  of_not_any_access_const_tg              { class of_t; class not_t; class any_t; class access_t; using base_tg = not_any_const_tg; };
    struct  of_not_any_access_non_const_tg          { class of_t; class not_t; class any_t; class access_t; using base_tg = not_any_non_const_tg; };
    struct  of_not_any_access_volatile_tg           { class of_t; class not_t; class any_t; class access_t; using base_tg = not_any_volatile_tg; };
    struct  of_not_any_access_non_volatile_tg       { class of_t; class not_t; class any_t; class access_t; using base_tg = not_any_non_volatile_tg; };

    struct  of_just_not_access_tg                   { class of_t; class just_t; class not_t; class access_t; using base_tg = just_not_tg; };
    struct  of_just_not_access_non_qualified_tg     { class of_t; class just_t; class not_t; class access_t; using base_tg = just_not_non_qualified_tg; };
    struct  of_just_not_access_const_tg             { class of_t; class just_t; class not_t; class access_t; using base_tg = just_not_const_tg; };
    struct  of_just_not_access_volatile_tg          { class of_t; class just_t; class not_t; class access_t; using base_tg = just_not_volatile_tg; };
    struct  of_just_not_access_const_volatile_tg    { class of_t; class just_t; class not_t; class access_t; using base_tg = just_not_const_volatile_tg; };

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

}}

namespace nkr { namespace $tr {

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

}}

namespace nkr { namespace $tr {

    template <typename child_p, typename parent_p, boolean::cpp_t do_access_p>
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

    template <typename child_p, typename parent_p, boolean::cpp_t do_access_p>
    using access_or_not_t   = access_or_not_tmpl<child_p, parent_p, do_access_p>::type_t;

}}

namespace nkr { namespace $tr {

    template <
        typename subject_p,
        typename operator_p
    > constexpr boolean::cpp_t  TR0() noexcept;

    template <
        typename subject_p,
        typename operator_p, typename operand_p
    > constexpr boolean::cpp_t  TR1() noexcept;

    template <
        typename subject_p,
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > constexpr boolean::cpp_t  TR2() noexcept;

    template <
        typename subject_p,
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > constexpr boolean::cpp_t  TR3() noexcept;

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

#include "nkr/tr_dec_def.h"
