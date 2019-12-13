#include "Game.h"

SDL_Texture* player_tex;
SDL_Rect src_r;
SDL_Rect dest_r;

Game::~Game()
{
	clean();
}

Game::Game(const Game& copy) noexcept(false)
{
	*this = copy;
}

Game& Game::operator=(const Game& rhs) noexcept(false)
{
	if (this != &rhs)
	{
		is_running_ = rhs.is_running_;
		cnt_ = rhs.cnt_;
		window_ = rhs.window_;
		renderer_ = rhs.renderer_;
	}
	return *this;
}

Game::Game(Game&& copy) noexcept
{
	*this = std::move(copy);
}

Game& Game::operator=(Game&& rhs) noexcept
{
	if(this != &rhs)
	{
		is_running_ = rhs.is_running_;
		cnt_ = rhs.cnt_;
		window_ = rhs.window_;
		renderer_ = rhs.renderer_;
	}
	return *this;
}

void Game::init(const char* title, const int width, const int height, const bool fullscreen)
{
	auto flags = 0;

	if(fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window_ = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer_ = SDL_CreateRenderer(window_, - 1, 0);

		if(renderer_)
		{
			SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
		}

		is_running_ = true;
	}

	const auto temp_surface = IMG_Load("assets/raiden.png");
	player_tex = SDL_CreateTextureFromSurface(renderer_, temp_surface);

	if(!player_tex)
	{
		std::cout << "error";
	}
	SDL_FreeSurface(temp_surface);
}

void Game::handle_events()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		is_running_ = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	cnt_++;
	dest_r.h = 32;
	dest_r.w = 32;
	std::cout << cnt_ << std::endl;
}

void Game::render() const
{
	SDL_RenderClear(renderer_);
	SDL_RenderCopy(renderer_, player_tex, nullptr, &dest_r);
	SDL_RenderPresent(renderer_);
}

void Game::clean() const
{
	SDL_DestroyWindow(window_);
	SDL_DestroyRenderer(renderer_);
	SDL_Quit();
}

