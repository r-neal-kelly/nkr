/*
    Copyright 2021 r-neal-kelly
*/

// JUST_NON_QUALIFIED
#define nkr_JUST_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p)    \
    nkr_TEMPLATES(nkr_BLANK, TYPE_p)                            \

#define nkr_JUST_NON_QUALIFIED_OF_JUST_CONST(TYPE_p)    \
    nkr_TEMPLATES(nkr_BLANK, const TYPE_p)              \

#define nkr_JUST_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p) \
    nkr_TEMPLATES(nkr_BLANK, volatile TYPE_p)           \

#define nkr_JUST_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)   \
    nkr_TEMPLATES(nkr_BLANK, const volatile TYPE_p)             \

#define nkr_JUST_NON_QUALIFIED_OF_ANY(TYPE_p)               \
    nkr_JUST_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),   \
    nkr_JUST_NON_QUALIFIED_OF_JUST_CONST(TYPE_p),           \
    nkr_JUST_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p),        \
    nkr_JUST_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)   \

#define nkr_JUST_NON_QUALIFIED_OF_ANY_QUALIFIED(TYPE_p)     \
    nkr_JUST_NON_QUALIFIED_OF_JUST_CONST(TYPE_p),           \
    nkr_JUST_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p),        \
    nkr_JUST_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)   \

#define nkr_JUST_NON_QUALIFIED_OF_ANY_NON_QUALIFIED(TYPE_p) \
    nkr_JUST_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p)    \

#define nkr_JUST_NON_QUALIFIED_OF_ANY_CONST(TYPE_p)         \
    nkr_JUST_NON_QUALIFIED_OF_JUST_CONST(TYPE_p),           \
    nkr_JUST_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)   \

#define nkr_JUST_NON_QUALIFIED_OF_ANY_NON_CONST(TYPE_p)     \
    nkr_JUST_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),   \
    nkr_JUST_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p)         \

#define nkr_JUST_NON_QUALIFIED_OF_ANY_VOLATILE(TYPE_p)      \
    nkr_JUST_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p),        \
    nkr_JUST_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)   \

#define nkr_JUST_NON_QUALIFIED_OF_ANY_NON_VOLATILE(TYPE_p)  \
    nkr_JUST_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),   \
    nkr_JUST_NON_QUALIFIED_OF_JUST_CONST(TYPE_p)            \

#define nkr_JUST_NON_QUALIFIED_OF_ANY_NOT_JUST_NON_QUALIFIED(TYPE_p)    \
    nkr_JUST_NON_QUALIFIED_OF_JUST_CONST(TYPE_p),                       \
    nkr_JUST_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p),                    \
    nkr_JUST_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)               \

#define nkr_JUST_NON_QUALIFIED_OF_ANY_NOT_JUST_CONST(TYPE_p)    \
    nkr_JUST_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),       \
    nkr_JUST_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p),            \
    nkr_JUST_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)       \

#define nkr_JUST_NON_QUALIFIED_OF_ANY_NOT_JUST_VOLATILE(TYPE_p) \
    nkr_JUST_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),       \
    nkr_JUST_NON_QUALIFIED_OF_JUST_CONST(TYPE_p),               \
    nkr_JUST_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)       \

#define nkr_JUST_NON_QUALIFIED_OF_ANY_NOT_JUST_CONST_VOLATILE(TYPE_p)   \
    nkr_JUST_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),               \
    nkr_JUST_NON_QUALIFIED_OF_JUST_CONST(TYPE_p),                       \
    nkr_JUST_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p)                     \

// JUST_CONST
#define nkr_JUST_CONST_OF_JUST_NON_QUALIFIED(TYPE_p)    \
    nkr_TEMPLATES(const, TYPE_p)                        \

#define nkr_JUST_CONST_OF_JUST_CONST(TYPE_p)    \
    nkr_TEMPLATES(const, const TYPE_p)          \

#define nkr_JUST_CONST_OF_JUST_VOLATILE(TYPE_p) \
    nkr_TEMPLATES(const, volatile TYPE_p)       \

#define nkr_JUST_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)   \
    nkr_TEMPLATES(const, const volatile TYPE_p)         \

#define nkr_JUST_CONST_OF_ANY(TYPE_p)               \
    nkr_JUST_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),   \
    nkr_JUST_CONST_OF_JUST_CONST(TYPE_p),           \
    nkr_JUST_CONST_OF_JUST_VOLATILE(TYPE_p),        \
    nkr_JUST_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)   \

#define nkr_JUST_CONST_OF_ANY_QUALIFIED(TYPE_p)     \
    nkr_JUST_CONST_OF_JUST_CONST(TYPE_p),           \
    nkr_JUST_CONST_OF_JUST_VOLATILE(TYPE_p),        \
    nkr_JUST_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)   \

#define nkr_JUST_CONST_OF_ANY_NON_QUALIFIED(TYPE_p) \
    nkr_JUST_CONST_OF_JUST_NON_QUALIFIED(TYPE_p)    \

#define nkr_JUST_CONST_OF_ANY_CONST(TYPE_p)         \
    nkr_JUST_CONST_OF_JUST_CONST(TYPE_p),           \
    nkr_JUST_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)   \

#define nkr_JUST_CONST_OF_ANY_NON_CONST(TYPE_p)     \
    nkr_JUST_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),   \
    nkr_JUST_CONST_OF_JUST_VOLATILE(TYPE_p)         \

#define nkr_JUST_CONST_OF_ANY_VOLATILE(TYPE_p)      \
    nkr_JUST_CONST_OF_JUST_VOLATILE(TYPE_p),        \
    nkr_JUST_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)   \

#define nkr_JUST_CONST_OF_ANY_NON_VOLATILE(TYPE_p)  \
    nkr_JUST_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),   \
    nkr_JUST_CONST_OF_JUST_CONST(TYPE_p)            \

#define nkr_JUST_CONST_OF_ANY_NOT_JUST_NON_QUALIFIED(TYPE_p)    \
    nkr_JUST_CONST_OF_JUST_CONST(TYPE_p),                       \
    nkr_JUST_CONST_OF_JUST_VOLATILE(TYPE_p),                    \
    nkr_JUST_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)               \

#define nkr_JUST_CONST_OF_ANY_NOT_JUST_CONST(TYPE_p)    \
    nkr_JUST_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),       \
    nkr_JUST_CONST_OF_JUST_VOLATILE(TYPE_p),            \
    nkr_JUST_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)       \

#define nkr_JUST_CONST_OF_ANY_NOT_JUST_VOLATILE(TYPE_p) \
    nkr_JUST_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),       \
    nkr_JUST_CONST_OF_JUST_CONST(TYPE_p),               \
    nkr_JUST_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)       \

