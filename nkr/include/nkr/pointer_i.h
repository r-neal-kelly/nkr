/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsic.h"
#include "nkr/traits.h"

namespace nkr {

    /*
        pointer_i in no way restricts the user from altering the unit_t that units points to.
        If you want units to point to const unit_t, you can simply pass a const sized_t.
        void_t is not useable by this type. I recommend using byte_t instead.
    */

    template <sized_t unit>
    class pointer_i
    {
    public:
        using unit_t    = unit;
        using units_t   = unit_t*;

    public:
        static constexpr const size_t   UNIT_SIZE       = sizeof(unit_t);
        static constexpr const count_t  MAX_UNIT_COUNT  = std::numeric_limits<count_t>::max();

    public:
        units_t units;
        count_t unit_count;

    public:
        pointer_i();
        pointer_i(unit_t* unit_pointer);
        pointer_i(units_t units, count_t unit_count);
        pointer_i(const pointer_i& other);
        pointer_i(pointer_i&& other) noexcept;
        pointer_i& operator =(const pointer_i& other);
        pointer_i& operator =(pointer_i&& other) noexcept;
        ~pointer_i();

    public:
        explicit operator   bool_t();
        explicit operator   const bool_t() const;

        operator            units_t&();
        operator            const units_t&() const;

        operator            count_t&();
        operator            const count_t&() const;

    public:
        const bool_t    operator !() const;

        units_t&        operator ()();
        const units_t&  operator ()() const;

        const units_t&  operator ->() const;
        unit_t&         operator *() const;
        unit_t&         operator [](index_t index) const;

        pointer_i&      operator ++();
        pointer_i       operator ++(int);

        pointer_i&      operator --();
        pointer_i       operator --(int);

    public:
        address_t   address() const;
    };

}

#include "nkr/pointer_i.inl"
