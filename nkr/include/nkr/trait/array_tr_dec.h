/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/template_i_dec.h"
#include "nkr/interface/type_i_dec.h"

#include "nkr/trait/array/any_tr_dec.h"

namespace nkr { namespace trait {

    struct                      array_tg    {};
    template <typename> struct  array_ttg   {};

    template <typename type_p>
    concept array_tr =
        array::any_tr<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<trait::array_tg> :
        public type_i<trait::array::any_tg>
    {
    public:
    };

    template <>
    class template_i<trait::array_ttg> :
        public template_i<trait::array::any_ttg>
    {
    public:
    };

}}
