/*
    Copyright 2022 r-neal-kelly
*/


#pragma once

// none_i
/**
* @class _9d52d2e1_c6dc_4dbb_ad58_01a219c6e510
* @private
*
* @brief
*   Allows any user-defined type to interact with nkr::none_t, which is necessary for nkr::maybe_t and nkr::some_t.
* 
* @details
*   We make no assumptions about whatever type is meant to interface with nkr::none_t, such as assuming that `operator bool_t()` indicates a lack of a value or not. Requiring an extra step to be taken by the implementor of the type helps to ensure correct usage.
*/
