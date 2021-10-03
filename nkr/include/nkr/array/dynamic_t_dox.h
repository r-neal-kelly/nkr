/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

/////////////////////////////////////////////////////////////////////////////// Docs
// dynamic_t
/**
* @class _70413fdc_3017_4341_a1d3_090d577803c8
* @private
* 
* @brief
*   Stores memory in a continguously growable and alterable array of units.
* 
* @details
*   Arguably the most important dynamic data structure of all time, the dynamic array allows you to easily modify its capacity as well as perform other customary functionality, such as adding and removing units with ease. With such ease comes a cost however, and that is in the form of the infamous allocator out of memory error. However every function which can possible run into this error is clearly and explicitly marked as such by the fact that they all return a nkr::maybe_t<allocator_err>.
*
*   This templated array allows you to alter several behaviors, including what memory source it allocates from. As it accepts any allocator that satisfies nkr::allocator_i, you can use publically global or privately local allocators. It stores an instance of the allocator in the footprint of the array, so for global allocators this is trivially small but with local allocators the memory used would be privately all encompassing and thus completely dedicated to the array. (Note: This is still be tested. The standard C++ library implements allocators in this way but I'm not dead set on following in their footsteps. We may end up making the allocator interface only work with global allocators.)
* 
*   The template also allows you to select the grow rate of the array, and because this fraction is completely tied into the type itself and has no dynamic storage, it adds nothing to the footprint of the array and would need a separate instance of the type to be compiled for each different grow rate. It is there if you need it, but the default should almost always suffice.
*
*   Unlike other dynamic arrays such as std::vector, this type will allow you to store const units which can be added to and removed from the array as long as the array itself it not const. When indexed, the units will remain const and unchangable by the accessor. Additionally, all qualifications and their combinations are implemented and ready to use, both for the unit_t and the dynamic_t itself, within reasonable limitations, such as not being able to move const units rather than copying them.
* 
*   It is encouraged that as much as possible you provide your instanced arrays a reasonable capacity up front before adding elements, for the sake of effciency. However it is completely unnecessary in terms of functionality if there is no way to garner that information statically.
* 
*   This type satisfies the nkr::array_i, and like all types that satisfy the array interface, you can copy and move their elements between them using the supplied methods. Comes with pre-defined traits by use of nkr_DEFINE_CONTAINER_TRAITS, such as nkr::array::any_dynamic_tr.
*/







/////////////////////////////////////////////////////////////////////////////// TO BE CLEANED UP

/* NOTES */

/**
* @class _1d59c95c_5324_405d_ac7e_8676f4f25d62
* @private
* 
* @brief
*   Deleting this prevents an unwanted rvalue from being copied.
*/

/**
* @class _d83f90d1_cdf6_43c2_a64f_bdb96e09bfb4
* @private
* 
* @details
*   Although not strictly necessary for this type, because it cannot even be instantiated, we have this here for consistentcy and robustness.
*/

/* CLASS */

// ctor: rvalue stack_t of any unwritable unit_t, const lvalue allocator
/**
* @class _075b7e64_4cb5_4651_b911_2fd1dabeef80
* @private
* 
* @copydoc _1d59c95c_5324_405d_ac7e_8676f4f25d62
*/

// ctor: rvalue stack_t of any unwritable unit_t, rvalue allocator
/**
* @class _d8def8ae_7b56_41a9_8494_b96bbb13c5b9
* @private
* 
* @copydoc _1d59c95c_5324_405d_ac7e_8676f4f25d62
*/

// ctor: rvalue instant_t of any unwritable unit_t, const lvalue allocator
/**
* @class _965c239c_d5ec_4d39_9832_666e6503019d
* @private
* 
* @copydoc _1d59c95c_5324_405d_ac7e_8676f4f25d62
* @copydoc _d83f90d1_cdf6_43c2_a64f_bdb96e09bfb4
*/

// ctor: rvalue instant_t of any unwritable unit_t, rvalue allocator
/**
* @class _c1790cd3_ad82_4ddf_9eb2_cc9036a6bc75
* @private
* 
* @copydoc _1d59c95c_5324_405d_ac7e_8676f4f25d62
* @copydoc _d83f90d1_cdf6_43c2_a64f_bdb96e09bfb4
*/
