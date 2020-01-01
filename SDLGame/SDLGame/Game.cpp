#include "Game.h"

Game::Game() : left_paddle(0, 240 - 50), right_paddle(680 - 10, 240 - 50), ball((680 / 2) + 5, (680 / 2) + 5)
{
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE, &window_, &renderer_);
	SDL_RenderSetLogicalSize(renderer_, SCREEN_WIDTH, SCREEN_HEIGHT);
	is_running_ = true;
	
	container_[left] = &left_paddle;
	container_[right] = &right_paddle;
	container_[obj::ball] = &ball;

}

void Game::loop()
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	while (is_running_)
	{
		const Uint32 frameStart = SDL_GetTicks();
		handleEvents();
		update();
		render();

		const int frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
}

void Game::render()
{
	SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
	SDL_RenderClear(renderer_);
	SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
	for (int y = 0; y < SCREEN_HEIGHT; ++y)
	{
		if (y % 5)
		{
			SDL_RenderDrawPoint(renderer_, SCREEN_WIDTH / 2, y);
		}
	}

	for (auto& i : container_)
	{
		i->draw(renderer_);
	}

	SDL_RenderPresent(renderer_);
}

void Game::update()
{
	for (auto& i : container_)
	{
		i->update();
	}

	if(ball.collisionCheck(left_paddle) || ball.collisionCheck(right_paddle))
	{
		ball.reverse();
	}
	if(ball.position() < -10 || ball.position() + 5 > SCREEN_WIDTH + 10)
	{
		ball.reset();
	}
}

void Game::handleEvents()
{
	while(SDL_PollEvent(&event_) > 0)
	{
		if (event_.type == SDL_QUIT)
		{
			is_running_ = false;
		}

		if (event_.type == SDL_KEYDOWN && event_.key.repeat == 0)
		{
			switch (event_.key.keysym.sym)
			{
			case SDLK_UP: right_paddle.up(); break;
			case SDLK_DOWN: right_paddle.down(); break;
			case SDLK_w: left_paddle.up(); break;
			case SDLK_s: left_paddle.down(); break;
			}
		}
		else if (event_.type == SDL_KEYUP && event_.key.repeat == 0)
		{
			switch (event_.key.keysym.sym)
			{
			case SDLK_UP: right_paddle.stop(); break;
			case SDLK_DOWN: right_paddle.stop(); break;
			case SDLK_w: left_paddle.stop(); break;
			case SDLK_s: left_paddle.stop(); break;
			}
		}
	}	
}

void Game::clean() const
{
	SDL_DestroyWindow(window_);
	SDL_DestroyRenderer(renderer_);
	SDL_Quit();
}

