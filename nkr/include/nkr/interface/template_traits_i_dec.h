/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_dec.h"
#include "nkr/intrinsics_dec.h"

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
    class template_traits_i
    {
    public:
        template <typename of_p>
        using type_t    = cpp::void_t;

    public:
        static constexpr cpp::bool_t    Is_Implemented();
    };

}}
