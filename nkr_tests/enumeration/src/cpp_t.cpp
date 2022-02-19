/*
    Copyright 2022 r-neal-kelly
*/

#pragma warning (disable : 26812)

#include "nkr/enumeration/cpp_t.h"
#include "nkr/generic/built_in/number/enumeration/any_tr.h"
#include "nkr/generic/built_in/number/enumeration/limited_tr.h"
#include "nkr/generic/built_in/number/enumeration/unlimited_tr.h"
#include "nkr/generic/implementing/interface/none/value_tr.h"
#include "nkr/generic/implementing/interface/randomness/value_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"
#include "nkr/generic/implementing/self_tr.h"
#include "nkr/generic/negatable_tr.h"
#include "nkr/generic/number/integer_tr.h"
#include "nkr/generic/type_tr.h"
#include "nkr/interface/none/value_i.h"
#include "nkr/interface/type_i.h"
#include "nkr/negatable/integer_t.h"
#include "nkr/none/value_t.h"
#include "nkr/positive/index_t.h"
#include "nkr/positive/integer_t.h"
#include "nkr/randomness/generator/software/default_t.h"
#include "nkr/randomness/value.h"
#include "nkr/tr.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::enumeration::cpp_t")
    {
        namespace c_positive_8_e    { enum enum_e   : nkr::positive::integer_8_t    { NONE_tg, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, MIN_tg = NONE_tg, MAX_tg = Z, }; }
        namespace c_positive_16_e   { enum enum_e   : nkr::positive::integer_16_t   { NONE_tg, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, MIN_tg = NONE_tg, MAX_tg = Z, }; }
        namespace c_positive_32_e   { enum enum_e   : nkr::positive::integer_32_t   { NONE_tg, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, MIN_tg = NONE_tg, MAX_tg = Z, }; }
        namespace c_positive_64_e   { enum enum_e   : nkr::positive::integer_64_t   { NONE_tg, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, MIN_tg = NONE_tg, MAX_tg = Z, }; }
        namespace c_negatable_8_e   { enum enum_e   : nkr::negatable::integer_8_t   { NONE_tg, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, MIN_tg = NONE_tg, MAX_tg = Z, }; }
        namespace c_negatable_16_e  { enum enum_e   : nkr::negatable::integer_16_t  { NONE_tg, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, MIN_tg = NONE_tg, MAX_tg = Z, }; }
        namespace c_negatable_32_e  { enum enum_e   : nkr::negatable::integer_32_t  { NONE_tg, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, MIN_tg = NONE_tg, MAX_tg = Z, }; }
        namespace c_negatable_64_e  { enum enum_e   : nkr::negatable::integer_64_t  { NONE_tg, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, MIN_tg = NONE_tg, MAX_tg = Z, }; }

        enum class cpp_positive_8_e     : nkr::positive::integer_8_t    { NONE_tg, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, MIN_tg = NONE_tg, MAX_tg = Z, };
        enum class cpp_positive_16_e    : nkr::positive::integer_16_t   { NONE_tg, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, MIN_tg = NONE_tg, MAX_tg = Z, };
        enum class cpp_positive_32_e    : nkr::positive::integer_32_t   { NONE_tg, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, MIN_tg = NONE_tg, MAX_tg = Z, };
        enum class cpp_positive_64_e    : nkr::positive::integer_64_t   { NONE_tg, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, MIN_tg = NONE_tg, MAX_tg = Z, };
        enum class cpp_negatable_8_e    : nkr::negatable::integer_8_t   { NONE_tg, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, MIN_tg = NONE_tg, MAX_tg = Z, };
        enum class cpp_negatable_16_e   : nkr::negatable::integer_16_t  { NONE_tg, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, MIN_tg = NONE_tg, MAX_tg = Z, };
        enum class cpp_negatable_32_e   : nkr::negatable::integer_32_t  { NONE_tg, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, MIN_tg = NONE_tg, MAX_tg = Z, };
        enum class cpp_negatable_64_e   : nkr::negatable::integer_64_t  { NONE_tg, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, MIN_tg = NONE_tg, MAX_tg = Z, };

    #define nkr_INTEGERS(TYPE_QUALIFIER_p)              \
        TYPE_QUALIFIER_p nkr::positive::integer_8_t,    \
        TYPE_QUALIFIER_p nkr::positive::integer_16_t,   \
        TYPE_QUALIFIER_p nkr::positive::integer_32_t,   \
        TYPE_QUALIFIER_p nkr::positive::integer_64_t,   \
        TYPE_QUALIFIER_p nkr::negatable::integer_8_t,   \
        TYPE_QUALIFIER_p nkr::negatable::integer_16_t,  \
        TYPE_QUALIFIER_p nkr::negatable::integer_32_t,  \
        TYPE_QUALIFIER_p nkr::negatable::integer_64_t   \

    #define nkr_TYPES_C(TYPE_QUALIFIER_p)           \
        TYPE_QUALIFIER_p c_positive_8_e::enum_e,    \
        TYPE_QUALIFIER_p c_positive_16_e::enum_e,   \
        TYPE_QUALIFIER_p c_positive_32_e::enum_e,   \
        TYPE_QUALIFIER_p c_positive_64_e::enum_e,   \
        TYPE_QUALIFIER_p c_negatable_8_e::enum_e,   \
        TYPE_QUALIFIER_p c_negatable_16_e::enum_e,  \
        TYPE_QUALIFIER_p c_negatable_32_e::enum_e,  \
        TYPE_QUALIFIER_p c_negatable_64_e::enum_e   \

    #define nkr_JUST_NON_QUALIFIED_C    \
        nkr_TYPES_C(nkr_BLANK)          \

    #define nkr_JUST_CONST_C    \
        nkr_TYPES_C(const)      \

    #define nkr_JUST_VOLATILE_C \
        nkr_TYPES_C(volatile)   \

    #define nkr_JUST_CONST_VOLATILE_C   \
        nkr_TYPES_C(const volatile)     \

    #define nkr_ANY_C               \
        nkr_JUST_NON_QUALIFIED_C,   \
        nkr_JUST_CONST_C,           \
        nkr_JUST_VOLATILE_C,        \
        nkr_JUST_CONST_VOLATILE_C   \

    #define nkr_ANY_QUALIFIED_C     \
        nkr_JUST_CONST_C,           \
        nkr_JUST_VOLATILE_C,        \
        nkr_JUST_CONST_VOLATILE_C   \

    #define nkr_ANY_NON_QUALIFIED_C \
        nkr_JUST_NON_QUALIFIED_C    \

    #define nkr_ANY_CONST_C         \
        nkr_JUST_CONST_C,           \
        nkr_JUST_CONST_VOLATILE_C   \

    #define nkr_ANY_NON_CONST_C     \
        nkr_JUST_NON_QUALIFIED_C,   \
        nkr_JUST_VOLATILE_C         \

    #define nkr_ANY_VOLATILE_C      \
        nkr_JUST_VOLATILE_C,        \
        nkr_JUST_CONST_VOLATILE_C   \

    #define nkr_ANY_NON_VOLATILE_C  \
        nkr_JUST_NON_QUALIFIED_C,   \
        nkr_JUST_CONST_C            \

    #define nkr_ANY_NOT_JUST_NON_QUALIFIED_C    \
        nkr_JUST_CONST_C,                       \
        nkr_JUST_VOLATILE_C,                    \
        nkr_JUST_CONST_VOLATILE_C               \

    #define nkr_ANY_NOT_JUST_CONST_C    \
        nkr_JUST_NON_QUALIFIED_C,       \
        nkr_JUST_VOLATILE_C,            \
        nkr_JUST_CONST_VOLATILE_C       \

    #define nkr_ANY_NOT_JUST_VOLATILE_C \
        nkr_JUST_NON_QUALIFIED_C,       \
        nkr_JUST_CONST_C,               \
        nkr_JUST_CONST_VOLATILE_C       \

    #define nkr_ANY_NOT_JUST_CONST_VOLATILE_C   \
        nkr_JUST_NON_QUALIFIED_C,               \
        nkr_JUST_CONST_C,                       \
        nkr_JUST_VOLATILE_C                     \

    #define nkr_TYPES_CPP(TYPE_QUALIFIER_p)     \
        TYPE_QUALIFIER_p cpp_positive_8_e,      \
        TYPE_QUALIFIER_p cpp_positive_16_e,     \
        TYPE_QUALIFIER_p cpp_positive_32_e,     \
        TYPE_QUALIFIER_p cpp_positive_64_e,     \
        TYPE_QUALIFIER_p cpp_negatable_8_e,     \
        TYPE_QUALIFIER_p cpp_negatable_16_e,    \
        TYPE_QUALIFIER_p cpp_negatable_32_e,    \
        TYPE_QUALIFIER_p cpp_negatable_64_e     \

        #define nkr_JUST_NON_QUALIFIED_CPP  \
        nkr_TYPES_CPP(nkr_BLANK)            \

    #define nkr_JUST_CONST_CPP  \
        nkr_TYPES_CPP(const)    \

    #define nkr_JUST_VOLATILE_CPP   \
        nkr_TYPES_CPP(volatile)     \

    #define nkr_JUST_CONST_VOLATILE_CPP \
        nkr_TYPES_CPP(const volatile)   \

    #define nkr_ANY_CPP             \
        nkr_JUST_NON_QUALIFIED_CPP, \
        nkr_JUST_CONST_CPP,         \
        nkr_JUST_VOLATILE_CPP,      \
        nkr_JUST_CONST_VOLATILE_CPP \

    #define nkr_ANY_QUALIFIED_CPP   \
        nkr_JUST_CONST_CPP,         \
        nkr_JUST_VOLATILE_CPP,      \
        nkr_JUST_CONST_VOLATILE_CPP \

    #define nkr_ANY_NON_QUALIFIED_CPP   \
        nkr_JUST_NON_QUALIFIED_CPP      \

    #define nkr_ANY_CONST_CPP       \
        nkr_JUST_CONST_CPP,         \
        nkr_JUST_CONST_VOLATILE_CPP \

    #define nkr_ANY_NON_CONST_CPP   \
        nkr_JUST_NON_QUALIFIED_CPP, \
        nkr_JUST_VOLATILE_CPP       \

    #define nkr_ANY_VOLATILE_CPP    \
        nkr_JUST_VOLATILE_CPP,      \
        nkr_JUST_CONST_VOLATILE_CPP \

    #define nkr_ANY_NON_VOLATILE_CPP    \
        nkr_JUST_NON_QUALIFIED_CPP,     \
        nkr_JUST_CONST_CPP              \

    #define nkr_ANY_NOT_JUST_NON_QUALIFIED_CPP  \
        nkr_JUST_CONST_CPP,                     \
        nkr_JUST_VOLATILE_CPP,                  \
        nkr_JUST_CONST_VOLATILE_CPP             \

    #define nkr_ANY_NOT_JUST_CONST_CPP  \
        nkr_JUST_NON_QUALIFIED_CPP,     \
        nkr_JUST_VOLATILE_CPP,          \
        nkr_JUST_CONST_VOLATILE_CPP     \

    #define nkr_ANY_NOT_JUST_VOLATILE_CPP   \
        nkr_JUST_NON_QUALIFIED_CPP,         \
        nkr_JUST_CONST_CPP,                 \
        nkr_JUST_CONST_VOLATILE_CPP         \

    #define nkr_ANY_NOT_JUST_CONST_VOLATILE_CPP \
        nkr_JUST_NON_QUALIFIED_CPP,             \
        nkr_JUST_CONST_CPP,                     \
        nkr_JUST_VOLATILE_CPP                   \

    #define nkr_TYPES(TYPE_QUALIFIER_p) \
        nkr_TYPES_C(TYPE_QUALIFIER_p),  \
        nkr_TYPES_CPP(TYPE_QUALIFIER_p) \

    #define nkr_JUST_NON_QUALIFIED  \
        nkr_TYPES_C(nkr_BLANK),     \
        nkr_TYPES_CPP(nkr_BLANK)    \

    #define nkr_JUST_CONST      \
        nkr_TYPES_C(const),     \
        nkr_TYPES_CPP(const)    \

    #define nkr_JUST_VOLATILE   \
        nkr_TYPES_C(volatile),  \
        nkr_TYPES_CPP(volatile) \

    #define nkr_JUST_CONST_VOLATILE     \
        nkr_TYPES_C(const volatile),    \
        nkr_TYPES_CPP(const volatile)   \

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
            Default_Iteration_Count()
            noexcept
        {
            return 128;
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

            TEST_SUITE("nkr::interface::randomness::value_i")
            {
                TEST_SUITE("direct")
                {
                    TEST_SUITE("with default parameters")
                    {
                        TEST_CASE_TEMPLATE("should return any value from MIN_tg to MAX_tg", enumeration_p, nkr_ANY)
                        {
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                enumeration_p enumeration =
                                    nkr::interface::randomness::value_i<enumeration_p>::template Value<>();

                                CHECK(enumeration >= enumeration_p::MIN_tg);
                                CHECK(enumeration <= enumeration_p::MAX_tg);
                            }
                        }

                        TEST_CASE_TEMPLATE("should return any value from MIN_tg to MAX_tg with a given generator", enumeration_p, nkr_ANY)
                        {
                            auto generator_lockee = nkr::randomness::generator::software::Default();
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                enumeration_p enumeration =
                                    nkr::interface::randomness::value_i<enumeration_p>::template Value<>(generator_lockee.Value());

                                CHECK(enumeration >= enumeration_p::MIN_tg);
                                CHECK(enumeration <= enumeration_p::MAX_tg);
                            }
                        }
                    }

                    TEST_SUITE("with min and max")
                    {
                        TEST_CASE_TEMPLATE("should return any value from the given min to the given max", enumeration_p, nkr_ANY)
                        {
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::cpp::just_non_qualified_t<enumeration_p> constraint_a =
                                    nkr::interface::randomness::value_i<enumeration_p>::template Value<>();
                                nkr::cpp::just_non_qualified_t<enumeration_p> constraint_b =
                                    nkr::interface::randomness::value_i<enumeration_p>::template Value<>();

                                if (constraint_a < constraint_b) {
                                    enumeration_p enumeration =
                                        nkr::interface::randomness::value_i<enumeration_p>::template Value<>(constraint_a, constraint_b);

                                    CHECK(enumeration >= constraint_a);
                                    CHECK(enumeration <= constraint_b);
                                } else {
                                    enumeration_p enumeration =
                                        nkr::interface::randomness::value_i<enumeration_p>::template Value<>(constraint_b, constraint_a);

                                    CHECK(enumeration >= constraint_b);
                                    CHECK(enumeration <= constraint_a);
                                }
                            }
                        }

                        TEST_CASE_TEMPLATE("should return any value from the given min to the given max with a given generator", enumeration_p, nkr_ANY)
                        {
                            auto generator_lockee = nkr::randomness::generator::software::Default();
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::cpp::just_non_qualified_t<enumeration_p> constraint_a =
                                    nkr::interface::randomness::value_i<enumeration_p>::template Value<>(generator_lockee.Value());
                                nkr::cpp::just_non_qualified_t<enumeration_p> constraint_b =
                                    nkr::interface::randomness::value_i<enumeration_p>::template Value<>(generator_lockee.Value());

                                if (constraint_a < constraint_b) {
                                    enumeration_p enumeration =
                                        nkr::interface::randomness::value_i<enumeration_p>::template Value<>(generator_lockee.Value(), constraint_a, constraint_b);

                                    CHECK(enumeration >= constraint_a);
                                    CHECK(enumeration <= constraint_b);
                                } else {
                                    enumeration_p enumeration =
                                        nkr::interface::randomness::value_i<enumeration_p>::template Value<>(generator_lockee.Value(), constraint_b, constraint_a);

                                    CHECK(enumeration >= constraint_b);
                                    CHECK(enumeration <= constraint_a);
                                }
                            }
                        }
                    }
                }

                TEST_SUITE("through nkr::randomness::Value<>()")
                {
                    TEST_SUITE("with default parameters")
                    {
                        TEST_CASE_TEMPLATE("should return any value from MIN_tg to MAX_tg", enumeration_p, nkr_ANY)
                        {
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                enumeration_p enumeration =
                                    nkr::randomness::Value<enumeration_p>();

                                CHECK(enumeration >= enumeration_p::MIN_tg);
                                CHECK(enumeration <= enumeration_p::MAX_tg);
                            }
                        }

                        TEST_CASE_TEMPLATE("should return any value from MIN_tg to MAX_tg with a given generator", enumeration_p, nkr_ANY)
                        {
                            auto generator_lockee = nkr::randomness::generator::software::Default();
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                enumeration_p enumeration =
                                    nkr::randomness::Value<enumeration_p>(generator_lockee.Value());

                                CHECK(enumeration >= enumeration_p::MIN_tg);
                                CHECK(enumeration <= enumeration_p::MAX_tg);
                            }
                        }
                    }

                    TEST_SUITE("with min and max")
                    {
                        TEST_CASE_TEMPLATE("should return any value from the given min to the given max", enumeration_p, nkr_ANY)
                        {
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::cpp::just_non_qualified_t<enumeration_p> constraint_a =
                                    nkr::randomness::Value<enumeration_p>();
                                nkr::cpp::just_non_qualified_t<enumeration_p> constraint_b =
                                    nkr::randomness::Value<enumeration_p>();

                                if (constraint_a < constraint_b) {
                                    enumeration_p enumeration =
                                        nkr::randomness::Value<enumeration_p>(constraint_a, constraint_b);

                                    CHECK(enumeration >= constraint_a);
                                    CHECK(enumeration <= constraint_b);
                                } else {
                                    enumeration_p enumeration =
                                        nkr::randomness::Value<enumeration_p>(constraint_b, constraint_a);

                                    CHECK(enumeration >= constraint_b);
                                    CHECK(enumeration <= constraint_a);
                                }
                            }
                        }

                        TEST_CASE_TEMPLATE("should return any value from the given min to the given max with a given generator", enumeration_p, nkr_ANY)
                        {
                            auto generator_lockee = nkr::randomness::generator::software::Default();
                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                nkr::cpp::just_non_qualified_t<enumeration_p> constraint_a =
                                    nkr::randomness::Value<enumeration_p>(generator_lockee.Value());
                                nkr::cpp::just_non_qualified_t<enumeration_p> constraint_b =
                                    nkr::randomness::Value<enumeration_p>(generator_lockee.Value());

                                if (constraint_a < constraint_b) {
                                    enumeration_p enumeration =
                                        nkr::randomness::Value<enumeration_p>(generator_lockee.Value(), constraint_a, constraint_b);

                                    CHECK(enumeration >= constraint_a);
                                    CHECK(enumeration <= constraint_b);
                                } else {
                                    enumeration_p enumeration =
                                        nkr::randomness::Value<enumeration_p>(generator_lockee.Value(), constraint_b, constraint_a);

                                    CHECK(enumeration >= constraint_b);
                                    CHECK(enumeration <= constraint_a);
                                }
                            }
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

            TEST_SUITE("copy_constructor()"
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

            TEST_SUITE("move_constructor()"
                       * doctest::description("should move other and leave its value alone"))
            {
                TEST_CASE_TEMPLATE("non-qualified", enumeration_p, nkr_ANY)
                {
                    nkr::cpp::just_non_qualified_t<enumeration_p> other = nkr::randomness::Value<enumeration_p>();
                    nkr::cpp::just_non_qualified_t<enumeration_p> backup = other;
                    enumeration_p enumeration = nkr::cpp::Move(other);

                    CHECK((enumeration == backup));
                    CHECK((other == backup));
                }

                TEST_CASE_TEMPLATE("volatile", enumeration_p, nkr_ANY)
                {
                    nkr::cpp::just_volatile_t<enumeration_p> other = nkr::randomness::Value<enumeration_p>();
                    nkr::cpp::just_volatile_t<enumeration_p> backup = other;
                    enumeration_p enumeration = nkr::cpp::Move(other);

                    CHECK((enumeration == backup));
                    CHECK((other == backup));
                }
            }

            TEST_SUITE("copy_assigner()"
                       * doctest::description("should always copy other without changing it"))
            {
                TEST_CASE_TEMPLATE("non-qualified", enumeration_p, nkr_ANY_NON_CONST)
                {
                    nkr::cpp::just_non_qualified_t<enumeration_p> other = nkr::randomness::Value<enumeration_p>();
                    enumeration_p enumeration;
                    enumeration = other;

                    CHECK((enumeration == other));
                }

                TEST_CASE_TEMPLATE("const", enumeration_p, nkr_ANY_NON_CONST)
                {
                    nkr::cpp::just_const_t<enumeration_p> other = nkr::randomness::Value<enumeration_p>();
                    enumeration_p enumeration;
                    enumeration = other;

                    CHECK((enumeration == other));
                }

                TEST_CASE_TEMPLATE("volatile", enumeration_p, nkr_ANY_NON_CONST)
                {
                    nkr::cpp::just_volatile_t<enumeration_p> other = nkr::randomness::Value<enumeration_p>();
                    enumeration_p enumeration;
                    enumeration = other;

                    CHECK((enumeration == other));
                }

                TEST_CASE_TEMPLATE("const volatile", enumeration_p, nkr_ANY_NON_CONST)
                {
                    nkr::cpp::just_const_volatile_t<enumeration_p> other = nkr::randomness::Value<enumeration_p>();
                    enumeration_p enumeration;
                    enumeration = other;

                    CHECK((enumeration == other));
                }
            }

            TEST_SUITE("move_assigner()"
                       * doctest::description("should move other and leave its value alone"))
            {
                TEST_SUITE("non-qualified")
                {
                    TEST_CASE_TEMPLATE("value", enumeration_p, nkr_ANY_NON_CONST)
                    {
                        nkr::cpp::just_non_qualified_t<enumeration_p> other = nkr::randomness::Value<enumeration_p>();
                        enumeration_p enumeration;
                        enumeration = nkr::cpp::just_non_qualified_t<enumeration_p>(other);

                        CHECK((enumeration == other));
                    }

                    TEST_CASE_TEMPLATE("rvalue", enumeration_p, nkr_ANY_NON_CONST)
                    {
                        nkr::cpp::just_non_qualified_t<enumeration_p> other = nkr::randomness::Value<enumeration_p>();
                        nkr::cpp::just_non_qualified_t<enumeration_p> backup = other;
                        enumeration_p enumeration;
                        enumeration = nkr::cpp::Move(other);

                        CHECK((enumeration == backup));
                        CHECK((other == backup));
                    }
                }

                TEST_SUITE("volatile")
                {
                    TEST_CASE_TEMPLATE("rvalue", enumeration_p, nkr_ANY_NON_CONST)
                    {
                        nkr::cpp::just_volatile_t<enumeration_p> other = nkr::randomness::Value<enumeration_p>();
                        nkr::cpp::just_volatile_t<enumeration_p> backup = other;
                        enumeration_p enumeration;
                        enumeration = nkr::cpp::Move(other);

                        CHECK((enumeration == backup));
                        CHECK((other == backup));
                    }
                }
            }

            TEST_SUITE("dtor()")
            {
                TEST_CASE_TEMPLATE("should leave its value alone", enumeration_p, nkr_ANY)
                {
                    enumeration_p enumeration = nkr::randomness::Value<enumeration_p>();
                    enumeration_p backup = enumeration;
                    enumeration.~enumeration_p();

                    CHECK(enumeration == backup);
                }
            }
        }

        TEST_SUITE("casts")
        {
            TEST_SUITE("value_t()")
            {
                TEST_SUITE("c_enumeration, cpp_enumeration")
                {
                    TEST_CASE_TEMPLATE("should explicitly cast to value_t", enumeration_p, nkr_ANY)
                    {
                        using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                        value_t value = nkr::randomness::Value<value_t>();
                        enumeration_p enumeration = nkr::cpp::just_non_qualified_t<enumeration_p>(value);

                        CHECK(static_cast<value_t>(enumeration) == value);
                    }
                }

                TEST_SUITE("c_enumeration")
                {
                    TEST_CASE_TEMPLATE("should implicitly cast to value_t", enumeration_p, nkr_ANY_C)
                    {
                        using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                        value_t value = nkr::randomness::Value<value_t>();
                        enumeration_p enumeration = nkr::cpp::just_non_qualified_t<enumeration_p>(value);

                        CHECK(enumeration == value);
                    }

                    TEST_SUITE("should implicitly allow for all logical operators")
                    {
                        TEST_CASE_TEMPLATE("when none", enumeration_p, nkr_ANY_C)
                        {
                            nkr::cpp::just_non_qualified_t<enumeration_p> none = nkr::none::value_t<enumeration_p>();
                            enumeration_p enumeration = none;

                            CHECK_FALSE(enumeration);
                            CHECK_TRUE(!enumeration);
                            CHECK_FALSE(!!enumeration);
                            CHECK_FALSE(enumeration || enumeration);
                            CHECK_FALSE(enumeration && enumeration);
                            CHECK_FALSE((enumeration ? true : false));
                        }

                        TEST_CASE_TEMPLATE("when not none", enumeration_p, nkr_ANY_C)
                        {
                            nkr::cpp::just_non_qualified_t<enumeration_p> non_none;
                            do {
                                non_none = nkr::randomness::Value<enumeration_p>();
                            } while (non_none == nkr::none::value_t<enumeration_p>());
                            enumeration_p enumeration = non_none;

                            CHECK_TRUE(enumeration);
                            CHECK_FALSE(!enumeration);
                            CHECK_TRUE(!!enumeration);
                            CHECK_TRUE(enumeration || enumeration);
                            CHECK_TRUE(enumeration && enumeration);
                            CHECK_TRUE((enumeration ? true : false));
                        }

                        TEST_CASE_TEMPLATE("with none values that convert to true", integer_p, nkr_INTEGERS(nkr_BLANK))
                        {
                            enum enumeration_e :
                                integer_p
                            {
                            };

                            nkr::cpp::just_non_qualified_t<enumeration_e> none = nkr::none::value_t<enumeration_e>();
                            enumeration_e enumeration = none;

                            CHECK_TRUE(enumeration);
                            CHECK_FALSE(!enumeration);
                            CHECK_TRUE(!!enumeration);
                            CHECK_TRUE(enumeration || enumeration);
                            CHECK_TRUE(enumeration && enumeration);
                            CHECK_TRUE((enumeration ? true : false));
                        }
                    }

                    TEST_CASE_TEMPLATE("should implicitly allow for all comparison operators", enumeration_p, nkr_ANY_C)
                    {
                        using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                        value_t value = nkr::randomness::Value<value_t>();
                        enumeration_p enumeration = nkr::cpp::just_non_qualified_t<enumeration_p>(value);

                        CHECK_TRUE(enumeration == value);
                        CHECK_FALSE(enumeration != value);
                        CHECK_FALSE(enumeration < value);
                        CHECK_FALSE(enumeration > value);
                        CHECK_TRUE(enumeration <= value);
                        CHECK_TRUE(enumeration >= value);
                        CHECK_TRUE((enumeration <=> value == 0));
                    }

                    TEST_CASE_TEMPLATE("should implicitly allow for some arithmetic operators", enumeration_p, nkr_ANY_C)
                    {
                        using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                        value_t value_a = nkr::randomness::Value<value_t>();
                        value_t value_b;
                        do {
                            value_b = nkr::randomness::Value<value_t>();
                        } while (value_b == nkr::none::value_t<value_t>());
                        enumeration_p enumeration = nkr::cpp::just_non_qualified_t<enumeration_p>(value_a);

                        CHECK(+enumeration == +value_a);
                        if constexpr (nkr::generic::negatable_tr<value_t>) {
                            CHECK(-enumeration == -value_a);
                        }

                        CHECK((enumeration + value_b) == (value_a + value_b));
                        CHECK((enumeration - value_b) == (value_a - value_b));
                        CHECK((enumeration * value_b) == (value_a * value_b));
                        CHECK((enumeration / value_b) == (value_a / value_b));
                        CHECK((enumeration % value_b) == (value_a % value_b));
                    }

                    TEST_CASE_TEMPLATE("should implicitly allow for some bitwise operators", enumeration_p, nkr_ANY_C)
                    {
                        using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                        value_t value_a = nkr::randomness::Value<value_t>();
                        value_t value_b = nkr::randomness::Value<value_t>();
                        value_t value_c = nkr::randomness::Value<value_t>(value_t(0), value_t(1));
                        enumeration_p enumeration = nkr::cpp::just_non_qualified_t<enumeration_p>(value_a);

                        CHECK(~enumeration == ~value_a);

                        CHECK((enumeration | value_b) == (value_a | value_b));
                        CHECK((enumeration & value_b) == (value_a & value_b));
                        CHECK((enumeration ^ value_b) == (value_a ^ value_b));
                        CHECK((enumeration << value_c) == (value_a << value_c));
                        CHECK((enumeration >> value_c) == (value_a >> value_c));
                    }
                }

                TEST_SUITE("cpp_enumeration")
                {
                    TEST_SUITE("should implicitly allow for some logical operators")
                    {
                        TEST_CASE_TEMPLATE("when none", enumeration_p, nkr_ANY_CPP)
                        {
                            nkr::cpp::just_non_qualified_t<enumeration_p> none = nkr::none::value_t<enumeration_p>();
                            enumeration_p enumeration = none;

                            CHECK_FALSE(enumeration);
                            CHECK_FALSE(enumeration || enumeration);
                            CHECK_FALSE(enumeration && enumeration);
                        }

                        TEST_CASE_TEMPLATE("when not none", enumeration_p, nkr_ANY_CPP)
                        {
                            nkr::cpp::just_non_qualified_t<enumeration_p> non_none;
                            do {
                                non_none = nkr::randomness::Value<enumeration_p>();
                            } while (non_none == nkr::none::value_t<enumeration_p>());
                            enumeration_p enumeration = non_none;

                            CHECK_TRUE(enumeration);
                            CHECK_TRUE(enumeration || enumeration);
                            CHECK_TRUE(enumeration && enumeration);
                        }

                        TEST_CASE_TEMPLATE("with none values that convert to true", integer_p, nkr_INTEGERS(nkr_BLANK))
                        {
                            enum class enumeration_e :
                                integer_p
                            {
                            };

                            nkr::cpp::just_non_qualified_t<enumeration_e> none = nkr::none::value_t<enumeration_e>();
                            enumeration_e enumeration = none;

                            CHECK_TRUE(enumeration);
                            CHECK_TRUE(enumeration || enumeration);
                            CHECK_TRUE(enumeration && enumeration);
                        }
                    }
                }
            }
        }

        TEST_SUITE("global operators")
        {
            TEST_SUITE("comparison operators: ==, !=, <, >, <=, >=, <=>")
            {
                TEST_SUITE("non-qualified")
                {
                    TEST_CASE_TEMPLATE("value", enumeration_p, nkr_ANY)
                    {
                        using non_qualified_t = nkr::cpp::just_non_qualified_t<enumeration_p>;
                        using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                        for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                            enumeration_p a = nkr::randomness::Value<enumeration_p>();
                            nkr::cpp::just_non_qualified_t<enumeration_p> b = nkr::randomness::Value<enumeration_p>();

                            CHECK((a == non_qualified_t(b)) == (value_t(a) == value_t(b)));
                            CHECK((non_qualified_t(b) == a) == (value_t(b) == value_t(a)));
                            CHECK((non_qualified_t(a) == b) == (value_t(a) == value_t(b)));
                            CHECK((b == non_qualified_t(a)) == (value_t(b) == value_t(a)));
                            CHECK((non_qualified_t(a) == non_qualified_t(b)) == (value_t(a) == value_t(b)));

                            CHECK((a != non_qualified_t(b)) == (value_t(a) != value_t(b)));
                            CHECK((non_qualified_t(b) != a) == (value_t(b) != value_t(a)));
                            CHECK((non_qualified_t(a) != b) == (value_t(a) != value_t(b)));
                            CHECK((b != non_qualified_t(a)) == (value_t(b) != value_t(a)));
                            CHECK((non_qualified_t(a) != non_qualified_t(b)) == (value_t(a) != value_t(b)));

                            CHECK((a < non_qualified_t(b)) == (value_t(a) < value_t(b)));
                            CHECK((non_qualified_t(b) < a) == (value_t(b) < value_t(a)));
                            CHECK((non_qualified_t(a) < b) == (value_t(a) < value_t(b)));
                            CHECK((b < non_qualified_t(a)) == (value_t(b) < value_t(a)));
                            CHECK((non_qualified_t(a) < non_qualified_t(b)) == (value_t(a) < value_t(b)));

                            CHECK((a > non_qualified_t(b)) == (value_t(a) > value_t(b)));
                            CHECK((non_qualified_t(b) > a) == (value_t(b) > value_t(a)));
                            CHECK((non_qualified_t(a) > b) == (value_t(a) > value_t(b)));
                            CHECK((b > non_qualified_t(a)) == (value_t(b) > value_t(a)));
                            CHECK((non_qualified_t(a) > non_qualified_t(b)) == (value_t(a) > value_t(b)));

                            CHECK((a <= non_qualified_t(b)) == (value_t(a) <= value_t(b)));
                            CHECK((non_qualified_t(b) <= a) == (value_t(b) <= value_t(a)));
                            CHECK((non_qualified_t(a) <= b) == (value_t(a) <= value_t(b)));
                            CHECK((b <= non_qualified_t(a)) == (value_t(b) <= value_t(a)));
                            CHECK((non_qualified_t(a) <= non_qualified_t(b)) == (value_t(a) <= value_t(b)));

                            CHECK((a >= non_qualified_t(b)) == (value_t(a) >= value_t(b)));
                            CHECK((non_qualified_t(b) >= a) == (value_t(b) >= value_t(a)));
                            CHECK((non_qualified_t(a) >= b) == (value_t(a) >= value_t(b)));
                            CHECK((b >= non_qualified_t(a)) == (value_t(b) >= value_t(a)));
                            CHECK((non_qualified_t(a) >= non_qualified_t(b)) == (value_t(a) >= value_t(b)));

                            CHECK((a <=> non_qualified_t(b)) == (value_t(a) <=> value_t(b)));
                            CHECK((non_qualified_t(b) <=> a) == (value_t(b) <=> value_t(a)));
                            CHECK((non_qualified_t(a) <=> b) == (value_t(a) <=> value_t(b)));
                            CHECK((b <=> non_qualified_t(a)) == (value_t(b) <=> value_t(a)));
                            CHECK((non_qualified_t(a) <=> non_qualified_t(b)) == (value_t(a) <=> value_t(b)));
                        }
                    }

                    TEST_CASE_TEMPLATE("lvalue", enumeration_p, nkr_ANY)
                    {
                        using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                        for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                            enumeration_p a = nkr::randomness::Value<enumeration_p>();
                            nkr::cpp::just_non_qualified_t<enumeration_p> b = nkr::randomness::Value<enumeration_p>();

                            CHECK((a == b) == (value_t(a) == value_t(b)));
                            CHECK((b == a) == (value_t(b) == value_t(a)));

                            CHECK((a != b) == (value_t(a) != value_t(b)));
                            CHECK((b != a) == (value_t(b) != value_t(a)));

                            CHECK((a < b) == (value_t(a) < value_t(b)));
                            CHECK((b < a) == (value_t(b) < value_t(a)));

                            CHECK((a > b) == (value_t(a) > value_t(b)));
                            CHECK((b > a) == (value_t(b) > value_t(a)));

                            CHECK((a <= b) == (value_t(a) <= value_t(b)));
                            CHECK((b <= a) == (value_t(b) <= value_t(a)));

                            CHECK((a >= b) == (value_t(a) >= value_t(b)));
                            CHECK((b >= a) == (value_t(b) >= value_t(a)));

                            CHECK((a <=> b) == (value_t(a) <=> value_t(b)));
                            CHECK((b <=> a) == (value_t(b) <=> value_t(a)));
                        }
                    }

                    TEST_CASE_TEMPLATE("rvalue", enumeration_p, nkr_ANY)
                    {
                        using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                        for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                            enumeration_p a = nkr::randomness::Value<enumeration_p>();
                            nkr::cpp::just_non_qualified_t<enumeration_p> b = nkr::randomness::Value<enumeration_p>();

                            CHECK((a == nkr::cpp::Move(b)) == (value_t(a) == value_t(b)));
                            CHECK((nkr::cpp::Move(b) == a) == (value_t(b) == value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                CHECK((nkr::cpp::Move(a) == b) == (value_t(a) == value_t(b)));
                                CHECK((b == nkr::cpp::Move(a)) == (value_t(b) == value_t(a)));
                                CHECK((nkr::cpp::Move(a) == nkr::cpp::Move(b)) == (value_t(a) == value_t(b)));
                            }

                            CHECK((a != nkr::cpp::Move(b)) == (value_t(a) != value_t(b)));
                            CHECK((nkr::cpp::Move(b) != a) == (value_t(b) != value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                CHECK((nkr::cpp::Move(a) != b) == (value_t(a) != value_t(b)));
                                CHECK((b != nkr::cpp::Move(a)) == (value_t(b) != value_t(a)));
                                CHECK((nkr::cpp::Move(a) != nkr::cpp::Move(b)) == (value_t(a) != value_t(b)));
                            }

                            CHECK((a < nkr::cpp::Move(b)) == (value_t(a) < value_t(b)));
                            CHECK((nkr::cpp::Move(b) < a) == (value_t(b) < value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                CHECK((nkr::cpp::Move(a) < b) == (value_t(a) < value_t(b)));
                                CHECK((b < nkr::cpp::Move(a)) == (value_t(b) < value_t(a)));
                                CHECK((nkr::cpp::Move(a) < nkr::cpp::Move(b)) == (value_t(a) < value_t(b)));
                            }

                            CHECK((a > nkr::cpp::Move(b)) == (value_t(a) > value_t(b)));
                            CHECK((nkr::cpp::Move(b) > a) == (value_t(b) > value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                CHECK((nkr::cpp::Move(a) > b) == (value_t(a) > value_t(b)));
                                CHECK((b > nkr::cpp::Move(a)) == (value_t(b) > value_t(a)));
                                CHECK((nkr::cpp::Move(a) > nkr::cpp::Move(b)) == (value_t(a) > value_t(b)));
                            }

                            CHECK((a <= nkr::cpp::Move(b)) == (value_t(a) <= value_t(b)));
                            CHECK((nkr::cpp::Move(b) <= a) == (value_t(b) <= value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                CHECK((nkr::cpp::Move(a) <= b) == (value_t(a) <= value_t(b)));
                                CHECK((b <= nkr::cpp::Move(a)) == (value_t(b) <= value_t(a)));
                                CHECK((nkr::cpp::Move(a) <= nkr::cpp::Move(b)) == (value_t(a) <= value_t(b)));
                            }

                            CHECK((a >= nkr::cpp::Move(b)) == (value_t(a) >= value_t(b)));
                            CHECK((nkr::cpp::Move(b) >= a) == (value_t(b) >= value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                CHECK((nkr::cpp::Move(a) >= b) == (value_t(a) >= value_t(b)));
                                CHECK((b >= nkr::cpp::Move(a)) == (value_t(b) >= value_t(a)));
                                CHECK((nkr::cpp::Move(a) >= nkr::cpp::Move(b)) == (value_t(a) >= value_t(b)));
                            }

                            CHECK((a <=> nkr::cpp::Move(b)) == (value_t(a) <=> value_t(b)));
                            CHECK((nkr::cpp::Move(b) <=> a) == (value_t(b) <=> value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                CHECK((nkr::cpp::Move(a) <=> b) == (value_t(a) <=> value_t(b)));
                                CHECK((b <=> nkr::cpp::Move(a)) == (value_t(b) <=> value_t(a)));
                                CHECK((nkr::cpp::Move(a) <=> nkr::cpp::Move(b)) == (value_t(a) <=> value_t(b)));
                            }
                        }
                    }
                }

                TEST_SUITE("const")
                {
                    TEST_CASE_TEMPLATE("lvalue", enumeration_p, nkr_ANY)
                    {
                        using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                        for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                            enumeration_p a = nkr::randomness::Value<enumeration_p>();
                            nkr::cpp::just_const_t<enumeration_p> b = nkr::randomness::Value<enumeration_p>();

                            CHECK((a == b) == (value_t(a) == value_t(b)));
                            CHECK((b == a) == (value_t(b) == value_t(a)));

                            CHECK((a != b) == (value_t(a) != value_t(b)));
                            CHECK((b != a) == (value_t(b) != value_t(a)));

                            CHECK((a < b) == (value_t(a) < value_t(b)));
                            CHECK((b < a) == (value_t(b) < value_t(a)));

                            CHECK((a > b) == (value_t(a) > value_t(b)));
                            CHECK((b > a) == (value_t(b) > value_t(a)));

                            CHECK((a <= b) == (value_t(a) <= value_t(b)));
                            CHECK((b <= a) == (value_t(b) <= value_t(a)));

                            CHECK((a >= b) == (value_t(a) >= value_t(b)));
                            CHECK((b >= a) == (value_t(b) >= value_t(a)));

                            CHECK((a <=> b) == (value_t(a) <=> value_t(b)));
                            CHECK((b <=> a) == (value_t(b) <=> value_t(a)));
                        }
                    }
                }

                TEST_SUITE("volatile")
                {
                    TEST_CASE_TEMPLATE("lvalue", enumeration_p, nkr_ANY)
                    {
                        using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                        for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                            enumeration_p a = nkr::randomness::Value<enumeration_p>();
                            nkr::cpp::just_volatile_t<enumeration_p> b = nkr::randomness::Value<enumeration_p>();

                            CHECK((a == b) == (value_t(a) == value_t(b)));
                            CHECK((b == a) == (value_t(b) == value_t(a)));

                            CHECK((a != b) == (value_t(a) != value_t(b)));
                            CHECK((b != a) == (value_t(b) != value_t(a)));

                            CHECK((a < b) == (value_t(a) < value_t(b)));
                            CHECK((b < a) == (value_t(b) < value_t(a)));

                            CHECK((a > b) == (value_t(a) > value_t(b)));
                            CHECK((b > a) == (value_t(b) > value_t(a)));

                            CHECK((a <= b) == (value_t(a) <= value_t(b)));
                            CHECK((b <= a) == (value_t(b) <= value_t(a)));

                            CHECK((a >= b) == (value_t(a) >= value_t(b)));
                            CHECK((b >= a) == (value_t(b) >= value_t(a)));

                            CHECK((a <=> b) == (value_t(a) <=> value_t(b)));
                            CHECK((b <=> a) == (value_t(b) <=> value_t(a)));
                        }
                    }

                    TEST_CASE_TEMPLATE("rvalue", enumeration_p, nkr_ANY)
                    {
                        using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                        for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                            enumeration_p a = nkr::randomness::Value<enumeration_p>();
                            nkr::cpp::just_volatile_t<enumeration_p> b = nkr::randomness::Value<enumeration_p>();

                            CHECK((a == nkr::cpp::Move(b)) == (value_t(a) == value_t(b)));
                            CHECK((nkr::cpp::Move(b) == a) == (value_t(b) == value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                CHECK((nkr::cpp::Move(a) == b) == (value_t(a) == value_t(b)));
                                CHECK((b == nkr::cpp::Move(a)) == (value_t(b) == value_t(a)));
                                CHECK((nkr::cpp::Move(a) == nkr::cpp::Move(b)) == (value_t(a) == value_t(b)));
                            }

                            CHECK((a != nkr::cpp::Move(b)) == (value_t(a) != value_t(b)));
                            CHECK((nkr::cpp::Move(b) != a) == (value_t(b) != value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                CHECK((nkr::cpp::Move(a) != b) == (value_t(a) != value_t(b)));
                                CHECK((b != nkr::cpp::Move(a)) == (value_t(b) != value_t(a)));
                                CHECK((nkr::cpp::Move(a) != nkr::cpp::Move(b)) == (value_t(a) != value_t(b)));
                            }

                            CHECK((a < nkr::cpp::Move(b)) == (value_t(a) < value_t(b)));
                            CHECK((nkr::cpp::Move(b) < a) == (value_t(b) < value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                CHECK((nkr::cpp::Move(a) < b) == (value_t(a) < value_t(b)));
                                CHECK((b < nkr::cpp::Move(a)) == (value_t(b) < value_t(a)));
                                CHECK((nkr::cpp::Move(a) < nkr::cpp::Move(b)) == (value_t(a) < value_t(b)));
                            }

                            CHECK((a > nkr::cpp::Move(b)) == (value_t(a) > value_t(b)));
                            CHECK((nkr::cpp::Move(b) > a) == (value_t(b) > value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                CHECK((nkr::cpp::Move(a) > b) == (value_t(a) > value_t(b)));
                                CHECK((b > nkr::cpp::Move(a)) == (value_t(b) > value_t(a)));
                                CHECK((nkr::cpp::Move(a) > nkr::cpp::Move(b)) == (value_t(a) > value_t(b)));
                            }

                            CHECK((a <= nkr::cpp::Move(b)) == (value_t(a) <= value_t(b)));
                            CHECK((nkr::cpp::Move(b) <= a) == (value_t(b) <= value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                CHECK((nkr::cpp::Move(a) <= b) == (value_t(a) <= value_t(b)));
                                CHECK((b <= nkr::cpp::Move(a)) == (value_t(b) <= value_t(a)));
                                CHECK((nkr::cpp::Move(a) <= nkr::cpp::Move(b)) == (value_t(a) <= value_t(b)));
                            }

                            CHECK((a >= nkr::cpp::Move(b)) == (value_t(a) >= value_t(b)));
                            CHECK((nkr::cpp::Move(b) >= a) == (value_t(b) >= value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                CHECK((nkr::cpp::Move(a) >= b) == (value_t(a) >= value_t(b)));
                                CHECK((b >= nkr::cpp::Move(a)) == (value_t(b) >= value_t(a)));
                                CHECK((nkr::cpp::Move(a) >= nkr::cpp::Move(b)) == (value_t(a) >= value_t(b)));
                            }

                            CHECK((a <=> nkr::cpp::Move(b)) == (value_t(a) <=> value_t(b)));
                            CHECK((nkr::cpp::Move(b) <=> a) == (value_t(b) <=> value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                CHECK((nkr::cpp::Move(a) <=> b) == (value_t(a) <=> value_t(b)));
                                CHECK((b <=> nkr::cpp::Move(a)) == (value_t(b) <=> value_t(a)));
                                CHECK((nkr::cpp::Move(a) <=> nkr::cpp::Move(b)) == (value_t(a) <=> value_t(b)));
                            }
                        }
                    }
                }

                TEST_SUITE("const volatile")
                {
                    TEST_CASE_TEMPLATE("lvalue", enumeration_p, nkr_ANY)
                    {
                        using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                        for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                            enumeration_p a = nkr::randomness::Value<enumeration_p>();
                            nkr::cpp::just_const_volatile_t<enumeration_p> b = nkr::randomness::Value<enumeration_p>();

                            CHECK((a == b) == (value_t(a) == value_t(b)));
                            CHECK((b == a) == (value_t(b) == value_t(a)));

                            CHECK((a != b) == (value_t(a) != value_t(b)));
                            CHECK((b != a) == (value_t(b) != value_t(a)));

                            CHECK((a < b) == (value_t(a) < value_t(b)));
                            CHECK((b < a) == (value_t(b) < value_t(a)));

                            CHECK((a > b) == (value_t(a) > value_t(b)));
                            CHECK((b > a) == (value_t(b) > value_t(a)));

                            CHECK((a <= b) == (value_t(a) <= value_t(b)));
                            CHECK((b <= a) == (value_t(b) <= value_t(a)));

                            CHECK((a >= b) == (value_t(a) >= value_t(b)));
                            CHECK((b >= a) == (value_t(b) >= value_t(a)));

                            CHECK((a <=> b) == (value_t(a) <=> value_t(b)));
                            CHECK((b <=> a) == (value_t(b) <=> value_t(a)));
                        }
                    }
                }
            }

            TEST_SUITE("arithmetic operators: +, -, *, /, %")
            {
                TEST_SUITE("c_enumeration")
                {
                    TEST_SUITE("non-qualified")
                    {
                        TEST_CASE_TEMPLATE("value", enumeration_p, nkr_ANY_C)
                        {
                            using non_qualified_t = nkr::cpp::just_non_qualified_t<enumeration_p>;
                            using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                enumeration_p a =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);
                                nkr::cpp::just_non_qualified_t<enumeration_p> b =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);

                                CHECK((a + non_qualified_t(b)) == (value_t(a) + value_t(b)));
                                CHECK((non_qualified_t(b) + a) == (value_t(b) + value_t(a)));
                                CHECK((non_qualified_t(a) + b) == (value_t(a) + value_t(b)));
                                CHECK((b + non_qualified_t(a)) == (value_t(b) + value_t(a)));
                                CHECK((non_qualified_t(a) + non_qualified_t(b)) == (value_t(a) + value_t(b)));

                                CHECK((a - non_qualified_t(b)) == (value_t(a) - value_t(b)));
                                CHECK((non_qualified_t(b) - a) == (value_t(b) - value_t(a)));
                                CHECK((non_qualified_t(a) - b) == (value_t(a) - value_t(b)));
                                CHECK((b - non_qualified_t(a)) == (value_t(b) - value_t(a)));
                                CHECK((non_qualified_t(a) - non_qualified_t(b)) == (value_t(a) - value_t(b)));

                                CHECK((a * non_qualified_t(b)) == (value_t(a) * value_t(b)));
                                CHECK((non_qualified_t(b) * a) == (value_t(b) * value_t(a)));
                                CHECK((non_qualified_t(a) * b) == (value_t(a) * value_t(b)));
                                CHECK((b * non_qualified_t(a)) == (value_t(b) * value_t(a)));
                                CHECK((non_qualified_t(a) * non_qualified_t(b)) == (value_t(a) * value_t(b)));

                                CHECK((a / non_qualified_t(b)) == (value_t(a) / value_t(b)));
                                CHECK((non_qualified_t(b) / a) == (value_t(b) / value_t(a)));
                                CHECK((non_qualified_t(a) / b) == (value_t(a) / value_t(b)));
                                CHECK((b / non_qualified_t(a)) == (value_t(b) / value_t(a)));
                                CHECK((non_qualified_t(a) / non_qualified_t(b)) == (value_t(a) / value_t(b)));

                                CHECK((a % non_qualified_t(b)) == (value_t(a) % value_t(b)));
                                CHECK((non_qualified_t(b) % a) == (value_t(b) % value_t(a)));
                                CHECK((non_qualified_t(a) % b) == (value_t(a) % value_t(b)));
                                CHECK((b % non_qualified_t(a)) == (value_t(b) % value_t(a)));
                                CHECK((non_qualified_t(a) % non_qualified_t(b)) == (value_t(a) % value_t(b)));
                            }
                        }

                        TEST_CASE_TEMPLATE("lvalue", enumeration_p, nkr_ANY_C)
                        {
                            using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                enumeration_p a =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);
                                nkr::cpp::just_non_qualified_t<enumeration_p> b =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);

                                CHECK((a + b) == (value_t(a) + value_t(b)));
                                CHECK((b + a) == (value_t(b) + value_t(a)));

                                CHECK((a - b) == (value_t(a) - value_t(b)));
                                CHECK((b - a) == (value_t(b) - value_t(a)));

                                CHECK((a * b) == (value_t(a) * value_t(b)));
                                CHECK((b * a) == (value_t(b) * value_t(a)));

                                CHECK((a / b) == (value_t(a) / value_t(b)));
                                CHECK((b / a) == (value_t(b) / value_t(a)));

                                CHECK((a % b) == (value_t(a) % value_t(b)));
                                CHECK((b % a) == (value_t(b) % value_t(a)));
                            }
                        }

                        TEST_CASE_TEMPLATE("rvalue", enumeration_p, nkr_ANY_C)
                        {
                            using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                enumeration_p a =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);
                                nkr::cpp::just_non_qualified_t<enumeration_p> b =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);

                                CHECK((a + nkr::cpp::Move(b)) == (value_t(a) + value_t(b)));
                                CHECK((nkr::cpp::Move(b) + a) == (value_t(b) + value_t(a)));
                                if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                    CHECK((nkr::cpp::Move(a) + b) == (value_t(a) + value_t(b)));
                                    CHECK((b + nkr::cpp::Move(a)) == (value_t(b) + value_t(a)));
                                    CHECK((nkr::cpp::Move(a) + nkr::cpp::Move(b)) == (value_t(a) + value_t(b)));
                                }

                                CHECK((a - nkr::cpp::Move(b)) == (value_t(a) - value_t(b)));
                                CHECK((nkr::cpp::Move(b) - a) == (value_t(b) - value_t(a)));
                                if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                    CHECK((nkr::cpp::Move(a) - b) == (value_t(a) - value_t(b)));
                                    CHECK((b - nkr::cpp::Move(a)) == (value_t(b) - value_t(a)));
                                    CHECK((nkr::cpp::Move(a) - nkr::cpp::Move(b)) == (value_t(a) - value_t(b)));
                                }

                                CHECK((a * nkr::cpp::Move(b)) == (value_t(a) * value_t(b)));
                                CHECK((nkr::cpp::Move(b) * a) == (value_t(b) * value_t(a)));
                                if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                    CHECK((nkr::cpp::Move(a) * b) == (value_t(a) * value_t(b)));
                                    CHECK((b * nkr::cpp::Move(a)) == (value_t(b) * value_t(a)));
                                    CHECK((nkr::cpp::Move(a) * nkr::cpp::Move(b)) == (value_t(a) * value_t(b)));
                                }

                                CHECK((a / nkr::cpp::Move(b)) == (value_t(a) / value_t(b)));
                                CHECK((nkr::cpp::Move(b) / a) == (value_t(b) / value_t(a)));
                                if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                    CHECK((nkr::cpp::Move(a) / b) == (value_t(a) / value_t(b)));
                                    CHECK((b / nkr::cpp::Move(a)) == (value_t(b) / value_t(a)));
                                    CHECK((nkr::cpp::Move(a) / nkr::cpp::Move(b)) == (value_t(a) / value_t(b)));
                                }

                                CHECK((a % nkr::cpp::Move(b)) == (value_t(a) % value_t(b)));
                                CHECK((nkr::cpp::Move(b) % a) == (value_t(b) % value_t(a)));
                                if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                    CHECK((nkr::cpp::Move(a) % b) == (value_t(a) % value_t(b)));
                                    CHECK((b % nkr::cpp::Move(a)) == (value_t(b) % value_t(a)));
                                    CHECK((nkr::cpp::Move(a) % nkr::cpp::Move(b)) == (value_t(a) % value_t(b)));
                                }
                            }
                        }
                    }

                    TEST_SUITE("const")
                    {
                        TEST_CASE_TEMPLATE("lvalue", enumeration_p, nkr_ANY_C)
                        {
                            using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                enumeration_p a =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);
                                nkr::cpp::just_const_t<enumeration_p> b =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);

                                CHECK((a + b) == (value_t(a) + value_t(b)));
                                CHECK((b + a) == (value_t(b) + value_t(a)));

                                CHECK((a - b) == (value_t(a) - value_t(b)));
                                CHECK((b - a) == (value_t(b) - value_t(a)));

                                CHECK((a * b) == (value_t(a) * value_t(b)));
                                CHECK((b * a) == (value_t(b) * value_t(a)));

                                CHECK((a / b) == (value_t(a) / value_t(b)));
                                CHECK((b / a) == (value_t(b) / value_t(a)));

                                CHECK((a % b) == (value_t(a) % value_t(b)));
                                CHECK((b % a) == (value_t(b) % value_t(a)));
                            }
                        }
                    }

                    TEST_SUITE("volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", enumeration_p, nkr_ANY_C)
                        {
                            using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                enumeration_p a =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);
                                nkr::cpp::just_volatile_t<enumeration_p> b =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);

                                CHECK((a + b) == (value_t(a) + value_t(b)));
                                CHECK((b + a) == (value_t(b) + value_t(a)));

                                CHECK((a - b) == (value_t(a) - value_t(b)));
                                CHECK((b - a) == (value_t(b) - value_t(a)));

                                CHECK((a * b) == (value_t(a) * value_t(b)));
                                CHECK((b * a) == (value_t(b) * value_t(a)));

                                CHECK((a / b) == (value_t(a) / value_t(b)));
                                CHECK((b / a) == (value_t(b) / value_t(a)));

                                CHECK((a % b) == (value_t(a) % value_t(b)));
                                CHECK((b % a) == (value_t(b) % value_t(a)));
                            }
                        }

                        TEST_CASE_TEMPLATE("rvalue", enumeration_p, nkr_ANY_C)
                        {
                            using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                enumeration_p a =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);
                                nkr::cpp::just_volatile_t<enumeration_p> b =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);

                                CHECK((a + nkr::cpp::Move(b)) == (value_t(a) + value_t(b)));
                                CHECK((nkr::cpp::Move(b) + a) == (value_t(b) + value_t(a)));
                                if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                    CHECK((nkr::cpp::Move(a) + b) == (value_t(a) + value_t(b)));
                                    CHECK((b + nkr::cpp::Move(a)) == (value_t(b) + value_t(a)));
                                    CHECK((nkr::cpp::Move(a) + nkr::cpp::Move(b)) == (value_t(a) + value_t(b)));
                                }

                                CHECK((a - nkr::cpp::Move(b)) == (value_t(a) - value_t(b)));
                                CHECK((nkr::cpp::Move(b) - a) == (value_t(b) - value_t(a)));
                                if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                    CHECK((nkr::cpp::Move(a) - b) == (value_t(a) - value_t(b)));
                                    CHECK((b - nkr::cpp::Move(a)) == (value_t(b) - value_t(a)));
                                    CHECK((nkr::cpp::Move(a) - nkr::cpp::Move(b)) == (value_t(a) - value_t(b)));
                                }

                                CHECK((a * nkr::cpp::Move(b)) == (value_t(a) * value_t(b)));
                                CHECK((nkr::cpp::Move(b) * a) == (value_t(b) * value_t(a)));
                                if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                    CHECK((nkr::cpp::Move(a) * b) == (value_t(a) * value_t(b)));
                                    CHECK((b * nkr::cpp::Move(a)) == (value_t(b) * value_t(a)));
                                    CHECK((nkr::cpp::Move(a) * nkr::cpp::Move(b)) == (value_t(a) * value_t(b)));
                                }

                                CHECK((a / nkr::cpp::Move(b)) == (value_t(a) / value_t(b)));
                                CHECK((nkr::cpp::Move(b) / a) == (value_t(b) / value_t(a)));
                                if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                    CHECK((nkr::cpp::Move(a) / b) == (value_t(a) / value_t(b)));
                                    CHECK((b / nkr::cpp::Move(a)) == (value_t(b) / value_t(a)));
                                    CHECK((nkr::cpp::Move(a) / nkr::cpp::Move(b)) == (value_t(a) / value_t(b)));
                                }

                                CHECK((a % nkr::cpp::Move(b)) == (value_t(a) % value_t(b)));
                                CHECK((nkr::cpp::Move(b) % a) == (value_t(b) % value_t(a)));
                                if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                    CHECK((nkr::cpp::Move(a) % b) == (value_t(a) % value_t(b)));
                                    CHECK((b % nkr::cpp::Move(a)) == (value_t(b) % value_t(a)));
                                    CHECK((nkr::cpp::Move(a) % nkr::cpp::Move(b)) == (value_t(a) % value_t(b)));
                                }
                            }
                        }
                    }

                    TEST_SUITE("const volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", enumeration_p, nkr_ANY_C)
                        {
                            using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                enumeration_p a =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);
                                nkr::cpp::just_const_volatile_t<enumeration_p> b =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);

                                CHECK((a + b) == (value_t(a) + value_t(b)));
                                CHECK((b + a) == (value_t(b) + value_t(a)));

                                CHECK((a - b) == (value_t(a) - value_t(b)));
                                CHECK((b - a) == (value_t(b) - value_t(a)));

                                CHECK((a * b) == (value_t(a) * value_t(b)));
                                CHECK((b * a) == (value_t(b) * value_t(a)));

                                CHECK((a / b) == (value_t(a) / value_t(b)));
                                CHECK((b / a) == (value_t(b) / value_t(a)));

                                CHECK((a % b) == (value_t(a) % value_t(b)));
                                CHECK((b % a) == (value_t(b) % value_t(a)));
                            }
                        }
                    }
                }
            }

            TEST_SUITE("bitwise operators: |, &, ^, <<, >>")
            {
                TEST_SUITE("c_enumeration")
                {
                    TEST_SUITE("non-qualified")
                    {
                        TEST_CASE_TEMPLATE("value", enumeration_p, nkr_ANY_C)
                        {
                            using non_qualified_t = nkr::cpp::just_non_qualified_t<enumeration_p>;
                            using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                enumeration_p a =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);
                                nkr::cpp::just_non_qualified_t<enumeration_p> b =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);
                                nkr::cpp::just_non_qualified_t<enumeration_p> c =
                                    nkr::randomness::Value<enumeration_p>(non_qualified_t(0), non_qualified_t(1));

                                CHECK((a | non_qualified_t(b)) == (value_t(a) | value_t(b)));
                                CHECK((non_qualified_t(b) | a) == (value_t(b) | value_t(a)));
                                CHECK((non_qualified_t(a) | b) == (value_t(a) | value_t(b)));
                                CHECK((b | non_qualified_t(a)) == (value_t(b) | value_t(a)));
                                CHECK((non_qualified_t(a) | non_qualified_t(b)) == (value_t(a) | value_t(b)));

                                CHECK((a & non_qualified_t(b)) == (value_t(a) & value_t(b)));
                                CHECK((non_qualified_t(b) & a) == (value_t(b) & value_t(a)));
                                CHECK((non_qualified_t(a) & b) == (value_t(a) & value_t(b)));
                                CHECK((b & non_qualified_t(a)) == (value_t(b) & value_t(a)));
                                CHECK((non_qualified_t(a) & non_qualified_t(b)) == (value_t(a) & value_t(b)));

                                CHECK((a ^ non_qualified_t(b)) == (value_t(a) ^ value_t(b)));
                                CHECK((non_qualified_t(b) ^ a) == (value_t(b) ^ value_t(a)));
                                CHECK((non_qualified_t(a) ^ b) == (value_t(a) ^ value_t(b)));
                                CHECK((b ^ non_qualified_t(a)) == (value_t(b) ^ value_t(a)));
                                CHECK((non_qualified_t(a) ^ non_qualified_t(b)) == (value_t(a) ^ value_t(b)));

                                CHECK((a << non_qualified_t(c)) == (value_t(a) << value_t(c)));
                                CHECK((non_qualified_t(c) << a) == (value_t(c) << value_t(a)));
                                CHECK((non_qualified_t(a) << c) == (value_t(a) << value_t(c)));
                                CHECK((c << non_qualified_t(a)) == (value_t(c) << value_t(a)));
                                CHECK((non_qualified_t(a) << non_qualified_t(c)) == (value_t(a) << value_t(c)));

                                CHECK((a >> non_qualified_t(c)) == (value_t(a) >> value_t(c)));
                                CHECK((non_qualified_t(c) >> a) == (value_t(c) >> value_t(a)));
                                CHECK((non_qualified_t(a) >> c) == (value_t(a) >> value_t(c)));
                                CHECK((c >> non_qualified_t(a)) == (value_t(c) >> value_t(a)));
                                CHECK((non_qualified_t(a) >> non_qualified_t(c)) == (value_t(a) >> value_t(c)));
                            }
                        }

                        TEST_CASE_TEMPLATE("lvalue", enumeration_p, nkr_ANY_C)
                        {
                            using non_qualified_t = nkr::cpp::just_non_qualified_t<enumeration_p>;
                            using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                enumeration_p a =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);
                                nkr::cpp::just_non_qualified_t<enumeration_p> b =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);
                                nkr::cpp::just_non_qualified_t<enumeration_p> c =
                                    nkr::randomness::Value<enumeration_p>(non_qualified_t(0), non_qualified_t(1));

                                CHECK((a | b) == (value_t(a) | value_t(b)));
                                CHECK((b | a) == (value_t(b) | value_t(a)));

                                CHECK((a & b) == (value_t(a) & value_t(b)));
                                CHECK((b & a) == (value_t(b) & value_t(a)));

                                CHECK((a ^ b) == (value_t(a) ^ value_t(b)));
                                CHECK((b ^ a) == (value_t(b) ^ value_t(a)));

                                CHECK((a << c) == (value_t(a) << value_t(c)));
                                CHECK((c << a) == (value_t(c) << value_t(a)));

                                CHECK((a >> c) == (value_t(a) >> value_t(c)));
                                CHECK((c >> a) == (value_t(c) >> value_t(a)));
                            }
                        }

                        TEST_CASE_TEMPLATE("rvalue", enumeration_p, nkr_ANY_C)
                        {
                            using non_qualified_t = nkr::cpp::just_non_qualified_t<enumeration_p>;
                            using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                enumeration_p a =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);
                                nkr::cpp::just_non_qualified_t<enumeration_p> b =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);
                                nkr::cpp::just_non_qualified_t<enumeration_p> c =
                                    nkr::randomness::Value<enumeration_p>(non_qualified_t(0), non_qualified_t(1));

                                CHECK((a | nkr::cpp::Move(b)) == (value_t(a) | value_t(b)));
                                CHECK((nkr::cpp::Move(b) | a) == (value_t(b) | value_t(a)));
                                if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                    CHECK((nkr::cpp::Move(a) | b) == (value_t(a) | value_t(b)));
                                    CHECK((b | nkr::cpp::Move(a)) == (value_t(b) | value_t(a)));
                                    CHECK((nkr::cpp::Move(a) | nkr::cpp::Move(b)) == (value_t(a) | value_t(b)));
                                }

                                CHECK((a & nkr::cpp::Move(b)) == (value_t(a) & value_t(b)));
                                CHECK((nkr::cpp::Move(b) & a) == (value_t(b) & value_t(a)));
                                if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                    CHECK((nkr::cpp::Move(a) & b) == (value_t(a) & value_t(b)));
                                    CHECK((b & nkr::cpp::Move(a)) == (value_t(b) & value_t(a)));
                                    CHECK((nkr::cpp::Move(a) & nkr::cpp::Move(b)) == (value_t(a) & value_t(b)));
                                }

                                CHECK((a ^ nkr::cpp::Move(b)) == (value_t(a) ^ value_t(b)));
                                CHECK((nkr::cpp::Move(b) ^ a) == (value_t(b) ^ value_t(a)));
                                if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                    CHECK((nkr::cpp::Move(a) ^ b) == (value_t(a) ^ value_t(b)));
                                    CHECK((b ^ nkr::cpp::Move(a)) == (value_t(b) ^ value_t(a)));
                                    CHECK((nkr::cpp::Move(a) ^ nkr::cpp::Move(b)) == (value_t(a) ^ value_t(b)));
                                }

                                CHECK((a << nkr::cpp::Move(c)) == (value_t(a) << value_t(c)));
                                CHECK((nkr::cpp::Move(c) << a) == (value_t(c) << value_t(a)));
                                if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                    CHECK((nkr::cpp::Move(a) << c) == (value_t(a) << value_t(c)));
                                    CHECK((c << nkr::cpp::Move(a)) == (value_t(c) << value_t(a)));
                                    CHECK((nkr::cpp::Move(a) << nkr::cpp::Move(c)) == (value_t(a) << value_t(c)));
                                }

                                CHECK((a >> nkr::cpp::Move(c)) == (value_t(a) >> value_t(c)));
                                CHECK((nkr::cpp::Move(c) >> a) == (value_t(c) >> value_t(a)));
                                if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                    CHECK((nkr::cpp::Move(a) >> c) == (value_t(a) >> value_t(c)));
                                    CHECK((c >> nkr::cpp::Move(a)) == (value_t(c) >> value_t(a)));
                                    CHECK((nkr::cpp::Move(a) >> nkr::cpp::Move(c)) == (value_t(a) >> value_t(c)));
                                }
                            }
                        }
                    }

                    TEST_SUITE("const")
                    {
                        TEST_CASE_TEMPLATE("lvalue", enumeration_p, nkr_ANY_C)
                        {
                            using non_qualified_t = nkr::cpp::just_non_qualified_t<enumeration_p>;
                            using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                enumeration_p a =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);
                                nkr::cpp::just_const_t<enumeration_p> b =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);
                                nkr::cpp::just_const_t<enumeration_p> c =
                                    nkr::randomness::Value<enumeration_p>(non_qualified_t(0), non_qualified_t(1));

                                CHECK((a | b) == (value_t(a) | value_t(b)));
                                CHECK((b | a) == (value_t(b) | value_t(a)));

                                CHECK((a & b) == (value_t(a) & value_t(b)));
                                CHECK((b & a) == (value_t(b) & value_t(a)));

                                CHECK((a ^ b) == (value_t(a) ^ value_t(b)));
                                CHECK((b ^ a) == (value_t(b) ^ value_t(a)));

                                CHECK((a << c) == (value_t(a) << value_t(c)));
                                CHECK((c << a) == (value_t(c) << value_t(a)));

                                CHECK((a >> c) == (value_t(a) >> value_t(c)));
                                CHECK((c >> a) == (value_t(c) >> value_t(a)));
                            }
                        }
                    }

                    TEST_SUITE("volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", enumeration_p, nkr_ANY_C)
                        {
                            using non_qualified_t = nkr::cpp::just_non_qualified_t<enumeration_p>;
                            using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                enumeration_p a =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);
                                nkr::cpp::just_volatile_t<enumeration_p> b =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);
                                nkr::cpp::just_volatile_t<enumeration_p> c =
                                    nkr::randomness::Value<enumeration_p>(non_qualified_t(0), non_qualified_t(1));

                                CHECK((a | b) == (value_t(a) | value_t(b)));
                                CHECK((b | a) == (value_t(b) | value_t(a)));

                                CHECK((a & b) == (value_t(a) & value_t(b)));
                                CHECK((b & a) == (value_t(b) & value_t(a)));

                                CHECK((a ^ b) == (value_t(a) ^ value_t(b)));
                                CHECK((b ^ a) == (value_t(b) ^ value_t(a)));

                                CHECK((a << c) == (value_t(a) << value_t(c)));
                                CHECK((c << a) == (value_t(c) << value_t(a)));

                                CHECK((a >> c) == (value_t(a) >> value_t(c)));
                                CHECK((c >> a) == (value_t(c) >> value_t(a)));
                            }
                        }

                        TEST_CASE_TEMPLATE("rvalue", enumeration_p, nkr_ANY_C)
                        {
                            using non_qualified_t = nkr::cpp::just_non_qualified_t<enumeration_p>;
                            using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                enumeration_p a =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);
                                nkr::cpp::just_volatile_t<enumeration_p> b =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);
                                nkr::cpp::just_volatile_t<enumeration_p> c =
                                    nkr::randomness::Value<enumeration_p>(non_qualified_t(0), non_qualified_t(1));

                                CHECK((a | nkr::cpp::Move(b)) == (value_t(a) | value_t(b)));
                                CHECK((nkr::cpp::Move(b) | a) == (value_t(b) | value_t(a)));
                                if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                    CHECK((nkr::cpp::Move(a) | b) == (value_t(a) | value_t(b)));
                                    CHECK((b | nkr::cpp::Move(a)) == (value_t(b) | value_t(a)));
                                    CHECK((nkr::cpp::Move(a) | nkr::cpp::Move(b)) == (value_t(a) | value_t(b)));
                                }

                                CHECK((a & nkr::cpp::Move(b)) == (value_t(a) & value_t(b)));
                                CHECK((nkr::cpp::Move(b) & a) == (value_t(b) & value_t(a)));
                                if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                    CHECK((nkr::cpp::Move(a) & b) == (value_t(a) & value_t(b)));
                                    CHECK((b & nkr::cpp::Move(a)) == (value_t(b) & value_t(a)));
                                    CHECK((nkr::cpp::Move(a) & nkr::cpp::Move(b)) == (value_t(a) & value_t(b)));
                                }

                                CHECK((a ^ nkr::cpp::Move(b)) == (value_t(a) ^ value_t(b)));
                                CHECK((nkr::cpp::Move(b) ^ a) == (value_t(b) ^ value_t(a)));
                                if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                    CHECK((nkr::cpp::Move(a) ^ b) == (value_t(a) ^ value_t(b)));
                                    CHECK((b ^ nkr::cpp::Move(a)) == (value_t(b) ^ value_t(a)));
                                    CHECK((nkr::cpp::Move(a) ^ nkr::cpp::Move(b)) == (value_t(a) ^ value_t(b)));
                                }

                                CHECK((a << nkr::cpp::Move(c)) == (value_t(a) << value_t(c)));
                                CHECK((nkr::cpp::Move(c) << a) == (value_t(c) << value_t(a)));
                                if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                    CHECK((nkr::cpp::Move(a) << c) == (value_t(a) << value_t(c)));
                                    CHECK((c << nkr::cpp::Move(a)) == (value_t(c) << value_t(a)));
                                    CHECK((nkr::cpp::Move(a) << nkr::cpp::Move(c)) == (value_t(a) << value_t(c)));
                                }

                                CHECK((a >> nkr::cpp::Move(c)) == (value_t(a) >> value_t(c)));
                                CHECK((nkr::cpp::Move(c) >> a) == (value_t(c) >> value_t(a)));
                                if constexpr (nkr::cpp::any_non_const_tr<enumeration_p>) {
                                    CHECK((nkr::cpp::Move(a) >> c) == (value_t(a) >> value_t(c)));
                                    CHECK((c >> nkr::cpp::Move(a)) == (value_t(c) >> value_t(a)));
                                    CHECK((nkr::cpp::Move(a) >> nkr::cpp::Move(c)) == (value_t(a) >> value_t(c)));
                                }
                            }
                        }
                    }

                    TEST_SUITE("const volatile")
                    {
                        TEST_CASE_TEMPLATE("lvalue", enumeration_p, nkr_ANY_C)
                        {
                            using non_qualified_t = nkr::cpp::just_non_qualified_t<enumeration_p>;
                            using value_t = nkr::enumeration::cpp_value_t<enumeration_p>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                enumeration_p a =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);
                                nkr::cpp::just_const_volatile_t<enumeration_p> b =
                                    nkr::randomness::Value<enumeration_p>(enumeration_p::A, enumeration_p::Z);
                                nkr::cpp::just_const_volatile_t<enumeration_p> c =
                                    nkr::randomness::Value<enumeration_p>(non_qualified_t(0), non_qualified_t(1));

                                CHECK((a | b) == (value_t(a) | value_t(b)));
                                CHECK((b | a) == (value_t(b) | value_t(a)));

                                CHECK((a & b) == (value_t(a) & value_t(b)));
                                CHECK((b & a) == (value_t(b) & value_t(a)));

                                CHECK((a ^ b) == (value_t(a) ^ value_t(b)));
                                CHECK((b ^ a) == (value_t(b) ^ value_t(a)));

                                CHECK((a << c) == (value_t(a) << value_t(c)));
                                CHECK((c << a) == (value_t(c) << value_t(a)));

                                CHECK((a >> c) == (value_t(a) >> value_t(c)));
                                CHECK((c >> a) == (value_t(c) >> value_t(a)));
                            }
                        }
                    }
                }
            }
        }
    }

}
