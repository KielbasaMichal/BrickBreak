#pragma once

#include "class_header.h"

///counter.h
//Pozycja okreslana wzgledem lewego gornego rogu
//Licznik wyswietlajacy zadany tekst

class counter : public sf::RectangleShape
{
	sf::Texture* _Texture;
	sf::Text _Text;
	
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
	counter(sf::Vector2f size, sf::Vector2f position, sf::Font &font, std::string src_img, int size_font, sf::Color color_font);
	counter(float size_x, float size_y, float pos_x, float pos_y, sf::Font &font, std::string src_img, int size_font, sf::Color color_font);

	counter(sf::Vector2f size, sf::Vector2f position, sf::Font &font, sf::Texture &src_tex, int size_font, sf::Color color_font);
	counter(float size_x, float size_y, float pos_x, float pos_y, sf::Font &font, sf::Texture &src_tex, int size_font, sf::Color color_font);
	~counter();

protected:
	void CenterText();
	void setString(std::string text);
	
};

