# Overview {#mainpage}

This library is in the early stages of development, but what better time to start end-user documentation? Currently the most useful things about the library are the nkr::atomic_t and the nkr::pointer_t. These two types have fairly thorough tests in the sister project nkr_test ensuring their functionality, and I'm thinking about making a separate set of documentation for that as well.

More to come as I implement more features! For now I'm going to document the types that are pretty solid.

# Designs

## Class Concept Specializations {#_16d56f49_95ba_456e_a026_706c054cb133}

Because we are using the C++20 concepts feature, which is not fully implemented in all compilers, we do have to work around a couple of bugs that currently exist in two of the big compilers to varying degrees. In order to use out-of-body class definitions, we use a pattern of concept specialization that have the specializations inherit all of their members from a different class, including methods, ctors, dtor, and assignment operators. This effectively makes the specialization the same class as the base. We put these in a name space one step interior to the namespace where the type lives, and it's named after the type with an additional "$" prefixing it. We also put no members in the default class and only use the specializations. This is to avoid yet another bug that currently exists in one of the big compilers:

```cpp
namespace nkr { namespace $class_t {

    template <integer_tr integer_p>
    class integer_sp
    {
        // has any member you want
    }

    template <pointer_tr pointer_p>
    class pointer_sp
    {
        // has any member you want
    }

}}

namespace nkr {

    template <typename invalid_p>
    class class_t
    {
        // has no members, and we usually delete all ctors and dtor explicitly
    }

    template <integer_tr integer_p>
    class class_t<integer_p> :
        public $class_t::integer_sp
    {
    public:
        using $class_t::integer_sp<integer_p>::integer_sp;
        using $class_t::integer_sp<integer_p>::operator =;
    }

    template <pointer_tr pointer_p>
    class class_t<pointer_p> :
        public $class_t::pointer_sp
    {
    public:
        using $class_t::pointer_sp<pointer_p>::pointer_sp;
        using $class_t::pointer_sp<pointer_p>::operator =;
    }

}
```

[Read about this on stackoverflow.](https://stackoverflow.com/questions/68589314/how-to-define-a-specialized-class-method-outside-of-class-body-in-c)
