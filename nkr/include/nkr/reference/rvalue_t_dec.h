/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_dc0f1ac4_bdc3_4bfc_a9e9_9f0798632e3f
#define nkr_INCLUDE_GUARD_dc0f1ac4_bdc3_4bfc_a9e9_9f0798632e3f

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_identity_tag_t_dec.h"
#include "nkr/interface/template_i_identity_template_t_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace reference {

    template <typename type_p>
    using   rvalue_t =
        type_p&&;

    struct  rvalue_tg   { class tag_lb; };

    template <typename ...>
    struct  rvalue_ttg  {};

    template <typename type_p>
    concept rvalue_tr =
        nkr::cpp::rvalue_reference_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept rvalue_ttr =
        nkr::cpp::is_any_ttr<template_p, rvalue_t, nkr::positive::integer_t>;

}}

namespace nkr { namespace reference { namespace rvalue_t$ {

    template <nkr::reference::rvalue_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::cpp::reference_value_t<type_t>;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::reference::rvalue_tg> type_p>
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

    template <nkr::reference::rvalue_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::reference::rvalue_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::reference::rvalue_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::reference::rvalue_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace reference { namespace rvalue_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::reference::rvalue_ttr<template_p>
    class template_i_template_sp :
        public nkr::interface::template_i_identity_template_t<
            nkr::reference::rvalue_t,
            nkr::tuple::types_t<nkr::positive::integer_t>,
            nkr::constant::positive::count_t<1>,
            nkr::constant::positive::count_t<1>,
            nkr::reference::rvalue_tg,
            nkr::reference::rvalue_ttg
        >
    {
    public:
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::reference::rvalue_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_identity_tag_t<
            template_i_template_sp<nkr::reference::rvalue_t>
        >
    {
    public:
    };

}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::reference::rvalue_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::reference::rvalue_t$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::reference::rvalue_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::reference::rvalue_t$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/reference/rvalue_t_dec_def.h"

#endif
