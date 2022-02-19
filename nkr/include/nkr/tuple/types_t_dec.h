/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/boolean/cpp_t_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/constant/positive/index_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"

namespace nkr { namespace tuple { namespace $types_t {

    template <typename type_p>
    class   is_tmpl;

    class   dummy_t;

}}}

namespace nkr { namespace tuple {

    template <typename ...types_p>
    class   types_t;

    struct  types_tg    {};

    template <typename>
    struct  types_ttg   {};

    template <typename type_p>
    concept types_tr =
        $types_t::is_tmpl<nkr::cpp::just_non_qualified_t<type_p>>::Value();

    template <template <typename ...> typename template_p>
    concept types_ttr =
        nkr::cpp::is_any_ttr<template_p, types_t, $types_t::dummy_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::tuple::types_tg>
    {
    public:
        using type_t    = nkr::tuple::types_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::tuple::types_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::tuple::types_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_p::head_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::tuple::types_ttg>
    {
    public:
        template <typename ...types_p>
        using template_t    = nkr::tuple::types_t<types_p...>;

        template <typename inner_p>
        using of_t          = template_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
            requires (parameters_p::Count() >= 0)
        using of_tuple_t    = parameters_p::template into_t<template_t>;

        template <typename ...parameters_p>
        using of_pack_t     = of_tuple_t<nkr::tuple::types_t<parameters_p...>>;

        using example_t     = of_t<nkr::tuple::$types_t::dummy_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::tuple::types_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::tuple::types_ttg>
    {
    public:
    };

}}

namespace nkr { namespace tuple { namespace $types_t {

    template <typename type_p>
    class is_tmpl :
        public nkr::constant::boolean::cpp_t<false>
    {
    public:
    };

    template <typename ...types_p>
    class is_tmpl<types_t<types_p...>> :
        public nkr::constant::boolean::cpp_t<true>
    {
    public:
    };

    template <typename head_p, typename ...tail_p>
    class is_tmpl<types_t<head_p, tail_p...>> :
        public nkr::constant::boolean::cpp_t<true>
    {
    public:
    };

}}}

namespace nkr { namespace tuple { namespace $types_t {

    template <typename tuple_p, nkr::positive::index_t index_p>
    class at_tmpl;

    template <typename tuple_p>
    class at_tmpl<tuple_p, 0>
    {
    public:
        using type_t    = tuple_p;
    };

    template <typename tuple_p, nkr::positive::index_t index_p>
    class at_tmpl
    {
    public:
        using type_t    = at_tmpl<tuple_p, index_p - 1>::type_t::tail_t;
    };

    template <typename tuple_p, nkr::positive::count_t count_p>
    class take_tmpl;

    template <typename tuple_p>
    class take_tmpl<tuple_p, 0>
    {
    public:
        using type_t    = types_t<>;
    };

    template <typename tuple_p, nkr::positive::count_t count_p>
        requires (count_p > 0)
    class take_tmpl<tuple_p, count_p>
    {
    private:
        using front_t   = take_tmpl<tuple_p, count_p - 1>::type_t;

    public:
        using type_t    = front_t::template push_back_t<
            typename tuple_p::template at_t<nkr::constant::positive::index_t<count_p - 1>>::head_t
        >;
    };

}}}

namespace nkr { namespace tuple {

    template <typename ...types_p>
    class types_t
    {
    public:
        using head_t        = nkr::none::type_t;
        using tail_t        = types_t<>;

        template <nkr::constant::positive::index_tr count_p>
            requires (count_p::Value() == 0)
        using at_t          = types_t<>;

        template <nkr::constant::positive::count_tr count_p>
            requires (count_p::Value() == 0)
        using take_t        = types_t<>;

        template <template <typename ...> typename template_p>
        using into_t        = template_p<>;
        template <template <typename ...> typename template_p, typename ...back_types_p>
        using into_front_t  = template_p<back_types_p...>;
        template <template <typename ...> typename template_p, typename ...front_types_p>
        using into_back_t   = template_p<front_types_p...>;

        template <typename ...types_p>
        using push_front_t  = types_t<types_p...>;
        template <typename ...types_p>
        using push_back_t   = types_t<types_p...>;

    public:
        static constexpr nkr::positive::count_t Count() noexcept;

    public:
        template <typename ...>
        constexpr types_t(...) noexcept = delete;
    };

}}

namespace nkr { namespace tuple {

    template <typename head_p, typename ...tail_p>
    class types_t<head_p, tail_p...>
    {
    public:
        using head_t        = head_p;
        using tail_t        = types_t<tail_p...>;

        template <nkr::constant::positive::index_tr index_p>
            requires (index_p::Value() <= 1 + sizeof...(tail_p))
        using at_t          = $types_t::at_tmpl<types_t, index_p::Value()>::type_t;

        template <nkr::constant::positive::count_tr count_p>
            requires (count_p::Value() <= 1 + sizeof...(tail_p))
        using take_t        = $types_t::take_tmpl<types_t, count_p::Value()>::type_t;

        template <template <typename ...> typename template_p>
        using into_t        = template_p<head_p, tail_p...>;
        template <template <typename ...> typename template_p, typename ...back_types_p>
        using into_front_t  = template_p<head_p, tail_p..., back_types_p...>;
        template <template <typename ...> typename template_p, typename ...front_types_p>
        using into_back_t   = template_p<front_types_p..., head_p, tail_p...>;

        template <typename ...types_p>
        using push_front_t  = types_t<types_p..., head_p, tail_p...>;
        template <typename ...types_p>
        using push_back_t   = types_t<head_p, tail_p..., types_p...>;

    public:
        static constexpr nkr::positive::count_t Count() noexcept;

    public:
        template <typename ...>
        constexpr types_t(...) noexcept = delete;
    };

}}

#include "nkr/tuple/types_t_dec_def.h"