#define nkr_JUST_CONST_OF_ANY_NOT_JUST_CONST_VOLATILE(TYPE_p)   \
    nkr_JUST_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),               \
    nkr_JUST_CONST_OF_JUST_CONST(TYPE_p),                       \
    nkr_JUST_CONST_OF_JUST_VOLATILE(TYPE_p)                     \

// JUST_VOLATILE
#define nkr_JUST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p) \
    nkr_TEMPLATES(volatile, TYPE_p)                     \

#define nkr_JUST_VOLATILE_OF_JUST_CONST(TYPE_p) \
    nkr_TEMPLATES(volatile, const TYPE_p)       \

#define nkr_JUST_VOLATILE_OF_JUST_VOLATILE(TYPE_p)  \
    nkr_TEMPLATES(volatile, volatile TYPE_p)        \

#define nkr_JUST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)    \
    nkr_TEMPLATES(volatile, const volatile TYPE_p)          \

#define nkr_JUST_VOLATILE_OF_ANY(TYPE_p)                \
    nkr_JUST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_JUST_VOLATILE_OF_JUST_CONST(TYPE_p),            \
    nkr_JUST_VOLATILE_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_JUST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_JUST_VOLATILE_OF_ANY_QUALIFIED(TYPE_p)      \
    nkr_JUST_VOLATILE_OF_JUST_CONST(TYPE_p),            \
    nkr_JUST_VOLATILE_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_JUST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_JUST_VOLATILE_OF_ANY_NON_QUALIFIED(TYPE_p)  \
    nkr_JUST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p)     \

#define nkr_JUST_VOLATILE_OF_ANY_CONST(TYPE_p)          \
    nkr_JUST_VOLATILE_OF_JUST_CONST(TYPE_p),            \
    nkr_JUST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_JUST_VOLATILE_OF_ANY_NON_CONST(TYPE_p)      \
    nkr_JUST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_JUST_VOLATILE_OF_JUST_VOLATILE(TYPE_p)          \

#define nkr_JUST_VOLATILE_OF_ANY_VOLATILE(TYPE_p)       \
    nkr_JUST_VOLATILE_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_JUST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_JUST_VOLATILE_OF_ANY_NON_VOLATILE(TYPE_p)   \
    nkr_JUST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_JUST_VOLATILE_OF_JUST_CONST(TYPE_p)             \

#define nkr_JUST_VOLATILE_OF_ANY_NOT_JUST_NON_QUALIFIED(TYPE_p) \
    nkr_JUST_VOLATILE_OF_JUST_CONST(TYPE_p),                    \
    nkr_JUST_VOLATILE_OF_JUST_VOLATILE(TYPE_p),                 \
    nkr_JUST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)            \

#define nkr_JUST_VOLATILE_OF_ANY_NOT_JUST_CONST(TYPE_p) \
    nkr_JUST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_JUST_VOLATILE_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_JUST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_JUST_VOLATILE_OF_ANY_NOT_JUST_VOLATILE(TYPE_p)  \
    nkr_JUST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),        \
    nkr_JUST_VOLATILE_OF_JUST_CONST(TYPE_p),                \
    nkr_JUST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)        \

#define nkr_JUST_VOLATILE_OF_ANY_NOT_JUST_CONST_VOLATILE(TYPE_p)    \
    nkr_JUST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),                \
    nkr_JUST_VOLATILE_OF_JUST_CONST(TYPE_p),                        \
    nkr_JUST_VOLATILE_OF_JUST_VOLATILE(TYPE_p)                      \

// JUST_CONST_VOLATILE
#define nkr_JUST_CONST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p)   \
    nkr_TEMPLATES(const volatile, TYPE_p)                       \

#define nkr_JUST_CONST_VOLATILE_OF_JUST_CONST(TYPE_p)   \
    nkr_TEMPLATES(const volatile, const TYPE_p)         \

#define nkr_JUST_CONST_VOLATILE_OF_JUST_VOLATILE(TYPE_p)    \
    nkr_TEMPLATES(const volatile, volatile TYPE_p)          \

#define nkr_JUST_CONST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)  \
    nkr_TEMPLATES(const volatile, const volatile TYPE_p)        \

#define nkr_JUST_CONST_VOLATILE_OF_ANY(TYPE_p)              \
    nkr_JUST_CONST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),  \
    nkr_JUST_CONST_VOLATILE_OF_JUST_CONST(TYPE_p),          \
    nkr_JUST_CONST_VOLATILE_OF_JUST_VOLATILE(TYPE_p),       \
    nkr_JUST_CONST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)  \

#define nkr_JUST_CONST_VOLATILE_OF_ANY_QUALIFIED(TYPE_p)    \
    nkr_JUST_CONST_VOLATILE_OF_JUST_CONST(TYPE_p),          \
    nkr_JUST_CONST_VOLATILE_OF_JUST_VOLATILE(TYPE_p),       \
    nkr_JUST_CONST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)  \

#define nkr_JUST_CONST_VOLATILE_OF_ANY_NON_QUALIFIED(TYPE_p)    \
    nkr_JUST_CONST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p)       \

#define nkr_JUST_CONST_VOLATILE_OF_ANY_CONST(TYPE_p)        \
    nkr_JUST_CONST_VOLATILE_OF_JUST_CONST(TYPE_p),          \
    nkr_JUST_CONST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)  \

#define nkr_JUST_CONST_VOLATILE_OF_ANY_NON_CONST(TYPE_p)    \
    nkr_JUST_CONST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),  \
    nkr_JUST_CONST_VOLATILE_OF_JUST_VOLATILE(TYPE_p)        \

#define nkr_JUST_CONST_VOLATILE_OF_ANY_VOLATILE(TYPE_p)     \
    nkr_JUST_CONST_VOLATILE_OF_JUST_VOLATILE(TYPE_p),       \
    nkr_JUST_CONST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)  \

#define nkr_JUST_CONST_VOLATILE_OF_ANY_NON_VOLATILE(TYPE_p) \
    nkr_JUST_CONST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),  \
    nkr_JUST_CONST_VOLATILE_OF_JUST_CONST(TYPE_p)           \

#define nkr_JUST_CONST_VOLATILE_OF_ANY_NOT_JUST_NON_QUALIFIED(TYPE_p)   \
    nkr_JUST_CONST_VOLATILE_OF_JUST_CONST(TYPE_p),                      \
    nkr_JUST_CONST_VOLATILE_OF_JUST_VOLATILE(TYPE_p),                   \
    nkr_JUST_CONST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)              \

#define nkr_JUST_CONST_VOLATILE_OF_ANY_NOT_JUST_CONST(TYPE_p)   \
    nkr_JUST_CONST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),      \
    nkr_JUST_CONST_VOLATILE_OF_JUST_VOLATILE(TYPE_p),           \
    nkr_JUST_CONST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)      \

