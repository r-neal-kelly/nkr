/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

namespace nkr { namespace interface {

    template <typename type_p>
    class type_i
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

}}

namespace nkr { namespace interface {

    template <typename type_p>
    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<type_p>::Is_Any()
        noexcept
    {
        static_assert(false, "you need to implement or include a type_i for this type");
    }

}}
