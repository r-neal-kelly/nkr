---
id: Ozr6six1T1XAbFlMzQ8jo
title: atomic_t
desc: ''
updated: 1628994171753
created: 1628962973944
---

A template wrapper for platform-dependent atomic objects, including booleans, integers, and pointers. Each specialization can be treated as the underlying type itself in almost every circumstance. And unlike `std::atomic`, `nkr::atomic_t` is strictly reserved for objects that are truly atomic in nature on each platform, without exception. *(Windows x64 and x86 are currently the only implemented platforms.)*

![[types.atomic_t.specializations]]
