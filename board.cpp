#include "board.h"

board::board(sf::Vector2f size, sf::Vector2f position, std::string src_img)
{
	setPosition(position);
	setSize(size);
	_texture = new sf::Texture;
	_texture->loadFromFile(src_img);
	setTexture(_texture);
}

board::board(float size_x, float size_y, float x, float y, std::string src_img)
	: board(sf::Vector2f(size_x, size_y), sf::Vector2f(x, y), src_img)
{
	//Wywolanie przez liste wczesniejszego konstruktora
}

board::board(sf::Vector2f size, sf::Vector2f position, sf::Texture &src_tex)
{
	setPosition(position);
	setSize(size);
	_texture = new sf::Texture;
	_texture = &src_tex;
	setTexture(_texture);
}

board::board(float size_x, float size_y, float x, float y, sf::Texture &src_tex)
	: board(sf::Vector2f(size_x, size_y), sf::Vector2f(x, y), src_tex)
{
	//Wywolanie przez liste wczesniejszego konstruktora
}

bool board::isContain(sf::Vector2f point)
{
	if (getGlobalBounds().contains(point))
		return true;
	else
		return false;
}

board::~board()
{
}
