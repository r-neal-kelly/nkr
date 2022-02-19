/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/z_intrinsics.h"
#include "nkr/z_os.h"
#include "nkr/z_utils.h"

#include "doctest.h"

namespace nkr { namespace os { namespace atomic {

    TEST_SUITE("nkr::os::atomic")
    {
        class base_t
        {
        };

        class derived_t :
            public base_t
        {
        };

    #if defined(nkr_IS_64_BIT)

    #define atoms   \
        bool_t,     \
        c_bool_t,   \
        u8_t,       \
        s8_t,       \
        u16_t,      \
        s16_t,      \
        u32_t,      \
        s32_t,      \
        u64_t,      \
        s64_t,      \
        r32_t,      \
        r64_t,      \
        void_t*,    \
        base_t*

    #define pairs                       \
        std::tuple<bool_t, word_t>,     \
        std::tuple<c_bool_t, word_t>,   \
        std::tuple<u8_t, real_t>,       \
        std::tuple<s8_t, real_t>,       \
        std::tuple<u16_t, real_t>,      \
        std::tuple<s16_t, real_t>,      \
        std::tuple<u32_t, real_t>,      \
        std::tuple<s32_t, real_t>,      \
        std::tuple<u64_t, real_t>,      \
        std::tuple<s64_t, real_t>,      \
        std::tuple<r32_t, word_t>,      \
        std::tuple<r64_t, word_t>,      \
        std::tuple<void_t*, word_t*>,   \
        std::tuple<base_t*, derived_t*>

    #else

    #define atoms   \
        bool_t,     \
        c_bool_t,   \
        u8_t,       \
        s8_t,       \
        u16_t,      \
        s16_t,      \
        u32_t,      \
        s32_t,      \
        r32_t,      \
        void_t*,    \
        base_t*

    #define pairs                       \
        std::tuple<bool_t, word_t>,     \
        std::tuple<c_bool_t, word_t>,   \
        std::tuple<u8_t, real_t>,       \
        std::tuple<s8_t, real_t>,       \
        std::tuple<u16_t, real_t>,      \
        std::tuple<s16_t, real_t>,      \
        std::tuple<u32_t, real_t>,      \
        std::tuple<s32_t, real_t>,      \
        std::tuple<r32_t, u64_t>,       \
        std::tuple<void_t*, word_t*>,   \
        std::tuple<base_t*, derived_t*>

    #endif

        TEST_SUITE("Access")
        {
            TEST_SUITE("Access()")
            {
                /// [_86910968_68e4_4a84_9b9c_8ac16a0ac95d]
                TEST_CASE_TEMPLATE("should return the value", atom_p, atoms)
                {
                    atom_p random = Random<atom_p>();
                    CHECK(Access(random) == random);
                }
                /// [_86910968_68e4_4a84_9b9c_8ac16a0ac95d]

                /// [_b9ee057a_7e73_4016_9503_c3920c6252d0]
                TEST_CASE_TEMPLATE("should not change the value", atom_p, atoms)
                {
                    const atom_p random = Random<atom_p>();
                    const atom_p backup = random;
                    Access(random);
                    CHECK(random == backup);
                }
                /// [_b9ee057a_7e73_4016_9503_c3920c6252d0]
            }
        }

        TEST_SUITE("Assign")
        {
            TEST_SUITE("Assign()")
            {
                /// [_cff5cad0_8935_47e7_9e98_0598518c3222]
                TEST_CASE_TEMPLATE("should set the value to the passed value", atom_p, atoms)
                {
                    atom_p random_a = Random<atom_p>();
                    atom_p random_b = Random<atom_p>();
                    atom_p value = random_a;
                    Assign(value, random_b);
                    CHECK(value == random_b);
                }
                /// [_cff5cad0_8935_47e7_9e98_0598518c3222]

                /// [_e5b23352_d0a7_4639_9b3d_4e330b3276b5]
                TEST_CASE_TEMPLATE("should return the new value", atom_p, atoms)
                {
                    atom_p random_a = Random<atom_p>();
                    atom_p random_b = Random<atom_p>();
                    atom_p value = random_a;
                    CHECK(Assign(value, random_b) == random_b);
                }
                /// [_e5b23352_d0a7_4639_9b3d_4e330b3276b5]

                /// [_c043156a_7642_423b_89d0_413a386ad1b4]
                TEST_CASE_TEMPLATE("should work with types convertible to the value", pair_p, pairs)
                {
                    using atom_p = std::tuple_element_t<0, pair_p>;
                    using convertible_p = std::tuple_element_t<1, pair_p>;

                    atom_p random_a = Random<atom_p>();
                    convertible_p random_b = Random<convertible_p>();
                    atom_p value = random_a;
                    Assign(value, random_b);
                    CHECK(value == static_cast<atom_p>(random_b));
                }
                /// [_c043156a_7642_423b_89d0_413a386ad1b4]
            }

            TEST_SUITE("Assign_Add()")
            {
                /// [_c04ef484_20f3_4fc0_be4b_2d8b40dff6d5]
                TEST_CASE_TEMPLATE("should set the value to value + passed value", atom_p, atoms)
                {
                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        Assign_Add(value, random_b);
                        CHECK(value == (random_a += random_b));
                    }
                }
                /// [_c04ef484_20f3_4fc0_be4b_2d8b40dff6d5]

                /// [_096ae2c4_1600_4049_ac92_d988d50936ec]
                TEST_CASE_TEMPLATE("should return the new value", atom_p, atoms)
                {
                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        CHECK(Assign_Add(value, random_b) == (random_a += random_b));
                    }
                }
                /// [_096ae2c4_1600_4049_ac92_d988d50936ec]

                /// [_4150d822_2671_4307_9086_beb5c310d5ac]
                TEST_CASE_TEMPLATE("should work with types convertible to the value", pair_p, pairs)
                {
                    using atom_p = std::tuple_element_t<0, pair_p>;
                    using convertible_p = std::tuple_element_t<1, pair_p>;

                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        convertible_p random_b = Random<convertible_p>();
                        atom_p value = random_a;
                        Assign_Add(value, random_b);
                        CHECK(value == (random_a += static_cast<atom_p>(random_b)));
                    }
                }
                /// [_4150d822_2671_4307_9086_beb5c310d5ac]
            }

