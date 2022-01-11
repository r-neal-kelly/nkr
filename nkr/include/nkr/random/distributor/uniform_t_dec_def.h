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

namespace nkr { namespace random { namespace distributor {

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::value_t
        uniform_t<value_p>::Default_Min()
        noexcept
    {
        return interface_t::Default_Min();
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::value_t
        uniform_t<value_p>::Default_Max()
        noexcept
    {
        return interface_t::Default_Max();
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr auto&
        uniform_t<value_p>::Assign(tr1<any_non_const_tg, uniform_t> auto& self, const tr1<any_tg, uniform_t> auto& other)
        noexcept
    {
        if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
            self.min = other.min;
            self.max = other.max;
        }

        return self;
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr auto&
        uniform_t<value_p>::Assign(tr1<any_non_const_tg, uniform_t> auto& self, tr1<any_non_const_tg, uniform_t> auto&& other)
        noexcept
    {
        if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
            self.min = nkr::cpp::Move(other.min);
            self.max = nkr::cpp::Move(other.max);
        }

        return self;
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr const auto&
        uniform_t<value_p>::Min(tr1<any_tg, uniform_t> auto& self)
        noexcept
    {
        return self.min;
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr auto&
        uniform_t<value_p>::Min(tr1<any_non_const_tg, uniform_t> auto& self, const value_t& value)
        noexcept
    {
        self.min = value;

        return self;
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr auto&
        uniform_t<value_p>::Min(tr1<any_non_const_tg, uniform_t> auto& self, value_t&& value)
        noexcept
    {
        self.min = nkr::cpp::Move(value);

        return self;
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr const auto&
        uniform_t<value_p>::Max(tr1<any_tg, uniform_t> auto& self)
        noexcept
    {
        return self.max;
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr auto&
        uniform_t<value_p>::Max(tr1<any_non_const_tg, uniform_t> auto& self, const value_t& value)
        noexcept
    {
        self.max = value;

        return self;
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr auto&
        uniform_t<value_p>::Max(tr1<any_non_const_tg, uniform_t> auto& self, value_t&& value)
        noexcept
    {
        self.max = nkr::cpp::Move(value);

        return self;
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::value_t
        uniform_t<value_p>::Value(tr1<any_tg, uniform_t> auto& self, tr1<any_non_const_tg, generic::random::generator_tg> auto& generator)
        noexcept
    {
        using number_t = interface_t::number_t;

        number_t min = interface_t::To_Number(Min(self));
        number_t max = interface_t::To_Number(Max(self));

        nkr_ASSERT_THAT(min <= max);

        if constexpr (nkr::generic::built_in::number::real_tr<number_t>) {
            // looks like we'll have to do it the hard way. This doesn't work all the time because the real min and max
            // interpreted as an int don't directly relate the real min and max. good thing we've already got the
            // algorithm figured out in z_utils, just need to move it over here.

            if constexpr (sizeof(number_t) == sizeof(negatable::real_64_t)) {
                negatable::integer_64_t integer = nkr::random::distributor::cpp::uniform::integer_t<negatable::integer_64_t>(
                    *reinterpret_cast<negatable::integer_64_t*>(&min),
                    *reinterpret_cast<negatable::integer_64_t*>(&max))(generator);

                return interface_t::From_Number(*reinterpret_cast<number_t*>(&integer));
            } else if constexpr (sizeof(number_t) == sizeof(negatable::real_32_t)) {
                negatable::integer_32_t integer = nkr::random::distributor::cpp::uniform::integer_t<negatable::integer_32_t>(
                    *reinterpret_cast<negatable::integer_32_t*>(&min),
                    *reinterpret_cast<negatable::integer_32_t*>(&max))(generator);

                return interface_t::From_Number(*reinterpret_cast<number_t*>(&integer));
            } else {
                static_assert(false);
            }
        } else {
            if constexpr (sizeof(number_t) < sizeof(positive::word_t)) {
                if constexpr (nkr::generic::positive_tr<number_t>) {
                    return interface_t::From_Number(
                        static_cast<number_t>(nkr::random::distributor::cpp::uniform::integer_t<positive::word_t>(min, max)(generator)));
                } else {
                    return interface_t::From_Number(
                        static_cast<number_t>(nkr::random::distributor::cpp::uniform::integer_t<negatable::word_t>(min, max)(generator)));
                }
            } else {
                return interface_t::From_Number(nkr::random::distributor::cpp::uniform::integer_t<number_t>(min, max)(generator));
            }
        }
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::uniform_t() noexcept :
        min(Default_Min()),
        max(Default_Max())
    {
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::uniform_t(const value_t& min, const value_t& max) noexcept :
        min(min),
        max(max)
    {
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::uniform_t(value_t&& min, value_t&& max) noexcept :
        min(nkr::cpp::Move(min)),
        max(nkr::cpp::Move(max))
    {
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::uniform_t(const uniform_t& other) noexcept :
        min(other.min),
        max(other.max)
    {
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::uniform_t(const volatile uniform_t& other) noexcept :
        min(other.min),
        max(other.max)
    {
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::uniform_t(uniform_t&& other) noexcept :
        min(nkr::cpp::Move(other.min)),
        max(nkr::cpp::Move(other.max))
    {
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::uniform_t(volatile uniform_t&& other) noexcept :
        min(nkr::cpp::Move(other.min)),
        max(nkr::cpp::Move(other.max))
    {
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>&
        uniform_t<value_p>::operator =(const uniform_t& other)
        noexcept
    {
        return Assign(*this, other);
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr volatile uniform_t<value_p>&
        uniform_t<value_p>::operator =(const uniform_t& other)
        volatile noexcept
    {
        return Assign(*this, other);
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>&
        uniform_t<value_p>::operator =(const volatile uniform_t& other)
        noexcept
    {
        return Assign(*this, other);
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr volatile uniform_t<value_p>&
        uniform_t<value_p>::operator =(const volatile uniform_t& other)
        volatile noexcept
    {
        return Assign(*this, other);
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>&
        uniform_t<value_p>::operator =(uniform_t&& other)
        noexcept
    {
        return Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr volatile uniform_t<value_p>&
        uniform_t<value_p>::operator =(uniform_t&& other)
        volatile noexcept
    {
        return Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>&
        uniform_t<value_p>::operator =(volatile uniform_t&& other)
        noexcept
    {
        return Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr volatile uniform_t<value_p>&
        uniform_t<value_p>::operator =(volatile uniform_t&& other)
        volatile noexcept
    {
        return Assign(*this, nkr::cpp::Move(other));
    }

#if defined(nkr_IS_DEBUG)
    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::~uniform_t() noexcept
    {
        this->min = Default_Min();
        this->max = Default_Min();
    }
#endif

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr const uniform_t<value_p>::value_t&
        uniform_t<value_p>::Min()
        const noexcept
    {
        return Min(*this);
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr const volatile uniform_t<value_p>::value_t&
        uniform_t<value_p>::Min()
        const volatile noexcept
    {
        return Min(*this);
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>&
        uniform_t<value_p>::Min(const value_t& value)
        noexcept
    {
        return Min(*this, value);
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr volatile uniform_t<value_p>&
        uniform_t<value_p>::Min(const value_t& value)
        volatile noexcept
    {
        return Min(*this, value);
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>&
        uniform_t<value_p>::Min(value_t&& value)
        noexcept
    {
        return Min(*this, nkr::cpp::Move(value));
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr volatile uniform_t<value_p>&
        uniform_t<value_p>::Min(value_t&& value)
        volatile noexcept
    {
        return Min(*this, nkr::cpp::Move(value));
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr const uniform_t<value_p>::value_t&
        uniform_t<value_p>::Max()
        const noexcept
    {
        return Max(*this);
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr const volatile uniform_t<value_p>::value_t&
        uniform_t<value_p>::Max()
        const volatile noexcept
    {
        return Max(*this);
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>&
        uniform_t<value_p>::Max(const value_t& value)
        noexcept
    {
        return Max(*this, value);
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr volatile uniform_t<value_p>&
        uniform_t<value_p>::Max(const value_t& value)
        volatile noexcept
    {
        return Max(*this, value);
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>&
        uniform_t<value_p>::Max(value_t&& value)
        noexcept
    {
        return Max(*this, nkr::cpp::Move(value));
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr volatile uniform_t<value_p>&
        uniform_t<value_p>::Max(value_t&& value)
        volatile noexcept
    {
        return Max(*this, nkr::cpp::Move(value));
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::value_t
        uniform_t<value_p>::Value(tr1<any_non_const_tg, generic::random::generator_tg> auto& generator)
        const noexcept
    {
        return Value(*this, generator);
    }

    template <nkr::generic::implementing::interface::random::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::value_t
        uniform_t<value_p>::Value(tr1<any_non_const_tg, generic::random::generator_tg> auto& generator)
        const volatile noexcept
    {
        return Value(*this, generator);
    }

}}}
