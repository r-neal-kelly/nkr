/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"

#include "nkr/allocator_err.h"

#include "nkr/array/static_t.h"

#include "nkr/charcoder_i.h"
#include "nkr/charcoder/utf_8_t.h"

#include "nkr/string_i.h"
#include "nkr/string_itr_dec.h"

namespace nkr { namespace string {

    template <charcoder_i charcoder_p>
    class static_t
    {
    public:
        using charcoder_t   = charcoder_p;
        using unit_t        = charcoder_p::unit_t;
        using array_t       = array::static_t<unit_t>;

    public:
        static constexpr c_bool_t   Has_Guaranteed_Terminus();

    public:
        static const unit_t*    Empty_C_String();

    protected:
        count_t point_count;
        array_t array;

    public:
        static_t();

        // not yet sure what to pass here yet.

        static_t(const static_t& other);
        static_t(const volatile static_t& other);
        static_t(static_t&& other) noexcept;
        static_t(volatile static_t&& other) noexcept;

        static_t&           operator =(const static_t& other);
        volatile static_t&  operator =(const static_t& other) volatile;
        static_t&           operator =(const volatile static_t& other);
        volatile static_t&  operator =(const volatile static_t& other) volatile;
        static_t&           operator =(static_t&& other) noexcept;
        volatile static_t&  operator =(static_t&& other) volatile noexcept;
        static_t&           operator =(is_just_volatile_tr<static_t> auto&& other) noexcept;
        volatile static_t&  operator =(is_just_volatile_tr<static_t> auto&& other) volatile noexcept;

        ~static_t();

    public:
        bool_t                          Has_Terminus() const;
        bool_t                          Has_Terminus() const volatile;

        count_t                         Unit_Count() const;
        count_t                         Unit_Count() const volatile;
        count_t                         Unit_Length() const;
        count_t                         Unit_Length() const volatile;

        count_t                         Point_Count() const;
        count_t                         Point_Count() const volatile;
        count_t                         Point_Length() const;
        count_t                         Point_Length() const volatile;

        some_t<const unit_t*>           C_String() const;
        some_t<const volatile unit_t*>  C_String() const volatile;

        unit_t&                         Unit(index_t unit_index);
        const unit_t&                   Unit(index_t unit_index) const;
        volatile unit_t&                Unit(index_t unit_index) volatile;
        const volatile unit_t&          Unit(index_t unit_index) const volatile;
    };
    static_assert(string_i<static_t<charcoder::utf_8_t>>);
    static_assert(string_i<const static_t<charcoder::utf_8_t>>);
    static_assert(string_i<volatile static_t<charcoder::utf_8_t>>);
    static_assert(string_i<const volatile static_t<charcoder::utf_8_t>>);

}}
