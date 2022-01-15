/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/generic/built_in/boolean_tr_dec.h"
#include "nkr/generic/built_in/number/enumeration/limited_tr_dec.h"
#include "nkr/generic/built_in/number/integer_tr_dec.h"
#include "nkr/generic/built_in/number/real_tr_dec.h"
#include "nkr/generic/built_in/pointer_tr_dec.h"
#include "nkr/generic/implementing/constructor/default_tr_dec.h"
#include "nkr/generic/implementing/self_tr_dec.h"
#include "nkr/generic/type_tr_dec.h"

namespace nkr { namespace interface { namespace randomness { namespace distributor { namespace $uniform_i {

    template <typename type_p>
    concept aliases_i =
        nkr::cpp::just_non_qualified_tr<typename type_p::type_t> &&
        nkr::generic::type_tr<typename type_p::type_t> &&
        nkr::generic::implementing::self_tr<typename type_p::type_t> &&

        nkr::cpp::just_non_qualified_tr<typename type_p::number_t> &&
        (nkr::generic::built_in::number::integer_tr<typename type_p::number_t> ||
         nkr::generic::built_in::number::real_tr<typename type_p::number_t>);

    template <typename type_p>
    concept static_functions_i =
        (requires(typename type_p::type_t object,
                  const typename type_p::type_t const_object,
                  volatile typename type_p::type_t volatile_object,
                  const volatile typename type_p::type_t const_volatile_object,

                  typename type_p::number_t number)
    {
        { type_p::Default_Min() }                       -> nkr::cpp::is_tr<typename type_p::type_t>;
        { type_p::Default_Max() }                       -> nkr::cpp::is_tr<typename type_p::type_t>;

        { type_p::To_Number(const_object) }             -> nkr::cpp::is_tr<typename type_p::number_t>;
        { type_p::To_Number(const_volatile_object) }    -> nkr::cpp::is_tr<typename type_p::number_t>;

        { type_p::From_Number(number) }                 -> nkr::cpp::is_tr<typename type_p::type_t>;
    });

    template <typename type_p>
    concept objects_i =
        !generic::implementing::constructor::default_tr<type_p>;

}}}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor { namespace $uniform_i {

    template <nkr::generic::built_in::boolean_tr type_p>
    class   boolean_sp;

    template <nkr::generic::built_in::number::enumeration::limited_tr type_p>
    class   enumeration_limited_sp;

    template <nkr::generic::built_in::number::integer_tr type_p>
    class   integer_sp;

    template <nkr::generic::built_in::number::real_tr type_p>
    class   real_sp;

    template <nkr::generic::built_in::pointer_tr type_p>
    class   pointer_sp;

}}}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor {

    template <typename type_p>
    class uniform_i_sp;

    template <nkr::generic::built_in::boolean_tr type_p>
    class uniform_i_sp<type_p>
    {
    public:
        using type_t    = $uniform_i::boolean_sp<type_p>;
    };

    template <nkr::generic::built_in::number::enumeration::limited_tr type_p>
    class uniform_i_sp<type_p>
    {
    public:
        using type_t    = $uniform_i::enumeration_limited_sp<type_p>;
    };

    template <nkr::generic::built_in::number::integer_tr type_p>
    class uniform_i_sp<type_p>
    {
    public:
        using type_t    = $uniform_i::integer_sp<type_p>;
    };

    template <nkr::generic::built_in::number::real_tr type_p>
    class uniform_i_sp<type_p>
    {
    public:
        using type_t    = $uniform_i::real_sp<type_p>;
    };

    template <nkr::generic::built_in::pointer_tr type_p>
    class uniform_i_sp<type_p>
    {
    public:
        using type_t    = $uniform_i::pointer_sp<type_p>;
    };

}}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor {

    template <typename type_p>
    using   uniform_i =
        uniform_i_sp<type_p>::type_t;

    struct  uniform_tg  {};

    template <typename>
    struct  uniform_ttg {};

    template <typename type_p>
    concept uniform_tr =
        nkr::cpp::is_any_tr<type_p, uniform_i<typename type_p::type_t>> &&
        $uniform_i::aliases_i<type_p> &&
        $uniform_i::static_functions_i<type_p> &&
        $uniform_i::objects_i<type_p>;

    template <template <typename ...> typename template_p>
    concept uniform_ttr =
        nkr::cpp::is_any_ttr<template_p, uniform_i, nkr::positive::integer_t>;

}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::interface::randomness::distributor::uniform_tg>
    {
    public:
        using type_t    = nkr::interface::randomness::distributor::uniform_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::interface::randomness::distributor::uniform_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::interface::randomness::distributor::uniform_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_p::type_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::interface::randomness::distributor::uniform_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::interface::randomness::distributor::uniform_i<inner_p>;
        using example_t = of_t<nkr::positive::integer_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::interface::randomness::distributor::uniform_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::interface::randomness::distributor::uniform_ttg>
    {
    public:
    };

}}

namespace nkr { namespace interface { namespace randomness { namespace distributor { namespace $uniform_i {

    template <nkr::generic::built_in::boolean_tr type_p>
    class boolean_sp
    {
    public:
        using type_t    = type_p;
        using number_t  = positive::integer_t;

    public:
        static constexpr type_t     Default_Min() noexcept;
        static constexpr type_t     Default_Max() noexcept;

        static constexpr number_t   To_Number(type_t object) noexcept;
        static constexpr type_t     From_Number(number_t number) noexcept;

