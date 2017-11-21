#include "mainWindow.h"
#include <iostream>
#include <SDL.h>
#include <vector>
#include <algorithm>

const int WIDTH = 800, HEIGHT = 600;
extern struct Window mainWindow;


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

				for (auto &i : mainWindow.arrows)
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
				for (auto &i : mainWindow.arrows)
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

				for (auto &i : mainWindow.arrows)
					i->Unclick();

				for (auto &i : mainWindow.elements)
				{
					i->Update();
				}
				RedrawMainWindow();
			}

			if (windowEvent.type == mainWindow.userDefinedEvent)
			{
				//for (auto &i : mainWindow.buttons)//тут идет поиск эвента по коду кнопки
			}

		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}