#define nkr_JUST_CONST_VOLATILE_OF_ANY_NOT_JUST_VOLATILE(TYPE_p)    \
    nkr_JUST_CONST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),          \
    nkr_JUST_CONST_VOLATILE_OF_JUST_CONST(TYPE_p),                  \
    nkr_JUST_CONST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)          \

#define nkr_JUST_CONST_VOLATILE_OF_ANY_NOT_JUST_CONST_VOLATILE(TYPE_p)  \
    nkr_JUST_CONST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),              \
    nkr_JUST_CONST_VOLATILE_OF_JUST_CONST(TYPE_p),                      \
    nkr_JUST_CONST_VOLATILE_OF_JUST_VOLATILE(TYPE_p)                    \

// ANY
#define nkr_ANY_OF_JUST_NON_QUALIFIED(TYPE_p)   \
    nkr_TEMPLATES(nkr_BLANK, TYPE_p),           \
    nkr_TEMPLATES(const, TYPE_p),               \
    nkr_TEMPLATES(volatile, TYPE_p),            \
    nkr_TEMPLATES(const volatile, TYPE_p)       \

#define nkr_ANY_OF_JUST_CONST(TYPE_p)           \
    nkr_TEMPLATES(nkr_BLANK, const TYPE_p),     \
    nkr_TEMPLATES(const, const TYPE_p),         \
    nkr_TEMPLATES(volatile, const TYPE_p),      \
    nkr_TEMPLATES(const volatile, const TYPE_p) \

#define nkr_ANY_OF_JUST_VOLATILE(TYPE_p)            \
    nkr_TEMPLATES(nkr_BLANK, volatile TYPE_p),      \
    nkr_TEMPLATES(const, volatile TYPE_p),          \
    nkr_TEMPLATES(volatile, volatile TYPE_p),       \
    nkr_TEMPLATES(const volatile, volatile TYPE_p)  \

#define nkr_ANY_OF_JUST_CONST_VOLATILE(TYPE_p)              \
    nkr_TEMPLATES(nkr_BLANK, const volatile TYPE_p),        \
    nkr_TEMPLATES(const, const volatile TYPE_p),            \
    nkr_TEMPLATES(volatile, const volatile TYPE_p),         \
    nkr_TEMPLATES(const volatile, const volatile TYPE_p)    \

#define nkr_ANY_OF_ANY(TYPE_p)              \
    nkr_ANY_OF_JUST_NON_QUALIFIED(TYPE_p),  \
    nkr_ANY_OF_JUST_CONST(TYPE_p),          \
    nkr_ANY_OF_JUST_VOLATILE(TYPE_p),       \
    nkr_ANY_OF_JUST_CONST_VOLATILE(TYPE_p)  \

#define nkr_ANY_OF_ANY_QUALIFIED(TYPE_p)    \
    nkr_ANY_OF_JUST_CONST(TYPE_p),          \
    nkr_ANY_OF_JUST_VOLATILE(TYPE_p),       \
    nkr_ANY_OF_JUST_CONST_VOLATILE(TYPE_p)  \

#define nkr_ANY_OF_ANY_NON_QUALIFIED(TYPE_p)    \
    nkr_ANY_OF_JUST_NON_QUALIFIED(TYPE_p)       \

#define nkr_ANY_OF_ANY_CONST(TYPE_p)        \
    nkr_ANY_OF_JUST_CONST(TYPE_p),          \
    nkr_ANY_OF_JUST_CONST_VOLATILE(TYPE_p)  \

#define nkr_ANY_OF_ANY_NON_CONST(TYPE_p)    \
    nkr_ANY_OF_JUST_NON_QUALIFIED(TYPE_p),  \
    nkr_ANY_OF_JUST_VOLATILE(TYPE_p)        \

#define nkr_ANY_OF_ANY_VOLATILE(TYPE_p)     \
    nkr_ANY_OF_JUST_VOLATILE(TYPE_p),       \
    nkr_ANY_OF_JUST_CONST_VOLATILE(TYPE_p)  \

#define nkr_ANY_OF_ANY_NON_VOLATILE(TYPE_p) \
    nkr_ANY_OF_JUST_NON_QUALIFIED(TYPE_p),  \
    nkr_ANY_OF_JUST_CONST(TYPE_p)           \

#define nkr_ANY_OF_ANY_NOT_JUST_NON_QUALIFIED(TYPE_p)   \
    nkr_ANY_OF_JUST_CONST(TYPE_p),                      \
    nkr_ANY_OF_JUST_VOLATILE(TYPE_p),                   \
    nkr_ANY_OF_JUST_CONST_VOLATILE(TYPE_p)              \

#define nkr_ANY_OF_ANY_NOT_JUST_CONST(TYPE_p)   \
    nkr_ANY_OF_JUST_NON_QUALIFIED(TYPE_p),      \
    nkr_ANY_OF_JUST_VOLATILE(TYPE_p),           \
    nkr_ANY_OF_JUST_CONST_VOLATILE(TYPE_p)      \

#define nkr_ANY_OF_ANY_NOT_JUST_VOLATILE(TYPE_p)    \
    nkr_ANY_OF_JUST_NON_QUALIFIED(TYPE_p),          \
    nkr_ANY_OF_JUST_CONST(TYPE_p),                  \
    nkr_ANY_OF_JUST_CONST_VOLATILE(TYPE_p)          \

#define nkr_ANY_OF_ANY_NOT_JUST_CONST_VOLATILE(TYPE_p)  \
    nkr_ANY_OF_JUST_NON_QUALIFIED(TYPE_p),              \
    nkr_ANY_OF_JUST_CONST(TYPE_p),                      \
    nkr_ANY_OF_JUST_VOLATILE(TYPE_p)                    \

// ANY_QUALIFIED
#define nkr_ANY_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p) \
    nkr_TEMPLATES(const, TYPE_p),                       \
    nkr_TEMPLATES(volatile, TYPE_p),                    \
    nkr_TEMPLATES(const volatile, TYPE_p)               \

#define nkr_ANY_QUALIFIED_OF_JUST_CONST(TYPE_p) \
    nkr_TEMPLATES(const, const TYPE_p),         \
    nkr_TEMPLATES(volatile, const TYPE_p),      \
    nkr_TEMPLATES(const volatile, const TYPE_p) \

#define nkr_ANY_QUALIFIED_OF_JUST_VOLATILE(TYPE_p)  \
    nkr_TEMPLATES(const, volatile TYPE_p),          \
    nkr_TEMPLATES(volatile, volatile TYPE_p),       \
    nkr_TEMPLATES(const volatile, volatile TYPE_p)  \

