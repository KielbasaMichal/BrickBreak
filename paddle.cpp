#include "paddle.h"

paddle::paddle(sf::Vector2f size, sf::Vector2f position, b2World &world, std::string src_img)
{
	//SFML init
	setSize(size);
	setPosition(position);
	setOrigin(size.x / 2, size.y / 2);
	_texture = new sf::Texture;
	_texture->loadFromFile(src_img);
	setTexture(_texture);

	//Box2D init
	_b2_block.position.Set(pxtom(position.x - WIDTH / 2), pxtom(position.y - HEIGHT / 2)*(-1));
	_b2_block.type = b2_staticBody;
	_b2_block_body = world.CreateBody(&_b2_block);
	_b2_shape.SetAsBox(pxtom(size.x / 2), pxtom(size.y / 2));
	_b2_fix.shape = &_b2_shape;
	_b2_fix.density = 0.f;
	_b2_fix.restitution = 1.f;
	_b2_fix.friction = 0.f;
	_b2_block_body->CreateFixture(&_b2_fix);
}

paddle::paddle(float size_x, float size_y, float pos_x, float pos_y, b2World & world, std::string src_img)
	:paddle(sf::Vector2f(size_x, size_y), sf::Vector2f(pos_x, pos_y), world, src_img)
{
	//Wywolanie przez liste wczesniejszego konstruktora
}

paddle::paddle(sf::Vector2f size, sf::Vector2f position, b2World & world, sf::Texture & src_tex)
{
	//SFML init
	setSize(size);
	setPosition(position);
	setOrigin(size.x / 2, size.y / 2);
	_texture = &src_tex;
	setTexture(_texture);

	//Box2D init
	_b2_block.position.Set(pxtom(position.x - WIDTH / 2), pxtom(position.y - HEIGHT / 2)*(-1));
	_b2_block.type = b2_staticBody;
	_b2_block_body = world.CreateBody(&_b2_block);
	_b2_shape.SetAsBox(pxtom(size.x / 2), pxtom(size.y / 2));
	_b2_fix.shape = &_b2_shape;
	_b2_fix.density = 0.f;
	_b2_fix.restitution = 1.f;
	_b2_fix.friction = 0.f;
	_b2_block_body->CreateFixture(&_b2_fix);
}

paddle::paddle(float size_x, float size_y, float pos_x, float pos_y, b2World & world, sf::Texture & src_tex)
	:paddle(sf::Vector2f(size_x, size_y), sf::Vector2f(pos_x, pos_y), world, src_tex)
{
	//Wywolanie przez liste wczesniejszego konstruktora
}

paddle::~paddle()
{
}

void paddle::update_pos(float x, float y)
{
	_b2_block_body->SetTransform(b2Vec2(pxtom(x - WIDTH / 2), pxtom(y - HEIGHT / 2)*(-1)), 0.f);
	b2Vec2 pos = _b2_block_body->GetPosition();
	pos.x = mtopx(pos.x) + WIDTH / 2;
	pos.y = mtopx(-1 * pos.y) + HEIGHT / 2;
	setPosition(pos.x, pos.y);
}

void paddle::update_pos_x_in_rage(sf::Vector2f updateTo, float min, float max)
{
	sf::Vector2f size = getSize();
	sf::Vector2f pos = getPosition();
	if (updateTo.x >= max - size.x/2)
		update_pos(max - size.x / 2, pos.y);
	else if (updateTo.x <= min +size.x/2)
		update_pos(min + size.x / 2, pos.y);
	else
		update_pos(updateTo.x, pos.y);
}

b2Body * paddle::getBody()
{
	return _b2_block_body;
}

void paddle::rand_init()
{
	srand((unsigned int)time(NULL));
}
