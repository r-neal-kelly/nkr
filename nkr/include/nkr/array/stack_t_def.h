/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/array/stack_t.h"
#include "nkr/utils.h"

namespace nkr {

    template <type_tr unit_p, count_t capacity_p>
    inline constexpr count_t
        stack_array_t<unit_p, capacity_p>::Capacity()
    {
        return capacity_p;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Copy_Construct(non_const_stack_array_of_tr<unit_t> auto& self,
                                                          const stack_array_of_tr<unit_t> auto& other)
    {
        assert(self.unit_count == 0);

        for (index_t idx = 0, end = other.unit_count; idx < end; idx += 1) {
            self.Writable_Array()[idx] = other.Array()[idx];
        }
        self.unit_count = other.unit_count;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Move_Construct(non_const_stack_array_of_tr<unit_t> auto& self,
                                                          non_const_stack_array_of_tr<unit_t> auto& other)
    {
        assert(self.unit_count == 0);

        for (index_t idx = 0, end = other.unit_count; idx < end; idx += 1) {
            self.Writable_Array()[idx] = nkr::Move(other.Writable_Array()[idx]);
        }
        self.unit_count = other.unit_count;
        other.unit_count = 0;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Destruct(stack_array_of_tr<unit_t> auto& self)
    {
        self.Clear();
    }

    template <type_tr unit_p, count_t capacity_p>
    inline auto&
        stack_array_t<unit_p, capacity_p>::Array(stack_array_of_tr<unit_t> auto& self)
    {
        using self_t = std::remove_reference_t<decltype(self)>;

        if constexpr (const_volatile_tr<self_t>) {
            return reinterpret_cast<const volatile array_t&>(self.byte_array);
        } else if constexpr (const_tr<self_t>) {
            return reinterpret_cast<const array_t&>(self.byte_array);
        } else if constexpr (volatile_tr<self_t>) {
            return reinterpret_cast<volatile array_t&>(self.byte_array);
        } else {
            return reinterpret_cast<array_t&>(self.byte_array);
        }
    }

    template <type_tr unit_p, count_t capacity_p>
    inline auto&
        stack_array_t<unit_p, capacity_p>::Writable_Array(non_const_stack_array_of_tr<unit_t> auto& self)
    {
        using self_t = std::remove_reference_t<decltype(self)>;

        if constexpr (volatile_tr<self_t>) {
            return reinterpret_cast<volatile writable_array_t&>(self.byte_array);
        } else {
            return reinterpret_cast<writable_array_t&>(self.byte_array);
        }
    }

    template <type_tr unit_p, count_t capacity_p>
    inline count_t
        stack_array_t<unit_p, capacity_p>::Count(const stack_array_of_tr<unit_t> auto& self)
    {
        return self.unit_count;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline auto&
        stack_array_t<unit_p, capacity_p>::At(stack_array_of_tr<unit_t> auto& self, index_t index)
    {
        assert(index < self.unit_count);

        return Array(self)[index];
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Push(non_const_stack_array_of_tr<unit_t> auto& self,
                                                is_any_tr<unit_t> auto& unit,
                                                is_any_tr<unit_t> auto& ...more_units)
    {
        assert(self.unit_count < Capacity());

        Writable_Array(self)[self.unit_count] = unit;
        self.unit_count += 1;

        if constexpr (sizeof...(more_units) > 0) {
            Push(self, more_units...);
        }
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Push(non_const_stack_array_of_tr<unit_t> auto& self,
                                                is_any_non_const_tr<unit_t> auto&& unit,
                                                is_any_non_const_tr<unit_t> auto&& ...more_units)
    {
        assert(self.unit_count < Capacity());

        Writable_Array(self)[self.unit_count] = nkr::Move(unit);
        self.unit_count += 1;

        if constexpr (sizeof...(more_units) > 0) {
            Push(self, nkr::Move(more_units)...);
        }
    }

    template <type_tr unit_p, count_t capacity_p>
    inline auto
        stack_array_t<unit_p, capacity_p>::Pop(non_const_stack_array_of_tr<unit_t> auto& self)
    {
        assert(self.unit_count > 0);

        self.unit_count -= 1;
        return nkr::Move(Writable_Array(self)[self.unit_count]);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Copy_To(const stack_array_of_tr<unit_t> auto& self,
                                                   non_const_array_of_any_tr<unit_t> auto& other)
    {
        assert(reinterpret_cast<const volatile void_t*>(std::addressof(self)) !=
               reinterpret_cast<const volatile void_t*>(std::addressof(other)));

        for (index_t idx = 0, end = self.unit_count; idx < end; idx += 1) {
            other.Push(Array(self)[idx]);
        }
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Copy_From(non_const_stack_array_of_tr<unit_t> auto& self,
                                                     const array_of_any_tr<unit_t> auto& other)
    {
        assert(reinterpret_cast<const volatile void_t*>(std::addressof(self)) !=
               reinterpret_cast<const volatile void_t*>(std::addressof(other)));

        return other.Copy_To(self);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Move_To(non_const_stack_array_of_any_non_const_tr<unit_t> auto& self,
                                                   non_const_array_of_any_tr<unit_t> auto& other)
    {
        assert(reinterpret_cast<const volatile void_t*>(std::addressof(self)) !=
               reinterpret_cast<const volatile void_t*>(std::addressof(other)));

        for (index_t idx = 0, end = self.unit_count; idx < end; idx += 1) {
            other.Push(nkr::Move(Writable_Array(self)[idx]));
        }
        self.unit_count = 0;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Move_From(non_const_stack_array_of_tr<unit_t> auto& self,
                                                     non_const_array_of_any_non_const_tr<unit_t> auto& other)
    {
        assert(reinterpret_cast<const volatile void_t*>(std::addressof(self)) !=
               reinterpret_cast<const volatile void_t*>(std::addressof(other)));

        return other.Move_To(self);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline bool_t
        stack_array_t<unit_p, capacity_p>::Is_Clear(const stack_array_of_tr<unit_t> auto& self)
    {
        return self.unit_count == 0;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Clear(non_const_stack_array_of_tr<unit_t> auto& self)
    {
        for (index_t idx = 0, end = self.unit_count; idx < end; idx += 1) {
            if constexpr (built_in_tr<unit_t>) {
                self.Writable_Array()[idx] = std::remove_cv_t<unit_t>(0);
            } else {
                self.Writable_Array()[idx].~unit_t();
            }
        }
        self.unit_count = 0;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::stack_array_t() :
        unit_count(0)
    {
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::stack_array_t(is_any_tr<unit_t> auto& ...args) :
        unit_count(0)
    {
        assert(sizeof...(args) <= Capacity());

        Push(*this, args...);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::stack_array_t(is_any_non_const_tr<unit_t> auto&& ...args) :
        unit_count(0)
    {
        assert(sizeof...(args) <= Capacity());

        Push(*this, nkr::Move(args)...);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::stack_array_t(const stack_array_t& other) :
        unit_count(0)
    {
        Copy_Construct(*this, other);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::stack_array_t(const volatile stack_array_t& other) :
        unit_count(0)
    {
        Copy_Construct(*this, other);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::stack_array_t(stack_array_t&& other) noexcept :
        unit_count(0)
    {
        Move_Construct(*this, other);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::stack_array_t(volatile stack_array_t&& other) noexcept :
        unit_count(0)
    {
        Move_Construct(*this, other);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename stack_array_t<unit_p, capacity_p>&
        stack_array_t<unit_p, capacity_p>::operator =(const stack_array_t& other)
    {
        if (this != std::addressof(other)) {
            Destruct(*this);
            Copy_Construct(*this, other);
        }
        return *this;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename volatile stack_array_t<unit_p, capacity_p>&
        stack_array_t<unit_p, capacity_p>::operator =(const volatile stack_array_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            Destruct(*this);
            Copy_Construct(*this, other);
        }
        return *this;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename stack_array_t<unit_p, capacity_p>&
        stack_array_t<unit_p, capacity_p>::operator =(stack_array_t&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            Destruct(*this);
            Move_Construct(*this, other);
        }
        return *this;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename volatile stack_array_t<unit_p, capacity_p>&
        stack_array_t<unit_p, capacity_p>::operator =(volatile stack_array_t&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            Destruct(*this);
            Move_Construct(*this, other);
        }
        return *this;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::~stack_array_t()
    {
        Destruct(*this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename stack_array_t<unit_p, capacity_p>::array_t&
        stack_array_t<unit_p, capacity_p>::Array()
    {
        return Array(*this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename const stack_array_t<unit_p, capacity_p>::array_t&
        stack_array_t<unit_p, capacity_p>::Array()
        const
    {
        return Array(*this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename volatile stack_array_t<unit_p, capacity_p>::array_t&
        stack_array_t<unit_p, capacity_p>::Array()
        volatile
    {
        return Array(*this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename const volatile stack_array_t<unit_p, capacity_p>::array_t&
        stack_array_t<unit_p, capacity_p>::Array()
        const volatile
    {
        return Array(*this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline count_t
        stack_array_t<unit_p, capacity_p>::Count()
        const
    {
        return Count(*this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline count_t
        stack_array_t<unit_p, capacity_p>::Count()
        const volatile
    {
        return Count(*this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename stack_array_t<unit_p, capacity_p>::unit_t&
        stack_array_t<unit_p, capacity_p>::At(index_t index)
    {
        return At(*this, index);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename const stack_array_t<unit_p, capacity_p>::unit_t&
        stack_array_t<unit_p, capacity_p>::At(index_t index)
        const
    {
        return At(*this, index);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename volatile stack_array_t<unit_p, capacity_p>::unit_t&
        stack_array_t<unit_p, capacity_p>::At(index_t index)
        volatile
    {
        return At(*this, index);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename const volatile stack_array_t<unit_p, capacity_p>::unit_t&
        stack_array_t<unit_p, capacity_p>::At(index_t index)
        const volatile
    {
        return At(*this, index);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Push(is_any_tr<unit_t> auto& ...units)
    {
        return Push(*this, units...);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Push(is_any_tr<unit_t> auto& ...units)
        volatile
    {
        return Push(*this, units...);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Push(is_any_non_const_tr<unit_t> auto&& ...units)
    {
        return Push(*this, nkr::Move(units)...);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Push(is_any_non_const_tr<unit_t> auto&& ...units)
        volatile
    {
        return Push(*this, nkr::Move(units)...);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename stack_array_t<unit_p, capacity_p>::unit_t
        stack_array_t<unit_p, capacity_p>::Pop()
    {
        return Pop(*this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename volatile stack_array_t<unit_p, capacity_p>::unit_t
        stack_array_t<unit_p, capacity_p>::Pop()
        volatile
    {
        return Pop(*this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Copy_To(non_const_array_of_any_tr<unit_t> auto& other)
        const
    {
        return Copy_To(*this, other);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Copy_To(non_const_array_of_any_tr<unit_t> auto& other)
        const volatile
    {
        return Copy_To(*this, other);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Copy_From(const array_of_any_tr<unit_t> auto& other)
    {
        return Copy_From(*this, other);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Copy_From(const array_of_any_tr<unit_t> auto& other)
        volatile
    {
        return Copy_From(*this, other);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Move_To(non_const_array_of_any_tr<unit_t> auto& other)
    {
        return Move_To(*this, other);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Move_To(non_const_array_of_any_tr<unit_t> auto& other)
        volatile
    {
        return Move_To(*this, other);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Move_From(non_const_array_of_any_non_const_tr<unit_t> auto& other)
    {
        return Move_From(*this, other);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Move_From(non_const_array_of_any_non_const_tr<unit_t> auto& other)
        volatile
    {
        return Move_From(*this, other);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline bool_t
        stack_array_t<unit_p, capacity_p>::Is_Clear()
        const
    {
        return Is_Clear(*this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline bool_t
        stack_array_t<unit_p, capacity_p>::Is_Clear()
        const volatile
    {
        return Is_Clear(*this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Clear()
    {
        return Clear(*this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Clear()
        volatile
    {
        return Clear(*this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename stack_array_t<unit_p, capacity_p>::writable_array_t&
        stack_array_t<unit_p, capacity_p>::Writable_Array()
    {
        return Writable_Array(*this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename volatile stack_array_t<unit_p, capacity_p>::writable_array_t&
        stack_array_t<unit_p, capacity_p>::Writable_Array()
        volatile
    {
        return Writable_Array(*this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename stack_array_t<unit_p, capacity_p>::unit_t&
        stack_array_t<unit_p, capacity_p>::operator [](index_t index)
    {
        return At(*this, index);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename const stack_array_t<unit_p, capacity_p>::unit_t&
        stack_array_t<unit_p, capacity_p>::operator [](index_t index)
        const
    {
        return At(*this, index);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename volatile stack_array_t<unit_p, capacity_p>::unit_t&
        stack_array_t<unit_p, capacity_p>::operator [](index_t index)
        volatile
    {
        return At(*this, index);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename const volatile stack_array_t<unit_p, capacity_p>::unit_t&
        stack_array_t<unit_p, capacity_p>::operator [](index_t index)
        const volatile
    {
        return At(*this, index);
    }

}
