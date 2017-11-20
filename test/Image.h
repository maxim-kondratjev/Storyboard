#pragma once
#include <iostream>
#include <SDL.h>
#include "UIObject.h"


class Image: public UIObject
{
protected:
	SDL_Rect Pos;
	SDL_Texture* _texture; //�������� �������� ����������
	SDL_Renderer* _mainRenderer; //���� ������ ������ ����� ������������ ������-�� ����, ����� ����� ������ ��� ������ �
public:
	Image(SDL_Renderer* _pRenderer, SDL_Texture* _texture, int posX, int posY, int width, int height);
	void Update();
	void Draw();

};