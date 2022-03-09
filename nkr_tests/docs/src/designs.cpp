/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/boolean/cpp_t.h"
#include "nkr/cpp.h"
#include "nkr/interface/type_i.h"
#include "nkr/namespaces.h"
#include "nkr/pointer/cpp_t.h"
#include "nkr/tr.h"

#include "doctest.h"

/* Global Equality Operators */

// [_e18507aa_b4f3_4469_b0a6_ff276fabf1b6]
    namespace nkr {

        class constexpr_t;

    }

    constexpr nkr::boolean::cpp_t   operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::constexpr_t>> auto& a, const auto& b) noexcept;
    constexpr nkr::boolean::cpp_t   operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::constexpr_t>> auto& a, const auto&& b) noexcept;
    constexpr nkr::boolean::cpp_t   operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::constexpr_t>> auto&& a, const auto& b) noexcept;
    constexpr nkr::boolean::cpp_t   operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::constexpr_t>> auto&& a, const auto&& b) noexcept;

    constexpr nkr::boolean::cpp_t   operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::constexpr_t>> auto& a, const auto& b) noexcept;
    constexpr nkr::boolean::cpp_t   operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::constexpr_t>> auto& a, const auto&& b) noexcept;
    constexpr nkr::boolean::cpp_t   operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::constexpr_t>> auto&& a, const auto& b) noexcept;
    constexpr nkr::boolean::cpp_t   operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::constexpr_t>> auto&& a, const auto&& b) noexcept;
// [_e18507aa_b4f3_4469_b0a6_ff276fabf1b6]

// [_fc99f829_b919_4aae_bdfb_b45b355c2614]
    namespace nkr {

        class non_constexpr_t;

    }

    nkr::boolean::cpp_t operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::non_constexpr_t>> auto& a, const auto& b) noexcept;
    nkr::boolean::cpp_t operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::non_constexpr_t>> auto& a, const auto&& b) noexcept;
    nkr::boolean::cpp_t operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::non_constexpr_t>> auto&& a, const auto& b) noexcept;
    nkr::boolean::cpp_t operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::non_constexpr_t>> auto&& a, const auto&& b) noexcept;

    nkr::boolean::cpp_t operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::non_constexpr_t>> auto& a, const auto& b) noexcept;
    nkr::boolean::cpp_t operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::non_constexpr_t>> auto& a, const auto&& b) noexcept;
    nkr::boolean::cpp_t operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::non_constexpr_t>> auto&& a, const auto& b) noexcept;
    nkr::boolean::cpp_t operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::non_constexpr_t>> auto&& a, const auto&& b) noexcept;
// [_fc99f829_b919_4aae_bdfb_b45b355c2614]

