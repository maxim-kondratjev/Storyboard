#pragma once
#include <SDL.h>

#include "Button.h"
#include "IMovable.h"

class DNDButton : public Button, public IMovable
{
private:
	int offX, offY;
	int isDragged;
public:
	DNDButton(SDL_Renderer* _mainRenderer, SDL_Texture* _texture, int posX = 0, int posY = 0, int width = 100, int height = 100);
	void RememberOffset(int X, int Y);
	void Move(int X, int Y);
	void Update();
	void CheckIfClicked();
	void Unclick();
};