    public:
        template <typename ...>
        constexpr boolean_sp(...) noexcept  = delete;
    };

}}}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor { namespace $uniform_i {

    template <nkr::generic::built_in::number::enumeration::limited_tr enumeration_p>
    class enumeration_limited_integer_tmpl;

    template <nkr::generic::built_in::number::enumeration::limited_tr enumeration_p>
        requires (sizeof(enumeration_p) == sizeof(positive::integer_8_t) && enumeration_p::MIN_tg >= 0)
    class enumeration_limited_integer_tmpl<enumeration_p>
    {
    public:
        using type_t    = positive::integer_8_t;
    };

    template <nkr::generic::built_in::number::enumeration::limited_tr enumeration_p>
        requires (sizeof(enumeration_p) == sizeof(positive::integer_16_t) && enumeration_p::MIN_tg >= 0)
    class enumeration_limited_integer_tmpl<enumeration_p>
    {
    public:
        using type_t    = positive::integer_16_t;
    };

    template <nkr::generic::built_in::number::enumeration::limited_tr enumeration_p>
        requires (sizeof(enumeration_p) == sizeof(positive::integer_32_t) && enumeration_p::MIN_tg >= 0)
    class enumeration_limited_integer_tmpl<enumeration_p>
    {
    public:
        using type_t    = positive::integer_32_t;
    };

    template <nkr::generic::built_in::number::enumeration::limited_tr enumeration_p>
        requires (sizeof(enumeration_p) == sizeof(positive::integer_64_t) && enumeration_p::MIN_tg >= 0)
    class enumeration_limited_integer_tmpl<enumeration_p>
    {
    public:
        using type_t    = positive::integer_64_t;
    };

    template <nkr::generic::built_in::number::enumeration::limited_tr enumeration_p>
        requires (sizeof(enumeration_p) == sizeof(negatable::integer_8_t) && enumeration_p::MIN_tg < 0)
    class enumeration_limited_integer_tmpl<enumeration_p>
    {
    public:
        using type_t    = negatable::integer_8_t;
    };

    template <nkr::generic::built_in::number::enumeration::limited_tr enumeration_p>
        requires (sizeof(enumeration_p) == sizeof(negatable::integer_16_t) && enumeration_p::MIN_tg < 0)
    class enumeration_limited_integer_tmpl<enumeration_p>
    {
    public:
        using type_t    = negatable::integer_16_t;
    };

    template <nkr::generic::built_in::number::enumeration::limited_tr enumeration_p>
        requires (sizeof(enumeration_p) == sizeof(negatable::integer_32_t) && enumeration_p::MIN_tg < 0)
    class enumeration_limited_integer_tmpl<enumeration_p>
    {
    public:
        using type_t    = negatable::integer_32_t;
    };

    template <nkr::generic::built_in::number::enumeration::limited_tr enumeration_p>
        requires (sizeof(enumeration_p) == sizeof(negatable::integer_64_t) && enumeration_p::MIN_tg < 0)
    class enumeration_limited_integer_tmpl<enumeration_p>
    {
    public:
        using type_t    = negatable::integer_64_t;
    };

    template <nkr::generic::built_in::number::enumeration::limited_tr enumeration_p>
    using enumeration_limited_integer_t = enumeration_limited_integer_tmpl<enumeration_p>::type_t;

    template <nkr::generic::built_in::number::enumeration::limited_tr type_p>
    class enumeration_limited_sp
    {
    public:
        using type_t    = type_p;
        using number_t  = enumeration_limited_integer_t<type_t>;

    public:
        static constexpr type_t     Default_Min() noexcept;
        static constexpr type_t     Default_Max() noexcept;

        static constexpr number_t   To_Number(type_t object) noexcept;
        static constexpr type_t     From_Number(number_t number) noexcept;

    public:
        template <typename ...>
        constexpr enumeration_limited_sp(...) noexcept  = delete;
    };

}}}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor { namespace $uniform_i {

    template <nkr::generic::built_in::number::integer_tr type_p>
    class integer_sp
    {
    public:
        using type_t    = type_p;
        using number_t  = type_t;

    public:
        static constexpr type_t     Default_Min() noexcept;
        static constexpr type_t     Default_Max() noexcept;

        static constexpr number_t   To_Number(type_t object) noexcept;
        static constexpr type_t     From_Number(number_t number) noexcept;

    public:
        template <typename ...>
        constexpr integer_sp(...) noexcept  = delete;
    };

}}}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor { namespace $uniform_i {

    template <nkr::generic::built_in::number::real_tr type_p>
    class real_sp
    {
    public:
        using type_t    = type_p;
        using number_t  = type_t;

    public:
        static constexpr type_t     Default_Min() noexcept;
        static constexpr type_t     Default_Max() noexcept;

        static constexpr number_t   To_Number(type_t object) noexcept;
        static constexpr type_t     From_Number(number_t number) noexcept;

    public:
        template <typename ...>
        constexpr real_sp(...) noexcept = delete;
    };

}}}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor { namespace $uniform_i {

    template <nkr::generic::built_in::pointer_tr type_p>
    class pointer_sp
    {
    public:
        using type_t    = type_p;
        using number_t  = positive::integer_t;

    public:
        static constexpr type_t     Default_Min() noexcept;
        static constexpr type_t     Default_Max() noexcept;

        static constexpr number_t   To_Number(type_t object) noexcept;
        static constexpr type_t     From_Number(number_t number) noexcept;

    public:
        template <typename ...>
        constexpr pointer_sp(...) noexcept  = delete;
    };

}}}}}

#include "nkr/interface/randomness/distributor/uniform_i_dec_def.h"