// [_26b07298_7839_4099_9253_a58ba962aa0b]
    namespace nkr {

        class equality_a_t
        {
        public:
            // The primary inner type.
            using value_t   = long;

        public:
            value_t value;

        public:
            constexpr equality_a_t(value_t value) noexcept :
                value(value)
            {
            }
        };

        class equality_b_t
        {
        public:
            // The primary inner type. It's different from equality_a_t's.
            using value_t   = long long;

        public:
            value_t value;

        public:
            constexpr equality_b_t(value_t value) noexcept :
                value(value)
            {
            }

            // Notice that we can construct this type with equality_a_t.
            constexpr equality_b_t(equality_a_t value) noexcept :
                value(value.value)
            {
            }
        };

    }

    // Forward declare equality_a_t's ops so it can see equality_b_t's ops.
    constexpr nkr::boolean::cpp_t operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_a_t>> auto& a, const auto& b) noexcept;
    constexpr nkr::boolean::cpp_t operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_a_t>> auto& a, const auto&& b) noexcept;
    constexpr nkr::boolean::cpp_t operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_a_t>> auto&& a, const auto& b) noexcept;
    constexpr nkr::boolean::cpp_t operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_a_t>> auto&& a, const auto&& b) noexcept;

    constexpr nkr::boolean::cpp_t operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_a_t>> auto& a, const auto& b) noexcept;
    constexpr nkr::boolean::cpp_t operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_a_t>> auto& a, const auto&& b) noexcept;
    constexpr nkr::boolean::cpp_t operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_a_t>> auto&& a, const auto& b) noexcept;
    constexpr nkr::boolean::cpp_t operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_a_t>> auto&& a, const auto&& b) noexcept;

    // And vice versa.
    constexpr nkr::boolean::cpp_t operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_b_t>> auto& a, const auto& b) noexcept;
    constexpr nkr::boolean::cpp_t operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_b_t>> auto& a, const auto&& b) noexcept;
    constexpr nkr::boolean::cpp_t operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_b_t>> auto&& a, const auto& b) noexcept;
    constexpr nkr::boolean::cpp_t operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_b_t>> auto&& a, const auto&& b) noexcept;

    constexpr nkr::boolean::cpp_t operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_b_t>> auto& a, const auto& b) noexcept;
    constexpr nkr::boolean::cpp_t operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_b_t>> auto& a, const auto&& b) noexcept;
    constexpr nkr::boolean::cpp_t operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_b_t>> auto&& a, const auto& b) noexcept;
    constexpr nkr::boolean::cpp_t operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_b_t>> auto&& a, const auto&& b) noexcept;

    // Here we define equality_a_t's operators.
    inline constexpr nkr::boolean::cpp_t
        operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_a_t>> auto& a, const auto& b)
        noexcept
    {
        // We want the value_t and not a value_t& type.
        using a_t = nkr::cpp::reference_value_t<decltype(a)>;
        using b_t = nkr::cpp::reference_value_t<decltype(b)>;

        if constexpr (nkr::cpp::is_any_tr<b_t, a_t>) {
            // If b_t is equality_a_t, it's super easy to compare the two.
            return a.value == b.value;
        } else if constexpr (nkr::cpp::to_tr<b_t, nkr::cpp::just_non_qualified_t<typename a_t::value_t>>) {
            // If b_t is equality_b_t, then this won't be branched to because it doesn't have a cast to
            // value_t operator. However another type might, and because our type defines equality based on
            // its primary inner type, it makes sense to have this branch. However if our type doesn't have
            // a primary inner type, it maybe should be excluded. This technique relies on a good design of
            // b_t, which should be castable to other types only when it's meaningful.
            return a.value == static_cast<nkr::cpp::just_non_qualified_t<typename a_t::value_t>>(b);
        } else if constexpr (nkr::cpp::to_tr<b_t, nkr::cpp::just_non_qualified_t<a_t>>) {
            // If b_t is equality_b_t, then this won't be branched to because a_t cannot be constructed from
            // an equality_b_t, nor can equality_b_t be cast to a_t. Notice that this recursively calls this
            // operator, we don't need to define a_t == a_t twice!
            return a == static_cast<nkr::cpp::just_non_qualified_t<a_t>>(b);
        } else if constexpr (nkr::cpp::to_tr<a_t, nkr::cpp::just_non_qualified_t<b_t>>) {
            // If b_t is equality_b_t, then even though equality_a_t cannot be cast to equality_b_t,
            // equality_b_t can be constructed with equality_a_t, so this is the branch that will compile.
            // However take note that equality_b_t's operators must be defined!
            return static_cast<nkr::cpp::just_non_qualified_t<b_t>>(a) == b;
        } else {
            // Bail, because there's no defined way to compare these two types. Make sure to let the user
            // know what happend. As complicated as it is, this standards compliant technique works great:
            [] <nkr::boolean::cpp_t _ = false>() { static_assert(_, "these two values can not be compared."); }();
        }
    }

    // The rest of these just call the above operator.
    inline constexpr nkr::boolean::cpp_t
        operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_a_t>> auto& a, const auto&& b)
        noexcept
    {
        return operator ==(a, b);
    }

    inline constexpr nkr::boolean::cpp_t
        operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_a_t>> auto&& a, const auto& b)
        noexcept
    {
        return operator ==(a, b);
    }

    inline constexpr nkr::boolean::cpp_t
        operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_a_t>> auto&& a, const auto&& b)
        noexcept
    {
        return operator ==(a, b);
    }

    inline constexpr nkr::boolean::cpp_t
        operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_a_t>> auto& a, const auto& b)
        noexcept
    {
        return !operator ==(a, b);
    }

    inline constexpr nkr::boolean::cpp_t
        operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_a_t>> auto& a, const auto&& b)
        noexcept
    {
        return !operator ==(a, b);
    }

    inline constexpr nkr::boolean::cpp_t
        operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_a_t>> auto&& a, const auto& b)
        noexcept
    {
        return !operator ==(a, b);
    }

    inline constexpr nkr::boolean::cpp_t
        operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_a_t>> auto&& a, const auto&& b)
        noexcept
    {
        return !operator ==(a, b);
    }

    // Here we do the same thing as above, but for equality_b_t.
    // We have the same algorithm because the two types are similar, but other types may have different algorithms.
    inline constexpr nkr::boolean::cpp_t
        operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_b_t>> auto& a, const auto& b)
        noexcept
    {
        using a_t = nkr::cpp::reference_value_t<decltype(a)>;
        using b_t = nkr::cpp::reference_value_t<decltype(b)>;

        if constexpr (nkr::cpp::is_any_tr<b_t, a_t>) {
            return a.value == b.value;
        } else if constexpr (nkr::cpp::to_tr<b_t, nkr::cpp::just_non_qualified_t<typename a_t::value_t>>) {
            return a.value == static_cast<nkr::cpp::just_non_qualified_t<typename a_t::value_t>>(b);
        } else if constexpr (nkr::cpp::to_tr<b_t, nkr::cpp::just_non_qualified_t<a_t>>) {
            return a == static_cast<nkr::cpp::just_non_qualified_t<a_t>>(b);
        } else if constexpr (nkr::cpp::to_tr<a_t, nkr::cpp::just_non_qualified_t<b_t>>) {
            return static_cast<nkr::cpp::just_non_qualified_t<b_t>>(a) == b;
        } else {
            [] <nkr::boolean::cpp_t _ = false>() { static_assert(_, "these two values can not be compared."); }();
        }
    }

    inline constexpr nkr::boolean::cpp_t
        operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_b_t>> auto& a, const auto&& b)
        noexcept
    {
        return operator ==(a, b);
    }

    inline constexpr nkr::boolean::cpp_t
        operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_b_t>> auto&& a, const auto& b)
        noexcept
    {
        return operator ==(a, b);
    }

    inline constexpr nkr::boolean::cpp_t
        operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_b_t>> auto&& a, const auto&& b)
        noexcept
    {
        return operator ==(a, b);
    }

    inline constexpr nkr::boolean::cpp_t
        operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_b_t>> auto& a, const auto& b)
        noexcept
    {
        return !operator ==(a, b);
    }

    inline constexpr nkr::boolean::cpp_t
        operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_b_t>> auto& a, const auto&& b)
        noexcept
    {
        return !operator ==(a, b);
    }

    inline constexpr nkr::boolean::cpp_t
        operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_b_t>> auto&& a, const auto& b)
        noexcept
    {
        return !operator ==(a, b);
    }

    inline constexpr nkr::boolean::cpp_t
        operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::equality_b_t>> auto&& a, const auto&& b)
        noexcept
    {
        return !operator ==(a, b);
    }
