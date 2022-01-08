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

namespace nkr { namespace boolean {

    template <cpp_t value_p>    using   cpp_c   = cpp::constant_t<cpp_t, value_p>;

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

namespace nkr { namespace positive {

    template <integer_8_t value_p>  using   integer_8_c     = cpp::constant_t<integer_8_t, value_p>;
    template <integer_16_t value_p> using   integer_16_c    = cpp::constant_t<integer_16_t, value_p>;
    template <integer_32_t value_p> using   integer_32_c    = cpp::constant_t<integer_32_t, value_p>;
    template <integer_64_t value_p> using   integer_64_c    = cpp::constant_t<integer_64_t, value_p>;
    template <integer_t value_p>    using   integer_c       = cpp::constant_t<integer_t, value_p>;

    template <byte_t value_p>       using   byte_c          = cpp::constant_t<byte_t, value_p>;
    template <word_t value_p>       using   word_c          = cpp::constant_t<word_t, value_p>;

    template <size_t value_p>       using   size_c          = cpp::constant_t<size_t, value_p>;
    template <count_t value_p>      using   count_c         = cpp::constant_t<count_t, value_p>;
    template <index_t value_p>      using   index_c         = cpp::constant_t<index_t, value_p>;

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

namespace nkr { namespace negatable {

    template <integer_8_t value_p>  using   integer_8_c     = cpp::constant_t<integer_8_t, value_p>;
    template <integer_16_t value_p> using   integer_16_c    = cpp::constant_t<integer_16_t, value_p>;
    template <integer_32_t value_p> using   integer_32_c    = cpp::constant_t<integer_32_t, value_p>;
    template <integer_64_t value_p> using   integer_64_c    = cpp::constant_t<integer_64_t, value_p>;
    template <integer_t value_p>    using   integer_c       = cpp::constant_t<integer_t, value_p>;

    template <real_32_t value_p>    using   real_32_c       = cpp::constant_t<real_32_t, value_p>;
    template <real_64_t value_p>    using   real_64_c       = cpp::constant_t<real_64_t, value_p>;
    template <real_t value_p>       using   real_c          = cpp::constant_t<real_t, value_p>;

    template <byte_t value_p>       using   byte_c          = cpp::constant_t<byte_t, value_p>;
    template <word_t value_p>       using   word_c          = cpp::constant_t<word_t, value_p>;

    template <size_t value_p>       using   size_c          = cpp::constant_t<size_t, value_p>;
    template <count_t value_p>      using   count_c         = cpp::constant_t<count_t, value_p>;
    template <index_t value_p>      using   index_c         = cpp::constant_t<index_t, value_p>;

}}

namespace nkr { namespace pointer {

    template <typename type_p>
    using   cpp_t   = type_p*;

}}

namespace nkr { namespace pointer {

    template <typename type_p, type_p* value_p>
    using   cpp_c   = cpp::constant_t<type_p*, value_p>;

}}

namespace nkr { namespace array {

    template <cpp::type_tr type_p, cpp::constant_of_tr<positive::count_t> capacity_p>
    using   cpp_t   = type_p[capacity_p::Value()];

}}

namespace nkr { namespace array {

    template <cpp::type_tr type_p, positive::count_t capacity_p, type_p value_p[capacity_p]>
    using   cpp_c   = cpp::constant_t<type_p[capacity_p], value_p>;

}}

namespace nkr { namespace interface { namespace $type_i {

    template <typename type_p>
    concept inner_type_tr = requires
    {
        typename type_p::type_t;
    };

    template <typename type_p>
    concept inner_value_tr = requires
    {
        typename type_p::value_t;
    };

    template <typename type_p>
    concept inner_unit_tr = requires
    {
        typename type_p::unit_t;
    };

    template <typename type_p>
    concept just_inner_type_tr =
        inner_type_tr<type_p> &&
        !inner_value_tr<type_p> &&
        !inner_unit_tr<type_p>;

    template <typename type_p>
    concept just_inner_value_tr =
        !inner_type_tr<type_p> &&
        inner_value_tr<type_p> &&
        !inner_unit_tr<type_p>;

    template <typename type_p>
    concept just_inner_unit_tr =
        !inner_type_tr<type_p> &&
        !inner_value_tr<type_p> &&
        inner_unit_tr<type_p>;

    template <typename type_p>
    class default_inner_tmpl
    {
    public:
        using type_t    = nkr::none::type_t;
    };

    template <just_inner_type_tr type_p>
    class default_inner_tmpl<type_p>
    {
    public:
        using type_t    = type_p::type_t;
    };

    template <just_inner_value_tr type_p>
    class default_inner_tmpl<type_p>
    {
    public:
        using type_t    = type_p::value_t;
    };

    template <just_inner_unit_tr type_p>
    class default_inner_tmpl<type_p>
    {
    public:
        using type_t    = type_p::unit_t;
    };

    template <typename type_p>
    using default_inner_t   = default_inner_tmpl<type_p>::type_t;

}}}

namespace nkr { namespace interface {

    template <nkr::cpp::just_non_qualified_tr type_p>
    class type_i
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::interface::$type_i::default_inner_t<type_t>;

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
        template <typename inner_p>
        using of_t      = template_p<inner_p>;
        using example_t = of_t<nkr::none::type_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

// pretty sure we'll want interface::random_i in here as well.
// and we can have a func or type, like we do none::value_t to more easily access it.

#include "nkr/intrinsics_dec_def.h"
