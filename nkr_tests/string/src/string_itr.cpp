/*
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
    #define nkr_RANDOM_MAX_POINT_COUNT  \
        128

    #define nkr_RESOLVED(QUALIFIER_p, STRING_p, CHARCODER_p)                                                            \
        QUALIFIER_p string_itr<decltype(STRING_p<CHARCODER_p>::Random<nkr_RANDOM_MAX_POINT_COUNT>())>,                  \
        QUALIFIER_p string_itr<const decltype(STRING_p<CHARCODER_p>::Random<nkr_RANDOM_MAX_POINT_COUNT>())>,            \
        QUALIFIER_p string_itr<volatile decltype(STRING_p<CHARCODER_p>::Random<nkr_RANDOM_MAX_POINT_COUNT>())>,         \
        QUALIFIER_p string_itr<const volatile decltype(STRING_p<CHARCODER_p>::Random<nkr_RANDOM_MAX_POINT_COUNT>())>

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
            TEST_SUITE("prefix_ctor()")
            {
                TEST_CASE_TEMPLATE("should set the iterator to the prefix of a string", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    auto random = string_t::Random<nkr_RANDOM_MAX_POINT_COUNT>(false);
                    itr_p itr(&random, position_e::prefix_tg());
                    CHECK(itr.Is_Prefix());
                }
            }

            TEST_SUITE("first_ctor()")
            {
                TEST_CASE_TEMPLATE("should set the iterator to the first point of a string", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    auto random = string_t::Random<nkr_RANDOM_MAX_POINT_COUNT>(false);
                    itr_p itr(&random, position_e::first_tg());
                    CHECK(itr.Is_First());
                }
            }

            TEST_SUITE("last_ctor()")
            {
                TEST_CASE_TEMPLATE("should set the iterator to the last point of a string", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    auto random = string_t::Random<nkr_RANDOM_MAX_POINT_COUNT>(false);
                    itr_p itr(&random, position_e::last_tg());
                    CHECK(itr.Is_Last());
                }
            }

            TEST_SUITE("terminus_ctor()")
            {
                TEST_CASE_TEMPLATE("should set the iterator to the terminus of a string", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    auto random = string_t::Random<nkr_RANDOM_MAX_POINT_COUNT>(false);
                    itr_p itr(&random, position_e::terminus_tg());
                    CHECK(itr.Is_Terminus());
                }
            }

            TEST_SUITE("postfix_ctor()")
            {
                TEST_CASE_TEMPLATE("should set the iterator to the postfix of a string", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    auto random = string_t::Random<nkr_RANDOM_MAX_POINT_COUNT>(false);
                    itr_p itr(&random, position_e::postfix_tg());
                    CHECK(itr.Is_Postfix());
                }
            }
        }

        TEST_SUITE("methods")
        {
            TEST_SUITE("Unit_Index")
            {
                TEST_CASE_TEMPLATE("should not return an index if at the prefix", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    auto random = string_t::Random<nkr_RANDOM_MAX_POINT_COUNT>(false);
                    itr_p itr(&random, position_e::prefix_tg());
                    optional_t<index_t> unit_index = itr.Unit_Index();
                    CHECK(!unit_index);
                }

                TEST_CASE_TEMPLATE("should return the correct index for first", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    auto random = string_t::Random<nkr_RANDOM_MAX_POINT_COUNT>(false);
                    itr_p itr(&random, position_e::first_tg());
                    optional_t<index_t> unit_index = itr.Unit_Index();
                    CHECK(unit_index && unit_index.Value() == 0);
                }

                TEST_CASE_TEMPLATE("should return the correct index for last", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    auto random = string_t::Random<nkr_RANDOM_MAX_POINT_COUNT>(false);
                    itr_p itr(&random, position_e::last_tg());
                    optional_t<index_t> unit_index = itr.Unit_Index();
                    if (random.Unit_Length() > 0) {
                        CHECK(unit_index && unit_index.Value() == random.Unit_Length() - itr.Point_Unit_Count());
                    } else {
                        CHECK(!unit_index);
                    }
                }

                TEST_CASE_TEMPLATE("should return the correct index for terminus", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    auto random = string_t::Random<nkr_RANDOM_MAX_POINT_COUNT>(false);
                    itr_p itr(&random, position_e::terminus_tg());
                    optional_t<index_t> unit_index = itr.Unit_Index();
                    CHECK(unit_index && unit_index.Value() == random.Unit_Count() - 1);
                }

                TEST_CASE_TEMPLATE("should return the correct index for postfix", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    auto random = string_t::Random<nkr_RANDOM_MAX_POINT_COUNT>(false);
                    itr_p itr(&random, position_e::postfix_tg());
                    optional_t<index_t> unit_index = itr.Unit_Index();
                    CHECK(unit_index && unit_index.Value() == random.Unit_Count());
                }
            }

            TEST_SUITE("Point_Index")
            {

            }
        }

        /*TEST_CASE("temp")
        {
            dynamic_t<charcoder::utf_8_t> string(u8"neal.νηαλ.נהאל.ነሐአለ.𐌍𐌄𐌀𐌋");

            auto Print_Point = [](auto& itr)
            {
                printf("%8zX ( ", itr.Point());
                for (index_t idx = 0, end = itr.Point_Unit_Count(); idx < end; idx += 1) {
                    printf("%2X ", itr.Point_Unit(idx));
                }
                printf(")\n");
            };

            for (auto itr = string.First(); !itr.Is_Postfix(); itr.Next()) {
                Print_Point(itr);
            }
            for (auto itr = string.Terminus(); !itr.Is_Prefix(); itr.Prior()) {
                Print_Point(itr);
            }
            for (auto itr = string.Last(); !itr.Is_Prefix(); itr.Prior()) {
                Print_Point(itr);
            }
            for (auto itr = string.First(); !itr.Is_Last(); itr.Next()) {
                Print_Point(itr);
            }

            CHECK(string.At(4).Point() == '.');
            CHECK(string.At(9).Point() == '.');
            CHECK(string.At(14).Point() == '.');
            CHECK(string.At(19).Point() == '.');
        }*/
    }
}}
