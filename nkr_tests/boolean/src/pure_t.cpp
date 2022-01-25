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

                using target_ts = nkr::tuple::types_t<
                    nkr::boolean::pure_t,
                    nkr::boolean::pure_tg,

                    nkr::generic::boolean_tg,
                    nkr::generic::boolean::any_tg,
                    nkr::generic::boolean::pure_tg,
                    nkr::generic::implementing::interface::none::value_tg,
                    nkr::generic::implementing::interface::randomness::value_tg,
                    nkr::generic::implementing::interface::type_tg,
                    nkr::generic::type_tg
                >;

                using non_target_ts = nkr::tuple::types_t<
                    nkr::generic::number::integer_tg
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
            TEST_CASE("should satisfy nkr::interface::none::value_i")
            {
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
                            auto generator = nkr::randomness::generator::software::Default();
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::interface::randomness::value_i<pure_p>::template Value<>(generator.Value()) ?
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
                            auto generator = nkr::randomness::generator::software::Default();
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::interface::randomness::value_i<pure_p>::template Value<>(generator.Value(), nkr::negatable::real_t(0.5)) ?
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
                            auto generator = nkr::randomness::generator::software::Default();
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::interface::randomness::value_i<pure_p>::template Value<>(generator.Value(), false, true) ?
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
                            auto generator = nkr::randomness::generator::software::Default();
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::randomness::Value<pure_p>(generator.Value()) ?
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
                            auto generator = nkr::randomness::generator::software::Default();
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::randomness::Value<pure_p>(generator.Value(), nkr::negatable::real_t(0.5)) ?
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
                            auto generator = nkr::randomness::generator::software::Default();
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::randomness::Value<pure_p>(generator.Value(), false, true) ?
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

        TEST_SUITE("operators")
        {
        }
    }

}
