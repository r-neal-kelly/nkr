/*
    Copyright 2021 r-neal-kelly
*/

#pragma warning (disable : 4146)
#pragma warning (disable : 26498)

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
#include "nkr/tuple/types_t.h"

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

        template <typename integer_p>
        inline nkr::cpp::just_non_qualified_t<integer_p>
            Random_Shift()
            noexcept
        {
            return nkr::randomness::Value<integer_p>(0, nkr::cpp::just_non_qualified_t<integer_p>(sizeof(integer_p) * nkr::cpp::Byte_Bit_Count() - 1));
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

        TEST_SUITE("objects")
        {
            TEST_SUITE("manual_default_constructor()")
            {
                TEST_CASE_TEMPLATE("should set its value to 0", integer_p, nkr_ANY)
                {
                    integer_p integer = nkr::cpp::just_non_qualified_t<integer_p>();

                    CHECK((integer == 0));
                }
            }

            TEST_SUITE("copy_constructor()"
                       * doctest::description("should copy other without changing it"))
            {
                TEST_CASE_TEMPLATE("non-qualified", integer_p, nkr_ANY)
                {
                    nkr::cpp::just_non_qualified_t<integer_p> other = nkr::randomness::Value<integer_p>();
                    integer_p integer = other;

                    CHECK((integer == other));
                }

                TEST_CASE_TEMPLATE("const", integer_p, nkr_ANY)
                {
                    nkr::cpp::just_const_t<integer_p> other = nkr::randomness::Value<integer_p>();
                    integer_p integer = other;

                    CHECK((integer == other));
                }

                TEST_CASE_TEMPLATE("volatile", integer_p, nkr_ANY)
                {
                    nkr::cpp::just_volatile_t<integer_p> other = nkr::randomness::Value<integer_p>();
                    integer_p integer = other;

                    CHECK((integer == other));
                }

                TEST_CASE_TEMPLATE("const volatile", integer_p, nkr_ANY)
                {
                    nkr::cpp::just_const_volatile_t<integer_p> other = nkr::randomness::Value<integer_p>();
                    integer_p integer = other;

                    CHECK((integer == other));
                }
            }

            TEST_SUITE("move_constructor()"
                       * doctest::description("should move other and leave its value alone"))
            {
                TEST_CASE_TEMPLATE("non-qualified", integer_p, nkr_ANY)
                {
                    nkr::cpp::just_non_qualified_t<integer_p> other = nkr::randomness::Value<integer_p>();
                    nkr::cpp::just_non_qualified_t<integer_p> backup = other;
                    integer_p integer = nkr::cpp::Move(other);

                    CHECK((integer == backup));
                    CHECK((other == backup));
                }

                TEST_CASE_TEMPLATE("volatile", integer_p, nkr_ANY)
                {
                    nkr::cpp::just_volatile_t<integer_p> other = nkr::randomness::Value<integer_p>();
                    nkr::cpp::just_volatile_t<integer_p> backup = other;
                    integer_p integer = nkr::cpp::Move(other);

                    CHECK((integer == backup));
                    CHECK((other == backup));
                }
            }

            TEST_SUITE("copy_assigner()"
                       * doctest::description("should always copy other without changing it"))
            {
                TEST_CASE_TEMPLATE("non-qualified", integer_p, nkr_ANY_NON_CONST)
                {
                    nkr::cpp::just_non_qualified_t<integer_p> other = nkr::randomness::Value<integer_p>();
                    integer_p integer;
                    integer = other;

                    CHECK((integer == other));
                }

                TEST_CASE_TEMPLATE("const", integer_p, nkr_ANY_NON_CONST)
                {
                    nkr::cpp::just_const_t<integer_p> other = nkr::randomness::Value<integer_p>();
                    integer_p integer;
                    integer = other;

                    CHECK((integer == other));
                }

                TEST_CASE_TEMPLATE("volatile", integer_p, nkr_ANY_NON_CONST)
                {
                    nkr::cpp::just_volatile_t<integer_p> other = nkr::randomness::Value<integer_p>();
                    integer_p integer;
                    integer = other;

                    CHECK((integer == other));
                }

                TEST_CASE_TEMPLATE("const volatile", integer_p, nkr_ANY_NON_CONST)
                {
                    nkr::cpp::just_const_volatile_t<integer_p> other = nkr::randomness::Value<integer_p>();
                    integer_p integer;
                    integer = other;

                    CHECK((integer == other));
                }
            }

            TEST_SUITE("move_assigner()"
                       * doctest::description("should move other and leave its value alone"))
            {
                TEST_SUITE("non-qualified")
                {
                    TEST_CASE_TEMPLATE("value", integer_p, nkr_ANY_NON_CONST)
                    {
                        nkr::cpp::just_non_qualified_t<integer_p> other = nkr::randomness::Value<integer_p>();
                        integer_p integer;
                        integer = nkr::cpp::just_non_qualified_t<integer_p>(other);

                        CHECK((integer == other));
                    }

                    TEST_CASE_TEMPLATE("rvalue", integer_p, nkr_ANY_NON_CONST)
                    {
                        nkr::cpp::just_non_qualified_t<integer_p> other = nkr::randomness::Value<integer_p>();
                        nkr::cpp::just_non_qualified_t<integer_p> backup = other;
                        integer_p integer;
                        integer = nkr::cpp::Move(other);

                        CHECK((integer == backup));
                        CHECK((other == backup));
                    }
                }

                TEST_SUITE("volatile")
                {
                    TEST_CASE_TEMPLATE("rvalue", integer_p, nkr_ANY_NON_CONST)
                    {
                        nkr::cpp::just_volatile_t<integer_p> other = nkr::randomness::Value<integer_p>();
                        nkr::cpp::just_volatile_t<integer_p> backup = other;
                        integer_p integer;
                        integer = nkr::cpp::Move(other);

                        CHECK((integer == backup));
                        CHECK((other == backup));
                    }
                }
            }

            TEST_SUITE("dtor()")
            {
                TEST_CASE_TEMPLATE("should leave its value alone", integer_p, nkr_ANY)
                {
                    integer_p integer = nkr::randomness::Value<integer_p>();
                    integer_p backup = integer;
                    integer.~integer_p();

                    CHECK(integer == backup);
                }
            }
        }

        TEST_SUITE("casts")
        {
            TEST_SUITE("nkr::boolean::cpp_t")
            {
                TEST_SUITE("should convert to false if 0")
                {
                    TEST_CASE_TEMPLATE("explicit", integer_p, nkr_ANY)
                    {
                        using value_t = nkr::cpp::just_non_qualified_t<integer_p>;

                        integer_p integer = value_t(0);

                        CHECK(static_cast<nkr::boolean::cpp_t>(integer) == false);
                    }

                    TEST_CASE_TEMPLATE("implicit", integer_p, nkr_ANY)
                    {
                        using value_t = nkr::cpp::just_non_qualified_t<integer_p>;

                        integer_p integer = value_t(0);

                        if (integer) {
                            CHECK(false);
                        } else {
                            CHECK(true);
                        }
                    }
                }

                TEST_SUITE("should convert to true if not 0")
                {
                    TEST_CASE_TEMPLATE("explicit", integer_p, nkr_ANY)
                    {
                        using value_t = nkr::cpp::just_non_qualified_t<integer_p>;

                        integer_p integer = nkr::randomness::Value<integer_p>(value_t(1), value_t(~0));

                        CHECK(static_cast<nkr::boolean::cpp_t>(integer) == true);
                    }

                    TEST_CASE_TEMPLATE("implicit", integer_p, nkr_ANY)
                    {
                        using value_t = nkr::cpp::just_non_qualified_t<integer_p>;

                        integer_p integer = nkr::randomness::Value<integer_p>(value_t(1), value_t(~0));

                        if (integer) {
                            CHECK(true);
                        } else {
                            CHECK(false);
                        }
                    }
                }
            }
        }

        TEST_SUITE("global operators")
        {
        #define nkr_ANY_WITH_VALUE                                                                          \
            nkr::tuple::types_t<nkr::positive::integer_8_t, nkr::positive::integer_8_t>,                    \
            nkr::tuple::types_t<const nkr::positive::integer_8_t, nkr::positive::integer_8_t>,              \
            nkr::tuple::types_t<volatile nkr::positive::integer_8_t, nkr::positive::integer_8_t>,           \
            nkr::tuple::types_t<const volatile nkr::positive::integer_8_t, nkr::positive::integer_8_t>,     \
            nkr::tuple::types_t<nkr::positive::integer_16_t, nkr::positive::integer_16_t>,                  \
            nkr::tuple::types_t<const nkr::positive::integer_16_t, nkr::positive::integer_16_t>,            \
            nkr::tuple::types_t<volatile nkr::positive::integer_16_t, nkr::positive::integer_16_t>,         \
            nkr::tuple::types_t<const volatile nkr::positive::integer_16_t, nkr::positive::integer_16_t>,   \
            nkr::tuple::types_t<nkr::positive::integer_32_t, nkr::positive::integer_32_t>,                  \
            nkr::tuple::types_t<const nkr::positive::integer_32_t, nkr::positive::integer_32_t>,            \
            nkr::tuple::types_t<volatile nkr::positive::integer_32_t, nkr::positive::integer_32_t>,         \
            nkr::tuple::types_t<const volatile nkr::positive::integer_32_t, nkr::positive::integer_32_t>,   \
            nkr::tuple::types_t<nkr::positive::integer_64_t, nkr::positive::integer_64_t>,                  \
            nkr::tuple::types_t<const nkr::positive::integer_64_t, nkr::positive::integer_64_t>,            \
            nkr::tuple::types_t<volatile nkr::positive::integer_64_t, nkr::positive::integer_64_t>,         \
            nkr::tuple::types_t<const volatile nkr::positive::integer_64_t, nkr::positive::integer_64_t>    \

        #define nkr_ANY_WITH_LVALUE                                                                                         \
            nkr::tuple::types_t<nkr::positive::integer_8_t, nkr::positive::integer_8_t>,                                    \
            nkr::tuple::types_t<nkr::positive::integer_8_t, const nkr::positive::integer_8_t>,                              \
            nkr::tuple::types_t<nkr::positive::integer_8_t, volatile nkr::positive::integer_8_t>,                           \
            nkr::tuple::types_t<nkr::positive::integer_8_t, const volatile nkr::positive::integer_8_t>,                     \
            nkr::tuple::types_t<const nkr::positive::integer_8_t, nkr::positive::integer_8_t>,                              \
            nkr::tuple::types_t<const nkr::positive::integer_8_t, const nkr::positive::integer_8_t>,                        \
            nkr::tuple::types_t<const nkr::positive::integer_8_t, volatile nkr::positive::integer_8_t>,                     \
            nkr::tuple::types_t<const nkr::positive::integer_8_t, const volatile nkr::positive::integer_8_t>,               \
            nkr::tuple::types_t<volatile nkr::positive::integer_8_t, nkr::positive::integer_8_t>,                           \
            nkr::tuple::types_t<volatile nkr::positive::integer_8_t, const nkr::positive::integer_8_t>,                     \
            nkr::tuple::types_t<volatile nkr::positive::integer_8_t, volatile nkr::positive::integer_8_t>,                  \
            nkr::tuple::types_t<volatile nkr::positive::integer_8_t, const volatile nkr::positive::integer_8_t>,            \
            nkr::tuple::types_t<const volatile nkr::positive::integer_8_t, nkr::positive::integer_8_t>,                     \
            nkr::tuple::types_t<const volatile nkr::positive::integer_8_t, const nkr::positive::integer_8_t>,               \
            nkr::tuple::types_t<const volatile nkr::positive::integer_8_t, volatile nkr::positive::integer_8_t>,            \
            nkr::tuple::types_t<const volatile nkr::positive::integer_8_t, const volatile nkr::positive::integer_8_t>,      \
            nkr::tuple::types_t<nkr::positive::integer_16_t, nkr::positive::integer_16_t>,                                  \
            nkr::tuple::types_t<nkr::positive::integer_16_t, const nkr::positive::integer_16_t>,                            \
            nkr::tuple::types_t<nkr::positive::integer_16_t, volatile nkr::positive::integer_16_t>,                         \
            nkr::tuple::types_t<nkr::positive::integer_16_t, const volatile nkr::positive::integer_16_t>,                   \
            nkr::tuple::types_t<const nkr::positive::integer_16_t, nkr::positive::integer_16_t>,                            \
            nkr::tuple::types_t<const nkr::positive::integer_16_t, const nkr::positive::integer_16_t>,                      \
            nkr::tuple::types_t<const nkr::positive::integer_16_t, volatile nkr::positive::integer_16_t>,                   \
            nkr::tuple::types_t<const nkr::positive::integer_16_t, const volatile nkr::positive::integer_16_t>,             \
            nkr::tuple::types_t<volatile nkr::positive::integer_16_t, nkr::positive::integer_16_t>,                         \
            nkr::tuple::types_t<volatile nkr::positive::integer_16_t, const nkr::positive::integer_16_t>,                   \
            nkr::tuple::types_t<volatile nkr::positive::integer_16_t, volatile nkr::positive::integer_16_t>,                \
            nkr::tuple::types_t<volatile nkr::positive::integer_16_t, const volatile nkr::positive::integer_16_t>,          \
            nkr::tuple::types_t<const volatile nkr::positive::integer_16_t, nkr::positive::integer_16_t>,                   \
            nkr::tuple::types_t<const volatile nkr::positive::integer_16_t, const nkr::positive::integer_16_t>,             \
            nkr::tuple::types_t<const volatile nkr::positive::integer_16_t, volatile nkr::positive::integer_16_t>,          \
            nkr::tuple::types_t<const volatile nkr::positive::integer_16_t, const volatile nkr::positive::integer_16_t>,    \
            nkr::tuple::types_t<nkr::positive::integer_32_t, nkr::positive::integer_32_t>,                                  \
            nkr::tuple::types_t<nkr::positive::integer_32_t, const nkr::positive::integer_32_t>,                            \
            nkr::tuple::types_t<nkr::positive::integer_32_t, volatile nkr::positive::integer_32_t>,                         \
            nkr::tuple::types_t<nkr::positive::integer_32_t, const volatile nkr::positive::integer_32_t>,                   \
            nkr::tuple::types_t<const nkr::positive::integer_32_t, nkr::positive::integer_32_t>,                            \
            nkr::tuple::types_t<const nkr::positive::integer_32_t, const nkr::positive::integer_32_t>,                      \
            nkr::tuple::types_t<const nkr::positive::integer_32_t, volatile nkr::positive::integer_32_t>,                   \
            nkr::tuple::types_t<const nkr::positive::integer_32_t, const volatile nkr::positive::integer_32_t>,             \
            nkr::tuple::types_t<volatile nkr::positive::integer_32_t, nkr::positive::integer_32_t>,                         \
            nkr::tuple::types_t<volatile nkr::positive::integer_32_t, const nkr::positive::integer_32_t>,                   \
            nkr::tuple::types_t<volatile nkr::positive::integer_32_t, volatile nkr::positive::integer_32_t>,                \
            nkr::tuple::types_t<volatile nkr::positive::integer_32_t, const volatile nkr::positive::integer_32_t>,          \
            nkr::tuple::types_t<const volatile nkr::positive::integer_32_t, nkr::positive::integer_32_t>,                   \
            nkr::tuple::types_t<const volatile nkr::positive::integer_32_t, const nkr::positive::integer_32_t>,             \
            nkr::tuple::types_t<const volatile nkr::positive::integer_32_t, volatile nkr::positive::integer_32_t>,          \
            nkr::tuple::types_t<const volatile nkr::positive::integer_32_t, const volatile nkr::positive::integer_32_t>,    \
            nkr::tuple::types_t<nkr::positive::integer_64_t, nkr::positive::integer_64_t>,                                  \
            nkr::tuple::types_t<nkr::positive::integer_64_t, const nkr::positive::integer_64_t>,                            \
            nkr::tuple::types_t<nkr::positive::integer_64_t, volatile nkr::positive::integer_64_t>,                         \
            nkr::tuple::types_t<nkr::positive::integer_64_t, const volatile nkr::positive::integer_64_t>,                   \
            nkr::tuple::types_t<const nkr::positive::integer_64_t, nkr::positive::integer_64_t>,                            \
            nkr::tuple::types_t<const nkr::positive::integer_64_t, const nkr::positive::integer_64_t>,                      \
            nkr::tuple::types_t<const nkr::positive::integer_64_t, volatile nkr::positive::integer_64_t>,                   \
            nkr::tuple::types_t<const nkr::positive::integer_64_t, const volatile nkr::positive::integer_64_t>,             \
            nkr::tuple::types_t<volatile nkr::positive::integer_64_t, nkr::positive::integer_64_t>,                         \
            nkr::tuple::types_t<volatile nkr::positive::integer_64_t, const nkr::positive::integer_64_t>,                   \
            nkr::tuple::types_t<volatile nkr::positive::integer_64_t, volatile nkr::positive::integer_64_t>,                \
            nkr::tuple::types_t<volatile nkr::positive::integer_64_t, const volatile nkr::positive::integer_64_t>,          \
            nkr::tuple::types_t<const volatile nkr::positive::integer_64_t, nkr::positive::integer_64_t>,                   \
            nkr::tuple::types_t<const volatile nkr::positive::integer_64_t, const nkr::positive::integer_64_t>,             \
            nkr::tuple::types_t<const volatile nkr::positive::integer_64_t, volatile nkr::positive::integer_64_t>,          \
            nkr::tuple::types_t<const volatile nkr::positive::integer_64_t, const volatile nkr::positive::integer_64_t>     \

        #define nkr_ANY_WITH_RVALUE                                                                                 \
            nkr::tuple::types_t<nkr::positive::integer_8_t, nkr::positive::integer_8_t>,                            \
            nkr::tuple::types_t<nkr::positive::integer_8_t, volatile nkr::positive::integer_8_t>,                   \
            nkr::tuple::types_t<const nkr::positive::integer_8_t, nkr::positive::integer_8_t>,                      \
            nkr::tuple::types_t<const nkr::positive::integer_8_t, volatile nkr::positive::integer_8_t>,             \
            nkr::tuple::types_t<volatile nkr::positive::integer_8_t, nkr::positive::integer_8_t>,                   \
            nkr::tuple::types_t<volatile nkr::positive::integer_8_t, volatile nkr::positive::integer_8_t>,          \
            nkr::tuple::types_t<const volatile nkr::positive::integer_8_t, nkr::positive::integer_8_t>,             \
            nkr::tuple::types_t<const volatile nkr::positive::integer_8_t, volatile nkr::positive::integer_8_t>,    \
            nkr::tuple::types_t<nkr::positive::integer_16_t, nkr::positive::integer_16_t>,                          \
            nkr::tuple::types_t<nkr::positive::integer_16_t, volatile nkr::positive::integer_16_t>,                 \
            nkr::tuple::types_t<const nkr::positive::integer_16_t, nkr::positive::integer_16_t>,                    \
            nkr::tuple::types_t<const nkr::positive::integer_16_t, volatile nkr::positive::integer_16_t>,           \
            nkr::tuple::types_t<volatile nkr::positive::integer_16_t, nkr::positive::integer_16_t>,                 \
            nkr::tuple::types_t<volatile nkr::positive::integer_16_t, volatile nkr::positive::integer_16_t>,        \
            nkr::tuple::types_t<const volatile nkr::positive::integer_16_t, nkr::positive::integer_16_t>,           \
            nkr::tuple::types_t<const volatile nkr::positive::integer_16_t, volatile nkr::positive::integer_16_t>,  \
            nkr::tuple::types_t<nkr::positive::integer_32_t, nkr::positive::integer_32_t>,                          \
            nkr::tuple::types_t<nkr::positive::integer_32_t, volatile nkr::positive::integer_32_t>,                 \
            nkr::tuple::types_t<const nkr::positive::integer_32_t, nkr::positive::integer_32_t>,                    \
            nkr::tuple::types_t<const nkr::positive::integer_32_t, volatile nkr::positive::integer_32_t>,           \
            nkr::tuple::types_t<volatile nkr::positive::integer_32_t, nkr::positive::integer_32_t>,                 \
            nkr::tuple::types_t<volatile nkr::positive::integer_32_t, volatile nkr::positive::integer_32_t>,        \
            nkr::tuple::types_t<const volatile nkr::positive::integer_32_t, nkr::positive::integer_32_t>,           \
            nkr::tuple::types_t<const volatile nkr::positive::integer_32_t, volatile nkr::positive::integer_32_t>,  \
            nkr::tuple::types_t<nkr::positive::integer_64_t, nkr::positive::integer_64_t>,                          \
            nkr::tuple::types_t<nkr::positive::integer_64_t, volatile nkr::positive::integer_64_t>,                 \
            nkr::tuple::types_t<const nkr::positive::integer_64_t, nkr::positive::integer_64_t>,                    \
            nkr::tuple::types_t<const nkr::positive::integer_64_t, volatile nkr::positive::integer_64_t>,           \
            nkr::tuple::types_t<volatile nkr::positive::integer_64_t, nkr::positive::integer_64_t>,                 \
            nkr::tuple::types_t<volatile nkr::positive::integer_64_t, volatile nkr::positive::integer_64_t>,        \
            nkr::tuple::types_t<const volatile nkr::positive::integer_64_t, nkr::positive::integer_64_t>,           \
            nkr::tuple::types_t<const volatile nkr::positive::integer_64_t, volatile nkr::positive::integer_64_t>   \

        #define nkr_NON_CONST_WITH_VALUE                                                            \
            nkr::tuple::types_t<nkr::positive::integer_8_t, nkr::positive::integer_8_t>,            \
            nkr::tuple::types_t<volatile nkr::positive::integer_8_t, nkr::positive::integer_8_t>,   \
            nkr::tuple::types_t<nkr::positive::integer_16_t, nkr::positive::integer_16_t>,          \
            nkr::tuple::types_t<volatile nkr::positive::integer_16_t, nkr::positive::integer_16_t>, \
            nkr::tuple::types_t<nkr::positive::integer_32_t, nkr::positive::integer_32_t>,          \
            nkr::tuple::types_t<volatile nkr::positive::integer_32_t, nkr::positive::integer_32_t>, \
            nkr::tuple::types_t<nkr::positive::integer_64_t, nkr::positive::integer_64_t>,          \
            nkr::tuple::types_t<volatile nkr::positive::integer_64_t, nkr::positive::integer_64_t>  \

        #define nkr_NON_CONST_WITH_LVALUE                                                                           \
            nkr::tuple::types_t<nkr::positive::integer_8_t, nkr::positive::integer_8_t>,                            \
            nkr::tuple::types_t<nkr::positive::integer_8_t, const nkr::positive::integer_8_t>,                      \
            nkr::tuple::types_t<nkr::positive::integer_8_t, volatile nkr::positive::integer_8_t>,                   \
            nkr::tuple::types_t<nkr::positive::integer_8_t, const volatile nkr::positive::integer_8_t>,             \
            nkr::tuple::types_t<volatile nkr::positive::integer_8_t, nkr::positive::integer_8_t>,                   \
            nkr::tuple::types_t<volatile nkr::positive::integer_8_t, const nkr::positive::integer_8_t>,             \
            nkr::tuple::types_t<volatile nkr::positive::integer_8_t, volatile nkr::positive::integer_8_t>,          \
            nkr::tuple::types_t<volatile nkr::positive::integer_8_t, const volatile nkr::positive::integer_8_t>,    \
            nkr::tuple::types_t<nkr::positive::integer_16_t, nkr::positive::integer_16_t>,                          \
            nkr::tuple::types_t<nkr::positive::integer_16_t, const nkr::positive::integer_16_t>,                    \
            nkr::tuple::types_t<nkr::positive::integer_16_t, volatile nkr::positive::integer_16_t>,                 \
            nkr::tuple::types_t<nkr::positive::integer_16_t, const volatile nkr::positive::integer_16_t>,           \
            nkr::tuple::types_t<volatile nkr::positive::integer_16_t, nkr::positive::integer_16_t>,                 \
            nkr::tuple::types_t<volatile nkr::positive::integer_16_t, const nkr::positive::integer_16_t>,           \
            nkr::tuple::types_t<volatile nkr::positive::integer_16_t, volatile nkr::positive::integer_16_t>,        \
            nkr::tuple::types_t<volatile nkr::positive::integer_16_t, const volatile nkr::positive::integer_16_t>,  \
            nkr::tuple::types_t<nkr::positive::integer_32_t, nkr::positive::integer_32_t>,                          \
            nkr::tuple::types_t<nkr::positive::integer_32_t, const nkr::positive::integer_32_t>,                    \
            nkr::tuple::types_t<nkr::positive::integer_32_t, volatile nkr::positive::integer_32_t>,                 \
            nkr::tuple::types_t<nkr::positive::integer_32_t, const volatile nkr::positive::integer_32_t>,           \
            nkr::tuple::types_t<volatile nkr::positive::integer_32_t, nkr::positive::integer_32_t>,                 \
            nkr::tuple::types_t<volatile nkr::positive::integer_32_t, const nkr::positive::integer_32_t>,           \
            nkr::tuple::types_t<volatile nkr::positive::integer_32_t, volatile nkr::positive::integer_32_t>,        \
            nkr::tuple::types_t<volatile nkr::positive::integer_32_t, const volatile nkr::positive::integer_32_t>,  \
            nkr::tuple::types_t<nkr::positive::integer_64_t, nkr::positive::integer_64_t>,                          \
            nkr::tuple::types_t<nkr::positive::integer_64_t, const nkr::positive::integer_64_t>,                    \
            nkr::tuple::types_t<nkr::positive::integer_64_t, volatile nkr::positive::integer_64_t>,                 \
            nkr::tuple::types_t<nkr::positive::integer_64_t, const volatile nkr::positive::integer_64_t>,           \
            nkr::tuple::types_t<volatile nkr::positive::integer_64_t, nkr::positive::integer_64_t>,                 \
            nkr::tuple::types_t<volatile nkr::positive::integer_64_t, const nkr::positive::integer_64_t>,           \
            nkr::tuple::types_t<volatile nkr::positive::integer_64_t, volatile nkr::positive::integer_64_t>,        \
            nkr::tuple::types_t<volatile nkr::positive::integer_64_t, const volatile nkr::positive::integer_64_t>   \

        #define nkr_NON_CONST_WITH_RVALUE                                                                       \
            nkr::tuple::types_t<nkr::positive::integer_8_t, nkr::positive::integer_8_t>,                        \
            nkr::tuple::types_t<nkr::positive::integer_8_t, volatile nkr::positive::integer_8_t>,               \
            nkr::tuple::types_t<volatile nkr::positive::integer_8_t, nkr::positive::integer_8_t>,               \
            nkr::tuple::types_t<volatile nkr::positive::integer_8_t, volatile nkr::positive::integer_8_t>,      \
            nkr::tuple::types_t<nkr::positive::integer_16_t, nkr::positive::integer_16_t>,                      \
            nkr::tuple::types_t<nkr::positive::integer_16_t, volatile nkr::positive::integer_16_t>,             \
            nkr::tuple::types_t<volatile nkr::positive::integer_16_t, nkr::positive::integer_16_t>,             \
            nkr::tuple::types_t<volatile nkr::positive::integer_16_t, volatile nkr::positive::integer_16_t>,    \
            nkr::tuple::types_t<nkr::positive::integer_32_t, nkr::positive::integer_32_t>,                      \
            nkr::tuple::types_t<nkr::positive::integer_32_t, volatile nkr::positive::integer_32_t>,             \
            nkr::tuple::types_t<volatile nkr::positive::integer_32_t, nkr::positive::integer_32_t>,             \
            nkr::tuple::types_t<volatile nkr::positive::integer_32_t, volatile nkr::positive::integer_32_t>,    \
            nkr::tuple::types_t<nkr::positive::integer_64_t, nkr::positive::integer_64_t>,                      \
            nkr::tuple::types_t<nkr::positive::integer_64_t, volatile nkr::positive::integer_64_t>,             \
            nkr::tuple::types_t<volatile nkr::positive::integer_64_t, nkr::positive::integer_64_t>,             \
            nkr::tuple::types_t<volatile nkr::positive::integer_64_t, volatile nkr::positive::integer_64_t>     \

            TEST_CASE_TEMPLATE("unary logical operators: !", integer_p, nkr_ANY)
            {
                using value_t = nkr::cpp::just_non_qualified_t<integer_p>;

                for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                    {
                        integer_p a = nkr::randomness::Value<integer_p>();

                        CHECK(!value_t(a) == !a);
                    }
                }
            }

            TEST_SUITE("binary logical operators: ||, &&")
            {
                TEST_CASE_TEMPLATE("value", tuple_p, nkr_ANY_WITH_VALUE)
                {
                    using integer_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using non_qualified_t = nkr::cpp::just_non_qualified_t<integer_t>;
                    using value_t = nkr::cpp::just_non_qualified_t<integer_t>;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) || value_t(b)) == (a || non_qualified_t(b)));
                            CHECK((value_t(b) || value_t(a)) == (non_qualified_t(b) || a));
                            CHECK((value_t(a) || value_t(b)) == (non_qualified_t(a) || b));
                            CHECK((value_t(b) || value_t(a)) == (b || non_qualified_t(a)));
                            CHECK((value_t(a) || value_t(b)) == (non_qualified_t(a) || non_qualified_t(b)));
                            CHECK((value_t(b) || value_t(a)) == (non_qualified_t(b) || non_qualified_t(a)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) && value_t(b)) == (a && non_qualified_t(b)));
                            CHECK((value_t(b) && value_t(a)) == (non_qualified_t(b) && a));
                            CHECK((value_t(a) && value_t(b)) == (non_qualified_t(a) && b));
                            CHECK((value_t(b) && value_t(a)) == (b && non_qualified_t(a)));
                            CHECK((value_t(a) && value_t(b)) == (non_qualified_t(a) && non_qualified_t(b)));
                            CHECK((value_t(b) && value_t(a)) == (non_qualified_t(b) && non_qualified_t(a)));
                        }
                    }
                }

                TEST_CASE_TEMPLATE("lvalue", tuple_p, nkr_ANY_WITH_LVALUE)
                {
                    using integer_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using value_t = nkr::cpp::just_non_qualified_t<integer_t>;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) || value_t(b)) == (a || b));
                            CHECK((value_t(b) || value_t(a)) == (b || a));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) && value_t(b)) == (a && b));
                            CHECK((value_t(b) && value_t(a)) == (b && a));
                        }
                    }
                }

                TEST_CASE_TEMPLATE("rvalue", tuple_p, nkr_ANY_WITH_RVALUE)
                {
                    using integer_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using value_t = nkr::cpp::just_non_qualified_t<integer_t>;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) || value_t(b)) == (a || nkr::cpp::Move(b)));
                            CHECK((value_t(b) || value_t(a)) == (nkr::cpp::Move(b) || a));
                            if constexpr (nkr::cpp::any_non_const_tr<integer_t>) {
                                CHECK((value_t(a) || value_t(b)) == (nkr::cpp::Move(a) || b));
                                CHECK((value_t(b) || value_t(a)) == (b || nkr::cpp::Move(a)));
                                CHECK((value_t(a) || value_t(b)) == (nkr::cpp::Move(a) || nkr::cpp::Move(b)));
                                CHECK((value_t(b) || value_t(a)) == (nkr::cpp::Move(b) || nkr::cpp::Move(a)));
                            }
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) && value_t(b)) == (a && nkr::cpp::Move(b)));
                            CHECK((value_t(b) && value_t(a)) == (nkr::cpp::Move(b) && a));
                            if constexpr (nkr::cpp::any_non_const_tr<integer_t>) {
                                CHECK((value_t(a) && value_t(b)) == (nkr::cpp::Move(a) && b));
                                CHECK((value_t(b) && value_t(a)) == (b && nkr::cpp::Move(a)));
                                CHECK((value_t(a) && value_t(b)) == (nkr::cpp::Move(a) && nkr::cpp::Move(b)));
                                CHECK((value_t(b) && value_t(a)) == (nkr::cpp::Move(b) && nkr::cpp::Move(a)));
                            }
                        }
                    }
                }
            }

            TEST_SUITE("trinary logical operators: ? :")
            {
                TEST_CASE_TEMPLATE("value", tuple_p, nkr_ANY_WITH_VALUE)
                {
                    using integer_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using non_qualified_t = nkr::cpp::just_non_qualified_t<integer_t>;
                    using value_t = nkr::cpp::just_non_qualified_t<integer_t>;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();
                            other_t c = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) ? value_t(b) : value_t(c)) == (a ? non_qualified_t(b) : non_qualified_t(c)));
                            CHECK((value_t(a) ? value_t(c) : value_t(b)) == (a ? non_qualified_t(c) : non_qualified_t(b)));
                            CHECK((value_t(b) ? value_t(a) : value_t(c)) == (non_qualified_t(b) ? a : non_qualified_t(c)));
                            CHECK((value_t(b) ? value_t(c) : value_t(a)) == (non_qualified_t(b) ? non_qualified_t(c) : a));
                            CHECK((value_t(c) ? value_t(a) : value_t(b)) == (non_qualified_t(c) ? a : non_qualified_t(b)));
                            CHECK((value_t(c) ? value_t(b) : value_t(a)) == (non_qualified_t(c) ? non_qualified_t(b) : a));
                            CHECK((value_t(a) ? value_t(b) : value_t(c)) == (non_qualified_t(a) ? b : c));
                            CHECK((value_t(a) ? value_t(c) : value_t(b)) == (non_qualified_t(a) ? c : b));
                            CHECK((value_t(b) ? value_t(a) : value_t(c)) == (b ? non_qualified_t(a) : c));
                            CHECK((value_t(b) ? value_t(c) : value_t(a)) == (b ? c : non_qualified_t(a)));
                            CHECK((value_t(c) ? value_t(a) : value_t(b)) == (c ? non_qualified_t(a) : b));
                            CHECK((value_t(c) ? value_t(b) : value_t(a)) == (c ? b : non_qualified_t(a)));
                            CHECK((value_t(a) ? value_t(b) : value_t(c)) == (non_qualified_t(a) ? non_qualified_t(b) : non_qualified_t(c)));
                            CHECK((value_t(a) ? value_t(c) : value_t(b)) == (non_qualified_t(a) ? non_qualified_t(c) : non_qualified_t(b)));
                            CHECK((value_t(b) ? value_t(a) : value_t(c)) == (non_qualified_t(b) ? non_qualified_t(a) : non_qualified_t(c)));
                            CHECK((value_t(b) ? value_t(c) : value_t(a)) == (non_qualified_t(b) ? non_qualified_t(c) : non_qualified_t(a)));
                            CHECK((value_t(c) ? value_t(a) : value_t(b)) == (non_qualified_t(c) ? non_qualified_t(a) : non_qualified_t(b)));
                            CHECK((value_t(c) ? value_t(b) : value_t(a)) == (non_qualified_t(c) ? non_qualified_t(b) : non_qualified_t(a)));
                        }
                    }
                }

                TEST_CASE_TEMPLATE("lvalue", tuple_p, nkr_ANY_WITH_LVALUE)
                {
                    using integer_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using value_t = nkr::cpp::just_non_qualified_t<integer_t>;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();
                            other_t c = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) ? value_t(b) : value_t(c)) == (a ? b : c));
                            CHECK((value_t(a) ? value_t(c) : value_t(b)) == (a ? c : b));
                            CHECK((value_t(b) ? value_t(a) : value_t(c)) == (b ? a : c));
                            CHECK((value_t(b) ? value_t(c) : value_t(a)) == (b ? c : a));
                            CHECK((value_t(c) ? value_t(a) : value_t(b)) == (c ? a : b));
                            CHECK((value_t(c) ? value_t(b) : value_t(a)) == (c ? b : a));
                        }
                    }
                }

                TEST_CASE_TEMPLATE("rvalue", tuple_p, nkr_ANY_WITH_RVALUE)
                {
                    using integer_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using value_t = nkr::cpp::just_non_qualified_t<integer_t>;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();
                            other_t c = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) ? value_t(b) : value_t(c)) == (a ? nkr::cpp::Move(b) : nkr::cpp::Move(c)));
                            CHECK((value_t(a) ? value_t(c) : value_t(b)) == (a ? nkr::cpp::Move(c) : nkr::cpp::Move(b)));
                            CHECK((value_t(b) ? value_t(a) : value_t(c)) == (nkr::cpp::Move(b) ? a : nkr::cpp::Move(c)));
                            CHECK((value_t(b) ? value_t(c) : value_t(a)) == (nkr::cpp::Move(b) ? nkr::cpp::Move(c) : a));
                            CHECK((value_t(c) ? value_t(a) : value_t(b)) == (nkr::cpp::Move(c) ? a : nkr::cpp::Move(b)));
                            CHECK((value_t(c) ? value_t(b) : value_t(a)) == (nkr::cpp::Move(c) ? nkr::cpp::Move(b) : a));
                            if constexpr (nkr::cpp::any_non_const_tr<integer_t>) {
                                CHECK((value_t(a) ? value_t(b) : value_t(c)) == (nkr::cpp::Move(a) ? b : c));
                                CHECK((value_t(a) ? value_t(c) : value_t(b)) == (nkr::cpp::Move(a) ? c : b));
                                CHECK((value_t(b) ? value_t(a) : value_t(c)) == (b ? nkr::cpp::Move(a) : c));
                                CHECK((value_t(b) ? value_t(c) : value_t(a)) == (b ? c : nkr::cpp::Move(a)));
                                CHECK((value_t(c) ? value_t(a) : value_t(b)) == (c ? nkr::cpp::Move(a) : b));
                                CHECK((value_t(c) ? value_t(b) : value_t(a)) == (c ? b : nkr::cpp::Move(a)));
                                CHECK((value_t(a) ? value_t(b) : value_t(c)) == (nkr::cpp::Move(a) ? nkr::cpp::Move(b) : nkr::cpp::Move(c)));
                                CHECK((value_t(a) ? value_t(c) : value_t(b)) == (nkr::cpp::Move(a) ? nkr::cpp::Move(c) : nkr::cpp::Move(b)));
                                CHECK((value_t(b) ? value_t(a) : value_t(c)) == (nkr::cpp::Move(b) ? nkr::cpp::Move(a) : nkr::cpp::Move(c)));
                                CHECK((value_t(b) ? value_t(c) : value_t(a)) == (nkr::cpp::Move(b) ? nkr::cpp::Move(c) : nkr::cpp::Move(a)));
                                CHECK((value_t(c) ? value_t(a) : value_t(b)) == (nkr::cpp::Move(c) ? nkr::cpp::Move(a) : nkr::cpp::Move(b)));
                                CHECK((value_t(c) ? value_t(b) : value_t(a)) == (nkr::cpp::Move(c) ? nkr::cpp::Move(b) : nkr::cpp::Move(a)));
                            }
                        }
                    }
                }
            }

            TEST_SUITE("binary comparison operators: ==, !=, <, >, <=, >=, <=>")
            {
                TEST_CASE_TEMPLATE("value", tuple_p, nkr_ANY_WITH_VALUE)
                {
                    using integer_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using non_qualified_t = nkr::cpp::just_non_qualified_t<integer_t>;
                    using value_t = nkr::cpp::just_non_qualified_t<integer_t>;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) == value_t(b)) == (a == non_qualified_t(b)));
                            CHECK((value_t(b) == value_t(a)) == (non_qualified_t(b) == a));
                            CHECK((value_t(a) == value_t(b)) == (non_qualified_t(a) == b));
                            CHECK((value_t(b) == value_t(a)) == (b == non_qualified_t(a)));
                            CHECK((value_t(a) == value_t(b)) == (non_qualified_t(a) == non_qualified_t(b)));
                            CHECK((value_t(b) == value_t(a)) == (non_qualified_t(b) == non_qualified_t(a)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) != value_t(b)) == (a != non_qualified_t(b)));
                            CHECK((value_t(b) != value_t(a)) == (non_qualified_t(b) != a));
                            CHECK((value_t(a) != value_t(b)) == (non_qualified_t(a) != b));
                            CHECK((value_t(b) != value_t(a)) == (b != non_qualified_t(a)));
                            CHECK((value_t(a) != value_t(b)) == (non_qualified_t(a) != non_qualified_t(b)));
                            CHECK((value_t(b) != value_t(a)) == (non_qualified_t(b) != non_qualified_t(a)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) < value_t(b)) == (a < non_qualified_t(b)));
                            CHECK((value_t(b) < value_t(a)) == (non_qualified_t(b) < a));
                            CHECK((value_t(a) < value_t(b)) == (non_qualified_t(a) < b));
                            CHECK((value_t(b) < value_t(a)) == (b < non_qualified_t(a)));
                            CHECK((value_t(a) < value_t(b)) == (non_qualified_t(a) < non_qualified_t(b)));
                            CHECK((value_t(b) < value_t(a)) == (non_qualified_t(b) < non_qualified_t(a)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) > value_t(b)) == (a > non_qualified_t(b)));
                            CHECK((value_t(b) > value_t(a)) == (non_qualified_t(b) > a));
                            CHECK((value_t(a) > value_t(b)) == (non_qualified_t(a) > b));
                            CHECK((value_t(b) > value_t(a)) == (b > non_qualified_t(a)));
                            CHECK((value_t(a) > value_t(b)) == (non_qualified_t(a) > non_qualified_t(b)));
                            CHECK((value_t(b) > value_t(a)) == (non_qualified_t(b) > non_qualified_t(a)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) <= value_t(b)) == (a <= non_qualified_t(b)));
                            CHECK((value_t(b) <= value_t(a)) == (non_qualified_t(b) <= a));
                            CHECK((value_t(a) <= value_t(b)) == (non_qualified_t(a) <= b));
                            CHECK((value_t(b) <= value_t(a)) == (b <= non_qualified_t(a)));
                            CHECK((value_t(a) <= value_t(b)) == (non_qualified_t(a) <= non_qualified_t(b)));
                            CHECK((value_t(b) <= value_t(a)) == (non_qualified_t(b) <= non_qualified_t(a)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) >= value_t(b)) == (a >= non_qualified_t(b)));
                            CHECK((value_t(b) >= value_t(a)) == (non_qualified_t(b) >= a));
                            CHECK((value_t(a) >= value_t(b)) == (non_qualified_t(a) >= b));
                            CHECK((value_t(b) >= value_t(a)) == (b >= non_qualified_t(a)));
                            CHECK((value_t(a) >= value_t(b)) == (non_qualified_t(a) >= non_qualified_t(b)));
                            CHECK((value_t(b) >= value_t(a)) == (non_qualified_t(b) >= non_qualified_t(a)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) <=> value_t(b)) == (a <=> non_qualified_t(b)));
                            CHECK((value_t(b) <=> value_t(a)) == (non_qualified_t(b) <=> a));
                            CHECK((value_t(a) <=> value_t(b)) == (non_qualified_t(a) <=> b));
                            CHECK((value_t(b) <=> value_t(a)) == (b <=> non_qualified_t(a)));
                            CHECK((value_t(a) <=> value_t(b)) == (non_qualified_t(a) <=> non_qualified_t(b)));
                            CHECK((value_t(b) <=> value_t(a)) == (non_qualified_t(b) <=> non_qualified_t(a)));
                        }
                    }
                }

                TEST_CASE_TEMPLATE("lvalue", tuple_p, nkr_ANY_WITH_LVALUE)
                {
                    using integer_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using value_t = nkr::cpp::just_non_qualified_t<integer_t>;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) == value_t(b)) == (a == b));
                            CHECK((value_t(b) == value_t(a)) == (b == a));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) != value_t(b)) == (a != b));
                            CHECK((value_t(b) != value_t(a)) == (b != a));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) < value_t(b)) == (a < b));
                            CHECK((value_t(b) < value_t(a)) == (b < a));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) > value_t(b)) == (a > b));
                            CHECK((value_t(b) > value_t(a)) == (b > a));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) <= value_t(b)) == (a <= b));
                            CHECK((value_t(b) <= value_t(a)) == (b <= a));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) >= value_t(b)) == (a >= b));
                            CHECK((value_t(b) >= value_t(a)) == (b >= a));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) <=> value_t(b)) == (a <=> b));
                            CHECK((value_t(b) <=> value_t(a)) == (b <=> a));
                        }
                    }
                }

                TEST_CASE_TEMPLATE("rvalue", tuple_p, nkr_ANY_WITH_RVALUE)
                {
                    using integer_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using value_t = nkr::cpp::just_non_qualified_t<integer_t>;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) == value_t(b)) == (a == nkr::cpp::Move(b)));
                            CHECK((value_t(b) == value_t(a)) == (nkr::cpp::Move(b) == a));
                            if constexpr (nkr::cpp::any_non_const_tr<integer_t>) {
                                CHECK((value_t(a) == value_t(b)) == (nkr::cpp::Move(a) == b));
                                CHECK((value_t(b) == value_t(a)) == (b == nkr::cpp::Move(a)));
                                CHECK((value_t(a) == value_t(b)) == (nkr::cpp::Move(a) == nkr::cpp::Move(b)));
                                CHECK((value_t(b) == value_t(a)) == (nkr::cpp::Move(b) == nkr::cpp::Move(a)));
                            }
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) != value_t(b)) == (a != nkr::cpp::Move(b)));
                            CHECK((value_t(b) != value_t(a)) == (nkr::cpp::Move(b) != a));
                            if constexpr (nkr::cpp::any_non_const_tr<integer_t>) {
                                CHECK((value_t(a) != value_t(b)) == (nkr::cpp::Move(a) != b));
                                CHECK((value_t(b) != value_t(a)) == (b != nkr::cpp::Move(a)));
                                CHECK((value_t(a) != value_t(b)) == (nkr::cpp::Move(a) != nkr::cpp::Move(b)));
                                CHECK((value_t(b) != value_t(a)) == (nkr::cpp::Move(b) != nkr::cpp::Move(a)));
                            }
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) < value_t(b)) == (a < nkr::cpp::Move(b)));
                            CHECK((value_t(b) < value_t(a)) == (nkr::cpp::Move(b) < a));
                            if constexpr (nkr::cpp::any_non_const_tr<integer_t>) {
                                CHECK((value_t(a) < value_t(b)) == (nkr::cpp::Move(a) < b));
                                CHECK((value_t(b) < value_t(a)) == (b < nkr::cpp::Move(a)));
                                CHECK((value_t(a) < value_t(b)) == (nkr::cpp::Move(a) < nkr::cpp::Move(b)));
                                CHECK((value_t(b) < value_t(a)) == (nkr::cpp::Move(b) < nkr::cpp::Move(a)));
                            }
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) > value_t(b)) == (a > nkr::cpp::Move(b)));
                            CHECK((value_t(b) > value_t(a)) == (nkr::cpp::Move(b) > a));
                            if constexpr (nkr::cpp::any_non_const_tr<integer_t>) {
                                CHECK((value_t(a) > value_t(b)) == (nkr::cpp::Move(a) > b));
                                CHECK((value_t(b) > value_t(a)) == (b > nkr::cpp::Move(a)));
                                CHECK((value_t(a) > value_t(b)) == (nkr::cpp::Move(a) > nkr::cpp::Move(b)));
                                CHECK((value_t(b) > value_t(a)) == (nkr::cpp::Move(b) > nkr::cpp::Move(a)));
                            }
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) <= value_t(b)) == (a <= nkr::cpp::Move(b)));
                            CHECK((value_t(b) <= value_t(a)) == (nkr::cpp::Move(b) <= a));
                            if constexpr (nkr::cpp::any_non_const_tr<integer_t>) {
                                CHECK((value_t(a) <= value_t(b)) == (nkr::cpp::Move(a) <= b));
                                CHECK((value_t(b) <= value_t(a)) == (b <= nkr::cpp::Move(a)));
                                CHECK((value_t(a) <= value_t(b)) == (nkr::cpp::Move(a) <= nkr::cpp::Move(b)));
                                CHECK((value_t(b) <= value_t(a)) == (nkr::cpp::Move(b) <= nkr::cpp::Move(a)));
                            }
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) >= value_t(b)) == (a >= nkr::cpp::Move(b)));
                            CHECK((value_t(b) >= value_t(a)) == (nkr::cpp::Move(b) >= a));
                            if constexpr (nkr::cpp::any_non_const_tr<integer_t>) {
                                CHECK((value_t(a) >= value_t(b)) == (nkr::cpp::Move(a) >= b));
                                CHECK((value_t(b) >= value_t(a)) == (b >= nkr::cpp::Move(a)));
                                CHECK((value_t(a) >= value_t(b)) == (nkr::cpp::Move(a) >= nkr::cpp::Move(b)));
                                CHECK((value_t(b) >= value_t(a)) == (nkr::cpp::Move(b) >= nkr::cpp::Move(a)));
                            }
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) <=> value_t(b)) == (a <=> nkr::cpp::Move(b)));
                            CHECK((value_t(b) <=> value_t(a)) == (nkr::cpp::Move(b) <=> a));
                            if constexpr (nkr::cpp::any_non_const_tr<integer_t>) {
                                CHECK((value_t(a) <=> value_t(b)) == (nkr::cpp::Move(a) <=> b));
                                CHECK((value_t(b) <=> value_t(a)) == (b <=> nkr::cpp::Move(a)));
                                CHECK((value_t(a) <=> value_t(b)) == (nkr::cpp::Move(a) <=> nkr::cpp::Move(b)));
                                CHECK((value_t(b) <=> value_t(a)) == (nkr::cpp::Move(b) <=> nkr::cpp::Move(a)));
                            }
                        }
                    }
                }
            }

            TEST_CASE_TEMPLATE("unary arithmetic operators: +, -", integer_p, nkr_ANY)
            {
                using value_t = nkr::cpp::just_non_qualified_t<integer_p>;

                for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                    {
                        integer_p a = nkr::randomness::Value<integer_p>();

                        CHECK(+value_t(a) == +a);
                    }
                    {
                        integer_p a = nkr::randomness::Value<integer_p>();

                        CHECK(-value_t(a) == -a);
                    }
                }
            }

            TEST_SUITE("binary arithmetic operators: +, -, *, /, %")
            {
                TEST_CASE_TEMPLATE("value", tuple_p, nkr_ANY_WITH_VALUE)
                {
                    using integer_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using non_qualified_t = nkr::cpp::just_non_qualified_t<integer_t>;
                    using value_t = nkr::cpp::just_non_qualified_t<integer_t>;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) + value_t(b)) == (a + non_qualified_t(b)));
                            CHECK((value_t(b) + value_t(a)) == (non_qualified_t(b) + a));
                            CHECK((value_t(a) + value_t(b)) == (non_qualified_t(a) + b));
                            CHECK((value_t(b) + value_t(a)) == (b + non_qualified_t(a)));
                            CHECK((value_t(a) + value_t(b)) == (non_qualified_t(a) + non_qualified_t(b)));
                            CHECK((value_t(b) + value_t(a)) == (non_qualified_t(b) + non_qualified_t(a)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) - value_t(b)) == (a - non_qualified_t(b)));
                            CHECK((value_t(b) - value_t(a)) == (non_qualified_t(b) - a));
                            CHECK((value_t(a) - value_t(b)) == (non_qualified_t(a) - b));
                            CHECK((value_t(b) - value_t(a)) == (b - non_qualified_t(a)));
                            CHECK((value_t(a) - value_t(b)) == (non_qualified_t(a) - non_qualified_t(b)));
                            CHECK((value_t(b) - value_t(a)) == (non_qualified_t(b) - non_qualified_t(a)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) * value_t(b)) == (a * non_qualified_t(b)));
                            CHECK((value_t(b) * value_t(a)) == (non_qualified_t(b) * a));
                            CHECK((value_t(a) * value_t(b)) == (non_qualified_t(a) * b));
                            CHECK((value_t(b) * value_t(a)) == (b * non_qualified_t(a)));
                            CHECK((value_t(a) * value_t(b)) == (non_qualified_t(a) * non_qualified_t(b)));
                            CHECK((value_t(b) * value_t(a)) == (non_qualified_t(b) * non_qualified_t(a)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>(value_t(1), value_t(~0));
                            other_t b = nkr::randomness::Value<integer_t>(value_t(1), value_t(~0));

                            CHECK((value_t(a) / value_t(b)) == (a / non_qualified_t(b)));
                            CHECK((value_t(b) / value_t(a)) == (non_qualified_t(b) / a));
                            CHECK((value_t(a) / value_t(b)) == (non_qualified_t(a) / b));
                            CHECK((value_t(b) / value_t(a)) == (b / non_qualified_t(a)));
                            CHECK((value_t(a) / value_t(b)) == (non_qualified_t(a) / non_qualified_t(b)));
                            CHECK((value_t(b) / value_t(a)) == (non_qualified_t(b) / non_qualified_t(a)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>(value_t(1), value_t(~0));
                            other_t b = nkr::randomness::Value<integer_t>(value_t(1), value_t(~0));

                            CHECK((value_t(a) % value_t(b)) == (a % non_qualified_t(b)));
                            CHECK((value_t(b) % value_t(a)) == (non_qualified_t(b) % a));
                            CHECK((value_t(a) % value_t(b)) == (non_qualified_t(a) % b));
                            CHECK((value_t(b) % value_t(a)) == (b % non_qualified_t(a)));
                            CHECK((value_t(a) % value_t(b)) == (non_qualified_t(a) % non_qualified_t(b)));
                            CHECK((value_t(b) % value_t(a)) == (non_qualified_t(b) % non_qualified_t(a)));
                        }
                    }
                }

                TEST_CASE_TEMPLATE("lvalue", tuple_p, nkr_ANY_WITH_LVALUE)
                {
                    using integer_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using value_t = nkr::cpp::just_non_qualified_t<integer_t>;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) + value_t(b)) == (a + b));
                            CHECK((value_t(b) + value_t(a)) == (b + a));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) - value_t(b)) == (a - b));
                            CHECK((value_t(b) - value_t(a)) == (b - a));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) * value_t(b)) == (a * b));
                            CHECK((value_t(b) * value_t(a)) == (b * a));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>(value_t(1), value_t(~0));
                            other_t b = nkr::randomness::Value<integer_t>(value_t(1), value_t(~0));

                            CHECK((value_t(a) / value_t(b)) == (a / b));
                            CHECK((value_t(b) / value_t(a)) == (b / a));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>(value_t(1), value_t(~0));
                            other_t b = nkr::randomness::Value<integer_t>(value_t(1), value_t(~0));

                            CHECK((value_t(a) % value_t(b)) == (a % b));
                            CHECK((value_t(b) % value_t(a)) == (b % a));
                        }
                    }
                }

                TEST_CASE_TEMPLATE("rvalue", tuple_p, nkr_ANY_WITH_RVALUE)
                {
                    using integer_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using value_t = nkr::cpp::just_non_qualified_t<integer_t>;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) + value_t(b)) == (a + nkr::cpp::Move(b)));
                            CHECK((value_t(b) + value_t(a)) == (nkr::cpp::Move(b) + a));
                            if constexpr (nkr::cpp::any_non_const_tr<integer_t>) {
                                CHECK((value_t(a) + value_t(b)) == (nkr::cpp::Move(a) + b));
                                CHECK((value_t(b) + value_t(a)) == (b + nkr::cpp::Move(a)));
                                CHECK((value_t(a) + value_t(b)) == (nkr::cpp::Move(a) + nkr::cpp::Move(b)));
                                CHECK((value_t(b) + value_t(a)) == (nkr::cpp::Move(b) + nkr::cpp::Move(a)));
                            }
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) - value_t(b)) == (a - nkr::cpp::Move(b)));
                            CHECK((value_t(b) - value_t(a)) == (nkr::cpp::Move(b) - a));
                            if constexpr (nkr::cpp::any_non_const_tr<integer_t>) {
                                CHECK((value_t(a) - value_t(b)) == (nkr::cpp::Move(a) - b));
                                CHECK((value_t(b) - value_t(a)) == (b - nkr::cpp::Move(a)));
                                CHECK((value_t(a) - value_t(b)) == (nkr::cpp::Move(a) - nkr::cpp::Move(b)));
                                CHECK((value_t(b) - value_t(a)) == (nkr::cpp::Move(b) - nkr::cpp::Move(a)));
                            }
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) * value_t(b)) == (a * nkr::cpp::Move(b)));
                            CHECK((value_t(b) * value_t(a)) == (nkr::cpp::Move(b) * a));
                            if constexpr (nkr::cpp::any_non_const_tr<integer_t>) {
                                CHECK((value_t(a) * value_t(b)) == (nkr::cpp::Move(a) * b));
                                CHECK((value_t(b) * value_t(a)) == (b * nkr::cpp::Move(a)));
                                CHECK((value_t(a) * value_t(b)) == (nkr::cpp::Move(a) * nkr::cpp::Move(b)));
                                CHECK((value_t(b) * value_t(a)) == (nkr::cpp::Move(b) * nkr::cpp::Move(a)));
                            }
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>(value_t(1), value_t(~0));
                            other_t b = nkr::randomness::Value<integer_t>(value_t(1), value_t(~0));

                            CHECK((value_t(a) / value_t(b)) == (a / nkr::cpp::Move(b)));
                            CHECK((value_t(b) / value_t(a)) == (nkr::cpp::Move(b) / a));
                            if constexpr (nkr::cpp::any_non_const_tr<integer_t>) {
                                CHECK((value_t(a) / value_t(b)) == (nkr::cpp::Move(a) / b));
                                CHECK((value_t(b) / value_t(a)) == (b / nkr::cpp::Move(a)));
                                CHECK((value_t(a) / value_t(b)) == (nkr::cpp::Move(a) / nkr::cpp::Move(b)));
                                CHECK((value_t(b) / value_t(a)) == (nkr::cpp::Move(b) / nkr::cpp::Move(a)));
                            }
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>(value_t(1), value_t(~0));
                            other_t b = nkr::randomness::Value<integer_t>(value_t(1), value_t(~0));

                            CHECK((value_t(a) % value_t(b)) == (a % nkr::cpp::Move(b)));
                            CHECK((value_t(b) % value_t(a)) == (nkr::cpp::Move(b) % a));
                            if constexpr (nkr::cpp::any_non_const_tr<integer_t>) {
                                CHECK((value_t(a) % value_t(b)) == (nkr::cpp::Move(a) % b));
                                CHECK((value_t(b) % value_t(a)) == (b % nkr::cpp::Move(a)));
                                CHECK((value_t(a) % value_t(b)) == (nkr::cpp::Move(a) % nkr::cpp::Move(b)));
                                CHECK((value_t(b) % value_t(a)) == (nkr::cpp::Move(b) % nkr::cpp::Move(a)));
                            }
                        }
                    }
                }
            }

            TEST_CASE_TEMPLATE("unary arithmetic operators: ++, ++(int), --, --(int)", integer_p, nkr_ANY_NON_CONST)
            {
                using value_t = nkr::cpp::just_non_qualified_t<integer_p>;

                for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                    {
                        integer_p a = nkr::randomness::Value<integer_p>();
                        integer_p backup = a;

                        CHECK(value_t(backup + 1) == ++a);
                        CHECK(value_t(backup + 1) == a);
                    }
                    {
                        integer_p a = nkr::randomness::Value<integer_p>();
                        integer_p backup = a;

                        CHECK(value_t(backup + 0) == a++);
                        CHECK(value_t(backup + 1) == a);
                    }
                    {
                        integer_p a = nkr::randomness::Value<integer_p>();
                        integer_p backup = a;

                        CHECK(value_t(backup - 1) == --a);
                        CHECK(value_t(backup - 1) == a);
                    }
                    {
                        integer_p a = nkr::randomness::Value<integer_p>();
                        integer_p backup = a;

                        CHECK(value_t(backup - 0) == a--);
                        CHECK(value_t(backup - 1) == a);
                    }
                }
            }

            TEST_SUITE("binary arithmetic operators: +=, -=, *=, /=, %=")
            {
                TEST_CASE_TEMPLATE("value", tuple_p, nkr_NON_CONST_WITH_VALUE)
                {
                    using integer_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using non_qualified_t = nkr::cpp::just_non_qualified_t<integer_t>;
                    using value_t = nkr::cpp::just_non_qualified_t<integer_t>;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK(value_t(value_t(a) + value_t(b)) == (a += non_qualified_t(b)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK(value_t(value_t(a) - value_t(b)) == (a -= non_qualified_t(b)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK(value_t(value_t(a) * value_t(b)) == (a *= non_qualified_t(b)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>(value_t(1), value_t(~0));

                            CHECK(value_t(value_t(a) / value_t(b)) == (a /= non_qualified_t(b)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>(value_t(1), value_t(~0));

                            CHECK(value_t(value_t(a) % value_t(b)) == (a %= non_qualified_t(b)));
                        }
                    }
                }

                TEST_CASE_TEMPLATE("lvalue", tuple_p, nkr_NON_CONST_WITH_LVALUE)
                {
                    using integer_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using value_t = nkr::cpp::just_non_qualified_t<integer_t>;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK(value_t(value_t(a) + value_t(b)) == (a += b));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK(value_t(value_t(a) - value_t(b)) == (a -= b));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK(value_t(value_t(a) * value_t(b)) == (a *= b));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>(value_t(1), value_t(~0));

                            CHECK(value_t(value_t(a) / value_t(b)) == (a /= b));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>(value_t(1), value_t(~0));

                            CHECK(value_t(value_t(a) % value_t(b)) == (a %= b));
                        }
                    }
                }

                TEST_CASE_TEMPLATE("rvalue", tuple_p, nkr_NON_CONST_WITH_RVALUE)
                {
                    using integer_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using value_t = nkr::cpp::just_non_qualified_t<integer_t>;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK(value_t(value_t(a) + value_t(b)) == (a += nkr::cpp::Move(b)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK(value_t(value_t(a) - value_t(b)) == (a -= nkr::cpp::Move(b)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK(value_t(value_t(a) * value_t(b)) == (a *= nkr::cpp::Move(b)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>(value_t(1), value_t(~0));

                            CHECK(value_t(value_t(a) / value_t(b)) == (a /= nkr::cpp::Move(b)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>(value_t(1), value_t(~0));

                            CHECK(value_t(value_t(a) % value_t(b)) == (a %= nkr::cpp::Move(b)));
                        }
                    }
                }
            }

            TEST_CASE_TEMPLATE("unary bitwise operators: ~", integer_p, nkr_ANY)
            {
                using value_t = nkr::cpp::just_non_qualified_t<integer_p>;

                for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                    {
                        integer_p a = nkr::randomness::Value<integer_p>();

                        CHECK(~value_t(a) == ~a);
                    }
                }
            }

            TEST_SUITE("binary bitwise operators: |, &, ^, <<, >>")
            {
                TEST_CASE_TEMPLATE("value", tuple_p, nkr_ANY_WITH_VALUE)
                {
                    using integer_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using non_qualified_t = nkr::cpp::just_non_qualified_t<integer_t>;
                    using value_t = nkr::cpp::just_non_qualified_t<integer_t>;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) | value_t(b)) == (a | non_qualified_t(b)));
                            CHECK((value_t(b) | value_t(a)) == (non_qualified_t(b) | a));
                            CHECK((value_t(a) | value_t(b)) == (non_qualified_t(a) | b));
                            CHECK((value_t(b) | value_t(a)) == (b | non_qualified_t(a)));
                            CHECK((value_t(a) | value_t(b)) == (non_qualified_t(a) | non_qualified_t(b)));
                            CHECK((value_t(b) | value_t(a)) == (non_qualified_t(b) | non_qualified_t(a)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) & value_t(b)) == (a & non_qualified_t(b)));
                            CHECK((value_t(b) & value_t(a)) == (non_qualified_t(b) & a));
                            CHECK((value_t(a) & value_t(b)) == (non_qualified_t(a) & b));
                            CHECK((value_t(b) & value_t(a)) == (b & non_qualified_t(a)));
                            CHECK((value_t(a) & value_t(b)) == (non_qualified_t(a) & non_qualified_t(b)));
                            CHECK((value_t(b) & value_t(a)) == (non_qualified_t(b) & non_qualified_t(a)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) ^ value_t(b)) == (a ^ non_qualified_t(b)));
                            CHECK((value_t(b) ^ value_t(a)) == (non_qualified_t(b) ^ a));
                            CHECK((value_t(a) ^ value_t(b)) == (non_qualified_t(a) ^ b));
                            CHECK((value_t(b) ^ value_t(a)) == (b ^ non_qualified_t(a)));
                            CHECK((value_t(a) ^ value_t(b)) == (non_qualified_t(a) ^ non_qualified_t(b)));
                            CHECK((value_t(b) ^ value_t(a)) == (non_qualified_t(b) ^ non_qualified_t(a)));
                        }
                        {
                            integer_t a = Random_Shift<integer_t>();
                            other_t b = Random_Shift<integer_t>();

                            CHECK((value_t(a) << value_t(b)) == (a << non_qualified_t(b)));
                            CHECK((value_t(b) << value_t(a)) == (non_qualified_t(b) << a));
                            CHECK((value_t(a) << value_t(b)) == (non_qualified_t(a) << b));
                            CHECK((value_t(b) << value_t(a)) == (b << non_qualified_t(a)));
                            CHECK((value_t(a) << value_t(b)) == (non_qualified_t(a) << non_qualified_t(b)));
                            CHECK((value_t(b) << value_t(a)) == (non_qualified_t(b) << non_qualified_t(a)));
                        }
                        {
                            integer_t a = Random_Shift<integer_t>();
                            other_t b = Random_Shift<integer_t>();

                            CHECK((value_t(a) >> value_t(b)) == (a >> non_qualified_t(b)));
                            CHECK((value_t(b) >> value_t(a)) == (non_qualified_t(b) >> a));
                            CHECK((value_t(a) >> value_t(b)) == (non_qualified_t(a) >> b));
                            CHECK((value_t(b) >> value_t(a)) == (b >> non_qualified_t(a)));
                            CHECK((value_t(a) >> value_t(b)) == (non_qualified_t(a) >> non_qualified_t(b)));
                            CHECK((value_t(b) >> value_t(a)) == (non_qualified_t(b) >> non_qualified_t(a)));
                        }
                    }
                }

                TEST_CASE_TEMPLATE("lvalue", tuple_p, nkr_ANY_WITH_LVALUE)
                {
                    using integer_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using value_t = nkr::cpp::just_non_qualified_t<integer_t>;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) | value_t(b)) == (a | b));
                            CHECK((value_t(b) | value_t(a)) == (b | a));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) & value_t(b)) == (a & b));
                            CHECK((value_t(b) & value_t(a)) == (b & a));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) ^ value_t(b)) == (a ^ b));
                            CHECK((value_t(b) ^ value_t(a)) == (b ^ a));
                        }
                        {
                            integer_t a = Random_Shift<integer_t>();
                            other_t b = Random_Shift<integer_t>();

                            CHECK((value_t(a) << value_t(b)) == (a << b));
                            CHECK((value_t(b) << value_t(a)) == (b << a));
                        }
                        {
                            integer_t a = Random_Shift<integer_t>();
                            other_t b = Random_Shift<integer_t>();

                            CHECK((value_t(a) >> value_t(b)) == (a >> b));
                            CHECK((value_t(b) >> value_t(a)) == (b >> a));
                        }
                    }
                }

                TEST_CASE_TEMPLATE("rvalue", tuple_p, nkr_ANY_WITH_RVALUE)
                {
                    using integer_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using value_t = nkr::cpp::just_non_qualified_t<integer_t>;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) | value_t(b)) == (a | nkr::cpp::Move(b)));
                            CHECK((value_t(b) | value_t(a)) == (nkr::cpp::Move(b) | a));
                            if constexpr (nkr::cpp::any_non_const_tr<integer_t>) {
                                CHECK((value_t(a) | value_t(b)) == (nkr::cpp::Move(a) | b));
                                CHECK((value_t(b) | value_t(a)) == (b | nkr::cpp::Move(a)));
                                CHECK((value_t(a) | value_t(b)) == (nkr::cpp::Move(a) | nkr::cpp::Move(b)));
                                CHECK((value_t(b) | value_t(a)) == (nkr::cpp::Move(b) | nkr::cpp::Move(a)));
                            }
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) & value_t(b)) == (a & nkr::cpp::Move(b)));
                            CHECK((value_t(b) & value_t(a)) == (nkr::cpp::Move(b) & a));
                            if constexpr (nkr::cpp::any_non_const_tr<integer_t>) {
                                CHECK((value_t(a) & value_t(b)) == (nkr::cpp::Move(a) & b));
                                CHECK((value_t(b) & value_t(a)) == (b & nkr::cpp::Move(a)));
                                CHECK((value_t(a) & value_t(b)) == (nkr::cpp::Move(a) & nkr::cpp::Move(b)));
                                CHECK((value_t(b) & value_t(a)) == (nkr::cpp::Move(b) & nkr::cpp::Move(a)));
                            }
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK((value_t(a) ^ value_t(b)) == (a ^ nkr::cpp::Move(b)));
                            CHECK((value_t(b) ^ value_t(a)) == (nkr::cpp::Move(b) ^ a));
                            if constexpr (nkr::cpp::any_non_const_tr<integer_t>) {
                                CHECK((value_t(a) ^ value_t(b)) == (nkr::cpp::Move(a) ^ b));
                                CHECK((value_t(b) ^ value_t(a)) == (b ^ nkr::cpp::Move(a)));
                                CHECK((value_t(a) ^ value_t(b)) == (nkr::cpp::Move(a) ^ nkr::cpp::Move(b)));
                                CHECK((value_t(b) ^ value_t(a)) == (nkr::cpp::Move(b) ^ nkr::cpp::Move(a)));
                            }
                        }
                        {
                            integer_t a = Random_Shift<integer_t>();
                            other_t b = Random_Shift<integer_t>();

                            CHECK((value_t(a) << value_t(b)) == (a << nkr::cpp::Move(b)));
                            CHECK((value_t(b) << value_t(a)) == (nkr::cpp::Move(b) << a));
                            if constexpr (nkr::cpp::any_non_const_tr<integer_t>) {
                                CHECK((value_t(a) << value_t(b)) == (nkr::cpp::Move(a) << b));
                                CHECK((value_t(b) << value_t(a)) == (b << nkr::cpp::Move(a)));
                                CHECK((value_t(a) << value_t(b)) == (nkr::cpp::Move(a) << nkr::cpp::Move(b)));
                                CHECK((value_t(b) << value_t(a)) == (nkr::cpp::Move(b) << nkr::cpp::Move(a)));
                            }
                        }
                        {
                            integer_t a = Random_Shift<integer_t>();
                            other_t b = Random_Shift<integer_t>();

                            CHECK((value_t(a) >> value_t(b)) == (a >> nkr::cpp::Move(b)));
                            CHECK((value_t(b) >> value_t(a)) == (nkr::cpp::Move(b) >> a));
                            if constexpr (nkr::cpp::any_non_const_tr<integer_t>) {
                                CHECK((value_t(a) >> value_t(b)) == (nkr::cpp::Move(a) >> b));
                                CHECK((value_t(b) >> value_t(a)) == (b >> nkr::cpp::Move(a)));
                                CHECK((value_t(a) >> value_t(b)) == (nkr::cpp::Move(a) >> nkr::cpp::Move(b)));
                                CHECK((value_t(b) >> value_t(a)) == (nkr::cpp::Move(b) >> nkr::cpp::Move(a)));
                            }
                        }
                    }
                }
            }

            TEST_SUITE("binary bitwise operators: |=, &=, ^=, <<=, >>=")
            {
                TEST_CASE_TEMPLATE("value", tuple_p, nkr_NON_CONST_WITH_VALUE)
                {
                    using integer_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using non_qualified_t = nkr::cpp::just_non_qualified_t<integer_t>;
                    using value_t = nkr::cpp::just_non_qualified_t<integer_t>;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK(value_t(value_t(a) | value_t(b)) == (a |= non_qualified_t(b)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK(value_t(value_t(a) & value_t(b)) == (a &= non_qualified_t(b)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK(value_t(value_t(a) ^ value_t(b)) == (a ^= non_qualified_t(b)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = Random_Shift<integer_t>();

                            CHECK(value_t(value_t(a) << value_t(b)) == (a <<= non_qualified_t(b)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = Random_Shift<integer_t>();

                            CHECK(value_t(value_t(a) >> value_t(b)) == (a >>= non_qualified_t(b)));
                        }
                    }
                }

                TEST_CASE_TEMPLATE("lvalue", tuple_p, nkr_NON_CONST_WITH_LVALUE)
                {
                    using integer_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using value_t = nkr::cpp::just_non_qualified_t<integer_t>;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK(value_t(value_t(a) | value_t(b)) == (a |= b));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK(value_t(value_t(a) & value_t(b)) == (a &= b));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK(value_t(value_t(a) ^ value_t(b)) == (a ^= b));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = Random_Shift<integer_t>();

                            CHECK(value_t(value_t(a) << value_t(b)) == (a <<= b));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = Random_Shift<integer_t>();

                            CHECK(value_t(value_t(a) >> value_t(b)) == (a >>= b));
                        }
                    }
                }

                TEST_CASE_TEMPLATE("rvalue", tuple_p, nkr_NON_CONST_WITH_RVALUE)
                {
                    using integer_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using value_t = nkr::cpp::just_non_qualified_t<integer_t>;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK(value_t(value_t(a) | value_t(b)) == (a |= nkr::cpp::Move(b)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK(value_t(value_t(a) & value_t(b)) == (a &= nkr::cpp::Move(b)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = nkr::randomness::Value<integer_t>();

                            CHECK(value_t(value_t(a) ^ value_t(b)) == (a ^= nkr::cpp::Move(b)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = Random_Shift<integer_t>();

                            CHECK(value_t(value_t(a) << value_t(b)) == (a <<= nkr::cpp::Move(b)));
                        }
                        {
                            integer_t a = nkr::randomness::Value<integer_t>();
                            other_t b = Random_Shift<integer_t>();

                            CHECK(value_t(value_t(a) >> value_t(b)) == (a >>= nkr::cpp::Move(b)));
                        }
                    }
                }
            }

        #undef nkr_ANY_WITH_VALUE
        #undef nkr_ANY_WITH_LVALUE
        #undef nkr_ANY_WITH_RVALUE
        #undef nkr_NON_CONST_WITH_VALUE
        #undef nkr_NON_CONST_WITH_LVALUE
        #undef nkr_NON_CONST_WITH_RVALUE
        }
    }

}
