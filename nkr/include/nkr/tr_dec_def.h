/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

namespace nkr { namespace $tr {

    template <typename type_p>
    concept operator_tr =
        (requires { typename type_p::operator_t; });

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
    class type_i
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t
            Is_Any_General()
            noexcept
        {
            return nkr::cpp::is_any_tr<other_p, type_t>;
        }

        template <typename other_p>
        static constexpr nkr::boolean::cpp_t
            Is_Any_Specific()
            noexcept
        {
            return nkr::cpp::is_any_tr<other_p, type_t>;
        }

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <typename type_p>
        requires (!nkr::cpp::array_tr<type_p> && nkr::generic::implementing::interface::type_tr<nkr::cpp::just_non_qualified_t<type_p>>)
    class type_i<type_p> :
        public nkr::interface::type_i<nkr::cpp::just_non_qualified_t<type_p>>
    {
    public:
    };

    template <nkr::cpp::array_tr type_p>
        requires (nkr::cpp::array_tr<type_p> && nkr::generic::implementing::interface::type_tr<type_p>)
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
        using front_t   = subjects_tmpl<subject_p, typename operators_p::template take_t<nkr::constant::positive::count_t<operators_p::Count() - 1>>>::type_t;
        using subject_t = front_t::template at_t<nkr::constant::positive::index_t<front_t::Count() - 1>>::head_t;

    private:
        static constexpr nkr::boolean::cpp_t    is_access_operator =
            access_operator_tr<typename operators_p::template at_t<nkr::constant::positive::index_t<operators_p::Count() - 1>>::head_t>;

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
        using object_t  = expression_parts_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;

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
        using object_t  = expression_parts_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;

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
        typename    type_p,
        typename    other_p,
        typename    do_specific_p   = nkr::constant::boolean::cpp_t<false>
    > inline constexpr nkr::boolean::cpp_t
        Is_Any()
        noexcept
    {
        if constexpr (do_specific_p::Value() == true) {
            return type_i<type_p>::template Is_Any_Specific<nkr::cpp::just_non_qualified_t<other_p>>();
        } else {
            return type_i<type_p>::template Is_Any_General<nkr::cpp::just_non_qualified_t<other_p>>();
        }
    }

    template <
        typename    subject_p,
        typename    operator_p
    > inline constexpr nkr::boolean::cpp_t
        Evaluate_0()
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

        else                                                                        [] <nkr::boolean::cpp_t _ = false>() { static_assert(_, "Undefined or invalid operator."); }();
    }

    template <
        typename    subject_p,
        typename    operator_p,
        typename    operand_p,
        typename    is_last_p   = nkr::constant::boolean::cpp_t<false>
    > inline constexpr nkr::boolean::cpp_t
        Evaluate_1()
        noexcept
    {
        static_assert(!to_operator_tr<operator_p>);
        static_assert(!of_operator_tr<operator_p>);

        using subject_t = subject_p;
        using object_t = operand_p;
        using do_specific_t = nkr::constant::boolean::cpp_t<is_last_p::Value() && !nkr::generic::tag_tr<object_t>>;

        if constexpr (Is_Any<object_t, subject_t, do_specific_t>()) {
            if constexpr (nkr::cpp::is_tr<operator_p, just_tg>) {
                return nkr::cpp::is_tr<object_t, nkr::cpp::same_qualification_as_t<object_t, subject_p>>;
            } else if constexpr (nkr::cpp::is_tr<operator_p, just_not_tg>) {
                return !nkr::cpp::is_tr<object_t, nkr::cpp::same_qualification_as_t<object_t, subject_p>>;
            } else {
                return Evaluate_0<subject_t, operator_p>();
            }
        } else {
            return not_operator_tr<operator_p>;
        }
    }

