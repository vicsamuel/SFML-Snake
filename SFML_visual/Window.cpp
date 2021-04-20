#include "Window.h"

#include <iostream>
#include <chrono>
#include <thread>


Window::Window(int winWidth, const char* winTitle)
	: rectSize_{ static_cast<float>(winWidth / Game::width) }, hasCrashed_{ false }
{
	// Sets a 4:3 aspect ratio depending on width
	const int winHeight = (winWidth * 3 / 4);

	// Path for the font type
	const char* fontLocation = "C:/Users/vsamu/source/repos/SFML-Snake-Final/SFML_visual/SFML_visual/good_times.ttf";

	if (!font_.loadFromFile(fontLocation))
	{
		std::cout << "File not found in the provided file path location: " << fontLocation << '\n';
	}

	// Create game window and set framrate
	gameWindow_.create(sf::VideoMode(winWidth, winHeight), winTitle);
	gameWindow_.setFramerateLimit(5);
}

void Window::eventHandler()
{
	sf::Event event;

	while (gameWindow_.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			gameWindow_.close();
			break;
		case sf::Event::TextEntered:
			game_.switchDirection(static_cast<char>(event.text.unicode));
			break;
		case sf::Event::KeyPressed:
			game_.switchDirection(static_cast<char>(event.text.unicode));
		}
	}
}

// Overriden draw function to implement states
void Window::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Color limeGreen(0, 255, 0);
	sf::Color redOrange(255, 51, 51);
	
	unsigned int i, j, k, l;
	for (i = 0, j = Game::height; i < j; ++i)
	{
		for (k = 0, l = Game::width; k < l; ++k)
		{
			Location here{ k, i };
			sf::RectangleShape rectangle;
			rectangle.setSize({ rectSize_, rectSize_ });
			rectangle.setPosition({ rectSize_ * k, rectSize_ * i });

			// EXPLAIN HERE THING
			switch (game_.curLocation(here))
			{
			case static_cast<int>(Game::tileState::WALL) :
				target.draw(rectangle, states);
				break;
			case static_cast<int>(Game::tileState::ADDTAIL) :
				rectangle.setFillColor(sf::Color::Yellow);
				target.draw(rectangle, states);
				break;
			case static_cast<int>(Game::tileState::SNAKE):
				rectangle.setFillColor(limeGreen);
				target.draw(rectangle, states);
				break;
			case static_cast<int>(Game::tileState::FOOD) :
				rectangle.setFillColor(redOrange);
				target.draw(rectangle, states);
			}
		}
	}
	
	sf::Text scoreboard;
	scoreboard.setFont(font_);
	scoreboard.setCharacterSize(static_cast<unsigned int>(rectSize_));
	scoreboard.setPosition({ 300.0f, 0.0f });
	scoreboard.setString("Score: " + std::to_string(game_.gameScore()));
	scoreboard.setFillColor(sf::Color::Black);

	target.draw(scoreboard, states);
}


void Window::windowUpdate()
{
	// Displays score window and closes after snake crashes
	if (hasCrashed_)
	{
		displayScore();
		gameWindow_.close();
		closeWindow();
	}

	// Clears window and draws new position of snake
	gameWindow_.clear(sf::Color::Black);
	gameWindow_.draw(*this);
	gameWindow_.display();
}

void Window::openWindow()
{
	while (gameWindow_.isOpen())
	{
		// Handles polling events like closing before game over
		eventHandler();
		game_.gameUpdate(&hasCrashed_);
		windowUpdate();
	}
}

void Window::closeWindow()
{
	// For debugging
	std::this_thread::sleep_for((std::chrono::milliseconds)1000);
}

// New window to diplay final score before closing
void Window::displayScore()
{
	sf::Text finalScore("Your Final Score is: " + std::to_string(game_.gameScore())
		+ "\nThanks for Playing!!!", font_);
	finalScore.setCharacterSize(24);
	finalScore.setFillColor(sf::Color::Red);
	sf::RenderWindow scoreWindow(sf::VideoMode(375, 80), "Score Window");
	while (scoreWindow.isOpen())
	{
		sf::Event event;
		while (scoreWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				scoreWindow.close();
			}
		}
		scoreWindow.clear(sf::Color::Black);
		scoreWindow.draw(finalScore);
		scoreWindow.display();
	}
}

// Had to add music in main for some reason
void Window::playMusic()
{
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("chiptronical.ogg"))
	{
		std::cout << "Music failed to load!" << '\n';
	}
	sf::Sound music;
	music.setBuffer(buffer);
	music.play();
}