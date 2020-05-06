#include "Player.hpp"

// ----------- Child Class Player ----------- //
int Player::StartPosition(int max_col, int max_row)
{
	int xPosition = max_row / 2;
	int yPosition = max_col - 1;
	_hit_points = 3;
	_x_cord = xPosition;
	_y_cord = yPosition;
	return (0);
}

Player::Player(char symbol) : GameObject(symbol)
{
	score = 0;
}

Player::Player(const Player &PlayerObj)
{
	*this = PlayerObj;
}
Player &Player::operator=(const Player &PlayerObj)
{
	this->_symbol = PlayerObj._symbol;
	return (*this);
}
Player::~Player(void)
{
	printw("%c has died!", _symbol);
}

Projectile *Player::shoot()
{
	return (new Projectile(this));
}