#define nkr_ANY_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)    \
    nkr_TEMPLATES(const, const volatile TYPE_p),            \
    nkr_TEMPLATES(volatile, const volatile TYPE_p),         \
    nkr_TEMPLATES(const volatile, const volatile TYPE_p)    \

#define nkr_ANY_QUALIFIED_OF_ANY(TYPE_p)                \
    nkr_ANY_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_ANY_QUALIFIED_OF_JUST_CONST(TYPE_p),            \
    nkr_ANY_QUALIFIED_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_ANY_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_QUALIFIED_OF_ANY_QUALIFIED(TYPE_p)      \
    nkr_ANY_QUALIFIED_OF_JUST_CONST(TYPE_p),            \
    nkr_ANY_QUALIFIED_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_ANY_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_QUALIFIED_OF_ANY_NON_QUALIFIED(TYPE_p)  \
    nkr_ANY_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p)     \

#define nkr_ANY_QUALIFIED_OF_ANY_CONST(TYPE_p)          \
    nkr_ANY_QUALIFIED_OF_JUST_CONST(TYPE_p),            \
    nkr_ANY_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_QUALIFIED_OF_ANY_NON_CONST(TYPE_p)      \
    nkr_ANY_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_ANY_QUALIFIED_OF_JUST_VOLATILE(TYPE_p)          \

#define nkr_ANY_QUALIFIED_OF_ANY_VOLATILE(TYPE_p)       \
    nkr_ANY_QUALIFIED_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_ANY_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_QUALIFIED_OF_ANY_NON_VOLATILE(TYPE_p)   \
    nkr_ANY_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_ANY_QUALIFIED_OF_JUST_CONST(TYPE_p)             \

#define nkr_ANY_QUALIFIED_OF_ANY_NOT_JUST_NON_QUALIFIED(TYPE_p) \
    nkr_ANY_QUALIFIED_OF_JUST_CONST(TYPE_p),                    \
    nkr_ANY_QUALIFIED_OF_JUST_VOLATILE(TYPE_p),                 \
    nkr_ANY_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)            \

#define nkr_ANY_QUALIFIED_OF_ANY_NOT_JUST_CONST(TYPE_p) \
    nkr_ANY_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_ANY_QUALIFIED_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_ANY_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_QUALIFIED_OF_ANY_NOT_JUST_VOLATILE(TYPE_p)  \
    nkr_ANY_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),        \
    nkr_ANY_QUALIFIED_OF_JUST_CONST(TYPE_p),                \
    nkr_ANY_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)        \

#define nkr_ANY_QUALIFIED_OF_ANY_NOT_JUST_CONST_VOLATILE(TYPE_p)    \
    nkr_ANY_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),                \
    nkr_ANY_QUALIFIED_OF_JUST_CONST(TYPE_p),                        \
    nkr_ANY_QUALIFIED_OF_JUST_VOLATILE(TYPE_p)                      \

// ANY_NON_QUALIFIED
#define nkr_ANY_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p) \
    nkr_TEMPLATES(nkr_BLANK, TYPE_p)                        \

#define nkr_ANY_NON_QUALIFIED_OF_JUST_CONST(TYPE_p) \
    nkr_TEMPLATES(nkr_BLANK, const TYPE_p)          \

#define nkr_ANY_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p)  \
    nkr_TEMPLATES(nkr_BLANK, volatile TYPE_p)           \

#define nkr_ANY_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)    \
    nkr_TEMPLATES(nkr_BLANK, const volatile TYPE_p)             \

#define nkr_ANY_NON_QUALIFIED_OF_ANY(TYPE_p)                \
    nkr_ANY_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_ANY_NON_QUALIFIED_OF_JUST_CONST(TYPE_p),            \
    nkr_ANY_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_ANY_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_NON_QUALIFIED_OF_ANY_QUALIFIED(TYPE_p)      \
    nkr_ANY_NON_QUALIFIED_OF_JUST_CONST(TYPE_p),            \
    nkr_ANY_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_ANY_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_NON_QUALIFIED_OF_ANY_NON_QUALIFIED(TYPE_p)  \
    nkr_ANY_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p)     \

#define nkr_ANY_NON_QUALIFIED_OF_ANY_CONST(TYPE_p)          \
    nkr_ANY_NON_QUALIFIED_OF_JUST_CONST(TYPE_p),            \
    nkr_ANY_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_NON_QUALIFIED_OF_ANY_NON_CONST(TYPE_p)      \
    nkr_ANY_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_ANY_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p)          \

#define nkr_ANY_NON_QUALIFIED_OF_ANY_VOLATILE(TYPE_p)       \
    nkr_ANY_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_ANY_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_NON_QUALIFIED_OF_ANY_NON_VOLATILE(TYPE_p)   \
    nkr_ANY_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_ANY_NON_QUALIFIED_OF_JUST_CONST(TYPE_p)             \

#define nkr_ANY_NON_QUALIFIED_OF_ANY_NOT_JUST_NON_QUALIFIED(TYPE_p) \
    nkr_ANY_NON_QUALIFIED_OF_JUST_CONST(TYPE_p),                    \
    nkr_ANY_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p),                 \
    nkr_ANY_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)            \

#define nkr_ANY_NON_QUALIFIED_OF_ANY_NOT_JUST_CONST(TYPE_p) \
    nkr_ANY_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_ANY_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_ANY_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_NON_QUALIFIED_OF_ANY_NOT_JUST_VOLATILE(TYPE_p)  \
    nkr_ANY_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),        \
    nkr_ANY_NON_QUALIFIED_OF_JUST_CONST(TYPE_p),                \
    nkr_ANY_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)        \

#define nkr_ANY_NON_QUALIFIED_OF_ANY_NOT_JUST_CONST_VOLATILE(TYPE_p)    \
    nkr_ANY_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),                \
    nkr_ANY_NON_QUALIFIED_OF_JUST_CONST(TYPE_p),                        \
    nkr_ANY_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p)                      \

// ANY_CONST
#define nkr_ANY_CONST_OF_JUST_NON_QUALIFIED(TYPE_p) \
    nkr_TEMPLATES(const, TYPE_p),                   \
    nkr_TEMPLATES(const volatile, TYPE_p)           \

#define nkr_ANY_CONST_OF_JUST_CONST(TYPE_p)     \
    nkr_TEMPLATES(const, const TYPE_p),         \
    nkr_TEMPLATES(const volatile, const TYPE_p) \

#define nkr_ANY_CONST_OF_JUST_VOLATILE(TYPE_p)      \
    nkr_TEMPLATES(const, volatile TYPE_p),          \
    nkr_TEMPLATES(const volatile, volatile TYPE_p)  \

