/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

// nkr::t
/**
* @class _13d670d2_5498_4b84_9648_94b1cd8f2c89
* @private
*
* @brief
*   A way to wrap a single type for use with an nkr::TR expression, to differentiate it from a template.
*/

// nkr::ts
/**
* @class _65d1963a_c1d4_4110_a6bb_a52a9e9150fe
* @private
*
* @brief
*   A way to parenthesize and perform logical operations on several types in an nkr::TR expression.
*/

// nkr::tt
/**
* @class _24a5dd1f_5bfc_4cc2_a831_302413bf8087
* @private
*
* @brief
*   A way to wrap a single template for use with an nkr::TR expression, to differentiate it from a type.
*/

// nkr::tts
/**
* @class _7d64d462_bbf9_452a_9d76_322daed0989e
* @private
*
* @brief
*   A way to parenthesize and perform logical operations on several templates in an nkr::TR expression.
*/

// nkr::TR
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
* @par Grammatical Parts
*   A full nkr::TR expression is made of two component parts, the `subject`, and an arbitrary number of `operators` paired with an `operand`:
*   @snippet "./tr/src/tr.cpp" _19a3f5b7_c3aa_4e86_bb68_1cfd8c306cda
*   In the above example we statically asserted that `int` is `any` `int`. This time without comments:
*   @snippet "./tr/src/tr.cpp" _008550d1_21e3_4bae_8844_b85ca680e16a
*
* @par Type Wrappers
*   A single type is wrapped with an nkr::t, or `type`. This syntactical addition to a nkr::TR expression allows for two powerful distinctions to occur, both of which we will learn in more detail below.
*
* @par Implicit Operands
*   It is possible to use just a `subject` and an `operator` without using an `operand`. This trivial example will always return `true` because `any` `subject` will always be `any` `subject`:
*   @snippet "./tr/src/tr.cpp" _236e3aa6_fd72_446d_ad8e_10d3afce07a3
*
* @par Any Qualification Operators
*   The above example may be trivial, but implicit operands become critical for operators besides `any_tg`. How else would we constrain a subject to a qualification regardless of type?:
*   @snippet "./tr/src/tr.cpp" _6d5532ca_8399_4a97_9e58_60e7bf7f7eb2
*   And by including an operand, you can constrain a subject to qualification as well as type:
*   @snippet "./tr/src/tr.cpp" _655eeb36_08b4_4a4c_bd0c_e36f89db9736
*   The reason why these are `any` operators is that `any_const_tg` will work with a volatile type as long as it's also const, and the `any_volatile_tg` with a const type, as long as it's also volatile:
*   @snippet "./tr/src/tr.cpp" _24f822e7_6c8f_4ce5_8ecc_f8b142a8f635
*   Likewise, `any_qualified_tg` merely requires that a type have any qualification:
*   @snippet "./tr/src/tr.cpp" _b760cc4f_cd3c_49e7_b19d_ebecb0c444fc
*   And inversely, the `any_non_qualified_tg` will only allow types without qualification:
*   @snippet "./tr/src/tr.cpp" _2db89416_6998_4dcb_91d1_4ff326956702
*   Yet more variants exist, such as `any_non_const_tg` and `any_non_volatile_tg` to help you explictly declare not only how to constrain the subjects of your nkr::TR expressions, but quite literally to declare the intent of your constraint in reasonably plain English.
*
* @par Just Qualification Operators
*   It is sometimes convenient to constrain to the **exact** qualification of an operand. The `just_tg` does just that:
*   @snippet "./tr/src/tr.cpp" _c5229a18_0f89_4919_b18f_2a87a5c6ded5
*   There are several variants of the `just_tg` that allow for exactitude through use of the operator, as opposed to the operand:
*   @snippet "./tr/src/tr.cpp" _d43e49fd_9953_4e45_b787_da4dd4be0018
*   Notice how the operand's qualification is completely respected with `just_tg` but entirely ignored for any of the variant operators:
*   @snippet "./tr/src/tr.cpp" _3a337d2c_afd1_4cf0_abb9_f7565d351f84
*   At first, this may seem strange, but these operators are defined this way so that it is easy to avoid any errors that could result from using an alias hiding a qualification:
*   @snippet "./tr/src/tr.cpp" _4f3d5c98_22ec_4d5a_bf75_08462f1be395
*   Whereas the `just_tg` allows for the standard combination of qualifications, even with the hidden qualification of an alias:
*   @snippet "./tr/src/tr.cpp" _17ac0ffa_ab9b_4e98_a3ff_91f45a911c09
*
* @par Pointer, Array, and Reference Operands
*   It's actually possible to test for compound built-in C++ types too:
*   @snippet "./tr/src/tr.cpp" _de9f97b4_db90_42bf_b9b9_f2166a5d4fcb
*   Notice how qualification is respected for the whole type in the following examples. We use the `just_tg` for the sake of simplicity:
*   @snippet "./tr/src/tr.cpp" _19915f22_ec07_4242_99e1_43cc4599420c
*
* @par Template Operands
*   It is also possible to use templates. Here we simply constrain to an instantiated nkr::pointer::cpp_t, which will result in `true` because nkr::pointer::cpp_t<int> is an alias of `int*`:
*   @snippet "./tr/src/tr.cpp" _371738b1_f8c5_4ebf_b8e4_a7bd23e4ab44
*   Often it is useful to separate the template from its `inner type` which would be `int` in this case. This allows for more flexible expressions that make use of more than just the `any_tg` operator. Here we are asserting the same as above, that `int*` is `any` nkr::pointer::cpp_t `of any` `int`:
*   @snippet "./tr/src/tr.cpp" _f06311f0_df34_4df8_af3b_4753b1c4d6b1
*
* @par Tag Operands
*   Alternatively we can use a `ttg`, that is a `template tag` of nkr::pointer::cpp_t to achieve the same result:
*   @snippet "./tr/src/tr.cpp" _59ddfa80_4281_4c2c_9838_d215d7528058
*   The use of `tags` can bring even more flexibility to an expression. For example, most templates provide a `tag` to test if a type is instantiated from it, regardless of the subject's actual `inner type`. Below we simply assert that the `subject` needs to be instantiated from `any` nkr::pointer::cpp_t by use of its `tg` or `type tag`:
*   @snippet "./tr/src/tr.cpp" _b0d595d6_4012_4b2b_89ac_3a861aca7af7
*   Note the symetrical use of `tt` with `ttg` to constrain a `template tag` and `t` with `tg` to constrain a `type tag`.
*
* @par Type Wrappers and Template Wrappers
*   Types are wrapped with nkr::t or nkr::ts, that is `type` or `types` respectively. This syntactical feature differentiates between using a singluar type or multiple types in a subject or operand. It also differentiates between using types or templates as an operand. To use templates as an operand you would use nkr::tt or nkr::tts, that is 'template type' or 'template types' respectively. It is necessary to wrap the templates this way for the sake of arbitrary length expressions, which cannot be made up of both types and templates but only one or the other.
*
* @par Generic Operands
*   `Tags` become absolutely critical when we start to introduce `generics` into our expressions.
*
* @par Arbitrary Length
*   Arbitrary length expressions allow for the constraint of templates of templates of templates, ..., of templates of types. Here we have an intentionally complex example:
*   @snippet "./tr/src/tr.cpp" _15b00d3d_2838_4308_a2ce_77071393e5d5
*   However it is possible to find real-world examples of two or even three operands in use with an nkr::TR expression throughout the library, with various templates and types coming into play. A classic C++ example would be an lvalue reference to a pointer which one might pass to a function for initialization:
*   @snippet "./tr/src/tr.cpp" _1374a6bc_a3e9_4663_90d7_45bf338a9077
*   In this case our function would not care what the pointer is pointing to, or that its `inner type` is `const`. It only cares that it is a reference to a pointer that is `non_const`, else it wouldn't be able to set it. It doesn't actualy care if the pointer is `volatile` or not because its functionality remains the same in that event.
*
* @par Target Operand
*   Finally, because the subject of nkr::TR must always be a type and not a template, so too must the last operand be a type and not a template, even if that type is a `type tag` representing a template.
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

// nkr::tr
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
