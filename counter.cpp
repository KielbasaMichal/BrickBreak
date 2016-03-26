#include "counter.h"

void counter::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw((sf::RectangleShape)*this);
	target.draw(count);
}

counter::counter(sf::Vector2f size, sf::Vector2f position, sf::Font & font, sf::Color color, int val)
{
	value = val;
	count.setFont(font);
	count.setString(std::to_string(value));
	count.setCharacterSize(40);
	count.setColor(sf::Color::Black);

	setSize(size);
	setPosition(position);
	setFillColor(color);

	sf::FloatRect count_pos = count.getLocalBounds();
	count.setPosition((size.x - count_pos.width) / 2 + position.x, (size.y - count_pos.height) / 2 + position.y);
	
}

counter::~counter()
{
}

void counter::increaseValue(int add)
{
	value += add;
	count.setString(std::to_string(value));

	sf::Vector2f pos = getPosition();
	sf::Vector2f size = getSize();
	sf::FloatRect count_pos = count.getLocalBounds();

	count.setPosition((size.x - count_pos.width) / 2 + pos.x, (size.y - count_pos.height) / 2 + pos.y);

}
