/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_bool_t.h"
#include "nkr/z_intrinsics.h"
#include "nkr/z_macros.h"
#include "nkr/z_math.h"
#include "nkr/z_maybe_t.h"
#include "nkr/z_some_t.h"
#include "nkr/z_traits.h"

#include "nkr/z_allocator_err.h"
#include "nkr/z_allocator_i.h"
#include "nkr/z_allocator/heap_t.h"

#include "nkr/z_array/dynamic_t.h"

#include "nkr/z_charcoder_i.h"
#include "nkr/z_charcoder/utf_8_t.h"

#include "nkr/z_string_i.h"
#include "nkr/z_string_itr_dec.h"

// to be deleted
namespace nkr { namespace string {

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    class dynamic_t;

    template <typename string_p>
    concept any_dynamic_tr =
        is_any_tr<string_p, dynamic_t<typename string_p::qualified_charcoder_t, typename string_p::allocator_t, typename string_p::grow_rate_t>>;

    nkr_DEFINE_CONTAINER_TRAITS(dynamic, qualified_charcoder_t);

}}
//

namespace nkr { namespace string {

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    class dynamic_t;

    struct                      dynamic_tg  {};
    template <typename> struct  dynamic_ttg {};

}}

namespace nkr { namespace string { namespace dynamic_t$ {

    template <typename type_p>
    concept any_tr =
        is_any_tr<type_p, dynamic_t<typename type_p::qualified_charcoder_t, typename type_p::allocator_t, typename type_p::grow_rate_t>>;

}}}

namespace nkr {

    template <>
    class type_traits_i<string::dynamic_tg>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t   Is_Any();
    };

    template <string::dynamic_t$::any_tr type_p>
    class type_traits_i<type_p> :
        public type_traits_i<string::dynamic_tg>
    {
    public:
        using of_t  = type_p::qualified_charcoder_t;
    };

    template <>
    class template_traits_i<string::dynamic_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = string::dynamic_t<of_p, allocator::heap_t<typename of_p::unit_t>, math::fraction_t<17, 10>>;

    public:
        static constexpr c_bool_t   Is_Implemented();
    };

    template <>
    class template_traits_i<string::dynamic_t> :
        public template_traits_i<string::dynamic_ttg>
    {
    public:
    };

}

namespace nkr { namespace string {

    // might it be worth adding an iterator to the string itself? that way we can allow things like the access operator to be more efficient
    // also, the we wouldn't necessarily have to use the stack for charcoders, unless we wanted to.

