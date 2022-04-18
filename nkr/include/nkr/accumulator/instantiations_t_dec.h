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
        template <
            typename                            operator_a_p,
            template <typename ...> typename    template_p,
            typename                            operator_b_p,
            nkr::tuple::types_tr                argument_tuples_p
        > class accumulate_tmpl;

        template <
            typename                            operator_a_p,
            template <typename ...> typename    template_p,
            typename                            operator_b_p,
            nkr::tuple::types_tr                argument_tuples_p
        >
            requires (argument_tuples_p::Count() == 0)
        class accumulate_tmpl<operator_a_p, template_p, operator_b_p, argument_tuples_p>
        {
        public:
            using type_t = nkr::tuple::types_t<>;
        };

        template <
            typename                            operator_a_p,
            template <typename ...> typename    template_p,
            typename                            operator_b_p,
            nkr::tuple::types_tr                argument_tuples_p
        >
            requires (argument_tuples_p::Count() > 0)
        class accumulate_tmpl<operator_a_p, template_p, operator_b_p, argument_tuples_p>
        {
        private:
            using accumulation_b_t = nkr::accumulator::types_t$::common_t::template instantiations_t<
                template_p,
                operator_b_p,
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

        template <
            typename                            operator_a_p,
            template <typename ...> typename    template_p,
            typename                            operator_b_p,
            nkr::tuple::types_tr                argument_tuples_p
        > using accumulate_t =
            typename accumulate_tmpl<operator_a_p, template_p, operator_b_p, argument_tuples_p>::type_t;

    public:
        template <
            typename                            operator_a_p,
            template <typename ...> typename    template_p,
            typename                            operator_b_p,
            nkr::tuple::types_tr                argument_tuples_p,
            typename                            operator_c_p,
            typename                            operator_d_p
        > class accumulate_pairs_tmpl;

        template <
            typename                            operator_a_p,
            template <typename ...> typename    template_p,
            typename                            operator_b_p,
            nkr::tuple::types_tr                argument_tuples_p,
            typename                            operator_c_p,
            typename                            operator_d_p
        >
            requires (argument_tuples_p::Count() > 0)
        class accumulate_pairs_tmpl<operator_a_p, template_p, operator_b_p, argument_tuples_p, operator_c_p, operator_d_p>
        {
        private:
            using accumulation_a_t = accumulate_t<
                operator_a_p,
                template_p,
                operator_b_p,
                typename argument_tuples_p::template take_t<nkr::constant::positive::count_t<1>>
            >;

            using accumulation_b_t = accumulate_t<
                operator_c_p,
                template_p,
                operator_d_p,
                typename argument_tuples_p::template take_t<nkr::constant::positive::count_t<1>>
            >;

        public:
            using type_t = typename accumulate_pairs_tmpl<
                operator_a_p, template_p, operator_b_p, typename argument_tuples_p::tail_t, operator_c_p, operator_d_p
            >::type_t::template apply_front_t<
                accumulation_a_t::template each_with_each_t<accumulation_b_t>
            >;
        };

        template <
            typename                            operator_a_p,
            template <typename ...> typename    template_p,
            typename                            operator_b_p,
            nkr::tuple::types_tr                argument_tuples_p,
            typename                            operator_c_p,
            typename                            operator_d_p
        >
            requires (argument_tuples_p::Count() == 0)
        class accumulate_pairs_tmpl<operator_a_p, template_p, operator_b_p, argument_tuples_p, operator_c_p, operator_d_p>
        {
        public:
            using type_t = nkr::tuple::types_t<>;
        };

        template <
            typename                            operator_a_p,
            template <typename ...> typename    template_p,
            typename                            operator_b_p,
            nkr::tuple::types_tr                argument_tuples_p,
            typename                            operator_c_p,
            typename                            operator_d_p
        > using accumulate_pairs_t =
            typename accumulate_pairs_tmpl<operator_a_p, template_p, operator_b_p, argument_tuples_p, operator_c_p, operator_d_p>::type_t;

    public:
        template <
            typename                            operator_a_p,
            template <typename ...> typename    template_p,
            typename                            operator_b_p,
            nkr::tuple::types_tr                argument_tuples_p,
            typename                            operator_c_p,
            template <
                template <
                    nkr::tuple::types_tr                types_p
                > typename                          accumulator_p,
                typename                            instantiation_p,
                template <typename ...> typename    instantiator_p,
                nkr::tuple::types_tr                arguments_p,
                typename                            head_argument_p,
                nkr::tuple::types_tr                tail_arguments_p
            > typename                          algorithm_p
        > class accumulate_paired_types_tmpl;

        template <
            typename                            operator_a_p,
            template <typename ...> typename    template_p,
            typename                            operator_b_p,
            nkr::tuple::types_tr                argument_tuples_p,
            typename                            operator_c_p,
            template <
                template <
                    nkr::tuple::types_tr                types_p
                > typename                          accumulator_p,
                typename                            instantiation_p,
                template <typename ...> typename    instantiator_p,
                nkr::tuple::types_tr                arguments_p,
                typename                            head_argument_p,
                nkr::tuple::types_tr                tail_arguments_p
            > typename                          algorithm_p
        >
            requires (argument_tuples_p::Count() > 0)
        class accumulate_paired_types_tmpl<operator_a_p, template_p, operator_b_p, argument_tuples_p, operator_c_p, algorithm_p>
        {
        private:
            using accumulation_a_t = accumulate_t<
                operator_a_p,
                template_p,
                operator_b_p,
                typename argument_tuples_p::template take_t<nkr::constant::positive::count_t<1>>
            >;

            template <
                nkr::tuple::types_tr    callback_types_p
            > using algorithm_accumulator_t = nkr::accumulator::types_t$::common_t::accumulate_t<
                operator_c_p,
                callback_types_p
            >;

            using algorithm_accumulation_t = algorithm_p<
                algorithm_accumulator_t,
                typename argument_tuples_p::head_t::template into_t<template_p>,
                template_p,
                typename argument_tuples_p::head_t,
                typename argument_tuples_p::head_t::head_t,
                typename argument_tuples_p::head_t::tail_t
            >;
            static_assert(nkr::tuple::types_tr<algorithm_accumulation_t>);

        public:
            using type_t = typename accumulate_paired_types_tmpl<
                operator_a_p, template_p, operator_b_p, typename argument_tuples_p::tail_t, operator_c_p, algorithm_p
            >::type_t::template apply_front_t<
                accumulation_a_t::template each_with_each_t<algorithm_accumulation_t>
            >;
        };

        template <
            typename                            operator_a_p,
            template <typename ...> typename    template_p,
            typename                            operator_b_p,
            nkr::tuple::types_tr                argument_tuples_p,
            typename                            operator_c_p,
            template <
                template <
                    nkr::tuple::types_tr                types_p
                > typename                          accumulator_p,
                typename                            instantiation_p,
                template <typename ...> typename    instantiator_p,
                nkr::tuple::types_tr                arguments_p,
                typename                            head_argument_p,
                nkr::tuple::types_tr                tail_arguments_p
            > typename                          algorithm_p
        >
            requires (argument_tuples_p::Count() == 0)
        class accumulate_paired_types_tmpl<operator_a_p, template_p, operator_b_p, argument_tuples_p, operator_c_p, algorithm_p>
        {
        public:
            using type_t = nkr::tuple::types_t<>;
        };

        template <
            typename                            operator_a_p,
            template <typename ...> typename    template_p,
            typename                            operator_b_p,
            nkr::tuple::types_tr                argument_tuples_p,
            typename                            operator_c_p,
            template <
                template <
                    nkr::tuple::types_tr                types_p
                > typename                          accumulator_p,
                typename                            instantiation_p,
                template <typename ...> typename    instantiator_p,
                nkr::tuple::types_tr                arguments_p,
                typename                            head_argument_p,
                nkr::tuple::types_tr                tail_arguments_p
            > typename                          algorithm_p
        > using accumulate_paired_types_t =
            typename accumulate_paired_types_tmpl<operator_a_p, template_p, operator_b_p, argument_tuples_p, operator_c_p, algorithm_p>::type_t;

    public:
        template <
            typename                            operator_a_p,
            template <typename ...> typename    template_p,
            typename                            operator_b_p,
            nkr::tuple::types_tr                argument_tuples_p,
            typename                            operator_c_p,
            typename                            operator_d_p,
            template <
                template <
                    template <typename ...> typename    instantiator_p,
                    nkr::tuple::types_tr                argument_tuples_p
                > typename                          accumulator_p,
                typename                            instantiation_p,
                template <typename ...> typename    instantiator_p,
                nkr::tuple::types_tr                arguments_p,
                typename                            head_argument_p,
                nkr::tuple::types_tr                tail_arguments_p
            > typename                          algorithm_p
        > class accumulate_paired_instantiations_tmpl;

        template <
            typename                            operator_a_p,
            template <typename ...> typename    template_p,
            typename                            operator_b_p,
            nkr::tuple::types_tr                argument_tuples_p,
            typename                            operator_c_p,
            typename                            operator_d_p,
            template <
                template <
                    template <typename ...> typename    instantiator_p,
                    nkr::tuple::types_tr                argument_tuples_p
                > typename                          accumulator_p,
                typename                            instantiation_p,
                template <typename ...> typename    instantiator_p,
                nkr::tuple::types_tr                arguments_p,
                typename                            head_argument_p,
                nkr::tuple::types_tr                tail_arguments_p
            > typename                          algorithm_p
        >
            requires (argument_tuples_p::Count() > 0)
        class accumulate_paired_instantiations_tmpl<operator_a_p, template_p, operator_b_p, argument_tuples_p, operator_c_p, operator_d_p, algorithm_p>
        {
        private:
            using accumulation_a_t = accumulate_t<
                operator_a_p,
                template_p,
                operator_b_p,
                typename argument_tuples_p::template take_t<nkr::constant::positive::count_t<1>>
            >;

            template <
                template <typename ...> typename    callback_instantiator_p,
                nkr::tuple::types_tr                callback_argument_tuples_p
            > using algorithm_accumulator_t = accumulate_t<
                operator_c_p,
                callback_instantiator_p,
                operator_d_p,
                callback_argument_tuples_p
            >;

            using algorithm_accumulation_t = algorithm_p<
                algorithm_accumulator_t,
                typename argument_tuples_p::head_t::template into_t<template_p>,
                template_p,
                typename argument_tuples_p::head_t,
                typename argument_tuples_p::head_t::head_t,
                typename argument_tuples_p::head_t::tail_t
            >;
            static_assert(nkr::tuple::types_tr<algorithm_accumulation_t>);

        public:
            using type_t = typename accumulate_paired_instantiations_tmpl<
                operator_a_p, template_p, operator_b_p, typename argument_tuples_p::tail_t, operator_c_p, operator_d_p, algorithm_p
            >::type_t::template apply_front_t<
                accumulation_a_t::template each_with_each_t<algorithm_accumulation_t>
            >;
        };

        template <
            typename                            operator_a_p,
            template <typename ...> typename    template_p,
            typename                            operator_b_p,
            nkr::tuple::types_tr                argument_tuples_p,
            typename                            operator_c_p,
            typename                            operator_d_p,
            template <
                template <
                    template <typename ...> typename    instantiator_p,
                    nkr::tuple::types_tr                argument_tuples_p
                > typename                          accumulator_p,
                typename                            instantiation_p,
                template <typename ...> typename    instantiator_p,
                nkr::tuple::types_tr                arguments_p,
                typename                            head_argument_p,
                nkr::tuple::types_tr                tail_arguments_p
            > typename                          algorithm_p
        >
            requires (argument_tuples_p::Count() == 0)
        class accumulate_paired_instantiations_tmpl<operator_a_p, template_p, operator_b_p, argument_tuples_p, operator_c_p, operator_d_p, algorithm_p>
        {
        public:
            using type_t = nkr::tuple::types_t<>;
        };

        template <
            typename                            operator_a_p,
            template <typename ...> typename    template_p,
            typename                            operator_b_p,
            nkr::tuple::types_tr                argument_tuples_p,
            typename                            operator_c_p,
            typename                            operator_d_p,
            template <
                template <
                    template <typename ...> typename    instantiator_p,
                    nkr::tuple::types_tr                argument_tuples_p
                > typename                          accumulator_p,
                typename                            instantiation_p,
                template <typename ...> typename    instantiator_p,
                nkr::tuple::types_tr                arguments_p,
                typename                            head_argument_p,
                nkr::tuple::types_tr                tail_arguments_p
            > typename                          algorithm_p
        > using accumulate_paired_instantiations_t =
            typename accumulate_paired_instantiations_tmpl<operator_a_p, template_p, operator_b_p, argument_tuples_p, operator_c_p, operator_d_p, algorithm_p>::type_t;
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
        using get_pairs_t = nkr::accumulator::instantiations_t$::common_t::template accumulate_pairs_t<
            operator_a_p, instantiator_p, operator_b_p, argument_tuples_p, operator_c_p, operator_d_p
        >;

        template <
            typename    operator_a_p,
            typename    operator_b_p,
            typename    operator_c_p,
            template <
                template <
                    nkr::tuple::types_tr                types_p
                > typename                          accumulator_p,
                typename                            instantiation_p,
                template <typename ...> typename    instantiator_p,
                nkr::tuple::types_tr                arguments_p,
                typename                            head_argument_p,
                nkr::tuple::types_tr                tail_arguments_p
            > typename  algorithm_p
        > using get_paired_types_t = nkr::accumulator::instantiations_t$::common_t::template accumulate_paired_types_t<
            operator_a_p, instantiator_p, operator_b_p, argument_tuples_p, operator_c_p, algorithm_p
        >;

        template <
            typename    operator_a_p,
            typename    operator_b_p,
            typename    operator_c_p,
            typename    operator_d_p,
            template <
                template <
                    template <typename ...> typename    instantiator_p,
                    nkr::tuple::types_tr                argument_tuples_p
                > typename                          accumulator_p,
                typename                            instantiation_p,
                template <typename ...> typename    instantiator_p,
                nkr::tuple::types_tr                arguments_p,
                typename                            head_argument_p,
                nkr::tuple::types_tr                tail_arguments_p
            > typename  algorithm_p
        > using get_paired_instantiations_t = nkr::accumulator::instantiations_t$::common_t::template accumulate_paired_instantiations_t<
            operator_a_p, instantiator_p, operator_b_p, argument_tuples_p, operator_c_p, operator_d_p, algorithm_p
        >;

    public:
        template <typename operator_a_p, typename operator_b_p>
        using get_cpp_t =
            get_t<operator_a_p, operator_b_p>::template into_t<nkr::cpp::tuple::values_t>;

        template <typename operator_a_p, typename operator_b_p, typename operator_c_p, typename operator_d_p>
        using get_cpp_pairs_t =
            get_pairs_t<operator_a_p, operator_b_p, operator_c_p, operator_d_p>::template into_t<nkr::cpp::tuple::values_t>;

        template <
            typename    operator_a_p,
            typename    operator_b_p,
            typename    operator_c_p,
            template <
                template <
                    nkr::tuple::types_tr                types_p
                > typename                          accumulator_p,
                typename                            instantiation_p,
                template <typename ...> typename    instantiator_p,
                nkr::tuple::types_tr                arguments_p,
                typename                            head_argument_p,
                nkr::tuple::types_tr                tail_arguments_p
            > typename  algorithm_p
        > using get_cpp_paired_types_t =
            get_paired_types_t<operator_a_p, operator_b_p, operator_c_p, algorithm_p>::template into_t<nkr::cpp::tuple::values_t>;

        template <
            typename    operator_a_p,
            typename    operator_b_p,
            typename    operator_c_p,
            typename    operator_d_p,
            template <
                template <
                    template <typename ...> typename    instantiator_p,
                    nkr::tuple::types_tr                argument_tuples_p
                > typename                          accumulator_p,
                typename                            instantiation_p,
                template <typename ...> typename    instantiator_p,
                nkr::tuple::types_tr                arguments_p,
                typename                            head_argument_p,
                nkr::tuple::types_tr                tail_arguments_p
            > typename  algorithm_p
        > using get_cpp_paired_instantiations_t =
            get_paired_instantiations_t<operator_a_p, operator_b_p, operator_c_p, operator_d_p, algorithm_p>::template into_t<nkr::cpp::tuple::values_t>;

    public:
        template <typename ...>
        constexpr generic_sp(...) noexcept  = delete;
    };

}}}

#include "nkr/accumulator/instantiations_t_dec_def.h"

#endif
