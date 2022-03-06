/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_utils.h"

#include "nkr/z_array/stack_t_def.h"
#include "nkr/z_array/static_t_dec.h"

namespace nkr {

    template <typename other_p>
    inline constexpr c_bool_t
        type_traits_i<array::static_tg>::Is_Any()
    {
        return array::static_t$::any_tr<other_p>;
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
    inline auto
        static_t<unit_p>::Pointer(is_any_tr<static_t> auto& self)
    {
        using self_t = std::remove_reference_t<decltype(self)>;
        using qualified_unit_t = accessed_qualification_of_t<unit_t, self_t>;

        return maybe_t<pointer_t<qualified_unit_t>>
            (reinterpret_cast<qualified_unit_t*>(self.pointer.Units()), Count(self));
    }

    template <any_type_tr unit_p>
    inline void_t
        static_t<unit_p>::Pointer(is_any_non_const_tr<static_t> auto& self, maybe_t<pointer_t<unit_t>> new_pointer)
    {
        self.pointer = new_pointer;
    }

    template <any_type_tr unit_p>
    inline count_t
        static_t<unit_p>::Count(const is_any_tr<static_t> auto& self)
    {
        return self.pointer.Unit_Count();
    }

    template <any_type_tr unit_p>
    inline void_t
        static_t<unit_p>::Count(tr1<any_non_const_tg, static_t> auto& self, count_t new_unit_count)
    {
        self.pointer.Unit_Count() = new_unit_count;
    }

    template <any_type_tr unit_p>
    inline auto&
        static_t<unit_p>::Unit(is_any_tr<static_t> auto& self, index_t index)
    {
        using self_t = std::remove_reference_t<decltype(self)>;
        using qualified_unit_t = accessed_qualification_of_t<unit_t, self_t>;

        nkr_ASSERT_THAT(Has_Memory(self));
        nkr_ASSERT_THAT(index < Count(self));

        return static_cast<qualified_unit_t&>(self.pointer[index]);
    }

    template <any_type_tr unit_p>
    inline typename static_t<unit_p>::split_t
        static_t<unit_p>::Split(const is_any_tr<static_t> auto& self, index_t at_index)
    {
        nkr_ASSERT_THAT(Has_Memory(self));
        nkr_ASSERT_THAT(at_index <= Count(self));

        return {
            static_t(pointer_t<unit_t>(self.pointer.Units(), at_index)),
            static_t(self.pointer + at_index)
        };
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::static_t() :
        pointer()
    {
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::static_t(const maybe_t<pointer_t<unit_t>>& pointer) :
        pointer(pointer)
    {
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::static_t(maybe_t<pointer_t<unit_t>>&& pointer) :
        pointer(nkr::Move(pointer))
    {
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::static_t(tr2<any_tg, pointable_array_ttg, of_just_accessed_tg, unit_t> auto& array) :
        pointer(array.Pointer())
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
    inline maybe_t<pointer_t<typename static_t<unit_p>::unit_t>>
        static_t<unit_p>::Pointer()
    {
        return Pointer(*this);
    }

    template <any_type_tr unit_p>
    inline maybe_t<pointer_t<const typename static_t<unit_p>::unit_t>>
        static_t<unit_p>::Pointer()
        const
    {
        return Pointer(*this);
    }

    template <any_type_tr unit_p>
    inline maybe_t<pointer_t<volatile typename static_t<unit_p>::unit_t>>
        static_t<unit_p>::Pointer()
        volatile
    {
        return Pointer(*this);
    }

    template <any_type_tr unit_p>
    inline maybe_t<pointer_t<const volatile typename static_t<unit_p>::unit_t>>
        static_t<unit_p>::Pointer()
        const volatile
    {
        return Pointer(*this);
    }

    template <any_type_tr unit_p>
    inline void_t
        static_t<unit_p>::Pointer(maybe_t<pointer_t<unit_t>> new_pointer)
    {
        return Pointer(*this, new_pointer);
    }

    template <any_type_tr unit_p>
    inline void_t
        static_t<unit_p>::Pointer(maybe_t<pointer_t<unit_t>> new_pointer)
        volatile
    {
        return Pointer(*this, new_pointer);
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
    inline void_t
        static_t<unit_p>::Count(count_t new_unit_count)
    {
        return Count(*this, new_unit_count);
    }

    template <any_type_tr unit_p>
    inline void_t
        static_t<unit_p>::Count(count_t new_unit_count)
        volatile
    {
        return Count(*this, new_unit_count);
    }

    template <any_type_tr unit_p>
    inline typename static_t<unit_p>::unit_t&
        static_t<unit_p>::Unit(index_t index)
    {
        return Unit(*this, index);
    }

    template <any_type_tr unit_p>
    inline const typename static_t<unit_p>::unit_t&
        static_t<unit_p>::Unit(index_t index)
        const
    {
        return Unit(*this, index);
    }

    template <any_type_tr unit_p>
    inline volatile typename static_t<unit_p>::unit_t&
        static_t<unit_p>::Unit(index_t index)
        volatile
    {
        return Unit(*this, index);
    }

    template <any_type_tr unit_p>
    inline const volatile typename static_t<unit_p>::unit_t&
        static_t<unit_p>::Unit(index_t index)
        const volatile
    {
        return Unit(*this, index);
    }

    template <any_type_tr unit_p>
    inline typename static_t<unit_p>::split_t
        static_t<unit_p>::Split(index_t at_index)
        const
    {
        return Split(*this, at_index);
    }

    template <any_type_tr unit_p>
    inline typename static_t<unit_p>::split_t
        static_t<unit_p>::Split(index_t at_index)
        const volatile
    {
        return Split(*this, at_index);
    }

    template <any_type_tr unit_p>
    inline typename static_t<unit_p>::unit_t&
        static_t<unit_p>::operator [](index_t index)
    {
        return Unit(*this, index);
    }

    template <any_type_tr unit_p>
    inline const typename static_t<unit_p>::unit_t&
        static_t<unit_p>::operator [](index_t index)
        const
    {
        return Unit(*this, index);
    }

    template <any_type_tr unit_p>
    inline volatile typename static_t<unit_p>::unit_t&
        static_t<unit_p>::operator [](index_t index)
        volatile
    {
        return Unit(*this, index);
    }

    template <any_type_tr unit_p>
    inline const volatile typename static_t<unit_p>::unit_t&
        static_t<unit_p>::operator [](index_t index)
        const volatile
    {
        return Unit(*this, index);
    }

}}
