#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameObject.hpp"
#include "Projectile.hpp"

class Player : public GameObject
{
private:

public:
	int score;
	//Player(void);
	Player(char symbol);
	Player(const Player &Player);
	Player &operator=(const Player &Player);
	~Player(void);
	int StartPosition(int max_col, int max_row);
	Projectile *shoot();
};

#endif