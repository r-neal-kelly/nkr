/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_6f760ba1_7a3c_485e_8059_26f1092e4877
#define nkr_INCLUDE_GUARD_6f760ba1_7a3c_485e_8059_26f1092e4877

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/cpp/randomness/generator/software/mersenne_twister_t_dec.h"
#include "nkr/interface/forward_dec.h"

namespace nkr { namespace cpp { namespace randomness { namespace generator { namespace software {

    using   mersenne_twister_19937_32_t =
        std::mt19937;

    struct  mersenne_twister_19937_32_tg    { class tag_lb; };

    template <typename type_p>
    concept mersenne_twister_19937_32_tr =
        nkr::cpp::is_any_tr<type_p, mersenne_twister_19937_32_t>;

}}}}}

namespace nkr { namespace cpp { namespace randomness { namespace generator { namespace software { namespace mersenne_twister_19937_32_t$ {

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::generator::software::mersenne_twister_19937_32_tg> type_p>
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

}}}}}}

namespace nkr { namespace interface {

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::generator::software::mersenne_twister_19937_32_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::randomness::generator::software::mersenne_twister_19937_32_t$::type_i_tag_sp<type_p>;
    };

}}

#include "nkr/cpp/randomness/generator/software/mersenne_twister_19937_32_t_dec_def.h"

#endif
