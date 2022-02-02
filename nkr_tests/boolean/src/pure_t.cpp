/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/boolean/cpp_t.h"
#include "nkr/boolean/pure_t.h"
#include "nkr/generic/boolean_tr.h"
#include "nkr/generic/boolean/any_tr.h"
#include "nkr/generic/boolean/pure_tr.h"
#include "nkr/generic/implementing/interface/none/value_tr.h"
#include "nkr/generic/implementing/interface/randomness/value_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"
#include "nkr/generic/implementing/self_tr.h"
#include "nkr/generic/number/integer_tr.h"
#include "nkr/generic/type_tr.h"
#include "nkr/negatable/integer_t.h"
#include "nkr/negatable/real_t.h"
#include "nkr/none/value_t.h"
#include "nkr/pointer/cpp_t.h"
#include "nkr/positive/integer_t.h"
#include "nkr/randomness/value.h"
#include "nkr/tr.h"

#include "doctest.h"

namespace nkr {

    // potential problem. we still need to finish up the boolean generics.
    static_assert(nkr::generic::boolean_tr<nkr::positive::integer_t>);

    TEST_SUITE("nkr::boolean::pure_t")
    {
    #define nkr_TYPES(TYPE_QUALIFIER_p)         \
        TYPE_QUALIFIER_p nkr::boolean::pure_t   \

    #define nkr_JUST_NON_QUALIFIED  \
        nkr_TYPES(nkr_BLANK)        \

    #define nkr_JUST_CONST  \
        nkr_TYPES(const)    \

    #define nkr_JUST_VOLATILE   \
        nkr_TYPES(volatile)     \

    #define nkr_JUST_CONST_VOLATILE \
        nkr_TYPES(const volatile)   \

    #define nkr_ANY             \
        nkr_JUST_NON_QUALIFIED, \
        nkr_JUST_CONST,         \
        nkr_JUST_VOLATILE,      \
        nkr_JUST_CONST_VOLATILE \

    #define nkr_ANY_QUALIFIED   \
        nkr_JUST_CONST,         \
        nkr_JUST_VOLATILE,      \
        nkr_JUST_CONST_VOLATILE \

    #define nkr_ANY_NON_QUALIFIED   \
        nkr_JUST_NON_QUALIFIED      \

    #define nkr_ANY_CONST       \
        nkr_JUST_CONST,         \
        nkr_JUST_CONST_VOLATILE \

    #define nkr_ANY_NON_CONST   \
        nkr_JUST_NON_QUALIFIED, \
        nkr_JUST_VOLATILE       \

    #define nkr_ANY_VOLATILE    \
        nkr_JUST_VOLATILE,      \
        nkr_JUST_CONST_VOLATILE \

    #define nkr_ANY_NON_VOLATILE    \
        nkr_JUST_NON_QUALIFIED,     \
        nkr_JUST_CONST              \

    #define nkr_ANY_NOT_JUST_NON_QUALIFIED  \
        nkr_JUST_CONST,                     \
        nkr_JUST_VOLATILE,                  \
        nkr_JUST_CONST_VOLATILE             \

    #define nkr_ANY_NOT_JUST_CONST  \
        nkr_JUST_NON_QUALIFIED,     \
        nkr_JUST_VOLATILE,          \
        nkr_JUST_CONST_VOLATILE     \

    #define nkr_ANY_NOT_JUST_VOLATILE   \
        nkr_JUST_NON_QUALIFIED,         \
        nkr_JUST_CONST,                 \
        nkr_JUST_CONST_VOLATILE         \

    #define nkr_ANY_NOT_JUST_CONST_VOLATILE \
        nkr_JUST_NON_QUALIFIED,             \
        nkr_JUST_CONST,                     \
        nkr_JUST_VOLATILE                   \

        using just_non_qualified_ts             = ts<AND_tg, nkr_JUST_NON_QUALIFIED>;
        using just_const_ts                     = ts<AND_tg, nkr_JUST_CONST>;
        using just_volatile_ts                  = ts<AND_tg, nkr_JUST_VOLATILE>;
        using just_const_volatile_ts            = ts<AND_tg, nkr_JUST_CONST_VOLATILE>;

        using any_ts                            = ts<AND_tg, nkr_ANY>;
        using any_qualified_ts                  = ts<AND_tg, nkr_ANY_QUALIFIED>;
        using any_non_qualified_ts              = ts<AND_tg, nkr_ANY_NON_QUALIFIED>;
        using any_const_ts                      = ts<AND_tg, nkr_ANY_CONST>;
        using any_non_const_ts                  = ts<AND_tg, nkr_ANY_NON_CONST>;
        using any_volatile_ts                   = ts<AND_tg, nkr_ANY_VOLATILE>;
        using any_non_volatile_ts               = ts<AND_tg, nkr_ANY_NON_VOLATILE>;

        using any_not_just_non_qualified_ts     = ts<AND_tg, nkr_ANY_NOT_JUST_NON_QUALIFIED>;
        using any_not_just_const_ts             = ts<AND_tg, nkr_ANY_NOT_JUST_CONST>;
        using any_not_just_volatile_ts          = ts<AND_tg, nkr_ANY_NOT_JUST_VOLATILE>;
        using any_not_just_const_volatile_ts    = ts<AND_tg, nkr_ANY_NOT_JUST_CONST_VOLATILE>;

        inline constexpr nkr::positive::count_t
            Default_Iteration_Count()
            noexcept
        {
            return 128;
        }

        TEST_SUITE("tr")
        {
            using target_ts = ts<AND_tg,
                nkr::boolean::pure_t,
                nkr::boolean::pure_tg,

                nkr::generic::boolean_tg,
                nkr::generic::boolean::any_tg,
                nkr::generic::boolean::pure_tg,
                nkr::generic::implementing::interface::none::value_tg,
                nkr::generic::implementing::interface::randomness::value_tg,
                nkr::generic::implementing::interface::type_tg,
                nkr::generic::implementing::self_tg,
                nkr::generic::type_tg
            >;

            using non_target_ts = ts<AND_tg,
                nkr::generic::number::integer_tg
            >;

            class other_t;
            using other_ts = ts<AND_tg,
                other_t,
                const other_t,
                volatile other_t,
                const volatile other_t
            >;
            using targets_for_other_ts = ts<AND_tg,
                nkr::boolean::pure_t,
                nkr::boolean::pure_tg,

                nkr::generic::boolean_tg,
                nkr::generic::boolean::any_tg,
                nkr::generic::boolean::pure_tg
            >;

            static_assert(TR<any_ts, any_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_ts, any_tg, to_ts<NOR_tg, non_target_ts>>());
            static_assert(TR<other_ts, any_tg, to_ts<NOR_tg, targets_for_other_ts>>());

            static_assert(TR<any_qualified_ts, any_qualified_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_non_qualified_ts, any_qualified_tg, to_ts<NOR_tg, target_ts>>());
            static_assert(TR<any_ts, any_qualified_tg, to_ts<NOR_tg, non_target_ts>>());
            static_assert(TR<other_ts, any_qualified_tg, to_ts<NOR_tg, targets_for_other_ts>>());

            static_assert(TR<any_non_qualified_ts, any_non_qualified_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_qualified_ts, any_non_qualified_tg, to_ts<NOR_tg, target_ts>>());
            static_assert(TR<any_ts, any_non_qualified_tg, to_ts<NOR_tg, non_target_ts>>());
            static_assert(TR<other_ts, any_non_qualified_tg, to_ts<NOR_tg, targets_for_other_ts>>());

            static_assert(TR<any_const_ts, any_const_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_non_const_ts, any_const_tg, to_ts<NOR_tg, target_ts>>());
            static_assert(TR<any_ts, any_const_tg, to_ts<NOR_tg, non_target_ts>>());
            static_assert(TR<other_ts, any_const_tg, to_ts<NOR_tg, targets_for_other_ts>>());

            static_assert(TR<any_non_const_ts, any_non_const_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_const_ts, any_non_const_tg, to_ts<NOR_tg, target_ts>>());
            static_assert(TR<any_ts, any_non_const_tg, to_ts<NOR_tg, non_target_ts>>());
            static_assert(TR<other_ts, any_non_const_tg, to_ts<NOR_tg, targets_for_other_ts>>());

            static_assert(TR<any_volatile_ts, any_volatile_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_non_volatile_ts, any_volatile_tg, to_ts<NOR_tg, target_ts>>());
            static_assert(TR<any_ts, any_volatile_tg, to_ts<NOR_tg, non_target_ts>>());
            static_assert(TR<other_ts, any_volatile_tg, to_ts<NOR_tg, targets_for_other_ts>>());

            static_assert(TR<any_non_volatile_ts, any_non_volatile_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_volatile_ts, any_non_volatile_tg, to_ts<NOR_tg, target_ts>>());
            static_assert(TR<any_ts, any_non_volatile_tg, to_ts<NOR_tg, non_target_ts>>());
            static_assert(TR<other_ts, any_non_volatile_tg, to_ts<NOR_tg, targets_for_other_ts>>());

            static_assert(TR<just_non_qualified_ts, just_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<just_const_ts, just_tg, const to_ts<AND_tg, target_ts>>());
            static_assert(TR<just_volatile_ts, just_tg, volatile to_ts<AND_tg, target_ts>>());
            static_assert(TR<just_const_volatile_ts, just_tg, const volatile to_ts<AND_tg, target_ts>>());
            static_assert(TR<to_ts<NOR_tg, any_not_just_non_qualified_ts>, just_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<to_ts<NOR_tg, any_not_just_const_ts>, just_tg, const to_ts<AND_tg, target_ts>>());
            static_assert(TR<to_ts<NOR_tg, any_not_just_volatile_ts>, just_tg, volatile to_ts<AND_tg, target_ts>>());
            static_assert(TR<to_ts<NOR_tg, any_not_just_const_volatile_ts>, just_tg, const volatile to_ts<AND_tg, target_ts>>());
            static_assert(TR<to_ts<NOR_tg, any_ts>, just_tg, to_ts<AND_tg, non_target_ts>>());
            static_assert(TR<to_ts<NOR_tg, any_ts>, just_tg, const to_ts<AND_tg, non_target_ts>>());
            static_assert(TR<to_ts<NOR_tg, any_ts>, just_tg, volatile to_ts<AND_tg, non_target_ts>>());
            static_assert(TR<to_ts<NOR_tg, any_ts>, just_tg, const volatile to_ts<AND_tg, non_target_ts>>());
            static_assert(TR<to_ts<NOR_tg, other_ts>, just_tg, to_ts<AND_tg, targets_for_other_ts>>());
            static_assert(TR<to_ts<NOR_tg, other_ts>, just_tg, const to_ts<AND_tg, targets_for_other_ts>>());
            static_assert(TR<to_ts<NOR_tg, other_ts>, just_tg, volatile to_ts<AND_tg, targets_for_other_ts>>());
            static_assert(TR<to_ts<NOR_tg, other_ts>, just_tg, const volatile to_ts<AND_tg, targets_for_other_ts>>());

            static_assert(TR<just_non_qualified_ts, just_non_qualified_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_not_just_non_qualified_ts, just_non_qualified_tg, to_ts<NOR_tg, target_ts>>());
            static_assert(TR<any_ts, just_non_qualified_tg, to_ts<NOR_tg, non_target_ts>>());
            static_assert(TR<other_ts, just_non_qualified_tg, to_ts<NOR_tg, targets_for_other_ts>>());

            static_assert(TR<just_const_ts, just_const_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_not_just_const_ts, just_const_tg, to_ts<NOR_tg, target_ts>>());
            static_assert(TR<any_ts, just_const_tg, to_ts<NOR_tg, non_target_ts>>());
            static_assert(TR<other_ts, just_const_tg, to_ts<NOR_tg, targets_for_other_ts>>());

            static_assert(TR<just_volatile_ts, just_volatile_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_not_just_volatile_ts, just_volatile_tg, to_ts<NOR_tg, target_ts>>());
            static_assert(TR<any_ts, just_volatile_tg, to_ts<NOR_tg, non_target_ts>>());
            static_assert(TR<other_ts, just_volatile_tg, to_ts<NOR_tg, targets_for_other_ts>>());

            static_assert(TR<just_const_volatile_ts, just_const_volatile_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_not_just_const_volatile_ts, just_const_volatile_tg, to_ts<NOR_tg, target_ts>>());
            static_assert(TR<any_ts, just_const_volatile_tg, to_ts<NOR_tg, non_target_ts>>());
            static_assert(TR<other_ts, just_const_volatile_tg, to_ts<NOR_tg, targets_for_other_ts>>());

            static_assert(TR<any_ts, not_any_tg, to_ts<NOR_tg, target_ts>>());
            static_assert(TR<any_ts, not_any_tg, to_ts<AND_tg, non_target_ts>>());
            static_assert(TR<other_ts, not_any_tg, to_ts<AND_tg, targets_for_other_ts>>());

            static_assert(TR<any_qualified_ts, not_any_qualified_tg, to_ts<NOR_tg, target_ts>>());
            static_assert(TR<any_non_qualified_ts, not_any_qualified_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_ts, not_any_qualified_tg, to_ts<AND_tg, non_target_ts>>());
            static_assert(TR<other_ts, not_any_qualified_tg, to_ts<AND_tg, targets_for_other_ts>>());

            static_assert(TR<any_non_qualified_ts, not_any_non_qualified_tg, to_ts<NOR_tg, target_ts>>());
            static_assert(TR<any_qualified_ts, not_any_non_qualified_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_ts, not_any_non_qualified_tg, to_ts<AND_tg, non_target_ts>>());
            static_assert(TR<other_ts, not_any_non_qualified_tg, to_ts<AND_tg, targets_for_other_ts>>());

            static_assert(TR<any_const_ts, not_any_const_tg, to_ts<NOR_tg, target_ts>>());
            static_assert(TR<any_non_const_ts, not_any_const_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_ts, not_any_const_tg, to_ts<AND_tg, non_target_ts>>());
            static_assert(TR<other_ts, not_any_const_tg, to_ts<AND_tg, targets_for_other_ts>>());

            static_assert(TR<any_non_const_ts, not_any_non_const_tg, to_ts<NOR_tg, target_ts>>());
            static_assert(TR<any_const_ts, not_any_non_const_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_ts, not_any_non_const_tg, to_ts<AND_tg, non_target_ts>>());
            static_assert(TR<other_ts, not_any_non_const_tg, to_ts<AND_tg, targets_for_other_ts>>());

            static_assert(TR<any_volatile_ts, not_any_volatile_tg, to_ts<NOR_tg, target_ts>>());
            static_assert(TR<any_non_volatile_ts, not_any_volatile_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_ts, not_any_volatile_tg, to_ts<AND_tg, non_target_ts>>());
            static_assert(TR<other_ts, not_any_volatile_tg, to_ts<AND_tg, targets_for_other_ts>>());

            static_assert(TR<any_non_volatile_ts, not_any_non_volatile_tg, to_ts<NOR_tg, target_ts>>());
            static_assert(TR<any_volatile_ts, not_any_non_volatile_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_ts, not_any_non_volatile_tg, to_ts<AND_tg, non_target_ts>>());
            static_assert(TR<other_ts, not_any_non_volatile_tg, to_ts<AND_tg, targets_for_other_ts>>());

            static_assert(TR<to_ts<NOR_tg, just_non_qualified_ts>, just_not_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<to_ts<NOR_tg, just_const_ts>, just_not_tg, const to_ts<AND_tg, target_ts>>());
            static_assert(TR<to_ts<NOR_tg, just_volatile_ts>, just_not_tg, volatile to_ts<AND_tg, target_ts>>());
            static_assert(TR<to_ts<NOR_tg, just_const_volatile_ts>, just_not_tg, const volatile to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_not_just_non_qualified_ts, just_not_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_not_just_const_ts, just_not_tg, const to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_not_just_volatile_ts, just_not_tg, volatile to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_not_just_const_volatile_ts, just_not_tg, const volatile to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_ts, just_not_tg, to_ts<AND_tg, non_target_ts>>());
            static_assert(TR<any_ts, just_not_tg, const to_ts<AND_tg, non_target_ts>>());
            static_assert(TR<any_ts, just_not_tg, volatile to_ts<AND_tg, non_target_ts>>());
            static_assert(TR<any_ts, just_not_tg, const volatile to_ts<AND_tg, non_target_ts>>());
            static_assert(TR<other_ts, just_not_tg, to_ts<AND_tg, targets_for_other_ts>>());
            static_assert(TR<other_ts, just_not_tg, const to_ts<AND_tg, targets_for_other_ts>>());
            static_assert(TR<other_ts, just_not_tg, volatile to_ts<AND_tg, targets_for_other_ts>>());
            static_assert(TR<other_ts, just_not_tg, const volatile to_ts<AND_tg, targets_for_other_ts>>());

            static_assert(TR<just_non_qualified_ts, just_not_non_qualified_tg, to_ts<NOR_tg, target_ts>>());
            static_assert(TR<any_not_just_non_qualified_ts, just_not_non_qualified_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_ts, just_not_non_qualified_tg, to_ts<AND_tg, non_target_ts>>());
            static_assert(TR<other_ts, just_not_non_qualified_tg, to_ts<AND_tg, targets_for_other_ts>>());

            static_assert(TR<just_const_ts, just_not_const_tg, to_ts<NOR_tg, target_ts>>());
            static_assert(TR<any_not_just_const_ts, just_not_const_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_ts, just_not_const_tg, to_ts<AND_tg, non_target_ts>>());
            static_assert(TR<other_ts, just_not_const_tg, to_ts<AND_tg, targets_for_other_ts>>());

            static_assert(TR<just_volatile_ts, just_not_volatile_tg, to_ts<NOR_tg, target_ts>>());
            static_assert(TR<any_not_just_volatile_ts, just_not_volatile_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_ts, just_not_volatile_tg, to_ts<AND_tg, non_target_ts>>());
            static_assert(TR<other_ts, just_not_volatile_tg, to_ts<AND_tg, targets_for_other_ts>>());

            static_assert(TR<just_const_volatile_ts, just_not_const_volatile_tg, to_ts<NOR_tg, target_ts>>());
            static_assert(TR<any_not_just_const_volatile_ts, just_not_const_volatile_tg, to_ts<AND_tg, target_ts>>());
            static_assert(TR<any_ts, just_not_const_volatile_tg, to_ts<AND_tg, non_target_ts>>());
            static_assert(TR<other_ts, just_not_const_volatile_tg, to_ts<AND_tg, targets_for_other_ts>>());
        }

        TEST_SUITE("interface")
        {
            TEST_SUITE("should satisfy nkr::interface::none::value_i")
            {
                TEST_SUITE("directly")
                {
                    TEST_CASE_TEMPLATE("should return false", pure_p, nkr_ANY_NON_QUALIFIED)
                    {
                        CHECK((nkr::interface::none::value_i<pure_p>::Value() == false));
                        CHECK((nkr::interface::none::value_i<pure_p>::Value() == pure_p(false)));
                    }
                }

                TEST_SUITE("through nkr::none::value_t")
                {
                    TEST_CASE_TEMPLATE("should return false", pure_p, nkr_ANY_NON_QUALIFIED)
                    {
                        CHECK((nkr::none::value_t<pure_p>() == false));
                        CHECK((nkr::none::value_t<pure_p>() == pure_p(false)));
                        CHECK((nkr::none::value_t<pure_p>() == nkr::none::value_t<pure_p>()));
                    }
                }
            }

            TEST_SUITE("should satisfy nkr::interface::randomness::value_i")
            {
                TEST_SUITE("directly")
                {
                    TEST_SUITE("with default parameters")
                    {
                        TEST_CASE_TEMPLATE("should return either false or true", pure_p, nkr_ANY)
                        {
                            nkr::positive::count_t true_count = 0;
                            nkr::positive::count_t false_count = 0;
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::interface::randomness::value_i<pure_p>::template Value<>() ?
                                    true_count += 1 :
                                    false_count += 1;
                            }

                            CHECK(true_count > 0);
                            CHECK(false_count > 0);
                        }

                        TEST_CASE_TEMPLATE("should return either false or true with a given generator", pure_p, nkr_ANY)
                        {
                            nkr::positive::count_t true_count = 0;
                            nkr::positive::count_t false_count = 0;
                            auto generator_lockee = nkr::randomness::generator::software::Default();
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::interface::randomness::value_i<pure_p>::template Value<>(generator_lockee.Value()) ?
                                    true_count += 1 :
                                    false_count += 1;
                            }

                            CHECK(true_count > 0);
                            CHECK(false_count > 0);
                        }
                    }

                    TEST_SUITE("with probability_for_true")
                    {
                        TEST_CASE_TEMPLATE("should always return false with 0.0", pure_p, nkr_ANY)
                        {
                            nkr::positive::count_t true_count = 0;
                            nkr::positive::count_t false_count = 0;
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::interface::randomness::value_i<pure_p>::template Value<>(nkr::negatable::real_t(0.0)) ?
                                    true_count += 1 :
                                    false_count += 1;
                            }

                            CHECK(true_count == 0);
                            CHECK(false_count > 0);
                        }

                        TEST_CASE_TEMPLATE("should always return true with 1.0", pure_p, nkr_ANY)
                        {
                            nkr::positive::count_t true_count = 0;
                            nkr::positive::count_t false_count = 0;
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::interface::randomness::value_i<pure_p>::template Value<>(nkr::negatable::real_t(1.0)) ?
                                    true_count += 1 :
                                    false_count += 1;
                            }

                            CHECK(true_count > 0);
                            CHECK(false_count == 0);
                        }

                        TEST_CASE_TEMPLATE("should return either false or true with any other value", pure_p, nkr_ANY)
                        {
                            nkr::positive::count_t true_count = 0;
                            nkr::positive::count_t false_count = 0;
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::interface::randomness::value_i<pure_p>::template Value<>(nkr::negatable::real_t(0.5)) ?
                                    true_count += 1 :
                                    false_count += 1;
                            }

                            CHECK(true_count > 0);
                            CHECK(false_count > 0);
                        }

