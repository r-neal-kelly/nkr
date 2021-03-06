/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_f3e7bb5c_14b8_400a_b501_7bb111c7e334
#define nkr_INCLUDE_GUARD_f3e7bb5c_14b8_400a_b501_7bb111c7e334

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/tag_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_tag_t_dec.h"

namespace nkr { namespace generic { namespace tag {

    struct  generic_tg  { class tag_lb; class generic_lb; };

    template <typename ...>
    struct  generic_ttg {};

    template <typename type_p>
    concept generic_tr =
        nkr::generic::tag_tr<type_p> &&
        (requires { typename type_p::generic_lb; });

    template <template <typename ...> typename template_p>
    concept generic_ttr =
        generic_tr<template_p<nkr::none::type_t>>;

}}}

namespace nkr { namespace generic { namespace tag { namespace generic_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::tag::generic_tg> type_p>
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

    template <nkr::cpp::is_any_tr<nkr::generic::tag::generic_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::generic::tag::generic_tr$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace generic { namespace tag { namespace generic_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::tag::generic_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_generic_tag_t<
        nkr::generic::tag::generic_tg,
        nkr::generic::tag::generic_ttg>
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
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::tag::generic_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::generic::tag::generic_tr$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/generic/tag/generic_tr_dec_def.h"

#endif