    template <
        nkr::tuple::types_tr    subjects_p,
        nkr::tuple::types_tr    operators_p,
        nkr::tuple::types_tr    objects_p
    > inline constexpr nkr::boolean::cpp_t
        Evaluate()
        noexcept
    {
        static_assert(subjects_p::Count() > 0);

        if constexpr (to_operator_tr<typename operators_p::head_t>) {
            static_assert(objects_p::Count() > 0);

            if constexpr (not_operator_tr<typename operators_p::head_t>) {
                return !nkr::cpp::to_tr<typename subjects_p::head_t, typename objects_p::head_t>;
            } else {
                return nkr::cpp::to_tr<typename subjects_p::head_t, typename objects_p::head_t>;
            }
        } else {
            if constexpr (subjects_p::Count() == 1) {
                static_assert(subjects_p::Count() == operators_p::Count());

                if constexpr (objects_p::Count() == 0) {
                    using subject_t = subjects_p::head_t;
                    using operator_t = operators_p::head_t;

                    return Evaluate_0<subject_t, typename operator_t::non_of_tg>();
                } else {
                    static_assert(subjects_p::Count() == objects_p::Count());

                    using subject_t = subjects_p::head_t;
                    using operator_t = operators_p::head_t;
                    using object_t = objects_p::head_t;

                    return Evaluate_1<subject_t, typename operator_t::non_of_tg, object_t, nkr::constant::boolean::cpp_t<true>>();
                }
            } else {
                static_assert(subjects_p::Count() == operators_p::Count());
                static_assert(subjects_p::Count() == objects_p::Count());

                using subject_t = subjects_p::head_t;
                using operator_t = operators_p::head_t;
                using object_t = objects_p::head_t;

                if constexpr (not_operator_tr<operator_t>) {
                    return
                        !(Evaluate_1<subject_t, typename operator_t::non_of_tg::is_tg, object_t>() &&
                          Evaluate<typename subjects_p::tail_t, typename operators_p::tail_t, typename objects_p::tail_t>());
                } else {
                    return
                        Evaluate_1<subject_t, typename operator_t::non_of_tg, object_t>() &&
                        Evaluate<typename subjects_p::tail_t, typename operators_p::tail_t, typename objects_p::tail_t>();
                }
            }
        }
    }

    template <
        typename                subject_p,
        nkr::tuple::types_tr    expression_parts_p,
        typename                index_p             = nkr::constant::positive::index_t<0>,
        typename                XOR_state_p         = nkr::constant::boolean::cpp_t<false>
    > inline constexpr nkr::boolean::cpp_t
        Evaluate_Expression()
        noexcept
    {
        static_assert(index_p::Value() < expression_parts_p::Count());

        if constexpr (expression_parts_p::Count() == 1) {
            using operators_t = nkr::$tr::operators_t<expression_parts_p>;
            using subjects_t = nkr::$tr::subjects_t<subject_p, operators_t>;
            using objects_t = nkr::$tr::objects_t<expression_parts_p>;

            return Evaluate<subjects_t, operators_t, objects_t>();
        } else {
            using operand_t = expression_parts_p::template at_t<nkr::constant::positive::index_t<index_p::Value() + 1>>::head_t;
            using expression_front_t = expression_parts_p::template take_t<nkr::constant::positive::count_t<index_p::Value() + 1>>;
            using expression_back_t = expression_parts_p::template at_t<nkr::constant::positive::index_t<index_p::Value() + 2>>;

            if constexpr (nkr::$tr::NOR_operator_tr<typename operand_t::operator_t>) {
                using expression_with_operand_t = expression_back_t::template into_t<
                    expression_front_t::template push_back_t<typename operand_t::template with_operator_t<OR_tg>>::template push_back_t
                >;

                return !Evaluate_Expression<subject_p, expression_with_operand_t, index_p>();
            } else if constexpr (nkr::$tr::NAND_operator_tr<typename operand_t::operator_t>) {
                using expression_with_operand_t = expression_back_t::template into_t<
                    expression_front_t::template push_back_t<typename operand_t::template with_operator_t<AND_tg>>::template push_back_t
                >;

                return !Evaluate_Expression<subject_p, expression_with_operand_t, index_p>();
            } else if constexpr (nkr::$tr::XNOR_operator_tr<typename operand_t::operator_t>) {
                using expression_with_operand_t = expression_back_t::template into_t<
                    expression_front_t::template push_back_t<typename operand_t::template with_operator_t<XOR_tg>>::template push_back_t
                >;

                return !Evaluate_Expression<subject_p, expression_with_operand_t, index_p>();
            } else {
                if constexpr (operand_t::Count() == 1) {
                    if constexpr (index_p::Value() < expression_parts_p::Count() - 2) {
                        if constexpr (nkr::$tr::XOR_operator_tr<typename operand_t::operator_t>) {
                            if constexpr (XOR_state_p::Value()) {
                                return !Evaluate_Expression<subject_p, expression_parts_p, nkr::constant::positive::index_t<index_p::Value() + 2>>();
                            } else {
                                return Evaluate_Expression<subject_p, expression_parts_p, nkr::constant::positive::index_t<index_p::Value() + 2>>();
                            }
                        } else {
                            return Evaluate_Expression<subject_p, expression_parts_p, nkr::constant::positive::index_t<index_p::Value() + 2>>();
                        }
                    } else {
                        using operators_t = nkr::$tr::operators_t<expression_parts_p>;
                        using subjects_t = nkr::$tr::subjects_t<subject_p, operators_t>;
                        using objects_t = nkr::$tr::objects_t<expression_parts_p>;

                        if constexpr (nkr::$tr::XOR_operator_tr<typename operand_t::operator_t>) {
                            if constexpr (XOR_state_p::Value()) {
                                return !Evaluate<subjects_t, operators_t, objects_t>();
                            } else {
                                return Evaluate<subjects_t, operators_t, objects_t>();
                            }
                        } else {
                            return Evaluate<subjects_t, operators_t, objects_t>();
                        }
                    }
                } else {
                    using operand_head_t = nkr::cpp::access_qualification_of_t<typename operand_t::template take_t<nkr::constant::positive::count_t<1>>, operand_t>;
                    using operand_tail_t = nkr::cpp::access_qualification_of_t<typename operand_t::tail_t, operand_t>;
                    using expression_with_head_t = expression_back_t::template into_t<
                        expression_front_t::template push_back_t<operand_head_t>::template push_back_t
                    >;
                    using expression_with_tail_t = expression_back_t::template into_t<
                        expression_front_t::template push_back_t<operand_tail_t>::template push_back_t
                    >;

                    if constexpr (nkr::$tr::OR_operator_tr<typename operand_t::operator_t>) {
                        if constexpr (Evaluate_Expression<subject_p, expression_with_head_t, index_p>()) {
                            return true;
                        } else {
                            return Evaluate_Expression<subject_p, expression_with_tail_t, index_p>();
                        }
                    } else if constexpr (nkr::$tr::AND_operator_tr<typename operand_t::operator_t>) {
                        if constexpr (!Evaluate_Expression<subject_p, expression_with_head_t, index_p>()) {
                            return false;
                        } else {
                            return Evaluate_Expression<subject_p, expression_with_tail_t, index_p>();
                        }
                    } else if constexpr (nkr::$tr::XOR_operator_tr<typename operand_t::operator_t>) {
                        if constexpr (XOR_state_p::Value()) {
                            if constexpr (Evaluate_Expression<subject_p, expression_with_head_t, index_p>()) {
                                return false;
                            } else {
                                return Evaluate_Expression<subject_p, expression_with_tail_t, index_p, nkr::constant::boolean::cpp_t<true>>();
                            }
                        } else {
                            if constexpr (Evaluate_Expression<subject_p, expression_with_head_t, index_p>()) {
                                return Evaluate_Expression<subject_p, expression_with_tail_t, index_p, nkr::constant::boolean::cpp_t<true>>();
                            } else {
                                return Evaluate_Expression<subject_p, expression_with_tail_t, index_p, nkr::constant::boolean::cpp_t<false>>();
                            }
                        }
                    } else {
                        [] <nkr::boolean::cpp_t _ = false>() { static_assert(_); }();
                    }
                }
            }
        }
    }

