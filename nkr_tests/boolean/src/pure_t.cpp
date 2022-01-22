/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/boolean/pure_t.h"
#include "nkr/generic/boolean_tr.h"
#include "nkr/generic/boolean/any_tr.h"
#include "nkr/generic/boolean/pure_tr.h"
#include "nkr/generic/implementing/interface/none/value_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"
#include "nkr/generic/type_tr.h"
#include "nkr/none/value_t.h"

#include "doctest.h"

namespace nkr {

    // potential problem.
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

    #define nkr_ANY             \
        nkr_JUST_NON_QUALIFIED, \
        nkr_JUST_CONST,         \
        nkr_JUST_VOLATILE,      \
        nkr_JUST_CONST_VOLATILE \

        TEST_SUITE("identity")
        {
            TEST_CASE_TEMPLATE("should satisfy the identity trait", pure_p, nkr_ANY)
            {
                static_assert(nkr::boolean::pure_tr<pure_p>);
            }
        }

        TEST_SUITE("generic")
        {
            // not sure why intellisense thinks some of these are false. they do properly compile.
            // it's something to do with having an == check in the concept requires section?
            static_assert(nkr::generic::boolean_tr<nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean_tr<const nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean_tr<volatile nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean_tr<const volatile nkr::boolean::pure_t>);

            static_assert(nkr::generic::boolean::any_tr<nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean::any_tr<const nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean::any_tr<volatile nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean::any_tr<const volatile nkr::boolean::pure_t>);

            static_assert(nkr::generic::boolean::pure_tr<nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean::pure_tr<const nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean::pure_tr<volatile nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean::pure_tr<const volatile nkr::boolean::pure_t>);

            static_assert(nkr::generic::implementing::interface::none::value_tr<nkr::boolean::pure_t>);

            static_assert(nkr::generic::implementing::interface::type_tr<nkr::boolean::pure_t>);
            static_assert(nkr::generic::implementing::interface::type_tr<nkr::boolean::pure_tg>);

            static_assert(nkr::generic::type_tr<nkr::boolean::pure_t>);
            static_assert(nkr::generic::type_tr<const nkr::boolean::pure_t>);
            static_assert(nkr::generic::type_tr<volatile nkr::boolean::pure_t>);
            static_assert(nkr::generic::type_tr<const volatile nkr::boolean::pure_t>);
        }

        TEST_SUITE("interface")
        {
            TEST_SUITE("nkr::interface::none::value_i")
            {
                static_assert(nkr::interface::none::value_i<nkr::boolean::pure_t>::Value() == false);

                static_assert(nkr::none::value_t<nkr::boolean::pure_t>() == false);
                static_assert(nkr::none::value_t<nkr::boolean::pure_t>() == nkr::boolean::pure_t(false));
                static_assert(nkr::none::value_t<nkr::boolean::pure_t>() == nkr::none::value_t<nkr::boolean::pure_t>());

                static_assert(false == nkr::none::value_t<nkr::boolean::pure_t>());
                static_assert(nkr::boolean::pure_t(false) == nkr::none::value_t<nkr::boolean::pure_t>());
                static_assert(nkr::none::value_t<nkr::boolean::pure_t>() == nkr::none::value_t<nkr::boolean::pure_t>());
            }
        }

        TEST_SUITE("tr")
        {
            TEST_SUITE("tr1")
            {
                using targets_t = nkr::tuple::types_t<
                    nkr::boolean::pure_t,
                    nkr::boolean::pure_tg,

                    nkr::generic::boolean_tg,
                    nkr::generic::boolean::any_tg,
                    nkr::generic::boolean::pure_tg,

                    nkr::generic::type_tg,

                    nkr::generic::implementing::interface::type_tg,
                    nkr::generic::implementing::interface::none::value_tg
                >;

                // again, intellisense thinks this is false when it actually compiles
                static_assert(tr1_t<any_tg, targets_t>::AND<nkr_ANY>());

            #define nkr_OTHER_TYPES         \
                nkr::positive::integer_t,   \
                nkr::negatable::integer_t   \

                TEST_CASE("any_tg")
                {
                    static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::AND<nkr_ANY>());
                    static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::NOR<nkr_OTHER_TYPES>());

                    static_assert(tr1_t<any_tg, nkr::boolean::pure_tg>::AND<nkr_ANY>());
                    static_assert(tr1_t<any_tg, nkr::boolean::pure_tg>::NOR<nkr_OTHER_TYPES>());
                }

