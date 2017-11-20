#include "DNDButton.h"

DNDButton::DNDButton(SDL_Renderer* _mainRenderer, SDL_Texture* _texture, int posX, int posY, int width, int height) 
	: Button(_mainRenderer, _texture, posX, posY, width, height), isDragged(false)
{
}

void DNDButton::RememberOffset(int X, int Y)
{
	offX = Pos.x - X; offY = Pos.y - Y;
}

void DNDButton::Move(int X, int Y)
{
	int mouseX = 0, mouseY = 0;
	SDL_GetMouseState(&mouseX, &mouseY);
	Pos.x = mouseX + offX; Pos.y = mouseY + offY;
}

void DNDButton::Update()
{
	int mouseX = 0, mouseY = 0;
	SDL_GetMouseState(&mouseX, &mouseY);

	if (isClicked == true)
	{
		Move(mouseX, mouseY);
	}
}

void DNDButton::CheckIfClicked()
{
	if (Button::CheckIfClicked())
	{
		int mouseX = 0, mouseY = 0;
		SDL_GetMouseState(&mouseX, &mouseY);
		RememberOffset(mouseX, mouseY);
		isDragged = true;
	}
}

void DNDButton::Unclick()
{
	Button::Unclick();
	isDragged = false;
}