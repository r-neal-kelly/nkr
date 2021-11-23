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
#include "nkr/string/static_t.h"

#include "doctest.h"

namespace nkr { namespace string {

    TEST_SUITE("string_itr<string_p>")
    {
    #define nkr_RESOLVED(QUALIFIER_p, STRING_p, CHARCODER_p)            \
        QUALIFIER_p string_itr<STRING_p<CHARCODER_p>>/*,                  \
        QUALIFIER_p string_itr<const STRING_p<CHARCODER_p>>,            \
        QUALIFIER_p string_itr<volatile STRING_p<CHARCODER_p>>,         \
        QUALIFIER_p string_itr<const volatile STRING_p<CHARCODER_p>>*/

    #define nkr_CHARCODERS(QUALIFIER_p, STRING_p)                       \
        nkr_RESOLVED(QUALIFIER_p, STRING_p, charcoder::ascii_t),        \
        nkr_RESOLVED(QUALIFIER_p, STRING_p, charcoder::utf_8_t),        \
        nkr_RESOLVED(QUALIFIER_p, STRING_p, charcoder::utf_16_be_t),    \
        nkr_RESOLVED(QUALIFIER_p, STRING_p, charcoder::utf_16_le_t),    \
        nkr_RESOLVED(QUALIFIER_p, STRING_p, charcoder::utf_32_be_t),    \
        nkr_RESOLVED(QUALIFIER_p, STRING_p, charcoder::utf_32_le_t)

    #define nkr_STRINGS(QUALIFIER_p)            \
        nkr_CHARCODERS(QUALIFIER_p, dynamic_t), \
        nkr_CHARCODERS(QUALIFIER_p, stack_t),   \
        nkr_CHARCODERS(QUALIFIER_p, static_t)

    #define nkr_TERMINATED_STRINGS(QUALIFIER_p) \
        nkr_CHARCODERS(QUALIFIER_p, dynamic_t), \
        nkr_CHARCODERS(QUALIFIER_p, stack_t),   \
        nkr_CHARCODERS(QUALIFIER_p, static_t)

    #define nkr_NON_TERMINATED_STRINGS(QUALIFIER_p) \
        nkr_CHARCODERS(QUALIFIER_p, static_t)

    #define nkr_REGULAR         \
        nkr_STRINGS(nkr_BLANK)

    #define nkr_REGULAR_TERMINATED          \
        nkr_TERMINATED_STRINGS(nkr_BLANK)

    #define nkr_REGULAR_NON_TERMINATED          \
        nkr_NON_TERMINATED_STRINGS(nkr_BLANK)

    #define nkr_NON_CONST       \
        nkr_STRINGS(nkr_BLANK), \
        nkr_STRINGS(volatile)

    #define nkr_NON_CONST_TERMINATED        \
        nkr_TERMINATED_STRINGS(nkr_BLANK),  \
        nkr_TERMINATED_STRINGS(volatile)

    #define nkr_NON_CONST_NON_TERMINATED        \
        nkr_NON_TERMINATED_STRINGS(nkr_BLANK),  \
        nkr_NON_TERMINATED_STRINGS(volatile)

    #define nkr_CONST               \
        nkr_STRINGS(const),         \
        nkr_STRINGS(const volatile)

    #define nkr_CONST_TERMINATED                \
        nkr_TERMINATED_STRINGS(const),          \
        nkr_TERMINATED_STRINGS(const volatile)

    #define nkr_CONST_NON_TERMINATED                \
        nkr_NON_TERMINATED_STRINGS(const),          \
        nkr_NON_TERMINATED_STRINGS(const volatile)

    #define nkr_ALL     \
        nkr_NON_CONST,  \
        nkr_CONST

    #define nkr_ALL_TERMINATED      \
        nkr_NON_CONST_TERMINATED,   \
        nkr_CONST_TERMINATED

    #define nkr_ALL_NON_TERMINATED      \
        nkr_NON_CONST_NON_TERMINATED,   \
        nkr_CONST_NON_TERMINATED

    #define nkr_RANDOM_STRING_t(...)                                                        \
        same_qualification_as_t<decltype(Random_String<string_t, __VA_ARGS__>()), string_t>

    #define nkr_EMPTY_STRING_t()                                                \
        same_qualification_as_t<decltype(Empty_String<string_t>()), string_t>

    #define nkr_REPLACEMENT_STRING_t()                                              \
        same_qualification_as_t<decltype(Replacement_String<string_t>()), string_t>

    #define nkr_ERROR_STRING_t()                                                \
        same_qualification_as_t<decltype(Error_String<string_t>()), string_t>

    #define nkr_STRING_itr(STRING_p)                                    \
        same_qualification_as_t<string_itr<decltype(STRING_p)>, itr_p>

        template <string_i string_p, count_t min_point_count_p = 1, count_t max_point_count_p = 128>
        auto Random_String(bool_t use_erroneous_units = false)
        {
            return Random<string_p, min_point_count_p, max_point_count_p>(use_erroneous_units);
        }

        template <string_i string_p, count_t min_point_count_p = 1, count_t max_point_count_p = 128>
        auto Non_Terminated_Random_String(bool_t use_erroneous_units = false)
        {
            static_assert(!string_p::Has_Guaranteed_Terminus());

            return Random<string_p, min_point_count_p, max_point_count_p>(use_erroneous_units, false);
        }

        template <string_i string_p>
        auto Empty_String()
        {
            using qualified_charcoder_t = string_p::qualified_charcoder_t;

            if constexpr (tr1<string_p, any_tg, static_tg>) {
                string::stack_t<qualified_charcoder_t, 1> string;
                return local_static_t<qualified_charcoder_t>(string);
            } else {
                return std::remove_cv_t<string_p>();
            }
        }

        template <string_i string_p>
        auto Non_Terminated_Empty_String()
        {
            using qualified_charcoder_t = string_p::qualified_charcoder_t;

            static_assert(!string_p::Has_Guaranteed_Terminus());

            if constexpr (tr1<string_p, any_tg, static_tg>) {
                return local_static_t<qualified_charcoder_t>(Empty_String<stack_t<qualified_charcoder_t>>(), false);
            } else {
                return std::remove_cv_t<string_p>(Empty_String<stack_t<qualified_charcoder_t>>(), false);
            }
        }

        template <string_i string_p>
        auto Replacement_String()
        {
            using charcoder_t = string_p::charcoder_t;
            using qualified_charcoder_t = string_p::qualified_charcoder_t;

            charcoder_t charcoder;
            charcoder.Encode(charcoder_t::Replacement_Point());

            if constexpr (tr1<string_p, any_tg, static_tg>) {
                string::stack_t<qualified_charcoder_t, charcoder_t::Max_Unit_Count() + 1> string(charcoder);
                return local_static_t<qualified_charcoder_t>(string);
            } else {
                return std::remove_cv_t<string_p>(charcoder);
            }
        }

        template <string_i string_p>
        auto Non_Terminated_Replacement_String()
        {
            using qualified_charcoder_t = string_p::qualified_charcoder_t;

            static_assert(!string_p::Has_Guaranteed_Terminus());

            if constexpr (tr1<string_p, any_tg, static_tg>) {
                return local_static_t<qualified_charcoder_t>(Replacement_String<stack_t<qualified_charcoder_t>>(), false);
            } else {
                return std::remove_cv_t<string_p>(Replacement_String<stack_t<qualified_charcoder_t>>(), false);
            }
        }

        template <string_i string_p>
        auto Error_String()
        {
            using charcoder_t = string_p::charcoder_t;
            using unit_t = string_p::unit_t;

            array::stack_t<unit_t, 2> units;
            if constexpr (is_tr<charcoder_t, charcoder::ascii_t>) {
                units = {
                    Random<unit_t>(std::numeric_limits<unit_t>::lowest(), -1),
                    unit_t(0),
                };
            } else if constexpr (is_tr<charcoder_t, charcoder::utf_8_t>) {
                units = {
                    Random<unit_t>(unit_t(charcoder::utf_32_t::UTF_8_BRACKET_1_LAST + 1)),
                    unit_t(0),
                };
            } else if constexpr (is_tr<charcoder_t, charcoder::utf_16_be_t> && os::endian::Is_Big() ||
                                 is_tr<charcoder_t, charcoder::utf_16_le_t> && os::endian::Is_Little()) {
                units = {
                    Random<unit_t>(charcoder::utf_32_t::SURROGATE_HIGH_FIRST, charcoder::utf_32_t::SURROGATE_LOW_LAST),
                    unit_t(0),
                };
            } else if constexpr (is_tr<charcoder_t, charcoder::utf_16_be_t> && os::endian::Is_Little() ||
                                 is_tr<charcoder_t, charcoder::utf_16_le_t> && os::endian::Is_Big()) {
                units = {
                    os::endian::Swap(Random<unit_t>(charcoder::utf_32_t::SURROGATE_HIGH_FIRST, charcoder::utf_32_t::SURROGATE_LOW_LAST)),
                    unit_t(0),
                };
            } else if constexpr (is_tr<charcoder_t, charcoder::utf_32_be_t> && os::endian::Is_Big() ||
                                 is_tr<charcoder_t, charcoder::utf_32_le_t> && os::endian::Is_Little()) {
                units = {
                    Random<unit_t>(charcoder::utf_32_t::POINT_LAST + 1),
                    unit_t(0),
                };
            } else if constexpr (is_tr<charcoder_t, charcoder::utf_32_be_t> && os::endian::Is_Little() ||
                                 is_tr<charcoder_t, charcoder::utf_32_le_t> && os::endian::Is_Big()) {
                units = {
                    os::endian::Swap(Random<unit_t>(charcoder::utf_32_t::POINT_LAST + 1)),
                    unit_t(0),
                };
            } else {
                static_assert(false);
            }

            if constexpr (tr1<string_p, any_tg, static_tg>) {
                return local_static_t<typename string_p::qualified_charcoder_t>(units.Array());
            } else {
                return std::remove_cv_t<string_p>(units.Array());
            }
        }

        template <string_i string_p>
        auto Non_Terminated_Error_String()
        {
            using qualified_charcoder_t = string_p::qualified_charcoder_t;

            static_assert(!string_p::Has_Guaranteed_Terminus());

            if constexpr (tr1<string_p, any_tg, static_tg>) {
                return local_static_t<qualified_charcoder_t>(Error_String<stack_t<qualified_charcoder_t>>(), false);
            } else {
                return std::remove_cv_t<string_p>(Error_String<stack_t<qualified_charcoder_t>>(), false);
            }
        }

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
            TEST_SUITE("string_ctor()")
            {
                TEST_CASE_TEMPLATE("should set the iterator to the first point of a string", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string);
                    CHECK(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should set the iterator to the first point of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string);
                    CHECK(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should set the iterator to the pretend terminus of a non-terminated empty string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_EMPTY_STRING_t() string = Non_Terminated_Empty_String<string_t>();
                    nkr_STRING_itr(string) itr(string);
                    CHECK(itr.Is_At_First());
                    CHECK(itr.Is_At_Terminus());
                }
            }

            TEST_SUITE("at_ctor()")
            {
                TEST_CASE_TEMPLATE("should set the iterator to the indexed point of a string", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    nkr_STRING_itr(string) itr(string, point_index);
                    optional_t<index_t> itr_point_index = itr.Point_Index();
                    CHECK(itr_point_index && itr_point_index.Value() == point_index);
                }

                TEST_CASE_TEMPLATE("should set the iterator to the indexed point of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    nkr_STRING_itr(string) itr(string, point_index);
                    optional_t<index_t> itr_point_index = itr.Point_Index();
                    CHECK(itr_point_index && itr_point_index.Value() == point_index);
                }

                TEST_CASE_TEMPLATE("should be able to set the iterator to the terminus of a string", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, string.Point_Count() - 1);
                    CHECK(itr.Is_At_Terminus());
                }

                TEST_CASE_TEMPLATE("should be able to set the iterator to the pretend terminus of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, string.Point_Count());
                    CHECK(itr.Is_At_Terminus());
                }

                TEST_CASE_TEMPLATE("should be able to set the iterator to the postfix of a string", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, string.Point_Count());
                    CHECK(itr.Is_At_Postfix());
                }

