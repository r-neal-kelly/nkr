/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/z_macros_def.h"
#include "nkr/z_math.h"
#include "nkr/z_utils.h"

#include "nkr/z_enumeration/flags_t_dec.h"

namespace nkr { namespace enumeration { namespace $flags_t {

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline constexpr index_t
        any_sp<integer_p, actual_value_p>::Min_Index()
    {
        return 0;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline constexpr typename any_sp<integer_p, actual_value_p>::value_t
        any_sp<integer_p, actual_value_p>::Min_Value()
    {
        return Value(Min_Index());
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline constexpr index_t
        any_sp<integer_p, actual_value_p>::Max_Index()
    {
        return (sizeof(value_t) * 8) - 1;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline constexpr typename any_sp<integer_p, actual_value_p>::value_t
        any_sp<integer_p, actual_value_p>::Max_Value()
    {
        return Value(Max_Index());
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline constexpr index_t
        any_sp<integer_p, actual_value_p>::Index(value_t value)
    {
        nkr_ASSERT_THAT(value >= Min_Value());
        nkr_ASSERT_THAT(value <= Max_Value());
        nkr_ASSERT_THAT(math::Is_Power_Of_2(value));

        for (index_t idx = 0, end = Max_Index() + 1; idx < end; idx += 1, value /= 2) {
            if (value == 1) {
                return idx;
            }
        }

        return 0;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline constexpr typename any_sp<integer_p, actual_value_p>::value_t
        any_sp<integer_p, actual_value_p>::Value(index_t index)
    {
        nkr_ASSERT_THAT(index >= Min_Index());
        nkr_ASSERT_THAT(index <= Max_Index());

        return static_cast<value_t>(1) << index;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline any_sp<integer_p, actual_value_p>::any_sp() :
        value(0)
    {
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline any_sp<integer_p, actual_value_p>::any_sp(value_t value) :
        value(value)
    {
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline any_sp<integer_p, actual_value_p>::any_sp(const any_sp& other) :
        value(other.value)
    {
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline any_sp<integer_p, actual_value_p>::any_sp(const volatile any_sp& other) :
        value(other.value)
    {
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline any_sp<integer_p, actual_value_p>::any_sp(any_sp&& other) noexcept :
        value(nkr::Move(other.value))
    {
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline any_sp<integer_p, actual_value_p>::any_sp(volatile any_sp&& other) noexcept :
        value(nkr::Move(other.value))
    {
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline any_sp<integer_p, actual_value_p>&
        any_sp<integer_p, actual_value_p>::operator =(const any_sp& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline volatile any_sp<integer_p, actual_value_p>&
        any_sp<integer_p, actual_value_p>::operator =(const any_sp& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline any_sp<integer_p, actual_value_p>&
        any_sp<integer_p, actual_value_p>::operator =(const volatile any_sp& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline volatile any_sp<integer_p, actual_value_p>&
        any_sp<integer_p, actual_value_p>::operator =(const volatile any_sp& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline any_sp<integer_p, actual_value_p>&
        any_sp<integer_p, actual_value_p>::operator =(any_sp&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline volatile any_sp<integer_p, actual_value_p>&
        any_sp<integer_p, actual_value_p>::operator =(any_sp&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline any_sp<integer_p, actual_value_p>&
        any_sp<integer_p, actual_value_p>::operator =(is_just_volatile_tr<any_sp> auto&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline volatile any_sp<integer_p, actual_value_p>&
        any_sp<integer_p, actual_value_p>::operator =(is_just_volatile_tr<any_sp> auto&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline any_sp<integer_p, actual_value_p>::~any_sp()
    {
        if constexpr (any_non_const_tr<value_t>) {
            this->value = 0;
        }
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline typename any_sp<integer_p, actual_value_p>::value_t
        any_sp<integer_p, actual_value_p>::Flags()
        const
    {
        return this->value;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline typename any_sp<integer_p, actual_value_p>::value_t
        any_sp<integer_p, actual_value_p>::Flags()
        const volatile
    {
        return this->value;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline bool_t
        any_sp<integer_p, actual_value_p>::Is_Index_Flagged(index_t index)
        const
    {
        nkr_ASSERT_THAT(index >= Min_Index());
        nkr_ASSERT_THAT(index <= Max_Index());

        return Is_Value_Flagged(Value(index));
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline bool_t
        any_sp<integer_p, actual_value_p>::Is_Index_Flagged(index_t index)
        const volatile
    {
        nkr_ASSERT_THAT(index >= Min_Index());
        nkr_ASSERT_THAT(index <= Max_Index());

        return Is_Value_Flagged(Value(index));
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline bool_t
        any_sp<integer_p, actual_value_p>::Is_Value_Flagged(value_t value)
        const
    {
        nkr_ASSERT_THAT(value >= Min_Value());
        nkr_ASSERT_THAT(value <= Max_Value());
        nkr_ASSERT_THAT(math::Is_Power_Of_2(value));

        return (this->value & value) != 0;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline bool_t
        any_sp<integer_p, actual_value_p>::Is_Value_Flagged(value_t value)
        const volatile
    {
        nkr_ASSERT_THAT(value >= Min_Value());
        nkr_ASSERT_THAT(value <= Max_Value());
        nkr_ASSERT_THAT(math::Is_Power_Of_2(value));

        return (this->value & value) != 0;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline void_t
        any_sp<integer_p, actual_value_p>::Flag_Index(index_t index)
    {
        nkr_ASSERT_THAT(index >= Min_Index());
        nkr_ASSERT_THAT(index <= Max_Index());

        return Flag_Value(Value(index));
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline void_t
        any_sp<integer_p, actual_value_p>::Flag_Index(index_t index)
        volatile
    {
        nkr_ASSERT_THAT(index >= Min_Index());
        nkr_ASSERT_THAT(index <= Max_Index());

        return Flag_Value(Value(index));
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline void_t
        any_sp<integer_p, actual_value_p>::Flag_Value(value_t value)
    {
        nkr_ASSERT_THAT(value >= Min_Value());
        nkr_ASSERT_THAT(value <= Max_Value());
        nkr_ASSERT_THAT(math::Is_Power_Of_2(value));

        this->value |= value;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline void_t
        any_sp<integer_p, actual_value_p>::Flag_Value(value_t value)
        volatile
    {
        nkr_ASSERT_THAT(value >= Min_Value());
        nkr_ASSERT_THAT(value <= Max_Value());
        nkr_ASSERT_THAT(math::Is_Power_Of_2(value));

        this->value |= value;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline void_t
        any_sp<integer_p, actual_value_p>::Unflag_Index(index_t index)
    {
        nkr_ASSERT_THAT(index >= Min_Index());
        nkr_ASSERT_THAT(index <= Max_Index());

        return Unflag_Value(Value(index));
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline void_t
        any_sp<integer_p, actual_value_p>::Unflag_Index(index_t index)
        volatile
    {
        nkr_ASSERT_THAT(index >= Min_Index());
        nkr_ASSERT_THAT(index <= Max_Index());

        return Unflag_Value(Value(index));
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline void_t
        any_sp<integer_p, actual_value_p>::Unflag_Value(value_t value)
    {
        nkr_ASSERT_THAT(value >= Min_Value());
        nkr_ASSERT_THAT(value <= Max_Value());
        nkr_ASSERT_THAT(math::Is_Power_Of_2(value));

        this->value &= ~value;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline void_t
        any_sp<integer_p, actual_value_p>::Unflag_Value(value_t value)
        volatile
    {
        nkr_ASSERT_THAT(value >= Min_Value());
        nkr_ASSERT_THAT(value <= Max_Value());
        nkr_ASSERT_THAT(math::Is_Power_Of_2(value));

        this->value &= ~value;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline any_sp<integer_p, actual_value_p>::any_sp(none_t)
    {
        this->value == 0;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline any_sp<integer_p, actual_value_p>&
        any_sp<integer_p, actual_value_p>::operator =(none_t)
    {
        this->value == 0;
        return *this;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline volatile any_sp<integer_p, actual_value_p>&
        any_sp<integer_p, actual_value_p>::operator =(none_t)
        volatile
    {
        this->value == 0;
        return *this;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline bool_t
        any_sp<integer_p, actual_value_p>::operator ==(none_t)
        const
    {
        return this->value == 0;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline bool_t
        any_sp<integer_p, actual_value_p>::operator ==(none_t)
        const volatile
    {
        return this->value == 0;
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline bool_t
        any_sp<integer_p, actual_value_p>::operator !=(none_t)
        const
    {
        return !operator ==(none_t());
    }

    template <integer_unsigned_tr integer_p, typename actual_value_p>
    inline bool_t
        any_sp<integer_p, actual_value_p>::operator !=(none_t)
        const volatile
    {
        return !operator ==(none_t());
    }

}}}