    template <
        nkr::ts_tr              subjects_p,
        nkr::tuple::types_tr    expression_parts_p,
        typename                XOR_state_p         = nkr::constant::boolean::cpp_t<false>
    > inline constexpr nkr::boolean::cpp_t
        Evaluate_Subjects()
        noexcept
    {
        if constexpr (nkr::$tr::NOR_operator_tr<typename subjects_p::operator_t>) {
            return !Evaluate_Subjects<nkr::cpp::access_qualification_of_t<to_ts<OR_tg, subjects_p>, subjects_p>, expression_parts_p>();
        } else if constexpr (nkr::$tr::NAND_operator_tr<typename subjects_p::operator_t>) {
            return !Evaluate_Subjects<nkr::cpp::access_qualification_of_t<to_ts<AND_tg, subjects_p>, subjects_p>, expression_parts_p>();
        } else if constexpr (nkr::$tr::XNOR_operator_tr<typename subjects_p::operator_t>) {
            return !Evaluate_Subjects<nkr::cpp::access_qualification_of_t<to_ts<XOR_tg, subjects_p>, subjects_p>, expression_parts_p>();
        } else {
            using subjects_head_t = nkr::cpp::access_qualification_of_t<typename subjects_p::head_t, subjects_p>;
            using subjects_tail_t = nkr::cpp::access_qualification_of_t<typename subjects_p::tail_t, subjects_p>;

            if constexpr (subjects_p::Count() == 1) {
                if constexpr (nkr::$tr::XOR_operator_tr<typename subjects_p::operator_t>) {
                    if constexpr (XOR_state_p::Value()) {
                        return !Evaluate_Expression<subjects_head_t, expression_parts_p>();
                    } else {
                        return Evaluate_Expression<subjects_head_t, expression_parts_p>();
                    }
                } else {
                    return Evaluate_Expression<subjects_head_t, expression_parts_p>();
                }
            } else {
                if constexpr (nkr::$tr::OR_operator_tr<typename subjects_p::operator_t>) {
                    if constexpr (Evaluate_Expression<subjects_head_t, expression_parts_p>()) {
                        return true;
                    } else {
                        return Evaluate_Subjects<subjects_tail_t, expression_parts_p>();
                    }
                } else if constexpr (nkr::$tr::AND_operator_tr<typename subjects_p::operator_t>) {
                    if constexpr (!Evaluate_Expression<subjects_head_t, expression_parts_p>()) {
                        return false;
                    } else {
                        return Evaluate_Subjects<subjects_tail_t, expression_parts_p>();
                    }
                } else if constexpr (nkr::$tr::XOR_operator_tr<typename subjects_p::operator_t>) {
                    if constexpr (XOR_state_p::Value()) {
                        if constexpr (Evaluate_Expression<subjects_head_t, expression_parts_p>()) {
                            return false;
                        } else {
                            return Evaluate_Subjects<subjects_tail_t, expression_parts_p, nkr::constant::boolean::cpp_t<true>>();
                        }
                    } else {
                        if constexpr (Evaluate_Expression<subjects_head_t, expression_parts_p>()) {
                            return Evaluate_Subjects<subjects_tail_t, expression_parts_p, nkr::constant::boolean::cpp_t<true>>();
                        } else {
                            return Evaluate_Subjects<subjects_tail_t, expression_parts_p, nkr::constant::boolean::cpp_t<false>>();
                        }
                    }
                } else {
                    [] <nkr::boolean::cpp_t _ = false>() { static_assert(_); }();
                }
            }
        }
    }

