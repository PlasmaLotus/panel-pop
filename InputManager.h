/*
 * InputManager.h
 *
 *  Created on: Aug 19, 2015
 *      Author: axel
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include <array>

#define KEYBOARD_SIZE 282

class InputManager {
public:
	static InputManager& getInstance();
	void poll();
	bool _quit;
	 std::array<bool, KEYBOARD_SIZE> _keys;
private:
	InputManager();
	InputManager(InputManager const&) = delete;
	void operator=(InputManager const&) = delete;
};

#endif /* INPUTMANAGER_H_ */
