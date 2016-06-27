#include "head.h"
#include <iostream>

void top_screen()
{
	//Texture load
	sf::Texture button_back;
	button_back.loadFromFile("data/button0.png");

	button back(sf::Vector2f(150, 70), sf::Vector2f(75, 35), "BACK", font, 30, sf::Color::Black, button_back);
	button down(sf::Vector2f(150, 70), sf::Vector2f(WIDTH - 75, HEIGHT - 35), "DOWN", font, 30, sf::Color::Black, button_back);
	button up(sf::Vector2f(150, 70), sf::Vector2f(WIDTH - 75, 35), "UP", font, 30, sf::Color::Black, button_back);
	button test(sf::Vector2f(150, 70), sf::Vector2f(WIDTH / 2, HEIGHT / 2), "TEST", font, 30, sf::Color::Black, button_back);

	sf::View TView;
	int pos_y = 0;
	TView.reset(sf::FloatRect(0, pos_y, WIDTH, HEIGHT));
	TView.setViewport(sf::FloatRect(0, 0, 1, 1));
	
	while (States == Top)
	{
		sf::Event event;
		while (windows.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				States = End;
			if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
			{
				if (back.mouse_over_button(windows))
					States = Start;
				if (down.mouse_over_button(windows))
				{
					pos_y += 50;
					std::cout << pos_y << std::endl;
					TView.reset(sf::FloatRect(0, pos_y, WIDTH, HEIGHT));
				}
				if (up.mouse_over_button(windows))
				{
					pos_y += 50;
					std::cout << pos_y << std::endl;
					TView.reset(sf::FloatRect(0, pos_y, WIDTH, HEIGHT));
				}

			}
			if (event.type == sf::Event::MouseWheelMoved)
			{
				if (event.mouseWheel.delta == 1)		//rolka do góry
				{
					pos_y -= 50;
					TView.reset(sf::FloatRect(0, pos_y, WIDTH, HEIGHT));
				}
				else			//rolka na dó³
				{
					pos_y += 50;
					TView.reset(sf::FloatRect(0, pos_y, WIDTH, HEIGHT));
				}

				// display number of ticks mouse wheel has moved
				//std::cout << event.mouseWheel.delta << '\n';
			}
		} //while
		windows.clear(sf::Color::Green);

		windows.setView(TView);		//Nowy widok
		windows.draw(rank);
		
		windows.setView(windows.getDefaultView());		//Koniec elementów dla nowego widoku, rysujemy elementy na które widok nie ma wp³ywu

		windows.draw(back);
		windows.draw(down);		//Do przesuwania widoku w dó³
		windows.draw(up);		//Do przesuwania widoku w górê

		windows.display();
	} //while
}

/*
klasa RankView
	{
	RankPosition
	{
	Rectangle z kolorem
	Indeks z lewej nr_pozycji
	Lewa stron: nick
	Prawa stron: punkty

	virtual draw (..)
	{
		rectangele, text, tex
	}
	vector <RankPositon> 

	push_back(nick, punkty)
	RankView(Rank)
	RankView()
	~RankView()
	{
		vector clear
	}
	vitual draw(...)
	{
		for(..)
			draw(vector.at)
	}


*/