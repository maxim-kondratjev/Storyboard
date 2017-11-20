#pragma once
#include <SDL.h>
#include "DNDButton.h"

class Arrow : public Image, public IMovable
{
private:

public:
	Arrow(SDL_Renderer* mainRender, SDL_Texture* arrowHead);
};