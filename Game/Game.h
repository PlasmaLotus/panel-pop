/*
 * Game.h
 *
 *  Created on: Aug 16, 2015
 *      Author: axel
 */

#ifndef GAME_H_
#define GAME_H_

#include "Board.h"
#include "KeyboardController.h"

class Game {
public:
	Game();
	Board _board;
	Board _board2;
	virtual ~Game();
	void tick();
	void reset();
	void inputTogglePause();
	const bool isPaused() const;
private:
	bool _paused;
	void handleGarbageSpawning(Board&, Board&);
};

#endif /* GAME_H_ */
