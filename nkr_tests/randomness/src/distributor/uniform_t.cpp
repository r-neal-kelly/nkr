/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/boolean/cpp_t.h"
#include "nkr/cpp/randomness/generator/hardware_t.h"
#include "nkr/cpp/randomness/generator/software/mersenne_twister_19937_64_t.h"
#include "nkr/enumeration/cpp_t.h"
#include "nkr/generic/implementing/interface/template_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"
#include "nkr/generic/randomness/distributor_tr.h"
#include "nkr/negatable/integer_t.h"
#include "nkr/negatable/real_t.h"
#include "nkr/pointer/cpp_t.h"
#include "nkr/positive/integer_t.h"
#include "nkr/randomness/distributor/uniform_t.h"

#include "doctest.h"

namespace nkr {

    enum enumeration_e
    {
        A,
        B,
        C,

        MIN_lb  = A,
        MAX_lb  = C,
    };

    /*namespace interface { namespace randomness { namespace distributor {

        template <>
        class uniform_i_sp<enumeration_e>
        {
        private:
            class implementation_t
            {
            public:
                using type_t    = enumeration_e;
                using number_t  = positive::integer_t;

            public:
                static constexpr type_t
                    Default_Min()
                    noexcept
                {
                    return type_t::MIN_lb;
                }

                static constexpr type_t
                    Default_Max()
                    noexcept
                {
                    return type_t::MAX_lb;
                }

                static constexpr number_t
                    To_Number(type_t value)
                    noexcept
                {
                    return static_cast<number_t>(value);
                }

                static constexpr type_t
                    From_Number(number_t number)
                    noexcept
                {
                    return static_cast<type_t>(number);
                }

            public:
                template <typename ...>
                constexpr implementation_t(...) noexcept    = delete;
            };

        public:
            using type_t    = implementation_t;
        };

        static_assert(uniform_tr<uniform_i<enumeration_e>>);

    }}}*/

    TEST_SUITE("nkr::randomness::distributor::uniform_t")
    {
    #define nkr_TYPES(TYPE_QUALIFIER_p)                                                                 \
        TYPE_QUALIFIER_p nkr::randomness::distributor::uniform_t<boolean::cpp_t>,                       \
        TYPE_QUALIFIER_p nkr::randomness::distributor::uniform_t<positive::integer_32_t>,               \
        TYPE_QUALIFIER_p nkr::randomness::distributor::uniform_t<positive::integer_64_t>,               \
        TYPE_QUALIFIER_p nkr::randomness::distributor::uniform_t<negatable::integer_32_t>,              \
        TYPE_QUALIFIER_p nkr::randomness::distributor::uniform_t<negatable::integer_64_t>,              \
        TYPE_QUALIFIER_p nkr::randomness::distributor::uniform_t<negatable::real_32_t>,                 \
        TYPE_QUALIFIER_p nkr::randomness::distributor::uniform_t<negatable::real_64_t>,                 \
        TYPE_QUALIFIER_p nkr::randomness::distributor::uniform_t<pointer::cpp_t<none::type_t>>,         \
        TYPE_QUALIFIER_p nkr::randomness::distributor::uniform_t<pointer::cpp_t<positive::integer_t>>,  \
        TYPE_QUALIFIER_p nkr::randomness::distributor::uniform_t<enumeration_e>                         \

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

    #define nkr_ALL             \
        nkr_JUST_NON_QUALIFIED, \
        nkr_JUST_CONST,         \
        nkr_JUST_VOLATILE,      \
        nkr_JUST_CONST_VOLATILE \

        TEST_SUITE("traits")
        {
            template <typename ...types_p>
            using alias_t =
                nkr::randomness::distributor::uniform_t<types_p...>;

            TEST_CASE_TEMPLATE("should satisfy its identity", uniform_p, nkr_ALL)
            {
                static_assert(nkr::randomness::distributor::uniform_tr<uniform_p>);
            }

            TEST_SUITE("should satisfy its template identity")
            {
                static_assert(nkr::randomness::distributor::uniform_ttr<nkr::randomness::distributor::uniform_t>);

                static_assert(nkr::randomness::distributor::uniform_ttr<alias_t>);
            }

            TEST_CASE_TEMPLATE("should satisfy all of the following generics", uniform_p, nkr_ALL)
            {
                static_assert(nkr::generic::randomness::distributor_tr<uniform_p>);
            }

            TEST_CASE_TEMPLATE("should satisfy all of the following interfaces", uniform_p, nkr_JUST_NON_QUALIFIED)
            {
                static_assert(nkr::generic::implementing::interface::type_tr<uniform_p>);
            }

            TEST_SUITE("should satisfy all of the following template interfaces")
            {
                static_assert(nkr::generic::implementing::interface::template_ttr<nkr::randomness::distributor::uniform_t>);

                static_assert(nkr::generic::implementing::interface::template_ttr<alias_t>);
            }
        }

        TEST_SUITE("static functions")
        {
            TEST_SUITE("Default_Min()")
            {
                TEST_CASE_TEMPLATE("should be <= Default_Max()", uniform_p, nkr_ALL)
                {
                    CHECK(uniform_p::Default_Min() <= uniform_p::Default_Max());
                }
            }

            TEST_SUITE("Default_Max()")
            {
                TEST_CASE_TEMPLATE("should be >= Default_Min()", uniform_p, nkr_ALL)
                {
                    CHECK(uniform_p::Default_Max() >= uniform_p::Default_Min());
                }
            }
        }

        TEST_SUITE("temp")
        {
            nkr::cpp::randomness::generator::hardware_t hardware_generator;
            nkr::cpp::randomness::generator::software::mersenne_twister_19937_64_t software_generator(hardware_generator());

            TEST_CASE_TEMPLATE("temp", uniform_p, nkr_ALL)
            {
                uniform_p distributor;

                for (positive::index_t idx = 0, end = 64; idx < end; idx += 1) {
                    auto value = distributor.Value(software_generator);

                    CHECK(value >= uniform_p::Default_Min());
                    CHECK(value <= uniform_p::Default_Max());
                    CHECK(value >= distributor.Min());
                    CHECK(value <= distributor.Max());
                }
            }
        }
    }

}
