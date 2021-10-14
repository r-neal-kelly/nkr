/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "nkr/array/dynamic_t.h"
#include "nkr/array/stack_t.h"

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

        static inline point_t
            Random_Point()
        {
            return Random<point_t>(0, 127);
        }

        static inline point_t
            Random_Non_Point()
        {
            return Random<point_t>(128);
        }

        static inline point_t
            Random_Non_Terminus_Point()
        {
            return Random<point_t>(1, 127);
        }

        static inline point_t
            Random_Non_Replacement_Point()
        {
            point_t random;
            do {
                random = Random_Point();
            } while (random == ascii_t::Replacement_Point());

            return random;
        }

        static inline point_t
            Random_Non_Terminus_And_Non_Replacement_Point()
        {
            point_t random;
            do {
                random = Random_Non_Terminus_Point();
            } while (random == ascii_t::Replacement_Point());

            return random;
        }

        template <typename charcoder_p, count_t point_count_p>
        static inline auto
            Random_C_String()
        {
            array::stack_t<typename charcoder_p::unit_t, point_count_p> string;
            for (index_t idx = 0, end = point_count_p - 1; idx < end; idx += 1) {
                string.Push(charcoder_p::unit_t(Random_Non_Terminus_And_Non_Replacement_Point())).Ignore_Error();
            }
            string.Push(charcoder_p::unit_t(0)).Ignore_Error();

            return string;
        }

        template <typename charcoder_p, count_t unit_count_p>
        static inline auto
            Error_Ridden_C_String()
        {
            array::stack_t<typename charcoder_p::unit_t, unit_count_p> string;
            for (index_t idx = 0, end = unit_count_p - 1; idx < end; idx += 1) {
                string.Push(charcoder_p::unit_t(Random_Non_Point())).Ignore_Error();
            }
            string.Push(charcoder_p::unit_t(0)).Ignore_Error();

            return string;
        }

        TEST_SUITE("aliases")
        {
            TEST_SUITE("unit_t")
            {
                TEST_CASE_TEMPLATE("should have a unit type of char", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    static_assert(is_tr<unit_t, char>);
                }
            }
        }

        TEST_SUITE("static constexpr functions")
        {
            TEST_SUITE("Replacement_Point()")
            {
                TEST_CASE_TEMPLATE("should return the replacement character, currently '?'", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    static_assert(ascii_p::Replacement_Point() == '?');
                }
            }

            TEST_SUITE("Has_1_To_1_Unit_To_Point_Ratio()")
            {
                TEST_CASE_TEMPLATE("should always return true for this charcoder", ascii_p, nkr_ALL)
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
                        static_assert(is_tr<decltype(ascii_p::unit), unit_t>);
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

                TEST_CASE_TEMPLATE("should always have a unit count of 1", ascii_p, nkr_ALL)
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

                TEST_CASE_TEMPLATE("should always have a unit count of 1 for this charcoder", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random<point_t>(0, 127);
                    ascii_p ascii = random;
                    CHECK(ascii.Unit_Count() == 1);
                }
            }

            TEST_SUITE("copy_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy other's data so that it decodes the same point", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random_Point();
                    ascii_p other = random;
                    ascii_p ascii = other;
                    CHECK(ascii.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should not alter other", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random_Point();
                    ascii_p other = random;
                    ascii_p ascii = other;
                    CHECK(other.Decode() == random);
                }
            }

            TEST_SUITE("move_ctor()")
            {
                TEST_CASE_TEMPLATE("should move other's data so that it decodes the other's point", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random_Point();
                    std::remove_const_t<ascii_p> other = random;
                    ascii_p ascii = nkr::Move(other);
                    CHECK(ascii.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should set other's data so that it decodes the terminus", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random_Non_Terminus_Point();
                    std::remove_const_t<ascii_p> other = random;
                    ascii_p ascii = nkr::Move(other);
                    CHECK(other.Decode() == 0);
                }
            }

            TEST_SUITE("copy_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy other's data so that it decodes the same point", ascii_p, nkr_NON_CONST)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random_Point();
                    const ascii_p other = random;
                    ascii_p ascii;
                    ascii = other;
                    CHECK(ascii.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should not alter other", ascii_p, nkr_NON_CONST)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random_Point();
                    const ascii_p other = random;
                    ascii_p ascii;
                    ascii = other;
                    CHECK(other.Decode() == random);
                }
            }

            TEST_SUITE("copy_volatile_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy other's data so that it decodes the same point", ascii_p, nkr_NON_CONST)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random_Point();
                    const volatile ascii_p other = random;
                    ascii_p ascii;
                    ascii = other;
                    CHECK(ascii.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should not alter other", ascii_p, nkr_NON_CONST)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random_Point();
                    const volatile ascii_p other = random;
                    ascii_p ascii;
                    ascii = other;
                    CHECK(other.Decode() == random);
                }
            }

            TEST_SUITE("move_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should move other's data so that it decodes to same point", ascii_p, nkr_NON_CONST)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random_Point();
                    ascii_p other = random;
                    ascii_p ascii;
                    ascii = nkr::Move(other);
                    CHECK(ascii.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should set other's data so that it decodes the terminus", ascii_p, nkr_NON_CONST)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random_Non_Terminus_Point();
                    ascii_p other = random;
                    ascii_p ascii;
                    ascii = nkr::Move(other);
                    CHECK(other.Decode() == 0);
                }
            }

            TEST_SUITE("move_volatile_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should move other's data so that it decodes to same point", ascii_p, nkr_NON_CONST)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random_Point();
                    volatile ascii_p other = random;
                    ascii_p ascii;
                    ascii = nkr::Move(other);
                    CHECK(ascii.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should set other's data so that it decodes the terminus", ascii_p, nkr_NON_CONST)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random_Non_Terminus_Point();
                    volatile ascii_p other = random;
                    ascii_p ascii;
                    ascii = nkr::Move(other);
                    CHECK(other.Decode() == 0);
                }
            }

            TEST_SUITE("dtor()")
            {
                TEST_CASE_TEMPLATE("should set its data to decode the terminus", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;
                    
                    point_t random = Random_Non_Terminus_Point();
                    ascii_p ascii = random;
                    CHECK(ascii.Decode() != 0);
                    ascii.~ascii_p();
                    CHECK(ascii.Decode() == 0);
                }
            }
        }

        TEST_SUITE("methods")
        {
            TEST_SUITE("Is_Well_Formed()")
            {
                TEST_CASE_TEMPLATE("should check if the units make a valid point."
                                   "should always return true because the charcoder can never be invalid."
                                   "(only meant for assertions)",
                                   ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random<point_t>();
                    ascii_p ascii = random;
                    CHECK(ascii.Is_Well_Formed() == true);
                }
            }

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

                TEST_CASE_TEMPLATE("should encode an invalid point with the replacement point", ascii_p, nkr_NON_CONST)
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
                TEST_CASE_TEMPLATE("should decode a valid point", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random<point_t>(0, 127);
                    ascii_p ascii = random;
                    CHECK(ascii.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should decode an invalid point with the replacement point", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random<point_t>(128);
                    ascii_p ascii = random;
                    CHECK(ascii.Decode() == ascii_p::Replacement_Point());
                }
            }

            TEST_SUITE("Read_Forward()")
            {
                TEST_CASE_TEMPLATE("should read forward from a given pointer to string", ascii_p, nkr_NON_CONST)
                {
                    using unit_t = ascii_p::unit_t;

                    auto c_string = Random_C_String<ascii_p, 8>();
                    const index_t index = Random<index_t>(0, c_string.Count() - 2);

                    ascii_p ascii;
                    ascii.Read_Forward(&c_string[index]);
                    CHECK(ascii.Decode() != 0);
                    CHECK(ascii.Decode() != ascii_p::Replacement_Point());
                }

                TEST_CASE_TEMPLATE("should return the number of units read", ascii_p, nkr_NON_CONST)
                {
                    using unit_t = ascii_p::unit_t;

                    auto c_string = Random_C_String<ascii_p, 8>();
                    const index_t index = Random<index_t>(0, c_string.Count() - 2);

                    ascii_p ascii;
                    CHECK(ascii.Read_Forward(&c_string[index]) != 0);
                }

                TEST_CASE_TEMPLATE("should allow for iteration over the string", ascii_p, nkr_NON_CONST)
                {
                    using unit_t = ascii_p::unit_t;

                    auto c_string = Random_C_String<ascii_p, 8>();
                    const unit_t* pointer = c_string.Array();

                    ascii_p ascii;
                    count_t read_count = ascii.Read_Forward(pointer);
                    for (; ascii.Decode() != 0; pointer += read_count, read_count = ascii.Read_Forward(pointer)) {
                        CHECK(ascii.Decode() != ascii_p::Replacement_Point());
                    }
                }
            }

            TEST_SUITE("Read_Reverse()")
            {
                TEST_CASE_TEMPLATE("should read reverse from a given pointer to string and pointer to first unit."
                                   "should not read the unit pointed to",
                                   ascii_p, nkr_NON_CONST)
                {
                    using unit_t = ascii_p::unit_t;

                    auto c_string = Random_C_String<ascii_p, 8>();
                    const index_t index = Random<index_t>(1, c_string.Count() - 1);

                    ascii_p ascii;
                    ascii.Read_Reverse(&c_string[index], &c_string[0]);
                    CHECK(ascii.Decode() != 0);
                    CHECK(ascii.Decode() != ascii_p::Replacement_Point());
                }

                TEST_CASE_TEMPLATE("should return the number of units read", ascii_p, nkr_NON_CONST)
                {
                    using unit_t = ascii_p::unit_t;

                    auto c_string = Random_C_String<ascii_p, 8>();
                    const index_t index = Random<index_t>(1, c_string.Count() - 1);

                    ascii_p ascii;
                    CHECK(ascii.Read_Reverse(&c_string[index], &c_string[0]) != 0);
                }

                TEST_CASE_TEMPLATE("should allow for iteration over the string", ascii_p, nkr_NON_CONST)
                {
                    using unit_t = ascii_p::unit_t;

                    auto c_string = Random_C_String<ascii_p, 8>();
                    const unit_t* pointer = c_string.Array() + c_string.Count();

                    ascii_p ascii;
                    count_t read_count = 0;
                    for (; pointer != c_string.Array(); read_count = ascii.Read_Reverse(pointer, c_string.Array()), pointer -= read_count) {
                        CHECK(ascii.Decode() != ascii_p::Replacement_Point());
                    }
                }

                TEST_CASE_TEMPLATE("should interpret the same points in an error-free string as when reading forwards", ascii_p, nkr_NON_CONST)
                {
                    using unit_t = ascii_p::unit_t;

                    auto c_string = Random_C_String<ascii_p, 128>();
                    array::dynamic_t<point_t> forward_points(128);
                    array::dynamic_t<point_t> backward_points(128);
                    nkr_ASSERT_THAT(forward_points.Has_Memory());
                    nkr_ASSERT_THAT(backward_points.Has_Memory());

                    unit_t* const first = c_string.Array();
                    unit_t* const postfix = first + c_string.Count();

                    ascii_p ascii;

                    for (unit_t* itr = first; itr != postfix;) {
                        itr += ascii.Read_Forward(itr);
                        if (forward_points.Push(ascii.Decode()) != allocator_err::NONE) {
                            nkr_ASSERT_THAT(false);
                        }
                    }

                    for (unit_t* itr = postfix; itr != first;) {
                        itr -= ascii.Read_Reverse(itr, first);
                        if (backward_points.Push(ascii.Decode()) != allocator_err::NONE) {
                            nkr_ASSERT_THAT(false);
                        }
                    }

                    CHECK(forward_points.Count() == backward_points.Count());
                    for (index_t idx = 0, end = forward_points.Count(); idx < end; idx += 1) {
                        CHECK(forward_points[idx] == backward_points[end - 1 - idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should interpret the same points in an error-ridden string as when reading forwards", ascii_p, nkr_NON_CONST)
                {
                    using unit_t = ascii_p::unit_t;

                    auto c_string = Error_Ridden_C_String<ascii_p, 128>();
                    array::dynamic_t<point_t> forward_points(128);
                    array::dynamic_t<point_t> backward_points(128);
                    nkr_ASSERT_THAT(forward_points.Has_Memory());
                    nkr_ASSERT_THAT(backward_points.Has_Memory());

                    unit_t* const first = c_string.Array();
                    unit_t* const postfix = first + c_string.Count();

                    ascii_p ascii;

                    for (unit_t* itr = first; itr != postfix;) {
                        itr += ascii.Read_Forward(itr);
                        if (forward_points.Push(ascii.Decode()) != allocator_err::NONE) {
                            nkr_ASSERT_THAT(false);
                        }
                    }

                    for (unit_t* itr = postfix; itr != first;) {
                        itr -= ascii.Read_Reverse(itr, first);
                        if (backward_points.Push(ascii.Decode()) != allocator_err::NONE) {
                            nkr_ASSERT_THAT(false);
                        }
                    }

                    CHECK(forward_points.Count() == backward_points.Count());
                    for (index_t idx = 0, end = forward_points.Count(); idx < end; idx += 1) {
                        CHECK(forward_points[idx] == backward_points[end - 1 - idx]);
                    }
                }
            }

            TEST_SUITE("Unit_Count()")
            {
                TEST_CASE_TEMPLATE("should return the number of units the charcoder holds", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random<point_t>();
                    ascii_p ascii = random;
                    CHECK(ascii_p::Has_1_To_1_Unit_To_Point_Ratio());
                    CHECK(ascii.Unit_Count() == 1);
                }
            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("[]()")
            {
                TEST_CASE_TEMPLATE("should return a copy of the indexed unit held by the charcoder", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    point_t random = Random_Non_Terminus_And_Non_Replacement_Point();
                    ascii_p ascii = random;
                    CHECK(ascii[0] == random);
                }
            }
        }

        TEST_SUITE("none_t interface")
        {
            TEST_SUITE("none_ctor()")
            {
                TEST_CASE_TEMPLATE("should set to terminus", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    ascii_p ascii = none_t();
                    CHECK(ascii.Decode() == 0);
                }
            }

            TEST_SUITE("none_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should set to terminus", ascii_p, nkr_NON_CONST)
                {
                    using unit_t = ascii_p::unit_t;

                    ascii_p ascii = Random_Non_Terminus_Point();
                    CHECK(ascii.Decode() != 0);
                    ascii = none_t();
                    CHECK(ascii.Decode() == 0);
                }

                TEST_CASE_TEMPLATE("should return itself", ascii_p, nkr_NON_CONST)
                {
                    using unit_t = ascii_p::unit_t;

                    ascii_p ascii = Random_Non_Terminus_Point();
                    CHECK(&(ascii = none_t()) == &ascii);
                }
            }

            TEST_SUITE("==(none_t)")
            {
                TEST_CASE_TEMPLATE("should return true if equal to terminus", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    ascii_p ascii = 0;
                    CHECK_TRUE(ascii == none_t());
                }

                TEST_CASE_TEMPLATE("should return false if not equal to terminus", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    ascii_p ascii = Random_Non_Terminus_Point();
                    CHECK_FALSE(ascii == none_t());
                }
            }

            TEST_SUITE("!=(none_t)")
            {
                TEST_CASE_TEMPLATE("should return true if not equal to terminus", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    ascii_p ascii = Random_Non_Terminus_Point();
                    CHECK_TRUE(ascii != none_t());
                }

                TEST_CASE_TEMPLATE("should return false if equal to terminus", ascii_p, nkr_ALL)
                {
                    using unit_t = ascii_p::unit_t;

                    ascii_p ascii = 0;
                    CHECK_FALSE(ascii != none_t());
                }
            }
        }
    }

}}
