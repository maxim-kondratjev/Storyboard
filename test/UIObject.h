#pragma once
#include "SDL.h"

class UIObject abstract
{
protected:
	SDL_Rect Pos;
	bool IsShown;
public:
	virtual SDL_Rect getRect() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};