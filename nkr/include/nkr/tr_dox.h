/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

// TR
/**
* @class _6dffcf53_72e8_40f7_9f3a_5b6b515aed1d
* @private
*
* @brief
*   Used to filter a type by other types, templates, identities, and generics.
*
* @details
*   An integral function for the entire library. Any type or template that satisfies the nkr::interface::type_i or nkr::interface::template_i respectively can be used in conjunction with pre-defined operators to form an expression for use with this function. Input a group of subjects in addition to your arbitrary-length expression, and a compile-time or runtime boolean will be output indicating whether or not the subjects satisfy the expression.
*
* The primary rationale for the existence of this function is to prevent the need of defining and redefining the same concepts over and over again with only minor variations. It keeps the focus on your static tests, and more importantly when using nkr::tr, it keeps the focus on the signature of your types and functions, and what kind of types are acceptable inputs for their parameters.
*
*/

// tr
/**
* @class _fbaf0b62_578a_48b1_b4e2_43ad69c9980c
* @private
* 
* @brief
*   Used to filter a type by other types, templates, identities, and generics in the context of a declaration.
*
* @details
*   Distinct from the nkr::TR function, nkr::tr is a concept that can be used in the context of type and function declarations where only one subject is implicitly allowed for constraint. In the library proper, it is far more common to see this concept in use as compared to the underlying function, which is more prevalent in static_asserts such as are found in the numerous test suites for nkr.
*
*   For more details about what nkr::tr and its underlying function are capable of, please see nkr::TR.
*
* @note
*   The most frequent use of this concept is found in method declarations which need to handle both volatile and non-volatile qualifications of variable types. What would otherwise have to be two or more functions can now be defined as one with these dynamically generated concepts produced by nkr::tr and the underlying nkr::TR function.
* 
*/
