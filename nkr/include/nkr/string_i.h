/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/macros.h"
#include "nkr/maybe_t.h"
#include "nkr/some_t.h"
#include "nkr/traits.h"
#include "nkr/utils.h"

#include "nkr/allocator_err.h"

#include "nkr/charcoder_i.h"

namespace nkr::string {};

namespace nkr { namespace string {

    using point_t   = charcoder::point_t;

}}

namespace nkr { namespace $string_i {

    template <typename string_p>
    concept aliases_i =
        is_tr<typename string_p::charcoder_t, std::remove_cv_t<typename string_p::qualified_charcoder_t>> &&
        is_tr<typename string_p::unit_t, same_qualification_as_t<typename string_p::charcoder_t::unit_t, typename string_p::qualified_charcoder_t>> &&
        requires()
    {
        typename string_p::charcoder_t;
        typename string_p::qualified_charcoder_t;
        typename string_p::unit_t;
        typename string_p::array_t;
    };

    template <typename string_p>
    concept static_constexpr_functions_i =
        requires()
    {
        { string_p::Has_Guaranteed_Terminus() } -> is_tr<c_bool_t>;
    };

    template <typename string_p>
    concept static_functions_i =
        requires()
    {
        { string_p::Empty_C_String() }  -> is_tr<const typename string_p::unit_t*>;
    };

    template <typename string_p>
    concept shared_methods_i =
        requires(std::remove_cv_t<string_p> string,
                 const std::remove_cv_t<string_p> const_string,
                 volatile std::remove_cv_t<string_p> volatile_string,
                 const volatile std::remove_cv_t<string_p> const_volatile_string,

                 index_t unit_index)
    {
        { string.Has_Memory() }                     -> is_tr<bool_t>;
        { const_string.Has_Memory() }               -> is_tr<bool_t>;
        { volatile_string.Has_Memory() }            -> is_tr<bool_t>;
        { const_volatile_string.Has_Memory() }      -> is_tr<bool_t>;
        { string.Has_Terminus() }                   -> is_tr<bool_t>;
        { const_string.Has_Terminus() }             -> is_tr<bool_t>;
        { volatile_string.Has_Terminus() }          -> is_tr<bool_t>;
        { const_volatile_string.Has_Terminus() }    -> is_tr<bool_t>;

        { string.Unit_Count() }                     -> is_tr<count_t>;
        { const_string.Unit_Count() }               -> is_tr<count_t>;
        { volatile_string.Unit_Count() }            -> is_tr<count_t>;
        { const_volatile_string.Unit_Count() }      -> is_tr<count_t>;
        { string.Unit_Length() }                    -> is_tr<count_t>;
        { const_string.Unit_Length() }              -> is_tr<count_t>;
        { volatile_string.Unit_Length() }           -> is_tr<count_t>;
        { const_volatile_string.Unit_Length() }     -> is_tr<count_t>;

        { string.Point_Count() }                    -> is_tr<count_t>;
        { const_string.Point_Count() }              -> is_tr<count_t>;
        { volatile_string.Point_Count() }           -> is_tr<count_t>;
        { const_volatile_string.Point_Count() }     -> is_tr<count_t>;
        { string.Point_Length() }                   -> is_tr<count_t>;
        { const_string.Point_Length() }             -> is_tr<count_t>;
        { volatile_string.Point_Length() }          -> is_tr<count_t>;
        { const_volatile_string.Point_Length() }    -> is_tr<count_t>;

        { string.C_String() }                       -> is_tr<some_t<const typename string_p::unit_t*>>;
        { const_string.C_String() }                 -> is_tr<some_t<const typename string_p::unit_t*>>;
        { volatile_string.C_String() }              -> is_tr<some_t<const volatile typename string_p::unit_t*>>;
        { const_volatile_string.C_String() }        -> is_tr<some_t<const volatile typename string_p::unit_t*>>;

        { string.Unit(unit_index) }                 -> is_tr<typename string_p::unit_t&>;
        { const_string.Unit(unit_index) }           -> is_tr<const typename string_p::unit_t&>;
        { volatile_string.Unit(unit_index) }        -> is_tr<volatile typename string_p::unit_t&>;
        { const_volatile_string.Unit(unit_index) }  -> is_tr<const volatile typename string_p::unit_t&>;
    };

    template <typename string_p>
    concept aggregate_methods_i =
        requires(std::remove_cv_t<string_p> string,
                 const std::remove_cv_t<string_p> const_string,
                 volatile std::remove_cv_t<string_p> volatile_string,
                 const volatile std::remove_cv_t<string_p> const_volatile_string,

                 count_t unit_capacity_including_terminus)
    {
        { string.Unit_Capacity() }                                          -> is_tr<count_t>;
        { const_string.Unit_Capacity() }                                    -> is_tr<count_t>;
        { volatile_string.Unit_Capacity() }                                 -> is_tr<count_t>;
        { const_volatile_string.Unit_Capacity() }                           -> is_tr<count_t>;
        { string.Unit_Capacity(unit_capacity_including_terminus) }          -> is_tr<maybe_t<allocator_err>>;
        { volatile_string.Unit_Capacity(unit_capacity_including_terminus) } -> is_tr<maybe_t<allocator_err>>;
    };

}}

namespace nkr {

    template <typename string_p>
    concept string_i =
        $string_i::aliases_i<string_p> &&
        $string_i::static_constexpr_functions_i<string_p> &&
        $string_i::static_functions_i<string_p> &&
        $string_i::shared_methods_i<string_p>;

    template <typename string_p>
    concept aggregate_string_i =
        string_i<string_p> &&
        $string_i::aggregate_methods_i<string_p>;

    template <typename string_p>
    concept non_aggregate_string_i =
        string_i<string_p> &&
        !$string_i::aggregate_methods_i<string_p>;

}

namespace nkr {

    struct string_tg {};
    template <>
    class type_traits_i<string_tg>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t Is_Any()
        {
            return string_i<other_p>;
        }
    };

    struct aggregate_string_tg {};
    template <>
    class type_traits_i<aggregate_string_tg>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t Is_Any()
        {
            return aggregate_string_i<other_p>;
        }
    };

    struct non_aggregate_string_tg {};
    template <>
    class type_traits_i<non_aggregate_string_tg>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t Is_Any()
        {
            return non_aggregate_string_i<other_p>;
        }
    };

}

// to be deleted
namespace nkr {

    template <typename string_p>
    concept any_string_tr =
        string_i<string_p>;

    nkr_DEFINE_CONTAINER_TRAITS(string, charcoder_t);

}
//
