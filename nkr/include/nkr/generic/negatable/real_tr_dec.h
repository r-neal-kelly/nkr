/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_ab80032a_55f3_42c0_97b4_ea32d8576ceb
#define nkr_INCLUDE_GUARD_ab80032a_55f3_42c0_97b4_ea32d8576ceb

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/negatable/any_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_tag_t_dec.h"

namespace nkr { namespace generic { namespace negatable {

    struct  real_tg     { class tag_lb; class generic_lb; };

    template <typename ...>
    struct  real_ttg    {};

    template <typename type_p>
    concept real_tr =
        nkr::generic::negatable::any_tr<type_p> &&
        nkr::cpp::real_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept real_ttr =
        real_tr<typename interface::template_i<template_p>::example_t>;

}}}

namespace nkr { namespace generic { namespace negatable { namespace real_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::negatable::real_tg> type_p>
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

    template <nkr::cpp::is_any_tr<nkr::generic::negatable::real_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::generic::negatable::real_tr$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace generic { namespace negatable { namespace real_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::negatable::real_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_generic_tag_t<
        nkr::generic::negatable::real_tg,
        nkr::generic::negatable::real_ttg>
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
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::negatable::real_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::generic::negatable::real_tr$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/generic/negatable/real_tr_dec_def.h"

#endif
