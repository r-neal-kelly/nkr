/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/generic/implementing/interface/template_tr_dec.h"
#include "nkr/generic/implementing/interface/type_tr_dec.h"
#include "nkr/generic/tag/logic_gate_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/positive/index_t_dec.h"
#include "nkr/tuple/templates_t_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr {

    struct  any_tg                                  { class operator_t; class any_t;                        using base_tg = any_tg;                 using is_tg = any_tg; };
    struct  any_qualified_tg                        { class operator_t; class any_t; class qualified_t;     using base_tg = any_qualified_tg;       using is_tg = any_qualified_tg; };
    struct  any_non_qualified_tg                    { class operator_t; class any_t; class non_qualified_t; using base_tg = any_non_qualified_tg;   using is_tg = any_non_qualified_tg; };
    struct  any_const_tg                            { class operator_t; class any_t; class const_t;         using base_tg = any_const_tg;           using is_tg = any_const_tg; };
    struct  any_non_const_tg                        { class operator_t; class any_t; class non_const_t;     using base_tg = any_non_const_tg;       using is_tg = any_non_const_tg; };
    struct  any_volatile_tg                         { class operator_t; class any_t; class volatile_t;      using base_tg = any_volatile_tg;        using is_tg = any_volatile_tg; };
    struct  any_non_volatile_tg                     { class operator_t; class any_t; class non_volatile_t;  using base_tg = any_non_volatile_tg;    using is_tg = any_non_volatile_tg; };

    struct  just_tg                                 { class operator_t; class just_t;                           using base_tg = just_tg;                using is_tg = just_tg; };
    struct  just_non_qualified_tg                   { class operator_t; class just_t; class non_qualified_t;    using base_tg = just_non_qualified_tg;  using is_tg = just_non_qualified_tg; };
    struct  just_const_tg                           { class operator_t; class just_t; class const_t;            using base_tg = just_const_tg;          using is_tg = just_const_tg; };
    struct  just_volatile_tg                        { class operator_t; class just_t; class volatile_t;         using base_tg = just_volatile_tg;       using is_tg = just_volatile_tg; };
    struct  just_const_volatile_tg                  { class operator_t; class just_t; class const_volatile_t;   using base_tg = just_const_volatile_tg; using is_tg = just_const_volatile_tg; };

    struct  not_any_tg                              { class operator_t; class not_t; class any_t;                           using base_tg = not_any_tg;                 using is_tg = any_tg; };
    struct  not_any_qualified_tg                    { class operator_t; class not_t; class any_t; class qualified_t;        using base_tg = not_any_qualified_tg;       using is_tg = any_qualified_tg; };
    struct  not_any_non_qualified_tg                { class operator_t; class not_t; class any_t; class non_qualified_t;    using base_tg = not_any_non_qualified_tg;   using is_tg = any_non_qualified_tg; };
    struct  not_any_const_tg                        { class operator_t; class not_t; class any_t; class const_t;            using base_tg = not_any_const_tg;           using is_tg = any_const_tg; };
    struct  not_any_non_const_tg                    { class operator_t; class not_t; class any_t; class non_const_t;        using base_tg = not_any_non_const_tg;       using is_tg = any_non_const_tg; };
    struct  not_any_volatile_tg                     { class operator_t; class not_t; class any_t; class volatile_t;         using base_tg = not_any_volatile_tg;        using is_tg = any_volatile_tg; };
    struct  not_any_non_volatile_tg                 { class operator_t; class not_t; class any_t; class non_volatile_t;     using base_tg = not_any_non_volatile_tg;    using is_tg = any_non_volatile_tg; };

    struct  just_not_tg                             { class operator_t; class just_t; class not_t;                          using base_tg = just_not_tg;                using is_tg = just_tg; };
    struct  just_not_non_qualified_tg               { class operator_t; class just_t; class not_t; class non_qualified_t;   using base_tg = just_not_non_qualified_tg;  using is_tg = just_non_qualified_tg; };
    struct  just_not_const_tg                       { class operator_t; class just_t; class not_t; class const_t;           using base_tg = just_not_const_tg;          using is_tg = just_const_tg; };
    struct  just_not_volatile_tg                    { class operator_t; class just_t; class not_t; class volatile_t;        using base_tg = just_not_volatile_tg;       using is_tg = just_volatile_tg; };
    struct  just_not_const_volatile_tg              { class operator_t; class just_t; class not_t; class const_volatile_t;  using base_tg = just_not_const_volatile_tg; using is_tg = just_const_volatile_tg; };

    struct  any_to_tg                               { class operator_t; class any_t;                        class to_t; using base_tg = any_tg; };
    struct  any_qualified_to_tg                     { class operator_t; class any_t; class qualified_t;     class to_t; using base_tg = any_qualified_tg; };
    struct  any_non_qualified_to_tg                 { class operator_t; class any_t; class non_qualified_t; class to_t; using base_tg = any_non_qualified_tg; };
    struct  any_const_to_tg                         { class operator_t; class any_t; class const_t;         class to_t; using base_tg = any_const_tg; };
    struct  any_non_const_to_tg                     { class operator_t; class any_t; class non_const_t;     class to_t; using base_tg = any_non_const_tg; };
    struct  any_volatile_to_tg                      { class operator_t; class any_t; class volatile_t;      class to_t; using base_tg = any_volatile_tg; };
    struct  any_non_volatile_to_tg                  { class operator_t; class any_t; class non_volatile_t;  class to_t; using base_tg = any_non_volatile_tg; };

    struct  just_to_tg                              { class operator_t; class just_t;                           class to_t; using base_tg = just_tg; };
    struct  just_non_qualified_to_tg                { class operator_t; class just_t; class non_qualified_t;    class to_t; using base_tg = just_non_qualified_tg; };
    struct  just_const_to_tg                        { class operator_t; class just_t; class const_t;            class to_t; using base_tg = just_const_tg; };
    struct  just_volatile_to_tg                     { class operator_t; class just_t; class volatile_t;         class to_t; using base_tg = just_volatile_tg; };
    struct  just_const_volatile_to_tg               { class operator_t; class just_t; class const_volatile_t;   class to_t; using base_tg = just_const_volatile_tg; };

    struct  not_any_to_tg                           { class operator_t; class not_t; class any_t;                           class to_t; using base_tg = not_any_tg; };
    struct  not_any_qualified_to_tg                 { class operator_t; class not_t; class any_t; class qualified_t;        class to_t; using base_tg = not_any_qualified_tg; };
    struct  not_any_non_qualified_to_tg             { class operator_t; class not_t; class any_t; class non_qualified_t;    class to_t; using base_tg = not_any_non_qualified_tg; };
    struct  not_any_const_to_tg                     { class operator_t; class not_t; class any_t; class const_t;            class to_t; using base_tg = not_any_const_tg; };
    struct  not_any_non_const_to_tg                 { class operator_t; class not_t; class any_t; class non_const_t;        class to_t; using base_tg = not_any_non_const_tg; };
    struct  not_any_volatile_to_tg                  { class operator_t; class not_t; class any_t; class volatile_t;         class to_t; using base_tg = not_any_volatile_tg; };
    struct  not_any_non_volatile_to_tg              { class operator_t; class not_t; class any_t; class non_volatile_t;     class to_t; using base_tg = not_any_non_volatile_tg; };

    struct  just_not_to_tg                          { class operator_t; class just_t; class not_t;                          class to_t; using base_tg = just_not_tg; };
    struct  just_not_non_qualified_to_tg            { class operator_t; class just_t; class not_t; class non_qualified_t;   class to_t; using base_tg = just_not_non_qualified_tg; };
    struct  just_not_const_to_tg                    { class operator_t; class just_t; class not_t; class const_t;           class to_t; using base_tg = just_not_const_tg; };
    struct  just_not_volatile_to_tg                 { class operator_t; class just_t; class not_t; class volatile_t;        class to_t; using base_tg = just_not_volatile_tg; };
    struct  just_not_const_volatile_to_tg           { class operator_t; class just_t; class not_t; class const_volatile_t;  class to_t; using base_tg = just_not_const_volatile_tg; };

    struct  of_any_tg                               { class operator_t; class of_t; class any_t;                        using base_tg = any_tg; };
    struct  of_any_qualified_tg                     { class operator_t; class of_t; class any_t; class qualified_t;     using base_tg = any_qualified_tg; };
    struct  of_any_non_qualified_tg                 { class operator_t; class of_t; class any_t; class non_qualified_t; using base_tg = any_non_qualified_tg; };
    struct  of_any_const_tg                         { class operator_t; class of_t; class any_t; class const_t;         using base_tg = any_const_tg; };
    struct  of_any_non_const_tg                     { class operator_t; class of_t; class any_t; class non_const_t;     using base_tg = any_non_const_tg; };
    struct  of_any_volatile_tg                      { class operator_t; class of_t; class any_t; class volatile_t;      using base_tg = any_volatile_tg; };
    struct  of_any_non_volatile_tg                  { class operator_t; class of_t; class any_t; class non_volatile_t;  using base_tg = any_non_volatile_tg; };

    struct  of_just_tg                              { class operator_t; class of_t; class just_t;                           using base_tg = just_tg; };
    struct  of_just_non_qualified_tg                { class operator_t; class of_t; class just_t; class non_qualified_t;    using base_tg = just_non_qualified_tg; };
    struct  of_just_const_tg                        { class operator_t; class of_t; class just_t; class const_t;            using base_tg = just_const_tg; };
    struct  of_just_volatile_tg                     { class operator_t; class of_t; class just_t; class volatile_t;         using base_tg = just_volatile_tg; };
    struct  of_just_const_volatile_tg               { class operator_t; class of_t; class just_t; class const_volatile_t;   using base_tg = just_const_volatile_tg; };

    struct  of_not_any_tg                           { class operator_t; class of_t; class not_t; class any_t;                           using base_tg = not_any_tg; };
    struct  of_not_any_qualified_tg                 { class operator_t; class of_t; class not_t; class any_t; class qualified_t;        using base_tg = not_any_qualified_tg; };
    struct  of_not_any_non_qualified_tg             { class operator_t; class of_t; class not_t; class any_t; class non_qualified_t;    using base_tg = not_any_non_qualified_tg; };
    struct  of_not_any_const_tg                     { class operator_t; class of_t; class not_t; class any_t; class const_t;            using base_tg = not_any_const_tg; };
    struct  of_not_any_non_const_tg                 { class operator_t; class of_t; class not_t; class any_t; class non_const_t;        using base_tg = not_any_non_const_tg; };
    struct  of_not_any_volatile_tg                  { class operator_t; class of_t; class not_t; class any_t; class volatile_t;         using base_tg = not_any_volatile_tg; };
    struct  of_not_any_non_volatile_tg              { class operator_t; class of_t; class not_t; class any_t; class non_volatile_t;     using base_tg = not_any_non_volatile_tg; };

    struct  of_just_not_tg                          { class operator_t; class of_t; class just_t; class not_t;                          using base_tg = just_not_tg; };
    struct  of_just_not_non_qualified_tg            { class operator_t; class of_t; class just_t; class not_t; class non_qualified_t;   using base_tg = just_not_non_qualified_tg; };
    struct  of_just_not_const_tg                    { class operator_t; class of_t; class just_t; class not_t; class const_t;           using base_tg = just_not_const_tg; };
    struct  of_just_not_volatile_tg                 { class operator_t; class of_t; class just_t; class not_t; class volatile_t;        using base_tg = just_not_volatile_tg; };
    struct  of_just_not_const_volatile_tg           { class operator_t; class of_t; class just_t; class not_t; class const_volatile_t;  using base_tg = just_not_const_volatile_tg; };

    struct  of_any_access_tg                        { class operator_t; class of_t; class any_t; class access_t;                        using base_tg = any_tg; };
    struct  of_any_access_qualified_tg              { class operator_t; class of_t; class any_t; class access_t; class qualified_t;     using base_tg = any_qualified_tg; };
    struct  of_any_access_non_qualified_tg          { class operator_t; class of_t; class any_t; class access_t; class non_qualified_t; using base_tg = any_non_qualified_tg; };
    struct  of_any_access_const_tg                  { class operator_t; class of_t; class any_t; class access_t; class const_t;         using base_tg = any_const_tg; };
    struct  of_any_access_non_const_tg              { class operator_t; class of_t; class any_t; class access_t; class non_const_t;     using base_tg = any_non_const_tg; };
    struct  of_any_access_volatile_tg               { class operator_t; class of_t; class any_t; class access_t; class volatile_t;      using base_tg = any_volatile_tg; };
    struct  of_any_access_non_volatile_tg           { class operator_t; class of_t; class any_t; class access_t; class non_volatile_t;  using base_tg = any_non_volatile_tg; };

    struct  of_just_access_tg                       { class operator_t; class of_t; class just_t; class access_t;                           using base_tg = just_tg; };
    struct  of_just_access_non_qualified_tg         { class operator_t; class of_t; class just_t; class access_t; class non_qualified_t;    using base_tg = just_non_qualified_tg; };
    struct  of_just_access_const_tg                 { class operator_t; class of_t; class just_t; class access_t; class const_t;            using base_tg = just_const_tg; };
    struct  of_just_access_volatile_tg              { class operator_t; class of_t; class just_t; class access_t; class volatile_t;         using base_tg = just_volatile_tg; };
    struct  of_just_access_const_volatile_tg        { class operator_t; class of_t; class just_t; class access_t; class const_volatile_t;   using base_tg = just_const_volatile_tg; };

    struct  of_not_any_access_tg                    { class operator_t; class of_t; class not_t; class any_t; class access_t;                           using base_tg = not_any_tg; };
    struct  of_not_any_access_qualified_tg          { class operator_t; class of_t; class not_t; class any_t; class access_t; class qualified_t;        using base_tg = not_any_qualified_tg; };
    struct  of_not_any_access_non_qualified_tg      { class operator_t; class of_t; class not_t; class any_t; class access_t; class non_qualified_t;    using base_tg = not_any_non_qualified_tg; };
    struct  of_not_any_access_const_tg              { class operator_t; class of_t; class not_t; class any_t; class access_t; class const_t;            using base_tg = not_any_const_tg; };
    struct  of_not_any_access_non_const_tg          { class operator_t; class of_t; class not_t; class any_t; class access_t; class non_const_t;        using base_tg = not_any_non_const_tg; };
    struct  of_not_any_access_volatile_tg           { class operator_t; class of_t; class not_t; class any_t; class access_t; class volatile_t;         using base_tg = not_any_volatile_tg; };
    struct  of_not_any_access_non_volatile_tg       { class operator_t; class of_t; class not_t; class any_t; class access_t; class non_volatile_t;     using base_tg = not_any_non_volatile_tg; };

    struct  of_just_not_access_tg                   { class operator_t; class of_t; class just_t; class not_t; class access_t;                          using base_tg = just_not_tg; };
    struct  of_just_not_access_non_qualified_tg     { class operator_t; class of_t; class just_t; class not_t; class access_t; class non_qualified_t;   using base_tg = just_not_non_qualified_tg; };
    struct  of_just_not_access_const_tg             { class operator_t; class of_t; class just_t; class not_t; class access_t; class const_t;           using base_tg = just_not_const_tg; };
    struct  of_just_not_access_volatile_tg          { class operator_t; class of_t; class just_t; class not_t; class access_t; class volatile_t;        using base_tg = just_not_volatile_tg; };
    struct  of_just_not_access_const_volatile_tg    { class operator_t; class of_t; class just_t; class not_t; class access_t; class const_volatile_t;  using base_tg = just_not_const_volatile_tg; };

    struct  OR_tg                                   { class operator_t; class logic_gate_t; class OR_t; };
    struct  AND_tg                                  { class operator_t; class logic_gate_t; class AND_t; };
    struct  XOR_tg                                  { class operator_t; class logic_gate_t; class XOR_t; };
    struct  NOR_tg                                  { class operator_t; class logic_gate_t; class NOR_t; };
    struct  NAND_tg                                 { class operator_t; class logic_gate_t; class NAND_t; };
    struct  XNOR_tg                                 { class operator_t; class logic_gate_t; class XNOR_t; };

}

