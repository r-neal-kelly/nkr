/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/template_i_dec.h"
#include "nkr/interface/type_i_dec.h"

#include "nkr/trait/positive/any_tr_dec.h"

namespace nkr { namespace trait {

    struct  positive_tg     {};

    template <typename>
    struct  positive_ttg    {};

    template <typename type_p>
    concept positive_tr =
        positive::any_tr<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<trait::positive_tg> :
        public type_i<trait::positive::any_tg>
    {
    public:
    };

    template <>
    class template_i<trait::positive_ttg> :
        public template_i<trait::positive::any_ttg>
    {
    public:
    };

}}

#include "nkr/trait/positive_tr_dec_def.h"
