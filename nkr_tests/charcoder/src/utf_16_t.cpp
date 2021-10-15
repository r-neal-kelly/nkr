/*
    Copyright 2021 r-neal-kelly
*/

#include "doctest.h"

#include "unicode.h"

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

        template <typename charcoder_p, count_t point_count_p>
        static inline auto
            Random_C_String()
        {
            constexpr const real_t bmp_probability = real_t(utf_32_t::BMP_LAST + 1) / real_t(utf_32_t::POINT_LAST + 1);

            array::stack_t<typename charcoder_p::unit_t, point_count_p * 2> string;
            if constexpr (has_native_endianness_tr<charcoder_p>) {
                for (index_t idx = 0, end = point_count_p - 1; idx < end; idx += 1) {
                    if (Random<bool_t>(bmp_probability)) {
                        string.Push(charcoder_p::unit_t(Random_Non_Terminus_And_Non_Replacement_BMP_Scalar())).Ignore_Error();
                    } else {
                        string.Push(charcoder_p::unit_t(Random_High_Surrogate())).Ignore_Error();
                        string.Push(charcoder_p::unit_t(Random_Low_Surrogate())).Ignore_Error();
                    }
                }
                string.Push(charcoder_p::unit_t(0)).Ignore_Error();
            } else if constexpr (has_non_native_endianness_tr<charcoder_p>) {
                for (index_t idx = 0, end = point_count_p - 1; idx < end; idx += 1) {
                    if (Random<bool_t>(bmp_probability)) {
                        string.Push(os::endian::Swap(charcoder_p::unit_t(Random_Non_Terminus_And_Non_Replacement_BMP_Scalar()))).Ignore_Error();
                    } else {
                        string.Push(os::endian::Swap(charcoder_p::unit_t(Random_High_Surrogate()))).Ignore_Error();
                        string.Push(os::endian::Swap(charcoder_p::unit_t(Random_Low_Surrogate()))).Ignore_Error();
                    }
                }
                string.Push(charcoder_p::unit_t(0)).Ignore_Error();
            } else {
                static_assert(false);
            }

            return string;
        }

        template <typename charcoder_p, count_t unit_count_p>
        static inline auto
            Error_Ridden_C_String()
        {
            array::stack_t<typename charcoder_p::unit_t, unit_count_p> string;
            for (index_t idx = 0, end = unit_count_p - 1; idx < end; idx += 1) {
                if (Random<bool_t>()) {
                    if constexpr (has_native_endianness_tr<charcoder_p>) {
                        string.Push(charcoder_p::unit_t(Random_Surrogate())).Ignore_Error();
                    } else if constexpr (has_non_native_endianness_tr<charcoder_p>) {
                        string.Push(os::endian::Swap(charcoder_p::unit_t(Random_Surrogate()))).Ignore_Error();
                    } else {
                        static_assert(false);
                    }
                } else {
                    if constexpr (has_native_endianness_tr<charcoder_p>) {
                        string.Push(charcoder_p::unit_t(Random_BMP_Scalar())).Ignore_Error();
                    } else if constexpr (has_non_native_endianness_tr<charcoder_p>) {
                        string.Push(os::endian::Swap(charcoder_p::unit_t(Random_BMP_Scalar()))).Ignore_Error();
                    } else {
                        static_assert(false);
                    }
                }
            }
            string.Push(charcoder_p::unit_t(0)).Ignore_Error();

            return string;
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
                TEST_CASE_TEMPLATE("should have a stack array to hold its total possible number of units", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    static_assert(is_tr<units_t, array::stack_t<unit_t, 2>>);
                }
            }
        }

        TEST_SUITE("static constexpr functions")
        {
            TEST_SUITE("Last_Point()")
            {
                TEST_CASE_TEMPLATE("should return the last Unicode point", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    static_assert(utf_p::Last_Point() == utf_32_t::POINT_LAST);
                }
            }

            TEST_SUITE("Replacement_Point()")
            {
                TEST_CASE_TEMPLATE("should return the Unicode replacement character", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    static_assert(utf_p::Replacement_Point() == utf_32_t::REPLACEMENT_CHARACTER);
                }
            }

            TEST_SUITE("Max_Unit_Count()")
            {
                TEST_CASE_TEMPLATE("should return 2", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    static_assert(utf_p::Max_Unit_Count() == 2);
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

                    point_t random = Random_Scalar();
                    utf_p utf = random;
                    utf.~utf_p();
                    CHECK(!utf.Is_Well_Formed());
                }
            }
        }

        TEST_SUITE("methods")
        {
            TEST_SUITE("Is_Well_Formed()")
            {
                TEST_CASE_TEMPLATE("should check if the units make a valid point."
                                   "should always return true because the charcoder can never be invalid, except when destructed."
                                   "(only meant for assertions)",
                                   utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Value();
                    utf_p utf = random;
                    CHECK(utf.Is_Well_Formed() == true);
                }
            }

            TEST_SUITE("Encode()")
            {
                TEST_CASE_TEMPLATE("should encode a scalar", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Scalar();
                    utf_p utf;
                    utf.Encode(random);
                    CHECK(utf.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should encode a non-point with the replacement point", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Non_Point();
                    utf_p utf;
                    utf.Encode(random);
                    CHECK(utf.Decode() == utf_p::Replacement_Point());
                }

                TEST_CASE_TEMPLATE("should encode a surrogate with the replacement point", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

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
                    using units_t = utf_p::units_t;

                    point_t random = Random_Scalar();
                    utf_p utf = random;
                    CHECK(utf.Decode() == random);
                }

                TEST_CASE_TEMPLATE("should decode a non-point with the replacement point", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Non_Point();
                    utf_p utf = random;
                    CHECK(utf.Decode() == utf_p::Replacement_Point());
                }

                TEST_CASE_TEMPLATE("should decode a surrogate with the replacement point", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

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
                    using units_t = utf_p::units_t;

                    auto c_string = Random_C_String<utf_p, 8>();
                    index_t index = Random<index_t>(0, c_string.Count() - 2);
                    if constexpr (has_native_endianness_tr<utf_p>) {
                        if (utf_32_t::Is_Surrogate_Low(c_string[index])) {
                            nkr_ASSERT_THAT(index > 0);
                            index -= 1;
                        }
                    } else if constexpr (has_non_native_endianness_tr<utf_p>) {
                        if (utf_32_t::Is_Surrogate_Low(os::endian::Swap(c_string[index]))) {
                            nkr_ASSERT_THAT(index > 0);
                            index -= 1;
                        }
                    } else {
                        static_assert(false);
                    }

                    utf_p utf;
                    utf.Read_Forward(&c_string[index]);
                    CHECK(utf.Decode() != 0);
                    CHECK(utf.Decode() != utf_p::Replacement_Point());
                }

                TEST_CASE_TEMPLATE("should return the number of units read", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    auto c_string = Random_C_String<utf_p, 8>();
                    index_t index = Random<index_t>(0, c_string.Count() - 2);
                    if constexpr (has_native_endianness_tr<utf_p>) {
                        if (utf_32_t::Is_Surrogate_Low(c_string[index])) {
                            nkr_ASSERT_THAT(index > 0);
                            index -= 1;
                        }
                    } else if constexpr (has_non_native_endianness_tr<utf_p>) {
                        if (utf_32_t::Is_Surrogate_Low(os::endian::Swap(c_string[index]))) {
                            nkr_ASSERT_THAT(index > 0);
                            index -= 1;
                        }
                    } else {
                        static_assert(false);
                    }

                    utf_p utf;
                    CHECK(utf.Read_Forward(&c_string[index]) != 0);
                }

                TEST_CASE_TEMPLATE("should allow for iteration over the string", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

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
                    using units_t = utf_p::units_t;

                    auto c_string = Random_C_String<utf_p, 8>();
                    index_t index = Random<index_t>(1, c_string.Count() - 1);
                    if constexpr (has_native_endianness_tr<utf_p>) {
                        if (utf_32_t::Is_Surrogate_Low(c_string[index])) {
                            nkr_ASSERT_THAT(index < c_string.Count() - 1);
                            index += 1;
                        }
                    } else if constexpr (has_non_native_endianness_tr<utf_p>) {
                        if (utf_32_t::Is_Surrogate_Low(os::endian::Swap(c_string[index]))) {
                            nkr_ASSERT_THAT(index < c_string.Count() - 1);
                            index += 1;
                        }
                    } else {
                        static_assert(false);
                    }

                    utf_p utf;
                    utf.Read_Reverse(&c_string[index], &c_string[0]);
                    CHECK(utf.Decode() != 0);
                    CHECK(utf.Decode() != utf_p::Replacement_Point());
                }

                TEST_CASE_TEMPLATE("should return the number of units read", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    auto c_string = Random_C_String<utf_p, 8>();
                    index_t index = Random<index_t>(1, c_string.Count() - 1);
                    if constexpr (has_native_endianness_tr<utf_p>) {
                        if (utf_32_t::Is_Surrogate_Low(c_string[index])) {
                            index += 1;
                        }
                    } else if constexpr (has_non_native_endianness_tr<utf_p>) {
                        if (utf_32_t::Is_Surrogate_Low(os::endian::Swap(c_string[index]))) {
                            index += 1;
                        }
                    } else {
                        static_assert(false);
                    }

                    utf_p utf;
                    CHECK(utf.Read_Reverse(&c_string[index], &c_string[0]) != 0);
                }

                TEST_CASE_TEMPLATE("should allow for iteration over the string", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    auto c_string = Random_C_String<utf_p, 8>();
                    const unit_t* pointer = c_string.Array() + c_string.Count();

                    utf_p utf;
                    count_t read_count = 0;
                    for (; pointer != c_string.Array(); read_count = utf.Read_Reverse(pointer, c_string.Array()), pointer -= read_count) {
                        CHECK(utf.Decode() != utf_p::Replacement_Point());
                    }
                }

                TEST_CASE_TEMPLATE("should interpret the same points in an error-free string as when reading forwards", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    auto c_string = Random_C_String<utf_p, 128>();
                    array::dynamic_t<point_t> forward_points(128);
                    array::dynamic_t<point_t> backward_points(128);
                    nkr_ASSERT_THAT(forward_points.Has_Memory());
                    nkr_ASSERT_THAT(backward_points.Has_Memory());

                    unit_t* const first = c_string.Array();
                    unit_t* const postfix = first + c_string.Count();

                    utf_p utf;

                    for (unit_t* itr = first; itr != postfix;) {
                        itr += utf.Read_Forward(itr);
                        if (forward_points.Push(utf.Decode()) != allocator_err::NONE) {
                            nkr_ASSERT_THAT(false);
                        }
                    }

                    for (unit_t* itr = postfix; itr != first;) {
                        itr -= utf.Read_Reverse(itr, first);
                        if (backward_points.Push(utf.Decode()) != allocator_err::NONE) {
                            nkr_ASSERT_THAT(false);
                        }
                    }

                    CHECK(forward_points.Count() == backward_points.Count());
                    for (index_t idx = 0, end = forward_points.Count(); idx < end; idx += 1) {
                        CHECK(forward_points[idx] == backward_points[end - 1 - idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should interpret the same points in an error-ridden string as when reading forwards", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    auto c_string = Error_Ridden_C_String<utf_p, 128>();
                    array::dynamic_t<point_t> forward_points(128);
                    array::dynamic_t<point_t> backward_points(128);
                    nkr_ASSERT_THAT(forward_points.Has_Memory());
                    nkr_ASSERT_THAT(backward_points.Has_Memory());

                    unit_t* const first = c_string.Array();
                    unit_t* const postfix = first + c_string.Count();

                    utf_p utf;

                    for (unit_t* itr = first; itr != postfix;) {
                        itr += utf.Read_Forward(itr);
                        if (forward_points.Push(utf.Decode()) != allocator_err::NONE) {
                            nkr_ASSERT_THAT(false);
                        }
                    }

                    for (unit_t* itr = postfix; itr != first;) {
                        itr -= utf.Read_Reverse(itr, first);
                        if (backward_points.Push(utf.Decode()) != allocator_err::NONE) {
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
                TEST_CASE_TEMPLATE("should return the number of units the charcoder holds", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    utf_p utf = Random_Scalar();
                    CHECK((utf.Unit_Count() == 1 || utf.Unit_Count() == 2));
                }

                TEST_CASE_TEMPLATE("should return 1 when holding a BMP scalar", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    utf_p utf = Random_BMP_Scalar();
                    CHECK(utf.Unit_Count() == 1);
                }

                TEST_CASE_TEMPLATE("should return 2 when holding a non BMP scalar", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    utf_p utf = Random_Non_BMP_Scalar();
                    CHECK(utf.Unit_Count() == 2);
                }
            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("[]()")
            {
                TEST_CASE_TEMPLATE("should return a copy of the indexed unit held by a charcoder with a BMP scalar", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_BMP_Scalar();
                    utf_p utf = random;
                    CHECK(utf.Unit_Count() == 1);
                    if constexpr (has_native_endianness_tr<utf_p>) {
                        CHECK(utf[0] == random);
                    } else if constexpr (has_non_native_endianness_tr<utf_p>) {
                        CHECK(utf[0] == os::endian::Swap(utf_p::unit_t(random)));
                    } else {
                        static_assert(false);
                    }
                }

                TEST_CASE_TEMPLATE("should return a copy of the indexed unit held by a charcoder with a non BMP scalar", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    point_t random = Random_Non_BMP_Scalar();
                    utf_p utf = random;
                    CHECK(utf.Unit_Count() == 2);
                    if constexpr (has_native_endianness_tr<utf_p>) {
                        CHECK(utf_32_t::Is_Surrogate_High(utf[0]));
                        CHECK(utf_32_t::Is_Surrogate_Low(utf[1]));
                    } else if constexpr (has_non_native_endianness_tr<utf_p>) {
                        CHECK(utf_32_t::Is_Surrogate_High(os::endian::Swap(utf[0])));
                        CHECK(utf_32_t::Is_Surrogate_Low(os::endian::Swap(utf[1])));
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
                    using units_t = utf_p::units_t;

                    utf_p utf = none_t();
                    CHECK(utf.Decode() == 0);
                }
            }

            TEST_SUITE("none_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should set to terminus", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    utf_p utf = Random_Non_Terminus_Scalar();
                    CHECK(utf.Decode() != 0);
                    utf = none_t();
                    CHECK(utf.Decode() == 0);
                }

                TEST_CASE_TEMPLATE("should return itself", utf_p, nkr_NON_CONST)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    utf_p utf = Random_Non_Terminus_Scalar();
                    CHECK(&(utf = none_t()) == &utf);
                }
            }

            TEST_SUITE("==(none_t)")
            {
                TEST_CASE_TEMPLATE("should return true if equal to terminus", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    utf_p utf = 0;
                    CHECK_TRUE(utf == none_t());
                }

                TEST_CASE_TEMPLATE("should return false if not equal to terminus", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    utf_p utf = Random_Non_Terminus_Scalar();
                    CHECK_FALSE(utf == none_t());
                }
            }

            TEST_SUITE("!=(none_t)")
            {
                TEST_CASE_TEMPLATE("should return true if not equal to terminus", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    utf_p utf = Random_Non_Terminus_Scalar();
                    CHECK_TRUE(utf != none_t());
                }

                TEST_CASE_TEMPLATE("should return false if equal to terminus", utf_p, nkr_ALL)
                {
                    using unit_t = utf_p::unit_t;
                    using units_t = utf_p::units_t;

                    utf_p utf = 0;
                    CHECK_FALSE(utf != none_t());
                }
            }
        }
    }

}}
