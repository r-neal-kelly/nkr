/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/boolean/cpp_t_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/constant/positive/index_t_dec.h"
#include "nkr/generic/implementing/interface/template_tr_dec.h"
#include "nkr/generic/implementing/interface/type_tr_dec.h"
#include "nkr/generic/tag/logic_gate_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/tuple/templates_t_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr {

    struct  any_tg                      { class operator_t; class any_t;                                        using non_of_tg = any_tg;                       using is_tg = any_tg; };
    struct  any_qualified_tg            { class operator_t; class any_t; class qualified_t;                     using non_of_tg = any_qualified_tg;             using is_tg = any_qualified_tg; };
    struct  any_non_qualified_tg        { class operator_t; class any_t; class non_qualified_t;                 using non_of_tg = any_non_qualified_tg;         using is_tg = any_non_qualified_tg; };
    struct  any_const_tg                { class operator_t; class any_t; class const_t;                         using non_of_tg = any_const_tg;                 using is_tg = any_const_tg; };
    struct  any_non_const_tg            { class operator_t; class any_t; class non_const_t;                     using non_of_tg = any_non_const_tg;             using is_tg = any_non_const_tg; };
    struct  any_volatile_tg             { class operator_t; class any_t; class volatile_t;                      using non_of_tg = any_volatile_tg;              using is_tg = any_volatile_tg; };
    struct  any_non_volatile_tg         { class operator_t; class any_t; class non_volatile_t;                  using non_of_tg = any_non_volatile_tg;          using is_tg = any_non_volatile_tg; };

    struct  just_tg                     { class operator_t; class just_t;                                       using non_of_tg = just_tg;                      using is_tg = just_tg; };
    struct  just_non_qualified_tg       { class operator_t; class just_t; class non_qualified_t;                using non_of_tg = just_non_qualified_tg;        using is_tg = just_non_qualified_tg; };
    struct  just_const_tg               { class operator_t; class just_t; class const_t;                        using non_of_tg = just_const_tg;                using is_tg = just_const_tg; };
    struct  just_volatile_tg            { class operator_t; class just_t; class volatile_t;                     using non_of_tg = just_volatile_tg;             using is_tg = just_volatile_tg; };
    struct  just_const_volatile_tg      { class operator_t; class just_t; class const_volatile_t;               using non_of_tg = just_const_volatile_tg;       using is_tg = just_const_volatile_tg; };

    struct  not_any_tg                  { class operator_t; class not_t; class any_t;                           using non_of_tg = not_any_tg;                   using is_tg = any_tg; };
    struct  not_any_qualified_tg        { class operator_t; class not_t; class any_t; class qualified_t;        using non_of_tg = not_any_qualified_tg;         using is_tg = any_qualified_tg; };
    struct  not_any_non_qualified_tg    { class operator_t; class not_t; class any_t; class non_qualified_t;    using non_of_tg = not_any_non_qualified_tg;     using is_tg = any_non_qualified_tg; };
    struct  not_any_const_tg            { class operator_t; class not_t; class any_t; class const_t;            using non_of_tg = not_any_const_tg;             using is_tg = any_const_tg; };
    struct  not_any_non_const_tg        { class operator_t; class not_t; class any_t; class non_const_t;        using non_of_tg = not_any_non_const_tg;         using is_tg = any_non_const_tg; };
    struct  not_any_volatile_tg         { class operator_t; class not_t; class any_t; class volatile_t;         using non_of_tg = not_any_volatile_tg;          using is_tg = any_volatile_tg; };
    struct  not_any_non_volatile_tg     { class operator_t; class not_t; class any_t; class non_volatile_t;     using non_of_tg = not_any_non_volatile_tg;      using is_tg = any_non_volatile_tg; };

    struct  just_not_tg                 { class operator_t; class just_t; class not_t;                          using non_of_tg = just_not_tg;                  using is_tg = just_tg; };
    struct  just_not_non_qualified_tg   { class operator_t; class just_t; class not_t; class non_qualified_t;   using non_of_tg = just_not_non_qualified_tg;    using is_tg = just_non_qualified_tg; };
    struct  just_not_const_tg           { class operator_t; class just_t; class not_t; class const_t;           using non_of_tg = just_not_const_tg;            using is_tg = just_const_tg; };
    struct  just_not_volatile_tg        { class operator_t; class just_t; class not_t; class volatile_t;        using non_of_tg = just_not_volatile_tg;         using is_tg = just_volatile_tg; };
    struct  just_not_const_volatile_tg  { class operator_t; class just_t; class not_t; class const_volatile_t;  using non_of_tg = just_not_const_volatile_tg;   using is_tg = just_const_volatile_tg; };

}

