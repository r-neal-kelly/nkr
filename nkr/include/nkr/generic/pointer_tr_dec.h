/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_148faea1_b082_429f_b5f4_29717f01218a
#define nkr_INCLUDE_GUARD_148faea1_b082_429f_b5f4_29717f01218a

#include "nkr/generic/pointer/any_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_tag_t_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace generic {

    struct  pointer_tg  { class tag_lb; class generic_lb; };

    template <typename ...>
    struct  pointer_ttg {};

    template <typename type_p>
    concept pointer_tr =
        nkr::generic::pointer::any_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept pointer_ttr =
        nkr::generic::pointer::any_ttr<template_p>;

}}

namespace nkr { namespace generic { namespace pointer_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::pointer_tg> type_p>
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

    template <nkr::cpp::is_any_tr<nkr::generic::pointer_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::generic::pointer_tr$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace generic { namespace pointer_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::pointer_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_generic_tag_t<
        nkr::generic::pointer_tg,
        nkr::generic::pointer_ttg>
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
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::pointer_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::generic::pointer_tr$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/generic/pointer_tr_dec_def.h"

#endif
