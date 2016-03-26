#pragma once
#include "head.h"

///Ball.h
//Pozycja liczona od srodka elementu
//Do tworzenia jej elementow potrzebny jest promien, pozycja, referencja do swiata fizyki oraz sciezka tekstury

class ball : public sf::CircleShape
{
	sf::Texture texture;
	b2BodyDef b2_ball;
	b2Body* b2_ball_body;
	b2CircleShape b2_shape;
	b2FixtureDef b2_fix;
public:
	ball(float r, sf::Vector2f position, b2World &world, std::string src_img);
	~ball();

	void update_pos();
	b2Body* getBody();

	static void rand_init();
};