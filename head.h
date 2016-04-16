#pragma once

#include "class_header.h"
#include "button.h"
#include "block.h"
#include "ball.h"
#include "paddle.h"
#include "ContactListener.h"
#include "board.h"
#include "wall.h"
#include "counter.h"

enum State
{
	End = 0,
	Start = 1,
	Play = 2,
	TopP = 3,
};

extern sf::RenderWindow windows;
extern State States;
extern sf::Font font;

void start_screen();
void play_screen();
void alert_screen(std::string alert, int number_of_button, const std::string button_string[], void (*func[])(sf::RenderWindow&));

//Ranking
struct Rank
{
	int _val;
	std::string _name;
};
extern std::vector<Rank> rank;
void loadRank(std::string src, std::vector<Rank> &vr);
void saveRank(std::string src, std::vector<Rank> &vr);
bool addRank(int val, std::string name, std::vector<Rank> &vr);