/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_fd2d8293_7272_4e79_93e6_51fb11a24f0a
#define nkr_INCLUDE_GUARD_fd2d8293_7272_4e79_93e6_51fb11a24f0a

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/type_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_identity_tag_t_dec.h"
#include "nkr/interface/template_i_identity_template_t_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace array {

    template <nkr::generic::type_tr unit_p, nkr::constant::positive::count_tr capacity_p>
    using   cpp_t =
        unit_p[capacity_p::Value()];

    struct  cpp_tg  { class tag_lb; };

    template <typename ...>
    struct  cpp_ttg {};

    template <typename type_p>
    concept cpp_tr =
        nkr::cpp::array_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept cpp_ttr =
        nkr::cpp::is_any_ttr<template_p, cpp_t, nkr::positive::integer_t, nkr::constant::positive::count_t<1>>;

}}

namespace nkr { namespace array { namespace cpp_t$ {

    template <nkr::array::cpp_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::cpp::array_unit_t<type_t>;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::array::cpp_tg> type_p>
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

    template <nkr::array::cpp_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::array::cpp_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::array::cpp_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::array::cpp_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace array { namespace cpp_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::array::cpp_ttr<template_p>
    class template_i_template_sp :
        public nkr::interface::template_i_identity_template_basic_t<
            nkr::array::cpp_t,
            nkr::tuple::types_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>,
            nkr::constant::positive::count_t<2>,
            nkr::constant::positive::count_t<2>,
            nkr::array::cpp_tg,
            nkr::array::cpp_ttg
        >
    {
    public:
        template <typename inner_p>
        using of_t          = template_t<inner_p, nkr::constant::positive::count_t<1>>;

        template <typename inner_p>
        using actual_of_t   = of_t<inner_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::array::cpp_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_identity_tag_t<
            template_i_template_sp<nkr::array::cpp_t>
        >
    {
    public:
    };

}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::array::cpp_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::array::cpp_t$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::array::cpp_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::array::cpp_t$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/array/cpp_t_dec_def.h"

#endif
