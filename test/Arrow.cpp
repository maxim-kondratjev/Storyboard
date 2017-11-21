#include "mainWindow.h"
#include "Geometry.h"
#include <iostream>

extern Window mainWindow;

Arrow::Arrow(SDL_Renderer* mainRender, SDL_Texture* arrowHead, 
	int posX, int posY, int width, int height, UIObject* src, bool isLinked)
	:DNDButton(mainRender, arrowHead, posX, posY, width, height)
{
	this->src = src;
	this->isLinked = false;
	this->dst = NULL;
}

void Arrow::Draw()//из за того что стрелка занимает площадь нормально ее поставить не выходит сотни расчетов итд короче хз проще нарисовать треугольник на конце
{
	if (_texture == NULL)
	{
		std::cout << "No texture surface!\n";
		return;
	}
	double angle1;
	SDL_Point centerPos;
	centerPos.x = Pos.x + Pos.w / 2;
	centerPos.y = Pos.y + Pos.h / 2;
	if (isLinked)//нужен метод чтобы прятать линию за объекты (или способ отрисовки)
	{
		SDL_Rect one, two;
		//one = src->getRect();
		one.x = 400;
		one.y = 400;
		two = dst->getRect();
		SDL_SetRenderDrawColor(_mainRenderer, 0x00, 0xFF, 0x00, 255);
		SDL_RenderDrawLine(_mainRenderer, one.x, one.y, two.x, two.y);
		angle1 = get_angle(one.x, one.y, two.x, two.y);
		centerPos.x = two.x;
		centerPos.y = two.y;
		Pos.x = two.x - Pos.w;
		Pos.y = two.y - Pos.h;
	}
	else
	{
		angle1 = get_angle(offX, offY, centerPos.x, centerPos.y);

		SDL_SetRenderDrawColor(_mainRenderer, 0x00, 0x00, 0x00, 255);
		SDL_RenderDrawLine(_mainRenderer, offX, offY, centerPos.x, centerPos.y);
	}

	//рисую треугольник заебало
	const int L = 10;
	const double anglearrow = 45;

	double angle = (anglearrow - angle1)/180*PI;;
	//std::cout << angle << std:: endl;
	

	SDL_RenderDrawLine(_mainRenderer, centerPos.x, centerPos.y, centerPos.x-L*sin(angle), centerPos.y-L*cos(angle));
	//std::cout << sin(angle) << std::endl;
	SDL_RenderDrawLine(_mainRenderer, centerPos.x, centerPos.y, centerPos.x - L*cos(angle), centerPos.y + L*sin(angle));
}


void Arrow::LinkArrow(UIObject* dst)
{
	this->dst = dst;
	isLinked = true;
	std::cout << "link arrow" << std::endl;
}

void Arrow::Unclick()
{
	DNDButton::Unclick();
	for (auto i : mainWindow.draggableButtons)
		if (includeRect(Pos, i->getRect()))
			LinkArrow(i);
}

bool Arrow:: CheckIfClicked()
{
	if (DNDButton::CheckIfClicked())
	{
		isLinked = false;
		dst = NULL;
		std::cout << "click on arrow" << std::endl;
		return true;
	}
	 return false;
}