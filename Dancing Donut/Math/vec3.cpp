#include "vec3.h"

#include<cmath>

vec3::vec3() 
{
    v = vec(vec3::len, 0.0);
}

vec3::vec3(vec vtr)
{
    if(vtr.size() == vec3::len)
    {
        v = vtr;
    }
}

vec3::vec3(vec4 vtr) : vec3()
{
    v[0] = vtr[0];
    v[1] = vtr[1];
    v[2] = vtr[2];
}

vec3::vec3(double x, double y, double z) : vec3()
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

vec3::vec3(double d) : vec3()
{
    for (int i = 0; i < vec3::len; i++)
    {
        v[i] = d;
    }
}

double& vec3::operator [](int i)
{
    return v[i];
}

double& vec3::operator ()(int i)
{
    return v[i];
}

vec3& vec3::operator +(vec3& vec)
{
    vec3* newV = new vec3();
    for (int i = 0; i < vec3::len; i++)
    {
        (*newV)[i] = v[i] + vec[i];
    }
    return *newV;
}

vec3& vec3::operator -(vec3& vec)
{
    vec3* newV = new vec3();
    for (int i = 0; i < vec3::len; i++)
    {
        (*newV)[i] = v[i] - vec[i];
    }
    return *newV;
}

vec3& vec3::operator -()
{
    vec3* newV = new vec3();
    for (int i = 0; i < vec3::len; i++)
    {
        (*newV)[i] = -v[i];
    }
    return *newV;
}

vec3& vec3::operator *(double c)
{
    vec3* newV = new vec3();
    for (int i = 0; i < vec3::len; i++)
    {
        (*newV)[i] = c * v[i];
    }
    return *newV;
}

vec3& operator *(const double c, const vec3 &rhs)
{
    vec3* newV = new vec3();
    for (int i = 0; i < vec3::len; i++)
    {
        (*newV)[i] = c * rhs.v[i];
    }
    return *newV;
}

vec3& vec3::operator /(double c)
{
    vec3* newV = new vec3();
    for (int i = 0; i < vec3::len; i++)
    {
        (*newV)[i] = v[i] / c;
    }
    return *newV;
}

double vec3::operator *(vec3& vec)
{
    double dotProd = 0.0;
    for (int i = 0; i < vec3::len; i++)
    {
        dotProd += v[i] * vec[i];
    }
    return dotProd;
}

vec3& vec3::operator +=(vec3& vec)
{
    for (int i = 0; i < vec3::len; i++)
    {
        v[i] += vec[i];
    }
    return *this;
}

vec3& vec3::operator -=(vec3& vec)
{
    for (int i = 0; i < vec3::len; i++)
    {
        v[i] -= vec[i];
    }
    return *this;
}

vec3& vec3::operator *=(double c)
{
    for (int i = 0; i < vec3::len; i++)
    {
        v[i] *= c;
    }
    return *this;
}

vec3& vec3::operator /=(double c)
{
    for (int i = 0; i < vec3::len; i++)
    {
        v[i] /= c;
    }
    return *this;
}

double vec3::magnSq() //Magnitude Squared
{
    return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
}

double vec3::magn() //Magnitude
{
    return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

vec3& vec3::norm() //Normalized Vector
{
    vec3* newV = new vec3();
    double magn = this->magn();
    for (int i = 0; i < vec3::len; i++)
    {
        (*newV)[i] = v[i] / magn;
    }
    return *newV;
}