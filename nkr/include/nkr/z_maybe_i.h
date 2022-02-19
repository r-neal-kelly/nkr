/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_intrinsics.h"
#include "nkr/z_none_i.h"
#include "nkr/z_utils.h"

namespace nkr { namespace $maybe_i {

    template <typename type_p>
    concept assignment_i = requires(std::remove_cv_t<type_p> instance,
                                    const std::remove_cv_t<type_p> const_instance,
                                    volatile std::remove_cv_t<type_p> volatile_instance,
                                    const volatile std::remove_cv_t<type_p> const_volatile_instance)
    {
        std::remove_cv_t<type_p>();

        std::remove_cv_t<type_p>(instance);
        std::remove_cv_t<type_p>(const_instance);
        std::remove_cv_t<type_p>(volatile_instance);
        std::remove_cv_t<type_p>(const_volatile_instance);

        std::remove_cv_t<type_p>(nkr::Move(instance));
        std::remove_cv_t<type_p>(nkr::Move(volatile_instance));

        { instance.operator =(instance) }                               -> is_tr<std::remove_cv_t<type_p>&>;
        { instance.operator =(const_instance) }                         -> is_tr<std::remove_cv_t<type_p>&>;
        { instance.operator =(volatile_instance) }                      -> is_tr<std::remove_cv_t<type_p>&>;
        { instance.operator =(const_volatile_instance) }                -> is_tr<std::remove_cv_t<type_p>&>;

        { volatile_instance.operator =(instance) }                      -> is_tr<volatile std::remove_cv_t<type_p>&>;
        { volatile_instance.operator =(const_instance) }                -> is_tr<volatile std::remove_cv_t<type_p>&>;
        { volatile_instance.operator =(volatile_instance) }             -> is_tr<volatile std::remove_cv_t<type_p>&>;
        { volatile_instance.operator =(const_volatile_instance) }       -> is_tr<volatile std::remove_cv_t<type_p>&>;

        { instance.operator =(nkr::Move(instance)) }                    -> is_tr<std::remove_cv_t<type_p>&>;
        { instance.operator =(nkr::Move(volatile_instance)) }           -> is_tr<std::remove_cv_t<type_p>&>;

        { volatile_instance.operator =(nkr::Move(instance)) }           -> is_tr<volatile std::remove_cv_t<type_p>&>;
        { volatile_instance.operator =(nkr::Move(volatile_instance)) }  -> is_tr<volatile std::remove_cv_t<type_p>&>;
    };

}}

namespace nkr {

    /// @nosubgrouping
    /// @ingroup _7752ee81_def2_4386_b164_bc31f29ce7b8
    /// @copydoc 
    template <typename type_p>
    concept maybe_i =
        none_i<type_p> &&
        $maybe_i::assignment_i<type_p>;

}
