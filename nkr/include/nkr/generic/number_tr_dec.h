/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_40ec5cb4_7dae_4a2a_bd26_9b46236b40b6
#define nkr_INCLUDE_GUARD_40ec5cb4_7dae_4a2a_bd26_9b46236b40b6

#include "nkr/generic/number/any_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_tag_t_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace generic {

    struct  number_tg   { class tag_lb; class generic_lb; };

    template <typename ...>
    struct  number_ttg  {};

    template <typename type_p>
    concept number_tr =
        nkr::generic::number::any_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept number_ttr =
        nkr::generic::number::any_ttr<template_p>;

}}

namespace nkr { namespace generic { namespace number_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::number_tg> type_p>
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

    template <nkr::cpp::is_any_tr<nkr::generic::number_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::generic::number_tr$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace generic { namespace number_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::number_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_generic_tag_t<
        nkr::generic::number_tg,
        nkr::generic::number_ttg>
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
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::number_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::generic::number_tr$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/generic/number_tr_dec_def.h"

#endif
