#pragma once
#include "head.h"

class paddle : public sf::RectangleShape
{
	b2BodyDef b2_block;
	b2Body * b2_block_body;
	b2PolygonShape b2_shape;
	b2FixtureDef b2_fix;
public:
	paddle(float size, float size2, sf::Vector2f position, b2World &world, sf::Color color = sf::Color::Transparent);
	~paddle();
	bool collison(sf::FloatRect rect);
	void update_pos(float x, float y);
	b2Body* getBody();

	static void rand_init();
};

