/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_dec.h"

namespace nkr { namespace none {

    using   type_t      = cpp::void_t;
    using   pointer_t   = cpp::nullptr_t;

}}

namespace nkr { namespace boolean {

    using   cpp_t   = cpp::bool_t;

}}

namespace nkr { namespace integer {



}}

namespace nkr { namespace real {



}}

namespace nkr { namespace pointer {

    template <typename any_p>
    using   cpp_t   = any_p*;

}}

namespace nkr { namespace array {

    template <cpp::type_tr type_p, cpp::count_t capacity_p>
    using   cpp_t   = type_p[capacity_p];

}}