namespace nkr {

    struct  of_any_tg                       { class operator_t; class of_t; class any_t;                                        using non_of_tg = any_tg; };
    struct  of_any_qualified_tg             { class operator_t; class of_t; class any_t; class qualified_t;                     using non_of_tg = any_qualified_tg; };
    struct  of_any_non_qualified_tg         { class operator_t; class of_t; class any_t; class non_qualified_t;                 using non_of_tg = any_non_qualified_tg; };
    struct  of_any_const_tg                 { class operator_t; class of_t; class any_t; class const_t;                         using non_of_tg = any_const_tg; };
    struct  of_any_non_const_tg             { class operator_t; class of_t; class any_t; class non_const_t;                     using non_of_tg = any_non_const_tg; };
    struct  of_any_volatile_tg              { class operator_t; class of_t; class any_t; class volatile_t;                      using non_of_tg = any_volatile_tg; };
    struct  of_any_non_volatile_tg          { class operator_t; class of_t; class any_t; class non_volatile_t;                  using non_of_tg = any_non_volatile_tg; };

    struct  of_just_tg                      { class operator_t; class of_t; class just_t;                                       using non_of_tg = just_tg; };
    struct  of_just_non_qualified_tg        { class operator_t; class of_t; class just_t; class non_qualified_t;                using non_of_tg = just_non_qualified_tg; };
    struct  of_just_const_tg                { class operator_t; class of_t; class just_t; class const_t;                        using non_of_tg = just_const_tg; };
    struct  of_just_volatile_tg             { class operator_t; class of_t; class just_t; class volatile_t;                     using non_of_tg = just_volatile_tg; };
    struct  of_just_const_volatile_tg       { class operator_t; class of_t; class just_t; class const_volatile_t;               using non_of_tg = just_const_volatile_tg; };

    struct  of_not_any_tg                   { class operator_t; class of_t; class not_t; class any_t;                           using non_of_tg = not_any_tg; };
    struct  of_not_any_qualified_tg         { class operator_t; class of_t; class not_t; class any_t; class qualified_t;        using non_of_tg = not_any_qualified_tg; };
    struct  of_not_any_non_qualified_tg     { class operator_t; class of_t; class not_t; class any_t; class non_qualified_t;    using non_of_tg = not_any_non_qualified_tg; };
    struct  of_not_any_const_tg             { class operator_t; class of_t; class not_t; class any_t; class const_t;            using non_of_tg = not_any_const_tg; };
    struct  of_not_any_non_const_tg         { class operator_t; class of_t; class not_t; class any_t; class non_const_t;        using non_of_tg = not_any_non_const_tg; };
    struct  of_not_any_volatile_tg          { class operator_t; class of_t; class not_t; class any_t; class volatile_t;         using non_of_tg = not_any_volatile_tg; };
    struct  of_not_any_non_volatile_tg      { class operator_t; class of_t; class not_t; class any_t; class non_volatile_t;     using non_of_tg = not_any_non_volatile_tg; };

    struct  of_just_not_tg                  { class operator_t; class of_t; class just_t; class not_t;                          using non_of_tg = just_not_tg; };
    struct  of_just_not_non_qualified_tg    { class operator_t; class of_t; class just_t; class not_t; class non_qualified_t;   using non_of_tg = just_not_non_qualified_tg; };
    struct  of_just_not_const_tg            { class operator_t; class of_t; class just_t; class not_t; class const_t;           using non_of_tg = just_not_const_tg; };
    struct  of_just_not_volatile_tg         { class operator_t; class of_t; class just_t; class not_t; class volatile_t;        using non_of_tg = just_not_volatile_tg; };
    struct  of_just_not_const_volatile_tg   { class operator_t; class of_t; class just_t; class not_t; class const_volatile_t;  using non_of_tg = just_not_const_volatile_tg; };

}

namespace nkr {

    struct  of_any_access_tg                        { class operator_t; class of_t; class any_t; class access_t;                                        using non_of_tg = any_tg; };
    struct  of_any_access_qualified_tg              { class operator_t; class of_t; class any_t; class access_t; class qualified_t;                     using non_of_tg = any_qualified_tg; };
    struct  of_any_access_non_qualified_tg          { class operator_t; class of_t; class any_t; class access_t; class non_qualified_t;                 using non_of_tg = any_non_qualified_tg; };
    struct  of_any_access_const_tg                  { class operator_t; class of_t; class any_t; class access_t; class const_t;                         using non_of_tg = any_const_tg; };
    struct  of_any_access_non_const_tg              { class operator_t; class of_t; class any_t; class access_t; class non_const_t;                     using non_of_tg = any_non_const_tg; };
    struct  of_any_access_volatile_tg               { class operator_t; class of_t; class any_t; class access_t; class volatile_t;                      using non_of_tg = any_volatile_tg; };
    struct  of_any_access_non_volatile_tg           { class operator_t; class of_t; class any_t; class access_t; class non_volatile_t;                  using non_of_tg = any_non_volatile_tg; };

