/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_48573e4c_1573_4c63_9f00_388757be4a7b
#define nkr_INCLUDE_GUARD_48573e4c_1573_4c63_9f00_388757be4a7b

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/cpp/generic/randomness/generator_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/tr_dec.h"

namespace nkr { namespace negatable {

    struct  real_32_tg  { class tag_lb; };

    template <typename type_p>
    concept real_32_tr =
        nkr::cpp::is_any_tr<type_p, real_32_t> ||
        (nkr::cpp::negatable_real_tr<type_p> && sizeof(type_p) * 8 == 32);

}}

namespace nkr { namespace negatable { namespace real_32_t$ {

    template <nkr::negatable::real_32_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::negatable::real_32_tg> type_p>
    class type_i_tag_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_tag_sp(...) noexcept   = delete;
    };

}}}

namespace nkr { namespace interface {

    template <nkr::negatable::real_32_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::negatable::real_32_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::negatable::real_32_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::negatable::real_32_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace negatable { namespace real_32_t$ {

    template <nkr::negatable::real_32_tr type_p>
    class none_value_i_sp
    {
    public:
        using type_t    = type_p;
        using value_t   = nkr::cpp::just_non_qualified_t<type_t>;

    public:
        static constexpr value_t    Value() noexcept;

    public:
        template <typename ...>
        constexpr none_value_i_sp(...) noexcept = delete;
    };

}}}

namespace nkr { namespace interface { namespace none {

    template <nkr::negatable::real_32_tr type_p>
    class value_i_sp<type_p>
    {
    public:
        using type_t    = nkr::negatable::real_32_t$::none_value_i_sp<type_p>;
    };

}}}

namespace nkr { namespace negatable { namespace real_32_t$ {

    template <nkr::negatable::real_32_tr type_p>
    class randomness_distributor_uniform_i_sp
    {
    public:
        using type_t    = type_p;
        using value_t   = nkr::cpp::just_non_qualified_t<type_t>;
        using number_t  = value_t;

    public:
        static constexpr value_t    Default_Min() noexcept;
        static constexpr value_t    Default_Max() noexcept;

        static constexpr number_t   To_Number(value_t value) noexcept;
        static constexpr value_t    From_Number(number_t number) noexcept;

    public:
        template <typename ...>
        constexpr randomness_distributor_uniform_i_sp(...) noexcept = delete;
    };

}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor {

    template <nkr::negatable::real_32_tr type_p>
    class uniform_i_sp<type_p>
    {
    public:
        using type_t    = nkr::negatable::real_32_t$::randomness_distributor_uniform_i_sp<type_p>;
    };

}}}}

namespace nkr { namespace negatable { namespace real_32_t$ {

    template <nkr::negatable::real_32_tr type_p>
    class randomness_value_i_sp
    {
    public:
        using type_t    = type_p;
        using value_t   = nkr::cpp::just_non_qualified_t<type_t>;

    public:
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(value_t min = nkr::cpp::Default_Min<value_t>(), value_t max = nkr::cpp::Default_Max<value_t>()) noexcept;
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                              value_t min = nkr::cpp::Default_Min<value_t>(), value_t max = nkr::cpp::Default_Max<value_t>()) noexcept;

    public:
        template <typename ...>
        constexpr randomness_value_i_sp(...) noexcept   = delete;
    };

}}}

namespace nkr { namespace interface { namespace randomness {

    template <nkr::negatable::real_32_tr type_p>
    class value_i_sp<type_p>
    {
    public:
        using type_t    = nkr::negatable::real_32_t$::randomness_value_i_sp<type_p>;
    };

}}}

#include "nkr/negatable/real_32_t_dec_def.h"

#endif
