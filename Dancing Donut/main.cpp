//include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<cmath>

#include "Console/console.h"
#include "Math/vec3.h"
#include "Math/mtx3x3.h"
#include "Math/line.h"
#include "Math/light.h";
#include "Math/donut.h"




int main()
{
    std::ios_base::sync_with_stdio(false);
    Console::setConsole();
 /*   mtx3x3 t = mtx3x3(
        {
            {3, 0, 2},
            {2, 0, -2},
            {0, 1, 1},
        });
    for (int i = 0; i < mtx3x3::len; i++)
    {
        for (int j = 0; j < mtx3x3::len; j++)
        {
            std::cout << t[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << t.determinant() << std::endl;
    t = t.inverse();
    for (int i = 0; i < mtx3x3::len; i++)
    {
        for (int j = 0; j < mtx3x3::len; j++)
        {
            std::cout << t[i][j] << " ";
        }
        std::cout << std::endl;
    }*/
    //double r;
    //vec coeff = { 19.98, -9.33, 1.0 };
    //findSmallestPositiveRoot(coeff, r);
    //std::cout << r << std::endl;
    light l = light();
    donut d = donut();
    //vec3 norm;
    //line& p = (line&)line((vec3&)vec3(0.0, 0.0, -1.0));
    //std::cout << d.IntersectsWith(p, norm) << std::endl;
    //std::cout << norm[0] << " " << norm[1] << " " << norm[2] << std::endl;
    d.applyRotation(0, acos(0.0), 0.0);
    while (true)
    {
        d.applyRotation(0.1, 0.1, 0.1);
        d.Draw(l);
        //system("get-console-screenshot");
        //return 0;
    }
    //Console::writeAt(3, 3, "Hello world");
    //system("cls")
}

