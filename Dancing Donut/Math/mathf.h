#pragma once

#include "types_shortened.h"

const double precision = 1e-10;

inline void swap(int a, int b)
{
	a ^= b ^= a ^= b;
}

inline double sq(double num) 
{ 
	return num * num;
}

inline double map(double val, double fromDown, double fromUp, double toDown, double toUp)
{
	return (val - fromDown) * (toUp - toDown) / (fromUp - fromDown) + toDown;
}

namespace mathf
{
	inline double absF(double& num)
	{
		return num > 0.0 ? num : -num;
	}

	//Calculates polinomial value at certain x
	inline double f(double x, vec& poly_coeff)
	{
		double res = 0.0;
		double xs = 1.0;
		for (int i = 0; i < poly_coeff.size(); i++)
		{
			res += poly_coeff[i] * xs;
			xs *= x;
		}
		return res;
	}

	inline bool findSmallestPositiveRoot(vec& poly_coeff, double& root)
	{
		const double upperBound = 50.0;
		const double step = 0.1;
		double firstX = 0.0, firstVal = f(firstX, poly_coeff),
			secondX = -1.0, secondVal = -1.0;

		for (double x = step; x < upperBound; x += step)
		{
			double val = f(x, poly_coeff);
			if (val == 0.0)
			{
				root = x;
				return true;
			}
			else if (val * firstVal > 0)
			{
				firstX = x;
				firstVal = val;
			}
			else
			{
				secondX = x;
				secondVal = val;
				while (secondX - firstX > precision)
				{
					double midX = (firstX + secondX) / 2;
					double midVal = f(midX, poly_coeff);
					if (midVal == 0.0)
					{
						root = midX;
						return true;
					}
					if (midVal * firstVal > 0)
					{
						firstX = midX;
						firstVal = midVal;
					}
					else
					{
						secondX = midX;
						secondVal = midVal;
					}
				}

				root = firstX;
				return true;
			}
		}

		return false;
	}
}