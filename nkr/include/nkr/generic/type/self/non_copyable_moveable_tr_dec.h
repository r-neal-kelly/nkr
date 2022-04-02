/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_f4766f37_1737_446f_ba19_89a57541fb66
#define nkr_INCLUDE_GUARD_f4766f37_1737_446f_ba19_89a57541fb66

#include "nkr/built_in/forward_dec.h"
#include "nkr/generic/implementing/self_tr_dec.h"
#include "nkr/generic/type_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_tag_t_dec.h"

namespace nkr { namespace generic { namespace type { namespace self {

    struct  non_copyable_moveable_tg    { class tag_lb; class generic_lb; };

    template <typename ...>
    struct  non_copyable_moveable_ttg   {};

    template <typename type_p>
    concept non_copyable_moveable_tr =
        nkr::generic::type_tr<type_p> &&

        !nkr::generic::implementing::self::constructor::copy::non_volatile_tr<type_p> &&
        !nkr::generic::implementing::self::constructor::copy::volatile_tr<type_p> &&
        !nkr::generic::implementing::self::assigner::non_volatile::copy::non_volatile_tr<type_p> &&
        !nkr::generic::implementing::self::assigner::non_volatile::copy::volatile_tr<type_p> &&
        !nkr::generic::implementing::self::assigner::volatile_::copy::non_volatile_tr<type_p> &&
        !nkr::generic::implementing::self::assigner::volatile_::copy::volatile_tr<type_p> &&

        nkr::generic::implementing::self::constructor::move::non_volatile_tr<type_p> &&
        nkr::generic::implementing::self::constructor::move::volatile_tr<type_p> &&
        nkr::generic::implementing::self::assigner::non_volatile::move::non_volatile_tr<type_p> &&
        nkr::generic::implementing::self::assigner::non_volatile::move::volatile_tr<type_p> &&
        nkr::generic::implementing::self::assigner::volatile_::move::non_volatile_tr<type_p> &&
        nkr::generic::implementing::self::assigner::volatile_::move::volatile_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept non_copyable_moveable_ttr =
        non_copyable_moveable_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}

namespace nkr { namespace generic { namespace type { namespace self { namespace non_copyable_moveable_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::type::self::non_copyable_moveable_tg> type_p>
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

    template <nkr::cpp::is_any_tr<nkr::generic::type::self::non_copyable_moveable_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::generic::type::self::non_copyable_moveable_tr$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace generic { namespace type { namespace self { namespace non_copyable_moveable_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::type::self::non_copyable_moveable_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_generic_tag_t<
        nkr::generic::type::self::non_copyable_moveable_tg,
        nkr::generic::type::self::non_copyable_moveable_ttg>
    {
    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i_tag_sp(...) noexcept   = delete;
    };

}}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::type::self::non_copyable_moveable_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::generic::type::self::non_copyable_moveable_tr$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/generic/type/self/non_copyable_moveable_tr_dec_def.h"

#endif
