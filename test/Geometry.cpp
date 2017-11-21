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

bool includePoint(SDL_Point p, SDL_Rect rect)
{
	return (p.x > rect.x)&&(p.y > rect.y)&&(p.x < rect.x + rect.w)&&(p.y < rect.y + rect.h);
}

bool includeRect(SDL_Rect small, SDL_Rect big)
{
	SDL_Point p1,p2;
	p1.x = small.x;
	p1.y = small.y;
	p2.x = small.x + small.w;
	p2.y = small.y + small.h;
	return (includePoint(p1, big)) && (includePoint(p2, big));
}