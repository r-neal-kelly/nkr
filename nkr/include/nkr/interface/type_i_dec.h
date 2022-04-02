/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_9b9dd95c_bf5a_4797_81a7_0aaadf82697c
#define nkr_INCLUDE_GUARD_9b9dd95c_bf5a_4797_81a7_0aaadf82697c

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/implementing/constructor/default_tr_dec.h"
#include "nkr/generic/type_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_identity_tag_t_dec.h"
#include "nkr/interface/template_i_identity_template_t_dec.h"
#include "nkr/none/type_t_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace interface { namespace type_i$ {

    template <typename type_p>
    concept aliases_i = requires
    {
        typename type_p::type_t;
        typename type_p::of_t;
        nkr::cpp::just_non_qualified_tr<typename type_p::type_t>;
        nkr::generic::type_tr<typename type_p::type_t>;
    };

    template <typename type_p>
    concept static_constexpr_functions_i = requires
    {
        { type_p::template Is_Any_General<typename type_p::type_t>() }  -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { type_p::template Is_Any_Specific<typename type_p::type_t>() } -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
    };

    template <typename type_p>
    concept objects_i =
        !nkr::generic::implementing::constructor::default_tr<type_p>;

}}}

namespace nkr { namespace interface {

    struct  type_tg     { class tag_lb; };

    template <typename ...>
    struct  type_ttg    {};

    template <typename type_p>
    concept type_tr =
        nkr::cpp::is_any_tr<type_p, type_i<typename type_p::type_t>> &&
        type_i$::aliases_i<type_p> &&
        type_i$::static_constexpr_functions_i<type_p> &&
        type_i$::objects_i<type_p>;

    template <template <typename ...> typename template_p>
    concept type_ttr =
        nkr::cpp::is_any_ttr<template_p, type_i, nkr::none::type_t>;

}}

namespace nkr { namespace interface { namespace type_i$ {

    template <typename type_p>
    concept inner_type_tr = requires
    {
        typename type_p::type_t;
    };

    template <typename type_p>
    concept inner_value_tr = requires
    {
        typename type_p::value_t;
    };

    template <typename type_p>
    concept inner_unit_tr = requires
    {
        typename type_p::unit_t;
    };

    template <typename type_p>
    concept just_inner_type_tr =
        inner_type_tr<type_p> &&
        !inner_value_tr<type_p> &&
        !inner_unit_tr<type_p>;

    template <typename type_p>
    concept just_inner_value_tr =
        !inner_type_tr<type_p> &&
        inner_value_tr<type_p> &&
        !inner_unit_tr<type_p>;

    template <typename type_p>
    concept just_inner_unit_tr =
        !inner_type_tr<type_p> &&
        !inner_value_tr<type_p> &&
        inner_unit_tr<type_p>;

    template <typename type_p>
    class default_inner_tmpl
    {
    public:
        using type_t    = nkr::none::type_t;
    };

    template <just_inner_type_tr type_p>
    class default_inner_tmpl<type_p>
    {
    public:
        using type_t    = typename type_p::type_t;
    };

    template <just_inner_value_tr type_p>
    class default_inner_tmpl<type_p>
    {
    public:
        using type_t    = typename type_p::value_t;
    };

    template <just_inner_unit_tr type_p>
    class default_inner_tmpl<type_p>
    {
    public:
        using type_t    = typename type_p::unit_t;
    };

    template <typename type_p>
    using default_inner_t   = typename default_inner_tmpl<type_p>::type_t;

}}}

namespace nkr { namespace interface { namespace type_i$ {

    template <nkr::interface::type_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = typename type_t::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::interface::type_tg> type_p>
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

}}}

namespace nkr { namespace interface {

    template <nkr::interface::type_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::interface::type_i$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::interface::type_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::interface::type_i$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace interface { namespace type_i$ {

    template <template <typename ...> typename template_p>
        requires nkr::interface::type_ttr<template_p>
    class template_i_template_sp :
        public nkr::interface::template_i_identity_template_t<
            nkr::interface::type_i,
            nkr::tuple::types_t<nkr::none::type_t>,
            nkr::constant::positive::count_t<1>,
            nkr::constant::positive::count_t<1>,
            nkr::interface::type_tg,
            nkr::interface::type_ttg
        >
    {
    public:
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::interface::type_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_identity_tag_t<
            template_i_template_sp<nkr::interface::type_i>
        >
    {
    public:
    };

}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::interface::type_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::interface::type_i$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::interface::type_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::interface::type_i$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/interface/type_i_dec_def.h"

#endif
