/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

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
