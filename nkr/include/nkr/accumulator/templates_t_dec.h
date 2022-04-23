/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_ce04d73d_d056_49aa_a32b_8d1b215b3160
#define nkr_INCLUDE_GUARD_ce04d73d_d056_49aa_a32b_8d1b215b3160

#include "nkr/accumulator/instantiations_t_dec.h"
#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/cpp/tuple/values_t_dec.h"
#include "nkr/tr_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace accumulator {

    namespace templates_t$  {};

}}

namespace nkr { namespace accumulator { namespace templates_t$ {

    class common_t;

    template <nkr::accumulator::instantiations_tr ...accumulators_p>
    class generic_sp;

}}}

namespace nkr { namespace accumulator { namespace templates_t$ {

    template <nkr::accumulator::instantiations_tr ...accumulators_p>
    class specialization_tmpl
    {
    public:
        using type_t    = generic_sp<accumulators_p...>;
    };

    template <nkr::accumulator::instantiations_tr ...accumulators_p>
    using specialization_t =
        typename specialization_tmpl<accumulators_p...>::type_t;

}}}

namespace nkr { namespace accumulator { namespace templates_t$ {

    // Annoyingly enough, we can't seem to use the specialization_t in this template function, but only the actual types.

    template <typename type_p>
    class is_tmpl :
        public nkr::constant::boolean::cpp_t<false>
    {
    public:
    };

    template <nkr::accumulator::instantiations_tr ...accumulators_p>
    class is_tmpl<generic_sp<accumulators_p...>> :
        public nkr::constant::boolean::cpp_t<true>
    {
    public:
    };

}}}

namespace nkr { namespace accumulator {

    template <nkr::accumulator::instantiations_tr ...accumulators_p>
    using templates_t =
        nkr::accumulator::templates_t$::specialization_t<accumulators_p...>;

    template <typename type_p>
    concept templates_tr =
        nkr::accumulator::templates_t$::is_tmpl<type_p>::Value();

}}

namespace nkr { namespace accumulator { namespace templates_t$ {

    class common_t
    {
    public:
    };

}}}

namespace nkr { namespace accumulator { namespace templates_t$ {

    template <nkr::accumulator::instantiations_tr ...accumulators_p>
    class generic_sp
    {
    public:
        template <typename operator_a_p, typename operator_b_p>
        using get_t = nkr::accumulator::templates_t$::common_t::template accumulate_t<
            operator_a_p, instantiator_p, operator_b_p, argument_tuples_p
        >;

        template <typename operator_a_p, typename operator_b_p, typename operator_c_p, typename operator_d_p>
        using get_pairs_t = nkr::accumulator::templates_t$::common_t::template accumulate_pairs_t<
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
                nkr::tuple::types_tr                arguments_p
            > typename  algorithm_p
        > using get_paired_types_t = nkr::accumulator::templates_t$::common_t::template accumulate_paired_types_t<
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
                nkr::tuple::types_tr                arguments_p
            > typename  algorithm_p
        > using get_paired_instantiations_t = nkr::accumulator::templates_t$::common_t::template accumulate_paired_instantiations_t<
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
                nkr::tuple::types_tr                arguments_p
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
                nkr::tuple::types_tr                arguments_p
            > typename  algorithm_p
        > using get_cpp_paired_instantiations_t =
            get_paired_instantiations_t<operator_a_p, operator_b_p, operator_c_p, operator_d_p, algorithm_p>::template into_t<nkr::cpp::tuple::values_t>;

    public:
        template <typename ...>
        constexpr generic_sp(...) noexcept  = delete;
    };

}}}

#include "nkr/accumulator/templates_t_dec_def.h"

#endif
