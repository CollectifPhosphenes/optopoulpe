#pragma once
#include "vec3.h"
#include "fixed_point.h"

// From https://iquilezles.org/www/articles/palettes/palettes.htm

template <typename T>
struct ColorPalette {

  vec3<T> eval(T t) const { return a + b * cos((c * t + d) * static_cast<T>(6.28f)); }

  operator vec3<T>*() { return (vec3<T>*)this; }

  vec3<T> a;
  vec3<T> b;
  vec3<T> c;
  vec3<T> d;
};

static const ColorPalette<float> palette_rainbow = {
    {0.5f, 0.5f, 0.5f},
    {0.5f, 0.5f, 0.5f},
    {1.f, 1.f, 1.f},
    {0.f, 0.33f, 0.67f}};

static const ColorPalette<float> palette_deep = {
    {0.5f, 0.5f, 0.5f},
    {0.5f, 0.5f, 0.5f},
    {2.f, 1.f, 0.f},
    {0.5f, 0.2f, 0.25f}};

static const ColorPalette<float> palette_coper = {
    {0.8f, 0.5f, 0.4f},
    {0.2f, 0.4f, 0.2f},
    {2.f, 1.f, 1.f},
    {0.f, 0.25f, 0.25f}};

static const ColorPalette<float> palette_yellow_blue = {
    {0.5f, 0.5f, 0.5f},
    {0.5f, 0.5f, 0.5f},
    {1.f, 1.f, 0.5f},
    {0.8f, 0.9f, 0.3f}};

static const ColorPalette<float> palette_red_blue = {
    {2.000000f, 0.170000f, 1.890000f},
    {2.000000f, 0.476000f, 1.515000f},
    {1.000000f, 1.000000f, 2.000000f},
    {0.957000f, 0.857000f, 0.935000f}};

static const ColorPalette<float> palette_test = {
    {0.000000f, 1.318000f, 0.035000f},
    {0.952000f, 1.734000f, 1.740000f},
    {1.000000f, 1.000000f, 2.000000f},
    {1.343000f, 1.594000f, 0.935000f}};

static const ColorPalette<float> palette_test2 = {
    {0.500000f, 0.500000f, 0.500000f},
    {0.500000f, 0.500000f, 0.500000f},
    {1.000000f, 1.000000f, 1.000000f},
    {0.000000f, 0.330000f, 1.410000f}};

static const ColorPalette<float> palette_test3 = {
    {0.500000f, 0.500000f, 0.500000f},
    {0.546000f, 0.301000f, 0.155000f},
    {1.000000f, 1.000000f, 1.000000f},
    {0.000000f, 1.063000f, 1.410000f}};

static const ColorPalette<float> palette_test4 = {
    {0.500000f, 0.500000f, 0.500000f},
    {0.546000f, 0.301000f, 0.155000f},
    {1.000000f, 1.000000f, 1.000000f},
    {0.000000f, 0.642000f, 1.410000f}};

static const ColorPalette<float> palette_test5 = {
    {1.794000f, 0.125000f, 0.000000f},
    {1.820000f, 0.216000f, 0.835000f},
    {1.000000f, 1.000000f, 1.000000f},
    {0.952000f, 0.642000f, 1.410000f}};

static const ColorPalette<float> palette_test6 = {
    {1.794000f, 0.125000f, 2.000000f},
    {1.820000f, 0.216000f, 2.000000f},
    {1.000000f, 1.000000f, 1.000000f},
    {0.952000f, 0.642000f, 1.410000f}};
