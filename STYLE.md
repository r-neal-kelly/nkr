# Style Guidelines
This is a work in progress as it's incomplete and some guidelines may change over time with the expectation that the code-base will need to be updated in order to remain consistent.



### Naming
__________

Snake case is used for all names and uppercase characters are currently to be avoided. Names are intended to follow natural grammars such that they are more easily discerned when trying to understand any particular piece of code. Thus short names, especially single character names, are usually unacceptable (with a major exception). Descriptive names are the key to understanding the code, however postfix notation is sometimes employed to indicate differences between types of objects.

- Namespaces have no postfix. They are exceptional because this is the only label where short names are encouraged although not required:

```cpp
    namespace nkr {



    }
```

- Variables have no postfix:

```cpp
    namespace nkr {

        count_t my_variable;

    }
```

- Concrete and template classes (types) have the "_t" postfix. They should be named after nouns:

```cpp
    namespace nkr {

        class my_class_t
        {
        };

        template <typename = void_t>
        class my_template_t
        {
        };
    }
```

- Unions have the "_u" postfix. They should be named after nouns to indicate the commonality between types:

```cpp
    namespace nkr {

        union my_number_u
        {
            u8_t    u8;
            u16_t   u16;
            u32_t   u32;
            u64_t   u64;
        };

    }
```

- Template type parameters have no postfix and are effectively meta variables:

```cpp
    namespace nkr {

        template <typename my_template_parameter>
        class my_template_t
        {
        };

    }
```

- Traits (concepts refining template parameters) have the "_tr" postfix and are effectively meta types. They should be named after adjectives:

```cpp
    namespace nkr {

        template <typename type>
        concept my_describable_tr = true;

    }

    namespace nkr {

        template <my_describable_tr template_parameter>
        class my_template_t
        {
        };

    }
```

- Types publically aliased in another type's scope, especially in templates, have the "_t" postfix just like regular types:

```cpp
    namespace nkr {

        template <my_describable_tr template_parameter>
        class my_template_t
        {
        public:
            using template_parameter_t  = template_parameter;
        };

    }
```

- Interfaces, whether C++20 concepts defined by requires-expressions, abstract virtual classes, structs of function pointers, or anything else that genuinely qualifies as an interface all have the "_i" postfix:

```cpp
    namespace nkr {

        template <typename type>
        concept my_concept_i = requires(type value)
        {
            { value.my_method() } -> std::same_as<void_t>;
        };

        class my_virtual_i
        {
        public:
            virtual         ~my_virtual_i() = default;
            virtual void_t  my_method()     = 0;
        };

        struct my_struct_i
        {
        public:
            void_t  (*my_method)();
        };

    }
```


### Namespaces
______________

- Namespaces should always have a space after their opening brace and before their closing brace, and at least a third line, either of code or space:

```cpp
    namespace nkr {

        // either a space or something else has to be here.

    }

    namespace nkr {

            

    }
```

- Nested namespaces must be on one line, and so namespaces should end up only having one indentation. When working with multiple namespaces, each namespace should have its own block:

```cpp
    namespace nkr { namespace a {



    }}

    namespace nkr { namespace a { namespace b {



    }}}
```



### Glossary
____________

#### **_i**:
> *interface*

#### **_t**:
> *type*

#### **_tr**:
> *trait*

#### **_u**:
> *union*
