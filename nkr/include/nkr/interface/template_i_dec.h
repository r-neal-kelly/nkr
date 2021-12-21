/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
    class template_i
    {
    public:
        template <typename of_p>
        using type_t    = cpp::void_t;

    public:
        static constexpr boolean::cpp_t Is_Implemented() noexcept;
    };

}}
