/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/maybe_t.h"

namespace nkr { namespace $maybe_t { namespace $built_in_sp {

    template <typename any_p>
    inline any_sp<any_p>::any_sp() :
        value(value_t())
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
    inline any_sp<any_p>::any_sp(any_sp&& other) noexcept :
        value(std::exchange(other.value, value_t()))
    {
    }

    template <typename any_p>
    inline any_sp<any_p>& any_sp<any_p>::operator =(value_t value)
    {
        this->value = value;
        return *this;
    }

    template <typename any_p>
    inline any_sp<any_p>& any_sp<any_p>::operator =(const any_sp& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    template <typename any_p>
    inline any_sp<any_p>& any_sp<any_p>::operator =(any_sp&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->value = std::exchange(other.value, value_t());
        }
        return *this;
    }

    template <typename any_p>
    inline any_sp<any_p>::~any_sp()
    {
        this->value = value_t();
    }

    template <typename any_p>
    inline any_sp<any_p>::operator value_t&()
    {
        return this->value;
    }

    template <typename any_p>
    inline any_sp<any_p>::operator const value_t&() const
    {
        return this->value;
    }

    template <typename any_p>
    inline typename any_sp<any_p>::value_t& any_sp<any_p>::operator ()()
    {
        return this->value;
    }

    template <typename any_p>
    inline typename const any_sp<any_p>::value_t& any_sp<any_p>::operator ()() const
    {
        return this->value;
    }

    template <typename any_p>
    inline auto* any_sp<any_p>::operator &()
    {
        return &this->value;
    }

    template <typename any_p>
    inline const auto* any_sp<any_p>::operator &() const
    {
        return &this->value;
    }

    template <typename any_p>
    inline any_sp<any_p>& any_sp<any_p>::operator =(none_t)
    {
        this->value = value_t();
        return *this;
    }

    template <typename any_p>
    inline bool_t any_sp<any_p>::operator ==(none_t) const
    {
        return this->value == value_t();
    }

    template <typename any_p>
    inline bool_t any_sp<any_p>::operator !=(none_t) const
    {
        return !operator ==(none_t());
    }

    template <floating_point_tr floating_point_p>
    inline floating_point_sp<floating_point_p>::floating_point_sp(const any_sp<floating_point_p>& other) :
        any_sp<floating_point_p>(other)
    {
    }

    template <floating_point_tr floating_point_p>
    inline floating_point_sp<floating_point_p>::floating_point_sp(any_sp<floating_point_p>&& other) noexcept :
        any_sp<floating_point_p>(std::move(other))
    {
    }

    template <floating_point_tr floating_point_p>
    inline typename floating_point_sp<floating_point_p>::value_t floating_point_sp<floating_point_p>::operator ++()
    {
        return this->value += 1.0;
    }

    template <floating_point_tr floating_point_p>
    inline typename floating_point_sp<floating_point_p>::value_t floating_point_sp<floating_point_p>::operator ++(int)
    {
        value_t value = this->value;
        this->value += 1.0;
        return value;
    }

    template <floating_point_tr floating_point_p>
    inline typename floating_point_sp<floating_point_p>::value_t floating_point_sp<floating_point_p>::operator --()
    {
        return this->value -= 1.0;
    }

    template <floating_point_tr floating_point_p>
    inline typename floating_point_sp<floating_point_p>::value_t floating_point_sp<floating_point_p>::operator --(int)
    {
        value_t value = this->value;
        this->value -= 1.0;
        return value;
    }

    template <pointer_tr pointer_p>
    inline pointer_sp<pointer_p>::pointer_sp(const any_sp<pointer_p>& other) :
        any_sp<pointer_p>(other)
    {
    }

    template <pointer_tr pointer_p>
    inline pointer_sp<pointer_p>::pointer_sp(any_sp<pointer_p>&& other) noexcept :
        any_sp<pointer_p>(std::move(other))
    {
    }

    template <pointer_tr pointer_p>
    inline typename pointer_sp<pointer_p>::pointer_sp::value_t pointer_sp<pointer_p>::operator ->() const
    {
        return this->value;
    }

}}}

namespace nkr { namespace $maybe_t {

    template <none_i user_defined_p>
    inline user_defined_sp<user_defined_p>::user_defined_sp(const value_t& other) :
        value_t(other)
    {
    }

    template <none_i user_defined_p>
    inline user_defined_sp<user_defined_p>::user_defined_sp(value_t&& other) noexcept :
        value_t(std::move(other))
    {
    }

    template <none_i user_defined_p>
    inline user_defined_sp<user_defined_p>::operator bool_t() const
    {
        return value_t::operator !=(none_t());
    }

    template <none_i user_defined_p>
    inline typename user_defined_sp<user_defined_p>::value_t& user_defined_sp<user_defined_p>::operator ()()
    {
        return static_cast<value_t&>(*this);
    }

    template <none_i user_defined_p>
    inline typename const user_defined_sp<user_defined_p>::value_t& user_defined_sp<user_defined_p>::operator ()() const
    {
        return static_cast<const value_t&>(*this);
    }

    template <none_i user_defined_p>
    inline bool_t user_defined_sp<user_defined_p>::operator !() const
    {
        return !operator bool_t();
    }

    template <none_i user_defined_p>
    inline auto* user_defined_sp<user_defined_p>::operator &()
    {
        return &static_cast<value_t&>(*this);
    }

    template <none_i user_defined_p>
    inline const auto* user_defined_sp<user_defined_p>::operator &() const
    {
        return &static_cast<const value_t&>(*this);
    }

    template <none_i user_defined_p>
    inline user_defined_sp<user_defined_p>& user_defined_sp<user_defined_p>::operator =(none_t)
    {
        value_t::operator =(none_t());
        return *this;
    }

    template <none_i user_defined_p>
    inline bool_t user_defined_sp<user_defined_p>::operator ==(none_t) const
    {
        return value_t::operator ==(none_t());
    }

    template <none_i user_defined_p>
    inline bool_t user_defined_sp<user_defined_p>::operator !=(none_t) const
    {
        return value_t::operator !=(none_t());
    }

}}
