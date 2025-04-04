#pragma once

#include <math/vector.hpp>

struct mat4
{
    float values[16];

    static mat4 identity()
    {
        return mat4
        {
            1.f, 0.f, 0.f, 0.f,
            0.f, 1.f, 0.f, 0.f,
            0.f, 0.f, 1.f, 0.f,
            0.f, 0.f, 0.f, 1.f
        };
    }
};