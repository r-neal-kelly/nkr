/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/macros.h"
#include "nkr/maybe_t.h"
#include "nkr/traits.h"
#include "nkr/utils.h"

#include "nkr/allocator_err.h"

#include "nkr/charcoder_i.h"

namespace nkr::string {};

namespace nkr { namespace string {

    using point_t   = charcoder::point_t;

}}

namespace nkr {

    template <typename string_p>
    concept string_i = requires(std::remove_const_t<string_p> string,
                                std::add_const_t<string_p> const_string)
    {
        typename string_p::charcoder_t;
        typename string_p::array_t; // we need to verify that the array_t satisfies array_i, but we have to move the code around a bit first
    
        // need to add more constraints.
    };

    template <typename string_p>
    concept any_string_tr =
        string_i<string_p>;

    nkr_DEFINE_CONTAINER_TRAITS(string, unit_t);

}
