#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h"

class Window : public sf::Drawable
{
public:

	Window(int winWidth, const char* title);
	~Window() = default;

	void openWindow();
	void closeWindow();
	void playMusic();


private:
	
	// rectSize is used to divide the window and get a size of the rectangles for snake and food
	const float rectSize_;
	bool hasCrashed_;
	Game game_;
	sf::RenderWindow gameWindow_;
	sf::Font font_;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void eventHandler();
	void displayScore();
	void windowUpdate();
};
