/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "nkr/charcoder/ascii_t.h"
#include "nkr/charcoder/utf_8_t.h"
#include "nkr/charcoder/utf_16_t.h"
#include "nkr/charcoder/utf_32_t.h"

#include "nkr/string/stack_t.h"

#include "doctest.h"

namespace nkr { namespace string {

    TEST_SUITE("stack_t<charcoder_p, unit_capacity_p>")
    {
    #define nkr_RESOLVED(QUALIFIER_p, CHARCODER_p, UNIT_CAPACITY_p) \
        QUALIFIER_p stack_t<CHARCODER_p, UNIT_CAPACITY_p>

    #define nkr_UNIT_CAPACITIES(QUALIFIER_p, CHARCODER_p)   \
        nkr_RESOLVED(QUALIFIER_p, CHARCODER_p, 16),         \
        nkr_RESOLVED(QUALIFIER_p, CHARCODER_p, 128)

    #define nkr_CHARCODERS(QUALIFIER_p)                             \
        nkr_UNIT_CAPACITIES(QUALIFIER_p, charcoder::ascii_t),       \
        nkr_UNIT_CAPACITIES(QUALIFIER_p, charcoder::utf_8_t),       \
        nkr_UNIT_CAPACITIES(QUALIFIER_p, charcoder::utf_16_be_t),   \
        nkr_UNIT_CAPACITIES(QUALIFIER_p, charcoder::utf_16_le_t),   \
        nkr_UNIT_CAPACITIES(QUALIFIER_p, charcoder::utf_32_be_t),   \
        nkr_UNIT_CAPACITIES(QUALIFIER_p, charcoder::utf_32_le_t)

    #define nkr_REGULAR             \
        nkr_CHARCODERS(nkr_BLANK)

    #define nkr_NON_CONST           \
        nkr_CHARCODERS(nkr_BLANK),  \
        nkr_CHARCODERS(volatile)

    #define nkr_CONST                   \
        nkr_CHARCODERS(const),          \
        nkr_CHARCODERS(const volatile)

    #define nkr_ALL     \
        nkr_NON_CONST,  \
        nkr_CONST

        TEST_SUITE("parameters")
        {
            TEST_SUITE("charcoder_p")
            {
                TEST_CASE_TEMPLATE("should accept any charcoder with no change to the template", string_p, nkr_ALL)
                {
                    using charcoder_t = string_p::charcoder_t;

                    static_assert(is_tr<charcoder_t, typename stack_t<charcoder_t>::charcoder_t>);
                    static_assert(is_tr<charcoder_t, typename stack_t<const charcoder_t>::charcoder_t>);
                    static_assert(is_tr<charcoder_t, typename stack_t<volatile charcoder_t>::charcoder_t>);
                    static_assert(is_tr<charcoder_t, typename stack_t<const volatile charcoder_t>::charcoder_t>);
                }
            }

            TEST_SUITE("unit_capacity_p")
            {
                TEST_CASE_TEMPLATE("should accept any unit capacity above 0", string_p, nkr_ALL)
                {
                    using charcoder_t = string_p::charcoder_t;

                    static_assert(stack_t<charcoder_t, 1>::Unit_Capacity() == 1);
                    static_assert(stack_t<charcoder_t, 2>::Unit_Capacity() == 2);
                    static_assert(stack_t<charcoder_t, 4>::Unit_Capacity() == 4);
                    static_assert(stack_t<charcoder_t, 8>::Unit_Capacity() == 8);
                    static_assert(stack_t<charcoder_t, 16>::Unit_Capacity() == 16);
                    static_assert(stack_t<charcoder_t, 32>::Unit_Capacity() == 32);
                    static_assert(stack_t<charcoder_t, 64>::Unit_Capacity() == 64);
                    static_assert(stack_t<charcoder_t, 128>::Unit_Capacity() == 128);
                    static_assert(stack_t<charcoder_t, 0xFFFF>::Unit_Capacity() == 0xFFFF);
                }

                TEST_CASE_TEMPLATE("should default to 128", string_p, nkr_ALL)
                {
                    using charcoder_t = string_p::charcoder_t;

                    static_assert(stack_t<charcoder_t>::Unit_Capacity() == 128);
                }
            }
        }

        TEST_SUITE("aliases")
        {
            TEST_SUITE("charcoder_t")
            {
                TEST_CASE_TEMPLATE("should have a charcoder_t", string_p, nkr_ALL)
                {
                    using charcoder_t = string_p::charcoder_t;

                    static_assert(is_tr<charcoder_t, charcoder_t>);
                }

                TEST_CASE_TEMPLATE("should never be qualified", string_p, nkr_ALL)
                {
                    using charcoder_t = string_p::charcoder_t;

                    static_assert(is_tr<charcoder_t, std::remove_cv_t<charcoder_t>>);
                }
            }

            TEST_SUITE("unit_t")
            {
                TEST_CASE_TEMPLATE("should have a unit_t", string_p, nkr_ALL)
                {
                    using unit_t = string_p::unit_t;

                    static_assert(is_tr<unit_t, unit_t>);
                }

                TEST_CASE_TEMPLATE("should be the same as the charcoder_t's unit_t", string_p, nkr_ALL)
                {
                    using charcoder_t = string_p::charcoder_t;
                    using unit_t = string_p::unit_t;

                    static_assert(is_tr<unit_t, typename charcoder_t::unit_t>);
                }
            }

            TEST_SUITE("array_t")
            {
                TEST_CASE_TEMPLATE("should have an array_t", string_p, nkr_ALL)
                {
                    using array_t = string_p::array_t;

                    static_assert(is_tr<array_t, array_t>);
                }

                TEST_CASE_TEMPLATE("should be the same as a stack::array_t", string_p, nkr_ALL)
                {
                    using unit_t = string_p::unit_t;
                    using array_t = string_p::array_t;

                    static_assert(is_tr<array_t, array::stack_t<unit_t, string_p::Unit_Capacity()>>);
                }

                TEST_CASE_TEMPLATE("should never be qualified", string_p, nkr_ALL)
                {
                    using array_t = string_p::array_t;

                    static_assert(is_tr<array_t, std::remove_cv_t<array_t>>);
                }
            }
        }

        TEST_SUITE("static constexpr functions")
        {
            TEST_SUITE("Unit_Capacity()")
            {
                TEST_CASE_TEMPLATE("should always be above 1 to allow for the terminus", string_p, nkr_ALL)
                {
                    static_assert(string_p::Unit_Capacity() >= 1);
                }
            }
        }

        TEST_SUITE("static functions")
        {
            TEST_SUITE("Empty_C_String()")
            {
                TEST_CASE_TEMPLATE("should return a raw const unit_t pointer", string_p, nkr_ALL)
                {
                    using unit_t = string_p::unit_t;

                    static_assert(is_tr<decltype(string_p::Empty_C_String()), const unit_t*>);
                }

                TEST_CASE_TEMPLATE("should only contain the terminus", string_p, nkr_ALL)
                {
                    using unit_t = string_p::unit_t;

                    const unit_t* c_string = string_p::Empty_C_String();
                    CHECK(*c_string == 0);
                }
            }
        }

        TEST_SUITE("protected object data")
        {
            TEST_SUITE("point_count")
            {
                TEST_CASE_TEMPLATE("should have a point_count that is a count_t", string_p, nkr_ALL)
                {
                    class derived_t :
                        public string_p
                    {
                    public:
                        static_assert(is_tr<decltype(string_p::point_count), count_t>);
                    };
                }
            }

            TEST_SUITE("array")
            {
                TEST_CASE_TEMPLATE("should have an array that is a array_t", string_p, nkr_ALL)
                {
                    using array_t = string_p::array_t;

                    class derived_t :
                        public string_p
                    {
                    public:
                        static_assert(is_tr<decltype(string_p::array), array_t>);
                    };
                }
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                TEST_CASE_TEMPLATE("should make an empty string", string_p, nkr_ALL)
                {
                    string_p string;
                    CHECK(string.Unit_Length() == 0);
                }

                TEST_CASE_TEMPLATE("should have a unit count of 1", string_p, nkr_ALL)
                {
                    string_p string;
                    CHECK(string.Unit_Count() == 1);
                }

                TEST_CASE_TEMPLATE("should have the terminus", string_p, nkr_ALL)
                {
                    string_p string;
                    CHECK(string.Unit(0) == 0);
                }
            }

            TEST_SUITE("charcoder_ctor()")
            {
                TEST_CASE_TEMPLATE("should make a string with a non-terminus charcoder", string_p, nkr_ALL)
                {
                    using charcoder_t = string_p::charcoder_t;

                    point_t point = Random<stack_t<charcoder_t>, 2, 2>().At(0).Point();
                    charcoder_t charcoder;
                    charcoder.Encode(point);
                    string_p string(charcoder);
                    CHECK(string.At(0).Point() == point);
                }

                TEST_CASE_TEMPLATE("should make a string with a non-terminus charcoder ending up with a point length of 1", string_p, nkr_ALL)
                {
                    using charcoder_t = string_p::charcoder_t;

                    point_t point = Random<stack_t<charcoder_t>, 2, 2>().At(0).Point();
                    charcoder_t charcoder;
                    charcoder.Encode(point);
                    string_p string(charcoder);
                    CHECK(string.Point_Length() == 1);
                }

                TEST_CASE_TEMPLATE("should make a string with a non-terminus charcoder ending up with a point count of 2", string_p, nkr_ALL)
                {
                    using charcoder_t = string_p::charcoder_t;

                    point_t point = Random<stack_t<charcoder_t>, 2, 2>().At(0).Point();
                    charcoder_t charcoder;
                    charcoder.Encode(point);
                    string_p string(charcoder);
                    CHECK(string.Point_Count() == 2);
                }

                TEST_CASE_TEMPLATE("should make a string with a terminus charcoder", string_p, nkr_ALL)
                {

                }

                TEST_CASE_TEMPLATE("should make a string with a terminus charcoder ending up with a point length of 0", string_p, nkr_ALL)
                {

                }

                TEST_CASE_TEMPLATE("should make a string with a terminus charcoder ending up with a point count of 1", string_p, nkr_ALL)
                {

                }
            }

            TEST_SUITE("c_string_ctor()")
            {
                TEST_CASE_TEMPLATE("should make a string by copying some C string using the same charcoder", string_p, nkr_ALL)
                {
                    using charcoder_t = string_p::charcoder_t;

                    string_p other = Random<string_p>();
                    string_p string(other.C_String());
                    CHECK(string.Point_Count() == other.Point_Count());

                    auto string_itr = string.At_First();
                    auto other_itr = other.At_First();
                    for (; !string_itr.Is_At_Postfix(); string_itr += 1, other_itr += 1) {
                        CHECK(string_itr.Point() == other_itr.Point());
                    }
                }
            }

            TEST_SUITE("copy_any_string_ctor()")
            {

            }

            TEST_SUITE("move_any_non_const_string_ctor()")
            {

            }

            TEST_SUITE("copy_ctor()")
            {

            }

            TEST_SUITE("copy_volatile_ctor()")
            {

            }

            TEST_SUITE("move_ctor()")
            {

            }

            TEST_SUITE("move_volatile_ctor()")
            {

            }

            TEST_SUITE("copy_assignment_ctor()")
            {

            }

            TEST_SUITE("copy_volatile_assignment_ctor()")
            {

            }

            TEST_SUITE("move_assignment_ctor()")
            {

            }

            TEST_SUITE("move_volatile_assignment_ctor()")
            {

            }

            TEST_SUITE("dtor()")
            {

            }
        }

        TEST_SUITE("methods")
        {
            TEST_SUITE("Has_Terminus()")
            {

            }

            TEST_SUITE("Unit_Capacity()")
            {
                TEST_CASE_TEMPLATE("should return the same unit capacity as the static constexpr function", string_p, nkr_ALL)
                {

                }
            }

            TEST_SUITE("Unit_Count()")
            {
                TEST_CASE_TEMPLATE("should always be below the unit capacity", string_p, nkr_ALL)
                {

                }
            }

            TEST_SUITE("Unit_Length()")
            {
                TEST_CASE_TEMPLATE("should always be below the unit capacity", string_p, nkr_ALL)
                {

                }
            }

            TEST_SUITE("Point_Count()")
            {
                TEST_CASE_TEMPLATE("should always be below the unit capacity", string_p, nkr_ALL)
                {

                }
            }

            TEST_SUITE("Point_Length()")
            {
                TEST_CASE_TEMPLATE("should always be below the unit capacity", string_p, nkr_ALL)
                {

                }
            }

            TEST_SUITE("C_String()")
            {

            }

            TEST_SUITE("Push(point_t)")
            {

            }

            TEST_SUITE("Push(charcoder_t)")
            {

            }

            TEST_SUITE("Push(c_string)")
            {

            }

            TEST_SUITE("Push(c_string, unit_length)")
            {

            }

            TEST_SUITE("Push(any_string_tr auto&)")
            {

            }

            TEST_SUITE("Push(any_non_const_string_tr auto&&)")
            {

            }

            TEST_SUITE("Unit()")
            {

            }
        }
    }

}}
