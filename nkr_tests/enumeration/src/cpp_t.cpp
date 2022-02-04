/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/enumeration/cpp_t.h"
#include "nkr/generic/built_in/number/enumeration/any_tr.h"
#include "nkr/generic/built_in/number/enumeration/limited_tr.h"
#include "nkr/generic/built_in/number/enumeration/unlimited_tr.h"
#include "nkr/generic/implementing/interface/none/value_tr.h"
#include "nkr/generic/implementing/interface/randomness/value_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"
#include "nkr/generic/implementing/self_tr.h"
#include "nkr/generic/number/integer_tr.h"
#include "nkr/generic/type_tr.h"
#include "nkr/interface/none/value_i.h"
#include "nkr/interface/type_i.h"
#include "nkr/none/value_t.h"
#include "nkr/positive/integer_t.h"
#include "nkr/randomness/value.h"
#include "nkr/tr.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::enumeration::cpp_t")
    {
        namespace c_positive_8_e    { enum enum_e   : nkr::positive::integer_8_t    { A, B, C, MIN_tg = A, MAX_tg = C, NONE_tg = A, }; }
        namespace c_positive_16_e   { enum enum_e   : nkr::positive::integer_16_t   { A, B, C, MIN_tg = A, MAX_tg = C, NONE_tg = A, }; }
        namespace c_positive_32_e   { enum enum_e   : nkr::positive::integer_32_t   { A, B, C, MIN_tg = A, MAX_tg = C, NONE_tg = A, }; }
        namespace c_positive_64_e   { enum enum_e   : nkr::positive::integer_64_t   { A, B, C, MIN_tg = A, MAX_tg = C, NONE_tg = A, }; }
        namespace c_negatable_8_e   { enum enum_e   : nkr::negatable::integer_8_t   { A, B, C, MIN_tg = A, MAX_tg = C, NONE_tg = A, }; }
        namespace c_negatable_16_e  { enum enum_e   : nkr::negatable::integer_16_t  { A, B, C, MIN_tg = A, MAX_tg = C, NONE_tg = A, }; }
        namespace c_negatable_32_e  { enum enum_e   : nkr::negatable::integer_32_t  { A, B, C, MIN_tg = A, MAX_tg = C, NONE_tg = A, }; }
        namespace c_negatable_64_e  { enum enum_e   : nkr::negatable::integer_64_t  { A, B, C, MIN_tg = A, MAX_tg = C, NONE_tg = A, }; }

        enum class cpp_positive_8_e     : nkr::positive::integer_8_t    { A, B, C, MIN_tg = A, MAX_tg = C, NONE_tg = A, };
        enum class cpp_positive_16_e    : nkr::positive::integer_16_t   { A, B, C, MIN_tg = A, MAX_tg = C, NONE_tg = A, };
        enum class cpp_positive_32_e    : nkr::positive::integer_32_t   { A, B, C, MIN_tg = A, MAX_tg = C, NONE_tg = A, };
        enum class cpp_positive_64_e    : nkr::positive::integer_64_t   { A, B, C, MIN_tg = A, MAX_tg = C, NONE_tg = A, };
        enum class cpp_negatable_8_e    : nkr::negatable::integer_8_t   { A, B, C, MIN_tg = A, MAX_tg = C, NONE_tg = A, };
        enum class cpp_negatable_16_e   : nkr::negatable::integer_16_t  { A, B, C, MIN_tg = A, MAX_tg = C, NONE_tg = A, };
        enum class cpp_negatable_32_e   : nkr::negatable::integer_32_t  { A, B, C, MIN_tg = A, MAX_tg = C, NONE_tg = A, };
        enum class cpp_negatable_64_e   : nkr::negatable::integer_64_t  { A, B, C, MIN_tg = A, MAX_tg = C, NONE_tg = A, };

    #define nkr_INTEGERS(TYPE_QUALIFIER_p)              \
        TYPE_QUALIFIER_p nkr::positive::integer_8_t,    \
        TYPE_QUALIFIER_p nkr::positive::integer_16_t,   \
        TYPE_QUALIFIER_p nkr::positive::integer_32_t,   \
        TYPE_QUALIFIER_p nkr::positive::integer_64_t,   \
        TYPE_QUALIFIER_p nkr::negatable::integer_8_t,   \
        TYPE_QUALIFIER_p nkr::negatable::integer_16_t,  \
        TYPE_QUALIFIER_p nkr::negatable::integer_32_t,  \
        TYPE_QUALIFIER_p nkr::negatable::integer_64_t   \

    #define nkr_TYPES(TYPE_QUALIFIER_p)             \
        TYPE_QUALIFIER_p c_positive_8_e::enum_e,    \
        TYPE_QUALIFIER_p c_positive_16_e::enum_e,   \
        TYPE_QUALIFIER_p c_positive_32_e::enum_e,   \
        TYPE_QUALIFIER_p c_positive_64_e::enum_e,   \
        TYPE_QUALIFIER_p c_negatable_8_e::enum_e,   \
        TYPE_QUALIFIER_p c_negatable_16_e::enum_e,  \
        TYPE_QUALIFIER_p c_negatable_32_e::enum_e,  \
        TYPE_QUALIFIER_p c_negatable_64_e::enum_e,  \
                                                    \
        TYPE_QUALIFIER_p cpp_positive_8_e,          \
        TYPE_QUALIFIER_p cpp_positive_16_e,         \
        TYPE_QUALIFIER_p cpp_positive_32_e,         \
        TYPE_QUALIFIER_p cpp_positive_64_e,         \
        TYPE_QUALIFIER_p cpp_negatable_8_e,         \
        TYPE_QUALIFIER_p cpp_negatable_16_e,        \
        TYPE_QUALIFIER_p cpp_negatable_32_e,        \
        TYPE_QUALIFIER_p cpp_negatable_64_e         \

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

        TEST_CASE("tr")
        {
            using target_ts = ts<AND_tg,
                nkr::enumeration::cpp_tg,

                nkr::generic::built_in::number::enumeration::any_tg,
                nkr::generic::built_in::number::enumeration::limited_tg
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

            static_assert(TR<to_ts<AND_tg, any_ts>, any_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, any_ts>, any_tg, non_target_ts>());
            static_assert(TR<to_ts<NOR_tg, other_ts>, any_tg, target_ts>());

            static_assert(TR<to_ts<AND_tg, any_qualified_ts>, any_qualified_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, any_non_qualified_ts>, any_qualified_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, any_ts>, any_qualified_tg, non_target_ts>());
            static_assert(TR<to_ts<NOR_tg, other_ts>, any_qualified_tg, target_ts>());

            static_assert(TR<to_ts<AND_tg, any_non_qualified_ts>, any_non_qualified_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, any_qualified_ts>, any_non_qualified_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, any_ts>, any_non_qualified_tg, non_target_ts>());
            static_assert(TR<to_ts<NOR_tg, other_ts>, any_non_qualified_tg, target_ts>());

            static_assert(TR<to_ts<AND_tg, any_const_ts>, any_const_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, any_non_const_ts>, any_const_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, any_ts>, any_const_tg, non_target_ts>());
            static_assert(TR<to_ts<NOR_tg, other_ts>, any_const_tg, target_ts>());

            static_assert(TR<to_ts<AND_tg, any_non_const_ts>, any_non_const_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, any_const_ts>, any_non_const_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, any_ts>, any_non_const_tg, non_target_ts>());
            static_assert(TR<to_ts<NOR_tg, other_ts>, any_non_const_tg, target_ts>());

            static_assert(TR<to_ts<AND_tg, any_volatile_ts>, any_volatile_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, any_non_volatile_ts>, any_volatile_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, any_ts>, any_volatile_tg, non_target_ts>());
            static_assert(TR<to_ts<NOR_tg, other_ts>, any_volatile_tg, target_ts>());

            static_assert(TR<to_ts<AND_tg, any_non_volatile_ts>, any_non_volatile_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, any_volatile_ts>, any_non_volatile_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, any_ts>, any_non_volatile_tg, non_target_ts>());
            static_assert(TR<to_ts<NOR_tg, other_ts>, any_non_volatile_tg, target_ts>());

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
            static_assert(TR<to_ts<NOR_tg, other_ts>, just_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, other_ts>, just_tg, const target_ts>());
            static_assert(TR<to_ts<NOR_tg, other_ts>, just_tg, volatile target_ts>());
            static_assert(TR<to_ts<NOR_tg, other_ts>, just_tg, const volatile target_ts>());

            static_assert(TR<to_ts<AND_tg, just_non_qualified_ts>, just_non_qualified_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, any_not_just_non_qualified_ts>, just_non_qualified_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, any_ts>, just_non_qualified_tg, non_target_ts>());
            static_assert(TR<to_ts<NOR_tg, other_ts>, just_non_qualified_tg, target_ts>());

            static_assert(TR<to_ts<AND_tg, just_const_ts>, just_const_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, any_not_just_const_ts>, just_const_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, any_ts>, just_const_tg, non_target_ts>());
            static_assert(TR<to_ts<NOR_tg, other_ts>, just_const_tg, target_ts>());

            static_assert(TR<to_ts<AND_tg, just_volatile_ts>, just_volatile_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, any_not_just_volatile_ts>, just_volatile_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, any_ts>, just_volatile_tg, non_target_ts>());
            static_assert(TR<to_ts<NOR_tg, other_ts>, just_volatile_tg, target_ts>());

            static_assert(TR<to_ts<AND_tg, just_const_volatile_ts>, just_const_volatile_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, any_not_just_const_volatile_ts>, just_const_volatile_tg, target_ts>());
            static_assert(TR<to_ts<NOR_tg, any_ts>, just_const_volatile_tg, non_target_ts>());
            static_assert(TR<to_ts<NOR_tg, other_ts>, just_const_volatile_tg, target_ts>());

            static_assert(TR<to_ts<NOR_tg, any_ts>, not_any_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, any_ts>, not_any_tg, non_target_ts>());
            static_assert(TR<to_ts<AND_tg, other_ts>, not_any_tg, target_ts>());

            static_assert(TR<to_ts<NOR_tg, any_qualified_ts>, not_any_qualified_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, any_non_qualified_ts>, not_any_qualified_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, any_ts>, not_any_qualified_tg, non_target_ts>());
            static_assert(TR<to_ts<AND_tg, other_ts>, not_any_qualified_tg, target_ts>());

            static_assert(TR<to_ts<NOR_tg, any_non_qualified_ts>, not_any_non_qualified_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, any_qualified_ts>, not_any_non_qualified_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, any_ts>, not_any_non_qualified_tg, non_target_ts>());
            static_assert(TR<to_ts<AND_tg, other_ts>, not_any_non_qualified_tg, target_ts>());

            static_assert(TR<to_ts<NOR_tg, any_const_ts>, not_any_const_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, any_non_const_ts>, not_any_const_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, any_ts>, not_any_const_tg, non_target_ts>());
            static_assert(TR<to_ts<AND_tg, other_ts>, not_any_const_tg, target_ts>());

            static_assert(TR<to_ts<NOR_tg, any_non_const_ts>, not_any_non_const_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, any_const_ts>, not_any_non_const_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, any_ts>, not_any_non_const_tg, non_target_ts>());
            static_assert(TR<to_ts<AND_tg, other_ts>, not_any_non_const_tg, target_ts>());

            static_assert(TR<to_ts<NOR_tg, any_volatile_ts>, not_any_volatile_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, any_non_volatile_ts>, not_any_volatile_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, any_ts>, not_any_volatile_tg, non_target_ts>());
            static_assert(TR<to_ts<AND_tg, other_ts>, not_any_volatile_tg, target_ts>());

            static_assert(TR<to_ts<NOR_tg, any_non_volatile_ts>, not_any_non_volatile_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, any_volatile_ts>, not_any_non_volatile_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, any_ts>, not_any_non_volatile_tg, non_target_ts>());
            static_assert(TR<to_ts<AND_tg, other_ts>, not_any_non_volatile_tg, target_ts>());

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
            static_assert(TR<to_ts<AND_tg, other_ts>, just_not_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, other_ts>, just_not_tg, const target_ts>());
            static_assert(TR<to_ts<AND_tg, other_ts>, just_not_tg, volatile target_ts>());
            static_assert(TR<to_ts<AND_tg, other_ts>, just_not_tg, const volatile target_ts>());

            static_assert(TR<to_ts<NOR_tg, just_non_qualified_ts>, just_not_non_qualified_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, any_not_just_non_qualified_ts>, just_not_non_qualified_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, any_ts>, just_not_non_qualified_tg, non_target_ts>());
            static_assert(TR<to_ts<AND_tg, other_ts>, just_not_non_qualified_tg, target_ts>());

            static_assert(TR<to_ts<NOR_tg, just_const_ts>, just_not_const_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, any_not_just_const_ts>, just_not_const_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, any_ts>, just_not_const_tg, non_target_ts>());
            static_assert(TR<to_ts<AND_tg, other_ts>, just_not_const_tg, target_ts>());

            static_assert(TR<to_ts<NOR_tg, just_volatile_ts>, just_not_volatile_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, any_not_just_volatile_ts>, just_not_volatile_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, any_ts>, just_not_volatile_tg, non_target_ts>());
            static_assert(TR<to_ts<AND_tg, other_ts>, just_not_volatile_tg, target_ts>());

            static_assert(TR<to_ts<NOR_tg, just_const_volatile_ts>, just_not_const_volatile_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, any_not_just_const_volatile_ts>, just_not_const_volatile_tg, target_ts>());
            static_assert(TR<to_ts<AND_tg, any_ts>, just_not_const_volatile_tg, non_target_ts>());
            static_assert(TR<to_ts<AND_tg, other_ts>, just_not_const_volatile_tg, target_ts>());
        }

        TEST_SUITE("interface")
        {
            TEST_SUITE("nkr::interface::none::value_i")
            {
                TEST_SUITE("direct")
                {
                    TEST_SUITE("default"
                               * doctest::description("should return ~0"))
                    {
                        TEST_CASE_TEMPLATE("c_enumeration", integer_p, nkr_INTEGERS(nkr_BLANK))
                        {
                            enum enum_e :
                                integer_p
                            {
                            };

                            static_assert(nkr::interface::none::value_i<enum_e>::Value() == integer_p(~0));
                            static_assert(nkr::interface::none::value_i<enum_e>::Value() == enum_e(~0));
                        }

                        TEST_CASE_TEMPLATE("cpp_enumeration", integer_p, nkr_INTEGERS(nkr_BLANK))
                        {
                            enum class enum_e :
                                integer_p
                            {
                            };

                            static_assert(nkr::interface::none::value_i<enum_e>::Value() == enum_e(~0));
                        }
                    }

                    TEST_SUITE("with NONE_tg"
                               * doctest::description("should return NONE_tg"))
                    {
                        TEST_CASE_TEMPLATE("c_enumeration", integer_p, nkr_INTEGERS(nkr_BLANK))
                        {
                            enum enum_e :
                                integer_p
                            {
                                NONE_tg = 0,
                            };

                            static_assert(nkr::interface::none::value_i<enum_e>::Value() == integer_p(0));
                            static_assert(nkr::interface::none::value_i<enum_e>::Value() == enum_e(0));
                            static_assert(nkr::interface::none::value_i<enum_e>::Value() == enum_e::NONE_tg);
                        }

                        TEST_CASE_TEMPLATE("cpp_enumeration", integer_p, nkr_INTEGERS(nkr_BLANK))
                        {
                            enum class enum_e :
                                integer_p
                            {
                                NONE_tg = 0,
                            };

                            static_assert(nkr::interface::none::value_i<enum_e>::Value() == enum_e(0));
                            static_assert(nkr::interface::none::value_i<enum_e>::Value() == enum_e::NONE_tg);
                        }
                    }
                }

                TEST_SUITE("through nkr::none::value_t")
                {
                    TEST_SUITE("default"
                               * doctest::description("should return ~0"))
                    {
                        TEST_CASE_TEMPLATE("c_enumeration", integer_p, nkr_INTEGERS(nkr_BLANK))
                        {
                            enum enum_e :
                                integer_p
                            {
                            };

                            static_assert(nkr::none::value_t<enum_e>() == integer_p(~0));
                            static_assert(nkr::none::value_t<enum_e>() == enum_e(~0));
                        }

                        TEST_CASE_TEMPLATE("cpp_enumeration", integer_p, nkr_INTEGERS(nkr_BLANK))
                        {
                            enum class enum_e :
                                integer_p
                            {
                            };

                            static_assert(nkr::none::value_t<enum_e>() == enum_e(~0));
                        }
                    }

                    TEST_SUITE("with NONE_tg"
                               * doctest::description("should return NONE_tg"))
                    {
                        TEST_CASE_TEMPLATE("c_enumeration", integer_p, nkr_INTEGERS(nkr_BLANK))
                        {
                            enum enum_e :
                                integer_p
                            {
                                NONE_tg = 0,
                            };

                            static_assert(nkr::none::value_t<enum_e>() == integer_p(0));
                            static_assert(nkr::none::value_t<enum_e>() == enum_e(0));
                            static_assert(nkr::none::value_t<enum_e>() == enum_e::NONE_tg);
                        }

                        TEST_CASE_TEMPLATE("cpp_enumeration", integer_p, nkr_INTEGERS(nkr_BLANK))
                        {
                            enum class enum_e :
                                integer_p
                            {
                                NONE_tg = 0,
                            };

                            static_assert(nkr::none::value_t<enum_e>() == enum_e(0));
                            static_assert(nkr::none::value_t<enum_e>() == enum_e::NONE_tg);
                        }
                    }
                }
            }

            TEST_CASE_TEMPLATE("nkr::interface::type_i", enum_p, nkr_ANY)
            {
                static_assert(nkr::cpp::is_tr<typename nkr::interface::type_i<enum_p>::type_t, enum_p>);
                static_assert(nkr::cpp::is_tr<typename nkr::interface::type_i<enum_p>::of_t, nkr::enumeration::cpp_value_t<enum_p>>);

                static_assert(nkr::interface::type_i<enum_p>::template Is_Any<nkr::cpp::just_non_qualified_t<enum_p>>());
                static_assert(nkr::interface::type_i<enum_p>::template Is_Any<nkr::cpp::just_const_t<enum_p>>());
                static_assert(nkr::interface::type_i<enum_p>::template Is_Any<nkr::cpp::just_volatile_t<enum_p>>());
                static_assert(nkr::interface::type_i<enum_p>::template Is_Any<nkr::cpp::just_const_volatile_t<enum_p>>());
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
            TEST_SUITE("manual_default_constructor()")
            {
                TEST_CASE_TEMPLATE("should set its value to 0", enumeration_p, nkr_ANY)
                {
                    enumeration_p enumeration = nkr::cpp::just_non_qualified_t<enumeration_p>();

                    CHECK((enumeration == nkr::cpp::just_non_qualified_t<enumeration_p>(0)));
                }
            }

            TEST_SUITE("copy_ctor()"
                       * doctest::description("should copy other without changing it"))
            {
                TEST_CASE_TEMPLATE("non-qualified", enumeration_p, nkr_ANY)
                {
                    nkr::cpp::just_non_qualified_t<enumeration_p> other = nkr::randomness::Value<enumeration_p>();
                    enumeration_p enumeration = other;

                    CHECK((enumeration == other));
                }

                TEST_CASE_TEMPLATE("const", enumeration_p, nkr_ANY)
                {
                    nkr::cpp::just_const_t<enumeration_p> other = nkr::randomness::Value<enumeration_p>();
                    enumeration_p enumeration = other;

                    CHECK((enumeration == other));
                }

                TEST_CASE_TEMPLATE("volatile", enumeration_p, nkr_ANY)
                {
                    nkr::cpp::just_volatile_t<enumeration_p> other = nkr::randomness::Value<enumeration_p>();
                    enumeration_p enumeration = other;

                    CHECK((enumeration == other));
                }

                TEST_CASE_TEMPLATE("const volatile", enumeration_p, nkr_ANY)
                {
                    nkr::cpp::just_const_volatile_t<enumeration_p> other = nkr::randomness::Value<enumeration_p>();
                    enumeration_p enumeration = other;

                    CHECK((enumeration == other));
                }
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
