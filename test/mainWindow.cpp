#include "mainWindow.h"

struct Window mainWindow;

void SetUpMainWindow()
{


	mainWindow.userDefinedEvent = SDL_RegisterEvents(1);

	mainWindow._renderer = SDL_GetRenderer(mainWindow._window);
	mainWindow._rm = new ResourceManager(mainWindow._renderer);

	mainWindow.buttons.push_back(new Button(mainWindow._renderer, mainWindow._rm->LoadImage("Button.bmp"), 0, 0, 100, 100));
	mainWindow.images.push_back(new Image(mainWindow._renderer, mainWindow._rm->LoadImage("TheSun.bmp"), 300, 300, 300, 300));
	mainWindow.draggableButtons.push_back(new DNDButton(mainWindow._renderer, mainWindow._rm->LoadImage("Button.bmp"), 100, 0, 100, 100));
	mainWindow.arrows.push_back(new Arrow(mainWindow._renderer, mainWindow._rm->LoadImage("arrow.bmp"), 400, 0, 30, 30));

	mainWindow.elements.push_back((UIObject*)(mainWindow.buttons[0]));
	mainWindow.elements.push_back((UIObject*)(mainWindow.images[0]));
	mainWindow.elements.push_back((UIObject*)(mainWindow.draggableButtons[0]));
	mainWindow.elements.push_back((UIObject*)(mainWindow.arrows[0]));

	mainWindow.buttons[0]
		->AddPressedImage(mainWindow._rm->LoadImage("Button_pressed.bmp"));

}

void RedrawMainWindow()
{
	SDL_SetRenderDrawColor(mainWindow._renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(mainWindow._renderer);

	for (auto &i : mainWindow.elements)
	{
		i->Draw();
	}


	int mouseX = 0, mouseY = 0;

	SDL_RenderPresent(mainWindow._renderer);

}