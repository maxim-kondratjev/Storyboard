#include "Image.h"
#include "ResourceManager.h"

Image::Image(SDL_Renderer* _pRender, SDL_Texture* texture, int posX, int posY, int width, int height )
{
	if (_pRender != NULL)
	{
		_mainRenderer = _pRender;
	}
	_texture = texture;
	Pos.x = posX; Pos.y = posY; Pos.w = width; Pos.h = height;
}

void Image::Draw()
{

	if (_texture == NULL)
	{
		std::cout << "No texture surface!\n";
		return;
	}
	SDL_RenderCopy(_mainRenderer, _texture, NULL, &Pos);
}

void Image::Update()
{

}

SDL_Rect Image::getRect()
{
	SDL_Rect a;
	a = Pos;
	return  a;
}