/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/array/stack_t.h"

namespace nkr {

    template <type_tr unit_p, count_t capacity_p>
    inline constexpr count_t
        stack_array_t<unit_p, capacity_p>::Capacity()
    {
        return capacity_p;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Copy(const same_as_any_tr<stack_array_t> auto& from,
                                                same_as_any_tr<stack_array_t> auto& to)
    {
        assert(to.unit_count == 0);

        for (index_t idx = 0, end = from.unit_count; idx < end; idx += 1) {
            to.Writable_Array()[idx] = from.Array()[idx];
        }
        to.unit_count = from.unit_count;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Move(const same_as_any_tr<stack_array_t> auto& from,
                                                same_as_any_tr<stack_array_t> auto& to)
    {
        assert(to.unit_count == 0);

        for (index_t idx = 0, end = from.unit_count; idx < end; idx += 1) {
            if constexpr (built_in_tr<unit_t>) {
                to.Writable_Array()[idx] = std::exchange(from.Writable_Array()[idx], std::remove_cv_t<unit_t>(0));
            } else {
                to.Writable_Array()[idx] = std::move(from.Writable_Array()[idx]);
            }
        }
        to.unit_count = from.unit_count;
        from.unit_count = 0;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Destroy(same_as_any_tr<stack_array_t> auto& self)
    {
        self.Clear();
    }

    template <type_tr unit_p, count_t capacity_p>
    inline auto&
        stack_array_t<unit_p, capacity_p>::Array(same_as_any_tr<stack_array_t> auto& self)
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
        stack_array_t<unit_p, capacity_p>::Writable_Array(same_as_any_writable_tr<stack_array_t> auto& self)
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
        stack_array_t<unit_p, capacity_p>::Count(const same_as_any_tr<stack_array_t> auto& self)
    {
        return self.unit_count;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline auto&
        stack_array_t<unit_p, capacity_p>::At(same_as_any_tr<stack_array_t> auto& self, index_t index)
    {
        assert(index < self.unit_count);

        return Array(self)[index];
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Push(same_as_any_tr<stack_array_t> auto& self,
                                                same_as_any_tr<unit_t> auto& unit,
                                                same_as_any_tr<unit_t> auto& ...more_units)
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
        stack_array_t<unit_p, capacity_p>::Push(same_as_any_tr<stack_array_t> auto& self,
                                                same_as_any_writable_tr<unit_t> auto&& unit,
                                                same_as_any_writable_tr<unit_t> auto&& ...more_units)
    {
        assert(self.unit_count < Capacity());

        Writable_Array(self)[self.unit_count] = std::move(unit);
        self.unit_count += 1;

        if constexpr (sizeof...(more_units) > 0) {
            Push(self, std::move(more_units)...);
        }
    }

    template <type_tr unit_p, count_t capacity_p>
    inline auto
        stack_array_t<unit_p, capacity_p>::Pop(same_as_any_writable_tr<stack_array_t> auto& self)
    {
        assert(self.unit_count > 0);

        self.unit_count -= 1;
        if constexpr (built_in_tr<unit_t>) {
            return std::exchange(Writable_Array(self)[self.unit_count], std::remove_cv_t<unit_t>(0));
        } else {
            return std::move(Writable_Array(self)[self.unit_count]);
        }
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Copy_Into(const same_as_any_tr<stack_array_t> auto& self,
                                                     push_copy_i<unit_t> auto& other)
    {
        for (index_t idx = 0, end = self.unit_count; idx < end; idx += 1) {
            other.Push(Array(self)[idx]);
        }
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Move_Into(same_as_any_writable_tr<stack_array_t> auto& self,
                                                     push_move_i<unit_t> auto& other)
    {
        for (index_t idx = 0, end = self.unit_count; idx < end; idx += 1) {
            if constexpr (built_in_tr<unit_t>) {
                other.Push(std::exchange(Writable_Array(self)[idx], std::remove_cv_t<unit_t>(0)));
            } else {
                other.Push(std::move(Writable_Array(self)[idx]));
            }
        }
        self.unit_count = 0;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline bool_t
        stack_array_t<unit_p, capacity_p>::Is_Clear(const same_as_any_tr<stack_array_t> auto& self)
    {
        return self.unit_count == 0;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Clear(same_as_any_writable_tr<stack_array_t> auto& self)
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
    inline stack_array_t<unit_p, capacity_p>::stack_array_t(same_as_any_tr<unit_t> auto& ...args) :
        unit_count(0)
    {
        assert(sizeof...(args) <= Capacity());

        Push(*this, args...);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::stack_array_t(same_as_any_writable_tr<unit_t> auto&& ...args) :
        unit_count(0)
    {
        assert(sizeof...(args) <= Capacity());

        Push(*this, std::move(args)...);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::stack_array_t(const stack_array_t& other) :
        unit_count(0)
    {
        Copy(other, *this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::stack_array_t(const volatile stack_array_t& other) :
        unit_count(0)
    {
        Copy(other, *this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::stack_array_t(stack_array_t&& other) noexcept :
        unit_count(0)
    {
        Move(other, *this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::stack_array_t(volatile stack_array_t&& other) noexcept :
        unit_count(0)
    {
        Move(other, *this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename stack_array_t<unit_p, capacity_p>&
        stack_array_t<unit_p, capacity_p>::operator =(const stack_array_t& other)
    {
        if (this != std::addressof(other)) {
            Destroy(*this);
            Copy(other, *this);
        }
        return *this;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename volatile stack_array_t<unit_p, capacity_p>&
        stack_array_t<unit_p, capacity_p>::operator =(const volatile stack_array_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            Destroy(*this);
            Copy(other, *this);
        }
        return *this;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename stack_array_t<unit_p, capacity_p>&
        stack_array_t<unit_p, capacity_p>::operator =(stack_array_t&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            Destroy(*this);
            Move(other, *this);
        }
        return *this;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename volatile stack_array_t<unit_p, capacity_p>&
        stack_array_t<unit_p, capacity_p>::operator =(volatile stack_array_t&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            Destroy(*this);
            Move(other, *this);
        }
        return *this;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::~stack_array_t()
    {
        Destroy(*this);
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
        stack_array_t<unit_p, capacity_p>::Push(same_as_any_tr<unit_t> auto& ...units)
    {
        return Push(*this, units...);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Push(same_as_any_tr<unit_t> auto& ...units)
        volatile
    {
        return Push(*this, units...);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Push(same_as_any_writable_tr<unit_t> auto&& ...units)
    {
        return Push(*this, std::move(units)...);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Push(same_as_any_writable_tr<unit_t> auto&& ...units)
        volatile
    {
        return Push(*this, std::move(units)...);
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
        stack_array_t<unit_p, capacity_p>::Copy_Into(push_copy_i<unit_t> auto& other)
        const
    {
        return Copy_Into(*this, other);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Copy_Into(push_copy_i<unit_t> auto& other)
        const volatile
    {
        return Copy_Into(*this, other);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Move_Into(push_move_i<unit_t> auto& other)
    {
        return Move_Into(*this, other);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Move_Into(push_move_i<volatile unit_t> auto& other)
        volatile
    {
        return Move_Into(*this, other);
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