                        TEST_CASE_TEMPLATE("should return either false or true with a given generator", pure_p, nkr_ANY)
                        {
                            nkr::positive::count_t true_count = 0;
                            nkr::positive::count_t false_count = 0;
                            auto generator_lockee = nkr::randomness::generator::software::Default();
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::interface::randomness::value_i<pure_p>::template Value<>(generator_lockee.Value(), nkr::negatable::real_t(0.5)) ?
                                    true_count += 1 :
                                    false_count += 1;
                            }

                            CHECK(true_count > 0);
                            CHECK(false_count > 0);
                        }
                    }

                    TEST_SUITE("with min and max")
                    {
                        TEST_CASE_TEMPLATE("should always return false when given false, false", pure_p, nkr_ANY)
                        {
                            nkr::positive::count_t true_count = 0;
                            nkr::positive::count_t false_count = 0;
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::interface::randomness::value_i<pure_p>::template Value<>(false, false) ?
                                    true_count += 1 :
                                    false_count += 1;
                            }

                            CHECK(true_count == 0);
                            CHECK(false_count > 0);
                        }

                        TEST_CASE_TEMPLATE("should always return true when given true, true", pure_p, nkr_ANY)
                        {
                            nkr::positive::count_t true_count = 0;
                            nkr::positive::count_t false_count = 0;
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::interface::randomness::value_i<pure_p>::template Value<>(true, true) ?
                                    true_count += 1 :
                                    false_count += 1;
                            }

                            CHECK(true_count > 0);
                            CHECK(false_count == 0);
                        }

                        TEST_CASE_TEMPLATE("should return either false or true when given false, true", pure_p, nkr_ANY)
                        {
                            nkr::positive::count_t true_count = 0;
                            nkr::positive::count_t false_count = 0;
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::interface::randomness::value_i<pure_p>::template Value<>(false, true) ?
                                    true_count += 1 :
                                    false_count += 1;
                            }

                            CHECK(true_count > 0);
                            CHECK(false_count > 0);
                        }

                        TEST_CASE_TEMPLATE("should return either false or true with a given generator", pure_p, nkr_ANY)
                        {
                            nkr::positive::count_t true_count = 0;
                            nkr::positive::count_t false_count = 0;
                            auto generator_lockee = nkr::randomness::generator::software::Default();
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::interface::randomness::value_i<pure_p>::template Value<>(generator_lockee.Value(), false, true) ?
                                    true_count += 1 :
                                    false_count += 1;
                            }

                            CHECK(true_count > 0);
                            CHECK(false_count > 0);
                        }
                    }
                }

                TEST_SUITE("through nkr::randomness::Value<>()")
                {
                    TEST_SUITE("with default parameters")
                    {
                        TEST_CASE_TEMPLATE("should return either false or true", pure_p, nkr_ANY)
                        {
                            nkr::positive::count_t true_count = 0;
                            nkr::positive::count_t false_count = 0;
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::randomness::Value<pure_p>() ?
                                    true_count += 1 :
                                    false_count += 1;
                            }

                            CHECK(true_count > 0);
                            CHECK(false_count > 0);
                        }

                        TEST_CASE_TEMPLATE("should return either false or true with a given generator", pure_p, nkr_ANY)
                        {
                            nkr::positive::count_t true_count = 0;
                            nkr::positive::count_t false_count = 0;
                            auto generator_lockee = nkr::randomness::generator::software::Default();
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::randomness::Value<pure_p>(generator_lockee.Value()) ?
                                    true_count += 1 :
                                    false_count += 1;
                            }

                            CHECK(true_count > 0);
                            CHECK(false_count > 0);
                        }
                    }

                    TEST_SUITE("with probability_for_true")
                    {
                        TEST_CASE_TEMPLATE("should always return false with 0.0", pure_p, nkr_ANY)
                        {
                            nkr::positive::count_t true_count = 0;
                            nkr::positive::count_t false_count = 0;
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::randomness::Value<pure_p>(nkr::negatable::real_t(0.0)) ?
                                    true_count += 1 :
                                    false_count += 1;
                            }

                            CHECK(true_count == 0);
                            CHECK(false_count > 0);
                        }

                        TEST_CASE_TEMPLATE("should always return true with 1.0", pure_p, nkr_ANY)
                        {
                            nkr::positive::count_t true_count = 0;
                            nkr::positive::count_t false_count = 0;
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::randomness::Value<pure_p>(nkr::negatable::real_t(1.0)) ?
                                    true_count += 1 :
                                    false_count += 1;
                            }

                            CHECK(true_count > 0);
                            CHECK(false_count == 0);
                        }

                        TEST_CASE_TEMPLATE("should return either false or true with any other value", pure_p, nkr_ANY)
                        {
                            nkr::positive::count_t true_count = 0;
                            nkr::positive::count_t false_count = 0;
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::randomness::Value<pure_p>(nkr::negatable::real_t(0.5)) ?
                                    true_count += 1 :
                                    false_count += 1;
                            }

                            CHECK(true_count > 0);
                            CHECK(false_count > 0);
                        }

                        TEST_CASE_TEMPLATE("should return either false or true with a given generator", pure_p, nkr_ANY)
                        {
                            nkr::positive::count_t true_count = 0;
                            nkr::positive::count_t false_count = 0;
                            auto generator_lockee = nkr::randomness::generator::software::Default();
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::randomness::Value<pure_p>(generator_lockee.Value(), nkr::negatable::real_t(0.5)) ?
                                    true_count += 1 :
                                    false_count += 1;
                            }

                            CHECK(true_count > 0);
                            CHECK(false_count > 0);
                        }
                    }

                    TEST_SUITE("with min and max")
                    {
                        TEST_CASE_TEMPLATE("should always return false when given false, false", pure_p, nkr_ANY)
                        {
                            nkr::positive::count_t true_count = 0;
                            nkr::positive::count_t false_count = 0;
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::randomness::Value<pure_p>(false, false) ?
                                    true_count += 1 :
                                    false_count += 1;
                            }

                            CHECK(true_count == 0);
                            CHECK(false_count > 0);
                        }

                        TEST_CASE_TEMPLATE("should always return true when given true, true", pure_p, nkr_ANY)
                        {
                            nkr::positive::count_t true_count = 0;
                            nkr::positive::count_t false_count = 0;
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::randomness::Value<pure_p>(true, true) ?
                                    true_count += 1 :
                                    false_count += 1;
                            }

                            CHECK(true_count > 0);
                            CHECK(false_count == 0);
                        }

                        TEST_CASE_TEMPLATE("should return either false or true when given false, true", pure_p, nkr_ANY)
                        {
                            nkr::positive::count_t true_count = 0;
                            nkr::positive::count_t false_count = 0;
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::randomness::Value<pure_p>(false, true) ?
                                    true_count += 1 :
                                    false_count += 1;
                            }

                            CHECK(true_count > 0);
                            CHECK(false_count > 0);
                        }

                        TEST_CASE_TEMPLATE("should return either false or true with a given generator", pure_p, nkr_ANY)
                        {
                            nkr::positive::count_t true_count = 0;
                            nkr::positive::count_t false_count = 0;
                            auto generator_lockee = nkr::randomness::generator::software::Default();
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::randomness::Value<pure_p>(generator_lockee.Value(), false, true) ?
                                    true_count += 1 :
                                    false_count += 1;
                            }

                            CHECK(true_count > 0);
                            CHECK(false_count > 0);
                        }
                    }
                }
            }
        }

        TEST_SUITE("aliases")
        {
            TEST_SUITE("value_t")
            {
                TEST_CASE_TEMPLATE("should have a value_t equal to nkr::boolean::cpp_t", pure_p, nkr_ANY)
                {
                    static_assert(nkr::cpp::is_tr<typename pure_p::value_t, nkr::boolean::cpp_t>);
                }
            }
        }

        TEST_SUITE("protected data")
        {
            TEST_SUITE("value")
            {
                TEST_CASE_TEMPLATE("should have a value of value_t", pure_p, nkr_ANY)
                {
                    class derived_t :
                        public pure_p
                    {
                    public:
                        static_assert(nkr::cpp::is_tr<decltype(derived_t::value), nkr::boolean::cpp_t>);
                    };
                }
            }
        }

        TEST_SUITE("objects")
        {
            class from_user_defined_t
            {
            public:
                using value_t   = nkr::boolean::cpp_t;

            protected:
                value_t value;

            public:
                constexpr from_user_defined_t(value_t value) noexcept :
                    value(value)
                {
                }

            public:
                constexpr operator from_user_defined_t::value_t()
                    const volatile noexcept
                {
                    return this->value;
                }
            };

            TEST_SUITE("default_ctor()")
            {
                TEST_CASE_TEMPLATE("should set its value to false", pure_p, nkr_ANY)
                {
                    pure_p pure;

                    CHECK((pure == false));
                }
            }

            TEST_SUITE("from_ctor()"
                       * doctest::description("should always copy the given convertible without changing it"))
            {
                TEST_SUITE("built-in")
                {
                #define nkr_FROM_BUILT_IN_TUPLES                                                                            \
                    nkr::tuple::types_t<nkr::boolean::pure_t, nkr::boolean::cpp_t>,                                         \
                    nkr::tuple::types_t<const nkr::boolean::pure_t, nkr::boolean::cpp_t>,                                   \
                    nkr::tuple::types_t<volatile nkr::boolean::pure_t, nkr::boolean::cpp_t>,                                \
                    nkr::tuple::types_t<const volatile nkr::boolean::pure_t, nkr::boolean::cpp_t>,                          \
                                                                                                                            \
                    nkr::tuple::types_t<nkr::boolean::pure_t, nkr::positive::integer_t>,                                    \
                    nkr::tuple::types_t<const nkr::boolean::pure_t, nkr::positive::integer_t>,                              \
                    nkr::tuple::types_t<volatile nkr::boolean::pure_t, nkr::positive::integer_t>,                           \
                    nkr::tuple::types_t<const volatile nkr::boolean::pure_t, nkr::positive::integer_t>,                     \
                                                                                                                            \
                    nkr::tuple::types_t<nkr::boolean::pure_t, nkr::negatable::integer_t>,                                   \
                    nkr::tuple::types_t<const nkr::boolean::pure_t, nkr::negatable::integer_t>,                             \
                    nkr::tuple::types_t<volatile nkr::boolean::pure_t, nkr::negatable::integer_t>,                          \
                    nkr::tuple::types_t<const volatile nkr::boolean::pure_t, nkr::negatable::integer_t>,                    \
                                                                                                                            \
                    nkr::tuple::types_t<nkr::boolean::pure_t, nkr::negatable::real_t>,                                      \
                    nkr::tuple::types_t<const nkr::boolean::pure_t, nkr::negatable::real_t>,                                \
                    nkr::tuple::types_t<volatile nkr::boolean::pure_t, nkr::negatable::real_t>,                             \
                    nkr::tuple::types_t<const volatile nkr::boolean::pure_t, nkr::negatable::real_t>,                       \
                                                                                                                            \
                    nkr::tuple::types_t<nkr::boolean::pure_t, nkr::pointer::cpp_t<nkr::positive::integer_t>>,               \
                    nkr::tuple::types_t<const nkr::boolean::pure_t, nkr::pointer::cpp_t<nkr::positive::integer_t>>,         \
                    nkr::tuple::types_t<volatile nkr::boolean::pure_t, nkr::pointer::cpp_t<nkr::positive::integer_t>>,      \
                    nkr::tuple::types_t<const volatile nkr::boolean::pure_t, nkr::pointer::cpp_t<nkr::positive::integer_t>> \

                    TEST_SUITE("non-qualified")
                    {
                        TEST_CASE_TEMPLATE("value", tuple_p, nkr_FROM_BUILT_IN_TUPLES)
                        {
                            using pure_t = tuple_p::template at_t<nkr::positive::index_c<0>>::head_t;
                            using from_t = tuple_p::template at_t<nkr::positive::index_c<1>>::head_t;
                            using value_t = pure_t::value_t;

                            nkr::cpp::just_non_qualified_t<from_t> from = nkr::randomness::Value<from_t>();
                            pure_t pure = from_t(from);

                            CHECK(pure() == static_cast<value_t>(from));
                        }

                        TEST_CASE_TEMPLATE("lvalue", tuple_p, nkr_FROM_BUILT_IN_TUPLES)
                        {
                            using pure_t = tuple_p::template at_t<nkr::positive::index_c<0>>::head_t;
                            using from_t = tuple_p::template at_t<nkr::positive::index_c<1>>::head_t;
                            using value_t = pure_t::value_t;

                            nkr::cpp::just_non_qualified_t<from_t> from = nkr::randomness::Value<from_t>();
                            pure_t pure = from;

                            CHECK(pure() == static_cast<value_t>(from));
                        }

                        TEST_CASE_TEMPLATE("rvalue", tuple_p, nkr_FROM_BUILT_IN_TUPLES)
                        {
                            using pure_t = tuple_p::template at_t<nkr::positive::index_c<0>>::head_t;
                            using from_t = tuple_p::template at_t<nkr::positive::index_c<1>>::head_t;
                            using value_t = pure_t::value_t;

                            nkr::cpp::just_non_qualified_t<from_t> from = nkr::randomness::Value<from_t>();
                            nkr::cpp::just_non_qualified_t<from_t> backup = from;
                            pure_t pure = nkr::cpp::Move(from);

                            CHECK(pure() == static_cast<value_t>(backup));
                        }
                    }

                    TEST_SUITE("const")
                    {
                        TEST_CASE_TEMPLATE("lvalue", tuple_p, nkr_FROM_BUILT_IN_TUPLES)
                        {
                            using pure_t = tuple_p::template at_t<nkr::positive::index_c<0>>::head_t;
                            using from_t = tuple_p::template at_t<nkr::positive::index_c<1>>::head_t;
                            using value_t = pure_t::value_t;

                            nkr::cpp::just_const_t<from_t> from = nkr::randomness::Value<from_t>();
                            pure_t pure = from;

                            CHECK(pure() == static_cast<value_t>(from));
                        }
                    }

                    TEST_SUITE("volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", tuple_p, nkr_FROM_BUILT_IN_TUPLES)
                        {
                            using pure_t = tuple_p::template at_t<nkr::positive::index_c<0>>::head_t;
                            using from_t = tuple_p::template at_t<nkr::positive::index_c<1>>::head_t;
                            using value_t = pure_t::value_t;

                            nkr::cpp::just_volatile_t<from_t> from = nkr::randomness::Value<from_t>();
                            pure_t pure = from;

                            CHECK(pure() == static_cast<value_t>(from));
                        }

                        TEST_CASE_TEMPLATE("rvalue", tuple_p, nkr_FROM_BUILT_IN_TUPLES)
                        {
                            using pure_t = tuple_p::template at_t<nkr::positive::index_c<0>>::head_t;
                            using from_t = tuple_p::template at_t<nkr::positive::index_c<1>>::head_t;
                            using value_t = pure_t::value_t;

                            nkr::cpp::just_volatile_t<from_t> from = nkr::randomness::Value<from_t>();
                            nkr::cpp::just_volatile_t<from_t> backup = from;
                            pure_t pure = nkr::cpp::Move(from);

                            CHECK(pure() == static_cast<value_t>(backup));
                        }
                    }

                    TEST_SUITE("const volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", tuple_p, nkr_FROM_BUILT_IN_TUPLES)
                        {
                            using pure_t = tuple_p::template at_t<nkr::positive::index_c<0>>::head_t;
                            using from_t = tuple_p::template at_t<nkr::positive::index_c<1>>::head_t;
                            using value_t = pure_t::value_t;

                            nkr::cpp::just_const_volatile_t<from_t> from = nkr::randomness::Value<from_t>();
                            pure_t pure = from;

                            CHECK(pure() == static_cast<value_t>(from));
                        }
                    }

                #undef nkr_FROM_BUILT_IN_TUPLES
                }

                TEST_SUITE("user-defined")
                {
                    TEST_SUITE("non-qualified")
                    {
                        TEST_CASE_TEMPLATE("value", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;

                            nkr::cpp::just_non_qualified_t<from_user_defined_t> from = nkr::randomness::Value<from_user_defined_t::value_t>();
                            pure_p pure = from_user_defined_t(from);

                            CHECK(pure() == static_cast<value_t>(from));
                        }

                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;

                            nkr::cpp::just_non_qualified_t<from_user_defined_t> from = nkr::randomness::Value<from_user_defined_t::value_t>();
                            pure_p pure = from;

                            CHECK(pure() == static_cast<value_t>(from));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;

                            nkr::cpp::just_non_qualified_t<from_user_defined_t> from = nkr::randomness::Value<from_user_defined_t::value_t>();
                            nkr::cpp::just_non_qualified_t<from_user_defined_t> backup = from;
                            pure_p pure = nkr::cpp::Move(from);

                            CHECK(pure() == static_cast<value_t>(backup));
                        }
                    }

                    TEST_SUITE("const")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;

                            nkr::cpp::just_const_t<from_user_defined_t> from = nkr::randomness::Value<from_user_defined_t::value_t>();
                            pure_p pure = from;

                            CHECK(pure() == static_cast<value_t>(from));
                        }
                    }

                    TEST_SUITE("volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;

                            nkr::cpp::just_volatile_t<from_user_defined_t> from = nkr::randomness::Value<from_user_defined_t::value_t>();
                            pure_p pure = from;

                            CHECK(pure() == static_cast<value_t>(from));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;

                            nkr::cpp::just_volatile_t<from_user_defined_t> from = nkr::randomness::Value<from_user_defined_t::value_t>();
                            nkr::cpp::just_volatile_t<from_user_defined_t> backup = from;
                            pure_p pure = nkr::cpp::Move(from);

                            CHECK(pure() == static_cast<value_t>(backup));
                        }
                    }

                    TEST_SUITE("const volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;

                            nkr::cpp::just_const_volatile_t<from_user_defined_t> from = nkr::randomness::Value<from_user_defined_t::value_t>();
                            pure_p pure = from;

                            CHECK(pure() == static_cast<value_t>(from));
                        }
                    }
                }
            }

            TEST_SUITE("copy_ctor()"
                       * doctest::description("should copy other without changing it"))
            {
                TEST_CASE_TEMPLATE("non-qualified", pure_p, nkr_ANY)
                {
                    nkr::cpp::just_non_qualified_t<pure_p> other = nkr::randomness::Value<pure_p>();
                    pure_p pure = other;

                    CHECK((pure == other));
                }

                TEST_CASE_TEMPLATE("const", pure_p, nkr_ANY)
                {
                    nkr::cpp::just_const_t<pure_p> other = nkr::randomness::Value<pure_p>();
                    pure_p pure = other;

                    CHECK((pure == other));
                }

                TEST_CASE_TEMPLATE("volatile", pure_p, nkr_ANY)
                {
                    nkr::cpp::just_volatile_t<pure_p> other = nkr::randomness::Value<pure_p>();
                    pure_p pure = other;

                    CHECK((pure == other));
                }

                TEST_CASE_TEMPLATE("const volatile", pure_p, nkr_ANY)
                {
                    nkr::cpp::just_const_volatile_t<pure_p> other = nkr::randomness::Value<pure_p>();
                    pure_p pure = other;

                    CHECK((pure == other));
                }
            }

            TEST_SUITE("move_ctor()"
                       * doctest::description("should move other and set its value to false in debug mode, else leave it alone"))
            {
                TEST_CASE_TEMPLATE("non-qualified", pure_p, nkr_ANY)
                {
                    nkr::cpp::just_non_qualified_t<pure_p> other = nkr::randomness::Value<pure_p>();
                    nkr::cpp::just_non_qualified_t<pure_p> backup = other;
                    pure_p pure = nkr::cpp::Move(other);

                    CHECK((pure == backup));
                #if defined(nkr_IS_DEBUG)
                    CHECK((other == false));
                #else
                    CHECK((other == backup));
                #endif
                }

                TEST_CASE_TEMPLATE("volatile", pure_p, nkr_ANY)
                {
                    nkr::cpp::just_volatile_t<pure_p> other = nkr::randomness::Value<pure_p>();
                    nkr::cpp::just_volatile_t<pure_p> backup = other;
                    pure_p pure = nkr::cpp::Move(other);

                    CHECK((pure == backup));
                #if defined(nkr_IS_DEBUG)
                    CHECK((other == false));
                #else
                    CHECK((other == backup));
                #endif
                }
            }

            TEST_SUITE("copy_assigner()"
                       * doctest::description("should always copy the given lvalue without changing it"))
            {
                TEST_SUITE("self")
                {
                    TEST_CASE_TEMPLATE("non-qualified", pure_p, nkr_ANY_NON_CONST)
                    {
                        nkr::cpp::just_non_qualified_t<pure_p> other = nkr::randomness::Value<pure_p>();
                        pure_p pure;
                        pure = other;

                        CHECK((pure == other));
                    }

                    TEST_CASE_TEMPLATE("const", pure_p, nkr_ANY_NON_CONST)
                    {
                        nkr::cpp::just_const_t<pure_p> other = nkr::randomness::Value<pure_p>();
                        pure_p pure;
                        pure = other;

                        CHECK((pure == other));
                    }

                    TEST_CASE_TEMPLATE("volatile", pure_p, nkr_ANY_NON_CONST)
                    {
                        nkr::cpp::just_volatile_t<pure_p> other = nkr::randomness::Value<pure_p>();
                        pure_p pure;
                        pure = other;

                        CHECK((pure == other));
                    }

                    TEST_CASE_TEMPLATE("const volatile", pure_p, nkr_ANY_NON_CONST)
                    {
                        nkr::cpp::just_const_volatile_t<pure_p> other = nkr::randomness::Value<pure_p>();
                        pure_p pure;
                        pure = other;

                        CHECK((pure == other));
                    }
                }

                TEST_SUITE("from")
                {
                    TEST_SUITE("built-in")
                    {
                    #define nkr_FROM_BUILT_IN_TUPLES                                                                        \
                        nkr::tuple::types_t<nkr::boolean::pure_t, nkr::boolean::cpp_t>,                                     \
                        nkr::tuple::types_t<volatile nkr::boolean::pure_t, nkr::boolean::cpp_t>,                            \
                                                                                                                            \
                        nkr::tuple::types_t<nkr::boolean::pure_t, nkr::positive::integer_t>,                                \
                        nkr::tuple::types_t<volatile nkr::boolean::pure_t, nkr::positive::integer_t>,                       \
                                                                                                                            \
                        nkr::tuple::types_t<nkr::boolean::pure_t, nkr::negatable::integer_t>,                               \
                        nkr::tuple::types_t<volatile nkr::boolean::pure_t, nkr::negatable::integer_t>,                      \
                                                                                                                            \
                        nkr::tuple::types_t<nkr::boolean::pure_t, nkr::negatable::real_t>,                                  \
                        nkr::tuple::types_t<volatile nkr::boolean::pure_t, nkr::negatable::real_t>,                         \
                                                                                                                            \
                        nkr::tuple::types_t<nkr::boolean::pure_t, nkr::pointer::cpp_t<nkr::positive::integer_t>>,           \
                        nkr::tuple::types_t<volatile nkr::boolean::pure_t, nkr::pointer::cpp_t<nkr::positive::integer_t>>   \

                        TEST_CASE_TEMPLATE("non-qualified", tuple_p, nkr_FROM_BUILT_IN_TUPLES)
                        {
                            using pure_t = tuple_p::template at_t<nkr::positive::index_c<0>>::head_t;
                            using from_t = tuple_p::template at_t<nkr::positive::index_c<1>>::head_t;

                            nkr::cpp::just_non_qualified_t<from_t> from = nkr::randomness::Value<from_t>();
                            pure_t pure;
                            pure = from;

                            CHECK((pure == from));
                        }

                        TEST_CASE_TEMPLATE("const", tuple_p, nkr_FROM_BUILT_IN_TUPLES)
                        {
                            using pure_t = tuple_p::template at_t<nkr::positive::index_c<0>>::head_t;
                            using from_t = tuple_p::template at_t<nkr::positive::index_c<1>>::head_t;

                            nkr::cpp::just_const_t<from_t> from = nkr::randomness::Value<from_t>();
                            pure_t pure;
                            pure = from;

                            CHECK((pure == from));
                        }

                        TEST_CASE_TEMPLATE("volatile", tuple_p, nkr_FROM_BUILT_IN_TUPLES)
                        {
                            using pure_t = tuple_p::template at_t<nkr::positive::index_c<0>>::head_t;
                            using from_t = tuple_p::template at_t<nkr::positive::index_c<1>>::head_t;

                            nkr::cpp::just_volatile_t<from_t> from = nkr::randomness::Value<from_t>();
                            pure_t pure;
                            pure = from;

                            CHECK((pure == from));
                        }

                        TEST_CASE_TEMPLATE("const volatile", tuple_p, nkr_FROM_BUILT_IN_TUPLES)
                        {
                            using pure_t = tuple_p::template at_t<nkr::positive::index_c<0>>::head_t;
                            using from_t = tuple_p::template at_t<nkr::positive::index_c<1>>::head_t;

                            nkr::cpp::just_const_volatile_t<from_t> from = nkr::randomness::Value<from_t>();
                            pure_t pure;
                            pure = from;

                            CHECK((pure == from));
                        }

                    #undef nkr_FROM_BUILT_IN_TUPLES
                    }

                    TEST_SUITE("user-defined")
                    {
                        TEST_CASE_TEMPLATE("non-qualified", pure_p, nkr_ANY_NON_CONST)
                        {
                            nkr::cpp::just_non_qualified_t<from_user_defined_t> from = nkr::randomness::Value<from_user_defined_t::value_t>();
                            pure_p pure;
                            pure = from;

                            CHECK((pure == from));
                        }

                        TEST_CASE_TEMPLATE("const", pure_p, nkr_ANY_NON_CONST)
                        {
                            nkr::cpp::just_const_t<from_user_defined_t> from = nkr::randomness::Value<from_user_defined_t::value_t>();
                            pure_p pure;
                            pure = from;

                            CHECK((pure == from));
                        }

                        TEST_CASE_TEMPLATE("volatile", pure_p, nkr_ANY_NON_CONST)
                        {
                            nkr::cpp::just_volatile_t<from_user_defined_t> from = nkr::randomness::Value<from_user_defined_t::value_t>();
                            pure_p pure;
                            pure = from;

                            CHECK((pure == from));
                        }

                        TEST_CASE_TEMPLATE("const volatile", pure_p, nkr_ANY_NON_CONST)
                        {
                            nkr::cpp::just_const_volatile_t<from_user_defined_t> from = nkr::randomness::Value<from_user_defined_t::value_t>();
                            pure_p pure;
                            pure = from;

                            CHECK((pure == from));
                        }
                    }
                }
            }

            TEST_SUITE("move_assigner()")
            {
                TEST_SUITE("self"
                           * doctest::description("should move 'other' and set it's value to false in debug mode, else leave it alone"))
                {
                    TEST_SUITE("non-qualified")
                    {
                        TEST_CASE_TEMPLATE("value", pure_p, nkr_ANY_NON_CONST)
                        {
                            nkr::cpp::just_non_qualified_t<pure_p> other = nkr::randomness::Value<pure_p>();
                            pure_p pure;
                            pure = nkr::cpp::just_non_qualified_t<pure_p>(other);

                            CHECK((pure == other));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY_NON_CONST)
                        {
                            nkr::cpp::just_non_qualified_t<pure_p> other = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<pure_p> backup = other;
                            pure_p pure;
                            pure = nkr::cpp::Move(other);

                            CHECK((pure == backup));
                        #if defined(nkr_IS_DEBUG)
                            CHECK((other == false));
                        #else
                            CHECK((other == backup));
                        #endif
                        }
                    }

                    TEST_SUITE("volatile")
                    {
                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY_NON_CONST)
                        {
                            nkr::cpp::just_volatile_t<pure_p> other = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<pure_p> backup = other;
                            pure_p pure;
                            pure = nkr::cpp::Move(other);

                            CHECK((pure == backup));
                        #if defined(nkr_IS_DEBUG)
                            CHECK((other == false));
                        #else
                            CHECK((other == backup));
                        #endif
                        }
                    }
                }

                TEST_SUITE("from"
                           * doctest::description("should move 'from' but always leave its state alone"))
                {
                    TEST_SUITE("built-in")
                    {
                    #define nkr_FROM_BUILT_IN_TUPLES                                                                        \
                        nkr::tuple::types_t<nkr::boolean::pure_t, nkr::boolean::cpp_t>,                                     \
                        nkr::tuple::types_t<volatile nkr::boolean::pure_t, nkr::boolean::cpp_t>,                            \
                                                                                                                            \
                        nkr::tuple::types_t<nkr::boolean::pure_t, nkr::positive::integer_t>,                                \
                        nkr::tuple::types_t<volatile nkr::boolean::pure_t, nkr::positive::integer_t>,                       \
                                                                                                                            \
                        nkr::tuple::types_t<nkr::boolean::pure_t, nkr::negatable::integer_t>,                               \
                        nkr::tuple::types_t<volatile nkr::boolean::pure_t, nkr::negatable::integer_t>,                      \
                                                                                                                            \
                        nkr::tuple::types_t<nkr::boolean::pure_t, nkr::negatable::real_t>,                                  \
                        nkr::tuple::types_t<volatile nkr::boolean::pure_t, nkr::negatable::real_t>,                         \
                                                                                                                            \
                        nkr::tuple::types_t<nkr::boolean::pure_t, nkr::pointer::cpp_t<nkr::positive::integer_t>>,           \
                        nkr::tuple::types_t<volatile nkr::boolean::pure_t, nkr::pointer::cpp_t<nkr::positive::integer_t>>   \

                        TEST_SUITE("non-qualified")
                        {
                            TEST_CASE_TEMPLATE("value", tuple_p, nkr_FROM_BUILT_IN_TUPLES)
                            {
                                using pure_t = tuple_p::template at_t<nkr::positive::index_c<0>>::head_t;
                                using from_t = tuple_p::template at_t<nkr::positive::index_c<1>>::head_t;

                                nkr::cpp::just_non_qualified_t<from_t> from = nkr::randomness::Value<from_t>();
                                pure_t pure;
                                pure = nkr::cpp::just_non_qualified_t<from_t>(from);

                                CHECK((pure == from));
                            }

                            TEST_CASE_TEMPLATE("rvalue", tuple_p, nkr_FROM_BUILT_IN_TUPLES)
                            {
                                using pure_t = tuple_p::template at_t<nkr::positive::index_c<0>>::head_t;
                                using from_t = tuple_p::template at_t<nkr::positive::index_c<1>>::head_t;

                                nkr::cpp::just_non_qualified_t<from_t> from = nkr::randomness::Value<from_t>();
                                pure_t pure;
                                pure = nkr::cpp::Move(from);

                                CHECK((pure == from));
                            }
                        }

                        TEST_SUITE("volatile")
                        {
                            TEST_CASE_TEMPLATE("rvalue", tuple_p, nkr_FROM_BUILT_IN_TUPLES)
                            {
                                using pure_t = tuple_p::template at_t<nkr::positive::index_c<0>>::head_t;
                                using from_t = tuple_p::template at_t<nkr::positive::index_c<1>>::head_t;

                                nkr::cpp::just_volatile_t<from_t> from = nkr::randomness::Value<from_t>();
                                pure_t pure;
                                pure = nkr::cpp::Move(from);

                                CHECK((pure == from));
                            }
                        }

                    #undef nkr_FROM_BUILT_IN_TUPLES
                    }

                    TEST_SUITE("user-defined")
                    {
                        TEST_SUITE("non-qualified")
                        {
                            TEST_CASE_TEMPLATE("value", pure_p, nkr_ANY_NON_CONST)
                            {
                                nkr::cpp::just_non_qualified_t<from_user_defined_t> from = nkr::randomness::Value<from_user_defined_t::value_t>();
                                pure_p pure;
                                pure = nkr::cpp::just_non_qualified_t<from_user_defined_t>(from);

                                CHECK((pure == from));
                            }

                            TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY_NON_CONST)
                            {
                                nkr::cpp::just_non_qualified_t<from_user_defined_t> from = nkr::randomness::Value<from_user_defined_t::value_t>();
                                pure_p pure;
                                pure = nkr::cpp::Move(from);

                                CHECK((pure == from));
                            }
                        }

                        TEST_SUITE("volatile")
                        {
                            TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY_NON_CONST)
                            {
                                nkr::cpp::just_volatile_t<from_user_defined_t> from = nkr::randomness::Value<from_user_defined_t::value_t>();
                                pure_p pure;
                                pure = nkr::cpp::Move(from);

                                CHECK((pure == from));
                            }
                        }
                    }
                }
            }

        #if defined(nkr_IS_DEBUG)
            TEST_SUITE("dtor()")
            {
                TEST_CASE_TEMPLATE("should set its value to false", pure_p, nkr_ANY)
                {
                    pure_p pure = true;
                    pure.~pure_p();

                    CHECK(pure() == false);
                }
            }
        #endif
        }

        TEST_SUITE("casts")
        {
            TEST_SUITE("value_t()")
            {
                TEST_CASE_TEMPLATE("should explicitly cast to value_t", pure_p, nkr_ANY)
                {
                    using value_t = pure_p::value_t;

                    value_t value = nkr::randomness::Value<value_t>();
                    pure_p pure = value;

                    CHECK(static_cast<value_t>(pure) == value);
                }

                TEST_SUITE("should implicitly allow for logical operators")
                {
                    TEST_CASE_TEMPLATE("when false", pure_p, nkr_ANY)
                    {
                        pure_p pure = false;

                        CHECK_FALSE(pure);
                        CHECK_TRUE(!pure);
                        CHECK_FALSE(!!pure);
                        CHECK_FALSE(pure || pure);
                        CHECK_FALSE(pure && pure);
                        CHECK_FALSE((pure ? true : false));
                    }

                    TEST_CASE_TEMPLATE("when true", pure_p, nkr_ANY)
                    {
                        pure_p pure = true;

                        CHECK_TRUE(pure);
                        CHECK_FALSE(!pure);
                        CHECK_TRUE(!!pure);
                        CHECK_TRUE(pure || pure);
                        CHECK_TRUE(pure && pure);
                        CHECK_TRUE((pure ? true : false));
                    }
                }
            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("operator ()()")
            {
                TEST_CASE_TEMPLATE("should return its value", pure_p, nkr_ANY)
                {
                    using value_t = pure_p::value_t;

                    value_t value = nkr::randomness::Value<value_t>();
                    pure_p pure = value;

                    CHECK(pure() == value);
                }
            }
        }

        TEST_SUITE("global operators")
        {
            TEST_SUITE("operator ==(), operator !=()")
            {
                TEST_SUITE("self")
                {
                    TEST_SUITE("non-qualified")
                    {
                        TEST_CASE_TEMPLATE("value", pure_p, nkr_ANY)
                        {
                            pure_p pure = nkr::randomness::Value<pure_p>();

                            CHECK_TRUE((pure == nkr::cpp::just_non_qualified_t<pure_p>(pure)));
                            CHECK_TRUE((nkr::cpp::just_non_qualified_t<pure_p>(pure) == pure));

                            CHECK_FALSE((pure != nkr::cpp::just_non_qualified_t<pure_p>(pure)));
                            CHECK_FALSE((nkr::cpp::just_non_qualified_t<pure_p>(pure) != pure));
                        }

                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<pure_p> other = pure;

                            CHECK_TRUE((pure == other));
                            CHECK_TRUE((other == pure));

                            CHECK_FALSE((pure != other));
                            CHECK_FALSE((other != pure));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<pure_p> other = pure;

                            CHECK_TRUE((pure == nkr::cpp::Move(other)));
                            CHECK_TRUE((nkr::cpp::Move(other) == pure));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_TRUE((nkr::cpp::Move(pure) == nkr::cpp::Move(other)));
                            }

                            CHECK_FALSE((pure != nkr::cpp::Move(other)));
                            CHECK_FALSE((nkr::cpp::Move(other) != pure));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_FALSE((nkr::cpp::Move(pure) != nkr::cpp::Move(other)));
                            }
                        }
                    }

                    TEST_SUITE("const")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_const_t<pure_p> other = pure;

                            CHECK_TRUE((pure == other));
                            CHECK_TRUE((other == pure));

                            CHECK_FALSE((pure != other));
                            CHECK_FALSE((other != pure));
                        }
                    }

                    TEST_SUITE("volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<pure_p> other = pure;

                            CHECK_TRUE((pure == other));
                            CHECK_TRUE((other == pure));

                            CHECK_FALSE((pure != other));
                            CHECK_FALSE((other != pure));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<pure_p> other = pure;

                            CHECK_TRUE((pure == nkr::cpp::Move(other)));
                            CHECK_TRUE((nkr::cpp::Move(other) == pure));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_TRUE((nkr::cpp::Move(pure) == nkr::cpp::Move(other)));
                            }

                            CHECK_FALSE((pure != nkr::cpp::Move(other)));
                            CHECK_FALSE((nkr::cpp::Move(other) != pure));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_FALSE((nkr::cpp::Move(pure) != nkr::cpp::Move(other)));
                            }
                        }
                    }

                    TEST_SUITE("const volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_const_volatile_t<pure_p> other = pure;

                            CHECK_TRUE((pure == other));
                            CHECK_TRUE((other == pure));

                            CHECK_FALSE((pure != other));
                            CHECK_FALSE((other != pure));
                        }
                    }
                }

                TEST_SUITE("user-defined implicitly convertible to non-qualified value_t")
                {
                    template <typename value_p, typename cast_p>
                    class from_user_defined_t
                    {
                    public:
                        using value_t   = value_p;
                        using cast_t    = cast_p;

                    protected:
                        value_t value;

                    public:
                        constexpr from_user_defined_t(value_t value) noexcept :
                            value(value)
                        {
                        }

                    public:
                        constexpr operator from_user_defined_t::cast_t()
                            const volatile noexcept
                        {
                            return static_cast<cast_t>(value);
                        }
                    };

                    TEST_SUITE("non-qualified")
                    {
                        TEST_CASE_TEMPLATE("value", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_user_defined_t<value_t, value_t>;

                            pure_p pure = nkr::randomness::Value<pure_p>();

                            CHECK_TRUE((pure == nkr::cpp::just_non_qualified_t<other_t>(pure())));

                            CHECK_FALSE((pure != nkr::cpp::just_non_qualified_t<other_t>(pure())));
                        }

                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_user_defined_t<value_t, value_t>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<other_t> other = pure();

                            CHECK_TRUE((pure == other));

                            CHECK_FALSE((pure != other));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_user_defined_t<value_t, value_t>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<other_t> other = pure();

                            CHECK_TRUE((pure == nkr::cpp::Move(other)));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_TRUE((nkr::cpp::Move(pure) == nkr::cpp::Move(other)));
                            }

                            CHECK_FALSE((pure != nkr::cpp::Move(other)));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_FALSE((nkr::cpp::Move(pure) != nkr::cpp::Move(other)));
                            }
                        }
                    }

                    TEST_SUITE("const")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_user_defined_t<value_t, value_t>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_const_t<other_t> other = pure();

                            CHECK_TRUE((pure == other));

                            CHECK_FALSE((pure != other));
                        }
                    }

                    TEST_SUITE("volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_user_defined_t<value_t, value_t>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<other_t> other = pure();

                            CHECK_TRUE((pure == other));

                            CHECK_FALSE((pure != other));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_user_defined_t<value_t, value_t>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<other_t> other = pure();

                            CHECK_TRUE((pure == nkr::cpp::Move(other)));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_TRUE((nkr::cpp::Move(pure) == nkr::cpp::Move(other)));
                            }

                            CHECK_FALSE((pure != nkr::cpp::Move(other)));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_FALSE((nkr::cpp::Move(pure) != nkr::cpp::Move(other)));
                            }
                        }
                    }

                    TEST_SUITE("const volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_user_defined_t<value_t, value_t>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_const_volatile_t<other_t> other = pure();

                            CHECK_TRUE((pure == other));

                            CHECK_FALSE((pure != other));
                        }
                    }
                }

                TEST_SUITE("user-defined implicitly convertible to non-qualified self")
                {
                    template <typename value_p, typename cast_p>
                    class from_user_defined_t
                    {
                    public:
                        using value_t   = value_p;
                        using cast_t    = cast_p;

                    protected:
                        value_t value;

                    public:
                        constexpr from_user_defined_t(value_t value) noexcept :
                            value(value)
                        {
                        }

                    public:
                        constexpr operator from_user_defined_t::cast_t()
                            const volatile noexcept
                        {
                            return static_cast<cast_t>(value);
                        }
                    };

                    TEST_SUITE("non-qualified")
                    {
                        TEST_CASE_TEMPLATE("value", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_user_defined_t<value_t, nkr::cpp::just_non_qualified_t<pure_p>>;

                            pure_p pure = nkr::randomness::Value<pure_p>();

                            CHECK_TRUE((pure == nkr::cpp::just_non_qualified_t<other_t>(pure())));

                            CHECK_FALSE((pure != nkr::cpp::just_non_qualified_t<other_t>(pure())));
                        }

                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_user_defined_t<value_t, nkr::cpp::just_non_qualified_t<pure_p>>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<other_t> other = pure();

                            CHECK_TRUE((pure == other));

                            CHECK_FALSE((pure != other));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_user_defined_t<value_t, nkr::cpp::just_non_qualified_t<pure_p>>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<other_t> other = pure();

                            CHECK_TRUE((pure == nkr::cpp::Move(other)));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_TRUE((nkr::cpp::Move(pure) == nkr::cpp::Move(other)));
                            }

                            CHECK_FALSE((pure != nkr::cpp::Move(other)));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_FALSE((nkr::cpp::Move(pure) != nkr::cpp::Move(other)));
                            }
                        }
                    }

                    TEST_SUITE("const")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_user_defined_t<value_t, nkr::cpp::just_non_qualified_t<pure_p>>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_const_t<other_t> other = pure();

                            CHECK_TRUE((pure == other));

                            CHECK_FALSE((pure != other));
                        }
                    }

                    TEST_SUITE("volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_user_defined_t<value_t, nkr::cpp::just_non_qualified_t<pure_p>>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<other_t> other = pure();

                            CHECK_TRUE((pure == other));

                            CHECK_FALSE((pure != other));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_user_defined_t<value_t, nkr::cpp::just_non_qualified_t<pure_p>>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<other_t> other = pure();

                            CHECK_TRUE((pure == nkr::cpp::Move(other)));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_TRUE((nkr::cpp::Move(pure) == nkr::cpp::Move(other)));
                            }

                            CHECK_FALSE((pure != nkr::cpp::Move(other)));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_FALSE((nkr::cpp::Move(pure) != nkr::cpp::Move(other)));
                            }
                        }
                    }

                    TEST_SUITE("const volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_user_defined_t<value_t, nkr::cpp::just_non_qualified_t<pure_p>>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_const_volatile_t<other_t> other = pure();

                            CHECK_TRUE((pure == other));

                            CHECK_FALSE((pure != other));
                        }
                    }
                }

                TEST_SUITE("self implicitly convertible to non-qualified user-defined")
                {
                    template <typename value_p>
                    class to_user_defined_t
                    {
                    public:
                        using value_t   = value_p;

                    protected:
                        value_t value;

                    public:
                        constexpr to_user_defined_t(value_t value) noexcept :
                            value(value)
                        {
                        }

                    public:
                        constexpr nkr::boolean::cpp_t
                            operator ==(to_user_defined_t other)
                            const volatile noexcept
                        {
                            return this->value == other.value;
                        }
                    };

                    TEST_SUITE("non-qualified")
                    {
                        TEST_CASE_TEMPLATE("value", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = to_user_defined_t<pure_p>;

                            pure_p pure = nkr::randomness::Value<pure_p>();

                            CHECK_TRUE((pure == nkr::cpp::just_non_qualified_t<other_t>(pure)));

                            CHECK_FALSE((pure != nkr::cpp::just_non_qualified_t<other_t>(pure)));
                        }

                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = to_user_defined_t<pure_p>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<other_t> other = pure;

                            CHECK_TRUE((pure == other));

                            CHECK_FALSE((pure != other));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = to_user_defined_t<pure_p>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<other_t> other = pure;

                            CHECK_TRUE((pure == nkr::cpp::Move(other)));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_TRUE((nkr::cpp::Move(pure) == nkr::cpp::Move(other)));
                            }

                            CHECK_FALSE((pure != nkr::cpp::Move(other)));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_FALSE((nkr::cpp::Move(pure) != nkr::cpp::Move(other)));
                            }
                        }
                    }

                    TEST_SUITE("const")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = to_user_defined_t<pure_p>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_const_t<other_t> other = pure;

                            CHECK_TRUE((pure == other));

                            CHECK_FALSE((pure != other));
                        }
                    }

                    TEST_SUITE("volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = to_user_defined_t<pure_p>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<other_t> other = pure;

                            CHECK_TRUE((pure == other));

                            CHECK_FALSE((pure != other));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = to_user_defined_t<pure_p>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<other_t> other = pure;

                            CHECK_TRUE((pure == nkr::cpp::Move(other)));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_TRUE((nkr::cpp::Move(pure) == nkr::cpp::Move(other)));
                            }

                            CHECK_FALSE((pure != nkr::cpp::Move(other)));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_FALSE((nkr::cpp::Move(pure) != nkr::cpp::Move(other)));
                            }
                        }
                    }

                    TEST_SUITE("const volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = to_user_defined_t<pure_p>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_const_volatile_t<other_t> other = pure;

                            CHECK_TRUE((pure == other));

                            CHECK_FALSE((pure != other));
                        }
                    }
                }
            }
        }
    }

}
