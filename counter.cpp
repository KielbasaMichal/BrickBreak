#include "counter.h"

void counter::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw((sf::RectangleShape)*this);
	target.draw(_count);
}

counter::counter(sf::Vector2f size, sf::Vector2f position, sf::Font & font, std::string src_img, int val)
{
	_value = val;
	_count.setFont(font);
	_count.setString(std::to_string(_value));
	_count.setCharacterSize(40);
	_count.setColor(sf::Color::Black);

	setSize(size);
	setPosition(position);
	_texture = new sf::Texture;
	_texture->loadFromFile(src_img);
	setTexture(_texture);

	sf::FloatRect count_pos = _count.getLocalBounds();
	_count.setPosition((size.x - count_pos.width) / 2 + position.x, (size.y - count_pos.height) / 2 + position.y);
	
}

counter::counter(float size_x, float size_y, float pos_x, float pos_y, sf::Font & font, std::string src_img, int val)
	:counter(sf::Vector2f(size_x, size_y), sf::Vector2f(pos_x, pos_y), font, src_img, val)
{
	//Wywolanie przez liste wczesniejszego konstruktora
}

counter::counter(sf::Vector2f size, sf::Vector2f position, sf::Font & font, sf::Texture &src_tex, int val)
{
	_value = val;
	_count.setFont(font);
	_count.setString(std::to_string(_value));
	_count.setCharacterSize(40);
	_count.setColor(sf::Color::Black);

	setSize(size);
	setPosition(position);
	_texture = new sf::Texture;
	_texture = &src_tex;
	setTexture(_texture);

	sf::FloatRect count_pos = _count.getLocalBounds();
	_count.setPosition((size.x - count_pos.width) / 2 + position.x, (size.y - count_pos.height) / 2 + position.y);
}

counter::counter(float size_x, float size_y, float pos_x, float pos_y, sf::Font & font, sf::Texture &src_tex, int val)
	:counter(sf::Vector2f(size_x, size_y), sf::Vector2f(pos_x, pos_y), font, src_tex, val)
{
	//Wywolanie przez liste wczesniejszego konstruktora
}

counter::~counter()
{
}

void counter::increaseValue(int add)
{
	_value += add;
	_count.setString(std::to_string(_value));

	sf::Vector2f pos = getPosition();
	sf::Vector2f size = getSize();
	sf::FloatRect count_pos = _count.getLocalBounds();
	_count.setPosition((size.x - count_pos.width) / 2 + pos.x, (size.y - count_pos.height) / 2 + pos.y);

}
