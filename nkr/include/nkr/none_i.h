/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/none_t.h"

namespace nkr {

    /// @nosubgrouping
    /// @ingroup _7752ee81_def2_4386_b164_bc31f29ce7b8
    /// @copydoc _9d52d2e1_c6dc_4dbb_ad58_01a219c6e510
    template <typename type_p>
    concept none_i = requires(type_p instance, const type_p const_instance)
    {
        type_p(none_t());
        static_cast<type_p&>(instance.operator =(none_t()));

        static_cast<bool_t>(const_instance.operator ==(none_t()));
        static_cast<bool_t>(const_instance.operator !=(none_t()));
    };

}
