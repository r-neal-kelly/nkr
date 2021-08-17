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
    *   Borrow a certain amount of memory from the heap. Grow it or give it back.
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
    * 
    * @todo
    *   make sure to doc assertions
    * @todo
    *   link to types that can shrink data in the above note. array_dynamic_t should be able to do that.
    */
    /** @{ **/
    /**
    * @return
    *   *on success*: a pointer to the allocated bytes
    * @return
    *   *on failure*: a nullptr
    */
    byte_t* Allocate(count_t byte_count);
    /**
    * @return
    *   *on success*: true
    * @return
    *   *on failure*: false
    * 
    * @note
    *   This cannot shrink the amount of memory you allocate, but higher level types in the library offer this capability. You can also provide your own functionality by using these functions.
    */
    bool_t  Reallocate(byte_t*& bytes, count_t new_byte_count);
    void_t  Deallocate(byte_t*& bytes);
    /** @} **/

    /**
    * @name zero-initialized allocation
    * 
    * @details
    *   This is a variant of regular allocation. The only functional difference is that it initializes all values to zero. This uses an efficient operating system dependent algorithm to avoid zeroing out all values during runtime. Normally the os will keep pages of zero'd out bytes ready for allocation and will only need to initialize them on the occasion that it doesn't have those pages readily available.
    */
    /** @{ **/
    /**
    * @return
    *   *on success*: a pointer to the allocated bytes
    * @return
    *   *on failure*: a nullptr
    * 
    * @note
    *   The returned pointer can be used with nkr::os::heap::Reallocate to allocate more memory that is not zero-intialized, however this is frowned upon because it may not work in future updates or on certain operating systems.
    * 
    * @note
    *   Although the returned pointer can be used with nkr::os::heap::Deallocate, this is frowned upon because it may not work in future updates or on certain operating systems.
    */
    byte_t* Allocate_Zeros(count_t byte_count);
    /**
    * @return
    *   *on success*: true
    * @return
    *   *on failure*: false
    */
    bool_t  Reallocate_Zeros(byte_t*& bytes, count_t new_byte_count);
    /**
    * @note
    *   This does not zero the memory.
    */
    void_t  Deallocate_Zeros(byte_t*& bytes);
    /** @} **/

}}}

#include "nkr/os.inl"
