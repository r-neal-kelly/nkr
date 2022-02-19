/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_bool_t.h"
#include "nkr/z_intrinsics.h"
#include "nkr/z_macros.h"
#include "nkr/z_maybe_t.h"
#include "nkr/z_pointer_t.h"
#include "nkr/z_some_t.h"
#include "nkr/z_traits.h"

#include "nkr/z_allocator_err.h"

#include "nkr/z_array/stack_t.h"

#include "nkr/z_charcoder_i.h"
#include "nkr/z_charcoder/utf_8_t.h"

#include "nkr/z_string_i.h"
#include "nkr/z_string_itr_dec.h"

namespace nkr { namespace string {

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    class stack_t;

    struct                      stack_tg    {};
    template <typename> struct  stack_ttg   {};

}}

namespace nkr { namespace string { namespace $stack_t {

    template <typename type_p>
    concept any_tr =
        is_any_tr<type_p, stack_t<typename type_p::qualified_charcoder_t, type_p::Unit_Capacity()>>;

}}}

namespace nkr {

    template <>
    class type_traits_i<string::stack_tg>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t   Is_Any();
    };

    template <string::$stack_t::any_tr type_p>
    class type_traits_i<type_p> :
        public type_traits_i<string::stack_tg>
    {
    public:
        using of_t  = type_p::qualified_charcoder_t;
    };

    template <>
    class template_traits_i<string::stack_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = string::stack_t<of_p, 1>;

    public:
        static constexpr c_bool_t   Is_Implemented();
    };

}

// to be deleted
namespace nkr { namespace string {

    template <typename type_p>
    concept any_stack_tr =
        is_any_tr<type_p, stack_t<typename type_p::qualified_charcoder_t, type_p::Unit_Capacity()>>;

    nkr_DEFINE_CONTAINER_TRAITS(stack, qualified_charcoder_t);

}}
//

namespace nkr { namespace string {

    template <charcoder_i charcoder_p, count_t unit_capacity_p = 128>
    class stack_t
    {
    public:
        static_assert(unit_capacity_p >= 1, "string::stack_t must have at least a unit_capacity of 1 to fit the terminus.");

    public:
        using charcoder_t           = std::remove_cv_t<charcoder_p>;
        using qualified_charcoder_t = charcoder_p;
        using unit_t                = same_qualification_as_t<typename charcoder_t::unit_t, qualified_charcoder_t>;
        using array_t               = array::stack_t<unit_t, unit_capacity_p>;

    public:
        template <charcoder_i charcoder_pp, count_t unit_capacity_pp>
        friend class stack_t;

    public:
        static constexpr c_bool_t   Has_Guaranteed_Terminus();

        static constexpr count_t    Unit_Capacity();

    public:
        static const unit_t*    Empty_C_String();

    private:
        static auto&                    Copy_Assign(is_any_non_const_tr<stack_t> auto& self, const is_any_tr<stack_t> auto& other);
        static auto&                    Move_Assign(is_any_non_const_tr<stack_t> auto& self, is_any_non_const_tr<stack_t> auto& other);

        static bool_t                   Has_Memory(const is_any_tr<stack_t> auto& self);
        static bool_t                   Has_Terminus(const is_any_tr<stack_t> auto& self);

        static count_t                  Unit_Capacity(const is_any_tr<stack_t> auto& self);
        static maybe_t<allocator_err>   Unit_Capacity(is_any_non_const_tr<stack_t> auto& self, count_t unit_capacity_including_terminus);

        static count_t                  Unit_Count(const is_any_tr<stack_t> auto& self);
        static count_t                  Unit_Count(const is_any_tr<stack_t> auto& self, index_t from_point_index, count_t point_count);
        static count_t                  Unit_Length(const is_any_tr<stack_t> auto& self);

        static count_t                  Point_Count(const is_any_tr<stack_t> auto& self);
        static count_t                  Point_Length(const is_any_tr<stack_t> auto& self);

        static auto                     C_String(const is_any_tr<stack_t> auto& self);

