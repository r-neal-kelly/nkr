/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_a5a9f2e4_da8d_42e1_87bc_5836309f755a
#define nkr_INCLUDE_GUARD_a5a9f2e4_da8d_42e1_87bc_5836309f755a

#include "nkr/accumulator/types_t_dec.h"
#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/cpp/tuple/values_t_dec.h"
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
        using types_common_t                = nkr::accumulator::types_t$::common_t;

        template <typename type_p>
        using just_ts                       = types_common_t::template just_ts<type_p>;
        template <typename type_p>
        using just_non_qualified_ts         = types_common_t::template just_non_qualified_ts<type_p>;
        template <typename type_p>
        using just_const_ts                 = types_common_t::template just_const_ts<type_p>;
        template <typename type_p>
        using just_volatile_ts              = types_common_t::template just_volatile_ts<type_p>;
        template <typename type_p>
        using just_const_volatile_ts        = types_common_t::template just_const_volatile_ts<type_p>;

        template <typename type_p>
        using any_ts                        = types_common_t::template any_ts<type_p>;
        template <typename type_p>
        using any_qualified_ts              = types_common_t::template any_qualified_ts<type_p>;
        template <typename type_p>
        using any_non_qualified_ts          = types_common_t::template any_non_qualified_ts<type_p>;
        template <typename type_p>
        using any_const_ts                  = types_common_t::template any_const_ts<type_p>;
        template <typename type_p>
        using any_non_const_ts              = types_common_t::template any_non_const_ts<type_p>;
        template <typename type_p>
        using any_volatile_ts               = types_common_t::template any_volatile_ts<type_p>;
        template <typename type_p>
        using any_non_volatile_ts           = types_common_t::template any_non_volatile_ts<type_p>;

        template <typename type_p>
        using just_not_ts                   = types_common_t::template just_not_ts<type_p>;
        template <typename type_p>
        using just_not_non_qualified_ts     = types_common_t::template just_not_non_qualified_ts<type_p>;
        template <typename type_p>
        using just_not_const_ts             = types_common_t::template just_not_const_ts<type_p>;
        template <typename type_p>
        using just_not_volatile_ts          = types_common_t::template just_not_volatile_ts<type_p>;
        template <typename type_p>
        using just_not_const_volatile_ts    = types_common_t::template just_not_const_volatile_ts<type_p>;

        template <typename type_p>
        using not_any_ts                    = types_common_t::template not_any_ts<type_p>;
        template <typename type_p>
        using not_any_qualified_ts          = types_common_t::template not_any_qualified_ts<type_p>;
        template <typename type_p>
        using not_any_non_qualified_ts      = types_common_t::template not_any_non_qualified_ts<type_p>;
        template <typename type_p>
        using not_any_const_ts              = types_common_t::template not_any_const_ts<type_p>;
        template <typename type_p>
        using not_any_non_const_ts          = types_common_t::template not_any_non_const_ts<type_p>;
        template <typename type_p>
        using not_any_volatile_ts           = types_common_t::template not_any_volatile_ts<type_p>;
        template <typename type_p>
        using not_any_non_volatile_ts       = types_common_t::template not_any_non_volatile_ts<type_p>;

    public:
        template <
            template <typename ...> typename                                            algorithm_a_p,
            template <typename ...> typename                                            template_p,
            template <template <typename ...> typename, typename, typename> typename    algorithm_b_p,
            nkr::tuple::types_tr                                                        argument_tuples_p
        > class accumulate_tmpl;

        template <
            template <typename ...> typename                                            algorithm_a_p,
            template <typename ...> typename                                            template_p,
            template <template <typename ...> typename, typename, typename> typename    algorithm_b_p,
            nkr::tuple::types_tr                                                        argument_tuples_p
        >
            requires (argument_tuples_p::Count() == 0)
        class accumulate_tmpl<algorithm_a_p, template_p, algorithm_b_p, argument_tuples_p>
        {
        public:
            using type_t = nkr::tuple::types_t<>;
        };

        template <
            template <typename ...> typename                                            algorithm_a_p,
            template <typename ...> typename                                            template_p,
            template <template <typename ...> typename, typename, typename> typename    algorithm_b_p,
            nkr::tuple::types_tr                                                        argument_tuples_p
        >
            requires (argument_tuples_p::Count() > 0)
        class accumulate_tmpl<algorithm_a_p, template_p, algorithm_b_p, argument_tuples_p>
        {
        private:
            using accumulation_b_t = algorithm_b_p<
                template_p,
                typename argument_tuples_p::head_t::head_t,
                typename argument_tuples_p::head_t::tail_t
            >;

        public:
            using type_t = typename accumulate_tmpl<
                algorithm_a_p, template_p, algorithm_b_p, typename argument_tuples_p::tail_t
            >::type_t::template apply_front_t<
                types_common_t::template accumulate_t<algorithm_a_p, accumulation_b_t>
            >;
        };

        template <
            template <typename ...> typename                                            algorithm_a_p,
            template <typename ...> typename                                            template_p,
            template <template <typename ...> typename, typename, typename> typename    algorithm_b_p,
            nkr::tuple::types_tr                                                        argument_tuples_p
        > using accumulate_t =
            typename accumulate_tmpl<algorithm_a_p, template_p, algorithm_b_p, argument_tuples_p>::type_t;

    public:
        template <
            template <typename ...> typename                                            algorithm_a_p,
            template <template <typename ...> typename, typename, typename> typename    algorithm_b_p,
            template <typename ...> typename                                            algorithm_c_p,
            template <template <typename ...> typename, typename, typename> typename    algorithm_d_p,
            template <typename ...> typename                                            template_p,
            nkr::tuple::types_tr                                                        argument_tuples_p
        > class accumulate_with_tmpl;

        template <
            template <typename ...> typename                                            algorithm_a_p,
            template <template <typename ...> typename, typename, typename> typename    algorithm_b_p,
            template <typename ...> typename                                            algorithm_c_p,
            template <template <typename ...> typename, typename, typename> typename    algorithm_d_p,
            template <typename ...> typename                                            template_p,
            nkr::tuple::types_tr                                                        argument_tuples_p
        >
            requires (argument_tuples_p::Count() > 0)
        class accumulate_with_tmpl<algorithm_a_p, algorithm_b_p, algorithm_c_p, algorithm_d_p, template_p, argument_tuples_p>
        {
        private:
            using accumulation_b_t = algorithm_b_p<
                template_p,
                typename argument_tuples_p::head_t::head_t,
                typename argument_tuples_p::head_t::tail_t
            >;

            using accumulation_a_t = types_common_t::template accumulate_t<algorithm_a_p, accumulation_b_t>;

            using accumulation_d_t = algorithm_d_p<
                template_p,
                typename argument_tuples_p::head_t::head_t,
                typename argument_tuples_p::head_t::tail_t
            >;

            using accumulation_c_t = types_common_t::template accumulate_t<algorithm_c_p, accumulation_d_t>;

        public:
            using type_t = typename accumulate_with_tmpl<
                algorithm_a_p, algorithm_b_p, algorithm_c_p, algorithm_d_p, template_p, typename argument_tuples_p::tail_t
            >::type_t::template apply_front_t<
                accumulation_a_t::template each_with_each_t<accumulation_c_t>
            >;
        };

        template <
            template <typename ...> typename                                            algorithm_a_p,
            template <template <typename ...> typename, typename, typename> typename    algorithm_b_p,
            template <typename ...> typename                                            algorithm_c_p,
            template <template <typename ...> typename, typename, typename> typename    algorithm_d_p,
            template <typename ...> typename                                            template_p,
            nkr::tuple::types_tr                                                        argument_tuples_p
        >
            requires (argument_tuples_p::Count() == 0)
        class accumulate_with_tmpl<algorithm_a_p, algorithm_b_p, algorithm_c_p, algorithm_d_p, template_p, argument_tuples_p>
        {
        public:
            using type_t = nkr::tuple::types_t<>;
        };

        template <
            template <typename ...> typename                                            algorithm_a_p,
            template <template <typename ...> typename, typename, typename> typename    algorithm_b_p,
            template <typename ...> typename                                            algorithm_c_p,
            template <template <typename ...> typename, typename, typename> typename    algorithm_d_p,
            template <typename ...> typename                                            template_p,
            nkr::tuple::types_tr                                                        argument_tuples_p
        > using accumulate_with_t =
            typename accumulate_with_tmpl<algorithm_a_p, algorithm_b_p, algorithm_c_p, algorithm_d_p, template_p, argument_tuples_p>::type_t;

    public:
        template <template <typename ...> typename template_p, typename head_type_p, nkr::tuple::types_tr tail_types_p>
        using of_just_const_ts = nkr::tuple::types_t<
            typename tail_types_p::template push_front_t<nkr::cpp::just_const_t<head_type_p>>::template into_t<template_p>
        >;

        template <template <typename ...> typename template_p, typename head_type_p, nkr::tuple::types_tr tail_types_p>
        using of_any_ts = nkr::tuple::types_t<
            typename tail_types_p::template push_front_t<nkr::cpp::just_non_qualified_t<head_type_p>>::template into_t<template_p>,
            typename tail_types_p::template push_front_t<nkr::cpp::just_const_t<head_type_p>>::template into_t<template_p>,
            typename tail_types_p::template push_front_t<nkr::cpp::just_volatile_t<head_type_p>>::template into_t<template_p>,
            typename tail_types_p::template push_front_t<nkr::cpp::just_const_volatile_t<head_type_p>>::template into_t<template_p>
        >;

        template <template <typename ...> typename template_p, typename head_type_p, nkr::tuple::types_tr tail_types_p>
        using of_any_const_ts = nkr::tuple::types_t<
            typename tail_types_p::template push_front_t<nkr::cpp::just_const_t<head_type_p>>::template into_t<template_p>,
            typename tail_types_p::template push_front_t<nkr::cpp::just_const_volatile_t<head_type_p>>::template into_t<template_p>
        >;
    };

}}}

