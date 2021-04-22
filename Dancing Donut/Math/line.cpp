#include "line.h"

line::line(vec3& pt)
{
	this->pt1 = vec3();
	this->pt2 = pt;
}

line::line(vec3& _pt1, vec3& _pt2)
{
	line::pt1 = _pt1;
	line::pt2 = _pt2;
}

line::line(line& l)
{
	this->pt1 = l.pt1;
	this->pt2 = l.pt2;
}

line& line::translate(vec3& translation)
{
	line* l = new line(*this);
	l->pt1 += translation;
	l->pt2 += translation;
	return *l;	
}

line& line::rotate(mtx3x3& rotation)
{
	line* l = new line(*this);
	l->pt1 = rotation * l->pt1;
	l->pt2 = rotation * l->pt2;
	return *l;
}