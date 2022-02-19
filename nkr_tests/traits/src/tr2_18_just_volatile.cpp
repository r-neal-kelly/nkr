/*
    Copyright 2022 r-neal-kelly
*/

#include "tr2.h"

namespace nkr { namespace traits {

    template <>
    class assert_t<just_volatile_tg>
    {
    public:
        template <typename subject_p, template <typename ...> typename template_p, typename of_tag_p, typename of_p>
        static void_t constexpr Is()
        {
            if constexpr (c_array_tr<subject_p>) {
                if constexpr (tr0<of_p, just_volatile_tg>) {
                    static_assert(tr2<subject_p,
                                  just_volatile_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
                }
            } else {
                static_assert(any_non_qualified_tr<subject_p>);

                static_assert(tr2<volatile subject_p,
                              just_volatile_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
            }
        }

        template <typename subject_p, template <typename ...> typename template_p, typename of_tag_p, typename of_p>
        static void_t constexpr Is_Opposite()
        {
            static_assert(any_non_qualified_tr<subject_p>);
            static_assert(!c_array_tr<subject_p>);

            static_assert(tr2<subject_p,
                          just_volatile_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
            static_assert(tr2<const subject_p,
                          just_volatile_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
            static_assert(tr2<const volatile subject_p,
                          just_volatile_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
        }

        template <typename subject_p, template <typename ...> typename template_p, typename of_tag_p, typename of_p>
        static void_t constexpr Not_Is()
        {
            if constexpr (c_array_tr<subject_p>) {
                static_assert(!tr2<subject_p,
                              just_volatile_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
            } else {
                static_assert(any_non_qualified_tr<subject_p>);

                static_assert(!tr2<volatile subject_p,
                              just_volatile_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
            }
        }

        template <typename subject_p, template <typename ...> typename template_p, typename of_tag_p, typename of_p>
        static void_t constexpr Not_Is_Opposite()
        {
            static_assert(any_non_qualified_tr<subject_p>);
            static_assert(!c_array_tr<subject_p>);

            static_assert(!tr2<subject_p,
                          just_volatile_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
            static_assert(!tr2<const subject_p,
                          just_volatile_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
            static_assert(!tr2<const volatile subject_p,
                          just_volatile_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
        }
    };

    TEST_SUITE("just_volatile_tg")
    {

    }

}}
