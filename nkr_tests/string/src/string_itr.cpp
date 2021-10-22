﻿/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "nkr/charcoder/ascii_t.h"
#include "nkr/charcoder/utf_8_t.h"
#include "nkr/charcoder/utf_16_t.h"
#include "nkr/charcoder/utf_32_t.h"

#include "nkr/string_itr.h"
#include "nkr/string/dynamic_t.h"
#include "nkr/string/stack_t.h"

#include "doctest.h"

namespace nkr { namespace string {

    TEST_SUITE("string_itr<string_p>")
    {
    #define nkr_RESOLVED(QUALIFIER_p, STRING_p, CHARCODER_p)            \
        QUALIFIER_p string_itr<STRING_p<CHARCODER_p>>,                  \
        QUALIFIER_p string_itr<const STRING_p<CHARCODER_p>>,            \
        QUALIFIER_p string_itr<volatile STRING_p<CHARCODER_p>>,         \
        QUALIFIER_p string_itr<const volatile STRING_p<CHARCODER_p>>

    #define nkr_CHARCODERS(QUALIFIER_p, STRING_p)                       \
        nkr_RESOLVED(QUALIFIER_p, STRING_p, charcoder::ascii_t),        \
        nkr_RESOLVED(QUALIFIER_p, STRING_p, charcoder::utf_8_t),        \
        nkr_RESOLVED(QUALIFIER_p, STRING_p, charcoder::utf_16_be_t),    \
        nkr_RESOLVED(QUALIFIER_p, STRING_p, charcoder::utf_16_le_t),    \
        nkr_RESOLVED(QUALIFIER_p, STRING_p, charcoder::utf_32_be_t),    \
        nkr_RESOLVED(QUALIFIER_p, STRING_p, charcoder::utf_32_le_t)

    #define nkr_STRINGS(QUALIFIER_p)            \
        nkr_CHARCODERS(QUALIFIER_p, dynamic_t), \
        nkr_CHARCODERS(QUALIFIER_p, stack_t)

    #define nkr_REGULAR         \
        nkr_STRINGS(nkr_BLANK)

    #define nkr_NON_CONST       \
        nkr_STRINGS(nkr_BLANK), \
        nkr_STRINGS(volatile)

    #define nkr_CONST               \
        nkr_STRINGS(const),         \
        nkr_STRINGS(const volatile)

    #define nkr_ALL     \
        nkr_NON_CONST,  \
        nkr_CONST

        TEST_SUITE("aliases")
        {
            TEST_SUITE("string_t")
            {
                TEST_CASE_TEMPLATE("should have a string_t", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    static_assert(any_string_tr<string_t>);
                }
            }

            TEST_SUITE("charcoder_t")
            {
                TEST_CASE_TEMPLATE("should have the same charcoder_t as its string_t", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    static_assert(is_tr<charcoder_t, typename string_t::charcoder_t>);
                }
            }

            TEST_SUITE("unit_t")
            {
                TEST_CASE_TEMPLATE("should have the same unit_t as its string_t", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    static_assert(is_tr<unit_t, string_t::unit_t>);
                }
            }
        }

        TEST_SUITE("protected object data")
        {
            TEST_SUITE("string")
            {
                TEST_CASE_TEMPLATE("should have a string that's a some_t<const string_t*>", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    class derived_t :
                        public itr_p
                    {
                    public:
                        static_assert(is_tr<decltype(itr_p::string), some_t<const string_t*>>);
                    };
                }
            }

            TEST_SUITE("is_prefix")
            {
                TEST_CASE_TEMPLATE("should have a is_prefix that's a bool_t", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    class derived_t :
                        public itr_p
                    {
                    public:
                        static_assert(is_tr<decltype(itr_p::is_prefix), bool_t>);
                    };
                }
            }

            TEST_SUITE("unit_index")
            {
                TEST_CASE_TEMPLATE("should have a unit_index that's an index_t", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    class derived_t :
                        public itr_p
                    {
                    public:
                        static_assert(is_tr<decltype(itr_p::unit_index), index_t>);
                    };
                }
            }

            TEST_SUITE("point_index")
            {
                TEST_CASE_TEMPLATE("should have a point_index that's an index_t", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    class derived_t :
                        public itr_p
                    {
                    public:
                        static_assert(is_tr<decltype(itr_p::point_index), index_t>);
                    };
                }
            }

            TEST_SUITE("read_unit_count")
            {
                TEST_CASE_TEMPLATE("should have a read_unit_count of count_t", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    class derived_t :
                        public itr_p
                    {
                    public:
                        static_assert(is_tr<decltype(itr_p::read_unit_count), count_t>);
                    };
                }
            }

            TEST_SUITE("charcoder")
            {
                TEST_CASE_TEMPLATE("should have a charcoder that's a charcoder_t", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    class derived_t :
                        public itr_p
                    {
                    public:
                        static_assert(is_tr<decltype(itr_p::charcoder), charcoder_t>);
                    };
                }
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("string_ctor()")
            {
                TEST_CASE_TEMPLATE("should set the iterator to the first point of a string", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    static_assert(is_tr<string_t, decltype(string)>);
                    itr_p itr(string);
                    CHECK(itr.Is_At_First());
                }
            }

            TEST_SUITE("point_index_ctor()")
            {
                TEST_CASE_TEMPLATE("should set the iterator to the indexed point of a string", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    itr_p itr(string, point_index);
                    optional_t<index_t> itr_point_index = itr.Point_Index();
                    CHECK(itr_point_index && itr_point_index.Value() == point_index);
                }

                TEST_CASE_TEMPLATE("should be able to set the iterator to the postfix of a string", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, string.Point_Count());
                    CHECK(itr.Is_At_Postfix());
                }
            }

            TEST_SUITE("prefix_ctor()")
            {
                TEST_CASE_TEMPLATE("should set the iterator to the prefix of a string", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::prefix_tg());
                    CHECK(itr.Is_At_Prefix());
                }
            }

            TEST_SUITE("first_ctor()")
            {
                TEST_CASE_TEMPLATE("should set the iterator to the first point of a string", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::first_tg());
                    CHECK(itr.Is_At_First());
                }
            }

