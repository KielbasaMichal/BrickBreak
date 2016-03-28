#pragma once

#include "class_header.h"

///counter.h
//Pozycja okreslana wzgledem lewego gornego rogu
//Licznik wyswietlajacy pewna liczbe ktora moze byc zwiekszana przy uzyciu funkcji increaseValue()

class counter : public sf::RectangleShape
{
	sf::Texture* _texture;
	sf::Text _count;
	int _value;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
	counter(sf::Vector2f size, sf::Vector2f position, sf::Font &font, std::string src_img, int val = 0);
	counter(float size_x, float size_y, float pos_x, float pos_y, sf::Font &font, std::string src_img, int val = 0);

	counter(sf::Vector2f size, sf::Vector2f position, sf::Font &font, sf::Texture &src_tex, int val = 0);
	counter(float size_x, float size_y, float pos_x, float pos_y, sf::Font &font, sf::Texture &src_tex, int val = 0);
	~counter();

	void increaseValue(int add);
	int getValue();
	
};

