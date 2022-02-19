/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/z_intrinsics.h"

#include "nkr/z_allocator_err.h"
#include "nkr/z_allocator/heap_zeros_t.h"

#include "nkr/z_array/dynamic_t.h"
#include "nkr/z_array/stack_t.h"
#include "nkr/z_array/static_t.h"

#include "nkr/z_number/arbitrary_t.h"

#include "doctest.h"

namespace nkr { namespace number {

    TEST_CASE("temp")
    {
        array::dynamic_t<u8_t> buffer;
        {
            array::stack_t<u8_t, 1> number_a = {
                u8_t(0xFF)
            };
            array::stack_t<u8_t, 1> number_b = {
                u8_t(0xFF)
            };
            array::stack_t<u8_t, 2> result;
            Multiply<u8_t>(number_a, number_b, result, buffer).Ignore_Error();
            CHECK(result.Count() == 2);
            CHECK(result[0] == 0x01);
            CHECK(result[1] == 0xFE);
        }
        {
            array::stack_t<u8_t, 2> number_a = {
                u8_t(0xFF),
                u8_t(0xFF)
            };
            array::stack_t<u8_t, 2> number_b = {
                u8_t(0xFF),
                u8_t(0xFF)
            };
            array::stack_t<u8_t, 4> result;
            array::stack_t<u8_t, Multiply_Buffer_Capacity(2)> buffer;
            Multiply<u8_t>(number_a, number_b, result, buffer).Ignore_Error();
            CHECK(result.Count() == 4);
            CHECK(result[0] == 0x01);
            CHECK(result[1] == 0x00);
            CHECK(result[2] == 0xFE);
            CHECK(result[3] == 0xFF);
        }
        {
            array::stack_t<u8_t, 3> number_a = {
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF)
            };
            array::stack_t<u8_t, 3> number_b = {
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF)
            };
            array::stack_t<u8_t, 6> result;
            array::stack_t<u8_t, Multiply_Buffer_Capacity(3)> buffer;
            Multiply<u8_t>(number_a, number_b, result, buffer).Ignore_Error();
            CHECK(result.Count() == 6);
            CHECK(result[0] == 0x01);
            CHECK(result[1] == 0x00);
            CHECK(result[2] == 0x00);
            CHECK(result[3] == 0xFE);
            CHECK(result[4] == 0xFF);
            CHECK(result[5] == 0xFF);
        }
        {
            array::stack_t<u8_t, 4> number_a = {
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF)
            };
            array::stack_t<u8_t, 4> number_b = {
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF)
            };
            array::stack_t<u8_t, 8> result;
            array::stack_t<u8_t, Multiply_Buffer_Capacity(4)> buffer;
            Multiply<u8_t>(number_a, number_b, result, buffer).Ignore_Error();
            CHECK(result.Count() == 8);
            CHECK(result[0] == 0x01);
            CHECK(result[1] == 0x00);
            CHECK(result[2] == 0x00);
            CHECK(result[3] == 0x00);
            CHECK(result[4] == 0xFE);
            CHECK(result[5] == 0xFF);
            CHECK(result[6] == 0xFF);
            CHECK(result[7] == 0xFF);
        }
        {
            array::stack_t<u8_t, 8> number_a = {
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF)
            };
            array::stack_t<u8_t, 8> number_b = {
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF)
            };
            array::stack_t<u8_t, 16> result;
            array::stack_t<u8_t, Multiply_Buffer_Capacity(8)> buffer;
            Multiply<u8_t>(number_a, number_b, result, buffer).Ignore_Error();
            CHECK(result.Count() == 16);
            CHECK(result[0] == 0x01);
            CHECK(result[1] == 0x00);
            CHECK(result[2] == 0x00);
            CHECK(result[3] == 0x00);
            CHECK(result[4] == 0x00);
            CHECK(result[5] == 0x00);
            CHECK(result[6] == 0x00);
            CHECK(result[7] == 0x00);
            CHECK(result[8] == 0xFE);
            CHECK(result[9] == 0xFF);
            CHECK(result[10] == 0xFF);
            CHECK(result[11] == 0xFF);
            CHECK(result[12] == 0xFF);
            CHECK(result[13] == 0xFF);
            CHECK(result[14] == 0xFF);
            CHECK(result[15] == 0xFF);
        }
        {
            array::stack_t<u8_t, 16> number_a = {
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF)
            };
            array::stack_t<u8_t, 16> number_b = {
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF)
            };
            array::stack_t<u8_t, 32> result;
            array::stack_t<u8_t, Multiply_Buffer_Capacity(16)> buffer;
            Multiply<u8_t>(number_a, number_b, result, buffer).Ignore_Error();
            CHECK(result.Count() == 32);
            CHECK(result[0] == 0x01);
            CHECK(result[1] == 0x00);
            CHECK(result[2] == 0x00);
            CHECK(result[3] == 0x00);
            CHECK(result[4] == 0x00);
            CHECK(result[5] == 0x00);
            CHECK(result[6] == 0x00);
            CHECK(result[7] == 0x00);
            CHECK(result[8] == 0x00);
            CHECK(result[9] == 0x00);
            CHECK(result[10] == 0x00);
            CHECK(result[11] == 0x00);
            CHECK(result[12] == 0x00);
            CHECK(result[13] == 0x00);
            CHECK(result[14] == 0x00);
            CHECK(result[15] == 0x00);
            CHECK(result[16] == 0xFE);
            CHECK(result[17] == 0xFF);
            CHECK(result[18] == 0xFF);
            CHECK(result[19] == 0xFF);
            CHECK(result[20] == 0xFF);
            CHECK(result[21] == 0xFF);
            CHECK(result[22] == 0xFF);
            CHECK(result[23] == 0xFF);
            CHECK(result[24] == 0xFF);
            CHECK(result[25] == 0xFF);
            CHECK(result[26] == 0xFF);
            CHECK(result[27] == 0xFF);
            CHECK(result[28] == 0xFF);
            CHECK(result[29] == 0xFF);
            CHECK(result[30] == 0xFF);
            CHECK(result[31] == 0xFF);
        }
        {
            array::stack_t<u8_t, 32> number_a = {
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF)
            };
            array::stack_t<u8_t, 32> number_b = {
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF)
            };
            array::stack_t<u8_t, 64> result;
            array::stack_t<u8_t, Multiply_Buffer_Capacity(32)> buffer;
            Multiply<u8_t>(number_a, number_b, result, buffer).Ignore_Error();
            CHECK(result.Count() == 64);
            CHECK(result[0] == 0x01);
            CHECK(result[1] == 0x00);
            CHECK(result[2] == 0x00);
            CHECK(result[3] == 0x00);
            CHECK(result[4] == 0x00);
            CHECK(result[5] == 0x00);
            CHECK(result[6] == 0x00);
            CHECK(result[7] == 0x00);
            CHECK(result[8] == 0x00);
            CHECK(result[9] == 0x00);
            CHECK(result[10] == 0x00);
            CHECK(result[11] == 0x00);
            CHECK(result[12] == 0x00);
            CHECK(result[13] == 0x00);
            CHECK(result[14] == 0x00);
            CHECK(result[15] == 0x00);
            CHECK(result[16] == 0x00);
            CHECK(result[17] == 0x00);
            CHECK(result[18] == 0x00);
            CHECK(result[19] == 0x00);
            CHECK(result[20] == 0x00);
            CHECK(result[21] == 0x00);
            CHECK(result[22] == 0x00);
            CHECK(result[23] == 0x00);
            CHECK(result[24] == 0x00);
            CHECK(result[25] == 0x00);
            CHECK(result[26] == 0x00);
            CHECK(result[27] == 0x00);
            CHECK(result[28] == 0x00);
            CHECK(result[29] == 0x00);
            CHECK(result[30] == 0x00);
            CHECK(result[31] == 0x00);
            CHECK(result[32] == 0xFE);
            CHECK(result[33] == 0xFF);
            CHECK(result[34] == 0xFF);
            CHECK(result[35] == 0xFF);
            CHECK(result[36] == 0xFF);
            CHECK(result[37] == 0xFF);
            CHECK(result[38] == 0xFF);
            CHECK(result[39] == 0xFF);
            CHECK(result[40] == 0xFF);
            CHECK(result[41] == 0xFF);
            CHECK(result[42] == 0xFF);
            CHECK(result[43] == 0xFF);
            CHECK(result[44] == 0xFF);
            CHECK(result[45] == 0xFF);
            CHECK(result[46] == 0xFF);
            CHECK(result[47] == 0xFF);
            CHECK(result[48] == 0xFF);
            CHECK(result[49] == 0xFF);
            CHECK(result[50] == 0xFF);
            CHECK(result[51] == 0xFF);
            CHECK(result[52] == 0xFF);
            CHECK(result[53] == 0xFF);
            CHECK(result[54] == 0xFF);
            CHECK(result[55] == 0xFF);
            CHECK(result[56] == 0xFF);
            CHECK(result[57] == 0xFF);
            CHECK(result[58] == 0xFF);
            CHECK(result[59] == 0xFF);
            CHECK(result[60] == 0xFF);
            CHECK(result[61] == 0xFF);
            CHECK(result[62] == 0xFF);
            CHECK(result[63] == 0xFF);
        }
        {
            array::stack_t<u8_t, 64> number_a = {
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF)
            };
            array::stack_t<u8_t, 64> number_b = {
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF)
            };
            array::stack_t<u8_t, 128> result;
            array::stack_t<u8_t, Multiply_Buffer_Capacity(64)> buffer;
            Multiply<u8_t>(number_a, number_b, result, buffer).Ignore_Error();
            CHECK(result.Count() == 128);
            CHECK(result[0] == 0x01);
            CHECK(result[1] == 0x00);
            CHECK(result[2] == 0x00);
            CHECK(result[3] == 0x00);
            CHECK(result[4] == 0x00);
            CHECK(result[5] == 0x00);
            CHECK(result[6] == 0x00);
            CHECK(result[7] == 0x00);
            CHECK(result[8] == 0x00);
            CHECK(result[9] == 0x00);
            CHECK(result[10] == 0x00);
            CHECK(result[11] == 0x00);
            CHECK(result[12] == 0x00);
            CHECK(result[13] == 0x00);
            CHECK(result[14] == 0x00);
            CHECK(result[15] == 0x00);
            CHECK(result[16] == 0x00);
            CHECK(result[17] == 0x00);
            CHECK(result[18] == 0x00);
            CHECK(result[19] == 0x00);
            CHECK(result[20] == 0x00);
            CHECK(result[21] == 0x00);
            CHECK(result[22] == 0x00);
            CHECK(result[23] == 0x00);
            CHECK(result[24] == 0x00);
            CHECK(result[25] == 0x00);
            CHECK(result[26] == 0x00);
            CHECK(result[27] == 0x00);
            CHECK(result[28] == 0x00);
            CHECK(result[29] == 0x00);
            CHECK(result[30] == 0x00);
            CHECK(result[31] == 0x00);
            CHECK(result[32] == 0x00);
            CHECK(result[33] == 0x00);
            CHECK(result[34] == 0x00);
            CHECK(result[35] == 0x00);
            CHECK(result[36] == 0x00);
            CHECK(result[37] == 0x00);
            CHECK(result[38] == 0x00);
            CHECK(result[39] == 0x00);
            CHECK(result[40] == 0x00);
            CHECK(result[41] == 0x00);
            CHECK(result[42] == 0x00);
            CHECK(result[43] == 0x00);
            CHECK(result[44] == 0x00);
            CHECK(result[45] == 0x00);
            CHECK(result[46] == 0x00);
            CHECK(result[47] == 0x00);
            CHECK(result[48] == 0x00);
            CHECK(result[49] == 0x00);
            CHECK(result[50] == 0x00);
            CHECK(result[51] == 0x00);
            CHECK(result[52] == 0x00);
            CHECK(result[53] == 0x00);
            CHECK(result[54] == 0x00);
            CHECK(result[55] == 0x00);
            CHECK(result[56] == 0x00);
            CHECK(result[57] == 0x00);
            CHECK(result[58] == 0x00);
            CHECK(result[59] == 0x00);
            CHECK(result[60] == 0x00);
            CHECK(result[61] == 0x00);
            CHECK(result[62] == 0x00);
            CHECK(result[63] == 0x00);
            CHECK(result[64] == 0xFE);
            CHECK(result[65] == 0xFF);
            CHECK(result[66] == 0xFF);
            CHECK(result[67] == 0xFF);
            CHECK(result[68] == 0xFF);
            CHECK(result[69] == 0xFF);
            CHECK(result[70] == 0xFF);
            CHECK(result[71] == 0xFF);
            CHECK(result[72] == 0xFF);
            CHECK(result[73] == 0xFF);
            CHECK(result[74] == 0xFF);
            CHECK(result[75] == 0xFF);
            CHECK(result[76] == 0xFF);
            CHECK(result[77] == 0xFF);
            CHECK(result[78] == 0xFF);
            CHECK(result[79] == 0xFF);
            CHECK(result[80] == 0xFF);
            CHECK(result[81] == 0xFF);
            CHECK(result[82] == 0xFF);
            CHECK(result[83] == 0xFF);
            CHECK(result[84] == 0xFF);
            CHECK(result[85] == 0xFF);
            CHECK(result[86] == 0xFF);
            CHECK(result[87] == 0xFF);
            CHECK(result[88] == 0xFF);
            CHECK(result[89] == 0xFF);
            CHECK(result[90] == 0xFF);
            CHECK(result[91] == 0xFF);
            CHECK(result[92] == 0xFF);
            CHECK(result[93] == 0xFF);
            CHECK(result[94] == 0xFF);
            CHECK(result[95] == 0xFF);
            CHECK(result[96] == 0xFF);
            CHECK(result[97] == 0xFF);
            CHECK(result[98] == 0xFF);
            CHECK(result[99] == 0xFF);
            CHECK(result[100] == 0xFF);
            CHECK(result[101] == 0xFF);
            CHECK(result[102] == 0xFF);
            CHECK(result[103] == 0xFF);
            CHECK(result[104] == 0xFF);
            CHECK(result[105] == 0xFF);
            CHECK(result[106] == 0xFF);
            CHECK(result[107] == 0xFF);
            CHECK(result[108] == 0xFF);
            CHECK(result[109] == 0xFF);
            CHECK(result[110] == 0xFF);
            CHECK(result[111] == 0xFF);
            CHECK(result[112] == 0xFF);
            CHECK(result[113] == 0xFF);
            CHECK(result[114] == 0xFF);
            CHECK(result[115] == 0xFF);
            CHECK(result[116] == 0xFF);
            CHECK(result[117] == 0xFF);
            CHECK(result[118] == 0xFF);
            CHECK(result[119] == 0xFF);
            CHECK(result[120] == 0xFF);
            CHECK(result[121] == 0xFF);
            CHECK(result[122] == 0xFF);
            CHECK(result[123] == 0xFF);
            CHECK(result[124] == 0xFF);
            CHECK(result[125] == 0xFF);
            CHECK(result[126] == 0xFF);
            CHECK(result[127] == 0xFF);
        }
        {
            array::dynamic_t<u16_t> buffer;
            
            array::stack_t<u16_t, 2> number_a = {
                u16_t(0xFFFF),
                u16_t(0x00FF)
            };
            array::stack_t<u16_t, 2> number_b = {
                u16_t(0xFFFF),
                u16_t(0x00FF)
            };
            array::stack_t<u16_t, 4> result;
            Multiply<u16_t>(number_a, number_b, result, buffer).Ignore_Error();
            CHECK(result.Count() == 3);
            CHECK(result[0] == 0x0001);
            CHECK(result[1] == 0xFE00);
            CHECK(result[2] == 0xFFFF);
        }
        {
            array::stack_t<u8_t, 8> number_a = {
                u8_t(0xbe),
                u8_t(0x40),
                u8_t(0xc2),
                u8_t(0xed),
                u8_t(0x5d),
                u8_t(0xd9),
                u8_t(0x7b),
                u8_t(0xbd)
            };
            array::stack_t<u8_t, 8> number_b = {
                u8_t(0x74),
                u8_t(0x6b),
                u8_t(0x8a),
                u8_t(0xc9),
                u8_t(0xac),
                u8_t(0xca),
                u8_t(0x3b),
                u8_t(0x24)
            };
            array::stack_t<u8_t, 16> result;
            Multiply<u8_t>(number_a, number_b, result, buffer).Ignore_Error();
            CHECK(result.Count() == 16);
            CHECK(result[0] == 0x18);
            CHECK(result[1] == 0xc0);
            CHECK(result[2] == 0x80);
            CHECK(result[3] == 0x01);
            CHECK(result[4] == 0x24);
            CHECK(result[5] == 0xdc);
            CHECK(result[6] == 0xab);
            CHECK(result[7] == 0x35);
            CHECK(result[8] == 0x8d);
            CHECK(result[9] == 0xf7);
            CHECK(result[10] == 0xfb);
            CHECK(result[11] == 0xeb);
            CHECK(result[12] == 0x1f);
            CHECK(result[13] == 0xac);
            CHECK(result[14] == 0xd1);
            CHECK(result[15] == 0x1a);
        }
        {
            array::stack_t<u8_t, 8> number_a = {
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF)
            };
            array::stack_t<u8_t, 1> number_b = {
                u8_t(0x01)
            };
            array::stack_t<u8_t, 16> result;
            Multiply<u8_t>(number_a, number_b, result, buffer).Ignore_Error();
            CHECK(result.Count() == 8);
            CHECK(result[0] == 0xFF);
            CHECK(result[1] == 0xFF);
            CHECK(result[2] == 0xFF);
            CHECK(result[3] == 0xFF);
            CHECK(result[4] == 0xFF);
            CHECK(result[5] == 0xFF);
            CHECK(result[6] == 0xFF);
            CHECK(result[7] == 0xFF);
        }
        {
            array::stack_t<u8_t, 8> number_a = {
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF)
            };
            array::stack_t<u8_t, 1> number_b = {
                u8_t(0x02)
            };
            array::stack_t<u8_t, 16> result;
            Multiply<u8_t>(number_a, number_b, result, buffer).Ignore_Error();
            CHECK(result.Count() == 9);
            CHECK(result[0] == 0xFE);
            CHECK(result[1] == 0xFF);
            CHECK(result[2] == 0xFF);
            CHECK(result[3] == 0xFF);
            CHECK(result[4] == 0xFF);
            CHECK(result[5] == 0xFF);
            CHECK(result[6] == 0xFF);
            CHECK(result[7] == 0xFF);
            CHECK(result[8] == 0x01);
        }
        {
            array::stack_t<u8_t, 1> number_a = {
                u8_t(0x02)
            };
            array::stack_t<u8_t, 4> number_b = {
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF)
            };
            array::stack_t<u8_t, 8> result;
            Multiply<u8_t>(number_a, number_b, result, buffer).Ignore_Error();
            CHECK(result.Count() == 5);
            CHECK(result[0] == 0xFE);
            CHECK(result[1] == 0xFF);
            CHECK(result[2] == 0xFF);
            CHECK(result[3] == 0xFF);
            CHECK(result[4] == 0x01);
        }
    }

}}
