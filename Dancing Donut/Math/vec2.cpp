#include "vec2.h"

vec2::vec2() 
{
    v = vec(vec2::len, 0.0);
}

vec2::vec2(vec vtr)
{
    if (vtr.size() == vec2::len)
    {
        v = vtr;
    }
}

vec2::vec2(double x, double y, double z) : vec2()
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

vec2::vec2(double d) : vec2()
{
    for (int i = 0; i < vec2::len; i++)
    {
        v[i] = d;
    }
}

double& vec2::operator [](int i)
{
    return v[i];
}

vec2& vec2::operator +(vec2& vec)
{
    vec2* newV = new vec2();
    for (int i = 0; i < vec2::len; i++)
    {
        (*newV)[i] = v[i] + vec[i];
    }
    return *newV;
}

vec2& vec2::operator -(vec2& vec)
{
    vec2* newV = new vec2();
    for (int i = 0; i < vec2::len; i++)
    {
        (*newV)[i] = v[i] - vec[i];
    }
    return *newV;
}

vec2& vec2::operator +=(vec2& vec)
{
    for (int i = 0; i < vec2::len; i++)
    {
        v[i] += vec[i];
    }
    return *this;
}

vec2& vec2::operator -=(vec2& vec)
{
    for (int i = 0; i < vec2::len; i++)
    {
        v[i] -= vec[i];
    }
    return *this;
}

vec2& vec2::operator *(double c)
{
    vec2* newV = new vec2();
    for (int i = 0; i < vec2::len; i++)
    {
        (*newV)[i] = c * v[i];
    }
    return *newV;
}

double vec2::operator *(vec2& vec)
{
    double dotProd = 0.0;
    for (int i = 0; i < vec2::len; i++)
    {
        dotProd += v[i] * vec[i];
    }
    return dotProd;
}

vec2& vec2::operator *=(double c)
{
    for (int i = 0; i < vec2::len; i++)
    {
        v[i] *= c;
    }
    return *this;
}

vec2& vec2::operator -()
{
    vec2* newV = new vec2();
    for (int i = 0; i < vec2::len - 1; i++)
    {
        (*newV)[i] = -v[i];
    }
    return *newV;
}