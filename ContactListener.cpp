#include "ContactListener.h"
#include "block.h"


ContactListener::ContactListener()
{
}


ContactListener::~ContactListener()
{
}

void ContactListener::EndContact(b2Contact * contact)
{
	void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
	if (bodyUserData)
	{
		static_cast<block*>(bodyUserData)->setContact();
	}

	bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
	if (bodyUserData)
	{
		static_cast<block*>(bodyUserData)->setContact();
	}
}
