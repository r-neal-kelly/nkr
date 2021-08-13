/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsic.h"
#include "nkr/traits.h"

namespace nkr {

    /*
        pointer_t in no way restricts the user from altering any unit_t that units points to.
        If you want units to point to const unit_t, you can simply pass a const unit_t in the
        template. void_t is not useable by this type. I recommend using byte_t instead.
    */

    template <sized_tr unit_p = byte_t>
    class pointer_t
    {
    public:
        using unit_t    = unit_p;
        using units_t   = unit_t*;

    public:
        static constexpr const size_t   UNIT_SIZE       = sizeof(unit_t);
        static constexpr const count_t  MAX_UNIT_COUNT  = std::numeric_limits<count_t>::max();

    public:
        units_t units;
        count_t unit_count;

    public:
        pointer_t();
        pointer_t(unit_t* unit_pointer);
        pointer_t(units_t units, count_t unit_count);
        pointer_t(const pointer_t& other);
        pointer_t(pointer_t&& other) noexcept;
        pointer_t& operator =(const pointer_t& other);
        pointer_t& operator =(pointer_t&& other) noexcept;
        ~pointer_t();

    public:
        units_t&        Units();
        const units_t&  Units() const;

        count_t&        Unit_Count();
        const count_t&  Unit_Count() const;

        address_t       Address() const;

    public:
        explicit operator   bool_t();
        explicit operator   const bool_t() const;

        operator            units_t&();
        operator            const units_t&() const;

    public:
        const bool_t    operator !() const;

        units_t&        operator ()();
        const units_t&  operator ()() const;

        const units_t&  operator ->() const;
        unit_t&         operator *() const;
        unit_t&         operator [](index_t index) const;

        pointer_t&      operator ++();
        pointer_t       operator ++(int);
        pointer_t&      operator --();
        pointer_t       operator --(int);

        template <integral_tr integer>
        pointer_t&      operator +=(integer count);
        template <integral_tr integer>
        pointer_t&      operator -=(integer count);

        template <integral_tr integer>
        pointer_t       operator +(integer count) const;
        template <integral_tr integer>
        pointer_t       operator -(integer count) const;
    };

}

#include "nkr/pointer_t.inl"
