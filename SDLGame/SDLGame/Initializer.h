#pragma once
#include <SDL.h>
#include "Window.h"
#include "Renderer.h"

class Initializer
{
public:
	Initializer();

private:
	Window window_;
	Renderer renderer_;
};