#define nkr_ANY_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)        \
    nkr_TEMPLATES(const, const volatile TYPE_p),            \
    nkr_TEMPLATES(const volatile, const volatile TYPE_p)    \

#define nkr_ANY_CONST_OF_ANY(TYPE_p)                \
    nkr_ANY_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_ANY_CONST_OF_JUST_CONST(TYPE_p),            \
    nkr_ANY_CONST_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_ANY_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_CONST_OF_ANY_QUALIFIED(TYPE_p)      \
    nkr_ANY_CONST_OF_JUST_CONST(TYPE_p),            \
    nkr_ANY_CONST_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_ANY_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_CONST_OF_ANY_NON_QUALIFIED(TYPE_p)  \
    nkr_ANY_CONST_OF_JUST_NON_QUALIFIED(TYPE_p)     \

#define nkr_ANY_CONST_OF_ANY_CONST(TYPE_p)          \
    nkr_ANY_CONST_OF_JUST_CONST(TYPE_p),            \
    nkr_ANY_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_CONST_OF_ANY_NON_CONST(TYPE_p)      \
    nkr_ANY_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_ANY_CONST_OF_JUST_VOLATILE(TYPE_p)          \

#define nkr_ANY_CONST_OF_ANY_VOLATILE(TYPE_p)       \
    nkr_ANY_CONST_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_ANY_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_CONST_OF_ANY_NON_VOLATILE(TYPE_p)   \
    nkr_ANY_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_ANY_CONST_OF_JUST_CONST(TYPE_p)             \

#define nkr_ANY_CONST_OF_ANY_NOT_JUST_NON_QUALIFIED(TYPE_p) \
    nkr_ANY_CONST_OF_JUST_CONST(TYPE_p),                    \
    nkr_ANY_CONST_OF_JUST_VOLATILE(TYPE_p),                 \
    nkr_ANY_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)            \

#define nkr_ANY_CONST_OF_ANY_NOT_JUST_CONST(TYPE_p) \
    nkr_ANY_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_ANY_CONST_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_ANY_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_CONST_OF_ANY_NOT_JUST_VOLATILE(TYPE_p)  \
    nkr_ANY_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),        \
    nkr_ANY_CONST_OF_JUST_CONST(TYPE_p),                \
    nkr_ANY_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)        \

#define nkr_ANY_CONST_OF_ANY_NOT_JUST_CONST_VOLATILE(TYPE_p)    \
    nkr_ANY_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),                \
    nkr_ANY_CONST_OF_JUST_CONST(TYPE_p),                        \
    nkr_ANY_CONST_OF_JUST_VOLATILE(TYPE_p)                      \

// ANY_NON_CONST
#define nkr_ANY_NON_CONST_OF_JUST_NON_QUALIFIED(TYPE_p) \
    nkr_TEMPLATES(nkr_BLANK, TYPE_p),                   \
    nkr_TEMPLATES(volatile, TYPE_p)                     \

#define nkr_ANY_NON_CONST_OF_JUST_CONST(TYPE_p) \
    nkr_TEMPLATES(nkr_BLANK, const TYPE_p),     \
    nkr_TEMPLATES(volatile, const TYPE_p)       \

#define nkr_ANY_NON_CONST_OF_JUST_VOLATILE(TYPE_p)  \
    nkr_TEMPLATES(nkr_BLANK, volatile TYPE_p),      \
    nkr_TEMPLATES(volatile, volatile TYPE_p)        \

#define nkr_ANY_NON_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)    \
    nkr_TEMPLATES(nkr_BLANK, const volatile TYPE_p),        \
    nkr_TEMPLATES(volatile, const volatile TYPE_p)          \

#define nkr_ANY_NON_CONST_OF_ANY(TYPE_p)                \
    nkr_ANY_NON_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_ANY_NON_CONST_OF_JUST_CONST(TYPE_p),            \
    nkr_ANY_NON_CONST_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_ANY_NON_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_NON_CONST_OF_ANY_QUALIFIED(TYPE_p)      \
    nkr_ANY_NON_CONST_OF_JUST_CONST(TYPE_p),            \
    nkr_ANY_NON_CONST_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_ANY_NON_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_NON_CONST_OF_ANY_NON_QUALIFIED(TYPE_p)  \
    nkr_ANY_NON_CONST_OF_JUST_NON_QUALIFIED(TYPE_p)     \

#define nkr_ANY_NON_CONST_OF_ANY_CONST(TYPE_p)          \
    nkr_ANY_NON_CONST_OF_JUST_CONST(TYPE_p),            \
    nkr_ANY_NON_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_NON_CONST_OF_ANY_NON_CONST(TYPE_p)      \
    nkr_ANY_NON_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_ANY_NON_CONST_OF_JUST_VOLATILE(TYPE_p)          \

#define nkr_ANY_NON_CONST_OF_ANY_VOLATILE(TYPE_p)       \
    nkr_ANY_NON_CONST_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_ANY_NON_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_NON_CONST_OF_ANY_NON_VOLATILE(TYPE_p)   \
    nkr_ANY_NON_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_ANY_NON_CONST_OF_JUST_CONST(TYPE_p)             \

#define nkr_ANY_NON_CONST_OF_ANY_NOT_JUST_NON_QUALIFIED(TYPE_p) \
    nkr_ANY_NON_CONST_OF_JUST_CONST(TYPE_p),                    \
    nkr_ANY_NON_CONST_OF_JUST_VOLATILE(TYPE_p),                 \
    nkr_ANY_NON_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)            \

#define nkr_ANY_NON_CONST_OF_ANY_NOT_JUST_CONST(TYPE_p) \
    nkr_ANY_NON_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_ANY_NON_CONST_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_ANY_NON_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_NON_CONST_OF_ANY_NOT_JUST_VOLATILE(TYPE_p)  \
    nkr_ANY_NON_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),        \
    nkr_ANY_NON_CONST_OF_JUST_CONST(TYPE_p),                \
    nkr_ANY_NON_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)        \

#define nkr_ANY_NON_CONST_OF_ANY_NOT_JUST_CONST_VOLATILE(TYPE_p)    \
    nkr_ANY_NON_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),                \
    nkr_ANY_NON_CONST_OF_JUST_CONST(TYPE_p),                        \
    nkr_ANY_NON_CONST_OF_JUST_VOLATILE(TYPE_p)                      \

// ANY_VOLATILE
#define nkr_ANY_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p)  \
    nkr_TEMPLATES(volatile, TYPE_p),                    \
    nkr_TEMPLATES(const volatile, TYPE_p)               \

