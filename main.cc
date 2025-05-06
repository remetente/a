////////////////////////////////
// Lib
////////////////////////////////
#include <iostream>
#include <vector>
#include <string>

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <SDL3_ttf/SDL_ttf.h>

////////////////////////////////
// Init
////////////////////////////////
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

bool error(std::string str) {
	std::cerr << str << ": " << SDL_GetError() << std::endl;
	return false;
}

bool init() {
	// initialize libraries
	try {
		// sdl
		if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)) throw 1;

		// audio
		int Mix_Flags = Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG);
		if (!(Mix_Flags |= MIX_INIT_FLAC)) throw 1;
		if (!(Mix_Flags |= MIX_INIT_MP3)) throw 1;
		if (!(Mix_Flags |= MIX_INIT_OGG)) throw 1;

		// fonts
		if (!TTF_Init()) throw 1;
	}
	catch (...)
		return error("Error during initialization");

	// create window
	try {
		if (!SDL_CreateWindowAndRenderer("music maker", 800, 600, SDL_WINDOW_RESIZABLE, &window, &renderer)) throw 1;
	}
	catch (...)
		return error("Error creating window");

	return true;
}

void quit() {
	// close window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	// close libraries
	TTF_Quit();
	Mix_CloseAudio();
	Mix_Quit();
	SDL_Quit();
}

////////////////////////////////
// Main
////////////////////////////////
int main() {
	if (init()) {
		std::cout << "1" << std::endl;
	}
	quit();
	return 0;
}
