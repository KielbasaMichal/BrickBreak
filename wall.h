#pragma once
#include "class_header.h"

///wall.h
//Pozycja liczona od srodka elementu
//Sciany do ograniczenia pola rozgrywki

class wall : public sf::RectangleShape
{
	sf::Texture* _texture;
	b2Body * _b2_wall_body;
	
public:
	wall(sf::Vector2f size, sf::Vector2f position, b2World &world, std::string src_img);
	wall(float size_x, float size_y, float x, float y, b2World &world, std::string src_img);

	wall(sf::Vector2f size, sf::Vector2f position, b2World &world, sf::Texture &src_tex);
	wall(float size_x, float size_y, float x, float y, b2World &world, sf::Texture &src_tex);

	~wall();

	b2Body* getb2Body();
};

