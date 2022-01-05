# nkr
This is my new C++20 library. I'm excited to use concepts finally! This is aiming to be cross-platform although currently there is only development for Windows.

[Go to documentation](https://r-neal-kelly.github.io/nkr_docs)

### Building
This library currently has no other code requirements, and is thus extremely straightforward to build for Windows, currently the only supported platform. However, you will need a Visual Studio 2022 instance to build unless you are willing to go through the trouble of backporting all of the project files.

### Status
I'm currently moving all the existent types to a new traits system and I'm taking this opportunity to update each type to address issues the original design may have had. For example, the enumeration types now accept more than just signed integers and have reasonable defaults set up for each kind of integer. All of the old files have the prefix 'z_' to indicate that they are the old implementation. Doing this kind of major overhaul allows us to sync everything to a new and improved traits system, that means removal of any of the very old-style macro trait definitions which turned out to lead to slow compilation times and hence the need for the second iteration of the traits system. We are now on our third and so far, it's looking like a real keeper!
