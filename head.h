#pragma once

#include "class_header.h"
#include "button.h"
#include "block.h"
#include "ball.h"
#include "paddle.h"
#include "ContactListener.h"
#include "board.h"
#include "wall.h"
#include "IntCount.h"
#include "SymbolCount.h"
#include "RankView.h"

enum State
{
	End = 0,
	Start = 1,
	Play = 2,
	Top = 3,
};

extern sf::RenderWindow windows;
extern State States;
extern sf::Font font;
extern RankView rank;

void start_screen();
void play_screen();
void top_screen();
void alert_screen(std::string alert, int number_of_button, const std::string button_string[], void (*func[])(sf::RenderWindow&));