#define nkr_ANY_VOLATILE_OF_JUST_CONST(TYPE_p)  \
    nkr_TEMPLATES(volatile, const TYPE_p),      \
    nkr_TEMPLATES(const volatile, const TYPE_p) \

#define nkr_ANY_VOLATILE_OF_JUST_VOLATILE(TYPE_p)   \
    nkr_TEMPLATES(volatile, volatile TYPE_p),       \
    nkr_TEMPLATES(const volatile, volatile TYPE_p)  \

#define nkr_ANY_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)     \
    nkr_TEMPLATES(volatile, const volatile TYPE_p),         \
    nkr_TEMPLATES(const volatile, const volatile TYPE_p)    \

#define nkr_ANY_VOLATILE_OF_ANY(TYPE_p)             \
    nkr_ANY_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p), \
    nkr_ANY_VOLATILE_OF_JUST_CONST(TYPE_p),         \
    nkr_ANY_VOLATILE_OF_JUST_VOLATILE(TYPE_p),      \
    nkr_ANY_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p) \

#define nkr_ANY_VOLATILE_OF_ANY_QUALIFIED(TYPE_p)   \
    nkr_ANY_VOLATILE_OF_JUST_CONST(TYPE_p),         \
    nkr_ANY_VOLATILE_OF_JUST_VOLATILE(TYPE_p),      \
    nkr_ANY_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p) \

#define nkr_ANY_VOLATILE_OF_ANY_NON_QUALIFIED(TYPE_p)   \
    nkr_ANY_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p)      \

#define nkr_ANY_VOLATILE_OF_ANY_CONST(TYPE_p)       \
    nkr_ANY_VOLATILE_OF_JUST_CONST(TYPE_p),         \
    nkr_ANY_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p) \

#define nkr_ANY_VOLATILE_OF_ANY_NON_CONST(TYPE_p)   \
    nkr_ANY_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p), \
    nkr_ANY_VOLATILE_OF_JUST_VOLATILE(TYPE_p)       \

#define nkr_ANY_VOLATILE_OF_ANY_VOLATILE(TYPE_p)    \
    nkr_ANY_VOLATILE_OF_JUST_VOLATILE(TYPE_p),      \
    nkr_ANY_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p) \

#define nkr_ANY_VOLATILE_OF_ANY_NON_VOLATILE(TYPE_p)    \
    nkr_ANY_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),     \
    nkr_ANY_VOLATILE_OF_JUST_CONST(TYPE_p)              \

#define nkr_ANY_VOLATILE_OF_ANY_NOT_JUST_NON_QUALIFIED(TYPE_p)  \
    nkr_ANY_VOLATILE_OF_JUST_CONST(TYPE_p),                     \
    nkr_ANY_VOLATILE_OF_JUST_VOLATILE(TYPE_p),                  \
    nkr_ANY_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)             \

#define nkr_ANY_VOLATILE_OF_ANY_NOT_JUST_CONST(TYPE_p)  \
    nkr_ANY_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),     \
    nkr_ANY_VOLATILE_OF_JUST_VOLATILE(TYPE_p),          \
    nkr_ANY_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)     \

#define nkr_ANY_VOLATILE_OF_ANY_NOT_JUST_VOLATILE(TYPE_p)   \
    nkr_ANY_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),         \
    nkr_ANY_VOLATILE_OF_JUST_CONST(TYPE_p),                 \
    nkr_ANY_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)         \

#define nkr_ANY_VOLATILE_OF_ANY_NOT_JUST_CONST_VOLATILE(TYPE_p) \
    nkr_ANY_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),             \
    nkr_ANY_VOLATILE_OF_JUST_CONST(TYPE_p),                     \
    nkr_ANY_VOLATILE_OF_JUST_VOLATILE(TYPE_p)                   \

// ANY_NON_VOLATILE
#define nkr_ANY_NON_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p)  \
    nkr_TEMPLATES(nkr_BLANK, TYPE_p),                       \
    nkr_TEMPLATES(const, TYPE_p)                            \

#define nkr_ANY_NON_VOLATILE_OF_JUST_CONST(TYPE_p)  \
    nkr_TEMPLATES(nkr_BLANK, const TYPE_p),         \
    nkr_TEMPLATES(const, const TYPE_p)              \

#define nkr_ANY_NON_VOLATILE_OF_JUST_VOLATILE(TYPE_p)   \
    nkr_TEMPLATES(nkr_BLANK, volatile TYPE_p),          \
    nkr_TEMPLATES(const, volatile TYPE_p)               \

#define nkr_ANY_NON_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p) \
    nkr_TEMPLATES(nkr_BLANK, const volatile TYPE_p),        \
    nkr_TEMPLATES(const, const volatile TYPE_p)             \

#define nkr_ANY_NON_VOLATILE_OF_ANY(TYPE_p)             \
    nkr_ANY_NON_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p), \
    nkr_ANY_NON_VOLATILE_OF_JUST_CONST(TYPE_p),         \
    nkr_ANY_NON_VOLATILE_OF_JUST_VOLATILE(TYPE_p),      \
    nkr_ANY_NON_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p) \

#define nkr_ANY_NON_VOLATILE_OF_ANY_QUALIFIED(TYPE_p)   \
    nkr_ANY_NON_VOLATILE_OF_JUST_CONST(TYPE_p),         \
    nkr_ANY_NON_VOLATILE_OF_JUST_VOLATILE(TYPE_p),      \
    nkr_ANY_NON_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p) \

#define nkr_ANY_NON_VOLATILE_OF_ANY_NON_QUALIFIED(TYPE_p)   \
    nkr_ANY_NON_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p)      \

#define nkr_ANY_NON_VOLATILE_OF_ANY_CONST(TYPE_p)       \
    nkr_ANY_NON_VOLATILE_OF_JUST_CONST(TYPE_p),         \
    nkr_ANY_NON_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p) \

#define nkr_ANY_NON_VOLATILE_OF_ANY_NON_CONST(TYPE_p)   \
    nkr_ANY_NON_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p), \
    nkr_ANY_NON_VOLATILE_OF_JUST_VOLATILE(TYPE_p)       \

#define nkr_ANY_NON_VOLATILE_OF_ANY_VOLATILE(TYPE_p)    \
    nkr_ANY_NON_VOLATILE_OF_JUST_VOLATILE(TYPE_p),      \
    nkr_ANY_NON_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p) \

#define nkr_ANY_NON_VOLATILE_OF_ANY_NON_VOLATILE(TYPE_p)    \
    nkr_ANY_NON_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),     \
    nkr_ANY_NON_VOLATILE_OF_JUST_CONST(TYPE_p)              \

