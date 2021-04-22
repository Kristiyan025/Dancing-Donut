#include "light.h"

light::light()
{
	dir = ((vec3&)vec3(0.0, 0.0, -3.0) - (vec3&)vec3(-5.0, -6.0, 0.0)).norm();
}

light::light(vec3& _dir)
{
	dir = _dir.norm();
}