            TEST_SUITE("Assign_Add(type_pointer_tr)")
            {
                /// [_dd52b045_aa56_4134_b7ff_6e00c13f892d]
                TEST_CASE_TEMPLATE("should set the value to value + passed value", atom_p, atoms)
                {
                    if constexpr (type_pointer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        word_t random_b = Random<word_t>();
                        atom_p value = random_a;
                        Assign_Add(value, random_b);
                        CHECK(value == (random_a += random_b));
                    }
                }
                /// [_dd52b045_aa56_4134_b7ff_6e00c13f892d]

                /// [_462ab46f_5031_49e9_98a7_2ca50e3b17d3]
                TEST_CASE_TEMPLATE("should return the new value", atom_p, atoms)
                {
                    if constexpr (type_pointer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        word_t random_b = Random<word_t>();
                        atom_p value = random_a;
                        CHECK(Assign_Add(value, random_b) == (random_a += random_b));
                    }
                }
                /// [_462ab46f_5031_49e9_98a7_2ca50e3b17d3]
            }

            TEST_SUITE("Assign_Subtract()")
            {
                /// [_548cda9b_cb3a_4cd3_954b_d69352ef3264]
                TEST_CASE_TEMPLATE("should set the value to value - passed value", atom_p, atoms)
                {
                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        Assign_Subtract(value, random_b);
                        CHECK(value == (random_a -= random_b));
                    }
                }
                /// [_548cda9b_cb3a_4cd3_954b_d69352ef3264]

                /// [_f2794a9e_5c10_4ff4_a912_7ace768cddc0]
                TEST_CASE_TEMPLATE("should return the new value", atom_p, atoms)
                {
                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        CHECK(Assign_Subtract(value, random_b) == (random_a -= random_b));
                    }
                }
                /// [_f2794a9e_5c10_4ff4_a912_7ace768cddc0]

