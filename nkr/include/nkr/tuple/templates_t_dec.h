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
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace tuple { namespace templates_t$ {

    template <typename type_p>
    class   is_tmpl;

    template <typename ...>
    class   dummy_t;

}}}

namespace nkr { namespace tuple {

    template <template <typename ...> typename ...templates_p>
    class   templates_t;

    struct  templates_tg    { class tag_lb; };

    template <template <typename ...> typename ...>
    struct  templates_tttg  {};

    template <typename type_p>
    concept templates_tr =
        templates_t$::is_tmpl<nkr::cpp::just_non_qualified_t<type_p>>::Value();

    template <template <template <typename ...> typename ...> typename template_template_p>
    concept templates_tttr =
        nkr::cpp::is_any_tttr<template_template_p, templates_t, templates_t$::dummy_t>;

}}

namespace nkr { namespace tuple { namespace templates_t$ {

    template <nkr::tuple::templates_tr type_p>
    class type_i_type_sp
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
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::tuple::templates_tg> type_p>
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

}}}

namespace nkr { namespace interface {

    template <nkr::tuple::templates_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::tuple::templates_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::tuple::templates_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::tuple::templates_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace tuple { namespace templates_t$ {

    template <typename type_p>
    class is_tmpl :
        public nkr::constant::boolean::cpp_t<false>
    {
    public:
    };

    template <template <typename ...> typename ...templates_p>
    class is_tmpl<templates_t<templates_p...>> :
        public nkr::constant::boolean::cpp_t<true>
    {
    public:
    };

    template <template <typename ...> typename head_p, template <typename ...> typename ...tail_p>
    class is_tmpl<templates_t<head_p, tail_p...>> :
        public nkr::constant::boolean::cpp_t<true>
    {
    public:
    };

}}}

namespace nkr { namespace tuple { namespace templates_t$ {

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
        using type_t    = typename at_tmpl<tuple_p, index_p - 1>::type_t::tail_t;
    };

    template <typename tuple_p, nkr::positive::count_t count_p>
    class take_tmpl;

    template <typename tuple_p>
    class take_tmpl<tuple_p, 0>
    {
    public:
        using type_t    = templates_t<>;
    };

    template <typename tuple_p, nkr::positive::count_t count_p>
        requires (count_p > 0)
    class take_tmpl<tuple_p, count_p>
    {
    private:
        using front_t   = typename take_tmpl<tuple_p, count_p - 1>::type_t;

    public:
        using type_t    = typename front_t::template push_back_t<
            tuple_p::template at_t<nkr::constant::positive::index_t<count_p - 1>>::template head_t
        >;
    };

}}}

namespace nkr { namespace tuple {

    template <template <typename ...> typename ...templates_p>
    class templates_t
    {
    public:
        template <typename ...types_p>
        using head_t        = nkr::none::type_t;
        using tail_t        = templates_t<>;

        template <nkr::constant::positive::index_tr count_p>
            requires (count_p::Value() == 0)
        using at_t          = templates_t<>;

        template <nkr::constant::positive::count_tr count_p>
            requires (count_p::Value() == 0)
        using take_t        = templates_t<>;

        template <template <template <typename ...> typename ...> typename template_template_p>
        using into_t        = template_template_p<>;
        template <template <template <typename ...> typename ...> typename template_template_p, template <typename ...> typename ...back_templates_p>
        using into_front_t  = template_template_p<back_templates_p...>;
        template <template <template <typename ...> typename ...> typename template_template_p, template <typename ...> typename ...front_templates_p>
        using into_back_t   = template_template_p<front_templates_p...>;

        template <template <typename ...> typename ...templates_to_push_p>
        using push_front_t  = templates_t<templates_to_push_p...>;
        template <template <typename ...> typename ...templates_to_push_p>
        using push_back_t   = templates_t<templates_to_push_p...>;

    public:
        static constexpr nkr::positive::count_t Count() noexcept;

    public:
        template <typename ...>
        constexpr templates_t(...) noexcept = delete;
    };

}}

namespace nkr { namespace tuple {

    template <template <typename ...> typename head_p, template <typename ...> typename ...tail_p>
    class templates_t<head_p, tail_p...>
    {
    public:
        template <typename ...types_p>
        using head_t        = typename nkr::interface::template_i<head_p>::template actual_of_pack_t<types_p...>;
        using tail_t        = templates_t<tail_p...>;

        template <nkr::constant::positive::index_tr index_p>
            requires (index_p::Value() <= 1 + sizeof...(tail_p))
        using at_t          = typename templates_t$::at_tmpl<templates_t, index_p::Value()>::type_t;

        template <nkr::constant::positive::count_tr count_p>
            requires (count_p::Value() <= 1 + sizeof...(tail_p))
        using take_t        = typename templates_t$::take_tmpl<templates_t, count_p::Value()>::type_t;

        template <template <template <typename ...> typename ...> typename template_template_p>
        using into_t        = template_template_p<head_p, tail_p...>;
        template <template <template <typename ...> typename ...> typename template_template_p, template <typename ...> typename ...back_templates_p>
        using into_front_t  = template_template_p<head_p, tail_p..., back_templates_p...>;
        template <template <template <typename ...> typename ...> typename template_template_p, template <typename ...> typename ...front_templates_p>
        using into_back_t   = template_template_p<front_templates_p..., head_p, tail_p...>;

        template <template <typename ...> typename ...templates_to_push_p>
        using push_front_t  = templates_t<templates_to_push_p..., head_p, tail_p...>;
        template <template <typename ...> typename ...templates_to_push_p>
        using push_back_t   = templates_t<head_p, tail_p..., templates_to_push_p...>;

    public:
        static constexpr nkr::positive::count_t Count() noexcept;

    public:
        template <typename ...>
        constexpr templates_t(...) noexcept = delete;
    };

}}

#include "nkr/tuple/templates_t_dec_def.h"
