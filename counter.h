#pragma once

#include "SFML\Graphics.hpp"
#include <string>
#include <iostream>

class counter : public sf::RectangleShape
{
	sf::Text count;
	int value;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	counter(sf::Vector2f size, sf::Vector2f position, sf::Font &font, sf::Color color, int val = 0);
	~counter();

	void increaseValue(int add);
	
};

