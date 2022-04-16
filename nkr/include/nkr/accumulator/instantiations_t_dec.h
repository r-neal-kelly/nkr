/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_a5a9f2e4_da8d_42e1_87bc_5836309f755a
#define nkr_INCLUDE_GUARD_a5a9f2e4_da8d_42e1_87bc_5836309f755a

#include "nkr/accumulator/types_t_dec.h"
#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/cpp/tuple/values_t_dec.h"
#include "nkr/tr_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace accumulator {

    namespace instantiations_t$ {};

}}

namespace nkr { namespace accumulator { namespace instantiations_t$ {

    class common_t;

    template <template <typename ...> typename instantiator_p, nkr::tuple::types_tr argument_tuples_p>
    class generic_sp;

}}}

namespace nkr { namespace accumulator { namespace instantiations_t$ {

    template <template <typename ...> typename instantiator_p, nkr::tuple::types_tr argument_tuples_p>
    class specialization_tmpl
    {
    public:
        using type_t    = generic_sp<instantiator_p, argument_tuples_p>;
    };

}}}

namespace nkr { namespace accumulator {

    template <template <typename ...> typename instantiator_p, nkr::tuple::types_tr argument_tuples_p>
    using instantiations_t =
        typename nkr::accumulator::instantiations_t$::specialization_tmpl<instantiator_p, argument_tuples_p>::type_t;

}}

namespace nkr { namespace accumulator { namespace instantiations_t$ {

    class common_t
    {
    public:
        template <typename operator_p, template <typename ...> typename template_p, typename head_type_p, nkr::tuple::types_tr tail_types_p>
        class algorithm_tmpl;

        template <nkr::cpp::is_any_tr<of_just_const_tg> operator_p, template <typename ...> typename template_p, typename head_type_p, nkr::tuple::types_tr tail_types_p>
        class algorithm_tmpl<operator_p, template_p, head_type_p, tail_types_p>
        {
        public:
            using type_t = nkr::tuple::types_t<
                typename tail_types_p::template push_front_t<nkr::cpp::just_const_t<head_type_p>>::template into_t<template_p>
            >;
        };

        template <nkr::cpp::is_any_tr<of_any_tg> operator_p, template <typename ...> typename template_p, typename head_type_p, nkr::tuple::types_tr tail_types_p>
        class algorithm_tmpl<operator_p, template_p, head_type_p, tail_types_p>
        {
        public:
            using type_t = nkr::tuple::types_t<
                typename tail_types_p::template push_front_t<nkr::cpp::just_non_qualified_t<head_type_p>>::template into_t<template_p>,
                typename tail_types_p::template push_front_t<nkr::cpp::just_const_t<head_type_p>>::template into_t<template_p>,
                typename tail_types_p::template push_front_t<nkr::cpp::just_volatile_t<head_type_p>>::template into_t<template_p>,
                typename tail_types_p::template push_front_t<nkr::cpp::just_const_volatile_t<head_type_p>>::template into_t<template_p>
            >;
        };

        template <nkr::cpp::is_any_tr<of_any_const_tg> operator_p, template <typename ...> typename template_p, typename head_type_p, nkr::tuple::types_tr tail_types_p>
        class algorithm_tmpl<operator_p, template_p, head_type_p, tail_types_p>
        {
        public:
            using type_t = nkr::tuple::types_t<
                typename tail_types_p::template push_front_t<nkr::cpp::just_const_t<head_type_p>>::template into_t<template_p>,
                typename tail_types_p::template push_front_t<nkr::cpp::just_const_volatile_t<head_type_p>>::template into_t<template_p>
            >;
        };

        template <typename operator_p, template <typename ...> typename template_p, typename head_type_p, nkr::tuple::types_tr tail_types_p>
        using algorithm_t =
            typename algorithm_tmpl<operator_p, template_p, head_type_p, tail_types_p>::type_t;

    public:
        template <typename operator_a_p, template <typename ...> typename template_p, typename operator_b_p, nkr::tuple::types_tr argument_tuples_p>
        class accumulate_tmpl;

        template <typename operator_a_p, template <typename ...> typename template_p, typename operator_b_p, nkr::tuple::types_tr argument_tuples_p>
            requires (argument_tuples_p::Count() == 0)
        class accumulate_tmpl<operator_a_p, template_p, operator_b_p, argument_tuples_p>
        {
        public:
            using type_t = nkr::tuple::types_t<>;
        };

        template <typename operator_a_p, template <typename ...> typename template_p, typename operator_b_p, nkr::tuple::types_tr argument_tuples_p>
            requires (argument_tuples_p::Count() > 0)
        class accumulate_tmpl<operator_a_p, template_p, operator_b_p, argument_tuples_p>
        {
        private:
            using accumulation_b_t = algorithm_t<
                operator_b_p,
                template_p,
                typename argument_tuples_p::head_t::head_t,
                typename argument_tuples_p::head_t::tail_t
            >;

