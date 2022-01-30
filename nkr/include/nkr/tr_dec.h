/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/generic/implementing/interface/template_tr_dec.h"
#include "nkr/generic/implementing/interface/type_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/positive/index_t_dec.h"
#include "nkr/tuple/templates_t_dec.h"
#include "nkr/tuple/types_t_dec.h"

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

    struct  OR_tg                                   { class OR_t; };
    struct  AND_tg                                  { class AND_t; };

}

namespace nkr { namespace $ts {

    template <typename types_p>
    class OR_sp :
        public types_p
    {
    public:
        using operator_t    = OR_tg;
        using types_t       = types_p;
        using tail_t        = OR_sp<typename types_t::tail_t>;
    };

    template <typename types_p>
    class AND_sp :
        public types_p
    {
    public:
        using operator_t    = AND_tg;
        using types_t       = types_p;
        using tail_t        = AND_sp<typename types_t::tail_t>;
    };

    template <typename tag_p, nkr::tuple::types_tr types_p>
    class sp;

    template <nkr::tuple::types_tr types_p>
    class sp<OR_tg, types_p>
    {
    public:
        using type_t    = OR_sp<types_p>;
    };

    template <nkr::tuple::types_tr types_p>
    class sp<AND_tg, types_p>
    {
    public:
        using type_t    = AND_sp<types_p>;
    };

}}

namespace nkr {

    template <typename operator_p, typename ...types_p>
        requires (nkr::cpp::is_any_tr<operator_p, OR_tg> || nkr::cpp::is_any_tr<operator_p, AND_tg>)
    using   ts  = nkr::$ts::sp<operator_p, nkr::tuple::types_t<types_p...>>::type_t;

    template <typename type_p>
    using   t   = ts<AND_tg, type_p>;

    template <typename type_p>
    concept ts_tr =
        nkr::cpp::is_any_tr<type_p, typename nkr::$ts::sp<typename type_p::operator_t, typename type_p::types_t>::type_t>;

}

namespace nkr { namespace $tts {

    template <nkr::tuple::templates_tr templates_p>
    class OR_sp :
        public templates_p
    {
    public:
        using operator_t    = OR_tg;
        using templates_t   = templates_p;
        using tail_t        = OR_sp<typename templates_t::tail_t>;
    };

    template <nkr::tuple::templates_tr templates_p>
    class AND_sp :
        public templates_p
    {
    public:
        using operator_t    = AND_tg;
        using templates_t   = templates_p;
        using tail_t        = AND_sp<typename templates_t::tail_t>;
    };

    template <typename tag_p, nkr::tuple::templates_tr templates_p>
    class sp;

    template <nkr::tuple::templates_tr templates_p>
    class sp<OR_tg, templates_p>
    {
    public:
        using type_t    = OR_sp<templates_p>;
    };

    template <nkr::tuple::templates_tr templates_p>
    class sp<AND_tg, templates_p>
    {
    public:
        using type_t    = AND_sp<templates_p>;
    };

}}

namespace nkr {

    template <typename operator_p, template <typename ...> typename ...templates_p>
        requires (nkr::cpp::is_any_tr<operator_p, OR_tg> || nkr::cpp::is_any_tr<operator_p, AND_tg>)
    using   tts = nkr::$tts::sp<operator_p, nkr::tuple::templates_t<templates_p...>>::type_t;

    template <template <typename ...> typename template_p>
    using   tt  = tts<AND_tg, template_p>;

    template <typename type_p>
    concept tts_tr =
        nkr::cpp::is_any_tr<type_p, typename nkr::$tts::sp<typename type_p::operator_t, typename type_p::templates_t>::type_t>;

}

// We should have another like type called 'ttr' which can take templates of types.
// Likewise we might even have a 'tttr' for templates of templates of types.

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

namespace nkr { namespace $tr {

    template <
        typename subject_p,
        typename ...expression_parts_p
    > constexpr nkr::boolean::cpp_t TR() noexcept;

}}

namespace nkr {

    template <typename subject_p, typename ...expression_parts_p>
    concept tr =
        nkr::$tr::TR<subject_p, expression_parts_p...>();

}

#include "nkr/tr_dec_def.h"
