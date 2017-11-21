#include "mainWindow.h"
extern struct Window mainWindow;

DNDButton::DNDButton(SDL_Renderer* _mainRenderer, SDL_Texture* _texture, int posX, int posY, int width, int height, bool isChild)
	: Button(_mainRenderer, _texture, posX, posY, width, height), isDragged(false)
{
	this->isChild = isChild;
	if (!isChild)
	{
		Bibs.push_back(new DNDButton(_mainRenderer, mainWindow._rm->LoadImage("delete.bmp"), posX, posY, 15, 15, true));
		Bibs.push_back(new DNDButton(_mainRenderer, mainWindow._rm->LoadImage("link.bmp"), posX + Pos.w - 15, posY, 15, 15, true));
	}
}


void DNDButton::RememberOffset(int X, int Y)
{
	offX = Pos.x - X; offY = Pos.y - Y;
	//std::cout << offX << "||" << offY << std::endl;
	if (!isChild)
		for (auto i : Bibs)
			i->RememberOffset(X, Y);
}

void DNDButton::Move(int X, int Y)
{
	int mouseX = 0, mouseY = 0;
	SDL_GetMouseState(&mouseX, &mouseY);
	Pos.x = mouseX + offX; Pos.y = mouseY + offY;
	if (!isChild)
		for (auto i : Bibs)
			i->Move(X,Y);
}

void DNDButton::Update()
{
	int mouseX = 0, mouseY = 0;
	SDL_GetMouseState(&mouseX, &mouseY);

	if (!isChild)
	{
		if (isClicked == true)
		{
			Move(mouseX, mouseY);
		}

		for (auto i : Bibs)
			i->Update();
	}
}

bool DNDButton::CheckIfClicked()
{
	if (Button::CheckIfClicked())
	{
		int mouseX = 0, mouseY = 0;
		SDL_GetMouseState(&mouseX, &mouseY);
		RememberOffset(mouseX, mouseY);
		std::cout << isChild << std::endl;
		if (!isChild)
		{
			isDragged = true;
			for (auto i : Bibs)
				i->Button::CheckIfClicked();
		}
		return true;
	}
	return false;
}

void DNDButton::Unclick()
{
	Button::Unclick();
	isDragged = false;
}

void DNDButton::Draw()
{
	Image::Draw();
	if (!isChild)
	for (auto i : Bibs)
		i->Draw();
}