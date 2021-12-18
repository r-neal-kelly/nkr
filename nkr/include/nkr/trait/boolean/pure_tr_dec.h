/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_dec.h"
#include "nkr/intrinsics_dec.h"

#include "nkr/interface/template_i_dec.h"
#include "nkr/interface/type_i_dec.h"

#include "nkr/trait/boolean/impure_tr_dec.h"

namespace nkr { namespace trait { namespace boolean {

    struct                      pure_tg     {};
    template <typename> struct  pure_ttg    {};

    template <typename type_p>
    concept pure_tr =
        any_tr<type_p> &&
        !impure_tr<type_p>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<trait::boolean::pure_tg>
    {
    public:
        using of_t  = cpp::void_t;

    public:
        template <typename other_p>
        static constexpr cpp::bool_t    Is_Any();
    };

    template <>
    class template_i<trait::boolean::pure_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = trait::boolean::pure_tg;

    public:
        static constexpr cpp::bool_t    Is_Implemented();
    };

}}