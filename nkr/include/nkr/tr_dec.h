/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_aebfd2a0_5752_4723_9b49_23e5a372eaf4
#define nkr_INCLUDE_GUARD_aebfd2a0_5752_4723_9b49_23e5a372eaf4

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/boolean/cpp_t_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/constant/positive/index_t_dec.h"
#include "nkr/generic/implementing/interface/template_tr_dec.h"
#include "nkr/generic/implementing/interface/type_tr_dec.h"
#include "nkr/generic/tag_tr_dec.h"
#include "nkr/generic/tag/logic_gate_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/tuple/templates_t_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr {

    struct  any_tg                      { class tag_lb; class operator_lb; class any_lb;                                            using non_of_tg = any_tg;                       using is_tg = any_tg; };
    struct  any_qualified_tg            { class tag_lb; class operator_lb; class any_lb; class qualified_lb;                        using non_of_tg = any_qualified_tg;             using is_tg = any_qualified_tg; };
    struct  any_non_qualified_tg        { class tag_lb; class operator_lb; class any_lb; class non_qualified_lb;                    using non_of_tg = any_non_qualified_tg;         using is_tg = any_non_qualified_tg; };
    struct  any_const_tg                { class tag_lb; class operator_lb; class any_lb; class const_lb;                            using non_of_tg = any_const_tg;                 using is_tg = any_const_tg; };
    struct  any_non_const_tg            { class tag_lb; class operator_lb; class any_lb; class non_const_lb;                        using non_of_tg = any_non_const_tg;             using is_tg = any_non_const_tg; };
    struct  any_volatile_tg             { class tag_lb; class operator_lb; class any_lb; class volatile_lb;                         using non_of_tg = any_volatile_tg;              using is_tg = any_volatile_tg; };
    struct  any_non_volatile_tg         { class tag_lb; class operator_lb; class any_lb; class non_volatile_lb;                     using non_of_tg = any_non_volatile_tg;          using is_tg = any_non_volatile_tg; };

    struct  just_tg                     { class tag_lb; class operator_lb; class just_lb;                                           using non_of_tg = just_tg;                      using is_tg = just_tg; };
    struct  just_non_qualified_tg       { class tag_lb; class operator_lb; class just_lb; class non_qualified_lb;                   using non_of_tg = just_non_qualified_tg;        using is_tg = just_non_qualified_tg; };
    struct  just_const_tg               { class tag_lb; class operator_lb; class just_lb; class const_lb;                           using non_of_tg = just_const_tg;                using is_tg = just_const_tg; };
    struct  just_volatile_tg            { class tag_lb; class operator_lb; class just_lb; class volatile_lb;                        using non_of_tg = just_volatile_tg;             using is_tg = just_volatile_tg; };
    struct  just_const_volatile_tg      { class tag_lb; class operator_lb; class just_lb; class const_volatile_lb;                  using non_of_tg = just_const_volatile_tg;       using is_tg = just_const_volatile_tg; };

    struct  not_any_tg                  { class tag_lb; class operator_lb; class not_lb; class any_lb;                              using non_of_tg = not_any_tg;                   using is_tg = any_tg; };
    struct  not_any_qualified_tg        { class tag_lb; class operator_lb; class not_lb; class any_lb; class qualified_lb;          using non_of_tg = not_any_qualified_tg;         using is_tg = any_qualified_tg; };
    struct  not_any_non_qualified_tg    { class tag_lb; class operator_lb; class not_lb; class any_lb; class non_qualified_lb;      using non_of_tg = not_any_non_qualified_tg;     using is_tg = any_non_qualified_tg; };
    struct  not_any_const_tg            { class tag_lb; class operator_lb; class not_lb; class any_lb; class const_lb;              using non_of_tg = not_any_const_tg;             using is_tg = any_const_tg; };
    struct  not_any_non_const_tg        { class tag_lb; class operator_lb; class not_lb; class any_lb; class non_const_lb;          using non_of_tg = not_any_non_const_tg;         using is_tg = any_non_const_tg; };
    struct  not_any_volatile_tg         { class tag_lb; class operator_lb; class not_lb; class any_lb; class volatile_lb;           using non_of_tg = not_any_volatile_tg;          using is_tg = any_volatile_tg; };
    struct  not_any_non_volatile_tg     { class tag_lb; class operator_lb; class not_lb; class any_lb; class non_volatile_lb;       using non_of_tg = not_any_non_volatile_tg;      using is_tg = any_non_volatile_tg; };

    struct  just_not_tg                 { class tag_lb; class operator_lb; class just_lb; class not_lb;                             using non_of_tg = just_not_tg;                  using is_tg = just_tg; };
    struct  just_not_non_qualified_tg   { class tag_lb; class operator_lb; class just_lb; class not_lb; class non_qualified_lb;     using non_of_tg = just_not_non_qualified_tg;    using is_tg = just_non_qualified_tg; };
    struct  just_not_const_tg           { class tag_lb; class operator_lb; class just_lb; class not_lb; class const_lb;             using non_of_tg = just_not_const_tg;            using is_tg = just_const_tg; };
    struct  just_not_volatile_tg        { class tag_lb; class operator_lb; class just_lb; class not_lb; class volatile_lb;          using non_of_tg = just_not_volatile_tg;         using is_tg = just_volatile_tg; };
    struct  just_not_const_volatile_tg  { class tag_lb; class operator_lb; class just_lb; class not_lb; class const_volatile_lb;    using non_of_tg = just_not_const_volatile_tg;   using is_tg = just_const_volatile_tg; };

}

