# nkr
A static 64 and 32 bit C++20 library providing powerfully generic types, versatile traits and interfaces, and a set of comprehensive test suites. Currently for Windows, with future plans to expand to Linux.

### Features (both finished and planned)
- **a long-lasting system of general-use types that are built upon each other**
  - such as dynamic and static arrays that can store their elements locally or remotely
  - and strings that extend the arrays and natively support Unicode as well as ASCII. They can be extended by user-defined character encodings.
  - Even a regex engine that matches the versatility of the strings and provides look-behinds that are just as fast as look-aheads.
  - and much more!
- **extensive use of C++20 concepts.** 
  - a rich hierarchy of concepts abstracted into well-defined and delineated 'traits' and 'interfaces' that abstractly simplify and beautify constraints
  - traits act as nouns by providing abstraction over types and their templates
  - interfaces act as verbs in generic operations and drastically cut down on the need for users to specialize types either too difficult or too redundant to reimplement.
  - all of the above come together in an expressive, dynamic, and compile-time filtering language which cuts down on the need for one-time-use concepts. It covers frequently used operations, such as identification by trait, functionality by interface, comparison of the primary inner type of a template, and whether a type can be cast into another.
  - the operators used in the filter are grammatically close to English and can express any qualification or combination thereof, helping to consistently cut down on the need for frequent overload definitions in the most versatile of types. Its shorthand reusability makes for a cleaner and easier to read API.

### Why? (alternatively, Why Not Use the Standard Library)?
Hindsight is always 20/20 and we have the opportunity to reflect and improve on the decades old standard C++ library:
- **by making types more useful and well-rounded**
  - atomics have all operators natively defined and ready to use, strings natively handle Unicode and are easily extended, arrays can be made locally on the stack or in the read section and handle very much like their heap-dynamic counterparts, enums are now full classes and you can define and add functionality to them like any other class, uniform distributions actually return negative real numbers and work with pointers, etc.
- **by providing data-oriented types**
  - the footprint of almost every type is 'protected'. This prevents accidentally changing internal state, yet allows the relatively easy option to inherit the type to become actively involved with its internals. If you need to squeeze out some extra performance, you can do that and still implicitly be able to interact with the rest of the library at large.
- **by fully supporting volatile**
  - when you need it, you need it. almost every type in the library fully supports volatile constructors, assigners, and methods. Even the larger types can be confidently used and combined when and where desired. (This is not to be confused with atomic operations, which are also provided by the library.)
- **by constexpr, constexpr, constexpr**
  - we have the opportunity to define almost all library types as constexpr, making them easily useable during compile-time and run-time. You now have to option of when you want your provided functionality executed, and they are ready for composition!
- **by lack of exceptions (or alternatively, by making asserts your friend)**
  - The stance of this library is that exceptions run counter-intuitive to the performance and flow of your program and lend themselves to overuse. Most types in the library cannot even produce an error because they are constexpr. But those than can, produce only those errors which cannot be handled during debug-time. So we intentionally use the sparse error-code to indicate such failures usually revolving around a shared resource such as the heap or a file-handle. The generic error type provided by the library is essentially an enum and is the singular strategy to both communicate and enforce the handling of errors. A debug build will assert during runtime if an error is left unchecked and thus puts a spotlight on code that has not handled the error. (For construction of objects, it is expected that the programmer will detect that the type is valid before using it, else the program will assert if you try to use it.)

### Goals
- **a smart and thorough set of test suites**
- **great end-user documentation**

[Go to the (still in the works) documentation](https://r-neal-kelly.github.io/nkr_docs)

### Building
This library currently has no other code requirements, and is thus extremely straightforward to build on Windows, currently the only supported platform. However, you will need a Visual Studio 2022 instance to build unless you are willing to go through the trouble of backporting all of the library's project files. To build the tests, you may batch build all of the solution's projects, and use the simple PowerShell script in the tools folder to automatically execute all of the test suites, or simply build individual projects. Please keep in mind that until the library stabilizes, there may be breaking changes to consumer's code because it is still in the pre-alpha phase and has not yet had an official release. The first official release will probably occur once we have the regex engine designed, implemented, tested, and documented.

### Status
I'm currently moving all the existent types to a new traits system and I'm taking this opportunity to update each type to address issues the original design may have had. For example, the enumeration types now accept more than just signed integers and have reasonable defaults set up for each kind of integer. All of the old files have the prefix 'z_' to indicate that they are the old implementation. Doing this kind of major overhaul allows us to sync everything to a new and improved traits system. That means removal of any of the very old-style macro trait definitions which turned out to lead to slow compilation times and hence the need for the second iteration of the traits system. We are now on our third and so far, it's looking like a real keeper!
