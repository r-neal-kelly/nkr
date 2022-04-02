/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_66ba7a16_718f_4b2a_a40e_b8690687a440
#define nkr_INCLUDE_GUARD_66ba7a16_718f_4b2a_a40e_b8690687a440

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"

namespace nkr { namespace constant { namespace negatable {

    template <nkr::negatable::real_t value_p>
    using real_t =
        nkr::constant_t<nkr::negatable::real_t, value_p>;

    template <typename type_p>
    concept real_tr =
        nkr::constant_tr<type_p> &&
        nkr::cpp::is_tr<typename type_p::value_t, nkr::negatable::real_t>;

    class real_tg
    {
    public:
        class   tag_lb      {};
        class   type_lb     {};
        class   identity_lb {};
    };

}}}

namespace nkr { namespace constant { namespace negatable { namespace real_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::real_tg> type_p>
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

}}}}

namespace nkr { namespace interface {

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::real_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::constant::negatable::real_t$::type_i_tag_sp<type_p>;
    };

}}

#include "nkr/constant/negatable/real_t_dec_def.h"

#endif
