/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/maybe_i.h"
#include "nkr/none_i.h"
#include "nkr/utils.h"

namespace nkr {

    /// @nosubgrouping
    /// @ingroup _7752ee81_def2_4386_b164_bc31f29ce7b8
    /// @copydoc 
    template <typename type_p>
    concept some_i =
        built_in_tr<type_p> ||
        maybe_i<type_p>;

}
