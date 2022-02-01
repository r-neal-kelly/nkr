/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

namespace nkr { namespace $tr {

    template <typename type_p>
    concept any_operator_tr =
        (requires { typename type_p::operator_t; }) &&
        (requires { typename type_p::any_t; });

    template <typename type_p>
    concept just_operator_tr =
        (requires { typename type_p::operator_t; }) &&
        (requires { typename type_p::just_t; });

    template <typename type_p>
    concept not_operator_tr =
        (requires { typename type_p::operator_t; }) &&
        (requires { typename type_p::not_t; });

    template <typename type_p>
    concept of_operator_tr =
        (requires { typename type_p::operator_t; }) &&
        (requires { typename type_p::of_t; });

    template <typename type_p>
    concept to_operator_tr =
        (requires { typename type_p::operator_t; }) &&
        (requires { typename type_p::to_t; });

    template <typename type_p>
    concept access_operator_tr =
        (requires { typename type_p::operator_t; }) &&
        (requires { typename type_p::access_t; });

    template <typename type_p>
    concept OR_operator_tr =
        (requires { typename type_p::operator_t; }) &&
        (requires { typename type_p::OR_t; });

    template <typename type_p>
    concept AND_operator_tr =
        (requires { typename type_p::operator_t; }) &&
        (requires { typename type_p::AND_t; });

    template <typename type_p>
    concept XOR_operator_tr =
        (requires { typename type_p::operator_t; }) &&
        (requires { typename type_p::XOR_t; });

    template <typename type_p>
    concept NOR_operator_tr =
        (requires { typename type_p::operator_t; }) &&
        (requires { typename type_p::NOR_t; });

    template <typename type_p>
    concept NAND_operator_tr =
        (requires { typename type_p::operator_t; }) &&
        (requires { typename type_p::NAND_t; });

    template <typename type_p>
    concept XNOR_operator_tr =
        (requires { typename type_p::operator_t; }) &&
        (requires { typename type_p::XNOR_t; });

}}

namespace nkr { namespace $tr {

    template <typename type_p>
    class type_i :
        public nkr::interface::type_i<nkr::cpp::just_non_qualified_t<type_p>>
    {
    public:
    };

    template <nkr::cpp::array_tr type_p>
    class type_i<type_p> :
        public nkr::interface::type_i<type_p>
    {
    public:
    };

    template <template <typename ...> typename template_p>
    class template_i :
        public nkr::interface::template_i<template_p>
    {
    public:
    };

}}

namespace nkr { namespace $tr {

    template <typename child_p, typename parent_p, nkr::boolean::cpp_t do_access_p>
    class access_or_not_tmpl
    {
    public:
        using type_t    = child_p;
    };

    template <typename child_p, typename parent_p>
    class access_or_not_tmpl<child_p, parent_p, true>
    {
    public:
        using type_t    = nkr::cpp::access_qualification_of_t<child_p, parent_p>;
    };

    template <typename child_p, typename parent_p, nkr::boolean::cpp_t do_access_p>
    using access_or_not_t   = access_or_not_tmpl<child_p, parent_p, do_access_p>::type_t;

}}

namespace nkr { namespace $tr {

    template <nkr::tuple::types_tr expression_parts_p>
        requires (expression_parts_p::Count() == 1 || !(expression_parts_p::Count() & 1))
    class operators_tmpl;

    template <>
    class operators_tmpl<nkr::tuple::types_t<>>
    {
    public:
        using type_t    = nkr::tuple::types_t<>;
    };

    template <nkr::tuple::types_tr expression_parts_p>
        requires (expression_parts_p::Count() == 1)
    class operators_tmpl<expression_parts_p>
    {
    public:
        using type_t    = nkr::tuple::types_t<typename expression_parts_p::head_t>;
    };

    template <nkr::tuple::types_tr expression_parts_p>
        requires (expression_parts_p::Count() >= 2)
    class operators_tmpl<expression_parts_p>
    {
    public:
        using type_t    = operators_tmpl<
            typename expression_parts_p::tail_t::tail_t
        >::type_t::template push_front_t<typename expression_parts_p::head_t>;
    };