#define nkr_ANY_NON_VOLATILE_OF_ANY_NOT_JUST_NON_QUALIFIED(TYPE_p)  \
    nkr_ANY_NON_VOLATILE_OF_JUST_CONST(TYPE_p),                     \
    nkr_ANY_NON_VOLATILE_OF_JUST_VOLATILE(TYPE_p),                  \
    nkr_ANY_NON_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)             \

#define nkr_ANY_NON_VOLATILE_OF_ANY_NOT_JUST_CONST(TYPE_p)  \
    nkr_ANY_NON_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),     \
    nkr_ANY_NON_VOLATILE_OF_JUST_VOLATILE(TYPE_p),          \
    nkr_ANY_NON_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)     \

#define nkr_ANY_NON_VOLATILE_OF_ANY_NOT_JUST_VOLATILE(TYPE_p)   \
    nkr_ANY_NON_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),         \
    nkr_ANY_NON_VOLATILE_OF_JUST_CONST(TYPE_p),                 \
    nkr_ANY_NON_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)         \

#define nkr_ANY_NON_VOLATILE_OF_ANY_NOT_JUST_CONST_VOLATILE(TYPE_p) \
    nkr_ANY_NON_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),             \
    nkr_ANY_NON_VOLATILE_OF_JUST_CONST(TYPE_p),                     \
    nkr_ANY_NON_VOLATILE_OF_JUST_VOLATILE(TYPE_p)                   \

// ANY_NOT_JUST_NON_QUALIFIED
#define nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p)    \
    nkr_TEMPLATES(const, TYPE_p),                                       \
    nkr_TEMPLATES(volatile, TYPE_p),                                    \
    nkr_TEMPLATES(const volatile, TYPE_p)                               \

#define nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_CONST(TYPE_p)    \
    nkr_TEMPLATES(const, const TYPE_p),                         \
    nkr_TEMPLATES(volatile, const TYPE_p),                      \
    nkr_TEMPLATES(const volatile, const TYPE_p)                 \

#define nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p) \
    nkr_TEMPLATES(const, volatile TYPE_p),                      \
    nkr_TEMPLATES(volatile, volatile TYPE_p),                   \
    nkr_TEMPLATES(const volatile, volatile TYPE_p)              \

#define nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)   \
    nkr_TEMPLATES(const, const volatile TYPE_p),                        \
    nkr_TEMPLATES(volatile, const volatile TYPE_p),                     \
    nkr_TEMPLATES(const volatile, const volatile TYPE_p)                \

#define nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_ANY(TYPE_p)               \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),   \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_CONST(TYPE_p),           \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p),        \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)   \

#define nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_ANY_QUALIFIED(TYPE_p)     \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_CONST(TYPE_p),           \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p),        \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)   \

#define nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_ANY_NON_QUALIFIED(TYPE_p) \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p)    \

#define nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_ANY_CONST(TYPE_p)         \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_CONST(TYPE_p),           \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)   \

#define nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_ANY_NON_CONST(TYPE_p)     \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),   \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p)         \

#define nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_ANY_VOLATILE(TYPE_p)      \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p),        \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)   \

#define nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_ANY_NON_VOLATILE(TYPE_p)  \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),   \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_CONST(TYPE_p)            \

#define nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_ANY_NOT_JUST_NON_QUALIFIED(TYPE_p)    \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_CONST(TYPE_p),                       \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p),                    \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)               \

#define nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_ANY_NOT_JUST_CONST(TYPE_p)    \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),       \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p),            \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)       \

#define nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_ANY_NOT_JUST_VOLATILE(TYPE_p) \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),       \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_CONST(TYPE_p),               \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_CONST_VOLATILE(TYPE_p)       \

#define nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_ANY_NOT_JUST_CONST_VOLATILE(TYPE_p)   \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_NON_QUALIFIED(TYPE_p),               \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_CONST(TYPE_p),                       \
    nkr_ANY_NOT_JUST_NON_QUALIFIED_OF_JUST_VOLATILE(TYPE_p)                     \

// ANY_NOT_JUST_CONST
#define nkr_ANY_NOT_JUST_CONST_OF_JUST_NON_QUALIFIED(TYPE_p)    \
    nkr_TEMPLATES(nkr_BLANK, TYPE_p),                           \
    nkr_TEMPLATES(volatile, TYPE_p),                            \
    nkr_TEMPLATES(const volatile, TYPE_p)                       \

#define nkr_ANY_NOT_JUST_CONST_OF_JUST_CONST(TYPE_p)    \
    nkr_TEMPLATES(nkr_BLANK, const TYPE_p),             \
    nkr_TEMPLATES(volatile, const TYPE_p),              \
    nkr_TEMPLATES(const volatile, const TYPE_p)         \

#define nkr_ANY_NOT_JUST_CONST_OF_JUST_VOLATILE(TYPE_p) \
    nkr_TEMPLATES(nkr_BLANK, volatile TYPE_p),          \
    nkr_TEMPLATES(volatile, volatile TYPE_p),           \
    nkr_TEMPLATES(const volatile, volatile TYPE_p)      \

#define nkr_ANY_NOT_JUST_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)   \
    nkr_TEMPLATES(nkr_BLANK, const volatile TYPE_p),            \
    nkr_TEMPLATES(volatile, const volatile TYPE_p),             \
    nkr_TEMPLATES(const volatile, const volatile TYPE_p)        \

#define nkr_ANY_NOT_JUST_CONST_OF_ANY(TYPE_p)               \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),   \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_CONST(TYPE_p),           \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_VOLATILE(TYPE_p),        \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)   \

#define nkr_ANY_NOT_JUST_CONST_OF_ANY_QUALIFIED(TYPE_p)     \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_CONST(TYPE_p),           \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_VOLATILE(TYPE_p),        \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)   \

#define nkr_ANY_NOT_JUST_CONST_OF_ANY_NON_QUALIFIED(TYPE_p) \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_NON_QUALIFIED(TYPE_p)    \

#define nkr_ANY_NOT_JUST_CONST_OF_ANY_CONST(TYPE_p)         \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_CONST(TYPE_p),           \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)   \

#define nkr_ANY_NOT_JUST_CONST_OF_ANY_NON_CONST(TYPE_p)     \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),   \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_VOLATILE(TYPE_p)         \

#define nkr_ANY_NOT_JUST_CONST_OF_ANY_VOLATILE(TYPE_p)      \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_VOLATILE(TYPE_p),        \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)   \

#define nkr_ANY_NOT_JUST_CONST_OF_ANY_NON_VOLATILE(TYPE_p)  \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),   \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_CONST(TYPE_p)            \

#define nkr_ANY_NOT_JUST_CONST_OF_ANY_NOT_JUST_NON_QUALIFIED(TYPE_p)    \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_CONST(TYPE_p),                       \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_VOLATILE(TYPE_p),                    \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)               \

