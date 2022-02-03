/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/enumeration/cpp_t.h"
#include "nkr/interface/none/value_i.h"
#include "nkr/positive/integer_t.h"
#include "nkr/tr.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::enumeration::cpp_t")
    {
        enum c_enum_e :
            nkr::positive::integer_t
        {
            A,
            B,
            C,
        };

        enum class cpp_enum_e :
            nkr::positive::integer_t
        {
            A,
            B,
            C,
        };

    #define nkr_TYPES(TYPE_QUALIFIER_p) \
        TYPE_QUALIFIER_p c_enum_e,      \
        TYPE_QUALIFIER_p cpp_enum_e     \

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

        TEST_SUITE("tr")
        {

        }

        TEST_SUITE("interface")
        {
            TEST_SUITE("should satisfy nkr::interface::none::value_i")
            {
                TEST_SUITE("directly")
                {
                    TEST_CASE_TEMPLATE("should return 0", enum_p, nkr_ANY)
                    {
                        //CHECK((nkr::interface::none::value_i<enum_p>::Value() == false));
                        //CHECK((nkr::interface::none::value_i<enum_p>::Value() == pure_p(false)));
                    }
                }

                TEST_SUITE("through nkr::none::value_t")
                {

                }
            }
        }

        TEST_SUITE("helpers")
        {
            TEST_SUITE("nkr::enumeration::cpp_value_t")
            {
                TEST_SUITE("c_enumeration"
                           * doctest::description("should return the exact integer type"))
                {
                    TEST_SUITE("unlimited")
                    {
                        TEST_SUITE("positive")
                        {
                            TEST_SUITE("8_bit")
                            {
                                enum enum_e :
                                    nkr::positive::integer_8_t
                                {
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::unlimited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::positive::integer_8_t
                                >);
                            }

                            TEST_SUITE("16_bit")
                            {
                                enum enum_e :
                                    nkr::positive::integer_16_t
                                {
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::unlimited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::positive::integer_16_t
                                >);
                            }

                            TEST_SUITE("32_bit")
                            {
                                enum enum_e :
                                    nkr::positive::integer_32_t
                                {
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::unlimited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::positive::integer_32_t
                                >);
                            }

                            TEST_SUITE("64_bit")
                            {
                                enum enum_e :
                                    nkr::positive::integer_64_t
                                {
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::unlimited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::positive::integer_64_t
                                >);
                            }
                        }

                        TEST_SUITE("negatable")
                        {
                            TEST_SUITE("8_bit")
                            {
                                enum enum_e :
                                    nkr::negatable::integer_8_t
                                {
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::unlimited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_8_t
                                >);
                            }

                            TEST_SUITE("16_bit")
                            {
                                enum enum_e :
                                    nkr::negatable::integer_16_t
                                {
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::unlimited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_16_t
                                >);
                            }

                            TEST_SUITE("32_bit")
                            {
                                enum enum_e :
                                    nkr::negatable::integer_32_t
                                {
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::unlimited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_32_t
                                >);
                            }

                            TEST_SUITE("64_bit")
                            {
                                enum enum_e :
                                    nkr::negatable::integer_64_t
                                {
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::unlimited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_64_t
                                >);
                            }
                        }
                    }

                    TEST_SUITE("limited")
                    {
                        TEST_SUITE("positive")
                        {
                            TEST_SUITE("8_bit")
                            {
                                enum enum_e :
                                    nkr::positive::integer_8_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::positive::integer_8_t>(),
                                    MAX_tg = nkr::cpp::Default_Max<nkr::positive::integer_8_t>(),
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::positive::integer_8_t
                                >);
                            }

                            TEST_SUITE("16_bit")
                            {
                                enum enum_e :
                                    nkr::positive::integer_16_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::positive::integer_16_t>(),
                                    MAX_tg = nkr::cpp::Default_Max<nkr::positive::integer_16_t>(),
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::positive::integer_16_t
                                >);
                            }

                            TEST_SUITE("32_bit")
                            {
                                enum enum_e :
                                    nkr::positive::integer_32_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::positive::integer_32_t>(),
                                    MAX_tg = nkr::cpp::Default_Max<nkr::positive::integer_32_t>(),
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::positive::integer_32_t
                                >);
                            }

                            TEST_SUITE("64_bit")
                            {
                                enum enum_e :
                                    nkr::positive::integer_64_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::positive::integer_64_t>(),
                                    MAX_tg = nkr::cpp::Default_Max<nkr::positive::integer_64_t>(),
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::positive::integer_64_t
                                >);
                            }
                        }

                        TEST_SUITE("negatable")
                        {
                            TEST_SUITE("8_bit")
                            {
                                enum enum_e :
                                    nkr::negatable::integer_8_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::negatable::integer_8_t>(),
                                    MAX_tg = nkr::cpp::Default_Max<nkr::negatable::integer_8_t>(),
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_8_t
                                >);
                            }

                            TEST_SUITE("16_bit")
                            {
                                enum enum_e :
                                    nkr::negatable::integer_16_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::negatable::integer_16_t>(),
                                    MAX_tg = nkr::cpp::Default_Max<nkr::negatable::integer_16_t>(),
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_16_t
                                >);
                            }

                            TEST_SUITE("32_bit")
                            {
                                enum enum_e :
                                    nkr::negatable::integer_32_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::negatable::integer_32_t>(),
                                    MAX_tg = nkr::cpp::Default_Max<nkr::negatable::integer_32_t>(),
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_32_t
                                >);
                            }

                            TEST_SUITE("64_bit")
                            {
                                enum enum_e :
                                    nkr::negatable::integer_64_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::negatable::integer_64_t>(),
                                    MAX_tg = nkr::cpp::Default_Max<nkr::negatable::integer_64_t>(),
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_64_t
                                >);
                            }
                        }
                    }
                }

                TEST_SUITE("cpp_enumeration")
                {
                    TEST_SUITE("unlimited"
                               * doctest::description("should return the correctly sized integer, but it's always going to be negatable"))
                    {
                        TEST_SUITE("positive")
                        {
                            TEST_SUITE("8_bit")
                            {
                                enum class enum_e :
                                    nkr::positive::integer_8_t
                                {
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::unlimited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_8_t
                                >);
                            }

                            TEST_SUITE("16_bit")
                            {
                                enum class enum_e :
                                    nkr::positive::integer_16_t
                                {
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::unlimited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_16_t
                                >);
                            }

                            TEST_SUITE("32_bit")
                            {
                                enum class enum_e :
                                    nkr::positive::integer_32_t
                                {
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::unlimited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_32_t
                                >);
                            }

                            TEST_SUITE("64_bit")
                            {
                                enum class enum_e :
                                    nkr::positive::integer_64_t
                                {
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::unlimited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_64_t
                                >);
                            }
                        }

                        TEST_SUITE("negatable")
                        {
                            TEST_SUITE("8_bit")
                            {
                                enum class enum_e :
                                    nkr::negatable::integer_8_t
                                {
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::unlimited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_8_t
                                >);
                            }

                            TEST_SUITE("16_bit")
                            {
                                enum class enum_e :
                                    nkr::negatable::integer_16_t
                                {
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::unlimited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_16_t
                                >);
                            }

                            TEST_SUITE("32_bit")
                            {
                                enum class enum_e :
                                    nkr::negatable::integer_32_t
                                {
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::unlimited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_32_t
                                >);
                            }

                            TEST_SUITE("64_bit")
                            {
                                enum class enum_e :
                                    nkr::negatable::integer_64_t
                                {
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::unlimited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_64_t
                                >);
                            }
                        }
                    }

                    TEST_SUITE("limited with a min that does not equal the max"
                               * doctest::description("should return the exact integer"))
                    {
                        TEST_SUITE("positive")
                        {
                            TEST_SUITE("8_bit")
                            {
                                enum class enum_e :
                                    nkr::positive::integer_8_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::positive::integer_8_t>(),
                                    MAX_tg = nkr::cpp::Default_Max<nkr::positive::integer_8_t>(),
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::positive::integer_8_t
                                >);
                            }

                            TEST_SUITE("16_bit")
                            {
                                enum class enum_e :
                                    nkr::positive::integer_16_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::positive::integer_16_t>(),
                                    MAX_tg = nkr::cpp::Default_Max<nkr::positive::integer_16_t>(),
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::positive::integer_16_t
                                >);
                            }

                            TEST_SUITE("32_bit")
                            {
                                enum class enum_e :
                                    nkr::positive::integer_32_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::positive::integer_32_t>(),
                                    MAX_tg = nkr::cpp::Default_Max<nkr::positive::integer_32_t>(),
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::positive::integer_32_t
                                >);
                            }

                            TEST_SUITE("64_bit")
                            {
                                enum class enum_e :
                                    nkr::positive::integer_64_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::positive::integer_64_t>(),
                                    MAX_tg = nkr::cpp::Default_Max<nkr::positive::integer_64_t>(),
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::positive::integer_64_t
                                >);
                            }
                        }

                        TEST_SUITE("negatable")
                        {
                            TEST_SUITE("8_bit")
                            {
                                enum class enum_e :
                                    nkr::negatable::integer_8_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::negatable::integer_8_t>(),
                                    MAX_tg = nkr::cpp::Default_Max<nkr::negatable::integer_8_t>(),
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_8_t
                                >);
                            }

                            TEST_SUITE("16_bit")
                            {
                                enum class enum_e :
                                    nkr::negatable::integer_16_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::negatable::integer_16_t>(),
                                    MAX_tg = nkr::cpp::Default_Max<nkr::negatable::integer_16_t>(),
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_16_t
                                >);
                            }

                            TEST_SUITE("32_bit")
                            {
                                enum class enum_e :
                                    nkr::negatable::integer_32_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::negatable::integer_32_t>(),
                                    MAX_tg = nkr::cpp::Default_Max<nkr::negatable::integer_32_t>(),
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_32_t
                                >);
                            }

                            TEST_SUITE("64_bit")
                            {
                                enum class enum_e :
                                    nkr::negatable::integer_64_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::negatable::integer_64_t>(),
                                    MAX_tg = nkr::cpp::Default_Max<nkr::negatable::integer_64_t>(),
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_64_t
                                >);
                            }
                        }
                    }

                    TEST_SUITE("limited with a min that equals the max"
                               * doctest::description("should return the correctly sized integer, but it's always going to be negatable"))
                    {
                        TEST_SUITE("positive")
                        {
                            TEST_SUITE("8_bit")
                            {
                                enum class enum_e :
                                    nkr::positive::integer_8_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::positive::integer_8_t>(),
                                    MAX_tg = MIN_tg,
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_8_t
                                >);
                            }

                            TEST_SUITE("16_bit")
                            {
                                enum class enum_e :
                                    nkr::positive::integer_16_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::positive::integer_16_t>(),
                                    MAX_tg = MIN_tg,
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_16_t
                                >);
                            }

                            TEST_SUITE("32_bit")
                            {
                                enum class enum_e :
                                    nkr::positive::integer_32_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::positive::integer_32_t>(),
                                    MAX_tg = MIN_tg,
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_32_t
                                >);
                            }

                            TEST_SUITE("64_bit")
                            {
                                enum class enum_e :
                                    nkr::positive::integer_64_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::positive::integer_64_t>(),
                                    MAX_tg = MIN_tg,
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_64_t
                                >);
                            }
                        }

                        TEST_SUITE("negatable")
                        {
                            TEST_SUITE("8_bit")
                            {
                                enum class enum_e :
                                    nkr::negatable::integer_8_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::negatable::integer_8_t>(),
                                    MAX_tg = MIN_tg,
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_8_t
                                >);
                            }

                            TEST_SUITE("16_bit")
                            {
                                enum class enum_e :
                                    nkr::negatable::integer_16_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::negatable::integer_16_t>(),
                                    MAX_tg = MIN_tg,
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_16_t
                                >);
                            }

                            TEST_SUITE("32_bit")
                            {
                                enum class enum_e :
                                    nkr::negatable::integer_32_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::negatable::integer_32_t>(),
                                    MAX_tg = MIN_tg,
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_32_t
                                >);
                            }

                            TEST_SUITE("64_bit")
                            {
                                enum class enum_e :
                                    nkr::negatable::integer_64_t
                                {
                                    MIN_tg = nkr::cpp::Default_Min<nkr::negatable::integer_64_t>(),
                                    MAX_tg = MIN_tg,
                                };
                                static_assert(nkr::generic::built_in::number::enumeration::limited_tr<enum_e>);
                                static_assert(nkr::cpp::is_tr<
                                              nkr::enumeration::cpp_value_t<enum_e>,
                                              nkr::negatable::integer_64_t
                                >);
                            }
                        }
                    }
                }
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {

            }
        }

        TEST_SUITE("casts")
        {

        }

        TEST_SUITE("global operators")
        {
            TEST_SUITE("operator ==(), operator !=()")
            {
                TEST_SUITE("non-qualified")
                {

                }

                TEST_SUITE("const")
                {

                }

                TEST_SUITE("volatile")
                {

                }

                TEST_SUITE("const volatile")
                {

                }
            }
        }
    }

}
