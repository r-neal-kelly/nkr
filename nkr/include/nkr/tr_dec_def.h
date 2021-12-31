/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

namespace nkr { namespace $tr {

    template <
        typename subject_p,
        typename operator_p
    > inline constexpr boolean::cpp_t
        TR0()
        noexcept
    {
        using subject_t = subject_p;

        if constexpr (cpp::is_tr<operator_p, any_tg>)                           return true;
        else if constexpr (cpp::is_tr<operator_p, any_qualified_tg>)            return cpp::any_qualified_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, any_non_qualified_tg>)        return cpp::any_non_qualified_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, any_const_tg>)                return cpp::any_const_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, any_non_const_tg>)            return cpp::any_non_const_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, any_volatile_tg>)             return cpp::any_volatile_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, any_non_volatile_tg>)         return cpp::any_non_volatile_tr<subject_t>;

        else if constexpr (cpp::is_tr<operator_p, not_any_tg>)                  return false;
        else if constexpr (cpp::is_tr<operator_p, not_any_qualified_tg>)        return !cpp::any_qualified_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, not_any_non_qualified_tg>)    return !cpp::any_non_qualified_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, not_any_const_tg>)            return !cpp::any_const_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, not_any_non_const_tg>)        return !cpp::any_non_const_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, not_any_volatile_tg>)         return !cpp::any_volatile_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, not_any_non_volatile_tg>)     return !cpp::any_non_volatile_tr<subject_t>;

        else if constexpr (cpp::is_tr<operator_p, just_tg>)                     return true;
        else if constexpr (cpp::is_tr<operator_p, just_non_qualified_tg>)       return cpp::just_non_qualified_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, just_const_tg>)               return cpp::just_const_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, just_volatile_tg>)            return cpp::just_volatile_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, just_const_volatile_tg>)      return cpp::just_const_volatile_tr<subject_t>;

        else if constexpr (cpp::is_tr<operator_p, just_not_tg>)                 return false;
        else if constexpr (cpp::is_tr<operator_p, just_not_non_qualified_tg>)   return !cpp::just_non_qualified_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, just_not_const_tg>)           return !cpp::just_const_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, just_not_volatile_tg>)        return !cpp::just_volatile_tr<subject_t>;
        else if constexpr (cpp::is_tr<operator_p, just_not_const_volatile_tg>)  return !cpp::just_const_volatile_tr<subject_t>;

        else                                                                    static_assert(false, "undefined or invalid operator");
    }

    template <
        typename subject_p,
        typename operator_p, typename operand_p
    > inline constexpr boolean::cpp_t
        TR1()
        noexcept
    {
        static_assert(generic::implementing::interface::type_tr<operand_p>);

        using subject_t = subject_p;
        using object_t = operand_p;

        if constexpr (to_operator_tr<operator_p>) {
            if constexpr (not_operator_tr<operator_p>) {
                return !(TR0<subject_t, typename operator_p::base_tg::is_tg>() && cpp::to_tr<subject_t, object_t>);
            } else {
                return TR0<subject_t, typename operator_p::base_tg>() && cpp::to_tr<subject_t, object_t>;
            }
        } else {
            if constexpr (type_i<object_t>::template Is_Any<cpp::just_non_qualified_t<subject_t>>()) {
                if constexpr (cpp::is_tr<operator_p, just_tg>) {
                    return cpp::is_tr<object_t, cpp::same_qualification_as_t<object_t, subject_p>>;
                } else if constexpr (cpp::is_tr<operator_p, just_not_tg>) {
                    return !cpp::is_tr<object_t, cpp::same_qualification_as_t<object_t, subject_p>>;
                } else {
                    return TR0<subject_t, operator_p>();
                }
            } else {
                return not_operator_tr<operator_p>;
            }
        }
    }

    template <
        typename subject_p,
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > inline constexpr boolean::cpp_t
        TR2()
        noexcept
    {
        static_assert(generic::implementing::interface::template_ttr<operand_p>);
        static_assert(generic::implementing::interface::type_tr<of_operand_p>);

        using subject_t = subject_p;
        using of_subject_t = access_or_not_t<typename type_i<subject_t>::of_t, subject_t, access_operator_tr<of_operator_p>>;
        using object_t = template_i<operand_p>::template of_t<of_operand_p>;
        using of_object_t = of_operand_p;

        if constexpr (not_operator_tr<operator_p>) {
            return
                !(TR1<subject_t, typename operator_p::is_tg, object_t>() &&
                  TR1<of_subject_t, typename of_operator_p::base_tg, of_object_t>());
        } else {
            return
                TR1<subject_t, operator_p, object_t>() &&
                TR1<of_subject_t, typename of_operator_p::base_tg, of_object_t>();
        }
    }

    template <
        typename subject_p,
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > inline constexpr boolean::cpp_t
        TR3()
        noexcept
    {
        static_assert(generic::implementing::interface::template_ttr<operand_p>);
        static_assert(generic::implementing::interface::template_ttr<of_operand_p>);
        static_assert(generic::implementing::interface::type_tr<of_of_operand_p>);

        using subject_t = subject_p;
        using of_subject_t = access_or_not_t<typename type_i<subject_t>::of_t, subject_t, access_operator_tr<of_of_operator_p>>;
        using of_of_subject_t = access_or_not_t<typename type_i<of_subject_t>::of_t, of_subject_t, access_operator_tr<of_of_operator_p>>;
        using of_object_t = template_i<of_operand_p>::template of_t<of_of_operand_p>;
        using of_of_object_t = of_of_operand_p;

        if constexpr (not_operator_tr<operator_p>) {
            return
                !(TR2<subject_t, typename operator_p::is_tg, operand_p, of_operator_p, of_object_t>() &&
                  TR1<of_of_subject_t, typename of_of_operator_p::base_tg, of_of_object_t>());
        } else {
            return
                TR2<subject_t, operator_p, operand_p, of_operator_p, of_object_t>() &&
                TR1<of_of_subject_t, typename of_of_operator_p::base_tg, of_of_object_t>();
        }
    }

}}
