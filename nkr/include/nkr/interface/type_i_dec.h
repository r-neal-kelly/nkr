/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_dec.h"
#include "nkr/intrinsics_dec.h"

namespace nkr { namespace interface {

    template <typename type_p>
    class type_i
    {
    public:
        using of_t  = cpp::void_t;

    public:
        template <typename other_p>
        static constexpr cpp::bool_t    Is_Any();
    };

}}
