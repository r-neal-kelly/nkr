/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"

namespace nkr {

    /// @nosubgrouping
    /// @copydoc _e81dde10_53a3_4c5e_b5e3_fa01c3325510
    class none_t
    {
    public:
        /// @name objects
        /// @copydoc _013126e0_1378_4f23_a393_bf330ab0b823
        /// @{
        none_t()                                    = default;  ///< @copydoc _4945c7b2_9854_48c5_9ffb_6e5e0d9ea8a2
        none_t(const none_t& other)                 = default;  ///< @copydoc _9a1760ef_b09e_4e12_8008_54228eb4db46
        none_t(none_t&& other) noexcept             = default;  ///< @copydoc _e4d8014b_ba97_4051_be28_9e60a1a81047
        none_t& operator =(const none_t& other)     = default;  ///< @copydoc _c5b4d034_9395_4c88_b3cc_33d6ef0b44a3
        none_t& operator =(none_t&& other) noexcept = default;  ///< @copydoc _8c3dca16_1f37_4d7b_bd14_522498aeb2e9
        ~none_t()                                   = default;  ///< @copydoc _d85fbe4a_ed6e_4ea0_8552_91e433238648
        /// @}
    };

}
