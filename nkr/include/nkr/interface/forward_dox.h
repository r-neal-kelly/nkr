/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

// nkr::interface::none::value_i
/**
    @class _fb7ae328_adb0_41f6_83fa_435b1c12cfb4
    @private

    @brief
    Allows for the construction of a [type instance](@ref _7c636ccf_7f4b_40c1_a955_2dca05506ac4) that semantically indicates a missing value.

    @details
    For a concrete example, say you design a [type](@ref _d5fa5645_f7f9_446a_936d_459b0e0e4982) that is essentially a dynamically remote array of random numbers stored on the heap. Perhaps exceptions are ruled-out of your design, so you set the pointer on your [instance](@ref _7c636ccf_7f4b_40c1_a955_2dca05506ac4) to nullptr to indicate memory allocation has failed. However by default you want to avoid being pessimistic and allow your [type](@ref _d5fa5645_f7f9_446a_936d_459b0e0e4982) to allocate memory and produce a valid value for your users. That means having a default constructor set the [instance](@ref _7c636ccf_7f4b_40c1_a955_2dca05506ac4) to an invalid state by default is out of the question.

    Making an [interface implementation](@ref _e930ffa6_a82e_461e_9bd9_427f2d51d568) for nkr::interface::none::value_i in this situation and all situations that involve memory allocation without exceptions is a reasonable solution to the problem. In the rare event that you failed to produce a value and literally have none to give, you can direct the [interface](@ref _530148d0_cb32_40a7_9288_99cff1c667fe) to return an invalid [instance](@ref _7c636ccf_7f4b_40c1_a955_2dca05506ac4) as the none value.

    However, if you're using a local array with a similar problem set, perhaps the nkr::interface::none_i would be more suitable, which only requires a boolean check of an already existing value to determine if it equals none, avoiding any need to create a potentially large instance just for literal comparison. nkr::interface::none::value_i is useful for when a none value must be produced and not only if an already existing none value needs to be compared.
*/
