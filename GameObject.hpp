#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "retro.hpp"

class GameObject
{
protected:
public:
	char _symbol;
	int _max_hit_points;
	int _hit_points;
	int _y_cord;
	int _x_cord;
	GameObject(void);
	GameObject(char symbol);
	GameObject(const GameObject &Object);
	GameObject &operator=(const GameObject &Object);
	~GameObject(void);
	int col_detect(GameObject *object);
	char getSymbol() const;
};

#endif