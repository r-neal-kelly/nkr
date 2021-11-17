/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "nkr/charcoder/ascii_t.h"
#include "nkr/charcoder/utf_8_t.h"
#include "nkr/charcoder/utf_16_t.h"
#include "nkr/charcoder/utf_32_t.h"

#include "nkr/string_itr.h"
#include "nkr/string/stack_t.h"
#include "nkr/string/static_t.h"

#include "doctest.h"

namespace nkr { namespace string {

    TEST_SUITE("string_itr<static_t>")
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
        nkr_CHARCODERS(QUALIFIER_p, static_t)

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

                    static_assert(any_string_tr<string_t>);
                }
            }

            TEST_SUITE("charcoder_t")
            {
                TEST_CASE_TEMPLATE("should have the same charcoder_t as its string_t", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;

                    static_assert(is_tr<charcoder_t, typename string_t::charcoder_t>);
                }
            }

            TEST_SUITE("unit_t")
            {
                TEST_CASE_TEMPLATE("should have the same unit_t as its string_t", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using unit_t = itr_p::unit_t;

                    static_assert(is_tr<unit_t, string_t::unit_t>);
                }
            }

            TEST_SUITE("substring_t")
            {
                TEST_CASE_TEMPLATE("should have a substring_t that is a string::stack_t", itr_p, nkr_ALL)
                {
                    using substring_t = itr_p::substring_t;

                    static_assert(string::any_stack_tr<substring_t>);
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
                    using charcoder_t = itr_p::charcoder_t;

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
            //TEST_SUITE("string_ctor()")
            //{
            //    TEST_CASE_TEMPLATE("should set the iterator to the first point of a string", itr_p, nkr_ALL)
            //    {
            //        using string_t = itr_p::string_t;
            //        using charcoder_t = itr_p::charcoder_t;

            //        auto stack_string = Random<stack_t<charcoder_t>>();
            //        //string_t string = stack_string;
            //        string_t string(maybe_t(stack_string.C_String()), stack_string.Unit_Count(), stack_string.Point_Count());
            //        static_assert(is_tr<string_t, decltype(string)>);
            //        itr_p itr(string);
            //        CHECK(itr.Is_At_First());
            //    }
            //}
        }
    }

}}
