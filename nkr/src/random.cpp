/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/random.h"

namespace nkr {

    std::random_device  random_device;
    std::mt19937_64     random_generator(random_device());
    std::mutex          random_lock;

}
