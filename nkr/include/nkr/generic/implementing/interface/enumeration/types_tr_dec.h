/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_814f3d64_07dc_408a_aa10_c2f9d65677d5
#define nkr_INCLUDE_GUARD_814f3d64_07dc_408a_aa10_c2f9d65677d5

#include "nkr/built_in/forward_dec.h"
#include "nkr/interface/enumeration/types_i_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_tag_t_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace interface { namespace enumeration {

    struct  types_tg    { class tag_lb; class generic_lb; };

    template <typename ...>
    struct  types_ttg   {};

    template <typename type_p>
    concept types_tr =
        nkr::interface::enumeration::types_tr<nkr::interface::enumeration::types_i<type_p>>;

    template <template <typename ...> typename template_p>
    concept types_ttr =
        types_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}}

namespace nkr { namespace generic { namespace implementing { namespace interface { namespace enumeration { namespace types_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::interface::enumeration::types_tg> type_p>
    class type_i_tag_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_tag_sp(...) noexcept   = delete;
    };

}}}}}}

namespace nkr { namespace interface {

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::interface::enumeration::types_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::generic::implementing::interface::enumeration::types_tr$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace generic { namespace implementing { namespace interface { namespace enumeration { namespace types_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::implementing::interface::enumeration::types_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_generic_tag_t<
        nkr::generic::implementing::interface::enumeration::types_tg,
        nkr::generic::implementing::interface::enumeration::types_ttg>
    {
    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i_tag_sp(...) noexcept   = delete;
    };

}}}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::implementing::interface::enumeration::types_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::generic::implementing::interface::enumeration::types_tr$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/generic/implementing/interface/enumeration/types_tr_dec_def.h"

#endif
