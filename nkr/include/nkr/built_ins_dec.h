/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_dec.h"

namespace nkr { namespace none {

    using   type_t      = cpp::none::type_t;
    using   pointer_t   = cpp::none::pointer_t;

}}

namespace nkr { namespace boolean {

    using   cpp_t   = cpp::boolean_t;

}}

namespace nkr { namespace positive {

    using   integer_8_t     = cpp::positive::integer_8_t;
    using   integer_16_t    = cpp::positive::integer_16_t;
    using   integer_32_t    = cpp::positive::integer_32_t;
    using   integer_64_t    = cpp::positive::integer_64_t;
    using   integer_t       = cpp::positive::integer_t;

    using   byte_t          = cpp::positive::byte_t;
    using   word_t          = cpp::positive::word_t;

    using   size_t          = cpp::positive::size_t;
    using   count_t         = cpp::positive::count_t;
    using   index_t         = cpp::positive::index_t;

}}

namespace nkr { namespace negatable {

    using   integer_8_t     = cpp::negatable::integer_8_t;
    using   integer_16_t    = cpp::negatable::integer_16_t;
    using   integer_32_t    = cpp::negatable::integer_32_t;
    using   integer_64_t    = cpp::negatable::integer_64_t;
    using   integer_t       = cpp::negatable::integer_t;

    using   real_32_t       = cpp::negatable::real_32_t;
    using   real_64_t       = cpp::negatable::real_64_t;
    using   real_t          = cpp::negatable::real_t;

    using   byte_t          = cpp::negatable::byte_t;
    using   word_t          = cpp::negatable::word_t;

    using   size_t          = cpp::negatable::size_t;
    using   count_t         = cpp::negatable::count_t;
    using   index_t         = cpp::negatable::index_t;

}}

namespace nkr { namespace pointer {

    template <typename any_p>
    using   cpp_t   = any_p*;

}}

namespace nkr { namespace array {

    template <cpp::type_tr type_p, cpp::positive::count_t capacity_p>
    using   cpp_t   = type_p[capacity_p];

}}

namespace nkr { namespace interface { namespace $type_i {

    template <typename type_p>
    concept of_tr = requires
    {
        typename type_p::of_t;
    };

    template <typename type_p>
    concept of_type_tr = requires
    {
        typename type_p::type_t;
    };

    template <typename type_p>
    concept of_value_tr = requires
    {
        typename type_p::value_t;
    };

    template <typename type_p>
    concept of_unit_tr = requires
    {
        typename type_p::unit_t;
    };

    template <typename type_p>
    concept just_of_tr =
        of_tr<type_p> &&
        !of_type_tr<type_p> &&
        !of_value_tr<type_p> &&
        !of_unit_tr<type_p>;

    template <typename type_p>
    concept just_of_type_tr =
        !of_tr<type_p> &&
        of_type_tr<type_p> &&
        !of_value_tr<type_p> &&
        !of_unit_tr<type_p>;

    template <typename type_p>
    concept just_of_value_tr =
        !of_tr<type_p> &&
        !of_type_tr<type_p> &&
        of_value_tr<type_p> &&
        !of_unit_tr<type_p>;

    template <typename type_p>
    concept just_of_unit_tr =
        !of_tr<type_p> &&
        !of_type_tr<type_p> &&
        !of_value_tr<type_p> &&
        of_unit_tr<type_p>;

    template <typename type_p>
    class default_of_tmpl
    {
    public:
        using type_t    = nkr::none::type_t;
    };

    template <just_of_tr type_p>
    class default_of_tmpl<type_p>
    {
    public:
        using type_t    = type_p::of_t;
    };

    template <just_of_type_tr type_p>
    class default_of_tmpl<type_p>
    {
    public:
        using type_t    = type_p::type_t;
    };

    template <just_of_value_tr type_p>
    class default_of_tmpl<type_p>
    {
    public:
        using type_t    = type_p::value_t;
    };

    template <just_of_unit_tr type_p>
    class default_of_tmpl<type_p>
    {
    public:
        using type_t    = type_p::unit_t;
    };

    template <typename type_p>
    using default_of_t  = default_of_tmpl<type_p>::type_t;

}}}

namespace nkr { namespace interface {

    template <nkr::cpp::just_non_qualified_tr type_p>
    class type_i
    {
    public:
        using type_t    = type_p;
        using of_t      = $type_i::default_of_t<type_t>;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
    class template_i
    {
    public:
        //template <typename ...types_p>
        //using template_t    = template_p<types_p...>;
        template <typename of_p>
        using of_t  = template_p<of_p>;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/built_ins_dec_def.h"
