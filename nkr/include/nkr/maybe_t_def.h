/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/maybe_t_dec.h"

namespace nkr { namespace $maybe_t { namespace $built_in_sp {

    template <typename any_p>
    inline any_sp<any_p>::any_sp() :
        value(static_cast<std::remove_cv_t<value_t>>(0))
    {
    }

    template <typename any_p>
    inline any_sp<any_p>::any_sp(value_t value) :
        value(value)
    {
    }

    template <typename any_p>
    inline any_sp<any_p>::any_sp(const any_sp& other) :
        value(other.value)
    {
    }

    template <typename any_p>
    inline any_sp<any_p>::any_sp(const volatile any_sp& other) :
        value(other.value)
    {
    }

    template <typename any_p>
    inline any_sp<any_p>::any_sp(any_sp&& other) noexcept :
        value(nkr::Move(other.value))
    {
    }

    template <typename any_p>
    inline any_sp<any_p>::any_sp(volatile any_sp&& other) noexcept :
        value(nkr::Move(other.value))
    {
    }

    template <typename any_p>
    inline any_sp<any_p>&
        any_sp<any_p>::operator =(const any_sp& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <typename any_p>
    inline volatile any_sp<any_p>&
        any_sp<any_p>::operator =(const any_sp& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <typename any_p>
    inline any_sp<any_p>&
        any_sp<any_p>::operator =(const volatile any_sp& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <typename any_p>
    inline volatile any_sp<any_p>&
        any_sp<any_p>::operator =(const volatile any_sp& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <typename any_p>
    inline any_sp<any_p>&
        any_sp<any_p>::operator =(any_sp&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    template <typename any_p>
    inline volatile any_sp<any_p>&
        any_sp<any_p>::operator =(any_sp&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    template <typename any_p>
    inline any_sp<any_p>&
        any_sp<any_p>::operator =(is_just_volatile_tr<any_sp> auto&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    template <typename any_p>
    inline volatile any_sp<any_p>&
        any_sp<any_p>::operator =(is_just_volatile_tr<any_sp> auto&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    template <typename any_p>
    inline any_sp<any_p>::~any_sp()
    {
        if constexpr (any_non_const_tr<value_t>) {
            this->value = static_cast<std::remove_cv_t<value_t>>(0);
        }
    }

    template <typename any_p>
    inline any_sp<any_p>::operator value_t&()
    {
        return this->value;
    }

    template <typename any_p>
    inline any_sp<any_p>::operator const value_t&()
        const
    {
        return this->value;
    }

    template <typename any_p>
    inline any_sp<any_p>::operator volatile value_t& ()
        volatile
    {
        return this->value;
    }

    template <typename any_p>
    inline any_sp<any_p>::operator const volatile value_t& ()
        const volatile
    {
        return this->value;
    }

    template <typename any_p>
    inline typename any_sp<any_p>::value_t&
        any_sp<any_p>::operator ()()
    {
        return this->value;
    }

    template <typename any_p>
    inline typename const any_sp<any_p>::value_t&
        any_sp<any_p>::operator ()()
        const
    {
        return this->value;
    }

    template <typename any_p>
    inline typename volatile any_sp<any_p>::value_t&
        any_sp<any_p>::operator ()()
        volatile
    {
        return this->value;
    }

    template <typename any_p>
    inline typename const volatile any_sp<any_p>::value_t&
        any_sp<any_p>::operator ()()
        const volatile
    {
        return this->value;
    }

    template <typename any_p>
    inline any_sp<any_p>::any_sp(none_t) :
        value(static_cast<std::remove_cv_t<value_t>>(0))
    {
    }

    template <typename any_p>
    inline any_sp<any_p>&
        any_sp<any_p>::operator =(none_t)
    {
        this->value = static_cast<std::remove_cv_t<value_t>>(0);
        return *this;
    }

    template <typename any_p>
    inline volatile any_sp<any_p>&
        any_sp<any_p>::operator =(none_t)
        volatile
    {
        this->value = static_cast<std::remove_cv_t<value_t>>(0);
        return *this;
    }

    template <typename any_p>
    inline bool_t
        any_sp<any_p>::operator ==(none_t)
        const
    {
        return this->value == static_cast<std::remove_cv_t<value_t>>(0);
    }

    template <typename any_p>
    inline bool_t
        any_sp<any_p>::operator ==(none_t)
        const volatile
    {
        return this->value == static_cast<std::remove_cv_t<value_t>>(0);
    }

    template <typename any_p>
    inline bool_t
        any_sp<any_p>::operator !=(none_t)
        const
    {
        return !operator ==(none_t());
    }

    template <typename any_p>
    inline bool_t
        any_sp<any_p>::operator !=(none_t)
        const volatile
    {
        return !operator ==(none_t());
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator ++()
    {
        return this->value += 1.0;
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator ++()
        volatile
    {
        return this->value += 1.0;
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator ++(int)
    {
        value_t value = this->value;
        this->value += 1.0;
        return value;
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator ++(int)
        volatile
    {
        value_t value = this->value;
        this->value += 1.0;
        return value;
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator --()
    {
        return this->value -= 1.0;
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator --()
        volatile
    {
        return this->value -= 1.0;
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator --(int)
    {
        value_t value = this->value;
        this->value -= 1.0;
        return value;
    }

    template <real_tr real_p>
    inline typename real_sp<real_p>::value_t
        real_sp<real_p>::operator --(int)
        volatile
    {
        value_t value = this->value;
        this->value -= 1.0;
        return value;
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::pointer_sp::value_t
        pointer_sp<pointer_p>::operator ->()
        const
    {
        return this->value;
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::pointer_sp::value_t
        pointer_sp<pointer_p>::operator ->()
        const volatile
    {
        return this->value;
    }

}}}

namespace nkr { namespace $maybe_t {

    template <maybe_i user_defined_p>
    inline typename user_defined_sp<user_defined_p>::value_t&
        user_defined_sp<user_defined_p>::operator ()()
    {
        return static_cast<value_t&>(*this);
    }

    template <maybe_i user_defined_p>
    inline typename const user_defined_sp<user_defined_p>::value_t&
        user_defined_sp<user_defined_p>::operator ()()
        const
    {
        return static_cast<const value_t&>(*this);
    }

    template <maybe_i user_defined_p>
    inline typename volatile user_defined_sp<user_defined_p>::value_t&
        user_defined_sp<user_defined_p>::operator ()()
        volatile
    {
        return static_cast<volatile value_t&>(*this);
    }

    template <maybe_i user_defined_p>
    inline typename const volatile user_defined_sp<user_defined_p>::value_t&
        user_defined_sp<user_defined_p>::operator ()()
        const volatile
    {
        return static_cast<const volatile value_t&>(*this);
    }

}}
