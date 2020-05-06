#include "Enemy.hpp"

Enemy::Enemy(char symbol, int max)
{
	_symbol = symbol;
	_max_hit_points = randomizer(2);
	_hit_points = 1;
	_y_cord = 0;
	_x_cord = randomizer(max);
}

Enemy::~Enemy() {}

Enemy::Enemy() {}

Enemy::Enemy(const Enemy &e)
{
	*this = e;
}

Enemy &Enemy::operator=(const Enemy &rhs)
{
	if (this != &rhs)
	{
		_symbol = rhs._symbol;
		_max_hit_points = rhs._max_hit_points;
		_hit_points = rhs._hit_points;
		_y_cord = rhs._y_cord;
		_x_cord = rhs._x_cord;
	}
	return (*this);
}

Projectile * Enemy::shoot()
{
	return (new Projectile(this));
}