/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/macros.h"

namespace nkr {

    #undef nkr_M
    #undef nkr_W

    #undef nkr_P
    #undef nkr_b

    #undef nkr_INITIALIZE_STATIC_SAFELY

    #undef nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR
    #undef nkr_DEFINE_INHERITANCE_WRAPPER_BASE_ACCESSORS

    #undef nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM
    #undef nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS
    #undef nkr_DEFINE_CONTAINER_TRAITS

    #define nkr_M   \
        (

    #define nkr_W   \
        )

    #define nkr_P   \
        do {

    #define nkr_b       \
        } while(false)

    #define nkr_INITIALIZE_STATIC_SAFELY(INITIALIZER_p)     \
    nkr_P                                                   \
        static volatile bool_t is_initialized = false;      \
        if (os::atomic::Access(is_initialized) == false) {  \
            static std::mutex lock;                         \
            std::lock_guard<std::mutex> locker(lock);       \
            if (!is_initialized) {                          \
                INITIALIZER_p();                            \
                is_initialized = true;                      \
            }                                               \
        }                                                   \
    nkr_b

    #define nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(WRAPPER_p, BASE_p)            \
        using BASE_p::BASE_p;                                                           \
        using BASE_p::operator =;                                                       \
                                                                                        \
        WRAPPER_p() :                                                                   \
            BASE_p()                                                                    \
        {                                                                               \
        }                                                                               \
                                                                                        \
        WRAPPER_p(const WRAPPER_p& other) :                                             \
            BASE_p(static_cast<const BASE_p&>(other))                                   \
        {                                                                               \
        }                                                                               \
                                                                                        \
        WRAPPER_p(const volatile WRAPPER_p& other) :                                    \
            BASE_p(static_cast<const volatile BASE_p&>(other))                          \
        {                                                                               \
        }                                                                               \
                                                                                        \
        WRAPPER_p(WRAPPER_p&& other) noexcept :                                         \
            BASE_p(nkr::Move(static_cast<BASE_p&>(other)))                              \
        {                                                                               \
        }                                                                               \
                                                                                        \
        WRAPPER_p(volatile WRAPPER_p&& other) noexcept :                                \
            BASE_p(nkr::Move(static_cast<volatile BASE_p&>(other)))                     \
        {                                                                               \
        }                                                                               \
                                                                                        \
        WRAPPER_p& operator =(const WRAPPER_p& other)                                   \
        {                                                                               \
            BASE_p::operator =(static_cast<const BASE_p&>(other));                      \
            return *this;                                                               \
        }                                                                               \
                                                                                        \
        volatile WRAPPER_p& operator =(const WRAPPER_p& other) volatile                 \
        {                                                                               \
            BASE_p::operator =(static_cast<const BASE_p&>(other));                      \
            return *this;                                                               \
        }                                                                               \
                                                                                        \
        WRAPPER_p& operator =(const volatile WRAPPER_p& other)                          \
        {                                                                               \
            BASE_p::operator =(static_cast<const volatile BASE_p&>(other));             \
            return *this;                                                               \
        }                                                                               \
                                                                                        \
        volatile WRAPPER_p& operator =(const volatile WRAPPER_p& other) volatile        \
        {                                                                               \
            BASE_p::operator =(static_cast<const volatile BASE_p&>(other));             \
            return *this;                                                               \
        }                                                                               \
                                                                                        \
        WRAPPER_p& operator =(WRAPPER_p&& other) noexcept                               \
        {                                                                               \
            BASE_p::operator =(nkr::Move(static_cast<BASE_p&>(other)));                 \
            return *this;                                                               \
        }                                                                               \
                                                                                        \
        volatile WRAPPER_p& operator =(WRAPPER_p&& other) volatile noexcept             \
        {                                                                               \
            BASE_p::operator =(nkr::Move(static_cast<BASE_p&>(other)));                 \
            return *this;                                                               \
        }                                                                               \
                                                                                        \
        WRAPPER_p& operator =(volatile WRAPPER_p&& other) noexcept                      \
        {                                                                               \
            BASE_p::operator =(nkr::Move(static_cast<volatile BASE_p&>(other)));        \
            return *this;                                                               \
        }                                                                               \
                                                                                        \
        volatile WRAPPER_p& operator =(volatile WRAPPER_p&& other) volatile noexcept    \
        {                                                                               \
            BASE_p::operator =(nkr::Move(static_cast<volatile BASE_p&>(other)));        \
            return *this;                                                               \
        }                                                                               \
                                                                                        \
        ~WRAPPER_p()                                                                    \
        {                                                                               \
        }

