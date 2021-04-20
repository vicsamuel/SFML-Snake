#include "Snake.h"

Snake::Snake()
	: direction_{ moveDirection::RIGHT }
{
	// Set size and place head of snake
	SnakeBody head{ {5, 2}, {4, 2} };
	snakeContainer_.push_back(head);

	--head.cur_.x;
	snakeContainer_.push_back(head);
}

size_t Snake::size()
{
	return snakeContainer_.size();
}

// Move back container pieces to add new head
Location Snake::growSnake()
{
	snakeContainer_.push_back({
		snakeContainer_.back().prev_,
		snakeContainer_.back().prev_
		});
	return snakeContainer_.back().prev_;
}

// Arrow key and wasd suppord
void Snake::switchDirection(char userInput)
{
	if (userInput == sf::Keyboard::Up || userInput == sf::Keyboard::Down
		|| userInput == sf::Keyboard::Right || userInput == sf::Keyboard::Left)
	{
		switch (userInput)
		{
		case sf::Keyboard::Up:
			if (direction_ != moveDirection::DOWN)
			{
				direction_ = moveDirection::UP;
				break;
			}
		case sf::Keyboard::Right:
			if (direction_ != moveDirection::LEFT)
			{
				direction_ = moveDirection::RIGHT;
				break;
			}
		case sf::Keyboard::Down:
			if (direction_ != moveDirection::UP)
			{
				direction_ = moveDirection::DOWN;
				break;
			}
		case sf::Keyboard::Left:
			if (direction_ != moveDirection::RIGHT)
			{
				direction_ = moveDirection::LEFT;
			}
		}
	}
	switch (userInput) {
	case 'w':
		if (direction_ != moveDirection::DOWN)
		{
			direction_ = moveDirection::UP;
			break;
		}
	case 'd':
		if (direction_ != moveDirection::LEFT)
		{
			direction_ = moveDirection::RIGHT;
			break;
		}
	case 's':
		if (direction_ != moveDirection::UP)
		{
			direction_ = moveDirection::DOWN;
			break;
		}
	case 'a':
		if (direction_ != moveDirection::RIGHT)
		{
			direction_ = moveDirection::LEFT;
		}
	}

}

Location Snake::followHead()
{
	// Move container pieces behind head using vector STL
	auto i = snakeContainer_.begin();
	for (auto j = i++; i != snakeContainer_.end(); ++i, ++j)
	{
		i->prev_ = i->cur_;
		i->cur_ = j->prev_;
	}
	return snakeContainer_.back().prev_;
}

Location Snake::moveHead()
{
	// Uses enum and vector STL to determine where head goes
	snakeContainer_[0].prev_ = snakeContainer_[0].cur_;

	switch (direction_) {
	case moveDirection::UP:
		--snakeContainer_.front().cur_.y;
		break;
	case moveDirection::DOWN:
		++snakeContainer_.front().cur_.y;
		break;
	case moveDirection::LEFT:
		--snakeContainer_.front().cur_.x;
		break;
	case moveDirection::RIGHT:
		++snakeContainer_.front().cur_.x;
	}

	return snakeContainer_.front().cur_;
}

Location Snake::headLocation() const
{
	return snakeContainer_.front().cur_;
}
