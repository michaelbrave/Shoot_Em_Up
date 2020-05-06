#include "BigBoss.hpp"

BigBoss::BigBoss(int max)
{
	_max_hit_points = 1;
	_hit_points = 5;
	_y_cord = 0;
	on = 0;
	_x_cord = randomizer(max) - 1;
	if (_x_cord < 0)
		_x_cord = 15;
	_string = "##\n##";
}

BigBoss::~BigBoss() {}

BigBoss::BigBoss() {}

BigBoss::BigBoss(const BigBoss &e)
{
	*this = e;
}

BigBoss &BigBoss::operator=(const BigBoss &rhs)
{
	if (this != &rhs)
	{
		_symbol = rhs._symbol;
		_max_hit_points = rhs._max_hit_points;
		_hit_points = rhs._hit_points;
		_y_cord = rhs._y_cord;
		_x_cord = rhs._x_cord;
		_string = "##\n##";
	}
	return (*this);
}

std::string BigBoss::getString() const {
	return _string;
}
