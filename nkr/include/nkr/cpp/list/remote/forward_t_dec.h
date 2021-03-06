/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_9508fda9_f038_467c_9457_9b506bbf2064
#define nkr_INCLUDE_GUARD_9508fda9_f038_467c_9457_9b506bbf2064

#include <forward_list>

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_identity_tag_t_dec.h"
#include "nkr/interface/template_i_identity_template_t_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace cpp { namespace list { namespace remote {

    template <typename unit_p, typename allocator_p = std::allocator<unit_p>>
    using   forward_t =
        std::forward_list<unit_p, allocator_p>;

    struct  forward_tg  { class tag_lb; };

    template <typename ...>
    struct  forward_ttg {};

    template <typename type_p>
    concept forward_tr =
        nkr::cpp::is_any_tr<type_p, forward_t<typename type_p::value_type, typename type_p::allocator_type>>;

    template <template <typename ...> typename template_p>
    concept forward_ttr =
        nkr::cpp::is_any_ttr<template_p, forward_t, nkr::positive::integer_t>;

}}}}

namespace nkr { namespace cpp { namespace list { namespace remote { namespace forward_t$ {

    template <nkr::cpp::list::remote::forward_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = type_t::value_type;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::list::remote::forward_tg> type_p>
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

    template <nkr::cpp::list::remote::forward_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::list::remote::forward_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::list::remote::forward_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::list::remote::forward_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace cpp { namespace list { namespace remote { namespace forward_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::list::remote::forward_ttr<template_p>
    class template_i_template_sp :
        public nkr::interface::template_i_identity_template_t<
            nkr::cpp::list::remote::forward_t,
            nkr::tuple::types_t<nkr::positive::integer_t>,
            nkr::constant::positive::count_t<1>,
            nkr::constant::positive::count_t<2>,
            nkr::cpp::list::remote::forward_tg,
            nkr::cpp::list::remote::forward_ttg
        >
    {
    public:
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::list::remote::forward_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_identity_tag_t<
            template_i_template_sp<nkr::cpp::list::remote::forward_t>
        >
    {
    public:
    };

}}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::list::remote::forward_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::list::remote::forward_t$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::list::remote::forward_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::list::remote::forward_t$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/cpp/list/remote/forward_t_dec_def.h"

#endif