                TEST_CASE_TEMPLATE("should be able to set the iterator to the postfix of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, string.Point_Count() + 1);
                    CHECK(itr.Is_At_Postfix());
                }
            }

            TEST_SUITE("at_prefix_ctor()")
            {
                TEST_CASE_TEMPLATE("should set the iterator to the prefix of a string", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK(itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should set the iterator to the prefix of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK(itr.Is_At_Prefix());
                }
            }

            TEST_SUITE("at_first_ctor()")
            {
                TEST_CASE_TEMPLATE("should set the iterator to the first point of a string", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    CHECK(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should set the iterator to the first point of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    CHECK(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should set the iterator to the pretend terminus of a non-terminated empty string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_EMPTY_STRING_t() string = Non_Terminated_Empty_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    CHECK(itr.Is_At_First());
                    CHECK(itr.Is_At_Terminus());
                }
            }

            TEST_SUITE("at_last_ctor()")
            {
                TEST_CASE_TEMPLATE("should set the iterator to the last point of a string", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    CHECK(itr.Is_At_Last());
                }

                TEST_CASE_TEMPLATE("should set the iterator to the last point of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    CHECK(itr.Is_At_Last());
                }

                TEST_CASE_TEMPLATE("should set the iterator to the prefix of an empty string", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_EMPTY_STRING_t() string = Empty_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    CHECK(itr.Is_At_Last());
                    CHECK(itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should set the iterator to the prefix of a non-terminated empty string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_EMPTY_STRING_t() string = Non_Terminated_Empty_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    CHECK(itr.Is_At_Last());
                    CHECK(itr.Is_At_Prefix());
                }
            }

            TEST_SUITE("at_terminus_ctor()")
            {
                TEST_CASE_TEMPLATE("should set the iterator to the terminus of a string", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK(itr.Is_At_Terminus());
                }

                TEST_CASE_TEMPLATE("should set the iterator to the pretend terminus of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK(itr.Is_At_Terminus());
                }

                TEST_CASE_TEMPLATE("should set the iterator to the first point of an empty string", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_EMPTY_STRING_t() string = Empty_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK(itr.Is_At_Terminus());
                    CHECK(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should set the iterator to the first point of a non-terminated empty string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_EMPTY_STRING_t() string = Non_Terminated_Empty_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK(itr.Is_At_Terminus());
                    CHECK(itr.Is_At_First());
                }
            }

            TEST_SUITE("at_postfix_ctor()")
            {
                TEST_CASE_TEMPLATE("should set the iterator to the postfix of a string", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK(itr.Is_At_Postfix());
                }

                TEST_CASE_TEMPLATE("should set the iterator to the postfix of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK(itr.Is_At_Postfix());
                }

                TEST_CASE_TEMPLATE("should not set the iterator to the terminus of a string", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK(!itr.Is_At_Terminus());
                }

                TEST_CASE_TEMPLATE("should not set the iterator to the terminus of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK(!itr.Is_At_Terminus());
                }
            }

            TEST_SUITE("copy_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy the other without changing it", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    const std::remove_cv_t<nkr_STRING_itr(string)> other(string, point_index);
                    nkr_STRING_itr(string) itr(other);
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

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    const volatile std::remove_cv_t<nkr_STRING_itr(string)> other(string, point_index);
                    nkr_STRING_itr(string) itr(other);
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

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    std::remove_cv_t<nkr_STRING_itr(string)> other(string, point_index);
                    nkr_STRING_itr(string) itr(nkr::Move(other));
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

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    volatile std::remove_cv_t<nkr_STRING_itr(string)> other(string, point_index);
                    nkr_STRING_itr(string) itr(nkr::Move(other));
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

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    const std::remove_cv_t<nkr_STRING_itr(string)> other(string, point_index);
                    nkr_STRING_itr(string) itr(string);
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

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    const volatile std::remove_cv_t<nkr_STRING_itr(string)> other(string, point_index);
                    nkr_STRING_itr(string) itr(string);
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

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    std::remove_cv_t<nkr_STRING_itr(string)> other(string, point_index);
                    nkr_STRING_itr(string) itr(string);
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

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    volatile std::remove_cv_t<nkr_STRING_itr(string)> other(string, point_index);
                    nkr_STRING_itr(string) itr(string);
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

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string);
                    itr.~nkr_STRING_itr(string)();
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

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string);
                    CHECK(&itr.String() == &string);
                }
            }

            TEST_SUITE("Is_At()")
            {
                TEST_CASE_TEMPLATE("should return true when at the point index", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    const index_t point_index = Random<index_t>(0, string.Point_Count());
                    nkr_STRING_itr(string) itr(string, point_index);
                    CHECK_TRUE(itr.Is_At(point_index));
                }

                TEST_CASE_TEMPLATE("should return true when at the point index of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    const index_t point_index = Random<index_t>(0, string.Point_Count() + 1);
                    nkr_STRING_itr(string) itr(string, point_index);
                    CHECK_TRUE(itr.Is_At(point_index));
                }

                TEST_CASE_TEMPLATE("should return false when at the prefix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK_FALSE(itr.Is_At(Random<index_t>(0, string.Point_Count())));
                }

                TEST_CASE_TEMPLATE("should return false when at the prefix of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK_FALSE(itr.Is_At(Random<index_t>(0, string.Point_Count() + 1)));
                }

                TEST_CASE_TEMPLATE("should return false when moved to the prefix", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count()));
                    itr.At_Prefix();
                    CHECK_FALSE(itr.Is_At(Random<index_t>(0, string.Point_Count())));
                }

                TEST_CASE_TEMPLATE("should return false when moved to the prefix of a non-terminated string", itr_p, nkr_NON_CONST_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count() + 1));
                    itr.At_Prefix();
                    CHECK_FALSE(itr.Is_At(Random<index_t>(0, string.Point_Count() + 1)));
                }

                TEST_CASE_TEMPLATE("should return true when at the terminus and given the terminus index", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK_TRUE(itr.Is_At(string.Point_Count() - 1));
                }

                TEST_CASE_TEMPLATE("should return true when at the pretend terminus and given the pretend terminus index of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK_TRUE(itr.Is_At(string.Point_Count()));
                }

                TEST_CASE_TEMPLATE("should return true when at the postfix and given the postfix index", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK_TRUE(itr.Is_At(string.Point_Count()));
                }

                TEST_CASE_TEMPLATE("should return true when at the postfix and given the postfix index of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK_TRUE(itr.Is_At(string.Point_Count() + 1));
                }

                TEST_CASE_TEMPLATE("should return false when at another point index", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    const count_t point_count = string.Point_Count();
                    const index_t point_index = Random<index_t>(0, point_count);
                    index_t other_point_index;
                    do {
                        other_point_index = Random<index_t>(0, point_count);
                    } while (other_point_index == point_index);
                    nkr_STRING_itr(string) itr(string, other_point_index);
                    CHECK_FALSE(itr.Is_At(point_index));
                }

                TEST_CASE_TEMPLATE("should return false when at another point index of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    const count_t point_count = string.Point_Count();
                    const index_t point_index = Random<index_t>(0, point_count + 1);
                    index_t other_point_index;
                    do {
                        other_point_index = Random<index_t>(0, point_count + 1);
                    } while (other_point_index == point_index);
                    nkr_STRING_itr(string) itr(string, other_point_index);
                    CHECK_FALSE(itr.Is_At(point_index));
                }
            }

            TEST_SUITE("Is_At_Prefix()")
            {
                TEST_CASE_TEMPLATE("should return true when at the prefix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK_TRUE(itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should return true when at the prefix of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK_TRUE(itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should return false when at the first point", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    CHECK_FALSE(itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should return false when at the first point of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    CHECK_FALSE(itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should return false when at the last point of a non-empty string", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(2) string = Random_String<string_t, 2>();
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    CHECK_FALSE(itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should return false when at the last point of a non-terminated non-empty string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(2) string = Non_Terminated_Random_String<string_t, 2>();
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    CHECK_FALSE(itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should return true when at the last point of an empty string", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_EMPTY_STRING_t() string = Empty_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    CHECK_TRUE(itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should return true when at the last point of a non-terminated empty string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_EMPTY_STRING_t() string = Non_Terminated_Empty_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    CHECK_TRUE(itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should return false when at the terminus", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK_FALSE(itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should return false when at the pretend terminus of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK_FALSE(itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should return false when at the postfix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK_FALSE(itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should return false when at the postfix of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK_FALSE(itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should return false when at another point", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count()));
                    CHECK_FALSE(itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should return false when at another point of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count() + 1));
                    CHECK_FALSE(itr.Is_At_Prefix());
                }
            }

            TEST_SUITE("Is_At_First()")
            {
                TEST_CASE_TEMPLATE("should return false when at the prefix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK_FALSE(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should return false when at the prefix of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK_FALSE(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should return true when at the first point", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    CHECK_TRUE(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should return true when at the first point of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    CHECK_TRUE(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should return true when at the last point of a string with a length of 1", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_REPLACEMENT_STRING_t() string = Replacement_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    CHECK_TRUE(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should return true when at the last point of a non-terminated string with a length of 1", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_REPLACEMENT_STRING_t() string = Non_Terminated_Replacement_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    CHECK_TRUE(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should return false when at the last point of a string without a length of 1", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string;
                    do {
                        string = Random_String<string_t>();
                    } while (string.Point_Length() == 1);
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    CHECK_FALSE(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should return false when at the last point of a non-terminated string without a length of 1", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string;
                    do {
                        string = Non_Terminated_Random_String<string_t>();
                    } while (string.Point_Length() == 1);
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    CHECK_FALSE(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should return false when at the terminus of a non-empty string", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(2) string = Random_String<string_t, 2>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK_FALSE(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should return false when at the pretend terminus of a non-terminated non-empty string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(2) string = Non_Terminated_Random_String<string_t, 2>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK_FALSE(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should return true when at the terminus of an empty string", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_EMPTY_STRING_t() string = Empty_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK_TRUE(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should return true when at the pretend terminus of a non-terminated empty string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_EMPTY_STRING_t() string = Non_Terminated_Empty_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK_TRUE(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should return false when at the postfix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK_FALSE(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should return false when at the postfix of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK_FALSE(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should return false when at another point", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(1, string.Point_Count()));
                    CHECK_FALSE(itr.Is_At_First());
                }

                TEST_CASE_TEMPLATE("should return false when at another point of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(1, string.Point_Count() + 1));
                    CHECK_FALSE(itr.Is_At_First());
                }
            }

            TEST_SUITE("Is_At_Last()")
            {
                TEST_CASE_TEMPLATE("should return false when at the prefix of a non-empty string", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(2) string = Random_String<string_t, 2>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK_FALSE(itr.Is_At_Last());
                }

                TEST_CASE_TEMPLATE("should return false when at the prefix of a non-terminated non-empty string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(2) string = Non_Terminated_Random_String<string_t, 2>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK_FALSE(itr.Is_At_Last());
                }

                TEST_CASE_TEMPLATE("should return true when at the prefix of an empty string", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_EMPTY_STRING_t() string = Empty_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK_TRUE(itr.Is_At_Last());
                }

                TEST_CASE_TEMPLATE("should return true when at the prefix of a non-terminated empty string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_EMPTY_STRING_t() string = Non_Terminated_Empty_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK_TRUE(itr.Is_At_Last());
                }

                TEST_CASE_TEMPLATE("should return true when at the first point of a string with a length of 1", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_REPLACEMENT_STRING_t() string = Replacement_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    CHECK_TRUE(itr.Is_At_Last());
                }

                TEST_CASE_TEMPLATE("should return true when at the first point of a non-terminated string with a length of 1", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_REPLACEMENT_STRING_t() string = Non_Terminated_Replacement_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    CHECK_TRUE(itr.Is_At_Last());
                }

                TEST_CASE_TEMPLATE("should return false when at the first point of a string without a length of 1", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string;
                    do {
                        string = Random_String<string_t>();
                    } while (string.Point_Length() == 1);
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    CHECK_FALSE(itr.Is_At_Last());
                }

                TEST_CASE_TEMPLATE("should return false when at the first point of a non-terminated string without a length of 1", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string;
                    do {
                        string = Non_Terminated_Random_String<string_t>();
                    } while (string.Point_Length() == 1);
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    CHECK_FALSE(itr.Is_At_Last());
                }

                TEST_CASE_TEMPLATE("should return true when at the last point", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    CHECK_TRUE(itr.Is_At_Last());
                }

                TEST_CASE_TEMPLATE("should return true when at the last point of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    CHECK_TRUE(itr.Is_At_Last());
                }

                TEST_CASE_TEMPLATE("should return false when at the terminus", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK_FALSE(itr.Is_At_Last());
                }

                TEST_CASE_TEMPLATE("should return false when at the pretend terminus of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK_FALSE(itr.Is_At_Last());
                }

                TEST_CASE_TEMPLATE("should return false when at the postfix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK_FALSE(itr.Is_At_Last());
                }

                TEST_CASE_TEMPLATE("should return false when at the postfix of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK_FALSE(itr.Is_At_Last());
                }

                TEST_CASE_TEMPLATE("should return false when at another point", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(2) string = Random_String<string_t, 2>();
                    const count_t point_count = string.Point_Count();
                    const index_t last_point_index = point_count - 2;
                    index_t random_point_index;
                    do {
                        random_point_index = Random<index_t>(0, point_count);
                    } while (random_point_index == last_point_index);
                    nkr_STRING_itr(string) itr(string, random_point_index);
                    CHECK_FALSE(itr.Is_At_Last());
                }

                TEST_CASE_TEMPLATE("should return false when at another point of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(2) string = Non_Terminated_Random_String<string_t, 2>();
                    const count_t point_count = string.Point_Count();
                    const index_t last_point_index = point_count + 1 - 2;
                    index_t random_point_index;
                    do {
                        random_point_index = Random<index_t>(0, point_count + 1);
                    } while (random_point_index == last_point_index);
                    nkr_STRING_itr(string) itr(string, random_point_index);
                    CHECK_FALSE(itr.Is_At_Last());
                }
            }

            TEST_SUITE("Is_At_Terminus()")
            {
                TEST_CASE_TEMPLATE("should return false when at the prefix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK_FALSE(itr.Is_At_Terminus());
                }

                TEST_CASE_TEMPLATE("should return false when at the prefix of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK_FALSE(itr.Is_At_Terminus());
                }

                TEST_CASE_TEMPLATE("should return false when at the first point of a non-empty string", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(2) string = Random_String<string_t, 2>();
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    CHECK_FALSE(itr.Is_At_Terminus());
                }

                TEST_CASE_TEMPLATE("should return false when at the first point of a non-terminated non-empty string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(2) string = Non_Terminated_Random_String<string_t, 2>();
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    CHECK_FALSE(itr.Is_At_Terminus());
                }

                TEST_CASE_TEMPLATE("should return true when at the first point of an empty string", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_EMPTY_STRING_t() string = Empty_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    CHECK_TRUE(itr.Is_At_Terminus());
                }

                TEST_CASE_TEMPLATE("should return true when at the first point of a non-terminated empty string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_EMPTY_STRING_t() string = Non_Terminated_Empty_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    CHECK_TRUE(itr.Is_At_Terminus());
                }

                TEST_CASE_TEMPLATE("should return false when at the last point", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    CHECK_FALSE(itr.Is_At_Terminus());
                }

                TEST_CASE_TEMPLATE("should return false when at the last point of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    CHECK_FALSE(itr.Is_At_Terminus());
                }

                TEST_CASE_TEMPLATE("should return true when at the terminus", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK_TRUE(itr.Is_At_Terminus());
                }

                TEST_CASE_TEMPLATE("should return true when at the pretend terminus of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK_TRUE(itr.Is_At_Terminus());
                }

                TEST_CASE_TEMPLATE("should return false when at the postfix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK_FALSE(itr.Is_At_Terminus());
                }

                TEST_CASE_TEMPLATE("should return false when at the postfix of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK_FALSE(itr.Is_At_Terminus());
                }

                TEST_CASE_TEMPLATE("should return false when at another point", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    const count_t point_count = string.Point_Count();
                    const index_t terminus_point_index = point_count - 1;
                    index_t random_point_index;
                    do {
                        random_point_index = Random<index_t>(0, point_count);
                    } while (random_point_index == terminus_point_index);
                    nkr_STRING_itr(string) itr(string, random_point_index);
                    CHECK_FALSE(itr.Is_At_Terminus());
                }

                TEST_CASE_TEMPLATE("should return false when at another point of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    const count_t point_count = string.Point_Count();
                    const index_t terminus_point_index = point_count + 1 - 1;
                    index_t random_point_index;
                    do {
                        random_point_index = Random<index_t>(0, point_count + 1);
                    } while (random_point_index == terminus_point_index);
                    nkr_STRING_itr(string) itr(string, random_point_index);
                    CHECK_FALSE(itr.Is_At_Terminus());
                }
            }

            TEST_SUITE("Is_At_Postfix()")
            {
                TEST_CASE_TEMPLATE("should return false when at the prefix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK_FALSE(itr.Is_At_Postfix());
                }

                TEST_CASE_TEMPLATE("should return false when at the prefix of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK_FALSE(itr.Is_At_Postfix());
                }

                TEST_CASE_TEMPLATE("should return false when at the first point", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    CHECK_FALSE(itr.Is_At_Postfix());
                }

                TEST_CASE_TEMPLATE("should return false when at the first point of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    CHECK_FALSE(itr.Is_At_Postfix());
                }

                TEST_CASE_TEMPLATE("should return false when at the last point", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    CHECK_FALSE(itr.Is_At_Postfix());
                }

                TEST_CASE_TEMPLATE("should return false when at the last point of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    CHECK_FALSE(itr.Is_At_Postfix());
                }

                TEST_CASE_TEMPLATE("should return false when at the terminus", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK_FALSE(itr.Is_At_Postfix());
                }

                TEST_CASE_TEMPLATE("should return false when at the pretend terminus of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK_FALSE(itr.Is_At_Postfix());
                }

                TEST_CASE_TEMPLATE("should return true when at the postfix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK_TRUE(itr.Is_At_Postfix());
                }

                TEST_CASE_TEMPLATE("should return true when at the postfix of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK_TRUE(itr.Is_At_Postfix());
                }

                TEST_CASE_TEMPLATE("should return false when at another point", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count() - 1));
                    CHECK_FALSE(itr.Is_At_Postfix());
                }

                TEST_CASE_TEMPLATE("should return false when at another point of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count()));
                    CHECK_FALSE(itr.Is_At_Postfix());
                }
            }

            TEST_SUITE("Is_At_Error()")
            {
                TEST_CASE_TEMPLATE("should return true when at an error", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_ERROR_STRING_t() string = Error_String<string_t>();
                    nkr_STRING_itr(string) itr(string);
                    CHECK_TRUE(itr.Is_At_Error());
                }

                TEST_CASE_TEMPLATE("should return true when at an error of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_ERROR_STRING_t() string = Non_Terminated_Error_String<string_t>();
                    nkr_STRING_itr(string) itr(string);
                    CHECK_TRUE(itr.Is_At_Error());
                }

                TEST_CASE_TEMPLATE("should return false when not at an error", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count() - 1));
                    CHECK_FALSE(itr.Is_At_Error());
                }

                TEST_CASE_TEMPLATE("should return false when not at an error of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count()));
                    CHECK_FALSE(itr.Is_At_Error());
                }

                TEST_CASE_TEMPLATE("should return false when at a replacement substring", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;

                    nkr_REPLACEMENT_STRING_t() string = Replacement_String<string_t>();
                    nkr_STRING_itr(string) itr(string);
                    CHECK(itr.Point() == charcoder_t::Replacement_Point());
                    CHECK_FALSE(itr.Is_At_Error());
                }

                TEST_CASE_TEMPLATE("should return false when at a replacement substring of non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;

                    nkr_REPLACEMENT_STRING_t() string = Non_Terminated_Replacement_String<string_t>();
                    nkr_STRING_itr(string) itr(string);
                    CHECK(itr.Point() == charcoder_t::Replacement_Point());
                    CHECK_FALSE(itr.Is_At_Error());
                }

                TEST_CASE_TEMPLATE("should return false when at the prefix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK_FALSE(itr.Is_At_Error());
                }

                TEST_CASE_TEMPLATE("should return false when at the prefix of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK_FALSE(itr.Is_At_Error());
                }

                TEST_CASE_TEMPLATE("should return false when at the terminus", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK_FALSE(itr.Is_At_Error());
                }

                TEST_CASE_TEMPLATE("should return false when at the pretend terminus of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK_FALSE(itr.Is_At_Error());
                }

                TEST_CASE_TEMPLATE("should return false when at the postfix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK_FALSE(itr.Is_At_Error());
                }

                TEST_CASE_TEMPLATE("should return false when at the postfix of a non-terminated string", itr_p, nkr_ALL_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK_FALSE(itr.Is_At_Error());
                }

                TEST_CASE_TEMPLATE("should decode to a replacement point when at an error", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;

                    nkr_RANDOM_STRING_t(64) string = Random_String<string_t, 64>(true);
                    nkr_STRING_itr(string) itr(string);
                    for (; !itr.Is_At_Postfix(); itr.Next()) {
                        if (itr.Is_At_Error()) {
                            CHECK(itr.Point() == charcoder_t::Replacement_Point());
                        }
                    }
                }

                TEST_CASE_TEMPLATE("should decode to a replacement point when at an error of a non-terminated string", itr_p, nkr_NON_CONST_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;

                    nkr_RANDOM_STRING_t(64) string = Non_Terminated_Random_String<string_t, 64>(true);
                    nkr_STRING_itr(string) itr(string);
                    for (; !itr.Is_At_Postfix(); itr.Next()) {
                        if (itr.Is_At_Error()) {
                            CHECK(itr.Point() == charcoder_t::Replacement_Point());
                        }
                    }
                }
            }

            TEST_SUITE("Is_At_Replacement_Point()")
            {
                TEST_CASE_TEMPLATE("should return true when at a replacement point", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_ERROR_STRING_t() string = Error_String<string_t>();
                    nkr_STRING_itr(string) itr(string);
                    CHECK_TRUE(itr.Is_At_Replacement_Point());
                }

                TEST_CASE_TEMPLATE("should return false when not at a replacement point", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count() - 1));
                    CHECK_FALSE(itr.Is_At_Replacement_Point());
                }

                TEST_CASE_TEMPLATE("should return true when at a replacement substring", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;

                    nkr_REPLACEMENT_STRING_t() string = Replacement_String<string_t>();
                    nkr_STRING_itr(string) itr(string);
                    CHECK(itr.Point() == charcoder_t::Replacement_Point());
                    CHECK_TRUE(itr.Is_At_Replacement_Point());
                }

                TEST_CASE_TEMPLATE("should return false when at the prefix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK_FALSE(itr.Is_At_Replacement_Point());
                }

                TEST_CASE_TEMPLATE("should return false when at the postfix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK_FALSE(itr.Is_At_Replacement_Point());
                }
            }

            TEST_SUITE("Is_At_Replacement_Substring()")
            {
                TEST_CASE_TEMPLATE("should return true when at a replacement substring", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;

                    nkr_REPLACEMENT_STRING_t() string = Replacement_String<string_t>();
                    nkr_STRING_itr(string) itr(string);
                    CHECK(itr.Point() == charcoder_t::Replacement_Point());
                    CHECK_TRUE(itr.Is_At_Replacement_Substring());
                }

                TEST_CASE_TEMPLATE("should return false when not at a replacement substring", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count() - 1));
                    CHECK_FALSE(itr.Is_At_Replacement_Substring());
                }

                TEST_CASE_TEMPLATE("should return false when at an error", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_ERROR_STRING_t() string = Error_String<string_t>();
                    nkr_STRING_itr(string) itr(string);
                    CHECK_FALSE(itr.Is_At_Replacement_Substring());
                }

                TEST_CASE_TEMPLATE("should return false when at the prefix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK_FALSE(itr.Is_At_Replacement_Substring());
                }

                TEST_CASE_TEMPLATE("should return false when at the postfix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK_FALSE(itr.Is_At_Replacement_Substring());
                }
            }

            TEST_SUITE("At()")
            {
                TEST_CASE_TEMPLATE("should move the iterator to the indexed point", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count()));
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    itr.At(point_index);
                    CHECK_TRUE(itr.Is_At(point_index));
                }

                // we should have a test that goes back and forth several times to make sure that the point index stays as it should.
            }

            TEST_SUITE("At_Prefix()")
            {
                TEST_CASE_TEMPLATE("should move the iterator to the prefix", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count()));
                    itr.At_Prefix();
                    CHECK_TRUE(itr.Is_At_Prefix());
                }
            }

            TEST_SUITE("At_First()")
            {
                TEST_CASE_TEMPLATE("should move the iterator to the first point", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count()));
                    itr.At_First();
                    CHECK_TRUE(itr.Is_At_First());
                }
            }

            TEST_SUITE("At_Last()")
            {
                TEST_CASE_TEMPLATE("should move the iterator to the last point", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count()));
                    itr.At_Last();
                    CHECK_TRUE(itr.Is_At_Last());
                }
            }

            TEST_SUITE("At_Terminus()")
            {
                TEST_CASE_TEMPLATE("should move the iterator to the terminus", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count()));
                    itr.At_Terminus();
                    CHECK_TRUE(itr.Is_At_Terminus());
                }
            }

            TEST_SUITE("At_Postfix()")
            {
                TEST_CASE_TEMPLATE("should move the iterator to the postfix", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count()));
                    itr.At_Postfix();
                    CHECK_TRUE(itr.Is_At_Postfix());
                }
            }

            TEST_SUITE("Next()")
            {
                TEST_CASE_TEMPLATE("should move to the next point when not at the postfix", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count() - 1);
                    nkr_STRING_itr(string) itr(string, point_index);
                    itr.Next();
                    CHECK(itr.Is_At(point_index + 1));
                }

                TEST_CASE_TEMPLATE("should return true when not at the postfix", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count() - 1));
                    CHECK_TRUE(itr.Next());
                }

                TEST_CASE_TEMPLATE("should return false when at the postfix", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK_FALSE(itr.Next());
                }

                TEST_CASE_TEMPLATE("should move through a string the same as manually using a charcoder", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string);
                    charcoder_t charcoder;
                    count_t unit_index = 0;
                    count_t point_index = 0;
                    do {
                        unit_index += charcoder.Read_Forward(&string.Unit(0) + unit_index);
                        point_index += 1;
                        CHECK(itr.Point() == charcoder.Decode());
                        itr.Next();
                        CHECK(itr.Unit_Index().Value() == unit_index);
                        CHECK(itr.Point_Index().Value() == point_index);
                    } while (charcoder != none_t());
                    CHECK(unit_index == string.Unit_Count());
                    CHECK(point_index == string.Point_Count());
                    CHECK(itr.Unit_Index().Value() == string.Unit_Count());
                    CHECK(itr.Point_Index().Value() == string.Point_Count());
                }

                TEST_CASE_TEMPLATE("should move through a non-terminated string the same as manually using a charcoder", itr_p, nkr_NON_CONST_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string);
                    charcoder_t charcoder;
                    count_t unit_index = 0;
                    count_t point_index = 0;
                    while (unit_index < string.Unit_Count()) {
                        unit_index += charcoder.Read_Forward(&string.Unit(0) + unit_index);
                        point_index += 1;
                        CHECK(itr.Point() == charcoder.Decode());
                        itr.Next();
                        CHECK(itr.Unit_Index().Value() == unit_index);
                        CHECK(itr.Point_Index().Value() == point_index);
                    }
                    CHECK(unit_index == string.Unit_Count());
                    CHECK(point_index == string.Point_Count());
                    CHECK(itr.Unit_Index().Value() == string.Unit_Count());
                    CHECK(itr.Point_Index().Value() == string.Point_Count());
                }

                TEST_CASE_TEMPLATE("should move through an error-ridden string the same as manually using a charcoder", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>(true);
                    nkr_STRING_itr(string) itr(string);
                    charcoder_t charcoder;
                    count_t unit_index = 0;
                    count_t point_index = 0;
                    do {
                        unit_index += charcoder.Read_Forward(&string.Unit(0) + unit_index);
                        point_index += 1;
                        CHECK(itr.Point() == charcoder.Decode());
                        itr.Next();
                        CHECK(itr.Unit_Index().Value() == unit_index);
                        CHECK(itr.Point_Index().Value() == point_index);
                    } while (charcoder != none_t());
                    CHECK(unit_index == string.Unit_Count());
                    CHECK(point_index == string.Point_Count());
                    CHECK(itr.Unit_Index().Value() == string.Unit_Count());
                    CHECK(itr.Point_Index().Value() == string.Point_Count());
                }

                TEST_CASE_TEMPLATE("should move through a non-terminated error-ridden string the same as manually using a charcoder", itr_p, nkr_NON_CONST_NON_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;

                    nkr_RANDOM_STRING_t() string = Non_Terminated_Random_String<string_t>(true);
                    nkr_STRING_itr(string) itr(string);
                    charcoder_t charcoder;
                    count_t unit_index = 0;
                    count_t point_index = 0;
                    while (unit_index < string.Unit_Count()) {
                        unit_index += charcoder.Read_Forward(&string.Unit(0) + unit_index);
                        point_index += 1;
                        CHECK(itr.Point() == charcoder.Decode());
                        itr.Next();
                        CHECK(itr.Unit_Index().Value() == unit_index);
                        CHECK(itr.Point_Index().Value() == point_index);
                    }
                    CHECK(unit_index == string.Unit_Count());
                    CHECK(point_index == string.Point_Count());
                    CHECK(itr.Unit_Index().Value() == string.Unit_Count());
                    CHECK(itr.Point_Index().Value() == string.Point_Count());
                }
            }

            TEST_SUITE("Prior()")
            {
                TEST_CASE_TEMPLATE("should move to the prior point when not at the prefix", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count());
                    nkr_STRING_itr(string) itr(string, point_index);
                    itr.Prior();
                    if (point_index == 0) {
                        CHECK(itr.Is_At_Prefix());
                    } else {
                        CHECK(itr.Is_At(point_index - 1));
                    }
                }

                TEST_CASE_TEMPLATE("should return true when not at the prefix", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count()));
                    CHECK_TRUE(itr.Prior());
                }

                TEST_CASE_TEMPLATE("should return false when at the prefix", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK_FALSE(itr.Prior());
                }
            }

            TEST_SUITE("Unit_Index()")
            {
                TEST_CASE_TEMPLATE("should not return an index if at the prefix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    optional_t<index_t> unit_index = itr.Unit_Index();
                    CHECK(!unit_index);
                }

                TEST_CASE_TEMPLATE("should return the correct index for first", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    optional_t<index_t> unit_index = itr.Unit_Index();
                    CHECK(unit_index && unit_index.Value() == 0);
                }

                TEST_CASE_TEMPLATE("should return the correct index for last", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    optional_t<index_t> unit_index = itr.Unit_Index();
                    if (string.Unit_Length() > 0) {
                        CHECK(unit_index && unit_index.Value() == string.Unit_Length() - itr.Point_Unit_Count());
                    } else {
                        CHECK(!unit_index);
                    }
                }

                TEST_CASE_TEMPLATE("should return the correct index for terminus", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    optional_t<index_t> unit_index = itr.Unit_Index();
                    CHECK(unit_index && unit_index.Value() == string.Unit_Count() - 1);
                }

                TEST_CASE_TEMPLATE("should return the correct index for postfix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    optional_t<index_t> unit_index = itr.Unit_Index();
                    CHECK(unit_index && unit_index.Value() == string.Unit_Count());
                }
            }

            TEST_SUITE("Point_Index()")
            {
                TEST_CASE_TEMPLATE("should not return an index if at the prefix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    optional_t<index_t> point_index = itr.Point_Index();
                    CHECK(!point_index);
                }

                TEST_CASE_TEMPLATE("should return the correct index for first", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    optional_t<index_t> point_index = itr.Point_Index();
                    CHECK(point_index && point_index.Value() == 0);
                }

                TEST_CASE_TEMPLATE("should return the correct index for last", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    optional_t<index_t> point_index = itr.Point_Index();
                    if (string.Point_Length() > 0) {
                        CHECK(point_index && point_index.Value() == string.Point_Length() - 1);
                    } else {
                        CHECK(!point_index);
                    }
                }

                TEST_CASE_TEMPLATE("should return the correct index for terminus", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    optional_t<index_t> point_index = itr.Point_Index();
                    CHECK(point_index && point_index.Value() == string.Point_Count() - 1);
                }

                TEST_CASE_TEMPLATE("should return the correct index for postfix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    optional_t<index_t> point_index = itr.Point_Index();
                    CHECK(point_index && point_index.Value() == string.Point_Count());
                }
            }

            TEST_SUITE("Charcoder()")
            {
                TEST_CASE_TEMPLATE("should return a const reference to the charcoder at the current point", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count() - 1));
                    CHECK(itr.Charcoder().Decode() == itr.Point());
                }

                TEST_CASE_TEMPLATE("should return a const reference to the charcoder with a terminus when at the prefix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK(itr.Charcoder().Decode() == 0);
                }

                TEST_CASE_TEMPLATE("should return a const reference to the charcoder with a terminus when at the postfix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK(itr.Charcoder().Decode() == 0);
                }
            }

            TEST_SUITE("Point()")
            {
                TEST_CASE_TEMPLATE("should return 0 when at the prefix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK(itr.Point() == 0);
                }

                TEST_CASE_TEMPLATE("should return 0 when at the first point in a string with a length of 0", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_EMPTY_STRING_t() string = Empty_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    CHECK(itr.Point() == 0);
                }

                TEST_CASE_TEMPLATE("should not return 0 when at the first point in a string with a length greater than 0", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(2) string = Random_String<string_t, 2>();
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    CHECK(itr.Point() != 0);
                }

                TEST_CASE_TEMPLATE("should return 0 when at the last point in a string with a length of 0", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_EMPTY_STRING_t() string = Empty_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    CHECK(itr.Point() == 0);
                    CHECK(itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should not return 0 when at the last point in a string with a length greater than 0", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(2) string = Random_String<string_t, 2>();
                    nkr_STRING_itr(string) itr(string, position_e::last_tg());
                    CHECK(itr.Point() != 0);
                    CHECK(!itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should return 0 when at the terminus", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK(itr.Point() == 0);
                }

                TEST_CASE_TEMPLATE("should return 0 when at the postfix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK(itr.Point() == 0);
                }

                TEST_CASE_TEMPLATE("should return point for point whether a string is terminated or not", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    using qualified_charcoder_t = itr_p::qualified_charcoder_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    static_t<qualified_charcoder_t> other(string, false);
                    CHECK(string.Point_Length() == other.Point_Length());

                    nkr_STRING_itr(string) itr(string);
                    string_itr<decltype(other)> other_itr(other);
                    for (; !itr.Is_At_Postfix(); itr += 1, other_itr += 1) {
                        CHECK(itr.Point() == other_itr.Point());
                    }
                }

                TEST_CASE_TEMPLATE("should return point for point whether an error-ridden string is terminated or not", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    using qualified_charcoder_t = itr_p::qualified_charcoder_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>(true);
                    static_t<qualified_charcoder_t> other(string, false);
                    CHECK(string.Point_Length() == other.Point_Length());

                    nkr_STRING_itr(string) itr(string);
                    string_itr<decltype(other)> other_itr(other);
                    for (; !itr.Is_At_Postfix(); itr += 1, other_itr += 1) {
                        CHECK(itr.Point() == other_itr.Point());
                    }
                }

                // should have a test that caches the points collected from a next and prior run to determine that they are the same
            }

            TEST_SUITE("Point_Unit_Count()")
            {
                TEST_CASE_TEMPLATE("should return the number of units which represent the point", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count()));
                    charcoder_t charcoder;
                    charcoder.Encode(itr.Point());
                    CHECK(itr.Point_Unit_Count() == charcoder.Unit_Count());
                }
            }

            TEST_SUITE("Point_Unit()")
            {
                TEST_CASE_TEMPLATE("should return the indexed unit of the point", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;

                    nkr_RANDOM_STRING_t(1) string = Random_String<string_t, 1>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count() - 1));
                    charcoder_t charcoder;
                    charcoder.Encode(itr.Point());
                    for (index_t idx = 0, end = itr.Point_Unit_Count(); idx < end; idx += 1) {
                        CHECK(itr.Point_Unit(idx) == charcoder.Unit(idx));
                    }
                }
            }

            TEST_SUITE("Substring()")
            {
                TEST_CASE_TEMPLATE("should return a substring_t containing non-error units", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    using substring_t = itr_p::substring_t;

                    nkr_RANDOM_STRING_t(2) string = Random_String<string_t, 2>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count() - 2));
                    CHECK(!itr.Is_At_Error());
                    substring_t substring = itr.Substring();
                    CHECK(substring.Unit_Length() > 0);
                    CHECK(substring.Unit_Length() == itr.Point_Unit_Count());
                    for (index_t idx = 0, end = substring.Unit_Length(); idx < end; idx += 1) {
                        CHECK(substring.Unit(idx) == itr.Point_Unit(idx));
                    }
                }

                TEST_CASE_TEMPLATE("should return a substring_t containing error units", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    using substring_t = itr_p::substring_t;

                    nkr_ERROR_STRING_t() string = Error_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count() - 2));
                    CHECK(itr.Is_At_Error());
                    substring_t substring = itr.Substring();
                    CHECK(substring.Unit_Length() > 0);
                    string_itr<substring_t> substring_itr(substring);
                    CHECK(substring_itr.Is_At_Error());
                }

                TEST_CASE_TEMPLATE("should return an empty substring_t when at the prefix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    using substring_t = itr_p::substring_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    substring_t substring = itr.Substring();
                    CHECK(substring.Unit_Length() == 0);
                }

                TEST_CASE_TEMPLATE("should return an empty substring_t when at the terminus", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    using substring_t = itr_p::substring_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    substring_t substring = itr.Substring();
                    CHECK(substring.Unit_Length() == 0);
                }

                TEST_CASE_TEMPLATE("should return an empty substring_t when at the postfix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    using substring_t = itr_p::substring_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    substring_t substring = itr.Substring();
                    CHECK(substring.Unit_Length() == 0);
                }
            }

            TEST_SUITE("Substring_Unit_Length()")
            {
                TEST_CASE_TEMPLATE("should return the same number of units in the point when not at an error", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(2) string = Random_String<string_t, 2>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count() - 2));
                    CHECK(itr.Substring_Unit_Length() == itr.Point_Unit_Count());
                }

                TEST_CASE_TEMPLATE("should return the number of units read by a charcoder, which may vary from the point count", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using substring_t = itr_p::substring_t;

                    nkr_ERROR_STRING_t() string = Error_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count() - 2));
                    charcoder_t charcoder;
                    substring_t substring = itr.Substring();
                    CHECK(itr.Substring_Unit_Length() == charcoder.Read_Forward(substring.C_String()()));
                }

                TEST_CASE_TEMPLATE("should return 0 when at the prefix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::prefix_tg());
                    CHECK(itr.Substring_Unit_Length() == 0);
                }

                TEST_CASE_TEMPLATE("should return 0 when at the terminus", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    CHECK(itr.Substring_Unit_Length() == 0);
                }

                TEST_CASE_TEMPLATE("should return 0 when at the postfix", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string, position_e::postfix_tg());
                    CHECK(itr.Substring_Unit_Length() == 0);
                }
            }

            TEST_SUITE("Substring_Unit()")
            {
                TEST_CASE_TEMPLATE("should return the same unit as Point_Unit when there is no error", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(2) string = Random_String<string_t, 2>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count() - 2));
                    CHECK(itr.Substring_Unit_Length() == itr.Point_Unit_Count());
                    index_t substring_unit_index = Random<index_t>(0, itr.Substring_Unit_Length() - 1);
                    CHECK(itr.Substring_Unit(substring_unit_index) == itr.Point_Unit(substring_unit_index));
                }

                TEST_CASE_TEMPLATE("should return the same unit as is found in the string when there is an error", itr_p, nkr_ALL_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_ERROR_STRING_t() string = Error_String<string_t>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count() - 2));
                    index_t itr_unit_index = itr.Unit_Index().Value();
                    index_t substring_unit_index = Random<index_t>(0, itr.Substring_Unit_Length() - 1);
                    CHECK(itr.Substring_Unit(substring_unit_index) == itr.String().Unit(itr_unit_index + substring_unit_index));
                }
            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("+=()")
            {
                TEST_CASE_TEMPLATE("should increment the iterator by the given point count", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(16) string = Random_String<string_t, 16>();
                    index_t point_index = Random<index_t>(0, string.Point_Count() - 1);
                    nkr_STRING_itr(string) itr(string, point_index);
                    count_t point_count = Random<count_t>(0, string.Point_Count() - 1 - point_index);
                    itr += point_count;
                    CHECK(itr.Is_At(point_index + point_count));
                }

                TEST_CASE_TEMPLATE("should not move when given a point count of zero", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count() - 1);
                    nkr_STRING_itr(string) itr(string, point_index);
                    itr += 0;
                    CHECK(itr.Is_At(point_index));
                }

                TEST_CASE_TEMPLATE("should be able to move unto the postfix", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count() - 1);
                    nkr_STRING_itr(string) itr(string, point_index);
                    itr += string.Point_Count() - point_index;
                    CHECK(itr.Is_At_Postfix());
                }
            }

            TEST_SUITE("-=()")
            {
                TEST_CASE_TEMPLATE("should decrement the iterator by the given point count", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(16) string = Random_String<string_t, 16>();
                    index_t point_index = Random<index_t>(0, string.Point_Count() - 1);
                    nkr_STRING_itr(string) itr(string, point_index);
                    count_t point_count = Random<count_t>(0, point_index);
                    itr -= point_count;
                    CHECK(itr.Is_At(point_index - point_count));
                }

                TEST_CASE_TEMPLATE("should not move when given a point count of zero", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count() - 1);
                    nkr_STRING_itr(string) itr(string, point_index);
                    itr -= 0;
                    CHECK(itr.Is_At(point_index));
                }

                TEST_CASE_TEMPLATE("should be able to move unto the prefix", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    index_t point_index = Random<index_t>(0, string.Point_Count() - 1);
                    nkr_STRING_itr(string) itr(string, point_index);
                    itr -= point_index + 1;
                    CHECK(itr.Is_At_Prefix());
                }
            }

            TEST_SUITE("++()")
            {
                TEST_CASE_TEMPLATE("should move the iterator one index after the current index", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(16) string = Random_String<string_t, 16>();
                    index_t point_index = Random<index_t>(0, string.Point_Count() - 2);
                    nkr_STRING_itr(string) itr(string, point_index);
                    ++itr;
                    CHECK(itr.Is_At(point_index + 1));
                }

                TEST_CASE_TEMPLATE("should move unto the postfix when at the terminus", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(16) string = Random_String<string_t, 16>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    ++itr;
                    CHECK(itr.Is_At_Postfix());
                }

                TEST_CASE_TEMPLATE("should return itself", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(16) string = Random_String<string_t, 16>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(0, string.Point_Count() - 1));
                    CHECK(&++itr == &itr);
                }

                TEST_CASE_TEMPLATE("should move through a string the same as manually using a charcoder", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;

                    nkr_RANDOM_STRING_t() string = Random_String<string_t>();
                    nkr_STRING_itr(string) itr(string);
                    charcoder_t charcoder;
                    count_t unit_index = 0;
                    count_t point_index = 0;
                    do {
                        unit_index += charcoder.Read_Forward(&string.Unit(0) + unit_index);
                        point_index += 1;
                        CHECK(itr.Point() == charcoder.Decode());
                        ++itr;
                        CHECK(itr.Unit_Index().Value() == unit_index);
                        CHECK(itr.Point_Index().Value() == point_index);
                    } while (charcoder != none_t());
                    CHECK(unit_index == string.Unit_Count());
                    CHECK(point_index == string.Point_Count());
                    CHECK(itr.Unit_Index().Value() == string.Unit_Count());
                    CHECK(itr.Point_Index().Value() == string.Point_Count());
                }
            }

            TEST_SUITE("++(int)")
            {
                TEST_CASE_TEMPLATE("should move the iterator one index after the current index", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(16) string = Random_String<string_t, 16>();
                    index_t point_index = Random<index_t>(0, string.Point_Count() - 2);
                    nkr_STRING_itr(string) itr(string, point_index);
                    itr++;
                    CHECK(itr.Is_At(point_index + 1));
                }

                TEST_CASE_TEMPLATE("should move unto the postfix when at the terminus", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(16) string = Random_String<string_t, 16>();
                    nkr_STRING_itr(string) itr(string, position_e::terminus_tg());
                    itr++;
                    CHECK(itr.Is_At_Postfix());
                }

                TEST_CASE_TEMPLATE("should return a copy of the iterator as it was before the alteration", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(16) string = Random_String<string_t, 16>();
                    index_t point_index = Random<index_t>(0, string.Point_Count() - 1);
                    nkr_STRING_itr(string) itr(string, point_index);
                    CHECK((itr++).Is_At(point_index));
                }
            }

            TEST_SUITE("--()")
            {
                TEST_CASE_TEMPLATE("should move the iterator one index before the current index", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(16) string = Random_String<string_t, 16>();
                    index_t point_index = Random<index_t>(1, string.Point_Count() - 1);
                    nkr_STRING_itr(string) itr(string, point_index);
                    --itr;
                    CHECK(itr.Is_At(point_index - 1));
                }

                TEST_CASE_TEMPLATE("should move unto the prefix when at the first point", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(16) string = Random_String<string_t, 16>();
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    --itr;
                    CHECK(itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should return itself", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(16) string = Random_String<string_t, 16>();
                    nkr_STRING_itr(string) itr(string, Random<index_t>(1, string.Point_Count()));
                    CHECK(&--itr == &itr);
                }
            }

            TEST_SUITE("--(int)")
            {
                TEST_CASE_TEMPLATE("should move the iterator one index before the current index", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(16) string = Random_String<string_t, 16>();
                    index_t point_index = Random<index_t>(1, string.Point_Count() - 1);
                    nkr_STRING_itr(string) itr(string, point_index);
                    itr--;
                    CHECK(itr.Is_At(point_index - 1));
                }

                TEST_CASE_TEMPLATE("should move unto the prefix when at the first point", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(16) string = Random_String<string_t, 16>();
                    nkr_STRING_itr(string) itr(string, position_e::first_tg());
                    itr--;
                    CHECK(itr.Is_At_Prefix());
                }

                TEST_CASE_TEMPLATE("should return a copy of the iterator as it was before the alteration", itr_p, nkr_NON_CONST_TERMINATED)
                {
                    using string_t = itr_p::string_t;

                    nkr_RANDOM_STRING_t(16) string = Random_String<string_t, 16>();
                    index_t point_index = Random<index_t>(1, string.Point_Count());
                    nkr_STRING_itr(string) itr(string, point_index);
                    CHECK((itr--).Is_At(point_index));
                }
            }
        }
    }

}}
