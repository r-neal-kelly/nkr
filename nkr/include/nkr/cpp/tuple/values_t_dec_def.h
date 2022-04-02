/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_28f3a737_9b95_4630_bd44_0cd64295c5f5
#define nkr_INCLUDE_GUARD_28f3a737_9b95_4630_bd44_0cd64295c5f5

#include "nkr/cpp/tuple/values_t_dec.h"

namespace nkr { namespace cpp { namespace tuple { namespace values_t$ {

    template <typename type_p>
    class is_tmpl :
        public nkr::constant::boolean::cpp_t<false>
    {
    public:
    };

    template <typename ...types_p>
    class is_tmpl<nkr::cpp::tuple::values_t<types_p...>> :
        public nkr::constant::boolean::cpp_t<true>
    {
    public:
    };

    template <typename head_p, typename ...tail_p>
    class is_tmpl<nkr::cpp::tuple::values_t<head_p, tail_p...>> :
        public nkr::constant::boolean::cpp_t<true>
    {
    public:
    };

    template <nkr::cpp::tuple::values_tr tuple_p>
        requires (std::tuple_size<nkr::cpp::just_non_qualified_t<tuple_p>>::value == 0)
    class of_tmpl<tuple_p>
    {
    public:
        using type_t    = nkr::none::type_t;
    };

    template <nkr::cpp::tuple::values_tr tuple_p>
        requires (std::tuple_size<nkr::cpp::just_non_qualified_t<tuple_p>>::value > 0)
    class of_tmpl<tuple_p>
    {
    public:
        using type_t    = std::tuple_element<0, nkr::cpp::just_non_qualified_t<tuple_p>>::type;
    };

}}}}

namespace nkr { namespace cpp { namespace tuple { namespace values_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::cpp::tuple::values_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::cpp::tuple::values_tg>;
    }

    template <nkr::cpp::tuple::values_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::tuple::values_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::tuple::values_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::tuple::values_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::tuple::values_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::tuple::values_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
