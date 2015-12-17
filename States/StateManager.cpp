/*
 * StateManager.cpp
 *
 *  Created on: 9.12.2015
 *      Author: axelw
 */

#include "StateManager.h"

#include "../Config/KeyboardControllerConfig.h"
#include "GameState.h"
#include "../SDLContext.h"

StateManager::StateManager() :
		_currentState(nullptr), _lastTick(0), _running(true), SDL(
				SDLContext::getInstance()), input(InputManager::getInstance()), _frameTime(
				16) {
	KeyboardControllerConfig c = {SDL_SCANCODE_UP,SDL_SCANCODE_DOWN,SDL_SCANCODE_LEFT,SDL_SCANCODE_RIGHT,SDL_SCANCODE_Z,SDL_SCANCODE_X};
	KeyboardControllerConfig c2 = {SDL_SCANCODE_R,SDL_SCANCODE_F,SDL_SCANCODE_D,SDL_SCANCODE_G,SDL_SCANCODE_T,SDL_SCANCODE_Y};
	//passed as reference but the KeyboardController copies it :P
	_currentState = new GameState(c, c2);
}

StateManager& StateManager::getInstance() {
	static StateManager instance;
	return instance;
}

void StateManager::run() {
	bool tick;
	while (_running) {
		tick = (SDL_GetTicks() - _lastTick >= _frameTime);
		if (tick) {
			input.poll();
			if (input._quit) {
				//TODO: State transitions?
				_running = false;
				break;
			}
			if(input._keys[SDL_SCANCODE_LALT] && input._keys[SDL_SCANCODE_RETURN] && !input._prevKeys[SDL_SCANCODE_RETURN]){
				SDL.toggleFullscreen();
			}
			_currentState->tick();
		}
		SDL_Texture* t = _currentState->render();
		SDL.renderTextureToWindow(t);
		if(tick){
			_lastTick = SDL_GetTicks();
		}
	}
}

