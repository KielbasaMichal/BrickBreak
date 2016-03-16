#pragma once
#include "head.h"


class ContactListener : public b2ContactListener
{
public:
	ContactListener();
	~ContactListener();

	void EndContact(b2Contact* contact);
};

