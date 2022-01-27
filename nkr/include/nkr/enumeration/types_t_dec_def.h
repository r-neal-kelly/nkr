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
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr auto&
        types_t<value_p, none_p>::Assign_Integer(tr1<any_non_const_tg, types_t> auto& self,
                                                 const tr1<any_to_tg, integer_t> auto& to_integer)
        noexcept
    {
        interface_t::Value(self.value, static_cast<integer_t>(to_integer));

        return self;
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr auto&
        types_t<value_p, none_p>::Assign_Value(tr1<any_non_const_tg, types_t> auto& self,
                                               const tr1<any_tg, value_t> auto& other)
        noexcept
    {
        self.value = other;

        return self;
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr auto&
        types_t<value_p, none_p>::Assign_Value(tr1<any_non_const_tg, types_t> auto& self,
                                               tr1<any_non_const_tg, value_t> auto&& other)
        noexcept
    {
        self.value = nkr::cpp::Move(other);

        return self;
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr auto&
        types_t<value_p, none_p>::Assign_Types(tr1<any_non_const_tg, types_t> auto& self,
                                               const tr1<any_tg, types_t> auto& other)
        noexcept
    {
        if (&self != nkr::cpp::Address(other)) {
            self.value = other.value;
        }

        return self;
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr auto&
        types_t<value_p, none_p>::Assign_Types(tr1<any_non_const_tg, types_t> auto& self,
                                               tr1<any_non_const_tg, types_t> auto&& other)
        noexcept
    {
        if (&self != nkr::cpp::Address(other)) {
            self.value = nkr::cpp::Move(other.value);
        }

        return self;
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::types_t() noexcept :
        value(none_t::Value())
    {
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::types_t(const tr1<any_to_tg, integer_t> auto& to_integer) noexcept :
        value(static_cast<integer_t>(to_integer))
    {
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::types_t(const value_t& value) noexcept :
        value(value)
    {
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::types_t(const volatile value_t& value) noexcept :
        value(value)
    {
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::types_t(value_t&& value) noexcept :
        value(nkr::cpp::Move(value))
    {
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::types_t(volatile value_t&& value) noexcept :
        value(nkr::cpp::Move(value))
    {
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::types_t(const types_t& other) noexcept :
        value(other.value)
    {
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::types_t(const volatile types_t& other) noexcept :
        value(other.value)
    {
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::types_t(types_t&& other) noexcept :
        value(nkr::cpp::Move(other.value))
    {
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::types_t(volatile types_t&& other) noexcept :
        value(nkr::cpp::Move(other.value))
    {
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(const tr1<any_to_tg, integer_t> auto& to_integer)
        noexcept
    {
        return Assign_Integer(*this, to_integer);
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr volatile types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(const tr1<any_to_tg, integer_t> auto& to_integer)
        volatile noexcept
    {
        return Assign_Integer(*this, to_integer);
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(const value_t& value)
        noexcept
    {
        return Assign_Value(*this, value);
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr volatile types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(const value_t& value)
        volatile noexcept
    {
        return Assign_Value(*this, value);
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(const volatile value_t& value)
        noexcept
    {
        return Assign_Value(*this, value);
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr volatile types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(const volatile value_t& value)
        volatile noexcept
    {
        return Assign_Value(*this, value);
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(value_t&& value)
        noexcept
    {
        return Assign_Value(*this, nkr::cpp::Move(value));
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr volatile types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(value_t&& value)
        volatile noexcept
    {
        return Assign_Value(*this, nkr::cpp::Move(value));
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(volatile value_t&& value)
        noexcept
    {
        return Assign_Value(*this, nkr::cpp::Move(value));
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr volatile types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(volatile value_t&& value)
        volatile noexcept
    {
        return Assign_Value(*this, nkr::cpp::Move(value));
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(const types_t& other)
        noexcept
    {
        return Assign_Types(*this, other);
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr volatile types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(const types_t& other)
        volatile noexcept
    {
        return Assign_Types(*this, other);
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(const volatile types_t& other)
        noexcept
    {
        return Assign_Types(*this, other);
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr volatile types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(const volatile types_t& other)
        volatile noexcept
    {
        return Assign_Types(*this, other);
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(types_t&& other)
        noexcept
    {
        return Assign_Types(*this, nkr::cpp::Move(other));
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr volatile types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(types_t&& other)
        volatile noexcept
    {
        return Assign_Types(*this, nkr::cpp::Move(other));
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(volatile types_t&& other)
        noexcept
    {
        return Assign_Types(*this, nkr::cpp::Move(other));
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr volatile types_t<value_p, none_p>&
        types_t<value_p, none_p>::operator =(volatile types_t&& other)
        volatile noexcept
    {
        return Assign_Types(*this, nkr::cpp::Move(other));
    }

#if defined(nkr_IS_DEBUG)
    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::~types_t() noexcept
    {
        interface_t::Value(this->value, none_t::Value());
    }
#endif

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::integer_t
        types_t<value_p, none_p>::Integer()
        const noexcept
    {
        return interface_t::Integer(this->value);
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::integer_t
        types_t<value_p, none_p>::Integer()
        const volatile noexcept
    {
        return interface_t::Integer(this->value);
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>&
        types_t<value_p, none_p>::Integer(const tr1<any_to_tg, integer_t> auto& to_integer)
        noexcept
    {
        return Assign_Integer(*this, to_integer);
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr volatile types_t<value_p, none_p>&
        types_t<value_p, none_p>::Integer(const tr1<any_to_tg, integer_t> auto& to_integer)
        volatile noexcept
    {
        return Assign_Integer(*this, to_integer);
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr const types_t<value_p, none_p>::value_t&
        types_t<value_p, none_p>::Value()
        const noexcept
    {
        return this->value;
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr const volatile types_t<value_p, none_p>::value_t&
        types_t<value_p, none_p>::Value()
        const volatile noexcept
    {
        return this->value;
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>&
        types_t<value_p, none_p>::Value(const tr1<any_tg, value_t> auto& value)
        noexcept
    {
        return Assign_Value(*this, value);
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr volatile types_t<value_p, none_p>&
        types_t<value_p, none_p>::Value(const tr1<any_tg, value_t> auto& value)
        volatile noexcept
    {
        return Assign_Value(*this, value);
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>&
        types_t<value_p, none_p>::Value(tr1<any_non_const_tg, value_t> auto&& value)
        noexcept
    {
        return Assign_Value(*this, nkr::cpp::Move(value));
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr volatile types_t<value_p, none_p>&
        types_t<value_p, none_p>::Value(tr1<any_non_const_tg, value_t> auto&& value)
        volatile noexcept
    {
        return Assign_Value(*this, nkr::cpp::Move(value));
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::operator types_t<value_p, none_p>::integer_t()
        const noexcept
    {
        return interface_t::Value(this->value);
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::operator types_t<value_p, none_p>::integer_t()
        const volatile noexcept
    {
        return interface_t::Value(this->value);
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::operator nkr::boolean::cpp_t()
        const noexcept
    {
        return interface_t::Value(this->value) != none_t::Value();
    }

    template <
        nkr::generic::implementing::interface::enumeration::types_tr value_p,
        nkr::cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > inline constexpr types_t<value_p, none_p>::operator nkr::boolean::cpp_t()
        const volatile noexcept
    {
        return interface_t::Value(this->value) != none_t::Value();
    }

}}
