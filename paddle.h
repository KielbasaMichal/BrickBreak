#pragma once
#include "class_header.h"

///paddle.h
//Pozycja liczona od srodka elementu
//Paletka do odbijania elementu ball

class paddle : public sf::RectangleShape
{
	sf::Texture* _texture;
	b2BodyDef _b2_block;
	b2Body * _b2_block_body;
	b2PolygonShape _b2_shape;
	b2FixtureDef _b2_fix;
public:
	paddle(sf::Vector2f size, sf::Vector2f position, b2World &world, std::string src_img);
	paddle(float size_x, float size_y, float pos_x, float pos_y, b2World &world, std::string src_img);

	paddle(sf::Vector2f size, sf::Vector2f position, b2World &world, sf::Texture &src_tex);
	paddle(float size_x, float size_y, float pos_x, float pos_y, b2World &world, sf::Texture &src_tex);

	~paddle();
	void update_pos(float x, float y);
	void update_pos_x_in_rage(sf::Vector2f updateTo, float min, float max);
	b2Body* getBody();

	static void rand_init();
};

