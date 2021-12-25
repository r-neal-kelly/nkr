/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/general/pointer/any_tr_dec.h"

namespace nkr { namespace general {

    struct  pointer_tg  {};

    template <typename>
    struct  pointer_ttg {};

    template <typename type_p>
    concept pointer_tr =
        pointer::any_tr<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<general::pointer_tg> :
        public type_i<general::pointer::any_tg>
    {
    public:
    };

    template <>
    class template_i<general::pointer_ttg> :
        public template_i<general::pointer::any_ttg>
    {
    public:
    };

}}

#include "nkr/general/pointer_tr_dec_def.h"