            TEST_SUITE("last_ctor()")
            {
                TEST_CASE_TEMPLATE("should set the iterator to the last point of a string", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::last_tg());
                    CHECK(itr.Is_At_Last());
                }
            }

            TEST_SUITE("terminus_ctor()")
            {
                TEST_CASE_TEMPLATE("should set the iterator to the terminus of a string", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::terminus_tg());
                    CHECK(itr.Is_At_Terminus());
                }
            }

            TEST_SUITE("postfix_ctor()")
            {
                TEST_CASE_TEMPLATE("should set the iterator to the postfix of a string", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::postfix_tg());
                    CHECK(itr.Is_At_Postfix());
                }
            }

            TEST_SUITE("copy_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy the other without changing it", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    const std::remove_cv_t<itr_p> other(string, point_index);
                    itr_p itr(other);
                    CHECK(&itr.String() == &other.String());
                    CHECK(!itr.Is_At_Prefix() && !other.Is_At_Prefix());
                    CHECK(itr.Unit_Index().Value() == other.Unit_Index().Value());
                    CHECK(itr.Point_Index().Value() == other.Point_Index().Value());
                    CHECK(itr.Point() == other.Point());
                }
            }

            TEST_SUITE("copy_volatile_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy the other without changing it", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    const volatile std::remove_cv_t<itr_p> other(string, point_index);
                    itr_p itr(other);
                    CHECK(&itr.String() == &other.String());
                    CHECK(!itr.Is_At_Prefix() && !other.Is_At_Prefix());
                    CHECK(itr.Unit_Index().Value() == other.Unit_Index().Value());
                    CHECK(itr.Point_Index().Value() == other.Point_Index().Value());
                    CHECK(itr.Point() == other.Point());
                }
            }

            TEST_SUITE("move_ctor()")
            {
                TEST_CASE_TEMPLATE("should move the other, making the other assert when used further", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    std::remove_cv_t<itr_p> other(string, point_index);
                    itr_p itr(nkr::Move(other));
                    CHECK(&itr.String() == &string);
                    CHECK(!itr.Is_At_Prefix());
                    CHECK(itr.Unit_Index().Value() >= point_index);
                    CHECK(itr.Point_Index().Value() == point_index);
                }
            }

            TEST_SUITE("move_volatile_ctor()")
            {
                TEST_CASE_TEMPLATE("should move the other, making the other assert when used further", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    volatile std::remove_cv_t<itr_p> other(string, point_index);
                    itr_p itr(nkr::Move(other));
                    CHECK(&itr.String() == &string);
                    CHECK(!itr.Is_At_Prefix());
                    CHECK(itr.Unit_Index().Value() >= point_index);
                    CHECK(itr.Point_Index().Value() == point_index);
                }
            }

            TEST_SUITE("copy_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy other without changing it", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    const std::remove_cv_t<itr_p> other(string, point_index);
                    itr_p itr(string);
                    itr = other;
                    CHECK(&itr.String() == &other.String());
                    CHECK(!itr.Is_At_Prefix() && !other.Is_At_Prefix());
                    CHECK(itr.Unit_Index().Value() == other.Unit_Index().Value());
                    CHECK(itr.Point_Index().Value() == other.Point_Index().Value());
                    CHECK(itr.Point() == other.Point());
                }
            }

            TEST_SUITE("copy_volatile_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy other without changing it", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    const volatile std::remove_cv_t<itr_p> other(string, point_index);
                    itr_p itr(string);
                    itr = other;
                    CHECK(&itr.String() == &other.String());
                    CHECK(!itr.Is_At_Prefix() && !other.Is_At_Prefix());
                    CHECK(itr.Unit_Index().Value() == other.Unit_Index().Value());
                    CHECK(itr.Point_Index().Value() == other.Point_Index().Value());
                    CHECK(itr.Point() == other.Point());
                }
            }

            TEST_SUITE("move_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should move the other, making the other assert when used further", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    std::remove_cv_t<itr_p> other(string, point_index);
                    itr_p itr(string);
                    itr = nkr::Move(other);
                    CHECK(&itr.String() == &string);
                    CHECK(!itr.Is_At_Prefix());
                    CHECK(itr.Unit_Index().Value() >= point_index);
                    CHECK(itr.Point_Index().Value() == point_index);
                }
            }

            TEST_SUITE("move_volatile_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should move the other, making the other assert when used further", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    volatile std::remove_cv_t<itr_p> other(string, point_index);
                    itr_p itr(string);
                    itr = nkr::Move(other);
                    CHECK(&itr.String() == &string);
                    CHECK(!itr.Is_At_Prefix());
                    CHECK(itr.Unit_Index().Value() >= point_index);
                    CHECK(itr.Point_Index().Value() == point_index);
                }
            }

            TEST_SUITE("dtor()")
            {
                TEST_CASE_TEMPLATE("should make the iterator assert if used any further", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string);
                    itr.~itr_p();
                }
            }
        }

        TEST_SUITE("methods")
        {
            TEST_SUITE("String()")
            {
                TEST_CASE_TEMPLATE("should return the underlying string", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string);
                    CHECK(&itr.String() == &string);
                }
            }

            TEST_SUITE("Is_At()")
            {
                TEST_CASE_TEMPLATE("should return true when at the point index", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    const index_t point_index = Random<index_t>(0, string.Point_Count());
                    itr_p itr(string, point_index);
                    CHECK_TRUE(itr.Is_At(point_index));
                }

                TEST_CASE_TEMPLATE("should return false when at the prefix", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::prefix_tg());
                    CHECK_FALSE(itr.Is_At(Random<index_t>(0, string.Point_Count())));
                }

                TEST_CASE_TEMPLATE("should return false when moved to the prefix", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, Random<index_t>(0, string.Point_Count()));
                    itr.At_Prefix();
                    CHECK_FALSE(itr.Is_At(Random<index_t>(0, string.Point_Count())));
                }

                TEST_CASE_TEMPLATE("should return true when at the postfix and given the postfix index", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::postfix_tg());
                    CHECK_TRUE(itr.Is_At(string.Point_Count()));
                }

                TEST_CASE_TEMPLATE("should return false when at another point index", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    const count_t point_count = string.Point_Count();
                    const index_t point_index = Random<index_t>(0, point_count);
                    index_t other_point_index;
                    do {
                        other_point_index = Random<index_t>(0, point_count);
                    } while (other_point_index == point_index);
                    itr_p itr(string, other_point_index);
                    CHECK_FALSE(itr.Is_At(point_index));
                }
            }

            TEST_SUITE("Is_At_Prefix()")
            {
                TEST_CASE_TEMPLATE("should return true when at the prefix", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::prefix_tg());
                    CHECK_TRUE(itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should return false when at the postfix", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::postfix_tg());
                    CHECK_FALSE(itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should return false when at any point index", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, Random<index_t>(0, string.Point_Count()));
                    CHECK_FALSE(itr.Is_At_Prefix());
                }
            }

            TEST_SUITE("Is_At_First()")
            {
                TEST_CASE_TEMPLATE("should return true when at the first point", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::first_tg());
                    CHECK_TRUE(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should return false when at the prefix", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::prefix_tg());
                    CHECK_FALSE(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should return false when at the postfix", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::postfix_tg());
                    CHECK_FALSE(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should return false when at another point index", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, Random<index_t>(1, string.Point_Count()));
                    CHECK_FALSE(itr.Is_At_First());
                }
            }

            TEST_SUITE("Is_At_Last()")
            {
                TEST_CASE_TEMPLATE("should return true when at the last point", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::last_tg());
                    CHECK_TRUE(itr.Is_At_Last());
                }

                TEST_CASE_TEMPLATE("should return false when at the prefix of a string with a length greather than zero", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t, 2>();
                    itr_p itr(string, position_e::prefix_tg());
                    CHECK_FALSE(itr.Is_At_Last());
                }

                TEST_CASE_TEMPLATE("should return true when at the prefix of a string with a length of zero", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string;
                    itr_p itr(string, position_e::prefix_tg());
                    CHECK_TRUE(itr.Is_At_Last());
                }

                TEST_CASE_TEMPLATE("should return false when at the postfix", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::postfix_tg());
                    CHECK_FALSE(itr.Is_At_Last());
                }

                TEST_CASE_TEMPLATE("should return false when at another point index", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t, 2>();
                    const count_t point_count = string.Point_Count();
                    const index_t last_point_index = point_count - 2;
                    index_t random_point_index;
                    do {
                        random_point_index = Random<index_t>(0, point_count);
                    } while (random_point_index == last_point_index);
                    itr_p itr(string, random_point_index);
                    CHECK_FALSE(itr.Is_At_Last());
                }
            }

            TEST_SUITE("Is_At_Terminus()")
            {
                TEST_CASE_TEMPLATE("should return true when at the terminus", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::terminus_tg());
                    CHECK_TRUE(itr.Is_At_Terminus());
                }

                TEST_CASE_TEMPLATE("should return false when at the prefix", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::prefix_tg());
                    CHECK_FALSE(itr.Is_At_Terminus());
                }

                TEST_CASE_TEMPLATE("should return false when at the postfix", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::postfix_tg());
                    CHECK_FALSE(itr.Is_At_Terminus());
                }

                TEST_CASE_TEMPLATE("should return false when at another point index", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    const count_t point_count = string.Point_Count();
                    const index_t terminus_point_index = point_count - 1;
                    index_t random_point_index;
                    do {
                        random_point_index = Random<index_t>(0, point_count);
                    } while (random_point_index == terminus_point_index);
                    itr_p itr(string, random_point_index);
                    CHECK_FALSE(itr.Is_At_Terminus());
                }
            }

            TEST_SUITE("Is_At_Postfix()")
            {
                TEST_CASE_TEMPLATE("should return true when at the postfix", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::postfix_tg());
                    CHECK_TRUE(itr.Is_At_Postfix());
                }

                TEST_CASE_TEMPLATE("should return false when at the prefix", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::prefix_tg());
                    CHECK_FALSE(itr.Is_At_Postfix());
                }

                TEST_CASE_TEMPLATE("should return false when at another point index", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, Random<index_t>(0, string.Point_Count() - 1));
                    CHECK_FALSE(itr.Is_At_Postfix());
                }
            }

            TEST_SUITE("Is_At_Error()")
            {
                TEST_CASE_TEMPLATE("should return true when at a substring that doesn't match the charcoder", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t, 16>(true);
                    CHECK(string.Unit_Count() >= 16);
                }

                TEST_CASE_TEMPLATE("should return false when at a substring that does match the charcoder", itr_p, nkr_ALL)
                {

                }
            }

            TEST_SUITE("At()")
            {
                TEST_CASE_TEMPLATE("should move the iterator to the indexed point", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, Random<index_t>(0, string.Point_Count()));
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    itr.At(point_index);
                    CHECK_TRUE(itr.Is_At(point_index));
                }
            }

            TEST_SUITE("At_Prefix()")
            {
                TEST_CASE_TEMPLATE("should move the iterator to the prefix", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, Random<index_t>(0, string.Point_Count()));
                    itr.At_Prefix();
                    CHECK_TRUE(itr.Is_At_Prefix());
                }
            }

            TEST_SUITE("At_First()")
            {
                TEST_CASE_TEMPLATE("should move the iterator to the first point", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, Random<index_t>(0, string.Point_Count()));
                    itr.At_First();
                    CHECK_TRUE(itr.Is_At_First());
                }
            }

            TEST_SUITE("At_Last()")
            {
                TEST_CASE_TEMPLATE("should move the iterator to the last point", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, Random<index_t>(0, string.Point_Count()));
                    itr.At_Last();
                    CHECK_TRUE(itr.Is_At_Last());
                }
            }

            TEST_SUITE("At_Terminus()")
            {
                TEST_CASE_TEMPLATE("should move the iterator to the terminus", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, Random<index_t>(0, string.Point_Count()));
                    itr.At_Terminus();
                    CHECK_TRUE(itr.Is_At_Terminus());
                }
            }

            TEST_SUITE("At_Postfix()")
            {
                TEST_CASE_TEMPLATE("should move the iterator to the postfix", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, Random<index_t>(0, string.Point_Count()));
                    itr.At_Postfix();
                    CHECK_TRUE(itr.Is_At_Postfix());
                }
            }

            TEST_SUITE("Next()")
            {
                TEST_CASE_TEMPLATE("should move to the next point when not at the postfix", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count() - 1);
                    itr_p itr(string, point_index);
                    itr.Next();
                    CHECK(itr.Is_At(point_index + 1));
                }

                TEST_CASE_TEMPLATE("should return true when not at the postfix", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, Random<index_t>(0, string.Point_Count() - 1));
                    CHECK_TRUE(itr.Next());
                }

                TEST_CASE_TEMPLATE("should return false when at the postfix", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::postfix_tg());
                    CHECK_FALSE(itr.Next());
                }
            }

            TEST_SUITE("Prior()")
            {
                TEST_CASE_TEMPLATE("should move to the prior point when not at the prefix", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    itr_p itr(string, point_index);
                    itr.Prior();
                    if (point_index == 0) {
                        CHECK(itr.Is_At_Prefix());
                    } else {
                        CHECK(itr.Is_At(point_index - 1));
                    }
                }

                TEST_CASE_TEMPLATE("should return true when not at the prefix", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, Random<index_t>(0, string.Point_Count()));
                    CHECK_TRUE(itr.Prior());
                }

                TEST_CASE_TEMPLATE("should return false when at the prefix", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::prefix_tg());
                    CHECK_FALSE(itr.Prior());
                }
            }

            TEST_SUITE("Unit_Index()")
            {
                TEST_CASE_TEMPLATE("should not return an index if at the prefix", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::prefix_tg());
                    optional_t<index_t> unit_index = itr.Unit_Index();
                    CHECK(!unit_index);
                }

                TEST_CASE_TEMPLATE("should return the correct index for first", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::first_tg());
                    optional_t<index_t> unit_index = itr.Unit_Index();
                    CHECK(unit_index && unit_index.Value() == 0);
                }

                TEST_CASE_TEMPLATE("should return the correct index for last", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::last_tg());
                    optional_t<index_t> unit_index = itr.Unit_Index();
                    if (string.Unit_Length() > 0) {
                        CHECK(unit_index && unit_index.Value() == string.Unit_Length() - itr.Point_Unit_Count());
                    } else {
                        CHECK(!unit_index);
                    }
                }

                TEST_CASE_TEMPLATE("should return the correct index for terminus", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::terminus_tg());
                    optional_t<index_t> unit_index = itr.Unit_Index();
                    CHECK(unit_index && unit_index.Value() == string.Unit_Count() - 1);
                }

                TEST_CASE_TEMPLATE("should return the correct index for postfix", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::postfix_tg());
                    optional_t<index_t> unit_index = itr.Unit_Index();
                    CHECK(unit_index && unit_index.Value() == string.Unit_Count());
                }
            }

            TEST_SUITE("Point_Index()")
            {
                TEST_CASE_TEMPLATE("should not return an index if at the prefix", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::prefix_tg());
                    optional_t<index_t> point_index = itr.Point_Index();
                    CHECK(!point_index);
                }

                TEST_CASE_TEMPLATE("should return the correct index for first", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::first_tg());
                    optional_t<index_t> point_index = itr.Point_Index();
                    CHECK(point_index && point_index.Value() == 0);
                }

                TEST_CASE_TEMPLATE("should return the correct index for last", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::last_tg());
                    optional_t<index_t> point_index = itr.Point_Index();
                    if (string.Point_Length() > 0) {
                        CHECK(point_index && point_index.Value() == string.Point_Length() - 1);
                    } else {
                        CHECK(!point_index);
                    }
                }

                TEST_CASE_TEMPLATE("should return the correct index for terminus", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::terminus_tg());
                    optional_t<index_t> point_index = itr.Point_Index();
                    CHECK(point_index && point_index.Value() == string.Point_Count() - 1);
                }

                TEST_CASE_TEMPLATE("should return the correct index for postfix", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::postfix_tg());
                    optional_t<index_t> point_index = itr.Point_Index();
                    CHECK(point_index && point_index.Value() == string.Point_Count());
                }
            }

            TEST_SUITE("Point()")
            {
                TEST_CASE_TEMPLATE("should return 0 when at the prefix", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::prefix_tg());
                    CHECK(itr.Point() == 0);
                }

                TEST_CASE_TEMPLATE("should return 0 when at the first point in a string with a length of 0", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string;
                    itr_p itr(string, position_e::first_tg());
                    CHECK(itr.Point() == 0);
                }

                TEST_CASE_TEMPLATE("should not return 0 when at the first point in a string with a length greater than 0", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t, 2>();
                    itr_p itr(string, position_e::first_tg());
                    CHECK(itr.Point() != 0);
                }

                TEST_CASE_TEMPLATE("should return 0 when at the last point in a string with a length of 0", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string;
                    itr_p itr(string, position_e::last_tg());
                    CHECK(itr.Point() == 0);
                    CHECK(itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should not return 0 when at the last point in a string with a length greater than 0", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t, 2>();
                    itr_p itr(string, position_e::last_tg());
                    CHECK(itr.Point() != 0);
                    CHECK(!itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should return 0 when at the terminus", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::terminus_tg());
                    CHECK(itr.Point() == 0);
                }

                TEST_CASE_TEMPLATE("should return 0 when at the postfix", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, position_e::postfix_tg());
                    CHECK(itr.Point() == 0);
                }
            }

            TEST_SUITE("Point_Unit_Count()")
            {
                TEST_CASE_TEMPLATE("should return the number of units which represent the point", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t>();
                    itr_p itr(string, Random<index_t>(0, string.Point_Count()));
                    charcoder_t charcoder;
                    charcoder.Encode(itr.Point());
                    CHECK(itr.Point_Unit_Count() == charcoder.Unit_Count());
                }
            }

            TEST_SUITE("Point_Unit()")
            {
                TEST_CASE_TEMPLATE("should return the indexed unit of the point", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    string_t string = Random<string_t, 1>();
                    itr_p itr(string, Random<index_t>(0, string.Point_Count() - 1));
                    charcoder_t charcoder;
                    charcoder.Encode(itr.Point());
                    for (index_t idx = 0, end = itr.Point_Unit_Count(); idx < end; idx += 1) {
                        CHECK(itr.Point_Unit(idx) == charcoder.Unit(idx));
                    }
                }
            }

            TEST_SUITE("Substring_Unit_Count()")
            {
                TEST_CASE_TEMPLATE("should return the number of units in the substring, as opposed to in the point", itr_p, nkr_ALL)
                {

                }
            }

            TEST_SUITE("Substring_Unit()")
            {
                TEST_CASE_TEMPLATE("should return the indexed unit in the substring, as opposed to in the point", itr_p, nkr_ALL)
                {

                }
            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("+=()")
            {
                TEST_CASE_TEMPLATE("should move the iterator to the index that is point_count points after the current index", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;
                }

                TEST_CASE_TEMPLATE("should move unto the postfix when at the terminus", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;
                }
            }

            TEST_SUITE("-=()")
            {
                TEST_CASE_TEMPLATE("should move the iterator to the index that is point_count points before the current index", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;
                }

                TEST_CASE_TEMPLATE("should move unto the prefix when at the first point", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;
                }
            }

            TEST_SUITE("++()")
            {
                TEST_CASE_TEMPLATE("should move the iterator one index after the current index", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;
                }

                TEST_CASE_TEMPLATE("should move unto the postfix when at the terminus", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;
                }

                TEST_CASE_TEMPLATE("should return itself", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;
                }
            }

            TEST_SUITE("++(int)")
            {
                TEST_CASE_TEMPLATE("should move the iterator one index after the current index", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;
                }

                TEST_CASE_TEMPLATE("should move unto the postfix when at the terminus", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;
                }

                TEST_CASE_TEMPLATE("should return a copy of the iterator as it was before the alteration", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;
                }
            }

            TEST_SUITE("--()")
            {
                TEST_CASE_TEMPLATE("should move the iterator one index before the current index", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;
                }

                TEST_CASE_TEMPLATE("should move unto the prefix when at the first point", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;
                }

                TEST_CASE_TEMPLATE("should return itself", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;
                }
            }

            TEST_SUITE("--(int)")
            {
                TEST_CASE_TEMPLATE("should move the iterator one index before the current index", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;
                }

                TEST_CASE_TEMPLATE("should move unto the prefix when at the first point", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;
                }

                TEST_CASE_TEMPLATE("should return a copy of the iterator as it was before the alteration", itr_p, nkr_NON_CONST)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;
                }
            }
        }
    }

}}
