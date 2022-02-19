/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_intrinsics.h"
#include "nkr/z_traits.h"

#include "nkr/z_array_i.h"
#include "nkr/z_array/static_t.h"

namespace nkr { namespace array {

    template <typename unit_p, count_t capacity_p>
    class stack_t;

}}

namespace nkr { namespace array {

    template <any_type_tr unit_p>
    class high_pad_t;

    struct                      high_pad_tg     {};
    template <typename> struct  high_pad_ttg    {};

}}

namespace nkr { namespace array { namespace $high_pad_t {

    template <typename type_p>
    concept any_tr =
        is_any_tr<type_p, high_pad_t<typename type_p::unit_t>>;

}}}

namespace nkr {

    template <>
    class type_traits_i<array::high_pad_tg>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t   Is_Any();
    };

    template <array::$high_pad_t::any_tr type_p>
    class type_traits_i<type_p> :
        public type_traits_i<array::high_pad_tg>
    {
    public:
        using of_t  = type_p::unit_t;
    };

    template <>
    class template_traits_i<array::high_pad_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = array::high_pad_t<of_p>;

    public:
        static constexpr c_bool_t   Is_Implemented();
    };

    template <>
    class template_traits_i<array::high_pad_t> :
        public template_traits_i<array::high_pad_ttg>
    {
    public:
    };

}

namespace nkr { namespace array {

    template <any_type_tr unit_p>
    class high_pad_t
    {
    public:
        using unit_t            = unit_p;
        using writable_unit_t   = std::remove_const_t<unit_t>;
        using static_t          = static_t<unit_t>;
        using split_t           = stack_t<high_pad_t, 2>;

    private:
        static auto&    Copy_Assign(is_any_non_const_tr<high_pad_t> auto& self, const is_any_tr<high_pad_t> auto& other);
        static auto&    Move_Assign(is_any_non_const_tr<high_pad_t> auto& self, is_any_non_const_tr<high_pad_t> auto&& other);

        static bool_t   Has_Memory(const is_any_tr<high_pad_t> auto& self);

        static count_t  Unit_Count(const is_any_tr<high_pad_t> auto& self);
        static count_t  Non_Extra_Unit_Count(const is_any_tr<high_pad_t> auto& self);
        static count_t  Extra_Unit_Count(const is_any_tr<high_pad_t> auto& self);
        static count_t  Total_Unit_Count(const is_any_tr<high_pad_t> auto& self);

        static auto&    Unit(is_any_tr<high_pad_t> auto& self, index_t index);
        static auto&    Extra_Unit(is_any_tr<high_pad_t> auto& self);

        static split_t  Split(is_any_tr<high_pad_t> auto& self, index_t at_index); // at_index is the first index of the second

    protected:
        static_t        static_array;
        count_t         total_unit_count;
        writable_unit_t extra_unit;

    public:
        high_pad_t();

        high_pad_t(tr2<any_tg, pointable_array_ttg, of_just_accessed_tg, unit_t> auto& array);
        high_pad_t(tr2<any_tg, pointable_array_ttg, of_just_accessed_tg, unit_t> auto& array, count_t total_unit_count);
        high_pad_t(tr2<any_tg, pointable_array_ttg, of_just_accessed_tg, unit_t> auto& array, count_t total_unit_count, const tr1<any_tg, unit_t> auto& extra_unit);
        high_pad_t(tr2<any_tg, pointable_array_ttg, of_just_accessed_tg, unit_t> auto& array, count_t total_unit_count, tr1<any_non_const_tg, unit_t> auto&& extra_unit);

        high_pad_t(count_t total_unit_count);
        high_pad_t(count_t total_unit_count, const tr1<any_tg, unit_t> auto& extra_unit);
        high_pad_t(count_t total_unit_count, tr1<any_non_const_tg, unit_t> auto&& extra_unit);

        high_pad_t(const high_pad_t& other);
        high_pad_t(const volatile high_pad_t& other);
        high_pad_t(high_pad_t&& other) noexcept;
        high_pad_t(volatile high_pad_t&& other) noexcept;

        high_pad_t&             operator =(const high_pad_t& other);
        volatile high_pad_t&    operator =(const high_pad_t& other) volatile;
        high_pad_t&             operator =(const volatile high_pad_t& other);
        volatile high_pad_t&    operator =(const volatile high_pad_t& other) volatile;
        high_pad_t&             operator =(high_pad_t&& other) noexcept;
        volatile high_pad_t&    operator =(high_pad_t&& other) volatile noexcept;
        high_pad_t&             operator =(is_just_volatile_tr<high_pad_t> auto&& other) noexcept;
        volatile high_pad_t&    operator =(is_just_volatile_tr<high_pad_t> auto&& other) volatile noexcept;

        ~high_pad_t();

    public:
        bool_t                  Has_Memory() const;
        bool_t                  Has_Memory() const volatile;

