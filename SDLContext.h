/*
 * SDLContext.h
 *
 *  Created on: Aug 15, 2015
 *      Author: axel
 */

#ifndef SDLCONTEXT_H_
#define SDLCONTEXT_H_

#include <SDL2/SDL.h>

class SDLContext {
public:
	const int WINDOW_WIDTH, WINDOW_HEIGHT;

	static SDLContext& getInstance();
	bool init();
	void tearDown();
	SDL_Renderer* getRenderer();
	void renderTextureToWindow(SDL_Texture*);
private:
	SDLContext();
	SDLContext(SDLContext const&) = delete;
	void operator=(SDLContext const&) = delete;

	SDL_Window* _window;
	SDL_Renderer* _renderer;
};

#endif /* SDLCONTEXT_H_ */
