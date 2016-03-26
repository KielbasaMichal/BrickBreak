#include "ball.h"


ball::ball(float r, sf::Vector2f position, b2World &world, std::string src_img)
{
	//SFML init
	_texture = new sf::Texture;
	_texture->loadFromFile(src_img);
	setTexture(_texture);
	setRadius(r);
	setPosition(position);
	setOrigin(r, r);
	
	//Box2D init
	_b2_ball.position.Set(pxtom(position.x - WIDTH / 2), pxtom(position.y - HEIGHT / 2)*-1);
	_b2_ball.type = b2_dynamicBody;
	_b2_ball.bullet = true;
	_b2_ball_body = world.CreateBody(&_b2_ball);
	_b2_shape.m_radius = pxtom(r);
	_b2_fix.shape = &_b2_shape;
	_b2_fix.density = 1.f;
	_b2_fix.restitution = 1.f;
	_b2_fix.friction = 0.f;
	_b2_ball_body->CreateFixture(&_b2_fix);
}

ball::ball(float r, sf::Vector2f position, b2World & world, sf::Texture & src_tex)
{
	//SFML init
	_texture = &src_tex;
	setTexture(_texture);
	setRadius(r);
	setPosition(position);
	setOrigin(r, r);

	//Box2D init
	_b2_ball.position.Set(pxtom(position.x - WIDTH / 2), pxtom(position.y - HEIGHT / 2)*-1);
	_b2_ball.type = b2_dynamicBody;
	_b2_ball.bullet = true;
	_b2_ball_body = world.CreateBody(&_b2_ball);
	_b2_shape.m_radius = pxtom(r);
	_b2_fix.shape = &_b2_shape;
	_b2_fix.density = 1.f;
	_b2_fix.restitution = 1.f;
	_b2_fix.friction = 0.f;
	_b2_ball_body->CreateFixture(&_b2_fix);
}

ball::~ball()
{
}

void ball::update_pos()
{
	b2Vec2 pos = _b2_ball_body->GetPosition();
	pos.x = mtopx(pos.x) + WIDTH / 2;
	pos.y = mtopx(-1 * pos.y) + HEIGHT / 2;
	setPosition(pos.x, pos.y);
}

b2Body* ball::getBody()
{
	return _b2_ball_body;
}
