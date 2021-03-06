/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_0fe8edbf_6906_492f_bfdb_b40b824cd04a
#define nkr_INCLUDE_GUARD_0fe8edbf_6906_492f_bfdb_b40b824cd04a

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/negatable/any_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_tag_t_dec.h"

namespace nkr { namespace generic { namespace negatable {

    struct  integer_tg  { class tag_lb; class generic_lb; };

    template <typename ...>
    struct  integer_ttg {};

    template <typename type_p>
    concept integer_tr =
        nkr::generic::negatable::any_tr<type_p> &&
        nkr::cpp::integer_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept integer_ttr =
        integer_tr<typename interface::template_i<template_p>::example_t>;

}}}

namespace nkr { namespace generic { namespace negatable { namespace integer_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::negatable::integer_tg> type_p>
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

}}}}

namespace nkr { namespace interface {

    template <nkr::cpp::is_any_tr<nkr::generic::negatable::integer_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::generic::negatable::integer_tr$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace generic { namespace negatable { namespace integer_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::negatable::integer_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_generic_tag_t<
        nkr::generic::negatable::integer_tg,
        nkr::generic::negatable::integer_ttg>
    {
    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i_tag_sp(...) noexcept   = delete;
    };

}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::negatable::integer_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::generic::negatable::integer_tr$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/generic/negatable/integer_tr_dec_def.h"

#endif
