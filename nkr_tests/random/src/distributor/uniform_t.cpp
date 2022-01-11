/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "nkr/random/distributor/uniform_t.h"
#include "nkr/random/generator/hardware/cpp_t.h"
#include "nkr/random/generator/software/cpp/mersenne_twister_19937_64_t.h"

#include "doctest.h"

namespace nkr {

    enum enumeration_e
    {
        A,
        B,
        C,

        MIN_tg  = A,
        MAX_tg  = C,
    };

    namespace interface { namespace random { namespace distributor {

        template <>
        class uniform_i_sp<enumeration_e>
        {
        private:
            class implementation_t
            {
            public:
                using type_t    = enumeration_e;
                using number_t  = type_t;

            public:
                static constexpr type_t
                    Default_Min()
                    noexcept
                {
                    return type_t::MIN_tg;
                }

                static constexpr type_t
                    Default_Max()
                    noexcept
                {
                    return type_t::MAX_tg;
                }

                static constexpr number_t
                    To_Number(type_t object)
                    noexcept
                {
                    return object;
                }

                static constexpr type_t
                    From_Number(number_t number)
                    noexcept
                {
                    return number;
                }

            public:
                template <typename ...>
                constexpr implementation_t(...) noexcept    = delete;
            };

        public:
            using type_t    = implementation_t;
        };

        static_assert(uniform_tr<uniform_i<enumeration_e>>);

    }}}

    TEST_SUITE("nkr::random::distributor::uniform_t")
    {
    #define nkr_TYPES(TYPE_QUALIFIER_p)                                                             \
        TYPE_QUALIFIER_p nkr::random::distributor::uniform_t<boolean::cpp_t>,                       \
        TYPE_QUALIFIER_p nkr::random::distributor::uniform_t<positive::integer_32_t>,               \
        TYPE_QUALIFIER_p nkr::random::distributor::uniform_t<positive::integer_64_t>,               \
        TYPE_QUALIFIER_p nkr::random::distributor::uniform_t<negatable::integer_32_t>,              \
        TYPE_QUALIFIER_p nkr::random::distributor::uniform_t<negatable::integer_64_t>,              \
        TYPE_QUALIFIER_p nkr::random::distributor::uniform_t<negatable::real_32_t>,                 \
        TYPE_QUALIFIER_p nkr::random::distributor::uniform_t<negatable::real_64_t>,                 \
        TYPE_QUALIFIER_p nkr::random::distributor::uniform_t<pointer::cpp_t<none::type_t>>,         \
        TYPE_QUALIFIER_p nkr::random::distributor::uniform_t<pointer::cpp_t<positive::integer_t>>,  \
        TYPE_QUALIFIER_p nkr::random::distributor::uniform_t<enumeration_e>                         \

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
            nkr::random::generator::hardware::cpp_t hardware_generator;
            nkr::random::generator::software::cpp::mersenne_twister_19937_64_t generator(hardware_generator());

            TEST_CASE_TEMPLATE("temp", uniform_p, nkr_ALL)
            {
                uniform_p distributor;

                for (positive::index_t idx = 0, end = 64; idx < end; idx += 1) {
                    auto value = distributor.Value(generator);

                    CHECK(value >= uniform_p::Default_Min());
                    CHECK(value <= uniform_p::Default_Max());
                    CHECK(value >= distributor.Min());
                    CHECK(value <= distributor.Max());
                }
            }
        }

        /*TEST_CASE("temp")
        {
            nkr::random::generator::hardware::cpp_t hardware_generator;
            nkr::random::generator::software::cpp::mersenne_twister_19937_64_t generator(hardware_generator());
            nkr::random::distributor::uniform_t<boolean::cpp_t> distributor(false, true);

            CHECK(distributor.Min() == false);
            CHECK(distributor.Max() == true);

            for (positive::index_t idx = 0, end = 8; idx < end; idx += 1) {
                printf("value: %i\n", distributor.Value(generator));
            }
            printf("\n");

            distributor.Min(false);
            distributor.Max(false);

            for (positive::index_t idx = 0, end = 8; idx < end; idx += 1) {
                printf("value: %i\n", distributor.Value(generator));
            }
            printf("\n");

            distributor.Min(true);
            distributor.Max(true);

            for (positive::index_t idx = 0, end = 8; idx < end; idx += 1) {
                printf("value: %i\n", distributor.Value(generator));
            }
            printf("\n");
        }*/
    }

}
