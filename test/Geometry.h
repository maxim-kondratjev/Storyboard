#pragma once
#include "SDL.h"
#define PI 3.14159265
double get_angle(int x1, int y1, int x2, int y2);//угол относительно горизонтали (отрицателен при y1>y2) должен быть
double get_length(int x1, int y1, int x2, int y2);//длина линии(отрицательна...)
bool includeRect(SDL_Rect small, SDL_Rect big);
bool includePoint(SDL_Point p, SDL_Rect rect);