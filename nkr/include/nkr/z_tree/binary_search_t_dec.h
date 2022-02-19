/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_bool_t_dec.h"
#include "nkr/z_intrinsics_dec.h"
#include "nkr/z_math_dec.h"
#include "nkr/z_maybe_t_dec.h"
#include "nkr/z_optional_t_dec.h"
#include "nkr/z_traits.h"

#include "nkr/z_allocator_err.h"

#include "nkr/z_array/stack_t_dec.h"

namespace nkr { namespace tree { namespace stack {

    // value_t needs to have operators ==, <=, >=, and maybe <, >
    template <typename node_p>
    concept node_i =
        (tr1<node_p, any_tg, maybe_tg> ||
         tr1<node_p, any_tg, optional_tg>) &&
        any_type_tr<typename node_p::value_t>;

}}}

namespace nkr { namespace tree { namespace stack {

    template <typename node_p, count_t max_node_count_p>
    class binary_search_t;

    struct                      binary_search_tg    {};
    template <typename> struct  binary_search_ttg   {};

}}}

namespace nkr { namespace tree { namespace stack { namespace $binary_search_t {

    template <typename type_p>
    concept any_tr =
        is_any_tr<type_p, binary_search_t<typename type_p::node_t, type_p::Max_Node_Count()>> ||
        is_any_tr<type_p, binary_search_t<typename type_p::node_t, type_p::Max_Node_Count()>>;

}}}}

namespace nkr {

    template <>
    class type_traits_i<tree::stack::binary_search_tg>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t   Is_Any();
    };

    template <tree::stack::$binary_search_t::any_tr type_p>
    class type_traits_i<type_p> :
        public type_traits_i<tree::stack::binary_search_tg>
    {
    public:
        using of_t  = type_p::node_t;
    };

    template <>
    class template_traits_i<tree::stack::binary_search_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = tree::stack::binary_search_t<of_p, 1>;

    public:
        static constexpr c_bool_t   Is_Implemented();
    };

}

namespace nkr { namespace tree { namespace stack {

    template <typename node_p, count_t max_node_count_p>
    class binary_search_t
    {
    public:
        binary_search_t()                                                                                           = delete;

        binary_search_t(const binary_search_t& other)                                                               = delete;
        binary_search_t(const volatile binary_search_t& other)                                                      = delete;
        binary_search_t(binary_search_t&& other) noexcept                                                           = delete;
        binary_search_t(volatile binary_search_t&& other) noexcept                                                  = delete;

        binary_search_t&            operator =(const binary_search_t& other)                                        = delete;
        volatile binary_search_t&   operator =(const binary_search_t& other) volatile                               = delete;
        binary_search_t&            operator =(const volatile binary_search_t& other)                               = delete;
        volatile binary_search_t&   operator =(const volatile binary_search_t& other) volatile                      = delete;
        binary_search_t&            operator =(binary_search_t&& other) noexcept                                    = delete;
        volatile binary_search_t&   operator =(binary_search_t&& other) volatile noexcept                           = delete;
        binary_search_t&            operator =(is_just_volatile_tr<binary_search_t> auto&& other) noexcept          = delete;
        volatile binary_search_t&   operator =(is_just_volatile_tr<binary_search_t> auto&& other) volatile noexcept = delete;

        ~binary_search_t()                                                                                          = delete;
    };

    template <node_i node_p, count_t max_node_count_p>
    class binary_search_t<node_p, max_node_count_p>
    {
    public:
        using node_t    = node_p;
        using value_t   = node_p::value_t;

    public:
        static_assert(math::Is_Even(max_node_count_p));

    public:
        static constexpr count_t    Max_Node_Count();

    private:
        maybe_t<allocator_err>  Add(tr1<any_non_const_tg, binary_search_t> auto& self, const value_t& unit);
        maybe_t<allocator_err>  Add(tr1<any_non_const_tg, binary_search_t> auto& self, value_t&& unit);

        index_t                 Parent(tr1<any_tg, binary_search_t> auto& self, index_t node_index);
        index_t                 Low_Child(tr1<any_tg, binary_search_t> auto& self, index_t node_index);
        index_t                 High_Child(tr1<any_tg, binary_search_t> auto& self, index_t node_index);

    protected:
        array::stack_t<node_t, max_node_count_p>    nodes;
        node_t                                      sentinel;

    public:
        binary_search_t();

        binary_search_t(const node_t& sentinel);
        binary_search_t(node_t&& sentinel);

        binary_search_t(const binary_search_t& other);
        binary_search_t(const volatile binary_search_t& other);
        binary_search_t(binary_search_t&& other) noexcept;
        binary_search_t(volatile binary_search_t&& other) noexcept;

        binary_search_t&            operator =(const binary_search_t& other);
        volatile binary_search_t&   operator =(const binary_search_t& other) volatile;
        binary_search_t&            operator =(const volatile binary_search_t& other);
        volatile binary_search_t&   operator =(const volatile binary_search_t& other) volatile;
        binary_search_t&            operator =(binary_search_t&& other) noexcept;
        volatile binary_search_t&   operator =(binary_search_t&& other) volatile noexcept;
        binary_search_t&            operator =(is_just_volatile_tr<binary_search_t> auto&& other) noexcept;
        volatile binary_search_t&   operator =(is_just_volatile_tr<binary_search_t> auto&& other) volatile noexcept;

        ~binary_search_t();

    public:
        maybe_t<allocator_err>  Add(const value_t& unit);
        maybe_t<allocator_err>  Add(const value_t& unit) volatile;
        maybe_t<allocator_err>  Add(value_t&& unit);
        maybe_t<allocator_err>  Add(value_t&& unit) volatile;

        bool_t                  Remove(const value_t& unit);
        bool_t                  Remove(const value_t& unit) volatile;
        bool_t                  Remove(value_t&& unit);
        bool_t                  Remove(value_t&& unit) volatile;

        // we can have a Remove_Each that can accept a functor. we do need to add our functor types to the library, it would be a good time to
    };

    // we can also have an implementation that handles built-ins with a sentinel by default as the max value?

}}}
