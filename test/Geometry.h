#pragma once
#include "SDL.h"
#define PI 3.14159265
double get_angle(int x1, int y1, int x2, int y2);//���� ������������ ����������� (����������� ��� y1>y2) ������ ����
double get_length(int x1, int y1, int x2, int y2);//����� �����(������������...)
bool includeRect(SDL_Rect small, SDL_Rect big);
bool includePoint(SDL_Point p, SDL_Rect rect);