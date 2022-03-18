/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/randomness/distributor/uniform_t_dec.h"

namespace nkr { namespace randomness { namespace distributor { namespace uniform_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::randomness::distributor::uniform_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::randomness::distributor::uniform_tg>;
    }

    template <nkr::randomness::distributor::uniform_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::randomness::distributor::uniform_t$::Is_Any_General<other_p>();
    }

    template <nkr::randomness::distributor::uniform_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::randomness::distributor::uniform_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::randomness::distributor::uniform_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::randomness::distributor::uniform_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

namespace nkr { namespace randomness { namespace distributor { namespace uniform_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::randomness::distributor::uniform_ttr<template_p>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_template_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::randomness::distributor::uniform_ttr<other_p>;
    }

    template <template <typename ...> typename template_p>
        requires nkr::randomness::distributor::uniform_ttr<template_p>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_template_sp<template_p>::Is_Any_Actual()
        noexcept
    {
        return nkr::randomness::distributor::uniform_ttr<other_p>;
    }

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::randomness::distributor::uniform_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any_Actual()
        noexcept
    {
        return nkr::cpp::is_any_ttr<other_p, actual_template_t>;
    }

}}}}

namespace nkr { namespace randomness { namespace distributor {

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::value_t
        uniform_t<value_p>::Default_Min()
        noexcept
    {
        return interface_t::Default_Min();
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::value_t
        uniform_t<value_p>::Default_Max()
        noexcept
    {
        return interface_t::Default_Max();
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr auto&
        uniform_t<value_p>::Assign(tr<any_non_const_tg, t<uniform_t>> auto& self, const tr<any_tg, t<uniform_t>> auto& other)
        noexcept
    {
        if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
            self.min = other.min;
            self.max = other.max;
        }

        return self;
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr auto&
        uniform_t<value_p>::Assign(tr<any_non_const_tg, t<uniform_t>> auto& self, tr<any_non_const_tg, t<uniform_t>> auto&& other)
        noexcept
    {
        if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
            self.min = nkr::cpp::Move(other.min);
            self.max = nkr::cpp::Move(other.max);
        }

        return self;
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr const auto&
        uniform_t<value_p>::Min(tr<any_tg, t<uniform_t>> auto& self)
        noexcept
    {
        return self.min;
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr auto&
        uniform_t<value_p>::Min(tr<any_non_const_tg, t<uniform_t>> auto& self, const value_t& value)
        noexcept
    {
        self.min = value;

        return self;
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr auto&
        uniform_t<value_p>::Min(tr<any_non_const_tg, t<uniform_t>> auto& self, value_t&& value)
        noexcept
    {
        self.min = nkr::cpp::Move(value);

        return self;
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr const auto&
        uniform_t<value_p>::Max(tr<any_tg, t<uniform_t>> auto& self)
        noexcept
    {
        return self.max;
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr auto&
        uniform_t<value_p>::Max(tr<any_non_const_tg, t<uniform_t>> auto& self, const value_t& value)
        noexcept
    {
        self.max = value;

        return self;
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr auto&
        uniform_t<value_p>::Max(tr<any_non_const_tg, t<uniform_t>> auto& self, value_t&& value)
        noexcept
    {
        self.max = nkr::cpp::Move(value);

        return self;
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::value_t
        uniform_t<value_p>::Value(tr<any_tg, t<uniform_t>> auto& self, tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator)
        noexcept
    {
        using number_t = interface_t::number_t;

        const number_t min = interface_t::To_Number(Min(self));
        const number_t max = interface_t::To_Number(Max(self));

        nkr_ASSERT_THAT(min <= max);

        if constexpr (nkr::generic::built_in::number::real_tr<number_t>) {
            // something we need to check is if -min or -max can cause undefined behavior, or if does something unexpected.
            // not sure if -real can hold as many discrete values as real.
            if (min < 0.0) {
                if (max > 0.0) {
                    // we want a proportional chance of getting a negative number. if min is -10 and max is 10
                    // then it should return either a negative or positive 50% of the time. if min is -10 and max is 20,
                    // then negative should be returned 25% of the time and positive 75% of the time.
                    const number_t absolute_min = -min;
                    const number_t absolute_max = max;
                    const nkr::boolean::cpp_t do_negative = absolute_min > absolute_max ?
                        !nkr::cpp::randomness::distributor::bernoulli_t(nkr::negatable::real_t(absolute_max / absolute_min / 2))(generator) :
                        nkr::cpp::randomness::distributor::bernoulli_t(nkr::negatable::real_t(absolute_min / absolute_max / 2))(generator);

                    if (do_negative) {
                        return interface_t::From_Number(
                            -nkr::cpp::randomness::distributor::uniform::real_t<number_t>(number_t(0.0), absolute_min)(generator)
                        );
                    } else {
                        return interface_t::From_Number(
                            nkr::cpp::randomness::distributor::uniform::real_t<number_t>(number_t(0.0), absolute_max)(generator)
                        );
                    }
                } else {
                    return interface_t::From_Number(
                        -nkr::cpp::randomness::distributor::uniform::real_t<number_t>(-max, -min)(generator)
                    );
                }
            } else {
                return interface_t::From_Number(
                    nkr::cpp::randomness::distributor::uniform::real_t<number_t>(min, max)(generator)
                );
            }
        } else if constexpr (nkr::generic::built_in::number::integer_tr<number_t>) {
            if constexpr (sizeof(number_t) < sizeof(nkr::positive::word_t)) {
                if constexpr (nkr::generic::positive_tr<number_t>) {
                    return interface_t::From_Number(
                        static_cast<number_t>(nkr::cpp::randomness::distributor::uniform::integer_t<nkr::positive::word_t>(min, max)(generator))
                    );
                } else {
                    return interface_t::From_Number(
                        static_cast<number_t>(nkr::cpp::randomness::distributor::uniform::integer_t<nkr::negatable::word_t>(min, max)(generator))
                    );
                }
            } else {
                return interface_t::From_Number(
                    nkr::cpp::randomness::distributor::uniform::integer_t<number_t>(min, max)(generator)
                );
            }
        } else {
            [] <nkr::boolean::cpp_t _ = false>() { static_assert(_); }();
        }
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::uniform_t() noexcept :
        min(Default_Min()),
        max(Default_Max())
    {
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::uniform_t(const value_t& min, const value_t& max) noexcept :
        min(min),
        max(max)
    {
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::uniform_t(value_t&& min, value_t&& max) noexcept :
        min(nkr::cpp::Move(min)),
        max(nkr::cpp::Move(max))
    {
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::uniform_t(const uniform_t& other) noexcept :
        min(other.min),
        max(other.max)
    {
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::uniform_t(const volatile uniform_t& other) noexcept :
        min(other.min),
        max(other.max)
    {
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::uniform_t(uniform_t&& other) noexcept :
        min(nkr::cpp::Move(other.min)),
        max(nkr::cpp::Move(other.max))
    {
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::uniform_t(volatile uniform_t&& other) noexcept :
        min(nkr::cpp::Move(other.min)),
        max(nkr::cpp::Move(other.max))
    {
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>&
        uniform_t<value_p>::operator =(const uniform_t& other)
        noexcept
    {
        return Assign(*this, other);
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr volatile uniform_t<value_p>&
        uniform_t<value_p>::operator =(const uniform_t& other)
        volatile noexcept
    {
        return Assign(*this, other);
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>&
        uniform_t<value_p>::operator =(const volatile uniform_t& other)
        noexcept
    {
        return Assign(*this, other);
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr volatile uniform_t<value_p>&
        uniform_t<value_p>::operator =(const volatile uniform_t& other)
        volatile noexcept
    {
        return Assign(*this, other);
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>&
        uniform_t<value_p>::operator =(uniform_t&& other)
        noexcept
    {
        return Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr volatile uniform_t<value_p>&
        uniform_t<value_p>::operator =(uniform_t&& other)
        volatile noexcept
    {
        return Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>&
        uniform_t<value_p>::operator =(tr<just_volatile_tg, t<uniform_t>> auto&& other)
        noexcept
    {
        return Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr volatile uniform_t<value_p>&
        uniform_t<value_p>::operator =(tr<just_volatile_tg, t<uniform_t>> auto&& other)
        volatile noexcept
    {
        return Assign(*this, nkr::cpp::Move(other));
    }

#if defined(nkr_IS_DEBUG)
    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::~uniform_t() noexcept
    {
        this->min = Default_Min();
        this->max = Default_Min();
    }
#endif

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr const uniform_t<value_p>::value_t&
        uniform_t<value_p>::Min()
        const noexcept
    {
        return Min(*this);
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr const volatile uniform_t<value_p>::value_t&
        uniform_t<value_p>::Min()
        const volatile noexcept
    {
        return Min(*this);
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>&
        uniform_t<value_p>::Min(const value_t& value)
        noexcept
    {
        return Min(*this, value);
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr volatile uniform_t<value_p>&
        uniform_t<value_p>::Min(const value_t& value)
        volatile noexcept
    {
        return Min(*this, value);
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>&
        uniform_t<value_p>::Min(value_t&& value)
        noexcept
    {
        return Min(*this, nkr::cpp::Move(value));
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr volatile uniform_t<value_p>&
        uniform_t<value_p>::Min(value_t&& value)
        volatile noexcept
    {
        return Min(*this, nkr::cpp::Move(value));
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr const uniform_t<value_p>::value_t&
        uniform_t<value_p>::Max()
        const noexcept
    {
        return Max(*this);
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr const volatile uniform_t<value_p>::value_t&
        uniform_t<value_p>::Max()
        const volatile noexcept
    {
        return Max(*this);
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>&
        uniform_t<value_p>::Max(const value_t& value)
        noexcept
    {
        return Max(*this, value);
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr volatile uniform_t<value_p>&
        uniform_t<value_p>::Max(const value_t& value)
        volatile noexcept
    {
        return Max(*this, value);
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>&
        uniform_t<value_p>::Max(value_t&& value)
        noexcept
    {
        return Max(*this, nkr::cpp::Move(value));
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr volatile uniform_t<value_p>&
        uniform_t<value_p>::Max(value_t&& value)
        volatile noexcept
    {
        return Max(*this, nkr::cpp::Move(value));
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::value_t
        uniform_t<value_p>::Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator)
        const noexcept
    {
        return Value(*this, generator);
    }

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    inline constexpr uniform_t<value_p>::value_t
        uniform_t<value_p>::Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator)
        const volatile noexcept
    {
        return Value(*this, generator);
    }

}}}
