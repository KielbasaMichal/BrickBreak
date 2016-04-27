#include "SymbolCount.h"



void SymbolCount::createString()
{
	std::string temp;
	for (int i = 0; i < _value;i++)
		temp += _symbol;
	setString(temp);
}

SymbolCount::SymbolCount(sf::Vector2f size, sf::Vector2f position, sf::Font &font, std::string src_img, int size_font, sf::Color color_font, char symbol, int value)
	:counter(size, position, font, src_img, size_font, color_font)
{
	_symbol = symbol;
	_value = value;
	createString();
	CenterText();
}

SymbolCount::SymbolCount(float size_x, float size_y, float pos_x, float pos_y, sf::Font &font, std::string src_img, int size_font, sf::Color color_font, char symbol, int value)
	:SymbolCount(sf::Vector2f(size_x, size_y), sf::Vector2f(pos_x, pos_y), font, src_img, size_font, color_font, symbol, value)
{
	//Wywolanie przez liste wczesniejszego konstruktora
}

SymbolCount::SymbolCount(sf::Vector2f size, sf::Vector2f position, sf::Font &font, sf::Texture &src_tex, int size_font, sf::Color color_font, char symbol, int value)
	:counter(size, position, font, src_tex, size_font, color_font)
{
	_symbol = symbol;
	_value = value;
	createString();
	CenterText();
}
SymbolCount::SymbolCount(float size_x, float size_y, float pos_x, float pos_y, sf::Font &font, sf::Texture &src_tex, int size_font, sf::Color color_font, char symbol, int value)
	: SymbolCount(sf::Vector2f(size_x, size_y), sf::Vector2f(pos_x, pos_y), font, src_tex, size_font, color_font, symbol, value)
{
	//Wywolanie przez liste wczesniejszego konstruktora
}

SymbolCount::~SymbolCount()
{
}

void SymbolCount::deleteOne()
{
	_value -= 1;
	createString();
}
