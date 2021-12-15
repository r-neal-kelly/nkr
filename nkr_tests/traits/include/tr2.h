/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "tr.h"

namespace nkr { namespace traits {

    template <typename tag_p>
    class assert_t
    {
    public:
        template <typename subject_p, template <typename ...> typename template_p, typename of_tag_p, typename of_p>
        static void_t constexpr Is()
        {
            static_assert(false, "missing specialization for this tag");
        }

        template <typename subject_p, template <typename ...> typename template_p, typename of_tag_p, typename of_p>
        static void_t constexpr Is_Opposite()
        {
            static_assert(false, "missing specialization for this tag");
        }

        template <typename subject_p, template <typename ...> typename template_p, typename of_tag_p, typename of_p>
        static void_t constexpr Not_Is()
        {
            static_assert(false, "missing specialization for this tag");
        }

        template <typename subject_p, template <typename ...> typename template_p, typename of_tag_p, typename of_p>
        static void_t constexpr Not_Is_Opposite()
        {
            static_assert(false, "missing specialization for this tag");
        }
    };

    template <c_bool_t is_true_p, typename tag_p, typename of_tag_p, typename of_p>
    void_t constexpr Assert_Tagged_Container_Of_Matching_Type()
    {
        if constexpr (is_true_p) {
            assert_t<tag_p>::template Is<std::add_pointer_t<of_p>, c_pointer_ttg, of_tag_p, of_p>();
            assert_t<tag_p>::template Is<value_template_t<of_p>, value_template_t, of_tag_p, of_p>();
            assert_t<tag_p>::template Is<unit_template_t<of_p>, unit_template_t, of_tag_p, of_p>();

            if constexpr (!is_any_tr<of_p, void_t>) {
                assert_t<tag_p>::template Is<of_p[1], c_array_ttg, of_tag_p, of_p>();
            }
        } else {
            assert_t<tag_p>::template Not_Is<std::add_pointer_t<of_p>, c_pointer_ttg, of_tag_p, of_p>();
            assert_t<tag_p>::template Not_Is<value_template_t<of_p>, value_template_t, of_tag_p, of_p>();
            assert_t<tag_p>::template Not_Is<unit_template_t<of_p>, unit_template_t, of_tag_p, of_p>();

            if constexpr (!is_any_tr<of_p, void_t>) {
                assert_t<tag_p>::template Not_Is<of_p[1], c_array_ttg, of_tag_p, of_p>();
            }
        }
    }

    template <c_bool_t is_true_p, typename tag_p, typename of_tag_p, typename of_p>
    void_t constexpr Assert_Tagged_Container_Of_Non_Matching_Type()
    {
        if constexpr (is_true_p) {
            assert_t<tag_p>::template Is<std::add_pointer_t<non_match_t>, c_pointer_ttg, of_tag_p, of_p>();
            assert_t<tag_p>::template Is<value_template_t<non_match_t>, value_template_t, of_tag_p, of_p>();
            assert_t<tag_p>::template Is<unit_template_t<non_match_t>, unit_template_t, of_tag_p, of_p>();

            if constexpr (!is_any_tr<of_p, void_t>) {
                if constexpr (just_non_qualified_tr<of_p>) {
                    assert_t<tag_p>::template Is<non_match_t[1], c_array_ttg, of_tag_p, of_p>();
                } else if constexpr (just_const_tr<of_p>) {
                    assert_t<tag_p>::template Is<const non_match_t[1], c_array_ttg, of_tag_p, of_p>();
                } else if constexpr (just_volatile_tr<of_p>) {
                    assert_t<tag_p>::template Is<volatile non_match_t[1], c_array_ttg, of_tag_p, of_p>();
                } else if constexpr (just_const_volatile_tr<of_p>) {
                    assert_t<tag_p>::template Is<const volatile non_match_t[1], c_array_ttg, of_tag_p, of_p>();
                }
            }
        } else {
            assert_t<tag_p>::template Not_Is<std::add_pointer_t<non_match_t>, c_pointer_ttg, of_tag_p, of_p>();
            assert_t<tag_p>::template Not_Is<value_template_t<non_match_t>, value_template_t, of_tag_p, of_p>();
            assert_t<tag_p>::template Not_Is<unit_template_t<non_match_t>, unit_template_t, of_tag_p, of_p>();

            if constexpr (!is_any_tr<of_p, void_t>) {
                if constexpr (just_non_qualified_tr<of_p>) {
                    assert_t<tag_p>::template Not_Is<non_match_t[1], c_array_ttg, of_tag_p, of_p>();
                } else if constexpr (just_const_tr<of_p>) {
                    assert_t<tag_p>::template Not_Is<const non_match_t[1], c_array_ttg, of_tag_p, of_p>();
                } else if constexpr (just_volatile_tr<of_p>) {
                    assert_t<tag_p>::template Not_Is<volatile non_match_t[1], c_array_ttg, of_tag_p, of_p>();
                } else if constexpr (just_const_volatile_tr<of_p>) {
                    assert_t<tag_p>::template Not_Is<const volatile non_match_t[1], c_array_ttg, of_tag_p, of_p>();
                }
            }
        }
    }

