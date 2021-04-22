#include "vec4.h"

vec4::vec4()
{
    v = vec(vec4::len, 0.0);
    v[vec4::len - 1] = 1.0;
}

vec4::vec4(vec vtr) : vec4()
{
    if (vtr.size() == vec4::len)
    {
        v = vtr;
    }
}

vec4::vec4(double x, double y, double z) : vec4()
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

vec4::vec4(int count, double d) : vec4()
{
    for (int i = 0; i < count; i++)
    {
        v[i] = d;
    }
}

double& vec4::operator [](int i)
{
    return v[i];
}

vec4& vec4::operator +(vec4& vec)
{
    vec4* newV = new vec4();
    for (int i = 0; i < vec4::len - 1; i++)
    {
        (*newV)[i] = v[i] + vec[i];
    }
    return *newV;
}

vec4& vec4::operator -(vec4& vec)
{
    vec4* newV = new vec4();
    for (int i = 0; i < vec4::len - 1; i++)
    {
        (*newV)[i] = v[i] - vec[i];
    }
    return *newV;
}

vec4& vec4::operator +=(vec4& vec)
{
    for (int i = 0; i < vec4::len - 1; i++)
    {
        v[i] += vec[i];
    }
    return *this;
}

vec4& vec4::operator -=(vec4& vec)
{
    for (int i = 0; i < vec4::len - 1; i++)
    {
        v[i] -= vec[i];
    }
    return *this;
}

vec4& vec4::operator *(double c)
{
    vec4* newV = new vec4();
    for (int i = 0; i < vec4::len - 1; i++)
    {
        (*newV)[i] = c * v[i];
    }
    return *newV;
}

double vec4::operator *(vec4& vec)
{
    double dotProd = 0.0;
    for (int i = 0; i < vec4::len; i++)
    {
        dotProd += v[i] * vec[i];
    }
    return dotProd;
}

vec4& vec4::operator *=(double c)
{
    for (int i = 0; i < vec4::len - 1; i++)
    {
        v[i] *= c;
    }
    return *this;
}

vec4& vec4::operator -()
{
    vec4* newV = new vec4();
    for (int i = 0; i < vec4::len - 1; i++)
    {
        (*newV)[i] = -v[i];
    }
    return *newV;
}