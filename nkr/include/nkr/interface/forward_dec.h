/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/macros_dec.h"

// these should eventually all use the i_sp pattern until the compilers can fix the_concept_bug

namespace nkr { namespace interface { namespace enumeration {

    template <typename type_p>
    class   types_i;

}}}

namespace nkr { namespace interface { namespace none {

    template <typename type_p>
    class   value_i_sp;

}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor {

    template <typename type_p>
    class   uniform_i_sp;

}}}}

namespace nkr { namespace interface { namespace randomness {

    template <typename type_p>
    class   value_i_sp;

}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
    class   template_i;

}}

namespace nkr { namespace interface {

    template <typename type_p>
    class   type_i;

}}

#include "nkr/interface/forward_dec_def.h"