                /// [_599ff640_2ddf_4edb_9a4e_e94242d25215]
                TEST_CASE_TEMPLATE("should work with types convertible to the value", pair_p, pairs)
                {
                    using atom_p = std::tuple_element_t<0, pair_p>;
                    using convertible_p = std::tuple_element_t<1, pair_p>;

                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        convertible_p random_b = Random<convertible_p>();
                        atom_p value = random_a;
                        Assign_Subtract(value, random_b);
                        CHECK(value == (random_a -= static_cast<atom_p>(random_b)));
                    }
                }
                /// [_599ff640_2ddf_4edb_9a4e_e94242d25215]
            }

            TEST_SUITE("Assign_Subtract(type_pointer_tr)")
            {
                /// [_5b2fdcbb_2d09_4209_ad38_336f6ff3f0c3]
                TEST_CASE_TEMPLATE("should set the value to value - passed value", atom_p, atoms)
                {
                    if constexpr (type_pointer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        word_t random_b = Random<word_t>();
                        atom_p value = random_a;
                        Assign_Subtract(value, random_b);
                        CHECK(value == (random_a -= random_b));
                    }
                }
                /// [_5b2fdcbb_2d09_4209_ad38_336f6ff3f0c3]

                /// [_e396ac45_f9d6_433c_8a11_addfb4d85587]
                TEST_CASE_TEMPLATE("should return the new value", atom_p, atoms)
                {
                    if constexpr (type_pointer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        word_t random_b = Random<word_t>();
                        atom_p value = random_a;
                        CHECK(Assign_Subtract(value, random_b) == (random_a -= random_b));
                    }
                }
                /// [_e396ac45_f9d6_433c_8a11_addfb4d85587]
            }

            TEST_SUITE("Assign_Multiply()")
            {
                /// [_95ff1c60_a59e_44f6_8f24_edffeb74ca2c]
                TEST_CASE_TEMPLATE("should set the value to value * passed value", atom_p, atoms)
                {
                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        Assign_Multiply(value, random_b);
                        CHECK(value == (random_a *= random_b));
                    }
                }
                /// [_95ff1c60_a59e_44f6_8f24_edffeb74ca2c]

                /// [_b4e15d76_ef69_4edd_a524_b50ca5cb6821]
                TEST_CASE_TEMPLATE("should return the new value", atom_p, atoms)
                {
                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        CHECK(Assign_Multiply(value, random_b) == (random_a *= random_b));
                    }
                }
                /// [_b4e15d76_ef69_4edd_a524_b50ca5cb6821]

                /// [_37851c52_0ed4_4b15_a024_657fa6449913]
                TEST_CASE_TEMPLATE("should work with types convertible to the value", pair_p, pairs)
                {
                    using atom_p = std::tuple_element_t<0, pair_p>;
                    using convertible_p = std::tuple_element_t<1, pair_p>;

                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        convertible_p random_b = Random<convertible_p>();
                        atom_p value = random_a;
                        Assign_Multiply(value, random_b);
                        CHECK(value == (random_a *= static_cast<atom_p>(random_b)));
                    }
                }
                /// [_37851c52_0ed4_4b15_a024_657fa6449913]
            }

            TEST_SUITE("Assign_Divide()")
            {
                /// [_88dfcc83_1a76_4d84_8196_b4a5582ac05a]
                TEST_CASE_TEMPLATE("should set the value to value / passed value", atom_p, atoms)
                {
                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b;
                        do {
                            random_b = Random<atom_p>();
                        } while (random_b == 0);
                        atom_p value = random_a;
                        Assign_Divide(value, random_b);
                        CHECK(value == (random_a /= random_b));
                    }
                }
                /// [_88dfcc83_1a76_4d84_8196_b4a5582ac05a]

                /// [_8880d6ac_53f3_4f80_9f8e_2141566a5dfb]
                TEST_CASE_TEMPLATE("should return the new value", atom_p, atoms)
                {
                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b;
                        do {
                            random_b = Random<atom_p>();
                        } while (random_b == 0);
                        atom_p value = random_a;
                        CHECK(Assign_Divide(value, random_b) == (random_a /= random_b));
                    }
                }
                /// [_8880d6ac_53f3_4f80_9f8e_2141566a5dfb]

                /// [_16308dc7_620e_43b4_8682_95947cce466b]
                TEST_CASE_TEMPLATE("should work with types convertible to the value", pair_p, pairs)
                {
                    using atom_p = std::tuple_element_t<0, pair_p>;
                    using convertible_p = std::tuple_element_t<1, pair_p>;

                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        convertible_p random_b;
                        do {
                            random_b = Random<convertible_p>(std::numeric_limits<atom_p>::lowest(),
                                                             std::numeric_limits<atom_p>::max());
                        } while (static_cast<atom_p>(random_b) == 0);
                        atom_p value = random_a;
                        Assign_Divide(value, random_b);
                        CHECK(value == (random_a /= static_cast<atom_p>(random_b)));
                    }
                }
                /// [_16308dc7_620e_43b4_8682_95947cce466b]
            }

            TEST_SUITE("Assign_Modulus()")
            {
                /// [_f08cbcd4_5eb9_4df6_a8eb_43a5ab642f1f]
                TEST_CASE_TEMPLATE("should set the value to value % passed value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b;
                        do {
                            random_b = Random<atom_p>();
                        } while (random_b == 0);
                        atom_p value = random_a;
                        Assign_Modulus(value, random_b);
                        CHECK(value == (random_a %= random_b));
                    }
                }
                /// [_f08cbcd4_5eb9_4df6_a8eb_43a5ab642f1f]

                /// [_83b37b61_a830_4c1a_a280_4d947b25f183]
                TEST_CASE_TEMPLATE("should return the new value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b;
                        do {
                            random_b = Random<atom_p>();
                        } while (random_b == 0);
                        atom_p value = random_a;
                        CHECK(Assign_Modulus(value, random_b) == (random_a %= random_b));
                    }
                }
                /// [_83b37b61_a830_4c1a_a280_4d947b25f183]
            }

            TEST_SUITE("Assign_Or()")
            {
                /// [_f5a67175_71e4_4e40_875d_0b649b258584]
                TEST_CASE_TEMPLATE("should set the value to value | passed value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        Assign_Or(value, random_b);
                        CHECK(value == (random_a |= random_b));
                    }
                }
                /// [_f5a67175_71e4_4e40_875d_0b649b258584]

                /// [_72fe08fb_efd6_41ad_b45d_1e13fa595118]
                TEST_CASE_TEMPLATE("should return the new value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        CHECK(Assign_Or(value, random_b) == (random_a |= random_b));
                    }
                }
                /// [_72fe08fb_efd6_41ad_b45d_1e13fa595118]
            }

            TEST_SUITE("Assign_And()")
            {
                /// [_8abe8ccb_90fd_4ae8_971f_a31fa3b61318]
                TEST_CASE_TEMPLATE("should set the value to value & passed value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        Assign_And(value, random_b);
                        CHECK(value == (random_a &= random_b));
                    }
                }
                /// [_8abe8ccb_90fd_4ae8_971f_a31fa3b61318]

                /// [_8b6d9f33_1845_4a13_999c_219390bfad89]
                TEST_CASE_TEMPLATE("should return the new value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        CHECK(Assign_And(value, random_b) == (random_a &= random_b));
                    }
                }
                /// [_8b6d9f33_1845_4a13_999c_219390bfad89]
            }

            TEST_SUITE("Assign_Xor()")
            {
                /// [_6a119048_abc7_41e9_8eed_756ba39191c5]
                TEST_CASE_TEMPLATE("should set the value to value ^ passed value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        Assign_Xor(value, random_b);
                        CHECK(value == (random_a ^= random_b));
                    }
                }
                /// [_6a119048_abc7_41e9_8eed_756ba39191c5]

                /// [_a88aea13_e8e8_4f55_a568_b48bfb7c666b]
                TEST_CASE_TEMPLATE("should return the new value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        CHECK(Assign_Xor(value, random_b) == (random_a ^= random_b));
                    }
                }
                /// [_a88aea13_e8e8_4f55_a568_b48bfb7c666b]
            }

            TEST_SUITE("Assign_Left_Shift()")
            {
                /// [_d34f4b0d_94d7_4cee_8275_2986169ee4bb]
                TEST_CASE_TEMPLATE("should set the value to value << passed value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        Assign_Left_Shift(value, random_b);
                        CHECK(value == (random_a <<= random_b));
                    }
                }
                /// [_d34f4b0d_94d7_4cee_8275_2986169ee4bb]

                /// [_7293a041_ac89_40d6_851c_2fcc5fa87cfc]
                TEST_CASE_TEMPLATE("should return the new value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        CHECK(Assign_Left_Shift(value, random_b) == (random_a <<= random_b));
                    }
                }
                /// [_7293a041_ac89_40d6_851c_2fcc5fa87cfc]
            }

            TEST_SUITE("Assign_Right_Shift()")
            {
                /// [_35470cf4_9526_436e_9e4d_1260a7f5da36]
                TEST_CASE_TEMPLATE("should set the value to value >> passed value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        Assign_Right_Shift(value, random_b);
                        CHECK(value == (random_a >>= random_b));
                    }
                }
                /// [_35470cf4_9526_436e_9e4d_1260a7f5da36]

                /// [_fac50b5b_9154_4619_a9f6_e9a8932be1d6]
                TEST_CASE_TEMPLATE("should return the new value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        CHECK(Assign_Right_Shift(value, random_b) == (random_a >>= random_b));
                    }
                }
                /// [_fac50b5b_9154_4619_a9f6_e9a8932be1d6]
            }
        }

        TEST_SUITE("Exchange")
        {
            TEST_SUITE("Exchange()")
            {
                /// [_bfb8a372_e1f9_4422_97e1_e6ba09bf5447]
                TEST_CASE_TEMPLATE("should set the value to the passed value", atom_p, atoms)
                {
                    atom_p random_a = Random<atom_p>();
                    atom_p random_b = Random<atom_p>();
                    atom_p value = random_a;
                    Exchange(value, random_b);
                    CHECK(value == random_b);
                }
                /// [_bfb8a372_e1f9_4422_97e1_e6ba09bf5447]

                /// [_ad652bfb_c5e7_4f7c_a44a_96bc9926770a]
                TEST_CASE_TEMPLATE("should return the old value", atom_p, atoms)
                {
                    atom_p random_a = Random<atom_p>();
                    atom_p random_b = Random<atom_p>();
                    atom_p value = random_a;
                    CHECK(Exchange(value, random_b) == random_a);
                }
                /// [_ad652bfb_c5e7_4f7c_a44a_96bc9926770a]

                /// [_6ff73bc8_9314_4d30_9ff1_f6075f14a765]
                TEST_CASE_TEMPLATE("should work with types convertible to the value", pair_p, pairs)
                {
                    using atom_p = std::tuple_element_t<0, pair_p>;
                    using convertible_p = std::tuple_element_t<1, pair_p>;

                    atom_p random_a = Random<atom_p>();
                    convertible_p random_b = Random<convertible_p>();
                    atom_p value = random_a;
                    Exchange(value, random_b);
                    CHECK(value == static_cast<atom_p>(random_b));
                }
                /// [_6ff73bc8_9314_4d30_9ff1_f6075f14a765]
            }

            TEST_SUITE("Exchange_Add()")
            {
                /// [_49848ac8_c1b4_4943_a696_01ad844ba232]
                TEST_CASE_TEMPLATE("should set the value to value + passed value", atom_p, atoms)
                {
                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        Exchange_Add(value, random_b);
                        CHECK(value == (random_a += random_b));
                    }
                }
                /// [_49848ac8_c1b4_4943_a696_01ad844ba232]

                /// [_63e6d632_7ff2_4ef9_81d7_99ba01619d4c]
                TEST_CASE_TEMPLATE("should return the old value", atom_p, atoms)
                {
                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        CHECK(Exchange_Add(value, random_b) == random_a);
                    }
                }
                /// [_63e6d632_7ff2_4ef9_81d7_99ba01619d4c]

                /// [_658a6304_5262_4da9_81ff_3a20dfb2416b]
                TEST_CASE_TEMPLATE("should work with types convertible to the value", pair_p, pairs)
                {
                    using atom_p = std::tuple_element_t<0, pair_p>;
                    using convertible_p = std::tuple_element_t<1, pair_p>;

                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        convertible_p random_b = Random<convertible_p>();
                        atom_p value = random_a;
                        Exchange_Add(value, random_b);
                        CHECK(value == (random_a += static_cast<atom_p>(random_b)));
                    }
                }
                /// [_658a6304_5262_4da9_81ff_3a20dfb2416b]
            }

            TEST_SUITE("Exchange_Add(type_pointer_tr)")
            {
                /// [_2ba66e6c_3839_4110_8317_6ff0d84e56bc]
                TEST_CASE_TEMPLATE("should set the value to value + passed value", atom_p, atoms)
                {
                    if constexpr (type_pointer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        word_t random_b = Random<word_t>();
                        atom_p value = random_a;
                        Exchange_Add(value, random_b);
                        CHECK(value == (random_a += random_b));
                    }
                }
                /// [_2ba66e6c_3839_4110_8317_6ff0d84e56bc]

                /// [_e68df812_6fdb_4279_a4e5_276d1e532426]
                TEST_CASE_TEMPLATE("should return the old value", atom_p, atoms)
                {
                    if constexpr (type_pointer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        word_t random_b = Random<word_t>();
                        atom_p value = random_a;
                        CHECK(Exchange_Add(value, random_b) == random_a);
                    }
                }
                /// [_e68df812_6fdb_4279_a4e5_276d1e532426]
            }

            TEST_SUITE("Exchange_Subtract()")
            {
                /// [_5af84e35_a73e_447e_a291_11cad13fc45a]
                TEST_CASE_TEMPLATE("should set the value to value - passed value", atom_p, atoms)
                {
                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        Exchange_Subtract(value, random_b);
                        CHECK(value == (random_a -= random_b));
                    }
                }
                /// [_5af84e35_a73e_447e_a291_11cad13fc45a]

                /// [_14b2395b_d7eb_4d35_ab27_d2483b376004]
                TEST_CASE_TEMPLATE("should return the old value", atom_p, atoms)
                {
                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        CHECK(Exchange_Subtract(value, random_b) == random_a);
                    }
                }
                /// [_14b2395b_d7eb_4d35_ab27_d2483b376004]

                /// [_83dfbe1a_86a9_42b8_bb6b_b4ad5b264a4a]
                TEST_CASE_TEMPLATE("should work with types convertible to the value", pair_p, pairs)
                {
                    using atom_p = std::tuple_element_t<0, pair_p>;
                    using convertible_p = std::tuple_element_t<1, pair_p>;

                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        convertible_p random_b = Random<convertible_p>();
                        atom_p value = random_a;
                        Exchange_Subtract(value, random_b);
                        CHECK(value == (random_a -= static_cast<atom_p>(random_b)));
                    }
                }
                /// [_83dfbe1a_86a9_42b8_bb6b_b4ad5b264a4a]
            }

            TEST_SUITE("Exchange_Subtract(type_pointer_tr)")
            {
                /// [_8834bbe1_d6e2_4813_b90f_2536b00eba99]
                TEST_CASE_TEMPLATE("should set the value to value - passed value", atom_p, atoms)
                {
                    if constexpr (type_pointer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        word_t random_b = Random<word_t>();
                        atom_p value = random_a;
                        Exchange_Subtract(value, random_b);
                        CHECK(value == (random_a -= random_b));
                    }
                }
                /// [_8834bbe1_d6e2_4813_b90f_2536b00eba99]

                /// [_536ea92e_bc98_402d_b22f_3ae2a338f694]
                TEST_CASE_TEMPLATE("should return the old value", atom_p, atoms)
                {
                    if constexpr (type_pointer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        word_t random_b = Random<word_t>();
                        atom_p value = random_a;
                        CHECK(Exchange_Subtract(value, random_b) == random_a);
                    }
                }
                /// [_536ea92e_bc98_402d_b22f_3ae2a338f694]
            }

            TEST_SUITE("Exchange_Multiply()")
            {
                /// [_5ae68f89_6432_4aac_a8c7_977f268bb34d]
                TEST_CASE_TEMPLATE("should set the value to value * passed value", atom_p, atoms)
                {
                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        Exchange_Multiply(value, random_b);
                        CHECK(value == (random_a *= random_b));
                    }
                }
                /// [_5ae68f89_6432_4aac_a8c7_977f268bb34d]

                /// [_58db82c9_bce0_4cc6_990b_644fbce87a59]
                TEST_CASE_TEMPLATE("should return the old value", atom_p, atoms)
                {
                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        CHECK(Exchange_Multiply(value, random_b) == random_a);
                    }
                }
                /// [_58db82c9_bce0_4cc6_990b_644fbce87a59]

                /// [_91df7f02_eabd_40c6_8255_cd4c64e92e82]
                TEST_CASE_TEMPLATE("should work with types convertible to the value", pair_p, pairs)
                {
                    using atom_p = std::tuple_element_t<0, pair_p>;
                    using convertible_p = std::tuple_element_t<1, pair_p>;

                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        convertible_p random_b = Random<convertible_p>();
                        atom_p value = random_a;
                        Exchange_Multiply(value, random_b);
                        CHECK(value == (random_a *= static_cast<atom_p>(random_b)));
                    }
                }
                /// [_91df7f02_eabd_40c6_8255_cd4c64e92e82]
            }

            TEST_SUITE("Exchange_Divide()")
            {
                /// [_fae67eda_9402_4e49_9607_e3184dbd2b38]
                TEST_CASE_TEMPLATE("should set the value to value / passed value", atom_p, atoms)
                {
                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b;
                        do {
                            random_b = Random<atom_p>();
                        } while (random_b == 0);
                        atom_p value = random_a;
                        Exchange_Divide(value, random_b);
                        CHECK(value == (random_a /= random_b));
                    }
                }
                /// [_fae67eda_9402_4e49_9607_e3184dbd2b38]

                /// [_c3947eeb_8969_4edb_8130_49d6ff2ac2fd]
                TEST_CASE_TEMPLATE("should return the old value", atom_p, atoms)
                {
                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b;
                        do {
                            random_b = Random<atom_p>();
                        } while (random_b == 0);
                        atom_p value = random_a;
                        CHECK(Exchange_Divide(value, random_b) == random_a);
                    }
                }
                /// [_c3947eeb_8969_4edb_8130_49d6ff2ac2fd]

                /// [_1cc9dcb3_26b4_4499_8cd5_8db780bdca8c]
                TEST_CASE_TEMPLATE("should work with types convertible to the value", pair_p, pairs)
                {
                    using atom_p = std::tuple_element_t<0, pair_p>;
                    using convertible_p = std::tuple_element_t<1, pair_p>;

                    if constexpr (number_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        convertible_p random_b;
                        do {
                            random_b = Random<convertible_p>(std::numeric_limits<atom_p>::lowest(),
                                                             std::numeric_limits<atom_p>::max());
                        } while (static_cast<atom_p>(random_b) == 0);
                        atom_p value = random_a;
                        Exchange_Divide(value, random_b);
                        CHECK(value == (random_a /= static_cast<atom_p>(random_b)));
                    }
                }
                /// [_1cc9dcb3_26b4_4499_8cd5_8db780bdca8c]
            }

            TEST_SUITE("Exchange_Modulus()")
            {
                /// [_e5451fea_cc5f_4ebc_b5d5_8b08c3a111da]
                TEST_CASE_TEMPLATE("should set the value to value % passed value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b;
                        do {
                            random_b = Random<atom_p>();
                        } while (random_b == 0);
                        atom_p value = random_a;
                        Exchange_Modulus(value, random_b);
                        CHECK(value == (random_a %= random_b));
                    }
                }
                /// [_e5451fea_cc5f_4ebc_b5d5_8b08c3a111da]

                /// [_9c67480d_25d1_41ad_8030_63335bf8ea23]
                TEST_CASE_TEMPLATE("should return the old value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b;
                        do {
                            random_b = Random<atom_p>();
                        } while (random_b == 0);
                        atom_p value = random_a;
                        CHECK(Exchange_Modulus(value, random_b) == random_a);
                    }
                }
                /// [_9c67480d_25d1_41ad_8030_63335bf8ea23]
            }

            TEST_SUITE("Exchange_Or()")
            {
                /// [_b174d2e7_5cb0_407a_8657_991c0f444ba4]
                TEST_CASE_TEMPLATE("should set the value to value | passed value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        Exchange_Or(value, random_b);
                        CHECK(value == (random_a |= random_b));
                    }
                }
                /// [_b174d2e7_5cb0_407a_8657_991c0f444ba4]

                /// [_7f93e7c5_8e50_44fa_8b7d_459a5b7a349a]
                TEST_CASE_TEMPLATE("should return the old value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        CHECK(Exchange_Or(value, random_b) == random_a);
                    }
                }
                /// [_7f93e7c5_8e50_44fa_8b7d_459a5b7a349a]
            }

            TEST_SUITE("Exchange_And()")
            {
                /// [_f22797a7_89bc_4b21_bb54_4821a254fef8]
                TEST_CASE_TEMPLATE("should set the value to value & passed value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        Exchange_And(value, random_b);
                        CHECK(value == (random_a &= random_b));
                    }
                }
                /// [_f22797a7_89bc_4b21_bb54_4821a254fef8]

                /// [_032da151_3782_47dc_a9fe_9bfa1ead41ca]
                TEST_CASE_TEMPLATE("should return the old value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        CHECK(Exchange_And(value, random_b) == random_a);
                    }
                }
                /// [_032da151_3782_47dc_a9fe_9bfa1ead41ca]
            }

            TEST_SUITE("Exchange_Xor()")
            {
                /// [_8aff4d56_ead1_4706_8a83_7ffe39b94dea]
                TEST_CASE_TEMPLATE("should set the value to value ^ passed value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        Exchange_Xor(value, random_b);
                        CHECK(value == (random_a ^= random_b));
                    }
                }
                /// [_8aff4d56_ead1_4706_8a83_7ffe39b94dea]

                /// [_b5a97fce_b8a8_46de_a777_b6b40b4094b2]
                TEST_CASE_TEMPLATE("should return the old value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        CHECK(Exchange_Xor(value, random_b) == random_a);
                    }
                }
                /// [_b5a97fce_b8a8_46de_a777_b6b40b4094b2]
            }

            TEST_SUITE("Exchange_Left_Shift()")
            {
                /// [_50e9921e_8412_4549_b13a_b999679ad0be]
                TEST_CASE_TEMPLATE("should set the value to value << passed value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        Exchange_Left_Shift(value, random_b);
                        CHECK(value == (random_a <<= random_b));
                    }
                }
                /// [_50e9921e_8412_4549_b13a_b999679ad0be]

                /// [_36e6f4c1_7bf0_4e1f_abeb_95fd6c7f4a6a]
                TEST_CASE_TEMPLATE("should return the old value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        CHECK(Exchange_Left_Shift(value, random_b) == random_a);
                    }
                }
                /// [_36e6f4c1_7bf0_4e1f_abeb_95fd6c7f4a6a]
            }

            TEST_SUITE("Exchange_Right_Shift()")
            {
                /// [_6e658448_1e1f_4055_9f66_e194035f5573]
                TEST_CASE_TEMPLATE("should set the value to value >> passed value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        Exchange_Right_Shift(value, random_b);
                        CHECK(value == (random_a >>= random_b));
                    }
                }
                /// [_6e658448_1e1f_4055_9f66_e194035f5573]

                /// [_db165fe2_b8b4_4056_aabd_a62cad104e6a]
                TEST_CASE_TEMPLATE("should return the old value", atom_p, atoms)
                {
                    if constexpr (integer_tr<atom_p>) {
                        atom_p random_a = Random<atom_p>();
                        atom_p random_b = Random<atom_p>();
                        atom_p value = random_a;
                        CHECK(Exchange_Right_Shift(value, random_b) == random_a);
                    }
                }
                /// [_db165fe2_b8b4_4056_aabd_a62cad104e6a]
            }

            TEST_SUITE("Exchange_If_Equals()")
            {
                /// [_034843e4_e0d0_4f52_8f78_c3f56925da13]
                TEST_CASE_TEMPLATE("should set the value to the passed value if the value equals the snapshot", atom_p, atoms)
                {
                    atom_p random_a = Random<atom_p>();
                    atom_p random_b = Random<atom_p>();
                    atom_p value = random_a;
                    atom_p snapshot = value;
                    Exchange_If_Equals(value, snapshot, random_b);
                    CHECK(value == random_b);
                }
                /// [_034843e4_e0d0_4f52_8f78_c3f56925da13]

                /// [_0be1610a_27fa_4ad6_90b8_13a3fc51a126]
                TEST_CASE_TEMPLATE("should return true if it set the new value", atom_p, atoms)
                {
                    atom_p random_a = Random<atom_p>();
                    atom_p random_b = Random<atom_p>();
                    atom_p value = random_a;
                    atom_p snapshot = value;
                    CHECK(Exchange_If_Equals(value, snapshot, random_b) == true);
                }
                /// [_0be1610a_27fa_4ad6_90b8_13a3fc51a126]

                /// [_03edfad8_0c53_4b7c_b3e6_6e718f150abb]
                TEST_CASE_TEMPLATE("should return false if it did not set the new value", atom_p, atoms)
                {
                    atom_p random_a = Random<atom_p>();
                    atom_p random_b;
                    do {
                        random_b = Random<atom_p>();
                    } while (random_b == random_a);
                    atom_p value = random_a;
                    atom_p snapshot = value;
                    value = random_b;
                    CHECK(Exchange_If_Equals(value, snapshot, atom_p()) == false);
                }
                /// [_03edfad8_0c53_4b7c_b3e6_6e718f150abb]

                /// [_8fa4472e_33c7_4135_a485_5ce05496cdf1]
                TEST_CASE_TEMPLATE("should leave snapshot with the old value if it succeeded", atom_p, atoms)
                {
                    atom_p random_a = Random<atom_p>();
                    atom_p random_b = Random<atom_p>();
                    atom_p value = random_a;
                    atom_p snapshot = value;
                    Exchange_If_Equals(value, snapshot, random_b);
                    CHECK(snapshot == random_a);
                }
                /// [_8fa4472e_33c7_4135_a485_5ce05496cdf1]

                /// [_55c80c7e_e54b_43fc_bc79_de6b25a4dfa8]
                TEST_CASE_TEMPLATE("should update snapshot to the current value if it failed", atom_p, atoms)
                {
                    atom_p random_a = Random<atom_p>();
                    atom_p random_b;
                    do {
                        random_b = Random<atom_p>();
                    } while (random_b == random_a);
                    atom_p value = random_a;
                    atom_p snapshot = value;
                    value = random_b;
                    Exchange_If_Equals(value, snapshot, atom_p());
                    CHECK(snapshot == random_b);
                }
                /// [_55c80c7e_e54b_43fc_bc79_de6b25a4dfa8]

                /// [_449b38fb_4737_41b7_80b0_3ab13221ffcc]
                TEST_CASE_TEMPLATE("should work with types convertible to the value", pair_p, pairs)
                {
                    using atom_p = std::tuple_element_t<0, pair_p>;
                    using convertible_p = std::tuple_element_t<1, pair_p>;

                    atom_p random_a = Random<atom_p>();
                    convertible_p random_b = Random<convertible_p>();
                    atom_p value = random_a;
                    atom_p snapshot = value;
                    Exchange_If_Equals(value, snapshot, random_b);
                    CHECK(value == static_cast<atom_p>(random_b));
                }
                /// [_449b38fb_4737_41b7_80b0_3ab13221ffcc]
            }
        }

    #undef atoms
    #undef pairs
    }

}}}

