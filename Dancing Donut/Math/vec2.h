#pragma once

#include"types_shortened.h"

struct vec2
{
private:
    vec v;

public:
    vec2();
    vec2(vec vtr);
    vec2(double x, double y, double z);
    vec2(double d);
    double& operator [](int i);
    vec2& operator +(vec2& vec);
    vec2& operator -(vec2& vec);
    vec2& operator +=(vec2& vec);
    vec2& operator -=(vec2& vec);
    vec2& operator *(double c);
    double operator *(vec2& vec);
    vec2& operator *=(double c);
    vec2& operator -();
    static const int len = 2;
};

