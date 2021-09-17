/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/pointer_t_dec.h"

namespace nkr { namespace $pointer_t {

    template <type_tr unit_p>
    inline bool_t type_sp<unit_p>::Is_Equal_To(same_as_any_tr<type_sp> auto a,
                                               same_as_any_tr<type_sp> auto b)
    {
        return a.units == b.units && a.unit_count == b.unit_count;
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>::type_sp() :
        units(nullptr),
        unit_count(0)
    {
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>::type_sp(convertible_tr<unit_t*> auto unit) :
        units(static_cast<unit_t*>(unit)),
        unit_count(unit ? 1 : 0)
    {
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>::type_sp(convertible_tr<units_t> auto units, count_t unit_count) :
        units(static_cast<unit_t*>(units)),
        unit_count(unit_count)
    {
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>::type_sp(const type_sp& other) :
        units(other.units),
        unit_count(other.unit_count)
    {
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>::type_sp(volatile const type_sp& other) :
        units(other.units),
        unit_count(other.unit_count)
    {
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>::type_sp(type_sp&& other) noexcept :
        units(std::exchange(other.units, nullptr)),
        unit_count(std::exchange(other.unit_count, 0))
    {
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>::type_sp(volatile type_sp&& other) noexcept :
        units(std::exchange(other.units, nullptr)),
        unit_count(std::exchange(other.unit_count, 0))
    {
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>& type_sp<unit_p>::operator =(const type_sp& other)
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <type_tr unit_p>
    inline volatile type_sp<unit_p>& type_sp<unit_p>::operator =(volatile const type_sp& other) volatile
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>& type_sp<unit_p>::operator =(type_sp&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->units = std::exchange(other.units, nullptr);
            this->unit_count = std::exchange(other.unit_count, 0);
        }
        return *this;
    }

    template <type_tr unit_p>
    inline volatile type_sp<unit_p>& type_sp<unit_p>::operator =(volatile type_sp&& other) volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->units = std::exchange(other.units, nullptr);
            this->unit_count = std::exchange(other.unit_count, 0);
        }
        return *this;
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>::~type_sp()
    {
        this->units = nullptr;
        this->unit_count = 0;
    }

    template <type_tr unit_p>
    inline typename type_sp<unit_p>::unit_t*&
        type_sp<unit_p>::Unit()
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline typename type_sp<unit_p>::unit_t* const&
        type_sp<unit_p>::Unit()
        const
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline typename type_sp<unit_p>::unit_t* volatile&
        type_sp<unit_p>::Unit()
        volatile
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline typename type_sp<unit_p>::unit_t* volatile const&
        type_sp<unit_p>::Unit()
        volatile const
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline typename type_sp<unit_p>::units_t&
        type_sp<unit_p>::Units()
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline typename const type_sp<unit_p>::units_t&
        type_sp<unit_p>::Units()
        const
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline typename volatile type_sp<unit_p>::units_t&
        type_sp<unit_p>::Units()
        volatile
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline typename volatile const type_sp<unit_p>::units_t&
        type_sp<unit_p>::Units()
        volatile const
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline count_t&
        type_sp<unit_p>::Unit_Count()
    {
        return this->unit_count;
    }

    template <type_tr unit_p>
    inline const count_t&
        type_sp<unit_p>::Unit_Count()
        const
    {
        return this->unit_count;
    }

    template <type_tr unit_p>
    inline volatile count_t&
        type_sp<unit_p>::Unit_Count()
        volatile
    {
        return this->unit_count;
    }

    template <type_tr unit_p>
    inline volatile const count_t&
        type_sp<unit_p>::Unit_Count()
        volatile const
    {
        return this->unit_count;
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>::operator units_t&()
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>::operator const units_t&() const
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>::operator volatile units_t&() volatile
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>::operator volatile const units_t&() volatile const
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline typename type_sp<unit_p>::units_t& type_sp<unit_p>::operator ()()
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline typename const type_sp<unit_p>::units_t& type_sp<unit_p>::operator ()() const
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline typename volatile type_sp<unit_p>::units_t& type_sp<unit_p>::operator ()() volatile
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline typename volatile const type_sp<unit_p>::units_t& type_sp<unit_p>::operator ()() volatile const
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>& type_sp<unit_p>::operator ()(convertible_tr<unit_t*> auto unit)
    {
        return *this = { unit };
    }

    template <type_tr unit_p>
    inline volatile type_sp<unit_p>& type_sp<unit_p>::operator ()(convertible_tr<unit_t*> auto unit) volatile
    {
        return *this = { unit };
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>& type_sp<unit_p>::operator ()(convertible_tr<units_t> auto units, count_t unit_count)
    {
        return *this = { units, unit_count };
    }

    template <type_tr unit_p>
    inline volatile type_sp<unit_p>& type_sp<unit_p>::operator ()(convertible_tr<units_t> auto units, count_t unit_count) volatile
    {
        return *this = { units, unit_count };
    }

    template <type_tr unit_p>
    inline type_sp<unit_p> type_sp<unit_p>::operator +(integer_tr auto amount) volatile const
    {
        assert(this->units != nullptr);

        return type_sp<unit_p>(this->units + amount, this->unit_count - amount);
    }

    template <type_tr unit_p>
    inline type_sp<unit_p> type_sp<unit_p>::operator -(integer_tr auto amount) volatile const
    {
        assert(this->units != nullptr);

        return type_sp<unit_p>(this->units - amount, this->unit_count + amount);
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>& type_sp<unit_p>::operator +=(integer_tr auto amount)
    {
        assert(this->units != nullptr);

        this->units += amount;
        this->unit_count -= amount;

        return *this;
    }

    template <type_tr unit_p>
    inline volatile type_sp<unit_p>& type_sp<unit_p>::operator +=(integer_tr auto amount) volatile
    {
        assert(this->units != nullptr);

        this->units += amount;
        this->unit_count -= amount;

        return *this;
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>& type_sp<unit_p>::operator -=(integer_tr auto amount)
    {
        assert(this->units != nullptr);

        this->units -= amount;
        this->unit_count += amount;

        return *this;
    }

    template <type_tr unit_p>
    inline volatile type_sp<unit_p>& type_sp<unit_p>::operator -=(integer_tr auto amount) volatile
    {
        assert(this->units != nullptr);

        this->units -= amount;
        this->unit_count += amount;

        return *this;
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>& type_sp<unit_p>::operator ++()
    {
        assert(this->units != nullptr);

        return operator +=(1);
    }

    template <type_tr unit_p>
    inline volatile type_sp<unit_p>& type_sp<unit_p>::operator ++() volatile
    {
        assert(this->units != nullptr);

        return operator +=(1);
    }

    template <type_tr unit_p>
    inline type_sp<unit_p> type_sp<unit_p>::operator ++(int) volatile
    {
        assert(this->units != nullptr);

        type_sp initial = *this;
        operator +=(1);

        return initial;
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>& type_sp<unit_p>::operator --()
    {
        assert(this->units != nullptr);

        return operator -=(1);
    }

    template <type_tr unit_p>
    inline volatile type_sp<unit_p>& type_sp<unit_p>::operator --() volatile
    {
        assert(this->units != nullptr);

        return operator -=(1);
    }

    template <type_tr unit_p>
    inline type_sp<unit_p> type_sp<unit_p>::operator --(int) volatile
    {
        assert(this->units != nullptr);

        type_sp initial = *this;
        operator -=(1);

        return initial;
    }

    template <type_tr unit_p>
    inline typename type_sp<unit_p>::unit_t* type_sp<unit_p>::operator ->() volatile const
    {
        assert(this->units != nullptr);
        assert(this->unit_count > 0);

        return this->units;
    }

    template <type_tr unit_p>
    inline typename type_sp<unit_p>::unit_t& type_sp<unit_p>::operator *() volatile const
    {
        assert(this->units != nullptr);
        assert(this->unit_count > 0);

        return *this->units;
    }

    template <type_tr unit_p>
    inline typename type_sp<unit_p>::unit_t& type_sp<unit_p>::operator [](index_t index) volatile const
    {
        assert(this->units != nullptr);
        assert(index < this->unit_count);

        return this->units[index];
    }

    template <non_type_tr unit_p>
    inline bool_t non_type_sp<unit_p>::Is_Equal_To(same_as_any_tr<non_type_sp> auto a,
                                                   same_as_any_tr<non_type_sp> auto b)
    {
        return a.units == b.units && a.unit_count == b.unit_count;
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>::non_type_sp() :
        units(nullptr),
        unit_count(0)
    {
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>::non_type_sp(convertible_tr<unit_t*> auto unit) :
        units(static_cast<unit_t*>(unit)),
        unit_count(unit ? 1 : 0)
    {
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>::non_type_sp(convertible_tr<units_t> auto units, count_t unit_count) :
        units(static_cast<unit_t*>(units)),
        unit_count(unit_count)
    {
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>::non_type_sp(const non_type_sp& other) :
        units(other.units),
        unit_count(other.unit_count)
    {
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>::non_type_sp(volatile const non_type_sp& other) :
        units(other.units),
        unit_count(other.unit_count)
    {
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>::non_type_sp(non_type_sp&& other) noexcept :
        units(std::exchange(other.units, nullptr)),
        unit_count(std::exchange(other.unit_count, 0))
    {
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>::non_type_sp(volatile non_type_sp&& other) noexcept :
        units(std::exchange(other.units, nullptr)),
        unit_count(std::exchange(other.unit_count, 0))
    {
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>& non_type_sp<unit_p>::operator =(const non_type_sp& other)
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <non_type_tr unit_p>
    inline volatile non_type_sp<unit_p>& non_type_sp<unit_p>::operator =(volatile const non_type_sp& other) volatile
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>& non_type_sp<unit_p>::operator =(non_type_sp&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->units = std::exchange(other.units, nullptr);
            this->unit_count = std::exchange(other.unit_count, 0);
        }
        return *this;
    }

    template <non_type_tr unit_p>
    inline volatile non_type_sp<unit_p>& non_type_sp<unit_p>::operator =(volatile non_type_sp&& other) volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->units = std::exchange(other.units, nullptr);
            this->unit_count = std::exchange(other.unit_count, 0);
        }
        return *this;
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>::~non_type_sp()
    {
        this->units = nullptr;
        this->unit_count = 0;
    }

    template <non_type_tr unit_p>
    inline typename non_type_sp<unit_p>::unit_t*&
        non_type_sp<unit_p>::Unit()
    {
        return this->units;
    }

    template <non_type_tr unit_p>
    inline typename non_type_sp<unit_p>::unit_t* const&
        non_type_sp<unit_p>::Unit()
        const
    {
        return this->units;
    }

    template <non_type_tr unit_p>
    inline typename non_type_sp<unit_p>::unit_t* volatile&
        non_type_sp<unit_p>::Unit()
        volatile
    {
        return this->units;
    }

    template <non_type_tr unit_p>
    inline typename non_type_sp<unit_p>::unit_t* volatile const&
        non_type_sp<unit_p>::Unit()
        volatile const
    {
        return this->units;
    }

    template <non_type_tr unit_p>
    inline typename non_type_sp<unit_p>::units_t&
        non_type_sp<unit_p>::Units()
    {
        return this->units;
    }

    template <non_type_tr unit_p>
    inline typename const non_type_sp<unit_p>::units_t&
        non_type_sp<unit_p>::Units()
        const
    {
        return this->units;
    }

    template <non_type_tr unit_p>
    inline typename volatile non_type_sp<unit_p>::units_t&
        non_type_sp<unit_p>::Units()
        volatile
    {
        return this->units;
    }

    template <non_type_tr unit_p>
    inline typename volatile const non_type_sp<unit_p>::units_t&
        non_type_sp<unit_p>::Units()
        volatile const
    {
        return this->units;
    }

    template <non_type_tr unit_p>
    inline count_t&
        non_type_sp<unit_p>::Unit_Count()
    {
        return this->unit_count;
    }

    template <non_type_tr unit_p>
    inline const count_t&
        non_type_sp<unit_p>::Unit_Count()
        const
    {
        return this->unit_count;
    }

    template <non_type_tr unit_p>
    inline volatile count_t&
        non_type_sp<unit_p>::Unit_Count()
        volatile
    {
        return this->unit_count;
    }

    template <non_type_tr unit_p>
    inline volatile const count_t&
        non_type_sp<unit_p>::Unit_Count()
        volatile const
    {
        return this->unit_count;
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>::operator units_t&()
    {
        return this->units;
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>::operator const units_t&() const
    {
        return this->units;
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>::operator volatile units_t&() volatile
    {
        return this->units;
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>::operator volatile const units_t&() volatile const
    {
        return this->units;
    }

    template <non_type_tr unit_p>
    inline typename non_type_sp<unit_p>::units_t& non_type_sp<unit_p>::operator ()()
    {
        return this->units;
    }

    template <non_type_tr unit_p>
    inline typename const non_type_sp<unit_p>::units_t& non_type_sp<unit_p>::operator ()() const
    {
        return this->units;
    }

    template <non_type_tr unit_p>
    inline typename volatile non_type_sp<unit_p>::units_t& non_type_sp<unit_p>::operator ()() volatile
    {
        return this->units;
    }

    template <non_type_tr unit_p>
    inline typename volatile const non_type_sp<unit_p>::units_t& non_type_sp<unit_p>::operator ()() volatile const
    {
        return this->units;
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>& non_type_sp<unit_p>::operator ()(convertible_tr<unit_t*> auto unit)
    {
        return *this = { unit };
    }

    template <non_type_tr unit_p>
    inline volatile non_type_sp<unit_p>& non_type_sp<unit_p>::operator ()(convertible_tr<unit_t*> auto unit) volatile
    {
        return *this = { unit };
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>& non_type_sp<unit_p>::operator ()(convertible_tr<units_t> auto units, count_t unit_count)
    {
        return *this = { units, unit_count };
    }

    template <non_type_tr unit_p>
    inline volatile non_type_sp<unit_p>& non_type_sp<unit_p>::operator ()(convertible_tr<units_t> auto units, count_t unit_count) volatile
    {
        return *this = { units, unit_count };
    }

}}

namespace nkr {



}

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

    extern template class pointer_t<volatile const void_t>;
    extern template class pointer_t<volatile const std_bool_t>;
    extern template class pointer_t<volatile const bool_t>;
    extern template class pointer_t<volatile const u8_t>;
    extern template class pointer_t<volatile const s8_t>;
    extern template class pointer_t<volatile const u16_t>;
    extern template class pointer_t<volatile const s16_t>;
    extern template class pointer_t<volatile const u32_t>;
    extern template class pointer_t<volatile const s32_t>;
    extern template class pointer_t<volatile const u64_t>;
    extern template class pointer_t<volatile const s64_t>;
    extern template class pointer_t<volatile const r32_t>;
    extern template class pointer_t<volatile const r64_t>;

}

#endif
