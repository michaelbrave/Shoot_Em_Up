#include "GameObject.hpp"
#include "Enemy.hpp"
#include "Projectile.hpp"

int GameObject::col_detect(GameObject *object)
{
	if (object != NULL){
		if ((_x_cord == object->_x_cord) && (_y_cord == object->_y_cord))
		{
			object->_hit_points--;
			_hit_points--;
			return (1);
		}
	}
	return (0);
}

GameObject::GameObject(void) {}

GameObject::GameObject(char symbol) :

	_symbol(symbol),
	_max_hit_points(1),
	_hit_points(1),
	_y_cord(10),
	_x_cord(10)
{}

GameObject::GameObject(const GameObject &Object)
{
	this->_symbol = Object._symbol;
	this->_hit_points = Object._hit_points;
	this->_max_hit_points = Object._max_hit_points;
}
GameObject & GameObject::operator = (const GameObject &Object)
{
	this->_symbol = Object._symbol;
	this->_hit_points = Object._hit_points;
	this->_max_hit_points = Object._max_hit_points;

	return (*this);
}
GameObject::~GameObject(void)
{
}

char GameObject::getSymbol() const {
	return _symbol;
}