/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/utils.h"

#include "nkr/array/static_t_dec.h"

namespace nkr {

    template <typename other_p>
    inline constexpr c_bool_t
        type_traits_i<array::static_tg>::Is_Any()
    {
        return array::$static_t::any_tr<other_p>;
    }

    inline constexpr c_bool_t
        template_traits_i<array::static_ttg>::Is_Implemented()
    {
        return true;
    }

}

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
        static_t<unit_p>::Move_Assign(is_any_non_const_tr<static_t> auto& self, is_any_non_const_tr<static_t> auto&& other)
    {
        if (&self != std::addressof(other)) {
            self.pointer = nkr::Move(other.pointer);
        }

        return self;
    }

    template <any_type_tr unit_p>
    inline bool_t
        static_t<unit_p>::Has_Memory(const is_any_tr<static_t> auto& self)
    {
        return self.pointer;
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
    inline static_t<unit_p>::static_t() :
        pointer()
    {
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::static_t(const maybe_t<pointer_t>& pointer) :
        pointer(pointer)
    {
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::static_t(maybe_t<pointer_t>&& pointer) :
        pointer(nkr::Move(pointer))
    {
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::static_t(tr2<any_tg, array_ttg, of_just_tg, unit_t> auto& array) :
        pointer(maybe_t<pointer_t>(&array[0], array.Count()))
    {
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
        return Move_Assign(*this, nkr::Move(other));
    }

    template <any_type_tr unit_p>
    inline volatile static_t<unit_p>&
        static_t<unit_p>::operator =(static_t&& other)
        volatile noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>&
        static_t<unit_p>::operator =(is_just_volatile_tr<static_t> auto&& other)
        noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <any_type_tr unit_p>
    inline volatile static_t<unit_p>&
        static_t<unit_p>::operator =(is_just_volatile_tr<static_t> auto&& other)
        volatile noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::~static_t()
    {
    }

    template <any_type_tr unit_p>
    inline bool_t
        static_t<unit_p>::Has_Memory()
        const
    {
        return Has_Memory(*this);
    }

    template <any_type_tr unit_p>
    inline bool_t
        static_t<unit_p>::Has_Memory()
        const volatile
    {
        return Has_Memory(*this);
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
