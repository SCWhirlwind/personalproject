#include "Window.h"


Window::Window(const char* title, int width, int height)
{
	width_ = width;
	height_ = height;
	title_ = title;
}

Window::~Window()
{
	SDL_DestroyWindow(window_);
}

SDL_Window* Window::getWindow() const
{
	return window_;
}

void Window::createWindow()
{
	window_ = SDL_CreateWindow(title_, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width_, height_, 0);
}
