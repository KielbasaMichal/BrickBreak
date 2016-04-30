#pragma once
#include "class_header.h"

//Elementy planszy
std::vector <block*> Block;
ball *Ball;
std::vector<sf::Texture> Texture;

//Wymiary elementów
const float paddle_size_x = 150;
const float paddle_size_y = 50;
const float board_border_size = 50;


//Table of path to textures
std::string TextureSrc[] = {
	"data/block0.png",		//[0] Block
	"data/block1.png",		//[1] Block
	"data/block2.png",		//[2] Block
	"data/block3.png",		//[3] Block
	"data/block4.png",		//[4] Block
	"data/button0.png",		//[5] Przycik
	"data/wall0.png",		//[6] Sciana boczna planszy
	"data/ball.png",		//[7] Pilka
	"data/paddle0.png",		//[8] Paletka
	"data/board.png"		//[9] T³o planszy
};

//Funkcje do budowy ryzgrywki
void loadTexture(std::string *src, int number_of_texture)
{
	for (int i = 0; i < number_of_texture; i++)
	{
		sf::Texture temp;
		temp.loadFromFile(*(src + i));
		Texture.push_back(temp);
	}
}

void create_block(float x, float y, float width, float heigth, sf::Vector2f size, b2World &world, std::vector<sf::Texture>& tex, int ile_tex)
{
	int ktora = 0, next = 0;
	bool offset = false;
	sf::Vector2f size2;
	Block.clear();
	float y2 = y + size.y / 2;
	for (; y2 + size.y < y + heigth; y2 += size.y)
	{
		for (float x2 = x; x2 < x + width; x2 += size.x)
		{
			while (ktora == next)
				next = rand() % ile_tex;
			ktora = next;
			if (offset)
			{
				Block.push_back(new block(size2, sf::Vector2f(x2 + size2.x / 2, y2), world, tex.at(ktora)));
				x2 -= (size.x - size2.x);
				offset = false;
			}
			else if (x2 + size.x < x + width)
			{
				Block.push_back(new block(size, sf::Vector2f(x2 + size.x / 2, y2), world, tex.at(ktora)));
			}
			else
			{
				size2.x = (x + width) - x2;
				size2.y = size.y;
				Block.push_back(new block(size2, sf::Vector2f(x2 + size2.x / 2, y2), world, tex.at(ktora)));
				offset = true;
			}
		}
	}
}

void create_ball(float r, float x, float y, b2World &world, sf::Texture &tex)
{
	delete Ball;
	Ball = new ball(15, sf::Vector2f(x, y), world, tex);
}

//Dane to okna alertu
std::string tekst[] = { "OK", "End" };

void ok_but(sf::RenderWindow& windows)
{
	//States = Start; 
	windows.close();
}

void end_but(sf::RenderWindow& windows)
{
	States = End;
	windows.close();
}
void(*func[])(sf::RenderWindow&) = { ok_but, end_but };
//Koniec danych do okna alertu