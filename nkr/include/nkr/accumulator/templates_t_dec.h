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

    template <nkr::tuple::types_tr instantiations_accumulators_p>
    class generic_sp;

}}}

namespace nkr { namespace accumulator { namespace templates_t$ {

    template <nkr::tuple::types_tr instantiations_accumulators_p>
    class specialization_tmpl
    {
    public:
        using type_t    = generic_sp<instantiations_accumulators_p>;
    };

    template <nkr::tuple::types_tr instantiations_accumulators_p>
    using specialization_t =
        typename specialization_tmpl<instantiations_accumulators_p>::type_t;

}}}

namespace nkr { namespace accumulator { namespace templates_t$ {

    // Annoyingly enough, we can't seem to use the specialization_t in this template function, but only the actual types.

    template <typename type_p>
    class is_tmpl :
        public nkr::constant::boolean::cpp_t<false>
    {
    public:
    };

    template <nkr::tuple::types_tr instantiations_accumulators_p>
    class is_tmpl<generic_sp<instantiations_accumulators_p>> :
        public nkr::constant::boolean::cpp_t<true>
    {
    public:
    };

}}}

namespace nkr { namespace accumulator {

    template <nkr::tuple::types_tr instantiations_accumulators_p>
    using templates_t =
        nkr::accumulator::templates_t$::specialization_t<instantiations_accumulators_p>;

    template <typename type_p>
    concept templates_tr =
        nkr::accumulator::templates_t$::is_tmpl<type_p>::Value();

    class templates_tg
    {
    public:
        class   tag_lb      {};
        class   type_lb     {};
        class   identity_lb {};
    };

}}

namespace nkr { namespace accumulator { namespace templates_t$ {

    template <nkr::accumulator::templates_tr type_p>
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

    template <nkr::cpp::is_any_tr<nkr::accumulator::templates_tg> type_p>
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

