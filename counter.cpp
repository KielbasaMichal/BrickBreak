#include "counter.h"

void counter::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw((sf::RectangleShape)*this);
	target.draw(_Text);
}

counter::counter(sf::Vector2f size, sf::Vector2f position, sf::Font & font, std::string src_img, int size_font, sf::Color color_font)
{
	_Text.setFont(font);
	_Text.setCharacterSize(size_font);
	_Text.setColor(color_font);

	setSize(size);
	setOrigin(size.x / 2, size.y / 2);
	setPosition(position);
	_Texture = new sf::Texture;
	_Texture->loadFromFile(src_img);
	setTexture(_Texture);

	_Text.setPosition(position);
	CenterText();
}

counter::counter(float size_x, float size_y, float pos_x, float pos_y, sf::Font & font, std::string src_img, int size_font, sf::Color color_font)
	:counter(sf::Vector2f(size_x, size_y), sf::Vector2f(pos_x, pos_y), font, src_img, size_font, color_font)
{
	//Wywolanie przez liste wczesniejszego konstruktora
}

counter::counter(sf::Vector2f size, sf::Vector2f position, sf::Font & font, sf::Texture &src_tex, int size_font, sf::Color color_font)
{
	_Text.setFont(font);
	_Text.setCharacterSize(size_font);
	_Text.setColor(color_font);

	setSize(size);
	setOrigin(size.x / 2, size.y / 2);
	setPosition(position);
	_Texture = new sf::Texture;
	_Texture = &src_tex;
	setTexture(_Texture);

	_Text.setPosition(position);
	CenterText();
}

counter::counter(float size_x, float size_y, float pos_x, float pos_y, sf::Font & font, sf::Texture &src_tex, int size_font, sf::Color color_font)
	:counter(sf::Vector2f(size_x, size_y), sf::Vector2f(pos_x, pos_y), font, src_tex, size_font, color_font)
{
	//Wywolanie przez liste wczesniejszego konstruktora
}

counter::~counter()
{
}

void counter::CenterText()
{
	sf::FloatRect count_pos = _Text.getLocalBounds();
	_Text.setOrigin(count_pos.width / 2, count_pos.height / 2 + _Text.getCharacterSize()*0.15f);
}

void counter::setString(std::string text)
{
	_Text.setString(text);
}
