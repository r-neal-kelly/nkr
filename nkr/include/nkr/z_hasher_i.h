/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/z_intrinsics.h"

namespace nkr {

    /*
        It would seem like the wise thing to do would be to require that the hashing function
        return a array::stack_t of either words or bytes. this way there is an understanding
        that the resultant hash can be any number of bits, such as 32, 64, 256, 512, etc.

        If we do require that the array::stack_t be in words, then the implementor of the hasher
        will have to somehow adapt their algorithm to the word_t, preferably statically in the
        compilation process through use of constexpr. It may assert if it can't handle a certain
        word_t I suppose.

        Another issue, the parameters of the hashing function. I think they should be a pointer
        of units being hashed, and a unit_count. I'm not sure yet if this unit_t should be in the
        template parameters of the hasher_t or just in the hasher function. But in any case, if
        necessary, the hasher can statically assert when it can't handle a certain type, which I
        think would be extremely rare.

        Some hashers require a salt or some other third parameter for hashing. This should be stored
        and created on the object itself. And for this reason, it's probably fair to store the hasher
        on other types instead of assuming a static object like we do with allocators, which is most
        appropiate for that class of types because it removes a whole host of problems with inheritance
        and composition with allocation, whereas I don't think hashers need to have the same consideration
        due to their not being global in nature like allocation is.

        Whereas it's relatively easy to create a private static allocator, doing so with a hasher that needs
        salts or whatever else would probably prove difficult. That said, I'm still considering making the allocators
        go on the types themselves because it would be easier for implementors...

        This may seem irrelevent for making hashers, but we're tyring to create a useable library that is consistent,
        and allocators and hashers have a lot of similarities when it comes to implementing and passing them to types.
    */

}
