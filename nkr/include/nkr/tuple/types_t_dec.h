/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_eadd843c_cd48_4c00_a610_d97d39c19b17
#define nkr_INCLUDE_GUARD_eadd843c_cd48_4c00_a610_d97d39c19b17

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/boolean/cpp_t_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/constant/positive/index_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"

namespace nkr { namespace tuple { namespace types_t$ {

    template <typename type_p>
    class   is_tmpl;

    class   dummy_t;

}}}

namespace nkr { namespace tuple {

    template <typename ...types_p>
    class   types_t;

    struct  types_tg    { class tag_lb; };

    template <typename ...>
    struct  types_ttg   {};

    template <typename type_p>
    concept types_tr =
        types_t$::is_tmpl<nkr::cpp::just_non_qualified_t<type_p>>::Value();

    template <template <typename ...> typename template_p>
    concept types_ttr =
        nkr::cpp::is_any_ttr<template_p, types_t, types_t$::dummy_t>;

}}

namespace nkr { namespace tuple { namespace types_t$ {

    template <nkr::tuple::types_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = typename type_t::head_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::tuple::types_tg> type_p>
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

    template <nkr::tuple::types_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::tuple::types_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::tuple::types_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::tuple::types_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace tuple { namespace types_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::tuple::types_ttr<template_p>
    class template_i_template_sp
    {
    public:
        template <typename ...types_p>
        using template_t                    = nkr::tuple::types_t<types_p...>;

        template <typename inner_p>
        using of_t                          = template_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
            requires (parameters_p::Count() >= 0)
        using of_tuple_t                    = typename parameters_p::template into_t<template_t>;

        template <typename ...parameters_p>
        using of_pack_t                     = of_tuple_t<nkr::tuple::types_t<parameters_p...>>;

        using example_arguments_t           = nkr::tuple::types_t<>;

        using example_t                     = of_t<nkr::tuple::types_t$::dummy_t>;

        template <typename ...types_p>
        using actual_template_t             = template_t<types_p...>;

        template <typename inner_p>
        using actual_of_t                   = of_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
        using actual_of_tuple_t             = of_tuple_t<parameters_p>;

        template <typename ...parameters_p>
        using actual_of_pack_t              = of_pack_t<parameters_p...>;

        using actual_example_arguments_t    = example_arguments_t;

        using actual_example_t              = example_t;

        using type_tg                       = nkr::tuple::types_tg;

        template <typename ...parameters_p>
        using template_ttg                  = nkr::tuple::types_ttg<parameters_p...>;

    public:
        static constexpr nkr::positive::count_t Min_Argument_Count() noexcept;
        static constexpr nkr::positive::count_t Max_Argument_Count() noexcept;
        static constexpr nkr::positive::count_t Actual_Min_Argument_Count() noexcept;
        static constexpr nkr::positive::count_t Actual_Max_Argument_Count() noexcept;

        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Actual() noexcept;

    public:
        template <typename ...>
        constexpr template_i_template_sp(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::tuple::types_ttg>
    class template_i_tag_sp :
        public template_i_template_sp<nkr::tuple::types_t>
    {
    public:
        template <typename ...parameters_p>
        using actual_template_t             = nkr::tuple::types_ttg<parameters_p...>;

        template <typename inner_p>
        using actual_of_t                   = actual_template_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
        using actual_of_tuple_t             = typename parameters_p::template into_t<actual_template_t>;

        template <typename ...parameters_p>
        using actual_of_pack_t              = actual_template_t<parameters_p...>;

        using actual_example_arguments_t    = nkr::tuple::types_t<>;

        using actual_example_t              = actual_template_t<>;

    public:
        static constexpr nkr::positive::count_t Actual_Min_Argument_Count() noexcept;
        static constexpr nkr::positive::count_t Actual_Max_Argument_Count() noexcept;

        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Actual() noexcept;
    };

}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::tuple::types_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::tuple::types_t$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::tuple::types_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::tuple::types_t$::template_i_tag_sp<template_p>;
    };

}}

namespace nkr { namespace tuple { namespace types_t$ {

