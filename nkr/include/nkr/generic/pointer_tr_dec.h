/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/generic/pointer/any_tr_dec.h"

namespace nkr { namespace generic {

    struct  pointer_tg  {};

    template <typename>
    struct  pointer_ttg {};

    template <typename type_p>
    concept pointer_tr =
        pointer::any_tr<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::pointer_tg> :
        public type_i<nkr::generic::pointer::any_tg>
    {
    public:
        using type_t    = nkr::generic::pointer_tg;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::generic::pointer_ttg> :
        public template_i<nkr::generic::pointer::any_ttg>
    {
    public:
    };

}}

#include "nkr/generic/pointer_tr_dec_def.h"
