/*
    Copyright 2022 r-neal-kelly
*/

#define nkr_JUST_NON_QUALIFIED  \
    nkr_TYPES(nkr_BLANK)        \

#define nkr_JUST_CONST  \
    nkr_TYPES(const)    \

#define nkr_JUST_VOLATILE   \
    nkr_TYPES(volatile)     \

#define nkr_JUST_CONST_VOLATILE \
    nkr_TYPES(const volatile)   \

#define nkr_ANY             \
    nkr_JUST_NON_QUALIFIED, \
    nkr_JUST_CONST,         \
    nkr_JUST_VOLATILE,      \
    nkr_JUST_CONST_VOLATILE \

#define nkr_ANY_QUALIFIED   \
    nkr_JUST_CONST,         \
    nkr_JUST_VOLATILE,      \
    nkr_JUST_CONST_VOLATILE \

#define nkr_ANY_NON_QUALIFIED   \
    nkr_JUST_NON_QUALIFIED      \

#define nkr_ANY_CONST       \
    nkr_JUST_CONST,         \
    nkr_JUST_CONST_VOLATILE \

#define nkr_ANY_NON_CONST   \
    nkr_JUST_NON_QUALIFIED, \
    nkr_JUST_VOLATILE       \

#define nkr_ANY_VOLATILE    \
    nkr_JUST_VOLATILE,      \
    nkr_JUST_CONST_VOLATILE \

#define nkr_ANY_NON_VOLATILE    \
    nkr_JUST_NON_QUALIFIED,     \
    nkr_JUST_CONST              \

#define nkr_ANY_NOT_JUST_NON_QUALIFIED  \
    nkr_JUST_CONST,                     \
    nkr_JUST_VOLATILE,                  \
    nkr_JUST_CONST_VOLATILE             \

#define nkr_ANY_NOT_JUST_CONST  \
    nkr_JUST_NON_QUALIFIED,     \
    nkr_JUST_VOLATILE,          \
    nkr_JUST_CONST_VOLATILE     \

#define nkr_ANY_NOT_JUST_VOLATILE   \
    nkr_JUST_NON_QUALIFIED,         \
    nkr_JUST_CONST,                 \
    nkr_JUST_CONST_VOLATILE         \

#define nkr_ANY_NOT_JUST_CONST_VOLATILE \
    nkr_JUST_NON_QUALIFIED,             \
    nkr_JUST_CONST,                     \
    nkr_JUST_VOLATILE                   \

#define nkr_DEFINE_QUALIFIED_TYPE_TS                                                            \
    using   just_non_qualified_ts           = nkr::ts<AND_tg, nkr_JUST_NON_QUALIFIED>;          \
    using   just_const_ts                   = nkr::ts<AND_tg, nkr_JUST_CONST>;                  \
    using   just_volatile_ts                = nkr::ts<AND_tg, nkr_JUST_VOLATILE>;               \
    using   just_const_volatile_ts          = nkr::ts<AND_tg, nkr_JUST_CONST_VOLATILE>;         \
    using   any_ts                          = nkr::ts<AND_tg, nkr_ANY>;                         \
    using   any_qualified_ts                = nkr::ts<AND_tg, nkr_ANY_QUALIFIED>;               \
    using   any_non_qualified_ts            = nkr::ts<AND_tg, nkr_ANY_NON_QUALIFIED>;           \
    using   any_const_ts                    = nkr::ts<AND_tg, nkr_ANY_CONST>;                   \
    using   any_non_const_ts                = nkr::ts<AND_tg, nkr_ANY_NON_CONST>;               \
    using   any_volatile_ts                 = nkr::ts<AND_tg, nkr_ANY_VOLATILE>;                \
    using   any_non_volatile_ts             = nkr::ts<AND_tg, nkr_ANY_NON_VOLATILE>;            \
    using   any_not_just_non_qualified_ts   = nkr::ts<AND_tg, nkr_ANY_NOT_JUST_NON_QUALIFIED>;  \
    using   any_not_just_const_ts           = nkr::ts<AND_tg, nkr_ANY_NOT_JUST_CONST>;          \
    using   any_not_just_volatile_ts        = nkr::ts<AND_tg, nkr_ANY_NOT_JUST_VOLATILE>;       \
    using   any_not_just_const_volatile_ts  = nkr::ts<AND_tg, nkr_ANY_NOT_JUST_CONST_VOLATILE>; \