    template <
        nkr::ts_tr              subjects_p,
        nkr::tuple::types_tr    expression_parts_p,
        typename                index_p             = nkr::constant::positive::index_t<0>
    > inline constexpr nkr::boolean::cpp_t
        Validate()
        noexcept
    {
        static_assert(expression_parts_p::Count() > 0,
                      "The length of the expression cannot be zero.");

        static_assert(index_p::Value() < expression_parts_p::Count(),
                      "Internal validation error.");

        using first_operator_t = expression_parts_p::head_t;

        if constexpr (expression_parts_p::Count() == 1) {
            using operator_t = first_operator_t;

            static_assert(operator_tr<operator_t>,
                          "The only expression part is not an operator.");
            static_assert(!to_operator_tr<operator_t>,
                          "An expression with a length of 1 cannot use the 'to' operator.");
            static_assert(!of_operator_tr<operator_t>,
                          "An expression with a length of 1 cannot use an 'of' operator.");

            return true;
        } else {
            static_assert(!(expression_parts_p::Count() & 1),
                          "An expression with a length greater than 1 must have an even number of parts.");

            using operator_t = expression_parts_p::template at_t<nkr::constant::positive::index_t<index_p::Value()>>::head_t;
            using operand_t = expression_parts_p::template at_t<nkr::constant::positive::index_t<index_p::Value() + 1>>::head_t;

            static_assert(operator_tr<operator_t> && !nkr::ts_tr<operator_t> && !nkr::tts_tr<operator_t>,
                          "Every odd-numbered expression part must be an operator.");
            static_assert(nkr::ts_tr<operand_t> || nkr::tts_tr<operand_t>,
                          "Every even-numbered expression part must be an operand.");

            if constexpr (index_p::Value() == 0) {
                static_assert(!of_operator_tr<operator_t>,
                              "The first operator in an expression cannot be an 'of' operator.");
            } else {
                static_assert(of_operator_tr<operator_t>,
                              "Every operator after the first in an expression must be an 'of' operator.");

                if constexpr (to_operator_tr<first_operator_t>) {
                    static_assert(nkr::cpp::is_any_tr<operator_t, of_just_tg>,
                                  "Every operator after the 'to' operator must be the 'of_just_tg' operator.");
                }
            }

            if constexpr (index_p::Value() < expression_parts_p::Count() - 2) {
                static_assert(tts_tr<operand_t>,
                              "Every operand except the last must either be a tt<> or a tts<> operand.");

                return Validate<subjects_p, expression_parts_p, nkr::constant::positive::index_t<index_p::Value() + 2>>();
            } else {
                static_assert(ts_tr<operand_t>,
                              "The last operand must either be a t<> or a ts<> operand.");

                return true;
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

        static_assert(nkr::$tr::Validate<subjects_p, expression_parts_t>());

        return nkr::$tr::Evaluate_Subjects<subjects_p, expression_parts_t>();
    }

}
