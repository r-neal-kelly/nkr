/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/macros.h"
#include "nkr/maybe_t.h"
#include "nkr/traits.h"
#include "nkr/utils.h"

#include "nkr/allocator_err.h"

#include "nkr/charcoder_i.h"

namespace nkr::string {};

namespace nkr { namespace string {

    using point_t   = charcoder::point_t;

}}

namespace nkr {

    template <typename string_p>
    concept string_i = requires(std::remove_cv_t<string_p> string,
                                const std::remove_cv_t<string_p> const_string,
                                volatile std::remove_cv_t<string_p> volatile_string,
                                const volatile std::remove_cv_t<string_p> const_volatile_string,
                                
                                count_t unit_capacity_including_terminus)
    {
        typename string_p::charcoder_t;
        typename string_p::array_t; // we need to verify that the array_t satisfies array_i, but we have to move the code around a bit first
        //typename string_p::iterator_t;

        { string.Has_Memory() }                                             -> is_tr<bool_t>;
        { const_string.Has_Memory() }                                       -> is_tr<bool_t>;
        { volatile_string.Has_Memory() }                                    -> is_tr<bool_t>;
        { const_volatile_string.Has_Memory() }                              -> is_tr<bool_t>;
        { string.Has_Terminus() }                                           -> is_tr<bool_t>;
        { const_string.Has_Terminus() }                                     -> is_tr<bool_t>;
        { volatile_string.Has_Terminus() }                                  -> is_tr<bool_t>;
        { const_volatile_string.Has_Terminus() }                            -> is_tr<bool_t>;

        { string.Unit_Count() }                                             -> is_tr<count_t>;
        { const_string.Unit_Count() }                                       -> is_tr<count_t>;
        { volatile_string.Unit_Count() }                                    -> is_tr<count_t>;
        { const_volatile_string.Unit_Count() }                              -> is_tr<count_t>;
        { string.Unit_Length() }                                            -> is_tr<count_t>;
        { const_string.Unit_Length() }                                      -> is_tr<count_t>;
        { volatile_string.Unit_Length() }                                   -> is_tr<count_t>;
        { const_volatile_string.Unit_Length() }                             -> is_tr<count_t>;

        { string.Point_Count() }                                            -> is_tr<count_t>;
        { const_string.Point_Count() }                                      -> is_tr<count_t>;
        { volatile_string.Point_Count() }                                   -> is_tr<count_t>;
        { const_volatile_string.Point_Count() }                             -> is_tr<count_t>;
        { string.Point_Length() }                                           -> is_tr<count_t>;
        { const_string.Point_Length() }                                     -> is_tr<count_t>;
        { volatile_string.Point_Length() }                                  -> is_tr<count_t>;
        { const_volatile_string.Point_Length() }                            -> is_tr<count_t>;

        { string.Unit_Capacity() }                                          -> is_tr<count_t>;
        { const_string.Unit_Capacity() }                                    -> is_tr<count_t>;
        { volatile_string.Unit_Capacity() }                                 -> is_tr<count_t>;
        { const_volatile_string.Unit_Capacity() }                           -> is_tr<count_t>;
        { string.Unit_Capacity(unit_capacity_including_terminus) }          -> is_tr<maybe_t<allocator_err>>;
        { volatile_string.Unit_Capacity(unit_capacity_including_terminus) } -> is_tr<maybe_t<allocator_err>>;

        // need to add more constraints.
    };

    template <typename string_p>
    concept any_string_tr =
        string_i<string_p>;

    nkr_DEFINE_CONTAINER_TRAITS(string, unit_t);

}
