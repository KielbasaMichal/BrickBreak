#include "paddle.h"

paddle::paddle(float size, float size2, sf::Vector2f position, b2World &world, sf::Color color)
{
	setSize(sf::Vector2f(size, size2));
	setPosition(position);
	if (color == sf::Color::Transparent)
		setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, 255));
	else
		setFillColor(color);
	setOrigin(size / 2, size2 / 2);
	//Box2D init
	b2_block.position.Set(pxtom(position.x - WIDTH / 2), pxtom(position.y - HEIGHT / 2)*(-1));
	b2_block.type = b2_staticBody;
	b2_block_body = world.CreateBody(&b2_block);
	b2_shape.SetAsBox(pxtom(size / 2), pxtom(size2 / 2));
	b2_fix.shape = &b2_shape;
	b2_fix.density = 0.f;
	b2_fix.restitution = 1.f;
	b2_fix.friction = 0.f;
	b2_block_body->CreateFixture(&b2_fix);
}

paddle::~paddle()
{
}

bool paddle::collison(sf::FloatRect rect)
{
	if (getLocalBounds().intersects(rect))
		return true;
	else
		return false;
}

void paddle::update_pos(float x, float y)
{
	b2_block_body->SetTransform(b2Vec2(pxtom(x - WIDTH / 2), pxtom(y - HEIGHT / 2)*(-1)), 0.f);
	b2Vec2 pos = b2_block_body->GetPosition();
	pos.x = mtopx(pos.x) + WIDTH / 2;
	pos.y = mtopx(-1 * pos.y) + HEIGHT / 2;
	setPosition(pos.x, pos.y);
}

b2Body * paddle::getBody()
{
	return b2_block_body;
}

void paddle::rand_init()
{
	srand((unsigned int)time(NULL));
}
