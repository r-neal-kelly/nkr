/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/macros_dec.h"

namespace nkr { namespace interface { namespace enumeration {

    template <typename type_p>
    class   types_i_sp;

    template <typename type_p>
    using   types_i =
        nkr::interface::enumeration::types_i_sp<type_p>::type_t;

}}}

namespace nkr { namespace interface { namespace none {

    template <typename type_p>
    class   value_i_sp;

    template <typename type_p>
    using   value_i =
        nkr::interface::none::value_i_sp<type_p>::type_t;

}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor {

    template <typename type_p>
    class   uniform_i_sp;

    template <typename type_p>
    using   uniform_i =
        nkr::interface::randomness::distributor::uniform_i_sp<type_p>::type_t;

}}}}

namespace nkr { namespace interface { namespace randomness {

    template <typename type_p>
    class   value_i_sp;

    template <typename type_p>
    using   value_i =
        nkr::interface::randomness::value_i_sp<type_p>::type_t;

}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
    class   template_i_sp;

    template <template <typename ...> typename template_p>
    using   template_i =
        nkr::interface::template_i_sp<template_p>::type_t;

}}

namespace nkr { namespace interface {

    template <typename type_p>
    class   type_i_sp;

    template <typename type_p>
    using   type_i =
        nkr::interface::type_i_sp<type_p>::type_t;

}}

#include "nkr/interface/forward_dec_def.h"
