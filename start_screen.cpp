#include "head.h"

void start_screen()
{
	//Texture load
	sf::Texture button_back;
	button_back.loadFromFile("data/button0.png");

	button start(sf::Vector2f(225, 75), sf::Vector2f(WIDTH/2, HEIGHT/2), "START", font, 38, sf::Color::Black, button_back);
	button rank(sf::Vector2f(225, 75), sf::Vector2f(WIDTH/2, HEIGHT / 2 + 125), "RANKING", font, 38, sf::Color::Black, button_back);
	button exit(sf::Vector2f(225, 75), sf::Vector2f(WIDTH/2, HEIGHT / 2 + 250), "WYJSCIE", font, 38, sf::Color::Black, button_back);

	while (States == Start)
	{
		sf::Event event;
		while (windows.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				States = End;
			if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
			{
				if (start.mouse_over_button(windows))
					States = Play;
				if (rank.mouse_over_button(windows))
					States = Top;
				if (exit.mouse_over_button(windows))
					States = End;
			}

		} //while
		windows.clear(sf::Color::Cyan);
		
		//TODO1 DRAW BACKGROUND
		//TODO2 DRAW LOGO
		windows.draw(start);
		windows.draw(rank);
		windows.draw(exit);

		windows.display();
	} //while
}