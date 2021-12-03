/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/macros_def.h"
#include "nkr/math_def.h"
#include "nkr/utils.h"

#include "nkr/array/stack_t_dec.h"

namespace nkr {

    template <typename other_p>
    inline constexpr c_bool_t
        type_traits_i<array::stack_tg>::Is_Any()
    {
        return array::$stack_t::any_tr<other_p>;
    }

    inline constexpr c_bool_t
        template_traits_i<array::stack_ttg>::Is_Implemented()
    {
        return true;
    }

}

namespace nkr { namespace array {

    template <any_type_tr unit_p, count_t capacity_p>
    inline constexpr count_t
        stack_t<unit_p, capacity_p>::Capacity()
    {
        return capacity_p;
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_t<unit_p, capacity_p>::Copy_Construct(is_any_non_const_tr<stack_t> auto& self,
                                                    const is_any_tr<stack_t> auto& other)
    {
        nkr_ASSERT_THAT(self.unit_count == 0);

        if (other.unit_count > 0) {
            maybe_t<allocator_err> err = Capacity(self, other.unit_count);
            if (!err) {
                for (index_t idx = 0, end = other.unit_count; idx < end; idx += 1) {
                    Writable_Array(self)[idx] = Array(other)[idx];
                }
                self.unit_count = other.unit_count;
            }
        }
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_t<unit_p, capacity_p>::Move_Construct(is_any_non_const_tr<stack_t> auto& self,
                                                    is_any_non_const_tr<stack_t> auto& other)
    {
        nkr_ASSERT_THAT(self.unit_count == 0);

        if (other.unit_count > 0) {
            maybe_t<allocator_err> err = Capacity(self, other.unit_count);
            if (!err) {
                for (index_t idx = 0, end = other.unit_count; idx < end; idx += 1) {
                    Writable_Array(self)[idx] = nkr::Move(Writable_Array(other)[idx]);
                }
                self.unit_count = nkr::Move(other.unit_count);
            }
        }
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline auto&
        stack_t<unit_p, capacity_p>::Copy_Assign(is_any_non_const_tr<stack_t> auto& self,
                                                 const is_any_tr<stack_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            Clear(self);
            maybe_t<allocator_err> err = Capacity(self, other.unit_count);
            if (!err) {
                for (index_t idx = 0, end = other.unit_count; idx < end; idx += 1) {
                    Writable_Array(self)[idx] = Array(other)[idx];
                }
                self.unit_count = other.unit_count;
            }

        }
        return self;
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline auto&
        stack_t<unit_p, capacity_p>::Move_Assign(is_any_non_const_tr<stack_t> auto& self,
                                                 is_any_non_const_tr<stack_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            Clear(self);
            maybe_t<allocator_err> err = Capacity(self, other.unit_count);
            if (!err) {
                for (index_t idx = 0, end = other.unit_count; idx < end; idx += 1) {
                    Writable_Array(self)[idx] = nkr::Move(Writable_Array(other)[idx]);
                }
                self.unit_count = nkr::Move(other.unit_count);
            }
        }
        return self;
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline bool_t
        stack_t<unit_p, capacity_p>::Has_Memory(const is_any_tr<stack_t> auto& self)
    {
        return true;
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline auto&
        stack_t<unit_p, capacity_p>::Array(is_any_tr<stack_t> auto& self)
    {
        using self_t = std::remove_reference_t<decltype(self)>;
        using qualified_array_t = accessed_qualification_of_t<array_t, self_t>;

        return reinterpret_cast<qualified_array_t&>(self.byte_array);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline auto&
        stack_t<unit_p, capacity_p>::Writable_Array(is_any_non_const_tr<stack_t> auto& self)
    {
        using self_t = std::remove_reference_t<decltype(self)>;

        if constexpr (any_volatile_tr<self_t>) {
            return reinterpret_cast<volatile writable_array_t&>(self.byte_array);
        } else {
            return reinterpret_cast<writable_array_t&>(self.byte_array);
        }
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline auto
        stack_t<unit_p, capacity_p>::Pointer(tr1<any_tg, stack_t> auto& self)
    {
        using self_t = std::remove_reference_t<decltype(self)>;
        using qualified_unit_t = accessed_qualification_of_t<unit_t, self_t>;

        return maybe_t<pointer_t<qualified_unit_t>>
            (reinterpret_cast<qualified_unit_t*>(self.byte_array), Count(self));
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline count_t
        stack_t<unit_p, capacity_p>::Capacity(const is_any_tr<stack_t> auto& self)
    {
        return capacity_p;
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<allocator_err>
        stack_t<unit_p, capacity_p>::Capacity(is_any_non_const_tr<stack_t> auto& self, count_t new_capacity)
    {
        if (new_capacity > Capacity(self)) {
            return allocator_err::OUT_OF_MEMORY;
        } else {
            const count_t unit_count = Count(self);
            if (new_capacity < unit_count) {
                // has consistent behavior with the array::dynamic_t
                for (count_t pop_count = unit_count - new_capacity; pop_count > 0; pop_count -= 1) {
                    Pop(self);
                }
            }

            return allocator_err::NONE;
        }
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline count_t
        stack_t<unit_p, capacity_p>::Count(const is_any_tr<stack_t> auto& self)
    {
        return self.unit_count;
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_t<unit_p, capacity_p>::Count(is_any_non_const_tr<stack_t> auto& self, count_t count)
    {
        nkr_ASSERT_THAT(count <= Capacity(self));

        self.unit_count = count;
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline auto&
        stack_t<unit_p, capacity_p>::At(is_any_tr<stack_t> auto& self, index_t index)
    {
        nkr_ASSERT_THAT(index < self.unit_count);

        return Array(self)[index];
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<allocator_err>
        stack_t<unit_p, capacity_p>::Push(is_any_non_const_tr<stack_t> auto& self,
                                          is_any_tr<unit_t> auto& ...units)
    {
        count_t count = Count(self);
        count_t other_count = sizeof...(units);
        if (math::Will_Overflow_Add(count, other_count)) {
            return allocator_err::OUT_OF_MEMORY;
        } else {
            maybe_t<allocator_err> err = Capacity(self, count + other_count);
            if (err) {
                return nkr::Move(err);
            } else {
                Push_Recursively(self, units...);

                return allocator_err::NONE;
            }
        }
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_t<unit_p, capacity_p>::Push_Recursively(is_any_non_const_tr<stack_t> auto& self,
                                                      is_any_tr<unit_t> auto& unit,
                                                      is_any_tr<unit_t> auto& ...more_units)
    {
        nkr_ASSERT_THAT(self.unit_count < Capacity(self));

        Writable_Array(self)[self.unit_count] = unit;
        self.unit_count += 1;

        if constexpr (sizeof...(more_units) > 0) {
            Push_Recursively(self, more_units...);
        }
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<allocator_err>
        stack_t<unit_p, capacity_p>::Push(is_any_non_const_tr<stack_t> auto& self,
                                          is_any_non_const_tr<unit_t> auto&& ...units)
    {
        count_t count = Count(self);
        count_t other_count = sizeof...(units);
        if (math::Will_Overflow_Add(count, other_count)) {
            return allocator_err::OUT_OF_MEMORY;
        } else {
            maybe_t<allocator_err> err = Capacity(self, count + other_count);
            if (err) {
                return nkr::Move(err);
            } else {
                Push_Recursively(self, nkr::Move(units)...);

                return allocator_err::NONE;
            }
        }
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_t<unit_p, capacity_p>::Push_Recursively(is_any_non_const_tr<stack_t> auto& self,
                                                      is_any_non_const_tr<unit_t> auto&& unit,
                                                      is_any_non_const_tr<unit_t> auto&& ...more_units)
    {
        nkr_ASSERT_THAT(self.unit_count < Capacity(self));

        Writable_Array(self)[self.unit_count] = nkr::Move(unit);
        self.unit_count += 1;

        if constexpr (sizeof...(more_units) > 0) {
            Push_Recursively(self, nkr::Move(more_units)...);
        }
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline auto
        stack_t<unit_p, capacity_p>::Pop(is_any_non_const_tr<stack_t> auto& self)
    {
        nkr_ASSERT_THAT(self.unit_count > 0);

        self.unit_count -= 1;
        return nkr::Move(Writable_Array(self)[self.unit_count]);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<allocator_err>
        stack_t<unit_p, capacity_p>::Copy_To(const is_any_tr<stack_t> auto& self,
                                             any_non_const_array_of_any_tr<unit_t> auto& other)
    {
        const count_t other_count = other.Count();
        const count_t count = Count(self);
        if (math::Will_Overflow_Add(other_count, count)) {
            return allocator_err::OUT_OF_MEMORY;
        } else {
            maybe_t<allocator_err> err = other.Capacity(other_count + count);
            if (err) {
                return err;
            } else {
                for (index_t idx = 0, end = count; idx < end; idx += 1) {
                    other.Push(Array(self)[idx]).Ignore_Error();
                }

                return allocator_err::NONE;
            }
        }
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<allocator_err>
        stack_t<unit_p, capacity_p>::Copy_From(is_any_non_const_tr<stack_t> auto& self,
                                               const any_array_of_any_tr<unit_t> auto& other)
    {
        return nkr::Move(other.Copy_To(self));
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<allocator_err>
        stack_t<unit_p, capacity_p>::Move_To(any_non_const_stack_of_any_non_const_tr<unit_t> auto& self,
                                             any_non_const_array_of_any_tr<unit_t> auto& other)
    {
        if (reinterpret_cast<const volatile void_t*>(std::addressof(self)) !=
            reinterpret_cast<const volatile void_t*>(std::addressof(other))) {
            const count_t other_count = other.Count();
            const count_t count = Count(self);
            if (math::Will_Overflow_Add(other_count, count)) {
                return allocator_err::OUT_OF_MEMORY;
            } else {
                maybe_t<allocator_err> err = other.Capacity(other_count + count);
                if (err) {
                    return err;
                } else {
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(nkr::Move(Writable_Array(self)[idx])).Ignore_Error();
                    }
                    self.unit_count = 0;

                    return allocator_err::NONE;
                }
            }
        } else {
            return allocator_err::NONE;
        }
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<allocator_err>
        stack_t<unit_p, capacity_p>::Move_From(is_any_non_const_tr<stack_t> auto& self,
                                               any_non_const_array_of_any_non_const_tr<unit_t> auto& other)
    {
        if (reinterpret_cast<const volatile void_t*>(std::addressof(self)) !=
            reinterpret_cast<const volatile void_t*>(std::addressof(other))) {
            return nkr::Move(other.Move_To(self));
        } else {
            return allocator_err::NONE;
        }
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline bool_t
        stack_t<unit_p, capacity_p>::Is_Clear(const is_any_tr<stack_t> auto& self)
    {
        return self.unit_count == 0;
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_t<unit_p, capacity_p>::Clear(is_any_non_const_tr<stack_t> auto& self)
    {
        for (index_t idx = 0, end = self.unit_count; idx < end; idx += 1) {
            if constexpr (built_in_tr<unit_t>) {
                Writable_Array(self)[idx] = std::remove_cv_t<unit_t>(0);
            } else {
                Writable_Array(self)[idx].~unit_t();
            }
        }
        self.unit_count = 0;
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline stack_t<unit_p, capacity_p>::stack_t() :
        unit_count(0)
    {
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline stack_t<unit_p, capacity_p>::stack_t(is_any_tr<unit_t> auto& ...args) :
        unit_count(0)
    {
        nkr_ASSERT_THAT(sizeof...(args) <= Capacity());

        Push(*this, args...).Ignore_Error();
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline stack_t<unit_p, capacity_p>::stack_t(is_any_non_const_tr<unit_t> auto&& ...args) :
        unit_count(0)
    {
        nkr_ASSERT_THAT(sizeof...(args) <= Capacity());

        Push(*this, nkr::Move(args)...).Ignore_Error();
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline stack_t<unit_p, capacity_p>::stack_t(const stack_t& other) :
        unit_count(0)
    {
        Copy_Construct(*this, other);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline stack_t<unit_p, capacity_p>::stack_t(const volatile stack_t& other) :
        unit_count(0)
    {
        Copy_Construct(*this, other);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline stack_t<unit_p, capacity_p>::stack_t(stack_t&& other) noexcept :
        unit_count(0)
    {
        Move_Construct(*this, other);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline stack_t<unit_p, capacity_p>::stack_t(volatile stack_t&& other) noexcept :
        unit_count(0)
    {
        Move_Construct(*this, other);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline stack_t<unit_p, capacity_p>&
        stack_t<unit_p, capacity_p>::operator =(const stack_t& other)
    {
        return Copy_Assign(*this, other);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline volatile stack_t<unit_p, capacity_p>&
        stack_t<unit_p, capacity_p>::operator =(const stack_t& other)
        volatile
    {
        return Copy_Assign(*this, other);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline stack_t<unit_p, capacity_p>&
        stack_t<unit_p, capacity_p>::operator =(const volatile stack_t& other)
    {
        return Copy_Assign(*this, other);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline volatile stack_t<unit_p, capacity_p>&
        stack_t<unit_p, capacity_p>::operator =(const volatile stack_t& other)
        volatile
    {
        return Copy_Assign(*this, other);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline stack_t<unit_p, capacity_p>&
        stack_t<unit_p, capacity_p>::operator =(stack_t&& other)
        noexcept
    {
        return Move_Assign(*this, other);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline volatile stack_t<unit_p, capacity_p>&
        stack_t<unit_p, capacity_p>::operator =(stack_t&& other)
        volatile noexcept
    {
        return Move_Assign(*this, other);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline stack_t<unit_p, capacity_p>&
        stack_t<unit_p, capacity_p>::operator =(is_just_volatile_tr<stack_t> auto&& other)
        noexcept
    {
        return Move_Assign(*this, other);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline volatile stack_t<unit_p, capacity_p>&
        stack_t<unit_p, capacity_p>::operator =(is_just_volatile_tr<stack_t> auto&& other)
        volatile noexcept
    {
        return Move_Assign(*this, other);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline stack_t<unit_p, capacity_p>::~stack_t()
    {
        Clear(*this);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline bool_t
        stack_t<unit_p, capacity_p>::Has_Memory()
        const
    {
        return Has_Memory(*this);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline bool_t
        stack_t<unit_p, capacity_p>::Has_Memory()
        const volatile
    {
        return Has_Memory(*this);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline typename stack_t<unit_p, capacity_p>::array_t&
        stack_t<unit_p, capacity_p>::Array()
    {
        return Array(*this);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline typename const stack_t<unit_p, capacity_p>::array_t&
        stack_t<unit_p, capacity_p>::Array()
        const
    {
        return Array(*this);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline typename volatile stack_t<unit_p, capacity_p>::array_t&
        stack_t<unit_p, capacity_p>::Array()
        volatile
    {
        return Array(*this);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline typename const volatile stack_t<unit_p, capacity_p>::array_t&
        stack_t<unit_p, capacity_p>::Array()
        const volatile
    {
        return Array(*this);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<pointer_t<typename stack_t<unit_p, capacity_p>::unit_t>>
        stack_t<unit_p, capacity_p>::Pointer()
    {
        static_assert(is_tr<decltype(Pointer(*this)), maybe_t<pointer_t<unit_t>>>);

        return Pointer(*this);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<pointer_t<const typename stack_t<unit_p, capacity_p>::unit_t>>
        stack_t<unit_p, capacity_p>::Pointer()
        const
    {
        static_assert(is_tr<decltype(Pointer(*this)), maybe_t<pointer_t<const unit_t>>>);

        return Pointer(*this);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<pointer_t<volatile typename stack_t<unit_p, capacity_p>::unit_t>>
        stack_t<unit_p, capacity_p>::Pointer()
        volatile
    {
        static_assert(is_tr<decltype(Pointer(*this)), maybe_t<pointer_t<volatile unit_t>>>);

        return Pointer(*this);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<pointer_t<const volatile typename stack_t<unit_p, capacity_p>::unit_t>>
        stack_t<unit_p, capacity_p>::Pointer()
        const volatile
    {
        static_assert(is_tr<decltype(Pointer(*this)), maybe_t<pointer_t<const volatile unit_t>>>);

        return Pointer(*this);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<allocator_err>
        stack_t<unit_p, capacity_p>::Capacity(count_t new_capacity)
    {
        return nkr::Move(Capacity(*this, new_capacity));
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<allocator_err>
        stack_t<unit_p, capacity_p>::Capacity(count_t new_capacity)
        volatile
    {
        return nkr::Move(Capacity(*this, new_capacity));
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline count_t
        stack_t<unit_p, capacity_p>::Count()
        const
    {
        return Count(*this);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline count_t
        stack_t<unit_p, capacity_p>::Count()
        const volatile
    {
        return Count(*this);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_t<unit_p, capacity_p>::Count(count_t count)
    {
        return Count(*this, count);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_t<unit_p, capacity_p>::Count(count_t count)
        volatile
    {
        return Count(*this, count);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline typename stack_t<unit_p, capacity_p>::unit_t&
        stack_t<unit_p, capacity_p>::At(index_t index)
    {
        return At(*this, index);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline typename const stack_t<unit_p, capacity_p>::unit_t&
        stack_t<unit_p, capacity_p>::At(index_t index)
        const
    {
        return At(*this, index);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline typename volatile stack_t<unit_p, capacity_p>::unit_t&
        stack_t<unit_p, capacity_p>::At(index_t index)
        volatile
    {
        return At(*this, index);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline typename const volatile stack_t<unit_p, capacity_p>::unit_t&
        stack_t<unit_p, capacity_p>::At(index_t index)
        const volatile
    {
        return At(*this, index);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<allocator_err>
        stack_t<unit_p, capacity_p>::Push(is_any_tr<unit_t> auto& ...units)
    {
        return nkr::Move(Push(*this, units...));
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<allocator_err>
        stack_t<unit_p, capacity_p>::Push(is_any_tr<unit_t> auto& ...units)
        volatile
    {
        return nkr::Move(Push(*this, units...));
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<allocator_err>
        stack_t<unit_p, capacity_p>::Push(is_any_non_const_tr<unit_t> auto&& ...units)
    {
        return nkr::Move(Push(*this, nkr::Move(units)...));
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<allocator_err>
        stack_t<unit_p, capacity_p>::Push(is_any_non_const_tr<unit_t> auto&& ...units)
        volatile
    {
        return nkr::Move(Push(*this, nkr::Move(units)...));
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline typename stack_t<unit_p, capacity_p>::unit_t
        stack_t<unit_p, capacity_p>::Pop()
    {
        return Pop(*this);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline typename volatile stack_t<unit_p, capacity_p>::unit_t
        stack_t<unit_p, capacity_p>::Pop()
        volatile
    {
        return Pop(*this);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<allocator_err>
        stack_t<unit_p, capacity_p>::Copy_To(any_non_const_array_of_any_tr<unit_t> auto& other)
        const
    {
        return nkr::Move(Copy_To(*this, other));
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<allocator_err>
        stack_t<unit_p, capacity_p>::Copy_To(any_non_const_array_of_any_tr<unit_t> auto& other)
        const volatile
    {
        return nkr::Move(Copy_To(*this, other));
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<allocator_err>
        stack_t<unit_p, capacity_p>::Copy_From(const any_array_of_any_tr<unit_t> auto& other)
    {
        return nkr::Move(Copy_From(*this, other));
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<allocator_err>
        stack_t<unit_p, capacity_p>::Copy_From(const any_array_of_any_tr<unit_t> auto& other)
        volatile
    {
        return nkr::Move(Copy_From(*this, other));
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<allocator_err>
        stack_t<unit_p, capacity_p>::Move_To(any_non_const_array_of_any_tr<unit_t> auto& other)
    {
        return nkr::Move(Move_To(*this, other));
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<allocator_err>
        stack_t<unit_p, capacity_p>::Move_To(any_non_const_array_of_any_tr<unit_t> auto& other)
        volatile
    {
        return nkr::Move(Move_To(*this, other));
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<allocator_err>
        stack_t<unit_p, capacity_p>::Move_From(any_non_const_array_of_any_non_const_tr<unit_t> auto& other)
    {
        return nkr::Move(Move_From(*this, other));
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline maybe_t<allocator_err>
        stack_t<unit_p, capacity_p>::Move_From(any_non_const_array_of_any_non_const_tr<unit_t> auto& other)
        volatile
    {
        return nkr::Move(Move_From(*this, other));
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline bool_t
        stack_t<unit_p, capacity_p>::Is_Clear()
        const
    {
        return Is_Clear(*this);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline bool_t
        stack_t<unit_p, capacity_p>::Is_Clear()
        const volatile
    {
        return Is_Clear(*this);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_t<unit_p, capacity_p>::Clear()
    {
        return Clear(*this);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_t<unit_p, capacity_p>::Clear()
        volatile
    {
        return Clear(*this);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline typename stack_t<unit_p, capacity_p>::unit_t&
        stack_t<unit_p, capacity_p>::operator [](index_t index)
    {
        return At(*this, index);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline typename const stack_t<unit_p, capacity_p>::unit_t&
        stack_t<unit_p, capacity_p>::operator [](index_t index)
        const
    {
        return At(*this, index);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline typename volatile stack_t<unit_p, capacity_p>::unit_t&
        stack_t<unit_p, capacity_p>::operator [](index_t index)
        volatile
    {
        return At(*this, index);
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline typename const volatile stack_t<unit_p, capacity_p>::unit_t&
        stack_t<unit_p, capacity_p>::operator [](index_t index)
        const volatile
    {
        return At(*this, index);
    }

}}

namespace nkr {

    template <tr1<any_tg, array::stack_tg> array_p, count_t min_unit_count_p, count_t max_unit_count_p>
    inline auto
        Random()
    {
        using namespace array;

        using unit_t = array_p::unit_t;

        nkr_ASSERT_THAT(min_unit_count_p >= 1);
        nkr_ASSERT_THAT(max_unit_count_p >= 1);
        nkr_ASSERT_THAT(min_unit_count_p <= max_unit_count_p);

        stack_t<unit_t, max_unit_count_p> array;

        for (index_t idx = 0, end = Random<count_t>(min_unit_count_p, max_unit_count_p); idx < end; idx += 1) {
            array.Push(Random<unit_t>()).Ignore_Error();
        }

        return array;
    }

}