    template <nkr::tuple::types_tr expression_parts_p>
    using operators_t   = operators_tmpl<expression_parts_p>::type_t;

}}

namespace nkr { namespace $tr {

    template <typename subject_p, nkr::tuple::types_tr operators_p>
        requires (operators_p::Count() > 0)
    class subjects_tmpl;

    template <typename subject_p, nkr::tuple::types_tr operators_p>
        requires (operators_p::Count() == 1)
    class subjects_tmpl<subject_p, operators_p>
    {
    public:
        using type_t    = nkr::tuple::types_t<subject_p>;
    };

    template <typename subject_p, nkr::tuple::types_tr operators_p>
        requires (operators_p::Count() > 1)
    class subjects_tmpl<subject_p, operators_p>
    {
    private:
        using front_t   = subjects_tmpl<subject_p, typename operators_p::template take_t<nkr::positive::count_c<operators_p::Count() - 1>>>::type_t;
        using subject_t = front_t::template at_t<nkr::positive::index_c<front_t::Count() - 1>>::head_t;

    private:
        static constexpr nkr::boolean::cpp_t    is_access_operator =
            access_operator_tr<typename operators_p::template at_t<nkr::positive::index_c<operators_p::Count() - 1>>::head_t>;

    public:
        using type_t    = front_t::template push_back_t<
            access_or_not_t<typename type_i<subject_t>::of_t, subject_t, is_access_operator>
        >;
    };

    template <typename subject_p, nkr::tuple::types_tr operators_p>
    using subjects_t    = subjects_tmpl<subject_p, operators_p>::type_t;

}}

namespace nkr { namespace $tr {

    template <nkr::tuple::types_tr expression_parts_p>
        requires (expression_parts_p::Count() == 1 || !(expression_parts_p::Count() & 1))
    class objects_tmpl;

    template <nkr::tuple::types_tr expression_parts_p>
        requires (expression_parts_p::Count() == 1)
    class objects_tmpl<expression_parts_p>
    {
    public:
        using type_t    = nkr::tuple::types_t<>;
    };

    template <nkr::tuple::types_tr expression_parts_p>
        requires (expression_parts_p::Count() == 2)
    class objects_tmpl<expression_parts_p>
    {
    private:
        using object_t  = expression_parts_p::template at_t<nkr::positive::index_c<1>>::head_t;

    private:
        static_assert(nkr::ts_tr<object_t>);
        static_assert(object_t::Count() == 1);

    public:
        using type_t    = nkr::tuple::types_t<nkr::cpp::access_qualification_of_t<typename object_t::head_t, object_t>>;
    };

    template <nkr::tuple::types_tr expression_parts_p>
        requires (expression_parts_p::Count() > 2)
    class objects_tmpl<expression_parts_p>
    {
    private:
        using tail_t    = objects_tmpl<typename expression_parts_p::tail_t::tail_t>::type_t;
        using object_t  = expression_parts_p::template at_t<nkr::positive::index_c<1>>::head_t;

    private:
        static_assert(nkr::tts_tr<object_t>);
        static_assert(object_t::Count() == 1);

    public:
        using type_t    = tail_t::template push_front_t<
            nkr::cpp::access_qualification_of_t<typename template_i<object_t::template head_t>::template of_t<typename tail_t::head_t>, object_t>
        >;
    };

    template <nkr::tuple::types_tr expression_parts_p>
    using objects_t = objects_tmpl<expression_parts_p>::type_t;

}}

namespace nkr { namespace $tr {