                TEST_CASE("any_qualified_tg")
                {
                    static_assert(tr1_t<any_qualified_tg, nkr::boolean::pure_t>::AND<nkr_ANY_QUALIFIED>());
                    static_assert(tr1_t<any_qualified_tg, nkr::boolean::pure_t>::NOR<nkr_ANY_NON_QUALIFIED>());
                    static_assert(tr1_t<any_qualified_tg, nkr::boolean::pure_t>::NOR<nkr_OTHER_TYPES>());

                    static_assert(tr1_t<any_qualified_tg, nkr::boolean::pure_tg>::AND<nkr_ANY_QUALIFIED>());
                    static_assert(tr1_t<any_qualified_tg, nkr::boolean::pure_tg>::NOR<nkr_ANY_NON_QUALIFIED>());
                    static_assert(tr1_t<any_qualified_tg, nkr::boolean::pure_tg>::NOR<nkr_OTHER_TYPES>());
                }

                TEST_CASE("any_non_qualified_tg")
                {
                    static_assert(tr1_t<any_non_qualified_tg, nkr::boolean::pure_t>::AND<nkr_ANY_NON_QUALIFIED>());
                    static_assert(tr1_t<any_non_qualified_tg, nkr::boolean::pure_t>::NOR<nkr_ANY_QUALIFIED>());
                    static_assert(tr1_t<any_non_qualified_tg, nkr::boolean::pure_t>::NOR<nkr_OTHER_TYPES>());

                    static_assert(tr1_t<any_non_qualified_tg, nkr::boolean::pure_tg>::AND<nkr_ANY_NON_QUALIFIED>());
                    static_assert(tr1_t<any_non_qualified_tg, nkr::boolean::pure_tg>::NOR<nkr_ANY_QUALIFIED>());
                    static_assert(tr1_t<any_non_qualified_tg, nkr::boolean::pure_tg>::NOR<nkr_OTHER_TYPES>());
                }

                TEST_CASE("any_const_tg")
                {
                    static_assert(tr1_t<any_const_tg, nkr::boolean::pure_t>::AND<nkr_ANY_CONST>());
                    static_assert(tr1_t<any_const_tg, nkr::boolean::pure_t>::NOR<nkr_ANY_NON_CONST>());
                    static_assert(tr1_t<any_const_tg, nkr::boolean::pure_t>::NOR<nkr_OTHER_TYPES>());

                    static_assert(tr1_t<any_const_tg, nkr::boolean::pure_tg>::AND<nkr_ANY_CONST>());
                    static_assert(tr1_t<any_const_tg, nkr::boolean::pure_tg>::NOR<nkr_ANY_NON_CONST>());
                    static_assert(tr1_t<any_const_tg, nkr::boolean::pure_tg>::NOR<nkr_OTHER_TYPES>());
                }

                TEST_CASE("any_non_const_tg")
                {
                    static_assert(tr1_t<any_non_const_tg, nkr::boolean::pure_t>::AND<nkr_ANY_NON_CONST>());
                    static_assert(tr1_t<any_non_const_tg, nkr::boolean::pure_t>::NOR<nkr_ANY_CONST>());
                    static_assert(tr1_t<any_non_const_tg, nkr::boolean::pure_t>::NOR<nkr_OTHER_TYPES>());

                    static_assert(tr1_t<any_non_const_tg, nkr::boolean::pure_tg>::AND<nkr_ANY_NON_CONST>());
                    static_assert(tr1_t<any_non_const_tg, nkr::boolean::pure_tg>::NOR<nkr_ANY_CONST>());
                    static_assert(tr1_t<any_non_const_tg, nkr::boolean::pure_tg>::NOR<nkr_OTHER_TYPES>());
                }

            #undef nkr_OTHER_TYPES
            }
        }

        TEST_SUITE("operators")
        {
            TEST_CASE("temp")
            {
                nkr::boolean::pure_t boolean;
                volatile nkr::boolean::cpp_t test = false;
                boolean = nkr::boolean::cpp_t();
                boolean = nkr::cpp::Move(test);

                CHECK((boolean == nkr::cpp::Move(test)));
            }
        }
    }

}
