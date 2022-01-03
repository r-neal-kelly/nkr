/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/enumeration/types_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::enumeration::types_tg>::Is_Any()
        noexcept
    {
        return nkr::enumeration::types_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::enumeration::types_ttg>::Is_Any()
        noexcept
    {
        return nkr::enumeration::types_ttr<other_p>;
    }

}}

namespace nkr { namespace interface { namespace none {

    template <nkr::enumeration::types_tr type_p>
    inline constexpr value_i<type_p>::type_t
        value_i<type_p>::Value()
        noexcept
    {
        return type_t();
    }

}}}

namespace nkr { namespace enumeration {

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr auto&
        types_t<value_p, none_p>::Assign_Copy(tr1<any_non_const_tg, types_t> auto& self, const tr1<any_tg, types_t> auto& other)
        noexcept
    {
        if (self != cpp::Address(other)) {
            self.value = other.value;
        }

        return self;
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr auto&
        types_t<value_p, none_p>::Assign_Move(tr1<any_non_const_tg, types_t> auto& self, tr1<any_non_const_tg, types_t> auto&& other)
        noexcept
    {
        if (self != cpp::Address(other)) {
            self.value = cpp::Move(other.value);
        }

        return self;
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::types_t() noexcept :
        value(none_t::Value())
    {
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::types_t(const value_t& value) noexcept :
        value(value)
    {
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::types_t(const volatile value_t& value) noexcept :
        value(value)
    {
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::types_t(value_t&& value) noexcept :
        value(cpp::Move(value))
    {
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::types_t(volatile value_t&& value) noexcept :
        value(cpp::Move(value))
    {
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::types_t(const tr1<any_to_tg, integer_t> auto& value) noexcept :
        value(static_cast<integer_t>(value))
    {
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::types_t(const types_t& other) noexcept :
        value(other.value)
    {
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::types_t(const volatile types_t& other) noexcept :
        value(other.value)
    {
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::types_t(types_t&& other) noexcept :
        value(cpp::Move(other.value))
    {
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::types_t(volatile types_t&& other) noexcept :
        value(cpp::Move(other.value))
    {
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(const types_t& other)
        noexcept
    {
        return Assign_Copy(*this, other);
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr volatile types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(const types_t& other)
        volatile noexcept
    {
        return Assign_Copy(*this, other);
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(const volatile types_t& other)
        noexcept
    {
        return Assign_Copy(*this, other);
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr volatile types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(const volatile types_t& other)
        volatile noexcept
    {
        return Assign_Copy(*this, other);
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(types_t&& other)
        noexcept
    {
        return Assign_Move(*this, cpp::Move(other));
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr volatile types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(types_t&& other)
        volatile noexcept
    {
        return Assign_Move(*this, cpp::Move(other));
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(volatile types_t&& other)
        noexcept
    {
        return Assign_Move(*this, cpp::Move(other));
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr volatile types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(volatile types_t&& other)
        volatile noexcept
    {
        return Assign_Move(*this, cpp::Move(other));
    }

#if defined(nkr_IS_DEBUG)
    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::~types_t() noexcept
    {
        this->value = none_t::Value();
    }
#endif

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::operator integer_t()
        const noexcept
    {
        return interface_t::Value(this->value);
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::operator integer_t()
        const volatile noexcept
    {
        return interface_t::Value(this->value);
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::operator boolean::cpp_t()
        const noexcept
    {
        return interface_t::Value(this->value) != none_t::Value();
    }

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::operator boolean::cpp_t()
        const volatile noexcept
    {
        return interface_t::Value(this->value) != none_t::Value();
    }

}}
