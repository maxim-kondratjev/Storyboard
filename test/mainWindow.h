#pragma once

#include "SDL.h"
#include <vector>
#include "ResourceManager.h"
#include "Image.h"
#include "Button.h"
#include "DNDButton.h"
#include "Arrow.h"

struct Window
{
	ResourceManager* _rm;
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	Uint32 userDefinedEvent;
	std::vector<UIObject*> elements;
	std::vector<DNDButton*> draggableButtons;
	std::vector<Button*> buttons;
	std::vector<Image*> images;
	std::vector<Arrow*> arrows;
	//////////////

};

void SetUpMainWindow();

void RedrawMainWindow();
