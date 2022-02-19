/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/array/cpp_t.h"
#include "nkr/boolean/cpp_t.h"
#include "nkr/boolean/pure_t.h"
#include "nkr/constant/positive/count_t.h"
#include "nkr/cpp.h"
#include "nkr/enumeration/cpp_t.h"
#include "nkr/generic/implementing/self_tr.h"
#include "nkr/generic/non_type_tr.h"
#include "nkr/negatable/integer_t.h"
#include "nkr/negatable/real_t.h"
#include "nkr/none/pointer_t.h"
#include "nkr/none/type_t.h"
#include "nkr/none/value_t.h"
#include "nkr/pointer/cpp_t.h"
#include "nkr/positive/integer_t.h"
#include "nkr/tr.h"
#include "nkr/tuple/templates_t.h"
#include "nkr/tuple/types_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::generic::implementing::self_tr")
    {
        enum enumeration_c_e :
            nkr::positive::integer_t
        {
        };

        enum class enumeration_cpp_e :
            nkr::positive::integer_t
        {
        };

        class user_defined_t
        {
        public:
            constexpr user_defined_t(const user_defined_t& other) noexcept
            {
            }

            constexpr user_defined_t(const volatile user_defined_t& other) noexcept
            {
            }

            constexpr user_defined_t(user_defined_t&& other) noexcept
            {
            }

            constexpr user_defined_t(volatile user_defined_t&& other) noexcept
            {
            }

            constexpr user_defined_t&
                operator =(const user_defined_t& other)
                noexcept
            {
                return *this;
            }

            constexpr volatile user_defined_t&
                operator =(const user_defined_t& other)
                volatile noexcept
            {
                return *this;
            }

            constexpr user_defined_t&
                operator =(const volatile user_defined_t& other)
                noexcept
            {
                return *this;
            }

            constexpr volatile user_defined_t&
                operator =(const volatile user_defined_t& other)
                volatile noexcept
            {
                return *this;
            }

            constexpr user_defined_t&
                operator =(user_defined_t&& other)
                noexcept
            {
                return *this;
            }

            constexpr volatile user_defined_t&
                operator =(user_defined_t&& other)
                volatile noexcept
            {
                return *this;
            }

            constexpr user_defined_t&
                operator =(tr<just_volatile_tg, t<user_defined_t>> auto&& other)
                noexcept
            {
                return *this;
            }

            constexpr volatile user_defined_t&
                operator =(tr<just_volatile_tg, t<user_defined_t>> auto&& other)
                volatile noexcept
            {
                return *this;
            }
        };

    #define nkr_TYPES(TYPE_QUALIFIER_p)                                 \
        TYPE_QUALIFIER_p nkr::boolean::cpp_t,                           \
                                                                        \
        TYPE_QUALIFIER_p nkr::positive::integer_t,                      \
        TYPE_QUALIFIER_p nkr::negatable::integer_t,                     \
        TYPE_QUALIFIER_p nkr::negatable::real_t,                        \
        TYPE_QUALIFIER_p enumeration_c_e,                               \
        TYPE_QUALIFIER_p enumeration_cpp_e,                             \
                                                                        \
        TYPE_QUALIFIER_p nkr::pointer::cpp_t<nkr::positive::integer_t>, \
        TYPE_QUALIFIER_p nkr::none::pointer_t,                          \
                                                                        \
        TYPE_QUALIFIER_p nkr::boolean::pure_t,                          \
        TYPE_QUALIFIER_p nkr::none::value_t<nkr::positive::integer_t>,  \
        TYPE_QUALIFIER_p user_defined_t                                 \

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
                nkr::generic::implementing::self_tg
            >;

            using non_target_ts = ts<AND_tg,
                nkr::generic::non_type_tg
            >;

            class non_subject_t;
            using non_subject_ts = ts<AND_tg,
                non_subject_t,
                const non_subject_t,
                volatile non_subject_t,
                const volatile non_subject_t,

                nkr::none::type_t,
                const nkr::none::type_t,
                volatile nkr::none::type_t,
                const volatile nkr::none::type_t,

                nkr::constant::positive::count_t<0>,
                const nkr::constant::positive::count_t<0>,
                volatile nkr::constant::positive::count_t<0>,
                const volatile nkr::constant::positive::count_t<0>,

                nkr::tuple::types_t<nkr::positive::integer_t>,
                const nkr::tuple::types_t<nkr::positive::integer_t>,
                volatile nkr::tuple::types_t<nkr::positive::integer_t>,
                const volatile nkr::tuple::types_t<nkr::positive::integer_t>,

                nkr::tuple::templates_t<nkr::array::cpp_t>,
                const nkr::tuple::templates_t<nkr::array::cpp_t>,
                volatile nkr::tuple::templates_t<nkr::array::cpp_t>,
                const volatile nkr::tuple::templates_t<nkr::array::cpp_t>,

                nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>,
                const nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>,
                volatile nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>,
                const volatile nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
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
    }

}
