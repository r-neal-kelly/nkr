/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_99f4eb63_ad3e_48f9_b006_75ccf155788d
#define nkr_INCLUDE_GUARD_99f4eb63_ad3e_48f9_b006_75ccf155788d

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/cpp/randomness/generator/software/mersenne_twister_t_dec.h"
#include "nkr/interface/forward_dec.h"

namespace nkr { namespace cpp { namespace randomness { namespace generator { namespace software {

    using   mersenne_twister_19937_64_t =
        std::mt19937_64;

    struct  mersenne_twister_19937_64_tg    { class tag_lb; };

    template <typename type_p>
    concept mersenne_twister_19937_64_tr =
        nkr::cpp::is_any_tr<type_p, mersenne_twister_19937_64_t>;

}}}}}

namespace nkr { namespace cpp { namespace randomness { namespace generator { namespace software { namespace mersenne_twister_19937_64_t$ {

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::generator::software::mersenne_twister_19937_64_tg> type_p>
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

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::generator::software::mersenne_twister_19937_64_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::randomness::generator::software::mersenne_twister_19937_64_t$::type_i_tag_sp<type_p>;
    };

}}

#include "nkr/cpp/randomness/generator/software/mersenne_twister_19937_64_t_dec_def.h"

#endif
