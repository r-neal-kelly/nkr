/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/concurrency/lockee_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::concurrency::lockee_tg>::Is_Any()
        noexcept
    {
        return nkr::concurrency::lockee_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::concurrency::lockee_ttg>::Is_Any()
        noexcept
    {
        return nkr::concurrency::lockee_ttr<other_p>;
    }

}}

namespace nkr { namespace concurrency {

    template <tr1<just_non_qualified_tg, nkr::generic::type_tg> value_p>
    inline auto
        lockee_t<value_p>::Assert(const tr1<any_tg, lockee_t> auto& self)
        noexcept
    {
        nkr_ASSERT_THAT(self.locker.owns_lock()); // This object has been moved and you should no longer access it.
    }

    template <tr1<just_non_qualified_tg, nkr::generic::type_tg> value_p>
    inline auto&
        lockee_t<value_p>::Assign(tr1<any_non_const_tg, lockee_t> auto& self, tr1<any_non_const_tg, lockee_t> auto&& other)
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

    template <tr1<just_non_qualified_tg, nkr::generic::type_tg> value_p>
    inline auto&
        lockee_t<value_p>::Value(const tr1<any_tg, lockee_t> auto& self)
        noexcept
    {
        Assert(self);

        return self.value;
    }

    template <tr1<just_non_qualified_tg, nkr::generic::type_tg> value_p>
    inline auto&
        lockee_t<value_p>::Value(tr1<any_non_const_tg, lockee_t> auto& self, const tr1<any_tg, value_t> auto& value)
        noexcept
    {
        Assert(self);

        self.value = value;

        return self;
    }

    template <tr1<just_non_qualified_tg, nkr::generic::type_tg> value_p>
    inline auto&
        lockee_t<value_p>::Value(tr1<any_non_const_tg, lockee_t> auto& self, tr1<any_non_const_tg, value_t> auto&& value)
        noexcept
    {
        Assert(self);

        self.value = nkr::cpp::Move(value);

        return self;
    }

    template <tr1<just_non_qualified_tg, nkr::generic::type_tg> value_p>
    inline lockee_t<value_p>::lockee_t(value_t& value, lock_t& lock) noexcept :
        value(value),
        lock(lock),
        locker(lock)
    {
        Assert(*this);
    }

    template <tr1<just_non_qualified_tg, nkr::generic::type_tg> value_p>
    inline lockee_t<value_p>::lockee_t(lockee_t&& other) noexcept :
        value(other.value),
        lock(other.lock),
        locker(nkr::cpp::Move(other.locker))
    {
        Assert(*this);
    }

    template <tr1<just_non_qualified_tg, nkr::generic::type_tg> value_p>
    inline lockee_t<value_p>&
        lockee_t<value_p>::operator =(lockee_t&& other)
        noexcept
    {
        return Assign(*this, nkr::cpp::Move(other));
    }

    template <tr1<just_non_qualified_tg, nkr::generic::type_tg> value_p>
    inline lockee_t<value_p>::~lockee_t() noexcept
    {
        if (this->locker.owns_lock()) {
            this->locker.unlock();
        }
    }

    template <tr1<just_non_qualified_tg, nkr::generic::type_tg> value_p>
    inline lockee_t<value_p>::value_t&
        lockee_t<value_p>::Value()
        noexcept
    {
        return Value(*this);
    }

    template <tr1<just_non_qualified_tg, nkr::generic::type_tg> value_p>
    inline const lockee_t<value_p>::value_t&
        lockee_t<value_p>::Value()
        const noexcept
    {
        return Value(*this);
    }

    template <tr1<just_non_qualified_tg, nkr::generic::type_tg> value_p>
    inline lockee_t<value_p>&
        lockee_t<value_p>::Value(const tr1<any_tg, value_t> auto& value)
        noexcept
    {
        return Value(*this, value);
    }

    template <tr1<just_non_qualified_tg, nkr::generic::type_tg> value_p>
    inline const lockee_t<value_p>&
        lockee_t<value_p>::Value(const tr1<any_tg, value_t> auto& value)
        const noexcept
    {
        return Value(*this, value);
    }

    template <tr1<just_non_qualified_tg, nkr::generic::type_tg> value_p>
    inline lockee_t<value_p>&
        lockee_t<value_p>::Value(tr1<any_non_const_tg, value_t> auto&& value)
        noexcept
    {
        return Value(*this, nkr::cpp::Move(value));
    }

    template <tr1<just_non_qualified_tg, nkr::generic::type_tg> value_p>
    inline const lockee_t<value_p>&
        lockee_t<value_p>::Value(tr1<any_non_const_tg, value_t> auto&& value)
        const noexcept
    {
        return Value(*this, nkr::cpp::Move(value));
    }

    template <tr1<just_non_qualified_tg, nkr::generic::type_tg> value_p>
    inline lockee_t<value_p>::operator lockee_t<value_p>::value_t&()
        noexcept
    {
        return Value(*this);
    }

    template <tr1<just_non_qualified_tg, nkr::generic::type_tg> value_p>
    inline lockee_t<value_p>::operator const lockee_t<value_p>::value_t&()
        const noexcept
    {
        return Value(*this);
    }

}}
