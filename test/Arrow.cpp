#include "Arrow.h"
#include "SDL.h"
#include "Geometry.h"
#include <iostream>

Arrow::Arrow(SDL_Renderer* mainRender, SDL_Texture* arrowHead, int posX, int posY, int width, int height)
	:DNDButton(mainRender, arrowHead, posX, posY, width, height)
{
}

void Arrow::Draw()//из за того что стрелка занимает площадь нормально ее поставить не выходит сотни расчетов итд короче хз проще нарисовать треугольник на конце
{
	if (_texture == NULL)
	{
		std::cout << "No texture surface!\n";
		return;
	}
	SDL_Point a, centerPos;
	a.x = 0;
	a.y = 0;
	//SDL_Point a(src->getPos());
	
	
	centerPos.x = Pos.x + Pos.w / 2;
	centerPos.y = Pos.y+Pos.h/2;
	double angle1 = get_angle(a.x, a.y, centerPos.x, centerPos.y);

	SDL_SetRenderDrawColor(_mainRenderer, 0x00, 0x00, 0x00, 255);
	SDL_RenderDrawLine(_mainRenderer,a.x, a.y, centerPos.x, centerPos.y);
	

	//рисую треугольник заебало
	const int L = 10;
	const double anglearrow = 45;

	double angle = (anglearrow - angle1)/180*PI;;
	std::cout << angle << std:: endl;
	

	SDL_RenderDrawLine(_mainRenderer, centerPos.x, centerPos.y, centerPos.x-L*sin(angle), centerPos.y-L*cos(angle));
	std::cout << sin(angle) << std::endl;
	SDL_RenderDrawLine(_mainRenderer, centerPos.x, centerPos.y, centerPos.x - L*cos(angle), centerPos.y + L*sin(angle));
}
