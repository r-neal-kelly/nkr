/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_tag_t_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace parameter_list {

    template <typename ...>
    struct  default_ttg     {};

    template <template <typename ...> typename ...>
    struct  default_tttg    {};

    template <template <typename ...> typename template_p>
    concept default_ttr =
        nkr::cpp::is_tr<template_p<>, template_p<>>;

    template <template <template <typename ...> typename ...> typename template_template_p>
    concept default_tttr =
        nkr::cpp::is_tr<template_template_p<>, template_template_p<>>;

}}}}

namespace nkr { namespace generic { namespace implementing { namespace parameter_list { namespace default_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::implementing::parameter_list::default_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_generic_tag_t<
        nkr::generic::implementing::parameter_list::default_tg,
        nkr::generic::implementing::parameter_list::default_ttg>
    {
    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i_tag_sp(...) noexcept   = delete;
    };

}}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::implementing::parameter_list::default_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::generic::implementing::parameter_list::default_tr$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/generic/implementing/parameter_list/default_tr_dec_def.h"
