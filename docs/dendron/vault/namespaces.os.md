---
id: rhrrH0bkCOyRjkGrK65Ie
title: os
desc: ''
updated: 1628994484615
created: 1628991725670
stub: false
---

The purpose of this namespace is to wrap all operating system functionality and data behind a rarely changing interface. The goal is to be able to work every platform into this mold behind the scenes, usually involving preprocessor switches.

The philosophy of `nkr` is to wrap every alien piece of code possible, with the exception of standard `C` and `C++` libraries that are in use.

The `nkr_test` suite is currently a little more lenient towards foreign code, but the library proper is to be treated with the utmost sanctity.

![[namespaces.os.namespaces]]
