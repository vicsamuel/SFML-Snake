#include "Game.h"

#include <random>

Game::Game()
	: position_(static_cast<size_t>(width * height), static_cast<char>(tileState::EMPTY))
{
	size_t i, j;
	// Sets the top and bottom walls
	for (i = 0; i < width; ++i)
	{
		setTile({i, 0}, tileState::WALL);
		setTile({i, height - 1}, tileState::WALL);
	}
	// Sets the side walls
	for (j = 0; j < height - 1; ++j)
	{
		setTile({0, j}, tileState::WALL);
		setTile({width - 1, j}, tileState::WALL);
	}

	setTile(snake_.headLocation(), tileState::ADDTAIL);
	setTile(snake_.growSnake(), tileState::SNAKE);

	setTile(randLocation(), tileState::FOOD);
}

// Main method that updates the game screen
void Game::gameUpdate(bool *hasCrashed)
{
	auto newHead{snake_.moveHead()};
	setTile(snake_.followHead(), tileState::EMPTY);

	// Cases for different states of tiles
	switch (static_cast<int>(curLocation(snake_.headLocation())))
	{
	case static_cast<int>(tileState::WALL):

	// Addtail adds on a new piece with a color change effect
	case static_cast<int>(tileState::ADDTAIL):
		*hasCrashed = true;
		break;
	case static_cast<int>(tileState::SNAKE):
		*hasCrashed = true;
		break;
	case static_cast<int>(tileState::FOOD):
		setTile(snake_.headLocation(), tileState::EMPTY);
		setTile(snake_.growSnake(), tileState::SNAKE);
		curScore_ += 1;

		setTile(randLocation(), tileState::FOOD);
	}
	setTile(newHead, tileState::ADDTAIL);
}

void Game::switchDirection(char userInput)
{
	snake_.switchDirection(userInput);
}

char Game::operator[](int i) const
{
	return position_[i];
}

// Returns the current game score
int Game::gameScore() const
{
	return curScore_;
}

// Returns curernt location
int Game::curLocation(Location coordinates) const
{
	return position_[coordinates.y * width + coordinates.x];
}

// Method to obtain a random location and return it for usage
Location Game::randLocation()
{
	// Obtain a random number from hardware and seed generator
	std::random_device rd;
	std::mt19937 gen(rd());

	// Generate random number between range for X and Y
	// Had to add unsigned int to prevent narrowing conversion error
	std::uniform_int_distribution<unsigned int> distributionX(1, width - 2);
	std::uniform_int_distribution<unsigned int> distributionY(1, height - 2);

	// Assign random location to Location coordinates
	Location coordinates = {distributionX(gen), distributionY(gen)};

	// Loop to keep creating random locations while the snake moves
	while (!isEmpty(coordinates))
	{
		coordinates = {distributionX(gen), distributionY(gen)};
	}

	return coordinates;
}

// Sets the tile to the contents provided if the tile is empty
bool Game::setTile(Location coordinates, tileState contents)
{
	if (contents != tileState::EMPTY && !isEmpty(coordinates))
	{
		return false;
	}
	// Must static cast contents so that it is compatible
	position_[coordinates.y * width + coordinates.x] = static_cast<char>(contents);
	return true;
}

// Checks if the tile is empty
bool Game::isEmpty(Location coordinates) const
{
	if (curLocation(coordinates) == static_cast<char>(tileState::EMPTY))
	{
		return true;
	}
	return false;
}