// [_26b07298_7839_4099_9253_a58ba962aa0b]

TEST_CASE("")
{
    // [_4cb072ae_149f_4024_9145_7592e38ea63e]
    // This calls equality_a_t branch 1
    static_assert(nkr::equality_a_t(1) == nkr::equality_a_t(1));

    // This calls equality_a_t branch 4 then equality_b_t branch 1
    static_assert(nkr::equality_a_t(1) == nkr::equality_b_t(1));

    // This calls equality_b_t branch 1
    static_assert(nkr::equality_b_t(1) == nkr::equality_b_t(1));

    // This calls equality_b_t branch 3 then equality_b_t branch 1
    static_assert(nkr::equality_b_t(1) == nkr::equality_a_t(1));

    // Even const and/or volatile values play nicely:
    const nkr::equality_a_t equality_a = 1;
    volatile nkr::equality_a_t equality_b = 1;

    CHECK((equality_a == equality_b));
    CHECK((equality_b == equality_a));

    // Any combination of lvalues, rvalues, and temp values will just work:
    CHECK((nkr::equality_a_t(1) == equality_b));
    CHECK((equality_a == nkr::cpp::Move(equality_b)));

    CHECK((nkr::equality_b_t(1) == equality_a));
    CHECK((nkr::cpp::Move(equality_b) == nkr::equality_a_t(1)));
    // [_4cb072ae_149f_4024_9145_7592e38ea63e]
}

