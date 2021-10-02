/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

// stack_t<unit_p, capacity_p>
/**
* @class _eea2eeb3_2ca8_4bbf_bdd0_0eca56b1ebae
* @private
* 
* @brief
*   Allocates an array on the stack with many helper functions.
* 
* @details
*   Wraps a standard C array into a wrapper that satisfies nkr::array_i. Like all arrays that satisfy nkr::array_i, nkr::array::stack_t can interoperate with other arrays. Comes with pre-defined traits by use of nkr_DEFINE_CONTAINER_TRAITS, such as nkr::array::any_stack_tr.
*/
