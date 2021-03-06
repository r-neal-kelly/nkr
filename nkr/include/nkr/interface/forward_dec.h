/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_93109f72_d3b8_4afb_9dc8_9859233d4825
#define nkr_INCLUDE_GUARD_93109f72_d3b8_4afb_9dc8_9859233d4825

#include "nkr/macros_dec.h"

namespace nkr { namespace interface { namespace enumeration {

    template <typename type_p>
    class   types_i_sp;

    template <typename type_p>
    using   types_i =
        typename nkr::interface::enumeration::types_i_sp<type_p>::type_t;

}}}

namespace nkr { namespace interface { namespace none {

    template <typename type_p>
    class   value_i_sp;

    /// @copydoc _fb7ae328_adb0_41f6_83fa_435b1c12cfb4
    template <typename type_p>
    using   value_i =
        typename nkr::interface::none::value_i_sp<type_p>::type_t;

}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor {

    template <typename type_p>
    class   uniform_i_sp;

    template <typename type_p>
    using   uniform_i =
        typename nkr::interface::randomness::distributor::uniform_i_sp<type_p>::type_t;

}}}}

namespace nkr { namespace interface { namespace randomness {

    template <typename type_p>
    class   value_i_sp;

    template <typename type_p>
    using   value_i =
        typename nkr::interface::randomness::value_i_sp<type_p>::type_t;

}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
    class   template_i_sp;

    /*template <template <typename ...> typename template_p>
    using   template_i =
        nkr::interface::template_i_sp<template_p>::type_t;*/

    // for whatever reason, the using version does not allow nkr::interface::template_i$::is_tmpl.
    // for right now the inheritance version is okay because all data is static on the class
    template <template <typename ...> typename template_p>
    class template_i :
        public nkr::interface::template_i_sp<template_p>::type_t
    {
    public:
    };

}}

namespace nkr { namespace interface {

    template <typename type_p>
    class   type_i_sp;

    template <typename type_p>
    using   type_i =
        typename nkr::interface::type_i_sp<type_p>::type_t;

}}

#include "nkr/interface/forward_dec_def.h"

#endif
