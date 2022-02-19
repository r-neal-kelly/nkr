/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

/////////////////////////////////////////////////////////////////////////////// Shared Details
/**
* @class _68c297e4_e2e3_4002_a52f_29edf775aa83
* @private
* 
* @details
*   In addition to working directly with C pointers, in order to satisfy the nkr::allocator_i this also handles nkr::pointer_t objects, correctly setting their unit counts after operating upon them. The primary purpose of this type and others like it is to provide an interchangable set of allocators with which to use with other types around the library, for example nkr::array::dynamic_t.
*/


/////////////////////////////////////////////////////////////////////////////// Docs
// namespace nkr::allocator
/**
* @class _627e5174_65ef_4aee_bb2a_034d9715cb0d
* @private
* 
* @brief
*   Contains allocators that satisfy nkr::allocator_i, making them interchangably useful anywhere that accepts the allocator interface.
*/

// allocator_i
/**
* @class _5fe34260_b2c5_442b_aa23_44ddb41cb7b6
* @private
* 
* @brief
*   Defines common functionality that must exist on an allocator implementation for use in nkr.
* 
* @details
*   Allocator types may either be of a static variety, such as nkr::allocator::heap_t and nkr::allocator::heap_zeros_t, or they may contain their own state such they are their own memory pool for use as a customized global allocator or even as a private arena shared between a group of functions. With such options, you can even make a custom allocator that allocates directly from the stack, and you'll be able to use any type that accepts an allocator in its interface, such as nkr::array::dynamic_t.
*/
