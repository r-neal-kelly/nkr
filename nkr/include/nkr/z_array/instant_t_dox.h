/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

/////////////////////////////////////////////////////////////////////////////// Docs
// instant_t
/**
* @class _44cf13e6_2d45_4363_82c4_c613d648f6b0
* @private
*
* @brief
*   Essentially the same as a nkr::array::stack_t, except that it allows you initialize the array without defining the capacity.
*
* @details
*   Simply for ease of use, you can define an instant array with an initializer list of units up front, thus avoiding the need to define an exact capacity that may not be set in stone in your code base. You will find that other types of arrays, such as nkr::array::dynamic_t accept an instant_array among their constructors such that you can use them as an initializer list without the added constness.
*
*   Please see nkr::array::stack_t for more information.
*
*   This type satisfies nkr::array_i, and like all arrays that satisfy the array interface, nkr::array::instant_t can interoperate with other arrays. Comes with pre-defined traits by use of nkr_DEFINE_CONTAINER_TRAITS, such as nkr::array::any_instant_tr.
*/
