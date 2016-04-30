#pragma once
#include "class_header.h"
#include "counter.h"

///class_header.h
//Klasa wyœwietlaj¹ca w sposób graficzny wartoœæ licznika
//Wyœwietla ona wybrany przez nas znak odpowiedni¹ iloœæ razy
//Pozycja liczona od srodka elementu

class SymbolCount : public counter
{
private:
	char _symbol;
	int _value;
	void createString();
public:
	SymbolCount(sf::Vector2f size, sf::Vector2f position, sf::Font &font, std::string src_img, int size_font, sf::Color color_font, char symbol, int value = 3);
	SymbolCount(float size_x, float size_y, float pos_x, float pos_y, sf::Font &font, std::string src_img, int size_font, sf::Color color_font, char symbol, int value = 3);

	SymbolCount(sf::Vector2f size, sf::Vector2f position, sf::Font &font, sf::Texture &src_tex, int size_font, sf::Color color_font, char symbol, int value = 3);
	SymbolCount(float size_x, float size_y, float pos_x, float pos_y, sf::Font &font, sf::Texture &src_tex, int size_font, sf::Color color_font, char symbol, int value = 3);
	~SymbolCount();

	void deleteOne();
	int getValue();
};

