/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp/randomness/generator/hardware_t_dec.h"
#include "nkr/cpp/randomness/generator/software/mersenne_twister_t_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_aliases_t_dec.h"

namespace nkr { namespace cpp { namespace generic { namespace randomness {

    struct  generator_tg    { class tag_lb; class generic_lb; };

    template <typename>
    struct  generator_ttg   {};

    template <typename type_p>
    concept generator_tr =
        nkr::cpp::randomness::generator::hardware_tr<type_p> ||
        nkr::cpp::randomness::generator::software::mersenne_twister_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept generator_ttr =
        generator_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}

namespace nkr { namespace cpp { namespace generic { namespace randomness { namespace generator_tr$ {

    template <nkr::cpp::is_any_tr<nkr::cpp::generic::randomness::generator_tg> type_p>
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

}}}}}

namespace nkr { namespace interface {

    template <nkr::cpp::is_any_tr<nkr::cpp::generic::randomness::generator_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::generic::randomness::generator_tr$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace cpp { namespace generic { namespace randomness { namespace generator_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::generic::randomness::generator_ttg, nkr::none::type_t>
    class template_i_tag_sp :
        public nkr::interface::template_i_generic_aliases_t<nkr::cpp::generic::randomness::generator_tg>
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
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::generic::randomness::generator_ttg, nkr::none::type_t>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::generic::randomness::generator_tr$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/cpp/generic/randomness/generator_tr_dec_def.h"