        static auto                     At(const is_any_tr<stack_t> auto& self, index_t point_index);
        static auto                     At_Prefix(const is_any_tr<stack_t> auto& self);
        static auto                     At_First(const is_any_tr<stack_t> auto& self);
        static auto                     At_Last(const is_any_tr<stack_t> auto& self);
        static auto                     At_Terminus(const is_any_tr<stack_t> auto& self);
        static auto                     At_Postfix(const is_any_tr<stack_t> auto& self);

        static void_t                   Push_Terminus(is_any_non_const_tr<stack_t> auto& self);
        static void_t                   Pop_Terminus(is_any_non_const_tr<stack_t> auto& self);

        static maybe_t<allocator_err>   Push(is_any_non_const_tr<stack_t> auto& self, point_t point);
        static maybe_t<allocator_err>   Push(is_any_non_const_tr<stack_t> auto& self, const charcoder_t& charcoder);
        static maybe_t<allocator_err>   Push(is_any_non_const_tr<stack_t> auto& self, tr2<any_tg, c_pointer_ttg, of_any_tg, unit_t> auto c_string);
        static maybe_t<allocator_err>   Push(is_any_non_const_tr<stack_t> auto& self, tr2<any_tg, c_pointer_ttg, of_any_tg, unit_t> auto c_string, count_t unit_count_or_length);
        static maybe_t<allocator_err>   Push(is_any_non_const_tr<stack_t> auto& self, tr2<any_tg, c_pointer_ttg, of_any_tg, unit_t> auto c_string, count_t unit_length, count_t point_length);
        static maybe_t<allocator_err>   Push(is_any_non_const_tr<stack_t> auto& self, const any_string_tr auto& other);
        static maybe_t<allocator_err>   Push(is_any_non_const_tr<stack_t> auto& self, any_non_const_string_tr auto&& other);

        static auto&                    Unit(is_any_tr<stack_t> auto& self, index_t unit_index);

    protected:
        count_t point_count;
        array_t array;

    public:
        stack_t();

        stack_t(const charcoder_t& charcoder);

        stack_t(tr2<any_tg, c_pointer_ttg, of_any_tg, unit_t> auto c_string);
        stack_t(tr2<any_tg, c_pointer_ttg, of_any_tg, unit_t> auto c_string, count_t unit_count_or_length);
        stack_t(tr2<any_tg, c_pointer_ttg, of_any_tg, unit_t> auto c_string, count_t unit_count_or_length, maybe_t<allocator_err>& result);
        stack_t(tr3<any_tg, maybe_t, of_any_tg, c_pointer_ttg, of_any_tg, unit_t> auto maybe_c_string);
        stack_t(tr3<any_tg, maybe_t, of_any_tg, c_pointer_ttg, of_any_tg, unit_t> auto maybe_c_string, count_t unit_count_or_length);
        stack_t(tr3<any_tg, maybe_t, of_any_tg, c_pointer_ttg, of_any_tg, unit_t> auto maybe_c_string, count_t unit_count_or_length, maybe_t<allocator_err>& result);
        stack_t(tr3<any_tg, some_t, of_any_tg, c_pointer_ttg, of_any_tg, unit_t> auto some_c_string);
        stack_t(tr3<any_tg, some_t, of_any_tg, c_pointer_ttg, of_any_tg, unit_t> auto some_c_string, count_t unit_count_or_length);
        stack_t(tr3<any_tg, some_t, of_any_tg, c_pointer_ttg, of_any_tg, unit_t> auto some_c_string, count_t unit_count_or_length, maybe_t<allocator_err>& result);

        stack_t(some_t<pointer_t<unit_t>> some_pointer);

        stack_t(const any_string_tr auto& string);
        stack_t(any_non_const_string_tr auto&& string);
        stack_t(any_const_string_tr auto&& string) = delete;

        stack_t(const stack_t& other);
        stack_t(const volatile stack_t& other);
        stack_t(stack_t&& other) noexcept;
        stack_t(volatile stack_t&& other) noexcept;

        stack_t&            operator =(const stack_t& other);
        volatile stack_t&   operator =(const stack_t& other) volatile;
        stack_t&            operator =(const volatile stack_t& other);
        volatile stack_t&   operator =(const volatile stack_t& other) volatile;
        stack_t&            operator =(stack_t&& other) noexcept;
        volatile stack_t&   operator =(stack_t&& other) volatile noexcept;
        stack_t&            operator =(is_just_volatile_tr<stack_t> auto&& other) noexcept;
        volatile stack_t&   operator =(is_just_volatile_tr<stack_t> auto&& other) volatile noexcept;

