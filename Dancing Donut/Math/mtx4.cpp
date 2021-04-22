#include "mtx4.h"

mtx4::mtx4()
{
    m = mtx(len, vec(len, 0.0));
    m[mtx4::len - 1][mtx4::len - 1] = 1.0;
}

mtx4::mtx4(mtx& mat)
{
    m = mat;
}

mtx4::mtx4(mtx mat)
{
    for (int i = 0; i < mtx4::len; i++)
    {
        m[i] = mat[i];
    }
}

inline vec& mtx4::operator [](int i)
{
    return (vec&)m[i];
}

inline double& mtx4::operator ()(int i, int j)
{
    return (double&)m[i][j];
}

inline mtx4& mtx4::operator *(double c)
{
    for (int i = 0; i < mtx4::len; i++)
    {
        for (int j = 0; j < mtx4::len; j++)
        {
            m[i][j] *= c;
        }
    }

    return *this;
}

inline vec4& mtx4::operator *(vec4& v)
{
    vec4* newV = new vec4();
    for (int i = 0; i < mtx4::len; i++)
    {
        (*newV)[i] = vec4(m[i]) * v;
    }

    return *newV;
}

inline mtx4& mtx4::operator *(mtx4& mat)
{
    mtx4* newMtx = new mtx4();
    for (int i = 0; i < mtx4::len; i++)
    {
        for (int j = 0; j < mtx4::len; j++)
        {
            double& cell = (*newMtx)(i, j);
            cell = 0.0;
            for (int k = 0; k < mtx4::len; k++)
            {
                cell += m[i][k] * mat(k, j);
            }
        }
    }

    return *newMtx;
}

inline mtx4& mtx4::IdentityMatrix()
{
    mtx4* newMtx = new mtx4();
    for (int i = 0; i < mtx4::len; i++)
    {
        (*newMtx)[i][i] = 1.0;
    }

    return *newMtx;
}

inline mtx4& mtx4::scale(double dx, double dy, double dz)
{
    mtx4* newMtx = &mtx4::IdentityMatrix();
    (*newMtx)[0][0] *= dx;
    (*newMtx)[1][1] *= dy;
    (*newMtx)[2][2] *= dz;
    return *newMtx;
}

inline mtx4& mtx4::translate(double dx, double dy, double dz)
{
    mtx4* newMtx = &mtx4::IdentityMatrix();
    (*newMtx)[0][mtx4::len - 1] *= dx;
    (*newMtx)[1][mtx4::len - 1] *= dy;
    (*newMtx)[2][mtx4::len - 1] *= dz;
    return *newMtx;
}

inline mtx4& mtx4::rotateXY(double angle)
{
    double s = sin(angle);
    double c = cos(angle);
    mtx4* mat = new mtx4(
        {
           {   c,  -s, 0.0, 0.0 },
           {   s,   c, 0.0, 0.0 },
           { 0.0, 0.0, 0.0, 0.0 },
           { 0.0, 0.0, 0.0, 1.0 }
        });
    return *mat;
}

inline mtx4& mtx4::rotateYZ(double angle)
{
    double s = sin(angle);
    double c = cos(angle);
    mtx4* mat = new mtx4(
        {
           { 0.0, 0.0, 0.0, 0.0 },
           { 0.0,   c,  -s, 0.0 },
           { 0.0,   s,   c, 0.0 },
           { 0.0, 0.0, 0.0, 1.0 }
        });
    return *mat;
}

inline mtx4& mtx4::rotateZX(double angle)
{
    double s = sin(angle);
    double c = cos(angle);
    mtx4* mat = new mtx4(
        {
           {   c, 0.0,   s, 0.0 },
           { 0.0, 0.0, 0.0, 0.0 },
           {  -s, 0.0,   c, 0.0 },
           { 0.0, 0.0, 0.0, 1.0 }
        });
    return *mat;
}

inline mtx4& mtx4::rotate(double angleXY, double angleYZ, double angleZX)
{
    mtx4* mat = &(rotateZX(angleZX) * (rotateYZ(angleYZ) * rotateXY(angleXY)));
    return *mat;
}

inline mtx4& mtx4::transform(double dx, double dy, double dz, double angleXY, double angleYZ, double angleZX)
{
    mtx4* mat = &(translate(dx, dy, dz) * rotate(angleXY, angleYZ, angleZX));
    return *mat;
}