#include "head.h"


sf::RenderWindow windows(sf::VideoMode(WIDTH, HEIGHT), "Brick Break", sf::Style::Titlebar);
State States = Start;
sf::Font font;
RankView rank("data/rank.txt", WIDTH, HEIGHT, 150, 100, 0.7, font, 30, sf::Color::Yellow , windows);

int main()
{
	if (!font.loadFromFile("data/FunSized.ttf"))
	{
		std::cout << "Nie znaleziono czcionek!!!!";
		return -1;
	}
	rank.loadRankFromFile();
	rank.sortRank();
	rank.addToRank(152, "Adamigos");
	while (States != End)
	{
		switch (States)
		{
		case End:
			break;
		case Start:
			start_screen();
			break;
		case Play:
			play_screen();
			break;
		case Top:
			top_screen();
			break;
		}

	}

	//rank.saveRankToFile();
	return 0;
}