/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/utils.h"

#include "nkr/array/static_t_dec.h"

namespace nkr { namespace array {

    template <any_type_tr unit_p>
    inline auto&
        static_t<unit_p>::Copy_Assign(is_any_non_const_tr<static_t> auto& self, const is_any_tr<static_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            self.pointer = other.pointer;
        }

        return self;
    }

    template <any_type_tr unit_p>
    inline auto&
        static_t<unit_p>::Move_Assign(is_any_non_const_tr<static_t> auto& self, is_any_non_const_tr<static_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            self.pointer = nkr::Move(other.pointer);
        }

        return self;
    }

    template <any_type_tr unit_p>
    inline count_t
        static_t<unit_p>::Count(const is_any_tr<static_t> auto& self)
    {
        return self.pointer.Unit_Count();
    }

    template <any_type_tr unit_p>
    inline typename static_t<unit_p>::unit_t&
        static_t<unit_p>::At(const is_any_tr<static_t> auto& self, index_t index)
    {
        return self.pointer[index];
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::static_t(const some_t<pointer_t>& pointer) :
        pointer(pointer)
    {
        nkr_ASSERT_THAT(pointer);
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::static_t(some_t<pointer_t>&& pointer) :
        pointer(nkr::Move(pointer))
    {
        nkr_ASSERT_THAT(pointer);
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::static_t(const static_t& other) :
        pointer(other.pointer)
    {
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::static_t(const volatile static_t& other) :
        pointer(other.pointer)
    {
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::static_t(static_t&& other) noexcept :
        pointer(nkr::Move(other.pointer))
    {
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::static_t(volatile static_t&& other) noexcept :
        pointer(nkr::Move(other.pointer))
    {
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>&
        static_t<unit_p>::operator =(const static_t& other)
    {
        return Copy_Assign(*this, other);
    }

    template <any_type_tr unit_p>
    inline volatile static_t<unit_p>&
        static_t<unit_p>::operator =(const static_t& other)
        volatile
    {
        return Copy_Assign(*this, other);
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>&
        static_t<unit_p>::operator =(const volatile static_t& other)
    {
        return Copy_Assign(*this, other);
    }

    template <any_type_tr unit_p>
    inline volatile static_t<unit_p>&
        static_t<unit_p>::operator =(const volatile static_t& other)
        volatile
    {
        return Copy_Assign(*this, other);
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>&
        static_t<unit_p>::operator =(static_t&& other)
        noexcept
    {
        return Move_Assign(*this, other);
    }

    template <any_type_tr unit_p>
    inline volatile static_t<unit_p>&
        static_t<unit_p>::operator =(static_t&& other)
        volatile noexcept
    {
        return Move_Assign(*this, other);
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>&
        static_t<unit_p>::operator =(is_just_volatile_tr<static_t> auto&& other)
        noexcept
    {
        return Move_Assign(*this, other);
    }

    template <any_type_tr unit_p>
    inline volatile static_t<unit_p>&
        static_t<unit_p>::operator =(is_just_volatile_tr<static_t> auto&& other)
        volatile noexcept
    {
        return Move_Assign(*this, other);
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::~static_t()
    {
    }

    template <any_type_tr unit_p>
    inline count_t
        static_t<unit_p>::Count()
        const
    {
        return Count(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        static_t<unit_p>::Count()
        const volatile
    {
        return Count(*this);
    }

    template <any_type_tr unit_p>
    inline typename static_t<unit_p>::unit_t&
        static_t<unit_p>::At(index_t index)
        const
    {
        return At(*this, index);
    }

    template <any_type_tr unit_p>
    inline typename static_t<unit_p>::unit_t&
        static_t<unit_p>::At(index_t index)
        const volatile
    {
        return At(*this, index);
    }

    template <any_type_tr unit_p>
    inline typename static_t<unit_p>::unit_t&
        static_t<unit_p>::operator [](index_t index)
        const
    {
        return At(*this, index);
    }

    template <any_type_tr unit_p>
    inline typename static_t<unit_p>::unit_t&
        static_t<unit_p>::operator [](index_t index)
        const volatile
    {
        return At(*this, index);
    }

}}
