/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/string_itr_def.h"
#include "nkr/string/static_t_dec.h"

namespace nkr { namespace string {

    template <charcoder_i charcoder_p>
    inline constexpr c_bool_t
        static_t<charcoder_p>::Has_Guaranteed_Terminus()
    {
        return false;
    }

}}
