#include "button.h"

//private
void button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw((sf::RectangleShape)*this);
	target.draw(_title);
}

//public
button::button(sf::Vector2f size, sf::Vector2f position, std::string text, sf::Font &font, unsigned int size_font, sf::Color color_font, std::string src_img)
{
	//Rectangle init
	setSize(size);
	setPosition(position);
	_texture = new sf::Texture;
	_texture->loadFromFile(src_img);
	setTexture(_texture);

	//Text init
	_title.setString(text);
	_title.setFont(font);
	_title.setCharacterSize(size_font);
	_title.setColor(color_font);
	sf::FloatRect title_pos = _title.getLocalBounds();
	_title.setPosition((size.x-title_pos.width)/2+position.x, (size.y - title_pos.height) / 2 + position.y);
}

button::button(float size_x, float size_y, float pos_x, float pos_y, std::string text, sf::Font & font, unsigned int size_font, sf::Color color_font, std::string src_img)
	:button(sf::Vector2f(size_x, size_y), sf::Vector2f(pos_x, pos_y), text, font, size_font, color_font, src_img)
{
	//Wywolanie przez liste wczesniejszego konstruktora
}

button::button(sf::Vector2f size, sf::Vector2f position, std::string text, sf::Font & font, unsigned int size_font, sf::Color color_font, sf::Texture &src_tex)
{
	//Rectangle init
	setSize(size);
	setPosition(position);
	_texture = &src_tex;
	setTexture(_texture);

	//Text init
	_title.setString(text);
	_title.setFont(font);
	_title.setCharacterSize(size_font);
	_title.setColor(color_font);
	sf::FloatRect title_pos = _title.getLocalBounds();
	_title.setPosition((size.x - title_pos.width) / 2 + position.x, (size.y - title_pos.height) / 2 + position.y);
}

button::button(float size_x, float size_y, float pos_x, float pos_y, std::string text, sf::Font & font, unsigned int size_font, sf::Color color_font, sf::Texture &src_tex)
	:button(sf::Vector2f(size_x, size_y), sf::Vector2f(pos_x, pos_y), text, font, size_font, color_font, src_tex)
{
	//Wywolanie przez liste wczesniejszego konstruktora
}

button::~button()
{
}

bool button::check_mouse_click(sf::RenderWindow &windows)
{
	if (getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(windows)))
		return true;
	else
		return false;
}