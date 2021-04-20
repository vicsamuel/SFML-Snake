#pragma once

#include "Snake.h" 
#include "Location.h"

#include <iostream>

class Game
{
public:

	Game();
	~Game() = default;

	void gameUpdate(bool* hasCrashed);
	void switchDirection(char userInput);

	char operator[](int i) const;
	int gameScore() const;
	int curLocation(Location coordinates) const;

	// Constants to change the size of the game field of view
	static constexpr int width = 24;
	static constexpr int height = 18;

	enum class tileState
	{
		EMPTY,
		WALL,
		SNAKE,
		ADDTAIL,
		FOOD
	};

private:

	Snake snake_;
	std::string position_;
	unsigned int curScore_ = 0;

	Location randLocation();
	bool setTile(Location coordinates, tileState content);
	bool isEmpty(Location coordinates) const;
};