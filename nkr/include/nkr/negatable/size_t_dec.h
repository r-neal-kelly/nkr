/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_3e93f5c7_0ff9_483c_b263_8480ddbd2c10
#define nkr_INCLUDE_GUARD_3e93f5c7_0ff9_483c_b263_8480ddbd2c10

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/negatable/integer_t_dec.h"

namespace nkr { namespace negatable {

    struct  size_tg { class tag_lb; };

    template <typename type_p>
    concept size_tr =
        nkr::cpp::is_any_tr<type_p, size_t> ||
        (nkr::cpp::negatable_integer_tr<type_p> && sizeof(type_p) == sizeof(size_t));

}}

namespace nkr { namespace negatable { namespace size_t$ {

    template <nkr::cpp::is_any_tr<nkr::negatable::size_tg> type_p>
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

    template <nkr::cpp::is_any_tr<nkr::negatable::size_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::negatable::size_t$::type_i_tag_sp<type_p>;
    };

}}

#include "nkr/negatable/size_t_dec_def.h"

#endif
