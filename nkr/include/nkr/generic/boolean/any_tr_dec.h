/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_f12e4b1a_c195_47a9_bb45_faada4fe2364
#define nkr_INCLUDE_GUARD_f12e4b1a_c195_47a9_bb45_faada4fe2364

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/implementing/self_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_tag_t_dec.h"

namespace nkr { namespace generic { namespace boolean { namespace any_tr$ {

    template <typename type_p>
    concept constructors_i =
        (requires(nkr::boolean::cpp_t boolean,
                  const nkr::boolean::cpp_t const_boolean,
                  volatile nkr::boolean::cpp_t volatile_boolean,
                  const volatile nkr::boolean::cpp_t const_volatile_boolean)
    {
        { type_p() };

        { type_p(nkr::boolean::cpp_t()) };

        { type_p(boolean) };
        { type_p(const_boolean) };
        { type_p(volatile_boolean) };
        { type_p(const_volatile_boolean) };

        { type_p(nkr::cpp::Move(boolean)) };
        { type_p(nkr::cpp::Move(volatile_boolean)) };
    });

    template <typename type_p>
    concept casts_i =
        (requires(nkr::cpp::just_non_qualified_t<type_p> object,
                  nkr::cpp::just_const_t<type_p> const_object,
                  nkr::cpp::just_volatile_t<type_p> volatile_object,
                  nkr::cpp::just_const_volatile_t<type_p> const_volatile_object)
    {
        { static_cast<nkr::boolean::cpp_t>(object) };
        { static_cast<nkr::boolean::cpp_t>(const_object) };
        { static_cast<nkr::boolean::cpp_t>(volatile_object) };
        { static_cast<nkr::boolean::cpp_t>(const_volatile_object) };

        { (object) ? true : false };
        { (const_object) ? true : false };
        { (volatile_object) ? true : false };
        { (const_volatile_object) ? true : false };

        { (!object) ? true : false };
        { (!const_object) ? true : false };
        { (!volatile_object) ? true : false };
        { (!const_volatile_object) ? true : false };

        { (object && object) ? true : false };
        { (const_object && const_object) ? true : false };
        { (volatile_object && volatile_object) ? true : false };
        { (const_volatile_object && const_volatile_object) ? true : false };

        { (object || object) ? true : false };
        { (const_object || const_object) ? true : false };
        { (volatile_object || volatile_object) ? true : false };
        { (const_volatile_object || const_volatile_object) ? true : false };
    });

    template <typename type_p>
    concept operators_i =
        (requires(nkr::cpp::just_non_qualified_t<type_p> object,
                  nkr::cpp::just_const_t<type_p> const_object,
                  nkr::cpp::just_volatile_t<type_p> volatile_object,
                  nkr::cpp::just_const_volatile_t<type_p> const_volatile_object,
                  
                  nkr::boolean::cpp_t boolean,
                  const nkr::boolean::cpp_t const_boolean,
                  volatile nkr::boolean::cpp_t volatile_boolean,
                  const volatile nkr::boolean::cpp_t const_volatile_boolean)
    {
        { object = nkr::boolean::cpp_t() };

        { object == boolean }                                           -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { object == const_boolean }                                     -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { object == volatile_boolean }                                  -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { object == const_volatile_boolean }                            -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_object == boolean }                                     -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_object == const_boolean }                               -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_object == volatile_boolean }                            -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_object == const_volatile_boolean }                      -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { volatile_object == boolean }                                  -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { volatile_object == const_boolean }                            -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { volatile_object == volatile_boolean }                         -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { volatile_object == const_volatile_boolean }                   -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_volatile_object == boolean }                            -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_volatile_object == const_boolean }                      -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_volatile_object == volatile_boolean }                   -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_volatile_object == const_volatile_boolean }             -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;

        { object == nkr::cpp::Move(boolean) }                           -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { object == nkr::cpp::Move(volatile_boolean) }                  -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_object == nkr::cpp::Move(boolean) }                     -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_object == nkr::cpp::Move(volatile_boolean) }            -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { volatile_object == nkr::cpp::Move(boolean) }                  -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { volatile_object == nkr::cpp::Move(volatile_boolean) }         -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_volatile_object == nkr::cpp::Move(boolean) }            -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_volatile_object == nkr::cpp::Move(volatile_boolean) }   -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;

        { object != boolean }                                           -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { object != const_boolean }                                     -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { object != volatile_boolean }                                  -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { object != const_volatile_boolean }                            -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_object != boolean }                                     -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_object != const_boolean }                               -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_object != volatile_boolean }                            -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_object != const_volatile_boolean }                      -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { volatile_object != boolean }                                  -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { volatile_object != const_boolean }                            -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { volatile_object != volatile_boolean }                         -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { volatile_object != const_volatile_boolean }                   -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_volatile_object != boolean }                            -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_volatile_object != const_boolean }                      -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_volatile_object != volatile_boolean }                   -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_volatile_object != const_volatile_boolean }             -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;

        { object != nkr::cpp::Move(boolean) }                           -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { object != nkr::cpp::Move(volatile_boolean) }                  -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_object != nkr::cpp::Move(boolean) }                     -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_object != nkr::cpp::Move(volatile_boolean) }            -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { volatile_object != nkr::cpp::Move(boolean) }                  -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { volatile_object != nkr::cpp::Move(volatile_boolean) }         -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_volatile_object != nkr::cpp::Move(boolean) }            -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { const_volatile_object != nkr::cpp::Move(volatile_boolean) }   -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
    });

}}}}

namespace nkr { namespace generic { namespace boolean {

    struct  any_tg  { class tag_lb; class generic_lb; };

    template <typename ...>
    struct  any_ttg {};

    template <typename type_p>
    concept any_tr =
        nkr::generic::implementing::self_tr<type_p> &&
        any_tr$::constructors_i<type_p> &&
        any_tr$::casts_i<type_p> &&
        any_tr$::operators_i<type_p>;

    template <template <typename ...> typename template_p>
    concept any_ttr =
        any_tr<typename interface::template_i<template_p>::example_t>;

}}}

namespace nkr { namespace generic { namespace boolean { namespace any_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::boolean::any_tg> type_p>
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

    template <nkr::cpp::is_any_tr<nkr::generic::boolean::any_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::generic::boolean::any_tr$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace generic { namespace boolean { namespace any_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::boolean::any_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_generic_tag_t<
        nkr::generic::boolean::any_tg,
        nkr::generic::boolean::any_ttg>
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
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::boolean::any_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::generic::boolean::any_tr$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/generic/boolean/any_tr_dec_def.h"

#endif
