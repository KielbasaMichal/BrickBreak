#include "head.h"

#define alert_x 450
#define alert_y 150

void alert_screen(string alert, int number_of_button, const string button_string[], void (*func[])(sf::RenderWindow&) )
{
	//Komunikat
	sf::Text sfml_alert(alert, font, 30);
	sfml_alert.setColor(sf::Color::Green);
	sf::FloatRect alert_size = sfml_alert.getLocalBounds();
	sfml_alert.setPosition((alert_x - alert_size.width) / 2, 30);
	sf::RenderWindow okno(sf::VideoMode(alert_x, alert_y), "Alert", sf::Style::None);
	
	//Przyciski
	vector <button*> buttons;
	for (int i = 0; i < number_of_button; i++)
	{
		buttons.push_back(new button(sf::Vector2f(100.f, 30.f), sf::Vector2f(20.f+i*120, 100), button_string[i], font, sf::Color::White));
	}

	while (okno.isOpen())
	{
		sf::Event event;
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
					if (buttons.at(0)->check_mouse_click(okno));
					{
						func[i](okno);
					} // przycisk exit_button
				}
			}
		} //while event
		okno.clear(sf::Color(182, 0, 0));


		
		
		okno.draw(sfml_alert);
		for (int i = 0; i < number_of_button; i++)
			okno.draw(*buttons.at(i));

		okno.display();
	}


}