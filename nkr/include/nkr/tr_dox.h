/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

// ts
/**
* @class _65d1963a_c1d4_4110_a6bb_a52a9e9150fe
* @private
*
* @brief
*   A way to parenthesize and perform logical operations on several types in an nkr::TR expression.
*/

// tts
/**
* @class _7d64d462_bbf9_452a_9d76_322daed0989e
* @private
*
* @brief
*   A way to parenthesize and perform logical operations on several templates in an nkr::TR expression.
*/

// TR
/**
* @class _6dffcf53_72e8_40f7_9f3a_5b6b515aed1d
* @private
*
* @brief
*   Used to filter a type by its qualifications, and by other types, templates, identities, and generics.
*
* @details
*   An integral function for the entire library. Any type or template that satisfies the nkr::interface::type_i or nkr::interface::template_i respectively can be used in conjunction with pre-defined operators to form an expression for use with this function. Input a group of subjects in addition to your arbitrary-length expression, and a compile-time or runtime boolean will be output indicating whether or not the subjects satisfy the expression.
*
* @par Purpose
*   The primary rationale for the existence of this function is to prevent the need of defining and redefining the same concepts over and over again with only minor variations. It keeps the focus on your static tests, and more importantly when using nkr::tr, it keeps the focus on the signature of your types and functions, and what kind of types are acceptable inputs for their parameters.
*
* @par Using Multiple Types as an Operand
*   Naturally there are times when using more than one type as a single operand in an nkr::TR expression is desirable. Sometimes one may wish to constrain to several operands parenthetically, to be evaluated by a logical operator. That's where nkr::ts comes in.
*
* @par
*   Here we constrain to either type in the operand, with use of the nkr::OR_tg:
*   @snippet "./tr/src/tr.cpp" _2e80ad9f_7fa0_4d4f_ba2c_7f56d92659d3
*   To both generics in the operand, with use of the nkr::AND_tg:
*   @snippet "./tr/src/tr.cpp" _898208a2_8cc9_48cb_a4b5_c7bdada49152
*   To just one generic in the operand, with use of the nkr::XOR_tg:
*   @snippet "./tr/src/tr.cpp" _ea052059_b418_4201_9690_5166d46ff670
*
* @par Using Multiple Types as a Subject
*   You can also use nkr::ts for multiple subjects. Here we've built an entire set of truth tables where each subject is tested against the singular operand. Notice how the complement for each of the above operators is also in play here, namely nkr::NOR_tg, nkr::NAND_tg, and nkr::XNOR_tg:
*   @snippet "./tr/src/tr.cpp" _01233b5b_1059_4d1d_a06b_50643a3f30eb
*
* @par Using Multiple Templates as an Operand
*   Because the syntax of the C++ language demands it, we
*
*/

// tr
/**
* @class _fbaf0b62_578a_48b1_b4e2_43ad69c9980c
* @private
* 
* @brief
*   Used to filter a type by its qualifications, and by other types, templates, identities, and generics in the context of a declaration.
*
* @details
*   Distinct from the nkr::TR function, nkr::tr is a concept that can be used in the context of type and function declarations where only one subject is implicitly allowed for constraint. In the library proper, it is far more common to see this concept in use as compared to the underlying function, which is more prevalent in static_asserts such as are found in the numerous test suites for nkr.
*
* @par
* @note
*   For more details about what nkr::tr and its underlying function are capable of, please see nkr::TR.
*
* @par
* @note
*   Syntactically, nkr::tr is one of a handful of unique traits in the library that doesn't have the `tr` postfix. Instead it is simply named as such to strongly indicate that all other traits can be combined by use of this one.
*
* @par
* @note
*   The most frequent use of this concept is found in method declarations which need to handle both volatile and non-volatile qualifications of variable types. What would otherwise have to be two or more functions can now be defined as one with these dynamically generated concepts produced by nkr::tr and the underlying nkr::TR function.
* 
*/
