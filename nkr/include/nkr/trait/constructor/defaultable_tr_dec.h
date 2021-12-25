/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

namespace nkr { namespace trait { namespace constructor { namespace $defaultable_tr {

    template <typename type_p>
    concept constructors_i = requires
    {
        { cpp::just_non_qualified_t<type_p>() };
    };

}}}}

namespace nkr { namespace trait { namespace constructor {

    struct  defaultable_tg  {};

    template <typename>
    struct  defaultable_ttg {};

    template <typename type_p>
    concept defaultable_tr =
        $defaultable_tr::constructors_i<type_p>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<trait::constructor::defaultable_tg>
    {
    public:
        using of_t  = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <>
    class template_i<trait::constructor::defaultable_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = trait::constructor::defaultable_tg;

    public:
        static constexpr boolean::cpp_t Is_Implemented() noexcept;
    };

}}

#include "nkr/trait/constructor/defaultable_tr_dec_def.h"
