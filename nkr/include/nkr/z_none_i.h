/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/z_bool_t.h"
#include "nkr/z_intrinsics.h"
#include "nkr/z_none_t.h"

namespace nkr { namespace $none_i {

    template <typename type_p>
    concept assignment_i = requires(std::remove_cv_t<type_p> instance,
                                    const std::remove_cv_t<type_p> const_instance,
                                    volatile std::remove_cv_t<type_p> volatile_instance,
                                    const volatile std::remove_cv_t<type_p> const_volatile_instance)
    {
        std::remove_cv_t<type_p>(none_t());

        { instance.operator =(none_t()) }           -> is_or_is_base_lvalue_reference_of_tr<std::remove_cv_t<type_p>>;
        { volatile_instance.operator =(none_t()) }  -> is_or_is_base_lvalue_reference_of_tr<volatile std::remove_cv_t<type_p>>;
    };

    template <typename type_p>
    concept comparison_i = requires(std::remove_cv_t<type_p> instance,
                                    const std::remove_cv_t<type_p> const_instance,
                                    volatile std::remove_cv_t<type_p> volatile_instance,
                                    const volatile std::remove_cv_t<type_p> const_volatile_instance)
    {
        { instance.operator ==(none_t()) }                  -> is_tr<bool_t>;
        { const_instance.operator ==(none_t()) }            -> is_tr<bool_t>;
        { volatile_instance.operator ==(none_t()) }         -> is_tr<bool_t>;
        { const_volatile_instance.operator ==(none_t()) }   -> is_tr<bool_t>;

        { instance.operator !=(none_t()) }                  -> is_tr<bool_t>;
        { const_instance.operator !=(none_t()) }            -> is_tr<bool_t>;
        { volatile_instance.operator !=(none_t()) }         -> is_tr<bool_t>;
        { const_volatile_instance.operator !=(none_t()) }   -> is_tr<bool_t>;
    };

}}

namespace nkr {

    /// @nosubgrouping
    /// @ingroup _7752ee81_def2_4386_b164_bc31f29ce7b8
    /// @copydoc _9d52d2e1_c6dc_4dbb_ad58_01a219c6e510
    template <typename type_p>
    concept none_i =
        $none_i::assignment_i<type_p> &&
        $none_i::comparison_i<type_p>;

}
