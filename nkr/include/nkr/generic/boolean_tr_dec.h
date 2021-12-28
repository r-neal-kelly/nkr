/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/generic/boolean/any_tr_dec.h"

namespace nkr { namespace generic {

    struct  boolean_tg  {};

    template <typename>
    struct  boolean_ttg {};

    template <typename type_p>
    concept boolean_tr =
        boolean::any_tr<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::boolean_tg> :
        public type_i<nkr::generic::boolean::any_tg>
    {
    public:
        using type_t    = nkr::generic::boolean_tg;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::generic::boolean_ttg> :
        public template_i<nkr::generic::boolean::any_ttg>
    {
    public:
    };

}}

#include "nkr/generic/boolean_tr_dec_def.h"