    template <
        charcoder_i         charcoder_p,
        allocator_i         allocator_p = allocator::heap_t<typename charcoder_p::unit_t>,
        math::fraction_i    grow_rate_p = math::fraction_t<17, 10>
    > class dynamic_t
    {
    public:
        static_assert(is_tr<charcoder_p::unit_t, allocator_p::unit_t>, "charcoder and allocator have different unit types");

    public:
        using charcoder_t           = std::remove_cv_t<charcoder_p>;
        using qualified_charcoder_t = charcoder_p;
        using unit_t                = same_qualification_as_t<typename charcoder_t::unit_t, qualified_charcoder_t>;
        using allocator_t           = allocator_p;
        using grow_rate_t           = grow_rate_p;
        using array_t               = array::dynamic_t<unit_t, allocator_p, grow_rate_p>;

    public:
        static constexpr c_bool_t   Has_Guaranteed_Terminus();

    public:
        static const unit_t*    Empty_C_String();

    private:
        static auto&                    Copy_Assign(is_any_non_const_tr<dynamic_t> auto& self,
                                                    const is_any_tr<dynamic_t> auto& other);
        static auto&                    Move_Assign(is_any_non_const_tr<dynamic_t> auto& self,
                                                    is_any_non_const_tr<dynamic_t> auto& other);

        static bool_t                   Has_Memory(const is_any_tr<dynamic_t> auto& self);
        static bool_t                   Has_Terminus(const is_any_tr<dynamic_t> auto& self);

        static count_t                  Unit_Capacity(const is_any_tr<dynamic_t> auto& self);
        static maybe_t<allocator_err>   Unit_Capacity(is_any_tr<dynamic_t> auto& self, count_t unit_capacity_including_terminus);

        static count_t                  Unit_Count(const is_any_tr<dynamic_t> auto& self);
        static count_t                  Unit_Length(const is_any_tr<dynamic_t> auto& self);

        static count_t                  Point_Count(const is_any_tr<dynamic_t> auto& self);
        static count_t                  Point_Length(const is_any_tr<dynamic_t> auto& self);

        static auto                     C_String(const is_any_tr<dynamic_t> auto& self);

        static auto                     At(const is_any_tr<dynamic_t> auto& self, index_t point_index);
        static auto                     At_Prefix(const is_any_tr<dynamic_t> auto& self);
        static auto                     At_First(const is_any_tr<dynamic_t> auto& self);
        static auto                     At_Last(const is_any_tr<dynamic_t> auto& self);
        static auto                     At_Terminus(const is_any_tr<dynamic_t> auto& self);
        static auto                     At_Postfix(const is_any_tr<dynamic_t> auto& self);

        static void_t                   Push_Terminus(is_any_tr<dynamic_t> auto& self);
        static void_t                   Pop_Terminus(is_any_tr<dynamic_t> auto& self);

        static maybe_t<allocator_err>   Push(is_any_tr<dynamic_t> auto& self, point_t point);
        static maybe_t<allocator_err>   Push(is_any_tr<dynamic_t> auto& self, const charcoder_t& charcoder);
        static maybe_t<allocator_err>   Push(is_any_tr<dynamic_t> auto& self, const is_any_tr<unit_t> auto* c_string);
        static maybe_t<allocator_err>   Push(is_any_tr<dynamic_t> auto& self, const is_any_tr<unit_t> auto* c_string, count_t unit_length);
        static maybe_t<allocator_err>   Push(is_any_tr<dynamic_t> auto& self, const any_string_tr auto& other);
        static maybe_t<allocator_err>   Push(is_any_tr<dynamic_t> auto& self, any_non_const_string_tr auto&& other);

        static auto&                    Unit(is_any_tr<dynamic_t> auto& self, index_t unit_index);

    protected:
        count_t point_count;
        array_t array;

    public:
        dynamic_t();

        dynamic_t(count_t unit_capacity_including_terminus);

        dynamic_t(const charcoder_t& charcoder);
        dynamic_t(const is_any_tr<unit_t> auto* c_string); // const is_any_some_of_any_tr<unit_t> auto*

        dynamic_t(const any_string_tr auto& string);
        dynamic_t(any_non_const_string_tr auto&& string);
        dynamic_t(any_const_string_tr auto&& string)                                                    = delete;

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
        bool_t                                  Has_Memory() const;
        bool_t                                  Has_Memory() const volatile;
        bool_t                                  Has_Terminus() const;
        bool_t                                  Has_Terminus() const volatile;

        count_t                                 Unit_Capacity() const;
        count_t                                 Unit_Capacity() const volatile;
        maybe_t<allocator_err>                  Unit_Capacity(count_t unit_capacity_including_terminus);
        maybe_t<allocator_err>                  Unit_Capacity(count_t unit_capacity_including_terminus) volatile;

        count_t                                 Unit_Count() const;
        count_t                                 Unit_Count() const volatile;
        count_t                                 Unit_Length() const;
        count_t                                 Unit_Length() const volatile;

        count_t                                 Point_Count() const;
        count_t                                 Point_Count() const volatile;
        count_t                                 Point_Length() const;
        count_t                                 Point_Length() const volatile;

        some_t<const unit_t*>                   C_String() const;
        some_t<const volatile unit_t*>          C_String() const volatile;

        string_itr<const dynamic_t>             At(index_t point_index) const;
        string_itr<const volatile dynamic_t>    At(index_t point_index) const volatile;
        string_itr<const dynamic_t>             At_Prefix() const;
        string_itr<const volatile dynamic_t>    At_Prefix() const volatile;
        string_itr<const dynamic_t>             At_First() const;
        string_itr<const volatile dynamic_t>    At_First() const volatile;
        string_itr<const dynamic_t>             At_Last() const;
        string_itr<const volatile dynamic_t>    At_Last() const volatile;
        string_itr<const dynamic_t>             At_Terminus() const;
        string_itr<const volatile dynamic_t>    At_Terminus() const volatile;
        string_itr<const dynamic_t>             At_Postfix() const;
        string_itr<const volatile dynamic_t>    At_Postfix() const volatile;

        maybe_t<allocator_err>                  Push(point_t point);
        maybe_t<allocator_err>                  Push(point_t point) volatile;
        maybe_t<allocator_err>                  Push(const charcoder_t& charcoder);
        maybe_t<allocator_err>                  Push(const charcoder_t& charcoder) volatile;
        maybe_t<allocator_err>                  Push(const is_any_tr<unit_t> auto* c_string);
        maybe_t<allocator_err>                  Push(const is_any_tr<unit_t> auto* c_string) volatile;
        maybe_t<allocator_err>                  Push(const is_any_tr<unit_t> auto* c_string, count_t unit_length);
        maybe_t<allocator_err>                  Push(const is_any_tr<unit_t> auto* c_string, count_t unit_length) volatile;
        maybe_t<allocator_err>                  Push(const any_string_tr auto& string);
        maybe_t<allocator_err>                  Push(const any_string_tr auto& string) volatile;
        maybe_t<allocator_err>                  Push(any_non_const_string_tr auto&& string);
        maybe_t<allocator_err>                  Push(any_non_const_string_tr auto&& string) volatile;

        unit_t&                                 Unit(index_t unit_index);
        const unit_t&                           Unit(index_t unit_index) const;
        volatile unit_t&                        Unit(index_t unit_index) volatile;
        const volatile unit_t&                  Unit(index_t unit_index) const volatile;

        // Split and Join should return new strings without altering this one. Push alters this one
    };
    static_assert(string_i<dynamic_t<charcoder::utf_8_t>>);
    static_assert(string_i<const dynamic_t<charcoder::utf_8_t>>);
    static_assert(string_i<volatile dynamic_t<charcoder::utf_8_t>>);
    static_assert(string_i<const volatile dynamic_t<charcoder::utf_8_t>>);

}}

namespace nkr {

    template <
        string::any_dynamic_tr  string_p,
        count_t                 min_point_count_p   = string::Default_Min_Point_Count(),
        count_t                 max_point_count_p   = string::Default_Max_Point_Count(min_point_count_p)
    > auto  Random(bool_t use_erroneous_units = false);

}
