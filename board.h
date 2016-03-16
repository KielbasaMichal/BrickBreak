#pragma once
#include "head.h"
class board : public sf::RectangleShape
{
public:
	board(float size_x, float size_y, float x, float y, sf::Color color = sf::Color::Transparent);
	board(sf::Vector2f size, sf::Vector2f position, sf::Color color = sf::Color::Transparent);

	bool isContain(sf::Vector2f point);
	~board();
};

