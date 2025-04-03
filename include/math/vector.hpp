#pragma once

struct vec2
{
    float x, y;
    vec2() : x(0.f), y(0.f) {}
    vec2(float s) : x(s), y(s) {}
    vec2(float _x, float _y) : x(_x), y(_y) {}
};

struct vec3
{
    float x, y, z;
    vec3() : x(0.f), y(0.f), z(0.f) {}
    vec3(float s) : x(s), y(s), z(s) {}
    vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};