namespace nkr { namespace $tr {

    template <nkr::generic::tag::logic_gate_tr operator_p, nkr::tuple::types_tr types_p>
    class ts :
        public types_p
    {
    public:
        using operator_t    = operator_p;
        using types_t       = types_p;

        using tail_t        = ts<operator_t, typename types_t::tail_t>;
        template <nkr::positive::count_ctr count_p>
            requires (count_p::Value() <= types_t::Count())
        using take_t        = ts<operator_t, typename types_t::template take_t<count_p>>;
    };

    template <nkr::generic::tag::logic_gate_tr operator_p, nkr::tuple::templates_tr templates_p>
    class tts :
        public templates_p
    {
    public:
        using operator_t    = operator_p;
        using templates_t   = templates_p;

        using tail_t        = tts<operator_t, typename templates_t::tail_t>;
        template <nkr::positive::count_ctr count_p>
            requires (count_p::Value() <= templates_t::Count())
        using take_t        = tts<operator_t, typename templates_t::template take_t<count_p>>;
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

    template <
        nkr::ts_tr              subjects_p,
        nkr::tuple::types_tr    expression_parts_p,
        typename                index_p             = nkr::positive::index_c<0>
    > constexpr nkr::boolean::cpp_t TR() noexcept;

}}

namespace nkr {