    template <
        typename    subject_p,
        typename    operator_p
    > inline constexpr nkr::boolean::cpp_t
        Execute_Expression_0()
        noexcept
    {
        using subject_t = subject_p;

        if constexpr (nkr::cpp::is_tr<operator_p, any_tg>)                          return true;
        else if constexpr (nkr::cpp::is_tr<operator_p, any_qualified_tg>)           return nkr::cpp::any_qualified_tr<subject_t>;
        else if constexpr (nkr::cpp::is_tr<operator_p, any_non_qualified_tg>)       return nkr::cpp::any_non_qualified_tr<subject_t>;
        else if constexpr (nkr::cpp::is_tr<operator_p, any_const_tg>)               return nkr::cpp::any_const_tr<subject_t>;
        else if constexpr (nkr::cpp::is_tr<operator_p, any_non_const_tg>)           return nkr::cpp::any_non_const_tr<subject_t>;
        else if constexpr (nkr::cpp::is_tr<operator_p, any_volatile_tg>)            return nkr::cpp::any_volatile_tr<subject_t>;
        else if constexpr (nkr::cpp::is_tr<operator_p, any_non_volatile_tg>)        return nkr::cpp::any_non_volatile_tr<subject_t>;

        else if constexpr (nkr::cpp::is_tr<operator_p, not_any_tg>)                 return false;
        else if constexpr (nkr::cpp::is_tr<operator_p, not_any_qualified_tg>)       return !nkr::cpp::any_qualified_tr<subject_t>;
        else if constexpr (nkr::cpp::is_tr<operator_p, not_any_non_qualified_tg>)   return !nkr::cpp::any_non_qualified_tr<subject_t>;
        else if constexpr (nkr::cpp::is_tr<operator_p, not_any_const_tg>)           return !nkr::cpp::any_const_tr<subject_t>;
        else if constexpr (nkr::cpp::is_tr<operator_p, not_any_non_const_tg>)       return !nkr::cpp::any_non_const_tr<subject_t>;
        else if constexpr (nkr::cpp::is_tr<operator_p, not_any_volatile_tg>)        return !nkr::cpp::any_volatile_tr<subject_t>;
        else if constexpr (nkr::cpp::is_tr<operator_p, not_any_non_volatile_tg>)    return !nkr::cpp::any_non_volatile_tr<subject_t>;

        else if constexpr (nkr::cpp::is_tr<operator_p, just_tg>)                    return true;
        else if constexpr (nkr::cpp::is_tr<operator_p, just_non_qualified_tg>)      return nkr::cpp::just_non_qualified_tr<subject_t>;
        else if constexpr (nkr::cpp::is_tr<operator_p, just_const_tg>)              return nkr::cpp::just_const_tr<subject_t>;
        else if constexpr (nkr::cpp::is_tr<operator_p, just_volatile_tg>)           return nkr::cpp::just_volatile_tr<subject_t>;
        else if constexpr (nkr::cpp::is_tr<operator_p, just_const_volatile_tg>)     return nkr::cpp::just_const_volatile_tr<subject_t>;

        else if constexpr (nkr::cpp::is_tr<operator_p, just_not_tg>)                return false;
        else if constexpr (nkr::cpp::is_tr<operator_p, just_not_non_qualified_tg>)  return !nkr::cpp::just_non_qualified_tr<subject_t>;
        else if constexpr (nkr::cpp::is_tr<operator_p, just_not_const_tg>)          return !nkr::cpp::just_const_tr<subject_t>;
        else if constexpr (nkr::cpp::is_tr<operator_p, just_not_volatile_tg>)       return !nkr::cpp::just_volatile_tr<subject_t>;
        else if constexpr (nkr::cpp::is_tr<operator_p, just_not_const_volatile_tg>) return !nkr::cpp::just_const_volatile_tr<subject_t>;

        else                                                                        static_assert(false, "Undefined or invalid operator.");
    }

    template <
        typename    subject_p,
        typename    operator_p,
        typename    operand_p
    > inline constexpr nkr::boolean::cpp_t
        Execute_Expression_1()
        noexcept
    {
        if constexpr (nkr::cpp::array_tr<operand_p>) {
            static_assert(nkr::generic::implementing::interface::type_tr<operand_p>);
        } else {
            static_assert(nkr::generic::implementing::interface::type_tr<nkr::cpp::just_non_qualified_t<operand_p>>);
        }

        using subject_t = subject_p;
        using object_t = operand_p;

        if constexpr (to_operator_tr<operator_p>) {
            if constexpr (not_operator_tr<operator_p>) {
                return !(Execute_Expression_0<subject_t, typename operator_p::non_to_tg::is_tg>() && nkr::cpp::to_tr<subject_t, object_t>);
            } else {
                return Execute_Expression_0<subject_t, typename operator_p::non_to_tg>() && nkr::cpp::to_tr<subject_t, object_t>;
            }
        } else {
            if constexpr (type_i<object_t>::template Is_Any<nkr::cpp::just_non_qualified_t<subject_t>>()) {
                if constexpr (nkr::cpp::is_tr<operator_p, just_tg>) {
                    return nkr::cpp::is_tr<object_t, nkr::cpp::same_qualification_as_t<object_t, subject_p>>;
                } else if constexpr (nkr::cpp::is_tr<operator_p, just_not_tg>) {
                    return !nkr::cpp::is_tr<object_t, nkr::cpp::same_qualification_as_t<object_t, subject_p>>;
                } else {
                    return Execute_Expression_0<subject_t, operator_p>();
                }
            } else {
                return not_operator_tr<operator_p>;
            }
        }
    }

