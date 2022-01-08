/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/random/distributor/uniform_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::random::distributor::uniform_tg>::Is_Any()
        noexcept
    {
        return nkr::random::distributor::uniform_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::random::distributor::uniform_ttg>::Is_Any()
        noexcept
    {
        return nkr::random::distributor::uniform_ttr<other_p>;
    }

}}

namespace nkr { namespace random { namespace distributor { namespace $uniform_t {

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>::value_t
        boolean_sp<value_p>::Default_Min()
        noexcept
    {
        return nkr::cpp::Min_Value<value_t>();
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>::value_t
        boolean_sp<value_p>::Default_Max()
        noexcept
    {
        return nkr::cpp::Max_Value<value_t>();
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr auto&
        boolean_sp<value_p>::Assign(tr1<any_non_const_tg, boolean_sp> auto& self, const tr1<any_tg, boolean_sp> auto& other)
        noexcept
    {
        if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
            self.min = other.min;
            self.max = other.max;
        }

        return self;
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr auto&
        boolean_sp<value_p>::Assign(tr1<any_non_const_tg, boolean_sp> auto& self, tr1<any_non_const_tg, boolean_sp> auto&& other)
        noexcept
    {
        if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
            self.min = nkr::cpp::Move(other.min);
            self.max = nkr::cpp::Move(other.max);
        }

        return self;
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>::value_t
        boolean_sp<value_p>::Min(tr1<any_tg, boolean_sp> auto& self)
        noexcept
    {
        return self.min;
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr auto&
        boolean_sp<value_p>::Min(tr1<any_non_const_tg, boolean_sp> auto& self, const value_t& value)
        noexcept
    {
        self.min = value;

        return self;
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr auto&
        boolean_sp<value_p>::Min(tr1<any_non_const_tg, boolean_sp> auto& self, value_t&& value)
        noexcept
    {
        self.min = nkr::cpp::Move(value);

        return self;
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>::value_t
        boolean_sp<value_p>::Max(tr1<any_tg, boolean_sp> auto& self)
        noexcept
    {
        return self.max;
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr auto&
        boolean_sp<value_p>::Max(tr1<any_non_const_tg, boolean_sp> auto& self, const value_t& value)
        noexcept
    {
        self.max = value;

        return self;
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr auto&
        boolean_sp<value_p>::Max(tr1<any_non_const_tg, boolean_sp> auto& self, value_t&& value)
        noexcept
    {
        self.max = nkr::cpp::Move(value);

        return self;
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>::value_t
        boolean_sp<value_p>::Value(tr1<any_tg, boolean_sp> auto& self, tr1<any_non_const_tg, generic::random::generator_tg> auto& generator)
        noexcept
    {
        nkr_ASSERT_THAT(static_cast<positive::integer_t>(static_cast<boolean::cpp_t>(self.min)) <=
                        static_cast<positive::integer_t>(static_cast<boolean::cpp_t>(self.max)));

        return value_t(nkr::random::distributor::cpp::uniform::integer_t<positive::integer_t>
                       (static_cast<positive::integer_t>(static_cast<boolean::cpp_t>(self.min)),
                        static_cast<positive::integer_t>(static_cast<boolean::cpp_t>(self.max)))(generator));
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>::boolean_sp() noexcept :
        min(Min()),
        max(Max())
    {
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>::boolean_sp(value_t min, value_t max) noexcept :
        min(min),
        max(max)
    {
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>::boolean_sp(const boolean_sp& other) noexcept :
        min(other.min),
        max(other.max)
    {
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>::boolean_sp(const volatile boolean_sp& other) noexcept :
        min(other.min),
        max(other.max)
    {
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>::boolean_sp(boolean_sp&& other) noexcept :
        min(nkr::cpp::Move(other.min)),
        max(nkr::cpp::Move(other.max))
    {
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>::boolean_sp(volatile boolean_sp&& other) noexcept :
        min(nkr::cpp::Move(other.min)),
        max(nkr::cpp::Move(other.max))
    {
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>&
        boolean_sp<value_p>::operator =(const boolean_sp& other)
        noexcept
    {
        return Assign(*this, other);
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr volatile boolean_sp<value_p>&
        boolean_sp<value_p>::operator =(const boolean_sp& other)
        volatile noexcept
    {
        return Assign(*this, other);
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>&
        boolean_sp<value_p>::operator =(const volatile boolean_sp& other)
        noexcept
    {
        return Assign(*this, other);
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr volatile boolean_sp<value_p>&
        boolean_sp<value_p>::operator =(const volatile boolean_sp& other)
        volatile noexcept
    {
        return Assign(*this, other);
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>&
        boolean_sp<value_p>::operator =(boolean_sp&& other)
        noexcept
    {
        return Assign(*this, nkr::cpp::Move(other));
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr volatile boolean_sp<value_p>&
        boolean_sp<value_p>::operator =(boolean_sp&& other)
        volatile noexcept
    {
        return Assign(*this, nkr::cpp::Move(other));
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>&
        boolean_sp<value_p>::operator =(volatile boolean_sp&& other)
        noexcept
    {
        return Assign(*this, nkr::cpp::Move(other));
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr volatile boolean_sp<value_p>&
        boolean_sp<value_p>::operator =(volatile boolean_sp&& other)
        volatile noexcept
    {
        return Assign(*this, nkr::cpp::Move(other));
    }

#if defined(nkr_IS_DEBUG)
    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>::~boolean_sp() noexcept
    {
        this->min = none::value_t<value_t>();
        this->max = none::value_t<value_t>();
    }
#endif

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>::value_t
        boolean_sp<value_p>::Min()
        const noexcept
    {
        return Min(*this);
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>::value_t
        boolean_sp<value_p>::Min()
        const volatile noexcept
    {
        return Min(*this);
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>&
        boolean_sp<value_p>::Min(const value_t& value)
        noexcept
    {
        return Min(*this, value);
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr volatile boolean_sp<value_p>&
        boolean_sp<value_p>::Min(const value_t& value)
        volatile noexcept
    {
        return Min(*this, value);
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>&
        boolean_sp<value_p>::Min(value_t&& value)
        noexcept
    {
        return Min(*this, nkr::cpp::Move(value));
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr volatile boolean_sp<value_p>&
        boolean_sp<value_p>::Min(value_t&& value)
        volatile noexcept
    {
        return Min(*this, nkr::cpp::Move(value));
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>::value_t
        boolean_sp<value_p>::Max()
        const noexcept
    {
        return Max(*this);
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>::value_t
        boolean_sp<value_p>::Max()
        const volatile noexcept
    {
        return Max(*this);
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>&
        boolean_sp<value_p>::Max(const value_t& value)
        noexcept
    {
        return Max(*this, value);
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr volatile boolean_sp<value_p>&
        boolean_sp<value_p>::Max(const value_t& value)
        volatile noexcept
    {
        return Max(*this, value);
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>&
        boolean_sp<value_p>::Max(value_t&& value)
        noexcept
    {
        return Max(*this, nkr::cpp::Move(value));
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr volatile boolean_sp<value_p>&
        boolean_sp<value_p>::Max(value_t&& value)
        volatile noexcept
    {
        return Max(*this, nkr::cpp::Move(value));
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>::value_t
        boolean_sp<value_p>::Value(tr1<any_non_const_tg, generic::random::generator_tg> auto& generator)
        const noexcept
    {
        return Value(*this, generator);
    }

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    inline constexpr boolean_sp<value_p>::value_t
        boolean_sp<value_p>::Value(tr1<any_non_const_tg, generic::random::generator_tg> auto& generator)
        const volatile noexcept
    {
        return Value(*this, generator);
    }

}}}}

namespace nkr { namespace random { namespace distributor { namespace $uniform_t {

    template <tr1<just_non_qualified_tg, generic::number::integer_tg> value_p>
    inline constexpr integer_sp<value_p>::value_t
        integer_sp<value_p>::Default_Min()
        noexcept
    {
        return nkr::cpp::Min_Value<value_t>();
    }

    template <tr1<just_non_qualified_tg, generic::number::integer_tg> value_p>
    inline constexpr integer_sp<value_p>::value_t
        integer_sp<value_p>::Default_Max()
        noexcept
    {
        return nkr::cpp::Max_Value<value_t>();
    }

}}}}

namespace nkr { namespace random { namespace distributor { namespace $uniform_t {

    template <tr1<just_non_qualified_tg, generic::number::real_tg> value_p>
    inline constexpr real_sp<value_p>::value_t
        real_sp<value_p>::Default_Min()
        noexcept
    {
        return nkr::cpp::Min_Value<value_t>();
    }

    template <tr1<just_non_qualified_tg, generic::number::real_tg> value_p>
    inline constexpr real_sp<value_p>::value_t
        real_sp<value_p>::Default_Max()
        noexcept
    {
        return nkr::cpp::Max_Value<value_t>();
    }

}}}}

namespace nkr { namespace random { namespace distributor { namespace $uniform_t {

    template <tr1<just_non_qualified_tg, generic::pointer_tg> value_p>
    inline constexpr pointer_sp<value_p>::value_t
        pointer_sp<value_p>::Default_Min()
        noexcept
    {
        return nkr::cpp::Min_Value<value_t>();
    }

    template <tr1<just_non_qualified_tg, generic::pointer_tg> value_p>
    inline constexpr pointer_sp<value_p>::value_t
        pointer_sp<value_p>::Default_Max()
        noexcept
    {
        return nkr::cpp::Max_Value<value_t>();
    }

}}}}
