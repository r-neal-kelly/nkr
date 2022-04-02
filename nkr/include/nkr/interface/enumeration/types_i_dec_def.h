/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_4acd2578_c9ea_431c_9c84_40ce13a7662e
#define nkr_INCLUDE_GUARD_4acd2578_c9ea_431c_9c84_40ce13a7662e

#include "nkr/interface/enumeration/types_i_dec.h"

namespace nkr { namespace interface { namespace enumeration { namespace types_i$ {

    template <nkr::cpp::is_any_tr<example_t> type_p>
    inline constexpr example_types_i_sp<type_p>::integer_t
        example_types_i_sp<type_p>::Default_Integer()
        noexcept
    {
        return value_t(~0);
    }

    template <nkr::cpp::is_any_tr<example_t> type_p>
    inline constexpr example_types_i_sp<type_p>::integer_t
        example_types_i_sp<type_p>::Integer(const tr<any_tg, t<value_t>> auto& value)
        noexcept
    {
        return static_cast<integer_t>(value);
    }

    template <nkr::cpp::is_any_tr<example_t> type_p>
    inline constexpr nkr::none::type_t
        example_types_i_sp<type_p>::Integer(tr<any_non_const_tg, t<value_t>> auto& value, integer_t integer)
        noexcept
    {
        value = static_cast<value_t>(integer);
    }

}}}}

namespace nkr { namespace interface { namespace enumeration { namespace types_i$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::interface::enumeration::types_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::interface::enumeration::types_tg>;
    }

    template <nkr::interface::enumeration::types_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::interface::enumeration::types_i$::Is_Any_General<other_p>();
    }

    template <nkr::interface::enumeration::types_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::interface::enumeration::types_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::interface::enumeration::types_i$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::interface::enumeration::types_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