namespace nkr {

    struct  of_any_tg                       { class tag_lb; class operator_lb; class of_lb; class any_lb;                                           using non_of_tg = any_tg;                       using is_tg = of_any_tg; };
    struct  of_any_qualified_tg             { class tag_lb; class operator_lb; class of_lb; class any_lb; class qualified_lb;                       using non_of_tg = any_qualified_tg;             using is_tg = of_any_qualified_tg; };
    struct  of_any_non_qualified_tg         { class tag_lb; class operator_lb; class of_lb; class any_lb; class non_qualified_lb;                   using non_of_tg = any_non_qualified_tg;         using is_tg = of_any_non_qualified_tg; };
    struct  of_any_const_tg                 { class tag_lb; class operator_lb; class of_lb; class any_lb; class const_lb;                           using non_of_tg = any_const_tg;                 using is_tg = of_any_const_tg; };
    struct  of_any_non_const_tg             { class tag_lb; class operator_lb; class of_lb; class any_lb; class non_const_lb;                       using non_of_tg = any_non_const_tg;             using is_tg = of_any_non_const_tg; };
    struct  of_any_volatile_tg              { class tag_lb; class operator_lb; class of_lb; class any_lb; class volatile_lb;                        using non_of_tg = any_volatile_tg;              using is_tg = of_any_volatile_tg; };
    struct  of_any_non_volatile_tg          { class tag_lb; class operator_lb; class of_lb; class any_lb; class non_volatile_lb;                    using non_of_tg = any_non_volatile_tg;          using is_tg = of_any_non_volatile_tg; };

    struct  of_just_tg                      { class tag_lb; class operator_lb; class of_lb; class just_lb;                                          using non_of_tg = just_tg;                      using is_tg = of_just_tg; };
    struct  of_just_non_qualified_tg        { class tag_lb; class operator_lb; class of_lb; class just_lb; class non_qualified_lb;                  using non_of_tg = just_non_qualified_tg;        using is_tg = of_just_non_qualified_tg; };
    struct  of_just_const_tg                { class tag_lb; class operator_lb; class of_lb; class just_lb; class const_lb;                          using non_of_tg = just_const_tg;                using is_tg = of_just_const_tg; };
    struct  of_just_volatile_tg             { class tag_lb; class operator_lb; class of_lb; class just_lb; class volatile_lb;                       using non_of_tg = just_volatile_tg;             using is_tg = of_just_volatile_tg; };
    struct  of_just_const_volatile_tg       { class tag_lb; class operator_lb; class of_lb; class just_lb; class const_volatile_lb;                 using non_of_tg = just_const_volatile_tg;       using is_tg = of_just_const_volatile_tg; };

