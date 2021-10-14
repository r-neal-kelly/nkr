﻿/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "nkr/string_itr.h"
#include "nkr/string/dynamic_t.h"

#include "doctest.h"

namespace nkr {

    TEST_CASE("temp")
    {
        string::dynamic_t<charcoder::utf_8_t> string(u8"neal.νηαλ.נהאל.ነሐአለ.𐌍𐌄𐌀𐌋");

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
    }

}