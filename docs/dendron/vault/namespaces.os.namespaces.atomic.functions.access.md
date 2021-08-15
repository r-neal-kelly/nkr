---
id: 7EKPGsYEZRgZ5nVIkVnIl
title: Access
desc: ''
updated: 1628991931833
created: 1628991725649
---

## Declaration
```cpp
    template <integral_tr atom_p>
    inline atom_p   Access(const volatile atom_p& atom);
    template <pointer_tr atom_p>
    inline atom_p   Access(const volatile atom_p& atom);
```

## Description
Atomically returns the value of `atom` without changing its value.
