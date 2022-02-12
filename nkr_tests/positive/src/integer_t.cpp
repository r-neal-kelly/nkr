/*
    Copyright 2021 r-neal-kelly
*/

#include <unordered_set> // until we finish our own

#include "nkr/cpp.h"
#include "nkr/generic/built_in/boolean_tr.h"
#include "nkr/generic/built_in/number/integer_tr.h"
#include "nkr/generic/non_type_tr.h"
#include "nkr/generic/positive/integer_tr.h"
#include "nkr/interface/enumeration/types_i.h"
#include "nkr/interface/none/value_i.h"
#include "nkr/interface/randomness/distributor/uniform_i.h"
#include "nkr/interface/randomness/value_i.h"
#include "nkr/positive/byte_t.h"
#include "nkr/positive/count_t.h"
#include "nkr/positive/index_t.h"
#include "nkr/positive/integer_t.h"
#include "nkr/positive/integer_8_t.h"
#include "nkr/positive/integer_16_t.h"
#include "nkr/positive/integer_32_t.h"
#include "nkr/positive/integer_64_t.h"
#include "nkr/positive/integer_max_t.h"
#include "nkr/positive/integer_min_t.h"
#include "nkr/positive/size_t.h"
#include "nkr/positive/word_t.h"
#include "nkr/randomness/generator/software/default_t.h"
#include "nkr/randomness/value.h"
#include "nkr/tr.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::positive::integer_8_t, nkr::positive::integer_16_t, nkr::positive::integer_32_t, nkr::positive::integer_64_t")
    {
        template <typename type_p>
        concept is_the_same_as_a_tested_subject_tr =
            nkr::cpp::is_any_tr<type_p, nkr::positive::integer_8_t> ||
            nkr::cpp::is_any_tr<type_p, nkr::positive::integer_16_t> ||
            nkr::cpp::is_any_tr<type_p, nkr::positive::integer_32_t> ||
            nkr::cpp::is_any_tr<type_p, nkr::positive::integer_64_t>;

        static_assert(is_the_same_as_a_tested_subject_tr<nkr::positive::byte_t>);
        static_assert(is_the_same_as_a_tested_subject_tr<nkr::positive::count_t>);
        static_assert(is_the_same_as_a_tested_subject_tr<nkr::positive::index_t>);
        static_assert(is_the_same_as_a_tested_subject_tr<nkr::positive::integer_t>);
        static_assert(is_the_same_as_a_tested_subject_tr<nkr::positive::integer_8_t>);
        static_assert(is_the_same_as_a_tested_subject_tr<nkr::positive::integer_16_t>);
        static_assert(is_the_same_as_a_tested_subject_tr<nkr::positive::integer_32_t>);
        static_assert(is_the_same_as_a_tested_subject_tr<nkr::positive::integer_64_t>);
        static_assert(is_the_same_as_a_tested_subject_tr<nkr::positive::integer_max_t>);
        static_assert(is_the_same_as_a_tested_subject_tr<nkr::positive::integer_min_t>);
        static_assert(is_the_same_as_a_tested_subject_tr<nkr::positive::size_t>);
        static_assert(is_the_same_as_a_tested_subject_tr<nkr::positive::word_t>);

    #define nkr_TYPES(TYPE_QUALIFIER_p)                 \
        TYPE_QUALIFIER_p nkr::positive::integer_8_t,    \
        TYPE_QUALIFIER_p nkr::positive::integer_16_t,   \
        TYPE_QUALIFIER_p nkr::positive::integer_32_t,   \
        TYPE_QUALIFIER_p nkr::positive::integer_64_t    \

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

        TEST_CASE("tr")
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
                nkr::generic::built_in::number::integer_tg,
                nkr::generic::positive::integer_tg
            >;

            using non_target_ts = ts<AND_tg,
                nkr::generic::built_in::boolean_tg,
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

        TEST_SUITE("interfaces")
        {
            TEST_SUITE("nkr::interface::enumeration::types_i")
            {
                TEST_SUITE("aliases")
                {
                    TEST_SUITE("type_t")
                    {
                        TEST_CASE_TEMPLATE("should equate to the type used to instantiate the interface", integer_p, nkr_ANY)
                        {
                            using interface_t = nkr::interface::enumeration::types_i<integer_p>;

                            static_assert(nkr::cpp::is_tr<typename interface_t::type_t, integer_p>);
                        }
                    }

                    TEST_SUITE("value_t")
                    {
                        TEST_CASE_TEMPLATE("should equate to non-qualified type_t", integer_p, nkr_ANY)
                        {
                            using interface_t = nkr::interface::enumeration::types_i<integer_p>;

                            static_assert(nkr::cpp::is_tr<typename interface_t::value_t, nkr::cpp::just_non_qualified_t<integer_p>>);
                        }
                    }

                    TEST_SUITE("integer_t")
                    {
                        TEST_CASE_TEMPLATE("should equate to value_t", integer_p, nkr_ANY)
                        {
                            using interface_t = nkr::interface::enumeration::types_i<integer_p>;

                            static_assert(nkr::cpp::is_tr<typename interface_t::integer_t, typename interface_t::value_t>);
                        }
                    }
                }

                TEST_SUITE("static functions")
                {
                    TEST_SUITE("Default_Integer()")
                    {
                        TEST_CASE_TEMPLATE("should always return integer_t(~0)", integer_p, nkr_ANY)
                        {
                            using interface_t = nkr::interface::enumeration::types_i<integer_p>;

                            static_assert(interface_t::Default_Integer() == typename interface_t::integer_t(~0));
                        }
                    }

                    TEST_SUITE("Integer()")
                    {
                        TEST_SUITE("parameters: (const value_t&)")
                        {
                            TEST_CASE_TEMPLATE("should convert the value to an integer", integer_p, nkr_ANY)
                            {
                                using interface_t = nkr::interface::enumeration::types_i<integer_p>;

                                for (nkr::positive::index_t idx = 0, end = Interface_Iteration_Count(); idx < end; idx += 1) {
                                    const auto value = nkr::randomness::Value<typename interface_t::value_t>();

                                    CHECK(interface_t::Integer(value) == typename interface_t::integer_t(value));
                                }
                            }
                        }

                        TEST_SUITE("parameters: (value_t&, integer_t)")
                        {
                            TEST_CASE_TEMPLATE("should convert the integer to a value and set it", integer_p, nkr_ANY)
                            {
                                using interface_t = nkr::interface::enumeration::types_i<integer_p>;

                                for (nkr::positive::index_t idx = 0, end = Interface_Iteration_Count(); idx < end; idx += 1) {
                                    auto value = nkr::randomness::Value<typename interface_t::value_t>();
                                    const auto integer = nkr::randomness::Value<typename interface_t::integer_t>();

                                    interface_t::Integer(value, integer);

                                    CHECK(interface_t::Integer(value) == integer);
                                }
                            }
                        }
                    }
                }
            }

            TEST_SUITE("nkr::interface::none::value_i")
            {
                TEST_SUITE("aliases")
                {
                    TEST_SUITE("type_t")
                    {
                        TEST_CASE_TEMPLATE("should equate to the type used to instantiate the interface", integer_p, nkr_ANY)
                        {
                            using interface_t = nkr::interface::none::value_i<integer_p>;

                            static_assert(nkr::cpp::is_tr<typename interface_t::type_t, integer_p>);
                        }
                    }

                    TEST_SUITE("value_t")
                    {
                        TEST_CASE_TEMPLATE("should equate to non-qualified type_t", integer_p, nkr_ANY)
                        {
                            using interface_t = nkr::interface::none::value_i<integer_p>;

                            static_assert(nkr::cpp::is_tr<typename interface_t::value_t, nkr::cpp::just_non_qualified_t<integer_p>>);
                        }
                    }
                }

                TEST_SUITE("static functions")
                {
                    TEST_SUITE("Value()")
                    {
                        TEST_CASE_TEMPLATE("should always return 0, the manual default value", integer_p, nkr_ANY)
                        {
                            using interface_t = nkr::interface::none::value_i<integer_p>;

                            static_assert(interface_t::Value() == 0);
                            static_assert(interface_t::Value() == nkr::cpp::just_non_qualified_t<integer_p>());
                        }
                    }
                }
            }

            TEST_SUITE("nkr::interface::randomness::distributor::uniform_i")
            {
                TEST_SUITE("aliases")
                {
                    TEST_SUITE("type_t")
                    {
                        TEST_CASE_TEMPLATE("should equate to the type used to instantiate the interface", integer_p, nkr_ANY)
                        {
                            using interface_t = nkr::interface::randomness::distributor::uniform_i<integer_p>;

                            static_assert(nkr::cpp::is_tr<typename interface_t::type_t, integer_p>);
                        }
                    }

                    TEST_SUITE("value_t")
                    {
                        TEST_CASE_TEMPLATE("should equate to non-qualified type_t", integer_p, nkr_ANY)
                        {
                            using interface_t = nkr::interface::randomness::distributor::uniform_i<integer_p>;

                            static_assert(nkr::cpp::is_tr<typename interface_t::value_t, nkr::cpp::just_non_qualified_t<integer_p>>);
                        }
                    }

                    TEST_SUITE("number_t")
                    {
                        TEST_CASE_TEMPLATE("should equate to value_t", integer_p, nkr_ANY)
                        {
                            using interface_t = nkr::interface::randomness::distributor::uniform_i<integer_p>;

                            static_assert(nkr::cpp::is_tr<typename interface_t::number_t, typename interface_t::value_t>);
                        }
                    }
                }

                TEST_SUITE("static functions")
                {
                    TEST_SUITE("Default_Min()")
                    {
                        TEST_CASE_TEMPLATE("should always return value_t(0)", integer_p, nkr_ANY)
                        {
                            using interface_t = nkr::interface::randomness::distributor::uniform_i<integer_p>;

                            static_assert(interface_t::Default_Min() == typename interface_t::value_t(0));
                        }
                    }

                    TEST_SUITE("Default_Max()")
                    {
                        TEST_CASE_TEMPLATE("should always return value_t(~0)", integer_p, nkr_ANY)
                        {
                            using interface_t = nkr::interface::randomness::distributor::uniform_i<integer_p>;

                            static_assert(interface_t::Default_Max() == typename interface_t::value_t(~0));
                        }
                    }

                    TEST_SUITE("To_Number()")
                    {
                        TEST_CASE_TEMPLATE("should always return the given value", integer_p, nkr_ANY)
                        {
                            using interface_t = nkr::interface::randomness::distributor::uniform_i<integer_p>;

                            for (nkr::positive::index_t idx = 0, end = Interface_Iteration_Count(); idx < end; idx += 1) {
                                const auto value = nkr::randomness::Value<typename interface_t::value_t>();

                                CHECK(interface_t::To_Number(value) == value);
                            }
                        }
                    }

                    TEST_SUITE("From_Number()")
                    {
                        TEST_CASE_TEMPLATE("should always return the given number", integer_p, nkr_ANY)
                        {
                            using interface_t = nkr::interface::randomness::distributor::uniform_i<integer_p>;
                            using number_t = interface_t::number_t;

                            for (nkr::positive::index_t idx = 0, end = Interface_Iteration_Count(); idx < end; idx += 1) {
                                const auto number = nkr::randomness::Value<typename interface_t::number_t>();

                                CHECK(interface_t::From_Number(number) == number);
                            }
                        }
                    }
                }
            }

            TEST_SUITE("nkr::interface::randomness::value_i")
            {
                TEST_SUITE("aliases")
                {
                    TEST_SUITE("type_t")
                    {
                        TEST_CASE_TEMPLATE("should equate to the type used to instantiate the interface", integer_p, nkr_ANY)
                        {
                            using interface_t = nkr::interface::randomness::value_i<integer_p>;

                            static_assert(nkr::cpp::is_tr<typename interface_t::type_t, integer_p>);
                        }
                    }

                    TEST_SUITE("value_t")
                    {
                        TEST_CASE_TEMPLATE("should equate to non-qualified type_t", integer_p, nkr_ANY)
                        {
                            using interface_t = nkr::interface::randomness::value_i<integer_p>;

                            static_assert(nkr::cpp::is_tr<typename interface_t::value_t, nkr::cpp::just_non_qualified_t<integer_p>>);
                        }
                    }
                }

                TEST_SUITE("static functions")
                {
                    TEST_SUITE("Value()")
                    {
                        TEST_SUITE("parameters: ()")
                        {
                            TEST_CASE_TEMPLATE("should return a value between default min and default max", integer_p, nkr_ANY)
                            {
                                using interface_t = nkr::interface::randomness::value_i<integer_p>;

                                for (nkr::positive::index_t idx = 0, end = Interface_Iteration_Count(); idx < end; idx += 1) {
                                    const auto integer = interface_t::template Value<>();

                                    CHECK(integer >= typename interface_t::value_t(0));
                                    CHECK(integer <= typename interface_t::value_t(~0));
                                }
                            }

                            TEST_CASE_TEMPLATE("should return values uniformly", integer_p, nkr_ANY)
                            {
                                using interface_t = nkr::interface::randomness::value_i<integer_p>;

                                constexpr auto difference_threshold = Interface_Iteration_Count() / 3;
                                std::unordered_set<typename interface_t::value_t> integers(Interface_Iteration_Count());

                                for (nkr::positive::index_t idx = 0, end = Interface_Iteration_Count(); idx < end; idx += 1) {
                                    integers.insert(interface_t::template Value<>());
                                }

                                CAPTURE(Interface_Iteration_Count());
                                CAPTURE(integers.size());
                                CAPTURE(difference_threshold);
                                WARN(Interface_Iteration_Count() - integers.size() <= difference_threshold);
                            }
                        }

                        TEST_SUITE("parameters: (generator)")
                        {
                            TEST_CASE_TEMPLATE("should return a value between default min and default max", integer_p, nkr_ANY)
                            {
                                using interface_t = nkr::interface::randomness::value_i<integer_p>;

                                auto generator_lockee = nkr::randomness::generator::software::Default();
                                for (nkr::positive::index_t idx = 0, end = Interface_Iteration_Count(); idx < end; idx += 1) {
                                    const auto integer = interface_t::template Value<>(generator_lockee.Value());

                                    CHECK(integer >= typename interface_t::value_t(0));
                                    CHECK(integer <= typename interface_t::value_t(~0));
                                }
                            }

                            TEST_CASE_TEMPLATE("should return values uniformly", integer_p, nkr_ANY)
                            {
                                using interface_t = nkr::interface::randomness::value_i<integer_p>;

                                constexpr auto difference_threshold = Interface_Iteration_Count() / 3;
                                std::unordered_set<typename interface_t::value_t> integers(Interface_Iteration_Count());

                                auto generator_lockee = nkr::randomness::generator::software::Default();
                                for (nkr::positive::index_t idx = 0, end = Interface_Iteration_Count(); idx < end; idx += 1) {
                                    integers.insert(interface_t::template Value<>(generator_lockee.Value()));
                                }

                                CAPTURE(Interface_Iteration_Count());
                                CAPTURE(integers.size());
                                CAPTURE(difference_threshold);
                                WARN(Interface_Iteration_Count() - integers.size() <= difference_threshold);
                            }
                        }

                        TEST_SUITE("parameters: (min, max)")
                        {
                            TEST_CASE_TEMPLATE("should return a value between min and max", integer_p, nkr_ANY)
                            {
                                using interface_t = nkr::interface::randomness::value_i<integer_p>;

                                for (nkr::positive::index_t idx = 0, end = Interface_Iteration_Count(); idx < end; idx += 1) {
                                    const auto constraint_a = interface_t::template Value<>();
                                    const auto constraint_b = interface_t::template Value<>();

                                    if (constraint_a < constraint_b) {
                                        const auto integer = interface_t::template Value<>(constraint_a, constraint_b);

                                        CHECK(integer >= constraint_a);
                                        CHECK(integer <= constraint_b);
                                    } else {
                                        const auto integer = interface_t::template Value<>(constraint_b, constraint_a);

                                        CHECK(integer >= constraint_b);
                                        CHECK(integer <= constraint_a);
                                    }
                                }
                            }
                        }

                        TEST_SUITE("parameters: (generator, min, max)")
                        {
                            TEST_CASE_TEMPLATE("should return a value between min and max", integer_p, nkr_ANY)
                            {
                                using interface_t = nkr::interface::randomness::value_i<integer_p>;

                                auto generator_lockee = nkr::randomness::generator::software::Default();
                                for (nkr::positive::index_t idx = 0, end = Interface_Iteration_Count(); idx < end; idx += 1) {
                                    const auto constraint_a = interface_t::template Value<>();
                                    const auto constraint_b = interface_t::template Value<>();

                                    if (constraint_a < constraint_b) {
                                        const auto integer = interface_t::template Value<>(generator_lockee.Value(), constraint_a, constraint_b);

                                        CHECK(integer >= constraint_a);
                                        CHECK(integer <= constraint_b);
                                    } else {
                                        const auto integer = interface_t::template Value<>(generator_lockee.Value(), constraint_b, constraint_a);

                                        CHECK(integer >= constraint_b);
                                        CHECK(integer <= constraint_a);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

}