    #define nkr_DEFINE_INHERITANCE_WRAPPER_BASE_ACCESSORS(ACCESSOR_NAME_p, BASE_p)  \
        BASE_p& ACCESSOR_NAME_p()                                                   \
        {                                                                           \
            return *static_cast<BASE_p*>(this);                                     \
        }                                                                           \
                                                                                    \
        const BASE_p& ACCESSOR_NAME_p() const                                       \
        {                                                                           \
            return *static_cast<const BASE_p*>(this);                               \
        }                                                                           \
                                                                                    \
        volatile BASE_p& ACCESSOR_NAME_p() volatile                                 \
        {                                                                           \
            return *static_cast<volatile BASE_p*>(this);                            \
        }                                                                           \
                                                                                    \
        const volatile BASE_p& ACCESSOR_NAME_p() const volatile                     \
        {                                                                           \
            return *static_cast<const volatile BASE_p*>(this);                      \
        }

    #define nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(TRAIT_p, PARAM_1_p)   \
        template <typename PARAM_1_p>                               \
        concept not_##TRAIT_p =                                     \
            !TRAIT_p<PARAM_1_p>

    #define nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(TRAIT_p, PARAM_1_p, PARAM_2_p)   \
        template <typename PARAM_1_p, typename PARAM_2_p>                       \
        concept not_##TRAIT_p =                                                 \
            !TRAIT_p<PARAM_1_p, PARAM_2_p>