namespace nkr { namespace os { namespace endian {

    TEST_SUITE("nkr::os::endian")
    {
        TEST_SUITE("Info")
        {
            TEST_SUITE("Is_Big()")
            {
                TEST_CASE("should in a thread-safe manner efficiently determine if the runtime is in big endian"
                          * doctest::may_fail(true)
                          * doctest::no_breaks(true))
                {
                    /// [_2367da3d_58c3_4a8f_98c4_c9d8c809cb25]
                #if defined(nkr_IS_WINDOWS)
                    CHECK(nkr::os::endian::Is_Big() == false);
                #else
                    CHECK(nkr::os::endian::Is_Big() == true);
                #endif
                    /// [_2367da3d_58c3_4a8f_98c4_c9d8c809cb25]
                }
            }

            TEST_SUITE("Is_Little()")
            {
                TEST_CASE("should in a thread-safe manner efficiently determine if the runtime is in little endian"
                          * doctest::may_fail(true)
                          * doctest::no_breaks(true))
                {
                    /// [_e5a7621e_6b04_42ef_b8d2_94d576abb57e]
                #if defined(nkr_IS_WINDOWS)
                    CHECK(nkr::os::endian::Is_Little() == true);
                #else
                    CHECK(nkr::os::endian::Is_Little() == false);
                #endif
                    /// [_e5a7621e_6b04_42ef_b8d2_94d576abb57e]
                }
            }
        }

        TEST_SUITE("Swap")
        {
            TEST_SUITE("Swap()")
            {
                TEST_SUITE("should swap the bytes of 16 bit, 32 bit, and 64 bit numbers")
                {
                    TEST_CASE("s32_t literal")
                    {
                        /// [_8204605f_3b41_4633_8865_89d336420022]
                        CHECK(nkr::os::endian::Swap(0x0102) != 0x0201);
                        CHECK(nkr::os::endian::Swap(0x0102) == 0x02010000);
                        CHECK(nkr::os::endian::Swap(static_cast<u16_t>(0x0102)) == 0x0201);

                        CHECK(nkr::os::endian::Swap(0x01020304) == 0x04030201);
                        CHECK(nkr::os::endian::Swap(0x0102030405060708) == 0x0807060504030201);
                        /// [_8204605f_3b41_4633_8865_89d336420022]
                    }
                    TEST_CASE("u16_t")
                    {
                        /// [_6bc67519_2af0_4999_a15c_ad085acb68e4]
                        u16_t u16 = 0x0102;
                        CHECK(nkr::os::endian::Swap(u16) == 0x0201);
                        /// [_6bc67519_2af0_4999_a15c_ad085acb68e4]
                    }
                    TEST_CASE("s16_t")
                    {
                        /// [_962de4de_8f29_4f35_9ffb_123ac19b3cf8]
                        s16_t s16 = 0x0102;
                        CHECK(nkr::os::endian::Swap(s16) == 0x0201);
                        /// [_962de4de_8f29_4f35_9ffb_123ac19b3cf8]
                    }
                    TEST_CASE("u32_t")
                    {
                        /// [_d480540a_cabf_45d6_b3dc_0882dca2569b]
                        u32_t u32 = 0x01020304;
                        CHECK(nkr::os::endian::Swap(u32) == 0x04030201);
                        /// [_d480540a_cabf_45d6_b3dc_0882dca2569b]
                    }
                    TEST_CASE("s32_t")
                    {
                        /// [_59caf647_91bb_4926_b0d0_401183e97ded]
                        s32_t s32 = 0x01020304;
                        CHECK(nkr::os::endian::Swap(s32) == 0x04030201);
                        /// [_59caf647_91bb_4926_b0d0_401183e97ded]
                    }
                    TEST_CASE("u64_t")
                    {
                        /// [_52a0d032_dab3_4a2e_a06a_67bc56f297f4]
                        u64_t u64 = 0x0102030405060708;
                        CHECK(nkr::os::endian::Swap(u64) == 0x0807060504030201);
                        /// [_52a0d032_dab3_4a2e_a06a_67bc56f297f4]
                    }
                    TEST_CASE("s64_t")
                    {
                        /// [_70f7b676_8069_4eec_93bf_007c172f1e39]
                        s64_t s64 = 0x0102030405060708;
                        CHECK(nkr::os::endian::Swap(s64) == 0x0807060504030201);
                        /// [_70f7b676_8069_4eec_93bf_007c172f1e39]
                    }
                }
            }
        }
    }

}}}

