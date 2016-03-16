#include "wall.h"


wall::wall(float size_x, float size_y, float x, float y, b2World &world, sf::Color color)
{
	//SFML
	setPosition(x, y);
	setSize(sf::Vector2f(size_x, size_y));
	setFillColor(color);

	//Box2D
	b2BodyDef b2_wall;
	b2PolygonShape b2_shape;
	b2FixtureDef b2_fix;
	b2_wall.position.Set(pxtom(x + size_x/2 - WIDTH / 2), pxtom(y + size_y/2 - HEIGHT / 2)*(-1));
	b2_wall.type = b2_staticBody;
	b2_wall_body = world.CreateBody(&b2_wall);
	b2_shape.SetAsBox(pxtom(size_x / 2), pxtom(size_y / 2));
	b2_fix.shape = &b2_shape;
	b2_fix.density = 0.0;
	b2_fix.restitution = 1.f;
	b2_fix.friction = 0.f;
	b2_wall_body->CreateFixture(&b2_fix);
}

wall::wall(sf::Vector2f size, sf::Vector2f position, b2World &world, sf::Color color)
{
	//SFML
	setPosition(position);
	setSize(size);
	setFillColor(color);

	//Box2D
	b2BodyDef b2_wall;
	b2PolygonShape b2_shape;
	b2FixtureDef b2_fix;
	b2_wall.position.Set(pxtom(position.x + size.x / 2 - WIDTH / 2), pxtom(position.y + size.y / 2 - HEIGHT / 2)*(-1));
	b2_wall.type = b2_staticBody;
	b2_wall_body = world.CreateBody(&b2_wall);
	b2_shape.SetAsBox(pxtom(size.x / 2), pxtom(size.y / 2));
	b2_fix.shape = &b2_shape;
	b2_fix.density = 0.0;
	b2_fix.restitution = 1.f;
	b2_fix.friction = 0.f;
	b2_wall_body->CreateFixture(&b2_fix);
}

wall::~wall()
{
}

b2Body * wall::getb2Body()
{
	return b2_wall_body;
}
