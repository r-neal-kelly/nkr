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

namespace nkr { namespace $tr1_t {

    template <typename operator_p, tr1<not_any_tg, nkr::tuple::types_tg> operand_p>
    template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operand_t<operator_p, operand_p>::OR()
        noexcept
    {
        if constexpr (subjects_p::Count() == 1) {
            return tr1<typename subjects_p::head_t, operator_p, operand_p>;
        } else {
            if constexpr (tr1<typename subjects_p::head_t, operator_p, operand_p>) {
                return true;
            } else {
                return OR<typename subjects_p::tail_t>();
            }
        }
    }

    template <typename operator_p, tr1<not_any_tg, nkr::tuple::types_tg> operand_p>
    template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operand_t<operator_p, operand_p>::OR()
        noexcept
    {
        return OR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <typename operator_p, tr1<not_any_tg, nkr::tuple::types_tg> operand_p>
    template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operand_t<operator_p, operand_p>::AND()
        noexcept
    {
        if constexpr (subjects_p::Count() == 1) {
            return tr1<typename subjects_p::head_t, operator_p, operand_p>;
        } else {
            if constexpr (tr1<typename subjects_p::head_t, operator_p, operand_p>) {
                return AND<typename subjects_p::tail_t>();
            } else {
                return false;
            }
        }
    }

    template <typename operator_p, tr1<not_any_tg, nkr::tuple::types_tg> operand_p>
    template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operand_t<operator_p, operand_p>::AND()
        noexcept
    {
        return AND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <typename operator_p, tr1<not_any_tg, nkr::tuple::types_tg> operand_p>
    template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operand_t<operator_p, operand_p>::XOR()
        noexcept
    {
        return XOR<nkr::boolean::cpp_c<false>, subjects_p>();
    }

    template <typename operator_p, tr1<not_any_tg, nkr::tuple::types_tg> operand_p>
    template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operand_t<operator_p, operand_p>::XOR()
        noexcept
    {
        return XOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <typename operator_p, tr1<not_any_tg, nkr::tuple::types_tg> operand_p>
    template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operand_t<operator_p, operand_p>::NOR()
        noexcept
    {
        return !OR<subjects_p>();
    }

    template <typename operator_p, tr1<not_any_tg, nkr::tuple::types_tg> operand_p>
    template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operand_t<operator_p, operand_p>::NOR()
        noexcept
    {
        return NOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <typename operator_p, tr1<not_any_tg, nkr::tuple::types_tg> operand_p>
    template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operand_t<operator_p, operand_p>::NAND()
        noexcept
    {
        return !AND<subjects_p>();
    }

    template <typename operator_p, tr1<not_any_tg, nkr::tuple::types_tg> operand_p>
    template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operand_t<operator_p, operand_p>::NAND()
        noexcept
    {
        return NAND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <typename operator_p, tr1<not_any_tg, nkr::tuple::types_tg> operand_p>
    template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operand_t<operator_p, operand_p>::XNOR()
        noexcept
    {
        return !XOR<subjects_p>();
    }

    template <typename operator_p, tr1<not_any_tg, nkr::tuple::types_tg> operand_p>
    template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operand_t<operator_p, operand_p>::XNOR()
        noexcept
    {
        return XNOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <typename operator_p, tr1<not_any_tg, nkr::tuple::types_tg> operand_p>
    template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operand_t<operator_p, operand_p>::Any()
        noexcept
    {
        return OR<subjects_p>();
    }

    template <typename operator_p, tr1<not_any_tg, nkr::tuple::types_tg> operand_p>
    template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operand_t<operator_p, operand_p>::Any()
        noexcept
    {
        return Any<nkr::tuple::types_t<subjects_p...>>();
    }

    template <typename operator_p, tr1<not_any_tg, nkr::tuple::types_tg> operand_p>
    template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operand_t<operator_p, operand_p>::Every()
        noexcept
    {
        return AND<subjects_p>();
    }

    template <typename operator_p, tr1<not_any_tg, nkr::tuple::types_tg> operand_p>
    template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operand_t<operator_p, operand_p>::Every()
        noexcept
    {
        return Every<nkr::tuple::types_t<subjects_p...>>();
    }

    template <typename operator_p, tr1<not_any_tg, nkr::tuple::types_tg> operand_p>
    template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operand_t<operator_p, operand_p>::One()
        noexcept
    {
        return XOR<subjects_p>();
    }

    template <typename operator_p, tr1<not_any_tg, nkr::tuple::types_tg> operand_p>
    template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operand_t<operator_p, operand_p>::One()
        noexcept
    {
        return One<nkr::tuple::types_t<subjects_p...>>();
    }

    template <typename operator_p, tr1<not_any_tg, nkr::tuple::types_tg> operand_p>
    template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operand_t<operator_p, operand_p>::None()
        noexcept
    {
        return NOR<subjects_p>();
    }

    template <typename operator_p, tr1<not_any_tg, nkr::tuple::types_tg> operand_p>
    template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operand_t<operator_p, operand_p>::None()
        noexcept
    {
        return None<nkr::tuple::types_t<subjects_p...>>();
    }

    template <typename operator_p, tr1<not_any_tg, nkr::tuple::types_tg> operand_p>
    template <nkr::boolean::cpp_ctr state_p, tr1<any_tg, nkr::tuple::types_tg> subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operand_t<operator_p, operand_p>::XOR()
        noexcept
    {
        if constexpr (subjects_p::Count() == 1) {
            if constexpr (state_p::Value()) {
                return !tr1<typename subjects_p::head_t, operator_p, operand_p>;
            } else {
                return tr1<typename subjects_p::head_t, operator_p, operand_p>;
            }
        } else {
            if constexpr (state_p::Value()) {
                if constexpr (tr1<typename subjects_p::head_t, operator_p, operand_p>) {
                    return false;
                } else {
                    return XOR<nkr::boolean::cpp_c<true>, typename subjects_p::tail_t>();
                }
            } else {
                if constexpr (tr1<typename subjects_p::head_t, operator_p, operand_p>) {
                    return XOR<nkr::boolean::cpp_c<true>, typename subjects_p::tail_t>();
                } else {
                    return XOR<nkr::boolean::cpp_c<false>, typename subjects_p::tail_t>();
                }
            }
        }
    }

}}

namespace nkr { namespace $tr1_t {

    template <typename operator_p, tr1<any_tg, nkr::tuple::types_tg> operands_p>
    template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operands_t<operator_p, operands_p>::OR()
        noexcept
    {
        if constexpr (operands_p::Count() == 1) {
            return operand_t<operator_p, operands_head_t>::template OR<subjects_p>();
        } else {
            if constexpr (!operand_t<operator_p, operands_head_t>::template OR<subjects_p>()) {
                return false;
            } else {
                return operands_t<operator_p, operands_tail_t>::template OR<subjects_p>();
            }
        }
    }

    template <typename operator_p, tr1<any_tg, nkr::tuple::types_tg> operands_p>
    template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operands_t<operator_p, operands_p>::OR()
        noexcept
    {
        return OR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <typename operator_p, tr1<any_tg, nkr::tuple::types_tg> operands_p>
    template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operands_t<operator_p, operands_p>::AND()
        noexcept
    {
        if constexpr (operands_p::Count() == 1) {
            return operand_t<operator_p, operands_head_t>::template AND<subjects_p>();
        } else {
            if constexpr (!operand_t<operator_p, operands_head_t>::template AND<subjects_p>()) {
                return false;
            } else {
                return operands_t<operator_p, operands_tail_t>::template AND<subjects_p>();
            }
        }
    }

    template <typename operator_p, tr1<any_tg, nkr::tuple::types_tg> operands_p>
    template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operands_t<operator_p, operands_p>::AND()
        noexcept
    {
        return AND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <typename operator_p, tr1<any_tg, nkr::tuple::types_tg> operands_p>
    template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operands_t<operator_p, operands_p>::XOR()
        noexcept
    {
        if constexpr (operands_p::Count() == 1) {
            return operand_t<operator_p, operands_head_t>::template XOR<subjects_p>();
        } else {
            if constexpr (!operand_t<operator_p, operands_head_t>::template XOR<subjects_p>()) {
                return false;
            } else {
                return operands_t<operator_p, operands_tail_t>::template XOR<subjects_p>();
            }
        }
    }

    template <typename operator_p, tr1<any_tg, nkr::tuple::types_tg> operands_p>
    template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operands_t<operator_p, operands_p>::XOR()
        noexcept
    {
        return XOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <typename operator_p, tr1<any_tg, nkr::tuple::types_tg> operands_p>
    template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operands_t<operator_p, operands_p>::NOR()
        noexcept
    {
        if constexpr (operands_p::Count() == 1) {
            return operand_t<operator_p, operands_head_t>::template NOR<subjects_p>();
        } else {
            if constexpr (!operand_t<operator_p, operands_head_t>::template NOR<subjects_p>()) {
                return false;
            } else {
                return operands_t<operator_p, operands_tail_t>::template NOR<subjects_p>();
            }
        }
    }

    template <typename operator_p, tr1<any_tg, nkr::tuple::types_tg> operands_p>
    template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operands_t<operator_p, operands_p>::NOR()
        noexcept
    {
        return NOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <typename operator_p, tr1<any_tg, nkr::tuple::types_tg> operands_p>
    template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operands_t<operator_p, operands_p>::NAND()
        noexcept
    {
        if constexpr (operands_p::Count() == 1) {
            return operand_t<operator_p, operands_head_t>::template NAND<subjects_p>();
        } else {
            if constexpr (!operand_t<operator_p, operands_head_t>::template NAND<subjects_p>()) {
                return false;
            } else {
                return operands_t<operator_p, operands_tail_t>::template NAND<subjects_p>();
            }
        }
    }

    template <typename operator_p, tr1<any_tg, nkr::tuple::types_tg> operands_p>
    template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operands_t<operator_p, operands_p>::NAND()
        noexcept
    {
        return NAND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <typename operator_p, tr1<any_tg, nkr::tuple::types_tg> operands_p>
    template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operands_t<operator_p, operands_p>::XNOR()
        noexcept
    {
        if constexpr (operands_p::Count() == 1) {
            return operand_t<operator_p, operands_head_t>::template XNOR<subjects_p>();
        } else {
            if constexpr (!operand_t<operator_p, operands_head_t>::template XNOR<subjects_p>()) {
                return false;
            } else {
                return operands_t<operator_p, operands_tail_t>::template XNOR<subjects_p>();
            }
        }
    }

    template <typename operator_p, tr1<any_tg, nkr::tuple::types_tg> operands_p>
    template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operands_t<operator_p, operands_p>::XNOR()
        noexcept
    {
        return XNOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <typename operator_p, tr1<any_tg, nkr::tuple::types_tg> operands_p>
    template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operands_t<operator_p, operands_p>::Any()
        noexcept
    {
        return OR<subjects_p>();
    }

    template <typename operator_p, tr1<any_tg, nkr::tuple::types_tg> operands_p>
    template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operands_t<operator_p, operands_p>::Any()
        noexcept
    {
        return Any<nkr::tuple::types_t<subjects_p...>>();
    }

    template <typename operator_p, tr1<any_tg, nkr::tuple::types_tg> operands_p>
    template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operands_t<operator_p, operands_p>::Every()
        noexcept
    {
        return AND<subjects_p>();
    }

    template <typename operator_p, tr1<any_tg, nkr::tuple::types_tg> operands_p>
    template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operands_t<operator_p, operands_p>::Every()
        noexcept
    {
        return Every<nkr::tuple::types_t<subjects_p...>>();
    }

    template <typename operator_p, tr1<any_tg, nkr::tuple::types_tg> operands_p>
    template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operands_t<operator_p, operands_p>::One()
        noexcept
    {
        return XOR<subjects_p>();
    }

    template <typename operator_p, tr1<any_tg, nkr::tuple::types_tg> operands_p>
    template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operands_t<operator_p, operands_p>::One()
        noexcept
    {
        return One<nkr::tuple::types_t<subjects_p...>>();
    }

    template <typename operator_p, tr1<any_tg, nkr::tuple::types_tg> operands_p>
    template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operands_t<operator_p, operands_p>::None()
        noexcept
    {
        return NOR<subjects_p>();
    }

    template <typename operator_p, tr1<any_tg, nkr::tuple::types_tg> operands_p>
    template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
    inline constexpr nkr::boolean::cpp_t
        operands_t<operator_p, operands_p>::None()
        noexcept
    {
        return None<nkr::tuple::types_t<subjects_p...>>();
    }

}}

namespace nkr { namespace $tr2_t {

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, tr1<not_any_tg, nkr::tuple::types_tg> of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        operand_of_operand_sp<operator_p, operand_p, of_operator_p, of_operand_p>::OR()
        noexcept
    {
        if constexpr (subjects_p::Count() == 1) {
            return tr2<typename subjects_p::head_t, operator_p, operand_p, of_operator_p, of_operand_p>;
        } else {
            if constexpr (tr2<typename subjects_p::head_t, operator_p, operand_p, of_operator_p, of_operand_p>) {
                return true;
            } else {
                return OR<typename subjects_p::tail_t>();
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, tr1<not_any_tg, nkr::tuple::types_tg> of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        operand_of_operand_sp<operator_p, operand_p, of_operator_p, of_operand_p>::OR()
        noexcept
    {
        return OR<nkr::tuple::types_t<subjects_p...>>();
    }

}}

namespace nkr { namespace $tr2_t {

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, tr1<any_tg, nkr::tuple::types_tg> of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        operand_of_operands_sp<operator_p, operand_p, of_operator_p, of_operands_p>::OR()
        noexcept
    {
        if constexpr (of_operands_p::Count() == 1) {
            return operand_of_operand_sp<operator_p, operand_p, of_operator_p, of_operands_head_t>::template OR<subjects_p>();
        } else {
            if constexpr (!operand_of_operand_sp<operator_p, operand_p, of_operator_p, of_operands_head_t>::template OR<subjects_p>()) {
                return false;
            } else {
                return operand_of_operands_sp<operator_p, operand_p, of_operator_p, of_operands_tail_t>::template OR<subjects_p>();
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, tr1<any_tg, nkr::tuple::types_tg> of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        operand_of_operands_sp<operator_p, operand_p, of_operator_p, of_operands_p>::OR()
        noexcept
    {
        return OR<nkr::tuple::types_t<subjects_p...>>();
    }

}}

namespace nkr { namespace $tr2_t {

    template <
        typename operator_p, tr1<any_tg, nkr::tuple::templates_tg> operands_p,
        typename of_operator_p, tr1<not_any_tg, nkr::tuple::types_tg> of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        operands_of_operand_sp<operator_p, operands_p, of_operator_p, of_operand_p>::OR()
        noexcept
    {
        if constexpr (operands_p::Count() == 1) {
            return operand_of_operand_sp<operator_p, operands_p::template head_t, of_operator_p, of_operand_p>::template OR<subjects_p>();
        } else {
            if constexpr (!operand_of_operand_sp<operator_p, operands_p::template head_t, of_operator_p, of_operand_p>::template OR<subjects_p>()) {
                return false;
            } else {
                return operands_of_operand_sp<operator_p, typename operands_p::tail_t, of_operator_p, of_operand_p>::template OR<subjects_p>();
            }
        }
    }

    template <
        typename operator_p, tr1<any_tg, nkr::tuple::templates_tg> operands_p,
        typename of_operator_p, tr1<not_any_tg, nkr::tuple::types_tg> of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        operands_of_operand_sp<operator_p, operands_p, of_operator_p, of_operand_p>::OR()
        noexcept
    {
        return OR<nkr::tuple::types_t<subjects_p...>>();
    }

}}

namespace nkr { namespace $tr2_t {

    template <
        typename operator_p, tr1<any_tg, nkr::tuple::templates_tg> operands_p,
        typename of_operator_p, tr1<any_tg, nkr::tuple::types_tg> of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        operands_of_operands_sp<operator_p, operands_p, of_operator_p, of_operands_p>::OR()
        noexcept
    {
        if constexpr (operands_p::Count() == 1) {
            return operand_of_operands_sp<operator_p, operands_p::template head_t, of_operator_p, of_operands_p>::template OR<subjects_p>();
        } else {
            if constexpr (!operand_of_operands_sp<operator_p, operands_p::template head_t, of_operator_p, of_operands_p>::template OR<subjects_p>()) {
                return false;
            } else {
                return operands_of_operands_sp<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p>::template OR<subjects_p>();
            }
        }
    }

    template <
        typename operator_p, tr1<any_tg, nkr::tuple::templates_tg> operands_p,
        typename of_operator_p, tr1<any_tg, nkr::tuple::types_tg> of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        operands_of_operands_sp<operator_p, operands_p, of_operator_p, of_operands_p>::OR()
        noexcept
    {
        return OR<nkr::tuple::types_t<subjects_p...>>();
    }

}}
