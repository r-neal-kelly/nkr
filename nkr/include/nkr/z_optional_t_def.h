/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_optional_t_dec.h"
#include "nkr/z_utils.h"

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
    inline auto&
        optional_t<value_p>::Assign_Copy(tr1<any_non_const_tg, optional_t> auto& self, const tr1<any_tg, optional_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            self.has_value = other.has_value;
            self.value = other.value;
        }

        return self;
    }

    template <any_type_tr value_p>
    inline auto&
        optional_t<value_p>::Assign_Move(tr1<any_non_const_tg, optional_t> auto& self, tr1<any_non_const_tg, optional_t> auto&& other)
    {
        if (&self != std::addressof(other)) {
            self.has_value = nkr::Move(other.has_value);
            self.value = nkr::Move(other.value);
        }

        return self;
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::Has_Value(const tr1<any_tg, optional_t> auto& self)
    {
        return self.has_value;
    }

    template <any_type_tr value_p>
    inline auto&
        optional_t<value_p>::Value(tr1<any_tg, optional_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Value(self));

        return self.value;
    }

    template <any_type_tr value_p>
    inline void_t
        optional_t<value_p>::Value(tr1<any_non_const_tg, optional_t> auto& self,
                                   const tr1<any_tg, value_t> auto& value)
    {
        self.has_value = true;
        self.value = value;
    }

    template <any_type_tr value_p>
    inline void_t
        optional_t<value_p>::Value(tr1<any_non_const_tg, optional_t> auto& self,
                                   tr1<any_non_const_tg, value_t> auto&& value)
    {
        self.has_value = true;
        self.value = nkr::Move(value);
    }

    template <any_type_tr value_p>
    inline void_t
        optional_t<value_p>::Value(tr1<any_non_const_tg, optional_t> auto& self,
                                   const tr2<any_tg, maybe_ttg, of_any_tg, value_t> auto& maybe_value)
    {
        self.has_value = maybe_value != none_t();
        self.value = maybe_value();
    }

    template <any_type_tr value_p>
    inline void_t
        optional_t<value_p>::Value(tr1<any_non_const_tg, optional_t> auto& self,
                                   tr2<any_tg, maybe_ttg, of_any_accessed_non_const_tg, value_t> auto&& maybe_value)
    {
        self.has_value = maybe_value != none_t();
        self.value = nkr::Move(maybe_value());
    }

    template <any_type_tr value_p>
    inline void_t
        optional_t<value_p>::Value(tr1<any_non_const_tg, optional_t> auto& self,
                                   const tr2<any_tg, some_ttg, of_any_tg, value_t> auto& some_value)
    {
        nkr_ASSERT_THAT(some_value);

        self.has_value = true;
        self.value = some_value();
    }

    template <any_type_tr value_p>
    inline void_t
        optional_t<value_p>::Value(tr1<any_non_const_tg, optional_t> auto& self,
                                   tr2<any_tg, some_ttg, of_any_accessed_non_const_tg, value_t> auto&& some_value)
    {
        nkr_ASSERT_THAT(some_value);

        self.has_value = true;
        self.value = nkr::Move(some_value());
    }

    template <any_type_tr value_p>
    inline void_t
        optional_t<value_p>::Clear(const tr1<any_tg, optional_t> auto& self)
    {
        self.has_value = false;
        self.value = value_t();
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
        return Assign_Copy(*this, other);
    }

    template <any_type_tr value_p>
    inline volatile optional_t<value_p>&
        optional_t<value_p>::operator =(const optional_t& other)
        volatile
    {
        return Assign_Copy(*this, other);
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>&
        optional_t<value_p>::operator =(const volatile optional_t& other)
    {
        return Assign_Copy(*this, other);
    }

    template <any_type_tr value_p>
    inline volatile optional_t<value_p>&
        optional_t<value_p>::operator =(const volatile optional_t& other)
        volatile
    {
        return Assign_Copy(*this, other);
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>&
        optional_t<value_p>::operator =(optional_t&& other)
        noexcept
    {
        return Assign_Move(*this, nkr::Move(other));
    }

    template <any_type_tr value_p>
    inline volatile optional_t<value_p>&
        optional_t<value_p>::operator =(optional_t&& other)
        volatile noexcept
    {
        return Assign_Move(*this, nkr::Move(other));
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>&
        optional_t<value_p>::operator =(is_just_volatile_tr<optional_t> auto&& other)
        noexcept
    {
        return Assign_Move(*this, nkr::Move(other));
    }

    template <any_type_tr value_p>
    inline volatile optional_t<value_p>&
        optional_t<value_p>::operator =(is_just_volatile_tr<optional_t> auto&& other)
        volatile noexcept
    {
        return Assign_Move(*this, nkr::Move(other));
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
        return Has_Value(*this);
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::Has_Value()
        const volatile
    {
        return Has_Value(*this);
    }

    template <any_type_tr value_p>
    inline typename optional_t<value_p>::value_t&
        optional_t<value_p>::Value()
    {
        return Value(*this);
    }

    template <any_type_tr value_p>
    inline const typename optional_t<value_p>::value_t&
        optional_t<value_p>::Value()
        const
    {
        return Value(*this);
    }

    template <any_type_tr value_p>
    inline volatile typename optional_t<value_p>::value_t&
        optional_t<value_p>::Value()
        volatile
    {
        return Value(*this);
    }

    template <any_type_tr value_p>
    inline const volatile typename optional_t<value_p>::value_t&
        optional_t<value_p>::Value()
        const volatile
    {
        return Value(*this);
    }

    template <any_type_tr value_p>
    inline void_t
        optional_t<value_p>::Value(const tr1<any_tg, value_t> auto& value)
    {
        return Value(*this, value);
    }

    template <any_type_tr value_p>
    inline void_t
        optional_t<value_p>::Value(const tr1<any_tg, value_t> auto& value)
        volatile
    {
        return Value(*this, value);
    }

    template <any_type_tr value_p>
    inline void_t
        optional_t<value_p>::Value(tr1<any_non_const_tg, value_t> auto&& value)
    {
        return Value(*this, nkr::Move(value));
    }

    template <any_type_tr value_p>
    inline void_t
        optional_t<value_p>::Value(tr1<any_non_const_tg, value_t> auto&& value)
        volatile
    {
        return Value(*this, nkr::Move(value));
    }

    template <any_type_tr value_p>
    inline void_t
        optional_t<value_p>::Value(const tr2<any_tg, maybe_ttg, of_any_tg, value_t> auto& maybe_value)
    {
        return Value(*this, value);
    }

    template <any_type_tr value_p>
    inline void_t
        optional_t<value_p>::Value(const tr2<any_tg, maybe_ttg, of_any_tg, value_t> auto& maybe_value)
        volatile
    {
        return Value(*this, value);
    }

    template <any_type_tr value_p>
    inline void_t
        optional_t<value_p>::Value(tr2<any_tg, maybe_ttg, of_any_accessed_non_const_tg, value_t> auto&& maybe_value)
    {
        return Value(*this, nkr::Move(value));
    }

    template <any_type_tr value_p>
    inline void_t
        optional_t<value_p>::Value(tr2<any_tg, maybe_ttg, of_any_accessed_non_const_tg, value_t> auto&& maybe_value)
        volatile
    {
        return Value(*this, nkr::Move(value));
    }

    template <any_type_tr value_p>
    inline void_t
        optional_t<value_p>::Value(const tr2<any_tg, some_ttg, of_any_tg, value_t> auto& some_value)
    {
        return Value(*this, value);
    }

    template <any_type_tr value_p>
    inline void_t
        optional_t<value_p>::Value(const tr2<any_tg, some_ttg, of_any_tg, value_t> auto& some_value)
        volatile
    {
        return Value(*this, value);
    }

    template <any_type_tr value_p>
    inline void_t
        optional_t<value_p>::Value(tr2<any_tg, some_ttg, of_any_accessed_non_const_tg, value_t> auto&& some_value)
    {
        return Value(*this, nkr::Move(value));
    }

    template <any_type_tr value_p>
    inline void_t
        optional_t<value_p>::Value(tr2<any_tg, some_ttg, of_any_accessed_non_const_tg, value_t> auto&& some_value)
        volatile
    {
        return Value(*this, nkr::Move(value));
    }

    template <any_type_tr value_p>
    inline void_t
        optional_t<value_p>::Clear()
    {
        return Clear(*this);
    }

    template <any_type_tr value_p>
    inline void_t
        optional_t<value_p>::Clear()
        volatile
    {
        return Clear(*this);
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::operator c_bool_t()
        const
    {
        return Has_Value(*this);
    }

    template <any_type_tr value_p>
    inline optional_t<value_p>::operator c_bool_t()
        const volatile
    {
        return Has_Value(*this);
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
        Clear(*this);

        return *this;
    }

    template <any_type_tr value_p>
    inline volatile optional_t<value_p>&
        optional_t<value_p>::operator =(none_t)
        volatile
    {
        Clear(*this);

        return *this;
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::operator ==(none_t)
        const
    {
        return !Has_Value(*this);
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::operator ==(none_t)
        const volatile
    {
        return !Has_Value(*this);
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::operator !=(none_t)
        const
    {
        return Has_Value(*this);
    }

    template <any_type_tr value_p>
    inline bool_t
        optional_t<value_p>::operator !=(none_t)
        const volatile
    {
        return Has_Value(*this);
    }

}

namespace nkr {

    inline bool_t
        operator ==(const tr1<any_tg, optional_tg> auto& a, const tr0<any_tg> auto& b)
    {
        using a_t = std::remove_reference_t<decltype(a)>;
        using b_t = std::remove_reference_t<decltype(b)>;

        if constexpr (is_any_tr<b_t, none_t>) {
            return a.operator ==(b);
        } else if constexpr (is_any_tr<b_t, typename a_t::value_t>) {
            if constexpr (can_equal_to_tr<decltype(a.Value()), decltype(b)>) {
                return a.Has_Value() && a.Value() == b;
            } else {
                [] <bool _ = false>() { static_assert(_, "these two values can not be equal to each other."); }();
            }
        } else if constexpr (tr1<b_t, any_tg, optional_tg>) {
            if constexpr (can_equal_to_tr<decltype(a.Value()), decltype(b.Value())>) {
                if (a.Has_Value() && b.Has_Value()) {
                    return a.Value() == b.Value();
                } else {
                    return !a.Has_Value() && !b.Has_Value();
                }
            } else {
                [] <bool _ = false>() { static_assert(_, "these two values can not be equal to each other."); }();
            }
        } else {
            if constexpr (can_equal_to_tr<decltype(a.Value()), decltype(b)>) {
                return a.Has_Value() && a.Value() == b;
            } else {
                [] <bool _ = false>() { static_assert(_, "these two values can not be equal to each other."); }();
            }
        }
    }

    inline bool_t
        operator ==(const tr1<any_tg, optional_tg> auto& a, const tr0<any_tg> auto&& b)
    {
        return operator ==(a, b);
    }

    inline bool_t
        operator ==(const tr1<any_tg, optional_tg> auto&& a, const tr0<any_tg> auto& b)
    {
        return operator ==(a, b);
    }

    inline bool_t
        operator ==(const tr1<any_tg, optional_tg> auto&& a, const tr0<any_tg> auto&& b)
    {
        return operator ==(a, b);
    }

    inline bool_t
        operator !=(const tr1<any_tg, optional_tg> auto& a, const tr0<any_tg> auto& b)
    {
        return !operator ==(a, b);
    }

    inline bool_t
        operator !=(const tr1<any_tg, optional_tg> auto& a, const tr0<any_tg> auto&& b)
    {
        return !operator ==(a, b);
    }

    inline bool_t
        operator !=(const tr1<any_tg, optional_tg> auto&& a, const tr0<any_tg> auto& b)
    {
        return !operator ==(a, b);
    }

    inline bool_t
        operator !=(const tr1<any_tg, optional_tg> auto&& a, const tr0<any_tg> auto&& b)
    {
        return !operator ==(a, b);
    }

}
