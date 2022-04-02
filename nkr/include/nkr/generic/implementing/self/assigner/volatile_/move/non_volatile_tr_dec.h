/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_8f23fdb0_5062_4a28_b487_20a4bd129ec9
#define nkr_INCLUDE_GUARD_8f23fdb0_5062_4a28_b487_20a4bd129ec9

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_tag_t_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace self { namespace assigner {
namespace volatile_ { namespace move { namespace non_volatile_tr$ {

    template <typename type_p>
    concept assigners_i =
        (requires(type_p instance,
                  const type_p const_instance,
                  volatile type_p volatile_instance,
                  const volatile type_p const_volatile_instance)
    {
        { volatile_instance = nkr::cpp::Move(instance) }    -> nkr::cpp::is_tr<volatile type_p&>;
    });

}}}}}}}}

namespace nkr { namespace generic { namespace implementing { namespace self { namespace assigner {
namespace volatile_ { namespace move {

    struct  non_volatile_tg     { class tag_lb; class generic_lb; };

    template <typename ...>
    struct  non_volatile_ttg    {};

    template <typename type_p>
    concept non_volatile_tr =
        non_volatile_tr$::assigners_i<nkr::cpp::just_non_qualified_t<type_p>>;

    template <template <typename ...> typename template_p>
    concept non_volatile_ttr =
        non_volatile_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}}}}

namespace nkr { namespace generic { namespace implementing { namespace self { namespace assigner {
namespace volatile_ { namespace move { namespace non_volatile_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::self::assigner::volatile_::move::non_volatile_tg> type_p>
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

}}}}}}}}

namespace nkr { namespace interface {

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::self::assigner::volatile_::move::non_volatile_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::generic::implementing::self::assigner::volatile_::move::non_volatile_tr$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace generic { namespace implementing { namespace self { namespace assigner {
namespace volatile_ { namespace move { namespace non_volatile_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::implementing::self::assigner::volatile_::move::non_volatile_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_generic_tag_t<
        nkr::generic::implementing::self::assigner::volatile_::move::non_volatile_tg,
        nkr::generic::implementing::self::assigner::volatile_::move::non_volatile_ttg>
    {
    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i_tag_sp(...) noexcept   = delete;
    };

}}}}}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::implementing::self::assigner::volatile_::move::non_volatile_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::generic::implementing::self::assigner::volatile_::move::non_volatile_tr$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/generic/implementing/self/assigner/volatile_/move/non_volatile_tr_dec_def.h"

#endif