    #define nkr_DEFINE_CONTAINER_OF_TRAITS(CONTAINER_TRAIT_NAME_p)                                                          \
        template <typename container_p, typename unit_p>                                                                    \
        concept CONTAINER_TRAIT_NAME_p##_of_any_tr =                                                                        \
            CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                     \
            is_any_tr<typename container_p::unit_t, unit_p>;                                                                \
                                                                                                                            \
            template <typename container_p, typename unit_p>                                                                \
            concept CONTAINER_TRAIT_NAME_p##_of_any_qualified_tr =                                                          \
                CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                 \
                is_any_qualified_tr<typename container_p::unit_t, unit_p>;                                                  \
                                                                                                                            \
            template <typename container_p, typename unit_p>                                                                \
            concept CONTAINER_TRAIT_NAME_p##_of_any_non_qualified_tr =                                                      \
                CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                 \
                is_any_non_qualified_tr<typename container_p::unit_t, unit_p>;                                              \
                                                                                                                            \
            template <typename container_p, typename unit_p>                                                                \
            concept CONTAINER_TRAIT_NAME_p##_of_any_const_tr =                                                              \
                CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                 \
                is_any_const_tr<typename container_p::unit_t, unit_p>;                                                      \
                                                                                                                            \
            template <typename container_p, typename unit_p>                                                                \
            concept CONTAINER_TRAIT_NAME_p##_of_any_non_const_tr =                                                          \
                CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                 \
                is_any_non_const_tr<typename container_p::unit_t, unit_p>;                                                  \
                                                                                                                            \
            template <typename container_p, typename unit_p>                                                                \
            concept CONTAINER_TRAIT_NAME_p##_of_any_volatile_tr =                                                           \
                CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                 \
                is_any_volatile_tr<typename container_p::unit_t, unit_p>;                                                   \
                                                                                                                            \
            template <typename container_p, typename unit_p>                                                                \
            concept CONTAINER_TRAIT_NAME_p##_of_any_non_volatile_tr =                                                       \
                CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                 \
                is_any_non_volatile_tr<typename container_p::unit_t, unit_p>;                                               \
                                                                                                                            \
        template <typename container_p, typename unit_p>                                                                    \
        concept CONTAINER_TRAIT_NAME_p##_of_not_any_tr =                                                                    \
            CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                     \
            not_is_any_tr<typename container_p::unit_t, unit_p>;                                                            \
                                                                                                                            \
            template <typename container_p, typename unit_p>                                                                \
            concept CONTAINER_TRAIT_NAME_p##_of_not_any_qualified_tr =                                                      \
                CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                 \
                not_is_any_qualified_tr<typename container_p::unit_t, unit_p>;                                              \
                                                                                                                            \
            template <typename container_p, typename unit_p>                                                                \
            concept CONTAINER_TRAIT_NAME_p##_of_not_any_non_qualified_tr =                                                  \
                CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                 \
                not_is_any_non_qualified_tr<typename container_p::unit_t, unit_p>;                                          \
                                                                                                                            \
            template <typename container_p, typename unit_p>                                                                \
            concept CONTAINER_TRAIT_NAME_p##_of_not_any_const_tr =                                                          \
                CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                 \
                not_is_any_const_tr<typename container_p::unit_t, unit_p>;                                                  \
                                                                                                                            \
            template <typename container_p, typename unit_p>                                                                \
            concept CONTAINER_TRAIT_NAME_p##_of_not_any_non_const_tr =                                                      \
                CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                 \
                not_is_any_non_const_tr<typename container_p::unit_t, unit_p>;                                              \
                                                                                                                            \
            template <typename container_p, typename unit_p>                                                                \
            concept CONTAINER_TRAIT_NAME_p##_of_not_any_volatile_tr =                                                       \
                CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                 \
                not_is_any_volatile_tr<typename container_p::unit_t, unit_p>;                                               \
                                                                                                                            \
            template <typename container_p, typename unit_p>                                                                \
            concept CONTAINER_TRAIT_NAME_p##_of_not_any_non_volatile_tr =                                                   \
                CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                 \
                not_is_any_non_volatile_tr<typename container_p::unit_t, unit_p>;                                           \
                                                                                                                            \
        template <typename container_p, typename unit_p>                                                                    \
        concept CONTAINER_TRAIT_NAME_p##_of_just_tr =                                                                       \
            CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                     \
            is_just_tr<typename container_p::unit_t, unit_p>;                                                               \
                                                                                                                            \
            template <typename container_p, typename unit_p>                                                                \
            concept CONTAINER_TRAIT_NAME_p##_of_just_non_qualified_tr =                                                     \
                CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                 \
                is_just_non_qualified_tr<typename container_p::unit_t, unit_p>;                                             \
                                                                                                                            \
            template <typename container_p, typename unit_p>                                                                \
            concept CONTAINER_TRAIT_NAME_p##_of_just_const_tr =                                                             \
                CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                 \
                is_just_const_tr<typename container_p::unit_t, unit_p>;                                                     \
                                                                                                                            \
            template <typename container_p, typename unit_p>                                                                \
            concept CONTAINER_TRAIT_NAME_p##_of_just_volatile_tr =                                                          \
                CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                 \
                is_just_volatile_tr<typename container_p::unit_t, unit_p>;                                                  \
                                                                                                                            \
            template <typename container_p, typename unit_p>                                                                \
            concept CONTAINER_TRAIT_NAME_p##_of_just_const_volatile_tr =                                                    \
                CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                 \
                is_just_const_volatile_tr<typename container_p::unit_t, unit_p>;                                            \
                                                                                                                            \
        template <typename container_p, typename unit_p>                                                                    \
        concept CONTAINER_TRAIT_NAME_p##_of_not_just_tr =                                                                   \
            CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                     \
            not_is_just_tr<typename container_p::unit_t, unit_p>;                                                           \
                                                                                                                            \
            template <typename container_p, typename unit_p>                                                                \
            concept CONTAINER_TRAIT_NAME_p##_of_not_just_non_qualified_tr =                                                 \
                CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                 \
                not_is_just_non_qualified_tr<typename container_p::unit_t, unit_p>;                                         \
                                                                                                                            \
            template <typename container_p, typename unit_p>                                                                \
            concept CONTAINER_TRAIT_NAME_p##_of_not_just_const_tr =                                                         \
                CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                 \
                not_is_just_const_tr<typename container_p::unit_t, unit_p>;                                                 \
                                                                                                                            \
            template <typename container_p, typename unit_p>                                                                \
            concept CONTAINER_TRAIT_NAME_p##_of_not_just_volatile_tr =                                                      \
                CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                 \
                not_is_just_volatile_tr<typename container_p::unit_t, unit_p>;                                              \
                                                                                                                            \
            template <typename container_p, typename unit_p>                                                                \
            concept CONTAINER_TRAIT_NAME_p##_of_not_just_const_volatile_tr =                                                \
                CONTAINER_TRAIT_NAME_p##_tr<container_p> &&                                                                 \
                not_is_just_const_volatile_tr<typename container_p::unit_t, unit_p>;                                        \
                                                                                                                            \
        nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_any_tr, container_p, unit_p);                        \
            nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_any_qualified_tr, container_p, unit_p);          \
            nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_any_non_qualified_tr, container_p, unit_p);      \
            nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_any_const_tr, container_p, unit_p);              \
            nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_any_non_const_tr, container_p, unit_p);          \
            nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_any_volatile_tr, container_p, unit_p);           \
            nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_any_non_volatile_tr, container_p, unit_p);       \
        nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_not_any_tr, container_p, unit_p);                    \
            nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_not_any_qualified_tr, container_p, unit_p);      \
            nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_not_any_non_qualified_tr, container_p, unit_p);  \
            nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_not_any_const_tr, container_p, unit_p);          \
            nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_not_any_non_const_tr, container_p, unit_p);      \
            nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_not_any_volatile_tr, container_p, unit_p);       \
            nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_not_any_non_volatile_tr, container_p, unit_p);   \
        nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_just_tr, container_p, unit_p);                       \
            nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_just_non_qualified_tr, container_p, unit_p);     \
            nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_just_const_tr, container_p, unit_p);             \
            nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_just_volatile_tr, container_p, unit_p);          \
            nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_just_const_volatile_tr, container_p, unit_p);    \
        nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_not_just_tr, container_p, unit_p);                   \
            nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_not_just_non_qualified_tr, container_p, unit_p); \
            nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_not_just_const_tr, container_p, unit_p);         \
            nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_not_just_volatile_tr, container_p, unit_p);      \
            nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(CONTAINER_TRAIT_NAME_p##_of_not_just_const_volatile_tr, container_p, unit_p)

    #define nkr_DEFINE_CONTAINER_TRAITS(CONTAINER_NAME_p)                                                   \
        /* the any_##CONTAINER_NAME_p##_tr must be defined outside this macro and before its called. */     \
                                                                                                            \
            template <typename container_p>                                                                 \
            concept any_qualified_##CONTAINER_NAME_p##_tr =                                                 \
                any_##CONTAINER_NAME_p##_tr<container_p> &&                                                 \
                any_qualified_tr<container_p>;                                                              \
                                                                                                            \
            template <typename container_p>                                                                 \
            concept any_non_qualified_##CONTAINER_NAME_p##_tr =                                             \
                any_##CONTAINER_NAME_p##_tr<container_p> &&                                                 \
                any_non_qualified_tr<container_p>;                                                          \
                                                                                                            \
            template <typename container_p>                                                                 \
            concept any_const_##CONTAINER_NAME_p##_tr =                                                     \
                any_##CONTAINER_NAME_p##_tr<container_p> &&                                                 \
                any_const_tr<container_p>;                                                                  \
                                                                                                            \
            template <typename container_p>                                                                 \
            concept any_non_const_##CONTAINER_NAME_p##_tr =                                                 \
                any_##CONTAINER_NAME_p##_tr<container_p> &&                                                 \
                any_non_const_tr<container_p>;                                                              \
                                                                                                            \
            template <typename container_p>                                                                 \
            concept any_volatile_##CONTAINER_NAME_p##_tr =                                                  \
                any_##CONTAINER_NAME_p##_tr<container_p> &&                                                 \
                any_volatile_tr<container_p>;                                                               \
                                                                                                            \
            template <typename container_p>                                                                 \
            concept any_non_volatile_##CONTAINER_NAME_p##_tr =                                              \
                any_##CONTAINER_NAME_p##_tr<container_p> &&                                                 \
                any_non_volatile_tr<container_p>;                                                           \
                                                                                                            \
        template <typename container_p>                                                                     \
        concept just_##CONTAINER_NAME_p##_tr =                                                              \
            any_##CONTAINER_NAME_p##_tr<container_p> &&                                                     \
            just_tr<container_p>;                                                                           \
                                                                                                            \
            template <typename container_p>                                                                 \
            concept just_non_qualified_##CONTAINER_NAME_p##_tr =                                            \
                any_##CONTAINER_NAME_p##_tr<container_p> &&                                                 \
                just_non_qualified_tr<container_p>;                                                         \
                                                                                                            \
            template <typename container_p>                                                                 \
            concept just_const_##CONTAINER_NAME_p##_tr =                                                    \
                any_##CONTAINER_NAME_p##_tr<container_p> &&                                                 \
                just_const_tr<container_p>;                                                                 \
                                                                                                            \
            template <typename container_p>                                                                 \
            concept just_volatile_##CONTAINER_NAME_p##_tr =                                                 \
                any_##CONTAINER_NAME_p##_tr<container_p> &&                                                 \
                just_volatile_tr<container_p>;                                                              \
                                                                                                            \
            template <typename container_p>                                                                 \
            concept just_const_volatile_##CONTAINER_NAME_p##_tr =                                           \
                any_##CONTAINER_NAME_p##_tr<container_p> &&                                                 \
                just_const_volatile_tr<container_p>;                                                        \
                                                                                                            \
        nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(any_##CONTAINER_NAME_p##_tr, container_p);                        \
            nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(any_qualified_##CONTAINER_NAME_p##_tr, container_p);          \
            nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(any_non_qualified_##CONTAINER_NAME_p##_tr, container_p);      \
            nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(any_const_##CONTAINER_NAME_p##_tr, container_p);              \
            nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(any_non_const_##CONTAINER_NAME_p##_tr, container_p);          \
            nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(any_volatile_##CONTAINER_NAME_p##_tr, container_p);           \
            nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(any_non_volatile_##CONTAINER_NAME_p##_tr, container_p);       \
        nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(just_##CONTAINER_NAME_p##_tr, container_p);                       \
            nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(just_non_qualified_##CONTAINER_NAME_p##_tr, container_p);     \
            nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(just_const_##CONTAINER_NAME_p##_tr, container_p);             \
            nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(just_volatile_##CONTAINER_NAME_p##_tr, container_p);          \
            nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(just_const_volatile_##CONTAINER_NAME_p##_tr, container_p);    \
                                                                                                            \
        nkr_DEFINE_CONTAINER_OF_TRAITS(any_##CONTAINER_NAME_p);                                             \
            nkr_DEFINE_CONTAINER_OF_TRAITS(any_qualified_##CONTAINER_NAME_p);                               \
            nkr_DEFINE_CONTAINER_OF_TRAITS(any_non_qualified_##CONTAINER_NAME_p);                           \
            nkr_DEFINE_CONTAINER_OF_TRAITS(any_const_##CONTAINER_NAME_p);                                   \
            nkr_DEFINE_CONTAINER_OF_TRAITS(any_non_const_##CONTAINER_NAME_p);                               \
            nkr_DEFINE_CONTAINER_OF_TRAITS(any_volatile_##CONTAINER_NAME_p);                                \
            nkr_DEFINE_CONTAINER_OF_TRAITS(any_non_volatile_##CONTAINER_NAME_p);                            \
        nkr_DEFINE_CONTAINER_OF_TRAITS(just_##CONTAINER_NAME_p);                                            \
            nkr_DEFINE_CONTAINER_OF_TRAITS(just_non_qualified_##CONTAINER_NAME_p);                          \
            nkr_DEFINE_CONTAINER_OF_TRAITS(just_const_##CONTAINER_NAME_p);                                  \
            nkr_DEFINE_CONTAINER_OF_TRAITS(just_volatile_##CONTAINER_NAME_p);                               \
            nkr_DEFINE_CONTAINER_OF_TRAITS(just_const_volatile_##CONTAINER_NAME_p)

}
