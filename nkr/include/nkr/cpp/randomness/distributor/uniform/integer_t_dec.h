/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_c6a151b4_de4c_422d_8264_39ee3307e892
#define nkr_INCLUDE_GUARD_c6a151b4_de4c_422d_8264_39ee3307e892

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_identity_tag_t_dec.h"
#include "nkr/interface/template_i_identity_template_t_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace cpp { namespace randomness { namespace distributor { namespace uniform {

    template <typename integer_p>
    using   integer_t =
        std::uniform_int_distribution<integer_p>;

    struct  integer_tg  { class tag_lb; };

    template <typename ...>
    struct  integer_ttg {};

    template <typename type_p>
    concept integer_tr =
        nkr::cpp::is_any_tr<type_p, integer_t<typename type_p::result_type>>;

    template <template <typename ...> typename template_p>
    concept integer_ttr =
        nkr::cpp::is_any_ttr<template_p, integer_t, nkr::positive::integer_t>;

}}}}}

namespace nkr { namespace cpp { namespace randomness { namespace distributor { namespace uniform { namespace integer_t$ {

    template <nkr::cpp::randomness::distributor::uniform::integer_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = typename type_t::result_type;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::distributor::uniform::integer_tg> type_p>
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

    template <nkr::cpp::randomness::distributor::uniform::integer_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::randomness::distributor::uniform::integer_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::distributor::uniform::integer_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::randomness::distributor::uniform::integer_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace cpp { namespace randomness { namespace distributor { namespace uniform { namespace integer_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::randomness::distributor::uniform::integer_ttr<template_p>
    class template_i_template_sp :
        public nkr::interface::template_i_identity_template_t<
            nkr::cpp::randomness::distributor::uniform::integer_t,
            nkr::tuple::types_t<nkr::positive::integer_t>,
            nkr::constant::positive::count_t<1>,
            nkr::constant::positive::count_t<1>,
            nkr::cpp::randomness::distributor::uniform::integer_tg,
            nkr::cpp::randomness::distributor::uniform::integer_ttg
        >
    {
    public:
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::randomness::distributor::uniform::integer_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_identity_tag_t<
            template_i_template_sp<nkr::cpp::randomness::distributor::uniform::integer_t>
        >
    {
    public:
    };

}}}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::randomness::distributor::uniform::integer_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::randomness::distributor::uniform::integer_t$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::randomness::distributor::uniform::integer_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::randomness::distributor::uniform::integer_t$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/cpp/randomness/distributor/uniform/integer_t_dec_def.h"

#endif
