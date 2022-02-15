/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/generic/built_in_tr.h"
#include "nkr/generic/built_in/number_tr.h"
#include "nkr/generic/built_in/pointer_tr.h"
#include "nkr/generic/non_type_tr.h"
#include "nkr/macro/qualified_templates.h"
#include "nkr/macro/qualified_types.h"
#include "nkr/negatable/integer_t.h"
#include "nkr/negatable/real_t.h"
#include "nkr/pointer/cpp_t.h"
#include "nkr/positive/integer_t.h"
#include "nkr/tr.h"
#include "nkr/tuple/templates_t.h"
#include "nkr/tuple/types_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::pointer::cpp_t")
    {
    #define nkr_TEMPLATES(TEMPLATE_QUALIFIER_p, TYPE_p)     \
        TEMPLATE_QUALIFIER_p nkr::pointer::cpp_t<TYPE_p>    \

    #define nkr_TEMPLATE_INNERS(TEMPLATE_QUALIFIER_p, TEMPLATE_p, TYPE_QUALIFIER_p)     \
        TEMPLATE_QUALIFIER_p TEMPLATE_p<TYPE_QUALIFIER_p nkr::positive::integer_t>,     \
        TEMPLATE_QUALIFIER_p TEMPLATE_p<TYPE_QUALIFIER_p nkr::negatable::integer_t>,    \
        TEMPLATE_QUALIFIER_p TEMPLATE_p<TYPE_QUALIFIER_p nkr::negatable::real_t>        \

    #define nkr_TYPES(TYPE_QUALIFIER_p)                                             \
        nkr_TEMPLATE_INNERS(TYPE_QUALIFIER_p, nkr::pointer::cpp_t, nkr_BLANK),      \
        nkr_TEMPLATE_INNERS(TYPE_QUALIFIER_p, nkr::pointer::cpp_t, const),          \
        nkr_TEMPLATE_INNERS(TYPE_QUALIFIER_p, nkr::pointer::cpp_t, volatile),       \
        nkr_TEMPLATE_INNERS(TYPE_QUALIFIER_p, nkr::pointer::cpp_t, const volatile)  \

        nkr_DEFINE_QUALIFIED_TEMPLATE_TS;
        nkr_DEFINE_QUALIFIED_TYPE_TS;

        inline constexpr nkr::positive::count_t
            Interface_Iteration_Count()
            noexcept
        {
            return 128;
        }

        inline constexpr nkr::positive::count_t
            Global_Operator_Iteration_Count()
            noexcept
        {
            return 8;
        }

        TEST_SUITE("tr")
        {
            TEST_SUITE("container")
            {
                using target_ts = ts<AND_tg,
                    nkr::pointer::cpp_tg,

                    nkr::generic::built_in::pointer_tg
                >;

                using non_target_ts = ts<AND_tg,
                    nkr::generic::built_in::number_tg,
                    nkr::generic::non_type_tg
                >;

                class non_subject_t;
                using non_subject_ts = ts<AND_tg,
                    non_subject_t,
                    const non_subject_t,
                    volatile non_subject_t,
                    const volatile non_subject_t
                >;

                static_assert(TR<to_ts<AND_tg, any_ts>, any_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_ts>, any_tg, non_target_ts>());
                static_assert(TR<to_ts<NOR_tg, non_subject_ts>, any_tg, target_ts>());

                static_assert(TR<to_ts<AND_tg, any_qualified_ts>, any_qualified_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_non_qualified_ts>, any_qualified_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_ts>, any_qualified_tg, non_target_ts>());
                static_assert(TR<to_ts<NOR_tg, non_subject_ts>, any_qualified_tg, target_ts>());

                static_assert(TR<to_ts<AND_tg, any_non_qualified_ts>, any_non_qualified_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_qualified_ts>, any_non_qualified_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_ts>, any_non_qualified_tg, non_target_ts>());
                static_assert(TR<to_ts<NOR_tg, non_subject_ts>, any_non_qualified_tg, target_ts>());

                static_assert(TR<to_ts<AND_tg, any_const_ts>, any_const_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_non_const_ts>, any_const_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_ts>, any_const_tg, non_target_ts>());
                static_assert(TR<to_ts<NOR_tg, non_subject_ts>, any_const_tg, target_ts>());

                static_assert(TR<to_ts<AND_tg, any_non_const_ts>, any_non_const_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_const_ts>, any_non_const_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_ts>, any_non_const_tg, non_target_ts>());
                static_assert(TR<to_ts<NOR_tg, non_subject_ts>, any_non_const_tg, target_ts>());

                static_assert(TR<to_ts<AND_tg, any_volatile_ts>, any_volatile_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_non_volatile_ts>, any_volatile_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_ts>, any_volatile_tg, non_target_ts>());
                static_assert(TR<to_ts<NOR_tg, non_subject_ts>, any_volatile_tg, target_ts>());

                static_assert(TR<to_ts<AND_tg, any_non_volatile_ts>, any_non_volatile_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_volatile_ts>, any_non_volatile_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_ts>, any_non_volatile_tg, non_target_ts>());
                static_assert(TR<to_ts<NOR_tg, non_subject_ts>, any_non_volatile_tg, target_ts>());

                static_assert(TR<to_ts<AND_tg, just_non_qualified_ts>, just_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, just_const_ts>, just_tg, const target_ts>());
                static_assert(TR<to_ts<AND_tg, just_volatile_ts>, just_tg, volatile target_ts>());
                static_assert(TR<to_ts<AND_tg, just_const_volatile_ts>, just_tg, const volatile target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_not_just_non_qualified_ts>, just_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_not_just_const_ts>, just_tg, const target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_not_just_volatile_ts>, just_tg, volatile target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_not_just_const_volatile_ts>, just_tg, const volatile target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_ts>, just_tg, non_target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_ts>, just_tg, const non_target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_ts>, just_tg, volatile non_target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_ts>, just_tg, const volatile non_target_ts>());
                static_assert(TR<to_ts<NOR_tg, non_subject_ts>, just_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, non_subject_ts>, just_tg, const target_ts>());
                static_assert(TR<to_ts<NOR_tg, non_subject_ts>, just_tg, volatile target_ts>());
                static_assert(TR<to_ts<NOR_tg, non_subject_ts>, just_tg, const volatile target_ts>());

                static_assert(TR<to_ts<AND_tg, just_non_qualified_ts>, just_non_qualified_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_not_just_non_qualified_ts>, just_non_qualified_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_ts>, just_non_qualified_tg, non_target_ts>());
                static_assert(TR<to_ts<NOR_tg, non_subject_ts>, just_non_qualified_tg, target_ts>());

                static_assert(TR<to_ts<AND_tg, just_const_ts>, just_const_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_not_just_const_ts>, just_const_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_ts>, just_const_tg, non_target_ts>());
                static_assert(TR<to_ts<NOR_tg, non_subject_ts>, just_const_tg, target_ts>());

                static_assert(TR<to_ts<AND_tg, just_volatile_ts>, just_volatile_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_not_just_volatile_ts>, just_volatile_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_ts>, just_volatile_tg, non_target_ts>());
                static_assert(TR<to_ts<NOR_tg, non_subject_ts>, just_volatile_tg, target_ts>());

                static_assert(TR<to_ts<AND_tg, just_const_volatile_ts>, just_const_volatile_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_not_just_const_volatile_ts>, just_const_volatile_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_ts>, just_const_volatile_tg, non_target_ts>());
                static_assert(TR<to_ts<NOR_tg, non_subject_ts>, just_const_volatile_tg, target_ts>());

                static_assert(TR<to_ts<NOR_tg, any_ts>, not_any_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_ts>, not_any_tg, non_target_ts>());
                static_assert(TR<to_ts<AND_tg, non_subject_ts>, not_any_tg, target_ts>());

                static_assert(TR<to_ts<NOR_tg, any_qualified_ts>, not_any_qualified_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_non_qualified_ts>, not_any_qualified_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_ts>, not_any_qualified_tg, non_target_ts>());
                static_assert(TR<to_ts<AND_tg, non_subject_ts>, not_any_qualified_tg, target_ts>());

                static_assert(TR<to_ts<NOR_tg, any_non_qualified_ts>, not_any_non_qualified_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_qualified_ts>, not_any_non_qualified_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_ts>, not_any_non_qualified_tg, non_target_ts>());
                static_assert(TR<to_ts<AND_tg, non_subject_ts>, not_any_non_qualified_tg, target_ts>());

                static_assert(TR<to_ts<NOR_tg, any_const_ts>, not_any_const_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_non_const_ts>, not_any_const_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_ts>, not_any_const_tg, non_target_ts>());
                static_assert(TR<to_ts<AND_tg, non_subject_ts>, not_any_const_tg, target_ts>());

                static_assert(TR<to_ts<NOR_tg, any_non_const_ts>, not_any_non_const_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_const_ts>, not_any_non_const_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_ts>, not_any_non_const_tg, non_target_ts>());
                static_assert(TR<to_ts<AND_tg, non_subject_ts>, not_any_non_const_tg, target_ts>());

                static_assert(TR<to_ts<NOR_tg, any_volatile_ts>, not_any_volatile_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_non_volatile_ts>, not_any_volatile_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_ts>, not_any_volatile_tg, non_target_ts>());
                static_assert(TR<to_ts<AND_tg, non_subject_ts>, not_any_volatile_tg, target_ts>());

                static_assert(TR<to_ts<NOR_tg, any_non_volatile_ts>, not_any_non_volatile_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_volatile_ts>, not_any_non_volatile_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_ts>, not_any_non_volatile_tg, non_target_ts>());
                static_assert(TR<to_ts<AND_tg, non_subject_ts>, not_any_non_volatile_tg, target_ts>());

                static_assert(TR<to_ts<NOR_tg, just_non_qualified_ts>, just_not_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, just_const_ts>, just_not_tg, const target_ts>());
                static_assert(TR<to_ts<NOR_tg, just_volatile_ts>, just_not_tg, volatile target_ts>());
                static_assert(TR<to_ts<NOR_tg, just_const_volatile_ts>, just_not_tg, const volatile target_ts>());
                static_assert(TR<to_ts<AND_tg, any_not_just_non_qualified_ts>, just_not_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_not_just_const_ts>, just_not_tg, const target_ts>());
                static_assert(TR<to_ts<AND_tg, any_not_just_volatile_ts>, just_not_tg, volatile target_ts>());
                static_assert(TR<to_ts<AND_tg, any_not_just_const_volatile_ts>, just_not_tg, const volatile target_ts>());
                static_assert(TR<to_ts<AND_tg, any_ts>, just_not_tg, non_target_ts>());
                static_assert(TR<to_ts<AND_tg, any_ts>, just_not_tg, const non_target_ts>());
                static_assert(TR<to_ts<AND_tg, any_ts>, just_not_tg, volatile non_target_ts>());
                static_assert(TR<to_ts<AND_tg, any_ts>, just_not_tg, const volatile non_target_ts>());
                static_assert(TR<to_ts<AND_tg, non_subject_ts>, just_not_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, non_subject_ts>, just_not_tg, const target_ts>());
                static_assert(TR<to_ts<AND_tg, non_subject_ts>, just_not_tg, volatile target_ts>());
                static_assert(TR<to_ts<AND_tg, non_subject_ts>, just_not_tg, const volatile target_ts>());

                static_assert(TR<to_ts<NOR_tg, just_non_qualified_ts>, just_not_non_qualified_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_not_just_non_qualified_ts>, just_not_non_qualified_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_ts>, just_not_non_qualified_tg, non_target_ts>());
                static_assert(TR<to_ts<AND_tg, non_subject_ts>, just_not_non_qualified_tg, target_ts>());

                static_assert(TR<to_ts<NOR_tg, just_const_ts>, just_not_const_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_not_just_const_ts>, just_not_const_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_ts>, just_not_const_tg, non_target_ts>());
                static_assert(TR<to_ts<AND_tg, non_subject_ts>, just_not_const_tg, target_ts>());

                static_assert(TR<to_ts<NOR_tg, just_volatile_ts>, just_not_volatile_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_not_just_volatile_ts>, just_not_volatile_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_ts>, just_not_volatile_tg, non_target_ts>());
                static_assert(TR<to_ts<AND_tg, non_subject_ts>, just_not_volatile_tg, target_ts>());

                static_assert(TR<to_ts<NOR_tg, just_const_volatile_ts>, just_not_const_volatile_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_not_just_const_volatile_ts>, just_not_const_volatile_tg, target_ts>());
                static_assert(TR<to_ts<AND_tg, any_ts>, just_not_const_volatile_tg, non_target_ts>());
                static_assert(TR<to_ts<AND_tg, non_subject_ts>, just_not_const_volatile_tg, target_ts>());
            }

            TEST_SUITE("inner")
            {
                using container_tts = tts<AND_tg,
                    nkr::pointer::cpp_ttg,

                    nkr::generic::built_in::pointer_ttg
                >;

                using inner_ts = ts<OR_tg,
                    nkr::positive::integer_t,
                    nkr::negatable::integer_t,
                    nkr::negatable::real_t
                >;

                using non_target_ts = ts<AND_tg,
                    nkr::generic::built_in::number_tg,
                    nkr::generic::non_type_tg
                >;

                class non_subject_t;
                using non_subject_ts = ts<AND_tg,
                    non_subject_t,
                    const non_subject_t,
                    volatile non_subject_t,
                    const volatile non_subject_t
                >;

                /*static_assert(TR<to_ts<AND_tg, any_ts>, any_tg, target_ts>());
                static_assert(TR<to_ts<NOR_tg, any_ts>, any_tg, non_target_ts>());
                static_assert(TR<to_ts<NOR_tg, non_subject_ts>, any_tg, target_ts>());*/

                template <nkr::tuple::types_tr inners_p>
                inline constexpr nkr::boolean::cpp_t
                    TR_Each_Inner()
                    noexcept
                {
                    using inner_t = nkr::cpp::just_non_qualified_t<typename inners_p::head_t>;

                    if constexpr (inners_p::Count() > 0) {
                        static_assert(TR<to_ts<AND_tg, any_of_any_ts<inner_t>>,
                                      any_tg, tt<nkr::pointer::cpp_t>, of_any_tg, t<inner_t>
                        >());

                        return TR_Each_Inner<typename inners_p::tail_t>();
                    } else {
                        return true;
                    }
                }
                static_assert(TR_Each_Inner<nkr::tuple::types_t<
                              nkr::positive::integer_t,
                              nkr::negatable::integer_t,
                              nkr::negatable::real_t>
                >());
            }
        }
    }

}
