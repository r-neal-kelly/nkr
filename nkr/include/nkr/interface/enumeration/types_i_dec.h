/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_1662cce5_4c6b_4eb3_bde0_419434ba5fd5
#define nkr_INCLUDE_GUARD_1662cce5_4c6b_4eb3_bde0_419434ba5fd5

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/built_in/number/integer_tr_dec.h"
#include "nkr/generic/implementing/constructor/default_tr_dec.h"
#include "nkr/generic/implementing/self_tr_dec.h"
#include "nkr/generic/type_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_identity_tag_t_dec.h"
#include "nkr/interface/template_i_identity_template_t_dec.h"
#include "nkr/tr_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace interface { namespace enumeration { namespace types_i$ {

    template <typename type_p>
    concept aliases_i =
        nkr::generic::type_tr<typename type_p::type_t> &&

        nkr::cpp::is_tr<typename type_p::value_t, nkr::cpp::just_non_qualified_t<typename type_p::type_t>> &&
        nkr::generic::implementing::self_tr<typename type_p::value_t> &&
        (requires(typename type_p::integer_t integer) { { typename type_p::value_t(integer) }; }) &&

        nkr::cpp::just_non_qualified_tr<typename type_p::integer_t> &&
        nkr::generic::type_tr<typename type_p::integer_t> &&
        nkr::generic::built_in::number::integer_tr<typename type_p::integer_t>;

    template <typename type_p>
    concept static_functions_i = requires(typename type_p::value_t value,
                                          const typename type_p::value_t const_value,
                                          volatile typename type_p::value_t volatile_value,
                                          const volatile typename type_p::value_t const_volatile_value,

                                          typename type_p::integer_t integer)
    {
        { type_p::Default_Integer() }                   -> nkr::cpp::is_tr<typename type_p::integer_t>;

        { type_p::Integer(const_value) }                -> nkr::cpp::is_tr<typename type_p::integer_t>;
        { type_p::Integer(const_volatile_value) }       -> nkr::cpp::is_tr<typename type_p::integer_t>;

        { type_p::Integer(value, integer) }             -> nkr::cpp::is_tr<nkr::none::type_t>;
        { type_p::Integer(volatile_value, integer) }    -> nkr::cpp::is_tr<nkr::none::type_t>;
    };

    template <typename type_p>
    concept objects_i =
        !nkr::generic::implementing::constructor::default_tr<type_p>;

}}}}

namespace nkr { namespace interface { namespace enumeration { namespace types_i$ {

    using example_t =
        nkr::positive::integer_t;

    template <nkr::cpp::is_any_tr<example_t> type_p>
    class example_types_i_sp
    {
    public:
        using type_t    = type_p;
        using value_t   = nkr::cpp::just_non_qualified_t<type_t>;
        using integer_t = nkr::positive::integer_t;

    public:
        static constexpr integer_t          Default_Integer() noexcept;

        static constexpr integer_t          Integer(const tr<any_tg, t<value_t>> auto& value) noexcept;
        static constexpr nkr::none::type_t  Integer(tr<any_non_const_tg, t<value_t>> auto& value, integer_t integer) noexcept;

    public:
        template <typename ...>
        constexpr example_types_i_sp(...) noexcept  = delete;
    };

}}}}

namespace nkr { namespace interface { namespace enumeration {

    template <nkr::cpp::is_any_tr<types_i$::example_t> type_p>
    class types_i_sp<type_p>
    {
    public:
        using type_t    = types_i$::example_types_i_sp<type_p>;
    };

}}}

namespace nkr { namespace interface { namespace enumeration {

    struct  types_tg    { class tag_lb; };

    template <typename ...>
    struct  types_ttg   {};

    template <typename type_p>
    concept types_tr =
        nkr::cpp::is_any_tr<type_p, types_i<typename type_p::type_t>> &&
        types_i$::aliases_i<type_p> &&
        types_i$::static_functions_i<type_p> &&
        types_i$::objects_i<type_p>;

    template <template <typename ...> typename template_p>
    concept types_ttr =
        nkr::cpp::is_any_ttr<template_p, types_i, types_i$::example_t>;

}}}

namespace nkr { namespace interface { namespace enumeration { namespace types_i$ {

    template <nkr::interface::enumeration::types_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = type_t::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::interface::enumeration::types_tg> type_p>
    class type_i_tag_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_tag_sp(...) noexcept   = delete;
    };

}}}}

namespace nkr { namespace interface {

    template <nkr::interface::enumeration::types_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::interface::enumeration::types_i$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::interface::enumeration::types_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::interface::enumeration::types_i$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace interface { namespace enumeration { namespace types_i$ {

    template <template <typename ...> typename template_p>
        requires nkr::interface::enumeration::types_ttr<template_p>
    class template_i_template_sp :
        public nkr::interface::template_i_identity_template_t<
            nkr::interface::enumeration::types_i,
            nkr::tuple::types_t<nkr::interface::enumeration::types_i$::example_t>,
            nkr::constant::positive::count_t<1>,
            nkr::constant::positive::count_t<1>,
            nkr::interface::enumeration::types_tg,
            nkr::interface::enumeration::types_ttg
        >
    {
    public:
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::interface::enumeration::types_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_identity_tag_t<
            template_i_template_sp<nkr::interface::enumeration::types_i>
        >
    {
    public:
    };

}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::interface::enumeration::types_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::interface::enumeration::types_i$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::interface::enumeration::types_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::interface::enumeration::types_i$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/interface/enumeration/types_i_dec_def.h"

#endif
