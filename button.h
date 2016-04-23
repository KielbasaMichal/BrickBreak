#pragma once
#include "class_header.h"

///button.h
//Pozycja liczona od srodka elementu

class button : public sf::RectangleShape
{
private:
	bool _status;
	sf::Text _title;
	sf::Texture* _texture;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	button(sf::Vector2f size, sf::Vector2f position, std::string text, sf::Font &font, unsigned int size_font, sf::Color color_font, std::string src_img);
	button(float size_x, float size_y, float pos_x, float pos_y, std::string text, sf::Font &font, unsigned int size_font, sf::Color color_font, std::string src_img);

	button(sf::Vector2f size, sf::Vector2f position, std::string text, sf::Font &font, unsigned int size_font, sf::Color color_font, sf::Texture &src_tex);
	button(float size_x, float size_y, float pos_x, float pos_y, std::string text, sf::Font &font, unsigned int size_font, sf::Color color_font, sf::Texture &src_tex);

	~button();

	bool mouse_over_button(sf::RenderWindow &windows);
};