/* Identities */

TEST_SUITE("")
{
    // [_54c5c7e1_91a3_4d5b_b41d_c158d3b4c573]
    class a_t
    {
    public:
    };

    // the "type indentity trait" for a_t
    template <typename type_p>
    concept a_tr =
        nkr::cpp::is_any_tr<type_p, a_t>;

    // should constrain to any qualification of a_t
    static_assert(a_tr<a_t> == true);
    static_assert(a_tr<const a_t> == true);
    static_assert(a_tr<volatile a_t> == true);
    static_assert(a_tr<const volatile a_t> == true);

    using alias_of_a_t = a_t;

    // and naturally any qualification of an alias of a_t
    static_assert(a_tr<alias_of_a_t> == true);
    static_assert(a_tr<const alias_of_a_t> == true);
    static_assert(a_tr<volatile alias_of_a_t> == true);
    static_assert(a_tr<const volatile alias_of_a_t> == true);

    class b_t
    {
    public:
    };

    // but never any qualification of any other type
    static_assert(a_tr<b_t> == false);
    static_assert(a_tr<const b_t> == false);
    static_assert(a_tr<volatile b_t> == false);
    static_assert(a_tr<const volatile b_t> == false);
    // [_54c5c7e1_91a3_4d5b_b41d_c158d3b4c573]
}

TEST_SUITE("")
{
    // [_fbae0c33_830c_4106_8c8d_bcbae9a82433]
    template <typename ...parameters_p>
    class a_t
    {
    public:
        using parameters_t = nkr::tuple::types_t<parameters_p...>;
    };

    // the "instantiated type indentity trait" for a_t
    template <typename type_p>
    concept a_tr =
        nkr::cpp::is_any_tr<type_p, typename type_p::parameters_t::template into_t<a_t>>;

    // should constrain to any qualification of an instantiated a_t
    static_assert(a_tr<a_t<>> == true);
    static_assert(a_tr<const a_t<>> == true);
    static_assert(a_tr<volatile a_t<>> == true);
    static_assert(a_tr<const volatile a_t<>> == true);

    template <typename ...parameters_p>
    using alias_of_a_t = a_t<parameters_p...>;

    // and naturally any qualification of an instantiated alias of a_t
    static_assert(a_tr<alias_of_a_t<>> == true);
    static_assert(a_tr<const alias_of_a_t<>> == true);
    static_assert(a_tr<volatile alias_of_a_t<>> == true);
    static_assert(a_tr<const volatile alias_of_a_t<>> == true);

    template <typename ...parameters_p>
    class b_t
    {
    public:
        using parameters_t = nkr::tuple::types_t<parameters_p...>;
    };

    // but never any qualification of any other type
    static_assert(a_tr<b_t<>> == false);
    static_assert(a_tr<const b_t<>> == false);
    static_assert(a_tr<volatile b_t<>> == false);
    static_assert(a_tr<const volatile b_t<>> == false);

    // the "template indentity trait" for a_t
    template <template <typename ...> typename template_p>
    concept a_ttr =
        nkr::cpp::is_any_ttr<template_p, a_t>;

    // should constrain to a_t
    static_assert(a_ttr<a_t> == true);

    // and any alias of a_t
    static_assert(a_ttr<alias_of_a_t> == true);

    // but never any other template
    static_assert(a_ttr<b_t> == false);
    // [_fbae0c33_830c_4106_8c8d_bcbae9a82433]
}

