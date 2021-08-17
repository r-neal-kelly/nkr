/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsic.h"
#include "nkr/traits.h"

namespace nkr { namespace os { namespace atomic {

    template <integral_tr atom_p>
    inline atom_p   Access(const volatile atom_p& atom);
    template <pointer_tr atom_p>
    inline atom_p   Access(const volatile atom_p& atom);

    template <integral_tr atom_p>
    inline atom_p   Access_Add(const volatile atom_p& atom, integral_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Access_Add(const volatile atom_p& atom, integral_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   Access_Subtract(const volatile atom_p& atom, integral_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Access_Subtract(const volatile atom_p& atom, integral_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   Access_Or(const volatile atom_p& atom, integral_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   Access_And(const volatile atom_p& atom, integral_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   Access_Xor(const volatile atom_p& atom, integral_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   Assign(volatile atom_p& atom, integral_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Assign(volatile atom_p& atom, pointer_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   Assign_Add(volatile atom_p& atom, integral_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Assign_Add(volatile atom_p& atom, integral_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   Assign_Subtract(volatile atom_p& atom, integral_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Assign_Subtract(volatile atom_p& atom, integral_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   Assign_Or(volatile atom_p& atom, integral_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   Assign_And(volatile atom_p& atom, integral_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   Assign_Xor(volatile atom_p& atom, integral_tr auto with);

    template <integral_8_tr atom_p>
    inline atom_p   Exchange(volatile atom_p& atom, integral_tr auto with);
    template <integral_16_tr atom_p>
    inline atom_p   Exchange(volatile atom_p& atom, integral_tr auto with);
    template <integral_32_tr atom_p>
    inline atom_p   Exchange(volatile atom_p& atom, integral_tr auto with);
    template <integral_64_tr atom_p>
    inline atom_p   Exchange(volatile atom_p& atom, integral_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Exchange(volatile atom_p& atom, pointer_tr auto with);

    template <integral_8_tr atom_p>
    inline atom_p   Exchange_If_Equals(volatile atom_p& atom, integral_tr auto with, integral_tr auto target);
    template <integral_16_tr atom_p>
    inline atom_p   Exchange_If_Equals(volatile atom_p& atom, integral_tr auto with, integral_tr auto target);
    template <integral_32_tr atom_p>
    inline atom_p   Exchange_If_Equals(volatile atom_p& atom, integral_tr auto with, integral_tr auto target);
    template <integral_64_tr atom_p>
    inline atom_p   Exchange_If_Equals(volatile atom_p& atom, integral_tr auto with, integral_tr auto target);
    template <pointer_tr atom_p>
    inline atom_p   Exchange_If_Equals(volatile atom_p& atom, pointer_tr auto with, pointer_tr auto target);

    template <integral_8_tr atom_p>
    inline atom_p   Exchange_Add(volatile atom_p& atom, integral_tr auto with);
    template <integral_16_tr atom_p>
    inline atom_p   Exchange_Add(volatile atom_p& atom, integral_tr auto with);
    template <integral_32_tr atom_p>
    inline atom_p   Exchange_Add(volatile atom_p& atom, integral_tr auto with);
    template <integral_64_tr atom_p>
    inline atom_p   Exchange_Add(volatile atom_p& atom, integral_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Exchange_Add(volatile atom_p& atom, integral_tr auto with);

    template <integral_8_tr atom_p>
    inline atom_p   Exchange_Subtract(volatile atom_p& atom, integral_tr auto with);
    template <integral_16_tr atom_p>
    inline atom_p   Exchange_Subtract(volatile atom_p& atom, integral_tr auto with);
    template <integral_32_tr atom_p>
    inline atom_p   Exchange_Subtract(volatile atom_p& atom, integral_tr auto with);
    template <integral_64_tr atom_p>
    inline atom_p   Exchange_Subtract(volatile atom_p& atom, integral_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Exchange_Subtract(volatile atom_p& atom, integral_tr auto with);

    template <integral_8_tr atom_p>
    inline atom_p   Exchange_Or(volatile atom_p& atom, integral_tr auto with);
    template <integral_16_tr atom_p>
    inline atom_p   Exchange_Or(volatile atom_p& atom, integral_tr auto with);
    template <integral_32_tr atom_p>
    inline atom_p   Exchange_Or(volatile atom_p& atom, integral_tr auto with);
    template <integral_64_tr atom_p>
    inline atom_p   Exchange_Or(volatile atom_p& atom, integral_tr auto with);

    template <integral_8_tr atom_p>
    inline atom_p   Exchange_And(volatile atom_p& atom, integral_tr auto with);
    template <integral_16_tr atom_p>
    inline atom_p   Exchange_And(volatile atom_p& atom, integral_tr auto with);
    template <integral_32_tr atom_p>
    inline atom_p   Exchange_And(volatile atom_p& atom, integral_tr auto with);
    template <integral_64_tr atom_p>
    inline atom_p   Exchange_And(volatile atom_p& atom, integral_tr auto with);

    template <integral_8_tr atom_p>
    inline atom_p   Exchange_Xor(volatile atom_p& atom, integral_tr auto with);
    template <integral_16_tr atom_p>
    inline atom_p   Exchange_Xor(volatile atom_p& atom, integral_tr auto with);
    template <integral_32_tr atom_p>
    inline atom_p   Exchange_Xor(volatile atom_p& atom, integral_tr auto with);
    template <integral_64_tr atom_p>
    inline atom_p   Exchange_Xor(volatile atom_p& atom, integral_tr auto with);

}}}

namespace nkr { namespace os { namespace endian {

    bool_t          Is_Big();
    bool_t          Is_Little();

    template <integral_16_tr i16_p>
    inline i16_p    Swap(i16_p bytes);
    template <integral_32_tr i32_p>
    inline i32_p    Swap(i32_p bytes);
    template <integral_64_tr i64_p>
    inline i64_p    Swap(i64_p bytes);

}}}

namespace nkr { namespace os { namespace heap {

    /**
    * @name allocation
    * 
    * @brief
    *   Borrow a certain amount of memory from the heap. Use it, expand it, and give it back.
    */ 
    /** @{ **/

    /**
    * @brief
    *   Gives you memory to use until your program exits.
    * 
    * @param byte_count
    *   Asserts if this equals zero.
    * 
    * @returns
    *   A pointer to the allocated bytes when it succeeds.
    * 
    * @returns
    *   A `nullptr` when it fails.
    * 
    * @details
    *   There are a few limitations to the number of bytes you can allocate depending on:
    * 
    *   1. how much ram is physically in the computer
    *   2. how much space the operating system has left to give
    *   3. the settings that your compiler operates with
    *   4. what the natural word size of the processor is
    * 
    *   At most the largest number of bytes you will be able to allocate is the max number that can fit in an nkr::count_t (an alias of nkr::word_t). If you are running on a 32 bit processor you will only be able to allocate one byte shy of 4gb, which is no where near the amount of memory you can allocate on a 64 bit processor. Furthermore, limitations may come into play depending on the operating system, which may significantly decrease that amount even further.
    */
    byte_t* Allocate(count_t byte_count);

    /**
    * @brief
    *   Gives you more memory while keeping all your data intact.
    * 
    * @param bytes
    *   This should be a pointer returned by nkr::os::heap::Allocate. When successful, `bytes` will be set to a new pointer if necessary, else it is left unchanged.
    * 
    * @param new_byte_count
    *   Asserts if this equals zero.
    *
    * @returns
    *   `true` when it succeeds.
    * 
    * @returns
    *   `false` when it fails.
    * 
    * @details
    *   This will allocate more memory for you if `new_byte_count` is greater than the currently allocated byte_count, which is stored internally in the operating system. Otherwise, it will simply return successfully with no changes to `bytes`. See nkr::os::heap::Allocate for more details about allocation generally.
    *
    * @note
    *   This cannot shrink the memory you allocate, but some higher level types in the library can by request.
    * 
    * @todo
    *   Maybe return an enum_t to indicate different kinds of failures, at least on Windows.
    */
    bool_t Reallocate(byte_t*& bytes, count_t new_byte_count);

    /**
    * @brief
    *   Takes back memory you no longer need so it can be reused later.
    * 
    * @param bytes
    *   This should be a pointer returned by nkr::os::heap::Allocate. `bytes` will be set to `nullptr` after deallocating.
    * 
    * @details
    *   When using these functions, memory will never be deallocated automatically for you like it is in some higher level types. You will have to manually deallocate every pointer you allocate, or else you may unexpectedly run out of memory. Regardless, the operating system will deallocate everything that has not already been deallocated when your program exits.
    */
    void_t Deallocate(byte_t*& bytes);

    /** @} **/

}}}

namespace nkr { namespace os { namespace heap {

    /**
    * @name zero-initialized allocation
    * 
    * @brief
    *   A variant of regular allocation, all the values in your memory will be initialized to zero.
    */
    /** @{ **/

    /**
    * @brief
    *   Gives you zero-initialized memory to use until your program exits.
    * 
    * @details
    *   This uses an efficient operating system dependent algorithm to avoid zeroing out all values during runtime. Normally the os will keep pages of zero initialized bytes ready for allocation and it will only need to initialize them on the occasion that it doesn't have any of those pages readily available. Please see nkr::os::heap::Allocate for more details.
    * 
    * @note
    *   The returned pointer can be used with nkr::os::heap::Reallocate to allocate more memory but without it being zero-intialized, and nkr::os::heap::Deallocate to free the memory. Both of these are currently frowned upon because they may not work in future updates or on certain operating systems.
    */
    byte_t* Allocate_Zeros(count_t byte_count);

    /**
    * @brief
    *   Gives you more zero-initialized memory while keeping all your data intact.
    * 
    * @details
    *   Please see nkr::os::heap::Reallocate for more details.
    */
    bool_t Reallocate_Zeros(byte_t*& bytes, count_t new_byte_count);

    /**
    * @brief
    *   Takes back memory you no longer need so it can be reused later.
    * 
    * @details
    *   Please see nkr::os::heap::Reallocate for more details.
    * 
    * @note
    *   This does not zero the memory.
    */
    void_t Deallocate_Zeros(byte_t*& bytes);

    /** @} **/

}}}

#include "nkr/os.inl"
