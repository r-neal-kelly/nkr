/*
    Copyright 2021 r-neal-kelly
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
