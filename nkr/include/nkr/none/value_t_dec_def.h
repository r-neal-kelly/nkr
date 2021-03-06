/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_799472c2_d23a_4d3c_bdec_62805e66cc22
#define nkr_INCLUDE_GUARD_799472c2_d23a_4d3c_bdec_62805e66cc22

#include "nkr/none/value_t_dec.h"

namespace nkr { namespace none { namespace value_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::none::value_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::none::value_tg>;
    }

    template <nkr::none::value_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::none::value_t$::Is_Any_General<other_p>();
    }

    template <nkr::none::value_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::none::value_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::none::value_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::none::value_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

namespace nkr { namespace none {

    template <nkr::generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::type_t value_t<type_p>::Value()
        noexcept
    {
        return interface_t::Value();
    }

    template <nkr::generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::value_t() noexcept
    {
    }

    template <nkr::generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::value_t(const value_t& other) noexcept
    {
    }

    template <nkr::generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::value_t(const volatile value_t& other) noexcept
    {
    }

    template <nkr::generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::value_t(value_t&& other) noexcept
    {
    }

    template <nkr::generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::value_t(volatile value_t&& other) noexcept
    {
    }

    template <nkr::generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>&
        value_t<type_p>::operator =(const value_t& other)
        noexcept
    {
        return *this;
    }

    template <nkr::generic::implementing::interface::none::value_tr type_p>
    inline constexpr volatile value_t<type_p>&
        value_t<type_p>::operator =(const value_t& other)
        volatile noexcept
    {
        return *this;
    }

    template <nkr::generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>&
        value_t<type_p>::operator =(const volatile value_t& other)
        noexcept
    {
        return *this;
    }

    template <nkr::generic::implementing::interface::none::value_tr type_p>
    inline constexpr volatile value_t<type_p>&
        value_t<type_p>::operator =(const volatile value_t& other)
        volatile noexcept
    {
        return *this;
    }

    template <nkr::generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>&
        value_t<type_p>::operator =(value_t&& other)
        noexcept
    {
        return *this;
    }

    template <nkr::generic::implementing::interface::none::value_tr type_p>
    inline constexpr volatile value_t<type_p>&
        value_t<type_p>::operator =(value_t&& other)
        volatile noexcept
    {
        return *this;
    }

    template <nkr::generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>&
        value_t<type_p>::operator =(tr<just_volatile_tg, t<value_t>> auto&& other)
        noexcept
    {
        return *this;
    }

    template <nkr::generic::implementing::interface::none::value_tr type_p>
    inline constexpr volatile value_t<type_p>&
        value_t<type_p>::operator =(tr<just_volatile_tg, t<value_t>> auto&& other)
        volatile noexcept
    {
        return *this;
    }

#if defined(nkr_IS_DEBUG)
    template <nkr::generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::~value_t() noexcept
    {
    }
#endif

    template <nkr::generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::operator value_t<type_p>::type_t()
        const noexcept
    {
        return interface_t::Value();
    }

    template <nkr::generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::operator value_t<type_p>::type_t()
        const volatile noexcept
    {
        return interface_t::Value();
    }

    template <nkr::generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::type_t value_t<type_p>::operator ()()
        const noexcept
    {
        return interface_t::Value();
    }

    template <nkr::generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::type_t value_t<type_p>::operator ()()
        const volatile noexcept
    {
        return interface_t::Value();
    }

}}

inline constexpr nkr::boolean::cpp_t
    operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::none::value_tg>> auto& a, const auto& b)
    noexcept
{
    using a_t = nkr::cpp::reference_value_t<decltype(a)>;
    using b_t = nkr::cpp::reference_value_t<decltype(b)>;

    if constexpr (nkr::cpp::is_any_tr<b_t, a_t>) {
        return a() == b();
    } else if constexpr (nkr::cpp::to_tr<b_t, nkr::cpp::just_non_qualified_t<typename a_t::type_t>>) {
        return a() == static_cast<nkr::cpp::just_non_qualified_t<typename a_t::type_t>>(b);
    } else if constexpr (nkr::cpp::to_tr<b_t, nkr::cpp::just_non_qualified_t<a_t>>) {
        return a == static_cast<nkr::cpp::just_non_qualified_t<a_t>>(b);
    } else if constexpr (nkr::cpp::to_tr<a_t, nkr::cpp::just_non_qualified_t<b_t>>) {
        return static_cast<nkr::cpp::just_non_qualified_t<b_t>>(a) == b;
    } else {
        [] <nkr::boolean::cpp_t _ = false>() { static_assert(_, "these two values can not be compared."); }();
    }
}

inline constexpr nkr::boolean::cpp_t
    operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::none::value_tg>> auto& a, const auto&& b)
    noexcept
{
    return operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::none::value_tg>> auto&& a, const auto& b)
    noexcept
{
    return operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::none::value_tg>> auto&& a, const auto&& b)
    noexcept
{
    return operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::none::value_tg>> auto& a, const auto& b)
    noexcept
{
    return !operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::none::value_tg>> auto& a, const auto&& b)
    noexcept
{
    return !operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::none::value_tg>> auto&& a, const auto& b)
    noexcept
{
    return !operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::none::value_tg>> auto&& a, const auto&& b)
    noexcept
{
    return !operator ==(a, b);
}

#endif
