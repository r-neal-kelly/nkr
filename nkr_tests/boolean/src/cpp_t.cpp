/*
    Copyright 2021 r-neal-kelly
*/

#pragma warning (disable : 4804)

#include "nkr/boolean/cpp_t.h"
#include "nkr/boolean/pure_t.h"
#include "nkr/built_in/forward.h"
#include "nkr/constant/positive/index_t.h"
#include "nkr/cpp.h"
#include "nkr/generic/non_type_tr.h"
#include "nkr/none/value_t.h"
#include "nkr/randomness/value.h"
#include "nkr/tuple/types_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::boolean::cpp_t")
    {
    #define nkr_TYPES(TYPE_QUALIFIER_p)         \
        TYPE_QUALIFIER_p nkr::boolean::cpp_t    \

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
                nkr::boolean::cpp_tg
            >;

            using non_target_ts = ts<AND_tg,
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

        TEST_SUITE("interface")
        {
            TEST_SUITE("nkr::interface::none::value_i")
            {

            }

            TEST_SUITE("nkr::interface::randomness::distributor::uniform_i")
            {

            }

            TEST_SUITE("nkr::interface::randomness::value_i")
            {

            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("manual_default_constructor()")
            {
                TEST_CASE_TEMPLATE("should set its value to false", boolean_p, nkr_ANY)
                {
                    boolean_p boolean = nkr::cpp::just_non_qualified_t<boolean_p>();

                    CHECK((boolean == false));
                }
            }

            TEST_SUITE("copy_constructor()"
                       * doctest::description("should copy other without changing it"))
            {
                TEST_CASE_TEMPLATE("non-qualified", boolean_p, nkr_ANY)
                {
                    nkr::cpp::just_non_qualified_t<boolean_p> other = nkr::randomness::Value<boolean_p>();
                    boolean_p boolean = other;

                    CHECK((boolean == other));
                }

                TEST_CASE_TEMPLATE("const", boolean_p, nkr_ANY)
                {
                    nkr::cpp::just_const_t<boolean_p> other = nkr::randomness::Value<boolean_p>();
                    boolean_p boolean = other;

                    CHECK((boolean == other));
                }

                TEST_CASE_TEMPLATE("volatile", boolean_p, nkr_ANY)
                {
                    nkr::cpp::just_volatile_t<boolean_p> other = nkr::randomness::Value<boolean_p>();
                    boolean_p boolean = other;

                    CHECK((boolean == other));
                }

                TEST_CASE_TEMPLATE("const volatile", boolean_p, nkr_ANY)
                {
                    nkr::cpp::just_const_volatile_t<boolean_p> other = nkr::randomness::Value<boolean_p>();
                    boolean_p boolean = other;

                    CHECK((boolean == other));
                }
            }

            TEST_SUITE("move_constructor()"
                       * doctest::description("should move other and leave its value alone"))
            {
                TEST_CASE_TEMPLATE("non-qualified", boolean_p, nkr_ANY)
                {
                    nkr::cpp::just_non_qualified_t<boolean_p> other = nkr::randomness::Value<boolean_p>();
                    nkr::cpp::just_non_qualified_t<boolean_p> backup = other;
                    boolean_p boolean = nkr::cpp::Move(other);

                    CHECK((boolean == backup));
                    CHECK((other == backup));
                }

                TEST_CASE_TEMPLATE("volatile", boolean_p, nkr_ANY)
                {
                    nkr::cpp::just_volatile_t<boolean_p> other = nkr::randomness::Value<boolean_p>();
                    nkr::cpp::just_volatile_t<boolean_p> backup = other;
                    boolean_p boolean = nkr::cpp::Move(other);

                    CHECK((boolean == backup));
                    CHECK((other == backup));
                }
            }

            TEST_SUITE("copy_assigner()"
                       * doctest::description("should always copy other without changing it"))
            {
                TEST_CASE_TEMPLATE("non-qualified", boolean_p, nkr_ANY_NON_CONST)
                {
                    nkr::cpp::just_non_qualified_t<boolean_p> other = nkr::randomness::Value<boolean_p>();
                    boolean_p boolean;
                    boolean = other;

                    CHECK((boolean == other));
                }

                TEST_CASE_TEMPLATE("const", boolean_p, nkr_ANY_NON_CONST)
                {
                    nkr::cpp::just_const_t<boolean_p> other = nkr::randomness::Value<boolean_p>();
                    boolean_p boolean;
                    boolean = other;

                    CHECK((boolean == other));
                }

                TEST_CASE_TEMPLATE("volatile", boolean_p, nkr_ANY_NON_CONST)
                {
                    nkr::cpp::just_volatile_t<boolean_p> other = nkr::randomness::Value<boolean_p>();
                    boolean_p boolean;
                    boolean = other;

                    CHECK((boolean == other));
                }

                TEST_CASE_TEMPLATE("const volatile", boolean_p, nkr_ANY_NON_CONST)
                {
                    nkr::cpp::just_const_volatile_t<boolean_p> other = nkr::randomness::Value<boolean_p>();
                    boolean_p boolean;
                    boolean = other;

                    CHECK((boolean == other));
                }
            }

            TEST_SUITE("move_assigner()"
                       * doctest::description("should move other and leave its value alone"))
            {
                TEST_SUITE("non-qualified")
                {
                    TEST_CASE_TEMPLATE("value", boolean_p, nkr_ANY_NON_CONST)
                    {
                        nkr::cpp::just_non_qualified_t<boolean_p> other = nkr::randomness::Value<boolean_p>();
                        boolean_p boolean;
                        boolean = nkr::cpp::just_non_qualified_t<boolean_p>(other);

                        CHECK((boolean == other));
                    }

                    TEST_CASE_TEMPLATE("rvalue", boolean_p, nkr_ANY_NON_CONST)
                    {
                        nkr::cpp::just_non_qualified_t<boolean_p> other = nkr::randomness::Value<boolean_p>();
                        nkr::cpp::just_non_qualified_t<boolean_p> backup = other;
                        boolean_p boolean;
                        boolean = nkr::cpp::Move(other);

                        CHECK((boolean == backup));
                        CHECK((other == backup));
                    }
                }

                TEST_SUITE("volatile")
                {
                    TEST_CASE_TEMPLATE("rvalue", boolean_p, nkr_ANY_NON_CONST)
                    {
                        nkr::cpp::just_volatile_t<boolean_p> other = nkr::randomness::Value<boolean_p>();
                        nkr::cpp::just_volatile_t<boolean_p> backup = other;
                        boolean_p boolean;
                        boolean = nkr::cpp::Move(other);

                        CHECK((boolean == backup));
                        CHECK((other == backup));
                    }
                }
            }

            TEST_SUITE("dtor()")
            {
                TEST_CASE_TEMPLATE("should leave its value alone", boolean_p, nkr_ANY)
                {
                    boolean_p boolean = nkr::randomness::Value<boolean_p>();
                    boolean_p backup = boolean;
                    boolean.~boolean_p();

                    CHECK(boolean == backup);
                }
            }
        }

        TEST_SUITE("casts")
        {
        }

        TEST_SUITE("global operators")
        {
        #define nkr_ANY_WITH_VALUE                                                          \
            nkr::tuple::types_t<nkr::boolean::cpp_t, nkr::boolean::cpp_t>,                  \
            nkr::tuple::types_t<const nkr::boolean::cpp_t, nkr::boolean::cpp_t>,            \
            nkr::tuple::types_t<volatile nkr::boolean::cpp_t, nkr::boolean::cpp_t>,         \
            nkr::tuple::types_t<const volatile nkr::boolean::cpp_t, nkr::boolean::cpp_t>    \

        #define nkr_ANY_WITH_LVALUE                                                                     \
            nkr::tuple::types_t<nkr::boolean::cpp_t, nkr::boolean::cpp_t>,                              \
            nkr::tuple::types_t<nkr::boolean::cpp_t, const nkr::boolean::cpp_t>,                        \
            nkr::tuple::types_t<nkr::boolean::cpp_t, volatile nkr::boolean::cpp_t>,                     \
            nkr::tuple::types_t<nkr::boolean::cpp_t, const volatile nkr::boolean::cpp_t>,               \
            nkr::tuple::types_t<const nkr::boolean::cpp_t, nkr::boolean::cpp_t>,                        \
            nkr::tuple::types_t<const nkr::boolean::cpp_t, const nkr::boolean::cpp_t>,                  \
            nkr::tuple::types_t<const nkr::boolean::cpp_t, volatile nkr::boolean::cpp_t>,               \
            nkr::tuple::types_t<const nkr::boolean::cpp_t, const volatile nkr::boolean::cpp_t>,         \
            nkr::tuple::types_t<volatile nkr::boolean::cpp_t, nkr::boolean::cpp_t>,                     \
            nkr::tuple::types_t<volatile nkr::boolean::cpp_t, const nkr::boolean::cpp_t>,               \
            nkr::tuple::types_t<volatile nkr::boolean::cpp_t, volatile nkr::boolean::cpp_t>,            \
            nkr::tuple::types_t<volatile nkr::boolean::cpp_t, const volatile nkr::boolean::cpp_t>,      \
            nkr::tuple::types_t<const volatile nkr::boolean::cpp_t, nkr::boolean::cpp_t>,               \
            nkr::tuple::types_t<const volatile nkr::boolean::cpp_t, const nkr::boolean::cpp_t>,         \
            nkr::tuple::types_t<const volatile nkr::boolean::cpp_t, volatile nkr::boolean::cpp_t>,      \
            nkr::tuple::types_t<const volatile nkr::boolean::cpp_t, const volatile nkr::boolean::cpp_t> \

        #define nkr_ANY_WITH_RVALUE                                                                 \
            nkr::tuple::types_t<nkr::boolean::cpp_t, nkr::boolean::cpp_t>,                          \
            nkr::tuple::types_t<nkr::boolean::cpp_t, volatile nkr::boolean::cpp_t>,                 \
            nkr::tuple::types_t<const nkr::boolean::cpp_t, nkr::boolean::cpp_t>,                    \
            nkr::tuple::types_t<const nkr::boolean::cpp_t, volatile nkr::boolean::cpp_t>,           \
            nkr::tuple::types_t<volatile nkr::boolean::cpp_t, nkr::boolean::cpp_t>,                 \
            nkr::tuple::types_t<volatile nkr::boolean::cpp_t, volatile nkr::boolean::cpp_t>,        \
            nkr::tuple::types_t<const volatile nkr::boolean::cpp_t, nkr::boolean::cpp_t>,           \
            nkr::tuple::types_t<const volatile nkr::boolean::cpp_t, volatile nkr::boolean::cpp_t>   \

            TEST_CASE_TEMPLATE("unary logical operators: !", boolean_p, nkr_ANY)
            {
                using value_t = nkr::boolean::cpp_t;

                for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                    boolean_p a =
                        nkr::randomness::Value<boolean_p>();

                    CHECK(!a == !value_t(a));
                }
            }

            TEST_SUITE("binary logical operators: ||, &&")
            {
                TEST_CASE_TEMPLATE("value", tuple_p, nkr_ANY_WITH_VALUE)
                {
                    using boolean_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using non_qualified_t = nkr::cpp::just_non_qualified_t<boolean_t>;
                    using value_t = nkr::boolean::cpp_t;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        boolean_t a =
                            nkr::randomness::Value<boolean_t>();
                        other_t b =
                            nkr::randomness::Value<boolean_t>();

                        CHECK((a || non_qualified_t(b)) == (value_t(a) || value_t(b)));
                        CHECK((non_qualified_t(b) || a) == (value_t(b) || value_t(a)));
                        CHECK((non_qualified_t(a) || b) == (value_t(a) || value_t(b)));
                        CHECK((b || non_qualified_t(a)) == (value_t(b) || value_t(a)));
                        CHECK((non_qualified_t(a) || non_qualified_t(b)) == (value_t(a) || value_t(b)));
                        CHECK((non_qualified_t(b) || non_qualified_t(a)) == (value_t(b) || value_t(a)));

                        CHECK((a && non_qualified_t(b)) == (value_t(a) && value_t(b)));
                        CHECK((non_qualified_t(b) && a) == (value_t(b) && value_t(a)));
                        CHECK((non_qualified_t(a) && b) == (value_t(a) && value_t(b)));
                        CHECK((b && non_qualified_t(a)) == (value_t(b) && value_t(a)));
                        CHECK((non_qualified_t(a) && non_qualified_t(b)) == (value_t(a) && value_t(b)));
                        CHECK((non_qualified_t(b) && non_qualified_t(a)) == (value_t(b) && value_t(a)));
                    }
                }

                TEST_CASE_TEMPLATE("lvalue", tuple_p, nkr_ANY_WITH_LVALUE)
                {
                    using boolean_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using value_t = nkr::boolean::cpp_t;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        boolean_t a =
                            nkr::randomness::Value<boolean_t>();
                        other_t b =
                            nkr::randomness::Value<boolean_t>();

                        CHECK((a || b) == (value_t(a) || value_t(b)));
                        CHECK((b || a) == (value_t(b) || value_t(a)));

                        CHECK((a && b) == (value_t(a) && value_t(b)));
                        CHECK((b && a) == (value_t(b) && value_t(a)));
                    }
                }

                TEST_CASE_TEMPLATE("rvalue", tuple_p, nkr_ANY_WITH_RVALUE)
                {
                    using boolean_t = tuple_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = tuple_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using value_t = nkr::boolean::cpp_t;

                    for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                        boolean_t a =
                            nkr::randomness::Value<boolean_t>();
                        other_t b =
                            nkr::randomness::Value<boolean_t>();

                        CHECK((a || nkr::cpp::Move(b)) == (value_t(a) || value_t(b)));
                        CHECK((nkr::cpp::Move(b) || a) == (value_t(b) || value_t(a)));
                        if constexpr (nkr::cpp::any_non_const_tr<boolean_t>) {
                            CHECK((nkr::cpp::Move(a) || b) == (value_t(a) || value_t(b)));
                            CHECK((b || nkr::cpp::Move(a)) == (value_t(b) || value_t(a)));
                            CHECK((nkr::cpp::Move(a) || nkr::cpp::Move(b)) == (value_t(a) || value_t(b)));
                            CHECK((nkr::cpp::Move(b) || nkr::cpp::Move(a)) == (value_t(b) || value_t(a)));
                        }

                        CHECK((a && nkr::cpp::Move(b)) == (value_t(a) && value_t(b)));
                        CHECK((nkr::cpp::Move(b) && a) == (value_t(b) && value_t(a)));
                        if constexpr (nkr::cpp::any_non_const_tr<boolean_t>) {
                            CHECK((nkr::cpp::Move(a) && b) == (value_t(a) && value_t(b)));
                            CHECK((b && nkr::cpp::Move(a)) == (value_t(b) && value_t(a)));
                            CHECK((nkr::cpp::Move(a) && nkr::cpp::Move(b)) == (value_t(a) && value_t(b)));
                            CHECK((nkr::cpp::Move(b) && nkr::cpp::Move(a)) == (value_t(b) && value_t(a)));
                        }
                    }
                }
            }

            TEST_SUITE("trinary logical operators: ? :")
            {
                TEST_SUITE("non-qualified")
                {
                    TEST_CASE_TEMPLATE("value", boolean_p, nkr_ANY)
                    {
                        using non_qualified_t = nkr::cpp::just_non_qualified_t<boolean_p>;
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>();
                            nkr::cpp::just_non_qualified_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>();
                            nkr::cpp::just_non_qualified_t<boolean_p> c =
                                nkr::randomness::Value<boolean_p>();

                            CHECK((a ? non_qualified_t(b) : non_qualified_t(c)) == (value_t(a) ? value_t(b) : value_t(c)));
                            CHECK((a ? non_qualified_t(c) : non_qualified_t(b)) == (value_t(a) ? value_t(c) : value_t(b)));
                            CHECK((non_qualified_t(b) ? a : non_qualified_t(c)) == (value_t(b) ? value_t(a) : value_t(c)));
                            CHECK((non_qualified_t(b) ? non_qualified_t(c) : a) == (value_t(b) ? value_t(c) : value_t(a)));
                            CHECK((non_qualified_t(c) ? a : non_qualified_t(b)) == (value_t(c) ? value_t(a) : value_t(b)));
                            CHECK((non_qualified_t(c) ? non_qualified_t(b) : a) == (value_t(c) ? value_t(b) : value_t(a)));
                            CHECK((non_qualified_t(a) ? b : c) == (value_t(a) ? value_t(b) : value_t(c)));
                            CHECK((non_qualified_t(a) ? c : b) == (value_t(a) ? value_t(c) : value_t(b)));
                            CHECK((b ? non_qualified_t(a) : c) == (value_t(b) ? value_t(a) : value_t(c)));
                            CHECK((b ? c : non_qualified_t(a)) == (value_t(b) ? value_t(c) : value_t(a)));
                            CHECK((c ? non_qualified_t(a) : b) == (value_t(c) ? value_t(a) : value_t(b)));
                            CHECK((c ? b : non_qualified_t(a)) == (value_t(c) ? value_t(b) : value_t(a)));
                            CHECK((non_qualified_t(a) ? non_qualified_t(b) : non_qualified_t(c)) == (value_t(a) ? value_t(b) : value_t(c)));
                            CHECK((non_qualified_t(a) ? non_qualified_t(c) : non_qualified_t(b)) == (value_t(a) ? value_t(c) : value_t(b)));
                            CHECK((non_qualified_t(b) ? non_qualified_t(a) : non_qualified_t(c)) == (value_t(b) ? value_t(a) : value_t(c)));
                            CHECK((non_qualified_t(b) ? non_qualified_t(c) : non_qualified_t(a)) == (value_t(b) ? value_t(c) : value_t(a)));
                            CHECK((non_qualified_t(c) ? non_qualified_t(a) : non_qualified_t(b)) == (value_t(c) ? value_t(a) : value_t(b)));
                            CHECK((non_qualified_t(c) ? non_qualified_t(b) : non_qualified_t(a)) == (value_t(c) ? value_t(b) : value_t(a)));
                        }
                    }

                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>();
                            nkr::cpp::just_non_qualified_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>();
                            nkr::cpp::just_non_qualified_t<boolean_p> c =
                                nkr::randomness::Value<boolean_p>();

                            CHECK((a ? b : c) == (value_t(a) ? value_t(b) : value_t(c)));
                            CHECK((a ? c : b) == (value_t(a) ? value_t(c) : value_t(b)));
                            CHECK((b ? a : c) == (value_t(b) ? value_t(a) : value_t(c)));
                            CHECK((b ? c : a) == (value_t(b) ? value_t(c) : value_t(a)));
                            CHECK((c ? a : b) == (value_t(c) ? value_t(a) : value_t(b)));
                            CHECK((c ? b : a) == (value_t(c) ? value_t(b) : value_t(a)));
                        }
                    }

                    TEST_CASE_TEMPLATE("rvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>();
                            nkr::cpp::just_non_qualified_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>();
                            nkr::cpp::just_non_qualified_t<boolean_p> c =
                                nkr::randomness::Value<boolean_p>();

                            CHECK((a ? nkr::cpp::Move(b) : nkr::cpp::Move(c)) == (value_t(a) ? value_t(b) : value_t(c)));
                            CHECK((a ? nkr::cpp::Move(c) : nkr::cpp::Move(b)) == (value_t(a) ? value_t(c) : value_t(b)));
                            CHECK((nkr::cpp::Move(b) ? a : nkr::cpp::Move(c)) == (value_t(b) ? value_t(a) : value_t(c)));
                            CHECK((nkr::cpp::Move(b) ? nkr::cpp::Move(c) : a) == (value_t(b) ? value_t(c) : value_t(a)));
                            CHECK((nkr::cpp::Move(c) ? a : nkr::cpp::Move(b)) == (value_t(c) ? value_t(a) : value_t(b)));
                            CHECK((nkr::cpp::Move(c) ? nkr::cpp::Move(b) : a) == (value_t(c) ? value_t(b) : value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) ? b : c) == (value_t(a) ? value_t(b) : value_t(c)));
                                CHECK((nkr::cpp::Move(a) ? c : b) == (value_t(a) ? value_t(c) : value_t(b)));
                                CHECK((b ? nkr::cpp::Move(a) : c) == (value_t(b) ? value_t(a) : value_t(c)));
                                CHECK((b ? c : nkr::cpp::Move(a)) == (value_t(b) ? value_t(c) : value_t(a)));
                                CHECK((c ? nkr::cpp::Move(a) : b) == (value_t(c) ? value_t(a) : value_t(b)));
                                CHECK((c ? b : nkr::cpp::Move(a)) == (value_t(c) ? value_t(b) : value_t(a)));
                                CHECK((nkr::cpp::Move(a) ? nkr::cpp::Move(b) : nkr::cpp::Move(c)) == (value_t(a) ? value_t(b) : value_t(c)));
                                CHECK((nkr::cpp::Move(a) ? nkr::cpp::Move(c) : nkr::cpp::Move(b)) == (value_t(a) ? value_t(c) : value_t(b)));
                                CHECK((nkr::cpp::Move(b) ? nkr::cpp::Move(a) : nkr::cpp::Move(c)) == (value_t(b) ? value_t(a) : value_t(c)));
                                CHECK((nkr::cpp::Move(b) ? nkr::cpp::Move(c) : nkr::cpp::Move(a)) == (value_t(b) ? value_t(c) : value_t(a)));
                                CHECK((nkr::cpp::Move(c) ? nkr::cpp::Move(a) : nkr::cpp::Move(b)) == (value_t(c) ? value_t(a) : value_t(b)));
                                CHECK((nkr::cpp::Move(c) ? nkr::cpp::Move(b) : nkr::cpp::Move(a)) == (value_t(c) ? value_t(b) : value_t(a)));
                            }
                        }
                    }
                }

                TEST_SUITE("const")
                {
                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>();
                            nkr::cpp::just_const_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>();
                            nkr::cpp::just_const_t<boolean_p> c =
                                nkr::randomness::Value<boolean_p>();

                            CHECK((a ? b : c) == (value_t(a) ? value_t(b) : value_t(c)));
                            CHECK((a ? c : b) == (value_t(a) ? value_t(c) : value_t(b)));
                            CHECK((b ? a : c) == (value_t(b) ? value_t(a) : value_t(c)));
                            CHECK((b ? c : a) == (value_t(b) ? value_t(c) : value_t(a)));
                            CHECK((c ? a : b) == (value_t(c) ? value_t(a) : value_t(b)));
                            CHECK((c ? b : a) == (value_t(c) ? value_t(b) : value_t(a)));
                        }
                    }
                }

                TEST_SUITE("volatile")
                {
                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>();
                            nkr::cpp::just_volatile_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>();
                            nkr::cpp::just_volatile_t<boolean_p> c =
                                nkr::randomness::Value<boolean_p>();

                            CHECK((a ? b : c) == (value_t(a) ? value_t(b) : value_t(c)));
                            CHECK((a ? c : b) == (value_t(a) ? value_t(c) : value_t(b)));
                            CHECK((b ? a : c) == (value_t(b) ? value_t(a) : value_t(c)));
                            CHECK((b ? c : a) == (value_t(b) ? value_t(c) : value_t(a)));
                            CHECK((c ? a : b) == (value_t(c) ? value_t(a) : value_t(b)));
                            CHECK((c ? b : a) == (value_t(c) ? value_t(b) : value_t(a)));
                        }
                    }

                    TEST_CASE_TEMPLATE("rvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>();
                            nkr::cpp::just_volatile_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>();
                            nkr::cpp::just_volatile_t<boolean_p> c =
                                nkr::randomness::Value<boolean_p>();

                            CHECK((a ? nkr::cpp::Move(b) : nkr::cpp::Move(c)) == (value_t(a) ? value_t(b) : value_t(c)));
                            CHECK((a ? nkr::cpp::Move(c) : nkr::cpp::Move(b)) == (value_t(a) ? value_t(c) : value_t(b)));
                            CHECK((nkr::cpp::Move(b) ? a : nkr::cpp::Move(c)) == (value_t(b) ? value_t(a) : value_t(c)));
                            CHECK((nkr::cpp::Move(b) ? nkr::cpp::Move(c) : a) == (value_t(b) ? value_t(c) : value_t(a)));
                            CHECK((nkr::cpp::Move(c) ? a : nkr::cpp::Move(b)) == (value_t(c) ? value_t(a) : value_t(b)));
                            CHECK((nkr::cpp::Move(c) ? nkr::cpp::Move(b) : a) == (value_t(c) ? value_t(b) : value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) ? b : c) == (value_t(a) ? value_t(b) : value_t(c)));
                                CHECK((nkr::cpp::Move(a) ? c : b) == (value_t(a) ? value_t(c) : value_t(b)));
                                CHECK((b ? nkr::cpp::Move(a) : c) == (value_t(b) ? value_t(a) : value_t(c)));
                                CHECK((b ? c : nkr::cpp::Move(a)) == (value_t(b) ? value_t(c) : value_t(a)));
                                CHECK((c ? nkr::cpp::Move(a) : b) == (value_t(c) ? value_t(a) : value_t(b)));
                                CHECK((c ? b : nkr::cpp::Move(a)) == (value_t(c) ? value_t(b) : value_t(a)));
                                CHECK((nkr::cpp::Move(a) ? nkr::cpp::Move(b) : nkr::cpp::Move(c)) == (value_t(a) ? value_t(b) : value_t(c)));
                                CHECK((nkr::cpp::Move(a) ? nkr::cpp::Move(c) : nkr::cpp::Move(b)) == (value_t(a) ? value_t(c) : value_t(b)));
                                CHECK((nkr::cpp::Move(b) ? nkr::cpp::Move(a) : nkr::cpp::Move(c)) == (value_t(b) ? value_t(a) : value_t(c)));
                                CHECK((nkr::cpp::Move(b) ? nkr::cpp::Move(c) : nkr::cpp::Move(a)) == (value_t(b) ? value_t(c) : value_t(a)));
                                CHECK((nkr::cpp::Move(c) ? nkr::cpp::Move(a) : nkr::cpp::Move(b)) == (value_t(c) ? value_t(a) : value_t(b)));
                                CHECK((nkr::cpp::Move(c) ? nkr::cpp::Move(b) : nkr::cpp::Move(a)) == (value_t(c) ? value_t(b) : value_t(a)));
                            }
                        }
                    }
                }

                TEST_SUITE("const volatile")
                {
                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>();
                            nkr::cpp::just_const_volatile_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>();
                            nkr::cpp::just_const_volatile_t<boolean_p> c =
                                nkr::randomness::Value<boolean_p>();

                            CHECK((a ? b : c) == (value_t(a) ? value_t(b) : value_t(c)));
                            CHECK((a ? c : b) == (value_t(a) ? value_t(c) : value_t(b)));
                            CHECK((b ? a : c) == (value_t(b) ? value_t(a) : value_t(c)));
                            CHECK((b ? c : a) == (value_t(b) ? value_t(c) : value_t(a)));
                            CHECK((c ? a : b) == (value_t(c) ? value_t(a) : value_t(b)));
                            CHECK((c ? b : a) == (value_t(c) ? value_t(b) : value_t(a)));
                        }
                    }
                }
            }

            TEST_SUITE("binary comparison operators: ==, !=, <, >, <=, >=, <=>")
            {
                TEST_SUITE("non-qualified")
                {
                    TEST_CASE_TEMPLATE("value", boolean_p, nkr_ANY)
                    {
                        using non_qualified_t = nkr::cpp::just_non_qualified_t<boolean_p>;
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>();
                            nkr::cpp::just_non_qualified_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>();

                            CHECK((a == non_qualified_t(b)) == (value_t(a) == value_t(b)));
                            CHECK((non_qualified_t(b) == a) == (value_t(b) == value_t(a)));
                            CHECK((non_qualified_t(a) == b) == (value_t(a) == value_t(b)));
                            CHECK((b == non_qualified_t(a)) == (value_t(b) == value_t(a)));
                            CHECK((non_qualified_t(a) == non_qualified_t(b)) == (value_t(a) == value_t(b)));
                            CHECK((non_qualified_t(b) == non_qualified_t(a)) == (value_t(b) == value_t(a)));

                            CHECK((a != non_qualified_t(b)) == (value_t(a) != value_t(b)));
                            CHECK((non_qualified_t(b) != a) == (value_t(b) != value_t(a)));
                            CHECK((non_qualified_t(a) != b) == (value_t(a) != value_t(b)));
                            CHECK((b != non_qualified_t(a)) == (value_t(b) != value_t(a)));
                            CHECK((non_qualified_t(a) != non_qualified_t(b)) == (value_t(a) != value_t(b)));
                            CHECK((non_qualified_t(b) != non_qualified_t(a)) == (value_t(b) != value_t(a)));

                            CHECK((a < non_qualified_t(b)) == (value_t(a) < value_t(b)));
                            CHECK((non_qualified_t(b) < a) == (value_t(b) < value_t(a)));
                            CHECK((non_qualified_t(a) < b) == (value_t(a) < value_t(b)));
                            CHECK((b < non_qualified_t(a)) == (value_t(b) < value_t(a)));
                            CHECK((non_qualified_t(a) < non_qualified_t(b)) == (value_t(a) < value_t(b)));
                            CHECK((non_qualified_t(b) < non_qualified_t(a)) == (value_t(b) < value_t(a)));

                            CHECK((a > non_qualified_t(b)) == (value_t(a) > value_t(b)));
                            CHECK((non_qualified_t(b) > a) == (value_t(b) > value_t(a)));
                            CHECK((non_qualified_t(a) > b) == (value_t(a) > value_t(b)));
                            CHECK((b > non_qualified_t(a)) == (value_t(b) > value_t(a)));
                            CHECK((non_qualified_t(a) > non_qualified_t(b)) == (value_t(a) > value_t(b)));
                            CHECK((non_qualified_t(b) > non_qualified_t(a)) == (value_t(b) > value_t(a)));

                            CHECK((a <= non_qualified_t(b)) == (value_t(a) <= value_t(b)));
                            CHECK((non_qualified_t(b) <= a) == (value_t(b) <= value_t(a)));
                            CHECK((non_qualified_t(a) <= b) == (value_t(a) <= value_t(b)));
                            CHECK((b <= non_qualified_t(a)) == (value_t(b) <= value_t(a)));
                            CHECK((non_qualified_t(a) <= non_qualified_t(b)) == (value_t(a) <= value_t(b)));
                            CHECK((non_qualified_t(b) <= non_qualified_t(a)) == (value_t(b) <= value_t(a)));

                            CHECK((a >= non_qualified_t(b)) == (value_t(a) >= value_t(b)));
                            CHECK((non_qualified_t(b) >= a) == (value_t(b) >= value_t(a)));
                            CHECK((non_qualified_t(a) >= b) == (value_t(a) >= value_t(b)));
                            CHECK((b >= non_qualified_t(a)) == (value_t(b) >= value_t(a)));
                            CHECK((non_qualified_t(a) >= non_qualified_t(b)) == (value_t(a) >= value_t(b)));
                            CHECK((non_qualified_t(b) >= non_qualified_t(a)) == (value_t(b) >= value_t(a)));

                            CHECK((a <=> non_qualified_t(b)) == (value_t(a) <=> value_t(b)));
                            CHECK((non_qualified_t(b) <=> a) == (value_t(b) <=> value_t(a)));
                            CHECK((non_qualified_t(a) <=> b) == (value_t(a) <=> value_t(b)));
                            CHECK((b <=> non_qualified_t(a)) == (value_t(b) <=> value_t(a)));
                            CHECK((non_qualified_t(a) <=> non_qualified_t(b)) == (value_t(a) <=> value_t(b)));
                            CHECK((non_qualified_t(b) <=> non_qualified_t(a)) == (value_t(b) <=> value_t(a)));
                        }
                    }

                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>();
                            nkr::cpp::just_non_qualified_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>();

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

                    TEST_CASE_TEMPLATE("rvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>();
                            nkr::cpp::just_non_qualified_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>();

                            CHECK((a == nkr::cpp::Move(b)) == (value_t(a) == value_t(b)));
                            CHECK((nkr::cpp::Move(b) == a) == (value_t(b) == value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) == b) == (value_t(a) == value_t(b)));
                                CHECK((b == nkr::cpp::Move(a)) == (value_t(b) == value_t(a)));
                                CHECK((nkr::cpp::Move(a) == nkr::cpp::Move(b)) == (value_t(a) == value_t(b)));
                                CHECK((nkr::cpp::Move(b) == nkr::cpp::Move(a)) == (value_t(b) == value_t(a)));
                            }

                            CHECK((a != nkr::cpp::Move(b)) == (value_t(a) != value_t(b)));
                            CHECK((nkr::cpp::Move(b) != a) == (value_t(b) != value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) != b) == (value_t(a) != value_t(b)));
                                CHECK((b != nkr::cpp::Move(a)) == (value_t(b) != value_t(a)));
                                CHECK((nkr::cpp::Move(a) != nkr::cpp::Move(b)) == (value_t(a) != value_t(b)));
                                CHECK((nkr::cpp::Move(b) != nkr::cpp::Move(a)) == (value_t(b) != value_t(a)));
                            }

                            CHECK((a < nkr::cpp::Move(b)) == (value_t(a) < value_t(b)));
                            CHECK((nkr::cpp::Move(b) < a) == (value_t(b) < value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) < b) == (value_t(a) < value_t(b)));
                                CHECK((b < nkr::cpp::Move(a)) == (value_t(b) < value_t(a)));
                                CHECK((nkr::cpp::Move(a) < nkr::cpp::Move(b)) == (value_t(a) < value_t(b)));
                                CHECK((nkr::cpp::Move(b) < nkr::cpp::Move(a)) == (value_t(b) < value_t(a)));
                            }

                            CHECK((a > nkr::cpp::Move(b)) == (value_t(a) > value_t(b)));
                            CHECK((nkr::cpp::Move(b) > a) == (value_t(b) > value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) > b) == (value_t(a) > value_t(b)));
                                CHECK((b > nkr::cpp::Move(a)) == (value_t(b) > value_t(a)));
                                CHECK((nkr::cpp::Move(a) > nkr::cpp::Move(b)) == (value_t(a) > value_t(b)));
                                CHECK((nkr::cpp::Move(b) > nkr::cpp::Move(a)) == (value_t(b) > value_t(a)));
                            }

                            CHECK((a <= nkr::cpp::Move(b)) == (value_t(a) <= value_t(b)));
                            CHECK((nkr::cpp::Move(b) <= a) == (value_t(b) <= value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) <= b) == (value_t(a) <= value_t(b)));
                                CHECK((b <= nkr::cpp::Move(a)) == (value_t(b) <= value_t(a)));
                                CHECK((nkr::cpp::Move(a) <= nkr::cpp::Move(b)) == (value_t(a) <= value_t(b)));
                                CHECK((nkr::cpp::Move(b) <= nkr::cpp::Move(a)) == (value_t(b) <= value_t(a)));
                            }

                            CHECK((a >= nkr::cpp::Move(b)) == (value_t(a) >= value_t(b)));
                            CHECK((nkr::cpp::Move(b) >= a) == (value_t(b) >= value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) >= b) == (value_t(a) >= value_t(b)));
                                CHECK((b >= nkr::cpp::Move(a)) == (value_t(b) >= value_t(a)));
                                CHECK((nkr::cpp::Move(a) >= nkr::cpp::Move(b)) == (value_t(a) >= value_t(b)));
                                CHECK((nkr::cpp::Move(b) >= nkr::cpp::Move(a)) == (value_t(b) >= value_t(a)));
                            }

                            CHECK((a <=> nkr::cpp::Move(b)) == (value_t(a) <=> value_t(b)));
                            CHECK((nkr::cpp::Move(b) <=> a) == (value_t(b) <=> value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) <=> b) == (value_t(a) <=> value_t(b)));
                                CHECK((b <=> nkr::cpp::Move(a)) == (value_t(b) <=> value_t(a)));
                                CHECK((nkr::cpp::Move(a) <=> nkr::cpp::Move(b)) == (value_t(a) <=> value_t(b)));
                                CHECK((nkr::cpp::Move(b) <=> nkr::cpp::Move(a)) == (value_t(b) <=> value_t(a)));
                            }
                        }
                    }
                }

                TEST_SUITE("const")
                {
                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>();
                            nkr::cpp::just_const_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>();

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
                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>();
                            nkr::cpp::just_volatile_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>();

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

                    TEST_CASE_TEMPLATE("rvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>();
                            nkr::cpp::just_volatile_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>();

                            CHECK((a == nkr::cpp::Move(b)) == (value_t(a) == value_t(b)));
                            CHECK((nkr::cpp::Move(b) == a) == (value_t(b) == value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) == b) == (value_t(a) == value_t(b)));
                                CHECK((b == nkr::cpp::Move(a)) == (value_t(b) == value_t(a)));
                                CHECK((nkr::cpp::Move(a) == nkr::cpp::Move(b)) == (value_t(a) == value_t(b)));
                                CHECK((nkr::cpp::Move(b) == nkr::cpp::Move(a)) == (value_t(b) == value_t(a)));
                            }

                            CHECK((a != nkr::cpp::Move(b)) == (value_t(a) != value_t(b)));
                            CHECK((nkr::cpp::Move(b) != a) == (value_t(b) != value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) != b) == (value_t(a) != value_t(b)));
                                CHECK((b != nkr::cpp::Move(a)) == (value_t(b) != value_t(a)));
                                CHECK((nkr::cpp::Move(a) != nkr::cpp::Move(b)) == (value_t(a) != value_t(b)));
                                CHECK((nkr::cpp::Move(b) != nkr::cpp::Move(a)) == (value_t(b) != value_t(a)));
                            }

                            CHECK((a < nkr::cpp::Move(b)) == (value_t(a) < value_t(b)));
                            CHECK((nkr::cpp::Move(b) < a) == (value_t(b) < value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) < b) == (value_t(a) < value_t(b)));
                                CHECK((b < nkr::cpp::Move(a)) == (value_t(b) < value_t(a)));
                                CHECK((nkr::cpp::Move(a) < nkr::cpp::Move(b)) == (value_t(a) < value_t(b)));
                                CHECK((nkr::cpp::Move(b) < nkr::cpp::Move(a)) == (value_t(b) < value_t(a)));
                            }

                            CHECK((a > nkr::cpp::Move(b)) == (value_t(a) > value_t(b)));
                            CHECK((nkr::cpp::Move(b) > a) == (value_t(b) > value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) > b) == (value_t(a) > value_t(b)));
                                CHECK((b > nkr::cpp::Move(a)) == (value_t(b) > value_t(a)));
                                CHECK((nkr::cpp::Move(a) > nkr::cpp::Move(b)) == (value_t(a) > value_t(b)));
                                CHECK((nkr::cpp::Move(b) > nkr::cpp::Move(a)) == (value_t(b) > value_t(a)));
                            }

                            CHECK((a <= nkr::cpp::Move(b)) == (value_t(a) <= value_t(b)));
                            CHECK((nkr::cpp::Move(b) <= a) == (value_t(b) <= value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) <= b) == (value_t(a) <= value_t(b)));
                                CHECK((b <= nkr::cpp::Move(a)) == (value_t(b) <= value_t(a)));
                                CHECK((nkr::cpp::Move(a) <= nkr::cpp::Move(b)) == (value_t(a) <= value_t(b)));
                                CHECK((nkr::cpp::Move(b) <= nkr::cpp::Move(a)) == (value_t(b) <= value_t(a)));
                            }

                            CHECK((a >= nkr::cpp::Move(b)) == (value_t(a) >= value_t(b)));
                            CHECK((nkr::cpp::Move(b) >= a) == (value_t(b) >= value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) >= b) == (value_t(a) >= value_t(b)));
                                CHECK((b >= nkr::cpp::Move(a)) == (value_t(b) >= value_t(a)));
                                CHECK((nkr::cpp::Move(a) >= nkr::cpp::Move(b)) == (value_t(a) >= value_t(b)));
                                CHECK((nkr::cpp::Move(b) >= nkr::cpp::Move(a)) == (value_t(b) >= value_t(a)));
                            }

                            CHECK((a <=> nkr::cpp::Move(b)) == (value_t(a) <=> value_t(b)));
                            CHECK((nkr::cpp::Move(b) <=> a) == (value_t(b) <=> value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) <=> b) == (value_t(a) <=> value_t(b)));
                                CHECK((b <=> nkr::cpp::Move(a)) == (value_t(b) <=> value_t(a)));
                                CHECK((nkr::cpp::Move(a) <=> nkr::cpp::Move(b)) == (value_t(a) <=> value_t(b)));
                                CHECK((nkr::cpp::Move(b) <=> nkr::cpp::Move(a)) == (value_t(b) <=> value_t(a)));
                            }
                        }
                    }
                }

                TEST_SUITE("const volatile")
                {
                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>();
                            nkr::cpp::just_const_volatile_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>();

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

            TEST_CASE_TEMPLATE("unary arithmetic operators: +, -", boolean_p, nkr_ANY)
            {
                using value_t = nkr::boolean::cpp_t;

                for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                    boolean_p a =
                        nkr::randomness::Value<boolean_p>();

                    CHECK(+a == +value_t(a));

                    CHECK(-a == -value_t(a));
                }
            }

            TEST_SUITE("binary arithmetic operators: +, -, *, /, %")
            {
                TEST_SUITE("non-qualified")
                {
                    TEST_CASE_TEMPLATE("value", boolean_p, nkr_ANY)
                    {
                        using non_qualified_t = nkr::cpp::just_non_qualified_t<boolean_p>;
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>(true, true);
                            nkr::cpp::just_non_qualified_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>(true, true);

                            CHECK((a + non_qualified_t(b)) == (value_t(a) + value_t(b)));
                            CHECK((non_qualified_t(b) + a) == (value_t(b) + value_t(a)));
                            CHECK((non_qualified_t(a) + b) == (value_t(a) + value_t(b)));
                            CHECK((b + non_qualified_t(a)) == (value_t(b) + value_t(a)));
                            CHECK((non_qualified_t(a) + non_qualified_t(b)) == (value_t(a) + value_t(b)));
                            CHECK((non_qualified_t(b) + non_qualified_t(a)) == (value_t(b) + value_t(a)));

                            CHECK((a - non_qualified_t(b)) == (value_t(a) - value_t(b)));
                            CHECK((non_qualified_t(b) - a) == (value_t(b) - value_t(a)));
                            CHECK((non_qualified_t(a) - b) == (value_t(a) - value_t(b)));
                            CHECK((b - non_qualified_t(a)) == (value_t(b) - value_t(a)));
                            CHECK((non_qualified_t(a) - non_qualified_t(b)) == (value_t(a) - value_t(b)));
                            CHECK((non_qualified_t(b) - non_qualified_t(a)) == (value_t(b) - value_t(a)));

                            CHECK((a * non_qualified_t(b)) == (value_t(a) * value_t(b)));
                            CHECK((non_qualified_t(b) * a) == (value_t(b) * value_t(a)));
                            CHECK((non_qualified_t(a) * b) == (value_t(a) * value_t(b)));
                            CHECK((b * non_qualified_t(a)) == (value_t(b) * value_t(a)));
                            CHECK((non_qualified_t(a) * non_qualified_t(b)) == (value_t(a) * value_t(b)));
                            CHECK((non_qualified_t(b) * non_qualified_t(a)) == (value_t(b) * value_t(a)));

                            CHECK((a / non_qualified_t(b)) == (value_t(a) / value_t(b)));
                            CHECK((non_qualified_t(b) / a) == (value_t(b) / value_t(a)));
                            CHECK((non_qualified_t(a) / b) == (value_t(a) / value_t(b)));
                            CHECK((b / non_qualified_t(a)) == (value_t(b) / value_t(a)));
                            CHECK((non_qualified_t(a) / non_qualified_t(b)) == (value_t(a) / value_t(b)));
                            CHECK((non_qualified_t(b) / non_qualified_t(a)) == (value_t(b) / value_t(a)));

                            CHECK((a % non_qualified_t(b)) == (value_t(a) % value_t(b)));
                            CHECK((non_qualified_t(b) % a) == (value_t(b) % value_t(a)));
                            CHECK((non_qualified_t(a) % b) == (value_t(a) % value_t(b)));
                            CHECK((b % non_qualified_t(a)) == (value_t(b) % value_t(a)));
                            CHECK((non_qualified_t(a) % non_qualified_t(b)) == (value_t(a) % value_t(b)));
                            CHECK((non_qualified_t(b) % non_qualified_t(a)) == (value_t(b) % value_t(a)));
                        }
                    }

                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>(true, true);
                            nkr::cpp::just_non_qualified_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>(true, true);

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

                    TEST_CASE_TEMPLATE("rvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>(true, true);
                            nkr::cpp::just_non_qualified_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>(true, true);

                            CHECK((a + nkr::cpp::Move(b)) == (value_t(a) + value_t(b)));
                            CHECK((nkr::cpp::Move(b) + a) == (value_t(b) + value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) + b) == (value_t(a) + value_t(b)));
                                CHECK((b + nkr::cpp::Move(a)) == (value_t(b) + value_t(a)));
                                CHECK((nkr::cpp::Move(a) + nkr::cpp::Move(b)) == (value_t(a) + value_t(b)));
                                CHECK((nkr::cpp::Move(b) + nkr::cpp::Move(a)) == (value_t(b) + value_t(a)));
                            }

                            CHECK((a - nkr::cpp::Move(b)) == (value_t(a) - value_t(b)));
                            CHECK((nkr::cpp::Move(b) - a) == (value_t(b) - value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) - b) == (value_t(a) - value_t(b)));
                                CHECK((b - nkr::cpp::Move(a)) == (value_t(b) - value_t(a)));
                                CHECK((nkr::cpp::Move(a) - nkr::cpp::Move(b)) == (value_t(a) - value_t(b)));
                                CHECK((nkr::cpp::Move(b) - nkr::cpp::Move(a)) == (value_t(b) - value_t(a)));
                            }

                            CHECK((a * nkr::cpp::Move(b)) == (value_t(a) * value_t(b)));
                            CHECK((nkr::cpp::Move(b) * a) == (value_t(b) * value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) * b) == (value_t(a) * value_t(b)));
                                CHECK((b * nkr::cpp::Move(a)) == (value_t(b) * value_t(a)));
                                CHECK((nkr::cpp::Move(a) * nkr::cpp::Move(b)) == (value_t(a) * value_t(b)));
                                CHECK((nkr::cpp::Move(b) * nkr::cpp::Move(a)) == (value_t(b) * value_t(a)));
                            }

                            CHECK((a / nkr::cpp::Move(b)) == (value_t(a) / value_t(b)));
                            CHECK((nkr::cpp::Move(b) / a) == (value_t(b) / value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) / b) == (value_t(a) / value_t(b)));
                                CHECK((b / nkr::cpp::Move(a)) == (value_t(b) / value_t(a)));
                                CHECK((nkr::cpp::Move(a) / nkr::cpp::Move(b)) == (value_t(a) / value_t(b)));
                                CHECK((nkr::cpp::Move(b) / nkr::cpp::Move(a)) == (value_t(b) / value_t(a)));
                            }

                            CHECK((a % nkr::cpp::Move(b)) == (value_t(a) % value_t(b)));
                            CHECK((nkr::cpp::Move(b) % a) == (value_t(b) % value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) % b) == (value_t(a) % value_t(b)));
                                CHECK((b % nkr::cpp::Move(a)) == (value_t(b) % value_t(a)));
                                CHECK((nkr::cpp::Move(a) % nkr::cpp::Move(b)) == (value_t(a) % value_t(b)));
                                CHECK((nkr::cpp::Move(b) % nkr::cpp::Move(a)) == (value_t(b) % value_t(a)));
                            }
                        }
                    }
                }

                TEST_SUITE("const")
                {
                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>(true, true);
                            nkr::cpp::just_const_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>(true, true);

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
                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>(true, true);
                            nkr::cpp::just_volatile_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>(true, true);

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

                    TEST_CASE_TEMPLATE("rvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>(true, true);
                            nkr::cpp::just_volatile_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>(true, true);

                            CHECK((a + nkr::cpp::Move(b)) == (value_t(a) + value_t(b)));
                            CHECK((nkr::cpp::Move(b) + a) == (value_t(b) + value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) + b) == (value_t(a) + value_t(b)));
                                CHECK((b + nkr::cpp::Move(a)) == (value_t(b) + value_t(a)));
                                CHECK((nkr::cpp::Move(a) + nkr::cpp::Move(b)) == (value_t(a) + value_t(b)));
                                CHECK((nkr::cpp::Move(b) + nkr::cpp::Move(a)) == (value_t(b) + value_t(a)));
                            }

                            CHECK((a - nkr::cpp::Move(b)) == (value_t(a) - value_t(b)));
                            CHECK((nkr::cpp::Move(b) - a) == (value_t(b) - value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) - b) == (value_t(a) - value_t(b)));
                                CHECK((b - nkr::cpp::Move(a)) == (value_t(b) - value_t(a)));
                                CHECK((nkr::cpp::Move(a) - nkr::cpp::Move(b)) == (value_t(a) - value_t(b)));
                                CHECK((nkr::cpp::Move(b) - nkr::cpp::Move(a)) == (value_t(b) - value_t(a)));
                            }

                            CHECK((a * nkr::cpp::Move(b)) == (value_t(a) * value_t(b)));
                            CHECK((nkr::cpp::Move(b) * a) == (value_t(b) * value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) * b) == (value_t(a) * value_t(b)));
                                CHECK((b * nkr::cpp::Move(a)) == (value_t(b) * value_t(a)));
                                CHECK((nkr::cpp::Move(a) * nkr::cpp::Move(b)) == (value_t(a) * value_t(b)));
                                CHECK((nkr::cpp::Move(b) * nkr::cpp::Move(a)) == (value_t(b) * value_t(a)));
                            }

                            CHECK((a / nkr::cpp::Move(b)) == (value_t(a) / value_t(b)));
                            CHECK((nkr::cpp::Move(b) / a) == (value_t(b) / value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) / b) == (value_t(a) / value_t(b)));
                                CHECK((b / nkr::cpp::Move(a)) == (value_t(b) / value_t(a)));
                                CHECK((nkr::cpp::Move(a) / nkr::cpp::Move(b)) == (value_t(a) / value_t(b)));
                                CHECK((nkr::cpp::Move(b) / nkr::cpp::Move(a)) == (value_t(b) / value_t(a)));
                            }

                            CHECK((a % nkr::cpp::Move(b)) == (value_t(a) % value_t(b)));
                            CHECK((nkr::cpp::Move(b) % a) == (value_t(b) % value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) % b) == (value_t(a) % value_t(b)));
                                CHECK((b % nkr::cpp::Move(a)) == (value_t(b) % value_t(a)));
                                CHECK((nkr::cpp::Move(a) % nkr::cpp::Move(b)) == (value_t(a) % value_t(b)));
                                CHECK((nkr::cpp::Move(b) % nkr::cpp::Move(a)) == (value_t(b) % value_t(a)));
                            }
                        }
                    }
                }

                TEST_SUITE("const volatile")
                {
                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>(true, true);
                            nkr::cpp::just_const_volatile_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>(true, true);

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

            TEST_SUITE("binary arithmetic operators: +=, -=, *=, /=, %=")
            {
                TEST_SUITE("non-qualified")
                {
                    TEST_CASE_TEMPLATE("value", boolean_p, nkr_ANY)
                    {

                    }

                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {

                    }

                    TEST_CASE_TEMPLATE("rvalue", boolean_p, nkr_ANY)
                    {

                    }
                }

                TEST_SUITE("const")
                {
                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {

                    }
                }

                TEST_SUITE("volatile")
                {
                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {

                    }

                    TEST_CASE_TEMPLATE("rvalue", boolean_p, nkr_ANY)
                    {

                    }
                }

                TEST_SUITE("const volatile")
                {
                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {

                    }
                }
            }

            TEST_CASE_TEMPLATE("unary bitwise operators: ~", boolean_p, nkr_ANY)
            {
                using value_t = nkr::boolean::cpp_t;

                for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                    boolean_p a =
                        nkr::randomness::Value<boolean_p>();

                    CHECK(~a == ~value_t(a));
                }
            }

            TEST_SUITE("binary bitwise operators: |, &, ^, <<, >>")
            {
                TEST_SUITE("non-qualified")
                {
                    TEST_CASE_TEMPLATE("value", boolean_p, nkr_ANY)
                    {
                        using non_qualified_t = nkr::cpp::just_non_qualified_t<boolean_p>;
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>(true, true);
                            nkr::cpp::just_non_qualified_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>(true, true);
                            nkr::cpp::just_non_qualified_t<boolean_p> c =
                                nkr::randomness::Value<boolean_p>(false, true);

                            CHECK((a | non_qualified_t(b)) == (value_t(a) | value_t(b)));
                            CHECK((non_qualified_t(b) | a) == (value_t(b) | value_t(a)));
                            CHECK((non_qualified_t(a) | b) == (value_t(a) | value_t(b)));
                            CHECK((b | non_qualified_t(a)) == (value_t(b) | value_t(a)));
                            CHECK((non_qualified_t(a) | non_qualified_t(b)) == (value_t(a) | value_t(b)));
                            CHECK((non_qualified_t(b) | non_qualified_t(a)) == (value_t(b) | value_t(a)));

                            CHECK((a & non_qualified_t(b)) == (value_t(a) & value_t(b)));
                            CHECK((non_qualified_t(b) & a) == (value_t(b) & value_t(a)));
                            CHECK((non_qualified_t(a) & b) == (value_t(a) & value_t(b)));
                            CHECK((b & non_qualified_t(a)) == (value_t(b) & value_t(a)));
                            CHECK((non_qualified_t(a) & non_qualified_t(b)) == (value_t(a) & value_t(b)));
                            CHECK((non_qualified_t(b) & non_qualified_t(a)) == (value_t(b) & value_t(a)));

                            CHECK((a ^ non_qualified_t(b)) == (value_t(a) ^ value_t(b)));
                            CHECK((non_qualified_t(b) ^ a) == (value_t(b) ^ value_t(a)));
                            CHECK((non_qualified_t(a) ^ b) == (value_t(a) ^ value_t(b)));
                            CHECK((b ^ non_qualified_t(a)) == (value_t(b) ^ value_t(a)));
                            CHECK((non_qualified_t(a) ^ non_qualified_t(b)) == (value_t(a) ^ value_t(b)));
                            CHECK((non_qualified_t(b) ^ non_qualified_t(a)) == (value_t(b) ^ value_t(a)));

                            CHECK((a << non_qualified_t(c)) == (value_t(a) << value_t(c)));
                            CHECK((non_qualified_t(c) << a) == (value_t(c) << value_t(a)));
                            CHECK((non_qualified_t(a) << c) == (value_t(a) << value_t(c)));
                            CHECK((c << non_qualified_t(a)) == (value_t(c) << value_t(a)));
                            CHECK((non_qualified_t(a) << non_qualified_t(c)) == (value_t(a) << value_t(c)));
                            CHECK((non_qualified_t(c) << non_qualified_t(a)) == (value_t(c) << value_t(a)));

                            CHECK((a >> non_qualified_t(c)) == (value_t(a) >> value_t(c)));
                            CHECK((non_qualified_t(c) >> a) == (value_t(c) >> value_t(a)));
                            CHECK((non_qualified_t(a) >> c) == (value_t(a) >> value_t(c)));
                            CHECK((c >> non_qualified_t(a)) == (value_t(c) >> value_t(a)));
                            CHECK((non_qualified_t(a) >> non_qualified_t(c)) == (value_t(a) >> value_t(c)));
                            CHECK((non_qualified_t(c) >> non_qualified_t(a)) == (value_t(c) >> value_t(a)));
                        }
                    }

                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>(true, true);
                            nkr::cpp::just_non_qualified_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>(true, true);
                            nkr::cpp::just_non_qualified_t<boolean_p> c =
                                nkr::randomness::Value<boolean_p>(false, true);

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

                    TEST_CASE_TEMPLATE("rvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>(true, true);
                            nkr::cpp::just_non_qualified_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>(true, true);
                            nkr::cpp::just_non_qualified_t<boolean_p> c =
                                nkr::randomness::Value<boolean_p>(false, true);

                            CHECK((a | nkr::cpp::Move(b)) == (value_t(a) | value_t(b)));
                            CHECK((nkr::cpp::Move(b) | a) == (value_t(b) | value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) | b) == (value_t(a) | value_t(b)));
                                CHECK((b | nkr::cpp::Move(a)) == (value_t(b) | value_t(a)));
                                CHECK((nkr::cpp::Move(a) | nkr::cpp::Move(b)) == (value_t(a) | value_t(b)));
                                CHECK((nkr::cpp::Move(b) | nkr::cpp::Move(a)) == (value_t(b) | value_t(a)));
                            }

                            CHECK((a & nkr::cpp::Move(b)) == (value_t(a) & value_t(b)));
                            CHECK((nkr::cpp::Move(b) & a) == (value_t(b) & value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) & b) == (value_t(a) & value_t(b)));
                                CHECK((b & nkr::cpp::Move(a)) == (value_t(b) & value_t(a)));
                                CHECK((nkr::cpp::Move(a) & nkr::cpp::Move(b)) == (value_t(a) & value_t(b)));
                                CHECK((nkr::cpp::Move(b) & nkr::cpp::Move(a)) == (value_t(b) & value_t(a)));
                            }

                            CHECK((a ^ nkr::cpp::Move(b)) == (value_t(a) ^ value_t(b)));
                            CHECK((nkr::cpp::Move(b) ^ a) == (value_t(b) ^ value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) ^ b) == (value_t(a) ^ value_t(b)));
                                CHECK((b ^ nkr::cpp::Move(a)) == (value_t(b) ^ value_t(a)));
                                CHECK((nkr::cpp::Move(a) ^ nkr::cpp::Move(b)) == (value_t(a) ^ value_t(b)));
                                CHECK((nkr::cpp::Move(b) ^ nkr::cpp::Move(a)) == (value_t(b) ^ value_t(a)));
                            }

                            CHECK((a << nkr::cpp::Move(c)) == (value_t(a) << value_t(c)));
                            CHECK((nkr::cpp::Move(c) << a) == (value_t(c) << value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) << c) == (value_t(a) << value_t(c)));
                                CHECK((c << nkr::cpp::Move(a)) == (value_t(c) << value_t(a)));
                                CHECK((nkr::cpp::Move(a) << nkr::cpp::Move(c)) == (value_t(a) << value_t(c)));
                                CHECK((nkr::cpp::Move(c) << nkr::cpp::Move(a)) == (value_t(c) << value_t(a)));
                            }

                            CHECK((a >> nkr::cpp::Move(c)) == (value_t(a) >> value_t(c)));
                            CHECK((nkr::cpp::Move(c) >> a) == (value_t(c) >> value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) >> c) == (value_t(a) >> value_t(c)));
                                CHECK((c >> nkr::cpp::Move(a)) == (value_t(c) >> value_t(a)));
                                CHECK((nkr::cpp::Move(a) >> nkr::cpp::Move(c)) == (value_t(a) >> value_t(c)));
                                CHECK((nkr::cpp::Move(c) >> nkr::cpp::Move(a)) == (value_t(c) >> value_t(a)));
                            }
                        }
                    }
                }

                TEST_SUITE("const")
                {
                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>(true, true);
                            nkr::cpp::just_const_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>(true, true);
                            nkr::cpp::just_const_t<boolean_p> c =
                                nkr::randomness::Value<boolean_p>(false, true);

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
                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>(true, true);
                            nkr::cpp::just_volatile_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>(true, true);
                            nkr::cpp::just_volatile_t<boolean_p> c =
                                nkr::randomness::Value<boolean_p>(false, true);

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

                    TEST_CASE_TEMPLATE("rvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>(true, true);
                            nkr::cpp::just_volatile_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>(true, true);
                            nkr::cpp::just_volatile_t<boolean_p> c =
                                nkr::randomness::Value<boolean_p>(false, true);

                            CHECK((a | nkr::cpp::Move(b)) == (value_t(a) | value_t(b)));
                            CHECK((nkr::cpp::Move(b) | a) == (value_t(b) | value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) | b) == (value_t(a) | value_t(b)));
                                CHECK((b | nkr::cpp::Move(a)) == (value_t(b) | value_t(a)));
                                CHECK((nkr::cpp::Move(a) | nkr::cpp::Move(b)) == (value_t(a) | value_t(b)));
                                CHECK((nkr::cpp::Move(b) | nkr::cpp::Move(a)) == (value_t(b) | value_t(a)));
                            }

                            CHECK((a & nkr::cpp::Move(b)) == (value_t(a) & value_t(b)));
                            CHECK((nkr::cpp::Move(b) & a) == (value_t(b) & value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) & b) == (value_t(a) & value_t(b)));
                                CHECK((b & nkr::cpp::Move(a)) == (value_t(b) & value_t(a)));
                                CHECK((nkr::cpp::Move(a) & nkr::cpp::Move(b)) == (value_t(a) & value_t(b)));
                                CHECK((nkr::cpp::Move(b) & nkr::cpp::Move(a)) == (value_t(b) & value_t(a)));
                            }

                            CHECK((a ^ nkr::cpp::Move(b)) == (value_t(a) ^ value_t(b)));
                            CHECK((nkr::cpp::Move(b) ^ a) == (value_t(b) ^ value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) ^ b) == (value_t(a) ^ value_t(b)));
                                CHECK((b ^ nkr::cpp::Move(a)) == (value_t(b) ^ value_t(a)));
                                CHECK((nkr::cpp::Move(a) ^ nkr::cpp::Move(b)) == (value_t(a) ^ value_t(b)));
                                CHECK((nkr::cpp::Move(b) ^ nkr::cpp::Move(a)) == (value_t(b) ^ value_t(a)));
                            }

                            CHECK((a << nkr::cpp::Move(c)) == (value_t(a) << value_t(c)));
                            CHECK((nkr::cpp::Move(c) << a) == (value_t(c) << value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) << c) == (value_t(a) << value_t(c)));
                                CHECK((c << nkr::cpp::Move(a)) == (value_t(c) << value_t(a)));
                                CHECK((nkr::cpp::Move(a) << nkr::cpp::Move(c)) == (value_t(a) << value_t(c)));
                                CHECK((nkr::cpp::Move(c) << nkr::cpp::Move(a)) == (value_t(c) << value_t(a)));
                            }

                            CHECK((a >> nkr::cpp::Move(c)) == (value_t(a) >> value_t(c)));
                            CHECK((nkr::cpp::Move(c) >> a) == (value_t(c) >> value_t(a)));
                            if constexpr (nkr::cpp::any_non_const_tr<boolean_p>) {
                                CHECK((nkr::cpp::Move(a) >> c) == (value_t(a) >> value_t(c)));
                                CHECK((c >> nkr::cpp::Move(a)) == (value_t(c) >> value_t(a)));
                                CHECK((nkr::cpp::Move(a) >> nkr::cpp::Move(c)) == (value_t(a) >> value_t(c)));
                                CHECK((nkr::cpp::Move(c) >> nkr::cpp::Move(a)) == (value_t(c) >> value_t(a)));
                            }
                        }
                    }
                }

                TEST_SUITE("const volatile")
                {
                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {
                        using value_t = nkr::boolean::cpp_t;

                        for (nkr::positive::index_t idx = 0, end = Global_Operator_Iteration_Count(); idx < end; idx += 1) {
                            boolean_p a =
                                nkr::randomness::Value<boolean_p>(true, true);
                            nkr::cpp::just_const_volatile_t<boolean_p> b =
                                nkr::randomness::Value<boolean_p>(true, true);
                            nkr::cpp::just_const_volatile_t<boolean_p> c =
                                nkr::randomness::Value<boolean_p>(false, true);

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

            TEST_SUITE("binary bitwise operators: |=, &=, ^=, <<=, >>=")
            {
                TEST_SUITE("non-qualified")
                {
                    TEST_CASE_TEMPLATE("value", boolean_p, nkr_ANY)
                    {

                    }

                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {

                    }

                    TEST_CASE_TEMPLATE("rvalue", boolean_p, nkr_ANY)
                    {

                    }
                }

                TEST_SUITE("const")
                {
                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {

                    }
                }

                TEST_SUITE("volatile")
                {
                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {

                    }

                    TEST_CASE_TEMPLATE("rvalue", boolean_p, nkr_ANY)
                    {

                    }
                }

                TEST_SUITE("const volatile")
                {
                    TEST_CASE_TEMPLATE("lvalue", boolean_p, nkr_ANY)
                    {

                    }
                }
            }

        #undef nkr_ANY_WITH_VALUE
        #undef nkr_ANY_WITH_LVALUE
        #undef nkr_ANY_WITH_RVALUE
        }
    }

}
