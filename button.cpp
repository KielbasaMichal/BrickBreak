#include "button.h"

//private
void button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw((sf::RectangleShape)*this);
	target.draw(title);
}

//public
button::button(sf::Vector2f size, sf::Vector2f position, string text, sf::Font &fonts, sf::Color color)
{
	setSize(size);
	setPosition(position);
	setFillColor(color);

	title.setString(text);
	title.setFont(fonts);
	title.setCharacterSize(20);
	title.setColor(sf::Color::Black);
	sf::FloatRect title_pos = title.getLocalBounds();
	title.setPosition((size.x-title_pos.width)/2+position.x, (size.y - title_pos.height) / 2 + position.y);
}

button::~button()
{
}

void button::check_activate(sf::RenderWindow &windows)
{
	if (getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(windows)))
		status = true;
	else
		status = false;
}

bool button::check_mouse_click(sf::RenderWindow &windows)
{
	check_activate(windows);
	if (status)
		return true;
	else
		return false;
}