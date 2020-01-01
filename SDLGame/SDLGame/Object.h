#pragma once
#include <SDL.h>
#include <string>

class Object
{
public:
	Object() = default;
	virtual ~Object() = default;
	virtual void update() = 0;
	virtual void draw(SDL_Renderer* renderer) = 0;
};
