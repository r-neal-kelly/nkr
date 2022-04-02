/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_5a0ad2d3_188e_4dc6_a31a_0e68c3d66c61
#define nkr_INCLUDE_GUARD_5a0ad2d3_188e_4dc6_a31a_0e68c3d66c61

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/tag_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_tag_t_dec.h"

namespace nkr { namespace generic { namespace tag {

    struct  type_tg     { class tag_lb; class generic_lb; };

    template <typename ...>
    struct  type_ttg    {};

    template <typename type_p>
    concept type_tr =
        nkr::generic::tag_tr<type_p> &&
        (requires { typename type_p::type_lb; });

    template <template <typename ...> typename template_p>
    concept type_ttr =
        type_tr<template_p<nkr::none::type_t>>;

}}}

namespace nkr { namespace generic { namespace tag { namespace type_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::tag::type_tg> type_p>
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

    template <nkr::cpp::is_any_tr<nkr::generic::tag::type_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::generic::tag::type_tr$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace generic { namespace tag { namespace type_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::tag::type_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_generic_tag_t<
        nkr::generic::tag::type_tg,
        nkr::generic::tag::type_ttg>
    {
    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i_tag_sp(...) noexcept   = delete;
    };

}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::tag::type_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::generic::tag::type_tr$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/generic/tag/type_tr_dec_def.h"

#endif
