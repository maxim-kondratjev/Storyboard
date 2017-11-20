#pragma once
#include "SDL.h"

class UIObject abstract
{
private:
	bool IsShown;
public:
	virtual void Update() = 0;
	virtual void Draw() = 0;
};