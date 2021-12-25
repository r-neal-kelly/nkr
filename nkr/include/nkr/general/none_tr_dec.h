/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/general/none/any_tr_dec.h"

namespace nkr { namespace general {

    struct  none_tg     {};

    template <typename>
    struct  none_ttg    {};

    template <typename type_p>
    concept none_tr =
        none::any_tr<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<general::none_tg> :
        public type_i<general::none::any_tg>
    {
    public:
    };

    template <>
    class template_i<general::none_ttg> :
        public template_i<general::none::any_ttg>
    {
    public:
    };

}}

#include "nkr/general/none_tr_dec_def.h"
