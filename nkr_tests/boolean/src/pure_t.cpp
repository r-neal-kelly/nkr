/*
    Copyright 2021 r-neal-kelly
*/

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
#include "nkr/none/value_t.h"
#include "nkr/randomness/value.h"

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

        using just_non_qualified_ts             = nkr::tuple::types_t<nkr_JUST_NON_QUALIFIED>;
        using just_const_ts                     = nkr::tuple::types_t<nkr_JUST_CONST>;
        using just_volatile_ts                  = nkr::tuple::types_t<nkr_JUST_VOLATILE>;
        using just_const_volatile_ts            = nkr::tuple::types_t<nkr_JUST_CONST_VOLATILE>;

        using any_ts                            = nkr::tuple::types_t<nkr_ANY>;
        using any_qualified_ts                  = nkr::tuple::types_t<nkr_ANY_QUALIFIED>;
        using any_non_qualified_ts              = nkr::tuple::types_t<nkr_ANY_NON_QUALIFIED>;
        using any_const_ts                      = nkr::tuple::types_t<nkr_ANY_CONST>;
        using any_non_const_ts                  = nkr::tuple::types_t<nkr_ANY_NON_CONST>;
        using any_volatile_ts                   = nkr::tuple::types_t<nkr_ANY_VOLATILE>;
        using any_non_volatile_ts               = nkr::tuple::types_t<nkr_ANY_NON_VOLATILE>;

        using any_not_just_non_qualified_ts     = nkr::tuple::types_t<nkr_ANY_NOT_JUST_NON_QUALIFIED>;
        using any_not_just_const_ts             = nkr::tuple::types_t<nkr_ANY_NOT_JUST_CONST>;
        using any_not_just_volatile_ts          = nkr::tuple::types_t<nkr_ANY_NOT_JUST_VOLATILE>;
        using any_not_just_const_volatile_ts    = nkr::tuple::types_t<nkr_ANY_NOT_JUST_CONST_VOLATILE>;

        inline constexpr nkr::positive::count_t
            Default_Iteration_Count()
            noexcept
        {
            return 128;
        }

        TEST_SUITE("tr")
        {
            TEST_CASE("should satisfy all of the following tr1 expressions")
            {
                using target_ts = nkr::tuple::types_t<
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

                using non_target_ts = nkr::tuple::types_t<
                    nkr::generic::number::integer_tg
                >;

                class other_t
                {
                public:
                };

                using other_ts = nkr::tuple::types_t<
                    other_t,
                    const other_t,
                    volatile other_t,
                    const volatile other_t
                >;

                using other_target_ts = nkr::tuple::types_t<
                    nkr::boolean::pure_t,
                    nkr::boolean::pure_tg,

                    nkr::generic::boolean_tg,
                    nkr::generic::boolean::any_tg,
                    nkr::generic::boolean::pure_tg
                >;

                static_assert(tr1s_t<any_tg, target_ts>::Every<any_ts>());
                static_assert(tr1s_t<any_tg, non_target_ts>::None<any_ts>());
                static_assert(tr1s_t<any_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1s_t<any_qualified_tg, target_ts>::Every<any_qualified_ts>());
                static_assert(tr1s_t<any_qualified_tg, target_ts>::None<any_non_qualified_ts>());
                static_assert(tr1s_t<any_qualified_tg, non_target_ts>::None<any_ts>());
                static_assert(tr1s_t<any_qualified_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1s_t<any_non_qualified_tg, target_ts>::Every<any_non_qualified_ts>());
                static_assert(tr1s_t<any_non_qualified_tg, target_ts>::None<any_qualified_ts>());
                static_assert(tr1s_t<any_non_qualified_tg, non_target_ts>::None<any_ts>());
                static_assert(tr1s_t<any_non_qualified_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1s_t<any_const_tg, target_ts>::Every<any_const_ts>());
                static_assert(tr1s_t<any_const_tg, target_ts>::None<any_non_const_ts>());
                static_assert(tr1s_t<any_const_tg, non_target_ts>::None<any_ts>());
                static_assert(tr1s_t<any_const_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1s_t<any_non_const_tg, target_ts>::Every<any_non_const_ts>());
                static_assert(tr1s_t<any_non_const_tg, target_ts>::None<any_const_ts>());
                static_assert(tr1s_t<any_non_const_tg, non_target_ts>::None<any_ts>());
                static_assert(tr1s_t<any_non_const_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1s_t<any_volatile_tg, target_ts>::Every<any_volatile_ts>());
                static_assert(tr1s_t<any_volatile_tg, target_ts>::None<any_non_volatile_ts>());
                static_assert(tr1s_t<any_volatile_tg, non_target_ts>::None<any_ts>());
                static_assert(tr1s_t<any_volatile_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1s_t<any_non_volatile_tg, target_ts>::Every<any_non_volatile_ts>());
                static_assert(tr1s_t<any_non_volatile_tg, target_ts>::None<any_volatile_ts>());
                static_assert(tr1s_t<any_non_volatile_tg, non_target_ts>::None<any_ts>());
                static_assert(tr1s_t<any_non_volatile_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1s_t<just_tg, target_ts>::Every<just_non_qualified_ts>());
                static_assert(tr1s_t<just_tg, const target_ts>::Every<just_const_ts>());
                static_assert(tr1s_t<just_tg, volatile target_ts>::Every<just_volatile_ts>());
                static_assert(tr1s_t<just_tg, const volatile target_ts>::Every<just_const_volatile_ts>());
                static_assert(tr1s_t<just_tg, target_ts>::None<any_not_just_non_qualified_ts>());
                static_assert(tr1s_t<just_tg, const target_ts>::None<any_not_just_const_ts>());
                static_assert(tr1s_t<just_tg, volatile target_ts>::None<any_not_just_volatile_ts>());
                static_assert(tr1s_t<just_tg, const volatile target_ts>::None<any_not_just_const_volatile_ts>());
                static_assert(tr1s_t<just_tg, non_target_ts>::None<any_ts>());
                static_assert(tr1s_t<just_tg, const non_target_ts>::None<any_ts>());
                static_assert(tr1s_t<just_tg, volatile non_target_ts>::None<any_ts>());
                static_assert(tr1s_t<just_tg, const volatile non_target_ts>::None<any_ts>());
                static_assert(tr1s_t<just_tg, other_target_ts>::None<other_ts>());
                static_assert(tr1s_t<just_tg, const other_target_ts>::None<other_ts>());
                static_assert(tr1s_t<just_tg, volatile other_target_ts>::None<other_ts>());
                static_assert(tr1s_t<just_tg, const volatile other_target_ts>::None<other_ts>());

                static_assert(tr1s_t<just_non_qualified_tg, target_ts>::Every<just_non_qualified_ts>());
                static_assert(tr1s_t<just_non_qualified_tg, target_ts>::None<any_not_just_non_qualified_ts>());
                static_assert(tr1s_t<just_non_qualified_tg, non_target_ts>::None<any_ts>());
                static_assert(tr1s_t<just_non_qualified_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1s_t<just_const_tg, target_ts>::Every<just_const_ts>());
                static_assert(tr1s_t<just_const_tg, target_ts>::None<any_not_just_const_ts>());
                static_assert(tr1s_t<just_const_tg, non_target_ts>::None<any_ts>());
                static_assert(tr1s_t<just_const_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1s_t<just_volatile_tg, target_ts>::Every<just_volatile_ts>());
                static_assert(tr1s_t<just_volatile_tg, target_ts>::None<any_not_just_volatile_ts>());
                static_assert(tr1s_t<just_volatile_tg, non_target_ts>::None<any_ts>());
                static_assert(tr1s_t<just_volatile_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1s_t<just_const_volatile_tg, target_ts>::Every<just_const_volatile_ts>());
                static_assert(tr1s_t<just_const_volatile_tg, target_ts>::None<any_not_just_const_volatile_ts>());
                static_assert(tr1s_t<just_const_volatile_tg, non_target_ts>::None<any_ts>());
                static_assert(tr1s_t<just_const_volatile_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1s_t<not_any_tg, target_ts>::None<any_ts>());
                static_assert(tr1s_t<not_any_tg, non_target_ts>::Every<any_ts>());
                static_assert(tr1s_t<not_any_tg, other_target_ts>::Every<other_ts>());

                static_assert(tr1s_t<not_any_qualified_tg, target_ts>::None<any_qualified_ts>());
                static_assert(tr1s_t<not_any_qualified_tg, target_ts>::Every<any_non_qualified_ts>());
                static_assert(tr1s_t<not_any_qualified_tg, non_target_ts>::Every<any_ts>());
                static_assert(tr1s_t<not_any_qualified_tg, other_target_ts>::Every<other_ts>());

                static_assert(tr1s_t<not_any_non_qualified_tg, target_ts>::None<any_non_qualified_ts>());
                static_assert(tr1s_t<not_any_non_qualified_tg, target_ts>::Every<any_qualified_ts>());
                static_assert(tr1s_t<not_any_non_qualified_tg, non_target_ts>::Every<any_ts>());
                static_assert(tr1s_t<not_any_non_qualified_tg, other_target_ts>::Every<other_ts>());

                static_assert(tr1s_t<not_any_const_tg, target_ts>::None<any_const_ts>());
                static_assert(tr1s_t<not_any_const_tg, target_ts>::Every<any_non_const_ts>());
                static_assert(tr1s_t<not_any_const_tg, non_target_ts>::Every<any_ts>());
                static_assert(tr1s_t<not_any_const_tg, other_target_ts>::Every<other_ts>());

                static_assert(tr1s_t<not_any_non_const_tg, target_ts>::None<any_non_const_ts>());
                static_assert(tr1s_t<not_any_non_const_tg, target_ts>::Every<any_const_ts>());
                static_assert(tr1s_t<not_any_non_const_tg, non_target_ts>::Every<any_ts>());
                static_assert(tr1s_t<not_any_non_const_tg, other_target_ts>::Every<other_ts>());

                static_assert(tr1s_t<not_any_volatile_tg, target_ts>::None<any_volatile_ts>());
                static_assert(tr1s_t<not_any_volatile_tg, target_ts>::Every<any_non_volatile_ts>());
                static_assert(tr1s_t<not_any_volatile_tg, non_target_ts>::Every<any_ts>());
                static_assert(tr1s_t<not_any_volatile_tg, other_target_ts>::Every<other_ts>());

                static_assert(tr1s_t<not_any_non_volatile_tg, target_ts>::None<any_non_volatile_ts>());
                static_assert(tr1s_t<not_any_non_volatile_tg, target_ts>::Every<any_volatile_ts>());
                static_assert(tr1s_t<not_any_non_volatile_tg, non_target_ts>::Every<any_ts>());
                static_assert(tr1s_t<not_any_non_volatile_tg, other_target_ts>::Every<other_ts>());

                static_assert(tr1s_t<just_not_tg, target_ts>::None<just_non_qualified_ts>());
                static_assert(tr1s_t<just_not_tg, const target_ts>::None<just_const_ts>());
                static_assert(tr1s_t<just_not_tg, volatile target_ts>::None<just_volatile_ts>());
                static_assert(tr1s_t<just_not_tg, const volatile target_ts>::None<just_const_volatile_ts>());
                static_assert(tr1s_t<just_not_tg, target_ts>::Every<any_not_just_non_qualified_ts>());
                static_assert(tr1s_t<just_not_tg, const target_ts>::Every<any_not_just_const_ts>());
                static_assert(tr1s_t<just_not_tg, volatile target_ts>::Every<any_not_just_volatile_ts>());
                static_assert(tr1s_t<just_not_tg, const volatile target_ts>::Every<any_not_just_const_volatile_ts>());
                static_assert(tr1s_t<just_not_tg, non_target_ts>::Every<any_ts>());
                static_assert(tr1s_t<just_not_tg, const non_target_ts>::Every<any_ts>());
                static_assert(tr1s_t<just_not_tg, volatile non_target_ts>::Every<any_ts>());
                static_assert(tr1s_t<just_not_tg, const volatile non_target_ts>::Every<any_ts>());
                static_assert(tr1s_t<just_not_tg, other_target_ts>::Every<other_ts>());
                static_assert(tr1s_t<just_not_tg, const other_target_ts>::Every<other_ts>());
                static_assert(tr1s_t<just_not_tg, volatile other_target_ts>::Every<other_ts>());
                static_assert(tr1s_t<just_not_tg, const volatile other_target_ts>::Every<other_ts>());

                static_assert(tr1s_t<just_not_non_qualified_tg, target_ts>::None<just_non_qualified_ts>());
                static_assert(tr1s_t<just_not_non_qualified_tg, target_ts>::Every<any_not_just_non_qualified_ts>());
                static_assert(tr1s_t<just_not_non_qualified_tg, non_target_ts>::Every<any_ts>());
                static_assert(tr1s_t<just_not_non_qualified_tg, other_target_ts>::Every<other_ts>());

                static_assert(tr1s_t<just_not_const_tg, target_ts>::None<just_const_ts>());
                static_assert(tr1s_t<just_not_const_tg, target_ts>::Every<any_not_just_const_ts>());
                static_assert(tr1s_t<just_not_const_tg, non_target_ts>::Every<any_ts>());
                static_assert(tr1s_t<just_not_const_tg, other_target_ts>::Every<other_ts>());

                static_assert(tr1s_t<just_not_volatile_tg, target_ts>::None<just_volatile_ts>());
                static_assert(tr1s_t<just_not_volatile_tg, target_ts>::Every<any_not_just_volatile_ts>());
                static_assert(tr1s_t<just_not_volatile_tg, non_target_ts>::Every<any_ts>());
                static_assert(tr1s_t<just_not_volatile_tg, other_target_ts>::Every<other_ts>());

                static_assert(tr1s_t<just_not_const_volatile_tg, target_ts>::None<just_const_volatile_ts>());
                static_assert(tr1s_t<just_not_const_volatile_tg, target_ts>::Every<any_not_just_const_volatile_ts>());
                static_assert(tr1s_t<just_not_const_volatile_tg, non_target_ts>::Every<any_ts>());
                static_assert(tr1s_t<just_not_const_volatile_tg, other_target_ts>::Every<other_ts>());
            }
        }

        TEST_SUITE("interface")
        {
            TEST_SUITE("should satisfy nkr::interface::none::value_i")
            {
                TEST_SUITE("directly")
                {

                }

                TEST_SUITE("through nkr::none::value_t")
                {

                }

                static_assert(nkr::interface::none::value_i<nkr::boolean::pure_t>::Value() == false);

                static_assert(nkr::none::value_t<nkr::boolean::pure_t>() == false);
                static_assert(nkr::none::value_t<nkr::boolean::pure_t>() == nkr::boolean::pure_t(false));
                static_assert(nkr::none::value_t<nkr::boolean::pure_t>() == nkr::none::value_t<nkr::boolean::pure_t>());

                static_assert(false == nkr::none::value_t<nkr::boolean::pure_t>());
                static_assert(nkr::boolean::pure_t(false) == nkr::none::value_t<nkr::boolean::pure_t>());
                static_assert(nkr::none::value_t<nkr::boolean::pure_t>() == nkr::none::value_t<nkr::boolean::pure_t>());
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
            TEST_SUITE("default_ctor()")
            {
                TEST_CASE_TEMPLATE("should set its value to false", pure_p, nkr_ANY)
                {
                    pure_p pure;

                    CHECK((pure == false));
                }
            }

            TEST_SUITE("to_value_ctor()")
            {
                class user_defined_t
                {
                public:
                    using value_t   = nkr::boolean::pure_t::value_t;

                protected:
                    value_t value;

                public:
                    constexpr user_defined_t(value_t value) noexcept :
                        value(value)
                    {
                    }

                public:
                    constexpr operator user_defined_t::value_t()
                        const volatile noexcept
                    {
                        return this->value;
                    }
                };

            #define nkr_TUPLES                                                                                              \
                nkr::tuple::types_t<nkr::boolean::pure_t, nkr::boolean::cpp_t>,                                             \
                nkr::tuple::types_t<const nkr::boolean::pure_t, nkr::boolean::cpp_t>,                                       \
                nkr::tuple::types_t<volatile nkr::boolean::pure_t, nkr::boolean::cpp_t>,                                    \
                nkr::tuple::types_t<const volatile nkr::boolean::pure_t, nkr::boolean::cpp_t>,                              \
                nkr::tuple::types_t<nkr::boolean::pure_t, nkr::positive::integer_t>,                                        \
                nkr::tuple::types_t<const nkr::boolean::pure_t, nkr::positive::integer_t>,                                  \
                nkr::tuple::types_t<volatile nkr::boolean::pure_t, nkr::positive::integer_t>,                               \
                nkr::tuple::types_t<const volatile nkr::boolean::pure_t, nkr::positive::integer_t>,                         \
                nkr::tuple::types_t<nkr::boolean::pure_t, nkr::negatable::integer_t>,                                       \
                nkr::tuple::types_t<const nkr::boolean::pure_t, nkr::negatable::integer_t>,                                 \
                nkr::tuple::types_t<volatile nkr::boolean::pure_t, nkr::negatable::integer_t>,                              \
                nkr::tuple::types_t<const volatile nkr::boolean::pure_t, nkr::negatable::integer_t>,                        \
                nkr::tuple::types_t<nkr::boolean::pure_t, nkr::negatable::real_t>,                                          \
                nkr::tuple::types_t<const nkr::boolean::pure_t, nkr::negatable::real_t>,                                    \
                nkr::tuple::types_t<volatile nkr::boolean::pure_t, nkr::negatable::real_t>,                                 \
                nkr::tuple::types_t<const volatile nkr::boolean::pure_t, nkr::negatable::real_t>,                           \
                nkr::tuple::types_t<nkr::boolean::pure_t, nkr::pointer::cpp_t<nkr::positive::integer_t>>,                   \
                nkr::tuple::types_t<const nkr::boolean::pure_t, nkr::pointer::cpp_t<nkr::positive::integer_t>>,             \
                nkr::tuple::types_t<volatile nkr::boolean::pure_t, nkr::pointer::cpp_t<nkr::positive::integer_t>>,          \
                nkr::tuple::types_t<const volatile nkr::boolean::pure_t, nkr::pointer::cpp_t<nkr::positive::integer_t>>,    \
                nkr::tuple::types_t<nkr::boolean::pure_t, user_defined_t>,                                                  \
                nkr::tuple::types_t<const nkr::boolean::pure_t, user_defined_t>,                                            \
                nkr::tuple::types_t<volatile nkr::boolean::pure_t, user_defined_t>,                                         \
                nkr::tuple::types_t<const volatile nkr::boolean::pure_t, user_defined_t>                                    \

                template <typename type_p>
                inline auto
                    Randomness_Value()
                    noexcept
                {
                    if constexpr (nkr::cpp::is_any_tr<type_p, user_defined_t>) {
                        return user_defined_t(nkr::randomness::Value<user_defined_t::value_t>());
                    } else {
                        return nkr::randomness::Value<type_p>();
                    }
                }

                TEST_SUITE("non-qualified from")
                {
                    TEST_CASE_TEMPLATE("lvalue", tuple_p, nkr_TUPLES)
                    {
                        using pure_t = tuple_p::template at_t<nkr::positive::index_c<0>>;
                        using from_t = tuple_p::template at_t<nkr::positive::index_c<1>>;
                        using value_t = pure_t::value_t;

                        nkr::cpp::just_non_qualified_t<from_t> from = Randomness_Value<from_t>();
                        pure_t pure = from;

                        CHECK(pure() == static_cast<value_t>(from));
                    }

                    TEST_CASE_TEMPLATE("rvalue", tuple_p, nkr_TUPLES)
                    {
                        using pure_t = tuple_p::template at_t<nkr::positive::index_c<0>>;
                        using from_t = tuple_p::template at_t<nkr::positive::index_c<1>>;
                        using value_t = pure_t::value_t;

                        nkr::cpp::just_non_qualified_t<from_t> from = Randomness_Value<from_t>();
                        nkr::cpp::just_non_qualified_t<from_t> backup = from;
                        pure_t pure = nkr::cpp::Move(from);

                        CHECK(pure() == static_cast<value_t>(backup));
                    }
                }

                TEST_SUITE("const from")
                {
                    TEST_CASE_TEMPLATE("lvalue", tuple_p, nkr_TUPLES)
                    {
                        using pure_t = tuple_p::template at_t<nkr::positive::index_c<0>>;
                        using from_t = tuple_p::template at_t<nkr::positive::index_c<1>>;
                        using value_t = pure_t::value_t;

                        nkr::cpp::just_const_t<from_t> from = Randomness_Value<from_t>();
                        pure_t pure = from;

                        CHECK(pure() == static_cast<value_t>(from));
                    }
                }

                TEST_SUITE("volatile from")
                {
                    TEST_CASE_TEMPLATE("lvalue", tuple_p, nkr_TUPLES)
                    {
                        using pure_t = tuple_p::template at_t<nkr::positive::index_c<0>>;
                        using from_t = tuple_p::template at_t<nkr::positive::index_c<1>>;
                        using value_t = pure_t::value_t;

                        nkr::cpp::just_volatile_t<from_t> from = Randomness_Value<from_t>();
                        pure_t pure = from;

                        CHECK(pure() == static_cast<value_t>(from));
                    }

                    TEST_CASE_TEMPLATE("rvalue", tuple_p, nkr_TUPLES)
                    {
                        using pure_t = tuple_p::template at_t<nkr::positive::index_c<0>>;
                        using from_t = tuple_p::template at_t<nkr::positive::index_c<1>>;
                        using value_t = pure_t::value_t;

                        nkr::cpp::just_volatile_t<from_t> from = Randomness_Value<from_t>();
                        nkr::cpp::just_volatile_t<from_t> backup = from;
                        pure_t pure = nkr::cpp::Move(from);

                        CHECK(pure() == static_cast<value_t>(backup));
                    }
                }

                TEST_SUITE("const volatile from")
                {
                    TEST_CASE_TEMPLATE("lvalue", tuple_p, nkr_TUPLES)
                    {
                        using pure_t = tuple_p::template at_t<nkr::positive::index_c<0>>;
                        using from_t = tuple_p::template at_t<nkr::positive::index_c<1>>;
                        using value_t = pure_t::value_t;

                        nkr::cpp::just_const_volatile_t<from_t> from = Randomness_Value<from_t>();
                        pure_t pure = from;

                        CHECK(pure() == static_cast<value_t>(from));
                    }
                }

            #undef nkr_TUPLES
            }

            TEST_SUITE("copy_ctor()")
            {

            }

            TEST_SUITE("copy_volatile_ctor()")
            {

            }

            TEST_SUITE("move_ctor()")
            {

            }

            TEST_SUITE("move_volatile_ctor()")
            {

            }

            TEST_SUITE("copy_assigner()")
            {
                // make sure to test to_values
            }

            TEST_SUITE("copy_volatile_assigner()")
            {
                // make sure to test to_values
            }

            TEST_SUITE("move_assigner()")
            {
                // make sure to test to_values
            }

            TEST_SUITE("move_volatile_assigner()")
            {
                // make sure to test to_values
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
            template <typename value_p, typename cast_p>
            class from_t
            {
            public:
                using value_t   = value_p;
                using cast_t    = cast_p;

            protected:
                value_t value;

            public:
                constexpr from_t(value_t value) noexcept :
                    value(value)
                {
                }

            public:
                constexpr operator from_t::cast_t()
                    const volatile noexcept
                {
                    return static_cast<cast_t>(value);
                }
            };

            template <typename value_p>
            class to_t
            {
            public:
                using value_t   = value_p;

            protected:
                value_t value;

            public:
                constexpr to_t(value_t value) noexcept :
                    value(value)
                {
                }

            public:
                constexpr nkr::boolean::cpp_t
                    operator ==(to_t other)
                    const volatile noexcept
                {
                    return this->value == other.value;
                }
            };

            TEST_SUITE("operator ==()")
            {
                TEST_SUITE("with its own type")
                {
                    TEST_SUITE("non-qualified")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<pure_p> other = pure;

                            CHECK_TRUE((pure == other));
                            CHECK_TRUE((other == pure));
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
                        }
                    }
                }

                TEST_SUITE("with a type that converts to its value_t")
                {
                    TEST_SUITE("non-qualified")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_t<value_t, value_t>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<other_t> other = pure();

                            CHECK_TRUE((pure == other));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_t<value_t, value_t>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<other_t> other = pure();

                            CHECK_TRUE((pure == nkr::cpp::Move(other)));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_TRUE((nkr::cpp::Move(pure) == nkr::cpp::Move(other)));
                            }
                        }
                    }

                    TEST_SUITE("const")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_t<value_t, value_t>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_const_t<other_t> other = pure();

                            CHECK_TRUE((pure == other));
                        }
                    }

                    TEST_SUITE("volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_t<value_t, value_t>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<other_t> other = pure();

                            CHECK_TRUE((pure == other));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_t<value_t, value_t>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<other_t> other = pure();

                            CHECK_TRUE((pure == nkr::cpp::Move(other)));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_TRUE((nkr::cpp::Move(pure) == nkr::cpp::Move(other)));
                            }
                        }
                    }

                    TEST_SUITE("const volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_t<value_t, value_t>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_const_volatile_t<other_t> other = pure();

                            CHECK_TRUE((pure == other));
                        }
                    }
                }

                TEST_SUITE("with a type that converts to its non-qualified type")
                {
                    TEST_SUITE("non-qualified")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_t<value_t, nkr::cpp::just_non_qualified_t<pure_p>>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<other_t> other = pure();

                            CHECK_TRUE((pure == other));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_t<value_t, nkr::cpp::just_non_qualified_t<pure_p>>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<other_t> other = pure();

                            CHECK_TRUE((pure == nkr::cpp::Move(other)));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_TRUE((nkr::cpp::Move(pure) == nkr::cpp::Move(other)));
                            }
                        }
                    }

                    TEST_SUITE("const")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_t<value_t, nkr::cpp::just_non_qualified_t<pure_p>>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_const_t<other_t> other = pure();

                            CHECK_TRUE((pure == other));
                        }
                    }

                    TEST_SUITE("volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_t<value_t, nkr::cpp::just_non_qualified_t<pure_p>>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<other_t> other = pure();

                            CHECK_TRUE((pure == other));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_t<value_t, nkr::cpp::just_non_qualified_t<pure_p>>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<other_t> other = pure();

                            CHECK_TRUE((pure == nkr::cpp::Move(other)));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_TRUE((nkr::cpp::Move(pure) == nkr::cpp::Move(other)));
                            }
                        }
                    }

                    TEST_SUITE("const volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_t<value_t, nkr::cpp::just_non_qualified_t<pure_p>>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_const_volatile_t<other_t> other = pure();

                            CHECK_TRUE((pure == other));
                        }
                    }
                }

                TEST_SUITE("with a type that it can convert to")
                {
                    TEST_SUITE("non-qualified")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = to_t<pure_p>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<other_t> other = pure;

                            CHECK_TRUE((pure == other));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = to_t<pure_p>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<other_t> other = pure;

                            CHECK_TRUE((pure == nkr::cpp::Move(other)));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_TRUE((nkr::cpp::Move(pure) == nkr::cpp::Move(other)));
                            }
                        }
                    }

                    TEST_SUITE("const")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = to_t<pure_p>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_const_t<other_t> other = pure;

                            CHECK_TRUE((pure == other));
                        }
                    }

                    TEST_SUITE("volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = to_t<pure_p>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<other_t> other = pure;

                            CHECK_TRUE((pure == other));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = to_t<pure_p>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<other_t> other = pure;

                            CHECK_TRUE((pure == nkr::cpp::Move(other)));
                            if constexpr (nkr::cpp::any_non_const_tr<pure_p>) {
                                CHECK_TRUE((nkr::cpp::Move(pure) == nkr::cpp::Move(other)));
                            }
                        }
                    }

                    TEST_SUITE("const volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = to_t<pure_p>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_const_volatile_t<other_t> other = pure;

                            CHECK_TRUE((pure == other));
                        }
                    }
                }
            }

            TEST_SUITE("operator !=()")
            {
                TEST_SUITE("with its own type")
                {
                    TEST_SUITE("non-qualified")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<pure_p> other = pure;

                            CHECK_FALSE((pure != other));
                            CHECK_FALSE((other != pure));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<pure_p> other = pure;

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

                            CHECK_FALSE((pure != other));
                            CHECK_FALSE((other != pure));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<pure_p> other = pure;

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

                            CHECK_FALSE((pure != other));
                            CHECK_FALSE((other != pure));
                        }
                    }
                }

                TEST_SUITE("with a type that converts to its value_t")
                {
                    TEST_SUITE("non-qualified")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_t<value_t, value_t>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<other_t> other = pure();

                            CHECK_FALSE((pure != other));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_t<value_t, value_t>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<other_t> other = pure();

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
                            using other_t = from_t<value_t, value_t>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_const_t<other_t> other = pure();

                            CHECK_FALSE((pure != other));
                        }
                    }

                    TEST_SUITE("volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_t<value_t, value_t>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<other_t> other = pure();

                            CHECK_FALSE((pure != other));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_t<value_t, value_t>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<other_t> other = pure();

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
                            using other_t = from_t<value_t, value_t>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_const_volatile_t<other_t> other = pure();

                            CHECK_FALSE((pure != other));
                        }
                    }
                }

                TEST_SUITE("with a type that converts to its non-qualified type")
                {
                    TEST_SUITE("non-qualified")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_t<value_t, nkr::cpp::just_non_qualified_t<pure_p>>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<other_t> other = pure();

                            CHECK_FALSE((pure != other));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_t<value_t, nkr::cpp::just_non_qualified_t<pure_p>>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<other_t> other = pure();

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
                            using other_t = from_t<value_t, nkr::cpp::just_non_qualified_t<pure_p>>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_const_t<other_t> other = pure();

                            CHECK_FALSE((pure != other));
                        }
                    }

                    TEST_SUITE("volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_t<value_t, nkr::cpp::just_non_qualified_t<pure_p>>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<other_t> other = pure();

                            CHECK_FALSE((pure != other));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = from_t<value_t, nkr::cpp::just_non_qualified_t<pure_p>>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<other_t> other = pure();

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
                            using other_t = from_t<value_t, nkr::cpp::just_non_qualified_t<pure_p>>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_const_volatile_t<other_t> other = pure();

                            CHECK_FALSE((pure != other));
                        }
                    }
                }

                TEST_SUITE("with a type that it can convert to")
                {
                    TEST_SUITE("non-qualified")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = to_t<pure_p>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<other_t> other = pure;

                            CHECK_FALSE((pure != other));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = to_t<pure_p>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_non_qualified_t<other_t> other = pure;

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
                            using other_t = to_t<pure_p>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_const_t<other_t> other = pure;

                            CHECK_FALSE((pure != other));
                        }
                    }

                    TEST_SUITE("volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = to_t<pure_p>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<other_t> other = pure;

                            CHECK_FALSE((pure != other));
                        }

                        TEST_CASE_TEMPLATE("rvalue", pure_p, nkr_ANY)
                        {
                            using value_t = pure_p::value_t;
                            using other_t = to_t<pure_p>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_volatile_t<other_t> other = pure;

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
                            using other_t = to_t<pure_p>;

                            pure_p pure = nkr::randomness::Value<pure_p>();
                            nkr::cpp::just_const_volatile_t<other_t> other = pure;

                            CHECK_FALSE((pure != other));
                        }
                    }
                }
            }
        }
    }

}
