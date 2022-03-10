/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

// modules
/**
    @defgroup _c8774f4a_9a1a_4339_9147_4d0ded6c301f identities

    @brief
    A list of all available [identities](@ref _fd6e7324_a83c_4317_a5a8_9edfabfa7fce) in the library.
*/

// nkr
/**
* @class _54e0fcc6_0af9_4a88_b5fd_830d997bb327
* @private
*
* @brief
*   The entire library is contained within this namespace.
*
* @details
*   The three letters `nkr` make up my initials. Inspiried by Sean T. Barrett's [stb](https://github.com/nothings/stb) library, I named this library after myself for two reasons:
*       1. The initials should prevent most name collisions when you include any of this library's headers.
*       2. I have staked my name and thus reputation on the line with this library. I intend for it to be useful in the decades to come.
*/

    // nkr::allocator
    /**
    * @class _a8073c93_ca63_430e_8b38_9b949a7ed4e3
    * @private
    *
    * @brief
    *   Allocator types are used by other types to allocate and deallocate various kinds of memory.
    *
    * @details
    *   Unlike traditional C programming, allocator types by definition of nkr::generic::allocator_tr only have two functions, `Allocate` and `Deallocate`. The prior is the only function that actually needs to be used, because it's similar to C's `realloc` in that it will allocate, reallocate, and deallocate based on its arguments. Furthermore, allocators come in two varieties, `shared` and `owned`. The `shared` allocators have static methods whereas `owned` allocators have non-static methods.
    *
    */

    // nkr::array
    /**
    * @class _2fce3cde_8ffb_4822_936a_be081bd1ad02
    * @private
    *
    * @brief
    *   Array types are used to represent multiple values of the same type in various ways and locations.
    *
    * @details
    *   Each array has at least two prominent qualitative dimensions: `local` to `remote`, and `static` to `dynamic`. The `static` arrays can not grow in size whereas `dynamic` arrays can both increase and decrease their `capacity`. The `local` arrays store their `units` within themselves such as on the stack, in the read section, or even on the heap, whereas a `remote` array only ever stores its `units` in an external location, wherever that may be.
    *
    *   Arrays are one of the most fundamental types for all of programming and thus boast an impressive amount of diversity both in quality and use-case. With these divergent qualities comes explicit control over how your data will behave.
    *
    * @par
    * @note
    *   These dimensions extend to other types that make heavy use of arrays internally, such as strings.
    *
    */

    // nkr::boolean
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

    // nkr::charcoder
    /**
    * @class _6b8b733b_0edd_4cfd_9236_554f9cb83b1d
    * @private
    *
    * @brief
    *   Charcoder types are used to represent and work with specific character encodings.
    *
    * @details
    *   Charcoders are the primary mechanism used to abstract the differences between the majority of encodings that can be used to represent characters and groups of characters, i.e. strings.
    *
    */

    // nkr::concurrency
    /**
    * @class _8c8acd09_c2f8_4d13_86fc_f5518577f811
    * @private
    *
    * @brief
    *   Concurrency types are used to make other types work in a concurrent or parallel context.
    *
    * @details
    *   Most modern computers come with more than one CPU core, making it possible to compute more than one thing at the same exact time. This namespace contains types that allow you to take advantage of the available CPU cores in a controlled manner, so that shared data will not be clobbered and so synchronization, i.e. the timing of pre and post concurrency execution, can properly occur.
    *
    * @par
    * @note
    *   Concurrency is analogous to using your right hand to perform one task while simultaneously using your left hand to perform another. There are different types of concurrency, and in particular there are two primary way to do it. I encourage you to always consider each before adopting concurrency into your code:
    *       1. Sometimes you have totally different tasks for each hand to do, and they may not take the same amount of time - thus when one hand finishes a job it is free to begin another while the other hand is still working on the first. This gives each hand the opportunity to always be doing something instead of having to wait on each other.
    *       2. Other times you may have a single job that you can break into parts, or multiple instances of the same job. Because they should each take about the same amount of time to complete you can coordinate both hands to start and finish each task at the same time. This parallel behavior is an efficient way to plan multiple batches, in this case batches of two jobs at a time, one batch after another.
    *
    */

    // nkr::constant
    /**
    * @class _95f550fe_1655_497f_b4d5_2c7adde2566f
    * @private
    *
    * @brief
    *   Constant types are used to represent values that cannot be changed.
    *
    * @details
    *   The primary use of a constant type is for template type parameters. It's true that a literal type can directly be used in a template parameter list, but this interferes with template parameter packs and their use as a means to achieve genericism in the library. In other words, constant types can be used to fulfill the principle of **one kind of template parameter**.
    *
    * @par
    * @note
    *   Constant types are similar to the standard C++ [std::integral_constant](https://en.cppreference.com/w/cpp/types/integral_constant).
    */

    // nkr::cpp
    /**
    * @class _9127b7bb_d45b_42ab_b26f_e8959e0fced0
    * @private
    *
    * @brief
    *   CPP types are standard C++ types that can be used like other @ref nkr types.
    *
    * @details
    *   This namespace contains a wealth of examples pertaining to how types can be interfaced with @ref nkr. These aliases and interface implementations allow supported standard C++ types to natively be usable in nkr::tr expressions. Like nkr::os, nkr::cpp is cordoned off from the rest of the library and treated as foreign code.
    */

    // nkr::enumeration
    /**
    * @class _c6a3763a_283e_4a37_ad1c_0d3804479382
    * @private
    *
    * @brief
    *   Enumeration types provide abstractions over the basic C and C++ enums, making them fully usable types.
    *
    * @details
    *   Unlike the standard `enum` and `enum class`, @ref nkr enumeration types provide the full benefits of classes, such as operator overloads and a full suite of constructors and assigners to carry a value. They are also inheritable so that multiple `enum` lists can be composed. Conversion operators are also fully definable, allowing you to change how your specific enumeration will behave when set with variables. Anything limiting about `enum` and `enum class` does not apply to an @ref nkr enumeration type.
    */

    // nkr::error
    /**
    * @class _7c03d996_023c_4733_b350_769f6a1fb26d
    * @private
    *
    * @brief
    *   Error types provide an abstraction over enumerations representing runtime recoverable errors.
    *
    * @details
    *   @ref nkr makes use of various error types where both a runtime problem can occur and it is desirable for your program to be able to recover from it, e.g. running out of main memory. For the most part they inherit from nkr::enumeration::errors_t. Error types **do not** represent a frivolous problem-set of programmer errors, most of which can be detailed to the developer by other more efficient means, usually during compile time. Error types **do** represent problems that can occur during runtime, such as dynamically registering a user-error for further processing.
    */

    // nkr::negatable
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

    // nkr::none
    /**
    * @class _ae416188_7c4b_42b5_8a3d_05060328e8cb
    * @private
    *
    * @brief
    *   None types are used to represent the concept of nothing.
    *
    * @details
    *   C++ actually comes with a couple of built in none types, one called`void` to represent the lack of a type, which is aliased as nkr::none::type_t, and two `std::nullptr_t` which represents the lack of a pointer, which is aliased as nkr::none::pointer_t. @ref nkr comes with more none types, in particular the nkr::none::value_t which represents the lack of a value.
    *
    */

    // nkr::os
    /**
    * @class _4a9c8771_0d04_4b92_a7cf_ce5119a5f7d4
    * @private
    *
    * @brief
    *   OS contains functionality supplied through a thin abstraction over the underlying operating system.
    *
    * @details
    *   This namespace provides low-level functionality that is either not provided through standard C++ and nkr::cpp or can be provided through a better abstraction here. nkr::os creates a ilghtweight abstraction on top of the operating system and provides as little functionality as possible, in order to remain abstract. To keep @ref nkr as portable as possible, nkr::os is cordoned off from the rest of the library and treated as foreign code. Where possible, functionality that is not directly supplied by the underlying operating system may be simulated in order to maintain the abstractions provided by @ref nkr.
    */

    // nkr::positive
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
