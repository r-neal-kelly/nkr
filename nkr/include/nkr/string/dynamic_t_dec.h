/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/macros.h"
#include "nkr/math.h"
#include "nkr/maybe_t.h"
#include "nkr/traits.h"

#include "nkr/allocator_err.h"
#include "nkr/allocator_i.h"
#include "nkr/allocator/heap_t.h"

#include "nkr/array/dynamic_t.h"

#include "nkr/charcoder_i.h"
#include "nkr/charcoder/utf_8_t.h"

#include "nkr/string_i.h"

namespace nkr { namespace string {

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    class dynamic_t;

    template <typename string_p>
    concept any_dynamic_tr =
        is_any_tr<string_p, dynamic_t<typename string_p::charcoder_t, typename string_p::allocator_t, typename string_p::grow_rate_t>>;

    nkr_DEFINE_CONTAINER_TRAITS(dynamic, charcoder_t);

}}

namespace nkr { namespace string {

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    class dynamic_t;

    // we might be able to abstract this to work with any string type that satisfies string_i.
    template <any_dynamic_tr string_p>
    class dynamic_itr
    {
    public:
        using string_t  = string_p;
        using unit_t    = string_t::unit_t;

    public:
        string_t&   string;
        unit_t*     unit;
        index_t     point_index;

    public:
        bool_t  Is_At_Prefix() const;
        bool_t  Is_At_First() const;
        bool_t  Is_At_Last() const;
        bool_t  Is_At_Null() const;
        bool_t  Is_At_Postfix() const;

        bool_t  Next(); // Forward
        bool_t  Previous(); // Backward, Reverse

        point_t Point() const;
        index_t Unit_Index() const;
        index_t Point_Index() const;
        unit_t* C_String() const;
    };

}}

namespace nkr { namespace string {

    // don't forget that we allocate an extra unit at the front of the array as a prefix.
    // don't forget that when given a string to work with that has the same charcoder, you can just plain copy instead of decode
    template <
        charcoder_i         charcoder_p = charcoder::utf_8_t,
        allocator_i         allocator_p = allocator::heap_t<typename charcoder_p::unit_t>,
        math::fraction_i    grow_rate_p = math::fraction_t<17, 10>
    > class dynamic_t
    {
    public:
        using charcoder_t   = charcoder_p;
        using array_t       = array::dynamic_t<typename charcoder_t::unit_t, allocator_p, grow_rate_p>;
        using unit_t        = array_t::unit_t;
        using allocator_t   = array_t::allocator_t;
        using grow_rate_t   = array_t::grow_rate_t;
        using iterator_t    = dynamic_itr<dynamic_t>;

    protected:
        count_t point_count;
        array_t array;

    public:
        dynamic_t(const allocator_t& allocator = allocator_t());
        dynamic_t(allocator_t&& allocator);

        dynamic_t(const is_any_tr<unit_t> auto* string, const allocator_t& allocator = allocator_t());
        dynamic_t(const is_any_tr<unit_t> auto* string, allocator_t&& allocator);

        dynamic_t(const any_string_tr auto& string, const allocator_t& allocator = allocator_t());
        dynamic_t(const any_string_tr auto& string, allocator_t&& allocator);
        dynamic_t(any_non_const_string_tr auto&& string, const allocator_t& allocator = allocator_t());
        dynamic_t(any_non_const_string_tr auto&& string, allocator_t&& allocator);
        dynamic_t(any_const_string_tr auto&& string, const allocator_t& allocator = allocator_t()) = delete;
        dynamic_t(any_const_string_tr auto&& string, allocator_t&& allocator) = delete;

        dynamic_t(const dynamic_t& other);
        dynamic_t(const volatile dynamic_t& other);
        dynamic_t(dynamic_t&& other) noexcept;
        dynamic_t(volatile dynamic_t&& other) noexcept;

        dynamic_t&          operator =(const dynamic_t& other);
        volatile dynamic_t& operator =(const dynamic_t& other) volatile;
        dynamic_t&          operator =(const volatile dynamic_t& other);
        volatile dynamic_t& operator =(const volatile dynamic_t& other) volatile;
        dynamic_t&          operator =(dynamic_t&& other) noexcept;
        volatile dynamic_t& operator =(dynamic_t&& other) volatile noexcept;
        dynamic_t&          operator =(is_just_volatile_tr<dynamic_t> auto&& other) noexcept;
        volatile dynamic_t& operator =(is_just_volatile_tr<dynamic_t> auto&& other) volatile noexcept;

        ~dynamic_t();

    public:
        count_t                 Unit_Count();
        count_t                 Point_Count();

        unit_t*                 C_String(); // this should point at first, and not prefix.

        iterator_t              At_Prefix();
        iterator_t              At_First();
        iterator_t              At_Last();
        iterator_t              At_Null();
        iterator_t              At_Postfix();

        maybe_t<allocator_err>  Push(point_t point);
        maybe_t<allocator_err>  Push(charcoder_t& charcoder);
        maybe_t<allocator_err>  Push(unit_t* c_string);
        maybe_t<allocator_err>  Push(const unit_t* c_string);
    };
    static_assert(string_i<dynamic_t<>>);
    static_assert(string_i<const dynamic_t<>>);
    static_assert(string_i<volatile dynamic_t<>>);
    static_assert(string_i<const volatile dynamic_t<>>);

}}
