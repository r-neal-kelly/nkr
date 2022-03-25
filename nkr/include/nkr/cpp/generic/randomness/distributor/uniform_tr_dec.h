/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp/randomness/distributor/uniform/integer_t_dec.h"
#include "nkr/cpp/randomness/distributor/uniform/real_t_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_tag_t_dec.h"

namespace nkr { namespace cpp { namespace generic { namespace randomness { namespace distributor {

    struct  uniform_tg  { class tag_lb; class generic_lb; };

    template <typename ...>
    struct  uniform_ttg {};

    template <typename type_p>
    concept uniform_tr =
        nkr::cpp::randomness::distributor::uniform::integer_tr<type_p> ||
        nkr::cpp::randomness::distributor::uniform::real_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept uniform_ttr =
        uniform_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}}

namespace nkr { namespace cpp { namespace generic { namespace randomness { namespace distributor { namespace uniform_tr$ {

    template <nkr::cpp::is_any_tr<nkr::cpp::generic::randomness::distributor::uniform_tg> type_p>
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

}}}}}}

namespace nkr { namespace interface {

    template <nkr::cpp::is_any_tr<nkr::cpp::generic::randomness::distributor::uniform_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::generic::randomness::distributor::uniform_tr$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace cpp { namespace generic { namespace randomness { namespace distributor { namespace uniform_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::generic::randomness::distributor::uniform_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_generic_tag_t<
        nkr::cpp::generic::randomness::distributor::uniform_tg,
        nkr::cpp::generic::randomness::distributor::uniform_ttg>
    {
    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i_tag_sp(...) noexcept   = delete;
    };

}}}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::generic::randomness::distributor::uniform_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::generic::randomness::distributor::uniform_tr$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/cpp/generic/randomness/distributor/uniform_tr_dec_def.h"
