#pragma once

#include "types_shortened.h"
#include "vec4.h"

struct vec3
{
public:
    vec v;
    vec3();
    vec3(vec vtr);
    vec3(vec4 vtr);
    vec3(double x, double y, double z);
    vec3(double d);
    static const int len = 3;
    double& operator [](int i);
    double& operator ()(int i);
    vec3& operator +(vec3& vec);
    vec3& operator -(vec3& vec);
    vec3& operator -();
    vec3& operator *(double c);
    vec3& operator /(double c);
    double operator *(vec3& vec);
    vec3& operator +=(vec3& vec);
    vec3& operator -=(vec3& vec);
    vec3& operator *=(double c);
    vec3& operator /=(double c);
    inline double& X() { return v[0]; }
    inline double& Y() { return v[1]; }
    inline double& Z() { return v[2]; }
    double magnSq(); //Magnitude Squared
    double magn(); //Magnitude
    vec3& norm(); //Normalized Vector
};