    template <typename type_p>
    class is_tmpl :
        public nkr::constant::boolean::cpp_t<false>
    {
    public:
    };

    template <typename ...types_p>
    class is_tmpl<types_t<types_p...>> :
        public nkr::constant::boolean::cpp_t<true>
    {
    public:
    };

    template <typename head_p, typename ...tail_p>
    class is_tmpl<types_t<head_p, tail_p...>> :
        public nkr::constant::boolean::cpp_t<true>
    {
    public:
    };

}}}

namespace nkr { namespace tuple { namespace types_t$ {

    template <typename tuple_p, nkr::positive::index_t index_p>
    class at_tmpl;

    template <typename tuple_p>
    class at_tmpl<tuple_p, 0>
    {
    public:
        using type_t    = tuple_p;
    };

    template <typename tuple_p, nkr::positive::index_t index_p>
    class at_tmpl
    {
    public:
        using type_t    = typename at_tmpl<tuple_p, index_p - 1>::type_t::tail_t;
    };

    template <typename tuple_p, nkr::positive::count_t count_p>
    class take_tmpl;

    template <typename tuple_p>
    class take_tmpl<tuple_p, 0>
    {
    public:
        using type_t    = types_t<>;
    };

    template <typename tuple_p, nkr::positive::count_t count_p>
        requires (count_p > 0)
    class take_tmpl<tuple_p, count_p>
    {
    private:
        using front_t   = typename take_tmpl<tuple_p, count_p - 1>::type_t;

    public:
        using type_t    = typename front_t::template push_back_t<
            typename tuple_p::template at_t<nkr::constant::positive::index_t<count_p - 1>>::head_t
        >;
    };

    template <
        nkr::tuple::types_tr    subjects_p,
        nkr::tuple::types_tr    objects_p,
        typename                object_index_p
    > class each_with_each_tmpl;

    template <
        nkr::tuple::types_tr    subjects_p,
        nkr::tuple::types_tr    objects_p,
        typename                object_index_p
    >
        requires (subjects_p::Count() > 0 && object_index_p::Value() < objects_p::Count())
    class each_with_each_tmpl<subjects_p, objects_p, object_index_p>
    {
    public:
        using type_t = typename each_with_each_tmpl<
            subjects_p, objects_p, nkr::constant::positive::index_t<object_index_p::Value() + 1>
        >::type_t::template push_front_t<
            nkr::tuple::types_t<typename subjects_p::head_t, typename objects_p::template at_t<object_index_p>::head_t>
        >;
    };

    template <
        nkr::tuple::types_tr    subjects_p,
        nkr::tuple::types_tr    objects_p,
        typename                object_index_p
    >
        requires (subjects_p::Count() > 0 && object_index_p::Value() == objects_p::Count())
    class each_with_each_tmpl<subjects_p, objects_p, object_index_p>
    {
    public:
        using type_t = typename each_with_each_tmpl<
            typename subjects_p::tail_t, objects_p, nkr::constant::positive::index_t<0>
        >::type_t;
    };

    template <
        nkr::tuple::types_tr    subjects_p,
        nkr::tuple::types_tr    objects_p,
        typename                object_index_p
    >
        requires (subjects_p::Count() == 0)
    class each_with_each_tmpl<subjects_p, objects_p, object_index_p>
    {
    public:
        using type_t = nkr::tuple::types_t<>;
    };

    template <
        nkr::tuple::types_tr    subjects_p,
        nkr::tuple::types_tr    objects_p
    > using each_with_each_t =
        typename each_with_each_tmpl<subjects_p, objects_p, nkr::constant::positive::index_t<0>>::type_t;

}}}

namespace nkr { namespace tuple {

    template <typename ...types_p>
    class types_t
    {
    public:
        using head_t            = nkr::none::type_t;
        using tail_t            = types_t<>;

