#pragma once

#include "mathf.h"
#include "vec3.h"
#include "mtx3x3.h"
#include "line.h"
#include "light.h"

/*
                 *******donut*******

                  ,,ggddY""""Ybbgg,,
             ,agd""'              `""bg,
          ,gdP"                       "Ybg,
        ,dP"                             "Yb,
      ,dP"         _,,ddP"|"Ybb,,_         "Yb,
     ,8"         ,dP"'    |    `"Yb,         "8,
    ,8'        ,d"        |<-R     "b,        `8,
   ,8'        d"          |          "b        `8,
   d'        d'        ,gP|Rg,        `b        `b
   8         8        dP' | `Yb        8         8
   8         8        8)  |  (8        8         8
   8         8        Yb     dP        8         8
   8         Y,        "8ggg8"        ,P         8
   Y,         Ya             \       aP         ,P
   `8,         "Ya         r->\    aP"         ,8'
    `8,          "Yb,_         \,dP"          ,8'
     `8a           `""YbbgggddP"\'           a8'
      `Yba                       \         adP'
        "Yba                   r->\      adY"
          `"Yba,                   \ ,adP"'
             `"Y8ba,             ,ad8P"'
                  ``""YYbaaadPP""''
*/

struct donut
{
private:
	vec3 translation;
    mtx3x3 rotation, rotationInverse;
    double weight; // the length squared of the tangent from the torus' center to the torus itself

public:
	vec3 pos;
	double R, r;
	donut();
	donut(double _R, double _r);
    void applyTranslation(vec3 &dpos);
    void applyTranslation(double dx, double dy, double dz);
	void applyRotation(double angleXY, double angleYZ, double angleZX);
    bool IntersectsWith(line &ln, vec3& norm);
	void Draw(light& l);
};

