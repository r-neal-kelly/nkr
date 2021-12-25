/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/general/boolean/impure_tr_dec.h"

namespace nkr { namespace general { namespace boolean {

    struct  pure_tg     {};

    template <typename>
    struct  pure_ttg    {};

    template <typename type_p>
    concept pure_tr =
        any_tr<type_p> &&
        !impure_tr<type_p>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<general::boolean::pure_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <>
    class template_i<general::boolean::pure_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = general::boolean::pure_tg;

    public:
        static constexpr boolean::cpp_t Is_Implemented() noexcept;
    };

}}

#include "nkr/general/boolean/pure_tr_dec_def.h"
