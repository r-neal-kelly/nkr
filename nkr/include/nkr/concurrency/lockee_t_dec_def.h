/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/concurrency/lockee_t_dec.h"

namespace nkr { namespace concurrency { namespace $lockee_t {

    template <nkr::concurrency::lockee_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::concurrency::lockee_tr<other_p>;
    }

    template <nkr::concurrency::lockee_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::concurrency::lockee_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::concurrency::lockee_tr<other_p>;
    }

    template <nkr::cpp::is_any_tr<nkr::concurrency::lockee_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

namespace nkr { namespace concurrency { namespace $lockee_t {

    template <template <typename ...> typename template_p>
        requires nkr::concurrency::lockee_ttr<template_p>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_template_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::concurrency::lockee_ttr<other_p>;
    }

}}}

namespace nkr { namespace concurrency {

    template <tr<just_non_qualified_tg, t<nkr::generic::type_tg>> value_p>
    inline auto
        lockee_t<value_p>::Assert(const tr<any_tg, t<lockee_t>> auto& self)
        noexcept
    {
        nkr_ASSERT_THAT(self.locker.owns_lock()); // This object has been moved and you should no longer access it.
    }

    template <tr<just_non_qualified_tg, t<nkr::generic::type_tg>> value_p>
    inline auto&
        lockee_t<value_p>::Assign(tr<any_non_const_tg, t<lockee_t>> auto& self, tr<any_non_const_tg, t<lockee_t>> auto&& other)
        noexcept
    {
        Assert(self);

        if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
            self.value = other.value;
            self.lock = other.lock;
            self.locker = nkr::cpp::Move(other.locker);
        }

        return self;
    }

    template <tr<just_non_qualified_tg, t<nkr::generic::type_tg>> value_p>
    inline auto&
        lockee_t<value_p>::Value(const tr<any_tg, t<lockee_t>> auto& self)
        noexcept
    {
        Assert(self);

        return self.value;
    }

    template <tr<just_non_qualified_tg, t<nkr::generic::type_tg>> value_p>
    inline auto&
        lockee_t<value_p>::Value(tr<any_non_const_tg, t<lockee_t>> auto& self, const tr<any_tg, t<value_t>> auto& value)
        noexcept
    {
        Assert(self);

        self.value = value;

        return self;
    }

    template <tr<just_non_qualified_tg, t<nkr::generic::type_tg>> value_p>
    inline auto&
        lockee_t<value_p>::Value(tr<any_non_const_tg, t<lockee_t>> auto& self, tr<any_non_const_tg, t<value_t>> auto&& value)
        noexcept
    {
        Assert(self);

        self.value = nkr::cpp::Move(value);

        return self;
    }

    template <tr<just_non_qualified_tg, t<nkr::generic::type_tg>> value_p>
    inline lockee_t<value_p>::lockee_t(value_t& value, lock_t& lock) noexcept :
        value(value),
        lock(lock),
        locker(lock)
    {
        Assert(*this);
    }

    template <tr<just_non_qualified_tg, t<nkr::generic::type_tg>> value_p>
    inline lockee_t<value_p>::lockee_t(lockee_t&& other) noexcept :
        value(other.value),
        lock(other.lock),
        locker(nkr::cpp::Move(other.locker))
    {
        Assert(*this);
    }

    template <tr<just_non_qualified_tg, t<nkr::generic::type_tg>> value_p>
    inline lockee_t<value_p>&
        lockee_t<value_p>::operator =(lockee_t&& other)
        noexcept
    {
        return Assign(*this, nkr::cpp::Move(other));
    }

    template <tr<just_non_qualified_tg, t<nkr::generic::type_tg>> value_p>
    inline lockee_t<value_p>::~lockee_t() noexcept
    {
        if (this->locker.owns_lock()) {
            this->locker.unlock();
        }
    }

    template <tr<just_non_qualified_tg, t<nkr::generic::type_tg>> value_p>
    inline lockee_t<value_p>::value_t&
        lockee_t<value_p>::Value()
        noexcept
    {
        return Value(*this);
    }

    template <tr<just_non_qualified_tg, t<nkr::generic::type_tg>> value_p>
    inline const lockee_t<value_p>::value_t&
        lockee_t<value_p>::Value()
        const noexcept
    {
        return Value(*this);
    }

    template <tr<just_non_qualified_tg, t<nkr::generic::type_tg>> value_p>
    inline lockee_t<value_p>&
        lockee_t<value_p>::Value(const tr<any_tg, t<value_t>> auto& value)
        noexcept
    {
        return Value(*this, value);
    }

    template <tr<just_non_qualified_tg, t<nkr::generic::type_tg>> value_p>
    inline const lockee_t<value_p>&
        lockee_t<value_p>::Value(const tr<any_tg, t<value_t>> auto& value)
        const noexcept
    {
        return Value(*this, value);
    }

    template <tr<just_non_qualified_tg, t<nkr::generic::type_tg>> value_p>
    inline lockee_t<value_p>&
        lockee_t<value_p>::Value(tr<any_non_const_tg, t<value_t>> auto&& value)
        noexcept
    {
        return Value(*this, nkr::cpp::Move(value));
    }

    template <tr<just_non_qualified_tg, t<nkr::generic::type_tg>> value_p>
    inline const lockee_t<value_p>&
        lockee_t<value_p>::Value(tr<any_non_const_tg, t<value_t>> auto&& value)
        const noexcept
    {
        return Value(*this, nkr::cpp::Move(value));
    }

    template <tr<just_non_qualified_tg, t<nkr::generic::type_tg>> value_p>
    inline lockee_t<value_p>::operator lockee_t<value_p>::value_t&()
        noexcept
    {
        return Value(*this);
    }

    template <tr<just_non_qualified_tg, t<nkr::generic::type_tg>> value_p>
    inline lockee_t<value_p>::operator const lockee_t<value_p>::value_t&()
        const noexcept
    {
        return Value(*this);
    }

}}
