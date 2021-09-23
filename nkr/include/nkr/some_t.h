/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/maybe_t.h"
#include "nkr/traits.h"

namespace nkr {

    /// @nosubgrouping
    /// @copydoc _fe4b1321_2470_4544_b8c0_0e93c38e7275
    template <typename any_p>
    class some_t :
        public maybe_t<any_p>
    {
    public:
        /// @name aliases
        /// @copydoc _68e8ea24_c725_481e_96e2_83379ee8f177
        /// @{
        using base_t    = maybe_t<any_p>;   ///< @copydoc 
        using value_t   = any_p;            ///< @copydoc _afe969ef_b9ff_4532_a311_5900ca7fba62
        /// @}

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(some_t, base_t);
        /// @}

    public:
        /// @name operators
        /// @copydoc _a9c2409d_1948_4a2d_a709_73323203c246
        /// @{
        some_t(none_t)              = delete;   ///< @copydoc _1d3fb757_fe58_4c5e_ba61_56a3ad52f3c1
        some_t& operator =(none_t)  = delete;   ///< @copydoc _7e0c8790_9442_454e_aa96_8dd70e9e804e
        /// @}
    };

}

#include "nkr/some_t.inl"
