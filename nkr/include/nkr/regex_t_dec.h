/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "intrinsics.h"
#include "traits.h"

#include "allocator/heap_t.h"

#include "array/dynamic_t.h"

#include "enumeration/flags_t.h"
#include "enumeration/types_t.h"

namespace nkr {

    namespace $regex_t {};

}

namespace nkr { namespace $regex_t {

    class general_flags_e :
        public enumeration::flags_t<unsigned_word_t>
    {
    public:
        using base_t    = enumeration::flags_t<unsigned_word_t>;

    public:
        enum : value_t
        {
            GLOBAL,
            CASELESS,
            MULTILINE,
        };

    public:
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(general_flags_e, base_t);
    };

    class state_e :
        public enumeration::types_t<signed_word_t>
    {
    public:
        using base_t    = enumeration::types_t<signed_word_t>;

    public:
        enum : value_t
        {
            NONE = base_t::NONE,

            MATCH,
            ANY_POINT, // .
        };

    public:
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(state_e, base_t);
    };

    template <typename>
    class syntax_tree_t
    {
    public:
        //array::dynamic_t<> 
    };

}}

namespace nkr {

    // maybe we should accept a stack string_t to put in the footprint?
    template <
        typename charcoder_p,
        typename allocator_p    = allocator::heap_t<typename charcoder_p::unit_t>
    > class regex_t
    {
    public:
        using general_flags_e   = $regex_t::general_flags_e;
        using syntax_tree_t     = $regex_t::syntax_tree_t<void_t>;

    public:
        general_flags_e general_flags;
        syntax_tree_t   syntax_tree; // should use allocator.

    public:
        // should be the charcoder's unit_t probably.
        regex_t(tr2<any_tg, c_pointer_ttg, of_any_tg, char> auto expression);

        // should accept a dynamic string_t as well

        // maybe we should only accept a static string_t?
        // probably the simplest thing is to just store a dynamic string through the provided allocator.
        // we'll have to use the allocator quite a bit to create a regex_t anyway, pretty sure.
    };

}