TEST_SUITE("")
{
    // [_7e0fe0cd_2eac_4f85_9539_4a1399492ab0]
    template <template <typename ...> typename ...parameters_p>
    class a_t
    {
    public:
        using parameters_t = nkr::tuple::templates_t<parameters_p...>;
    };

    // the "instantiated type indentity trait" for a_t
    template <typename type_p>
    concept a_tr =
        nkr::cpp::is_any_tr<type_p, typename type_p::parameters_t::template into_t<a_t>>;

    // should constrain to any qualification of an instantiated a_t
    static_assert(a_tr<a_t<>> == true);
    static_assert(a_tr<const a_t<>> == true);
    static_assert(a_tr<volatile a_t<>> == true);
    static_assert(a_tr<const volatile a_t<>> == true);

    template <template <typename ...> typename ...parameters_p>
    using alias_of_a_t = a_t<parameters_p...>;

    // and naturally any qualification of an instantiated alias of a_t
    static_assert(a_tr<alias_of_a_t<>> == true);
    static_assert(a_tr<const alias_of_a_t<>> == true);
    static_assert(a_tr<volatile alias_of_a_t<>> == true);
    static_assert(a_tr<const volatile alias_of_a_t<>> == true);

    template <template <typename ...> typename ...parameters_p>
    class b_t
    {
    public:
        using parameters_t = nkr::tuple::templates_t<parameters_p...>;
    };

    // but never any qualification of any other type
    static_assert(a_tr<b_t<>> == false);
    static_assert(a_tr<const b_t<>> == false);
    static_assert(a_tr<volatile b_t<>> == false);
    static_assert(a_tr<const volatile b_t<>> == false);

    // the "template template indentity trait" for a_t
    template <template <template <typename ...> typename ...> typename template_template_p>
    concept a_tttr =
        nkr::cpp::is_any_tttr<template_template_p, a_t>;

    // should constrain to a_t
    static_assert(a_tttr<a_t> == true);

    // and any alias of a_t
    static_assert(a_tttr<alias_of_a_t> == true);

    // but never any other template
    static_assert(a_tttr<b_t> == false);
    // [_7e0fe0cd_2eac_4f85_9539_4a1399492ab0]
}

/* Label Postfixes */

TEST_SUITE("")
{
    // [_b516dddc_3630_470a_acf5_f070b2d4ffd1]
    // "_t" is for "type"
    class example_t
    {
    public:
    };

    // "_tr" is for "trait"
    template <typename type_p>
    concept example_tr =
        true;

    // "_i" is for "interface"
    template <typename type_p>
    class example_i
    {
    public:
    };
    // [_b516dddc_3630_470a_acf5_f070b2d4ffd1]
}

TEST_SUITE("")
{
    // [_d77d72c6_49d4_48d5_8799_655eef4bdebb]
    // "_p" is for "parameter"
    template <typename parameter_p>
    class example_t
    {
    public:
        using parameter_t   = parameter_p;
    };
    // [_d77d72c6_49d4_48d5_8799_655eef4bdebb]
}

TEST_SUITE("")
{
    // [_d4386f68_d330_40bb_8659_4d3d81ca6a2c]
    using namespace nkr;

    // a template type is frequently the primary entity in a relationship
    template <typename type_p>
    class entity_t
    {
    public:
    };

    // this "tag" can represent an instantiation of the primary entity
    struct entity_tg    {};

    // whereas this "template tag" can represent the template itself
    template <typename>
    struct entity_ttg   {};

    // a "trait" can be used to constrain to an instantiated type
    template <typename type_p>
    concept entity_tr =
        true;

    // and a "template trait" to constrain to the template proper
    template <template <typename ...> typename template_p>
    concept entity_ttr =
        true;
    // [_d4386f68_d330_40bb_8659_4d3d81ca6a2c]
}

TEST_SUITE("")
{
    // [_78f65ebc_ee89_4eb9_b7bf_eca7bf552002]
    using namespace nkr;

    // "_t" is not for "template"!
    template <typename type_p>
    class template_t
    {
    public:
    };

    // "_t" is for "type", as in "instantiated type".
    using instantiated_type_t = template_t<int>;
    // [_78f65ebc_ee89_4eb9_b7bf_eca7bf552002]
}

