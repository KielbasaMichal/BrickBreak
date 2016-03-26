#pragma once

#include "class_header.h"

///block.h
//Pozycja liczona od srodka elementu

class block : public sf::RectangleShape
{
	sf::Texture* _texture;
	bool _contact;
	b2Body * _b2_block_body;
	b2World* _world;
public:
	block(sf::Vector2f size, sf::Vector2f position, b2World &world, std::string src_img);
	block(float size_x, float size_y, float pos_x, float pos_y, b2World &world, std::string src_img);

	block(sf::Vector2f size, sf::Vector2f position, b2World &world, sf::Texture &src_tex);
	block(float size_x, float size_y, float pos_x, float pos_y, b2World & world, sf::Texture &src_tex);

	~block();

	b2Body* getBody();

	//Funkcje do wykrywania kolizji, do klasy ContactListener
	void setContact();
	bool isContact();

};

