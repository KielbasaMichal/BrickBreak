#pragma once
#include "head.h"

//Pozycja liczona od srodka elementu

class ball : public sf::CircleShape
{
	b2BodyDef b2_ball;
	b2Body* b2_ball_body;
	b2CircleShape b2_shape;
	b2FixtureDef b2_fix;
public:
	ball(float r, sf::Vector2f position, b2World &world);
	~ball();

	void update_pos();
	b2Body* getBody();

	static void rand_init();
};

