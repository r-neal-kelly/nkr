/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_7609e36c_d06f_4b37_9782_647f0b0a5016
#define nkr_INCLUDE_GUARD_7609e36c_d06f_4b37_9782_647f0b0a5016

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/negatable/real_32_t_dec.h"
#include "nkr/negatable/real_64_t_dec.h"

namespace nkr { namespace negatable {

    struct  real_tg { class tag_lb; };

    template <typename type_p>
    concept real_tr =
        nkr::cpp::is_any_tr<type_p, real_t> ||
        (nkr::cpp::negatable_real_tr<type_p> && sizeof(type_p) == sizeof(real_t));

}}

namespace nkr { namespace negatable { namespace real_t$ {

    template <nkr::cpp::is_any_tr<nkr::negatable::real_tg> type_p>
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

    template <nkr::cpp::is_any_tr<nkr::negatable::real_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::negatable::real_t$::type_i_tag_sp<type_p>;
    };

}}

#include "nkr/negatable/real_t_dec_def.h"

#endif
