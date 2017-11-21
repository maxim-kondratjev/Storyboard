#pragma once
#include <vector>
#include "Button.h"
#include "IMovable.h"

class DNDButton : public Button, public IMovable
{
private:
	int isDragged;
	bool isChild;
	std::vector<DNDButton*> Bibs;
public:
	DNDButton(SDL_Renderer* _mainRenderer, SDL_Texture* _texture, int posX = 0, int posY = 0, int width = 100, int height = 100, bool isChild=false);
	void RememberOffset(int X, int Y);
	void Move(int X, int Y);
	void Update();
	bool CheckIfClicked();
	void Unclick();
	void Draw();
};