    template <c_bool_t is_true_p, typename tag_p, typename of_tag_p, typename of_p>
    void_t constexpr Assert_Non_Tagged_Container_Of_Matching_Type()
    {
        if constexpr (is_true_p) {
            assert_t<tag_p>::template Is_Opposite<std::add_pointer_t<of_p>, c_pointer_ttg, of_tag_p, of_p>();
            assert_t<tag_p>::template Is_Opposite<value_template_t<of_p>, value_template_t, of_tag_p, of_p>();
            assert_t<tag_p>::template Is_Opposite<unit_template_t<of_p>, unit_template_t, of_tag_p, of_p>();
        } else {
            assert_t<tag_p>::template Not_Is_Opposite<std::add_pointer_t<of_p>, c_pointer_ttg, of_tag_p, of_p>();
            assert_t<tag_p>::template Not_Is_Opposite<value_template_t<of_p>, value_template_t, of_tag_p, of_p>();
            assert_t<tag_p>::template Not_Is_Opposite<unit_template_t<of_p>, unit_template_t, of_tag_p, of_p>();
        }
    }

    template <c_bool_t is_true_p, typename tag_p, typename of_tag_p, typename of_p>
    void_t constexpr Assert_Non_Tagged_Container_Of_Non_Matching_Type()
    {
        if constexpr (is_true_p) {
            assert_t<tag_p>::template Is_Opposite<std::add_pointer_t<non_match_t>, c_pointer_ttg, of_tag_p, of_p>();
            assert_t<tag_p>::template Is_Opposite<value_template_t<non_match_t>, value_template_t, of_tag_p, of_p>();
            assert_t<tag_p>::template Is_Opposite<unit_template_t<non_match_t>, unit_template_t, of_tag_p, of_p>();
        } else {
            assert_t<tag_p>::template Not_Is_Opposite<std::add_pointer_t<non_match_t>, c_pointer_ttg, of_tag_p, of_p>();
            assert_t<tag_p>::template Not_Is_Opposite<value_template_t<non_match_t>, value_template_t, of_tag_p, of_p>();
            assert_t<tag_p>::template Not_Is_Opposite<unit_template_t<non_match_t>, unit_template_t, of_tag_p, of_p>();
        }
    }

    template <c_bool_t is_true_p, typename tag_p, typename of_tag_p, typename of_p>
    void_t constexpr Assert_Non_Container()
    {
        if constexpr (is_true_p) {
            assert_t<tag_p>::template Is<non_match_t, c_pointer_ttg, of_tag_p, of_p>();
            assert_t<tag_p>::template Is<non_match_t, value_template_t, of_tag_p, of_p>();
            assert_t<tag_p>::template Is<non_match_t, unit_template_t, of_tag_p, of_p>();

            assert_t<tag_p>::template Is_Opposite<non_match_t, c_pointer_ttg, of_tag_p, of_p>();
            assert_t<tag_p>::template Is_Opposite<non_match_t, value_template_t, of_tag_p, of_p>();
            assert_t<tag_p>::template Is_Opposite<non_match_t, unit_template_t, of_tag_p, of_p>();
        } else {
            assert_t<tag_p>::template Not_Is<non_match_t, c_pointer_ttg, of_tag_p, of_p>();
            assert_t<tag_p>::template Not_Is<non_match_t, value_template_t, of_tag_p, of_p>();
            assert_t<tag_p>::template Not_Is<non_match_t, unit_template_t, of_tag_p, of_p>();

            assert_t<tag_p>::template Not_Is_Opposite<non_match_t, c_pointer_ttg, of_tag_p, of_p>();
            assert_t<tag_p>::template Not_Is_Opposite<non_match_t, value_template_t, of_tag_p, of_p>();
            assert_t<tag_p>::template Not_Is_Opposite<non_match_t, unit_template_t, of_tag_p, of_p>();
        }
    }

}}
