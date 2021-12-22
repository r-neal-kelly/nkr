/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/template_i_dec.h"
#include "nkr/interface/type_i_dec.h"

#include "nkr/trait/negatable/any_tr_dec.h"

namespace nkr { namespace trait {

    struct                      negatable_tg    {};
    template <typename> struct  negatable_ttg   {};

    template <typename type_p>
    concept negatable_tr =
        negatable::any_tr<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<trait::negatable_tg> :
        public type_i<trait::negatable::any_tg>
    {
    public:
    };

    template <>
    class template_i<trait::negatable_ttg> :
        public template_i<trait::negatable::any_ttg>
    {
    public:
    };

}}
