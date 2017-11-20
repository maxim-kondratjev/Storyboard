#include "Geometry.h"
#include <cmath>

double get_angle(int x1, int y1, int x2, int y2)
{
	double dx = x2 - x1;
	double dy = y2 - y1;
	return atan(dy / dx) * 180 / PI;
}

double get_length(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}