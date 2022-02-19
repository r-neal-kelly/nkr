/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

/////////////////////////////////////////////////////////////////////////////// Docs
// stack_t
/**
* @class _eea2eeb3_2ca8_4bbf_bdd0_0eca56b1ebae
* @private
* 
* @brief
*   Stores memory in a continguously ungrowable but alterable array of units on the stack.
* 
* @details
*   Arguably the most important data structure of all time, the stack array allows you to easily modify its contents at the cost of not being able to alter its capacity. It's capable of being remarkably efficient when used in a data-oriented manner, because it will avoid the costly cache misses which come with any dynamic array. This type is particularly preferred for smaller arrays that can fit on the stack and aren't needed but for a single or even a handful of stack frames.
* 
*   Unlike the standard C array, which rests at the heart of this type, the stack array offers ready-to-use functionality and feels very similar to the dynamic array which you may be more accustomed to using. It offers several key methods with nearly the same if not the same exact signature you would find on other arrays. Importantly, just like a dynamic array objects are only constructed when they are added to the array, so you can create a stack array with a large capacity but without providing it units up front. You can also remove them in the same ways that you would a dynamic array.
* 
*   The capacity of the stack array is tied directly to its type and thus must be provided before compile time. However, you may find it easier to use the nkr::array::instant_t if you are creating small arrays that you don't want to manually count the units of.
* 
*   This type satisfies nkr::array_i, and like all arrays that satisfy the array interface, nkr::array::stack_t can interoperate with other arrays. Comes with pre-defined traits by use of nkr_DEFINE_CONTAINER_TRAITS, such as nkr::array::any_stack_tr.
*/
