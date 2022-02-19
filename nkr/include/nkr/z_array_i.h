/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_intrinsics.h"
#include "nkr/z_macros.h"
#include "nkr/z_math.h"
#include "nkr/z_maybe_t.h"
#include "nkr/z_pointer_t.h"
#include "nkr/z_traits.h"
#include "nkr/z_utils.h"

#include "nkr/z_allocator_err.h"

namespace nkr { namespace $array_i {

    template <typename array_p>
    concept aliases_i =
        requires()
    {
        typename array_p::unit_t;
    };

    template <typename array_p>
    concept methods_i =
        requires(std::remove_cv_t<array_p> array,
                 const std::remove_cv_t<array_p> const_array,
                 volatile std::remove_cv_t<array_p> volatile_array,
                 const volatile std::remove_cv_t<array_p> const_volatile_array)
    {
        { array.Has_Memory() }                  -> is_tr<bool_t>;
        { const_array.Has_Memory() }            -> is_tr<bool_t>;
        { volatile_array.Has_Memory() }         -> is_tr<bool_t>;
        { const_volatile_array.Has_Memory() }   -> is_tr<bool_t>;

        { array.Count() }                       -> is_tr<count_t>;
        { const_array.Count() }                 -> is_tr<count_t>;
        { volatile_array.Count() }              -> is_tr<count_t>;
        { const_volatile_array.Count() }        -> is_tr<count_t>;
    };

    template <typename array_p>
    concept aggregate_methods_i =
        requires(std::remove_cv_t<array_p> array,
                 const std::remove_cv_t<array_p> const_array,
                 volatile std::remove_cv_t<array_p> volatile_array,
                 const volatile std::remove_cv_t<array_p> const_volatile_array,

                 count_t new_capacity,

                 typename array_p::unit_t & lvalue_unit,
                 typename array_p::writable_unit_t && rvalue_unit)
    {
        { array.Capacity() }                            -> is_tr<count_t>;
        { const_array.Capacity() }                      -> is_tr<count_t>;
        { volatile_array.Capacity() }                   -> is_tr<count_t>;
        { const_volatile_array.Capacity() }             -> is_tr<count_t>;
        { array.Capacity(new_capacity) }                -> is_tr<maybe_t<allocator_err>>;
        { volatile_array.Capacity(new_capacity) }       -> is_tr<maybe_t<allocator_err>>;
        { array.Reserve(new_capacity) }                 -> is_tr<maybe_t<allocator_err>>;
        { volatile_array.Reserve(new_capacity) }        -> is_tr<maybe_t<allocator_err>>;

        { array.Push(lvalue_unit) }                     -> is_tr<maybe_t<allocator_err>>;
        { volatile_array.Push(lvalue_unit) }            -> is_tr<maybe_t<allocator_err>>;

        { array.Push(nkr::Move(rvalue_unit)) }          -> is_tr<maybe_t<allocator_err>>;
        { volatile_array.Push(nkr::Move(rvalue_unit)) } -> is_tr<maybe_t<allocator_err>>;

        // maybe add and remove instead of push pop. remove(index_t) can be an overload
    };

    template <typename array_p>
    concept pointable_methods_i =
        requires(std::remove_cv_t<array_p> array,
                 const std::remove_cv_t<array_p> const_array,
                 volatile std::remove_cv_t<array_p> volatile_array,
                 const volatile std::remove_cv_t<array_p> const_volatile_array)
    {
        { array.Pointer() }                 -> is_tr<maybe_t<pointer_t<typename array_p::unit_t>>>;
        { const_array.Pointer() }           -> is_tr<maybe_t<pointer_t<const typename array_p::unit_t>>>;
        { volatile_array.Pointer() }        -> is_tr<maybe_t<pointer_t<volatile typename array_p::unit_t>>>;
        { const_volatile_array.Pointer() }  -> is_tr<maybe_t<pointer_t<const volatile typename array_p::unit_t>>>;
    };

}}

namespace nkr {

    template <typename array_p>
    concept array_i =
        $array_i::aliases_i<array_p> &&
        $array_i::methods_i<array_p>;

    template <typename array_p>
    concept aggregate_array_i =
        array_i<array_p> &&
        $array_i::aggregate_methods_i<array_p>;

    template <typename array_p>
    concept non_aggregate_array_i =
        array_i<array_p> &&
        !aggregate_array_i<array_p>;

    template <typename array_p>
    concept pointable_array_i =
        array_i<array_p> &&
        $array_i::pointable_methods_i<array_p>;

    template <typename array_p>
    concept non_pointable_array_i =
        array_i<array_p> &&
        !pointable_array_i<array_p>;

}

namespace nkr {

    struct                      array_tg    {};
    template <typename> struct  array_ttg   {};

    template <>
    class type_traits_i<array_tg>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t Is_Any()
        {
            return array_i<other_p>;
        }
    };

    template <>
    class template_traits_i<array_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = array_tg;

    public:
        static constexpr c_bool_t Is_Implemented()
        {
            return true;
        }
    };

    struct                      aggregate_array_tg  {};
    template <typename> struct  aggregate_array_ttg {};

    template <>
    class type_traits_i<aggregate_array_tg>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t Is_Any()
        {
            return aggregate_array_i<other_p>;
        }
    };

    template <>
    class template_traits_i<aggregate_array_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = aggregate_array_tg;

    public:
        static constexpr c_bool_t Is_Implemented()
        {
            return true;
        }
    };

    struct                      non_aggregate_array_tg  {};
    template <typename> struct  non_aggregate_array_ttg {};

    template <>
    class type_traits_i<non_aggregate_array_tg>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t Is_Any()
        {
            return non_aggregate_array_i<other_p>;
        }
    };

    template <>
    class template_traits_i<non_aggregate_array_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = non_aggregate_array_tg;

    public:
        static constexpr c_bool_t Is_Implemented()
        {
            return true;
        }
    };

    struct                      pointable_array_tg  {};
    template <typename> struct  pointable_array_ttg {};

    template <>
    class type_traits_i<pointable_array_tg>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t Is_Any()
        {
            return pointable_array_i<other_p>;
        }
    };

    template <>
    class template_traits_i<pointable_array_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = pointable_array_tg;

    public:
        static constexpr c_bool_t Is_Implemented()
        {
            return true;
        }
    };

    struct                      non_pointable_array_tg  {};
    template <typename> struct  non_pointable_array_ttg {};

    template <>
    class type_traits_i<non_pointable_array_tg>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t Is_Any()
        {
            return non_pointable_array_i<other_p>;
        }
    };

    template <>
    class template_traits_i<non_pointable_array_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = non_pointable_array_tg;

    public:
        static constexpr c_bool_t Is_Implemented()
        {
            return true;
        }
    };

}

namespace nkr { namespace array {

    constexpr count_t
        Default_Unit_Count()
    {
        return 128;
    }

    constexpr count_t
        Default_Min_Unit_Count()
    {
        return 1;
    }

    constexpr count_t
        Default_Max_Unit_Count(count_t min_unit_count)
    {
        return min_unit_count < 64 ? Default_Unit_Count() : math::Round_To_Power_Of_2(min_unit_count * 4);
    }

}}

// to be deleted
namespace nkr {

    template <typename array_p>
    concept any_array_tr =
        array_i<array_p>;

    #undef array
    nkr_DEFINE_CONTAINER_TRAITS(array, unit_t);
    #define array array_

}
//