        count_t                 Count() const;
        count_t                 Count() const volatile;
        count_t                 Unit_Count() const;
        count_t                 Unit_Count() const volatile;
        count_t                 Non_Extra_Unit_Count() const;
        count_t                 Non_Extra_Unit_Count() const volatile;
        count_t                 Extra_Unit_Count() const;
        count_t                 Extra_Unit_Count() const volatile;
        count_t                 Total_Unit_Count() const;
        count_t                 Total_Unit_Count() const volatile;

        unit_t&                 Unit(index_t index);
        const unit_t&           Unit(index_t index) const;
        volatile unit_t&        Unit(index_t index) volatile;
        const volatile unit_t&  Unit(index_t index) const volatile;
        unit_t&                 Extra_Unit();
        const unit_t&           Extra_Unit() const;
        volatile unit_t&        Extra_Unit() volatile;
        const volatile unit_t&  Extra_Unit() const volatile;

        split_t                 Split(index_t at_index) const;
        split_t                 Split(index_t at_index) const volatile;

    public:
        unit_t&                 operator [](index_t index);
        const unit_t&           operator [](index_t index) const;
        volatile unit_t&        operator [](index_t index) volatile;
        const volatile unit_t&  operator [](index_t index) const volatile;
    };

    static_assert(array_i<high_pad_t<word_t>>);
    static_assert(array_i<high_pad_t<const word_t>>);
    static_assert(array_i<high_pad_t<volatile word_t>>);
    static_assert(array_i<high_pad_t<const volatile word_t>>);
    static_assert(array_i<const high_pad_t<word_t>>);
    static_assert(array_i<const high_pad_t<const word_t>>);
    static_assert(array_i<const high_pad_t<volatile word_t>>);
    static_assert(array_i<const high_pad_t<const volatile word_t>>);
    static_assert(array_i<volatile high_pad_t<word_t>>);
    static_assert(array_i<volatile high_pad_t<const word_t>>);
    static_assert(array_i<volatile high_pad_t<volatile word_t>>);
    static_assert(array_i<volatile high_pad_t<const volatile word_t>>);
    static_assert(array_i<const volatile high_pad_t<word_t>>);
    static_assert(array_i<const volatile high_pad_t<const word_t>>);
    static_assert(array_i<const volatile high_pad_t<volatile word_t>>);
    static_assert(array_i<const volatile high_pad_t<const volatile word_t>>);

    static_assert(non_aggregate_array_i<high_pad_t<word_t>>);
    static_assert(non_aggregate_array_i<high_pad_t<const word_t>>);
    static_assert(non_aggregate_array_i<high_pad_t<volatile word_t>>);
    static_assert(non_aggregate_array_i<high_pad_t<const volatile word_t>>);
    static_assert(non_aggregate_array_i<const high_pad_t<word_t>>);
    static_assert(non_aggregate_array_i<const high_pad_t<const word_t>>);
    static_assert(non_aggregate_array_i<const high_pad_t<volatile word_t>>);
    static_assert(non_aggregate_array_i<const high_pad_t<const volatile word_t>>);
    static_assert(non_aggregate_array_i<volatile high_pad_t<word_t>>);
    static_assert(non_aggregate_array_i<volatile high_pad_t<const word_t>>);
    static_assert(non_aggregate_array_i<volatile high_pad_t<volatile word_t>>);
    static_assert(non_aggregate_array_i<volatile high_pad_t<const volatile word_t>>);
    static_assert(non_aggregate_array_i<const volatile high_pad_t<word_t>>);
    static_assert(non_aggregate_array_i<const volatile high_pad_t<const word_t>>);
    static_assert(non_aggregate_array_i<const volatile high_pad_t<volatile word_t>>);
    static_assert(non_aggregate_array_i<const volatile high_pad_t<const volatile word_t>>);

    static_assert(non_pointable_array_i<high_pad_t<word_t>>);
    static_assert(non_pointable_array_i<high_pad_t<const word_t>>);
    static_assert(non_pointable_array_i<high_pad_t<volatile word_t>>);
    static_assert(non_pointable_array_i<high_pad_t<const volatile word_t>>);
    static_assert(non_pointable_array_i<const high_pad_t<word_t>>);
    static_assert(non_pointable_array_i<const high_pad_t<const word_t>>);
    static_assert(non_pointable_array_i<const high_pad_t<volatile word_t>>);
    static_assert(non_pointable_array_i<const high_pad_t<const volatile word_t>>);
    static_assert(non_pointable_array_i<volatile high_pad_t<word_t>>);
    static_assert(non_pointable_array_i<volatile high_pad_t<const word_t>>);
    static_assert(non_pointable_array_i<volatile high_pad_t<volatile word_t>>);
    static_assert(non_pointable_array_i<volatile high_pad_t<const volatile word_t>>);
    static_assert(non_pointable_array_i<const volatile high_pad_t<word_t>>);
    static_assert(non_pointable_array_i<const volatile high_pad_t<const word_t>>);
    static_assert(non_pointable_array_i<const volatile high_pad_t<volatile word_t>>);
    static_assert(non_pointable_array_i<const volatile high_pad_t<const volatile word_t>>);

}}
