/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include <forward_list>

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace cpp { namespace list { namespace remote {

    template <typename unit_p, typename allocator_p = std::allocator<unit_p>>
    using   forward_t =
        std::forward_list<unit_p, allocator_p>;

    struct  forward_tg  { class tag_lb; };

    template <typename ...>
    struct  forward_ttg {};

    template <typename type_p>
    concept forward_tr =
        nkr::cpp::is_any_tr<type_p, forward_t<typename type_p::value_type, typename type_p::allocator_type>>;

    template <template <typename ...> typename template_p>
    concept forward_ttr =
        nkr::cpp::is_any_ttr<template_p, forward_t, nkr::positive::integer_t>;

}}}}

namespace nkr { namespace cpp { namespace list { namespace remote { namespace forward_t$ {

    template <nkr::cpp::list::remote::forward_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = type_t::value_type;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::list::remote::forward_tg> type_p>
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

    template <nkr::cpp::list::remote::forward_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::list::remote::forward_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::list::remote::forward_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::list::remote::forward_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace cpp { namespace list { namespace remote { namespace forward_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::list::remote::forward_ttr<template_p>
    class template_i_template_sp
    {
    public:
        template <typename unit_p, typename allocator_p = std::allocator<unit_p>>
        using template_t        = nkr::cpp::list::remote::forward_t<unit_p, allocator_p>;

        template <typename inner_p>
        using of_t              = template_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
            requires (parameters_p::Count() >= 1 && parameters_p::Count() <= 2)
        using of_tuple_t        = parameters_p::template into_t<template_t>;

        template <typename ...parameters_p>
        using of_pack_t         = of_tuple_t<nkr::tuple::types_t<parameters_p...>>;

        using example_t         = of_t<nkr::positive::integer_t>;

        template <typename integer_p>
        using actual_template_t = template_t<integer_p>;

        template <typename inner_p>
        using actual_of_t       = of_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
        using actual_of_tuple_t = of_tuple_t<parameters_p>;

        template <typename ...parameters_p>
        using actual_of_pack_t  = of_pack_t<parameters_p...>;

        using actual_example_t  = example_t;

        using type_tg           = nkr::cpp::list::remote::forward_tg;

        template <typename ...parameters_p>
        using template_tg       = nkr::cpp::list::remote::forward_ttg<parameters_p...>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Actual() noexcept;

    public:
        template <typename ...>
        constexpr template_i_template_sp(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::list::remote::forward_ttg>
    class template_i_tag_sp :
        public template_i_template_sp<nkr::cpp::list::remote::forward_t>
    {
    public:
        template <typename ...parameters_p>
        using actual_template_t = template_tg<parameters_p...>;

        template <typename inner_p>
        using actual_of_t       = actual_template_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
        using actual_of_tuple_t = parameters_p::template into_t<actual_template_t>;

        template <typename ...parameters_p>
        using actual_of_pack_t  = actual_template_t<parameters_p...>;

        using actual_example_t  = actual_template_t<>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Actual() noexcept;
    };

}}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::list::remote::forward_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::list::remote::forward_t$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::list::remote::forward_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::list::remote::forward_t$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/cpp/list/remote/forward_t_dec_def.h"