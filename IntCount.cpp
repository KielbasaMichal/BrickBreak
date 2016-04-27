#include "IntCount.h"

IntCount::IntCount(sf::Vector2f size, sf::Vector2f position, sf::Font & font, std::string src_img, int size_font, sf::Color color_font, int val)
	:counter(size, position, font, src_img, size_font, color_font)
{
	_value = val;
	setString(std::to_string(_value));
	CenterText();
}

IntCount::IntCount(float size_x, float size_y, float pos_x, float pos_y, sf::Font & font, std::string src_img, int size_font, sf::Color color_font, int val)
	:IntCount(sf::Vector2f(size_x, size_y), sf::Vector2f(pos_x, pos_y), font, src_img, size_font, color_font, val)
{
	//Wywolanie przez liste wczesniejszego konstruktora
}

IntCount::IntCount(sf::Vector2f size, sf::Vector2f position, sf::Font & font, sf::Texture &src_tex, int size_font, sf::Color color_font, int val)
	: counter(size, position, font, src_tex, size_font, color_font)
{
	_value = val;
	setString(std::to_string(_value));
	CenterText();
}

IntCount::IntCount(float size_x, float size_y, float pos_x, float pos_y, sf::Font & font, sf::Texture &src_tex, int size_font, sf::Color color_font, int val)
	:IntCount(sf::Vector2f(size_x, size_y), sf::Vector2f(pos_x, pos_y), font, src_tex, size_font, color_font, val)
{
	//Wywolanie przez liste wczesniejszego konstruktora
}

IntCount::~IntCount()
{
}

void IntCount::increaseValue(int add)
{
	_value += add;
	setString(std::to_string(_value));
	CenterText();
}