    struct  of_not_any_tg                   { class tag_lb; class operator_lb; class of_lb; class not_lb; class any_lb;                             using non_of_tg = not_any_tg;                   using is_tg = of_any_tg; };
    struct  of_not_any_qualified_tg         { class tag_lb; class operator_lb; class of_lb; class not_lb; class any_lb; class qualified_lb;         using non_of_tg = not_any_qualified_tg;         using is_tg = of_any_qualified_tg; };
    struct  of_not_any_non_qualified_tg     { class tag_lb; class operator_lb; class of_lb; class not_lb; class any_lb; class non_qualified_lb;     using non_of_tg = not_any_non_qualified_tg;     using is_tg = of_any_non_qualified_tg; };
    struct  of_not_any_const_tg             { class tag_lb; class operator_lb; class of_lb; class not_lb; class any_lb; class const_lb;             using non_of_tg = not_any_const_tg;             using is_tg = of_any_const_tg; };
    struct  of_not_any_non_const_tg         { class tag_lb; class operator_lb; class of_lb; class not_lb; class any_lb; class non_const_lb;         using non_of_tg = not_any_non_const_tg;         using is_tg = of_any_non_const_tg; };
    struct  of_not_any_volatile_tg          { class tag_lb; class operator_lb; class of_lb; class not_lb; class any_lb; class volatile_lb;          using non_of_tg = not_any_volatile_tg;          using is_tg = of_any_volatile_tg; };
    struct  of_not_any_non_volatile_tg      { class tag_lb; class operator_lb; class of_lb; class not_lb; class any_lb; class non_volatile_lb;      using non_of_tg = not_any_non_volatile_tg;      using is_tg = of_any_non_volatile_tg; };

    struct  of_just_not_tg                  { class tag_lb; class operator_lb; class of_lb; class just_lb; class not_lb;                            using non_of_tg = just_not_tg;                  using is_tg = of_just_tg; };
    struct  of_just_not_non_qualified_tg    { class tag_lb; class operator_lb; class of_lb; class just_lb; class not_lb; class non_qualified_lb;    using non_of_tg = just_not_non_qualified_tg;    using is_tg = of_just_non_qualified_tg; };
    struct  of_just_not_const_tg            { class tag_lb; class operator_lb; class of_lb; class just_lb; class not_lb; class const_lb;            using non_of_tg = just_not_const_tg;            using is_tg = of_just_const_tg; };
    struct  of_just_not_volatile_tg         { class tag_lb; class operator_lb; class of_lb; class just_lb; class not_lb; class volatile_lb;         using non_of_tg = just_not_volatile_tg;         using is_tg = of_just_volatile_tg; };
    struct  of_just_not_const_volatile_tg   { class tag_lb; class operator_lb; class of_lb; class just_lb; class not_lb; class const_volatile_lb;   using non_of_tg = just_not_const_volatile_tg;   using is_tg = of_just_const_volatile_tg; };

}

namespace nkr {

    struct  of_any_access_tg                        { class tag_lb; class operator_lb; class of_lb; class any_lb; class access_lb;                                          using non_of_tg = any_tg;                       using is_tg = of_any_access_tg; };
    struct  of_any_access_qualified_tg              { class tag_lb; class operator_lb; class of_lb; class any_lb; class access_lb; class qualified_lb;                      using non_of_tg = any_qualified_tg;             using is_tg = of_any_access_qualified_tg; };
    struct  of_any_access_non_qualified_tg          { class tag_lb; class operator_lb; class of_lb; class any_lb; class access_lb; class non_qualified_lb;                  using non_of_tg = any_non_qualified_tg;         using is_tg = of_any_access_non_qualified_tg; };
    struct  of_any_access_const_tg                  { class tag_lb; class operator_lb; class of_lb; class any_lb; class access_lb; class const_lb;                          using non_of_tg = any_const_tg;                 using is_tg = of_any_access_const_tg; };
    struct  of_any_access_non_const_tg              { class tag_lb; class operator_lb; class of_lb; class any_lb; class access_lb; class non_const_lb;                      using non_of_tg = any_non_const_tg;             using is_tg = of_any_access_non_const_tg; };
    struct  of_any_access_volatile_tg               { class tag_lb; class operator_lb; class of_lb; class any_lb; class access_lb; class volatile_lb;                       using non_of_tg = any_volatile_tg;              using is_tg = of_any_access_volatile_tg; };
    struct  of_any_access_non_volatile_tg           { class tag_lb; class operator_lb; class of_lb; class any_lb; class access_lb; class non_volatile_lb;                   using non_of_tg = any_non_volatile_tg;          using is_tg = of_any_access_non_volatile_tg; };

