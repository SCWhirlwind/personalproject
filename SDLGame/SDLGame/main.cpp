#include "Game.h"

Game* game1 = nullptr;

int main(int argc, char* argv[])
{
	const auto fps = 60;
	const auto frame_delay = 1000/fps;

	game1 = new Game();
	game1->init("Game!", 800, 600, false);

	while (game1->running())
	{
		const auto frame_start = SDL_GetTicks();

		game1->handle_events();
		game1->update();
		game1->render();

		const int frame_time = SDL_GetTicks() - frame_start;

		if(frame_delay > frame_time)
		{
			SDL_Delay(frame_delay - frame_time);
		}
	}

	game1->clean();

	return 0;
}