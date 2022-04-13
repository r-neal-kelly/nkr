/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_8932856c_a4b8_4fd1_a679_3e687e4f1f5f
#define nkr_INCLUDE_GUARD_8932856c_a4b8_4fd1_a679_3e687e4f1f5f

#include "nkr/enumeration/errors_t_dec.h"

namespace nkr { namespace enumeration { namespace errors_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::enumeration::errors_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::enumeration::errors_tg>;
    }

    template <nkr::enumeration::errors_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::enumeration::errors_t$::Is_Any_General<other_p>();
    }

    template <nkr::enumeration::errors_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::enumeration::errors_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::enumeration::errors_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::enumeration::errors_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

namespace nkr { namespace enumeration { namespace errors_t$ {

    class common_t
    {
    public:
    };

}}}

namespace nkr { namespace enumeration { namespace errors_t$ {

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>::generic_sp() noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>::generic_sp(const tr<to_tg, t<integer_t>> auto& to_integer) noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>::generic_sp(tr<to_tg, t<integer_t>> auto&& to_integer) noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>::generic_sp(const value_t& value) noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline generic_sp<value_p>::generic_sp(const volatile value_t& value) noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>::generic_sp(value_t&& value) noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline generic_sp<value_p>::generic_sp(volatile value_t&& value) noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>::generic_sp(const generic_sp& other) noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline generic_sp<value_p>::generic_sp(const volatile generic_sp& other) noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>::generic_sp(generic_sp&& other) noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline generic_sp<value_p>::generic_sp(volatile generic_sp&& other) noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>&
        generic_sp<value_p>::operator =(const tr<to_tg, t<integer_t>> auto& to_integer)
        noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline volatile generic_sp<value_p>&
        generic_sp<value_p>::operator =(const tr<to_tg, t<integer_t>> auto& to_integer)
        volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>&
        generic_sp<value_p>::operator =(tr<to_tg, t<integer_t>> auto&& to_integer)
        noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline volatile generic_sp<value_p>&
        generic_sp<value_p>::operator =(tr<to_tg, t<integer_t>> auto&& to_integer)
        volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>&
        generic_sp<value_p>::operator =(const value_t& value)
        noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline volatile generic_sp<value_p>&
        generic_sp<value_p>::operator =(const value_t& value)
        volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline generic_sp<value_p>&
        generic_sp<value_p>::operator =(const volatile value_t& value)
        noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline volatile generic_sp<value_p>&
        generic_sp<value_p>::operator =(const volatile value_t& value)
        volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>&
        generic_sp<value_p>::operator =(value_t&& value)
        noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline volatile generic_sp<value_p>&
        generic_sp<value_p>::operator =(value_t&& value)
        volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline generic_sp<value_p>&
        generic_sp<value_p>::operator =(tr<just_volatile_tg, t<value_t>> auto&& value)
        noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline volatile generic_sp<value_p>&
        generic_sp<value_p>::operator =(tr<just_volatile_tg, t<value_t>> auto&& value)
        volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>&
        generic_sp<value_p>::operator =(const generic_sp& other)
        noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline volatile generic_sp<value_p>&
        generic_sp<value_p>::operator =(const generic_sp& other)
        volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline generic_sp<value_p>&
        generic_sp<value_p>::operator =(const volatile generic_sp& other)
        noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline volatile generic_sp<value_p>&
        generic_sp<value_p>::operator =(const volatile generic_sp& other)
        volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>&
        generic_sp<value_p>::operator =(generic_sp&& other)
        noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline volatile generic_sp<value_p>&
        generic_sp<value_p>::operator =(generic_sp&& other)
        volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline generic_sp<value_p>&
        generic_sp<value_p>::operator =(tr<just_volatile_tg, t<generic_sp>> auto&& other)
        noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline volatile generic_sp<value_p>&
        generic_sp<value_p>::operator =(tr<just_volatile_tg, t<generic_sp>> auto&& other)
        volatile noexcept;

#if defined(nkr_IS_DEBUG)
    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>::~generic_sp() noexcept;
#endif

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr typename generic_sp<value_p>::integer_t
        generic_sp<value_p>::Integer()
        const noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline typename generic_sp<value_p>::integer_t
        generic_sp<value_p>::Integer()
        const volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>&
        generic_sp<value_p>::Integer(const tr<to_tg, t<integer_t>> auto& to_integer)
        noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline volatile generic_sp<value_p>&
        generic_sp<value_p>::Integer(const tr<to_tg, t<integer_t>> auto& to_integer)
        volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>&
        generic_sp<value_p>::Integer(tr<to_tg, t<integer_t>> auto&& to_integer)
        noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline volatile generic_sp<value_p>&
        generic_sp<value_p>::Integer(tr<to_tg, t<integer_t>> auto&& to_integer)
        volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr typename generic_sp<value_p>::value_t&
        generic_sp<value_p>::Value()
        noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr const typename generic_sp<value_p>::value_t&
        generic_sp<value_p>::Value()
        const noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline volatile typename generic_sp<value_p>::value_t&
        generic_sp<value_p>::Value()
        volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline const volatile typename generic_sp<value_p>::value_t&
        generic_sp<value_p>::Value()
        const volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>&
        generic_sp<value_p>::Value(const tr<any_tg, t<value_t>> auto& value)
        noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline volatile generic_sp<value_p>&
        generic_sp<value_p>::Value(const tr<any_tg, t<value_t>> auto& value)
        volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>&
        generic_sp<value_p>::Value(tr<any_non_const_tg, t<value_t>> auto&& value)
        noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline volatile generic_sp<value_p>&
        generic_sp<value_p>::Value(tr<any_non_const_tg, t<value_t>> auto&& value)
        volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr nkr::none::type_t
        generic_sp<value_p>::Ignore()
        const noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline nkr::none::type_t
        generic_sp<value_p>::Ignore()
        const volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>::operator generic_sp<value_p>::integer_t()
        const noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline generic_sp<value_p>::operator generic_sp<value_p>::integer_t()
        const volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>::operator nkr::boolean::cpp_t()
        const noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline generic_sp<value_p>::operator nkr::boolean::cpp_t()
        const volatile noexcept;

}}}

#endif
