/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_2476d36e_8c32_4c23_a1f2_b7840f2bc0f6
#define nkr_INCLUDE_GUARD_2476d36e_8c32_4c23_a1f2_b7840f2bc0f6

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/cpp/tuple/values_t_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_identity_tag_t_dec.h"
#include "nkr/interface/template_i_identity_template_t_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace accumulator {

    namespace types_t$  {};

}}

namespace nkr { namespace accumulator { namespace types_t$ {

    class common_t;

    template <nkr::tuple::types_tr types_p>
    class generic_sp;

}}}

namespace nkr { namespace accumulator { namespace types_t$ {

    template <nkr::tuple::types_tr types_p>
    class specialization_tmpl
    {
    public:
        using type_t    = generic_sp<types_p>;
    };

}}}

namespace nkr { namespace accumulator {

    template <nkr::tuple::types_tr types_p>
    using types_t =
        typename nkr::accumulator::types_t$::specialization_tmpl<types_p>::type_t;

    template <typename type_p>
    concept types_tr =
        nkr::cpp::is_any_tr<type_p, types_t<typename type_p::types_t>>;

    template <template <typename ...> typename template_p>
    concept types_ttr =
        nkr::cpp::is_any_ttr<template_p, types_t, nkr::tuple::types_t<>>;

    class types_tg
    {
    public:
        class   tag_lb      {};
        class   type_lb     {};
        class   identity_lb {};
    };

    template <typename ...>
    class types_ttg
    {
    public:
        class   tag_lb      {};
        class   template_lb {};
        class   identity_lb {};
    };

}}

namespace nkr { namespace accumulator { namespace types_t$ {

    template <nkr::accumulator::types_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = typename type_t::types_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::accumulator::types_tg> type_p>
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

    template <nkr::accumulator::types_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::accumulator::types_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::accumulator::types_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::accumulator::types_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace accumulator { namespace types_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::accumulator::types_ttr<template_p>
    class template_i_template_sp :
        public nkr::interface::template_i_identity_template_t<
            nkr::accumulator::types_t,
            nkr::tuple::types_t<nkr::tuple::types_t<>>,
            nkr::constant::positive::count_t<1>,
            nkr::constant::positive::count_t<1>,
            nkr::accumulator::types_tg,
            nkr::accumulator::types_ttg
        >
    {
    public:
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::accumulator::types_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_identity_tag_t<
            template_i_template_sp<nkr::accumulator::types_t>
        >
    {
    public:
    };

}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::accumulator::types_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::accumulator::types_t$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::accumulator::types_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::accumulator::types_t$::template_i_tag_sp<template_p>;
    };

}}

namespace nkr { namespace accumulator { namespace types_t$ {

    class common_t
    {
    public:
        template <template <typename ...> typename algorithm_p, nkr::tuple::types_tr types_p>
        class accumulate_tmpl;

        template <template <typename ...> typename algorithm_p, nkr::tuple::types_tr types_p>
            requires (types_p::Count() == 0)
        class accumulate_tmpl<algorithm_p, types_p>
        {
        public:
            using type_t = nkr::tuple::types_t<>;
        };

        template <template <typename ...> typename algorithm_p, nkr::tuple::types_tr types_p>
            requires (types_p::Count() > 0)
        class accumulate_tmpl<algorithm_p, types_p>
        {
        public:
            using type_t = typename accumulate_tmpl<
                algorithm_p, typename types_p::tail_t
            >::type_t::template apply_front_t<
                algorithm_p<typename types_p::head_t>
            >;
        };

        template <template <typename ...> typename algorithm_p, nkr::tuple::types_tr types_p>
        using accumulate_t =
            typename accumulate_tmpl<algorithm_p, types_p>::type_t;

    public:
        template <
            template <typename ...> typename algorithm_a_p,
            template <typename ...> typename algorithm_b_p,
            nkr::tuple::types_tr types_p
        > class accumulate_per_tmpl;

        template <
            template <typename ...> typename algorithm_a_p,
            template <typename ...> typename algorithm_b_p,
            nkr::tuple::types_tr types_p
        >
            requires (types_p::Count() > 0)
        class accumulate_per_tmpl<algorithm_a_p, algorithm_b_p, types_p>
        {
        public:
            using type_t = typename accumulate_per_tmpl<
                algorithm_a_p, algorithm_b_p, typename types_p::tail_t
            >::type_t::template apply_front_t<
                algorithm_a_p<typename types_p::head_t>::template each_with_each_t<algorithm_b_p<typename types_p::head_t>>
            >;
        };

        template <
            template <typename ...> typename algorithm_a_p,
            template <typename ...> typename algorithm_b_p,
            nkr::tuple::types_tr types_p
        >
            requires (types_p::Count() == 0)
        class accumulate_per_tmpl<algorithm_a_p, algorithm_b_p, types_p>
        {
        public:
            using type_t = nkr::tuple::types_t<>;
        };

        template <
            template <typename ...> typename algorithm_a_p,
            template <typename ...> typename algorithm_b_p,
            nkr::tuple::types_tr types_p
        > using accumulate_per_t =
            typename accumulate_per_tmpl<algorithm_a_p, algorithm_b_p, types_p>::type_t;

    public:
        template <typename type_p>
        using just_const_t = nkr::tuple::types_t<
            nkr::cpp::just_const_t<type_p>
        >;

        template <typename type_p>
        using any_t = nkr::tuple::types_t<
            nkr::cpp::just_non_qualified_t<type_p>,
            nkr::cpp::just_const_t<type_p>,
            nkr::cpp::just_volatile_t<type_p>,
            nkr::cpp::just_const_volatile_t<type_p>
        >;

        template <typename type_p>
        using any_const_t = nkr::tuple::types_t<
            nkr::cpp::just_const_t<type_p>,
            nkr::cpp::just_const_volatile_t<type_p>
        >;
    };

}}}

namespace nkr { namespace accumulator { namespace types_t$ {

    template <nkr::tuple::types_tr types_p>
    class generic_sp
    {
    public:
        using types_t           = types_p;

    public:
        using common_t          = nkr::accumulator::types_t$::common_t;
        template <template <typename ...> typename algorithm_p>
        using accumulate_t      = common_t::template accumulate_t<algorithm_p, types_t>;
        template <template <typename ...> typename algorithm_a_p, template <typename ...> typename algorithm_b_p>
        using accumulate_per_t  = common_t::template accumulate_per_t<algorithm_a_p, algorithm_b_p, types_t>;

    public:
        using just_const_ts     = accumulate_t<common_t::template just_const_t>;

        using any_ts            = accumulate_t<common_t::template any_t>;
        using any_const_ts      = accumulate_t<common_t::template any_const_t>;

        using any_per_any_ts    = accumulate_per_t<common_t::template any_t, common_t::template any_t>;

    public:
        using cpp_any_ts        = any_ts::template into_t<nkr::cpp::tuple::values_t>;

    public:
        template <typename ...>
        constexpr generic_sp(...) noexcept  = delete;
    };

}}}

#include "nkr/accumulator/types_t_dec_def.h"

#endif
