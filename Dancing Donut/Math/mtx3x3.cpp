#include "mtx3x3.h"

#include<cmath>
#include "mathf.h"

mtx3x3::mtx3x3()
{
    m = mtx(len, vec(len, 0.0));
    for (int i = 0; i < mtx3x3::len; i++)
    {
        m[i][i] = 1.0;
    }
}

mtx3x3::mtx3x3(mtx& mat)
{
    m = mat;
}

mtx3x3::mtx3x3(mtx mat)
{
    m = mat;
    /*if(mat.size())
    for (int i = 0; i < mtx3x3::len; i++)
    {
        m[i] = mat[i];
    }*/
}

inline vec& mtx3x3::operator [](int i)
{
    return (vec&)m[i];
}

inline double& mtx3x3::operator ()(int i, int j)
{
    return (double&)m[i][j];
}

mtx3x3& mtx3x3::operator *(double c)
{
    mtx3x3* mat = new mtx3x3();
    for (int i = 0; i < mtx3x3::len; i++)
    {
        for (int j = 0; j < mtx3x3::len; j++)
        {
            (*mat)[i][j] *= c;
        }
    }

    return *mat;
}

vec3& mtx3x3::operator *(vec3& v)
{
    vec3* newV = new vec3();
    for (int i = 0; i < mtx3x3::len; i++)
    {
        (*newV)[i] = vec3(m[i]) * v;
    }

    return *newV;
}

mtx3x3& mtx3x3::operator *(mtx3x3& mat)
{
    mtx3x3* newMtx = new mtx3x3();
    for (int i = 0; i < mtx3x3::len; i++)
    {
        for (int j = 0; j < mtx3x3::len; j++)
        {
            double& cell = (*newMtx)[i][j];
            cell = 0.0;
            for (int k = 0; k < mtx3x3::len; k++)
            {
                cell += m[i][k] * mat[k][j];
            }
        }
    }

    return *newMtx;
}

mtx3x3& mtx3x3::operator /(double c)
{
    mtx3x3* mat = new mtx3x3();
    for (int i = 0; i < mtx3x3::len; i++)
    {
        for (int j = 0; j < mtx3x3::len; j++)
        {
            (*mat)[i][j] = m[i][j] / c;
        }
    }

    return *mat;
}

mtx3x3& mtx3x3::operator *=(double c)
{
    for (int i = 0; i < mtx3x3::len; i++)
    {
        for (int j = 0; j < mtx3x3::len; j++)
        {
            m[i][j] *= c;
        }
    }

    return *this;
}

mtx3x3& mtx3x3::operator /=(double c)
{
    for (int i = 0; i < mtx3x3::len; i++)
    {
        for (int j = 0; j < mtx3x3::len; j++)
        {
            m[i][j] /= c;
        }
    }

    return *this;
}

mtx3x3& mtx3x3::IdentityMatrix()
{
    mtx3x3* newMtx = new mtx3x3();
    for (int i = 0; i < mtx3x3::len; i++)
    {
        (*newMtx)[i][i] = 1.0;
    }

    return *newMtx;
}

mtx3x3& mtx3x3::scale(double dx, double dy, double dz)
{
    mtx3x3* newMtx = &mtx3x3::IdentityMatrix();
    (*newMtx)[0][0] *= dx;
    (*newMtx)[1][1] *= dy;
    (*newMtx)[2][2] *= dz;
    return *newMtx;
}

mtx3x3& mtx3x3::rotateXY(double angle)
{
    double s = sin(angle);
    double c = cos(angle);
    if (s > -precision && s < precision) s = 0.0;
    if (c > -precision && c < precision) c = 0.0;
    mtx3x3* mat = new mtx3x3(
        {
           {   c,  -s, 0.0 },
           {   s,   c, 0.0 },
           { 0.0, 0.0, 1.0 }
        });
    return *mat;
}

mtx3x3& mtx3x3::rotateYZ(double angle)
{
    double s = sin(angle);
    double c = cos(angle);
    if (s > -precision && s < precision) s = 0.0;
    if (c > -precision && c < precision) c = 0.0;
    mtx3x3* mat = new mtx3x3(
        {
           { 1.0, 0.0, 0.0, },
           { 0.0,   c,  -s, },
           { 0.0,   s,   c, }
        });
    return *mat;
}

mtx3x3& mtx3x3::rotateZX(double angle)
{
    double s = sin(angle);
    double c = cos(angle);
    if (s > -precision && s < precision) s = 0.0;
    if (c > -precision && c < precision) c = 0.0;
    mtx3x3* mat = new mtx3x3(
        {
           {   c, 0.0,   s, },
           { 0.0, 1.0, 0.0, },
           {  -s, 0.0,   c, }
        });
    return *mat;
}

mtx3x3& mtx3x3::rotate(double angleXY, double angleYZ, double angleZX)
{
    mtx3x3* mat = &(rotateXY(angleXY) * (rotateYZ(angleYZ) * rotateZX(angleZX)));
    return *mat;
}

inline double mtx3x3::determinant()
{
    /*
    *        Matrix 3x3
    * m[0][0] m[0][1] m[0][2]
    * m[1][0] m[1][1] m[1][2]
    * m[2][0] m[2][1] m[2][2]
    */
    return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
         - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
         + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
}

mtx3x3& mtx3x3::adjugate()
{
    /*
    *        Matrix 3x3
    * m[0][0] m[0][1] m[0][2]
    * m[1][0] m[1][1] m[1][2]
    * m[2][0] m[2][1] m[2][2]
    */
    mtx3x3 * mat = new mtx3x3(/*
        {
           {  
               (m[1][1] * m[2][2] - m[1][2] * m[2][1]), // w/o m[0][0]
              -(m[0][1] * m[2][2] - m[0][2] * m[2][1]), // w/o m[1][0]
               (m[0][1] * m[1][2] - m[0][2] * m[1][1]), // w/o m[2][0]
           },
           { 
              -(m[1][0] * m[2][2] - m[1][2] * m[2][0]), // w/o m[0][1]
               (m[0][0] * m[2][2] - m[0][2] * m[2][0]), // w/o m[1][1]
              -(m[0][0] * m[1][2] - m[0][2] * m[1][0]), // w/o m[2][1]
           },
           {  
               (m[1][0] * m[2][1] - m[1][1] * m[2][0]), // w/o m[0][2] 
              -(m[0][0] * m[2][1] - m[0][1] * m[2][0]), // w/o m[1][2]
               (m[0][0] * m[1][1] - m[0][1] * m[1][0]), // w/o m[2][2]
           },
        }*/);
    for (int i = 0; i < mtx3x3::len; i++)
    {
        for (int j = 0; j < mtx3x3::len; j++)
        {
            (*mat)[i][j] = ((*this)[(j + 1) % 3][(i + 1) % 3] * (*this)[(j + 2) % 3][(i + 2) % 3]) - ((*this)[(j + 1) % 3][(i + 2) % 3] * (*this)[(j + 2) % 3][(i + 1) % 3]);
        }
    }
    return *mat;
}

mtx3x3& mtx3x3::inverse()
{
    double det = this->determinant();
    if (det < precision) throw "Zero determinant!";
    return this->adjugate() / det;
}