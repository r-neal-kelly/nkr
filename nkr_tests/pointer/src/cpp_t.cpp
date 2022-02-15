/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/generic/built_in_tr.h"
#include "nkr/generic/built_in/number_tr.h"
#include "nkr/generic/built_in/pointer_tr.h"
#include "nkr/generic/non_type_tr.h"
#include "nkr/negatable/integer_t.h"
#include "nkr/negatable/real_t.h"
#include "nkr/pointer/cpp_t.h"
#include "nkr/positive/integer_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::pointer::cpp_t")
    {
    #define nkr_TEMPLATES(TEMPLATE_QUALIFIER_p, TYPE_p)     \
        TEMPLATE_QUALIFIER_p nkr::pointer::cpp_t<TYPE_p>    \

    #include "nkr/macro/qualified_templates.h"

    #define nkr_TEMPLATE_INNERS(TEMPLATE_QUALIFIER_p, TEMPLATE_p, TYPE_QUALIFIER_p)     \
        TEMPLATE_QUALIFIER_p TEMPLATE_p<TYPE_QUALIFIER_p nkr::positive::integer_t>,     \
        TEMPLATE_QUALIFIER_p TEMPLATE_p<TYPE_QUALIFIER_p nkr::negatable::integer_t>,    \
        TEMPLATE_QUALIFIER_p TEMPLATE_p<TYPE_QUALIFIER_p nkr::negatable::real_t>        \

    #define nkr_TYPES(TYPE_QUALIFIER_p)                                             \
        nkr_TEMPLATE_INNERS(TYPE_QUALIFIER_p, nkr::pointer::cpp_t, nkr_BLANK),      \
        nkr_TEMPLATE_INNERS(TYPE_QUALIFIER_p, nkr::pointer::cpp_t, const),          \
        nkr_TEMPLATE_INNERS(TYPE_QUALIFIER_p, nkr::pointer::cpp_t, volatile),       \
        nkr_TEMPLATE_INNERS(TYPE_QUALIFIER_p, nkr::pointer::cpp_t, const volatile)  \

    #include "nkr/macro/qualified_types.h"

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
                using just_non_qualified_ts = ts<AND_tg, nkr_JUST_NON_QUALIFIED>;
                using just_const_ts = ts<AND_tg, nkr_JUST_CONST>;
                using just_volatile_ts = ts<AND_tg, nkr_JUST_VOLATILE>;
                using just_const_volatile_ts = ts<AND_tg, nkr_JUST_CONST_VOLATILE>;

                using any_ts = ts<AND_tg, nkr_ANY>;
                using any_qualified_ts = ts<AND_tg, nkr_ANY_QUALIFIED>;
                using any_non_qualified_ts = ts<AND_tg, nkr_ANY_NON_QUALIFIED>;
                using any_const_ts = ts<AND_tg, nkr_ANY_CONST>;
                using any_non_const_ts = ts<AND_tg, nkr_ANY_NON_CONST>;
                using any_volatile_ts = ts<AND_tg, nkr_ANY_VOLATILE>;
                using any_non_volatile_ts = ts<AND_tg, nkr_ANY_NON_VOLATILE>;

                using any_not_just_non_qualified_ts = ts<AND_tg, nkr_ANY_NOT_JUST_NON_QUALIFIED>;
                using any_not_just_const_ts = ts<AND_tg, nkr_ANY_NOT_JUST_CONST>;
                using any_not_just_volatile_ts = ts<AND_tg, nkr_ANY_NOT_JUST_VOLATILE>;
                using any_not_just_const_volatile_ts = ts<AND_tg, nkr_ANY_NOT_JUST_CONST_VOLATILE>;

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

                static_assert(TR<ts<AND_tg, nkr_ANY_OF_ANY(nkr::positive::integer_t)>,
                              any_tg, tt<nkr::pointer::cpp_t>,
                              of_any_tg, t<nkr::positive::integer_t>
                >());
            }
        }
    }

}
