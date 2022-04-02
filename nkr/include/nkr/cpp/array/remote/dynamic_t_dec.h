/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_7ec4a3cf_d254_415f_8458_eed31b93d0db
#define nkr_INCLUDE_GUARD_7ec4a3cf_d254_415f_8458_eed31b93d0db

#include <vector>

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_identity_tag_t_dec.h"
#include "nkr/interface/template_i_identity_template_t_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace cpp { namespace array { namespace remote {

    template <typename unit_p, typename allocator_p = std::allocator<unit_p>>
    using   dynamic_t =
        std::vector<unit_p, allocator_p>;

    struct  dynamic_tg  { class tag_lb; };

    template <typename ...>
    struct  dynamic_ttg {};

    template <typename type_p>
    concept dynamic_tr =
        nkr::cpp::is_any_tr<type_p, dynamic_t<typename type_p::value_type, typename type_p::allocator_type>>;

    template <template <typename ...> typename template_p>
    concept dynamic_ttr =
        nkr::cpp::is_any_ttr<template_p, dynamic_t, nkr::positive::integer_t>;

}}}}

namespace nkr { namespace cpp { namespace array { namespace remote { namespace dynamic_t$ {

    template <nkr::cpp::array::remote::dynamic_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = typename type_t::value_type;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::array::remote::dynamic_tg> type_p>
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

}}}}}

namespace nkr { namespace interface {

    template <nkr::cpp::array::remote::dynamic_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::array::remote::dynamic_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::array::remote::dynamic_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::array::remote::dynamic_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace cpp { namespace array { namespace remote { namespace dynamic_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::array::remote::dynamic_ttr<template_p>
    class template_i_template_sp :
        public nkr::interface::template_i_identity_template_t<
            nkr::cpp::array::remote::dynamic_t,
            nkr::tuple::types_t<nkr::positive::integer_t>,
            nkr::constant::positive::count_t<1>,
            nkr::constant::positive::count_t<2>,
            nkr::cpp::array::remote::dynamic_tg,
            nkr::cpp::array::remote::dynamic_ttg
        >
    {
    public:
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::array::remote::dynamic_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_identity_tag_t<
            template_i_template_sp<nkr::cpp::array::remote::dynamic_t>
        >
    {
    public:
    };

}}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::array::remote::dynamic_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::array::remote::dynamic_t$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::array::remote::dynamic_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::array::remote::dynamic_t$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/cpp/array/remote/dynamic_t_dec_def.h"

#endif