        ~stack_t();

    public:
        bool_t                              Has_Memory() const;
        bool_t                              Has_Memory() const volatile;
        bool_t                              Has_Terminus() const;
        bool_t                              Has_Terminus() const volatile;

        maybe_t<allocator_err>              Unit_Capacity(count_t unit_capacity_including_terminus);
        maybe_t<allocator_err>              Unit_Capacity(count_t unit_capacity_including_terminus) volatile;

        count_t                             Unit_Count() const;
        count_t                             Unit_Count() const volatile;
        count_t                             Unit_Count(index_t from_point_index, count_t point_count) const;
        count_t                             Unit_Count(index_t from_point_index, count_t point_count) const volatile;
        count_t                             Unit_Length() const;
        count_t                             Unit_Length() const volatile;

        count_t                             Point_Count() const;
        count_t                             Point_Count() const volatile;
        count_t                             Point_Length() const;
        count_t                             Point_Length() const volatile;

        some_t<const unit_t*>               C_String() const;
        some_t<const volatile unit_t*>      C_String() const volatile;

        string_itr<const stack_t>           At(index_t point_index) const;
        string_itr<const volatile stack_t>  At(index_t point_index) const volatile;
        string_itr<const stack_t>           At_Prefix() const;
        string_itr<const volatile stack_t>  At_Prefix() const volatile;
        string_itr<const stack_t>           At_First() const;
        string_itr<const volatile stack_t>  At_First() const volatile;
        string_itr<const stack_t>           At_Last() const;
        string_itr<const volatile stack_t>  At_Last() const volatile;
        string_itr<const stack_t>           At_Terminus() const;
        string_itr<const volatile stack_t>  At_Terminus() const volatile;
        string_itr<const stack_t>           At_Postfix() const;
        string_itr<const volatile stack_t>  At_Postfix() const volatile;

        maybe_t<allocator_err>              Push(point_t point);
        maybe_t<allocator_err>              Push(point_t point) volatile;
        maybe_t<allocator_err>              Push(const charcoder_t& charcoder);
        maybe_t<allocator_err>              Push(const charcoder_t& charcoder) volatile;
        maybe_t<allocator_err>              Push(const is_any_tr<unit_t> auto* c_string);
        maybe_t<allocator_err>              Push(const is_any_tr<unit_t> auto* c_string) volatile;
        maybe_t<allocator_err>              Push(const is_any_tr<unit_t> auto* c_string, count_t unit_count_or_length);
        maybe_t<allocator_err>              Push(const is_any_tr<unit_t> auto* c_string, count_t unit_count_or_length) volatile;
        maybe_t<allocator_err>              Push(const any_string_tr auto& string);
        maybe_t<allocator_err>              Push(const any_string_tr auto& string) volatile;
        maybe_t<allocator_err>              Push(any_non_const_string_tr auto&& string);
        maybe_t<allocator_err>              Push(any_non_const_string_tr auto&& string) volatile;

        unit_t&                             Unit(index_t unit_index);
        const unit_t&                       Unit(index_t unit_index) const;
        volatile unit_t&                    Unit(index_t unit_index) volatile;
        const volatile unit_t&              Unit(index_t unit_index) const volatile;
    };
    static_assert(string_i<stack_t<charcoder::utf_8_t>>);
    static_assert(string_i<const stack_t<charcoder::utf_8_t>>);
    static_assert(string_i<volatile stack_t<charcoder::utf_8_t>>);
    static_assert(string_i<const volatile stack_t<charcoder::utf_8_t>>);

}}

namespace nkr {

    template <
        tr1<any_tg, string::stack_tg>   string_p,
        count_t                         min_point_count_p   = string::Default_Min_Point_Count(),
        count_t                         max_point_count_p   = string::Default_Max_Point_Count(min_point_count_p)
    > auto  Random(bool_t use_erroneous_units = false);

}
