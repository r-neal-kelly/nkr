/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/built_in/forward.h"
#include "nkr/constant/positive/index_t.h"
#include "nkr/tuple/types_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::tuple::types_t")
    {
    #define nkr_TYPES(TYPE_QUALIFIER_p)                                                                                                                         \
        TYPE_QUALIFIER_p nkr::tuple::types_t<nkr::positive::integer_t>,                                                                                         \
        TYPE_QUALIFIER_p nkr::tuple::types_t<nkr::negatable::integer_t>,                                                                                        \
        TYPE_QUALIFIER_p nkr::tuple::types_t<nkr::positive::integer_t, nkr::negatable::integer_t>,                                                              \
        TYPE_QUALIFIER_p nkr::tuple::types_t<nkr::positive::integer_8_t, nkr::positive::integer_16_t, nkr::positive::integer_32_t, nkr::positive::integer_64_t> \

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

        using just_non_qualified_ts = nkr::tuple::types_t<nkr_JUST_NON_QUALIFIED>;
        using just_const_ts = nkr::tuple::types_t<nkr_JUST_CONST>;
        using just_volatile_ts = nkr::tuple::types_t<nkr_JUST_VOLATILE>;
        using just_const_volatile_ts = nkr::tuple::types_t<nkr_JUST_CONST_VOLATILE>;

        using any_ts = nkr::tuple::types_t<nkr_ANY>;
        using any_qualified_ts = nkr::tuple::types_t<nkr_ANY_QUALIFIED>;
        using any_non_qualified_ts = nkr::tuple::types_t<nkr_ANY_NON_QUALIFIED>;
        using any_const_ts = nkr::tuple::types_t<nkr_ANY_CONST>;
        using any_non_const_ts = nkr::tuple::types_t<nkr_ANY_NON_CONST>;
        using any_volatile_ts = nkr::tuple::types_t<nkr_ANY_VOLATILE>;
        using any_non_volatile_ts = nkr::tuple::types_t<nkr_ANY_NON_VOLATILE>;

        using any_not_just_non_qualified_ts = nkr::tuple::types_t<nkr_ANY_NOT_JUST_NON_QUALIFIED>;
        using any_not_just_const_ts = nkr::tuple::types_t<nkr_ANY_NOT_JUST_CONST>;
        using any_not_just_volatile_ts = nkr::tuple::types_t<nkr_ANY_NOT_JUST_VOLATILE>;
        using any_not_just_const_volatile_ts = nkr::tuple::types_t<nkr_ANY_NOT_JUST_CONST_VOLATILE>;

        // If I switch the order of tuple_p and index_p intellisense starts to work again.
        // but it makes for a worse api.
        template <
            template <typename ...> typename functor_p,
            nkr::tuple::types_tr tuple_p,
            typename index_p = nkr::constant::positive::index_t<0>,
            typename ...parameters_p
        > inline constexpr void
            Iterate_Forward(parameters_p&&... arguments)
            noexcept
        {
            static_assert(index_p::Value() < tuple_p::Count());

            functor_p<typename tuple_p::template at_t<index_p>::head_t>::Call(nkr::cpp::Forward<parameters_p>(arguments)...);

            if constexpr (index_p::Value() < tuple_p::Count() - 1) {
                Iterate_Forward<functor_p, tuple_p, nkr::constant::positive::index_t<index_p::Value() + 1>>();
            }
        }

        template <
            template <typename ...> typename functor_p,
            nkr::tuple::types_tr tuple_p,
            typename index_p = nkr::constant::positive::index_t<tuple_p::Count() - 1>,
            typename ...parameters_p
        > inline constexpr void
            Iterate_Backward(parameters_p&&... arguments)
            noexcept
        {
            static_assert(index_p::Value() < tuple_p::Count());

            functor_p<typename tuple_p::template at_t<index_p>::head_t>::Call(nkr::cpp::Forward<parameters_p>(arguments)...);

            if constexpr (index_p::Value() > 0) {
                Iterate_Backward<functor_p, tuple_p, nkr::constant::positive::index_t<index_p::Value() - 1>>();
            }
        }

        template <typename type_p>
        class print_size_tmpl
        {
        public:
            using type_t    = type_p;

        public:
            static void Call() noexcept
            {
                printf("sizeof type_t: %zu\n", sizeof(type_t));
            }
        };

        TEST_CASE_TEMPLATE("temp", tuple_p, nkr_JUST_NON_QUALIFIED)
        {
            printf("forward\n");
            Iterate_Forward<print_size_tmpl, tuple_p>();
            printf("\n");

            printf("backward\n");
            Iterate_Backward<print_size_tmpl, tuple_p>();
            printf("\n");
        }

        TEST_CASE("temp")
        {
            using tuple_t = nkr::tuple::types_t<nkr::positive::integer_t, nkr::negatable::integer_t>;

            static_assert(tuple_t::Count() == 2);
            using a_t = tuple_t::template at_t<nkr::constant::positive::index_t<0>>::head_t;
            using b_t = tuple_t::template at_t<nkr::constant::positive::index_t<1>>::head_t;
            static_assert(nkr::cpp::is_tr<a_t, nkr::positive::integer_t>);
            static_assert(nkr::cpp::is_tr<b_t, nkr::negatable::integer_t>);

            using type_i = nkr::interface::type_i<nkr::tuple::types_t<>>;
            using of_t = type_i::of_t;
            static_assert(nkr::tuple::types_tr<nkr::tuple::types_t<>>);
        }
    }

}
