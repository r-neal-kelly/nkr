/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/maybe_t.h"
#include "nkr/some_i.h"
#include "nkr/traits.h"

namespace nkr {

    template <some_i any_p>
    class some_t;

    template <typename some_p>
    concept any_some_tr =
        is_any_tr<some_p, some_t<typename some_p::value_t>>;

    nkr_DEFINE_CONTAINER_TRAITS(some, value_t);

}

namespace nkr {

    /// @nosubgrouping
    /// @copydoc _fe4b1321_2470_4544_b8c0_0e93c38e7275
    template <some_i any_p>
    class some_t :
        public maybe_t<any_p>
    {
    public:
        /// @name aliases
        /// @copydoc _68e8ea24_c725_481e_96e2_83379ee8f177
        /// @{
        using value_t   = any_p;    ///< @copydoc _afe969ef_b9ff_4532_a311_5900ca7fba62
        /// @}

    private:
        using base_t    = maybe_t<any_p>;

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(some_t, base_t);
        /// @}

    public:
        /// @name none_t interface
        /// @copydoc _a9c2409d_1948_4a2d_a709_73323203c246
        /// @{
        some_t(none_t)                                  = delete;   ///< @copydoc _1d3fb757_fe58_4c5e_ba61_56a3ad52f3c1

        some_t&             operator =(none_t)          = delete;   ///< @copydoc _7e0c8790_9442_454e_aa96_8dd70e9e804e
        volatile some_t&    operator =(none_t) volatile = delete;   ///< @copydoc 
        /// @}
    };
    static_assert(some_i<std_bool_t>);
    static_assert(some_i<word_t>);
    static_assert(some_i<real_t>);
    static_assert(some_i<void_t*>);
    static_assert(some_i<bool_t>);

}
