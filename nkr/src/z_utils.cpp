/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/z_utils.h"

namespace nkr {

    std::random_device  random_device;
    std::mt19937_64     random_generator(random_device());
    std::mutex          random_lock;

}