namespace nkr { namespace accumulator { namespace instantiations_t$ {

    template <template <typename ...> typename instantiator_p, nkr::tuple::types_tr argument_tuples_p>
    class generic_sp
    {
    public:
        using common_t  = nkr::accumulator::instantiations_t$::common_t;

        template <
            template <typename ...> typename                                            algorithm_a_p,
            template <template <typename ...> typename, typename, typename> typename    algorithm_b_p
        > using accumulate_t = common_t::template accumulate_t<
            algorithm_a_p,
            instantiator_p,
            algorithm_b_p,
            argument_tuples_p
        >;
        template <
            template <typename ...> typename                                            algorithm_a_p,
            template <template <typename ...> typename, typename, typename> typename    algorithm_b_p,
            template <typename ...> typename                                            algorithm_c_p,
            template <template <typename ...> typename, typename, typename> typename    algorithm_d_p
        > using accumulate_with_t = common_t::template accumulate_with_t<
            algorithm_a_p,
            algorithm_b_p,
            algorithm_c_p,
            algorithm_d_p,
            instantiator_p,
            argument_tuples_p
        >;

    public:
        using just_const_of_just_const_ts   = accumulate_t<common_t::template just_const_ts, common_t::template of_just_const_ts>;

        using any_of_any_ts                 = accumulate_t<common_t::template any_ts, common_t::template of_any_ts>;

        using any_const_of_any_const_ts     = accumulate_t<common_t::template any_const_ts, common_t::template of_any_const_ts>;

    public:
        using any_of_any_with_any_of_any_ts = accumulate_with_t<
            common_t::template any_ts,
            common_t::template of_any_ts,
            common_t::template any_ts,
            common_t::template of_any_ts
        >;

    public:
        class cpp_t
        {
        public:
            using any_of_any_ts = any_of_any_ts::template into_t<nkr::cpp::tuple::values_t>;
        };

    public:
        template <typename ...>
        constexpr generic_sp(...) noexcept  = delete;
    };

}}}

#include "nkr/accumulator/instantiations_t_dec_def.h"

#endif
