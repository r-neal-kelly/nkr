/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_6a054f09_912b_4442_9c4f_c75a3a3df358
#define nkr_INCLUDE_GUARD_6a054f09_912b_4442_9c4f_c75a3a3df358

#include "nkr/macros_dec.h"

#undef  nkr_ASSERT_THAT
#define nkr_ASSERT_THAT(EXPRESSION_p)   \
        assert(EXPRESSION_p)            \

#undef  nkr_CONSTEXPR_INHERITANCE_WRAPPER_DEFINE_CTORS
#define nkr_CONSTEXPR_INHERITANCE_WRAPPER_DEFINE_CTORS(WRAPPER_p, BASE_p)                       \
    static_assert(cpp::just_non_qualified_tr<WRAPPER_p>);                                       \
    static_assert(cpp::just_non_qualified_tr<BASE_p>);                                          \
                                                                                                \
    using BASE_p::BASE_p;                                                                       \
    using BASE_p::operator =;                                                                   \
                                                                                                \
    constexpr WRAPPER_p(const BASE_p& base) noexcept :                                          \
        BASE_p(base)                                                                            \
    {                                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr WRAPPER_p(const volatile BASE_p& base) noexcept :                                 \
        BASE_p(base)                                                                            \
    {                                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr WRAPPER_p(BASE_p&& base) noexcept :                                               \
        BASE_p(cpp::Move(base))                                                                 \
    {                                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr WRAPPER_p(volatile BASE_p&& base) noexcept :                                      \
        BASE_p(cpp::Move(base))                                                                 \
    {                                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr WRAPPER_p& operator =(const BASE_p& base) noexcept                                \
    {                                                                                           \
        BASE_p::operator =(base);                                                               \
                                                                                                \
        return *this;                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr volatile WRAPPER_p& operator =(const BASE_p& base) volatile noexcept              \
    {                                                                                           \
        BASE_p::operator =(base);                                                               \
                                                                                                \
        return *this;                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr WRAPPER_p& operator =(const volatile BASE_p& base) noexcept                       \
    {                                                                                           \
        BASE_p::operator =(base);                                                               \
                                                                                                \
        return *this;                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr volatile WRAPPER_p& operator =(const volatile BASE_p& base) volatile noexcept     \
    {                                                                                           \
        BASE_p::operator =(base);                                                               \
                                                                                                \
        return *this;                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr WRAPPER_p& operator =(BASE_p&& base) noexcept                                     \
    {                                                                                           \
        BASE_p::operator =(cpp::Move(base));                                                    \
                                                                                                \
        return *this;                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr volatile WRAPPER_p& operator =(BASE_p&& base) volatile noexcept                   \
    {                                                                                           \
        BASE_p::operator =(cpp::Move(base));                                                    \
                                                                                                \
        return *this;                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr WRAPPER_p& operator =(volatile BASE_p&& base) noexcept                            \
    {                                                                                           \
        BASE_p::operator =(cpp::Move(base));                                                    \
                                                                                                \
        return *this;                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr volatile WRAPPER_p& operator =(volatile BASE_p&& base) volatile noexcept          \
    {                                                                                           \
        BASE_p::operator =(cpp::Move(base));                                                    \
                                                                                                \
        return *this;                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr WRAPPER_p(const WRAPPER_p& other) noexcept :                                      \
        BASE_p(static_cast<const BASE_p&>(other))                                               \
    {                                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr WRAPPER_p(const volatile WRAPPER_p& other) noexcept :                             \
        BASE_p(static_cast<const volatile BASE_p&>(other))                                      \
    {                                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr WRAPPER_p(WRAPPER_p&& other) noexcept :                                           \
        BASE_p(static_cast<BASE_p&&>(other))                                                    \
    {                                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr WRAPPER_p(volatile WRAPPER_p&& other) noexcept :                                  \
        BASE_p(static_cast<volatile BASE_p&&>(other))                                           \
    {                                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr WRAPPER_p& operator =(const WRAPPER_p& other) noexcept                            \
    {                                                                                           \
        BASE_p::operator =(static_cast<const BASE_p&>(other));                                  \
                                                                                                \
        return *this;                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr volatile WRAPPER_p& operator =(const WRAPPER_p& other) volatile noexcept          \
    {                                                                                           \
        BASE_p::operator =(static_cast<const BASE_p&>(other));                                  \
                                                                                                \
        return *this;                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr WRAPPER_p& operator =(const volatile WRAPPER_p& other) noexcept                   \
    {                                                                                           \
        BASE_p::operator =(static_cast<const volatile BASE_p&>(other));                         \
                                                                                                \
        return *this;                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr volatile WRAPPER_p& operator =(const volatile WRAPPER_p& other) volatile noexcept \
    {                                                                                           \
        BASE_p::operator =(static_cast<const volatile BASE_p&>(other));                         \
                                                                                                \
        return *this;                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr WRAPPER_p& operator =(WRAPPER_p&& other) noexcept                                 \
    {                                                                                           \
        BASE_p::operator =(static_cast<BASE_p&&>(cpp::Move(other)));                            \
                                                                                                \
        return *this;                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr volatile WRAPPER_p& operator =(WRAPPER_p&& other) volatile noexcept               \
    {                                                                                           \
        BASE_p::operator =(static_cast<BASE_p&&>(cpp::Move(other)));                            \
                                                                                                \
        return *this;                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr WRAPPER_p& operator =(volatile WRAPPER_p&& other) noexcept                        \
    {                                                                                           \
        BASE_p::operator =(static_cast<volatile BASE_p&&>(cpp::Move(other)));                   \
                                                                                                \
        return *this;                                                                           \
    }                                                                                           \
                                                                                                \
    constexpr volatile WRAPPER_p& operator =(volatile WRAPPER_p&& other) volatile noexcept      \
    {                                                                                           \
        BASE_p::operator =(static_cast<volatile BASE_p&&>(cpp::Move(other)));                   \
                                                                                                \
        return *this;                                                                           \
    }                                                                                           \

#endif
