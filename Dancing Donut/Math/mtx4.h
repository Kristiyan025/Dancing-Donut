#pragma once

#include"types_shortened.h"
#include"vec4.h"

class mtx4
{
private:
    mtx m;

public:
    mtx4();
    mtx4(mtx& mat);
    mtx4(mtx mat);
    static const int len = 4;
    inline vec& operator [](int i);
    inline double& operator ()(int i, int j);
    inline mtx4& operator *(double c);
    inline vec4& operator *(vec4& v);
    inline mtx4& operator *(mtx4& mat);
    static inline mtx4& IdentityMatrix();
    static inline mtx4& scale(double dx = 0.0, double dy = 0.0, double dz = 0.0);
    static inline mtx4& translate(double dx = 0.0, double dy = 0.0, double dz = 0.0);
    static inline mtx4& rotateXY(double angle = 0.0);
    static inline mtx4& rotateYZ(double angle = 0.0);
    static inline mtx4& rotateZX(double angle = 0.0);
    static inline mtx4& rotate(double angleXY = 0.0, double angleYZ = 0.0, double angleZX = 0.0);
    static inline mtx4& transform(double dx = 0.0, double dy = 0.0, double dz = 0.0,
        double angleXY = 0.0, double angleYZ = 0.0, double angleZX = 0.0);
};

