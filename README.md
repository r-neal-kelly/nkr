# nkr
A static 64 and 32 bit C++20 library providing powerfully generic types, versatile traits and interfaces, and a set of comprehensive test suites. Currently for Windows, with future plans to expand to Linux.

### Rationale
After wrapping up development on mods and libraries for [Skyrim](https://www.nexusmods.com/skyrimspecialedition/users/myaccount?tab=files), I began looking for a project to improve my skills, learn something new, and amplify my portfolio. In conjunction with my previous experience modding the Skyrim game engine, I eventually settled on developing a modern C++20 library with some very deliberate goals:
- **a long-lasting system of general-use types outshining the standard C++ library.** From a string type that supports ASCII, Unicode, and any user-extended character encoding, unto a regex engine that takes advantage of that versatile string and provides look-behinds that are just as fast as look-aheads.
- **very extensive use of C++20 concepts.** Having spent quite a bit of time in C++11, it became evident early on that concepts were going to be a great addition to the language and a persistent staple of the library. It's desirable to have a rich hierarchy of abstract concepts including traits and interfaces that simplify and beautify constraints. All the while improving correctness of code and facilitating end-user handling of our types.
- **a smart and thorough set of test suites.** I finally came to the hypothesis that good software is a by-product of good testing, and this library is partially an attempt to prove it. That may be an obvious conclusion for some, but it took a while for it to dawn on me because I had to face a system that I built myself which was sufficiently complex enough to show how impossible it becomes at scale to keep up without a good test suite. So for this project I decided up front to do my best to create test code that has as much attention paid to it as the library itself, and it should be as long lasting too. I look forward to running this code 10+ years from now and saying "yup, still passing all tests."
- **the employment of continuous integration.** There comes a point when it is dangerous to assume we can simply update a program with an entirely new version that's made on the side. It appears to be far better to make slower and more steady updates that either do not at all effect the consuming code, or at most effect it in a calculatedly small and acceptable way, thus splitting up the total cost of changing consumer code into multiple smaller payments that can be made in installments over time. I've been on the other side of a community wide break where the cost was so high to update our programs that many, even some very important developers in the community left for the indefinite future. It's complicated by the fact that having multiple versions of the consumed program not only adds a potentially large cost for a consumer to update to, but an additional charge if they wish to support the older version for the sake of their split user base that does not want or can not update because some other consumer's work they use simply cannot afford to be updated. Such users cannot be blamed, for it is often the case that the most costly programs to update are also lower level, and thus affect a wider number of other programs that simply cannot or will not be updated without them. Essentially I think it boils down to this, it's better to have one source of truth, and changes in that truth should be given to consumers in a bite sized fashion such that they can comfortably eat it.
- **great end-user documentation.** By taking advantage of Doxygen we should be able to generate an easily accessible website that takes advantage of code in the test suite to provide up-to-date examples of how to use the library, as well as abstract discussions on how everything works together. It should cover semantics as well as syntax that is particular to this library, and as much as possible, just like with our test suites, it should last and be quite thorough. This is again inspired by previous experience. It comes from the fact that I had to delve into and comprehend rather large libraries of code ranging into the hundreds of thousands of lines, all without a single piece of noteworthy documentation from their creators and hardly anything else from anyone else. That's unacceptable for growth. I know there are a bunch of otherwise capable developers who would turn away from that because it's so much work on the front end of the experience. It's taken a while for me too to come around as prefer making the code speak for itself as much as possible, but I'm becoming more and more of the opinion that a maybe unexpected component required to make great software is great documentation. And it's only recently that I'm beginning to ponder how it might be the case that the most important part of that documentation is not at all the dictionary to the library, which covers individual types and functions, but rather the standard grammar book and example sentences, in other words, an explanation of the syntax and semantics of the code, and example programs both small and large.

Currently with only one developer, the library is seeing an iterative update pattern, where it is intended that no one goal should be significantly advanced beyond another. However, it does take quite a bit of time to iterate! So we do see gaps here and there, especially in the documentation. There are plans to fill everything in when it becomes most appropriate, e.g. currently it does not make too much sense for one man to write a bunch of documentation for a system that will likely become outdated faster than the time it takes to properly document it. Once things stabilize, it will of course become a higher priority.

I'm in this for the long-haul and so I prefer for this project to go slowly and get it right than to go so quickly that we get it very wrong. The major compilers' implementations of C++20 are seemingly practicing this same methodology. However, this should not hold us back from pushing our code to the forefront of the language. It's very open to experimentation, and is a great place to learn and to even play with new ideas. Eventually, when they are sufficiently ready for use, modules will be the home of most of our code because consumers will see a huge decrease in compile times with this template heavy library.

Overall, it's intended to be a great learning experience and a library that I can come back to and be happy with far into the future.

[Go to documentation](https://r-neal-kelly.github.io/nkr_docs)

### Building
This library currently has no other code requirements, and is thus extremely straightforward to build on Windows, currently the only supported platform. However, you will need a Visual Studio 2022 instance to build unless you are willing to go through the trouble of backporting all of the library's project files. To build the tests, you may batch build all of the solution's projects, and use the simple PowerShell script in the tools folder to automatically execute all of the test suites, or simply build individual projects. Please keep in mind that until the library stabilizes, there may be breaking changes to consumer's code because it is still in the pre-alpha phase and has not yet had an official release. The first official release will probably occur once we have the regex engine designed, implemented, tested, and documented.

### Status
I'm currently moving all the existent types to a new traits system and I'm taking this opportunity to update each type to address issues the original design may have had. For example, the enumeration types now accept more than just signed integers and have reasonable defaults set up for each kind of integer. All of the old files have the prefix 'z_' to indicate that they are the old implementation. Doing this kind of major overhaul allows us to sync everything to a new and improved traits system. That means removal of any of the very old-style macro trait definitions which turned out to lead to slow compilation times and hence the need for the second iteration of the traits system. We are now on our third and so far, it's looking like a real keeper!
