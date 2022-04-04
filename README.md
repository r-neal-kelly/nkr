[blank]: blank

# nkr
A static C++20 library providing powerfully generic types, versatile traits and interfaces, and a formal meta-programming language to dynamically define C++20 concepts in-place with arbitrary constraints and arbitrary precision. Comes with a robust and comprehensive set of test suites to ensure correctness and performance, as well as an all-encompassing set of documentation to guarantee understanding and usability. Currently available for 64 bit and 32 bit Windows and Linux machines.

## Why Use nkr?
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
- **helpful asserts replacing exceptions**
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

## Goals
- **a smart and thorough set of test suites**
  - 100% coverage is the goal
  - this library better a.) compile and b.) pass all tests in 10 years, or I will consider it a failure on this point.
- **great end-user documentation**
  - Coverage of the general 'feel' for the library and how the traits and interfaces work together with all the types.
  - With the help of Doxygen, 100% coverage by use of test cases in the test suites for every entity intended to be used by the consumer.

[Go to the (still in the works) documentation](https://r-neal-kelly.github.io/nkr_docs)

## Building
Please keep in mind that until the library stabilizes, there may be breaking changes if you use nkr in your code. It is still in the alpha phase and has not yet had an official release. The first official release will occur once we have the regex engine designed, implemented, tested, and documented.

The provided build script `build.ps1` is capable of updating, generating, compiling, and executing the library and its test suites. It's really only necessary for test-suites or if you wish to alter the library. Ohterwise as a static library, nkr is as simple as including headers into your code, with no extra dependencies.

### Requirements for Test-Suites
- Compatible C++20 compiler (e.g. Visual Studio 2022 for Windows, GCC 11.2 for Linux)
- CMake (https://cmake.org/)
- Node.js + NPM (https://nodejs.org/en/. Installer comes with NPM, Linux will need to install explicitly.)
- PowerShell (Preinstalled on Windows and also available for install on Linux.)

### Steps for Test-Suites (Windows)
1. Open the start button, search for `PowerShell` and set the nkr repository as the current working directory.
2. Execute `./build.ps1 --help` to bring up the help info.
3. Execute `./build.ps1 -arch 64 -mode Debug -make` to generate and compile the library's few .cpp files. It's a good way to test that everything is working on your system properly.
4. Execute `./build.ps1 -arch 64 -mode Debug -test -make -exec` to generate, compile, and execute all of the library's test suites.

### Steps for Test-Suites (Linux)
1. Open a terminal and set the nkr repository as the current working directory.
2. Execute `pwsh ./build.ps1 --help` to bring up the help info.
3. Execute `pwsh ./build.ps1 -arch 64 -mode Debug -make` to generate and compile the library's few .cpp files. It's a good way to test that everything is working on your system properly.
4. Execute `pwsh ./build.ps1 -arch 64 -mode Debug -test -make -exec` to generate, compile, and execute all of the library's test suites.

## Status
Adding types from the second iteration into the final form of the library.
