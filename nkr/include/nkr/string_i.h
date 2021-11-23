/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/macros.h"
#include "nkr/math.h"
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

namespace nkr { namespace string {

    constexpr count_t
        Default_Point_Count()
    {
        return 128;
    }

    constexpr count_t
        Default_Min_Point_Count()
    {
        return 1;
    }

    constexpr count_t
        Default_Max_Point_Count(count_t min_point_count)
    {
        return min_point_count < 64 ? Default_Point_Count() : math::Round_To_Power_Of_2(min_point_count * 4);
    }

    template <string_i string_p>
    inline count_t
        Offset_To_New_Mid_Point(const string_p& string,
                                const is_any_tr<typename string_p::unit_t> auto* c_string,
                                count_t unit_length)
    {
        using string_t = std::remove_reference_t<decltype(string)>;
        using charcoder_t = string_t::charcoder_t;
        using unit_t = string_t::unit_t;

        if constexpr (charcoder_t::Max_Unit_Count() > 1) {
            if (unit_length > 0) {
                const count_t string_unit_count = string.Unit_Count();
                if (string_unit_count > 1) {
                    charcoder_t charcoder;
                    const count_t last_point_unit_count = charcoder.Read_Reverse(&string.Unit(string_unit_count - 1), &string.Unit(0));
                    const count_t difference = charcoder_t::Max_Unit_Count() - last_point_unit_count;
                    nkr_ASSERT_THAT(last_point_unit_count <= charcoder_t::Max_Unit_Count());
                    if (difference > 0) {
                        array::stack_t<unit_t, charcoder_t::Max_Unit_Count()> last_point_units;
                        for (index_t idx = string_unit_count - 1 - last_point_unit_count, end = string_unit_count - 1; idx < end; idx += 1) {
                            last_point_units.Push(string.Unit(idx)).Ignore_Error();
                        }
                        for (index_t idx = 0, end = difference > unit_length ? unit_length : difference; idx < end; idx += 1) {
                            last_point_units.Push(c_string[idx]).Ignore_Error();
                            if (charcoder.Read_Forward(&last_point_units[0]) == last_point_unit_count) {
                                return 0;
                            }
                        }
                        return last_point_units.Count() - last_point_unit_count;
                    } else {
                        return 0;
                    }
                } else {
                    return 0;
                }
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }

}}

// to be deleted
namespace nkr {

    template <typename string_p>
    concept any_string_tr =
        string_i<string_p>;

    nkr_DEFINE_CONTAINER_TRAITS(string, charcoder_t);

}
//
