#include "GameWorld.hpp"

GameWorld::GameWorld(Player *player, BigBoss *bb, int maxX, int maxY, WINDOW *menu, time_t clockpace)
{
	_player = player;
	_maxX = maxX - 1;
	_maxY = maxY - 1;
	_menu = menu;
	_bb = bb;
	_clockpace = clockpace;
	for (int i = 0; i < 20; i++)
	{
		_ea[i] = NULL;
		_pa[i] = NULL;
		_pae[i] = NULL;
	}
}

GameWorld::GameWorld()
{
	for (int i = 0; i < 20; i++)
	{
		_ea[i] = NULL;
		_pa[i] = NULL;
		_pae[i] = NULL;
	}
}

GameWorld::~GameWorld()
{
	for (int i = 0; i < 20; i++)
	{
		if (_ea[i] != NULL)
			delete _ea[i];
		if (_pa[i] != NULL)
			delete _pa[i];
		if (_pae[i] != NULL)
			delete _pae[i];
	}
	delete _bb;
}

GameWorld::GameWorld(const GameWorld &gw)
{
	for (int i = 0; i < 20; i++)
	{
		if (_ea[i] != NULL)
			delete _ea[i];
		if (_pa[i] != NULL)
			delete _pa[i];
		if (_pae[i] != NULL)
			delete _pae[i];
	}
	*this = gw;
}

GameWorld &GameWorld::operator=(const GameWorld &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 20; i++)
		{
			if (_ea[i] != NULL)
				delete _ea[i];
			if (_pa[i] != NULL)
				delete _pa[i];
			if (_pae[i] != NULL)
				delete _pae[i];
		}
		for (int i = 0; i < 20; i++)
		{
			_ea[i] = rhs._ea[i];
			_pa[i] = rhs._pa[i];
			_pae[i] = rhs._pae[i];
		}
	}
	return (*this);
}

void GameWorld::addEnemy(Enemy *e)
{
	for (int i = 0; i < 20; i++)
	{
		if (_ea[i] == NULL)
		{
			_ea[i] = e;
			return;
		}
	}
}

void GameWorld::addProjectile(Projectile *p)
{
	for (int i = 0; i < 20; i++)
	{
		if (_pa[i] == NULL)
		{
			_pa[i] = p;
			return;
		}
	}
}

void GameWorld::addEnemyProjectile(Projectile *p) {
	for (int i = 0; i < 20; i++)
	{
		if (_pae[i] == NULL)
		{
			_pae[i] = p;
			return;
		}
	}
}

int GameWorld::getMaxX() const
{
	return _maxX;
}

int GameWorld::getMaxY() const
{
	return _maxY;
}

Player *GameWorld::getPlayer() const
{
	return _player;
}

void GameWorld::updateEnemies()
{
	int index = randomizer(21);
	if (index <= 5) {
		_bb->on = 1;
		_bb->_y_cord = 0;
		_bb->_x_cord = randomizer(_maxX - 1);
		index = randomizer(20);
	}
	if (_ea[index] != NULL) {
		addEnemyProjectile(_ea[index]->shoot());
	}
	for (int i = 0; i < 20; i++)
	{
		if (_ea[i] != NULL)
		{
			_ea[i]->_y_cord++;
			if (_ea[i]->_max_hit_points == 1)
				_ea[i]->_x_cord++;
			else
				_ea[i]->_x_cord--;
			if (_ea[i]->_x_cord >= _maxX) {
				_ea[i]->_max_hit_points = 0;
			}
			if (_ea[i]->_x_cord <= 0) {
				_ea[i]->_max_hit_points = 1;
			}
			if (_ea[i]->_y_cord > _maxY)
			{
				delete (_ea[i]);
				_ea[i] = NULL;
			}
		}
		if (_pa[i] != NULL)
		{
			_pa[i]->move();
			if (_pa[i]->_y_cord > _maxY || _pa[i]->_y_cord < 0)
			{
				delete (_pa[i]);
				_pa[i] = NULL;
			}
		}
		if (_pae[i] != NULL)
		{
			_pae[i]->move();
			if (_pae[i]->_y_cord > _maxY || _pae[i]->_y_cord < 0)
			{
				delete (_pae[i]);
				_pae[i] = NULL;
			}
		}
	}
	if (_bb->on) {
		if (_bb->_max_hit_points) {
			int i = 0;
			i = randomizer(2);
			if (i == 0) {
				_bb->_x_cord--;
			}
			else {
				_bb->_x_cord++;
			}
			_bb->_max_hit_points = 0;
		}
		else {
			_bb->_y_cord++;
			_bb->_max_hit_points = 1;
		}
		if (_bb->_x_cord > _maxX - 2) {
			_bb->_x_cord = _maxX - 2;
		}
		if (_bb->_x_cord < 0)
			_bb->_x_cord = 0;
		if (_bb->_y_cord >= _maxY)
			_bb->on = 0;
	}
}

void GameWorld::renderEnemies() const
{
	for (int i = 0; i < 20; i++)
	{
		if (_ea[i] != NULL)
			mvprintw(_ea[i]->_y_cord, _ea[i]->_x_cord, "%c", _ea[i]->getSymbol());
		if (_pa[i] != NULL)
			mvprintw(_pa[i]->_y_cord, _pa[i]->_x_cord, "%c", _pa[i]->getSymbol());
		if (_pae[i] != NULL)
			mvprintw(_pae[i]->_y_cord, _pae[i]->_x_cord, "%c", _pae[i]->getSymbol());
	}
		if (_bb->on)
			mvprintw(_bb->_y_cord, _bb->_x_cord, "##/n##");
}

void GameWorld::collisionChecking()
{
	for (int i = 0; i < 20; i++)
	{
		if (_ea[i] != NULL)
		{
			if(_player->col_detect(_ea[i]) == 1)
			{
				printw("ouch");
				//deathMenu();
			}
			if(_player->col_detect(_pae[i]) == 1) {}
			for (int j = 0; j < 20; j++)
			{
				if (_pa[j] != NULL && _ea[i] != NULL) {
					if (_ea[i]->col_detect(_pa[j])) {
						delete _ea[i];
						_ea[i] = NULL;
						i++;
						j = 0;
						_player->score++;
					}
				}
			}
		}
	}
	if (_bb->on == 1) {
		if ((_bb->_x_cord == _player->_x_cord && _bb->_y_cord == _player->_y_cord) ||
		(_bb->_x_cord + 1 == _player->_x_cord && _bb->_y_cord == _player->_y_cord) ||
		(_bb->_x_cord == _player->_x_cord && _bb->_y_cord + 1 == _player->_y_cord) ||
		(_bb->_x_cord + 1 == _player->_x_cord && _bb->_y_cord + 1 == _player->_y_cord)) {
			_player->_hit_points--;
		}
		for (int j = 0; j < 20; j++)
			{
				if (_pa[j] != NULL) {
					if ((_bb->_x_cord == _pa[j]->_x_cord && _bb->_y_cord == _pa[j]->_y_cord) ||
						(_bb->_x_cord + 1 == _pa[j]->_x_cord && _bb->_y_cord == _pa[j]->_y_cord) ||
						(_bb->_x_cord == _pa[j]->_x_cord && _bb->_y_cord + 1 == _pa[j]->_y_cord) ||
						(_bb->_x_cord + 1 == _pa[j]->_x_cord && _bb->_y_cord + 1 == _pa[j]->_y_cord)) {
						_player->score++;
						_pa[j]->_hit_points--;
						_bb->_hit_points--;
					}
				}
			}
	}
}