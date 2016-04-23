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
#include "Rank.h"

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
extern Rank rank;

void start_screen();
void play_screen();
void alert_screen(std::string alert, int number_of_button, const std::string button_string[], void (*func[])(sf::RenderWindow&));