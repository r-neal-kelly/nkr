/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/generic/implementing/constructor/default_tr_dec.h"

namespace nkr { namespace interface { namespace $template_i {

    template <typename type_p>
    concept aliases_i = requires
    {
        typename type_p::template type_t<nkr::none::type_t>;
    };

    template <typename type_p>
    concept objects_i =
        !generic::implementing::constructor::default_tr<type_p>;

}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
    class   template_i;

    struct  template_tg     {};

    template <template <typename ...> typename template_p>
    struct  template_ttg    {};

    template <typename type_p>
    concept template_tr =
        cpp::is_tr<typename type_p::template type_t<nkr::none::type_t>, typename template_i<type_p::template type_t>::template type_t<nkr::none::type_t>> &&
        $template_i::aliases_i<type_p> &&
        $template_i::objects_i<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::interface::template_tg>
    {
    public:
        using type_t    = nkr::interface::template_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::interface::template_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::interface::template_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;
    };

}}

#include "nkr/interface/template_i_dec_def.h"
