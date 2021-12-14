/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/optional_t_dec.h"
#include "nkr/utils.h"

namespace nkr {

    template <typename other_p>
    inline constexpr c_bool_t
        type_traits_i<optional_tg>::Is_Any()
    {
        return $optional_t::any_tr<other_p>;
    }

    inline constexpr c_bool_t
        template_traits_i<optional_ttg>::Is_Implemented()
    {
        return true;
    }

}

namespace nkr {

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::Is_Equal_To(const tr1<any_tg, optional_t> auto& self, const tr0<any_tg> auto& other)
    {
        using other_t = std::remove_reference_t<decltype(other)>;

        if constexpr (is_any_tr<other_t, value_t>) {
            if constexpr (can_equal_to_tr<decltype(self.Value()), decltype(other)>) {
                return self.Has_Value() && self.Value() == other;
            } else {
                static_assert(false, "these two values can not be equal to each other.");
            }
        } else if constexpr (tr1<other_t, any_tg, optional_tg>) {
            if constexpr (can_equal_to_tr<decltype(self.Value()), decltype(other.Value())>) {
                if (self.Has_Value() && other.Has_Value()) {
                    return self.Value() == other.Value();
                } else {
                    return !self.Has_Value() && !other.Has_Value();
                }
            } else {
                static_assert(false, "these two values can not be equal to each other.");
            }
        } else {
            if constexpr (can_equal_to_tr<decltype(self.Value()), decltype(other)>) {
                return self.Has_Value() && self.Value() == other;
            } else {
                static_assert(false, "these two values can not be equal to each other.");
            }
        }
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::optional_t() :
        has_value(false),
        value()
    {
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::optional_t(const tr1<any_tg, value_t> auto& value) :
        has_value(true),
        value(value)
    {
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::optional_t(tr1<any_non_const_tg, value_t> auto&& value) :
        has_value(true),
        value(nkr::Move(value))
    {
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::optional_t(const tr2<any_tg, maybe_ttg, of_any_tg, value_t> auto& maybe_value) :
        has_value(maybe_value != none_t()),
        value(maybe_value())
    {
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::optional_t(tr2<any_tg, maybe_ttg, of_any_accessed_non_const_tg, value_t> auto&& maybe_value) :
        has_value(maybe_value != none_t()),
        value(nkr::Move(maybe_value()))
    {
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::optional_t(const tr2<any_tg, some_ttg, of_any_tg, value_t> auto& some_value) :
        has_value((nkr_ASSERT_THAT(some_value), true)),
        value(some_value())
    {
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::optional_t(tr2<any_tg, some_ttg, of_any_accessed_non_const_tg, value_t> auto&& some_value) :
        has_value((nkr_ASSERT_THAT(some_value), true)),
        value(nkr::Move(some_value()))
    {
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::optional_t(const optional_t& other) :
        has_value(other.has_value),
        value(other.value)
    {
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::optional_t(const volatile optional_t& other) :
        has_value(other.has_value),
        value(other.value)
    {
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::optional_t(optional_t&& other) noexcept :
        has_value(nkr::Move(other.has_value)),
        value(nkr::Move(other.value))
    {
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::optional_t(volatile optional_t&& other) noexcept :
        has_value(nkr::Move(other.has_value)),
        value(nkr::Move(other.value))
    {
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>&
        optional_t<value_p>::operator =(const optional_t& other)
    {
        if (this != std::addressof(other)) {
            this->has_value = other.has_value;
            this->value = other.value;
        }

        return *this;
    }

    template <any_type_tr value_p>
    inline volatile optional_t<value_p>&
        optional_t<value_p>::operator =(const optional_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->has_value = other.has_value;
            this->value = other.value;
        }

        return *this;
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>&
        optional_t<value_p>::operator =(const volatile optional_t& other)
    {
        if (this != std::addressof(other)) {
            this->has_value = other.has_value;
            this->value = other.value;
        }

        return *this;
    }

    template <any_type_tr value_p>
    inline volatile optional_t<value_p>&
        optional_t<value_p>::operator =(const volatile optional_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->has_value = other.has_value;
            this->value = other.value;
        }

        return *this;
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>&
        optional_t<value_p>::operator =(optional_t&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->has_value = nkr::Move(other.has_value);
            this->value = nkr::Move(other.value);
        }

        return *this;
    }

    template <any_type_tr value_p>
    inline volatile optional_t<value_p>&
        optional_t<value_p>::operator =(optional_t&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->has_value = nkr::Move(other.has_value);
            this->value = nkr::Move(other.value);
        }

        return *this;
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>&
        optional_t<value_p>::operator =(is_just_volatile_tr<optional_t> auto&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->has_value = nkr::Move(other.has_value);
            this->value = nkr::Move(other.value);
        }

        return *this;
    }

    template <any_type_tr value_p>
    inline volatile optional_t<value_p>&
        optional_t<value_p>::operator =(is_just_volatile_tr<optional_t> auto&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->has_value = nkr::Move(other.has_value);
            this->value = nkr::Move(other.value);
        }

        return *this;
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::~optional_t()
    {
        this->has_value = false;
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::Has_Value()
        const
    {
        return this->has_value;
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::Has_Value()
        const volatile
    {
        return this->has_value;
    }

    template <any_type_tr value_p>
    inline typename optional_t<value_p>::value_t&
        optional_t<value_p>::Value()
    {
        nkr_ASSERT_THAT(Has_Value());

        return this->value;
    }

    template <any_type_tr value_p>
    inline const typename optional_t<value_p>::value_t&
        optional_t<value_p>::Value()
        const
    {
        nkr_ASSERT_THAT(Has_Value());

        return this->value;
    }

    template <any_type_tr value_p>
    inline volatile typename optional_t<value_p>::value_t&
        optional_t<value_p>::Value()
        volatile
    {
        nkr_ASSERT_THAT(Has_Value());

        return this->value;
    }

    template <any_type_tr value_p>
    inline const volatile typename optional_t<value_p>::value_t&
        optional_t<value_p>::Value()
        const volatile
    {
        nkr_ASSERT_THAT(Has_Value());

        return this->value;
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::operator c_bool_t()
        const
    {
        return this->has_value;
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::operator c_bool_t()
        const volatile
    {
        return this->has_value;
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::operator ==(const tr0<any_tg> auto& other)
        const
    {
        return Is_Equal_To(*this, other);
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::operator ==(const tr0<any_tg> auto& other)
        const volatile
    {
        return Is_Equal_To(*this, other);
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::operator ==(const tr0<any_tg> auto&& other)
        const
    {
        return Is_Equal_To(*this, other);
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::operator ==(const tr0<any_tg> auto&& other)
        const volatile
    {
        return Is_Equal_To(*this, other);
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::operator !=(const tr0<any_tg> auto& other)
        const
    {
        return !Is_Equal_To(*this, other);
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::operator !=(const tr0<any_tg> auto& other)
        const volatile
    {
        return !Is_Equal_To(*this, other);
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::operator !=(const tr0<any_tg> auto&& other)
        const
    {
        return !Is_Equal_To(*this, other);
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::operator !=(const tr0<any_tg> auto&& other)
        const volatile
    {
        return !Is_Equal_To(*this, other);
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::optional_t(none_t) :
        optional_t()
    {
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>&
        optional_t<value_p>::operator =(none_t)
    {
        this->has_value = false;
        this->value = value_t();
    }

    template <any_type_tr value_p>
    inline volatile optional_t<value_p>&
        optional_t<value_p>::operator =(none_t)
        volatile
    {
        this->has_value = false;
        this->value = value_t();
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::operator ==(none_t)
        const
    {
        return !Has_Value();
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::operator ==(none_t)
        const volatile
    {
        return !Has_Value();
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::operator !=(none_t)
        const
    {
        return Has_Value();
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::operator !=(none_t)
        const volatile
    {
        return Has_Value();
    }

}
