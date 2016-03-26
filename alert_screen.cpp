#include "head.h"
using namespace std;

#define alert_x 450
#define alert_y 150

void alert_screen(string alert, int number_of_button, const string button_string[], void (*func[])(sf::RenderWindow&) )
{
	//Texture load
	sf::Texture button_back;
	button_back.loadFromFile("data/button0.png");

	//Mozemy maksymalnie wypisac 4 przyciski wiec dodatkowe nie zostana narysowane
	if (number_of_button > 4)
		number_of_button = 4;

	//Komunikat
	sf::Text sfml_alert(alert, font, 30);
	sfml_alert.setColor(sf::Color::Green);
	sf::FloatRect alert_size = sfml_alert.getLocalBounds();
	sfml_alert.setPosition((alert_x - alert_size.width) / 2, 30);
	sf::RenderWindow okno(sf::VideoMode(alert_x, alert_y), "Alert", sf::Style::None);
	
	//Przyciski
	vector <button*> buttons;
	int _space = (alert_x - (number_of_button * 100)) / (number_of_button + 1);
	int space = _space;
	for (int i = 0; i < number_of_button; i++)
	{
		buttons.push_back(new button(sf::Vector2f(100.f, 30.f), sf::Vector2f(space, 100), button_string[i], font, 30, sf::Color::White, button_back));
		space += 100 + _space;
	}
	cout << endl;

	//Static step object
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

	while (okno.isOpen())
	{
		timeSinceLastUpdate += clock.restart();
		sf::Event event;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			while (okno.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					okno.close();
				if (event.type == sf::Event::KeyPressed &&  sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
					okno.close();
				if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					for (int i = 0; i < number_of_button; i++)
					{
						if (buttons.at(i)->check_mouse_click(okno))
						{
							func[i](okno);
						}
					}
				}
			} //while event


			timeSinceLastUpdate -= TimePerFrame;
		}
		okno.clear(sf::Color(182, 0, 0));
		
		okno.draw(sfml_alert);
		for (int i = 0; i < number_of_button; i++)
			okno.draw(*buttons.at(i));

		okno.display();
	}


}