#pragma once
#include "class_header.h"

///ContactListener
//Klasa do wykrywania kolizji pomiedzy ball a block
//Po zakonczeniu kolizji flaga w klasie block zostaje ustawiona

class ContactListener : public b2ContactListener
{
public:
	ContactListener();
	~ContactListener();

	void EndContact(b2Contact* contact);
};

