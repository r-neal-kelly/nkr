/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_2e70ba8e_7a97_4d13_ac4b_909ac1f9ab6f
#define nkr_INCLUDE_GUARD_2e70ba8e_7a97_4d13_ac4b_909ac1f9ab6f

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/negatable/integer_8_t_dec.h"
#include "nkr/negatable/integer_16_t_dec.h"
#include "nkr/negatable/integer_32_t_dec.h"
#include "nkr/negatable/integer_64_t_dec.h"

namespace nkr { namespace negatable {

    struct  integer_tg  { class tag_lb; };

    template <typename type_p>
    concept integer_tr =
        nkr::cpp::is_any_tr<type_p, integer_t> ||
        (nkr::cpp::negatable_integer_tr<type_p> && sizeof(type_p) == sizeof(integer_t));

}}

namespace nkr { namespace negatable { namespace integer_t$ {

    template <nkr::cpp::is_any_tr<nkr::negatable::integer_tg> type_p>
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

    template <nkr::cpp::is_any_tr<nkr::negatable::integer_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::negatable::integer_t$::type_i_tag_sp<type_p>;
    };

}}

#include "nkr/negatable/integer_t_dec_def.h"

#endif