    struct  of_just_access_tg                       { class operator_t; class of_t; class just_t; class access_t;                                       using non_of_tg = just_tg; };
    struct  of_just_access_non_qualified_tg         { class operator_t; class of_t; class just_t; class access_t; class non_qualified_t;                using non_of_tg = just_non_qualified_tg; };
    struct  of_just_access_const_tg                 { class operator_t; class of_t; class just_t; class access_t; class const_t;                        using non_of_tg = just_const_tg; };
    struct  of_just_access_volatile_tg              { class operator_t; class of_t; class just_t; class access_t; class volatile_t;                     using non_of_tg = just_volatile_tg; };
    struct  of_just_access_const_volatile_tg        { class operator_t; class of_t; class just_t; class access_t; class const_volatile_t;               using non_of_tg = just_const_volatile_tg; };

    struct  of_not_any_access_tg                    { class operator_t; class of_t; class not_t; class any_t; class access_t;                           using non_of_tg = not_any_tg; };
    struct  of_not_any_access_qualified_tg          { class operator_t; class of_t; class not_t; class any_t; class access_t; class qualified_t;        using non_of_tg = not_any_qualified_tg; };
    struct  of_not_any_access_non_qualified_tg      { class operator_t; class of_t; class not_t; class any_t; class access_t; class non_qualified_t;    using non_of_tg = not_any_non_qualified_tg; };
    struct  of_not_any_access_const_tg              { class operator_t; class of_t; class not_t; class any_t; class access_t; class const_t;            using non_of_tg = not_any_const_tg; };
    struct  of_not_any_access_non_const_tg          { class operator_t; class of_t; class not_t; class any_t; class access_t; class non_const_t;        using non_of_tg = not_any_non_const_tg; };
    struct  of_not_any_access_volatile_tg           { class operator_t; class of_t; class not_t; class any_t; class access_t; class volatile_t;         using non_of_tg = not_any_volatile_tg; };
    struct  of_not_any_access_non_volatile_tg       { class operator_t; class of_t; class not_t; class any_t; class access_t; class non_volatile_t;     using non_of_tg = not_any_non_volatile_tg; };

    struct  of_just_not_access_tg                   { class operator_t; class of_t; class just_t; class not_t; class access_t;                          using non_of_tg = just_not_tg; };
    struct  of_just_not_access_non_qualified_tg     { class operator_t; class of_t; class just_t; class not_t; class access_t; class non_qualified_t;   using non_of_tg = just_not_non_qualified_tg; };
    struct  of_just_not_access_const_tg             { class operator_t; class of_t; class just_t; class not_t; class access_t; class const_t;           using non_of_tg = just_not_const_tg; };
    struct  of_just_not_access_volatile_tg          { class operator_t; class of_t; class just_t; class not_t; class access_t; class volatile_t;        using non_of_tg = just_not_volatile_tg; };
    struct  of_just_not_access_const_volatile_tg    { class operator_t; class of_t; class just_t; class not_t; class access_t; class const_volatile_t;  using non_of_tg = just_not_const_volatile_tg; };

}

namespace nkr {

    struct  to_tg       { class operator_t; class to_t;                 using non_of_tg = to_tg;        using is_tg = to_tg; };
    struct  not_to_tg   { class operator_t; class not_t; class to_t;    using non_of_tg = not_to_tg;    using is_tg = to_tg; };

}

namespace nkr {

    struct  OR_tg   { class operator_t; class logic_gate_t; class OR_t; };
    struct  AND_tg  { class operator_t; class logic_gate_t; class AND_t; };
    struct  XOR_tg  { class operator_t; class logic_gate_t; class XOR_t; };
    struct  NOR_tg  { class operator_t; class logic_gate_t; class NOR_t; };
    struct  NAND_tg { class operator_t; class logic_gate_t; class NAND_t; };
    struct  XNOR_tg { class operator_t; class logic_gate_t; class XNOR_t; };

}

namespace nkr { namespace $tr {

