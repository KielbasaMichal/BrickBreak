#include "wall.h"

wall::wall(sf::Vector2f size, sf::Vector2f position, b2World &world, std::string src_img)
{
	//SFML init
	setOrigin(size.x / 2, size.y / 2);
	setPosition(position);
	setSize(size);
	_texture = new sf::Texture;
	_texture->loadFromFile(src_img);
	setTexture(_texture);

	//Box2D init
	b2BodyDef b2_wall;
	b2PolygonShape b2_shape;
	b2FixtureDef b2_fix;
	b2_wall.position.Set(pxtom(position.x + size.x / 2 - WIDTH / 2), pxtom(position.y + size.y / 2 - HEIGHT / 2)*(-1));
	b2_wall.type = b2_staticBody;
	_b2_wall_body = world.CreateBody(&b2_wall);
	b2_shape.SetAsBox(pxtom(size.x / 2), pxtom(size.y / 2));
	b2_fix.shape = &b2_shape;
	b2_fix.density = 0.0;
	b2_fix.restitution = 1.f;
	b2_fix.friction = 0.f;
	_b2_wall_body->CreateFixture(&b2_fix);
}

wall::wall(float size_x, float size_y, float x, float y, b2World &world, std::string src_img)
	:wall(sf::Vector2f(size_x, size_y), sf::Vector2f(x, y), world, src_img)
{
	//Wywolanie przez liste wczesniejszego konstruktora
}

wall::wall(sf::Vector2f size, sf::Vector2f position, b2World & world, sf::Texture & src_tex)
{
	//SFML init
	setOrigin(size.x / 2, size.y / 2);
	setPosition(position);
	setSize(size);
	_texture = &src_tex;
	setTexture(_texture);

	//Box2D init
	b2BodyDef b2_wall;
	b2PolygonShape b2_shape;
	b2FixtureDef b2_fix;
	b2_wall.position.Set(pxtom(position.x - WIDTH / 2), pxtom(position.y - HEIGHT / 2)*(-1));
	b2_wall.type = b2_staticBody;
	_b2_wall_body = world.CreateBody(&b2_wall);
	b2_shape.SetAsBox(pxtom(size.x / 2), pxtom(size.y / 2));
	b2_fix.shape = &b2_shape;
	b2_fix.density = 0.0;
	b2_fix.restitution = 1.f;
	b2_fix.friction = 0.f;
	_b2_wall_body->CreateFixture(&b2_fix);
}

wall::wall(float size_x, float size_y, float x, float y, b2World & world, sf::Texture & src_tex)
	:wall(sf::Vector2f(size_x, size_y), sf::Vector2f(x, y), world, src_tex)
{
	//Wywolanie przez liste wczesniejszego konstruktora
}

wall::~wall()
{
}

b2Body * wall::getb2Body()
{
	return _b2_wall_body;
}
