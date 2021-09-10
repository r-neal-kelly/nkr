/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/pointer_t_dec.h"

#if defined(nkr_DO_EXTERN_TEMPLATES)

namespace nkr {

    template class pointer_t<void_t>;
    template class pointer_t<std_bool_t>;
    template class pointer_t<bool_t>;
    template class pointer_t<u8_t>;
    template class pointer_t<s8_t>;
    template class pointer_t<u16_t>;
    template class pointer_t<s16_t>;
    template class pointer_t<u32_t>;
    template class pointer_t<s32_t>;
    template class pointer_t<u64_t>;
    template class pointer_t<s64_t>;
    template class pointer_t<r32_t>;
    template class pointer_t<r64_t>;

    template class pointer_t<const void_t>;
    template class pointer_t<const std_bool_t>;
    template class pointer_t<const bool_t>;
    template class pointer_t<const u8_t>;
    template class pointer_t<const s8_t>;
    template class pointer_t<const u16_t>;
    template class pointer_t<const s16_t>;
    template class pointer_t<const u32_t>;
    template class pointer_t<const s32_t>;
    template class pointer_t<const u64_t>;
    template class pointer_t<const s64_t>;
    template class pointer_t<const r32_t>;
    template class pointer_t<const r64_t>;

    template class pointer_t<volatile void_t>;
    template class pointer_t<volatile std_bool_t>;
    template class pointer_t<volatile bool_t>;
    template class pointer_t<volatile u8_t>;
    template class pointer_t<volatile s8_t>;
    template class pointer_t<volatile u16_t>;
    template class pointer_t<volatile s16_t>;
    template class pointer_t<volatile u32_t>;
    template class pointer_t<volatile s32_t>;
    template class pointer_t<volatile u64_t>;
    template class pointer_t<volatile s64_t>;
    template class pointer_t<volatile r32_t>;
    template class pointer_t<volatile r64_t>;

    template class pointer_t<volatile const void_t>;
    template class pointer_t<volatile const std_bool_t>;
    template class pointer_t<volatile const bool_t>;
    template class pointer_t<volatile const u8_t>;
    template class pointer_t<volatile const s8_t>;
    template class pointer_t<volatile const u16_t>;
    template class pointer_t<volatile const s16_t>;
    template class pointer_t<volatile const u32_t>;
    template class pointer_t<volatile const s32_t>;
    template class pointer_t<volatile const u64_t>;
    template class pointer_t<volatile const s64_t>;
    template class pointer_t<volatile const r32_t>;
    template class pointer_t<volatile const r64_t>;

}

#endif