namespace nkr { namespace os { namespace heap {

    TEST_SUITE("nkr::os::heap")
    {
        TEST_SUITE("Allocation")
        {
            TEST_SUITE("Allocate()")
            {
                TEST_CASE("should allocate heap memory and set pointer. sets nullptr on failure. returns maybe error")
                {
                    /// [_a06ecc73_e7ac_43b2_b231_059675458c15]
                    word_t* words = nullptr;
                    CHECK(os::heap::Allocate(words, 0xFF) == allocator_err::NONE);
                    CHECK(words != nullptr);

                    word_t* too_many = nullptr;
                    CHECK(os::heap::Allocate(too_many, std::numeric_limits<count_t>::max() / sizeof(word_t)) == allocator_err::OUT_OF_MEMORY);
                    CHECK(too_many == nullptr);

                    os::heap::Deallocate(words);
                    /// [_a06ecc73_e7ac_43b2_b231_059675458c15]
                }
            }

            TEST_SUITE("Reallocate()")
            {
                TEST_CASE("should reallocate heap memory and set pointer. leaves pointer on failure. returns maybe error")
                {
                    /// [_3c97398a_6fe6_4b47_81a2_18efd5ab72d5]
                    word_t* words = nullptr;
                    CHECK(os::heap::Allocate(words, 0xFF) == allocator_err::NONE);
                    CHECK(os::heap::Reallocate(words, 0x100) == allocator_err::NONE);
                    CHECK(words != nullptr);

                    word_t* backup = words;
                    CHECK(os::heap::Reallocate(words, std::numeric_limits<count_t>::max() / sizeof(word_t)) == allocator_err::OUT_OF_MEMORY);
                    CHECK(words == backup);

                    os::heap::Deallocate(words);
                    /// [_3c97398a_6fe6_4b47_81a2_18efd5ab72d5]
                }

                TEST_CASE("should deallocate pointer when given a new_unit_count of 0. sets nullptr. returns maybe error")
                {
                    /// []
                    word_t* words = nullptr;
                    CHECK(os::heap::Allocate(words, 0xFF) == allocator_err::NONE);
                    CHECK(os::heap::Reallocate(words, 0) == allocator_err::NONE);
                    CHECK(words == nullptr);

                    os::heap::Deallocate(words);
                    /// []
                }

                TEST_CASE("should allocate pointer when given nullptr. returns maybe error")
                {
                    word_t* words = nullptr;
                    CHECK(os::heap::Reallocate(words, 0xFF) == allocator_err::NONE);
                    CHECK(words != nullptr);

                    os::heap::Deallocate(words);
                }
            }

            TEST_SUITE("Deallocate()")
            {
                TEST_CASE("should deallocate heap memory and set pointer to nullptr, or if pointer is nullptr, silently fail")
                {
                    /// [_09113b05_5f70_459c_9827_f53c58816243]
                    word_t* words = nullptr;
                    CHECK(os::heap::Allocate(words, 0xFF) == allocator_err::NONE);
                    os::heap::Deallocate(words);
                    CHECK(words == nullptr);

                    os::heap::Deallocate(words);
                    CHECK(words == nullptr);
                    /// [_09113b05_5f70_459c_9827_f53c58816243]
                }
            }
        }

        TEST_SUITE("Zero-Initialized Allocation")
        {
            TEST_SUITE("Allocate_Zeros()")
            {
                TEST_CASE("should allocate heap memory and set pointer. sets memory to zero. sets nullptr on failure. returns maybe error")
                {
                    /// [_fc02c748_8572_4062_b2b1_8cfaa78bc002]
                    word_t* words = nullptr;
                    CHECK(os::heap::Allocate_Zeros(words, 0xFF) == allocator_err::NONE);
                    CHECK(words != nullptr);
                    for (index_t idx = 0, end = 0xFF; idx < end; idx += 1) {
                        WARN(words[idx] == 0);
                    }

                    word_t* too_many = nullptr;
                    CHECK(os::heap::Allocate_Zeros(too_many, std::numeric_limits<count_t>::max() / sizeof(word_t)) == allocator_err::OUT_OF_MEMORY);
                    CHECK(too_many == nullptr);

                    os::heap::Deallocate_Zeros(words);
                    /// [_fc02c748_8572_4062_b2b1_8cfaa78bc002]
                }
            }

            TEST_SUITE("Reallocate_Zeros()")
            {
                TEST_CASE("should reallocate heap memory and set pointer. sets memory to zero. leaves pointer on failure. returns maybe error")
                {
                    /// [_831dc6ca_17bd_4515_9fd9_48f36c1014da]
                    word_t* words = nullptr;
                    CHECK(os::heap::Allocate_Zeros(words, 0xFF) == allocator_err::NONE);
                    CHECK(os::heap::Reallocate_Zeros(words, 0x100) == allocator_err::NONE);
                    CHECK(words != nullptr);
                    for (index_t idx = 0, end = 0x100; idx < end; idx += 1) {
                        WARN(words[idx] == 0);
                    }

                    word_t* backup = words;
                    CHECK(os::heap::Reallocate_Zeros(words, std::numeric_limits<count_t>::max() / sizeof(word_t)) == allocator_err::OUT_OF_MEMORY);
                    CHECK(words == backup);

                    os::heap::Deallocate_Zeros(words);
                    /// [_831dc6ca_17bd_4515_9fd9_48f36c1014da]
                }

                TEST_CASE("should deallocate pointer when given a new_unit_count of 0. sets nullptr. returns maybe error")
                {
                    /// []
                    word_t* words = nullptr;
                    CHECK(os::heap::Allocate_Zeros(words, 0xFF) == allocator_err::NONE);
                    CHECK(os::heap::Reallocate_Zeros(words, 0) == allocator_err::NONE);
                    CHECK(words == nullptr);

                    os::heap::Deallocate_Zeros(words);
                    /// []
                }

                TEST_CASE("should allocate pointer when given nullptr. returns maybe error")
                {
                    word_t* words = nullptr;
                    CHECK(os::heap::Reallocate_Zeros(words, 0xFF) == allocator_err::NONE);
                    CHECK(words != nullptr);

                    os::heap::Deallocate_Zeros(words);
                }
            }

            TEST_SUITE("Deallocate_Zeros()")
            {
                TEST_CASE("should deallocate heap memory and set pointer to nullptr, or if pointer is nullptr, silently fail")
                {
                    /// [_6c279b29_119d_4ca0_8c6a_552cb9ea6431]
                    word_t* words = nullptr;
                    CHECK(os::heap::Allocate_Zeros(words, 0xFF) == allocator_err::NONE);
                    os::heap::Deallocate_Zeros(words);
                    CHECK(words == nullptr);

                    os::heap::Deallocate_Zeros(words);
                    CHECK(words == nullptr);
                    /// [_6c279b29_119d_4ca0_8c6a_552cb9ea6431]
                }
            }
        }
    }

}}}