        template <nkr::constant::positive::index_tr count_p>
            requires (count_p::Value() == 0)
        using at_t              = types_t<>;

        template <nkr::constant::positive::count_tr count_p>
            requires (count_p::Value() == 0)
        using take_t            = types_t<>;

        template <template <typename ...> typename template_p>
        using into_t            = template_p<>;
        template <template <typename ...> typename template_p, typename ...back_types_p>
        using into_front_t      = template_p<back_types_p...>;
        template <template <typename ...> typename template_p, typename ...front_types_p>
        using into_back_t       = template_p<front_types_p...>;

        template <typename ...types_to_push_p>
        using push_front_t      = types_t<types_to_push_p...>;
        template <typename ...types_to_push_p>
        using push_back_t       = types_t<types_to_push_p...>;

        template <nkr::tuple::types_tr tuple_p>
        using apply_front_t     = tuple_p::template into_t<push_front_t>;
        template <nkr::tuple::types_tr tuple_p>
        using apply_back_t      = tuple_p::template into_t<push_back_t>;

        template <nkr::tuple::types_tr tuple_p>
        using each_with_each_t  = types_t$::each_with_each_t<types_t, tuple_p>;

    public:
        static constexpr nkr::positive::count_t Count() noexcept;

        template <typename iterator_p>
        static constexpr nkr::none::type_t      Iterate_Forward() noexcept;
        static constexpr nkr::none::type_t      Iterate_Forward(auto& iterator) noexcept;

        template <typename algorithm_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        static constexpr nkr::boolean::cpp_t    AND(auto& algorithm) noexcept;

    public:
        template <typename ...>
        constexpr types_t(...) noexcept = delete;
    };

}}

namespace nkr { namespace tuple {

    template <typename head_p, typename ...tail_p>
    class types_t<head_p, tail_p...>
    {
    public:
        using head_t            = head_p;
        using tail_t            = types_t<tail_p...>;

        template <nkr::constant::positive::index_tr index_p>
            requires (index_p::Value() <= 1 + sizeof...(tail_p))
        using at_t              = typename types_t$::at_tmpl<types_t, index_p::Value()>::type_t;

        template <nkr::constant::positive::count_tr count_p>
            requires (count_p::Value() <= 1 + sizeof...(tail_p))
        using take_t            = typename types_t$::take_tmpl<types_t, count_p::Value()>::type_t;

        template <template <typename ...> typename template_p>
        using into_t            = template_p<head_p, tail_p...>;
        template <template <typename ...> typename template_p, typename ...back_types_p>
        using into_front_t      = template_p<head_p, tail_p..., back_types_p...>;
        template <template <typename ...> typename template_p, typename ...front_types_p>
        using into_back_t       = template_p<front_types_p..., head_p, tail_p...>;

        template <typename ...types_to_push_p>
        using push_front_t      = types_t<types_to_push_p..., head_p, tail_p...>;
        template <typename ...types_to_push_p>
        using push_back_t       = types_t<head_p, tail_p..., types_to_push_p...>;

        template <nkr::tuple::types_tr tuple_p>
        using apply_front_t     = tuple_p::template into_t<push_front_t>;
        template <nkr::tuple::types_tr tuple_p>
        using apply_back_t      = tuple_p::template into_t<push_back_t>;

        template <nkr::tuple::types_tr tuple_p>
        using each_with_each_t  = types_t$::each_with_each_t<types_t, tuple_p>;

    public:
        static constexpr nkr::positive::count_t Count() noexcept;

        template <typename iterator_p>
        static constexpr nkr::none::type_t      Iterate_Forward() noexcept;
        static constexpr nkr::none::type_t      Iterate_Forward(auto& iterator) noexcept;

        template <typename algorithm_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        static constexpr nkr::boolean::cpp_t    AND(auto& algorithm) noexcept;

    public:
        template <typename ...>
        constexpr types_t(...) noexcept = delete;
    };

}}

#include "nkr/tuple/types_t_dec_def.h"

#endif