    template <nkr::accumulator::templates_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::accumulator::templates_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::accumulator::templates_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::accumulator::templates_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace accumulator { namespace templates_t$ {

    class common_t
    {
    public:
        template <
            nkr::tuple::types_tr    instantiations_accumulators_p,
            typename                operator_a_p,
            typename                operator_b_p
        > class accumulate_tmpl;

        template <
            nkr::tuple::types_tr    instantiations_accumulators_p,
            typename                operator_a_p,
            typename                operator_b_p
        >
            requires (instantiations_accumulators_p::Count() == 0)
        class accumulate_tmpl<instantiations_accumulators_p, operator_a_p, operator_b_p>
        {
        public:
            using type_t = nkr::tuple::types_t<>;
        };

        template <
            nkr::tuple::types_tr    instantiations_accumulators_p,
            typename                operator_a_p,
            typename                operator_b_p
        >
            requires (instantiations_accumulators_p::Count() > 0)
        class accumulate_tmpl<instantiations_accumulators_p, operator_a_p, operator_b_p>
        {
        public:
            using type_t = typename accumulate_tmpl<
                typename instantiations_accumulators_p::tail_t, operator_a_p, operator_b_p
            >::type_t::template apply_front_t<
                typename instantiations_accumulators_p::head_t::template get_t<operator_a_p, operator_b_p>
            >;
        };

        template <
            nkr::tuple::types_tr    instantiations_accumulators_p,
            typename                operator_a_p,
            typename                operator_b_p
        > using accumulate_t =
            typename accumulate_tmpl<instantiations_accumulators_p, operator_a_p, operator_b_p>::type_t;

    public:
        template <
            nkr::tuple::types_tr    instantiations_accumulators_p,
            typename                operator_a_p,
            typename                operator_b_p,
            typename                operator_c_p,
            typename                operator_d_p
        > class accumulate_pairs_tmpl;

        template <
            nkr::tuple::types_tr    instantiations_accumulators_p,
            typename                operator_a_p,
            typename                operator_b_p,
            typename                operator_c_p,
            typename                operator_d_p
        >
            requires (instantiations_accumulators_p::Count() == 0)
        class accumulate_pairs_tmpl<instantiations_accumulators_p, operator_a_p, operator_b_p, operator_c_p, operator_d_p>
        {
        public:
            using type_t = nkr::tuple::types_t<>;
        };

        template <
            nkr::tuple::types_tr    instantiations_accumulators_p,
            typename                operator_a_p,
            typename                operator_b_p,
            typename                operator_c_p,
            typename                operator_d_p
        >
            requires (instantiations_accumulators_p::Count() > 0)
        class accumulate_pairs_tmpl<instantiations_accumulators_p, operator_a_p, operator_b_p, operator_c_p, operator_d_p>
        {
        public:
            using type_t = typename accumulate_pairs_tmpl<
                typename instantiations_accumulators_p::tail_t, operator_a_p, operator_b_p, operator_c_p, operator_d_p
            >::type_t::template apply_front_t<
                typename instantiations_accumulators_p::head_t::template get_pairs_t<operator_a_p, operator_b_p, operator_c_p, operator_d_p>
            >;
        };

        template <
            nkr::tuple::types_tr    instantiations_accumulators_p,
            typename                operator_a_p,
            typename                operator_b_p,
            typename                operator_c_p,
            typename                operator_d_p
        > using accumulate_pairs_t =
            typename accumulate_pairs_tmpl<instantiations_accumulators_p, operator_a_p, operator_b_p, operator_c_p, operator_d_p>::type_t;

    public:
        template <
            nkr::tuple::types_tr    instantiations_accumulators_p,
            typename                operator_a_p,
            typename                operator_b_p,
            typename                operator_c_p,
            template <
                template <
                    nkr::tuple::types_tr                types_p
                > typename                          accumulator_p,
                typename                            instantiation_p,
                template <typename ...> typename    instantiator_p,
                nkr::tuple::types_tr                arguments_p
            > typename              algorithm_p
        > class accumulate_paired_types_tmpl;

        template <
            nkr::tuple::types_tr    instantiations_accumulators_p,
            typename                operator_a_p,
            typename                operator_b_p,
            typename                operator_c_p,
            template <
                template <
                    nkr::tuple::types_tr                types_p
                > typename                          accumulator_p,
                typename                            instantiation_p,
                template <typename ...> typename    instantiator_p,
                nkr::tuple::types_tr                arguments_p
            > typename              algorithm_p
        >
            requires (instantiations_accumulators_p::Count() == 0)
        class accumulate_paired_types_tmpl<instantiations_accumulators_p, operator_a_p, operator_b_p, operator_c_p, algorithm_p>
        {
        public:
            using type_t = nkr::tuple::types_t<>;
        };

        template <
            nkr::tuple::types_tr    instantiations_accumulators_p,
            typename                operator_a_p,
            typename                operator_b_p,
            typename                operator_c_p,
            template <
                template <
                    nkr::tuple::types_tr                types_p
                > typename                          accumulator_p,
                typename                            instantiation_p,
                template <typename ...> typename    instantiator_p,
                nkr::tuple::types_tr                arguments_p
            > typename              algorithm_p
        >
            requires (instantiations_accumulators_p::Count() > 0)
        class accumulate_paired_types_tmpl<instantiations_accumulators_p, operator_a_p, operator_b_p, operator_c_p, algorithm_p>
        {
        public:
            using type_t = typename accumulate_paired_types_tmpl<
                typename instantiations_accumulators_p::tail_t, operator_a_p, operator_b_p, operator_c_p, algorithm_p
            >::type_t::template apply_front_t<
                typename instantiations_accumulators_p::head_t::template get_paired_types_t<operator_a_p, operator_b_p, operator_c_p, algorithm_p>
            >;
        };

        template <
            nkr::tuple::types_tr    instantiations_accumulators_p,
            typename                operator_a_p,
            typename                operator_b_p,
            typename                operator_c_p,
            template <
                template <
                    nkr::tuple::types_tr                types_p
                > typename                          accumulator_p,
                typename                            instantiation_p,
                template <typename ...> typename    instantiator_p,
                nkr::tuple::types_tr                arguments_p
            > typename              algorithm_p
        > using accumulate_paired_types_t =
            typename accumulate_paired_types_tmpl<instantiations_accumulators_p, operator_a_p, operator_b_p, operator_c_p, algorithm_p>::type_t;

    public:
        template <
            nkr::tuple::types_tr    instantiations_accumulators_p,
            typename                operator_a_p,
            typename                operator_b_p,
            typename                operator_c_p,
            typename                operator_d_p,
            template <
                template <
                    template <typename ...> typename    instantiator_p,
                    nkr::tuple::types_tr                argument_tuples_p
                > typename                          accumulator_p,
                typename                            instantiation_p,
                template <typename ...> typename    instantiator_p,
                nkr::tuple::types_tr                arguments_p
            > typename              algorithm_p
        > class accumulate_paired_instantiations_tmpl;

        template <
            nkr::tuple::types_tr    instantiations_accumulators_p,
            typename                operator_a_p,
            typename                operator_b_p,
            typename                operator_c_p,
            typename                operator_d_p,
            template <
                template <
                    template <typename ...> typename    instantiator_p,
                    nkr::tuple::types_tr                argument_tuples_p
                > typename                          accumulator_p,
                typename                            instantiation_p,
                template <typename ...> typename    instantiator_p,
                nkr::tuple::types_tr                arguments_p
            > typename              algorithm_p
        >
            requires (instantiations_accumulators_p::Count() == 0)
        class accumulate_paired_instantiations_tmpl<instantiations_accumulators_p, operator_a_p, operator_b_p, operator_c_p, operator_d_p, algorithm_p>
        {
        public:
            using type_t = nkr::tuple::types_t<>;
        };

        template <
            nkr::tuple::types_tr    instantiations_accumulators_p,
            typename                operator_a_p,
            typename                operator_b_p,
            typename                operator_c_p,
            typename                operator_d_p,
            template <
                template <
                    template <typename ...> typename    instantiator_p,
                    nkr::tuple::types_tr                argument_tuples_p
                > typename                          accumulator_p,
                typename                            instantiation_p,
                template <typename ...> typename    instantiator_p,
                nkr::tuple::types_tr                arguments_p
            > typename              algorithm_p
        >
            requires (instantiations_accumulators_p::Count() > 0)
        class accumulate_paired_instantiations_tmpl<instantiations_accumulators_p, operator_a_p, operator_b_p, operator_c_p, operator_d_p, algorithm_p>
        {
        public:
            using type_t = typename accumulate_paired_instantiations_tmpl<
                typename instantiations_accumulators_p::tail_t, operator_a_p, operator_b_p, operator_c_p, operator_d_p, algorithm_p
            >::type_t::template apply_front_t<
                typename instantiations_accumulators_p::head_t::template get_paired_instantiations_t<operator_a_p, operator_b_p, operator_c_p, operator_d_p, algorithm_p>
            >;
        };

        template <
            nkr::tuple::types_tr    instantiations_accumulators_p,
            typename                operator_a_p,
            typename                operator_b_p,
            typename                operator_c_p,
            typename                operator_d_p,
            template <
                template <
                    template <typename ...> typename    instantiator_p,
                    nkr::tuple::types_tr                argument_tuples_p
                > typename                          accumulator_p,
                typename                            instantiation_p,
                template <typename ...> typename    instantiator_p,
                nkr::tuple::types_tr                arguments_p
            > typename              algorithm_p
        > using accumulate_paired_instantiations_t =
            typename accumulate_paired_instantiations_tmpl<instantiations_accumulators_p, operator_a_p, operator_b_p, operator_c_p, operator_d_p, algorithm_p>::type_t;
    };

}}}

namespace nkr { namespace accumulator { namespace templates_t$ {

    template <nkr::tuple::types_tr instantiations_accumulators_p>
    class generic_sp
    {
    public:
        template <typename operator_a_p, typename operator_b_p>
        using get_t = nkr::accumulator::templates_t$::common_t::template accumulate_t<
            instantiations_accumulators_p, operator_a_p, operator_b_p
        >;

        template <typename operator_a_p, typename operator_b_p, typename operator_c_p, typename operator_d_p>
        using get_pairs_t = nkr::accumulator::templates_t$::common_t::template accumulate_pairs_t<
            instantiations_accumulators_p, operator_a_p, operator_b_p, operator_c_p, operator_d_p
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
            instantiations_accumulators_p, operator_a_p, operator_b_p, operator_c_p, algorithm_p
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
            instantiations_accumulators_p, operator_a_p, operator_b_p, operator_c_p, operator_d_p, algorithm_p
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
