/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/enumeration/types_t.h"

namespace nkr {

    //temp
    enum test_e :
        cpp::negatable::integer_16_t
    {
        TEST = 1,
    };
    static_assert(sizeof(decltype(TEST)) == sizeof(cpp::negatable::integer_16_t));  // always keeps the same size as given integral
    static_assert(!cpp::is_tr<decltype(TEST), cpp::negatable::integer_16_t>);       // is never the same type as its integral
    static_assert(cpp::is_tr<decltype(TEST), test_e>);                              // is the same type as its identifier
    static_assert(!std::is_integral<decltype(TEST)>::value);                        // is not actually an integral
    static_assert(std::is_enum<decltype(TEST)>::value);                             // but is an enum
    static_assert(!std::is_unsigned<decltype(TEST)>::value);                        // cannot be unsigned
    static_assert(!std::is_signed<decltype(TEST)>::value);                          // and cannot be signed

    enum class test_2_e :
        cpp::positive::integer_8_t
    {
        TEST_2 = 1,
    };
    static_assert(sizeof(decltype(test_2_e::TEST_2)) == sizeof(cpp::positive::integer_8_t));
    static_assert(!cpp::is_tr<decltype(test_2_e::TEST_2), cpp::positive::integer_8_t>);
    static_assert(cpp::is_tr<decltype(test_2_e::TEST_2), test_2_e>);
    static_assert(!std::is_integral<decltype(test_2_e::TEST_2)>::value);
    static_assert(std::is_enum<decltype(test_2_e::TEST_2)>::value);
    static_assert(!std::is_unsigned<decltype(test_2_e::TEST_2)>::value);
    static_assert(!std::is_signed<decltype(test_2_e::TEST_2)>::value);
    //

}
