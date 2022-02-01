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
        typename subject_p,
        typename operator_p
    > inline constexpr nkr::boolean::cpp_t
        TR0()
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
        typename subject_p,
        typename operator_p, typename operand_p
    > inline constexpr nkr::boolean::cpp_t
        TR1()
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
                return !(TR0<subject_t, typename operator_p::base_tg::is_tg>() && nkr::cpp::to_tr<subject_t, object_t>);
            } else {
                return TR0<subject_t, typename operator_p::base_tg>() && nkr::cpp::to_tr<subject_t, object_t>;
            }
        } else {
            if constexpr (type_i<object_t>::template Is_Any<nkr::cpp::just_non_qualified_t<subject_t>>()) {
                if constexpr (nkr::cpp::is_tr<operator_p, just_tg>) {
                    return nkr::cpp::is_tr<object_t, nkr::cpp::same_qualification_as_t<object_t, subject_p>>;
                } else if constexpr (nkr::cpp::is_tr<operator_p, just_not_tg>) {
                    return !nkr::cpp::is_tr<object_t, nkr::cpp::same_qualification_as_t<object_t, subject_p>>;
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
    > inline constexpr nkr::boolean::cpp_t
        TR2()
        noexcept
    {
        static_assert(nkr::generic::implementing::interface::template_ttr<operand_p>);
        if constexpr (nkr::cpp::array_tr<of_operand_p>) {
            static_assert(nkr::generic::implementing::interface::type_tr<of_operand_p>);
        } else {
            static_assert(nkr::generic::implementing::interface::type_tr<nkr::cpp::just_non_qualified_t<of_operand_p>>);
        }

        using subject_t = subject_p;
        using of_subject_t = access_or_not_t<typename type_i<subject_t>::of_t, subject_t, access_operator_tr<of_operator_p>>;

        using of_object_t = of_operand_p;
        using object_t = template_i<operand_p>::template of_t<of_object_t>;

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
    > inline constexpr nkr::boolean::cpp_t
        TR3()
        noexcept
    {
        static_assert(nkr::generic::implementing::interface::template_ttr<operand_p>);
        static_assert(nkr::generic::implementing::interface::template_ttr<of_operand_p>);
        if constexpr (nkr::cpp::array_tr<of_of_operand_p>) {
            static_assert(nkr::generic::implementing::interface::type_tr<of_of_operand_p>);
        } else {
            static_assert(nkr::generic::implementing::interface::type_tr<nkr::cpp::just_non_qualified_t<of_of_operand_p>>);
        }

        using subject_t = subject_p;
        using of_subject_t = access_or_not_t<typename type_i<subject_t>::of_t, subject_t, access_operator_tr<of_of_operator_p>>;
        using of_of_subject_t = access_or_not_t<typename type_i<of_subject_t>::of_t, of_subject_t, access_operator_tr<of_of_operator_p>>;

        using of_of_object_t = of_of_operand_p;
        using of_object_t = template_i<of_operand_p>::template of_t<of_of_object_t>;
        using object_t = template_i<operand_p>::template of_t<of_object_t>;

        if constexpr (not_operator_tr<operator_p>) {
            return
                !(TR1<subject_t, typename operator_p::is_tg, object_t>() &&
                  TR2<of_subject_t, typename of_operator_p::base_tg, of_operand_p, of_of_operator_p, of_of_object_t>());
        } else {
            return
                TR1<subject_t, operator_p, object_t>() &&
                TR2<of_subject_t, typename of_operator_p::base_tg, of_operand_p, of_of_operator_p, of_of_object_t>();
        }
    }

    template <
        nkr::tuple::types_tr    subjects_p,
        nkr::tuple::types_tr    operators_p,
        nkr::tuple::types_tr    objects_p
    > inline constexpr nkr::boolean::cpp_t
        Execute()
        noexcept
    {
        static_assert(subjects_p::Count() > 0);

        if constexpr (subjects_p::Count() == 1) {
            static_assert(subjects_p::Count() == operators_p::Count());

            if constexpr (objects_p::Count() == 0) {
                using subject_t = subjects_p::head_t;
                using operator_t = operators_p::head_t;

                return TR0<subject_t, typename operator_t::base_tg>();
            } else {
                static_assert(subjects_p::Count() == objects_p::Count());

                using subject_t = subjects_p::head_t;
                using operator_t = operators_p::head_t;
                using object_t = objects_p::head_t;

                return TR1<subject_t, typename operator_t::base_tg, object_t>();
            }
        } else {
            static_assert(subjects_p::Count() == operators_p::Count());
            static_assert(subjects_p::Count() == objects_p::Count());

            using subject_t = subjects_p::head_t;
            using operator_t = operators_p::head_t;
            using object_t = objects_p::head_t;

            if constexpr (not_operator_tr<operator_t>) {
                return
                    !(TR1<subject_t, typename operator_t::base_tg::is_tg, object_t>() &&
                      Execute<typename subjects_p::tail_t, typename operators_p::tail_t, typename objects_p::tail_t>());
            } else {
                return
                    TR1<subject_t, typename operator_t::base_tg, object_t>() &&
                    Execute<typename subjects_p::tail_t, typename operators_p::tail_t, typename objects_p::tail_t>();
            }
        }
    }

    template <
        nkr::ts_tr              subjects_p,
        nkr::tuple::types_tr    expression_parts_p,
        typename                index_p
    > inline constexpr nkr::boolean::cpp_t
        TR()
        noexcept
    {
        static_assert(index_p::Value() < expression_parts_p::Count());

        if constexpr (expression_parts_p::Count() == 1) {
            // we should recurse for each t of subjects_p here
            using subject_p = subjects_p::head_t; // temp

            using operators_t = nkr::$tr::operators_t<expression_parts_p>;
            using subjects_t = nkr::$tr::subjects_t<subject_p, operators_t>;
            using objects_t = nkr::$tr::objects_t<expression_parts_p>;

            return Execute<subjects_t, operators_t, objects_t>();
        } else {
            static_assert(!(expression_parts_p::Count() & 1));

            using operator_t = expression_parts_p::template at_t<nkr::positive::index_c<index_p::Value()>>::head_t;
            using operand_t = expression_parts_p::template at_t<nkr::positive::index_c<index_p::Value() + 1>>::head_t;

            if constexpr (operand_t::Count() > 1) {
                using expression_front_t = expression_parts_p::template take_t<nkr::positive::count_c<index_p::Value() + 1>>;
                using expression_back_t = expression_parts_p::template at_t<nkr::positive::index_c<index_p::Value() + 2>>;
                using expression_with_head_t = expression_back_t::template into_t<
                    expression_front_t::template push_back_t<typename operand_t::template take_t<nkr::positive::count_c<1>>>::template push_back_t
                >;
                using expression_with_tail_t = expression_back_t::template into_t<
                    expression_front_t::template push_back_t<typename operand_t::tail_t>::template push_back_t
                >;

                if constexpr (nkr::$tr::OR_operator_tr<typename operand_t::operator_t>) {
                    if constexpr (TR<subjects_p, expression_with_head_t, index_p>()) {
                        return true;
                    } else {
                        return TR<subjects_p, expression_with_tail_t, index_p>();
                    }
                } else if constexpr (nkr::$tr::AND_operator_tr<typename operand_t::operator_t>) {
                    if constexpr (!TR<subjects_p, expression_with_head_t, index_p>()) {
                        return false;
                    } else {
                        return TR<subjects_p, expression_with_tail_t, index_p>();
                    }
                } else if constexpr (nkr::$tr::NOR_operator_tr<typename operand_t::operator_t>) {
                    if constexpr (TR<subjects_p, expression_with_head_t, index_p>()) {
                        return false;
                    } else {
                        return !TR<subjects_p, expression_with_tail_t, index_p>();
                    }
                } else if constexpr (nkr::$tr::NAND_operator_tr<typename operand_t::operator_t>) {
                    if constexpr (!TR<subjects_p, expression_with_head_t, index_p>()) {
                        return true;
                    } else {
                        return !TR<subjects_p, expression_with_tail_t, index_p>();
                    }
                } else {
                    // if we're using XOR or XNOR, maybe we can supply a boolean in the parameter list of the function.
                    // another option would be to try and store it in the type of the operator itself, which does make some sense.
                    static_assert(false);
                }
            } else {
                if constexpr (index_p::Value() < expression_parts_p::Count() - 2) {
                    return TR<subjects_p, expression_parts_p, nkr::positive::index_c<index_p::Value() + 2>>();
                } else {
                    // we should recurse for each t of subjects_p here
                    using subject_p = subjects_p::head_t; // temp

                    using operators_t = nkr::$tr::operators_t<expression_parts_p>;
                    using subjects_t = nkr::$tr::subjects_t<subject_p, operators_t>;
                    using objects_t = nkr::$tr::objects_t<expression_parts_p>;

                    return Execute<subjects_t, operators_t, objects_t>();
                }
            }
        }
    }

}}

// everything below here will be deleted.

namespace nkr {

    template <
        typename operator_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr0_t<operator_p>::OR()
        noexcept
    {
        if constexpr (subjects_p::Count() == 1) {
            return tr0<typename subjects_p::head_t, operator_p>;
        } else {
            if constexpr (tr0<typename subjects_p::head_t, operator_p>) {
                return true;
            } else {
                return OR<typename subjects_p::tail_t>();
            }
        }
    }

    template <
        typename operator_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr0_t<operator_p>::OR()
        noexcept
    {
        return OR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr0_t<operator_p>::AND()
        noexcept
    {
        if constexpr (subjects_p::Count() == 1) {
            return tr0<typename subjects_p::head_t, operator_p>;
        } else {
            if constexpr (tr0<typename subjects_p::head_t, operator_p>) {
                return AND<typename subjects_p::tail_t>();
            } else {
                return false;
            }
        }
    }

    template <
        typename operator_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr0_t<operator_p>::AND()
        noexcept
    {
        return AND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr0_t<operator_p>::XOR()
        noexcept
    {
        return XOR<nkr::boolean::cpp_c<false>, subjects_p>();
    }

    template <
        typename operator_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr0_t<operator_p>::XOR()
        noexcept
    {
        return XOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr0_t<operator_p>::NOR()
        noexcept
    {
        return !OR<subjects_p>();
    }

    template <
        typename operator_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr0_t<operator_p>::NOR()
        noexcept
    {
        return NOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr0_t<operator_p>::NAND()
        noexcept
    {
        return !AND<subjects_p>();
    }

    template <
        typename operator_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr0_t<operator_p>::NAND()
        noexcept
    {
        return NAND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr0_t<operator_p>::XNOR()
        noexcept
    {
        return !XOR<subjects_p>();
    }

    template <
        typename operator_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr0_t<operator_p>::XNOR()
        noexcept
    {
        return XNOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr0_t<operator_p>::Any()
        noexcept
    {
        return OR<subjects_p>();
    }

    template <
        typename operator_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr0_t<operator_p>::Any()
        noexcept
    {
        return Any<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr0_t<operator_p>::Every()
        noexcept
    {
        return AND<subjects_p>();
    }

    template <
        typename operator_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr0_t<operator_p>::Every()
        noexcept
    {
        return Every<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr0_t<operator_p>::One()
        noexcept
    {
        return XOR<subjects_p>();
    }

    template <
        typename operator_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr0_t<operator_p>::One()
        noexcept
    {
        return One<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr0_t<operator_p>::None()
        noexcept
    {
        return NOR<subjects_p>();
    }

    template <
        typename operator_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr0_t<operator_p>::None()
        noexcept
    {
        return None<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p
    > template <
        nkr::boolean::cpp_ctr state_p, tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr0_t<operator_p>::XOR()
        noexcept
    {
        if constexpr (subjects_p::Count() == 1) {
            if constexpr (state_p::Value()) {
                return !tr0<typename subjects_p::head_t, operator_p>;
            } else {
                return tr0<typename subjects_p::head_t, operator_p>;
            }
        } else {
            if constexpr (state_p::Value()) {
                if constexpr (tr0<typename subjects_p::head_t, operator_p>) {
                    return false;
                } else {
                    return XOR<nkr::boolean::cpp_c<true>, typename subjects_p::tail_t>();
                }
            } else {
                if constexpr (tr0<typename subjects_p::head_t, operator_p>) {
                    return XOR<nkr::boolean::cpp_c<true>, typename subjects_p::tail_t>();
                } else {
                    return XOR<nkr::boolean::cpp_c<false>, typename subjects_p::tail_t>();
                }
            }
        }
    }

}

namespace nkr {

    template <
        typename operator_p, typename operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1_t<operator_p, operand_p>::OR()
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

    template <
        typename operator_p, typename operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1_t<operator_p, operand_p>::OR()
        noexcept
    {
        return OR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, typename operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1_t<operator_p, operand_p>::AND()
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

    template <
        typename operator_p, typename operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1_t<operator_p, operand_p>::AND()
        noexcept
    {
        return AND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, typename operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1_t<operator_p, operand_p>::XOR()
        noexcept
    {
        return XOR<nkr::boolean::cpp_c<false>, subjects_p>();
    }

    template <
        typename operator_p, typename operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1_t<operator_p, operand_p>::XOR()
        noexcept
    {
        return XOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, typename operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1_t<operator_p, operand_p>::NOR()
        noexcept
    {
        return !OR<subjects_p>();
    }

    template <
        typename operator_p, typename operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1_t<operator_p, operand_p>::NOR()
        noexcept
    {
        return NOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, typename operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1_t<operator_p, operand_p>::NAND()
        noexcept
    {
        return !AND<subjects_p>();
    }

    template <
        typename operator_p, typename operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1_t<operator_p, operand_p>::NAND()
        noexcept
    {
        return NAND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, typename operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1_t<operator_p, operand_p>::XNOR()
        noexcept
    {
        return !XOR<subjects_p>();
    }

    template <
        typename operator_p, typename operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1_t<operator_p, operand_p>::XNOR()
        noexcept
    {
        return XNOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, typename operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1_t<operator_p, operand_p>::Any()
        noexcept
    {
        return OR<subjects_p>();
    }

    template <
        typename operator_p, typename operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1_t<operator_p, operand_p>::Any()
        noexcept
    {
        return Any<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, typename operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1_t<operator_p, operand_p>::Every()
        noexcept
    {
        return AND<subjects_p>();
    }

    template <
        typename operator_p, typename operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1_t<operator_p, operand_p>::Every()
        noexcept
    {
        return Every<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, typename operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1_t<operator_p, operand_p>::One()
        noexcept
    {
        return XOR<subjects_p>();
    }

    template <
        typename operator_p, typename operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1_t<operator_p, operand_p>::One()
        noexcept
    {
        return One<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, typename operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1_t<operator_p, operand_p>::None()
        noexcept
    {
        return NOR<subjects_p>();
    }

    template <
        typename operator_p, typename operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1_t<operator_p, operand_p>::None()
        noexcept
    {
        return None<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, typename operand_p
    > template <
        nkr::boolean::cpp_ctr state_p, tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1_t<operator_p, operand_p>::XOR()
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

}

namespace nkr {

    template <
        typename operator_p, nkr::ts_tr operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1s_t<operator_p, operands_p>::OR()
        noexcept
    {
        using operands_head_t = nkr::cpp::access_qualification_of_t<typename operands_p::head_t, operands_p>;
        using operands_tail_t = nkr::cpp::access_qualification_of_t<typename operands_p::tail_t, operands_p>;

        if constexpr (operands_p::Count() == 1) {
            return tr1_t<operator_p, operands_head_t>::template OR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename operands_p::operator_t>) {
                if constexpr (tr1_t<operator_p, operands_head_t>::template OR<subjects_p>()) {
                    return true;
                } else {
                    return tr1s_t<operator_p, operands_tail_t>::template OR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename operands_p::operator_t>) {
                if constexpr (!tr1_t<operator_p, operands_head_t>::template OR<subjects_p>()) {
                    return false;
                } else {
                    return tr1s_t<operator_p, operands_tail_t>::template OR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, nkr::ts_tr operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1s_t<operator_p, operands_p>::OR()
        noexcept
    {
        return OR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::ts_tr operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1s_t<operator_p, operands_p>::AND()
        noexcept
    {
        using operands_head_t = nkr::cpp::access_qualification_of_t<typename operands_p::head_t, operands_p>;
        using operands_tail_t = nkr::cpp::access_qualification_of_t<typename operands_p::tail_t, operands_p>;

        if constexpr (operands_p::Count() == 1) {
            return tr1_t<operator_p, operands_head_t>::template AND<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename operands_p::operator_t>) {
                if constexpr (tr1_t<operator_p, operands_head_t>::template AND<subjects_p>()) {
                    return true;
                } else {
                    return tr1s_t<operator_p, operands_tail_t>::template AND<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename operands_p::operator_t>) {
                if constexpr (!tr1_t<operator_p, operands_head_t>::template AND<subjects_p>()) {
                    return false;
                } else {
                    return tr1s_t<operator_p, operands_tail_t>::template AND<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, nkr::ts_tr operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1s_t<operator_p, operands_p>::AND()
        noexcept
    {
        return AND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::ts_tr operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1s_t<operator_p, operands_p>::XOR()
        noexcept
    {
        using operands_head_t = nkr::cpp::access_qualification_of_t<typename operands_p::head_t, operands_p>;
        using operands_tail_t = nkr::cpp::access_qualification_of_t<typename operands_p::tail_t, operands_p>;

        if constexpr (operands_p::Count() == 1) {
            return tr1_t<operator_p, operands_head_t>::template XOR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename operands_p::operator_t>) {
                if constexpr (tr1_t<operator_p, operands_head_t>::template XOR<subjects_p>()) {
                    return true;
                } else {
                    return tr1s_t<operator_p, operands_tail_t>::template XOR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename operands_p::operator_t>) {
                if constexpr (!tr1_t<operator_p, operands_head_t>::template XOR<subjects_p>()) {
                    return false;
                } else {
                    return tr1s_t<operator_p, operands_tail_t>::template XOR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, nkr::ts_tr operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1s_t<operator_p, operands_p>::XOR()
        noexcept
    {
        return XOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::ts_tr operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1s_t<operator_p, operands_p>::NOR()
        noexcept
    {
        using operands_head_t = nkr::cpp::access_qualification_of_t<typename operands_p::head_t, operands_p>;
        using operands_tail_t = nkr::cpp::access_qualification_of_t<typename operands_p::tail_t, operands_p>;

        if constexpr (operands_p::Count() == 1) {
            return tr1_t<operator_p, operands_head_t>::template NOR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename operands_p::operator_t>) {
                if constexpr (tr1_t<operator_p, operands_head_t>::template NOR<subjects_p>()) {
                    return true;
                } else {
                    return tr1s_t<operator_p, operands_tail_t>::template NOR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename operands_p::operator_t>) {
                if constexpr (!tr1_t<operator_p, operands_head_t>::template NOR<subjects_p>()) {
                    return false;
                } else {
                    return tr1s_t<operator_p, operands_tail_t>::template NOR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, nkr::ts_tr operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1s_t<operator_p, operands_p>::NOR()
        noexcept
    {
        return NOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::ts_tr operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1s_t<operator_p, operands_p>::NAND()
        noexcept
    {
        using operands_head_t = nkr::cpp::access_qualification_of_t<typename operands_p::head_t, operands_p>;
        using operands_tail_t = nkr::cpp::access_qualification_of_t<typename operands_p::tail_t, operands_p>;

        if constexpr (operands_p::Count() == 1) {
            return tr1_t<operator_p, operands_head_t>::template NAND<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename operands_p::operator_t>) {
                if constexpr (tr1_t<operator_p, operands_head_t>::template NAND<subjects_p>()) {
                    return true;
                } else {
                    return tr1s_t<operator_p, operands_tail_t>::template NAND<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename operands_p::operator_t>) {
                if constexpr (!tr1_t<operator_p, operands_head_t>::template NAND<subjects_p>()) {
                    return false;
                } else {
                    return tr1s_t<operator_p, operands_tail_t>::template NAND<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, nkr::ts_tr operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1s_t<operator_p, operands_p>::NAND()
        noexcept
    {
        return NAND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::ts_tr operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1s_t<operator_p, operands_p>::XNOR()
        noexcept
    {
        using operands_head_t = nkr::cpp::access_qualification_of_t<typename operands_p::head_t, operands_p>;
        using operands_tail_t = nkr::cpp::access_qualification_of_t<typename operands_p::tail_t, operands_p>;

        if constexpr (operands_p::Count() == 1) {
            return tr1_t<operator_p, operands_head_t>::template XNOR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename operands_p::operator_t>) {
                if constexpr (tr1_t<operator_p, operands_head_t>::template XNOR<subjects_p>()) {
                    return true;
                } else {
                    return tr1s_t<operator_p, operands_tail_t>::template XNOR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename operands_p::operator_t>) {
                if constexpr (!tr1_t<operator_p, operands_head_t>::template XNOR<subjects_p>()) {
                    return false;
                } else {
                    return tr1s_t<operator_p, operands_tail_t>::template XNOR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, nkr::ts_tr operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1s_t<operator_p, operands_p>::XNOR()
        noexcept
    {
        return XNOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::ts_tr operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1s_t<operator_p, operands_p>::Any()
        noexcept
    {
        return OR<subjects_p>();
    }

    template <
        typename operator_p, nkr::ts_tr operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1s_t<operator_p, operands_p>::Any()
        noexcept
    {
        return Any<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::ts_tr operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1s_t<operator_p, operands_p>::Every()
        noexcept
    {
        return AND<subjects_p>();
    }

    template <
        typename operator_p, nkr::ts_tr operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1s_t<operator_p, operands_p>::Every()
        noexcept
    {
        return Every<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::ts_tr operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1s_t<operator_p, operands_p>::One()
        noexcept
    {
        return XOR<subjects_p>();
    }

    template <
        typename operator_p, nkr::ts_tr operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1s_t<operator_p, operands_p>::One()
        noexcept
    {
        return One<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::ts_tr operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1s_t<operator_p, operands_p>::None()
        noexcept
    {
        return NOR<subjects_p>();
    }

    template <
        typename operator_p, nkr::ts_tr operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr1s_t<operator_p, operands_p>::None()
        noexcept
    {
        return None<nkr::tuple::types_t<subjects_p...>>();
    }

}

namespace nkr {

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2_t<operator_p, operand_p, of_operator_p, of_operand_p>::OR()
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
        typename of_operator_p, typename of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2_t<operator_p, operand_p, of_operator_p, of_operand_p>::OR()
        noexcept
    {
        return OR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2_t<operator_p, operand_p, of_operator_p, of_operand_p>::AND()
        noexcept
    {
        if constexpr (subjects_p::Count() == 1) {
            return tr2<typename subjects_p::head_t, operator_p, operand_p, of_operator_p, of_operand_p>;
        } else {
            if constexpr (tr2<typename subjects_p::head_t, operator_p, operand_p, of_operator_p, of_operand_p>) {
                return AND<typename subjects_p::tail_t>();
            } else {
                return false;
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2_t<operator_p, operand_p, of_operator_p, of_operand_p>::AND()
        noexcept
    {
        return AND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2_t<operator_p, operand_p, of_operator_p, of_operand_p>::XOR()
        noexcept
    {
        return XOR<nkr::boolean::cpp_c<false>, subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2_t<operator_p, operand_p, of_operator_p, of_operand_p>::XOR()
        noexcept
    {
        return XOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2_t<operator_p, operand_p, of_operator_p, of_operand_p>::NOR()
        noexcept
    {
        return !OR<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2_t<operator_p, operand_p, of_operator_p, of_operand_p>::NOR()
        noexcept
    {
        return NOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2_t<operator_p, operand_p, of_operator_p, of_operand_p>::NAND()
        noexcept
    {
        return !AND<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2_t<operator_p, operand_p, of_operator_p, of_operand_p>::NAND()
        noexcept
    {
        return NAND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2_t<operator_p, operand_p, of_operator_p, of_operand_p>::XNOR()
        noexcept
    {
        return !XOR<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2_t<operator_p, operand_p, of_operator_p, of_operand_p>::XNOR()
        noexcept
    {
        return XNOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2_t<operator_p, operand_p, of_operator_p, of_operand_p>::Any()
        noexcept
    {
        return OR<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2_t<operator_p, operand_p, of_operator_p, of_operand_p>::Any()
        noexcept
    {
        return Any<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2_t<operator_p, operand_p, of_operator_p, of_operand_p>::Every()
        noexcept
    {
        return AND<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2_t<operator_p, operand_p, of_operator_p, of_operand_p>::Every()
        noexcept
    {
        return Every<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2_t<operator_p, operand_p, of_operator_p, of_operand_p>::One()
        noexcept
    {
        return XOR<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2_t<operator_p, operand_p, of_operator_p, of_operand_p>::One()
        noexcept
    {
        return One<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2_t<operator_p, operand_p, of_operator_p, of_operand_p>::None()
        noexcept
    {
        return NOR<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2_t<operator_p, operand_p, of_operator_p, of_operand_p>::None()
        noexcept
    {
        return None<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > template <
        nkr::boolean::cpp_ctr state_p, tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2_t<operator_p, operand_p, of_operator_p, of_operand_p>::XOR()
        noexcept
    {
        if constexpr (subjects_p::Count() == 1) {
            if constexpr (state_p::Value()) {
                return !tr2<typename subjects_p::head_t, operator_p, operand_p, of_operator_p, of_operand_p>;
            } else {
                return tr2<typename subjects_p::head_t, operator_p, operand_p, of_operator_p, of_operand_p>;
            }
        } else {
            if constexpr (state_p::Value()) {
                if constexpr (tr2<typename subjects_p::head_t, operator_p, operand_p, of_operator_p, of_operand_p>) {
                    return false;
                } else {
                    return XOR<nkr::boolean::cpp_c<true>, typename subjects_p::tail_t>();
                }
            } else {
                if constexpr (tr2<typename subjects_p::head_t, operator_p, operand_p, of_operator_p, of_operand_p>) {
                    return XOR<nkr::boolean::cpp_c<true>, typename subjects_p::tail_t>();
                } else {
                    return XOR<nkr::boolean::cpp_c<false>, typename subjects_p::tail_t>();
                }
            }
        }
    }

}

namespace nkr { namespace $tr2s_t {

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > class sp1
    {
    public:
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    OR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    OR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    NOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    NOR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    NAND() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    NAND() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XNOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    XNOR() noexcept;

        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    Any() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    Any() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    Every() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    Every() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    One() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    One() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    None() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    None() noexcept;
    };

}}

namespace nkr { namespace $tr2s_t {

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operands_p>::OR()
        noexcept
    {
        using of_operands_head_t = nkr::cpp::access_qualification_of_t<typename of_operands_p::head_t, of_operands_p>;
        using of_operands_tail_t = nkr::cpp::access_qualification_of_t<typename of_operands_p::tail_t, of_operands_p>;

        if constexpr (of_operands_p::Count() == 1) {
            return tr2_t<operator_p, operand_p, of_operator_p, of_operands_head_t>::template OR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (tr2_t<operator_p, operand_p, of_operator_p, of_operands_head_t>::template OR<subjects_p>()) {
                    return true;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operands_tail_t>::template OR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (!tr2_t<operator_p, operand_p, of_operator_p, of_operands_head_t>::template OR<subjects_p>()) {
                    return false;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operands_tail_t>::template OR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operands_p>::OR()
        noexcept
    {
        return OR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operands_p>::AND()
        noexcept
    {
        using of_operands_head_t = nkr::cpp::access_qualification_of_t<typename of_operands_p::head_t, of_operands_p>;
        using of_operands_tail_t = nkr::cpp::access_qualification_of_t<typename of_operands_p::tail_t, of_operands_p>;

        if constexpr (of_operands_p::Count() == 1) {
            return tr2_t<operator_p, operand_p, of_operator_p, of_operands_head_t>::template AND<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (tr2_t<operator_p, operand_p, of_operator_p, of_operands_head_t>::template AND<subjects_p>()) {
                    return true;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operands_tail_t>::template AND<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (!tr2_t<operator_p, operand_p, of_operator_p, of_operands_head_t>::template AND<subjects_p>()) {
                    return false;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operands_tail_t>::template AND<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operands_p>::AND()
        noexcept
    {
        return AND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operands_p>::XOR()
        noexcept
    {
        using of_operands_head_t = nkr::cpp::access_qualification_of_t<typename of_operands_p::head_t, of_operands_p>;
        using of_operands_tail_t = nkr::cpp::access_qualification_of_t<typename of_operands_p::tail_t, of_operands_p>;

        if constexpr (of_operands_p::Count() == 1) {
            return tr2_t<operator_p, operand_p, of_operator_p, of_operands_head_t>::template XOR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (tr2_t<operator_p, operand_p, of_operator_p, of_operands_head_t>::template XOR<subjects_p>()) {
                    return true;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operands_tail_t>::template XOR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (!tr2_t<operator_p, operand_p, of_operator_p, of_operands_head_t>::template XOR<subjects_p>()) {
                    return false;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operands_tail_t>::template XOR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operands_p>::XOR()
        noexcept
    {
        return XOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operands_p>::NOR()
        noexcept
    {
        using of_operands_head_t = nkr::cpp::access_qualification_of_t<typename of_operands_p::head_t, of_operands_p>;
        using of_operands_tail_t = nkr::cpp::access_qualification_of_t<typename of_operands_p::tail_t, of_operands_p>;

        if constexpr (of_operands_p::Count() == 1) {
            return tr2_t<operator_p, operand_p, of_operator_p, of_operands_head_t>::template NOR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (tr2_t<operator_p, operand_p, of_operator_p, of_operands_head_t>::template NOR<subjects_p>()) {
                    return true;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operands_tail_t>::template NOR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (!tr2_t<operator_p, operand_p, of_operator_p, of_operands_head_t>::template NOR<subjects_p>()) {
                    return false;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operands_tail_t>::template NOR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operands_p>::NOR()
        noexcept
    {
        return NOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operands_p>::NAND()
        noexcept
    {
        using of_operands_head_t = nkr::cpp::access_qualification_of_t<typename of_operands_p::head_t, of_operands_p>;
        using of_operands_tail_t = nkr::cpp::access_qualification_of_t<typename of_operands_p::tail_t, of_operands_p>;

        if constexpr (of_operands_p::Count() == 1) {
            return tr2_t<operator_p, operand_p, of_operator_p, of_operands_head_t>::template NAND<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (tr2_t<operator_p, operand_p, of_operator_p, of_operands_head_t>::template NAND<subjects_p>()) {
                    return true;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operands_tail_t>::template NAND<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (!tr2_t<operator_p, operand_p, of_operator_p, of_operands_head_t>::template NAND<subjects_p>()) {
                    return false;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operands_tail_t>::template NAND<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operands_p>::NAND()
        noexcept
    {
        return NAND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operands_p>::XNOR()
        noexcept
    {
        using of_operands_head_t = nkr::cpp::access_qualification_of_t<typename of_operands_p::head_t, of_operands_p>;
        using of_operands_tail_t = nkr::cpp::access_qualification_of_t<typename of_operands_p::tail_t, of_operands_p>;

        if constexpr (of_operands_p::Count() == 1) {
            return tr2_t<operator_p, operand_p, of_operator_p, of_operands_head_t>::template XNOR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (tr2_t<operator_p, operand_p, of_operator_p, of_operands_head_t>::template XNOR<subjects_p>()) {
                    return true;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operands_tail_t>::template XNOR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (!tr2_t<operator_p, operand_p, of_operator_p, of_operands_head_t>::template XNOR<subjects_p>()) {
                    return false;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operands_tail_t>::template XNOR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operands_p>::XNOR()
        noexcept
    {
        return XNOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operands_p>::Any()
        noexcept
    {
        return OR<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operands_p>::Any()
        noexcept
    {
        return Any<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operands_p>::Every()
        noexcept
    {
        return AND<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operands_p>::Every()
        noexcept
    {
        return Every<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operands_p>::One()
        noexcept
    {
        return XOR<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operands_p>::One()
        noexcept
    {
        return One<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operands_p>::None()
        noexcept
    {
        return NOR<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operands_p>::None()
        noexcept
    {
        return None<nkr::tuple::types_t<subjects_p...>>();
    }

}}

namespace nkr {

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2s_t<operator_p, operands_p, of_operator_p, of_operands_p>::OR()
        noexcept
    {
        if constexpr (operands_p::Count() == 1) {
            return $tr2s_t::sp1<operator_p, operands_p::template head_t, of_operator_p, of_operands_p>::template OR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename operands_p::operator_t>) {
                if constexpr ($tr2s_t::sp1<operator_p, operands_p::template head_t, of_operator_p, of_operands_p>::template OR<subjects_p>()) {
                    return true;
                } else {
                    return tr2s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p>::template OR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename operands_p::operator_t>) {
                if constexpr (!$tr2s_t::sp1<operator_p, operands_p::template head_t, of_operator_p, of_operands_p>::template OR<subjects_p>()) {
                    return false;
                } else {
                    return tr2s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p>::template OR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2s_t<operator_p, operands_p, of_operator_p, of_operands_p>::OR()
        noexcept
    {
        return OR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2s_t<operator_p, operands_p, of_operator_p, of_operands_p>::AND()
        noexcept
    {
        if constexpr (operands_p::Count() == 1) {
            return $tr2s_t::sp1<operator_p, operands_p::template head_t, of_operator_p, of_operands_p>::template AND<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename operands_p::operator_t>) {
                if constexpr ($tr2s_t::sp1<operator_p, operands_p::template head_t, of_operator_p, of_operands_p>::template AND<subjects_p>()) {
                    return true;
                } else {
                    return tr2s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p>::template AND<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename operands_p::operator_t>) {
                if constexpr (!$tr2s_t::sp1<operator_p, operands_p::template head_t, of_operator_p, of_operands_p>::template AND<subjects_p>()) {
                    return false;
                } else {
                    return tr2s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p>::template AND<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2s_t<operator_p, operands_p, of_operator_p, of_operands_p>::AND()
        noexcept
    {
        return AND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2s_t<operator_p, operands_p, of_operator_p, of_operands_p>::XOR()
        noexcept
    {
        if constexpr (operands_p::Count() == 1) {
            return $tr2s_t::sp1<operator_p, operands_p::template head_t, of_operator_p, of_operands_p>::template XOR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename operands_p::operator_t>) {
                if constexpr ($tr2s_t::sp1<operator_p, operands_p::template head_t, of_operator_p, of_operands_p>::template XOR<subjects_p>()) {
                    return true;
                } else {
                    return tr2s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p>::template XOR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename operands_p::operator_t>) {
                if constexpr (!$tr2s_t::sp1<operator_p, operands_p::template head_t, of_operator_p, of_operands_p>::template XOR<subjects_p>()) {
                    return false;
                } else {
                    return tr2s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p>::template XOR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2s_t<operator_p, operands_p, of_operator_p, of_operands_p>::XOR()
        noexcept
    {
        return XOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2s_t<operator_p, operands_p, of_operator_p, of_operands_p>::NOR()
        noexcept
    {
        if constexpr (operands_p::Count() == 1) {
            return $tr2s_t::sp1<operator_p, operands_p::template head_t, of_operator_p, of_operands_p>::template NOR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename operands_p::operator_t>) {
                if constexpr ($tr2s_t::sp1<operator_p, operands_p::template head_t, of_operator_p, of_operands_p>::template NOR<subjects_p>()) {
                    return true;
                } else {
                    return tr2s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p>::template NOR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename operands_p::operator_t>) {
                if constexpr (!$tr2s_t::sp1<operator_p, operands_p::template head_t, of_operator_p, of_operands_p>::template NOR<subjects_p>()) {
                    return false;
                } else {
                    return tr2s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p>::template NOR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2s_t<operator_p, operands_p, of_operator_p, of_operands_p>::NOR()
        noexcept
    {
        return NOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2s_t<operator_p, operands_p, of_operator_p, of_operands_p>::NAND()
        noexcept
    {
        if constexpr (operands_p::Count() == 1) {
            return $tr2s_t::sp1<operator_p, operands_p::template head_t, of_operator_p, of_operands_p>::template NAND<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename operands_p::operator_t>) {
                if constexpr ($tr2s_t::sp1<operator_p, operands_p::template head_t, of_operator_p, of_operands_p>::template NAND<subjects_p>()) {
                    return true;
                } else {
                    return tr2s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p>::template NAND<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename operands_p::operator_t>) {
                if constexpr (!$tr2s_t::sp1<operator_p, operands_p::template head_t, of_operator_p, of_operands_p>::template NAND<subjects_p>()) {
                    return false;
                } else {
                    return tr2s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p>::template NAND<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2s_t<operator_p, operands_p, of_operator_p, of_operands_p>::NAND()
        noexcept
    {
        return NAND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2s_t<operator_p, operands_p, of_operator_p, of_operands_p>::XNOR()
        noexcept
    {
        if constexpr (operands_p::Count() == 1) {
            return $tr2s_t::sp1<operator_p, operands_p::template head_t, of_operator_p, of_operands_p>::template XNOR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename operands_p::operator_t>) {
                if constexpr ($tr2s_t::sp1<operator_p, operands_p::template head_t, of_operator_p, of_operands_p>::template XNOR<subjects_p>()) {
                    return true;
                } else {
                    return tr2s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p>::template XNOR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename operands_p::operator_t>) {
                if constexpr (!$tr2s_t::sp1<operator_p, operands_p::template head_t, of_operator_p, of_operands_p>::template XNOR<subjects_p>()) {
                    return false;
                } else {
                    return tr2s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p>::template XNOR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2s_t<operator_p, operands_p, of_operator_p, of_operands_p>::XNOR()
        noexcept
    {
        return XNOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2s_t<operator_p, operands_p, of_operator_p, of_operands_p>::Any()
        noexcept
    {
        return OR<subjects_p>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2s_t<operator_p, operands_p, of_operator_p, of_operands_p>::Any()
        noexcept
    {
        return Any<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2s_t<operator_p, operands_p, of_operator_p, of_operands_p>::Every()
        noexcept
    {
        return AND<subjects_p>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2s_t<operator_p, operands_p, of_operator_p, of_operands_p>::Every()
        noexcept
    {
        return Every<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2s_t<operator_p, operands_p, of_operator_p, of_operands_p>::One()
        noexcept
    {
        return XOR<subjects_p>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2s_t<operator_p, operands_p, of_operator_p, of_operands_p>::One()
        noexcept
    {
        return One<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2s_t<operator_p, operands_p, of_operator_p, of_operands_p>::None()
        noexcept
    {
        return NOR<subjects_p>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::ts_tr of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr2s_t<operator_p, operands_p, of_operator_p, of_operands_p>::None()
        noexcept
    {
        return None<nkr::tuple::types_t<subjects_p...>>();
    }

}

namespace nkr {

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>::OR()
        noexcept
    {
        if constexpr (subjects_p::Count() == 1) {
            return tr3<typename subjects_p::head_t, operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>;
        } else {
            if constexpr (tr3<typename subjects_p::head_t, operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>) {
                return true;
            } else {
                return OR<typename subjects_p::tail_t>();
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>::OR()
        noexcept
    {
        return OR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>::AND()
        noexcept
    {
        if constexpr (subjects_p::Count() == 1) {
            return tr3<typename subjects_p::head_t, operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>;
        } else {
            if constexpr (tr3<typename subjects_p::head_t, operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>) {
                return AND<typename subjects_p::tail_t>();
            } else {
                return false;
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>::AND()
        noexcept
    {
        return AND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>::XOR()
        noexcept
    {
        return XOR<nkr::boolean::cpp_c<false>, subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>::XOR()
        noexcept
    {
        return XOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>::NOR()
        noexcept
    {
        return !OR<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>::NOR()
        noexcept
    {
        return NOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>::NAND()
        noexcept
    {
        return !AND<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>::NAND()
        noexcept
    {
        return NAND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>::XNOR()
        noexcept
    {
        return !XOR<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>::XNOR()
        noexcept
    {
        return XNOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>::Any()
        noexcept
    {
        return OR<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>::Any()
        noexcept
    {
        return Any<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>::Every()
        noexcept
    {
        return AND<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>::Every()
        noexcept
    {
        return Every<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>::One()
        noexcept
    {
        return XOR<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>::One()
        noexcept
    {
        return One<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>::None()
        noexcept
    {
        return NOR<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>::None()
        noexcept
    {
        return None<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > template <
        nkr::boolean::cpp_ctr state_p, tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>::XOR()
        noexcept
    {
        if constexpr (subjects_p::Count() == 1) {
            if constexpr (state_p::Value()) {
                return !tr3<typename subjects_p::head_t, operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>;
            } else {
                return tr3<typename subjects_p::head_t, operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>;
            }
        } else {
            if constexpr (state_p::Value()) {
                if constexpr (tr3<typename subjects_p::head_t, operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>) {
                    return false;
                } else {
                    return XOR<nkr::boolean::cpp_c<true>, typename subjects_p::tail_t>();
                }
            } else {
                if constexpr (tr3<typename subjects_p::head_t, operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>) {
                    return XOR<nkr::boolean::cpp_c<true>, typename subjects_p::tail_t>();
                } else {
                    return XOR<nkr::boolean::cpp_c<false>, typename subjects_p::tail_t>();
                }
            }
        }
    }

}

namespace nkr { namespace $tr3s_t {

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > class sp1
    {
    public:
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    OR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    OR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    NOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    NOR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    NAND() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    NAND() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XNOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    XNOR() noexcept;

        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    Any() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    Any() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    Every() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    Every() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    One() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    One() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    None() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    None() noexcept;
    };

}}

namespace nkr { namespace $tr3s_t {

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > class sp2
    {
    public:
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    OR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    OR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    AND() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    XOR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    NOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    NOR() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    NAND() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    NAND() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    XNOR() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    XNOR() noexcept;

        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    Any() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    Any() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    Every() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    Every() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    One() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    One() noexcept;
        template <tr1<any_tg, nkr::tuple::types_tg> subjects_p>
        static constexpr nkr::boolean::cpp_t    None() noexcept;
        template <tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p>
        static constexpr nkr::boolean::cpp_t    None() noexcept;
    };

}}

namespace nkr { namespace $tr3s_t {

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_p>::OR()
        noexcept
    {
        using of_of_operands_head_t = nkr::cpp::access_qualification_of_t<typename of_of_operands_p::head_t, of_of_operands_p>;
        using of_of_operands_tail_t = nkr::cpp::access_qualification_of_t<typename of_of_operands_p::tail_t, of_of_operands_p>;

        if constexpr (of_of_operands_p::Count() == 1) {
            return tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_head_t>::template OR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename of_of_operands_p::operator_t>) {
                if constexpr (tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_head_t>::template OR<subjects_p>()) {
                    return true;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_tail_t>::template OR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename of_of_operands_p::operator_t>) {
                if constexpr (!tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_head_t>::template OR<subjects_p>()) {
                    return false;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_tail_t>::template OR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_p>::OR()
        noexcept
    {
        return OR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_p>::AND()
        noexcept
    {
        using of_of_operands_head_t = nkr::cpp::access_qualification_of_t<typename of_of_operands_p::head_t, of_of_operands_p>;
        using of_of_operands_tail_t = nkr::cpp::access_qualification_of_t<typename of_of_operands_p::tail_t, of_of_operands_p>;

        if constexpr (of_of_operands_p::Count() == 1) {
            return tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_head_t>::template AND<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename of_of_operands_p::operator_t>) {
                if constexpr (tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_head_t>::template AND<subjects_p>()) {
                    return true;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_tail_t>::template AND<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename of_of_operands_p::operator_t>) {
                if constexpr (!tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_head_t>::template AND<subjects_p>()) {
                    return false;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_tail_t>::template AND<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_p>::AND()
        noexcept
    {
        return AND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_p>::XOR()
        noexcept
    {
        using of_of_operands_head_t = nkr::cpp::access_qualification_of_t<typename of_of_operands_p::head_t, of_of_operands_p>;
        using of_of_operands_tail_t = nkr::cpp::access_qualification_of_t<typename of_of_operands_p::tail_t, of_of_operands_p>;

        if constexpr (of_of_operands_p::Count() == 1) {
            return tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_head_t>::template XOR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename of_of_operands_p::operator_t>) {
                if constexpr (tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_head_t>::template XOR<subjects_p>()) {
                    return true;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_tail_t>::template XOR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename of_of_operands_p::operator_t>) {
                if constexpr (!tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_head_t>::template XOR<subjects_p>()) {
                    return false;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_tail_t>::template XOR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_p>::XOR()
        noexcept
    {
        return XOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_p>::NOR()
        noexcept
    {
        using of_of_operands_head_t = nkr::cpp::access_qualification_of_t<typename of_of_operands_p::head_t, of_of_operands_p>;
        using of_of_operands_tail_t = nkr::cpp::access_qualification_of_t<typename of_of_operands_p::tail_t, of_of_operands_p>;

        if constexpr (of_of_operands_p::Count() == 1) {
            return tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_head_t>::template NOR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename of_of_operands_p::operator_t>) {
                if constexpr (tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_head_t>::template NOR<subjects_p>()) {
                    return true;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_tail_t>::template NOR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename of_of_operands_p::operator_t>) {
                if constexpr (!tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_head_t>::template NOR<subjects_p>()) {
                    return false;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_tail_t>::template NOR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_p>::NOR()
        noexcept
    {
        return NOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_p>::NAND()
        noexcept
    {
        using of_of_operands_head_t = nkr::cpp::access_qualification_of_t<typename of_of_operands_p::head_t, of_of_operands_p>;
        using of_of_operands_tail_t = nkr::cpp::access_qualification_of_t<typename of_of_operands_p::tail_t, of_of_operands_p>;

        if constexpr (of_of_operands_p::Count() == 1) {
            return tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_head_t>::template NAND<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename of_of_operands_p::operator_t>) {
                if constexpr (tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_head_t>::template NAND<subjects_p>()) {
                    return true;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_tail_t>::template NAND<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename of_of_operands_p::operator_t>) {
                if constexpr (!tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_head_t>::template NAND<subjects_p>()) {
                    return false;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_tail_t>::template NAND<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_p>::NAND()
        noexcept
    {
        return NAND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_p>::XNOR()
        noexcept
    {
        using of_of_operands_head_t = nkr::cpp::access_qualification_of_t<typename of_of_operands_p::head_t, of_of_operands_p>;
        using of_of_operands_tail_t = nkr::cpp::access_qualification_of_t<typename of_of_operands_p::tail_t, of_of_operands_p>;

        if constexpr (of_of_operands_p::Count() == 1) {
            return tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_head_t>::template XNOR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename of_of_operands_p::operator_t>) {
                if constexpr (tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_head_t>::template XNOR<subjects_p>()) {
                    return true;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_tail_t>::template XNOR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename of_of_operands_p::operator_t>) {
                if constexpr (!tr3_t<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_head_t>::template XNOR<subjects_p>()) {
                    return false;
                } else {
                    return sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_tail_t>::template XNOR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_p>::XNOR()
        noexcept
    {
        return XNOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_p>::Any()
        noexcept
    {
        return OR<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_p>::Any()
        noexcept
    {
        return Any<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_p>::Every()
        noexcept
    {
        return AND<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_p>::Every()
        noexcept
    {
        return Every<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_p>::One()
        noexcept
    {
        return XOR<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_p>::One()
        noexcept
    {
        return One<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_p>::None()
        noexcept
    {
        return NOR<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp1<operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operands_p>::None()
        noexcept
    {
        return None<nkr::tuple::types_t<subjects_p...>>();
    }

}}

namespace nkr { namespace $tr3s_t {

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp2<operator_p, operand_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::OR()
        noexcept
    {
        if constexpr (of_operands_p::Count() == 1) {
            return sp1<operator_p, operand_p, of_operator_p, of_operands_p::template head_t, of_of_operator_p, of_of_operands_p>::template OR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (sp1<operator_p, operand_p, of_operator_p, of_operands_p::template head_t, of_of_operator_p, of_of_operands_p>::template OR<subjects_p>()) {
                    return true;
                } else {
                    return sp2<operator_p, operand_p, of_operator_p, typename of_operands_p::tail_t, of_of_operator_p, of_of_operands_p>::template OR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (!sp1<operator_p, operand_p, of_operator_p, of_operands_p::template head_t, of_of_operator_p, of_of_operands_p>::template OR<subjects_p>()) {
                    return false;
                } else {
                    return sp2<operator_p, operand_p, of_operator_p, typename of_operands_p::tail_t, of_of_operator_p, of_of_operands_p>::template OR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp2<operator_p, operand_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::OR()
        noexcept
    {
        return OR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp2<operator_p, operand_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::AND()
        noexcept
    {
        if constexpr (of_operands_p::Count() == 1) {
            return sp1<operator_p, operand_p, of_operator_p, of_operands_p::template head_t, of_of_operator_p, of_of_operands_p>::template AND<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (sp1<operator_p, operand_p, of_operator_p, of_operands_p::template head_t, of_of_operator_p, of_of_operands_p>::template AND<subjects_p>()) {
                    return true;
                } else {
                    return sp2<operator_p, operand_p, of_operator_p, typename of_operands_p::tail_t, of_of_operator_p, of_of_operands_p>::template AND<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (!sp1<operator_p, operand_p, of_operator_p, of_operands_p::template head_t, of_of_operator_p, of_of_operands_p>::template AND<subjects_p>()) {
                    return false;
                } else {
                    return sp2<operator_p, operand_p, of_operator_p, typename of_operands_p::tail_t, of_of_operator_p, of_of_operands_p>::template AND<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp2<operator_p, operand_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::AND()
        noexcept
    {
        return AND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp2<operator_p, operand_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::XOR()
        noexcept
    {
        if constexpr (of_operands_p::Count() == 1) {
            return sp1<operator_p, operand_p, of_operator_p, of_operands_p::template head_t, of_of_operator_p, of_of_operands_p>::template XOR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (sp1<operator_p, operand_p, of_operator_p, of_operands_p::template head_t, of_of_operator_p, of_of_operands_p>::template XOR<subjects_p>()) {
                    return true;
                } else {
                    return sp2<operator_p, operand_p, of_operator_p, typename of_operands_p::tail_t, of_of_operator_p, of_of_operands_p>::template XOR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (!sp1<operator_p, operand_p, of_operator_p, of_operands_p::template head_t, of_of_operator_p, of_of_operands_p>::template XOR<subjects_p>()) {
                    return false;
                } else {
                    return sp2<operator_p, operand_p, of_operator_p, typename of_operands_p::tail_t, of_of_operator_p, of_of_operands_p>::template XOR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp2<operator_p, operand_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::XOR()
        noexcept
    {
        return XOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp2<operator_p, operand_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::NOR()
        noexcept
    {
        if constexpr (of_operands_p::Count() == 1) {
            return sp1<operator_p, operand_p, of_operator_p, of_operands_p::template head_t, of_of_operator_p, of_of_operands_p>::template NOR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (sp1<operator_p, operand_p, of_operator_p, of_operands_p::template head_t, of_of_operator_p, of_of_operands_p>::template NOR<subjects_p>()) {
                    return true;
                } else {
                    return sp2<operator_p, operand_p, of_operator_p, typename of_operands_p::tail_t, of_of_operator_p, of_of_operands_p>::template NOR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (!sp1<operator_p, operand_p, of_operator_p, of_operands_p::template head_t, of_of_operator_p, of_of_operands_p>::template NOR<subjects_p>()) {
                    return false;
                } else {
                    return sp2<operator_p, operand_p, of_operator_p, typename of_operands_p::tail_t, of_of_operator_p, of_of_operands_p>::template NOR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp2<operator_p, operand_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::NOR()
        noexcept
    {
        return NOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp2<operator_p, operand_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::NAND()
        noexcept
    {
        if constexpr (of_operands_p::Count() == 1) {
            return sp1<operator_p, operand_p, of_operator_p, of_operands_p::template head_t, of_of_operator_p, of_of_operands_p>::template NAND<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (sp1<operator_p, operand_p, of_operator_p, of_operands_p::template head_t, of_of_operator_p, of_of_operands_p>::template NAND<subjects_p>()) {
                    return true;
                } else {
                    return sp2<operator_p, operand_p, of_operator_p, typename of_operands_p::tail_t, of_of_operator_p, of_of_operands_p>::template NAND<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (!sp1<operator_p, operand_p, of_operator_p, of_operands_p::template head_t, of_of_operator_p, of_of_operands_p>::template NAND<subjects_p>()) {
                    return false;
                } else {
                    return sp2<operator_p, operand_p, of_operator_p, typename of_operands_p::tail_t, of_of_operator_p, of_of_operands_p>::template NAND<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp2<operator_p, operand_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::NAND()
        noexcept
    {
        return NAND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp2<operator_p, operand_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::XNOR()
        noexcept
    {
        if constexpr (of_operands_p::Count() == 1) {
            return sp1<operator_p, operand_p, of_operator_p, of_operands_p::template head_t, of_of_operator_p, of_of_operands_p>::template XNOR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (sp1<operator_p, operand_p, of_operator_p, of_operands_p::template head_t, of_of_operator_p, of_of_operands_p>::template XNOR<subjects_p>()) {
                    return true;
                } else {
                    return sp2<operator_p, operand_p, of_operator_p, typename of_operands_p::tail_t, of_of_operator_p, of_of_operands_p>::template XNOR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename of_operands_p::operator_t>) {
                if constexpr (!sp1<operator_p, operand_p, of_operator_p, of_operands_p::template head_t, of_of_operator_p, of_of_operands_p>::template XNOR<subjects_p>()) {
                    return false;
                } else {
                    return sp2<operator_p, operand_p, of_operator_p, typename of_operands_p::tail_t, of_of_operator_p, of_of_operands_p>::template XNOR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp2<operator_p, operand_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::XNOR()
        noexcept
    {
        return XNOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp2<operator_p, operand_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::Any()
        noexcept
    {
        return OR<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp2<operator_p, operand_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::Any()
        noexcept
    {
        return Any<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp2<operator_p, operand_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::Every()
        noexcept
    {
        return AND<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp2<operator_p, operand_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::Every()
        noexcept
    {
        return Every<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp2<operator_p, operand_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::One()
        noexcept
    {
        return XOR<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp2<operator_p, operand_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::One()
        noexcept
    {
        return One<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp2<operator_p, operand_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::None()
        noexcept
    {
        return NOR<subjects_p>();
    }

    template <
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        sp2<operator_p, operand_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::None()
        noexcept
    {
        return None<nkr::tuple::types_t<subjects_p...>>();
    }

}}

namespace nkr {

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3s_t<operator_p, operands_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::OR()
        noexcept
    {
        if constexpr (operands_p::Count() == 1) {
            return $tr3s_t::sp2<operator_p, operands_p::template head_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template OR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename operands_p::operator_t>) {
                if constexpr ($tr3s_t::sp2<operator_p, operands_p::template head_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template OR<subjects_p>()) {
                    return true;
                } else {
                    return tr3s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template OR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename operands_p::operator_t>) {
                if constexpr (!$tr3s_t::sp2<operator_p, operands_p::template head_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template OR<subjects_p>()) {
                    return false;
                } else {
                    return tr3s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template OR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3s_t<operator_p, operands_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::OR()
        noexcept
    {
        return OR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3s_t<operator_p, operands_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::AND()
        noexcept
    {
        if constexpr (operands_p::Count() == 1) {
            return $tr3s_t::sp2<operator_p, operands_p::template head_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template AND<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename operands_p::operator_t>) {
                if constexpr ($tr3s_t::sp2<operator_p, operands_p::template head_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template AND<subjects_p>()) {
                    return true;
                } else {
                    return tr3s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template AND<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename operands_p::operator_t>) {
                if constexpr (!$tr3s_t::sp2<operator_p, operands_p::template head_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template AND<subjects_p>()) {
                    return false;
                } else {
                    return tr3s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template AND<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3s_t<operator_p, operands_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::AND()
        noexcept
    {
        return AND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3s_t<operator_p, operands_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::XOR()
        noexcept
    {
        if constexpr (operands_p::Count() == 1) {
            return $tr3s_t::sp2<operator_p, operands_p::template head_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template XOR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename operands_p::operator_t>) {
                if constexpr ($tr3s_t::sp2<operator_p, operands_p::template head_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template XOR<subjects_p>()) {
                    return true;
                } else {
                    return tr3s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template XOR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename operands_p::operator_t>) {
                if constexpr (!$tr3s_t::sp2<operator_p, operands_p::template head_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template XOR<subjects_p>()) {
                    return false;
                } else {
                    return tr3s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template XOR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3s_t<operator_p, operands_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::XOR()
        noexcept
    {
        return XOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3s_t<operator_p, operands_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::NOR()
        noexcept
    {
        if constexpr (operands_p::Count() == 1) {
            return $tr3s_t::sp2<operator_p, operands_p::template head_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template NOR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename operands_p::operator_t>) {
                if constexpr ($tr3s_t::sp2<operator_p, operands_p::template head_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template NOR<subjects_p>()) {
                    return true;
                } else {
                    return tr3s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template NOR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename operands_p::operator_t>) {
                if constexpr (!$tr3s_t::sp2<operator_p, operands_p::template head_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template NOR<subjects_p>()) {
                    return false;
                } else {
                    return tr3s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template NOR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3s_t<operator_p, operands_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::NOR()
        noexcept
    {
        return NOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3s_t<operator_p, operands_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::NAND()
        noexcept
    {
        if constexpr (operands_p::Count() == 1) {
            return $tr3s_t::sp2<operator_p, operands_p::template head_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template NAND<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename operands_p::operator_t>) {
                if constexpr ($tr3s_t::sp2<operator_p, operands_p::template head_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template NAND<subjects_p>()) {
                    return true;
                } else {
                    return tr3s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template NAND<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename operands_p::operator_t>) {
                if constexpr (!$tr3s_t::sp2<operator_p, operands_p::template head_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template NAND<subjects_p>()) {
                    return false;
                } else {
                    return tr3s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template NAND<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3s_t<operator_p, operands_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::NAND()
        noexcept
    {
        return NAND<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3s_t<operator_p, operands_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::XNOR()
        noexcept
    {
        if constexpr (operands_p::Count() == 1) {
            return $tr3s_t::sp2<operator_p, operands_p::template head_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template XNOR<subjects_p>();
        } else {
            if constexpr (nkr::$tr::OR_operator_tr<typename operands_p::operator_t>) {
                if constexpr ($tr3s_t::sp2<operator_p, operands_p::template head_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template XNOR<subjects_p>()) {
                    return true;
                } else {
                    return tr3s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template XNOR<subjects_p>();
                }
            } else if constexpr (nkr::$tr::AND_operator_tr<typename operands_p::operator_t>) {
                if constexpr (!$tr3s_t::sp2<operator_p, operands_p::template head_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template XNOR<subjects_p>()) {
                    return false;
                } else {
                    return tr3s_t<operator_p, typename operands_p::tail_t, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::template XNOR<subjects_p>();
                }
            }
        }
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3s_t<operator_p, operands_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::XNOR()
        noexcept
    {
        return XNOR<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3s_t<operator_p, operands_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::Any()
        noexcept
    {
        return OR<subjects_p>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3s_t<operator_p, operands_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::Any()
        noexcept
    {
        return Any<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3s_t<operator_p, operands_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::Every()
        noexcept
    {
        return AND<subjects_p>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3s_t<operator_p, operands_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::Every()
        noexcept
    {
        return Every<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3s_t<operator_p, operands_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::One()
        noexcept
    {
        return XOR<subjects_p>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3s_t<operator_p, operands_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::One()
        noexcept
    {
        return One<nkr::tuple::types_t<subjects_p...>>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<any_tg, nkr::tuple::types_tg> subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3s_t<operator_p, operands_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::None()
        noexcept
    {
        return NOR<subjects_p>();
    }

    template <
        typename operator_p, nkr::tts_tr operands_p,
        typename of_operator_p, nkr::tts_tr of_operands_p,
        typename of_of_operator_p, nkr::ts_tr of_of_operands_p
    > template <
        tr1<not_any_tg, nkr::tuple::types_tg> ...subjects_p
    > inline constexpr nkr::boolean::cpp_t
        tr3s_t<operator_p, operands_p, of_operator_p, of_operands_p, of_of_operator_p, of_of_operands_p>::None()
        noexcept
    {
        return None<nkr::tuple::types_t<subjects_p...>>();
    }

}