    struct  of_just_access_tg                       { class tag_lb; class operator_lb; class of_lb; class just_lb; class access_lb;                                         using non_of_tg = just_tg;                      using is_tg = of_just_access_tg; };
    struct  of_just_access_non_qualified_tg         { class tag_lb; class operator_lb; class of_lb; class just_lb; class access_lb; class non_qualified_lb;                 using non_of_tg = just_non_qualified_tg;        using is_tg = of_just_access_non_qualified_tg; };
    struct  of_just_access_const_tg                 { class tag_lb; class operator_lb; class of_lb; class just_lb; class access_lb; class const_lb;                         using non_of_tg = just_const_tg;                using is_tg = of_just_access_const_tg; };
    struct  of_just_access_volatile_tg              { class tag_lb; class operator_lb; class of_lb; class just_lb; class access_lb; class volatile_lb;                      using non_of_tg = just_volatile_tg;             using is_tg = of_just_access_volatile_tg; };
    struct  of_just_access_const_volatile_tg        { class tag_lb; class operator_lb; class of_lb; class just_lb; class access_lb; class const_volatile_lb;                using non_of_tg = just_const_volatile_tg;       using is_tg = of_just_access_const_volatile_tg; };

    struct  of_not_any_access_tg                    { class tag_lb; class operator_lb; class of_lb; class not_lb; class any_lb; class access_lb;                            using non_of_tg = not_any_tg;                   using is_tg = of_any_access_tg; };
    struct  of_not_any_access_qualified_tg          { class tag_lb; class operator_lb; class of_lb; class not_lb; class any_lb; class access_lb; class qualified_lb;        using non_of_tg = not_any_qualified_tg;         using is_tg = of_any_access_qualified_tg; };
    struct  of_not_any_access_non_qualified_tg      { class tag_lb; class operator_lb; class of_lb; class not_lb; class any_lb; class access_lb; class non_qualified_lb;    using non_of_tg = not_any_non_qualified_tg;     using is_tg = of_any_access_non_qualified_tg; };
    struct  of_not_any_access_const_tg              { class tag_lb; class operator_lb; class of_lb; class not_lb; class any_lb; class access_lb; class const_lb;            using non_of_tg = not_any_const_tg;             using is_tg = of_any_access_const_tg; };
    struct  of_not_any_access_non_const_tg          { class tag_lb; class operator_lb; class of_lb; class not_lb; class any_lb; class access_lb; class non_const_lb;        using non_of_tg = not_any_non_const_tg;         using is_tg = of_any_access_non_const_tg; };
    struct  of_not_any_access_volatile_tg           { class tag_lb; class operator_lb; class of_lb; class not_lb; class any_lb; class access_lb; class volatile_lb;         using non_of_tg = not_any_volatile_tg;          using is_tg = of_any_access_volatile_tg; };
    struct  of_not_any_access_non_volatile_tg       { class tag_lb; class operator_lb; class of_lb; class not_lb; class any_lb; class access_lb; class non_volatile_lb;     using non_of_tg = not_any_non_volatile_tg;      using is_tg = of_any_access_non_volatile_tg; };

    struct  of_just_not_access_tg                   { class tag_lb; class operator_lb; class of_lb; class just_lb; class not_lb; class access_lb;                           using non_of_tg = just_not_tg;                  using is_tg = of_just_access_tg; };
    struct  of_just_not_access_non_qualified_tg     { class tag_lb; class operator_lb; class of_lb; class just_lb; class not_lb; class access_lb; class non_qualified_lb;   using non_of_tg = just_not_non_qualified_tg;    using is_tg = of_just_access_non_qualified_tg; };
    struct  of_just_not_access_const_tg             { class tag_lb; class operator_lb; class of_lb; class just_lb; class not_lb; class access_lb; class const_lb;           using non_of_tg = just_not_const_tg;            using is_tg = of_just_access_const_tg; };
    struct  of_just_not_access_volatile_tg          { class tag_lb; class operator_lb; class of_lb; class just_lb; class not_lb; class access_lb; class volatile_lb;        using non_of_tg = just_not_volatile_tg;         using is_tg = of_just_access_volatile_tg; };
    struct  of_just_not_access_const_volatile_tg    { class tag_lb; class operator_lb; class of_lb; class just_lb; class not_lb; class access_lb; class const_volatile_lb;  using non_of_tg = just_not_const_volatile_tg;   using is_tg = of_just_access_const_volatile_tg; };

}

