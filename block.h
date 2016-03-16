#pragma once
#include "head.h"

//Pozycja liczona od srodka elementu

class block : public sf::RectangleShape
{
	bool m_contact;
	b2Body * b2_block_body;
	b2World* world;
public:
	block(float size, sf::Vector2f position, b2World &world, sf::Color color = sf::Color::Transparent);
	block(float size, float size2, sf::Vector2f position, b2World &world, sf::Color color = sf::Color::Transparent);
	~block();

	void update_pos();
	b2Body* getBody();

	//Funkcje do zmiany statutu kolizji pilki z klockiem
	void setContact();
	bool isContact();

	//Uruchamianie lowowego generowania
	static void rand_init();
};

