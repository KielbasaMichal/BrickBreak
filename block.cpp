#include "block.h"

block::block(float size, sf::Vector2f position, b2World &world, sf::Color color)
{
	m_contact = false;
	
	//SFML
	setSize(sf::Vector2f(size, size));
	setOrigin(size / 2, size / 2);
	setPosition(position);
	if (color == sf::Color::Transparent)
		setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, 255));
	else
		setFillColor(color);
	
	//Box2D
	b2BodyDef b2_block;
	b2PolygonShape b2_shape;
	b2FixtureDef b2_fix;
	block::world = &world;
	b2_block.position.Set(pxtom(position.x - WIDTH/2), pxtom(position.y - HEIGHT/2)*(-1));
	b2_block.type = b2_staticBody;
	b2_block_body = world.CreateBody(&b2_block);
	b2_shape.SetAsBox(pxtom(size/2), pxtom(size/2));
	b2_fix.shape = &b2_shape;
	b2_fix.density = 1.0;
	b2_fix.restitution = 1.f;
	b2_fix.friction = 0.f;
	b2_block_body->CreateFixture(&b2_fix);
	b2_block_body->SetUserData(this);		//wyslanie informacji do pozniejszego odczytania w ContactListener
}

block::block(float size_x,float size_y, sf::Vector2f position, b2World &world, sf::Color color)
{
	m_contact = false;

	//SFML
	setSize(sf::Vector2f(size_x, size_y));
	setOrigin(size_x / 2, size_y / 2);
	setPosition(position);
	if (color == sf::Color::Transparent)
		setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, 255));
	else
		setFillColor(color);

	//Box2D
	b2BodyDef b2_block;
	b2PolygonShape b2_shape;
	b2FixtureDef b2_fix;
	block::world = &world;
	b2_block.position.Set(pxtom(position.x - WIDTH / 2), pxtom(position.y - HEIGHT / 2)*(-1));
	b2_block.type = b2_staticBody;
	b2_block_body = world.CreateBody(&b2_block);
	b2_shape.SetAsBox(pxtom(size_x / 2), pxtom(size_y / 2));
	b2_fix.shape = &b2_shape;
	b2_fix.density = 1.0;
	b2_fix.restitution = 1.f;
	b2_fix.friction = 0.f;
	b2_block_body->CreateFixture(&b2_fix);
	b2_block_body->SetUserData(this);		//wyslanie informacji do pozniejszego odczytania w ContactListener
}

block::~block()
{
	world->DestroyBody(b2_block_body);
}


void block::update_pos()
{
	b2Vec2 pos = b2_block_body->GetPosition();
	pos.x = mtopx(pos.x) + WIDTH / 2;
	pos.y = mtopx(-1 * pos.y) + HEIGHT / 2;
	setPosition(pos.x, pos.y);
}

b2Body * block::getBody()
{
	return b2_block_body;
}

void block::setContact()
{
	m_contact = true;
}

bool block::isContact()
{
	return m_contact;
}

void block::rand_init()
{
	srand((unsigned int)time(NULL));
}