#define nkr_ANY_NOT_JUST_CONST_OF_ANY_NOT_JUST_CONST(TYPE_p)    \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),       \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_VOLATILE(TYPE_p),            \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)       \

#define nkr_ANY_NOT_JUST_CONST_OF_ANY_NOT_JUST_VOLATILE(TYPE_p) \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),       \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_CONST(TYPE_p),               \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_CONST_VOLATILE(TYPE_p)       \

#define nkr_ANY_NOT_JUST_CONST_OF_ANY_NOT_JUST_CONST_VOLATILE(TYPE_p)   \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_NON_QUALIFIED(TYPE_p),               \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_CONST(TYPE_p),                       \
    nkr_ANY_NOT_JUST_CONST_OF_JUST_VOLATILE(TYPE_p)                     \

// ANY_NOT_JUST_VOLATILE
#define nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p) \
    nkr_TEMPLATES(nkr_BLANK, TYPE_p),                           \
    nkr_TEMPLATES(const, TYPE_p),                               \
    nkr_TEMPLATES(const volatile, TYPE_p)                       \

#define nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_CONST(TYPE_p) \
    nkr_TEMPLATES(nkr_BLANK, const TYPE_p),             \
    nkr_TEMPLATES(const, const TYPE_p),                 \
    nkr_TEMPLATES(const volatile, const TYPE_p)         \

#define nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_VOLATILE(TYPE_p)  \
    nkr_TEMPLATES(nkr_BLANK, volatile TYPE_p),              \
    nkr_TEMPLATES(const, volatile TYPE_p),                  \
    nkr_TEMPLATES(const volatile, volatile TYPE_p)          \

#define nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)    \
    nkr_TEMPLATES(nkr_BLANK, const volatile TYPE_p),                \
    nkr_TEMPLATES(const, const volatile TYPE_p),                    \
    nkr_TEMPLATES(const volatile, const volatile TYPE_p)            \

#define nkr_ANY_NOT_JUST_VOLATILE_OF_ANY(TYPE_p)                \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_CONST(TYPE_p),            \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_NOT_JUST_VOLATILE_OF_ANY_QUALIFIED(TYPE_p)      \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_CONST(TYPE_p),            \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_NOT_JUST_VOLATILE_OF_ANY_NON_QUALIFIED(TYPE_p)  \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p)     \

#define nkr_ANY_NOT_JUST_VOLATILE_OF_ANY_CONST(TYPE_p)          \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_CONST(TYPE_p),            \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_NOT_JUST_VOLATILE_OF_ANY_NON_CONST(TYPE_p)      \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_VOLATILE(TYPE_p)          \

#define nkr_ANY_NOT_JUST_VOLATILE_OF_ANY_VOLATILE(TYPE_p)       \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_NOT_JUST_VOLATILE_OF_ANY_NON_VOLATILE(TYPE_p)   \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_CONST(TYPE_p)             \

#define nkr_ANY_NOT_JUST_VOLATILE_OF_ANY_NOT_JUST_NON_QUALIFIED(TYPE_p) \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_CONST(TYPE_p),                    \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_VOLATILE(TYPE_p),                 \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)            \

#define nkr_ANY_NOT_JUST_VOLATILE_OF_ANY_NOT_JUST_CONST(TYPE_p) \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),    \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_VOLATILE(TYPE_p),         \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)    \

#define nkr_ANY_NOT_JUST_VOLATILE_OF_ANY_NOT_JUST_VOLATILE(TYPE_p)  \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),        \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_CONST(TYPE_p),                \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)        \

#define nkr_ANY_NOT_JUST_VOLATILE_OF_ANY_NOT_JUST_CONST_VOLATILE(TYPE_p)    \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),                \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_CONST(TYPE_p),                        \
    nkr_ANY_NOT_JUST_VOLATILE_OF_JUST_VOLATILE(TYPE_p)                      \

// ANY_NOT_JUST_CONST_VOLATILE
#define nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p)   \
    nkr_TEMPLATES(nkr_BLANK, TYPE_p),                                   \
    nkr_TEMPLATES(const, TYPE_p),                                       \
    nkr_TEMPLATES(volatile, TYPE_p)                                     \

#define nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_CONST(TYPE_p)   \
    nkr_TEMPLATES(nkr_BLANK, const TYPE_p),                     \
    nkr_TEMPLATES(const, const TYPE_p),                         \
    nkr_TEMPLATES(volatile, const TYPE_p)                       \

#define nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_VOLATILE(TYPE_p)    \
    nkr_TEMPLATES(nkr_BLANK, volatile TYPE_p),                      \
    nkr_TEMPLATES(const, volatile TYPE_p),                          \
    nkr_TEMPLATES(volatile, volatile TYPE_p)                        \

#define nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)  \
    nkr_TEMPLATES(nkr_BLANK, const volatile TYPE_p),                    \
    nkr_TEMPLATES(const, const volatile TYPE_p),                        \
    nkr_TEMPLATES(volatile, const volatile TYPE_p)                      \

#define nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_ANY(TYPE_p)              \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),  \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_CONST(TYPE_p),          \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_VOLATILE(TYPE_p),       \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)  \

#define nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_ANY_QUALIFIED(TYPE_p)    \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_CONST(TYPE_p),          \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_VOLATILE(TYPE_p),       \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)  \

#define nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_ANY_NON_QUALIFIED(TYPE_p)    \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p)       \

#define nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_ANY_CONST(TYPE_p)        \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_CONST(TYPE_p),          \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)  \

#define nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_ANY_NON_CONST(TYPE_p)    \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),  \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_VOLATILE(TYPE_p)        \

#define nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_ANY_VOLATILE(TYPE_p)     \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_VOLATILE(TYPE_p),       \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)  \

#define nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_ANY_NON_VOLATILE(TYPE_p) \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),  \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_CONST(TYPE_p)           \

#define nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_ANY_NOT_JUST_NON_QUALIFIED(TYPE_p)   \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_CONST(TYPE_p),                      \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_VOLATILE(TYPE_p),                   \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)              \

#define nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_ANY_NOT_JUST_CONST(TYPE_p)   \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),      \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_VOLATILE(TYPE_p),           \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)      \

#define nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_ANY_NOT_JUST_VOLATILE(TYPE_p)    \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),          \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_CONST(TYPE_p),                  \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_CONST_VOLATILE(TYPE_p)          \

#define nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_ANY_NOT_JUST_CONST_VOLATILE(TYPE_p)  \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_NON_QUALIFIED(TYPE_p),              \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_CONST(TYPE_p),                      \
    nkr_ANY_NOT_JUST_CONST_VOLATILE_OF_JUST_VOLATILE(TYPE_p)                    \
