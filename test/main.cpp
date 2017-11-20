#include "ResourceManager.h"
#include "Image.h"
#include "Button.h"
#include "DNDButton.h"

#include <iostream>
#include <SDL.h>
#include <vector>
#include <algorithm>

const int WIDTH = 800, HEIGHT = 600;

struct mainWindow
{
	ResourceManager* _rm;
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	Uint32 userDefinedEvent;
	std::vector<UIObject*> elements;
	std::vector<DNDButton*> draggableButtons;
	std::vector<Button*> buttons;
	std::vector<Image*> images;
	//////////////

}mainWindow;

void SetUpMainWindow()
{

	
	mainWindow.userDefinedEvent = SDL_RegisterEvents(1); //������ ����������� ������������� ������� � ��������� ��� ���, ����� ����� ������������ � �������.

	mainWindow._renderer = SDL_GetRenderer(mainWindow._window);
	mainWindow._rm = new ResourceManager(mainWindow._renderer);

	mainWindow.buttons.push_back(new Button(mainWindow._renderer, mainWindow._rm->LoadImage("Button.bmp"), 0, 0, 100, 100));
	mainWindow.images.push_back(new Image(mainWindow._renderer, mainWindow._rm->LoadImage("TheSun.bmp"), 300, 300, 300, 300));
	mainWindow.draggableButtons.push_back(new DNDButton(mainWindow._renderer, mainWindow._rm->LoadImage("Button.bmp"), 100, 0, 100, 100));

	mainWindow.elements.push_back((UIObject*)(mainWindow.buttons[0]));
	mainWindow.elements.push_back((UIObject*)(mainWindow.images[0]));
	mainWindow.elements.push_back((UIObject*)(mainWindow.draggableButtons[0]));

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

	SDL_SetRenderDrawColor(mainWindow._renderer, 0x00, 0xFF, 0x00, 255);

	int mouseX = 0, mouseY = 0;
	SDL_GetMouseState(&mouseX, &mouseY);
	SDL_RenderDrawLine(mainWindow._renderer, 0, 0, mouseX, mouseY);

	SDL_RenderPresent(mainWindow._renderer);
	
}

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL could not load! SDL Error: " << SDL_GetError() << std::endl;
	}

	SDL_Window *window = SDL_CreateWindow("InterfaceTest", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Renderer *mainRender = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


	if (window == NULL)
	{
		std::cout << "Could not create window: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	mainWindow._window = window;

	SetUpMainWindow();

	RedrawMainWindow();

	SDL_Event windowEvent;

	int mouseX = 0, mouseY = 0;

	while (true)
	{
		if (SDL_PollEvent(&windowEvent))
		{
			if (SDL_QUIT == windowEvent.type)
			{
				break;
			}

			if (windowEvent.type == SDL_MOUSEBUTTONDOWN)
			{
				for (auto &i : mainWindow.buttons)
					i->CheckIfClicked();

				for (auto &i : mainWindow.draggableButtons)
					i->CheckIfClicked();

				for (auto &i : mainWindow.elements)
				{
					i->Update();

				}

				RedrawMainWindow();
			}

			if (windowEvent.type == SDL_MOUSEMOTION)
			{
				for (auto &i : mainWindow.draggableButtons)
				{
					i->Update();
				}
				
				RedrawMainWindow();
			}

			if (windowEvent.type == SDL_MOUSEBUTTONUP) 
			{
				for (auto &i : mainWindow.buttons)
					i->Unclick();

				for (auto &i : mainWindow.draggableButtons)
					i->Unclick();

				for (auto &i : mainWindow.elements)
				{
					i->Update();
				}
				RedrawMainWindow();
			}

			if (windowEvent.type == mainWindow.userDefinedEvent)
			{

			}

		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}
