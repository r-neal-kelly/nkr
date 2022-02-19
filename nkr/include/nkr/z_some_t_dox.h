/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

// some_t<any_p>
/**
* @class _fe4b1321_2470_4544_b8c0_0e93c38e7275
* @private
*
* @brief
*   Wraps a type whose object has some value.
* 
* @param any_p
*   must satisfy one of the specializations of nkr::maybe_t.
*
* @details
*   This template is an in-code tag for an object which has a value. In other words, it does not equate to nkr::none_t. This is opposed to nkr::maybe_t which indicates that an object may or may not have a value.
* 
*   This is used as a space efficient means of ensuring that any other interface is being fulfilled properly, including functions and other types. This is opposed to nkr::option_t, which adds a nkr::bool_t to its footprint to indicate nothing.
* 
* @copydoc _f66dddf5_07cc_4240_b2e2_39253f780892
*/

    // aliases
    /**
    * @class _68e8ea24_c725_481e_96e2_83379ee8f177
    * @private
    */

        // value_t
        /**
        * @class _afe969ef_b9ff_4532_a311_5900ca7fba62
        * @private
        */

    // operators
    /**
    * @class _a9c2409d_1948_4a2d_a709_73323203c246
    * @private
    */

        // none_ctor()
        /**
        * @class _1d3fb757_fe58_4c5e_ba61_56a3ad52f3c1
        * @private
        */

        // =(none_t)
        /**
        * @class _7e0c8790_9442_454e_aa96_8dd70e9e804e
        * @private
        * 
        * @brief
        *   Deleted to prevent making the object invalid.
        */
