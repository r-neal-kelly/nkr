/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_intrinsics.h"
#include "nkr/z_maybe_i.h"
#include "nkr/z_none_i.h"
#include "nkr/z_utils.h"

namespace nkr {

    /// @nosubgrouping
    /// @ingroup _7752ee81_def2_4386_b164_bc31f29ce7b8
    /// @copydoc 
    template <typename type_p>
    concept some_i =
        built_in_tr<type_p> ||
        maybe_i<type_p>;

}