    template <
        nkr::tuple::types_tr    subjects_p,
        nkr::tuple::types_tr    operators_p,
        nkr::tuple::types_tr    objects_p
    > inline constexpr nkr::boolean::cpp_t
        Execute_Expression()
        noexcept
    {
        static_assert(subjects_p::Count() > 0);

        if constexpr (subjects_p::Count() == 1) {
            static_assert(subjects_p::Count() == operators_p::Count());

            if constexpr (objects_p::Count() == 0) {
                using subject_t = subjects_p::head_t;
                using operator_t = operators_p::head_t;

                return Execute_Expression_0<subject_t, typename operator_t::base_tg>();
            } else {
                static_assert(subjects_p::Count() == objects_p::Count());

                using subject_t = subjects_p::head_t;
                using operator_t = operators_p::head_t;
                using object_t = objects_p::head_t;

                return Execute_Expression_1<subject_t, typename operator_t::base_tg, object_t>();
            }
        } else {
            static_assert(subjects_p::Count() == operators_p::Count());
            static_assert(subjects_p::Count() == objects_p::Count());

            using subject_t = subjects_p::head_t;
            using operator_t = operators_p::head_t;
            using object_t = objects_p::head_t;

            if constexpr (not_operator_tr<operator_t>) {
                return
                    !(Execute_Expression_1<subject_t, typename operator_t::base_tg::is_tg, object_t>() &&
                      Execute_Expression<typename subjects_p::tail_t, typename operators_p::tail_t, typename objects_p::tail_t>());
            } else {
                return
                    Execute_Expression_1<subject_t, typename operator_t::base_tg, object_t>() &&
                    Execute_Expression<typename subjects_p::tail_t, typename operators_p::tail_t, typename objects_p::tail_t>();
            }
        }
    }

    template <
        nkr::tuple::types_tr    expression_parts_p,
        typename                index_p
    > inline constexpr nkr::boolean::cpp_t
        Validate_Expression()
        noexcept
    {
        static_assert(index_p::Value() < expression_parts_p::Count());

        if constexpr (expression_parts_p::Count() == 1) {
            using operator_t = expression_parts_p::head_t;

            static_assert(!of_operator_tr<operator_t>);

            return true;
        } else {
            static_assert(!(expression_parts_p::Count() & 1));

            using operator_t = expression_parts_p::template at_t<nkr::positive::index_c<index_p::Value()>>::head_t;
            using operand_t = expression_parts_p::template at_t<nkr::positive::index_c<index_p::Value() + 1>>::head_t;

            if constexpr (index_p::Value() == 0) {
                static_assert(!of_operator_tr<operator_t>);
            } else {
                static_assert(of_operator_tr<operator_t>);
            }

            if constexpr (index_p::Value() < expression_parts_p::Count() - 2) {
                static_assert(tts_tr<operand_t>);

                return Validate_Expression<expression_parts_p, nkr::positive::index_c<index_p::Value() + 2>>();
            } else {
                static_assert(ts_tr<operand_t>);

                return true;
            }
        }
    }

