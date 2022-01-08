# nkr
A 64 and 32 bit C++20 library providing powerfully generic types, versatile traits and interfaces, and a set of comprehensive test suites. Currently for Windows, with future plans to expand to Linux.

### Rationale
After wrapping up development on mods and libraries for [Skyrim](https://www.nexusmods.com/skyrimspecialedition/users/myaccount?tab=files), I began looking for a project to improve my skills, learn something new, and amplify my portfolio. After following up on a couple of suggestions online and in conjunction with my previous experience working on the Skyrim game engine, I eventually settled on developing a modern C++20 library with some very deliberate goals:
- **a long-lasting system of general-use types outshining the standard C++ library.** From a string type that natively supports Unicode as well as ASCII which can be easily extended to work with any character encoding, unto a regex engine that takes advantage of that versatile string and has look-behinds that are just as fast as look-aheads.
- **very extensive use of C++20 concepts.** Having come from being stuck in C++11, it became evident early on that inevitably, concepts are a an excellent addition to the language. It's desirable to have a rich hierarchy of abstract concepts including traits and interfaces that simplify and beautify constraints which improve correctness of code and end-user handling of our facilities.
- **a smart and thorough set of test suites.** Test code should have as much attention paid to it as the library itself, and it should be as long lasting too. I look forward to running this code 10+ years from now and saying "yup, still passes all tests."
- **the employment of continuous integration.** The library should be able to compile and pass all tests at any particular time, and we should avoid making separate git branches when possible. There should be only one source of truth.
- **and great end-user documentation.** By taking advantage of doxygen we should be able to generate an easily accessible website that takes advantage of code in the test suite to provide up-to-date examples of how to use the library, as well as abstract discussions on how everything works together.

Currently with only one developer, the library is seeing an iterative update pattern, where it is intended that no one goal should be sufficiently advanced beyond another. However, it does take quite a bit of time to iterate! So we do see gaps here and there, but there are plans to fill them in when it becomes most appropriate.
    
I'm in this for the long-haul and so I prefer for this project to go slowly and get it right than to go so quickly that we get it very terribly wrong. Because it's written in C++20, this code should be as much as possible on the forefront of the language proper. It's very open to experimentation, and is a great place to learn and to even play with new ideas. Eventually I the library will be moved into modules, but that will have to wait for the next major iteration.
    
Overall, it's intended to be a great learning experience and a library that I can come back to and be happy to use far into the future.

[Go to documentation](https://r-neal-kelly.github.io/nkr_docs)

### Building
This library currently has no other code requirements, and is thus extremely straightforward to build for Windows, currently the only supported platform. However, you will need a Visual Studio 2022 instance to build unless you are willing to go through the trouble of backporting all of the project files. After batch building the test suites through the solution file, one may use the simple PowerShell script in the tools folder to automatically execute them all of them.

### Status
I'm currently moving all the existent types to a new traits system and I'm taking this opportunity to update each type to address issues the original design may have had. For example, the enumeration types now accept more than just signed integers and have reasonable defaults set up for each kind of integer. All of the old files have the prefix 'z_' to indicate that they are the old implementation. Doing this kind of major overhaul allows us to sync everything to a new and improved traits system, that means removal of any of the very old-style macro trait definitions which turned out to lead to slow compilation times and hence the need for the second iteration of the traits system. We are now on our third and so far, it's looking like a real keeper!
