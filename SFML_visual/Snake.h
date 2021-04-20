#pragma once

#include <vector>

#include <SFML\Graphics.hpp>
#include "Location.h"

class Snake
{
public:

	Snake();
	~Snake() = default;
	
	void switchDirection(char userInput);
	size_t size();

	Location growSnake();
	Location followHead();
	Location moveHead();
	Location headLocation() const;

private:

	struct SnakeBody
	{
		Location cur_;
		Location prev_;
	};

	enum class moveDirection 
	{
		UP,
		RIGHT,
		DOWN,
		LEFT
	};

	std::vector<SnakeBody> snakeContainer_;
	moveDirection direction_;
};