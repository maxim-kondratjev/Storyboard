#pragma once
#include <SDL.h>
#include "DNDButton.h"

class Arrow : public DNDButton
{
private:
	bool isLinked;
	UIObject* src;
	UIObject* dst;
	void LinkArrow(UIObject* dst);
public:
	Arrow(SDL_Renderer* mainRender, SDL_Texture* arrowHead, int posX, 
		int posxY, int width=50, int height=50, UIObject* src=NULL, bool isLinked=false);
	void Draw();
	void Unclick();
	bool CheckIfClicked();
};