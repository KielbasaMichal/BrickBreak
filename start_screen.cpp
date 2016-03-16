#include "head.h"

void start_screen()
{
	button start(sf::Vector2f(150, 75), sf::Vector2f(565, 300), "START", font, sf::Color::Yellow);
	button exit(sf::Vector2f(150, 75), sf::Vector2f(565, 400), "WYJSCIE", font, sf::Color::Yellow);

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