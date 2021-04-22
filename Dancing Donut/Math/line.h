#pragma once

#include "vec3.h"
#include "mtx3x3.h"

struct line
{
	vec3 pt1, pt2;
	line(vec3& pt);
	line(vec3& _pt1, vec3& _pt2);
	line(line& l);
	line& translate(vec3& translation);
	line& rotate(mtx3x3& rotation);
};

