#pragma once
#include "class_header.h"

class RankView : public sf::Drawable
{
private:
	class RankPosition : public sf::Drawable
	{
	private:
		sf::RectangleShape _back;
		sf::Text _text[3];
		int _Lp;
		std::string _nick;
		int _Score;

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	public:
		RankPosition(int lp, std::string nick, int score, sf::Vector2f size, sf::Color color, sf::Font &font, int &font_size, int x, int y);
		void updateLp(int position);
		int getScore();
		std::string getNick();
		static int compScore(RankPosition a, RankPosition b);
		void setPosY(int y);
	};
	std::vector <RankPosition> _rank;

	int _screen_width;
	int _screen_height;

	std::string _source_file;
	sf::Vector2f _size;
	sf::Font *_font;
	int _font_size;
	sf::Color _color;
	int _x, _y;
	int last_y;
	sf::RenderWindow *_window;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
	RankView(std::string src, int screen_x, int screen_y, int x, int y, double percent_size_x, sf::Font &font, int font_size, sf::Color color, sf::RenderWindow &window);
	~RankView();
	void loadRankFromFile();
	void saveRankToFile();
	void addToRank(int val, std::string name);
	void sortRank();

};