    template <
        typename subject_p,
        typename ...expression_parts_p
    > concept tr =
        nkr::$tr::TR<t<subject_p>, nkr::tuple::types_t<expression_parts_p...>>();

}

// We should have another like type called 'ttr' which can take templates of types.
// Likewise we might even have a 'tttr' for templates of templates of types.

// these will probably be deleted.

namespace nkr { namespace $tr {

    template <
        typename subject_p,
        typename operator_p
    > constexpr nkr::boolean::cpp_t TR0() noexcept;

    template <
        typename subject_p,
        typename operator_p, typename operand_p
    > constexpr nkr::boolean::cpp_t TR1() noexcept;

    template <
        typename subject_p,
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > constexpr nkr::boolean::cpp_t TR2() noexcept;

    template <
        typename subject_p,
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > constexpr nkr::boolean::cpp_t TR3() noexcept;

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

// everything below here will be deleted.

namespace nkr {

    template <
        typename operator_p
    > class tr0_t
    {
    public:
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    OR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    OR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    NOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    NOR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    NAND() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    NAND() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XNOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    XNOR() noexcept;

        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    Any() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    Any() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    Every() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    Every() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    One() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    One() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    None() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    None() noexcept;

    private:
        template <nkr::boolean::cpp_ctr state_p, tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
    };

}

namespace nkr {

