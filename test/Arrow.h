#pragma once
#include <SDL.h>
#include "DNDButton.h"

class Arrow : public DNDButton
{
private:
	Image* src;
	Image* dst;
public:
	Arrow(SDL_Renderer* mainRender, SDL_Texture* arrowHead,  int posX, int posxY, int width=50, int height=50);
	void Draw();
};