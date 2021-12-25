/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/trait/none/any_tr_dec.h"

namespace nkr { namespace trait {

    struct  none_tg     {};

    template <typename>
    struct  none_ttg    {};

    template <typename type_p>
    concept none_tr =
        none::any_tr<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<trait::none_tg> :
        public type_i<trait::none::any_tg>
    {
    public:
    };

    template <>
    class template_i<trait::none_ttg> :
        public template_i<trait::none::any_ttg>
    {
    public:
    };

}}

#include "nkr/trait/none_tr_dec_def.h"
