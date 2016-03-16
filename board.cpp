#include "board.h"


board::board(float size_x, float size_y, float x, float y, sf::Color color)
{
	setSize(sf::Vector2f(size_x, size_y));
	setPosition(x, y);
	setFillColor(color);
}

board::board(sf::Vector2f size, sf::Vector2f position, sf::Color color)
{
	setPosition(position);
	setSize(size);
	setFillColor(color);
}

bool board::isContain(sf::Vector2f point)
{
	if (getGlobalBounds().contains(point))
		return true;
	else
		return false;
}

board::~board()
{
}
