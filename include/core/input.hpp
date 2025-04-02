#pragma once

#include <utils/logger.hpp>

static bool keys[512];

class input
{
public:
    static bool is_pressed(int key) { return keys[key]; }
    static void set_key(int key, bool state) { keys[key] = state; }
};
