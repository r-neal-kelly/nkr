/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_dec.h"
#include "nkr/interface/template_i_generic_aliases_t_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace interface {

    template <typename ...>
    struct  template_ttg    {};

    template <template <typename ...> typename template_p>
    concept template_ttr =
        nkr::interface::template_tr<nkr::interface::template_i<template_p>>;

}}}}

namespace nkr { namespace generic { namespace implementing { namespace interface { namespace template_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::implementing::interface::template_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_generic_aliases_t<
        nkr::none::type_t,
        nkr::generic::implementing::interface::template_ttg>
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
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::implementing::interface::template_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::generic::implementing::interface::template_tr$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/generic/implementing/interface/template_tr_dec_def.h"
