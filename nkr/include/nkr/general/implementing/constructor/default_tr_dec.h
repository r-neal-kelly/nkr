/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

namespace nkr { namespace general { namespace implementing { namespace constructor { namespace $default_tr {

    template <typename type_p>
    concept constructors_i = requires
    {
        { cpp::just_non_qualified_t<type_p>() };
    };

}}}}}

namespace nkr { namespace general { namespace implementing { namespace constructor {

    struct  default_tg  {};

    template <typename>
    struct  default_ttg {};

    template <typename type_p>
    concept default_tr =
        $default_tr::constructors_i<type_p>;

}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::general::implementing::constructor::default_tg>
    {
    public:
        using of_t  = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;
    };

    template <>
    class template_i<nkr::general::implementing::constructor::default_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = nkr::general::implementing::constructor::default_tg;

    public:
        static constexpr nkr::boolean::cpp_t    Is_Implemented() noexcept;
    };

}}

#include "nkr/general/implementing/constructor/default_tr_dec_def.h"
