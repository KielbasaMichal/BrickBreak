#pragma once

#include "SFML\Graphics.hpp"
#include <string>
#include <iostream>

using namespace std;

class button : public sf::RectangleShape
{
private:
	bool status;
	sf::Text title;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	button(sf::Vector2f size, sf::Vector2f position, string text, sf::Font &font, sf::Color color);
	~button();

	void check_activate(sf::RenderWindow &windows);
	bool check_mouse_click(sf::RenderWindow &windows);
};

