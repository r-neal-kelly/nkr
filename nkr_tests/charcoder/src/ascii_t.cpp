/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "nkr/charcoder/ascii_t.h"

#include "doctest.h"

namespace nkr { namespace charcoder {

    TEST_SUITE("ascii_t")
    {
    #define nkr_REGULAR \
        ascii_t

    #define nkr_NON_CONST   \
        ascii_t,            \
        volatile ascii_t

    #define nkr_CONST           \
        const ascii_t,          \
        const volatile ascii_t

    #define nkr_ALL     \
        nkr_NON_CONST,  \
        nkr_CONST

        TEST_SUITE("aliases")
        {
            TEST_SUITE("unit_t")
            {
                TEST_CASE_TEMPLATE("should have a unit type of char", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    static_assert(is_tr<typename ascii_p::unit_t, char>);
                }
            }
        }

        TEST_SUITE("static constexpr functions")
        {
            TEST_SUITE("Has_1_To_1_Unit_To_Point_Ratio()")
            {
                TEST_CASE_TEMPLATE("should always return true", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    static_assert(ascii_p::Has_1_To_1_Unit_To_Point_Ratio() == true);
                }
            }
        }

        TEST_SUITE("protected object data")
        {
            TEST_SUITE("unit")
            {
                TEST_CASE_TEMPLATE("should have a unit of unit_t", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    class derived_t :
                        public ascii_p
                    {
                    public:
                        static_assert(is_tr<typename ascii_p::unit_t, decltype(ascii_p::unit)>);
                    };
                }
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                TEST_CASE_TEMPLATE("should decode to terminus", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    ascii_p ascii;
                    CHECK(ascii.Decode() == 0);
                }

                TEST_CASE_TEMPLATE("should have a unit count of 1", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    ascii_p ascii;
                    CHECK(ascii.Unit_Count() == 1);
                }

                TEST_CASE_TEMPLATE("should equal none_t", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    ascii_p ascii;
                    CHECK(ascii == none_t());
                }
            }

            TEST_SUITE("point_ctor()")
            {
                TEST_CASE_TEMPLATE("should encode a valid point", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random<point_t>(0, 127);
                    ascii_p ascii = random;
                    CHECK(ascii.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should replace an invalid point", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random<point_t>(128);
                    ascii_p ascii = random;
                    CHECK(ascii.Decode() == ascii_p::Replacement_Point());
                }
            }

            TEST_SUITE("copy_ctor()")
            {

            }
        }

        TEST_SUITE("methods")
        {
            TEST_SUITE("Encode()")
            {
                TEST_CASE_TEMPLATE("should encode a valid point", ascii_p, nkr_NON_CONST)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random<point_t>(0, 127);
                    ascii_p ascii;
                    ascii.Encode(random);
                    CHECK(ascii.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should replace an invalid point", ascii_p, nkr_NON_CONST)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random<point_t>(128);
                    ascii_p ascii;
                    ascii.Encode(random);
                    CHECK(ascii.Decode() == ascii_p::Replacement_Point());
                }
            }

            TEST_SUITE("Decode()")
            {

            }
        }
    }

}}
