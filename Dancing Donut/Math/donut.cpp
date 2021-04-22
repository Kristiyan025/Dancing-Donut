#include "donut.h"

#include<iostream>
#include "../Console/console.h"

const double initialDistance = -10.0;
const double narrowingX = 0.025,
			 narrowingY = 2 * narrowingX;
const double f = 1.0; //focus

donut::donut()
{
	this->translation = vec3();
	this->rotation = mtx3x3();
	this->rotationInverse = mtx3x3();
	this->pos = vec3(0, 0, initialDistance);
	this->R = 5.0;
	this->r = 2.0;
	this->weight = sq(this->R) + sq(this->r);
}

donut::donut(double _R, double _r)
{
	this->translation = vec3();
	this->rotation = mtx3x3();
	this->rotationInverse = mtx3x3();
	this->pos = vec3(0, 0, initialDistance);
	this->R = _R;
	this->r = _r;
	this->weight = sq(this->R) + sq(this->r);
}

void donut::applyTranslation(vec3 &dpos)
{
	this->pos += dpos;
}

void donut::applyTranslation(double dx, double dy, double dz)
{
	vec3 dpos = vec3(dx, dy, dz);
	this->pos += dpos;
}

void donut::applyRotation(double angleXY, double angleYZ, double angleZX)
{
	this->rotation = mtx3x3::rotateZX(angleZX) * mtx3x3::rotateYZ(angleYZ) * mtx3x3::rotateXY(angleXY) * this->rotation;//mtx3x3::rotateYZ(angleYZ) * this->rotation;
	this->rotationInverse = mtx3x3::rotateXY(-angleXY) * mtx3x3::rotateYZ(-angleYZ) * mtx3x3::rotateZX(-angleZX) * this->rotationInverse;
	/*for (int i = 0; i < mtx3x3::len; i++)
	{
		for (int j = 0; j < mtx3x3::len; j++)
		{
			std::cout << rotation[i][j] << " ";
		}
		std::cout << std::endl;
	}*/
}

bool donut::IntersectsWith(line &ln, vec3 &norm)
{
	/*
	* Reverse the hole scen, so tha the torus in default position (origin)
	* That is accomplished by rotating and translatingevrithing else (the line) in the
	* exact opposite way the toruse is positioned
	*/
	line& l = ln
		.translate(-this->pos)
		.rotate(this->rotationInverse);
	//std::cout << "ln" << l.pt1[0] << " " << l.pt1[1] << " " << l.pt1[2] << std::endl;
	//std::cout << "ln" << l.pt2[0] << " " << l.pt2[1] << " " << l.pt2[2] << std::endl;

	vec3& o = l.pt1;
	double oXo = o.magnSq();
	vec3& d = (l.pt2 - l.pt1).norm();
	double oXd = o * d; // the dot product of o and d 
	/*
	* So if the they do intersect, then the point will be in the form: o + d * t, 
	* where t is a real parameter which defines the intersection. Thus, it will be a root of:
	* c4 * x ^ 4 + c3 * x ^ 3 + c2 * x ^ 2 + c1 * x + c0 = 0
	*/
	vec coefficients =
	{
		sq(oXo - this->weight) - 4 * sq(this->R) * (sq(this->r) - sq(o.Y())),
		4 * (oXo - this->weight) * oXd + 8 * sq(this->R) * o.Y() * d.Y(),
		2 * (oXo - this->weight) + 4 * sq(oXd) + 4 * sq(this->R * d.Y()),
		4 * oXd,
		1, // == d.magnSq() ^ 2, but d is a unit vector, thus |d| = 1
	};
	//for (int i = 4; i >= 0; i--)
	//{
	//	std::cout << coefficients[i] << " ";
	//}
	//std::cout << std::endl;
	double root;
	bool hasFoundRoot = mathf::findSmallestPositiveRoot(coefficients, root);

	if (hasFoundRoot)
	{
		//std::cout << 1 << std::endl;
		//std::cout << root << " ";
		vec3 pt = o + d * root;
		vec3 temp = vec3(pt);
		temp[1] = 0.0;
		norm = (pt - (temp.norm() * this->R));
		norm = (rotation * norm).norm();
	}

	return hasFoundRoot;
}

void donut::Draw(light& l)
{
	int halfWidth = Console::bufferWidth / 2,
		halfHeight = Console::bufferHeight / 2;
	std::string image = "";
	for (int j = -halfHeight; j < halfHeight; j++)
	{
		for (int i = -halfWidth; i < halfWidth; i++)
		{
			vec3 norm;
			bool doesIntersect = this->IntersectsWith((line&)line((vec3&)vec3(i * narrowingX, j * narrowingY, -f)), norm);
			if (doesIntersect)
			{
				//row += '1';
				image += shades[map(norm * -l.dir, -1.0, 1.0, 0, shades.length())];//];
			}
			else
			{
				image += ' ';
			}
		}
		if (j != halfHeight - 1) image += '\n';
	}
	system("cls");
	std::cout << image;
}