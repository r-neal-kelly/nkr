/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_identity_tag_t_dec.h"
#include "nkr/interface/template_i_identity_template_t_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace cpp { namespace randomness { namespace distributor { namespace uniform {

    template <typename real_p>
    using   real_t =
        std::uniform_real_distribution<real_p>;

    struct  real_tg     { class tag_lb; };

    template <typename ...>
    struct  real_ttg    {};

    template <typename type_p>
    concept real_tr =
        nkr::cpp::is_any_tr<type_p, real_t<typename type_p::result_type>>;

    template <template <typename ...> typename template_p>
    concept real_ttr =
        nkr::cpp::is_any_ttr<template_p, real_t, nkr::negatable::real_t>;

}}}}}

namespace nkr { namespace cpp { namespace randomness { namespace distributor { namespace uniform { namespace real_t$ {

    template <nkr::cpp::randomness::distributor::uniform::real_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = typename type_t::result_type;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::distributor::uniform::real_tg> type_p>
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

    template <nkr::cpp::randomness::distributor::uniform::real_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::randomness::distributor::uniform::real_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::distributor::uniform::real_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::randomness::distributor::uniform::real_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace cpp { namespace randomness { namespace distributor { namespace uniform { namespace real_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::randomness::distributor::uniform::real_ttr<template_p>
    class template_i_template_sp :
        public nkr::interface::template_i_identity_template_t<
            nkr::cpp::randomness::distributor::uniform::real_t,
            nkr::tuple::types_t<nkr::negatable::real_t>,
            nkr::constant::positive::count_t<1>,
            nkr::constant::positive::count_t<1>,
            nkr::cpp::randomness::distributor::uniform::real_tg,
            nkr::cpp::randomness::distributor::uniform::real_ttg
        >
    {
    public:
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::randomness::distributor::uniform::real_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_identity_tag_t<
            template_i_template_sp<nkr::cpp::randomness::distributor::uniform::real_t>
        >
    {
    public:
    };

}}}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::randomness::distributor::uniform::real_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::randomness::distributor::uniform::real_t$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::randomness::distributor::uniform::real_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::randomness::distributor::uniform::real_t$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/cpp/randomness/distributor/uniform/real_t_dec_def.h"
