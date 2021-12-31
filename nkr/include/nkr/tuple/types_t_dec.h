/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

namespace nkr { namespace tuple { namespace $types_t {

    template <typename type_p>
    class   is_tmpl;

}}}

namespace nkr { namespace tuple {

    template <typename ...types_p>
    class   types_t;

    struct  types_tg    {};

    template <typename>
    struct  types_ttg   {};

    template <typename type_p>
    concept types_tr =
        $types_t::is_tmpl<cpp::just_non_qualified_t<type_p>>::Value();

}}

namespace nkr { namespace interface {
}}

namespace nkr { namespace interface {
}}

namespace nkr { namespace tuple { namespace $types_t {

    template <typename type_p>
    class is_tmpl :
        public boolean::cpp_c<false>
    {
    public:
    };

    template <typename head_p, typename ...tail_p>
    class is_tmpl<types_t<head_p, tail_p...>> :
        public boolean::cpp_c<true>
    {
    public:
    };

    template <typename tuple_p, positive::index_t index_p>
    class unit_t;

    template <typename head_p, typename ...tail_p>
    class unit_t<types_t<head_p, tail_p...>, 0>
    {
    public:
        using type_t    = head_p;
    };

    template <typename head_p, typename ...tail_p, positive::index_t index_p>
    class unit_t<types_t<head_p, tail_p...>, index_p> :
        public unit_t<types_t<tail_p...>, index_p - 1>
    {
    public:
    };

}}}

namespace nkr { namespace tuple {

    template <typename head_p, typename ...tail_p>
    class types_t<head_p, tail_p...>
    {
    public:
        template <positive::index_t index_p>
        using at_t  = $types_t::unit_t<types_t, index_p>::type_t;

    public:
        static constexpr positive::count_t  Count() noexcept;

    public:
        template <typename ...>
        constexpr types_t(...) noexcept = delete;
    };

}}

#include "nkr/tuple/types_t_dec_def.h"
