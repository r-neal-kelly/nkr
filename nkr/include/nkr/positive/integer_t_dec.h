/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_189caa74_ebfa_4696_8ae5_2ffbf283ae99
#define nkr_INCLUDE_GUARD_189caa74_ebfa_4696_8ae5_2ffbf283ae99

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/positive/integer_8_t_dec.h"
#include "nkr/positive/integer_16_t_dec.h"
#include "nkr/positive/integer_32_t_dec.h"
#include "nkr/positive/integer_64_t_dec.h"

namespace nkr { namespace positive {

    struct  integer_tg  { class tag_lb; };

    template <typename type_p>
    concept integer_tr =
        nkr::cpp::is_any_tr<type_p, integer_t> ||
        (nkr::cpp::positive_integer_tr<type_p> && sizeof(type_p) == sizeof(integer_t));

}}

namespace nkr { namespace positive { namespace integer_t$ {

    template <nkr::cpp::is_any_tr<nkr::positive::integer_tg> type_p>
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

    template <nkr::cpp::is_any_tr<nkr::positive::integer_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::positive::integer_t$::type_i_tag_sp<type_p>;
    };

}}

#include "nkr/positive/integer_t_dec_def.h"

#endif
