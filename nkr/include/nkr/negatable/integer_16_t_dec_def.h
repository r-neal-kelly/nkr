/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_df4036f7_dbf2_4ab4_a47a_b2691249fe18
#define nkr_INCLUDE_GUARD_df4036f7_dbf2_4ab4_a47a_b2691249fe18

#include "nkr/negatable/integer_16_t_dec.h"

namespace nkr { namespace negatable { namespace integer_16_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::negatable::integer_16_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::negatable::integer_16_tg>;
    }

    template <nkr::negatable::integer_16_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::negatable::integer_16_t$::Is_Any_General<other_p>();
    }

    template <nkr::negatable::integer_16_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::negatable::integer_16_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::negatable::integer_16_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::negatable::integer_16_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

namespace nkr { namespace negatable { namespace integer_16_t$ {

    template <nkr::negatable::integer_16_tr type_p>
    inline constexpr none_value_i_sp<type_p>::value_t
        none_value_i_sp<type_p>::Value()
        noexcept
    {
        return value_t();
    }

}}}

namespace nkr { namespace negatable { namespace integer_16_t$ {

    template <nkr::negatable::integer_16_tr type_p>
    inline constexpr enumeration_types_i_sp<type_p>::integer_t
        enumeration_types_i_sp<type_p>::Default_Integer()
        noexcept
    {
        return value_t(~0);
    }

    template <nkr::negatable::integer_16_tr type_p>
    inline constexpr enumeration_types_i_sp<type_p>::integer_t
        enumeration_types_i_sp<type_p>::Integer(const tr<any_tg, t<value_t>> auto& value)
        noexcept
    {
        return value;
    }

    template <nkr::negatable::integer_16_tr type_p>
    inline constexpr nkr::none::type_t
        enumeration_types_i_sp<type_p>::Integer(tr<any_non_const_tg, t<value_t>> auto& value, integer_t integer)
        noexcept
    {
        value = integer;
    }

}}}

namespace nkr { namespace negatable { namespace integer_16_t$ {

    template <nkr::negatable::integer_16_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::value_t
        randomness_distributor_uniform_i_sp<type_p>::Default_Min()
        noexcept
    {
        return nkr::cpp::Default_Min<value_t>();
    }

    template <nkr::negatable::integer_16_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::value_t
        randomness_distributor_uniform_i_sp<type_p>::Default_Max()
        noexcept
    {
        return nkr::cpp::Default_Max<value_t>();
    }

    template <nkr::negatable::integer_16_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::number_t
        randomness_distributor_uniform_i_sp<type_p>::To_Number(value_t value)
        noexcept
    {
        return value;
    }

    template <nkr::negatable::integer_16_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::value_t
        randomness_distributor_uniform_i_sp<type_p>::From_Number(number_t number)
        noexcept
    {
        return number;
    }

}}}

#endif
