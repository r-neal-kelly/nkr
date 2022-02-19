/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/constant_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/reference/lvalue_t_dec.h"

namespace nkr { namespace constant { namespace reference {

    template <typename type_p, type_p& value_p>
    using   cpp_t =
        nkr::constant_t<type_p&, value_p>;

    template <typename type_p>
    concept cpp_tr =
        nkr::constant_tr<type_p> &&
        nkr::reference::lvalue_tr<typename type_p::value_t>;

}}}

#include "nkr/constant/reference/lvalue_t_dec_def.h"
