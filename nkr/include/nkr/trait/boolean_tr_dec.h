/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_dec.h"
#include "nkr/intrinsics_dec.h"

#include "nkr/interface/template_i_dec.h"
#include "nkr/interface/type_i_dec.h"

#include "nkr/trait/boolean/any_tr_dec.h"

namespace nkr { namespace trait {

    struct                      boolean_tg  {};
    template <typename> struct  boolean_ttg {};

    template <typename type_p>
    concept boolean_tr =
        boolean::any_tr<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<trait::boolean_tg> :
        public type_i<trait::boolean::any_tg>
    {
    public:
    };

    template <>
    class template_i<trait::boolean_ttg> :
        public template_i<trait::boolean::any_ttg>
    {
    public:
    };

}}
