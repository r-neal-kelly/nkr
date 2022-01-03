/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/enumeration/types_i_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::interface::enumeration::types_tg>::Is_Any()
        noexcept
    {
        return nkr::interface::enumeration::types_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::interface::enumeration::types_ttg>::Is_Any()
        noexcept
    {
        return nkr::interface::enumeration::types_ttr<other_p>;
    }

}}

namespace nkr { namespace interface { namespace enumeration {

    template <$types_i::default_tr type_p>
    inline constexpr types_i<type_p>::integer_t
        types_i<type_p>::Default_None_Value()
        noexcept
    {
        if constexpr (nkr::generic::positive_tr<integer_t>) {
            return ~integer_t(0);
        } else if constexpr (nkr::generic::negatable_tr<integer_t>) {
            return integer_t(-1);
        } else {
            static_assert(false);
        }
    }

    template <$types_i::default_tr type_p>
    inline constexpr types_i<type_p>::integer_t
        types_i<type_p>::Value(const tr1<any_tg, type_t> auto& type)
        noexcept
    {
        return type;
    }

    template <$types_i::default_tr type_p>
    inline constexpr nkr::none::type_t
        types_i<type_p>::Value(tr1<any_non_const_tg, type_t> auto& type, integer_t integer)
        noexcept
    {
        type = integer;
    }

}}}
