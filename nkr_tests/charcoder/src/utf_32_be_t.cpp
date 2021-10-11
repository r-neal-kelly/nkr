/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "nkr/charcoder/utf_32_t.h"

#include "doctest.h"

namespace nkr { namespace charcoder {

    TEST_SUITE("utf_32_be_t")
    {
    #define nkr_REGULAR \
        utf_32_be_t

    #define nkr_NON_CONST       \
        utf_32_be_t,            \
        volatile utf_32_be_t

    #define nkr_CONST               \
        const utf_32_be_t,          \
        const volatile utf_32_be_t

    #define nkr_ALL     \
        nkr_NON_CONST,  \
        nkr_CONST

        static inline point_t Random_Valid_Point()
        {
            point_t random;
            do {
                random = Random<point_t>(utf_32_be_t::POINT_FIRST, utf_32_be_t::POINT_LAST);
            } while (!utf_32_be_t::Is_Scalar(random));

            return random;
        }

        static inline point_t Random_Valid_And_Non_Terminus_Point()
        {
            point_t random;
            do {
                random = Random_Valid_Point();
            } while (random == 0);

            return random;
        }

        static inline point_t Random_Valid_And_Non_Terminus_And_Non_Replacement_Point()
        {
            point_t random;
            do {
                random = Random_Valid_And_Non_Terminus_Point();
            } while (random == utf_32_be_t::Replacement_Point());

            return random;
        }

        TEST_SUITE("aliases")
        {
            TEST_SUITE("unit_t")
            {
                TEST_CASE_TEMPLATE("should have a unit type of c32_t", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    static_assert(is_tr<typename utf_p::unit_t, c32_t>);
                }
            }
        }

        TEST_SUITE("static constexpr functions")
        {
            TEST_SUITE("Replacement_Point()")
            {
                TEST_CASE_TEMPLATE("should return the Unicode replacement character", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    static_assert(utf_p::Replacement_Point() == utf_32_be_t::REPLACEMENT_CHARACTER);
                }
            }

            TEST_SUITE("Has_1_To_1_Unit_To_Point_Ratio()")
            {
                TEST_CASE_TEMPLATE("should always return true for this charcoder", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    static_assert(utf_p::Has_1_To_1_Unit_To_Point_Ratio() == true);
                }
            }
        }

        TEST_SUITE("protected object data")
        {
            TEST_SUITE("unit")
            {
                TEST_CASE_TEMPLATE("should have a unit of unit_t", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    class derived_t :
                        public utf_p
                    {
                    public:
                        static_assert(is_tr<typename utf_p::unit_t, decltype(utf_p::unit)>);
                    };
                }
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                TEST_CASE_TEMPLATE("should decode to terminus", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    utf_p utf;
                    CHECK(utf.Decode() == 0);
                }

                TEST_CASE_TEMPLATE("should always have a unit count of 1 for this charcoder", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    utf_p utf;
                    CHECK(utf.Unit_Count() == 1);
                }

                TEST_CASE_TEMPLATE("should equal none_t", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    utf_p utf;
                    CHECK(utf == none_t());
                }
            }
        }
    }

}}
