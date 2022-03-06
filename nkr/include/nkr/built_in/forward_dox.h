/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

// namespace nkr
/**
* @class _54e0fcc6_0af9_4a88_b5fd_830d997bb327
* @private
* 
* @brief
*   The entire library is contained within this namespace.
*
* @details
*   The three letters `nkr` make up my initials. Inspiried by Sean T. Barrett's [stb](https://github.com/nothings/stb) library for C, I named this C++ library of mine after myself for two reasons:
*       1. The initials should prevent most name collisions when you include any of this library's headers.
*       2. I have staked my name and thus reputation on the line with this library. I intend for it to be useful in the decades to come.
*/

// namespace nkr::boolean
/**
* @class _9730e15e_a0a8_4b22_b55b_771a4ea09486
* @private
*
* @brief
*   Boolean types are used to represent one of two values, and never any more than two.
*
* @details
*   Although C++ comes with only one boolean type to represent `true` and `false`, this library provides more.
*
*/

// namespace nkr::negatable
/**
* @class _f94a7a61_bc8b_467c_ad48_177ebf2a6288
* @private
*
* @brief
*   Negatable types are used to represent numbers that can be negated, i.e. set to a negative number.
*
* @details
*   The name "negatable" was chosen for two reasons:
*       1. "Negatable" actually makes more sense. A "sign" is just a mathematical symbol, such a `x` for multiplication and `+` for addition. Just because a number is "signed" does not mean it is negatable, e.g. `+1` simply means "positive 1" in a mathematical context. (In a C++ context, it is the operator to promote an integer type.) So the word "negatable" was chosen because it is obvious what you intend it to be capable of.
*       2. `signed` is a C++ reserved word and cannot be used as a namespace name.
*
* @par
* @note
*   Compare to nkr::positive.
*
*/

// namespace nkr::none
/**
* @class _ae416188_7c4b_42b5_8a3d_05060328e8cb
* @private
*
* @brief
*   None types are used to represent the concept of nothing.
*
* @details
*   C++ actually comes with a couple of built in none types, one called`void` to represent the lack of a type, which is aliased as nkr::none::type_t, and two `std::nullptr_t` which represents the lack of a pointer, which is aliased as nkr::none::pointer_t. nkr comes with more none types, in particular the nkr::none::value_t which represents the lack of a value.
*
*/

// namespace nkr::positive
/**
* @class _e03a80e9_3550_4f45_94b2_afe505b344f1
* @private
*
* @brief
*   Positive types are used to represent numbers that are only ever positive and cannot be negated.
*
* @details
*   The name "positive" was chosen for two reasons:
*       1. The word "positive" is extremely clear and straightforward. It can not be mistaken that this number is only ever going to be positive.
*       2. `unsigned` is a C++ reserved word and cannot be used as a namespace name.
*
* @par
* @note
*   Compare to nkr::negatable.
*/
