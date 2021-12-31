/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/z_intrinsics.h"
#include "nkr/z_some_t.h"
#include "nkr/z_traits.h"

#include "nkr/z_allocator/heap_t.h"

#include "nkr/z_array/dynamic_t.h"

#include "nkr/z_charcoder/utf_8_t.h"

#include "nkr/z_enumeration/flags_t.h"
#include "nkr/z_enumeration/types_t.h"

#include "nkr/z_string/dynamic_t.h"

namespace nkr {

    namespace $regex_t {
    
        namespace $syntax_tree_t {
        

        
        }
    
    };

}

namespace nkr { namespace $regex_t { namespace $syntax_tree_t {

    // It makes sense to sacrifice the space in memory for execution speed,
    // because the size of text that will be searched will be magnitudes larger
    // than the regex string, even considering the compiled expression!

    class node_type_e :
        public enumeration::types_t<signed_word_t>
    {
    public:
        using base_t    = enumeration::types_t<signed_word_t>;

    public:
        enum : value_t
        {
            MATCH,              // end of the expression

            POINT,              // a literal string::point_t
            ANY_POINT,          // a ., which can be any string::point_t with some exceptions like \n (can be defined by the user)
            STRING,             // a static string of literal charcoder units, as an optimization
            
            LITERAL_CLASS,      // anything in a [] like [abc]
            NOT_LITERAL_CLASS,  // not anything in a [^] like [^abc]
            ABSTRACT_CLASS,     // anything in a class like ~s or ~:Greek:
            NOT_ABSTRACT_CLASS, // not anything in a class like ~S or ~:^Greek:

            BRANCH,             // an operator like *, +, ?, or |

            BEHIND,             // anything in a look-behind (?<), like (?<a|b)
            NOT_BEHIND,         // anything in a look-behind (?<^), like (?<^a|b)
            AHEAD,              // anything in a look-ahead (?>), like (?>a|b)
            NOT_AHEAD,          // anything in a look-ahead (?>^), like (?>^a|b)

            BOUNDARY_OF_WORD,   // ~b, a point in the ~s class which isn't returned in the match string
            BOUNDARY_OF_SPACE,  // ~B, a point in the ~w class which isn't returned in the match string

            FRONT_OF_STRING,    // ^, the prefix of a string which isn't returned in the match string
            BACK_OF_STRING,     // $, the terminus of a string (\0), which isn't returned in the match string
        };

    public:
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(node_type_e, base_t);
    };

    union node_u;

    class node_t
    {
    public:
        node_type_e     type;
        some_t<node_u*> next;
    };

    class match_t :
        public node_t
    {
    public:
    };

    class point_t :
        public node_t
    {
    public:
        string::point_t point;
    };

    class any_point_t :
        public node_t
    {
    public:
    };

    template <charcoder_i charcoder_p>
    class string_t :
        public node_t
    {
    public:
        using charcoder_t   = charcoder_p;

    public:
        //string::static_t<charcoder_t>   string;

        // the size of this type should not be any different for any specialization, because it's just a string::static_t,
        // which is just a pointer to units and a unit_count
    };

    class literal_class_t :
        public node_t
    {
    public:
    };

    class not_literal_class_t :
        public literal_class_t
    {
    public:
    };

    class abstract_class_t :
        public node_t
    {
    public:
    };

    class not_abstract_class_t :
        public abstract_class_t
    {
    public:
    };

    class branch_t :
        public node_t
    {
    public:
        some_t<node_u*> branch;
    };

    class behind_t :
        public node_t
    {
    public:
        some_t<node_u*> tree;
    };

    class not_behind_t :
        public behind_t
    {
    public:
    };

    class ahead_t :
        public node_t
    {
    public:
        some_t<node_u*> tree;
    };

    class not_ahead_t :
        public ahead_t
    {
    public:
    };

    union node_u
    {
    public:
        node_type_e type;

        match_t     match;

        point_t     point;
        any_point_t any_point;
        string_t<charcoder::utf_8_t>    string;

        node_u() {};
        ~node_u() {};
    };

}}}

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

    template <typename allocator_p>
    class syntax_tree_t
    {
    public:
        using allocator_t   = allocator_p;

        using node_type_e   = $syntax_tree_t::node_type_e;
        using node_t        = $syntax_tree_t::node_t;
        using node_u        = $syntax_tree_t::node_u;

    public:
        array::dynamic_t<node_u, allocator_t>   nodes;
        some_t<node_u*>                         first;
    };

}}

namespace nkr {

    // there should probably be a manager that maps expressions to already existing regex_t's.

    // maybe we can have a hash-map for user-defined abstract classes as well as the defaults?

    template <
        charcoder_i charcoder_p,
        typename    allocator_p     = allocator::heap_t<typename charcoder_p::unit_t>
    > class regex_t
    {
    public:
        using charcoder_t       = charcoder_p;
        using allocator_t       = allocator_p;
        using unit_t            = charcoder_p::unit_t;

        using general_flags_e   = $regex_t::general_flags_e;
        using syntax_tree_t     = $regex_t::syntax_tree_t<allocator_t>;

    public:
        string::dynamic_t<charcoder_t, allocator_t> expression;
        general_flags_e                             general_flags;
        syntax_tree_t                               syntax_tree;

    public:
        // should be the charcoder's unit_t probably.
        regex_t(tr2<any_tg, c_pointer_ttg, of_any_tg, char> auto expression);

        // should accept a dynamic string_t as well

        // maybe we should only accept a static string_t?
        // probably the simplest thing is to just store a dynamic string through the provided allocator.
        // we'll have to use the allocator quite a bit to create a regex_t anyway, pretty sure.

        // also, this should be able to work with any string_t, not just strings using its own charcoder
    };

}
