/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

// t
/**
* @class _13d670d2_5498_4b84_9648_94b1cd8f2c89
* @private
*
* @brief
*   A way to wrap a single type for use with an nkr::TR expression, to differentiate it from a template.
*/

// ts
/**
* @class _65d1963a_c1d4_4110_a6bb_a52a9e9150fe
* @private
*
* @brief
*   A way to parenthesize and perform logical operations on several types in an nkr::TR expression.
*/

// tt
/**
* @class _24a5dd1f_5bfc_4cc2_a831_302413bf8087
* @private
*
* @brief
*   A way to wrap a single template for use with an nkr::TR expression, to differentiate it from a type.
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
* @par Grammar Parts
*   A full nkr::TR expression is made of two component parts, the `subject`, and an arbitrary number of `operators` paired with an `operand`:
*   @snippet "./tr/src/tr.cpp" _19a3f5b7_c3aa_4e86_bb68_1cfd8c306cda
*   In the above example we statically asserted that `int` is `any` `int`. Again, but without the comments:
*   @snippet "./tr/src/tr.cpp" _008550d1_21e3_4bae_8844_b85ca680e16a
*   It is possible to use just a `subject` and an `operator`. In the following example we are asserting the subject is `any` subject:
*   @snippet "./tr/src/tr.cpp" _236e3aa6_fd72_446d_ad8e_10d3afce07a3
*   And it is also possible to use templates when working with multiple pairs of `operators` and `operands`. Here we are asserting that `int*` is `any` nkr::pointer::cpp_t `of any` `int`. This will result in `true` because nkr::pointer::cpp_t<int> is an alias for `int*`:
*   @snippet "./tr/src/tr.cpp" _f06311f0_df34_4df8_af3b_4753b1c4d6b1
*   Alternatively, we can use a `tg`, that is a `tag` of nkr::pointer::cpp_t to achieve the same result:
*   @snippet "./tr/src/tr.cpp" _59ddfa80_4281_4c2c_9838_d215d7528058
*   Like nkr::pointer::cpp_t whose `tag` is used in the above example, many templates provide the means to test any type directly belonging to it, regardless of the subject's actual `inner type`. Below we are simply asserting that the subject is `any` nkr::pointer::cpp_t:
*   @snippet "./tr/src/tr.cpp" _b0d595d6_4012_4b2b_89ac_3a861aca7af7
*   Note the use of the `ttg` postfix to constrain a template of an explicit type and the `tg` postifx to constrain a template of any type, both modifying `nkr:pointer::cpp`. These two `tags` nkr::pointer::cpp_tg and nkr::pointer::cpp_ttg are `identities` of nkr::pointer::cpp_t, respectively the `type indentity tag` and the `template identity tag`. Suffice it to say these grammatical artifices provide the ability to semantically alter an nkr::TR expression as we have shown above.
*
* @par Qualification Operators
*
* @par Arbitrary Length
*
* @par Wrapping Types and Templates
*   You will have noticed that types are wrapped with nkr::t or nkr::ts, that is `type` or `types` respectively. This syntactical feature differentiates between using a singluar type or multiple types in a subject or operand. It also differentiates between using types or templates as an operand. To use templates as an operand you would use nkr::tt or nkr::tts, that is 'template type' or 'template types' respectively.
* @par
*   It is necessary to wrap the templates into a type for the sake of arbitrary length expressions, which cannot be made up of both types and templates but only one or the other.
*
* @par Using Multiple Types as an Operand
*   Naturally there are times when using more than one type as a single operand in an nkr::TR expression is desirable. Sometimes one may wish to constrain to several operands parenthetically, to be evaluated by a logical operator. That's where nkr::ts comes in.
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
*   Following the pattern of postfixes, with `t` for type and `tt` for template of type, we also likewise use nkr::tts instead of nkr::ts to make use of multiple templates in an operand:
    @snippet "./tr/src/tr.cpp" _76decf6a_1e47_43c3_9413_4b9a895b73e3
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
