#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Box2D\Box2D.h"
#include "button.h"
#include "block.h"
#include "ball.h"
#include "paddle.h"
#include "ContactListener.h"
#include "board.h"
#include "wall.h"
#include "counter.h"


#define WIDTH 1280
#define HEIGHT 720

#define mtopx(metry) (metry)*50.0f
#define pxtom(pixele) (pixele)*0.02f
#define DGtoRD(deg) (b2_pi * (deg) / 180.0f)
#define RDtoDG(rad) ((rad) * (180.0f / b2_pi))

enum State
{
	End = 0,
	Start = 1,
	Play = 2,
};

extern sf::RenderWindow windows;
extern State States;
extern sf::Font font;

void start_screen();
void play_screen();
void alert_screen(string alert, int number_of_button, const string button_string[], void (*func[])(sf::RenderWindow&));