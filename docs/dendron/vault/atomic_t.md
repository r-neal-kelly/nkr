---
id: Ozr6six1T1XAbFlMzQ8jo
title: atomic_t
desc: ''
updated: 1628979396408
created: 1628962973944
---

A template wrapper for platform-dependent atomic objects, including booleans, integers, and pointers. Each specialization can be treated as the underlying type itself in almost every circumstance. And unlike `std::atomic`, `nkr::atomic_t` is strictly reserved for objects that are truly atomic in nature on each platform, without exception. *(Windows x64 and x86 are currently the only implemented platforms.)*

## Specializations

- [[integer_p|atomic_t.specialization.integer_p]]
- [[bool_t|atomic_t.specialization.bool_t]]
- [[value_p*|atomic_t.specialization.value_p_pointer]]
- [[void_t*|atomic_t.specialization.void_t_pointer]]
