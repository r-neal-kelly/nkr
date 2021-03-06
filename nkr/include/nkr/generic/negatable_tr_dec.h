/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_77a7ea7a_8462_42fa_bfda_cec2615d5e32
#define nkr_INCLUDE_GUARD_77a7ea7a_8462_42fa_bfda_cec2615d5e32

#include "nkr/generic/negatable/any_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_tag_t_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace generic {

    struct  negatable_tg    { class tag_lb; class generic_lb; };

    template <typename ...>
    struct  negatable_ttg   {};

    template <typename type_p>
    concept negatable_tr =
        nkr::generic::negatable::any_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept negatable_ttr =
        nkr::generic::negatable::any_ttr<template_p>;

}}

namespace nkr { namespace generic { namespace negatable_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::negatable_tg> type_p>
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

    template <nkr::cpp::is_any_tr<nkr::generic::negatable_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::generic::negatable_tr$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace generic { namespace negatable_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::negatable_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_generic_tag_t<
        nkr::generic::negatable_tg,
        nkr::generic::negatable_ttg>
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
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::negatable_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::generic::negatable_tr$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/generic/negatable_tr_dec_def.h"

#endif
