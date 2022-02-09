/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/boolean/cpp_t.h"
#include "nkr/boolean/pure_t.h"
#include "nkr/built_in/forward.h"
#include "nkr/cpp.h"
#include "nkr/generic/non_type_tr.h"
#include "nkr/none/value_t.h"
#include "nkr/randomness/value.h"

#include "doctest.h"

namespace nkr { namespace boolean {

    TEST_CASE("temp")
    {
        CHECK(boolean::cpp_t(true));
        CHECK(boolean::cpp_t(true) == true);
        CHECK(!boolean::cpp_t(false));
        CHECK(boolean::cpp_t(false) != true);

        CHECK(boolean::pure_t(true));
        CHECK((boolean::pure_t(true) == true));
        CHECK(!boolean::pure_t(false));
        CHECK((boolean::pure_t(false) != true));

        CHECK(boolean::cpp_t(boolean::pure_t(true)));
        CHECK(!boolean::cpp_t(boolean::pure_t(false)));
        CHECK(boolean::pure_t(boolean::cpp_t(true)));
        CHECK(!boolean::pure_t(boolean::cpp_t(false)));

        CHECK((boolean::cpp_t(true) == boolean::pure_t(true)));
        CHECK((boolean::pure_t(true) == boolean::cpp_t(true)));
        CHECK((boolean::cpp_t(true) != boolean::pure_t(false)));
        CHECK((boolean::pure_t(true) != boolean::cpp_t(false)));
    }

    TEST_CASE("temp")
    {
        CHECK(nkr::none::value_t<nkr::boolean::cpp_t>() == false);
    }

}}

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
    }

}