TEST_SUITE("")
{
    // [_4af78359_e062_45a4_b14c_f59533520b0b]
    using namespace nkr;

    // "_tttg" for "template of template of type tag"
    template <template <template <typename ...> typename ...> typename template_template_p>
    struct  entity_tttg {};

    // "_tttr" for "template of template of type trait"
    template <template <template <typename ...> typename ...> typename template_template_p>
    concept entity_tttr =
        true;
    // [_4af78359_e062_45a4_b14c_f59533520b0b]
}

// [_dda6b4f4_9596_4713_8d31_f48990e0c898]
    // The non-postfix header pulls in everything but the "_dox" below. This is what you would normally use in your code.
    #include "nkr/pointer/cpp_t.h"

    // "_dec" provides the declarations of entities contained in this header-group. The go-to file to know what is available.
    #include "nkr/pointer/cpp_t_dec.h"

    // "_dec_def" defines the constexpr and other meta entities of "_dec". A helpful technical distinction from "_def".
    #include "nkr/pointer/cpp_t_dec_def.h"

    // "_def" defines the non-constexpr and non-meta entities of "_dec".
    #include "nkr/pointer/cpp_t_def.h"

    // "_dox" provides the doxygen comments used to create the documention for the entities of "_dec".
    #include "nkr/pointer/cpp_t_dox.h"
// [_dda6b4f4_9596_4713_8d31_f48990e0c898]

/* Primary Inner Type */

TEST_SUITE("")
{
    // [_71d0edc7_85b8_40e5_a79b_4d46a8ff2f08]
    using namespace nkr;

    template <typename type_p, typename ...maybe_more_types_p>
    class template_t
    {
    public:
        using type_t    = type_p;   // the primary inner type
    };
    // [_71d0edc7_85b8_40e5_a79b_4d46a8ff2f08]
}

TEST_SUITE("")
{
    // [_61c79cda_e67d_4202_b6de_3f7078ba5f7b]
    using namespace nkr;

    template <typename type_p, typename ...maybe_more_types_p>
    class template_t
    {
    public:
        using value_t   = type_p;   // does not use the parameter's name
    };
    // [_61c79cda_e67d_4202_b6de_3f7078ba5f7b]
}

TEST_SUITE("")
{
    // [_6dffcb91_cf58_4490_9cd2_e39762bab3f0]
    using namespace nkr;

    // we can use any nkr template as long as it has a primary inner type
    template <typename type_p>
    using template_t = nkr::pointer::cpp_t<type_p>;

    static_assert(tr<
                  template_t<long>,         // we provide a primary inner type of "long"
                  any_tg, tt<template_t>,
                  of_any_tg, t<long long>   // but we're looking for "long long", so it's false
    > == false);

    static_assert(tr<
                  template_t<long long>,    // we change it to "long long" to get true
                  any_tg, tt<template_t>,
                  of_any_tg, t<long long>
    > == true);
    // [_6dffcb91_cf58_4490_9cd2_e39762bab3f0]
}

TEST_SUITE("")
{
    // [_7c1eacd8_f30a_4dd8_80e7_c4e02c2b88a2]
    using namespace nkr;

    template <typename type_p>
    using template_t = nkr::pointer::cpp_t<type_p>;

    // here we give our example template a primary inner type of "int"
    using type_t = template_t<int>;

    using interface_of_type_t = nkr::interface::type_i<type_t>;

    // we can access the primary inner type with an alias contained in the interface
    using primary_inner_type_of_type_t = interface_of_type_t::of_t;

    // it should be equal to what we gave our template_t
    static_assert(nkr::cpp::is_tr<primary_inner_type_of_type_t, int>);

    using interface_of_interface_of_type_t = nkr::interface::type_i<interface_of_type_t>;

    // coincidentally, the interface itself has a primary inner type equal to type_t
    static_assert(nkr::cpp::is_tr<interface_of_interface_of_type_t::of_t, type_t>);
    // [_7c1eacd8_f30a_4dd8_80e7_c4e02c2b88a2]
}

/* One Kind of Template Parameter */
