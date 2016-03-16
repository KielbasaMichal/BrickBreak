#include "ball.h"


ball::ball(float r, sf::Vector2f position, b2World &world)
{
	setRadius(r);
	setPosition(position);
	setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, 255));
	setOrigin(r, r);
	//Box2D init
	b2_ball.position.Set(pxtom(position.x - WIDTH / 2), pxtom(position.y - HEIGHT / 2)*-1);
	b2_ball.type = b2_dynamicBody;
	b2_ball.bullet = true;
	b2_ball_body = world.CreateBody(&b2_ball);
	b2_shape.m_radius = pxtom(r);
	b2_fix.shape = &b2_shape;
	b2_fix.density = 1.f;
	b2_fix.restitution = 1.f;
	b2_fix.friction = 0.f;
	b2_ball_body->CreateFixture(&b2_fix);
}

ball::~ball()
{
}

void ball::rand_init()
{
	srand((unsigned int)time(NULL));
}

void ball::update_pos()
{
	b2Vec2 pos = b2_ball_body->GetPosition();
	pos.x = mtopx(pos.x) + WIDTH / 2;
	pos.y = mtopx(-1 * pos.y) + HEIGHT / 2;
	setPosition(pos.x, pos.y);
}

b2Body* ball::getBody()
{
	return b2_ball_body;
}
