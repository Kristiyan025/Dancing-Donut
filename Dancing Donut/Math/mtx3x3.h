#pragma once

#include "types_shortened.h"
#include "vec3.h"

struct mtx3x3
{
private:
    mtx m;

public:
    mtx3x3();
    mtx3x3(mtx& mat);
    mtx3x3(mtx mat);
    static const int len = 3;
    inline vec& operator [](int i);
    inline double& operator ()(int i, int j);
    mtx3x3& operator *(double c);
    vec3& operator *(vec3& v);
    mtx3x3& operator *(mtx3x3& mat);
    mtx3x3& operator /(double c);
    mtx3x3& operator *=(double c);
    mtx3x3& operator /=(double c);
    static mtx3x3& IdentityMatrix();
    static mtx3x3& scale(double dx = 0.0, double dy = 0.0, double dz = 0.0);
    static mtx3x3& rotateXY(double angle = 0.0);
    static mtx3x3& rotateYZ(double angle = 0.0);
    static mtx3x3& rotateZX(double angle = 0.0);
    static mtx3x3& rotate(double angleXY = 0.0, double angleYZ = 0.0, double angleZX = 0.0);
    inline double determinant();
    mtx3x3& adjugate();
    mtx3x3& inverse();
};

