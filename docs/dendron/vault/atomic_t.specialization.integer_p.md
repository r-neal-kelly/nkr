---
id: JrHaS8tsuvHUZaSSndWH1
title: integer_p
desc: ''
updated: 1628981192336
created: 1628978307524
---

This is the default specialization of [[atomic_t]]. Depending on the platform, most signed and unsigned integers are available, and at a bare minimum the `word_t` should be available.

## Aliases

- `value_t` is `integer_p`

## Static Asserts

- `value_t` must satisfy `std::is_integral`

## Constructors

It is important to note that none of the constructors are atomic. This means that they must be initialized in a thread-safe manner.

- default
- `value_t`
- copy
- move
- copy assignment
- move assignment

## Destructor

Atomically sets its value to 0.

## Methods

- [[Access]]
- [[Assign]]
- [[Exchange]]
- [[Exchange_If_Equals]]


- [[Access_Add]]
- [[Assign_Add]]
- [[Exchange_Add]]


- [[Access_Subtract]]
- [[Assign_Subtract]]
- [[Exchange_Subtract]]


- [[Access_Or]]
- [[Assign_Or]]
- [[Exchange_Or]]


- [[Access_And]]
- [[Assign_And]]
- [[Exchange_And]]


- [[Access_Xor]]
- [[Assign_Xor]]
- [[Exchange_Xor]]

## Casts

- [[value_t]]

## Operators

- [[Invoke]]


- [[Assign]]


- [[Add]]
- [[Subtract]]
- [[Add_Assign]]
- [[Subtract_Assign]]
- [[Increment_Pre]]
- [[Increment_Post]]
- [[Decrement_Pre]]
- [[Decrement_Post]]


- [[Bitwise_Not]]
- [[Bitwise_Or]]
- [[Bitwise_And]]
- [[Bitwise_Xor]]
- [[Bitwise_Or_Assign]]
- [[Bitwise_And_Assign]]
- [[Bitwise_Xor_Assign]]
