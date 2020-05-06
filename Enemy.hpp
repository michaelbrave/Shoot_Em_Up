#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "GameObject.hpp"
#include "Projectile.hpp"

class Enemy : public GameObject
{
private:
public:
	Enemy(void);
	Enemy(char symbol, int);
	Enemy(const Enemy &);
	Enemy &operator=(const Enemy &rhs);
	~Enemy(void);
	Projectile *shoot();
};

#endif