/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_macros_def.h"
#include "nkr/z_pointer_t_dec.h"
#include "nkr/z_utils.h"

namespace nkr {

    template <typename other_p>
    inline constexpr c_bool_t
        type_traits_i<pointer_tg>::Is_Any()
    {
        return pointer_t$::any_tr<other_p>;
    }

    inline constexpr c_bool_t
        template_traits_i<pointer_ttg>::Is_Implemented()
    {
        return true;
    }

}

namespace nkr { namespace pointer_t$ {

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
        units(nkr::Move(other.units)),
        unit_count(nkr::Move(other.unit_count))
    {
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>::any_type_sp(volatile any_type_sp&& other) noexcept :
        units(nkr::Move(other.units)),
        unit_count(nkr::Move(other.unit_count))
    {
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator =(const any_type_sp& other)
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <any_type_tr unit_p>
    inline volatile any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator =(const any_type_sp& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator =(const volatile any_type_sp& other)
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <any_type_tr unit_p>
    inline volatile any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator =(const volatile any_type_sp& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator =(any_type_sp&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->units = nkr::Move(other.units);
            this->unit_count = nkr::Move(other.unit_count);
        }
        return *this;
    }

    template <any_type_tr unit_p>
    inline volatile any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator =(any_type_sp&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->units = nkr::Move(other.units);
            this->unit_count = nkr::Move(other.unit_count);
        }
        return *this;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator =(is_just_volatile_tr<any_type_sp> auto&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->units = nkr::Move(other.units);
            this->unit_count = nkr::Move(other.unit_count);
        }
        return *this;
    }

    template <any_type_tr unit_p>
    inline volatile any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator =(is_just_volatile_tr<any_type_sp> auto&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->units = nkr::Move(other.units);
            this->unit_count = nkr::Move(other.unit_count);
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
    inline any_type_sp<unit_p>::operator const units_t&()
        const
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>::operator volatile units_t&()
        volatile
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>::operator const volatile units_t&()
        const volatile
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline typename any_type_sp<unit_p>::units_t&
        any_type_sp<unit_p>::operator ()()
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline typename const any_type_sp<unit_p>::units_t&
        any_type_sp<unit_p>::operator ()()
        const
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline typename volatile any_type_sp<unit_p>::units_t&
        any_type_sp<unit_p>::operator ()()
        volatile
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline typename const volatile any_type_sp<unit_p>::units_t&
        any_type_sp<unit_p>::operator ()()
        const volatile
    {
        return this->units;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator ()(convertible_tr<unit_t*> auto unit)
    {
        return *this = { unit };
    }

    template <any_type_tr unit_p>
    inline volatile any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator ()(convertible_tr<unit_t*> auto unit)
        volatile
    {
        return *this = { unit };
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator ()(convertible_tr<units_t> auto units, count_t unit_count)
    {
        return *this = { units, unit_count };
    }

    template <any_type_tr unit_p>
    inline volatile any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator ()(convertible_tr<units_t> auto units, count_t unit_count)
        volatile
    {
        return *this = { units, unit_count };
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>
        any_type_sp<unit_p>::operator +(integer_tr auto amount)
        const
    {
        nkr_ASSERT_THAT(this->units != nullptr);

        return any_type_sp<unit_p>(this->units + amount, this->unit_count - amount);
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>
        any_type_sp<unit_p>::operator +(integer_tr auto amount)
        const volatile
    {
        nkr_ASSERT_THAT(this->units != nullptr);

        return any_type_sp<unit_p>(this->units + amount, this->unit_count - amount);
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>
        any_type_sp<unit_p>::operator -(integer_tr auto amount)
        const
    {
        nkr_ASSERT_THAT(this->units != nullptr);

        return any_type_sp<unit_p>(this->units - amount, this->unit_count + amount);
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>
        any_type_sp<unit_p>::operator -(integer_tr auto amount)
        const volatile
    {
        nkr_ASSERT_THAT(this->units != nullptr);

        return any_type_sp<unit_p>(this->units - amount, this->unit_count + amount);
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator +=(integer_tr auto amount)
    {
        nkr_ASSERT_THAT(this->units != nullptr);

        this->units += amount;
        this->unit_count -= amount;

        return *this;
    }

    template <any_type_tr unit_p>
    inline volatile any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator +=(integer_tr auto amount)
        volatile
    {
        nkr_ASSERT_THAT(this->units != nullptr);

        this->units += amount;
        this->unit_count -= amount;

        return *this;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator -=(integer_tr auto amount)
    {
        nkr_ASSERT_THAT(this->units != nullptr);

        this->units -= amount;
        this->unit_count += amount;

        return *this;
    }

    template <any_type_tr unit_p>
    inline volatile any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator -=(integer_tr auto amount)
        volatile
    {
        nkr_ASSERT_THAT(this->units != nullptr);

        this->units -= amount;
        this->unit_count += amount;

        return *this;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator ++()
    {
        nkr_ASSERT_THAT(this->units != nullptr);

        return operator +=(1);
    }

    template <any_type_tr unit_p>
    inline volatile any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator ++()
        volatile
    {
        nkr_ASSERT_THAT(this->units != nullptr);

        return operator +=(1);
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>
        any_type_sp<unit_p>::operator ++(int)
    {
        nkr_ASSERT_THAT(this->units != nullptr);

        any_type_sp initial = *this;
        operator +=(1);

        return initial;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>
        any_type_sp<unit_p>::operator ++(int)
        volatile
    {
        nkr_ASSERT_THAT(this->units != nullptr);

        any_type_sp initial = *this;
        operator +=(1);

        return initial;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator --()
    {
        nkr_ASSERT_THAT(this->units != nullptr);

        return operator -=(1);
    }

    template <any_type_tr unit_p>
    inline volatile any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator --()
        volatile
    {
        nkr_ASSERT_THAT(this->units != nullptr);

        return operator -=(1);
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>
        any_type_sp<unit_p>::operator --(int)
    {
        nkr_ASSERT_THAT(this->units != nullptr);

        any_type_sp initial = *this;
        operator -=(1);

        return initial;
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>
        any_type_sp<unit_p>::operator --(int)
        volatile
    {
        nkr_ASSERT_THAT(this->units != nullptr);

        any_type_sp initial = *this;
        operator -=(1);

        return initial;
    }

    template <any_type_tr unit_p>
    inline typename any_type_sp<unit_p>::unit_t*
        any_type_sp<unit_p>::operator ->()
        const
    {
        nkr_ASSERT_THAT(this->units != nullptr);
        nkr_ASSERT_THAT(this->unit_count > 0);

        return this->units;
    }

    template <any_type_tr unit_p>
    inline typename any_type_sp<unit_p>::unit_t*
        any_type_sp<unit_p>::operator ->()
        const volatile
    {
        nkr_ASSERT_THAT(this->units != nullptr);
        nkr_ASSERT_THAT(this->unit_count > 0);

        return this->units;
    }

    template <any_type_tr unit_p>
    inline typename any_type_sp<unit_p>::unit_t&
        any_type_sp<unit_p>::operator *()
        const
    {
        nkr_ASSERT_THAT(this->units != nullptr);
        nkr_ASSERT_THAT(this->unit_count > 0);

        return *this->units;
    }

    template <any_type_tr unit_p>
    inline typename any_type_sp<unit_p>::unit_t&
        any_type_sp<unit_p>::operator *()
        const volatile
    {
        nkr_ASSERT_THAT(this->units != nullptr);
        nkr_ASSERT_THAT(this->unit_count > 0);

        return *this->units;
    }

    template <any_type_tr unit_p>
    inline typename any_type_sp<unit_p>::unit_t&
        any_type_sp<unit_p>::operator [](index_t index)
        const
    {
        nkr_ASSERT_THAT(this->units != nullptr);
        nkr_ASSERT_THAT(index < this->unit_count);

        return this->units[index];
    }

    template <any_type_tr unit_p>
    inline typename any_type_sp<unit_p>::unit_t&
        any_type_sp<unit_p>::operator [](index_t index)
        const volatile
    {
        nkr_ASSERT_THAT(this->units != nullptr);
        nkr_ASSERT_THAT(index < this->unit_count);

        return this->units[index];
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>::any_type_sp(none_t) :
        units(nullptr),
        unit_count(0)
    {
    }

    template <any_type_tr unit_p>
    inline any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator =(none_t)
    {
        this->units = nullptr;
        this->unit_count = 0;
        return *this;
    }

    template <any_type_tr unit_p>
    inline volatile any_type_sp<unit_p>&
        any_type_sp<unit_p>::operator =(none_t)
        volatile
    {
        this->units = nullptr;
        this->unit_count = 0;
        return *this;
    }

    template <any_type_tr unit_p>
    inline bool_t
        any_type_sp<unit_p>::operator ==(none_t)
        const
    {
        return this->units == nullptr;
    }

    template <any_type_tr unit_p>
    inline bool_t
        any_type_sp<unit_p>::operator ==(none_t)
        const volatile
    {
        return this->units == nullptr;
    }

    template <any_type_tr unit_p>
    inline bool_t
        any_type_sp<unit_p>::operator !=(none_t)
        const
    {
        return !operator ==(none_t());
    }

    template <any_type_tr unit_p>
    inline bool_t
        any_type_sp<unit_p>::operator !=(none_t)
        const volatile
    {
        return !operator ==(none_t());
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
        units(nkr::Move(other.units)),
        unit_count(nkr::Move(other.unit_count))
    {
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>::any_non_type_sp(volatile any_non_type_sp&& other) noexcept :
        units(nkr::Move(other.units)),
        unit_count(nkr::Move(other.unit_count))
    {
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>&
        any_non_type_sp<unit_p>::operator =(const any_non_type_sp& other)
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <any_non_type_tr unit_p>
    inline volatile any_non_type_sp<unit_p>&
        any_non_type_sp<unit_p>::operator =(const any_non_type_sp& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>&
        any_non_type_sp<unit_p>::operator =(const volatile any_non_type_sp& other)
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <any_non_type_tr unit_p>
    inline volatile any_non_type_sp<unit_p>&
        any_non_type_sp<unit_p>::operator =(const volatile any_non_type_sp& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>&
        any_non_type_sp<unit_p>::operator =(any_non_type_sp&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->units = nkr::Move(other.units);
            this->unit_count = nkr::Move(other.unit_count);
        }
        return *this;
    }

    template <any_non_type_tr unit_p>
    inline volatile any_non_type_sp<unit_p>&
        any_non_type_sp<unit_p>::operator =(any_non_type_sp&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->units = nkr::Move(other.units);
            this->unit_count = nkr::Move(other.unit_count);
        }
        return *this;
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>&
        any_non_type_sp<unit_p>::operator =(is_just_volatile_tr<any_non_type_sp> auto&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->units = nkr::Move(other.units);
            this->unit_count = nkr::Move(other.unit_count);
        }
        return *this;
    }

    template <any_non_type_tr unit_p>
    inline volatile any_non_type_sp<unit_p>&
        any_non_type_sp<unit_p>::operator =(is_just_volatile_tr<any_non_type_sp> auto&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->units = nkr::Move(other.units);
            this->unit_count = nkr::Move(other.unit_count);
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
    inline any_non_type_sp<unit_p>::operator const units_t&()
        const
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>::operator volatile units_t&()
        volatile
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>::operator const volatile units_t&()
        const volatile
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline typename any_non_type_sp<unit_p>::units_t&
        any_non_type_sp<unit_p>::operator ()()
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline typename const any_non_type_sp<unit_p>::units_t&
        any_non_type_sp<unit_p>::operator ()()
        const
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline typename volatile any_non_type_sp<unit_p>::units_t&
        any_non_type_sp<unit_p>::operator ()()
        volatile
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline typename const volatile any_non_type_sp<unit_p>::units_t&
        any_non_type_sp<unit_p>::operator ()()
        const volatile
    {
        return this->units;
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>&
        any_non_type_sp<unit_p>::operator ()(convertible_tr<unit_t*> auto unit)
    {
        return *this = { unit };
    }

    template <any_non_type_tr unit_p>
    inline volatile any_non_type_sp<unit_p>&
        any_non_type_sp<unit_p>::operator ()(convertible_tr<unit_t*> auto unit)
        volatile
    {
        return *this = { unit };
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>&
        any_non_type_sp<unit_p>::operator ()(convertible_tr<units_t> auto units, count_t unit_count)
    {
        return *this = { units, unit_count };
    }

    template <any_non_type_tr unit_p>
    inline volatile any_non_type_sp<unit_p>&
        any_non_type_sp<unit_p>::operator ()(convertible_tr<units_t> auto units, count_t unit_count)
        volatile
    {
        return *this = { units, unit_count };
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>::any_non_type_sp(none_t) :
        units(nullptr),
        unit_count(0)
    {
    }

    template <any_non_type_tr unit_p>
    inline any_non_type_sp<unit_p>&
        any_non_type_sp<unit_p>::operator =(none_t)
    {
        this->units = nullptr;
        this->unit_count = 0;
        return *this;
    }

    template <any_non_type_tr unit_p>
    inline volatile any_non_type_sp<unit_p>&
        any_non_type_sp<unit_p>::operator =(none_t)
        volatile
    {
        this->units = nullptr;
        this->unit_count = 0;
        return *this;
    }

    template <any_non_type_tr unit_p>
    inline bool_t
        any_non_type_sp<unit_p>::operator ==(none_t)
        const
    {
        return this->units == nullptr;
    }

    template <any_non_type_tr unit_p>
    inline bool_t
        any_non_type_sp<unit_p>::operator ==(none_t)
        const volatile
    {
        return this->units == nullptr;
    }

    template <any_non_type_tr unit_p>
    inline bool_t
        any_non_type_sp<unit_p>::operator !=(none_t)
        const
    {
        return !operator ==(none_t());
    }

    template <any_non_type_tr unit_p>
    inline bool_t
        any_non_type_sp<unit_p>::operator !=(none_t)
        const volatile
    {
        return !operator ==(none_t());
    }

}}

namespace nkr {

    inline bool_t
        operator ==(const tr1<any_tg, pointer_tg> auto& a, const tr0<any_tg> auto& b)
    {
        using a_t = std::remove_reference_t<decltype(a)>;
        using b_t = std::remove_reference_t<decltype(b)>;

        if constexpr (is_any_tr<b_t, none_t>) {
            return a.operator ==(b);
        } else if constexpr (is_any_tr<b_t, typename a_t::units_t>) {
            if constexpr (can_equal_to_tr<decltype(a.Units()), decltype(b)>) {
                return a.Units() == b;
            } else {
                [] <bool _ = false>() { static_assert(_, "these two values can not be equal to each other."); }();
            }
        } else if constexpr (tr1<b_t, any_tg, pointer_tg>) {
            if constexpr (can_equal_to_tr<decltype(a.Units()), decltype(b.Units())>) {
                return a.Units() == b.Units() && a.Unit_Count() == b.Unit_Count();
            } else {
                [] <bool _ = false>() { static_assert(_, "these two values can not be equal to each other."); }();
            }
        } else {
            if constexpr (can_equal_to_tr<decltype(a.Units()), decltype(b)>) {
                return a.Units() == b;
            } else {
                [] <bool _ = false>() { static_assert(_, "these two values can not be equal to each other."); }();
            }
        }
    }

    inline bool_t
        operator ==(const tr1<any_tg, pointer_tg> auto& a, const tr0<any_tg> auto&& b)
    {
        return operator ==(a, b);
    }

    inline bool_t
        operator ==(const tr1<any_tg, pointer_tg> auto&& a, const tr0<any_tg> auto& b)
    {
        return operator ==(a, b);
    }

    inline bool_t
        operator ==(const tr1<any_tg, pointer_tg> auto&& a, const tr0<any_tg> auto&& b)
    {
        return operator ==(a, b);
    }

    inline bool_t
        operator !=(const tr1<any_tg, pointer_tg> auto& a, const tr0<any_tg> auto& b)
    {
        return !operator ==(a, b);
    }

    inline bool_t
        operator !=(const tr1<any_tg, pointer_tg> auto& a, const tr0<any_tg> auto&& b)
    {
        return !operator ==(a, b);
    }

    inline bool_t
        operator !=(const tr1<any_tg, pointer_tg> auto&& a, const tr0<any_tg> auto& b)
    {
        return !operator ==(a, b);
    }

    inline bool_t
        operator !=(const tr1<any_tg, pointer_tg> auto&& a, const tr0<any_tg> auto&& b)
    {
        return !operator ==(a, b);
    }

}

#if defined(nkr_DO_EXTERN_TEMPLATES)

namespace nkr {

    extern template class pointer_t<void_t>;
    extern template class pointer_t<c_bool_t>;
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
    extern template class pointer_t<const c_bool_t>;
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
    extern template class pointer_t<volatile c_bool_t>;
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
    extern template class pointer_t<const volatile c_bool_t>;
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
