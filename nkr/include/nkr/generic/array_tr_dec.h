/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_04c5c4b8_5605_494c_864e_0f400dc6045d
#define nkr_INCLUDE_GUARD_04c5c4b8_5605_494c_864e_0f400dc6045d

#include "nkr/generic/array/any_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_tag_t_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace generic {

    struct  array_tg    { class tag_lb; class generic_lb; };

    template <typename ...>
    struct  array_ttg   {};

    template <typename type_p>
    concept array_tr =
        nkr::generic::array::any_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept array_ttr =
        nkr::generic::array::any_ttr<template_p>;

}}

namespace nkr { namespace generic { namespace array_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::array_tg> type_p>
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

}}}

namespace nkr { namespace interface {

    template <nkr::cpp::is_any_tr<nkr::generic::array_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::generic::array_tr$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace generic { namespace array_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::array_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_generic_tag_t<
        nkr::generic::array_tg,
        nkr::generic::array_ttg>
    {
    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i_tag_sp(...) noexcept   = delete;
    };

}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::array_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::generic::array_tr$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/generic/array_tr_dec_def.h"

#endif
