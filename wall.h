#pragma once
#include "head.h"

class wall : public sf::RectangleShape
{
	b2Body * b2_wall_body;
	
public:
	wall(float size_x, float size_y, float x, float y, b2World &world, sf::Color color = sf::Color::Transparent);
	wall(sf::Vector2f size, sf::Vector2f position, b2World &world, sf::Color color = sf::Color::Transparent);
	~wall();

	b2Body* getb2Body();
};

