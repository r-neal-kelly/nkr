/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/bool_t.h"

#include "intrinsics.h"

namespace nkr {

    TEST_SUITE("bool_t")
    {
        /// [_3e7cd520_dafd_4a17_befe_912aeb32e870]
        template <typename type_p>
        concept has_unwanted_bool_operators_tr =
            requires(type_p instance) { +instance; } ||
            requires(type_p instance) { -instance; } ||

            requires(type_p instance) { instance + 1; } ||
            requires(type_p instance) { instance - 1; } ||
            requires(type_p instance) { instance * 1; } ||
            requires(type_p instance) { instance / 1; } ||
            requires(type_p instance) { instance % 1; } ||

            requires(type_p instance) { ~instance; } ||
            requires(type_p instance) { instance | 1; } ||
            requires(type_p instance) { instance & 1; } ||
            requires(type_p instance) { instance ^ 1; } ||
            requires(type_p instance) { instance << 1; } ||
            requires(type_p instance) { instance >> 1; } ||

            requires(type_p instance) { instance += 1; } ||
            requires(type_p instance) { instance -= 1; } ||
            requires(type_p instance) { instance *= 1; } ||
            requires(type_p instance) { instance /= 1; } ||
            requires(type_p instance) { instance %= 1; } ||

            requires(type_p instance) { instance |= 1; } ||
            requires(type_p instance) { instance &= 1; } ||
            requires(type_p instance) { instance ^= 1; } ||
            requires(type_p instance) { instance <<= 1; } ||
            requires(type_p instance) { instance >>= 1; } ||

            requires(type_p instance) { ++instance; } ||
            requires(type_p instance) { instance++; } ||
            requires(type_p instance) { --instance; } ||
            requires(type_p instance) { instance--; } ||

            requires(type_p instance) { instance < 1; } ||
            requires(type_p instance) { instance > 1; } ||
            requires(type_p instance) { instance <= 1; } ||
            requires(type_p instance) { instance >= 1; } ||
            requires(type_p instance) { instance <=> 1; };
        /// [_3e7cd520_dafd_4a17_befe_912aeb32e870]

        TEST_CASE("certain operators are unwanted")
        {
            /// [_29b44101_c393_4fdd_b59d_cb9a75802d5a]
            CHECK(has_unwanted_bool_operators_tr<std_bool_t> == true);
            CHECK(has_unwanted_bool_operators_tr<bool_t> == false);
            /// [_29b44101_c393_4fdd_b59d_cb9a75802d5a]
        }

        TEST_SUITE("object data")
        {
            /// [_a89a1659_6cb8_4255_a6da_a2c1e5869af4]
            template <typename type_t>
            concept accessible_value_tr = requires(type_t instance)
            {
                instance.value;
            };
            /// [_a89a1659_6cb8_4255_a6da_a2c1e5869af4]

            TEST_CASE("value should be protected and accessible only through inheritance")
            {
                /// [_7d5433ff_7c1f_4566_b1ab_55367dfb36b8]
                CHECK(accessible_value_tr<bool_t> == false);
                
                class derived_t :
                    public bool_t
                {
                public:
                    using bool_t::value;
                };
                CHECK(accessible_value_tr<derived_t> == true);
                /// [_7d5433ff_7c1f_4566_b1ab_55367dfb36b8]
            }
        }

        TEST_SUITE("objects")
        {
            TEST_CASE("default_ctor() should set value to false")
            {
                /// [_a4d6c055_2b65_4b1f_90ca_28a60ebf4eab]
                bool_t boolean;
                CHECK(boolean == false);
                /// [_a4d6c055_2b65_4b1f_90ca_28a60ebf4eab]
            }

            TEST_CASE("value_ctor() should take an object or expression convertible to std_bool_t and copy its value")
            {
                /// [_62211c6c_3f81_4429_ab68_5fb576cd2e2e]
                CHECK(bool_t(true) == true);
                CHECK(bool_t(1) == true);
                CHECK(bool_t(static_cast<std_bool_t>('a')) == true);
                CHECK(bool_t(1.0) == true);

                word_t word = 0;
                CHECK(bool_t(&word) == true);
                CHECK(bool_t(static_cast<void_t*>(&word)) == true);
                CHECK(bool_t(static_cast<std_bool_t>(nullptr)) == false);

                CHECK(bool_t(static_cast<std_bool_t>(bool_t(true))) == true);

                CHECK(bool_t(true && 1 && 1.0) == true);
                /// [_62211c6c_3f81_4429_ab68_5fb576cd2e2e]
            }

            TEST_CASE("value_ctor() should be called when using construction by assignment")
            {
                /// [_df5e960b_9224_4646_b4fb_593e26554f6f]
                bool_t boolean = true;
                CHECK(boolean == true);
                /// [_df5e960b_9224_4646_b4fb_593e26554f6f]
            }

            TEST_CASE("copy_ctor() should copy the other's value without changing it")
            {
                /// [_5481d9e8_2096_40da_a7a0_22d0b80308fb]
                bool_t other(true);
                CHECK(bool_t(other) == true);
                CHECK(other == true);
                /// [_5481d9e8_2096_40da_a7a0_22d0b80308fb]
            }

            TEST_CASE("copy_ctor() should be called when using construction by assignment")
            {
                /// [_9c61dce0_72c4_4990_bdc7_531edda971d3]
                bool_t other(true);
                bool_t boolean = other;
                CHECK(boolean == true);
                CHECK(other == true);
                /// [_9c61dce0_72c4_4990_bdc7_531edda971d3]
            }

            TEST_CASE("move_ctor() should move the other's value by exchanging it with false")
            {
                /// [_93151c91_7466_446f_9886_a448bfa178dc]
                bool_t other(true);
                CHECK(bool_t(std::move(other)) == true);
                CHECK(other == false);
                /// [_93151c91_7466_446f_9886_a448bfa178dc]
            }

            TEST_CASE("move_ctor() should be called when using construction by assignment")
            {
                /// [_23f44a66_a616_4359_8cc3_7c98f7f2227c]
                bool_t other(true);
                bool_t boolean = std::move(other);
                CHECK(boolean == true);
                CHECK(other == false);
                /// [_23f44a66_a616_4359_8cc3_7c98f7f2227c]
            }

            TEST_CASE("volatile_copy_ctor() should copy the other's value without changing it")
            {
                /// [_cb2b3c43_0b96_4dfe_b9b3_81951cfaa93e]
                volatile bool_t other(true);
                CHECK(bool_t(other) == true);
                CHECK(other == true);
                /// [_cb2b3c43_0b96_4dfe_b9b3_81951cfaa93e]
            }

            TEST_CASE("volatile_copy_ctor() should be called when using construction by assignment")
            {
                /// [_24bbff36_522f_42fd_8f12_454437c24c51]
                volatile bool_t other(true);
                volatile bool_t boolean = other;
                CHECK(boolean == true);
                CHECK(other == true);
                /// [_24bbff36_522f_42fd_8f12_454437c24c51]
            }

            TEST_CASE("volatile_move_ctor() should move the other's value by exchanging it with false")
            {
                /// [_1b1d0b0f_2c1e_46d8_924b_cbaaf8a604d6]
                volatile bool_t other(true);
                CHECK(bool_t(std::move(other)) == true);
                CHECK(other == false);
                /// [_1b1d0b0f_2c1e_46d8_924b_cbaaf8a604d6]
            }

            TEST_CASE("volatile_move_ctor() should be called when using construction by assignment")
            {
                /// [_95b07b9c_0cd5_4b6a_9575_3ae7a8d5853e]
                volatile bool_t other(true);
                volatile bool_t boolean = std::move(other);
                CHECK(boolean == true);
                CHECK(other == false);
                /// [_95b07b9c_0cd5_4b6a_9575_3ae7a8d5853e]
            }

            TEST_CASE("value_assignment_ctor() should take an object or expression convertible to std_bool_t and copy its value")
            {
                /// [_2ba5c93f_34cc_41cd_9429_de6b7da6f8f5]
                bool_t boolean;

                boolean = true;
                CHECK(boolean == true);

                boolean = 1;
                CHECK(boolean == true);

                boolean = static_cast<std_bool_t>('a');
                CHECK(boolean == true);

                boolean = 1.0;
                CHECK(boolean == true);

                boolean = &boolean;
                CHECK(boolean == true);

                boolean = static_cast<void_t*>(&boolean);
                CHECK(boolean == true);

                boolean = static_cast<std_bool_t>(nullptr);
                CHECK(boolean == false);

                boolean = static_cast<std_bool_t>(bool_t(true));
                CHECK(boolean == true);

                boolean = true && 1 && 1.0;
                CHECK(boolean == true);
                /// [_2ba5c93f_34cc_41cd_9429_de6b7da6f8f5]
            }

            TEST_CASE("copy_assignment_ctor() should copy the other's value without changing it")
            {
                /// [_3f590aea_1f04_4fea_bd78_8c165201a062]
                bool_t boolean;
                bool_t other(true);
                boolean = other;
                CHECK(boolean == true);
                CHECK(other == true);
                /// [_3f590aea_1f04_4fea_bd78_8c165201a062]
            }

            TEST_CASE("move_assignment_ctor() should move the other's value by exchanging it with false")
            {
                /// [_89dafc76_93be_49dc_b612_2cd3989b0c3c]
                bool_t boolean;
                bool_t other(true);
                boolean = std::move(other);
                CHECK(boolean == true);
                CHECK(other == false);
                /// [_89dafc76_93be_49dc_b612_2cd3989b0c3c]
            }

            TEST_CASE("volatile_value_assignment_ctor() should take an object or expression convertible to std_bool_t and copy its value")
            {
                /// [_4b269631_1d91_45de_af15_ab2e1fd878bb]
                volatile bool_t boolean;

                boolean = true;
                CHECK(boolean == true);

                boolean = 1;
                CHECK(boolean == true);

                boolean = static_cast<std_bool_t>('a');
                CHECK(boolean == true);

                boolean = 1.0;
                CHECK(boolean == true);

                boolean = &boolean;
                CHECK(boolean == true);

                boolean = static_cast<volatile void_t*>(&boolean);
                CHECK(boolean == true);

                boolean = static_cast<std_bool_t>(nullptr);
                CHECK(boolean == false);

                boolean = static_cast<std_bool_t>(bool_t(true));
                CHECK(boolean == true);

                boolean = true && 1 && 1.0;
                CHECK(boolean == true);
                /// [_4b269631_1d91_45de_af15_ab2e1fd878bb]
            }

            TEST_CASE("volatile_copy_assignment_ctor() should copy the other's value without changing it")
            {
                /// [_915f296c_5a2a_44ab_bd99_04367377d7bd]
                volatile bool_t boolean;
                volatile bool_t other(true);
                boolean = other;
                CHECK(boolean == true);
                CHECK(other == true);
                /// [_915f296c_5a2a_44ab_bd99_04367377d7bd]
            }

            TEST_CASE("volatile_move_assignment_ctor() should move the other's value by exchanging it with false")
            {
                /// [_e57cfa69_54fa_4e91_8509_2cd75aedcb1a]
                volatile bool_t boolean;
                volatile bool_t other(true);
                boolean = std::move(other);
                CHECK(boolean == true);
                CHECK(other == false);
                /// [_e57cfa69_54fa_4e91_8509_2cd75aedcb1a]
            }

            TEST_CASE("dtor() should set its value to false")
            {
                /// [_6fd7e147_ba41_4d98_adfe_e140a227e79a]
                bool_t boolean(true);
                boolean.~bool_t();
                CHECK(boolean == false);

                const bool_t const_boolean(true);
                const_boolean.~bool_t();
                CHECK(const_boolean == false);

                volatile bool_t volatile_boolean(true);
                volatile_boolean.~bool_t();
                CHECK(volatile_boolean == false);

                volatile const bool_t volatile_const_boolean(true);
                volatile_const_boolean.~bool_t();
                CHECK(volatile_const_boolean == false);
                /// [_6fd7e147_ba41_4d98_adfe_e140a227e79a]
            }
        }

        TEST_SUITE("casts")
        {
            TEST_CASE("std_bool_t() const should convert value to std_bool_t explicity")
            {
                /// [_c90cbd67_36ee_49a8_809d_380c54085e40]
                bool_t boolean(true);
                const bool_t const_boolean(true);
                CHECK(std_bool_t(boolean) == true);
                CHECK(std_bool_t(const_boolean) == true);

                std_bool_t std_bool = static_cast<std_bool_t>(boolean);
                std_bool_t const_std_bool = static_cast<std_bool_t>(const_boolean);
                CHECK(std_bool);
                CHECK(const_std_bool);
                
                CHECK(boolean && const_boolean && true);
                /// [_c90cbd67_36ee_49a8_809d_380c54085e40]
            }

            TEST_CASE("std_bool_t() volatile const should convert value to std_bool_t explicity")
            {
                /// [_21637196_10ce_4fc2_add4_3d95f5351f34]
                volatile bool_t boolean(true);
                volatile const bool_t const_boolean(true);
                CHECK(std_bool_t(boolean) == true);
                CHECK(std_bool_t(const_boolean) == true);

                std_bool_t std_bool = static_cast<std_bool_t>(boolean);
                std_bool_t const_std_bool = static_cast<std_bool_t>(const_boolean);
                CHECK(std_bool);
                CHECK(const_std_bool);

                CHECK(boolean && const_boolean && true);
                /// [_21637196_10ce_4fc2_add4_3d95f5351f34]
            }

            TEST_CASE("word_t&() should convert value to word_t& explicity")
            {
                /// [_dfb57b0b_8471_44f7_9333_166571f405ae]
                bool_t boolean(true);
                CHECK(word_t(boolean) == 1);

                word_t word = static_cast<word_t>(boolean);
                word_t& word_ref = static_cast<word_t&>(boolean);
                CHECK(word == 1 && word_ref == 1);
                
                CHECK(boolean == true);
                word_ref = 0;
                CHECK(boolean == false);
                /// [_dfb57b0b_8471_44f7_9333_166571f405ae]
            }

            TEST_CASE("const word_t&() should convert value to const word_t& explicity")
            {
                /// [_0fa2a600_9160_4608_89aa_1ff52d9865ae]
                const bool_t boolean(true);
                CHECK(word_t(boolean) == 1);

                word_t word = static_cast<word_t>(boolean);
                const word_t& word_ref = static_cast<const word_t&>(boolean);
                CHECK(word == 1 && word_ref == 1);
                /// [_0fa2a600_9160_4608_89aa_1ff52d9865ae]
            }

            TEST_CASE("volatile word_t&() should convert value to volatile word_t& explicity")
            {
                /// [_7acf2bea_986a_4fea_ac75_b69447b0b864]
                volatile bool_t boolean(true);
                CHECK(word_t(boolean) == 1);

                word_t word = static_cast<word_t>(boolean);
                volatile word_t& word_ref = static_cast<volatile word_t&>(boolean);
                CHECK(word == 1 && word_ref == 1);

                CHECK(boolean == true);
                word_ref = 0;
                CHECK(boolean == false);
                /// [_7acf2bea_986a_4fea_ac75_b69447b0b864]
            }

            TEST_CASE("volatile const word_t&() should convert value to volatile const word_t& explicity")
            {
                /// [_ff97659e_50ba_4233_820b_c1f30f56a4b4]
                volatile const bool_t boolean(true);
                CHECK(word_t(boolean) == 1);

                word_t word = static_cast<word_t>(boolean);
                volatile const word_t& word_ref = static_cast<volatile const word_t&>(boolean);
                CHECK(word == 1 && word_ref == 1);
                /// [_ff97659e_50ba_4233_820b_c1f30f56a4b4]
            }
        }

        TEST_SUITE("operators")
        {
            TEST_CASE("!() should return true if value is false, else false")
            {
                /// [_1f904e7d_68be_4c15_84d3_1290e39591b2]
                bool_t boolean(true);
                const bool_t const_boolean(true);
                volatile bool_t volatile_boolean(true);
                volatile const bool_t volatile_const_boolean(true);
                CHECK(!boolean == false);
                CHECK(!const_boolean == false);
                CHECK(!volatile_boolean == false);
                CHECK(!volatile_const_boolean == false);

                CHECK(!bool_t(true) == false);
                CHECK(!bool_t(false) == true);
                /// [_1f904e7d_68be_4c15_84d3_1290e39591b2]
            }

            TEST_CASE("==() should check if two bool_ts equate")
            {
                /// [_970274ba_914f_4966_be01_1a141e6fab53]
                bool_t boolean(true);
                const bool_t const_boolean(true);
                volatile bool_t volatile_boolean(true);
                volatile const bool_t volatile_const_boolean(true);
                CHECK(boolean == const_boolean);
                CHECK(boolean == volatile_boolean);
                CHECK(boolean == volatile_const_boolean);

                CHECK(boolean == 1);
                CHECK(boolean == 1.0);
                CHECK(boolean == &boolean);
                /// [_970274ba_914f_4966_be01_1a141e6fab53]
            }

            TEST_CASE("!=() should check if two bool_ts do not equate")
            {
                /// [_3da4ab6e_f4ec_497c_9315_383d2abc5a35]
                bool_t boolean(true);
                const bool_t const_boolean(false);
                volatile bool_t volatile_boolean(false);
                volatile const bool_t volatile_const_boolean(false);
                CHECK(boolean != const_boolean);
                CHECK(boolean != volatile_boolean);
                CHECK(boolean != volatile_const_boolean);

                CHECK(boolean != 0);
                CHECK(boolean != 0.0);
                CHECK(boolean != static_cast<std_bool_t>(nullptr));
                /// [_3da4ab6e_f4ec_497c_9315_383d2abc5a35]
            }
        }

        TEST_SUITE("none_t interface")
        {
            TEST_CASE("none_ctor() should explicitly set its value to false")
            {
                /// [_d2eb2094_38e0_4df3_b3f4_d21934bdcea1]
                bool_t boolean((none_t()));
                CHECK(boolean == false);
                /// [_d2eb2094_38e0_4df3_b3f4_d21934bdcea1]
            }

            TEST_CASE("none_ctor() should implicitly set its value to false")
            {
                /// [_593e9222_eae5_40ed_a624_f8b6901271dc]
                bool_t boolean = none_t();
                CHECK(boolean == false);
                /// [_593e9222_eae5_40ed_a624_f8b6901271dc]
            }

            TEST_CASE("=(none_t) should set its value to false and return itself")
            {
                /// [_054daa01_e0d0_4313_bc9f_02f277d97bcd]
                bool_t boolean = true;
                CHECK(boolean != none_t());
                CHECK(&(boolean = none_t()) == &boolean);
                CHECK(boolean == none_t());
                /// [_054daa01_e0d0_4313_bc9f_02f277d97bcd]
            }

            TEST_CASE("==(none_t) should return true if the value is false, else true")
            {
                /// [_53ec2db4_77be_49a2_a3d4_395f5515d4a9]
                bool_t boolean = true;
                CHECK(!(boolean == none_t()));
                boolean = none_t();
                CHECK(boolean == none_t());
                /// [_53ec2db4_77be_49a2_a3d4_395f5515d4a9]
            }

            TEST_CASE("!=(none_t) should return true if the value is true, else false")
            {
                /// [_9a721957_28c0_4dbc_a65e_a74d4f395002]
                bool_t boolean = true;
                CHECK(boolean != none_t());
                boolean = none_t();
                CHECK(!(boolean != none_t()));
                /// [_9a721957_28c0_4dbc_a65e_a74d4f395002]
            }
        }
    }

}
