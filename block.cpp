#include "block.h"

block::block(sf::Vector2f size, sf::Vector2f position, b2World & world, std::string src_img)
{
	_contact = false;

	//SFML init
	setSize(size);
	setOrigin(size.x / 2, size.y / 2);
	setPosition(position);
	_texture = new sf::Texture;
	_texture->loadFromFile(src_img);
	setTexture(_texture);

	//Box2D init
	b2BodyDef b2_block;
	b2PolygonShape b2_shape;
	b2FixtureDef b2_fix;
	block::_world = &world;
	b2_block.position.Set(pxtom(position.x - WIDTH / 2), pxtom(position.y - HEIGHT / 2)*(-1));
	b2_block.type = b2_staticBody;
	_b2_block_body = world.CreateBody(&b2_block);
	b2_shape.SetAsBox(pxtom(size.x / 2), pxtom(size.y / 2));
	b2_fix.shape = &b2_shape;
	b2_fix.density = 1.0;
	b2_fix.restitution = 1.f;
	b2_fix.friction = 0.f;
	_b2_block_body->CreateFixture(&b2_fix);

	_b2_block_body->SetUserData(this);		//wyslanie informacji aby odczytac je w ContactListener
}

block::block(float size_x, float size_y, float pos_x, float pos_y, b2World &world, std::string src_img)
	: block(sf::Vector2f(size_x, size_y), sf::Vector2f(pos_x, pos_y), world, src_img)
{
	//Wywolanie przez liste wczesniejszego konstruktora
}

block::block(sf::Vector2f size, sf::Vector2f position, b2World & world, sf::Texture & src_tex)
{
	_contact = false;

	//SFML init
	setSize(size);
	setOrigin(size.x / 2, size.y / 2);
	setPosition(position);
	_texture = new sf::Texture;
	_texture = &src_tex;
	setTexture(_texture);

	//Box2D init
	b2BodyDef b2_block;
	b2PolygonShape b2_shape;
	b2FixtureDef b2_fix;
	block::_world = &world;
	b2_block.position.Set(pxtom(position.x - WIDTH / 2), pxtom(position.y - HEIGHT / 2)*(-1));
	b2_block.type = b2_staticBody;
	_b2_block_body = world.CreateBody(&b2_block);
	b2_shape.SetAsBox(pxtom(size.x / 2), pxtom(size.y / 2));
	b2_fix.shape = &b2_shape;
	b2_fix.density = 1.0;
	b2_fix.restitution = 1.f;
	b2_fix.friction = 0.f;
	_b2_block_body->CreateFixture(&b2_fix);

	_b2_block_body->SetUserData(this);		//wyslanie informacji aby odczytac je w ContactListener
}

block::block(float size_x, float size_y, float pos_x, float pos_y, b2World & world, sf::Texture & src_tex)
	: block(sf::Vector2f(size_x, size_y), sf::Vector2f(pos_x, pos_y), world, src_tex)
{
	//Wywolanie przez liste wczesniejszego konstruktora
}


block::~block()
{
	_world->DestroyBody(_b2_block_body);
}

b2Body * block::getBody()
{
	return _b2_block_body;
}

void block::setContact()
{
	_contact = true;
}

bool block::isContact()
{
	return _contact;
}

