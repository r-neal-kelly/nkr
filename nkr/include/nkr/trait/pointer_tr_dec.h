/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/template_i_dec.h"
#include "nkr/interface/type_i_dec.h"

#include "nkr/trait/pointer/any_tr_dec.h"

namespace nkr { namespace trait {

    struct                      pointer_tg  {};
    template <typename> struct  pointer_ttg {};

    template <typename type_p>
    concept pointer_tr =
        pointer::any_tr<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<trait::pointer_tg> :
        public type_i<trait::pointer::any_tg>
    {
    public:
    };

    template <>
    class template_i<trait::pointer_ttg> :
        public template_i<trait::pointer::any_ttg>
    {
    public:
    };

}}

#include "nkr/trait/pointer_tr_dec_def.h"
