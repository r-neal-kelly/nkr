/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_def.h"
#include "nkr/intrinsics_def.h"
#include "nkr/tr_def.h"

#include "nkr/boolean/deleted_operators_t_def.h"

#include "nkr/interface/template_i_def.h"
#include "nkr/interface/type_i_def.h"

#include "nkr/trait/boolean_tr_def.h"
#include "nkr/trait/boolean/any_tr_def.h"
#include "nkr/trait/boolean/pure_tr_def.h"

#include "nkr/boolean/fast_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr cpp::bool_t
        type_i<boolean::fast_tg>::Is_Any()
    {
        return boolean::fast_tr<other_p>;
    }

}}

namespace nkr { namespace boolean {

    inline constexpr cpp::bool_t
        fast_t::Is_Boolean_Type()
    {
        return true;
    }

    inline fast_t::fast_t() :
        value(static_cast<value_t>(false))
    {
    }

    template <typename type_p>
        requires std::convertible_to<type_p, fast_t::value_t>
    inline fast_t::fast_t(type_p value) :
        value(static_cast<value_t>(static_cast<c_bool_t>(value)))
    {
    }

    inline fast_t::fast_t(const fast_t& other) :
        value(other.value)
    {
    }

    inline fast_t::fast_t(const volatile fast_t& other) :
        value(other.value)
    {
    }

    inline fast_t::fast_t(fast_t&& other) noexcept :
        value(nkr::Move(other.value))
    {
    }

    inline fast_t::fast_t(volatile fast_t&& other) noexcept :
        value(nkr::Move(other.value))
    {
    }

    inline fast_t&
        fast_t::operator =(const fast_t& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    inline volatile fast_t&
        fast_t::operator =(const fast_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    inline fast_t&
        fast_t::operator =(const volatile fast_t& other)
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    inline volatile fast_t&
        fast_t::operator =(const volatile fast_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->value = other.value;
        }
        return *this;
    }

    inline fast_t&
        fast_t::operator =(fast_t&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    inline volatile fast_t&
        fast_t::operator =(fast_t&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    inline fast_t&
        fast_t::operator =(tr1<just_volatile_tg, fast_t> auto&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    inline volatile fast_t&
        fast_t::operator =(tr1<just_volatile_tg, fast_t> auto&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->value = nkr::Move(other.value);
        }
        return *this;
    }

    inline fast_t::~fast_t()
    {
        this->value = static_cast<value_t>(false);
    }

    inline fast_t::operator cpp::bool_t()
        const
    {
        return static_cast<cpp::bool_t>(this->value);
    }

    inline fast_t::operator cpp::bool_t()
        const volatile
    {
        return static_cast<cpp::bool_t>(this->value);
    }

    inline fast_t::operator value_t&()
    {
        return this->value;
    }

    inline fast_t::operator const value_t&()
        const
    {
        return this->value;
    }

    inline fast_t::operator volatile value_t&()
        volatile
    {
        return this->value;
    }

    inline fast_t::operator const volatile value_t&()
        const volatile
    {
        return this->value;
    }

    inline fast_t::fast_t(none_t) :
        value(static_cast<value_t>(false))
    {
    }

    inline fast_t&
        fast_t::operator =(none_t)
    {
        this->value = static_cast<value_t>(false);
        return *this;
    }

    inline volatile fast_t&
        fast_t::operator =(none_t)
        volatile
    {
        this->value = static_cast<value_t>(false);
        return *this;
    }

    inline fast_t
        fast_t::operator ==(none_t)
        const
    {
        return !static_cast<boolean::cpp_t>(this->value);
    }

    inline fast_t
        fast_t::operator ==(none_t)
        const volatile
    {
        return !static_cast<boolean::cpp_t>(this->value);
    }

    inline fast_t
        fast_t::operator !=(none_t)
        const
    {
        return !operator ==(none_t());
    }

    inline fast_t
        fast_t::operator !=(none_t)
        const volatile
    {
        return !operator ==(none_t());
    }

}}

namespace nkr { namespace boolean {

    static_assert(sizeof(fast_t) == sizeof(fast_t::value_t));

    static_assert(trait::boolean_tr<fast_t>);
    static_assert(trait::boolean_tr<const fast_t>);
    static_assert(trait::boolean_tr<volatile fast_t>);
    static_assert(trait::boolean_tr<const volatile fast_t>);

    static_assert(trait::boolean::any_tr<fast_t>);
    static_assert(trait::boolean::any_tr<const fast_t>);
    static_assert(trait::boolean::any_tr<volatile fast_t>);
    static_assert(trait::boolean::any_tr<const volatile fast_t>);

    static_assert(trait::boolean::pure_tr<fast_t>);
    static_assert(trait::boolean::pure_tr<const fast_t>);
    static_assert(trait::boolean::pure_tr<volatile fast_t>);
    static_assert(trait::boolean::pure_tr<const volatile fast_t>);

}}
