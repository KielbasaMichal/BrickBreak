#pragma once
#include "class_header.h"

///board.h
//Pozycja liczona od srodka elementu

class board : public sf::RectangleShape
{
	sf::Texture* _texture;
public:
	board(sf::Vector2f size, sf::Vector2f position, std::string src_img);
	board(float size_x, float size_y, float x, float y, std::string src_img);

	board(sf::Vector2f size, sf::Vector2f position, sf::Texture &src_tex);
	board(float size_x, float size_y, float x, float y, sf::Texture &src_tex);
	
	bool isContain(sf::Vector2f point);
	~board();
};

