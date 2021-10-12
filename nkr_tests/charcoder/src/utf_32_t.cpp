/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"
#include "nkr/os.h"

#include "nkr/array/stack_t.h"

#include "nkr/charcoder/utf_32_t.h"

#include "doctest.h"

namespace nkr { namespace charcoder {

    TEST_SUITE("utf_32_t")
    {
    #define nkr_REGULAR \
        utf_32_be_t,    \
        utf_32_le_t

    #define nkr_NON_CONST       \
        utf_32_be_t,            \
        utf_32_le_t,            \
        volatile utf_32_be_t,   \
        volatile utf_32_le_t

    #define nkr_CONST               \
        const utf_32_be_t,          \
        const utf_32_le_t,          \
        const volatile utf_32_be_t, \
        const volatile utf_32_le_t

    #define nkr_ALL     \
        nkr_NON_CONST,  \
        nkr_CONST

        template <typename charcoder_p>
        concept has_native_endianness_tr =
            is_any_tr<charcoder_p, utf_32_be_t> && os::endian::Is_Big() ||
            is_any_tr<charcoder_p, utf_32_le_t> && os::endian::Is_Little();

        template <typename charcoder_p>
        concept has_non_native_endianness_tr =
            is_any_tr<charcoder_p, utf_32_be_t> && os::endian::Is_Little() ||
            is_any_tr<charcoder_p, utf_32_le_t> && os::endian::Is_Big();

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

        template <typename charcoder_p, count_t unit_count_p>
        static inline array::stack_t<typename utf_32_t::unit_t, unit_count_p> Random_C_String()
        {
            array::stack_t<typename utf_32_t::unit_t, unit_count_p> string;
            if constexpr (has_native_endianness_tr<charcoder_p>) {
                for (index_t idx = 0, end = unit_count_p - 1; idx < end; idx += 1) {
                    string.Push(utf_32_t::unit_t(Random_Non_Terminus_And_Non_Replacement_Scalar())).Ignore_Error();
                }
                string.Push(utf_32_t::unit_t(0)).Ignore_Error();
            } else if constexpr (has_non_native_endianness_tr<charcoder_p>) {
                for (index_t idx = 0, end = unit_count_p - 1; idx < end; idx += 1) {
                    string.Push(os::endian::Swap(utf_32_t::unit_t(Random_Non_Terminus_And_Non_Replacement_Scalar()))).Ignore_Error();
                }
                string.Push(utf_32_t::unit_t(0)).Ignore_Error();
            } else {
                static_assert(false);
            }

            return string;
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

                    static_assert(utf_p::Replacement_Point() == utf_32_t::REPLACEMENT_CHARACTER);
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

            TEST_SUITE("point_ctor()")
            {
                TEST_CASE_TEMPLATE("should encode a scalar", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    point_t random = Random_Scalar();
                    utf_p utf = random;
                    CHECK(utf.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should replace a non-point", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    point_t random = Random_Non_Point();
                    utf_p utf = random;
                    CHECK(utf.Decode() == utf_p::Replacement_Point());
                }

                TEST_CASE_TEMPLATE("should replace a surrogate", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    point_t random = Random_Surrogate();
                    utf_p utf = random;
                    CHECK(utf.Decode() == utf_p::Replacement_Point());
                }
            }

            TEST_SUITE("copy_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy other's data so that it decodes the same point", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    point_t random = Random_Scalar();
                    utf_p other = random;
                    utf_p utf = other;
                    CHECK(utf.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should not alter other", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

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

                    point_t random = Random_Scalar();
                    std::remove_const_t<utf_p> other = random;
                    utf_p utf = nkr::Move(other);
                    CHECK(utf.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should set other's data so that it decodes the terminus", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

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

                    point_t random = Random_Scalar();
                    const utf_p other = random;
                    utf_p utf;
                    utf = other;
                    CHECK(utf.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should not alter other", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;

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

                    point_t random = Random_Scalar();
                    const volatile utf_p other = random;
                    utf_p utf;
                    utf = other;
                    CHECK(utf.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should not alter other", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;

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

                    point_t random = Random_Scalar();
                    utf_p other = random;
                    utf_p utf;
                    utf = nkr::Move(other);
                    CHECK(utf.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should set other's data so that it decodes the terminus", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;

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

                    point_t random = Random_Scalar();
                    volatile utf_p other = random;
                    utf_p utf;
                    utf = nkr::Move(other);
                    CHECK(utf.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should set other's data so that it decodes the terminus", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;

                    point_t random = Random_Non_Terminus_Scalar();
                    volatile utf_p other = random;
                    utf_p utf;
                    utf = nkr::Move(other);
                    CHECK(other.Decode() == 0);
                }
            }

            TEST_SUITE("dtor()")
            {
                TEST_CASE_TEMPLATE("should set its data to decode the terminus", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    point_t random = Random_Non_Terminus_Scalar();
                    utf_p utf = random;
                    CHECK(utf.Decode() != 0);
                    utf.~utf_p();
                    CHECK(utf.Decode() == 0);
                }
            }
        }

        TEST_SUITE("methods")
        {
            TEST_SUITE("Is_Well_Formed()")
            {
                TEST_CASE_TEMPLATE("should check if the units make a valid point."
                                   "should always return true because the charcoder can never be invalid."
                                   "(available for assertions)",
                                   utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    point_t random = Random_Any();
                    utf_p utf = random;
                    CHECK(utf.Is_Well_Formed() == true);
                }
            }

            TEST_SUITE("Encode()")
            {
                TEST_CASE_TEMPLATE("should encode a scalar", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;

                    point_t random = Random_Scalar();
                    utf_p utf;
                    utf.Encode(random);
                    CHECK(utf.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should encode a non-point with the replacement point", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;

                    point_t random = Random_Non_Point();
                    utf_p utf;
                    utf.Encode(random);
                    CHECK(utf.Decode() == utf_p::Replacement_Point());
                }

                TEST_CASE_TEMPLATE("should encode a surrogate with the replacement point", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;

                    point_t random = Random_Surrogate();
                    utf_p utf;
                    utf.Encode(random);
                    CHECK(utf.Decode() == utf_p::Replacement_Point());
                }
            }

            TEST_SUITE("Decode()")
            {
                TEST_CASE_TEMPLATE("should decode a scalar", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    point_t random = Random_Scalar();
                    utf_p utf = random;
                    CHECK(utf.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should decode a non-point with the replacement point", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    point_t random = Random_Non_Point();
                    utf_p utf = random;
                    CHECK(utf.Decode() == utf_p::Replacement_Point());
                }

                TEST_CASE_TEMPLATE("should decode a surrogate with the replacement point", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    point_t random = Random_Surrogate();
                    utf_p utf = random;
                    CHECK(utf.Decode() == utf_p::Replacement_Point());
                }
            }

            TEST_SUITE("Read_Forward()")
            {
                TEST_CASE_TEMPLATE("should read forward from a given pointer to string", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;

                    auto c_string = Random_C_String<utf_p, 8>();
                    const index_t index = Random<index_t>(0, c_string.Count() - 2);

                    utf_p utf;
                    utf.Read_Forward(&c_string[index]);
                    CHECK(utf.Decode() != 0);
                    CHECK(utf.Decode() != utf_p::Replacement_Point());
                }

                TEST_CASE_TEMPLATE("should return the number of units read", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;

                    auto c_string = Random_C_String<utf_p, 8>();
                    const index_t index = Random<index_t>(0, c_string.Count() - 2);

                    utf_p utf;
                    CHECK(utf.Read_Forward(&c_string[index]) != 0);
                }

                TEST_CASE_TEMPLATE("should allow for iteration over the string", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;

                    auto c_string = Random_C_String<utf_p, 8>();
                    const unit_t* pointer = c_string.Array();

                    utf_p utf;
                    point_t point;
                    pointer += utf.Read_Forward(pointer);
                    point = utf.Decode();
                    for (; point != 0; pointer += utf.Read_Forward(pointer), point = utf.Decode()) {
                        CHECK(utf.Decode() != utf_p::Replacement_Point());
                    }
                }
            }

            TEST_SUITE("Read_Reverse()")
            {
                TEST_CASE_TEMPLATE("should read reverse from a given pointer to string and pointer to first unit."
                                   "should not read the unit pointed to",
                                   utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;

                    auto c_string = Random_C_String<utf_p, 8>();
                    const index_t index = Random<index_t>(1, c_string.Count() - 1);

                    utf_p utf;
                    utf.Read_Reverse(&c_string[index], &c_string[0]);
                    CHECK(utf.Decode() != 0);
                    CHECK(utf.Decode() != utf_p::Replacement_Point());
                }

                TEST_CASE_TEMPLATE("should return the number of units read", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;

                    auto c_string = Random_C_String<utf_p, 8>();
                    const index_t index = Random<index_t>(1, c_string.Count() - 1);

                    utf_p utf;
                    CHECK(utf.Read_Reverse(&c_string[index], &c_string[0]) != 0);
                }

                TEST_CASE_TEMPLATE("should allow for iteration over the string", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;

                    auto c_string = Random_C_String<utf_p, 8>();
                    const unit_t* pointer = c_string.Array() + c_string.Count();

                    utf_p utf;
                    count_t read_count = 0;
                    for (; pointer != c_string.Array(); read_count = utf.Read_Reverse(pointer, c_string.Array()), pointer -= read_count) {
                        CHECK(utf.Decode() != utf_p::Replacement_Point());
                    }
                }
            }

            TEST_SUITE("Unit_Count()")
            {
                TEST_CASE_TEMPLATE("should return the number of units the charcoder holds", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    utf_p utf = Random_Scalar();
                    CHECK(utf_p::Has_1_To_1_Unit_To_Point_Ratio());
                    CHECK(utf.Unit_Count() == 1);
                }
            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("[]()")
            {
                TEST_CASE_TEMPLATE("should return a copy of the indexed unit held by the charcoder", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    point_t random = Random_Non_Replacement_Scalar();
                    utf_p utf = random;
                    if constexpr (has_native_endianness_tr<utf_p>) {
                        CHECK(utf[0] == random);
                    } else if constexpr (has_non_native_endianness_tr<utf_p>) {
                        CHECK(utf[0] == os::endian::Swap(utf_32_t::unit_t(random)));
                    } else {
                        static_assert(false);
                    }
                }
            }
        }

        TEST_SUITE("none_t interface")
        {
            TEST_SUITE("none_ctor()")
            {
                TEST_CASE_TEMPLATE("should set to terminus", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    utf_p utf = none_t();
                    CHECK(utf.Decode() == 0);
                }
            }

            TEST_SUITE("none_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should set to terminus", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;

                    utf_p utf = Random_Non_Terminus_Scalar();
                    CHECK(utf.Decode() != 0);
                    utf = none_t();
                    CHECK(utf.Decode() == 0);
                }

                TEST_CASE_TEMPLATE("should return itself", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;

                    utf_p utf = Random_Non_Terminus_Scalar();
                    CHECK(&(utf = none_t()) == &utf);
                }
            }

            TEST_SUITE("==(none_t)")
            {
                TEST_CASE_TEMPLATE("should return true if equal to terminus", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    utf_p utf = 0;
                    CHECK_TRUE(utf == none_t());
                }

                TEST_CASE_TEMPLATE("should return false if not equal to terminus", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    utf_p utf = Random_Non_Terminus_Scalar();
                    CHECK_FALSE(utf == none_t());
                }
            }

            TEST_SUITE("!=(none_t)")
            {
                TEST_CASE_TEMPLATE("should return true if not equal to terminus", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    utf_p utf = Random_Non_Terminus_Scalar();
                    CHECK_TRUE(utf != none_t());
                }

                TEST_CASE_TEMPLATE("should return false if equal to terminus", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;

                    utf_p utf = 0;
                    CHECK_FALSE(utf != none_t());
                }
            }
        }
    }

}}