    template <
        nkr::ts_tr              subjects_p,
        nkr::tuple::types_tr    expression_parts_p,
        typename                index_p
    > inline constexpr nkr::boolean::cpp_t
        Evaluate_Expression()
        noexcept
    {
        static_assert(index_p::Value() < expression_parts_p::Count());

        if constexpr (expression_parts_p::Count() == 1) {
            // we should recurse for each t of subjects_p here
            using subject_p = subjects_p::head_t; // temp

            using operators_t = nkr::$tr::operators_t<expression_parts_p>;
            using subjects_t = nkr::$tr::subjects_t<subject_p, operators_t>;
            using objects_t = nkr::$tr::objects_t<expression_parts_p>;

            return Execute_Expression<subjects_t, operators_t, objects_t>();
        } else {
            using operator_t = expression_parts_p::template at_t<nkr::positive::index_c<index_p::Value()>>::head_t;
            using operand_t = expression_parts_p::template at_t<nkr::positive::index_c<index_p::Value() + 1>>::head_t;

            if constexpr (operand_t::Count() > 1) {
                using expression_front_t = expression_parts_p::template take_t<nkr::positive::count_c<index_p::Value() + 1>>;
                using expression_back_t = expression_parts_p::template at_t<nkr::positive::index_c<index_p::Value() + 2>>;
                using operand_head_t = nkr::cpp::access_qualification_of_t<typename operand_t::template take_t<nkr::positive::count_c<1>>, operand_t>;
                using operand_tail_t = nkr::cpp::access_qualification_of_t<typename operand_t::tail_t, operand_t>;
                using expression_with_head_t = expression_back_t::template into_t<
                    expression_front_t::template push_back_t<operand_head_t>::template push_back_t
                >;
                using expression_with_tail_t = expression_back_t::template into_t<
                    expression_front_t::template push_back_t<operand_tail_t>::template push_back_t
                >;

                if constexpr (nkr::$tr::OR_operator_tr<typename operand_t::operator_t>) {
                    if constexpr (Evaluate_Expression<subjects_p, expression_with_head_t, index_p>()) {
                        return true;
                    } else {
                        return Evaluate_Expression<subjects_p, expression_with_tail_t, index_p>();
                    }
                } else if constexpr (nkr::$tr::AND_operator_tr<typename operand_t::operator_t>) {
                    if constexpr (!Evaluate_Expression<subjects_p, expression_with_head_t, index_p>()) {
                        return false;
                    } else {
                        return Evaluate_Expression<subjects_p, expression_with_tail_t, index_p>();
                    }
                } else if constexpr (nkr::$tr::NOR_operator_tr<typename operand_t::operator_t>) {
                    if constexpr (Evaluate_Expression<subjects_p, expression_with_head_t, index_p>()) {
                        return false;
                    } else {
                        return !Evaluate_Expression<subjects_p, expression_with_tail_t, index_p>();
                    }
                } else if constexpr (nkr::$tr::NAND_operator_tr<typename operand_t::operator_t>) {
                    if constexpr (!Evaluate_Expression<subjects_p, expression_with_head_t, index_p>()) {
                        return true;
                    } else {
                        return !Evaluate_Expression<subjects_p, expression_with_tail_t, index_p>();
                    }
                } else {
                    // if we're using XOR or XNOR, maybe we can supply a boolean in the parameter list of the function.
                    // another option would be to try and store it in the type of the operator itself, which does make some sense.
                    static_assert(false);
                }
            } else {
                if constexpr (index_p::Value() < expression_parts_p::Count() - 2) {
                    return Evaluate_Expression<subjects_p, expression_parts_p, nkr::positive::index_c<index_p::Value() + 2>>();
                } else {
                    // we should recurse for each t of subjects_p here
                    using subject_p = subjects_p::head_t; // temp

                    using operators_t = nkr::$tr::operators_t<expression_parts_p>;
                    using subjects_t = nkr::$tr::subjects_t<subject_p, operators_t>;
                    using objects_t = nkr::$tr::objects_t<expression_parts_p>;

                    return Execute_Expression<subjects_t, operators_t, objects_t>();
                }
            }
        }
    }

}}

namespace nkr {

    template <
        nkr::ts_tr  subjects_p,
        typename    ...expression_parts_p
    > inline constexpr nkr::boolean::cpp_t
        TR()
        noexcept
    {
        using expression_parts_t = nkr::tuple::types_t<expression_parts_p...>;

        //static_assert(nkr::$tr::Validate_Expression<expression_parts_t, nkr::positive::index_c<0>>());

        return nkr::$tr::Evaluate_Expression<subjects_p, expression_parts_t, nkr::positive::index_c<0>>();
    }

}