        public:
            using type_t = typename accumulate_tmpl<
                operator_a_p, template_p, operator_b_p, typename argument_tuples_p::tail_t
            >::type_t::template apply_front_t<
                nkr::accumulator::types_t$::common_t::template accumulate_t<operator_a_p, accumulation_b_t>
            >;
        };

        template <typename operator_a_p, template <typename ...> typename template_p, typename operator_b_p, nkr::tuple::types_tr argument_tuples_p>
        using accumulate_t =
            typename accumulate_tmpl<operator_a_p, template_p, operator_b_p, argument_tuples_p>::type_t;

    public:
        template <
            typename operator_a_p,
            typename operator_b_p,
            typename operator_c_p,
            typename operator_d_p,
            template <typename ...> typename template_p,
            nkr::tuple::types_tr argument_tuples_p
        > class accumulate_with_tmpl;

        template <
            typename operator_a_p,
            typename operator_b_p,
            typename operator_c_p,
            typename operator_d_p,
            template <typename ...> typename template_p,
            nkr::tuple::types_tr argument_tuples_p
        >
            requires (argument_tuples_p::Count() > 0)
        class accumulate_with_tmpl<operator_a_p, operator_b_p, operator_c_p, operator_d_p, template_p, argument_tuples_p>
        {
        private:
            using accumulation_b_t = algorithm_t<
                operator_b_p,
                template_p,
                typename argument_tuples_p::head_t::head_t,
                typename argument_tuples_p::head_t::tail_t
            >;

            using accumulation_a_t = nkr::accumulator::types_t$::common_t::template accumulate_t<operator_a_p, accumulation_b_t>;

            using accumulation_d_t = algorithm_t<
                operator_d_p,
                template_p,
                typename argument_tuples_p::head_t::head_t,
                typename argument_tuples_p::head_t::tail_t
            >;

            using accumulation_c_t = nkr::accumulator::types_t$::common_t::template accumulate_t<operator_c_p, accumulation_d_t>;

        public:
            using type_t = typename accumulate_with_tmpl<
                operator_a_p, operator_b_p, operator_c_p, operator_d_p, template_p, typename argument_tuples_p::tail_t
            >::type_t::template apply_front_t<
                accumulation_a_t::template each_with_each_t<accumulation_c_t>
            >;
        };

        template <
            typename operator_a_p,
            typename operator_b_p,
            typename operator_c_p,
            typename operator_d_p,
            template <typename ...> typename template_p,
            nkr::tuple::types_tr argument_tuples_p
        >
            requires (argument_tuples_p::Count() == 0)
        class accumulate_with_tmpl<operator_a_p, operator_b_p, operator_c_p, operator_d_p, template_p, argument_tuples_p>
        {
        public:
            using type_t = nkr::tuple::types_t<>;
        };

        template <
            typename operator_a_p,
            typename operator_b_p,
            typename operator_c_p,
            typename operator_d_p,
            template <typename ...> typename template_p,
            nkr::tuple::types_tr argument_tuples_p
        > using accumulate_with_t =
            typename accumulate_with_tmpl<operator_a_p, operator_b_p, operator_c_p, operator_d_p, template_p, argument_tuples_p>::type_t;
    };

}}}

namespace nkr { namespace accumulator { namespace instantiations_t$ {

    template <template <typename ...> typename instantiator_p, nkr::tuple::types_tr argument_tuples_p>
    class generic_sp
    {
    public:
        template <typename operator_a_p, typename operator_b_p>
        using get_t = nkr::accumulator::instantiations_t$::common_t::template accumulate_t<
            operator_a_p, instantiator_p, operator_b_p, argument_tuples_p
        >;

        template <typename operator_a_p, typename operator_b_p, typename operator_c_p, typename operator_d_p>
        using get_with_t = nkr::accumulator::instantiations_t$::common_t::template accumulate_with_t<
            operator_a_p, operator_b_p, operator_c_p, operator_d_p, instantiator_p, argument_tuples_p
        >;

        template <typename operator_a_p, typename operator_b_p>
        using get_cpp_t =
            get_t<operator_a_p, operator_b_p>::template into_t<nkr::cpp::tuple::values_t>;

        template <typename operator_a_p, typename operator_b_p, typename operator_c_p, typename operator_d_p>
        using get_cpp_with_t =
            get_with_t<operator_a_p, operator_b_p, operator_c_p, operator_d_p>::template into_t<nkr::cpp::tuple::values_t>;

    public:
        template <typename ...>
        constexpr generic_sp(...) noexcept  = delete;
    };

}}}

#include "nkr/accumulator/instantiations_t_dec_def.h"

#endif
