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

        TEST_SUITE("tr")
        {
            TEST_SUITE("tr1")
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
                    nkr::generic::implementing::interface::type_tg,
                    nkr::generic::implementing::interface::none::value_tg,
                    nkr::generic::type_tg
                >;

                using other_target_ts = nkr::tuple::types_t<
                    nkr::boolean::pure_t,
                    nkr::boolean::pure_tg,

                    nkr::generic::boolean_tg,
                    nkr::generic::boolean::any_tg,
                    nkr::generic::boolean::pure_tg
                >;

                static_assert(tr1_t<any_tg, target_ts>::Every<any_ts>());
                static_assert(tr1_t<any_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1_t<any_qualified_tg, target_ts>::Every<any_qualified_ts>());
                static_assert(tr1_t<any_qualified_tg, target_ts>::None<any_non_qualified_ts>());
                static_assert(tr1_t<any_qualified_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1_t<any_non_qualified_tg, target_ts>::Every<any_non_qualified_ts>());
                static_assert(tr1_t<any_non_qualified_tg, target_ts>::None<any_qualified_ts>());
                static_assert(tr1_t<any_non_qualified_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1_t<any_const_tg, target_ts>::Every<any_const_ts>());
                static_assert(tr1_t<any_const_tg, target_ts>::None<any_non_const_ts>());
                static_assert(tr1_t<any_const_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1_t<any_non_const_tg, target_ts>::Every<any_non_const_ts>());
                static_assert(tr1_t<any_non_const_tg, target_ts>::None<any_const_ts>());
                static_assert(tr1_t<any_non_const_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1_t<any_volatile_tg, target_ts>::Every<any_volatile_ts>());
                static_assert(tr1_t<any_volatile_tg, target_ts>::None<any_non_volatile_ts>());
                static_assert(tr1_t<any_volatile_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1_t<any_non_volatile_tg, target_ts>::Every<any_non_volatile_ts>());
                static_assert(tr1_t<any_non_volatile_tg, target_ts>::None<any_volatile_ts>());
                static_assert(tr1_t<any_non_volatile_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1_t<just_tg, target_ts>::Every<any_non_qualified_ts>());
                static_assert(tr1_t<just_tg, target_ts>::None<any_qualified_ts>());
                static_assert(tr1_t<just_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1_t<just_non_qualified_tg, target_ts>::Every<just_non_qualified_ts>());
                static_assert(tr1_t<just_non_qualified_tg, target_ts>::None<any_not_just_non_qualified_ts>());
                static_assert(tr1_t<just_non_qualified_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1_t<just_const_tg, target_ts>::Every<just_const_ts>());
                static_assert(tr1_t<just_const_tg, target_ts>::None<any_not_just_const_ts>());
                static_assert(tr1_t<just_const_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1_t<just_volatile_tg, target_ts>::Every<just_volatile_ts>());
                static_assert(tr1_t<just_volatile_tg, target_ts>::None<any_not_just_volatile_ts>());
                static_assert(tr1_t<just_volatile_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1_t<just_const_volatile_tg, target_ts>::Every<just_const_volatile_ts>());
                static_assert(tr1_t<just_const_volatile_tg, target_ts>::None<any_not_just_const_volatile_ts>());
                static_assert(tr1_t<just_const_volatile_tg, other_target_ts>::None<other_ts>());

                static_assert(tr1_t<not_any_tg, target_ts>::None<any_ts>());
                static_assert(tr1_t<not_any_tg, other_target_ts>::Every<other_ts>());

                static_assert(tr1_t<not_any_qualified_tg, target_ts>::None<any_qualified_ts>());
                static_assert(tr1_t<not_any_qualified_tg, target_ts>::Every<any_non_qualified_ts>());
                static_assert(tr1_t<not_any_qualified_tg, other_target_ts>::Every<other_ts>());

                static_assert(tr1_t<not_any_non_qualified_tg, target_ts>::None<any_non_qualified_ts>());
                static_assert(tr1_t<not_any_non_qualified_tg, target_ts>::Every<any_qualified_ts>());
                static_assert(tr1_t<not_any_non_qualified_tg, other_target_ts>::Every<other_ts>());

                static_assert(tr1_t<not_any_const_tg, target_ts>::None<any_const_ts>());
                static_assert(tr1_t<not_any_const_tg, target_ts>::Every<any_non_const_ts>());
                static_assert(tr1_t<not_any_const_tg, other_target_ts>::Every<other_ts>());

                static_assert(tr1_t<not_any_non_const_tg, target_ts>::None<any_non_const_ts>());
                static_assert(tr1_t<not_any_non_const_tg, target_ts>::Every<any_const_ts>());
                static_assert(tr1_t<not_any_non_const_tg, other_target_ts>::Every<other_ts>());

                static_assert(tr1_t<not_any_volatile_tg, target_ts>::None<any_volatile_ts>());
                static_assert(tr1_t<not_any_volatile_tg, target_ts>::Every<any_non_volatile_ts>());
                static_assert(tr1_t<not_any_volatile_tg, other_target_ts>::Every<other_ts>());

                static_assert(tr1_t<not_any_non_volatile_tg, target_ts>::None<any_non_volatile_ts>());
                static_assert(tr1_t<not_any_non_volatile_tg, target_ts>::Every<any_volatile_ts>());
                static_assert(tr1_t<not_any_non_volatile_tg, other_target_ts>::Every<other_ts>());

                static_assert(tr1_t<just_not_tg, target_ts>::None<any_non_qualified_ts>());
                static_assert(tr1_t<just_not_tg, target_ts>::Every<any_qualified_ts>());
                static_assert(tr1_t<just_not_tg, other_target_ts>::Every<other_ts>());

                static_assert(tr1_t<just_not_non_qualified_tg, target_ts>::None<just_non_qualified_ts>());
                static_assert(tr1_t<just_not_non_qualified_tg, target_ts>::Every<any_not_just_non_qualified_ts>());
                static_assert(tr1_t<just_not_non_qualified_tg, other_target_ts>::Every<other_ts>());

                static_assert(tr1_t<just_not_const_tg, target_ts>::None<just_const_ts>());
                static_assert(tr1_t<just_not_const_tg, target_ts>::Every<any_not_just_const_ts>());
                static_assert(tr1_t<just_not_const_tg, other_target_ts>::Every<other_ts>());

                static_assert(tr1_t<just_not_volatile_tg, target_ts>::None<just_volatile_ts>());
                static_assert(tr1_t<just_not_volatile_tg, target_ts>::Every<any_not_just_volatile_ts>());
                static_assert(tr1_t<just_not_volatile_tg, other_target_ts>::Every<other_ts>());

                static_assert(tr1_t<just_not_const_volatile_tg, target_ts>::None<just_const_volatile_ts>());
                static_assert(tr1_t<just_not_const_volatile_tg, target_ts>::Every<any_not_just_const_volatile_ts>());
                static_assert(tr1_t<just_not_const_volatile_tg, other_target_ts>::Every<other_ts>());
            }
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
