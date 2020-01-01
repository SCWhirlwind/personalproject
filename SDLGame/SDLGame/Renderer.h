#pragma once
#include <SDL.h>

class Renderer
{
public:
	Renderer();

private:
	SDL_Renderer* renderer_ = nullptr;
};

