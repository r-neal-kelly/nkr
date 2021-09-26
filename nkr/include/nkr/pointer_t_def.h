/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/pointer_t_dec.h"

namespace nkr { namespace $pointer_t {

    template <any_type_tr unit_p>
    inline bool_t any_type_sp<unit_p>::Is_Equal_To(is_any_tr<any_type_sp> auto a, is_any_tr<any_type_sp> auto b)
    {
        return a.units == b.units && a.unit_count == b.unit_count;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>::any_type_sp() :
        units(nullptr),
        unit_count(0)
    {
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>::any_type_sp(convertible_tr<unit_t*> auto unit) :
        units(static_cast<unit_t*>(unit)),
        unit_count(unit ? 1 : 0)
    {
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>::any_type_sp(convertible_tr<units_t> auto units, count_t unit_count) :
        units(static_cast<unit_t*>(units)),
        unit_count(unit_count)
    {
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>::any_type_sp(const any_type_sp& other) :
        units(other.units),
        unit_count(other.unit_count)
    {
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>::any_type_sp(const volatile any_type_sp& other) :
        units(other.units),
        unit_count(other.unit_count)
    {
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>::any_type_sp(any_type_sp&& other) noexcept :
        units(std::exchange(other.units, nullptr)),
        unit_count(std::exchange(other.unit_count, 0))
    {
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>::any_type_sp(volatile any_type_sp&& other) noexcept :
        units(std::exchange(other.units, nullptr)),
        unit_count(std::exchange(other.unit_count, 0))
    {
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>& any_type_sp<unit_p>::operator =(const any_type_sp& other)
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <any_type_tr unit_p>
    inline volatile any_type_sp<unit_p>& any_type_sp<unit_p>::operator =(const any_type_sp& other) volatile
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>& any_type_sp<unit_p>::operator =(const volatile any_type_sp& other)
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <any_type_tr unit_p>
    inline volatile any_type_sp<unit_p>& any_type_sp<unit_p>::operator =(const volatile any_type_sp& other) volatile
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>& any_type_sp<unit_p>::operator =(any_type_sp&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->units = std::exchange(other.units, nullptr);
            this->unit_count = std::exchange(other.unit_count, 0);
        }
        return *this;
    }

    template <any_type_tr unit_p>
    inline volatile any_type_sp<unit_p>& any_type_sp<unit_p>::operator =(any_type_sp&& other) volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->units = std::exchange(other.units, nullptr);
            this->unit_count = std::exchange(other.unit_count, 0);
        }
        return *this;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>& any_type_sp<unit_p>::operator =(is_just_volatile_tr<any_type_sp> auto&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->units = std::exchange(other.units, nullptr);
            this->unit_count = std::exchange(other.unit_count, 0);
        }
        return *this;
    }

    template <any_type_tr unit_p>
    inline volatile any_type_sp<unit_p>& any_type_sp<unit_p>::operator =(is_just_volatile_tr<any_type_sp> auto&& other) volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->units = std::exchange(other.units, nullptr);
            this->unit_count = std::exchange(other.unit_count, 0);
        }
        return *this;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>::~any_type_sp()
    {
        this->units = nullptr;
        this->unit_count = 0;
    }

    template <any_type_tr unit_p>
    inline typename any_type_sp<unit_p>::unit_t*&
        any_type_sp<unit_p>::Unit()
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline typename any_type_sp<unit_p>::unit_t* const&
        any_type_sp<unit_p>::Unit()
        const
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline typename any_type_sp<unit_p>::unit_t* volatile&
        any_type_sp<unit_p>::Unit()
        volatile
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline typename any_type_sp<unit_p>::unit_t* const volatile&
        any_type_sp<unit_p>::Unit()
        const volatile
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline typename any_type_sp<unit_p>::units_t&
        any_type_sp<unit_p>::Units()
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline typename const any_type_sp<unit_p>::units_t&
        any_type_sp<unit_p>::Units()
        const
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline typename volatile any_type_sp<unit_p>::units_t&
        any_type_sp<unit_p>::Units()
        volatile
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline typename const volatile any_type_sp<unit_p>::units_t&
        any_type_sp<unit_p>::Units()
        const volatile
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline count_t&
        any_type_sp<unit_p>::Unit_Count()
    {
        return this->unit_count;
    }

    template <any_type_tr unit_p>
    inline const count_t&
        any_type_sp<unit_p>::Unit_Count()
        const
    {
        return this->unit_count;
    }

    template <any_type_tr unit_p>
    inline volatile count_t&
        any_type_sp<unit_p>::Unit_Count()
        volatile
    {
        return this->unit_count;
    }

    template <any_type_tr unit_p>
    inline const volatile count_t&
        any_type_sp<unit_p>::Unit_Count()
        const volatile
    {
        return this->unit_count;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>::operator units_t&()
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>::operator const units_t&() const
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>::operator volatile units_t&() volatile
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>::operator const volatile units_t&() const volatile
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline typename any_type_sp<unit_p>::units_t& any_type_sp<unit_p>::operator ()()
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline typename const any_type_sp<unit_p>::units_t& any_type_sp<unit_p>::operator ()() const
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline typename volatile any_type_sp<unit_p>::units_t& any_type_sp<unit_p>::operator ()() volatile
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline typename const volatile any_type_sp<unit_p>::units_t& any_type_sp<unit_p>::operator ()() const volatile
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>& any_type_sp<unit_p>::operator ()(convertible_tr<unit_t*> auto unit)
    {
        return *this = { unit };
    }

    template <any_type_tr unit_p>
    inline volatile any_type_sp<unit_p>& any_type_sp<unit_p>::operator ()(convertible_tr<unit_t*> auto unit) volatile
    {
        return *this = { unit };
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>& any_type_sp<unit_p>::operator ()(convertible_tr<units_t> auto units, count_t unit_count)
    {
        return *this = { units, unit_count };
    }

    template <any_type_tr unit_p>
    inline volatile any_type_sp<unit_p>& any_type_sp<unit_p>::operator ()(convertible_tr<units_t> auto units, count_t unit_count) volatile
    {
        return *this = { units, unit_count };
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p> any_type_sp<unit_p>::operator +(integer_tr auto amount) const volatile
    {
        assert(this->units != nullptr);

        return any_type_sp<unit_p>(this->units + amount, this->unit_count - amount);
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p> any_type_sp<unit_p>::operator -(integer_tr auto amount) const volatile
    {
        assert(this->units != nullptr);

        return any_type_sp<unit_p>(this->units - amount, this->unit_count + amount);
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>& any_type_sp<unit_p>::operator +=(integer_tr auto amount)
    {
        assert(this->units != nullptr);

        this->units += amount;
        this->unit_count -= amount;

        return *this;
    }

    template <any_type_tr unit_p>
    inline volatile any_type_sp<unit_p>& any_type_sp<unit_p>::operator +=(integer_tr auto amount) volatile
    {
        assert(this->units != nullptr);

        this->units += amount;
        this->unit_count -= amount;

        return *this;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>& any_type_sp<unit_p>::operator -=(integer_tr auto amount)
    {
        assert(this->units != nullptr);

        this->units -= amount;
        this->unit_count += amount;

        return *this;
    }

    template <any_type_tr unit_p>
    inline volatile any_type_sp<unit_p>& any_type_sp<unit_p>::operator -=(integer_tr auto amount) volatile
    {
        assert(this->units != nullptr);

        this->units -= amount;
        this->unit_count += amount;

        return *this;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>& any_type_sp<unit_p>::operator ++()
    {
        assert(this->units != nullptr);

        return operator +=(1);
    }

    template <any_type_tr unit_p>
    inline volatile any_type_sp<unit_p>& any_type_sp<unit_p>::operator ++() volatile
    {
        assert(this->units != nullptr);

        return operator +=(1);
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p> any_type_sp<unit_p>::operator ++(int) volatile
    {
        assert(this->units != nullptr);

        any_type_sp initial = *this;
        operator +=(1);

        return initial;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>& any_type_sp<unit_p>::operator --()
    {
        assert(this->units != nullptr);

        return operator -=(1);
    }

    template <any_type_tr unit_p>
    inline volatile any_type_sp<unit_p>& any_type_sp<unit_p>::operator --() volatile
    {
        assert(this->units != nullptr);

        return operator -=(1);
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p> any_type_sp<unit_p>::operator --(int) volatile
    {
        assert(this->units != nullptr);

        any_type_sp initial = *this;
        operator -=(1);

        return initial;
    }

    template <any_type_tr unit_p>
    inline typename any_type_sp<unit_p>::unit_t* any_type_sp<unit_p>::operator ->() const volatile
    {
        assert(this->units != nullptr);
        assert(this->unit_count > 0);

        return this->units;
    }

    template <any_type_tr unit_p>
    inline typename any_type_sp<unit_p>::unit_t& any_type_sp<unit_p>::operator *() const volatile
    {
        assert(this->units != nullptr);
        assert(this->unit_count > 0);

        return *this->units;
    }

    template <any_type_tr unit_p>
    inline typename any_type_sp<unit_p>::unit_t& any_type_sp<unit_p>::operator [](index_t index) const volatile
    {
        assert(this->units != nullptr);
        assert(index < this->unit_count);

        return this->units[index];
    }

    template <any_non_type_tr unit_p>
    inline bool_t any_non_type_sp<unit_p>::Is_Equal_To(is_any_tr<any_non_type_sp> auto a, is_any_tr<any_non_type_sp> auto b)
    {
        return a.units == b.units && a.unit_count == b.unit_count;
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>::any_non_type_sp() :
        units(nullptr),
        unit_count(0)
    {
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>::any_non_type_sp(convertible_tr<unit_t*> auto unit) :
        units(static_cast<unit_t*>(unit)),
        unit_count(unit ? 1 : 0)
    {
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>::any_non_type_sp(convertible_tr<units_t> auto units, count_t unit_count) :
        units(static_cast<unit_t*>(units)),
        unit_count(unit_count)
    {
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>::any_non_type_sp(const any_non_type_sp& other) :
        units(other.units),
        unit_count(other.unit_count)
    {
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>::any_non_type_sp(const volatile any_non_type_sp& other) :
        units(other.units),
        unit_count(other.unit_count)
    {
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>::any_non_type_sp(any_non_type_sp&& other) noexcept :
        units(std::exchange(other.units, nullptr)),
        unit_count(std::exchange(other.unit_count, 0))
    {
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>::any_non_type_sp(volatile any_non_type_sp&& other) noexcept :
        units(std::exchange(other.units, nullptr)),
        unit_count(std::exchange(other.unit_count, 0))
    {
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>& any_non_type_sp<unit_p>::operator =(const any_non_type_sp& other)
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <any_non_type_tr unit_p>
    inline volatile any_non_type_sp<unit_p>& any_non_type_sp<unit_p>::operator =(const any_non_type_sp& other) volatile
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>& any_non_type_sp<unit_p>::operator =(const volatile any_non_type_sp& other)
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <any_non_type_tr unit_p>
    inline volatile any_non_type_sp<unit_p>& any_non_type_sp<unit_p>::operator =(const volatile any_non_type_sp& other) volatile
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>& any_non_type_sp<unit_p>::operator =(any_non_type_sp&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->units = std::exchange(other.units, nullptr);
            this->unit_count = std::exchange(other.unit_count, 0);
        }
        return *this;
    }

    template <any_non_type_tr unit_p>
    inline volatile any_non_type_sp<unit_p>& any_non_type_sp<unit_p>::operator =(any_non_type_sp&& other) volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->units = std::exchange(other.units, nullptr);
            this->unit_count = std::exchange(other.unit_count, 0);
        }
        return *this;
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>& any_non_type_sp<unit_p>::operator =(is_just_volatile_tr<any_non_type_sp> auto&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->units = std::exchange(other.units, nullptr);
            this->unit_count = std::exchange(other.unit_count, 0);
        }
        return *this;
    }

    template <any_non_type_tr unit_p>
    inline volatile any_non_type_sp<unit_p>& any_non_type_sp<unit_p>::operator =(is_just_volatile_tr<any_non_type_sp> auto&& other) volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->units = std::exchange(other.units, nullptr);
            this->unit_count = std::exchange(other.unit_count, 0);
        }
        return *this;
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>::~any_non_type_sp()
    {
        this->units = nullptr;
        this->unit_count = 0;
    }

    template <any_non_type_tr unit_p>
    inline typename any_non_type_sp<unit_p>::unit_t*&
        any_non_type_sp<unit_p>::Unit()
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline typename any_non_type_sp<unit_p>::unit_t* const&
        any_non_type_sp<unit_p>::Unit()
        const
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline typename any_non_type_sp<unit_p>::unit_t* volatile&
        any_non_type_sp<unit_p>::Unit()
        volatile
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline typename any_non_type_sp<unit_p>::unit_t* const volatile&
        any_non_type_sp<unit_p>::Unit()
        const volatile
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline typename any_non_type_sp<unit_p>::units_t&
        any_non_type_sp<unit_p>::Units()
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline typename const any_non_type_sp<unit_p>::units_t&
        any_non_type_sp<unit_p>::Units()
        const
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline typename volatile any_non_type_sp<unit_p>::units_t&
        any_non_type_sp<unit_p>::Units()
        volatile
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline typename const volatile any_non_type_sp<unit_p>::units_t&
        any_non_type_sp<unit_p>::Units()
        const volatile
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline count_t&
        any_non_type_sp<unit_p>::Unit_Count()
    {
        return this->unit_count;
    }

    template <any_non_type_tr unit_p>
    inline const count_t&
        any_non_type_sp<unit_p>::Unit_Count()
        const
    {
        return this->unit_count;
    }

    template <any_non_type_tr unit_p>
    inline volatile count_t&
        any_non_type_sp<unit_p>::Unit_Count()
        volatile
    {
        return this->unit_count;
    }

    template <any_non_type_tr unit_p>
    inline const volatile count_t&
        any_non_type_sp<unit_p>::Unit_Count()
        const volatile
    {
        return this->unit_count;
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>::operator units_t&()
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>::operator const units_t&() const
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>::operator volatile units_t&() volatile
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>::operator const volatile units_t&() const volatile
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline typename any_non_type_sp<unit_p>::units_t& any_non_type_sp<unit_p>::operator ()()
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline typename const any_non_type_sp<unit_p>::units_t& any_non_type_sp<unit_p>::operator ()() const
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline typename volatile any_non_type_sp<unit_p>::units_t& any_non_type_sp<unit_p>::operator ()() volatile
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline typename const volatile any_non_type_sp<unit_p>::units_t& any_non_type_sp<unit_p>::operator ()() const volatile
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>& any_non_type_sp<unit_p>::operator ()(convertible_tr<unit_t*> auto unit)
    {
        return *this = { unit };
    }

    template <any_non_type_tr unit_p>
    inline volatile any_non_type_sp<unit_p>& any_non_type_sp<unit_p>::operator ()(convertible_tr<unit_t*> auto unit) volatile
    {
        return *this = { unit };
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>& any_non_type_sp<unit_p>::operator ()(convertible_tr<units_t> auto units, count_t unit_count)
    {
        return *this = { units, unit_count };
    }

    template <any_non_type_tr unit_p>
    inline volatile any_non_type_sp<unit_p>& any_non_type_sp<unit_p>::operator ()(convertible_tr<units_t> auto units, count_t unit_count) volatile
    {
        return *this = { units, unit_count };
    }

}}

#if defined(nkr_DO_EXTERN_TEMPLATES)

namespace nkr {

    extern template class pointer_t<void_t>;
    extern template class pointer_t<std_bool_t>;
    extern template class pointer_t<bool_t>;
    extern template class pointer_t<u8_t>;
    extern template class pointer_t<s8_t>;
    extern template class pointer_t<u16_t>;
    extern template class pointer_t<s16_t>;
    extern template class pointer_t<u32_t>;
    extern template class pointer_t<s32_t>;
    extern template class pointer_t<u64_t>;
    extern template class pointer_t<s64_t>;
    extern template class pointer_t<r32_t>;
    extern template class pointer_t<r64_t>;

    extern template class pointer_t<const void_t>;
    extern template class pointer_t<const std_bool_t>;
    extern template class pointer_t<const bool_t>;
    extern template class pointer_t<const u8_t>;
    extern template class pointer_t<const s8_t>;
    extern template class pointer_t<const u16_t>;
    extern template class pointer_t<const s16_t>;
    extern template class pointer_t<const u32_t>;
    extern template class pointer_t<const s32_t>;
    extern template class pointer_t<const u64_t>;
    extern template class pointer_t<const s64_t>;
    extern template class pointer_t<const r32_t>;
    extern template class pointer_t<const r64_t>;

    extern template class pointer_t<volatile void_t>;
    extern template class pointer_t<volatile std_bool_t>;
    extern template class pointer_t<volatile bool_t>;
    extern template class pointer_t<volatile u8_t>;
    extern template class pointer_t<volatile s8_t>;
    extern template class pointer_t<volatile u16_t>;
    extern template class pointer_t<volatile s16_t>;
    extern template class pointer_t<volatile u32_t>;
    extern template class pointer_t<volatile s32_t>;
    extern template class pointer_t<volatile u64_t>;
    extern template class pointer_t<volatile s64_t>;
    extern template class pointer_t<volatile r32_t>;
    extern template class pointer_t<volatile r64_t>;

    extern template class pointer_t<const volatile void_t>;
    extern template class pointer_t<const volatile std_bool_t>;
    extern template class pointer_t<const volatile bool_t>;
    extern template class pointer_t<const volatile u8_t>;
    extern template class pointer_t<const volatile s8_t>;
    extern template class pointer_t<const volatile u16_t>;
    extern template class pointer_t<const volatile s16_t>;
    extern template class pointer_t<const volatile u32_t>;
    extern template class pointer_t<const volatile s32_t>;
    extern template class pointer_t<const volatile u64_t>;
    extern template class pointer_t<const volatile s64_t>;
    extern template class pointer_t<const volatile r32_t>;
    extern template class pointer_t<const volatile r64_t>;

}

#endif
