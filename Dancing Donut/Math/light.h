#pragma once

#include<string>

#include "vec3.h"

const std::string shades = ".,-~^:;=!*#$@";//"$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

struct light
{
	vec3 dir;
	light();
	light(vec3& _dir);
};

