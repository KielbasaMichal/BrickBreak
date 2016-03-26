#include "head.h"

void start_screen()
{
	//Texture load
	sf::Texture button_back;
	button_back.loadFromFile("data/button0.png");

	button start(sf::Vector2f(150, 75), sf::Vector2f(565, 300), "START", font, 40, sf::Color::Black, button_back);
	button exit(sf::Vector2f(150, 75), sf::Vector2f(565, 400), "WYJSCIE", font, 40, sf::Color::Black, button_back);

	while (States == Start)
	{
		sf::Event event;
		while (windows.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				States = End;
			if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
			{
				if (start.check_mouse_click(windows))
					States = Play;
				if (exit.check_mouse_click(windows))
					States = End;
			}

		} //while
		windows.clear(sf::Color::Blue);
		
		windows.draw(start);
		windows.draw(exit);

		windows.display();
	} //while
}