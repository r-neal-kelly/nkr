# nkr
A static 64 and 32 bit C++20 library providing powerfully generic types, versatile traits and interfaces, and a set of comprehensive test suites. Currently for Windows, with future plans to expand to Linux.

### Why Use nkr?
Hindsight is always 20/20. The stalwart standard C++ library is an impressive feat that's taken decades to create. But in that time many design choices were made that negatively impact its usability to this day. We have the opportunity to reflect and make changes to that design by providing:
- **well-rounded and easy to use types**
  - strings natively handle Unicode and are easily extended
  - arrays can store their elements locally on the stack or in the read section, all using an API consistent with their heap-centric counterparts
  - enums are full classes and you can define and add functionality to them like any other class
  - atomics have all expected operators natively defined and ready to use
  - we supply "none", "maybe", and "some" types in addition to an "optional" in order to prevent misuse of null. These give you the flexibility to manage your memory footprint how you want to, and in an explicit way
  - and more! Even specific things such as uniform distributions which can return negative real numbers and that work with pointers, booleans, and your user-defined types
- **constexpr, constexpr, and more constexpr**
  - We have the opportunity to define almost all library types as constexpr, making them easily usable during compile-time.
  - You have the option to refactor library types between compile-time and run-time contexts with ease.
  - They are ready for composition in your own types, even types that are designed for dynamic and volatile use when desired.
  - Relying on constexpr brings the benefit of standards-required undefined behavior checks during compile-time, even when they are only used dynamically.
- **data-oriented facilities**
  - The footprint of almost every type is 'protected', allowing you to easily inherit the type and become actively involved with its internals.
  - Yet by default, you are still prevented from making accidental changes to its internal state.
  - You can squeeze out extra performance for a particular feature and still selectively interact with the rest of the library at large using the inherited type.
  - arrays and other containers are explicitly local or remote, static or dynamic, bringing an ever present reminder of how your data is stored
- **full volatile support**
  - When you need it, you need it, and every type where possible in the library is fully supported.
  - That means volatile constructors, assigners, methods, casts, operators, and more.
  - Larger types can be confidently made by composing smaller types and you will still be able to use them in a volatile manner.
  - (Not to be confused with atomic operations, which are provided by the library through other means.)
- **lack of exceptions and helpful asserts**
  - Exceptions are often counter-intuitive to the performance and flow of your program and very much lend themselves to overuse.
  - So most types in the library are designed so that they cannot even produce an error, because they are constexpr.
  - But those than can, produce only those errors which should not be asserted during debug-time, like resource allocation.
  - Only a sparse number of error enums are used to indicate dynamic failures, making them easier to remember and to work with.
  - The generic error enum provided by the library both communicates and enforces the handling of errors in debug builds, by asserting during runtime if an error is left unchecked or when it is not moved to another context.
  - Where a type that can have an error during construction exists, validity checks are provided for post-construction use. The program will assert when you try to use an invalid instance other than to check its validity.
- **intuitively composed types**
  - for example, we provide dynamic and static template arrays that can store their elements locally or remotely, facilitating data-oriented design choices and changes.
  - each of those arrays are used to make the provided strings that natively support Unicode as well as ASCII, and which can be easily extended to handle user-defined encodings.
  - these same strings are then used to operate and to be operated upon by the regex engine. This gives the engine all the versatility of the underlying arrays and strings, thus breaking down both performance and encoding barriers.
- **extensive use of C++20 concepts** 
  - a rich hierarchy of concepts abstracted into well-defined and delineated 'traits' and 'interfaces' that abstractly simplify and beautify constraints
  - traits act as nouns by providing abstraction over types and their templates
  - interfaces act as verbs in generic operations and drastically cut down on the need for users to specialize types either too difficult or too redundant to reimplement.
  - all of the above come together in an expressive, dynamic, and compile-time filtering language which cuts down on the need for one-time-use concepts. It covers frequently used operations, such as identification by trait, functionality by interface, comparison of the primary inner type of a template, and whether a type can be cast into another.
  - the operators used in the filter are grammatically close to English and can express any qualification or combination thereof, helping to consistently cut down on the need for frequent overload definitions in the most versatile of types. Its shorthand reusability makes for a cleaner and easier to read API.

### Goals
- **a smart and thorough set of test suites**
  - 100% coverage is the goal
  - this library better a.) compile and b.) pass all tests in 10 years, or I will consider it a failure on this point.
- **great end-user documentation**
  - Coverage of the general 'feel' for the library and how the traits and interfaces work together with all the types.
  - With the help of Doxygen, 100% coverage by use of test cases in the test suites for every entity intended to be used by the consumer.

[Go to the (still in the works) documentation](https://r-neal-kelly.github.io/nkr_docs)

### Building
This library currently has no other code requirements, and is thus extremely straightforward to build on Windows, currently the only supported platform. However, you will need a Visual Studio 2022 instance to build unless you are willing to go through the trouble of backporting all of the library's project files. To build the tests, you may batch build all of the solution's projects, and use the simple PowerShell script in the tools folder to automatically execute all of the test suites, or simply build individual projects. Please keep in mind that until the library stabilizes, there may be breaking changes to consumer's code because it is still in the pre-alpha phase and has not yet had an official release. The first official release will probably occur once we have the regex engine designed, implemented, tested, and documented.

### Status
I'm currently moving all the existent types to a new traits system and I'm taking this opportunity to update each type to address issues the original design may have had. For example, the enumeration types now accept more than just signed integers and have reasonable defaults set up for each kind of integer. All of the old files have the prefix 'z_' to indicate that they are the old implementation. Doing this kind of major overhaul allows us to sync everything to a new and improved traits system. That means removal of any of the very old-style macro trait definitions which turned out to lead to slow compilation times and hence the need for the second iteration of the traits system. We are now on our third and so far, it's looking like a real keeper!
