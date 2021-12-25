/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/general/boolean/any_tr_dec.h"

namespace nkr { namespace general {

    struct  boolean_tg  {};

    template <typename>
    struct  boolean_ttg {};

    template <typename type_p>
    concept boolean_tr =
        boolean::any_tr<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<general::boolean_tg> :
        public type_i<general::boolean::any_tg>
    {
    public:
    };

    template <>
    class template_i<general::boolean_ttg> :
        public template_i<general::boolean::any_ttg>
    {
    public:
    };

}}

#include "nkr/general/boolean_tr_dec_def.h"
