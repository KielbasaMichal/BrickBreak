#pragma once
#include "class_header.h"

///Ball.h
//Pozycja liczona od srodka elementu
//Do tworzenia jej elementow potrzebny jest promien, pozycja, referencja do swiata fizyki oraz sciezka tekstury

class ball : public sf::CircleShape
{
	sf::Texture* _texture;
	b2BodyDef _b2_ball;
	b2Body* _b2_ball_body;
	b2CircleShape _b2_shape;
	b2FixtureDef _b2_fix;
public:
	ball(float r, sf::Vector2f position, b2World &world, std::string src_img);
	ball(float r, sf::Vector2f position, b2World &world, sf::Texture &src_tex);
	~ball();

	void update_pos();
	b2Body* getBody();
};