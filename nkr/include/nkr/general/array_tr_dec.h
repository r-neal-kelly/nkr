/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/general/array/any_tr_dec.h"

namespace nkr { namespace general {

    struct  array_tg    {};

    template <typename>
    struct  array_ttg   {};

    template <typename type_p>
    concept array_tr =
        array::any_tr<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<general::array_tg> :
        public type_i<general::array::any_tg>
    {
    public:
    };

    template <>
    class template_i<general::array_ttg> :
        public template_i<general::array::any_ttg>
    {
    public:
    };

}}

#include "nkr/general/array_tr_dec_def.h"