namespace nkr {

    struct  to_tg       { class tag_lb; class operator_lb; class to_lb;                 using non_of_tg = to_tg;        using is_tg = to_tg; };
    struct  not_to_tg   { class tag_lb; class operator_lb; class not_lb; class to_lb;   using non_of_tg = not_to_tg;    using is_tg = to_tg; };

}

namespace nkr {

    struct  OR_tg   { class tag_lb; class operator_lb; class logic_gate_lb; class OR_lb; };
    struct  AND_tg  { class tag_lb; class operator_lb; class logic_gate_lb; class AND_lb; };
    struct  XOR_tg  { class tag_lb; class operator_lb; class logic_gate_lb; class XOR_lb; };
    struct  NOR_tg  { class tag_lb; class operator_lb; class logic_gate_lb; class NOR_lb; };
    struct  NAND_tg { class tag_lb; class operator_lb; class logic_gate_lb; class NAND_lb; };
    struct  XNOR_tg { class tag_lb; class operator_lb; class logic_gate_lb; class XNOR_lb; };

}

namespace nkr { namespace tr$ {

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
        nkr::tr$::ts<AND_tg, nkr::tuple::types_t<type_p>>;                                                              ///< @copydoc _13d670d2_5498_4b84_9648_94b1cd8f2c89

    template <nkr::generic::tag::logic_gate_tr operator_p, typename ...types_p>
        requires (nkr::tuple::types_t<types_p...>::Count() > 0)
    using   ts =
        nkr::tr$::ts<operator_p, nkr::tuple::types_t<types_p...>>;                                                      ///< @copydoc _65d1963a_c1d4_4110_a6bb_a52a9e9150fe

    template <typename type_p>
    concept ts_tr =
        nkr::cpp::is_any_tr<type_p, typename nkr::tr$::ts<typename type_p::operator_t, typename type_p::types_t>>;

    template <template <typename ...> typename template_p>
    using   tt =
        nkr::tr$::tts<AND_tg, nkr::tuple::templates_t<template_p>>;                                                     ///< @copydoc _24a5dd1f_5bfc_4cc2_a831_302413bf8087

    template <nkr::generic::tag::logic_gate_tr operator_p, template <typename ...> typename ...templates_p>
        requires (nkr::tuple::templates_t<templates_p...>::Count() > 0)
    using   tts =
        nkr::tr$::tts<operator_p, nkr::tuple::templates_t<templates_p...>>;                                             ///< @copydoc _7d64d462_bbf9_452a_9d76_322daed0989e

    template <typename type_p>
    concept tts_tr =
        nkr::cpp::is_any_tr<type_p, typename nkr::tr$::tts<typename type_p::operator_t, typename type_p::templates_t>>;

}

namespace nkr { namespace tr$ {

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
        typename nkr::tr$::to_ts_sp<operator_p, type_p>::type_t;

    template <nkr::generic::tag::logic_gate_tr operator_p, typename type_p>
    using   to_tts =
        typename nkr::tr$::to_tts_sp<operator_p, type_p>::type_t;

}

namespace nkr {

    template <
        nkr::ts_tr  subjects_p,
        typename    ...expression_parts_p
    > constexpr nkr::boolean::cpp_t TR() noexcept;  ///< @copydoc _6dffcf53_72e8_40f7_9f3a_5b6b515aed1d

    template <
        typename    subject_p,
        typename    ...expression_parts_p
    > concept tr =
        TR<t<subject_p>, expression_parts_p...>();  ///< @copydoc _fbaf0b62_578a_48b1_b4e2_43ad69c9980c

}

// We should have another like type called 'ttr' which can take templates of types.
// Likewise we might even have a 'tttr' for templates of templates of types.

#include "nkr/tr_dec_def.h"

#endif
