#pragma once
#include "class_header.h"
#include "counter.h"
class IntCount : public counter
{
private:
	int _value;
	
public:
	IntCount(sf::Vector2f size, sf::Vector2f position, sf::Font &font, std::string src_img, int size_font, sf::Color color_font, int val = 0);
	IntCount(float size_x, float size_y, float pos_x, float pos_y, sf::Font &font, std::string src_img, int size_font, sf::Color color_font, int val = 0);

	IntCount(sf::Vector2f size, sf::Vector2f position, sf::Font &font, sf::Texture &src_tex, int size_font, sf::Color color_font, int val = 0);
	IntCount(float size_x, float size_y, float pos_x, float pos_y, sf::Font &font, sf::Texture &src_tex, int size_font, sf::Color color_font, int val = 0);
	~IntCount();

	void increaseValue(int add);
};

