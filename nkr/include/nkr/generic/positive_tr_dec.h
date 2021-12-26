/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/generic/positive/any_tr_dec.h"

namespace nkr { namespace generic {

    struct  positive_tg     {};

    template <typename>
    struct  positive_ttg    {};

    template <typename type_p>
    concept positive_tr =
        positive::any_tr<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<generic::positive_tg> :
        public type_i<generic::positive::any_tg>
    {
    public:
    };

    template <>
    class template_i<generic::positive_ttg> :
        public template_i<generic::positive::any_ttg>
    {
    public:
    };

}}

#include "nkr/generic/positive_tr_dec_def.h"
