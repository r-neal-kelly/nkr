/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include <mutex>
#include <random>

#include "nkr/intrinsics.h"

#include "doctest.h"

namespace nkr {

    // we'll eventually move this stuff to the library, within a class or something
    extern std::random_device   random_device;
    extern std::mt19937_64      random_generator;
    extern std::mutex           random_lock;

}
