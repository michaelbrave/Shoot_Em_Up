#ifndef GAME_WORLD_HPP
#define GAME_WORLD_HPP

#include "GameObject.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Projectile.hpp"
#include "BigBoss.hpp"

class Player;
class Enemy;
class Projectile;

class GameWorld
{
private:
	Enemy *_ea[20];
	Projectile *_pa[20];
	Projectile *_pae[20];
	BigBoss *_bb;
	Player *_player;
	int _maxX;
	int _maxY;

public:
	WINDOW* _menu;
	time_t _clockpace;
	GameWorld(Player *player, BigBoss *bb, int maxX, int maxY, WINDOW*, time_t);
	GameWorld();
	~GameWorld();
	GameWorld(const GameWorld &);
	GameWorld &operator=(const GameWorld &);
	void addEnemy(Enemy *e);
	void addProjectile(Projectile *p);
	void addEnemyProjectile(Projectile *p);
	int getMaxX() const;
	int getMaxY() const;
	Player *getPlayer() const;
	void updateEnemies();
	void renderEnemies() const;
	void collisionChecking();
};

#endif