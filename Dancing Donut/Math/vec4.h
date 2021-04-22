#pragma once

#include"types_shortened.h"

struct vec4
{
private:
    vec v;

public:
    vec4();
    vec4(vec vtr);
    vec4(double x, double y, double z);
    vec4(int count, double d);
    double& operator [](int i);
    vec4& operator +(vec4& vec);
    vec4& operator -(vec4& vec);
    vec4& operator +=(vec4& vec);
    vec4& operator -=(vec4& vec);
    vec4& operator *(double c);
    double operator *(vec4& vec);
    vec4& operator *=(double c);
    vec4& operator -();
    static const int len = 4;
};

