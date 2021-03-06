/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_4d15c9b7_7ea6_4e97_8749_a1ad5ec7f86a
#define nkr_INCLUDE_GUARD_4d15c9b7_7ea6_4e97_8749_a1ad5ec7f86a

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/boolean/cpp_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/implementing/constructor/default_tr_dec.h"
#include "nkr/interface/forward_dec.h"

namespace nkr { namespace interface { namespace template_i$ {

    template <typename type_p>
    class is_tmpl :
        public nkr::constant::boolean::cpp_t<false>
    {
    public:
    };

    template <template <typename ...> typename template_p>
    class is_tmpl<nkr::interface::template_i<template_p>> :
        public nkr::constant::boolean::cpp_t<true>
    {
    public:
    };

    template <typename ...>
    class dummy_t;

    /*
        Because some special implementations cannot have the existence of their
        template_t alias checked. This is a terrible solution. I really just
        want to know if an implementation has an alias called 'template_t',
        but the language affords no way to determine the existence of a
        template alias that takes multiple kinds of template parameters.
    */
    template <typename type_p>
    concept special_i =
        nkr::cpp::is_any_tr<type_p, nkr::interface::template_i<nkr::constant_ttg>>;

    template <typename type_p>
    concept aliases_i =
        nkr::cpp::is_ttr<type_p::template template_t, type_p::template template_t> &&
        nkr::cpp::is_ttr<type_p::template of_t, type_p::template of_t> &&
        nkr::cpp::is_ttr<type_p::template of_tuple_t, type_p::template of_tuple_t> &&
        nkr::cpp::is_ttr<type_p::template of_pack_t, type_p::template of_pack_t> &&
        nkr::cpp::is_tr<typename type_p::example_arguments_t, typename type_p::example_arguments_t> &&
        nkr::cpp::is_tr<typename type_p::example_t, typename type_p::example_t> &&

        nkr::cpp::is_ttr<type_p::template actual_template_t, type_p::template actual_template_t> &&
        nkr::cpp::is_ttr<type_p::template actual_of_t, type_p::template actual_of_t> &&
        nkr::cpp::is_ttr<type_p::template actual_of_tuple_t, type_p::template actual_of_tuple_t> &&
        nkr::cpp::is_ttr<type_p::template actual_of_pack_t, type_p::template actual_of_pack_t> &&
        nkr::cpp::is_tr<typename type_p::actual_example_arguments_t, typename type_p::actual_example_arguments_t> &&
        nkr::cpp::is_tr<typename type_p::actual_example_t, typename type_p::actual_example_t> &&
        
        nkr::cpp::is_tr<typename type_p::type_tg, typename type_p::type_tg> &&
        nkr::cpp::is_ttr<type_p::template template_ttg, type_p::template template_ttg>;

    template <typename type_p>
    concept static_constexpr_functions_i = requires
    {
        { type_p::Min_Argument_Count() }                -> nkr::cpp::is_tr<nkr::positive::count_t>;
        { type_p::Max_Argument_Count() }                -> nkr::cpp::is_tr<nkr::positive::count_t>;
        { type_p::Actual_Min_Argument_Count() }         -> nkr::cpp::is_tr<nkr::positive::count_t>;
        { type_p::Actual_Max_Argument_Count() }         -> nkr::cpp::is_tr<nkr::positive::count_t>;

        { type_p::template Is_Any<dummy_t>() }          -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
        { type_p::template Is_Any_Actual<dummy_t>() }   -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
    };

    template <typename type_p>
    concept objects_i =
        !nkr::generic::implementing::constructor::default_tr<type_p>;

}}}

namespace nkr { namespace interface {

    struct  template_tg     { class tag_lb; };

    template <template <typename ...> typename ...>
    struct  template_tttg   {};

    template <typename type_p>
    concept template_tr =
        template_i$::special_i<type_p> ||
        (template_i$::is_tmpl<type_p>::Value() &&
         template_i$::aliases_i<type_p> &&
         template_i$::static_constexpr_functions_i<type_p> &&
         template_i$::objects_i<type_p>);

}}

namespace nkr { namespace interface { namespace template_i$ {

    template <nkr::interface::template_tr type_p>
    class type_i_type_sp
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
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::interface::template_tg> type_p>
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

    template <nkr::interface::template_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::interface::template_i$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::interface::template_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::interface::template_i$::type_i_tag_sp<type_p>;
    };

}}

#include "nkr/interface/template_i_dec_def.h"

#endif
