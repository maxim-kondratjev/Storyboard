#include "Button.h"

Button::Button(SDL_Renderer* _mainRenderer, SDL_Texture* _textur, int posX, int posY, int width, int height) 
	: Image(_mainRenderer, _textur, posX, posY, width, height), isClicked(false)
{
	_textureVariants[0] = _texture;

	myCode = -1;
}
int Button::code = 0;

void Button::Update() //Îáðàáîò÷èê ñîáûòèé äëÿ êíîïêè.
{

	if (mainFunction == "one" && isClicked == true)
	{
		std::cout << "test2\n";
		std::cout << "test3\n";
		SDL_Event tempEvent;
		tempEvent.type = myEventType;
		tempEvent.user.code = myCode;
		SDL_PushEvent(&tempEvent);
	}

	if (isClicked == true)
	{
		_texture = _textureVariants[1];
		isClicked = false;
	}
	else
	{
		_texture = _textureVariants[0];
	}
}


bool Button::CheckIfClicked()
{
	int mouseX = 0, mouseY = 0;
	isClicked = false;

	SDL_GetMouseState(&mouseX, &mouseY);
	
		if ((mouseX > Pos.x) && (mouseX < Pos.x + Pos.w) && (mouseY > Pos.y) && (mouseY < Pos.y + Pos.h))
		{
			std::cout << "Detected a click at (" << mouseX << "," << mouseY << ")!\n";
			isClicked = true;
		}
	
	return isClicked;
}

void Button::AddPressedImage(SDL_Texture* _texture)
{
	_textureVariants[1] = _texture;
}

int Button::GetCode()
{
	return myCode;
}

void Button::setMainFunction(std::string mainFunctions, Uint32 eventType)
{
	mainFunction = mainFunctions;  //êàæäàÿ ôóíêöèîíàëüíàÿ êíîïêà óíèêàëüíà
	myEventType = eventType;       //ó âñåõ êíîïîê îäèí òèï ïîñûëàåìîãî â îáðàáîò÷èê ñîáûòèÿ
	myCode = code++;               //êàæäàÿ ôóíêöèîíàëüíàÿ êíîïêà îòëè÷àåòñÿ îò äðóãîé, äàæå íåñóùåé òàêîé æå ôóíêöèþ, ñâîèì êîäîì
}

void Button::Unclick()
{
	isClicked = false;
}
