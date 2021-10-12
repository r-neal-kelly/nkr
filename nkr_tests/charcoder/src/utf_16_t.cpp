/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"
#include "nkr/os.h"

#include "nkr/array/stack_t.h"

#include "nkr/charcoder/utf_16_t.h"
#include "nkr/charcoder/utf_32_t.h"

#include "doctest.h"

namespace nkr { namespace charcoder {

    TEST_SUITE("utf_16_t")
    {
    #define nkr_REGULAR \
        utf_16_be_t,    \
        utf_16_le_t

    #define nkr_NON_CONST       \
        utf_16_be_t,            \
        utf_16_le_t,            \
        volatile utf_16_be_t,   \
        volatile utf_16_le_t

    #define nkr_CONST               \
        const utf_16_be_t,          \
        const utf_16_le_t,          \
        const volatile utf_16_be_t, \
        const volatile utf_16_le_t

    #define nkr_ALL     \
        nkr_NON_CONST,  \
        nkr_CONST

        template <typename charcoder_p>
        concept has_native_endianness_tr =
            is_any_tr<charcoder_p, utf_16_be_t> && os::endian::Is_Big() ||
            is_any_tr<charcoder_p, utf_16_le_t> && os::endian::Is_Little();

        template <typename charcoder_p>
        concept has_non_native_endianness_tr =
            is_any_tr<charcoder_p, utf_16_be_t> && os::endian::Is_Little() ||
            is_any_tr<charcoder_p, utf_16_le_t> && os::endian::Is_Big();

        static inline point_t Random_Any()
        {
            return Random<point_t>();
        }

        static inline point_t Random_Point()
        {
            return Random<point_t>(utf_32_t::POINT_FIRST, utf_32_t::POINT_LAST);
        }

        static inline point_t Random_Non_Point()
        {
            return Random<point_t>(utf_32_t::POINT_LAST + 1);
        }

        static inline point_t Random_Scalar()
        {
            point_t random;
            do {
                random = Random_Point();
            } while (!utf_32_t::Is_Scalar(random));

            return random;
        }

        static inline point_t Random_Non_Terminus_Scalar()
        {
            point_t random;
            do {
                random = Random_Scalar();
            } while (random == 0);

            return random;
        }

        static inline point_t Random_Non_Replacement_Scalar()
        {
            point_t random;
            do {
                random = Random_Scalar();
            } while (random == utf_32_t::Replacement_Point());

            return random;
        }

        static inline point_t Random_Non_Terminus_And_Non_Replacement_Scalar()
        {
            point_t random;
            do {
                random = Random_Non_Terminus_Scalar();
            } while (random == utf_32_t::Replacement_Point());

            return random;
        }

        static inline point_t Random_Surrogate()
        {
            return Random<point_t>(utf_32_t::SURROGATE_HIGH_FIRST, utf_32_t::SURROGATE_LOW_LAST);
        }

        TEST_SUITE("aliases")
        {
            TEST_SUITE("unit_t")
            {
                TEST_CASE_TEMPLATE("should have a unit type of c16_t", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    static_assert(is_tr<unit_t, c16_t>);
                }
            }

            TEST_SUITE("units_t")
            {
                TEST_CASE_TEMPLATE("should have a stack array to hold its units", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    static_assert(is_tr<units_t, array::stack_t<unit_t, 2>>);
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
                    using units_t = utf_p::units_t;

                    static_assert(utf_p::Replacement_Point() == utf_32_t::REPLACEMENT_CHARACTER);
                }
            }

            TEST_SUITE("Has_1_To_1_Unit_To_Point_Ratio()")
            {
                TEST_CASE_TEMPLATE("should always return false for this charcoder", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    static_assert(utf_p::Has_1_To_1_Unit_To_Point_Ratio() == false);
                }
            }
        }

        TEST_SUITE("protected object data")
        {
            TEST_SUITE("units")
            {
                TEST_CASE_TEMPLATE("should have a units of units_t", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    class derived_t :
                        public utf_p
                    {
                    public:
                        static_assert(is_tr<decltype(utf_p::units), units_t>);
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
                    using units_t = utf_p::units_t;

                    utf_p utf;
                    CHECK(utf.Decode() == 0);
                }

                TEST_CASE_TEMPLATE("should always have a unit count of 1", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    utf_p utf;
                    CHECK(utf.Unit_Count() == 1);
                }

                TEST_CASE_TEMPLATE("should equal none_t", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    utf_p utf;
                    CHECK(utf == none_t());
                }
            }

            TEST_SUITE("point_ctor()")
            {
                TEST_CASE_TEMPLATE("should encode a scalar", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Scalar();
                    utf_p utf = random;
                    CHECK(utf.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should replace a non-point", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Non_Point();
                    utf_p utf = random;
                    CHECK(utf.Decode() == utf_p::Replacement_Point());
                }

                TEST_CASE_TEMPLATE("should replace a surrogate", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Surrogate();
                    utf_p utf = random;
                    CHECK(utf.Decode() == utf_p::Replacement_Point());
                }

                TEST_CASE_TEMPLATE("should always have a unit count of 1-2 for this charcoder", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Scalar();
                    utf_p utf = random;
                    CHECK((utf.Unit_Count() == 1 || utf.Unit_Count() == 2));
                }
            }

            TEST_SUITE("copy_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy other's data so that it decodes the same point", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Scalar();
                    utf_p other = random;
                    utf_p utf = other;
                    CHECK(utf.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should not alter other", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Scalar();
                    utf_p other = random;
                    utf_p utf = other;
                    CHECK(other.Decode() == random);
                }
            }

            TEST_SUITE("move_ctor()")
            {
                TEST_CASE_TEMPLATE("should move other's data so that it decodes the other's point", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Scalar();
                    std::remove_const_t<utf_p> other = random;
                    utf_p utf = nkr::Move(other);
                    CHECK(utf.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should set other's data so that it decodes the terminus", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Non_Terminus_Scalar();
                    std::remove_const_t<utf_p> other = random;
                    utf_p utf = nkr::Move(other);
                    CHECK(other.Decode() == 0);
                }
            }

            TEST_SUITE("copy_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy other's data so that it decodes the same point", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Scalar();
                    const utf_p other = random;
                    utf_p utf;
                    utf = other;
                    CHECK(utf.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should not alter other", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Scalar();
                    const utf_p other = random;
                    utf_p utf;
                    utf = other;
                    CHECK(other.Decode() == random);
                }
            }

            TEST_SUITE("copy_volatile_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy other's data so that it decodes the same point", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Scalar();
                    const volatile utf_p other = random;
                    utf_p utf;
                    utf = other;
                    CHECK(utf.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should not alter other", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Scalar();
                    const volatile utf_p other = random;
                    utf_p utf;
                    utf = other;
                    CHECK(other.Decode() == random);
                }
            }

            TEST_SUITE("move_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should move other's data so that it decodes to same point", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Scalar();
                    utf_p other = random;
                    utf_p utf;
                    utf = nkr::Move(other);
                    CHECK(utf.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should set other's data so that it decodes the terminus", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Non_Terminus_Scalar();
                    utf_p other = random;
                    utf_p utf;
                    utf = nkr::Move(other);
                    CHECK(other.Decode() == 0);
                }
            }

            TEST_SUITE("move_volatile_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should move other's data so that it decodes to same point", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Scalar();
                    volatile utf_p other = random;
                    utf_p utf;
                    utf = nkr::Move(other);
                    CHECK(utf.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should set other's data so that it decodes the terminus", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Non_Terminus_Scalar();
                    volatile utf_p other = random;
                    utf_p utf;
                    utf = nkr::Move(other);
                    CHECK(other.Decode() == 0);
                }
            }

            TEST_SUITE("dtor()")
            {
                TEST_CASE_TEMPLATE("should allow itself to become invalid as a charcoder", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Non_Terminus_Scalar();
                    utf_p utf = random;
                    CHECK(utf.Decode() != 0);
                    utf.~utf_p();
                    CHECK(!utf.Is_Well_Formed());
                }
            }
        }
    }

}}