    template <
        typename operator_p, typename operand_p
    > class tr1_t
    {
    public:
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    OR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    OR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    NOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    NOR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    NAND() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    NAND() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XNOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    XNOR() noexcept;

        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    Any() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    Any() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    Every() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    Every() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    One() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    One() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    None() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    None() noexcept;

    private:
        template <nkr::boolean::cpp_ctr state_p, tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
    };

}

namespace nkr {

    template <
        typename operator_p, nkr::ts_tr operands_p
    > class tr1s_t
    {
    public:
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    OR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    OR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    NOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    NOR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    NAND() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    NAND() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XNOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    XNOR() noexcept;

        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    Any() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    Any() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    Every() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    Every() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    One() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    One() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    None() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    None() noexcept;
    };

}

namespace nkr {

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > class tr2_t
    {
    public:
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    OR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    OR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    NOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    NOR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    NAND() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    NAND() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XNOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    XNOR() noexcept;

        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    Any() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    Any() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    Every() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    Every() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    One() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    One() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    None() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    None() noexcept;

    private:
        template <nkr::boolean::cpp_ctr state_p, tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
    };

}

namespace nkr {

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > class tr2s_t
    {
    public:
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    OR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    OR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    NOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    NOR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    NAND() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    NAND() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XNOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    XNOR() noexcept;

        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    Any() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    Any() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    Every() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    Every() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    One() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    One() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    None() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    None() noexcept;
    };

}

namespace nkr {

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > class tr3_t
    {
    public:
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    OR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    OR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    NOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    NOR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    NAND() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    NAND() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XNOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    XNOR() noexcept;

        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    Any() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    Any() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    Every() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    Every() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    One() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    One() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    None() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    None() noexcept;

    private:
        template <nkr::boolean::cpp_ctr state_p, tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
    };

}

namespace nkr {

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > class tr3s_t
    {
    public:
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    OR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    OR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    NOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    NOR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    NAND() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    NAND() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XNOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    XNOR() noexcept;

        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    Any() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    Any() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    Every() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    Every() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    One() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    One() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    None() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    None() noexcept;
    };

}

#include "nkr/tr_dec_def.h"
