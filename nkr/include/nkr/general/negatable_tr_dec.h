/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/general/negatable/any_tr_dec.h"

namespace nkr { namespace general {

    struct  negatable_tg    {};

    template <typename>
    struct  negatable_ttg   {};

    template <typename type_p>
    concept negatable_tr =
        negatable::any_tr<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<general::negatable_tg> :
        public type_i<general::negatable::any_tg>
    {
    public:
    };

    template <>
    class template_i<general::negatable_ttg> :
        public template_i<general::negatable::any_ttg>
    {
    public:
    };

}}

#include "nkr/general/negatable_tr_dec_def.h"