    template <nkr::generic::tag::logic_gate_tr operator_p, nkr::tuple::types_tr types_p>
    class ts :
        public types_p
    {
    public:
        using operator_t        = operator_p;
        using types_t           = types_p;

        using tail_t            = ts<operator_t, typename types_t::tail_t>;
        template <nkr::constant::positive::count_tr count_p>
            requires (count_p::Value() <= types_t::Count())
        using take_t            = ts<operator_t, typename types_t::template take_t<count_p>>;

        template <nkr::generic::tag::logic_gate_tr with_operator_p>
        using with_operator_t   = ts<with_operator_p, types_t>;
    };

    template <nkr::generic::tag::logic_gate_tr operator_p, nkr::tuple::templates_tr templates_p>
    class tts :
        public templates_p
    {
    public:
        using operator_t        = operator_p;
        using templates_t       = templates_p;

        using tail_t            = tts<operator_t, typename templates_t::tail_t>;
        template <nkr::constant::positive::count_tr count_p>
            requires (count_p::Value() <= templates_t::Count())
        using take_t            = tts<operator_t, typename templates_t::template take_t<count_p>>;

        template <nkr::generic::tag::logic_gate_tr with_operator_p>
        using with_operator_t   = tts<with_operator_p, templates_t>;
    };

}}

namespace nkr {

    template <typename type_p>
    using   t =
        nkr::$tr::ts<AND_tg, nkr::tuple::types_t<type_p>>;

    template <nkr::generic::tag::logic_gate_tr operator_p, typename ...types_p>
        requires (nkr::tuple::types_t<types_p...>::Count() > 0)
    using   ts =
        nkr::$tr::ts<operator_p, nkr::tuple::types_t<types_p...>>;

    template <typename type_p>
    concept ts_tr =
        nkr::cpp::is_any_tr<type_p, typename nkr::$tr::ts<typename type_p::operator_t, typename type_p::types_t>>;

    template <template <typename ...> typename template_p>
    using   tt =
        nkr::$tr::tts<AND_tg, nkr::tuple::templates_t<template_p>>;

    template <nkr::generic::tag::logic_gate_tr operator_p, template <typename ...> typename ...templates_p>
        requires (nkr::tuple::templates_t<templates_p...>::Count() > 0)
    using   tts =
        nkr::$tr::tts<operator_p, nkr::tuple::templates_t<templates_p...>>;

    template <typename type_p>
    concept tts_tr =
        nkr::cpp::is_any_tr<type_p, typename nkr::$tr::tts<typename type_p::operator_t, typename type_p::templates_t>>;

}

namespace nkr { namespace $tr {

    template <nkr::generic::tag::logic_gate_tr operator_p, typename type_p>
    class to_ts_sp;

    template <nkr::generic::tag::logic_gate_tr operator_p, nkr::tuple::types_tr tuple_p>
    class to_ts_sp<operator_p, tuple_p>
    {
    public:
        using type_t    = ts<operator_p, tuple_p>;
    };

    template <nkr::generic::tag::logic_gate_tr operator_p, nkr::ts_tr ts_p>
    class to_ts_sp<operator_p, ts_p>
    {
    public:
        using type_t    = ts<operator_p, typename ts_p::types_t>;
    };

    template <nkr::generic::tag::logic_gate_tr operator_p, typename type_p>
    class to_tts_sp;

    template <nkr::generic::tag::logic_gate_tr operator_p, nkr::tuple::templates_tr tuple_p>
    class to_tts_sp<operator_p, tuple_p>
    {
    public:
        using type_t    = tts<operator_p, tuple_p>;
    };

    template <nkr::generic::tag::logic_gate_tr operator_p, nkr::tts_tr tts_p>
    class to_tts_sp<operator_p, tts_p>
    {
    public:
        using type_t    = tts<operator_p, typename tts_p::templates_t>;
    };

}}

namespace nkr {

    template <nkr::generic::tag::logic_gate_tr operator_p, typename type_p>
    using   to_ts =
        nkr::$tr::to_ts_sp<operator_p, type_p>::type_t;

    template <nkr::generic::tag::logic_gate_tr operator_p, typename type_p>
    using   to_tts =
        nkr::$tr::to_tts_sp<operator_p, type_p>::type_t;

}

namespace nkr {

    template <
        nkr::ts_tr  subjects_p,
        typename    ...expression_parts_p
    > constexpr nkr::boolean::cpp_t TR() noexcept;

    template <
        typename    subject_p,
        typename    ...expression_parts_p
    > concept tr =
        TR<t<subject_p>, expression_parts_p...>();

}

// We should have another like type called 'ttr' which can take templates of types.
// Likewise we might even have a 'tttr' for templates of templates of types.

#include "nkr/tr_dec_def.h"
